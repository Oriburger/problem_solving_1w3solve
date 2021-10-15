#include <cstring>
#include <vector>
using namespace std;

int cache[501][501];

int get_answer(int y, int x, vector<vector<int>> &t)
{
    int &ret = cache[y][x];
    if(x>y || ret != -1) return ret;
    if(y == t.size()) return ret = 0;
    
    ret = t[y][x];
    
    ret += max(get_answer(y+1, x, t)
                , get_answer(y+1, x+1, t));
    
    return ret;
}

int solution(vector<vector<int>> triangle)
{
    memset(cache, -1, sizeof(cache));
    
    return get_answer(0, 0, triangle);
}
