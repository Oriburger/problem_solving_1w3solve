#include <string>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

int solution(const int bridge_length, const int weight, vector<int> truck_weights) 
{
    int answer = 0, sum = 0, cnt=0;
    const int n = truck_weights.size();
    
    queue<int> bridge;
    vector<bool> check(n, false), finished(n, false);
    
    for(int i=0; i<bridge_length; i++)
        bridge.push(0);
    
    while(cnt != n)
    {
        for(int i=0; i<n; i++)
        {
            if(check[i]) continue;
            if(sum + truck_weights[i] <= weight)
            {
				if(i>0 && !check[i-1]) continue;
                sum += truck_weights[i];
                bridge.push(truck_weights[i]);
                if(bridge.front() > 0)
		{
			cnt++;
			sum -= bridge.front();
		}
                bridge.pop();
                check[i] = true;
		break;
            }
        }

	bridge.push(0);
	if(bridge.front() > 0)
	{
		cnt++;
		sum -= bridge.front();
	}
	bridge.pop();
        answer++;
    }
    
    return answer+1;
}
