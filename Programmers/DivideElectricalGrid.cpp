#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool adj[201][201];
vector<bool> visited;

int DFS(int curr, const int n)
{
    if(visited[curr]) return 0;
    visited[curr] = true;
    
    int ret = 1;
    for(int next=1; next<=n; next++)
    {
        if(!adj[curr][next]) continue;
        
        ret += DFS(next, n);
    }
    return ret;
}

int solution(int n, vector<vector<int>> wires) 
{
    int answer = 201;
    
    for(int i=0; i<wires.size(); i++)
    {
        int u = wires[i][0];
        int v = wires[i][1];
        adj[u][v] = adj[v][u] = true;
    }
    
    for(int i=0; i<wires.size(); i++)
    {
        int u = wires[i][0];
        int v = wires[i][1];
        adj[u][v] = adj[v][u] = false;
        
        vector<int> count;
        visited = vector<bool>(n+1, false);
        for(int j=1; j<=n; j++)
        {
            int temp = DFS(j, n);
            if(!temp) continue;
            count.push_back(temp);
        }
        answer = min(answer, abs(count[0]-count[1]));
        adj[u][v] = adj[v][u] = true;
    }
    
    return answer;
}
