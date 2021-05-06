#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<int>::iterator viter;

int solution(vector<int> arr)
{
    int answer = 0;
    
    sort(arr.begin(), arr.end());
    
    for(int h=arr.size(); h>=0; h--)
    {
        viter pos = lower_bound(arr.begin(), arr.end(), h);
        
        if(pos == arr.end()) continue;
        else if(arr.end()-pos >= h) 
        {
            answer = h;
            break;
        }
    }
    
    return answer;
}
