#include <iostream>
#include <vector>
using namespace std;

vector<unsigned int> state(10);
const int INF = 2147000000;
const int dy[5] = {0,1, -1, 0, 0};
const int dx[5] = {0, 0, 0, 1, -1};

void ShowInfo(int y)
{
    for(int x=0; x<10; x++)
        cout<< ((state[y] & (1<<x)) == (1<<x) ? 'O' : '#') <<' ';
    cout<<'\n';
}

inline bool isLightOn(int state, int x){ return (state & (1<<x)) == (1<<x); }

void toggleYX(int y, int x)
{
    if(y<0 || x<0 || y>=10 || x>=10) return;
    if(isLightOn(state[y], x))
        state[y] = ~(~state[y] | (~state[y] + (1 << x)));
    else state[y] |= (1<<x);
}

void toggleAround(int y, int x)
{
    for (int d = 0; d < 5; d++)
        toggleYX(y + dy[d], x + dx[d]);
}

int GetAnswer(int idx, int first, int cnt)
{
    if(idx==10)
    {
        vector<unsigned int> temp = state;
        for(int x=0; x<10; x++)
            if(isLightOn(first, x))
                toggleAround(0, x);

        for(int y=1; y<10; y++)
            for(int x=0; x<10; x++)
                if(isLightOn(state[y-1], x))
                {
                    cnt = cnt + 1;
                    toggleAround(y, x);
                }

        for(int x=0; x<10; x++)
            if(isLightOn(state[9], x))
                cnt = INF;

        state = temp;
        return cnt;
    }

    return min(GetAnswer(idx+1, first, cnt)
            , GetAnswer(idx+1, first | (1<<idx), cnt+1));
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    for(int i=0; i<10; i++)
    {
        string str; cin>>str;
        state[i] = (1<<11);
        for(int j=0; j<10; j++)
            if(str[j]=='O') state[i] |= (1<<j);
    }
    int ans = GetAnswer(0, 0, 0);
    cout<<(ans == INF ? -1 : ans)<<'\n';

    return 0;
}
