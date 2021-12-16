#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

typedef pair<int,int> P;

const int inf = 987654321;
const int dy[4] = {1,-1,0,0};
const int dx[4] = {0,0,1,-1};

int n, landNum=1, ans=inf;
int land[100][100];
bool visited[100][100];

int Bridge(int y, int x) 
//(y, x)���� �ٸ� ������ ���� ���� ª�� �ٸ� ���̸� ����. 
{
	int ret=inf, length=1;
	int curLandNum = land[y][x];
	int step[100][100]={0};
	queue<P> q;
	
	q.push({y, x});
	
	while(!q.empty())
	{
		P curr = make_pair(q.front().first, q.front().second);
		q.pop();
		length--;
		
		for(int i=0; i<4; i++)
		{
			int ny = curr.first + dy[i];
			int nx = curr.second + dx[i];

			if(ny<0 || nx<0 || ny>=n || nx>=n) continue;
			if(land[ny][nx] == curLandNum) continue;
			
			if(land[ny][nx]==0 && !step[ny][nx])
			{
				q.push(make_pair(ny, nx));
				length++;
				step[ny][nx] = step[curr.first][curr.second] + 1;
			}
			
			if(land[ny][nx] != curLandNum && land[ny][nx] != 0)
			{
				if(length==0) continue;
				ret = min(ret, step[curr.first][curr.second]);
			}
		}
	}
	return ret;
}

void DivideLand(int y, int x, int landCurrNum) 
//DFS����� �Լ��� �� ���� ��ȣ�� ���δ�. 
{
	if(visited[y][x]) return;
	if(land[y][x]==0 || y<0 || x<0 || y>=n || x>=n) return;
	
	visited[y][x]=true;
	land[y][x]=landCurrNum;
	
	for(int i=0; i<4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		
		DivideLand(ny, nx, landCurrNum);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>n;
	
	for(int i=0; i<n; i++) //������ �Է� 
	for(int j=0; j<n; j++)
		cin>>land[i][j];
	
	for(int i=0; i<n; i++) //DFS�� ���� ���� ��ȣ�� �ٿ� �������´�. 
	for(int j=0; j<n; j++)
		if(land[i][j]==1 && !visited[i][j])
			DivideLand(i, j, landNum++);
	
	for(int i=0; i<n; i++) //�� ���� ���� �ٸ� �������� ���� ª�� �ٸ� ���̸� ���Ѵ�. 
	for(int j=0; j<n; j++)
	{
		if(land[i][j]!=0)
		{
			int ret = Bridge(i, j);
			ans = min(ans, ret);
		}
	}
	
	cout<<ans<<'\n';
	
	return 0;
}
