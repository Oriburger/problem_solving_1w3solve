#include <iostream>
#include <string>
#include <map>
using namespace std;

int ans=0;
char board[5][5];
map<string, int> m;

const int dy[4]={1,-1,0,0};
const int dx[4]={0,0,1,-1};

void Sequence(int y, int x, string curr)
{
	if(curr.size()==6)
	{
		map<string, int>::iterator iterPos = m.find(curr);
		
		if(iterPos == m.end()) 
		{
		//	cout<<curr<<'\n';
			ans++;
			m.insert({curr, 1});
		}
		return;
	}
	
	for(int i=0; i<4; i++)
	{
		int ny = y+dy[i];
		int nx = x+dx[i];
		
		if(ny<0 || nx<0 || ny>=5 || nx>=5) continue;
		
		curr.push_back(board[ny][nx]);
		Sequence(ny, nx, curr);
		curr.pop_back();
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	for(int i=0; i<5; i++)
	for(int j=0; j<5; j++)
		cin>>board[i][j];
	
	for(int i=0; i<5; i++)
	for(int j=0; j<5; j++)
		Sequence(i, j, string{board[i][j]});
	
	cout<<ans<<'\n';
	
	return 0;
}
