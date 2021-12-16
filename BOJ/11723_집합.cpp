#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int m;
bool check[21];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>m;
	
	while(m--)
	{
		string str; int n;

		cin>>str;
		
		if(str=="add")
		{
			cin>>n;
			check[n]=true;
		}
		else if(str=="remove")
		{
			cin>>n;
			check[n]=false;
		}
		else if(str=="check")
		{
			cin>>n;
			cout<<check[n]<<'\n';
		}
		else if(str=="toggle")
		{
			cin>>n;
			check[n]=!check[n];
		}
		else if(str=="all")
			memset(check, true, sizeof(check));
		else if(str=="empty")
			memset(check, false, sizeof(check));
	}

	return 0;
}
