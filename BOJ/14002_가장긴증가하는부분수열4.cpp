#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> s, cache, choices, ans;

int LIS(int start)
{
	int &ret = cache[start+1];
	if(ret != -1) return ret;

	ret = 1;
	int bestNext = -1;
	for(int next = start+1; next<n; next++)
	{
		if(start == -1 || s[start] < s[next])
		{
			int cand = LIS(next) + 1;
			if(cand > ret)
			{
				ret = cand;
				bestNext = next;
			}
		}
	}
	choices[start+1] = bestNext;
	return ret;
}

void reconstruct(int start)
{
	if(start != -1) ans.push_back(s[start]);
	int next = choices[start+1];
	if(next != -1) reconstruct(next);
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	s = vector<int>(1001, 0);
	choices = cache = vector<int>(1001, -1);

	cin>>n;

	for(int i=0; i<n; i++)
		cin>>s[i];

	cout<<LIS(-1)-1<<'\n';

	reconstruct(-1);
	for(auto &p : ans)
		cout<<p<<' ';

	return 0;
}
