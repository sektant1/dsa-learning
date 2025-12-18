#include <iostream>

#include "int_cell.hpp"

// Default ctor definiton
int_cell::int_cell()
    : m_stored_value {0}
{
    std::cout << "Creating cell with default value(0)..." << "\n";
    std::cout << "Stored value: " << m_stored_value << "\n";
}

// Param ctor definiton
int_cell::int_cell(int initial_value)
    : m_stored_value {initial_value}
{
    std::cout << "Creating cell with parameter value..." << "\n";
    std::cout << "Stored value: " << m_stored_value << "\n";
}

// Copy ctor definition
int_cell::int_cell(const int_cell& rhs)
    : m_stored_value {rhs.m_stored_value}
{
    std::cout << "Creating cell with copy rhs value..." << "\n";
    std::cout << "Stored value: " << m_stored_value << "\n";
}

// Move ctor definition
int_cell::int_cell(int_cell&& rhs) noexcept
    : m_stored_value {rhs.m_stored_value}
{
    std::cout << "Creating cell with move rhs value..." << "\n";
    std::cout << "Stored value: " << m_stored_value << "\n";
}

// Copy assignment definition
int_cell& int_cell::operator=(const int_cell& rhs)
{
    if (this != &rhs) {
        m_stored_value = rhs.m_stored_value;
    }
    std::cout << "Copying assignment cell with rhs value..." << "\n";
    std::cout << "Stored value: " << m_stored_value << "\n";
    return *this;
}

// Move assignment definition
int_cell& int_cell::operator=(int_cell&& rhs) noexcept
{
    if (this != &rhs) {
        m_stored_value = rhs.m_stored_value;
        std::cout << "Moving assignment cell with rhs value..." << "\n";
        std::cout << "Stored value: " << m_stored_value << "\n";
    }
    return *this;
}

int int_cell::read() const
{
    std::cout << "Reading cell with value: " << m_stored_value << "\n";
    return m_stored_value;
}

void int_cell::write(int value)
{
    std::cout << "Writing cell with value: " << m_stored_value << "\n";
    m_stored_value = value;
}

int main()
{
    int_cell cell1(1);

    int_cell cell2 = cell1;

    int_cell cell3 {11};
    cell3.read();

    int_cell cell4 {};
    cell4.write(cell3.read());

    return 0;
}
