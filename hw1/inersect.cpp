#include <iostream>
using namespace std;

int main ()
{
    size_t n1, n2;
    cin >> n1 >> n2;
    ssize_t *ar1 = new ssize_t[n1];
    ssize_t *inters = new ssize_t[n2];
    for (size_t i = 0; i < n1; i++)
        cin >> ar1[i];
    size_t k = 0;
    for (size_t i = 0, j = 0; i < n2; i++) {
        ssize_t tmp;
        cin >> tmp;
        for ( ; ar1[j] < tmp && j < n1; j++) ;
        if (j == n1)
            break;
        if (ar1[j] == tmp) {
            inters[k] = tmp;
            k++;
        }
    }
    for (size_t i = 0; i < k; i++)
        cout << inters[i] << ' ';
    cout << endl;
    delete[] ar1;
    delete[] inters;
}