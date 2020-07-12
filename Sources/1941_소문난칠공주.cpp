#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>
using namespace std;

const int dy[4]={1,-1,0,0};
const int dx[4]={0,0,1,-1};

char board[5][5];
vector<int> combi(25, 0);

int BFS(int y, int x)
{
	int ret=1;
	queue<pair<int, int> > q;
	bool visited[5][5]={0};

	q.push({y, x});
	visited[y][x]=true;

	while(!q.empty())
	{
		pair<int, int> curr = q.front();
		q.pop();

		for(int i=0; i<4; i++)
		{
			int ny = dy[i] + curr.first;
			int nx = dx[i] + curr.second;
			
			if(ny<0 || nx<0 || ny>=5 || nx>=5) continue;
			if(visited[ny][nx]) continue;
			if(!combi[ny*5+nx]) continue;

			visited[ny][nx]=true;
			q.push({ny,nx});
			ret++;
		}
	}

	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for(int i=0; i<5; i++)
	for(int j=0; j<5; j++)
		cin>>board[i][j];

	for(int i=18; i<25; i++) combi[i]=1;

	int answer=0;
	do
	{
		bool flag=true;
		int sCnt=0, yCnt=0;
		for(int i=0; i<25; i++)
		{
			if(combi[i])
			{
				if(flag)
				{
					if(BFS(i/5, i%5)==7) flag = false;	//한번만 실행, 인접해있는지 확인
					else break;							//인접해있지 않으면 break
				}

				if(board[i/5][i%5]=='S') sCnt++;
			}	
		}

		if(sCnt>=4) answer++;

	}while(next_permutation(combi.begin(), combi.end()));

	cout<<answer<<'\n';

	return 0;
}
