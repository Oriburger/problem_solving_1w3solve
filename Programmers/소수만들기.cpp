//https://school.programmers.co.kr/learn/courses/30/lessons/12977


#include <vector>
#include <cstring>
#include <iostream>
using namespace std;

vector<bool> isPrime(3001, true);

int solution(vector<int> nums) 
{
    int answer = 0;
    
    isPrime[0] = isPrime[1] = false;
    for(int i=2; i<=1500; i++)
        for(int j=2; i*j<=3000; j++)
            isPrime[i*j] = false;
    
    for(int i=0; i<nums.size(); i++)
        for(int j=i+1; j<nums.size(); j++)
            for(int k=j+1; k<nums.size(); k++)
                answer += isPrime[nums[i]+nums[j]+nums[k]];

    return answer;
}
