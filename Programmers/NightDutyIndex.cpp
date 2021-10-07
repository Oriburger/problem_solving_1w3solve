#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

long long solution(int n, vector<int> works)
{
    long long answer = 0;
    
    priority_queue<int> pq;
    
    for(auto &p : works)
        pq.push(p); //우선순위 큐에 모두 넣어준다. (최대-힙)
    
    while(n) //n번 반복
    {
        int curr = pq.top(); 
        pq.pop();
        pq.push(curr-1); //top에 있는 작업의 양을 1 감소
        n--;
    }
  
    while(!pq.empty()) //pq 순회
    { 
        int curr = pq.top(); 
        pq.pop();
        
        if(curr <= 0) continue;
        answer += (curr*curr); //아직 남아있는 작업들을 제곱해서 더함
    }
    
    return answer;
}
