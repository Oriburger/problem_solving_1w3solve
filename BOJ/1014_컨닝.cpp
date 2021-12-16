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
//현재 좌표가 (y, x)이고, 현재 y줄의 학생 배치 상태가 cur_state
//y+1줄의 학생 배치 상태가 prev_state 일 때, 구할 수 있는 최대 학생 수

//state 상태에서 pos 번쨰 비트가 켜져있는지?
bool isVisited(int state, int pos)
{
	if(pos < 0 || pos >= m) return false;

	int visited = (1<<MAX);
	if(state & (1<<pos)) return true;
	return false;
}

int GetAnswer(int y, int x, int cur_state, const int prev_state)
{
	if(y<0 || x>=m) return 0; //기저사례 : 보드 범위를 벗어나면 0 반환

	int &ret = cache[y][x][cur_state][prev_state];
	if(ret != -1) return ret;

	ret = 0;
	//만약, 현재 줄과 아랫 줄의 상태를 고려하여, 학생 배치가 가능하다면?
	if( !isVisited(cur_state, x-1) && !isVisited(prev_state, x-1) 
		&& !isVisited(prev_state, x+1) && board[y][x] != 'x')
	{
		//우로 한칸
		ret = max(ret, GetAnswer(y, x+1, (cur_state | (1<<x)), prev_state) + 1);
		//혹은 아랫줄 (prev_state은 cur_state가 된다)
		ret = max(ret, GetAnswer(y-1, 0, 0, (cur_state | (1<<x))) + 1);
	}
	//학생을 배치하지 않을 경우 
	//우로 한칸
	ret = max(ret, GetAnswer(y, x+1, cur_state, prev_state));
	//혹은 아랫줄 (prev_state은 cur_state가 된다)
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
