#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k, ans;
vector<int> t, dist;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin>>n>>k;
    t = vector<int>(n);
    for(int i=0; i<n; i++)
        cin>>t[i];
    sort(t.begin(), t.end());
    
    for(int i=1; i<n; i++)
        dist.push_back(abs(t[i]-t[i-1]-1));
    sort(dist.begin(), dist.end());
    
    ans = n;
    for(int i=0; i<n-k; i++)
        ans += dist[i];
        
    cout<<ans<<'\n';
    
    return 0;
}
