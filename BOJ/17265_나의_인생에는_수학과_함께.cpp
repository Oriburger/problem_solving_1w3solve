#include <bits/stdc++.h>
#define INF 1e6
using namespace std;

const int dy[3] = {1, 0};
const int dx[3] = {0, 1};

int n, ans[2];
char board[5][5];

inline int getOpResult(const int& a, const int& b, char& op)
{
	if(op == '*') return a * b;
	else if(op == '+') return a + b;
	else if(op == '-') return a - b;
	return 0;
}

void getAnswer(int y, int x, string str)
{
	if(y>=n || x>=n) return;

	str += board[y][x];
	
	if(y==n-1 && x==n-1)
	{
		reverse(str.begin(), str.end());
		
		int a = str.back()-'0', b = 0;
		str.pop_back();
		
		while(str.size())
		{
			char op = str.back();
			str.pop_back();
			b = str.back() - '0';
			str.pop_back();
			
			a = getOpResult(a, b, op);
		}
		ans[0] = max(ans[0], a);
		ans[1] = min(ans[1], a);
		
		return;
	}
	for(int d=0; d<2; d++)
		getAnswer(y + dy[d], x + dx[d], str);
}

int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin>>n;

	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			cin>>board[i][j];

	ans[0]=-INF; ans[1]=INF;
	getAnswer(0, 0, "");
	
	cout<<ans[0]<<' '<<ans[1]<<'\n';
	
	return 0;
}
