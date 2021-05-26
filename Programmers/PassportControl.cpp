#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/* -----------
가능한 시간의 범위를 지정해놓고
문제에 대입해보며 가능한지 판단하며 
이분탐색을 진행
-------------*/
long long solution(int n, vector<int> times)
{
    long long answer = 0;
    long long lo=0, hi=0, mid=0;
    
    sort(times.begin(), times.end()); //times를 초기화
    
    lo = times[0]; //답의 범위는 times[0] ~ times.back() * n
    hi = times.back()*(long long)n;
    answer = hi; 
    
    while(lo<=hi) //lo가 hi보다 작을 경우 반복
    {
        mid = (lo + hi)/2; 
        
        long long val = 0; //mid 시간에 통과할 수 있는 사람의 수
        for(int i=0; i<times.size(); i++) //times 순회하며
            val += mid/times[i]; //mid 시간에 i번째 심사관이 통과시키는 사람의 수를 더함
        
        if(val < n) //만약, n명보다 덜 통과 한다면... 
            lo = mid+1; //범위 재지정
        else //만약, 답이 조건에 만족한다면?
        {
            hi = mid-1; //범위 재지정
            answer = min(answer, mid); //정답 갱신
        }
    }
    
    return answer;
}
