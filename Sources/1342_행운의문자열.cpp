#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool isLucky(string s)
{
	for(int i=0; i<s.size()-1; i++)
		if(s[i]==s[i+1]) return false;
	
	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);

	string s;
	int ans=0;
	
	cin>>s;
	sort(s.begin(), s.end());

	do
	{
		if(isLucky(s)) ans++;
	}while(next_permutation(s.begin(), s.end()));

	cout<<ans<<'\n';

	return 0;
}
