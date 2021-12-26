#include <string>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 10000;
queue<int> q;

int solution(int n)
{
    int ans=0, sum = 0;
    
    for(int i=1; i<=n; i++)
    {
        q.push(i);
        sum+=i;
        
        while(1)
        {
            if(sum==n) ans++;    
            else if(sum < n) break;
            sum-=q.front();
            q.pop();
        }
    }
    
    return ans;
}
