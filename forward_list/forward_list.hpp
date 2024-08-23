#ifndef FORWARD_LIST_HPP
#define FORWARD_LIST_HPP

#include <iostream>
#include <cstddef>
#include <iterator>
#include <limits>
#include <stdexcept>
#include <algorithm>

namespace atlas {
    template <typename T>
    class forward_list {
    public:
        using value_type = T;
        using size_type = std::size_t;
        using difference_type = std::ptrdiff_t;
        using reference = T&;
        using const_reference = const T&;
        using pointer = T*;
        using const_pointer = const T*;

        class iterator;
        class const_iterator;

        forward_list();
        explicit forward_list(size_type count);
        forward_list(const forward_list& other);
        forward_list(forward_list&& other) noexcept;
        ~forward_list();

        forward_list& operator=(const forward_list& other);

        reference front();
        const_reference front() const;

        iterator begin();
        iterator end();
        const_iterator begin() const;
        const_iterator end() const;
        iterator before_begin();
        const_iterator cbefore_begin() const;

        bool empty() const;
        size_type max_size() const;

        void clear();
        void push_front(const T& value);
        void pop_front();
        void insert_after(iterator pos, const T& value);
        void erase_after(iterator pos);
        void reverse();
        void remove(const T& value);
        void sort();

    private:
        struct Node {
            T m_data;
            Node* m_next;
            Node(const T& d);
        };

        Node* m_head;

        void delete_list(Node* node);

    public:
        class iterator {
        public:
            using iterator_category = std::forward_iterator_tag;
            using value_type = T;
            using difference_type = std::ptrdiff_t;
            using pointer = T*;
            using reference = T&;

            iterator(Node* node = nullptr);

            reference operator*() const;
            pointer operator->() const;
            iterator& operator++();
            iterator operator++(int);
            bool operator==(const iterator& other) const;
            bool operator!=(const iterator& other) const;

        private:
            Node* current;
        };

        class const_iterator {
        public:
            using iterator_category = std::forward_iterator_tag;
            using value_type = T;
            using difference_type = std::ptrdiff_t;
            using pointer = const T*;
            using reference = const T&;

            const_iterator(Node* node = nullptr);

            reference operator*() const;
            pointer operator->() const;
            const_iterator& operator++();
            const_iterator operator++(int);
            bool operator==(const const_iterator& other) const;
            bool operator!=(const const_iterator& other) const;

        private:
            Node* current;
        };
    };
} // namespace atlas

#include "forward_list.cpp"

#endif 
