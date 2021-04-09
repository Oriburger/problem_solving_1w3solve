#include <string>
#include <vector>
using namespace std;

vector<int> arr;
int k;

int Answer(int idx, int curr)
{
    if(idx == arr.size())
        return curr==k;
    
    int ret = 0;
    
    ret += Answer(idx+1, curr+arr[idx]);
    ret += Answer(idx+1, curr-arr[idx]);
    
    return ret;
}

int solution(vector<int> numbers, int target) 
{
    arr = numbers;    
    k = target;
    
    return Answer(0, 0);
}
