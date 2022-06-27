#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

typedef pair<int, bool> P;
int n, ans, cnt;
vector<P> arr;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>n;
    for(int i=0; i<n; i++)
    {
        int tmp, a, b;
        cin>>tmp>>a>>b;
        arr.push_back({a, 1});
        arr.push_back({b, 0});
    }
    sort(arr.begin(), arr.end());

    for(auto &p : arr)
    {
        if(p.second) cnt+=1;
        else cnt-=1;
        ans = max(ans, cnt);
    }
    cout<<ans<<'\n';

    return 0;
}
