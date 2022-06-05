#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

typedef long long ll;
int t, k; ll ans = 0;
priority_queue<ll, vector<ll>, greater<ll> > pq;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>t;
    while(t--)
    {
        cin>>k;
        for(int i=0; i<k; i++)
        {
            int tmp; cin>>tmp;
            pq.push(tmp);
        }

        while(1)
        {
            ll comb = 0;
            for(int i=0; i<2 && !pq.empty(); i++)
            {
                comb += pq.top();
                pq.pop();
            }
            ans += comb;

            if(pq.empty()) break;
            pq.push(comb);
        }
        cout<<ans<<'\n';
        ans = 0;
    }

    return 0;
}
