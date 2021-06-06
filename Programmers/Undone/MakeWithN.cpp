#include <string>
#include <vector>
using namespace std;

const int INF = 2147000000;
int operand[8] = {1, 11, 111, 1111, 11111, 111111, 1111111, 11111111};

int GetAnswer(int curr, int level, const int target)
{
    if(level > 8) return INF;
    if(curr == target) return 0;
    
    int ret = INF;
    for(int j=-1; j<1; j*=-1)
    for(int i=1; i<=8; i++)
    {
        if(level + i > 8) break;
        
        ret = min(ret, GetAnswer(curr+(j*operand[i-1]), level+i, target)+i);
        ret = min(ret, GetAnswer(curr-(j*operand[i-1]), level+i, target)+i);
        ret = min(ret, GetAnswer((j*operand[i-1]-curr), level+i, target)+i);
        ret = min(ret, GetAnswer(curr*(j*operand[i-1]), level+i, target)+i);
        ret = min(ret, GetAnswer(curr/(j*operand[i-1]), level+i, target)+i);
        if(curr!=0) ret = min(ret, GetAnswer((j*operand[i-1])/curr, level+i, target)+i);
    }
    if(level + 2 <= 8)
    {
        ret = min(ret, GetAnswer(curr+1, level+2, target)+2);
        ret = min(ret, GetAnswer(curr-1, level+2, target)+2);
    }
    
    return ret;    
}

int solution(int N, const int number)
{
    int answer = INF;
    
    for(int i=1; i<=8; i++)  
    {
        operand[i-1] *= N;
        answer = min(answer, GetAnswer(operand[i-1], i, number)+i);
    }
    
    return answer==INF ? -1 : answer;
}
