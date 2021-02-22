#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <map>
using namespace std;

string str;
map<char, int> opRank; //연산자의 우선순위 저장

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	opRank['+']=0;
	opRank['-']=0;
	opRank['*']=1;
	opRank['/']=1; 
	opRank['(']=-1; //스택의 top가 '(' 일 수 있다.
	
	cin>>str;

	stack<char> stk;
	for(int i=0; i<str.size(); i++)
	{
		if(str[i]=='(') // '('를 만나면 스택에 push
			stk.push(str[i]);  
		else if(str[i]==')') //')'를 만나면, 출력과 pop을 한다.
		{	
			while(stk.top()!='(') //top가 '(' 일때까지
			{
				cout<<stk.top();
				stk.pop();
			}
			stk.pop(); // '('도 pop 해준다.
		}
		else if(str[i]>='A' && str[i]<='Z') //피연산자라면?
			cout<<str[i];
		else //연산자라면?
		{
			//스택이 빌때까지 && stk.top에 있는 연산자가 우선순위가 더 높다면
			//pop를 하며 위 조건이 어긋날때까지 반복한다. 
			while(!stk.empty() && opRank[stk.top()] >= opRank[str[i]])
			{
				cout<<stk.top(); //출력
				stk.pop(); //pop
			}
			stk.push(str[i]); //stk에 연산자를 push 
		}
	}

	while(!stk.empty()) //stk에 남은 연산자들을 출력
	{
		cout<<stk.top();
		stk.pop();
	}

	return 0;
}
