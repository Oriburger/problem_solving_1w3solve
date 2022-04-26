#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge { int dist; int u; int v; };
bool comp(const Edge& e1, const Edge& e2) { return e1.dist > e2.dist; }

int n, k, ans;
vector<Edge> edges;
vector<int> height;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin>>n>>k;
    height = vector<int>(n);
    for(int i=0; i<n; i++)
    {
        cin>>height[i];
        if(i>=1) edges.push_back({height[i]-height[i-1], i-1, i});
    }
    
    sort(edges.begin(), edges.end(), comp);
    
    for(int i=0; i<edges.size(); i++)
    {
        if(i < k-1) continue;
        ans += edges[i].dist;
    }
    
    cout<<ans<<'\n';
    
    return 0;
}
