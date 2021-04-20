#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

int n;
vector<int> arr, ans;

vector<int> Answer()
{
	vector<int> ret; 

	vector<bool> check(n, false);
	ret.push_back(arr[0]);
		
	check[0]=true;
	for(int i=0; i<n; i++)
	{
		if(check[i]) continue;
		
		if(ret.back()+1 != arr[i])
		{
			ret.push_back(arr[i]);
			check[i]=true;
			i=0;
		}
	}

	if(ret.size()!=n)
	{
		vector<int> temp;
		for(int i=0; i<n; i++)
			if(!check[i]) temp.push_back(arr[i]);
		
		vector<int>::iterator iter;
		iter = lower_bound(ret.begin(), ret.end(), temp[0]);
		if(*iter == temp[0])
			ret.insert(iter, temp.size(), temp[0]);
		else
		{
			iter = lower_bound(ret.begin(), ret.end(), ret.back());
			ret.insert(iter, temp.size(), temp[0]);
		}
	}
	
	return ret; 
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n;

	arr = vector<int>(n);
	for(int i=0; i<n; i++)
		cin>>arr[i];

	sort(arr.begin(), arr.end());
	ans = Answer();

	for(auto &p : ans)
		cout<<p<<' ';

	return 0;
}
