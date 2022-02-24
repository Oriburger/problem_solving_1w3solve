#include <bits/stdc++.h>
using namespace std;

int A, B, C;
bool visited[201][201][201];
vector<int> ans;

void Solve(int a, int b, int c)
{
	if(a<0 || b<0 || c<0) return; 
	if(visited[a][b][c]) return;
	
	visited[a][b][c] = true;
	if(a==0) ans.push_back(c);
	
	if(b!=B)
	{
		Solve(a - min(a, B-b), b + min(a, B-b), c); //a->b
		Solve(a, b + min(c, B-b), c - min(c, B-b)); //c->b
	}
	if(a!=A)
	{
		Solve(a + min(b, A-a), b - min(b, A-a), c); //b->a
		Solve(a + min(c, A-a), b, c - min(c, A-a)); //c->a
	}
	if(c!=C)
	{
		Solve(a - min(a, C-c), b, c + min(a, C-c)); //a->c
		Solve(a, b - min(b, C-c), c + min(b, C-c)); //b->c	
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin>>A>>B>>C;
	
	Solve(0, 0, C);
	
	sort(ans.begin(), ans.end());
	ans.erase(unique(ans.begin(), ans.end()), ans.end());
	for(auto &p : ans)
		cout<<p<<' ';
	
	return 0;
}
