#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

unordered_map<char, int> umap;

//기준 문자열 s1, 비교대상 문자열s2
//s2에 s1의 문자들이 몇개가 존재하는지 반환
int GetFrontMatchCnt(string s1, string s2)
{
    int ret = 0;
    
    for(int i=0; i<s1.size(); i++)
        for(int j=0; j<s2.size(); j++)
            if(s1[i] == s2[j])
                ret++;
    
    return ret;
}

int solution(string skill, vector<string> skill_trees)
{
    int answer = 0;
    
    for(const auto &s : skill_trees)
    {
        int idx = 0, cnt = GetFrontMatchCnt(skill, s);
        for(int i=0; i<s.size(); i++)   
            if(skill[idx] == s[i]) 
                idx++; 
        if(idx == cnt) answer++;
    }
    
    return answer;
}
