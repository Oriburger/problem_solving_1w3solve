#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <cmath>
using namespace std;

typedef pair<int,int> P;

vector<bool> pnum(10001, false);

int UpdateNum(int n, int k, int pos)
{
	int temp, ret=0;
	
	temp = n/(int)pow(10, pos+1);
  ret = n%(int)pow(10, pos);
	
	ret+=k*(int)pow(10, pos);
	ret+=temp*(int)pow(10, pos+1);
	
	return ret;
}

void BFS(int n1, const int n2)
{
	queue<P> q;
	vector<bool> visited(10001, false);
	
	q.push({n1, 0});
	visited[n1]=true;
	while(!q.empty())
	{
		P curr = q.front();
		q.pop();
		
		if(curr.first==n2)
		{
			cout<<curr.second<<"\n";
			return;
		}
		
		for(int i=0; i<4; i++)
		{
			for(int j=0; j<10; j++)
			{
        int next = UpdateNum(curr.first, j, i);
				if(!pnum[next] && next>999 
				    && !visited[next])
			  {
			  	//cout<<i<<" "<<j<<" "<<curr.first<<" -> "<<next<<"\n";
			  	
			  	q.push({next, curr.second+1});
			  	visited[next]=true;
			  }
			}
		}
	}
	
	cout<<"Impossible\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int t; cin>>t;
	
	pnum[0] = pnum[1] = true;
	for(int i=2; i<10000; i++)
    for(int j=i; i*j<10000; j++)
	    pnum[i*j]=true;
	
	while(t--)
	{
		int n1, n2;
		cin>>n1>>n2;
		
	  BFS(n1, n2);
	}
	
	return 0;
}
