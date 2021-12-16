#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int n;
vector<int> seq;
vector<char> ans;
stack<int> stk;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n;

	seq.resize(n, 0);
	for(int i=0; i<n; i++)
		cin>>seq[i];

	int curr = 1;
	int currIdx = 0;

	while(1)
	{
		if(currIdx >= n) break;

		if(stk.empty() || seq[currIdx] > stk.top())
		{
			ans.push_back('+');
			stk.push(curr++);
		}

		else if(seq[currIdx]==stk.top())
		{
			ans.push_back('-');
			stk.pop();
			currIdx++;
		}
		
		else if(seq[currIdx] < stk.top())
		{
			cout<<"NO\n";
			return 0;
		}
	}

	for(int i=0; i<ans.size(); i++)
		cout<<ans[i]<<'\n';

	return 0;
}
