#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<int>::iterator viter;

int solution(vector<int> citations) 
{
    int answer = 0;
    sort(citations.begin(), citations.end()); //lower_bound 사용을 위해 정렬
    for(int h=0; h<=citations.size(); h++)
    {
        int q = citations.end() - lower_bound(citations.begin(), citations.end(), h);
        if(q >= h) answer = h; //h번이상 인용된 논문이 h편 이상이라면?
    }
    
    return answer;
}
