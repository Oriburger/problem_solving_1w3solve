/*
2018 Kakao Blind Recruitment 1차 - 뉴스 클러스터링
*/

#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

bool isAlphabet(const char c)
{
	if(c<='Z' && c>='A') return true;
	return false;
}

unordered_map<string, int> GetMultiSet(const string &str)
{
    unordered_map<string, int> ret;
    for(int i=0; i<str.size()-1; i++)
    {       
        string temp = str.substr(i, 2);    

    	if(!isAlphabet(temp[0]) || !isAlphabet(temp[1])) continue;
        
        if(ret.find(temp)==ret.end())
            ret[temp]=1;
        else
            ret[temp]++;
    }
    return ret;
}

string upperStr(string str)
{
    for(int i=0; i<str.size(); i++)
        if(str[i]<='z' && str[i]>='a')
            str[i]=toupper(str[i]);
    return str;
}

int solution(string str1, string str2) 
{
    int uni=0, inter=0; //합집합, 교집합
    unordered_map<string, int> set1, set2;
 
    str1 = upperStr(str1);
    str2 = upperStr(str2);
    set1 = GetMultiSet(str1);
    set2 = GetMultiSet(str2);
    
    unordered_map<string, int>::iterator iterPos;
    for(iterPos = set1.begin(); iterPos != set1.end(); iterPos++)
    {
        if(set2.find(iterPos->first) != set2.end()) //set2에 iterPos->first 가 있다면?
        {
            uni += max(set1[iterPos->first], set2[(iterPos->first)]); //합집합의 개수++
            inter += min(set1[iterPos->first], set2[(iterPos->first)]);
        }
        else uni += set1[iterPos->first];
    }
    for(iterPos = set2.begin(); iterPos != set2.end(); iterPos++)
    {
        if(!set1.count(iterPos->first)) 
            uni += set2[iterPos->first];
	}

    if(!inter && !uni) return 65536;
    else if(!inter) return 0;
    
    return inter*65536/uni;
}
