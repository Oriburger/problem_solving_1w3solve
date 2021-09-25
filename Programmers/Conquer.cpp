#include <iostream>
#include <vector>
using namespace std;

int solution(vector<vector<int> > land)
{
    int ans = 0;
    
    for(int i=1; i<land.size(); i++)
    {
        land[i][0] += max(land[i-1][1], max(land[i-1][2], land[i-1][3]));
        land[i][1] += max(land[i-1][0], max(land[i-1][2], land[i-1][3]));
        land[i][2] += max(land[i-1][1], max(land[i-1][0], land[i-1][3]));
        land[i][3] += max(land[i-1][1], max(land[i-1][2], land[i-1][0]));
        
        ans = max(land[i][0], max(land[i][1], max(land[i][2], land[i][3])));
    }
    
    return ans;
}
