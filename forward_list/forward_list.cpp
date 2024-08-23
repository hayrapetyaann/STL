#include "forward_list.hpp"

namespace atlas {
    template <typename T>
    forward_list<T>::Node::Node(const T& d) : m_data(d), m_next(nullptr) {}

    template <typename T>
    forward_list<T>::forward_list() : m_head(nullptr) {}

    template <typename T>
    forward_list<T>::forward_list(size_type count) : m_head(nullptr) {
        while ((count--) > 0) {
            push_front(T());
        }
    }

    template <typename T>
    forward_list<T>::forward_list(const forward_list& other) : m_head(nullptr) {
        for (const auto& elem : other) {
            push_front(elem);
        }
        reverse();
    }

    template <typename T>
    forward_list<T>::forward_list(forward_list&& other) noexcept : m_head(other.m_head) {
        other.m_head = nullptr;
    }

    template <typename T>
    forward_list<T>::~forward_list() {
        clear();
    }

    template <typename T>
    forward_list<T>& forward_list<T>::operator=(const forward_list& other) {
        if (this != &other) {
            clear();
            for (const auto& elem : other) {
                push_front(elem);
            }
            reverse();
        }
        return *this;
    }

    template <typename T>
    typename forward_list<T>::reference forward_list<T>::front() {
        if (!m_head) {
            throw std::out_of_range("Empty list");
        }
        return m_head->m_data;
    }

    template <typename T>
    typename forward_list<T>::const_reference forward_list<T>::front() const {
        if (m_head == nullptr) {
            throw std::out_of_range("Empty list");
        }
        return m_head->m_data;
    }

    template <typename T>
    typename forward_list<T>::iterator forward_list<T>::begin() {
        return iterator(m_head);
    }

    template <typename T>
    typename forward_list<T>::iterator forward_list<T>::end() {
        return iterator(nullptr);
    }

    template <typename T>
    typename forward_list<T>::const_iterator forward_list<T>::begin() const {
        return const_iterator(m_head);
    }

    template <typename T>
    typename forward_list<T>::const_iterator forward_list<T>::end() const {
        return const_iterator(nullptr);
    }

    template <typename T>
    typename forward_list<T>::iterator forward_list<T>::before_begin() {
        return iterator(nullptr);
    }

    template <typename T>
    typename forward_list<T>::const_iterator forward_list<T>::cbefore_begin() const {
        return const_iterator(nullptr);
    }

    template <typename T>
    bool forward_list<T>::empty() const {
        return m_head == nullptr;
    }

    template <typename T>
    typename forward_list<T>::size_type forward_list<T>::max_size() const {
        return std::numeric_limits<size_type>::max();
    }

    template <typename T>
    void forward_list<T>::clear() {
        delete_list(m_head);
        m_head = nullptr;
    }

    template <typename T>
    void forward_list<T>::push_front(const T& value) {
        Node* new_node = new Node(value);
        new_node->m_next = m_head;
        m_head = new_node;
    }

    template <typename T>
    void forward_list<T>::pop_front() {
        if (m_head) {
            Node* old_head = m_head;
            m_head = m_head->m_next;
            delete old_head;
        }
    }

    template <typename T>
    void forward_list<T>::insert_after(iterator pos, const T& value) {
        if (pos.current != nullptr) {
            Node* new_node = new Node(value);
            new_node->m_next = pos.current->m_next;
            pos.current->m_next = new_node;
        }
    }

    template <typename T>
    void forward_list<T>::erase_after(iterator pos) {
        if (pos.current != nullptr && pos.current->m_next != nullptr) {
            Node* to_delete = pos.current->m_next;
            pos.current->m_next = to_delete->m_next;
            delete to_delete;
        }
    }

    template <typename T>
    void forward_list<T>::reverse() {
        Node* prev = nullptr;
        Node* current = m_head;
        Node* m_next = nullptr;

        while (current != nullptr) {
            m_next = current->m_next;
            current->m_next = prev;
            prev = current;
            current = m_next;
        }

        m_head = prev;
    }

    template <typename T>
    void forward_list<T>::remove(const T& value) {
        Node** current = &m_head;
        while (*current) {
            if ((*current)->m_data == value) {
                Node* tmp = *current;
                *current = (*current)->m_next;
                delete tmp;
            } else {
                current = &((*current)->m_next);
            }
        }
    }

    template <typename T>
    void forward_list<T>::sort() {
        if (!m_head) return;

        bool swapped;
        do {
            swapped = false;
            Node* current = m_head;
            while (current != nullptr && current->m_next != nullptr) {
                if (current->m_data > current->m_next->m_data) {
                    std::swap(current->m_data, current->m_next->m_data);
                    swapped = true;
                }
                current = current->m_next;
            }
        } while (swapped);
    }

    template <typename T>
        void forward_list<T>::delete_list(Node* node) {
            while (node != nullptr) {
                Node* next_node = node->m_next;
                delete node;
                node = next_node;
            }
    }

    template <typename T>
    forward_list<T>::iterator::iterator(Node* node) : current(node) {}

    template <typename T>
    typename forward_list<T>::iterator::reference forward_list<T>::iterator::operator*() const {
        return current->m_data;
    }

    template <typename T>
    typename forward_list<T>::iterator::pointer forward_list<T>::iterator::operator->() const {
        return &(current->m_data);
    }

    template <typename T>
    typename forward_list<T>::iterator& forward_list<T>::iterator::operator++() {
        current = current->m_next;
        return *this;
    }

    template <typename T>
    typename forward_list<T>::iterator forward_list<T>::iterator::operator++(int) {
        iterator tmp = *this;
        current = current->m_next;
        return tmp;
    }

    template <typename T>
    bool forward_list<T>::iterator::operator==(const iterator& other) const {
        return current == other.current;
    }

    template <typename T>
    bool forward_list<T>::iterator::operator!=(const iterator& other) const {
        return current != other.current;
    }

    template <typename T>
    forward_list<T>::const_iterator::const_iterator(Node* node) : current(node) {}

    template <typename T>
    typename forward_list<T>::const_iterator::reference forward_list<T>::const_iterator::operator*() const {
        return current->m_data;
    }

    template <typename T>
    typename forward_list<T>::const_iterator::pointer forward_list<T>::const_iterator::operator->() const {
        return &(current->m_data);
    }

    template <typename T>
    typename forward_list<T>::const_iterator& forward_list<T>::const_iterator::operator++() {
        current = current->m_next;
        return *this;
    }

    template <typename T>
    typename forward_list<T>::const_iterator forward_list<T>::const_iterator::operator++(int) {
        const_iterator tmp = *this;
        current = current->m_next;
        return tmp;
    }

    template <typename T>
    bool forward_list<T>::const_iterator::operator==(const const_iterator& other) const {
        return current == other.current;
    }

    template <typename T>
    bool forward_list<T>::const_iterator::operator!=(const const_iterator& other) const {
        return current != other.current;
    }

} // namespace atlas 
