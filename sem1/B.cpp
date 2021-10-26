#include <iostream>
using namespace std;

int f (int n, int k, int l);

int main ()
{
    int N, K, L;
    cin >> N >> K >> L;
    f (N, K, L);
    cout << endl;
    return 0;
}

int f (int n, int k, int l)
{
    if (n <= 0)
        return 1;
    if (k == 1) {
        cout << (char) ('a' + (n - 1));
        if (k < l)
            k++;
    }
    if (k <= (1 << (n - 1))) {
        if (l <= (1 << (n - 1))) {
            f (n - 1, k - 1, l - 1);
        }
        if (l > (1 << (n - 1))) {
            f (n - 1, k - 1, (1 << (n - 1)) - 1);
            f (n - 1, 1, l - (1 << (n - 1)));
        }
    }
    if (k > (1 << (n - 1))) {
        f (n - 1, k - (1 << (n - 1)), l - (1 << (n - 1)));
    }
    return 0;
}