#include <string>
#include <vector>

using namespace std;

void hanoi(vector<vector<int>>& ans, int num, char a, char b, char c)
{
    if(num == 1)
    {
        ans.push_back({a-'0', c-'0'}); //하나만 있다면, 바로 보낸다.
        return;
    }
    
    hanoi(ans, num-1, a, c, b); //num-1 만큼을 c를 거쳐 b로 보낸다
    ans.push_back({a-'0', c-'0'}); //맨 밑의 하나를 c로 보낸다
    hanoi(ans, num-1, b, a, c); //b로 보낸 num-1 만큼을 다시 a로 보낸다
}

vector<vector<int>> solution(int n) 
{
    vector<vector<int>> answer;
    
    hanoi(answer, n, '1', '2', '3');    
    
    return answer;
}
