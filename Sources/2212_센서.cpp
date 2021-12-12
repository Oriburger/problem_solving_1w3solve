#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> sensor, dist;

int GetAnswer()
{
	if(n <= k) return 0;

	int ret = 0;
	sort(sensor.begin(), sensor.end());

	for(int i=1; i<n; i++)
		dist.push_back(sensor[i]-sensor[i-1]);
	sort(dist.begin(), dist.end());

	for(int i=0; i<dist.size()-k+1; i++)
		ret += dist[i];
	
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin>>n>>k;

	sensor = vector<int>(n);
	for(int i=0; i<n; i++)
		cin>>sensor[i];
	
	cout<<GetAnswer()<<'\n';

	return 0;
}
