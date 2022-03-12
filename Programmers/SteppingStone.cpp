#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int distance, vector<int> rocks, int n) 
{
    int lo = 0, hi = distance;
    
    rocks.push_back(0);
    rocks.push_back(distance);
    sort(rocks.begin(), rocks.end()); //탐색 위한 정렬
    
    while(lo+1 < hi) //이분탐색!
    {
        int mid = (lo+hi)/2;
        int prev = 0, cnt = 0; 
        
        for(int curr=1; curr<rocks.size(); curr++) //mid가 가능한 정답인지 판단
        {
            if(rocks[curr]-rocks[prev] < mid) cnt++; //두 바위의 거리가 mid보다 작다면, 없애줌
            else prev = curr; //아니라면? prev 갱신
        }
        if(cnt > n) hi = mid; //만약, 없앤 돌이 cnt보다 크거나 같다면 hi 범위 재지정
        else lo = mid; //반대라면, lo 범위 재지정
    }
    return lo;
}
