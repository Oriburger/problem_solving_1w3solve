#include <string>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

struct Edge { int cost; int u; int v; };
bool CompEdge(const Edge &e1, const Edge &e2) {   return e1.cost <= e2.cost; }

struct DisjointSet
{
    vector<int> parent, rank;
    
    DisjointSet(int n) : parent(n), rank(n, 1)
    {
        for(int i=0; i<n; i++)
            parent[i]=i;
    }
    
    int find(int u)
    {
        if(u==parent[u]) return u;
        return parent[u] = find(parent[u]);
    }
    
    void merge(int u, int v)
    {
        u = find(u); v = find(v);
        if(u==v) return;
        
        if(rank[u] > rank[v]) swap(u, v);
        parent[u] = v;
        if(rank[u] == rank[v]) rank[v]+=1;
    }
};

int solution(int n, vector<vector<int>> costs) 
{
    int answer = 0;
    
    vector<Edge> edges;
    for(int i=0; i<costs.size(); i++) //간선정렬을 위해 새 배열 구성
        edges.push_back({costs[i][2], costs[i][0], costs[i][1]});
    sort(edges.begin(), edges.end(), CompEdge); //정렬
    
    int cnt = 0;
    DisjointSet djs(n);
    for(auto &e : edges) //크루스칼 알고리즘
    {
        if(cnt == n-1) break; //간선을 n-1개 골랐다면, break
        if(djs.find(e.u)==djs.find(e.v)) continue; //이미 연결된 섬이라면
        
        djs.merge(e.u, e.v); // 섬 연결
        answer += e.cost; //연결비용 더함
        cnt += 1; //cnt++
    }
    
    return answer;
}
