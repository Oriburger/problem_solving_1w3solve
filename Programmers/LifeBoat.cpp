#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<int>::iterator iter;

int solution(vector<int> people, int limit) 
{
    int answer = 0;
    vector<int> tmp;
    
    sort(people.begin(), people.end());
    iter lo = people.begin(), hi = people.end()-1;
    while(lo<=hi)
    {
        if(*lo + *hi > limit)
        {
            hi--;
            answer++;
        }
        else
        {
            lo++; hi--;
            answer++;
        }
    }
    
    return answer;
}
