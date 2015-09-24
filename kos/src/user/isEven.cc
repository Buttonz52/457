#include <iostream>
#include <syscalls.h>
#include <string>

using namespace std;

int main()
{
    bool even = isEven(52);
    
    if(even == 0)
    {
        cout << "THE NUMBER IS ODD" << endl;    
    }
    else
    {
        cout << "THE NUMBER IS EVEN" << endl;  
    }

    return 0;    
}
