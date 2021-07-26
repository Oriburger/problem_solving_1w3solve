#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int n, m, answer = 1;
vector<int> arr;

void GetAnswer(int curr, int time, int size)
{
	if(!time || curr == n)
	{
		answer = max(answer, size);
		return;
	}
	if(curr + 1 <= n) GetAnswer(curr+1, time-1, size+arr[curr+1]);
	if(curr + 2 <= n) GetAnswer(curr+2, time-1, size/2 + arr[curr+2]);

	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n>>m;

	arr = vector<int>(n+1, -1);
	for(int i=1; i<=n; i++)
		cin>>arr[i];
	
	GetAnswer(0, m, 1);

	cout<<answer<<'\n';

	return 0;
}
