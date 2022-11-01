#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
using namespace std;

typedef pair<int, int> P;
const int MAXN = 1e5;
const int INF = 2147000000;

vector<vector<int> > adj(MAXN+1);

int getShortestPath(int n, int start, int dest)
{
    vector<int> dist(n+1, INF);
    priority_queue<P, vector<P>, greater<P> > pq;
    
    pq.push({0, start});
    dist[start] = 0;
    
    while(!pq.empty())
    {
        int curr = pq.top().second;
        int curDist = pq.top().first;
        pq.pop();
        
        if(curr == dest) break;
        
        for(auto &next : adj[curr])
        {
            if(dist[curr] + 1 >= dist[next]) continue;
            dist[next] = dist[curr] + 1;
            pq.push({dist[next], next});
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
