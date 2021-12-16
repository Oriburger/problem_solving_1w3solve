#include <iostream>
#include <string>
using namespace std;

string n_str;
int n, m;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n_str>>m;

	n = stoi(n_str);

	if(n*n_str.length() >= m)
	{
		int idx=0;
		while(m--)
		{
			cout<<n_str[idx];

			idx++;
			if(idx==n_str.length()) idx=0;
		}
	}
	else 
	{
		for(int i=0; i<n; i++)
			cout<<n_str;
		cout<<'\n';
	}

	return 0;
}
