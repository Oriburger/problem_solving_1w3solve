#include <string>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};

struct Pos{ int y; int x; };
typedef pair<Pos, int> P;

vector<int> solution(vector<vector<string>> places)
{
    vector<int> answer;
    
    for(auto &board : places)
    {
        vector<Pos> st_pos;
        bool flag = false;
        
        for(int i=0; i<5; i++)
            for(int j=0; j<5; j++)
                if(board[i][j]=='P')
                    st_pos.push_back({i, j});
        
        
        for(auto &st : st_pos)
        {
            vector<vector<bool> > visited(5, vector<bool>(5, false));
            queue<P> q;
            q.push({st, 0});
            visited[st.y][st.x] = true;
            
            while(!q.empty())
            {
                P curr = q.front();
                q.pop();
                
                if(curr.second > 2) break;
                else if(curr.second != 0 && board[curr.first.y][curr.first.x] == 'P')
                {
                    flag = true;
                    break;
                }
                
                for(int i=0; i<4; i++)
                {
                    int ny = curr.first.y + dy[i];
                    int nx = curr.first.x + dx[i];
                    
                    if(ny<0 || nx<0 || ny>=5 || nx>=5)
                        continue;
                    if(visited[ny][nx]) continue;
                    if(board[ny][nx]=='X') continue;
                    
                    q.push({{ny, nx}, curr.second+1});
                    visited[ny][nx] = true;
                }
            }           
            if(flag) break;
        }
        answer.push_back(!flag);
    }
    
    return answer;
}
