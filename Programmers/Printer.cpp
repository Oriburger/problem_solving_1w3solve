#include <string>
#include <vector>
#include <deque>
#include <utility>
using namespace std;

typedef pair<int, int> P;

int solution(vector<int> priorities, int location)
{
    deque<P> q;
    int answer = 0;
    const int n = priorities.size();
    
    for(int i=0; i<n; i++)
        q.push_back({i, priorities[i]});
    
    while(1)
    {
        P curr = q.front();
        deque<P>::iterator iter;
        
        bool flag = false;
        for(iter = q.begin()+1; iter!= q.end(); iter++)
        {
            if(iter->second > curr.second)
            {
                flag = true;
                break;
            }
        }
        if(flag) q.push_back(curr);
        else answer+=1;
        q.pop_front();
        
        if(!flag && curr.first == location) break;
    }
    
    return answer;
}
