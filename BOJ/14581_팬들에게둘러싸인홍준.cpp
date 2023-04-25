#include <bits/stdc++.h>
using namespace std;

const string fan = ":fan:";

int main()
{
    string str; cin>>str;
    str.insert(0, ":");
    str+=":";
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            if(i==1 && j==1) cout<<str;
            else cout<<fan;
        }
            
        cout<<'\n';
    }
    
    return 0;
}
//멈춰
