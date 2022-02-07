#include <string>
#include <vector>

using namespace std;

string solution(vector<string> seoul)
{
    int ans = -1;  
    for(int i=0; i<seoul.size(); i++)
        if(seoul[i]=="Kim")
        {
            ans = i;
            break;
        }    
    return "김서방은 "+to_string(ans)+"에 있다";
}
