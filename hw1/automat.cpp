#include <iostream>
using namespace std;

int main ()
{
    size_t N;
    ssize_t coin_amount = 0;
    ssize_t coin_need = 0;
    cin >> N;
    for (size_t i = 0; i < N; i++) {
        int income;
        cin >> income;
        if (income == 5)
            coin_amount++;
        coin_amount -= (income - 5) / 5;
        if (coin_amount < coin_need)
            coin_need = coin_amount;
    }
    if (coin_need >= 0)
        coin_need = 0;
    cout << -coin_need << endl;
}
