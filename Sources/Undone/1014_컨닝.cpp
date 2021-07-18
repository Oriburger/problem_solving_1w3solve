#include <iostream>
#include <cstring>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

typedef pair<int, int> P;
const int MAX = 10;
const int INF = 2147000000;

int n, m;
char board[11][11];
int cache[MAX][MAX][(1<<MAX)][(1<<MAX)];
vector<P> st_pos;

bool isVisited(int state, int pos)
{
	if(pos < 0 || pos >= m) return false;

	int visited = (1<<MAX);
	if(state & (1<<pos)) return true;
	return false;
}

int GetAnswer(int y, int x, int cur_state, const int prev_state)
{
	if(y<0 || x>=m) return 0;

	int &ret = cache[y][x][cur_state][prev_state];
	if(ret != -1) return ret;

	ret = 0;
	int visited = (1<<MAX);

	if( !isVisited(cur_state, x-1) && !isVisited(prev_state, x-1)
		&& !isVisited(prev_state, x+1) && board[y][x] != 'x')
	{
		ret = max(ret, GetAnswer(y, x+1, (cur_state | (1<<x)), prev_state) + 1);
		ret = max(ret, GetAnswer(y-1, 0, (cur_state | (1<<x)), prev_state) + 1);
	}
	ret = max(ret, GetAnswer(y, x+1, cur_state, prev_state));
	ret = max(ret, GetAnswer(y-1, 0, 0, cur_state));

	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t;
	cin>>t;

	while(t--)
	{
		cin>>n>>m;

		memset(board, 0, sizeof(board));
		memset(cache, -1, sizeof(cache));

		for(int i=0; i<n; i++)
			for(int j=0; j<m; j++)
				cin>>board[i][j];
		
		cout<<GetAnswer(n-1, 0, 0, 0)<<'\n';
	}

	return 0;
}
