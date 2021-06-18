#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> menus;

// 길이가 len인 가능한 모든 메뉴 리스트를 menus에 저장
void GetMenu(string& picked, char curr, const int len) 
{
    if(picked.size()==len)
    {
        menus.push_back(picked);
        return;
    }
    
    for(char i=curr+1; i<='Z'; i++)
    {
        picked.push_back(i);
        GetMenu(picked, i, len);
        picked.pop_back();
    }
}

//st2에 메뉴가 포함되어있는지 여부를 반환
bool IsIncluded(string st1, string st2)
{
    for(int i=0; i<st1.size(); i++)
    {
        bool flag = false;
        for(int j=0; j<st2.size(); j++)
        {
            if(st1[i]==st2[j])
            {
                flag = true;
                break;
            }
        }
        if(!flag) return false;
    }
    return true; 
}

vector<string> solution(vector<string> orders, vector<int> course)
{
    vector<string> answer;
   
    for(int &len : course)
    {
        string temp="";
        GetMenu(temp, 'A'-1, len); //가능한 메뉴들을 찾는다
        
        int maxCnt = 0;
        vector<string> pick;
        for(string &menu : menus) //메뉴 후보들을 하나씩 골라서
        {
            int cnt = 0;
            for(string& order : orders) //주문 목록에 몇개가 포함되어있는지 찾음
                if(IsIncluded(menu, order)) cnt++; //있다면 cnt증가
            
            if(cnt < 2) continue; //2명보다 작다면 continue
            else if(maxCnt < cnt) //더 많은 손님이 주문했다면
            {
                pick.clear(); //기존에 담았던걸 지우고
                maxCnt = cnt; //최대값 갱신
            }
            else if(maxCnt > cnt) continue;
            pick.push_back(menu); //찾은 후보를 pick에 넣는다
        }
        for(string& p : pick) //최종적으로 찾은 후보들을 answer에 넣음
            answer.push_back(p);
       
        menus.clear();
    }
    
    sort(answer.begin(), answer.end()); //정렬 
    
    return answer;
}
