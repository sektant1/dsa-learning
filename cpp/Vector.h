#ifndef VECTOR_H
#define VECTOR_H

// The Vector is a first-class type (can be copied and memory can be
// automatically freed)

// It will mantain the primitive array (via pointer variable to the allocated
// block), its capacity and the current numbers of elements in the Vector.

// The Vector implements the Big-Five to provide deep-copy semantics,
// its destructor to reclaim the primitive array and the move semantics aswell.

// The Vector will provide the resize() routine that changes the SIZE of the
// Vector and the reserve() that changes the CAPACITY of the Vector. The
// capacity is changed by obtaining a new block of memory for the primitive
// array, copying the old block there and reclaiming the old one.

// It also implements the operator[], with an accessor and mutator.

// The basic routines such as size(), empty(), clear(), back(), pop_back() and
// push_back will be implemented as well. Note that push_back() will call
// reserve() if the SIZE and CAPACITY are same.

// This Vector also provides support for the nested types iterator and
// const_iterator, and its associated begin() and end() methods.

#include <algorithm>
#include <iostream>

template<typename T>
class Vector
{
public:
    explicit Vector(int init_size = 0)
        : m_size {init_size}
        , m_capacity {init_size + k_spare_capacity}
        , m_elements(new T[m_capacity])
    {}

    Vector(const Vector& rhs)
        : m_size {rhs.m_size}
        , m_capacity {rhs.m_capacity}
        , m_elements(new T[m_capacity])
    {
        for (int k = 0; k < m_size; ++k) {
            m_elements[k] = rhs.m_elements[k];
        }
    }

    Vector& operator=(const Vector& rhs)
    {
        Vector copy = rhs;
        std::swap(*this, copy);
        return *this;
    }

    Vector(Vector&& rhs) noexcept
        : m_size {rhs.m_size}
        , m_capacity {rhs.m_capacity}
        , m_elements {rhs.m_elements}
    {
        rhs.m_size     = 0;
        rhs.m_capacity = 0;
        rhs.m_elements = nullptr;
    }

    Vector& operator=(Vector&& rhs) noexcept
    {
        std::swap(m_size, rhs.m_size);
        std::swap(m_capacity, rhs.m_capacity);
        std::swap(m_elements, rhs.m_elements);

        return *this;
    }

    ~Vector() { delete[] m_elements; }

    T& operator[](int index) { return m_elements[index]; }

    const T& operator[](int index) const { return m_elements[index]; }

    int size() const { return m_size; }

    int capacity() const { return m_capacity; }

    bool empty() const { return size() == 0; }

    void resize(int new_size)
    {
        if (new_size > m_capacity) {
            reserve(new_size * 2);
        }
        m_size = new_size;
    }

    void reserve(int new_capacity)
    {
        if (new_capacity < m_size) {
            return;
        }

        T* new_vec = new T[new_capacity];
        for (int k = 0; k < m_size; ++k) {
            new_vec[k] = std::move(m_elements[k]);
        }

        m_capacity = new_capacity;
        std::swap(m_elements, new_vec);

        delete[] new_vec;
    }

    void push_back(const T& elem)
    {
        if (m_size == m_capacity) {
            reserve((2 * m_capacity) + 1);  // +1 is used in case size is 0
        }
        m_elements[m_size++] = elem;
    }

    void push_back(T&& elem)
    {
        if (m_size == m_capacity) {
            reserve((2 * m_capacity) + 1);  // +1 is used in case size is 0
        }
        m_elements[m_size++] = std::move(elem);
    }

    void pop_back()
    {
        if (!empty()) {
            --m_size;
        }
    }

    void clear() { resize(0); }

    T& front() { return m_elements[0] };

    const T& front() const { return m_elements[0] };

    T& back() { return m_elements[m_size - 1]; }

    const T& back() const { return m_elements[m_size - 1]; }

    typedef T*       iterator;
    typedef const T* const_iterator;

    iterator begin() { return &m_elements[0]; }

    iterator end() { return &m_elements[size()]; }

    const_iterator begin() const { return &m_elements[0]; }

    const_iterator end() const { return &m_elements[size()]; }

private:
    int m_size;
    int m_capacity;
    T*  m_elements = nullptr;

    static const int k_spare_capacity = 16;
};

#endif  // VECTOR_H
