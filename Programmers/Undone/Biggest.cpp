#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> arr;

bool comp(string &a, string &b)
{
    for(int i=0; i<min(a.size(), b.size()); i++)
    {
        if(a[i] > b[i]) return true;
        else if(a[i] < b[i]) return false;
    }
}

string solution(vector<int> num)
{
    string ret; 
    
    for(int i=0; i<num.size(); i++)
        arr.push_back(to_string(num[i]));
    
    sort(arr.begin(), arr.end(), comp);
    
    for(int i=0; i<num.size(); i++)
        ret += arr[i];
    
    return to_string(stoi(ret));
}
