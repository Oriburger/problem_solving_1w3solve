#include <bits/stdc++.h>
using namespace std;

struct P{ int a, b; };

string str[3];

bool GetAnswer()
{
	if(str[0].size() + str[1].size() != str[2].size()) return false;

	queue<P> q;
	bool visited[201][201];
	memset(visited, false, sizeof(visited));

	q.push({0, 0});
	visited[0][0]=true;

	while(!q.empty())
	{
		P curr = q.front();
		q.pop();

		if(curr.a + curr.b == str[2].size()) return true;
		
		if(curr.a < str[0].size() && !visited[curr.a+1][curr.b]
			&& str[0][curr.a] == str[2][curr.a+curr.b])
		{
			q.push({curr.a+1, curr.b});
			visited[curr.a+1][curr.b] = true;
		}
		if(curr.b < str[1].size() && !visited[curr.a][curr.b+1]
			&& str[1][curr.b] == str[2][curr.a+curr.b])
		{
			q.push({curr.a, curr.b+1});
			visited[curr.a][curr.b+1] = true;
		}
	}
	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t;
	cin>>t;

	for(int k=0; k<t; k++)
	{	
		for(int i=0; i<3; i++) 
			cin>>str[i];
		
		cout<<"Data set "<<k+1<<": ";

		if(GetAnswer())	cout<<"yes\n";
		else cout<<"no\n";
	}

	return 0;
}
