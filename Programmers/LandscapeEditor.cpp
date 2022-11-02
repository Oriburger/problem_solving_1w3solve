#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
ll lo = 2e9, hi = 0;

ll solution(vector<vector<int> > land, int P, int Q)
{
    ll answer = 9e16+1;
    
    for(int i=0; i<land.size(); i++)
        for(int j=0; j<land[0].size(); j++)
        {
            lo = min(lo, (ll)land[i][j]);
            hi = max(hi, (ll)land[i][j]);
        }
    
    while(lo <= hi)
    {
        ll mid = (hi + lo) / 2;
        ll total[2] = {0, 0};
        
        for(int i=0; i<land.size(); i++)
            for(int j=0; j<land[0].size(); j++)
            {
                const ll p = land[i][j];
                total[0] += abs(p - mid) * (p < mid ? P : Q);
                total[1] += abs(p - (mid+1)) * (p < (mid+1) ? P : Q);
            }
        
        answer = min(answer, min(total[0], total[1]));
        
        if(total[0] < total[1]) hi = mid - 1;
        else if(total[0] > total[1]) lo = mid + 1; 
        else break;
    }
    
    return answer;
}
