#include <iostream>
#include <vector>
#include <deque>
#include <cmath>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<int> arr;
unordered_map<int, int> umap;
deque<int> dq;
int n, m; 
bool flag = false;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin>>n>>m;
	
	arr = vector<int>(n, 0);
	for(int i=0; i<n; i++)
	{
		cin>>arr[i];
		umap[arr[i]] = 0;
	}
		
	int threshold = (int)ceil((double)(9.0f * (double)m / 10.0f));
	int max_val = arr[0];
	for(int i=0; i<n; i++)
	{
		umap[arr[i]] += 1;
		if(umap[max_val] <= umap[arr[i]]) 
			max_val = arr[i];
		dq.push_back(arr[i]);
		
		if(dq.size() == m)
		{
			if(umap[max_val] >= threshold)
			{
				flag = true;
				break;		
			}
			umap[dq.front()] -= 1;
			dq.pop_front();
		}
	}
	cout<<(flag ? "YES\n" : "NO\n");	

	return 0;
}
