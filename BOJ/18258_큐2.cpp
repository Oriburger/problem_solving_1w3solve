#include <iostream>
#include <deque>
#include <string>
#include <algorithm>
using namespace std;

deque<int> deq;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n; 
	cin>>n;
	
	while(n--)
	{
		string cmd;
		cin>>cmd; 
		
		if(cmd == "push")
		{
			int val; cin>>val;
			
			deq.push_back(val);
		}
		else if(cmd == "pop")
		{
			cout<<(deq.empty() ? -1 : deq.front())<<'\n';
			if(!deq.empty()) deq.pop_front();
		}
		else if(cmd == "front")
			cout<<(deq.empty() ? -1 : deq.front())<<'\n';
			
		else if(cmd == "back")
			cout<<(deq.empty() ? -1 : deq.back())<<'\n';
			
		else if(cmd == "size")
			cout<<deq.size()<<'\n';
			
		else if(cmd == "empty")
			cout<<deq.empty()<<'\n';
	}	
	
	return 0;
}
