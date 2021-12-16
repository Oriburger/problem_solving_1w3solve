#include <iostream>
#include <vector>
#include <string>
using namespace std;

int t, ans=0;
string s;
vector<bool> check;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>t;

	while(t--)
	{
		cin>>s;
		check.resize(26, false);
		
		for(char &p : s)
			check[p-'A']=true;
		
		for(int i=0; i<26; i++)
			if(!check[i])
				ans+=('A'+i);

		cout<<ans<<'\n';

		ans=0;
		check.clear();
	}

	return 0;
}
