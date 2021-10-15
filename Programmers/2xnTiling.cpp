#include <string>
#include <vector>
using namespace std;

const int INF = 1000000007;
vector<int> cache(60001, 0);

int solution(int n)
{
    int answer = 0;
    
    cache[0]=cache[1]=1;
    for(int i=2; i<=n; i++)
        cache[i]=(cache[i-1]%INF + cache[i-2]%INF)%INF;
    
    return cache[n]%INF;
}
