#include <iostream>
#include <queue>
using namespace std;

struct pos { int z; int y; int x; int val; };

pos s, f; //start, finish pos

const int dy[6]={0,0,1,-1,0,0};
const int dx[6]={0,0,0,0,1,-1};
const int dz[6]={1,-1,0,0,0,0};

int building[31][31][31]; //minute 연산 
int l, r, c;

void BFS(int z, int y, int x)
{
	queue<pos> q;
	q.push({z, y, x, 0});
	building[z][y][x]=0;
	
	while(!q.empty())
	{
		pos curr = q.front();
		q.pop();
		
		if(curr.z == f.z && curr.y == f.y && curr.x == f.x) return;
		
		for(int i=0; i<6; i++)
		{
			pos next = {curr.z+dz[i], curr.y+dy[i], curr.x+dx[i], curr.val+1};
			
			if(next.z<0 || next.y<0 || next.x<0 
				|| next.z>=l || next.y>=r || next.x>=c) continue;
			if(building[next.z][next.y][next.x]!=0) continue; //방문했을 경우 or 벽 
			
			q.push(next);
			building[next.z][next.y][next.x] = next.val;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	while(1)
	{
		char input;
			
		cin>>l>>r>>c;
		if(!(l || r || c)) break;
		
		for(int k=0; k<l; k++)
		for(int i=0; i<r; i++)
		for(int j=0; j<c; j++)
		{
			cin>>input;
		
			switch (input)
			{
			case 'S': //시작 좌표 저장  
				s = {k, i, j};
				break;
			case 'E': //끝 좌표 저장 
				f = {k, i, j};
				break;
			case '.': //빈칸일 경우 0 
				building[k][i][j]=0;
				break;
			case '#': //벽이면 -1 저장  
				building[k][i][j]=-1;
				break;
			}
		}
		
		BFS(s.z, s.y, s.x);
		
		if(building[f.z][f.y][f.x]==0) 
			cout<<"Trapped!\n";
		else
			cout<<"Escaped in "<<building[f.z][f.y][f.x]<<" minute(s).\n";
		
		//clear data
		for(int k=0; k<l; k++)
		for(int i=0; i<r; i++)
		for(int j=0; j<c; j++)
			building[k][i][j]=0;
	}
	
	return 0;
}
