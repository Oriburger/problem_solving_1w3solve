#include <string>
#include <stack>
using namespace std;

bool solution(string s)
{
    stack<char> stk;
    
    for(auto &c : s)
    {
        if(!stk.empty() && stk.top()=='(' && c==')') stk.pop();
        else stk.push(c);
    }
        
    return stk.empty();
}
