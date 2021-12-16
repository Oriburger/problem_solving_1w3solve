#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string str[5];
int maxLen;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	for(int i=0; i<5; i++)
	{
		cin>>str[i];
		maxLen = maxLen > str[i].length() ? maxLen : str[i].length();
	}
	
	for(int i=0; i<maxLen; i++)
	{
		for(int j=0; j<5; j++)
		{
			if(str[j].length() <= i) continue;
			else cout<<str[j].at(i);
		}
	}
	
	
	return 0;
}
