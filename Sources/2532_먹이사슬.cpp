#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

typedef vector<int>::iterator ITERPOS;
typedef pair<int, int> P;
const int MAX = 500000;

int n;
vector<P> arr;
vector<int> temp;

bool comp(const P& p, const P& q)
{
	if(p.first == q.first) return p.second > q.second;
	return p.first < q.first;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n;

	for(int i=0; i<n; i++)
	{
		int idx, l, r;
		cin>>idx>>l>>r;
		arr.push_back({l, r});
	}
	sort(arr.begin(), arr.end(), comp);
	arr.erase(unique(arr.begin(), arr.end()), arr.end());

	temp.push_back(-1);
	for(int i=n-1; i>=0; i--)
	{
	//	cout<<arr[i].first<<' '<<arr[i].second<<'\n';

		if(i < n-1 && arr[i].first == arr[i+1].first
				   && arr[i].second == arr[i+1].second) continue;

		if(temp.back() <= arr[i].second)
			temp.push_back(arr[i].second);
		else
		{
			ITERPOS iter = upper_bound(temp.begin(), temp.end(), arr[i].second);
			*iter = arr[i].second;
		}
	}	

	cout<<temp.size()-1<<'\n';

	return 0;
}
