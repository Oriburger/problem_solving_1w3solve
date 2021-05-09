#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds)
{
    const int n = progresses.size();
    vector<int> answer;
    vector<bool> check(n, false);
    queue<int> q;
    
    for(int i=0; i<n; i++) q.push(i); //개발할 기능들을 순서에 맞게 큐에 넣는다.
    
    for(int i=1; i<=100; i++) //최대 100일
    {
        for(int j=0; j<n; j++) //기능들을 하나씩 순회
        {
            if(check[j]) continue;
            
            progresses[j] = progresses[j]+speeds[j];  //개발 진행도 갱신
            progresses[j] = min(progresses[j], 100);  //100을 넘지 않도록..
        }
        
        int cnt = 0;
        while(!q.empty()) //큐의 머리부분에서 개발이 완료된 기능들을 순차적으로 꺼낸다.
        { 
            int curr = q.front();
            if(progressescurr] == 100) //개발이 완료된 기능이라면? 개수를 센다.
            {
                cnt+=1;
                q.pop();
                check[curr] = true;
            }
            else break; //개발이 덜 된 기능을 만나면 break.
        }
        
        if(cnt!=0) answer.push_back(cnt); //i일에 개발이 완료된게 1개 이상이라면 정답에 추가
    }
    
    return answer;
}
