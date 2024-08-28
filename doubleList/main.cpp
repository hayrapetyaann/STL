#include "list.hpp"
#include <iostream>

int main() {
    atlas::List<int> myList;

    myList.push_back(10);
    myList.push_back(20);
    myList.push_back(30);
    myList.push_front(5);

    for (auto it = myList.begin(); it != myList.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    for (auto rit = myList.rbegin(); rit != myList.rend(); ++rit) {
        std::cout << *rit << " ";
    }
    std::cout << std::endl;

    myList.pop_back();
    
    for (auto it = myList.begin(); it != myList.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    myList.push_front(1);
    myList.push_front(2);

    for (auto it = myList.begin(); it != myList.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    for (auto rit = myList.rbegin(); rit != myList.rend(); ++rit) {
        std::cout << *rit << " ";
    }
    std::cout << std::endl;

    myList.clear();

    myList.push_back(50);
    myList.push_back(30);
    myList.push_back(10);
    myList.push_back(40);
    myList.push_back(20);

    for (auto it = myList.begin(); it != myList.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    myList.sort();
    
    for (auto it = myList.begin(); it != myList.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    myList.reverse();
    
    for (auto it = myList.begin(); it != myList.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    for (auto cit = myList.cbegin(); cit != myList.cend(); ++cit) {
        std::cout << *cit << " ";
    }
    std::cout << std::endl;

    for (auto crit = myList.crbegin(); crit != myList.crend(); ++crit) {
        std::cout << *crit << " ";
    }
    std::cout << std::endl;

    return 0;
}
