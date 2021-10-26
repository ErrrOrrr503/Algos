#include <iostream>
#include <stack>

int main ()
{
    std::stack<char> stack;
    bool operate = 1;
    while (operate) {
        switch (std::cin.get ()) {
            case ('\n'):
                operate = 0;
                break;
            case (EOF):
                operate = 0;
                break;
            case ('a'):
                if (!stack.empty () && stack.top () == 'b') {
                    stack.pop ();
                    break;
                }
                stack.push ('a');
                break;
            case ('b'):
                if (!stack.empty () && stack.top () == 'a') {
                    stack.pop ();
                    break;
                }
                stack.push ('b');
                break;
            default:
                break;
        }
    }
    if (stack.empty ()) {
        std::cout << "YES" << std::endl;
        return 0;
    }
    std::cout << "NO" << std::endl;
    return 0;
}