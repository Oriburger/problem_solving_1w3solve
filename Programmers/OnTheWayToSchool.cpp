#include <string>
#include <vector>
using namespace std;

const int MOD = 1000000007;

int dp[101][101];
const int dy[2] = {0, 1};
const int dx[2] = {1, 0};

int GetAnswer(int y, int x, const int n, const int m)
{
    if(y<=0 || x<=0 || y>n || x>m) return 0;
    
    int &ret = dp[y][x];
    
    if(ret != 0) return ret==-1 ? 0 : ret;
    if(y==n && x==m) return ret = 1;
    
    return ret = (GetAnswer(y+1, x, n, m) % MOD + GetAnswer(y, x+1, n, m) % MOD) % MOD;
}

int solution(int m, int n, vector<vector<int>> puddles)
{
    for(vector<int>& p : puddles)
        dp[p[1]][p[0]]=-1;
    
    return GetAnswer(1, 1, n, m);
}
