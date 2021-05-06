#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<int>::iterator viter;

int solution(vector<int> arr)
{
    int answer = 0;
    
    sort(arr.begin(), arr.end()); //lower_bound 사용을 위해 정렬
    
    for(int h=arr.size(); h>=0; h--) //h는 최대 n이다.
    {
        //h값 이상의 위치를 찾는다.
        viter pos = lower_bound(arr.begin(), arr.end(), h);
        
        //찾을수가 없다면?
        if(pos == arr.end()) continue;
        //그렇지 않고, pos의 위치가 조건에 부합한다면
        else if(arr.end()-pos >= h) 
        {
            answer = h; //정답은 갱신
            break; //가장 큰 수부터 탐색을 진행하기 때문에, 최초로 찾은 값이 최대
        }
    }
    
    return answer;
}
