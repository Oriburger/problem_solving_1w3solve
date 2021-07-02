#include <string>
#include <vector>
using namespace std;

int cache[100001];

int solution(int n)
{
    if(n<0) return 0;
    int &ret = cache[n];

    if(ret!=0 || n==0) return ret;
    if(n==1) return ret = 1;

    return ret = (solution(n-1) + solution(n-2))%1234567;
}
