#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    int p, y; p = y = 0;
    
    for(auto& c : s)
    {
        c = tolower(c);
        if(c == 'p') p++;
        else if(c == 'y') y++;
    }
    
    return p==y;
}
