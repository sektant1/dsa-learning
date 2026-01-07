#ifndef LIST_H
#define LIST_H

// Our List structure will need to implement four new classes:

// - The List class itself, which will hold the links to both ends, the size of
// the list and the methods that will be used.

// - The Node class which will be a
// nested PRIVATE class. a Node contains the DATA and POINTERS to the
// next/previous Node and its constructors.

// - The const_iterator class which is a PUBLIC nested class and ABSTRACTS the
// notion of a POSITION. the const_iterator stores a pointer to "current" node
// and provides the basic impl of the basic iterator operations, overloading
// operators such as =, ==, != and ++.

// - The iterator class, which is the same as the const_iterator except that
// operator* returns a reference to the item being viewed rather than a constant
// reference to it. also, its important to know that the iterator can be used in
// any routine that requires a const_iterator, but NOT vice-versa. in other
// words, iterator IS A const_iterator.

// Because the iterator classes store a pointer to the “current node,” and the
// end marker is a valid position, it makes sense to create an extra node at the
// end of the list to represent the endmarker.
// These extra nodes are sometimes known as sentinel nodes; speciﬁcally, the
// node at the front is called HEADER node, and the back one TAIL node.

#include <algorithm>
#include <utility>

template<typename T>
class List
{
    struct Node
    {
        T     data;
        Node* prev;
        Node* next;

        Node(const T& d = T {}, Node* p = nullptr, Node* n = nullptr)
            : data {d}
            , prev {p}
            , next {n}
        {}

        Node(T&& d, Node* p = nullptr, Node* n = nullptr)
            : data {std::move(d)}
            , prev {p}
            , next {n}
        {}
    };

    int   m_size;
    Node* m_head;
    Node* m_tail;

    void init()
    {
        m_size       = 0;
        m_head       = new Node;
        m_tail       = new Node;
        m_head->next = m_tail;
        m_tail->prev = m_head;
    }

public:
    class const_iterator
    {
    public:
        const_iterator()
            : m_current {nullptr}
        {}

        const T& operator*() const { return retrieve(); }

        const_iterator& operator++()
        {
            m_current = m_current->next;
            return *this;
        }

        const_iterator operator++(int)
        {
            const_iterator old = *this;
            ++(*this);
            return old;
        }

        bool operator==(const const_iterator& rhs) const
        {
            return m_current == rhs.m_current;
        }

        bool operator!=(const const_iterator& rhs) const
        {
            return !(*this == rhs);
        }

    protected:
        Node* m_current;

        T& retrieve() const { return m_current->data; }

        explicit const_iterator(Node* p)
            : m_current {p}
        {}

        friend class List<T>;
    };

    class iterator : public const_iterator
    {
    public:
        iterator() = default;

        T& operator*() { return const_iterator::retrieve(); }

        const T& operator*() { return const_iterator::operator*(); }

        iterator& operator++()
        {
            this->current = this->current->next;
            return *this;
        }

        iterator& operator++(int)
        {
            iterator old = *this;
            ++(*this);
            return old;
        }

    protected:
        explicit iterator(Node* p)
            : const_iterator {p}
        {}

        friend class List<T>;
    };

    List() { init(); }

    List(const List& rhs)
    {
        init();
        for (auto& elem : rhs) {
            push_back(elem);
        }
    }

    List& operator=(const List& rhs)
    {
        List copy = rhs;
        std::swap(*this, copy);
        return *this;
    }

    List(List&& rhs) noexcept
        : m_size {rhs.m_size}
        , m_head {rhs.m_head}
        , m_tail {rhs.m_tail}
    {
        rhs.m_size = 0;
        rhs.m_head = nullptr;
        rhs.m_tail = nullptr;
    }

    List& operator=(List&& rhs)
    {
        std::swap(m_size, rhs.m_size);
        std::swap(m_head, rhs.m_head);
        std::swap(m_tail, rhs.m_tail);

        return *this;
    }

    ~List()
    {
        clear();
        delete m_head;
        delete m_tail;
    }

    iterator begin() { return {m_head->next}; }

    const_iterator begin() const { return {m_head->next}; }

    iterator end() { return {m_tail}; }

    const_iterator end() { return {m_tail}; }

    int size() const { return m_size; }

    bool empty() const { return size() == 0; }

    void clear()
    {
        while (!empty()) {
            pop_front();
        }
    }

    T& front() { return *begin(); }

    const T& front() const { return *begin(); }

    T& back() { return *--end(); }

    const T& back() const { return *--end(); }

    void push_front(const T& elem) { insert(begin(), elem); }

    void push_front(T&& elem) { insert(begin(), std::move(elem)); }

    void push_back(const T& elem) { insert(end(), elem); }

    void push_back(T&& elem) { insert(end(), std::move(elem)); }

    void pop_front() { erase(begin()); }

    void pop_back() { erase(--end()); }

    iterator insert(iterator itr, const T& elem)
    {
        Node* p = itr.current;

        m_size++;
        return {p->prev = p->prev->next = new Node {elem, p->prev, p}};
    }

    iterator insert(iterator itr, T&& elem)
    {
        Node* p = itr.current;

        m_size++;
        return {p->prev = p->prev->next =
                    new Node {std::move(elem), p->prev, p}};
    }

    iterator erase(iterator itr)
    {
        Node*    p = itr.current;
        iterator ret_val {p->next};
        p->prev->next = p->next;
        p->next->prev = p->prev;

        delete p;
        m_size--;

        return ret_val;
    }

    iterator erase(iterator from, iterator to)
    {
        for (iterator itr = from; itr != to;) {
            itr = erase(itr);
        }
        return to;
    }
};

#endif  // LIST_H
