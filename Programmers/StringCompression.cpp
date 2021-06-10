#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int GetLength(const string s, int len) //len만큼 끊어서 압축했을때, 문자열의 최소 길이
{
    string ret = "";
    
    for(int i=0; i<s.size(); i+=len)
    {
        int cnt = 0;
        string src = s.substr(i, len); //기준이 되는 문자열 src
        for(int j=i; j<s.size(); j+=len) //src가 범위 i~s.size에서 연속으로 몇 번이나 등장하는가?
        {
            if(src==s.substr(j, len)) cnt++; //연속으로 등장하는 횟수 카운팅
            else break; //다르다면 break
        }
        
        i += len*(cnt-1); //카운팅한 개수-1 만큼 증가 (반복문의 증감부에서 처리하기 때문)
        if(cnt > 1) ret+=(to_string(cnt)); //1보다 많다면? 숫자를 앞에 붙여줌
        ret+=src; //그리고 나서 기준 문자열을 붙임
    }
  
    return ret.size(); 
}

int solution(string s)
{
    int answer = 10000; //나올 수 없는 큰 값.
    
    for(int i=1; i<=s.size(); i++) //1개부터 하나씩 차례로 시도
            answer = min(answer, GetLength(s, i)); 
    
    return answer;
}
