#include <string>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

int solution(const int bridge_length, const int weight, vector<int> truck_weights) 
{
    int answer = 0, sum = 0, cnt=0; //sum : 다리 위에 있는 트럭 무게의 합,  cnt : 다리를 통과한 트럭의 수
    const int n = truck_weights.size();

    queue<int> bridge; 
    vector<bool> check(n, false);
 
    //0초에는 다리에 아무것도 없다.
    for(int i=0; i<bridge_length; i++)
        bridge.push(0);
    
    //트럭이 다 통과할때까지 반복 : 
    while(cnt != n)
    {
        for(int i=0; i<n; i++)
        {
            if(check[i]) continue; //이미 다리에 올랐거나 통과한 트럭이라면? 
            if(sum + truck_weights[i] - bridge.front()<= weight) //만약 1초가 지난 뒤에 다리에 오를수 있다면? 
            {
                if(i>0 && !check[i-1]) break; //i-1번째의 트럭이 다리에 오르지 않았다면 못올림..
                bridge.push(truck_weights[i]); //트럭을 다리에 올리고
                sum += truck_weights[i]; //무게합 갱신
                check[i] = true; //올린 트럭을 체크
                
                cnt += (bridge.front()>0); //트럭이 빠져나왔다면 cnt에 1추가
				sum -= bridge.front(); //무게의 총합에서 빠져나온걸 뺌 
				bridge.pop(); //다리 pop
				answer++; //1초 추가
            }
        }

        bridge.push(0); //공기를 추가
        cnt += (bridge.front()>0); //트럭이 빠져나왔다면 cnt에 1추가
		sum -= bridge.front(); //무게의 총합에서 빠져나온걸 뺌 
		bridge.pop(); //다리 pop
		answer++; //1초 추가
    }

    return answer;
}
