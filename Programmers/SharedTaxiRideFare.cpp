#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 99999999;
const int MAX_N = 201;
vector<vector<int> > adj;

int solution(int n, int s, int a, int b, vector<vector<int>> fares)
{
    int answer = INF;
    
    adj = vector<vector<int> >(n+1, vector<int>(n+1, INF));
    for(int i=0; i<fares.size(); i++) //그래프 초기화
    {
        int u, v, cost;
        u = fares[i][0];
        v = fares[i][1];
        cost = fares[i][2];
        adj[u][v]=adj[v][u]=cost;
    }
    
    for(int k=1; k<=n; k++) //플로이드-워셜 알고리즘!
    {
        adj[k][k] = 0; //자기 자신에게 가는 요금은 0
        for(int u=1; u<=n; u++)
        {
            for(int v=1; v<=n; v++)
            {
                if(u==v) continue; 
                
                if(adj[u][k] + adj[k][v] < adj[u][v])
                    adj[u][v] = adj[u][k] + adj[k][v];
            }
        }
    }
    
    for(int k=1; k<=n; k++) //모든 정점을 탐색하여 최소 비용을 탐색
    {
        //k까지 같이 합승한다고 할 때, 드는 최소 비용
        int temp = adj[s][k] + adj[k][a] + adj[k][b]; 
        answer = min(answer, temp);
    }
    
    return answer;
}
