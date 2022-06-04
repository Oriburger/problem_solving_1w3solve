#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string s, t;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>s>>t;

    while(1)
    {
        if(s==t || t.empty()) break;
        char tmp = t.back();
        t.pop_back();
        if(tmp=='B') reverse(t.begin(), t.end());
    }
    cout<<(s==t ? 1 : 0)<<'\n';

    return 0;
}
