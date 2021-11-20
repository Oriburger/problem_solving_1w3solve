#include <string>
#include <vector>
using namespace std;

inline string ctostr(char &c)
{
    string str;
    str.push_back(c);
    return str;
}
    

string solution(string s)
{
    string ret;
    
    if(s.size()%2) ret = s[s.size()/2];
    else ret = ctostr(s[s.size()/2-1]) + ctostr(s[s.size()/2]);
    
    return ret;
}
