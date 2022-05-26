#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> P;

int n, k;
vector<P> arr; 

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin>>n;
    for(int i=0; i<n; i++)
    {
        int a, b; cin>>a>>b;
        arr.push_back({a, b});
        k = max(k, b);
    }
    sort(arr.begin(), arr.end(), [](P p1, P p2) -> bool
    {
        if(p1.second == p2.second) return p1.first < p2.first;
        return p1.second > p2.second;
    });
    
    for(auto &p : arr)
    {
        k = min(k, p.second);
        k -= p.first;
    }
    cout<<k<<'\n';
    
    return 0;
}
