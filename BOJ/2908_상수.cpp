#include <bits/stdc++.h>
using namespace std;

string str1, str2;

int main()
{
	cin>>str1>>str2;
	reverse(str1.begin(), str1.end());
	reverse(str2.begin(), str2.end());
	
	if(str1>str2) cout<<str1<<'\n';
	else cout<<str2<<'\n';
	return 0;
}	
