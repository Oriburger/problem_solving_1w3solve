#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int dy[3] = {1, 1, 0};
const int dx[3] = {1, 0, 1};

int board[30][30];
bool check[30][30];

void PopCheck(int y, int x, const int m, const int n)
{
    for(int i=0; i<3; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        
        if(ny<0 || nx<0 || ny>=m || nx>=n)  return;
        if(board[y][x] != board[ny][nx]) return;
    }
    
    check[y][x] = true;
    for(int i=0; i<3; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        check[ny][nx] = true;
    }
}

int solution(int m, int n, vector<string> str) 
{
    int ret=0;
    
    memset(board, -1, sizeof(board));
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            board[i][j] = str[i][j]-'A'+1;
    
    while(1)
    {
        memset(check, false, sizeof(check));
        int cnt = 0;
        
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                if(board[i][j]!=-1)
                    PopCheck(i, j, m, n);
        
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                if(check[i][j])
                {
                    board[i][j]=-1;
                    cnt++;
                }
        
        for(int i=0; i<n; i++)
        {
            vector<int> temp;
            for(int j=m-1; j>=0; j--)
            {
                if(board[j][i]!=-1) 
                    temp.push_back(board[j][i]);
            }
            
            vector<int>::iterator iterPos = temp.begin();
            for(int j=m-1; j>=0; j--)
            {
                if(iterPos == temp.end())
                    board[j][i] = -1;
                else
                {
                    board[j][i] = *iterPos;
                    iterPos+=1;
                }
            }
        }  
                    
        if(cnt==0) break;
        else ret += cnt;
    }
    return ret;
}
