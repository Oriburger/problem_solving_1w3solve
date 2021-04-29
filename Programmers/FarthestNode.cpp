#include <string>
#include <vector>
#include <queue>
using namespace std;

int n;
vector<vector<int> > adj;

int BFS(int st)
{
    int cnt=1, longest=0;
    queue<int> q;
    vector<int> dist(n+1, -1);
    
    dist[st]=0;
    q.push(st);
    while(!q.empty())
    {
        int curr = q.front();
        q.pop();
        
        for(const auto& next : adj[curr])
        {
            if(dist[next]!=-1) continue;
            
            dist[next] = dist[curr] + 1;
            q.push(next);
            
            if(longest < dist[next])
            {
                longest=dist[next];
                cnt=1;
            }
            else if(longest == dist[next])
                cnt+=1;
        }
    }
    
    return cnt;
}

int solution(int N, vector<vector<int>> edge) 
{
    n = N;
    adj.resize(n+1);
    for(int i=0; i<edge.size(); i++)
    {
        int u = edge[i][0];
        int v = edge[i][1];
        
        adj[v].push_back(u);
        adj[u].push_back(v);
    }
    
    return BFS(1);
}
