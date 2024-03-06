#include <iostream>
#include <string>
using namespace std;

string str; 
int n, p, q; 
char ch;

int sum[26][200001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin>>str>>n;
	
	for(int i=0; i<26; i++)
	{
		ch = i + 'a';
		
		for(int j=0; j<str.size(); j++)
		{
			if(j==0) sum[i][j] = (str[j] == ch);
			else sum[i][j] = sum[i][j-1] + (str[j] == ch);
		}
	}
	
	while(n--)
	{
		cin>>ch>>p>>q;
		
		if(p > 0) cout<<sum[ch-'a'][q] - sum[ch-'a'][p-1]<<'\n';
		else cout<<sum[ch-'a'][q]<<'\n';
	}
	
	return 0;
}
