#include <iostream>
#include <cstring> 
using namespace std;

int n;
int arr[1000001];
int cache[1000001]={0};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>n;
	
	for(int i=2; i<=n; i++)
	{
		if(i%3==0 && i%2==0)
			cache[i]=min(cache[i/3], min(cache[i/2], cache[i-1]))+1;
		else if(i%3==0)
			cache[i]=min(cache[i/3], cache[i-1])+1;
		else if(i%2==0)
			cache[i]=min(cache[i/2], cache[i-1])+1;
		else
			cache[i]=cache[i-1]+1;
	}
	
	cout<<cache[n]<<'\n';
	
	return 0;
}
