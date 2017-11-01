#include <iostream>
#include "general_class.h"

customer::customer(customer const& rhs) :m_name(rhs.m_name)
{
	std::cout << "customer copy constructor called" << std::endl;
}

customer& customer::operator=(customer const& rhs)
{
	std::cout << "customer assignment operator" << std::endl;
	m_name = rhs.m_name;
	return *this;
}

priority_customer::priority_customer(priority_customer const& rhs):customer(rhs), m_priority(rhs.m_priority)
{
	std::cout << "priority_customer copy constructor called" << std::endl;
}

priority_customer& priority_customer::operator=(priority_customer const& rhs)
{
	std::cout << "priority_customer assignment operator" << std::endl;
	customer::operator=(rhs);
	m_priority = rhs.m_priority;
	return *this;
}


