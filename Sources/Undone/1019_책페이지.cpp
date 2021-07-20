#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <utility>
#include <algorithm>
using namespace std;

int n;
vector<vector<int> > arr;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n;



	vector<int> cnt(10, 0);
	for(int i=0; i<=n; i++)
	{
		for(int j=0; j<to_string(i).size(); j++)
			cnt[to_string(i)[j]-'0']++;		
	}

	for(int i=0; i<10; i++)
		cout<<cnt[i]<<' ';
	cout<<"\n------\n";


	arr.push_back({});
	for(int i=1; i<=9; i++)
	{
		vector<int> tmp(10, 0);

		for(int j=1; j<=9; j++)
			tmp[j] = pow(10, i-1) * i;
		
		string s="";
		for(int j=1; j<=i; j++)
			s.push_back('1');
		tmp[0] = tmp[1] - (stoi(s) - 1);

		arr.push_back(tmp);
	}

	vector<int> ans(10, 0);
	int idx = 0;
	while(1)
	{
		int cur = n%10;
		n/=10;
		if(n==0) break;

		if(idx==0)
		{
			for(int i=0; i<=cur; i++)
				ans[i]++;
				
		}
		else
		{
			for(int i=1; i<=cur; i++)
			{
				for(int i=0; i<=cur; i++)
					ans[i] += arr[idx][i];
				
				ans[i] += i * pow(10, idx+1);
			}
		}

		idx++;
	}

	for(int i=0; i<10; i++)
		cout<<ans[i]<<' ';
	cout<<'\n';

	return 0;
}
