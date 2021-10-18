#include <iostream>
#include <vector>
using namespace std;

int row, col, ans = 0;
const int INF = 9999999;
vector<vector<int>> board;
vector<vector<int>> cache;

int get_max_area(int y, int x)
{
    if(y>=col || x>=row) return 0;
    
    int &ret = cache[y][x];
    if(ret!=-1) return ret;
    
    ret = board[y][x];
    
    int temp = INF;
    temp = min(temp, get_max_area(y+1, x));
    temp = min(temp, get_max_area(y, x+1));
    temp = min(temp, get_max_area(y+1, x+1));
    
    if(temp && board[y][x]) ret += temp;
    
    return ret;
}

int solution(vector<vector<int> > b)
{
    board = b;
    col = board.size(), row = board[0].size();
    cache = vector<vector<int> >(col, vector<int>(row, -1));
    
    for(int i=0; i<col; i++)
        for(int j=0; j<row; j++)
            if(board[i][j])
                ans = max(ans, get_max_area(i, j));
            
    return ans*ans;
}
