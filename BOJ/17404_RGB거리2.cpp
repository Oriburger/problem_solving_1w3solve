#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int n, ans;
int cost[1001][3], cache[1001][3][3];
const int INF = 1000001;

int GetAnswer(int idx, int prev, int first)
{
    if(idx > n) return 0;
    int& ret = cache[idx][prev][first];
    if(ret != INF) return ret;

    for(int i=0; i<3; i++)
    {
        if(prev==i || (idx == n && i == first)) continue;
        int temp = GetAnswer(idx+1, i, idx==1 ? i : first) + cost[idx][i];
        ret = min(ret, temp);
    }
    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>n;

    memset(cost, 0, sizeof(cost));
    fill(&cache[0][0][0], &cache[1000][2][3], INF);
    for(int i=1; i<=n; i++)
        for(int j=0; j<3; j++)
            cin>>cost[i][j];

    ans = GetAnswer(0, 0, 0);

    cout<<ans<<'\n';

    return 0;
}
