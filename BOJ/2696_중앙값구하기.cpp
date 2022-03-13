#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int t, m;
vector<int> arr;
vector<int>::iterator iter;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin>>t;
	
	while(t--)
	{
		cin>>m;
			
		int num;
		cout<<m/2+1<<'\n';
		for(int i=0; i<m; i++)
		{
			cin>>num;
			
			iter = lower_bound(arr.begin(), arr.end(), num);
			arr.insert(iter, num);
			
			if(i%2==0) cout<<arr[i/2]<<' ';
			if((i+1)%20==0)	cout<<'\n';
		}
		cout<<'\n';
		arr.clear();
	}
	
	return 0;	
}

/*----pq---------

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int t, m, tmp, mid;
vector<int> ans;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin>>t;
	
	while(t--)
	{
		cin>>m;

		priority_queue<int> max_heap;
		priority_queue<int, vector<int>, greater<int> > min_heap; 
			
		for(int i=1; i<=m; i++)
		{
			cin>>tmp;
			
			if(i==1)
			{
				mid = tmp;
				ans.push_back(mid);
				continue;
			}
			
			if(tmp <= mid) max_heap.push(tmp);
			else min_heap.push(tmp);
			
			if(i%2==1)
			{
				if(max_heap.size() > min_heap.size())
				{
					min_heap.push(mid);
					mid = max_heap.top();
					max_heap.pop();
				}
				else if(max_heap.size() < min_heap.size())
				{
					max_heap.push(mid);
					mid = min_heap.top();
					min_heap.pop();
				}
				
				ans.push_back(mid);
			}
		}
			
		cout<<ans.size()<<'\n';
		for(int i=0; i<ans.size(); i++)
		{
			cout<<ans[i]<<' ';
			if((i+1)%10==0) cout<<'\n';
		}
		cout<<'\n';
		ans.clear();
	}
	
	return 0;	
}

*/
