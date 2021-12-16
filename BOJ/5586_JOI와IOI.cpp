#include <iostream>
#include <string>
using namespace std;

string s;
int jCnt, iCnt;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>s;

	for(int i=2; i<s.length(); i++)
	{
		if(s[i-2]=='I' && s[i-1]=='O' && s[i]=='I') iCnt++;
		else if(s[i-2]=='J' && s[i-1]=='O' && s[i]=='I') jCnt++;
	}
	
	cout<<jCnt<<'\n'<<iCnt<<'\n';

	return 0;
}
