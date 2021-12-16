#include <iostream>
using namespace std;

struct Medal
{
	int idx;
	int g;
	int s;
	int b;
	int rank;
};

int n, k, kidx;
Medal arr[1001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>n>>k;
	
	for(int i=1; i<=n; i++)
	{
		int idx, g, s, b;
		cin>>idx>>g>>s>>b;
		if(idx == k) 
			kidx = i;
		arr[i]={idx, g, s, b, 0};
	}
	
	for(int i=1; i<=n; i++)
		if(i!=kidx)
		{
			if(arr[i].g > arr[kidx].g) arr[kidx].rank++;
			else if(arr[i].g == arr[kidx].g)
			{
				if(arr[i].s > arr[kidx].s) arr[kidx].rank++;
				else if(arr[i].s == arr[kidx].s)
					if(arr[i].b > arr[kidx].b) arr[kidx].rank++;
			}
		}
	
	cout<<arr[kidx].rank+1<<'\n';
		
	return 0;
}
