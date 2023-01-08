#include <iostream>
#include <stack>
#include <string>

using namespace std;

stack<int> stk;
string sel;
int N;

int pop()
{
    if(stk.empty()) return -1;
	int temp = stk.top();
	stk.pop();
    return temp;
}
    
int main()
{
    cin>>N;
    
    for(int i=0; i<N; i++)
    {
        cin>>sel;
        
        if(sel == "push")
        {
            int X; cin>>X;
            stk.push(X);
        }
        else if(sel == "pop")
            cout<<pop()<<endl;
        else if(sel == "size")
            cout<<stk.size()<<endl;
        else if(sel == "empty")
            cout<<stk.empty()<<endl;
        else if(sel == "top")
            cout<<(stk.empty() ? -1 : stk.top())<<endl;
    }
	return 0;
}
