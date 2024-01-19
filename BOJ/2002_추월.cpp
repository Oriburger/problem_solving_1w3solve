#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

int n, ans = 0;
string str;
unordered_map<string, int> umap;
vector<int> fin;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin>>n; 
	
	for(int i=0; i<n; i++)
	{
		cin>>str;
		umap[str] = i;
	}
	for(int i=0; i<n; i++)
	{
		cin>>str;
		fin.push_back(umap[str]);
	}
	
	//get answer
	for(int i=0; i<n-1; i++)
		for(int j=i+1; j<n; j++)
			if(fin[i] > fin[j])
			{
				ans += 1; 
				break;
			}
	
	cout<<ans<<'\n';
	
	return 0;
}
