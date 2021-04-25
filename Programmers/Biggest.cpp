#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> arr;

bool comp(string &a, string &b)
{
    const int n1 = stoi(a+b);
    const int n2 = stoi(b+a);
    return n1 > n2;
}

string solution(vector<int> num)
{
    string tmp, ret;
    
    for(int i=0; i<num.size(); i++)
        arr.push_back(to_string(num[i]));
    
    sort(arr.begin(), arr.end(), comp);
    
    for(int i=0; i<num.size(); i++)
        tmp = tmp + arr[i];
    
    bool flag = false;
    for(int i=0; i<tmp.size(); i++)
    {
        if(!flag && tmp[i]=='0') continue;
        ret.push_back(tmp[i]);
        flag = true;
    }
    if(ret=="") ret = "0";
    
    return ret;
}
