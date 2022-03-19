#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int dy[2] = {1, 1};
const int dx[2] = {0, 1};
int cache[500][500];
vector<vector<int>> tri;

int GetAnswer(int y, int x)
{
    int &ret = cache[y][x];
    if(ret != -1) return ret;
    if(y == tri.size() || x > y) return ret = 0;
    
    ret = max(GetAnswer(y+1, x), GetAnswer(y+1, x+1))
            + tri[y][x]; 
    
    return ret;
}

int solution(vector<vector<int>> triangle) 
{
    memset(cache, -1, sizeof(cache));
    
    tri = triangle; 
    
    return GetAnswer(0, 0);    
}
