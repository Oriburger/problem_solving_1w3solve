//풀이) https://blog.naver.com/uss425/222922539773

#include <string>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

typedef pair<int, int> P;
const int INF = 2e9;
vector<bool> isSummit, isGate;
vector<vector<P> > adj;

class disjointSet
{
private:
    vector<int> parent, rank;
    
public:    
    disjointSet(int n) : rank(n+1, 1), parent(n+1)
    {
        for(int i=1; i<=n; i++)
            parent[i] = i;
    }       
    
    int find(int u)
    {
        if(parent[u]==u) return u;
        return parent[u] = find(parent[u]);
    }
    
    void merge(int u, int v)
    {
        u = find(u), v = find(v);
        
        if(u == v) return;
        if(rank[u] < rank[v]) swap(u, v);
        if(rank[u] == rank[v]) rank[u]++;
        parent[v] = u;
    }
    
};

vector<int> dijkstra(vector<int>& gates)
{
    priority_queue<P, vector<P>, greater<P> > pq;
    vector<int> dist(adj.size(), INF);
    vector<P> temp;    
    
    for(auto &s : gates)
    {
        pq.push({0, s});
        dist[s] = 0;
    }
    
    while(!pq.empty())
    {
        int curr = pq.top().second;
        int curDist = pq.top().first; 
        pq.pop();
        
        if(curDist > dist[curr]) continue;
        if(isSummit[curr])
        {
            temp.push_back({curDist, curr});
            continue;
        }
        
        for(P& nx : adj[curr])
        {
            int next = nx.first;
            int nextDist = nx.second; 
            
            if(dist[next] > max(curDist, nextDist))
            {
                dist[next] = max(curDist, nextDist);
                pq.push({dist[next], next});
            }
        }
    }
    sort(temp.begin(), temp.end());
    
    return {temp[0].second, temp[0].first};
}

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) 
{
    vector<int> answer = {0, INF}, intensity;
    isSummit.resize(n+1, false);
    isGate.resize(n+1, false);
    adj.resize(n+1);
    
    int cnt = 0;
    disjointSet djs(n);
    
    sort(paths.begin(), paths.end(), [](vector<int>& a, vector<int>& b) -> bool
        {
            return a[2] < b[2];
        });
    
    for(vector<int>& edge : paths)
    {
        int u = edge[0], v = edge[1], cost = edge[2];
        
        if(djs.find(u) != djs.find(v))
        {
            djs.merge(u, v);
            adj[u].push_back({v, cost});
            adj[v].push_back({u, cost});
            if(++cnt == n-1) break;
        }
    }
    
    for(auto &s : summits) isSummit[s] = true;
    for(auto &g : gates) isGate[g] = true;
    
    answer = dijkstra(gates);
    
    return answer;
}
