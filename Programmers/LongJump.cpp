#include <string>
#include <vector>
using namespace std;

typedef long long ll;

const ll INF = 1234567;
vector<ll> cache(2001, 0);

ll solution(int n)
{
    ll &ret = cache[n];
    if(ret) return (ret%INF);
    if(n<=2) return ret = n; //기저사례
    
    ret = (ret%INF + solution(n-2)%INF)%INF;
    ret = (ret%INF + solution(n-1)%INF)%INF;
    
    return ret;
}
