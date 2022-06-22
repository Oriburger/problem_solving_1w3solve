#include <iostream>
#include <vector>
using namespace std;

vector<unsigned int> state(10);
const int INF = 2147000000;
const int dy[5] = {0,1, -1, 0, 0}; //본인 좌표 + 상하좌우
const int dx[5] = {0, 0, 0, 1, -1};

//현재줄(state)의 x좌표에 불이 켜져있는지?
inline bool isLightOn(int state, int x){ return (state & (1<<x)) == (1<<x); }

//y, x 좌표에 toggle!
void toggleYX(int y, int x)
{
    if(y<0 || x<0 || y>=10 || x>=10) return; //범위 내에서만 진행
    if(isLightOn(state[y], x)) //불이 켜져있으면 끔
        state[y] = ~(~state[y] | (~state[y] + (1 << x)));
    else state[y] |= (1<<x); //꺼져있으면 켬
}

//y, x 좌표에 버튼을 누름 (자기자신 + 상하좌우) toggle
void toggleAround(int y, int x)
{
    for (int d = 0; d < 5; d++)
        toggleYX(y + dy[d], x + dx[d]);
}

//첫째줄의 idx번째를 toggle할지 말지 여부를 first에 저장. 
//2^10번의 경우를 모두 탐색  /  cnt는 총 toggle 횟수 
int GetAnswer(int idx, int first, int cnt)
{
    if(idx==10) //첫번째 줄의 각 경우에 대해
    {
        vector<unsigned int> temp = state; //state 원본 저장
        for(int x=0; x<10; x++) //first를 기반으로 toggle 연산 진행
            if(isLightOn(first, x))
                toggleAround(0, x);

        for(int y=1; y<10; y++) //두번째 줄~마지막 줄
            for(int x=0; x<10; x++) 
                if(isLightOn(state[y -1], x)) //바로 위 전구가 켜져있다면 toggle
                {
                    cnt = cnt + 1;
                    toggleAround(y, x);
                }

        for(int x=0; x<10; x++) //마지막 줄 체크
            if(isLightOn(state[9], x))
                cnt = INF; //불이 켜져있다면 INF 반환

        state = temp; //backtrack!
        return cnt;
    }

    return min(GetAnswer(idx+1, first, cnt) //toggle 안함
            , GetAnswer(idx+1, first | (1<<idx), cnt+1)); //toggle 함
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    //입력
    for(int i=0; i<10; i++)
    {
        string str; cin>>str;
        state[i] = (1<<11);
        for(int j=0; j<10; j++)
            if(str[j]=='O') state[i] |= (1<<j);
    }

    int ans = GetAnswer(0, 0, 0);
    cout<<(ans == INF ? -1 : ans)<<'\n'; //INF이면 모두 끌 수 있는 방법이 없음

    return 0;
}
