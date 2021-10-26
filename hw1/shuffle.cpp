#include <iostream>
#include <vector>
#include <map>

int f (size_t n, size_t m, std::vector<size_t> &shuffle_elem);
size_t fact (size_t n);

int main () {
    size_t N, M;
    std::cin >> N >> M;
    std::vector<size_t> shuffle_elem;
    for (size_t i = 1; i <= N; i++)
        shuffle_elem.push_back (i);
    f (N, M, shuffle_elem);
    return 0;
}

int f (size_t n, size_t m, std::vector<size_t> &shuffle_elem)
{
    if (n == 1) {
        std::cout << shuffle_elem[0] << std::endl;
        return 0;
    }
    std::cout << shuffle_elem[(m - 1) / fact (n - 1)] << ' ';
    shuffle_elem.erase (shuffle_elem.begin () + (m - 1) / fact (n - 1));
    f (n - 1, (m - 1) % fact (n - 1) + 1, shuffle_elem);
    return 0;
}

size_t fact (size_t n)
{
    if (!n)
        return 1;
    static std::map<size_t, size_t> mem;
    auto res = mem.find (n);
    if (res != mem.end ())
        return res->second;
    size_t fact = n;
    for (size_t i = n - 1; i > 0; i--)
        fact *= i;
    mem.insert ({n, fact});
    return fact;
}