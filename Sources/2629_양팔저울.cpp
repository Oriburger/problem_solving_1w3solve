#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int n, m;
int w[31], ball[8];
int cache[31][15001];
vector<char> ans;

void GetAnswer(int idx, int curr)
{
	if(idx > n) return;

	int &ret = cache[idx][curr];
	if(ret != -1) return;

	ret = 1;

	GetAnswer(idx+1, curr);
	GetAnswer(idx+1, curr+w[idx]);
	GetAnswer(idx+1, abs(curr-w[idx]));
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	memset(cache, -1, sizeof(cache));

	cin>>n;
	for(int i=0; i<n; i++) 
		cin>>w[i];
	
	cin>>m;
	for(int i=0; i<m; i++)
		cin>>ball[i];
	
	GetAnswer(0, 0);
	for(int i=0; i<m; i++)
	{
		if(ball[i] > 15000)
		{
			ans.push_back('N');
			continue;
		}

		if(cache[n][ball[i]]==1) ans.push_back('Y');
		else ans.push_back('N');
	}

	for(auto &p : ans)
		cout<<p<<' ';

	return 0;
}
