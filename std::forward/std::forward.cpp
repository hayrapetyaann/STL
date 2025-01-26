#include <iostream>
#include <type_traits>

namespace atlas {

    template <typename T>
    struct remove_reference {
        using type = T;
    };

    template <typename T>
    struct remove_reference<T&> {
        using type = T;
    };

    template <typename T>
    struct remove_reference<T&&> {
        using type = T;
    };

    template <class T>
    inline T&& forward(typename remove_reference<T>::type& t) noexcept {
        return static_cast<T&&>(t);
    }

    template <class T>
    inline T&& forward(typename remove_reference<T>::type&& t) noexcept {
        static_assert(!std::is_lvalue_reference<T>::value,
                      "Cannot forward an rvalue as an lvalue.");
        return static_cast<T&&>(t);
    }

    void check(int& x) {
        std::cout << "Lvalue" << std::endl;
    }

    void check(int&& x) {
        std::cout << "Rvalue" << std::endl;
    }

    template <typename T>
    void foo(T&& value) {
        check(forward<T>(value));
    }

} // namespace atlas

int main() {
    int a = 10;
    atlas::foo(a);    // Calls with an lvalue
    atlas::foo(20);   // Calls with an rvalue
}
