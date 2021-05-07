#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int answer = 0;
const int MAX = 10000000;

vector<bool> isPrime(MAX, true);
vector<bool> visited, checked;

void GetNum(const string& str, string picked, int toPick)
{
    if(toPick==0)
    {
        if(isPrime[stoi(picked)]
          && !checked[stoi(picked)])
        {
            answer++;
            checked[stoi(picked)]=true;
        }
        return;
    }
    
    for(int i=0; i<str.size(); i++)
    {
        if(visited[i]) continue;
        
        visited[i]=true;
        picked.push_back(str[i]);
        GetNum(str, picked, toPick-1);
        picked.pop_back();
        visited[i]=false;
    }
}

int solution(string numbers)
{
    isPrime[0]=isPrime[1]=false;
    for(int i=2; i<MAX; i++)
        for(int j=2; i*j < MAX; j++)
            isPrime[i*j] = false;
    
    checked.resize(MAX, false);        
    for(int i=1; i<=numbers.size(); i++)
    {
        visited = vector<bool>(7, false);
        GetNum(numbers, "", i);
    }
    
    return answer;
}
