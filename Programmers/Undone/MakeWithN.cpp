#include <string>
#include <vector>
using namespace std;

const int MAX = 32001;

int arr[5]={1, 11, 111, 1111, 11111};
vector<int> cache(MAX+1, -1);

//n을 만드는데 쓰이는 N의 최소 갯수 
int DP(int n)
{
    int &ret = cache[n];
    if(ret != -1) return ret;
    else if(ret > 8) return ret = MAX;
    else if(ret==0) return ret=2;
    
    ret = 2147000000;
    for(int i=1; i<=5; i++)
    {
        if(n+arr[i-1] < MAX)
            ret = min(ret, DP(n+arr[i-1])+i);
        if(n-arr[i-1] >= 0)
            ret = min(ret, DP(n-arr[i-1])+i);
        if(n*arr[i-1] < MAX)
            ret = min(ret, DP(n*arr[i-1])+i);
        ret = min(ret, DP(n/arr[i-1])+i);
    }
    
    return ret;
}

int solution(int N, int number)
{
    for(int i=0; i<5; i++)
    {
        arr[i]*=N;
        if(arr[i]>=MAX) continue;
        cache[arr[i]]=i+1;
    }
    
    DP(MAX-1);
    
    return cache[number]>8 ? -1 : cache[number];
}
