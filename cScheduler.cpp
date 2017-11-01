#include "cScheduler.h"
#include <ctime>
#include <iostream>

//template<typename T, std::size_t n, std::size_t p> inline void cSchedule<T, n, p>::add(T const& t)
//{
//    add_element(t);
//}
//
//template<typename T> inline void cScheduleBase<T>::add_element(T const& t)
//{
//    element item(t);
//    m_elements.push_back(item);
//}

template<>
void cSchedulerBase<int>::print_elements(void)
{
    for (int i = 0; i < m_elements.size(); i++)
    {
        std::cout << m_elements.at(i).t << std::endl;
    }
}

//template<typename T> inline void cScheduleBase<T>::print_elements(void)   // Won't work. Has to defined inside the class...
template<> void cSchedulerBase<std::string>::print_elements(void)
{
    std::cout << "Default function called!" << std::endl;
}