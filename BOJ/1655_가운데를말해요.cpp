#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;

int n;

priority_queue<int, vector<int>, less<int> > maxHeap;
priority_queue<int, vector<int>, greater<int> > minHeap;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin>>n;
	for(int i=1; i<=n; i++)
	{
		int k; cin>>k; 
		
		if(i%2==1) minHeap.push(k);
		else maxHeap.push(k);
		
		if(i>1 && minHeap.top() < maxHeap.top())
		{
			int a = maxHeap.top(), b = minHeap.top();
			maxHeap.pop(); minHeap.pop();
			maxHeap.push(b); minHeap.push(a);
		}
		
		if(i%2==1) cout<<minHeap.top()<<'\n';
		else cout<<min(minHeap.top(), maxHeap.top())<<'\n';
	}	
	return 0;
} 
