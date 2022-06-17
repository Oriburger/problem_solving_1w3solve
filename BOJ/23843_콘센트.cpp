#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, ans=0;
vector<int> t;
priority_queue<int, vector<int>, greater<int> > pq;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>n>>m;

    t = vector<int>(n);
    for(int i=0; i<n; i++)
        cin>>t[i];

    sort(t.begin(), t.end(), greater<int>());

    for(int i=0; i<m; i++)
        pq.push(0);

    for(int i=0; i<n; i++)
    {
        int temp = t[i] + pq.top();
        pq.pop(); pq.push(temp);
    }

    while(!pq.empty())
    {
        ans = max(ans, pq.top());
        pq.pop();
    }
    cout<<ans<<'\n';

    return 0;
}
