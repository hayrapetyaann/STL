#ifndef LIST_HPP
#define LIST_HPP

#include <cstddef>
#include <iterator>
#include <utility> 

namespace atlas {

    template<typename T>
    class List {
    private:
        struct Node {
            T m_data;
            Node* m_prev;
            Node* m_next;

            Node(const T& value) : m_data(value), m_prev(nullptr), m_next(nullptr) {}
        };

        Node* m_head;
        Node* m_tail;
        std::size_t m_node_count;

    public:
        using value_type = T;
        using size_type = std::size_t;
        using difference_type = std::ptrdiff_t;
        using reference = value_type&;
        using const_reference = const value_type&;

        class iterator {
        private:
            Node* node;

        public:
            iterator(Node* n = nullptr) : node(n) {}

            T& operator*();
            T* operator->();

            iterator& operator++();
            iterator operator++(int);
            iterator& operator--();
            iterator operator--(int);

            bool operator==(const iterator& other) const;
            bool operator!=(const iterator& other) const;

            Node* get_node() const;
        };

        class const_iterator {
        private:
            const Node* node;

        public:
            const_iterator(const Node* n = nullptr) : node(n) {}

            const T& operator*() const;
            const T* operator->() const;

            const_iterator& operator++();
            const_iterator operator++(int);
            const_iterator& operator--();
            const_iterator operator--(int);

            bool operator==(const const_iterator& other) const;
            bool operator!=(const const_iterator& other) const;

            const Node* get_node() const;
        };

        class reverse_iterator {
        private:
            Node* node;

        public:
            reverse_iterator(Node* n = nullptr) : node(n) {}

            T& operator*();
            T* operator->();

            reverse_iterator& operator++();
            reverse_iterator operator++(int);
            reverse_iterator& operator--();
            reverse_iterator operator--(int);

            bool operator==(const reverse_iterator& other) const;
            bool operator!=(const reverse_iterator& other) const;

            Node* get_node() const;
        };

        class const_reverse_iterator {
        private:
            const Node* node;

        public:
            const_reverse_iterator(const Node* n = nullptr) : node(n) {}

            const T& operator*() const;
            const T* operator->() const;

            const_reverse_iterator& operator++();
            const_reverse_iterator operator++(int);
            const_reverse_iterator& operator--();
            const_reverse_iterator operator--(int);

            bool operator==(const const_reverse_iterator& other) const;
            bool operator!=(const const_reverse_iterator& other) const;

            const Node* get_node() const;
        };

        List();
        explicit List(size_type count);
        List(const List& other);
        List(List&& other) noexcept;
        List& operator=(const List& other);
        List& operator=(List&& other) noexcept;
        ~List();

        bool empty() const;
        size_type size() const;

        reference front();
        const_reference front() const;
        reference back();
        const_reference back() const;
        
        iterator begin();
        iterator end();

        const_iterator begin() const;
        const_iterator end() const;

        reverse_iterator rbegin();
        reverse_iterator rend();

        const_reverse_iterator rbegin() const;
        const_reverse_iterator rend() const;

        const_iterator cbegin() const;
        const_iterator cend() const;

        const_reverse_iterator crbegin() const;
        const_reverse_iterator crend() const;

        void clear();
        void push_back(const T& value);
        void pop_back();
        void push_front(const T& value);
        void pop_front();
        iterator insert(iterator position, const T& value);
        iterator erase(iterator position);
        void swap(List& other);
        void reverse();
        void sort();
    };

} // namespace atlas

#include "list.cpp"

#endif 
