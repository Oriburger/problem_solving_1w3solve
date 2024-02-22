#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;  

int n, k;
vector<string> ans;

void getAnswer(int curr, string str)
{
	if(curr < 0) return; 
	if(curr == 0)
	{
		ans.push_back(str);
		return;
	}
	
	getAnswer(curr-1, str+"+1");
	getAnswer(curr-2, str+"+2");
	getAnswer(curr-3, str+"+3");
}

int main()
{
	ios::sync_with_stdio(false); 
	cin.tie(0); cout.tie(0);
	
	cin>>n>>k;
	getAnswer(n, "");
	sort(ans.begin(), ans.end());
	
	if(ans.size() < k)
		cout<<-1<<'\n';
	else
	{
		for(int i=1; i<ans[k-1].size(); i++)
			cout<<ans[k-1][i];
		cout<<'\n';	
	}
	
	return 0;
}
