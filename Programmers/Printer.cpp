#include <string>
#include <vector>
#include <deque> //반복자 사용을 위해 deque 사용
#include <utility>
using namespace std;

typedef pair<int, int> P;

int solution(vector<int> priorities, int location)
{
    deque<P> q; //{문서의 번호, 중요도}
    int answer = 0;
    const int n = priorities.size();
    
    for(int i=0; i<n; i++) //초기 큐 구성
        q.push_back({i, priorities[i]});
    
    while(1)
    {
        P curr = q.front();
        deque<P>::iterator iter;
        
        bool flag = false;
        for(iter = q.begin()+1; iter!= q.end(); iter++) 
        {
            if(iter->second > curr.second) //큐에 중요도가 더 높은 문서가 있다면?
            {
                flag = true;
                break;
            }
        }
        if(flag) q.push_back(curr); //맨 뒤에 넣는다.
        else answer+=1; //없다면 순서를 카운팅 해주고 pop
        q.pop_front();
        
        if(!flag && curr.first == location) break; //정답을 찾았다면
    }
    
    return answer;
}
