#include <iostream>

using namespace std;
int solution(int n)
{
    int answer = 0;

    while(1)
    {
        if(n==0) break;
        answer += n%10;
        n/=10;
    }

    return answer;
}
