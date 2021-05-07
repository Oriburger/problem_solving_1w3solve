#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int answer = 0;
const int MAX = 10000000;

vector<bool> isPrime(MAX, true); //isPrime[k] : k는 소수인가?
vector<bool> visited, checked; //visited : str에서 뽑은거 체크
                               //checked : 정답 중복체크 방지
void GetNum(const string& str, string picked, int toPick)
{
    if(toPick==0) //더 고를게 없다면 
    {
        //이 수가 소수이고, 정답으로 체크가 안되었다면
        if(isPrime[stoi(picked)]
          && !checked[stoi(picked)])
        {
            answer++; //정답으로 체크 
            checked[stoi(picked)]=true; //중복 방지 체크
        }
        return;
    }
    
    for(int i=0; i<str.size(); i++)
    {
        if(visited[i]) continue; //이미 수를 만드는데에 사용되었다면 pass
        
        visited[i]=true;
        picked.push_back(str[i]);

        GetNum(str, picked, toPick-1);

        picked.pop_back();
        visited[i]=false;
    }
}

int solution(string numbers)
{
    //에라토스테네스의 체 알고리즘으로 소수들을 모두 찾아준다
    isPrime[0]=isPrime[1]=false;
    for(int i=2; i<MAX; i++)
        for(int j=2; i*j < MAX; j++)
            isPrime[i*j] = false;
    
    //checked 배열 초기화
    checked.resize(MAX, false);        
    //가능한 길이에서 모두 소수를 찾아준다
    for(int i=1; i<=numbers.size(); i++)
    {
        visited = vector<bool>(7, false);
        GetNum(numbers, "", i);
    }
    
    return answer;
}
