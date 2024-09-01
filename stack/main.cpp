#include "stack.hpp"

int main() {
    atlas::stack<int> s;

    s.push(1);
    s.push(2);
    s.push(3);
    std::cout << "Top element: " << s.top() << std::endl;

    s.pop();
    std::cout << "New top element after pop: " << s.top() << std::endl;

    std::cout << "Stack empty: " << (s.empty() ? "Yes" : "No") << std::endl;

    std::cout << "Stack size: " << s.size() << std::endl;

    atlas::stack<int> s2;
    s2.push(10);
    s2.push(20);

    std::cout << "Top element of s2 before swap: " << s2.top() << std::endl;

    s.swap(s2);

    std::cout << "Top element of s after swap: " << s.top() << std::endl;
    std::cout << "Top element of s2 after swap: " << s2.top() << std::endl;
    std::cout << "Stacks equal after swap: " << (s == s2 ? "Yes" : "No") << std::endl;

    return 0;
}
