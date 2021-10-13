#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string s)
{
    string answer = "";
    vector<int> arr;
    
    for(int i=0; i<s.size(); i++)
    {
        bool minus = false;
        
        if(s[i]==' ') continue;
        else if(s[i]=='-')
        {
            minus = true;
            i += 1;
        }
        int temp = s[i]-'0';
        arr.push_back(temp * (minus ? -1 : 1));
    }
    
    sort(arr.begin(), arr.end());
    
    for(int i=0; i<arr.size(); i+=arr.size()-1)
    {
        answer+=(to_string(arr[i]));
        if(i<arr.size()-1) answer.push_back(' ');
    }
    
    return answer;
}
