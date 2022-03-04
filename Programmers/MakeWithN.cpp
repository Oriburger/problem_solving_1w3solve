#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

int tmp[8] = {1, 11, 111, 1111, 11111, 111111, 1111111, 11111111};
unordered_set<int> cache[9];

int solution(int N, int number) 
{
    int answer = 0;
    
    for(int i=1; i<9; i++)
        cache[i].insert(tmp[i-1]*N);
    
    for(int i=1; i<=8; i++)
    {
        for(int j=1; j<=i; j++)
        {
            if(i+j > 8) continue;
            
            for(auto &p : cache[i])
            {
                for(auto &q : cache[j])
                {
                    if(p!=q) cache[i+j].insert(abs(p-q));
                    cache[i+j].insert(p*q);
                    cache[i+j].insert(p+q);
                    if(p&&q) cache[i+j].insert(max(p,q)/min(p,q));
                }
            }
        }
    }
    
    answer = -1;
    for(int i=1; i<=8; i++)
        if(cache[i].count(number) > 0)
        {
            answer = i;
            break;
        }
    
    return answer;
}
