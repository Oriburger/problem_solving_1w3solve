#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int n, s[1001], cache[1001], choice[1001];
vector<int> answer;

void reconstruct(int start)
{
	if(start != 0) answer.push_back(s[start]);
	int next = choice[start+1];
	if(next != -1) reconstruct(next);
}

int lis(int start)
{
	int& ret = cache[start];
	
	if(ret!=-1) return ret;
	
	ret = 1;
	int bestNext = -1;
	for(int next = start+1; next<=n; next++)
	{
		if(s[start] < s[next])
		{
			int nextLis = lis(next) + 1;
			if(ret < nextLis)
			{
				ret = nextLis;
				bestNext = next;
			}
		}
	}
	choice[start+1] = bestNext;
	
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>n;
	
	memset(cache, -1, sizeof(cache));
	for(int i=1; i<=n; i++) cin>>s[i];

	cout<<lis(0)-1<<'\n';
	
	reconstruct(0);
	
	for(int i=0; i<answer.size(); i++)
		cout<<answer[i]<<' ';
	cout<<'\n';
	
	return 0;
}
