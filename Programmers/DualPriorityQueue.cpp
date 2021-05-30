#include <string>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

typedef deque<int>::iterator dIter;

vector<int> solution(vector<string> operations)
{
    deque<int> answer;
    
    for(const string &p : operations) //연산을 하나씩 수행
    {
        dIter iter;
        if(p[0]=='I') //삽입 연산이라면? 
        {
            int num = stoi(p.substr(2)); //숫자를 stoi와 substr을 활용해 추출
            iter = lower_bound(answer.begin(), answer.end(), num); //이분탐색으로 들어갈 자리를 탐색
            answer.insert(iter, num); //해당 자리에 insert
        }
        else if(p[0]=='D') //삭제 연산이라면? 
        {
            if(!answer.size()) continue; //만약, answer이 비었다면 무시
            
            if(p[2]=='-') answer.pop_front(); //최솟값을 pop
            else answer.pop_back(); //최댓값을 pop
        }
    }
    
    if(!answer.size()) return {0, 0}; //답이 없다면 0,0을 반환
    
    return {answer.back(), answer.front()}; //최대, 최소를 반환
}
