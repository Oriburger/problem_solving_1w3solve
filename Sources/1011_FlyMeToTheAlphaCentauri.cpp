#include <iostream>
#include <algorithm>
#define INF 2148000000
using namespace std;

typedef long long ll;
int t, x, y;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin>>t;
	
	while(t--)
	{
		cin>>x>>y;
		
		if(y-x < 2)
		{
			cout<<y-x<<'\n';
			continue;
		}
		
		ll sum=0;
		ll num=0;
		bool flag = false;
		for(int i=1; i<=INF; i++)
		{
			for(int j=0; j<=1; j++)
			{
				sum+=i;
				num++;
				
				if(sum>=y-x)
				{
					cout<<num<<'\n';
					flag = true;
					break;
				}
			}
			if(flag) break;
		}
	}
	
	return 0;
}
