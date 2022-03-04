#include <string>
#include <queue>
#include <vector>
using namespace std;

int solution(string name) 
{
    int answer = 0;
    int len = name.size(), min_val = len;
    vector<int> pos;
    
    for(int i=0; i<len; i++)
    {
        answer += min(name[i]-'A', 26+'A'-name[i]); //각 자리마다 바꾸는데에 필요한 최소 횟수를 더함
        if(name[i]!='A') pos.push_back(i);
    }
 
    if(pos.empty()) return answer; //바꿀게 없다면, 정답을 바로 반환
    
    min_val = min(len-*pos.begin(), pos.back()); //왼쪽으로 질러가는 방법 vs 오른쪽으로 질러가는 방법의 최소를 초기값으로 둠
    for(int i=1; i<pos.size(); i++) //인접한 두 점을 기준으로 잡고, 원점을 통과하는 경로를 만들어 각 경우당 최솟값을 구해서 min_val을 갱신
        min_val = min(min_val, len + pos[i-1] - pos[i] + min(pos[i-1], len-pos[i])); //min(pos[i-1], len-pos[i])는 추가로 더해지는 원점까지의 최소 거리
    
    return answer + min_val;
}
