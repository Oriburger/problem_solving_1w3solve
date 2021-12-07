#include <bits/stdc++.h>
using namespace std;

int n, ans=1;
string str;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n>>str;

	for(int i=0; i<str.size(); i++)
	{
		if(str[i]=='L') i++;
		ans+=1;
	}
	ans = min(n, ans);

	cout<<ans<<'\n';

	return 0;
}
