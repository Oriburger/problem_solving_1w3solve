#include <iostream>
using namespace std;

bool flag;
int n, m, year, icebergCnt;
int iceberg[300][300];
int blankCnt[300][300];
bool visited[300][300];
const int dy[4] = {1,-1,0,0};
const int dx[4] = {0,0,1,-1};

void DFS(int y, int x)
{
	if(y<0 || x<0 || y>=n || x>=m) return;
	if(visited[y][x] || iceberg[y][x]==0) return;
	
	visited[y][x]=true;
	
	for(int i=0; i<4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		
		return DFS(ny, nx);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>n>>m;
	
	for(int i=0; i<n; i++)
	for(int j=0; j<m; j++)
		cin>>iceberg[i][j];

	
	while(1)
	{	
		cout<<"year : "<<year<<'\n';
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<m; j++)
			{
				cout<<iceberg[i][j];
			}
			cout<<'\n';
		}
		
		
		//dfs
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<m; j++)
			{
				if(!visited[i][j] && iceberg[i][j] != 0)
				{
					cout<<i<<", "<<j<<" : visited - "
					DFS(i, j);
					flag = true;
					icebergCnt++;
				}
			}
		}
	//=================================
		cout<<icebergCnt<<'\n';
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<m; j++)
			{
				cout<<visited[i][j];
			}
			cout<<'\n';
		}
	//====================================
	
		if(!flag || icebergCnt>=2) break; //빙하가 하나도 없으면 break;
		
		//val init
		for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
		{
			visited[i][j]=false;
			blankCnt[i][j]=0;
			flag=false;
		}
		
		//melt
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<m; j++)
			{
				if(iceberg[i][j]!=0)
					for(int k=0; k<4; k++)
					{
						int ny = i+dy[k];
						int nx = j+dx[k];
						if(ny<0 || nx<0 || ny>=n || nx>=m) continue;
						if(iceberg[ny][nx]==0) blankCnt[i][j]++;
					}
			}
		}
		for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			iceberg[i][j] = iceberg[i][j] - blankCnt[i][j] < 0 ? 0 : iceberg[i][j] - blankCnt[i][j];
		
		year++;
	}
	
	if(year==0) cout<<"0\n";
	else cout<<year-1<<'\n';
	
	return 0;
} 
