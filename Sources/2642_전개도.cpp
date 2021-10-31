#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> P;

const int dy[4] = {1, -1, 0, 0}; //BFS에 사용
const int dx[4] = {0, 0, 1, -1};

//짝을 찾을 수 있는 옳은 경우들
const vector<P> correct[4] = {{{0,1}, {1,1}, {1,2}}
			              	,{{0,1}, {0,2}}
			            	,{{1,0}, {1,1}, {1,2}, {2,2}}
			            	,{{1,0}, {1,1}, {1,2}, {1,3}, {2,3}}};
const P dir[4] = {{1,1}, {1, -1}, {-1, 1}, {-1, -1}}; //correct를 4방향으로 탐색

int board[6][6]; //입력으로 주어질 2차원 배열
bool visited[6][6]; //BFS를 통한 방문 여부
int answer[6]; //answer[i] : i의 맞은편에 있는 칸의 번호

void BFS(int y, int x) //BFS, 주석 생략.
{
	queue<P> q;
	q.push({y, x});
	visited[y][x] = true;

	while(!q.empty())
	{
		P curr = q.front();
		q.pop();

		for(int i=0; i<4; i++)
		{
			P next = {curr.first + dy[i]
						, curr.second + dx[i]};
			
			if(next.first<0 || next.second<0 
				|| next.first>=6 || next.second>=6) continue;
			if(visited[next.first][next.second]) continue;

			visited[next.first][next.second] = true;
			q.push(next);
		}
	}
}

int get_answer()
{
	int ret = 0;
	bool bfs_flag = false; //BFS가 2번이상 호출되는지 판별하기 위한 변수

	for(int y=0; y<6; y++)
	{
		for(int x=0; x<6; x++)
		{
			if(!board[y][x]) continue;
			if(!visited[y][x]) //bfs를 통해 방문체크가 되지 않은 칸이라면
			{
                //이미 bfs를 실행한 상태라면? 잘못된 경우이므로 0반환
				if(bfs_flag) return 0; 
					
				BFS(y, x); //BFS 탐색
				bfs_flag = true; //bfs_flag 체크
			}

			for(int s=0; s<=1; s++) //좌-우 반전
			for(int d=0; d<4; d++) //4방향 탐색
			for(const vector<P> &p : correct) //correct의 각 경우에 대해 시도
			{
				bool find_flag = true; //맞은편의 찾았는지 여부 판단
				int pair_val = 0; //맞은편의 값
				for(int i=0; i<p.size(); i++)
				{
					int ny, nx;

					if(!s)
					{
						ny = y + p[i].first * dir[d].first;
						nx = x + p[i].second * dir[d].second;
					}
					else
					{
						ny = y + p[i].second * dir[d].second;
						nx = x + p[i].first * dir[d].first;
					}

					if(ny<0 || nx<0 || ny>=6 || nx>=6) find_flag = false;
					if(!board[ny][nx]) find_flag = false;
					if(!find_flag) break;
					
                    //맞은편의 상대 좌표는 p[p.size()-1]
					pair_val = board[ny][nx];
				}
				
				if(find_flag)
				{
                    //기존에 찾았던 '맞은편 칸'말고 또 다른 '맞은편 칸'을 찾았다면?
					if(answer[board[y][x]] && answer[board[y][x]]!=pair_val) 
						return 0; //잘못된 경우이므로 0 반환
					
					answer[board[y][x]] = pair_val; //answer 배열 갱신
					if(board[y][x]==1) ret = pair_val; //1일 경우, 이 함수의 반환값이 됨
                    //--> answer 배열로 두지않고, 변수 하나로 둬도 될 것 같네요😂
				}
			}
		}
	}
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for(int i=0; i<6; i++)
		for(int j=0; j<6; j++)
			cin>>board[i][j];
	
	cout<<get_answer()<<'\n';

	return 0;
}
