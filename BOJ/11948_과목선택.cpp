#include <bits/stdc++.h>
using namespace std;

int answer = 0;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tmp = 1e9, score; 
    for(int i=0; i<4; i++)
    {
        cin>>score;
        answer += score; 
        tmp = min(tmp, score);
    }
    answer -= tmp;
    cin>>tmp>>score;
    answer += max(tmp, score);

    cout<<answer<<'\n';

    return 0;
}
