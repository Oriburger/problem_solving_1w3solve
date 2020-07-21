#include <iostream>
#include <string>
using namespace std;

string s1, s2;
int dp[4001][4001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>s1>>s2;

	s1.insert(s1.begin(), '.');
	s2.insert(s2.begin(), '.');

	for(int i=0; i<s1.size(); i++)
	{
		for(int j=0; j<s2.size(); j++)
		{
			if(i==0 || j==0) dp[i][j]=0;

			else if(s1[i]==s2[j])
				dp[i][j] = dp[i-1][j-1] + 1;
			else
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}

	cout<<dp[s1.size()-1][s2.size()-1]<<'\n';

	return 0;
}
