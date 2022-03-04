#include <string>
#include <vector>

using namespace std;

int solution(string name) 
{
    int answer = 0;
    
    //먼저, 각 자리별 최소 조작 횟수를 ans에 더한다.
    for(int i=0; i<name.size(); i++)
    {
        if(name[i]=='A') continue; //바꾸지 않아도 된다면
        else
        {
            int cnt = abs(name[i]-'A');
            answer += min(cnt, 26-cnt); //앞으로 이동, 뒤로 이동 둘 중 하나가 최소
        }
    }
    
    int curr = 0; //시작은 idx == 0
    vector<bool> visited(name.size(), false);
    visited[curr] = true;
    
    while(1)
    {
        int next = 0, nextDist = 9999; 
        //현재 자리에서 가장 가까운 자리로 이동한다
        for(int i=0; i<name.size(); i++) 
        {
            if(visited[i] || name[i]=='A') continue; //체크가 되어있거나, 바꾸지 않아도 되는 자리는 pass
            
            int temp = abs(curr - i);
            if(nextDist > min(temp, (int)name.size()-temp)) //찾은 자리보다 더 가깝다면? 
            {
                next = i; //next와 이동수인 nextDist 갱신
                nextDist = min(temp, (int)name.size()-temp);
            }
        }
        if(nextDist == 9999) break; //만약 이동을 마쳤다면 break; 
        
        curr = next; //자리 이동
        answer += nextDist; //이동한 만큼 더함 
        visited[next] = true; //체크
    }
    
    return answer;
}
