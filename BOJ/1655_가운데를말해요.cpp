#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;

int n;

priority_queue<int, vector<int>, less<int> > minHeap;
priority_queue<int, vector<int>, greater<int> > maxHeap;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin>>n;
	for(int i=1; i<=n; i++)
	{
		int k; cin>>k; 
		
		if(i%2==1) maxHeap.push(k);
		else minHeap.push(k);
		
		if(i>1 && maxHeap.top() < minHeap.top())
		{
			int a = minHeap.top(), b = maxHeap.top();
			minHeap.pop(); maxHeap.pop();
			minHeap.push(b); maxHeap.push(a);
		}
		
		if(i%2==1) cout<<maxHeap.top()<<'\n';
		else cout<<min(maxHeap.top(), minHeap.top())<<'\n';
	}	
	return 0;
} 
