#include <iostream>
#include <vector>
#include <algorithm>
#include <utility> 
using namespace std;

typedef pair<int,int> P;

const int MIN_INF = -210000000;

int n;
vector<P> s;
vector<int> arr;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>n;
	
	arr.push_back(MIN_INF);
	for(int i=0; i<n; i++)
	{
		int a, b;
		cin>>a>>b;
		s.push_back({a, b});
	}	
	sort(s.begin(), s.end());

	
	for(int i=0; i<n; i++)
	{
		if(s[i].second > arr.back())
			arr.push_back(s[i].second);
		
		else
		{
			vector<int>::iterator iterPos = lower_bound(arr.begin(), arr.end(), s[i].second);
			*iterPos = s[i].second;
		}
	}
	
	cout<<n-(arr.size()-1)<<'\n';
	
	return 0;
}
