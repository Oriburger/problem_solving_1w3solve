#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 1001;

int n, k, w[MAX], v[MAX];
int cache[10001][MAX];

int Answer(int curr, int idx)
{
	if(idx==k) return 0;

	int &ret = cache[curr][idx];
	if(ret != -1) return ret;

	ret = Answer(curr, idx+1);

	if(curr - w[idx] >= 0)
		ret = max(ret, Answer(curr-w[idx], idx+1) + v[idx]);
	
	return ret; 
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n>>k;

	memset(cache, -1, sizeof(cache));
	for(int i=0; i<k; i++)
		cin>>v[i]>>w[i];

	cout<<Answer(n, 0)<<'\n';

	return 0;
}
