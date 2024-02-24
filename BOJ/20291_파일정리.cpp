/*------ ------
풀이)

unorderd_map으로 하나씩 확장자를 세주면 됨
'.' 이 있는 부분을 substr로 잘라서 확장자를 추출하면 됨

-------------*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int n;
vector<string> types; 
unordered_map<string, int> umap;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin>>n; 
	
	for(int i=0; i<n; i++)
	{
		string s; 
		cin>>s; 
		
		int j;
		for(j=0; j<s.size(); j++)
			if(s[j]=='.') break; 
			
		string t = s.substr(j+1, s.size()-j-1);
		if(umap.count(t) == 0)	
		{
			umap[t] = 0;
			types.push_back(t);
		}
		umap[t]++;
	}
	sort(types.begin(), types.end());
	
	for(auto &t : types)
		cout<<t<<" "<<umap[t]<<'\n';
	
	return 0;
}
