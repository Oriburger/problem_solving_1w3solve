#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

typedef long long ll;
typedef priority_queue<ll, vector<ll>, greater<ll> > PQueue;

int solution(vector<int> scoville, int K)
{
    PQueue pq; 
    
    for(int i=0; i<scoville.size(); i++)
        pq.push(scoville[i]);

	for(int i=0; i<scoville.size(); i++)
	{
		if(pq.top()>=K) return i;

		ll tmp = pq.top();
		pq.pop();
        if(pq.size()==0) break;
		tmp = tmp + pq.top()*2;
		pq.pop();
		pq.push(tmp);
	}
    
    return -1;
}
