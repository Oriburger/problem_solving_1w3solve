#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int GetSum(string s)
{
	int ret = 0;
	for(int i=0; i<s.size(); i++)
		ret += s[i]-'0';
	return ret;
}

int main()
{
	string s;
	cin>>s;

	for(const char &c : s)
	{
		int k = GetSum(to_string((int)c));
		
		while(k--) cout<<c;
		cout<<'\n';
	}

	return 0;
}
