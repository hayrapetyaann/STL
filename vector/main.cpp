#include "vector.hpp"

int main() {
    atlas::vector<int> vec = { 1, 2, 3, 4, 5 };

    for (auto it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    const atlas::vector<int> const_vec = { 10, 20, 30, 40, 50 };
    for (auto it = const_vec.begin(); it != const_vec.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    

    for (auto rit = vec.rbegin(); rit != vec.rend(); ++rit) {
        std::cout << *rit << " ";
    }
    std::cout << std::endl;

    return 0;
}
