#include <iostream>
#include <vector>
using namespace std;

int n, k, prob, cnt=0;
vector<int> per; //permutation 
vector<int> per2;
vector<bool> visited;
bool flag;

void PrtPer(const int k)
{
	if(per.size()==n)
	{
		cnt++;
		
		if(cnt==k)
		{
			for(int i=0; i<n; i++)
				cout<<per[i]<<' ';
			cout<<'\n';
		}
		return;
	}

	for(int i=1; i<=n; i++)
	{
		if(visited[i]) continue;

		per.push_back(i);
		visited[i]=true;
		PrtPer(k);
		per.pop_back();
		visited[i]=false;
	}
	return;
}

void PrtPerCnt()
{
	if(flag) return;
	if(per.size()==n)
	{
		cnt++;
		
		flag = true;
		for(int i=0; i<n; i++)
		{
			if(per[i] != per2[i])
			{
				flag = false;
				break;
			}
		}
		if(flag) cout<<cnt<<'\n';
		
		return;
	}

	for(int i=1; i<=n; i++)
	{
		if(visited[i]) continue;

		per.push_back(i);
		visited[i]=true;
		PrtPerCnt();
		per.pop_back();
		visited[i]=false;
	}
	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n>>prob;

	visited.resize(n+1);

	if(prob == 1)
	{
		cin>>k;
		
		PrtPer(k);
	}

	else if(prob == 2)
	{
		for(int i=0; i<n; i++)
		{
			int input;
			cin>>input;
			per2.push_back(input);
		}
		PrtPerCnt();
	}

	return 0;
}
