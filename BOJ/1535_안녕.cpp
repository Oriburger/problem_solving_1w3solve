#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int n, cache[21][101];
vector<int> L, J;

int GetAnswer(int idx, int hp)
{
	int& ret = cache[idx][hp];
	if(ret != -1) return ret;
	if(idx == n) return ret = 0;

	if(hp-L[idx] > 0) ret = max(ret, GetAnswer(idx+1, hp-L[idx])+J[idx]);
	ret = max(ret, GetAnswer(idx+1, hp));

	return ret; 
}

int main()
{
	ios::sync_with_stdio();
	cin.tie(NULL); cout.tie(NULL);

	cin>>n;
	
	L = J = vector<int>(n, 0);
	memset(cache, -1, sizeof(cache));
	for(int i=0; i<n; i++)
		cin>>L[i];
	for(int i=0; i<n; i++)
		cin>>J[i];

	cout<<GetAnswer(0, 100)<<'\n';

	return 0;
}
