#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes)
{
    int max_w, max_h;
    
    max_w = max_h = -1;
    
    for(auto &p : sizes)
    {
        if(p[0] < p[1]) swap(p[0], p[1]);
        max_w = max(max_w, p[0]);
        max_h = max(max_h, p[1]);
    }
    
    return max_w * max_h;
}
