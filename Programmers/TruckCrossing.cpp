
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
40
41
42
43
44
45
46
47
48
49
50
51
52
53
54
55
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
        bool flag = false;
        for(int i=0; i<n; i++)
        {
            if(check[i]) continue;
            if(sum + truck_weights[i] - bridge.front()<= weight)
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
                answer++;
                //prt_queue(bridge);
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

        //prt_queue(bridge);
    }

    return answer;
}
