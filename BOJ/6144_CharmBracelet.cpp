#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int n, m, w[3403], d[3403];
int cache[12881], ans=0;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>n>>m;

    memset(cache, -1, sizeof(cache));
    for(int i=0; i<n; i++)
        cin>>w[i]>>d[i];

    cache[0] = 0;
    for(int i=0; i<n; i++)
        for(int j=m; j>=w[i]; j--)
            if(cache[j-w[i]] != -1)
                cache[j] = max(cache[j], cache[j - w[i]]+d[i]);


    for(int i=0; i<=m; i++)
        ans = max(ans, cache[i]);
    cout<<ans<<'\n';

    return 0;
}
