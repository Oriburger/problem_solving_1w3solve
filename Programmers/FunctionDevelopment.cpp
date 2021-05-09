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
    
    for(int i=0; i<n; i++) q.push(i);
    
    for(int i=1; i<=100; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(check[j]) continue;
            
            progresses[j] = progresses[j]+speeds[j];
            progresses[j] = min(progresses[j], 100);
        }
        
        int cnt = 0;
        while(!q.empty())
        {
            int curr = q.front();
            if(progresses[curr] == 100)
            {
                cnt+=1;
                q.pop();
                check[curr] = true;
            }
            else break;
        }
        
        if(cnt!=0) answer.push_back(cnt);
    }
    
    return answer;
}
