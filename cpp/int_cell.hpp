#ifndef INT_CELL_H
#define INT_CELL_H

#include <iostream>

class int_cell
{
    int m_stored_value;

public:
    // Due to this class beinb simple/POD, the rule of 5 isnt necessary, but I
    // implemented just for learning purposes.

    int_cell();                            // Default ctor
    ~int_cell() = default;                 // Destructor
    explicit int_cell(int initial_value);  // Param ctor
    int_cell(const int_cell& rhs);         // Copy ctor
    int_cell(int_cell&& rhs) noexcept;     // Move ctor

    int_cell& operator=(const int_cell& rhs);      // Copy Assignment ctor
    int_cell& operator=(int_cell&& rhs) noexcept;  // Move Assignment ctor

    int  read() const;
    void write(int value);
};

#endif
