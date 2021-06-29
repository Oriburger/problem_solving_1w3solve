#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 101;
const int dy[4] = {1, -1, 0, 0};
const int dx[4] = {0, 0, 1, -1};

struct Pos{int y; int x;};

int cnt = 0;
vector<vector<bool> > visited;

void DFS(Pos curr, const vector<vector<int>> &picture, const int m, const int n)
{
    cnt++;
    visited[curr.y][curr.x] = true;
    
    for(int i=0; i<4; i++)
    {
        Pos next = {curr.y + dy[i], curr.x + dx[i]};
        
        if(next.y < 0 || next.y >= m
           || next.x < 0 || next.x >= n) continue;
        if(visited[next.y][next.x]) continue;
        if(picture[next.y][next.x]!=picture[curr.y][curr.x])
            continue;
        
        DFS(next, picture, m, n);
    }
}

vector<int> solution(int m, int n, vector<vector<int>> picture)
{
    int max_area = 0;
    int cnt_area = 0;
    
    visited = vector<vector<bool> >(MAX, vector<bool>(MAX, 0));
    
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            if(!visited[i][j] && picture[i][j])
            {
                cnt = 0;
                DFS({i, j}, picture, m, n);
                max_area = max(max_area, cnt);
                cnt_area++;
            }

    return {cnt_area, max_area};
}
