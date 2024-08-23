#include "forward_list.hpp"

int main() {
    atlas::forward_list<int> list;
    list.push_front(1);
    list.push_front(2);
    list.push_front(3);

    std::cout << "List elements are: ";
    for (auto it = list.begin(); it != list.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    list.reverse();
    std::cout << "Reversed list elements are: ";
    for (auto it = list.begin(); it != list.end(); ++it) {
        std::cout << *it << " ";
    }

    std::cout << std::endl;

    list.pop_front();
    list.remove(2);
    list.push_front(9);
    for (auto it = list.begin(); it != list.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;


    return 0;
}
