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

class disjointSet //서로소 집합
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
        return parent[u] = find(parent[u]); //경로 압축
    }
    
    void merge(int u, int v)
    {
        u = find(u), v = find(v);
        
        if(u == v) return;
        if(rank[u] < rank[v]) swap(u, v);
        if(rank[u] == rank[v]) rank[u]++; //rank 최적화
        parent[v] = u;
    }
    
};

int BFS(int start, const vector<int>& gates)
{
    queue<int> q;
    vector<int> intensity(adj.size(), -1); // start에서부터의 intensity
    
    q.push(start);
    intensity[start] = 0;
    while(!q.empty())
    {
        int curr = q.front();
        q.pop();
        
        for(auto &nextP : adj[curr])
        {
            int next = nextP.first;
            int nextDist = nextP.second;
            
            if(intensity[next] != -1 || isSummit[next]) continue; //이미 방문 했거나 경로에 산봉우리가 있으면 continue
            intensity[next] = max(intensity[curr], nextDist); //intensity 체크
            
            if(isGate[next]) continue; //gate라면 큐에는 넣지 않음
            q.push(next);
        }
    }
    
    int ret = INF;
    for(auto& gate : gates) //gate들의 intensity 비교
        if(intensity[gate] != -1)
            ret = min(ret, intensity[gate]);
    
    return ret;
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
        }); //cost를 기준으로 path를 정렬
    
    for(vector<int>& edge : paths) //MST를 구성
    {
        int u = edge[0], v = edge[1], cost = edge[2];
        
        if(djs.find(u) != djs.find(v))
        {
            djs.merge(u, v);
            adj[u].push_back({v, cost});
            adj[v].push_back({u, cost});
            if(++cnt == n-1) break; //n-1개를 pick 하면 break;
        }
    }
    
    for(auto &s : summits) isSummit[s] = true;
    for(auto &g : gates) isGate[g] = true; 
    sort(summits.begin(), summits.end()); //summit이 정렬되어있지 않음에 주의
  
    for(auto &start : summits) //정답 탐색
    {
        int temp = BFS(start, gates);
        if(temp < answer[1])
            answer = {start, temp};
    }
    
    return answer;
}
