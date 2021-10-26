#include <iostream>
using namespace std;

int main ()
{
    size_t N;
    cin >> N;
    unsigned *money = new unsigned[N];
    for (size_t i = 0; i < N; i++)
        cin >> money[i];
    size_t S = 0;
    for (size_t i = 0; i < N; i++) {
        if (S + 1 < money[i]) {
            cout << S + 1 << endl;
            delete[] money;
            return 0;
        }
        S += money[i];
    }
    cout << S + 1 << endl;
    delete[] money;
    return 0;
}