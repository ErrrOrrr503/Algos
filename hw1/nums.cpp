#include <iostream>
using namespace std;

int f (size_t n, size_t m);

int main ()
{
    size_t N, M;
    cin >> N >> M;
    size_t *m = new size_t[M];
    for (size_t i = 0; i < M; i++)
        cin >> m[i];
    for (size_t i = 0; i < M; i++)
        f (N, m[i]);
    cout << endl;
    delete[] m;
    return 0;
}

int f (size_t n, size_t m)
{
    if (!n)
        return 1;
    size_t n_sz = 0;
    size_t n1 = n;
    for (n1 = n; n1 > 0; n1 /= 10)
        n_sz++;
    n1 = n;
    if (m <= n_sz) {
        for (size_t i = n_sz; i > m; i--)
            n1 /= 10;
        cout << n1 % 10;
        return 0;
    }
    size_t len = (1 << n) - 1;
    if (n > 9)
        len = (1 << n) + (1 << (n - 9)) - 2;
    if (m <= (len - n_sz) / 2 + n_sz)
        f (n - 1, m - n_sz);
    else
        f (n - 1, (len - n_sz) / 2 + 1 - (m - n_sz - (len - n_sz) / 2));
    return 0;
}