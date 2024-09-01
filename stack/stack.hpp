#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>
#include <deque>
#include <iterator>
#include <utility>
#include <stdexcept>

namespace atlas {

template <typename T, typename Container = std::deque<T>>
class stack {
public:
    using container_type = Container;
    using value_type = typename Container::value_type;
    using size_type = typename Container::size_type;
    using reference = typename Container::reference;
    using const_reference = typename Container::const_reference;

    stack();
    explicit stack(const Container& cont);
    explicit stack(Container&& cont);
    stack(const stack& other);
    stack(stack&& other) noexcept;
    template <class InputIt>
    stack(InputIt first, InputIt last);
    ~stack();

    stack& operator=(const stack& other);
    stack& operator=(stack&& other) noexcept;

    reference top();
    const_reference top() const;

    bool empty() const noexcept;
    size_type size() const noexcept;

    void push(const value_type& value);
    void push(value_type&& value);
    template <class... Args>
    void emplace(Args&&... args);
    void pop();
    void swap(stack& other) noexcept;

    friend bool operator==(const stack& lhs, const stack& rhs) {
        return lhs.c == rhs.c;
    }
    friend bool operator!=(const stack& lhs, const stack& rhs) {
        return !(lhs == rhs);
    }
    friend bool operator<(const stack& lhs, const stack& rhs) {
        return lhs.c < rhs.c;
    }
    friend bool operator<=(const stack& lhs, const stack& rhs) {
        return !(rhs < lhs);
    }
    friend bool operator>(const stack& lhs, const stack& rhs) {
        return rhs < lhs;
    }
    friend bool operator>=(const stack& lhs, const stack& rhs) {
        return !(lhs < rhs);
    }
    friend void swap(stack& lhs, stack& rhs) noexcept {
        lhs.swap(rhs);
    }

private:
    Container c;
};

} // namespace atlas


#endif
