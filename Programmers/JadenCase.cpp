#include <string>
#include <vector>
#include <cctype>
#include <algorithm>
using namespace std;

string solution(string s)
{   
    string answer = "";
    
    for(int i=0; i<s.size(); i++)
    {
        if(i==0 || s[i]==' ')
        {
            while(s[i]==' ')
                answer.push_back(s[i++]);
            
            if(i==s.size()) break;
            
            answer.push_back(toupper(s[i]));
            continue;
        }
        answer.push_back(tolower(s[i]));
    }
    
    return answer;
}
