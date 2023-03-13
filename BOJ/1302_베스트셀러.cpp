#include <bits/stdc++.h>
using namespace std;

int n, maxCnt = 0;
string answer;
unordered_map<string, int> umap;

int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin>>n;

	for(int i=0; i<n; i++)
	{
		string str; 
		cin>>str; 
			
		if(!umap.count(str)) umap[str] = 0;
		umap[str] += 1;
	}
	for(auto &p : umap)
	{
		if(maxCnt < p.second)
		{
			maxCnt = p.second;
			answer = p.first;
		}
		else if(maxCnt == p.second)
		{
			answer = min(answer, p.first);
		}
	}
	cout<<answer<<'\n';
	
	return 0;
}
