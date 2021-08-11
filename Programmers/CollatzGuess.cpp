#include <string>
#include <vector>
using namespace std;

int solution(int n)
{
    int i = 0;
    
    long long num = n;
    for(i=0; i<500; i++)
    {
        if(num==1) break;
        else if(num%2==0) num/=2;
        else num=num*3+1;
    }
    
    return (i==500 ? -1 : i);
}
