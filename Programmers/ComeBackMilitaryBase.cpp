#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAXN = 1e5;
const int INF = 2147000000;

vector<vector<int> > adj(MAXN+1);

int getShortestPath(int n, int start, int dest)
{
    queue<int> q;
    vector<int> dist(n+1, -1);
    
    q.push(start);
    dist[start] = 0;
    
    while(!q.empty())
    {
        int curr = q.front();
        q.pop(); 
        
        if(curr == dest) break;
        
        for(auto &next : adj[curr])
        {
            if(dist[next] != -1) continue;
            dist[next] = dist[curr] + 1;
            q.push(next);
        }
    }
    return dist[dest] == INF ? -1 : dist[dest];
}

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) 
{
    vector<int> answer;
    
    for(auto &r : roads)
    {
        adj[r[0]].push_back(r[1]);
        adj[r[1]].push_back(r[0]);
    }
    
    for(auto &s : sources)
        answer.push_back(getShortestPath(n, s, destination));
    
    return answer;
}
