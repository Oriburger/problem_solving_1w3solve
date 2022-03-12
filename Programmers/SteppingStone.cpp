#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int distance, vector<int> rocks, int n) 
{
    int lo = 0, hi = distance;
    
    rocks.push_back(0);
    rocks.push_back(distance);
    sort(rocks.begin(), rocks.end());
    
    while(lo<=hi)
    {
        int mid = (lo+hi)/2;
        int prev = 0, cnt = 0;
        
        for(int curr=1; curr<rocks.size(); curr++)
        {
            if(rocks[curr]-rocks[prev] < mid) cnt++;
            else prev = curr;
        }
        if(cnt > n) hi = mid-1;
        else lo = mid+1;        
    }
    return hi; 
}
