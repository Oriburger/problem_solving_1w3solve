#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 1001;
const int dy[3] = {-1, 0};
const int dx[3] = {0, -1};

string s1, s2;
vector<char> ans;
int cache[MAX][MAX];

bool GetAnswer(int y, int x)
{
	if(cache[y][x]==0) return true;

	bool check = false;
	for(int i=0; i<2; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if(cache[y][x] == cache[ny][nx])
		{
			if(GetAnswer(ny, nx)) return true;
			check = true;
		}
	}
	if(!check)
	{
		int ny = y - 1, nx = x - 1;
		if(cache[y][x]-1 == cache[ny][nx])
		{
			ans.push_back(s1[y]);
			if(GetAnswer(ny, nx)) return true;
			ans.pop_back();
		}
	}

	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>s1>>s2;

	s1 = ' ' + s1;
	s2 = ' ' + s2;

	for(int i=1; i<s1.size(); i++)
	{
		for(int j=1; j<s2.size(); j++)
		{
			if(s1[i]==s2[j]) cache[i][j] = cache[i-1][j-1]+1;
			else cache[i][j] = max(cache[i][j-1], cache[i-1][j]);
		}
	}
	cout<<cache[s1.size()-1][s2.size()-1]<<'\n';
	
	GetAnswer(s1.size()-1, s2.size()-1);
	reverse(ans.begin(), ans.end());

	for(auto &p : ans) cout<<p;

	return 0;
}
