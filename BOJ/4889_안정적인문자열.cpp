#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	unordered_map<string, int> umap = {{"{{", 1}, {"}}", 1}, {"}{", 2}};
	
	for(int i=0; ; i++)
	{
		int answer = 0;
		string st; 
		vector<int> stk;
		 
		cin>>st;
		
		if(st[0]=='-') break;
		
		for(auto &c : st)
		{
			if(stk.empty()) stk.push_back(c);
			else
			{
				if(stk.back() == '{' && c == '}') stk.pop_back();
				else stk.push_back(c);
			}
		}
		
		string tmp = "";
		for(auto &c : stk)
		{
			tmp += c;
			if(tmp.size()==2)
			{
				answer += umap[tmp];
				tmp = "";
			}
		}
		cout<<i+1<<". "<<answer<<'\n';
	}	
	 
	return 0;
}
