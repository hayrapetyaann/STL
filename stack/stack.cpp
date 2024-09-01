#include "stack.hpp"

namespace atlas {
    template <typename T, typename Container>
    stack<T, Container>::stack() : c() {}

    template <typename T, typename Container>
    stack<T, Container>::stack(const Container& cont) : c(cont) {}

    template <typename T, typename Container>
    stack<T, Container>::stack(Container&& cont) : c(std::move(cont)) {}

    template <typename T, typename Container>
    stack<T, Container>::stack(const stack& other) : c(other.c) {}

    template <typename T, typename Container>
    stack<T, Container>::stack(stack&& other) noexcept : c(std::move(other.c)) {}

    template <typename T, typename Container>
    template <class InputIt>
    stack<T, Container>::stack(InputIt first, InputIt last) {
        while (first != last) {
            c.push_back(*first++);
        }
    }

    template <typename T, typename Container>
    stack<T, Container>::~stack() = default;

    template <typename T, typename Container>
    stack<T, Container>& stack<T, Container>::operator=(const stack& other) {
        if (this != &other) {
            c = other.c;
        }
        return *this;
    }

    template <typename T, typename Container>
    stack<T, Container>& stack<T, Container>::operator=(stack&& other) noexcept {
        if (this != &other) {
            c = std::move(other.c);
        }
        return *this;
    }

    template <typename T, typename Container>
    typename stack<T, Container>::reference stack<T, Container>::top() {
        if (c.empty()) {
            throw std::out_of_range("Stack is empty");
        }
        return c.back();
    }

    template <typename T, typename Container>
    typename stack<T, Container>::const_reference stack<T, Container>::top() const {
        if (c.empty()) {
            throw std::out_of_range("Stack is empty");
        }
        return c.back();
    }

    template <typename T, typename Container>
    bool stack<T, Container>::empty() const noexcept {
        return c.empty();
    }

    template <typename T, typename Container>
    typename stack<T, Container>::size_type stack<T, Container>::size() const noexcept {
        return c.size();
    }

    template <typename T, typename Container>
    void stack<T, Container>::push(const value_type& value) {
        c.push_back(value);
    }

    template <typename T, typename Container>
    void stack<T, Container>::push(value_type&& value) {
        c.push_back(std::move(value));
    }

    template <typename T, typename Container>
    template <class... Args>
    void stack<T, Container>::emplace(Args&&... args) {
        c.emplace_back(std::forward<Args>(args)...);
    }

    template <typename T, typename Container>
    void stack<T, Container>::pop() {
        if (c.empty()) {
            throw std::out_of_range("Stack is empty");
        }
        c.pop_back();
    }

    template <typename T, typename Container>
    void stack<T, Container>::swap(stack& other) noexcept {
        using std::swap;
        swap(c, other.c);
    }

} // namespace atlas
