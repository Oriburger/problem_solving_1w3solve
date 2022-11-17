#include <iostream>
#include <vector>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> P;
typedef long long ll;

ll t, n, answer = 0;
const ll INF = 1e9+7;
priority_queue<ll, vector<ll>, greater<ll> > pq;
vector<ll> resultList;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>t;

    while(t--)
    {
        cin>>n;

        for(int i=0; i<n; i++)
        {
            ll tmp; cin>>tmp;
            pq.push(tmp);
        }

        if(n==1)
        {
            cout<<1<<'\n';
            pq.pop();
            continue;
        }

        answer = 1;
        while(!pq.empty())
        {
            ll target[2] = {-1, -1}, result = 0;
            for(int i=0; i<2; i++)
            {
                if(pq.empty()) break;
                target[i] = pq.top();
                pq.pop();
            }
            if(target[1]==-1) break;
            answer *= ((target[0]%INF) * (target[1]%INF))%INF;
            answer %= INF;
            pq.push(target[0] * target[1]);
        }
        cout<<answer<<'\n';
    }

    return 0;
}
