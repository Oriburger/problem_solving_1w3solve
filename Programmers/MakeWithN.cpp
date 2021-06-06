#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

unordered_set<int> uset[9];
const int temp[8] = {1, 11, 111, 1111, 11111, 111111, 1111111, 11111111};

int solution(int N, const int number)
{    
    for(int i=1; i<=8; i++)
        uset[i].insert(temp[i-1]*N);
    
    for(int i=1; i<=8; i++)
    {
        for(int j=1; j<=i; j++)
        {
            if(i + j > 8) continue;
            
            for(int a : uset[i])
            {
                for(int b : uset[j])
                {
                    if(a!=b) uset[i+j].insert(abs(a-b));
                    uset[i+j].insert(a+b);
                    uset[i+j].insert(a*b);
                    if(a && b) uset[i+j].insert(max(a, b)/min(a, b));
                }
            }
        }
    }
    
    int answer = -1;
    
    for(int i=1; i<=8; i++)
        if(uset[i].count(number))
        {
            answer = i;
            break;
        }
    
    return answer;
}
