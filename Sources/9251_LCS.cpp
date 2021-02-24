#include <iostream>
#include <string>
using namespace std;

const int MAX = 1001;
int cache[MAX][MAX];
string s1, s2;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>s1>>s2;

	s1 = ' ' + s1;
	s2 = ' ' + s2;

	for(int i=1; i<s1.size(); i++)
	{
		for(int j=1; j<s2.size(); j++)
		{
			if(s1[i]==s2[j]) cache[i][j] = cache[i-1][j-1]+1;
			else cache[i][j] = max(cache[i][j-1], cache[i-1][j]);
		}
	}
	
	cout<<cache[s1.size()-1][s2.size()-1]<<'\n';

	return 0;
}
