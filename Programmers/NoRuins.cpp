#include <string>
#include <vector>
using namespace std;

struct Pos { int y; int x; };
int presum[1001][1001];

int solution(vector<vector<int>> board, vector<vector<int>> skill)
{
    int answer = 0;
    
    for(vector<int>& s : skill)
    {
        int type = s[0], degree = s[5];
        Pos p[2] = { {s[1], s[2]}, {s[3], s[4]} };
        
        presum[p[0].y][p[0].x] += (degree * (type==1 ? -1 : 1));
        presum[p[1].y+1][p[1].x+1] += (degree * (type==1 ? -1 : 1));
        presum[p[0].y][p[1].x+1] -= (degree * (type==1 ? -1 : 1));
        presum[p[1].y+1][p[0].x] -= (degree * (type==1 ? -1 : 1));
    }
    
    for(int i=0; i<board.size(); i++)
        for(int j=1; j<board[0].size(); j++)
            presum[i][j] += presum[i][j-1];
    
    for(int i=0; i<board[0].size(); i++)
        for(int j=1; j<board.size(); j++)
            presum[j][i] += presum[j-1][i];
    
    for(int i=0; i<board.size(); i++)
        for(int j=0; j<board[0].size(); j++)
            if(board[i][j]+presum[i][j] > 0)
                answer += 1;
    
    return answer;
}
