#include <string>
#include <vector>

using namespace std;

bool solution(string s)
{
    for(const char &c : s)
    {
        if(c >= '0' && c <= '9') continue;
        return false;
    }
    
    return (s.size()==4 || s.size()==6);
}
