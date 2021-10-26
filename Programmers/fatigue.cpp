#include <string>
#include <vector>
#include <cstring>
using namespace std;

int cache[(1<<9)][5001];

int get_answer(int visited, int energy, vector<vector<int>>& d)
{
    int &ret = cache[visited][energy];
    if(ret != -1) return ret; //dp
    
    ret = 0; 
    for(int i=0; i<d.size(); i++)
    {
        const int need = d[i][0];
        const int cons = d[i][1];
        
        if(visited & (1<<i)) continue;
        if(energy < need) continue;
        
        visited |= (1 << i); 
        ret = max(ret, get_answer(visited, energy-cons, d)+1); 
        visited &= ~(1<<i); //backtrack
    }
    return ret;
}

int solution(int k, vector<vector<int>> dungeons) 
{
    memset(cache, -1, sizeof(cache));
    
    return get_answer(0, k, dungeons);
}
