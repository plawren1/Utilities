#include <iostream>
#include <string>

class date {

};

class customer {
public:
	customer() :m_name("") { std::cout << "A" << std::endl; };
	customer(std::string name) :m_name(name) { std::cout << "B" << std::endl; };
	customer(customer const& rhs);
	customer& operator=(customer const& rhs);

private:
	std::string m_name;
//	date last_transaction;
};


class priority_customer :public customer {	//Derived class
public:
	priority_customer():m_priority(0),customer() { std::cout << "C" << std::endl; };
	priority_customer(int const& priority):m_priority(priority), customer() { std::cout << "D" << std::endl; };
	priority_customer(int const& priority, std::string name) :m_priority(priority), customer(name) { std::cout << "E" << std::endl; };
	priority_customer(priority_customer const& rhs);
	priority_customer& operator=(priority_customer const& rhs);
private:
	int m_priority;
};