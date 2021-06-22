#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

struct Pos{int y; int x;};

const int dy[4]={1,-1,0,0};
const int dx[4]={0,0,1,-1};

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    const int n = maps.size();
    const int m = maps[0].size();
    vector<vector<int> > visited(n, vector<int>(m, 0));
    
    queue<Pos> q;
    q.push({0, 0});
    visited[0][0]=1;
    
    while(!q.empty())
    {
        Pos curr = q.front();
        q.pop();
        
        for(int i=0; i<4; i++)
        {
            Pos next = {curr.y+dy[i], curr.x+dx[i]};
            
            if(next.y<0 || next.x<0 || next.y>=n || next.x>=m 
               || visited[next.y][next.x]
               || !maps[next.y][next.x])
                continue;
            
            visited[next.y][next.x]=visited[curr.y][curr.x]+1;
            q.push(next);
        }
    }
    
    return !visited[n-1][m-1] ? -1 : visited[n-1][m-1];
}
