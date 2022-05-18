#include <bits/stdc++.h>
using namespace std;

int n, m, arr[21];
int cache[10001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int t; cin>>t;
    
    while(t--)
    {
        cin>>n;
        for(int i=0; i<n; i++)
            cin>>arr[i];
        cin>>m;
        
        memset(cache, 0, sizeof(cache));
        
        cache[0] = 1;
        for(int i=0; i<n; i++)
            for(int j=arr[i]; j<=m; j++)
                cache[j] += cache[j - arr[i]];
                
        cout<<cache[m]<<'\n';
        
    }
    
    return 0;
}
