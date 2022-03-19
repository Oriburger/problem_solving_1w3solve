#include <string>
#include <cstring>
#include <vector>
using namespace std;

const int INF = 1000000007;
int cache[101][101];

int GetAnswer(int y, int x, const int n, const int m)
{
    if(y>n || x>m) return 0;
    int& ret = cache[y][x];
    if(ret != 0) return ret == -1 ? 0 : ret;
    if(y == n && x == m) return ret = 1;
    
    ret = (ret + GetAnswer(y+1, x, n, m)%INF)%INF;
    ret = (ret + GetAnswer(y, x+1, n, m)%INF)%INF;
    
    return ret % INF ; 
}

int solution(int m, int n, vector<vector<int>> puddles) 
{   
    for(auto &p : puddles)
        cache[p[1]][p[0]] = -1;
    
    return GetAnswer(1, 1, n, m);
}
