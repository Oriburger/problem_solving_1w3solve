#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/* -----------
가능한 시간의 범위를 지정해놓고
문제에 대입해보며 가능한지 판단하며 
이분탐색을 진행
-------------*/
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(int n, vector<int> times) 
{
    long long lo = 0, hi = times[0]*(long long)n;
    while(lo<=hi)
    {
        long long mid = (lo+hi)/2;
        
        long long tmp = 0;
        for(auto &p : times)
            tmp += mid/p;
        
        if(tmp >= n) hi = mid - 1;
        else lo = mid + 1;
    }
    return lo;
}
