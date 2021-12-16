#include <iostream>
#include <cmath>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 100000;
typedef long long ll;

struct Point
{
	int x, y; //실제 위치
	int p, q; //기준점으로부터 상대 위치

	Point(int x1=0, int y1=0): x(x1), y(y1), p(1), q(0){}
};

bool CompPoint(const Point &A, const Point &B)
{
	if(1LL * A.q * B.p != 1LL * A.p * B.q)
		return 1LL * A.q * B.p < 1LL * A.p * B.q;

	if(A.y != B.y) return A.y < B.y;

	return A.x < B.x;
}

ll CCW(const Point &A, const Point &B, const Point &C)
{
	return 1LL*(B.x-A.x)*(C.y-A.y) - 1LL*(B.y-A.y)*(C.x-A.x);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	vector<Point> p;

	cin>>n;
	p.resize(n);
	for(int i=0; i<n; i++)
	{
		int x, y;
		cin>>x>>y;
		p[i] = Point(x, y);
	}

	//y좌표 x좌표가 작은순으로 정렬 
	// => 기준점인 0번 점이 왼쪽 제일 아래에 위치
	sort(p.begin(), p.end(), CompPoint);

	//기준점인 0번 점으로부터 상대 위치를 계산한다.
	for(int i=1; i<n; i++)
	{
		p[i].p = p[i].x - p[0].x;
		p[i].q = p[i].y - p[0].y;
	}
	//기준점을 제외한 점들을 반시계 방향으로 정렬
	sort(p.begin()+1, p.end(), CompPoint);

	stack<int> stk;
	stk.push(0); //스택에 0, 1번 점을 넣음
	stk.push(1);
	
	int next = 2;
	while(next<n)
	{
		while(stk.size() >= 2)
		{
			int first, second;
			first=stk.top();
			stk.pop();
			second=stk.top();

			//first, second, next가 CCW(반시계 방향)이라면, first를 push
			//CW(시계 방향)이라면, while문 반복
			if(CCW(p[second], p[first], p[next]) > 0)
			{
				stk.push(first);
				break;
			}
		}
		stk.push(next++);
	}

	cout<<stk.size()<<'\n';

	return 0;
}
