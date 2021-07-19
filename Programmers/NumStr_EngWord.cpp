#include <string>
#include <vector>

using namespace std;

vector<string> str_list = {"zero", "one", "two", "three", "four", "five"
                        , "six", "seven", "eight", "nine"};

int GetNum(const string str)
{
    for(int i=0; i<10; i++)
        if(str==str_list[i])
            return i;
    return -1;
}

int solution(string s)
{
    string answer, tmp;
    
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]>='0' && s[i]<='9')
        {
            answer.push_back(s[i]);
            tmp.clear();
        }
        
        else
        {
            tmp.push_back(s[i]);
            int n = GetNum(tmp);
        
            if(n==-1) continue;
            answer.push_back(n+'0');
            tmp.clear();
        }
    }
    
    return stoi(answer);
}
