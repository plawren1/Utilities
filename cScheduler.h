#include <cstddef>
#include <vector>
#include <ctime>

#if !defined cSheduler_INCLUDE
#define cSheduler_INCLUDE
template<typename T>
class cSchedulerBase{
public:
    cSchedulerBase(std::size_t n, std::size_t p) :m_size(n), m_time(p){};
protected:
    //    void add_element(T const& t);
    void add_element(T const& t){
        element item(t);
        item.expiry_time += m_time;
        m_elements.push_back(item);
    }

    int get_size(){ return m_elements.size(); }
    T get_element(int i){ return m_elements.at(i).t; }

    void print_elements(void);
    //void print_elements(void){
    //    std::cout << "Default function called!" << std::endl;
    //}

    void removeOldElements()
    {
        std::time_t time_now = std::time(nullptr);
        int time_now_epoch = time_now;
		int size = m_elements.size();
        for (int i = 0; i < size; i++)
        {
            if (time_now_epoch > m_elements.at(i).expiry_time)
            {
//                std::cout << "removing " << i << std::endl;
                m_elements.erase(m_elements.begin() + i);
				size = m_elements.size();
            }
        }
    }

    bool schedulerEmpty( void ){ return m_elements.empty(); }

private:
    
    struct element{
       int expiry_time;
       T t;

       element(T t) :expiry_time(std::time(nullptr)), t(t){  }
    };
    std::size_t  m_time;
    std::size_t m_size;    
    std::vector < element > m_elements;
};

template<class T, std::size_t n, std::size_t p>
class cScheduler : private cSchedulerBase<T>{
public:
	cScheduler() : cSchedulerBase(n, p), next_element(0){}

//    void add(T const& t);
    void add(T const& t)
	{	// Remove any old elements
		removeOld();
		add_element(t); 
	}
    int size(void){ return get_size(); }    
    void print(void){ print_elements(); }
    void removeOld(void){ removeOldElements(); }
    bool empty(void){ return schedulerEmpty(); }

	bool getNextOk(T & ele) {
		bool ret = false;
		int size_before = size();
		removeOld();
		int size_after = size();

		next_element = next_element + size_after - size_before;

		if (!empty())
		{
			if (next_element > (size() - 1))
			{
				next_element = 0;
			}
			ele = get_element(next_element++);
			ret = true;
		}

		return ret;
	}
private:    
	T get(int i) { return get_element(i); }
	std::size_t next_element;
};

#endif  //cSheduler_INCLUDE