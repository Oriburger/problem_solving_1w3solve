#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

struct Pos {int y; int x;};
const int INF = 2147000000;
const int M_INF = -2147000000;

int n, w;
vector<Pos> task; 
int cache[1001][1001]; //메모이제이션
Pos trace[1001][1001]; //추적을 위한 배열,,   utility의 pair을 사용하기엔 귀찮았따ㅏㅏ..

inline int GetDist(int p1, int p2) //task[p1]과 task[p2]의 맨해튼 거리를 반환
{
	return abs(task[p1].y-task[p2].y) + abs(task[p1].x-task[p2].x);
}

int GetAnswer(int pa, int pb)
{
	if(pa == w+1 || pb == w+1) return 0;
	
	int &ret = cache[pa][pb];
	if(ret != -1) return ret;

	ret = INF;

	int next, val1, val2;
	
	next = max(pa, pb) + 1;
	val1 = GetAnswer(next, pb) + GetDist(pa, next);
	val2 = GetAnswer(pa, next) + GetDist(pb, next);

	if(val1 < val2)
		trace[pa][pb] = {next, pb}; //GetAnswer(pa, pb)의 결과가 무엇이었는지 저장
	else
		trace[pa][pb] = {pa, next};

	return ret = min(val1, val2);
}

int main()
{
	ios::sync_with_stdio(false); // IO 속도향상
	cin.tie(NULL); cout.tie(NULL);

	cin>>n>>w;

	task.push_back({1, 1}); //경찰차의 초기위치
	task.push_back({n, n}); //
	for(int i=0; i<w; i++)
	{
		int y, x;
		cin>>y>>x;
		task.push_back({y, x});
	}

	memset(cache, -1, sizeof(cache));
	cout<<GetAnswer(0, 1)<<'\n'; 

	int pa = 0, pb = 1; //초기 경찰차의 위치 idx
	for(int i=2; i<=w+1; i++) //2 ~ w+1까지 반복
	{
		Pos next = trace[pa][pb]; //GetAnswer(pa, pb)의 결과가 무엇이었는지? 

		if(next.y == pa) cout<<2<<'\n'; //만약 next의 첫번째 멤버가 pa라면?  
		else cout<<1<<'\n';             //ㄴ> 즉, pb가 해당 사건을 맡았다면? 2 출력, 
                                        //                    그렇지 않으면? 1 출력

		pa = next.y;  //다음 pa, pb 갱신 
		pb = next.x;
	}

	return 0;
}
