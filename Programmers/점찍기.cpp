//https://school.programmers.co.kr/learn/courses/30/lessons/140107#

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll; 

ll solution(int k, int d) 
{
    ll answer = 0;
    vector<ll> arr; //k의 배수
    
    for(ll a=0; a*k<=d; a++)
        arr.push_back(pow(a*k, 2));
    
    for(ll a=0; a<=d; a+=k)
    {
        ll temp = (upper_bound(arr.begin(), arr.end(), pow(d, 2) - pow(a, 2)) - arr.begin());
       // cout<<"a : "<<a<<")   ";
       // cout<<*upper_bound(arr.begin(), arr.end(), pow(d, 2) - pow(a, 2))<<", "<<pow(d, 2) - pow(a, 2)<<" /// ";
       // cout<<arr[temp]<<", "<<temp<<"\n";
        answer += temp;
    }
    
    //1000000000000
    //2147000000
    
    return answer;
}
