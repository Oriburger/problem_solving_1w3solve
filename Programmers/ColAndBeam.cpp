#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

set<vector<int>> build_set;

inline bool find(int x, int y, int type) { return build_set.count({x, y, type}); }

bool is_valid()
{
    for(auto &p : build_set)
    {
        int x = p[0], y = p[1], type = p[2];
        if(!type) //기둥
        {
            if(y==0 || find(x, y-1, 0) || find(x, y, 1) || find(x-1, y, 1)) continue;
            return false;
        }
        else //보
        {
            if(find(x, y-1, 0) || find(x+1, y-1, 0) || (find(x-1, y, 1) && find(x+1, y, 1))) continue;
            return false;
        }
    }
    return true;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) 
{
    vector<vector<int>> answer;
    
    for(auto &p : build_frame)
    {
        int x = p[0], y = p[1], type = p[2];
        if(p[3]) //설치
        {
            build_set.insert({x, y, type});
            if(!is_valid()) build_set.erase({x, y, type}); 
        }
        else
        {
            build_set.erase({x, y, type});
            if(!is_valid()) build_set.insert({x, y, type});
        }
    }
    for(auto &p : build_set)
        answer.push_back(p);
    
    return answer;
}
