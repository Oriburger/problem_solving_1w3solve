#include <vector>
#include <iostream>
using namespace std;

bool prime[3001];

int solution(vector<int> nums) 
{
    int answer = 0;

    prime[0] = prime[1] = true;
    for(int i=2; i<=3000; i++)
        for(int j=2; i*j<=3000; j++)
            prime[i*j]=true;
    
    for(int i=0; i<nums.size(); i++)
      for(int j=i+1; j<nums.size(); j++)
        for(int k=j+1; k<nums.size(); k++)
            answer += !prime[nums[i]+nums[j]+nums[k]];
    
    return answer;
}
