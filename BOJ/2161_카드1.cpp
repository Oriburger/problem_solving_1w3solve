#include <iostream>
#include <queue>
using namespace std;

int n;
queue<int> q;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>n;

    for(int i=1; i<=n; i++) q.push(i);

    while(!q.empty())
    {
        cout<<q.front()<<' ';
        q.pop();
        if(q.empty()) break;

        q.push(q.front());
        q.pop();
    }

    return 0;
}
