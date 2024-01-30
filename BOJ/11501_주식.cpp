#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int t, n;
vector<int> price;

ll getAnswer()
{
	ll ret = 0;
	ll cnt = 0, temp = 0, highest = price[0];
	for(int i=1; i<=n; i++)
	{
		if(i<n && highest > price[i])
		{
			cnt++; 
			temp += price[i];
			if(i==0)
				cnt = temp = 0;
		}
		else
		{
			ret += (highest * cnt - temp);
			cnt = temp = 0;
			highest = price[i];
		}
	}
	
	return ret;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin>>t; 
	
	while(t--)
	{
		cin>>n; 
	
		price = vector<int>(n);
		for(int i=0; i<n; i++)
			cin>>price[i];
			
		reverse(price.begin(), price.end());
		cout<<getAnswer()<<'\n';
	}
	return 0;
}
