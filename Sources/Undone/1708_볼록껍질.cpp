#include <iostream>
#include <cmath>
#include <stack>
#include <algorithm>
using namespace std;

const int MAX = 100000;
typedef long long ll;

struct Point
{
	int x, y; //실제 위치
	int p, q; //기준점으로부터 상대 위치

	Point(int x1, int y1): x(x1), y(y1), p(1), q(0){}
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
	return 1LL * 
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);



	return 0;
}
