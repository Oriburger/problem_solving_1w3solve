#include <bits/stdc++.h>
using namespace std;

int n, m, d, ans;
const int INF = INT_MAX;
vector<int> archer;
vector<vector<int> > board;

typedef pair<int, int> P;

inline int GetDist(P p, P q)
{
	return abs(p.first-q.first) + abs(p.second - q.second);
}

int GetAnswer(vector<vector<int> > board)
{
	int ret = 0;
	vector<int> pos;
	for(int i=0; i<m; i++)
		if(archer[i]) pos.push_back(i);

	for(int r=n; r>=1; r--)
	{
		vector<P> target(3, {-1, -1});
		for(int k=0; k<3; k++)
		{
			int min_dist = INF;
			for(int j=0; j<m; j++)
			for(int i=0; i<r; i++)
			{
				if(board[i][j]==0) continue;
				int temp = GetDist(P(r, pos[k]), P(i, j));
				
				if(temp <= d && min_dist > temp)
				{
					min_dist = temp;
					target[k] = {i, j};
				}
			}
		}

		for(auto &p : target)
		{
			if(p == P(-1, -1)) continue;
			if(board[p.first][p.second]==1)
			{
				ret+=1;
				board[p.first][p.second] = 0;
			}
		}
	}

	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n>>m>>d;

	board = vector<vector<int> >(n, vector<int>(m));
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			cin>>board[i][j];
	
	for(int i=0; i<m; i++)
		archer.push_back(i>=m-3 ? 1 : 0);

	do
	{		
		ans = max(ans, GetAnswer(board));
	}while(next_permutation(archer.begin(), archer.end()));

	cout<<ans<<'\n';

	return 0;
}
