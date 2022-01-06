#include <bits/stdc++.h>
using namespace std;

int n, m, d, ans;
const int INF = INT_MAX;
vector<int> archer;
vector<vector<int> > board;

typedef pair<int, int> P;

inline int GetDist(P p, P q){ return abs(p.first-q.first) + abs(p.second - q.second); } //맨해튼 거리 계산법

int GetAnswer(vector<vector<int> > board)
{
	int ret = 0;
	vector<int> pos; //궁수들이 위치한 열을 저장할 배열
	for(int i=0; i<m; i++)	if(archer[i]) pos.push_back(i); 

	for(int r=n; r>=1; r--) //궁수들이 한 칸씩 올라가며 턴을 진행
	{
		vector<P> target(3, {-1, -1}); //3명의 궁수들의 타겟이 될 적
		for(int k=0; k<3; k++)
		{
			int min_dist = INF;
			for(int j=0; j<m; j++) //왼쪽에서 -> 오른쪽으로 순회
			for(int i=0; i<r; i++) //위에서 -> 아래로 순회
			{
				if(board[i][j]==0) continue; //적이 없다면 continue
				int temp = GetDist(P(r, pos[k]), P(i, j)); //적과의 거리 도출
				
				if(temp <= d && min_dist > temp) //d 이하이고, 이전에 구했던 거리보다 더 짧다면
				{
					min_dist = temp; //타겟 갱신
					target[k] = {i, j}; //타겟 갱신
				}
			}
		}

		for(auto &p : target) //3명의 궁수들은 타겟을 동시에 공격
		{
			if(p == P(-1, -1)) continue; //타겟이 없다면 continue
			if(board[p.first][p.second]==1)
			{
				ret+=1; //적을 카운팅
				board[p.first][p.second] = 0; //적은 죽음
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
		ans = max(ans, GetAnswer(board)); //최댓값을 찾아냄
	}while(next_permutation(archer.begin(), archer.end())); //가능한 모든 조합을 시도

	cout<<ans<<'\n';

	return 0;
}
