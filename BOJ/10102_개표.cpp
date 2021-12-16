#include <iostream>
using namespace std;

int main()
{
    int v; cin>>v;
    int aCnt=0, bCnt=0;
    while(v--)
    {
        char input;
        cin>>input;
        if(input=='A') aCnt++;
        else if(input=='B') bCnt++;
    }    
    
    if(aCnt>bCnt) cout<<"A\n";
    else if(aCnt<bCnt) cout<<"B\n";
    else cout<<"Tie\n";

    return 0;
}
