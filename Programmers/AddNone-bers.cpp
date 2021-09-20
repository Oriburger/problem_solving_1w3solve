#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> numbers) 
{
    int answer = 0, idx=0;
    
    sort(numbers.begin(), numbers.end());
    
    for(int i=0; i<10; i++)
    {
        if(idx < numbers.size() && numbers[idx]==i) idx++;
        else answer+=i;
    }
    
    return answer;
}
