#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit)
{
    int answer = 0;
    sort(people.begin(), people.end());
    
    vector<int>::iterator lo, hi;
    lo = people.begin();
    hi = people.end()-1;
    
    while(1)
    {
        if(lo >= hi)
        {
            answer += (lo==hi); //lo(hi) 하나가 남았다면? 1추가
            break;
        }
        
        if(*lo + *hi > limit) //만약 *lo와 *hi의 합이 limit를 초과한다면?
        {
            answer++; //hi만 배를 태워 보낸다.
            hi--; //hi는 1감소
        }
        else //둘을 보트에 태워보낼수있다면?
        {
            answer++; //둘다 보트에 태워보냄
            lo++; hi--; //각각 1
        }
    }
    return answer; //정답 반환
}
