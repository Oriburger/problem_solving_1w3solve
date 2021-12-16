#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	while(1)
	{
		string str;
		stack<char> stk;
		bool flag=false;
		
		getline(cin, str);

		if(str.size()==1 && str[0]=='.') break;

		for(int i=0; i<str.size(); i++)
		{	
			if(str[i]=='[' || str[i]=='(')
				stk.push(str[i]);

			else if(str[i]==']')
			{
				if(!stk.empty() && stk.top()=='[') stk.pop();
				else
				{
					flag = true;
					break;
				}
			}
			else if(str[i]==')')
			{
				if(!stk.empty() && stk.top()=='(') stk.pop();
				else
				{
					flag = true;
					break;
				}
			}
		}

		if(!flag && stk.empty())
			cout<<"yes\n";
		else
			cout<<"no\n";
	}

	return 0;
}
