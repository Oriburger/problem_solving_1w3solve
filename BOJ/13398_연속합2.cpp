#include <iostream>
#include <algorithm>
using namespace std;

int n, answer=-2147000000;
int arr[100000];
int cache[100000][3];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n;
	for(int i=0; i<n; i++)
		cin>>arr[i];

	cache[0][0]=arr[0];
	cache[0][1]=arr[0];
	for(int i=1; i<n; i++)
	{
		cache[i][0] = max(cache[i-1][0] + arr[i], arr[i]);
		cache[i][1] = max(cache[i-1][0], cache[i-1][1] + arr[i]);
	}

	for(int i=0; i<n; i++)
		answer = max(answer, max(cache[i][0], cache[i][1]));

	cout<<answer<<'\n';

	return 0;
}
