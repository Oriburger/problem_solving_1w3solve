#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 1001;
const int dy[3] = {-1, 0};
const int dx[3] = {0, -1};

bool flag = false;
string s1, s2;
vector<char> ans;
int cache[MAX][MAX];

void GetAnswer(int y, int x)
{
	if(flag) return;
	if(cache[y][x]==0)
	{
		flag = true; 
		return;
	}

	bool check = false;
	for(int i=0; i<2; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if(cache[y][x] == cache[ny][nx])
		{
			GetAnswer(ny, nx);
			if(flag) return;
			check = true;
		}
	}
	if(!check)
	{
		int ny = y - 1, nx = x - 1;
		if(cache[y][x]-1 == cache[ny][nx])
		{
			ans.push_back(s1[y]);
			GetAnswer(ny, nx);
			if(flag) return;
			ans.pop_back();
		}
	}
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
