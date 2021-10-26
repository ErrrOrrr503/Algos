#include <iostream>
#include <cinttypes>

int main ()
{
    int64_t S = 0, tmp = 0;
    while (!std::cin.eof ()) {
        S += tmp;
        tmp = 0;
        std::cin >> tmp;
    }
    S += tmp;
    std::cout << S;
    return 0;
}