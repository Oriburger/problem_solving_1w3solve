#include <iostream>
using namespace std;

int solution(int n)
{
    if(n <= 2) return 1;
    
    int ans = 0;

    if(n%2) ans = solution(n-1) + 1;
    else ans = solution(n/2);
    
    return ans;
}
