#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	string str;
	getline(cin, str);
	
	for(auto &p : str)
	{
	  int next = p;
		if(next>='a' && next<='z')
		{
			next+=13;
			if(next>'z') next-=26;
		}
		else if(next>='A' && next<='Z')
		{
			next+=13;
			if(next>'Z') next-=26;
		}
		p=next;
	}
	
	cout<<str<<"\n";
	
	return 0;
}
