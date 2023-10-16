#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

ll n, ans = 1;
vector<ll> a, cnt;
const ll INF = 1e9 + 7;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>n; 
    
    a = cnt = vector<ll>(n);
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
        cnt[a[i]] += 1;
    }
    sort(a.begin(), a.end()); 
    a.erase(unique(a.begin(), a.end()), a.end());

    for(int i=0; i<a.size(); i++)
    {
        const int k = cnt[a[i]] + 1;
        ans = ans * k % INF;
    }
    cout<<ans - 1<<'\n';

    return 0;
}
