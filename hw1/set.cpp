#include <iostream>
#include <set>
using namespace std;

int main ()
{
    set<int> A;
    int tmp;
    while (1) {
        cin >> tmp;
        if (!tmp)
            break;
        A.insert (tmp);
    }
    set<int> SUB;
    while (1) {
        cin >> tmp;
        if (!tmp)
            break;
        if (A.find (tmp) == A.end ()) {
            SUB.insert (tmp);
            continue;
        }
        A.erase (tmp);
    }
    for (auto it = A.begin (); it != A.end (); it++)
    {
        SUB.insert (*it);
    }
    for (auto it = A.begin (); it != A.end (); it++)
    {
        SUB.insert (*it);
    }
    for (auto it = SUB.begin (); it != SUB.end (); it++)
    {
        cout << *it << ' ';
    }
    cout << endl;
}