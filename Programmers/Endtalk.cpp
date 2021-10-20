#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

unordered_map<string, int> check;

vector<int> solution(int n, vector<string> words)
{
    vector<int> answer = {0, 0};
    bool flag = false;
    int count = 0;

    for(int i=0; i<words.size(); i++)
    {
        string curr_str = words[i];
        int curr_user = i%n;
        
        if(i>0)
        {
            string prev_str = words[i-1];
            if(curr_str[0] != prev_str[prev_str.size()-1])
                flag = true;
        }
        
        if(check.count(curr_str) || curr_str.size()==1)
            flag = true;
        
        if(flag)
        {
            answer = {curr_user+1, i/n+1};
            break;
        }
        check[curr_str]=count++;
    }

    return answer;
}
