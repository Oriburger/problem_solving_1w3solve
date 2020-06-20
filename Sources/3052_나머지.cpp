#include <iostream>
using namespace std;

int n, arr[42], answer=0;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
		
	for(int i=0; i<10; i++)
	{
		cin>>n;
		arr[n%42]++;
	}
	
	for(int i=0; i<42; i++)
		if(arr[i]>=1)
			answer++;
	
	cout<<answer<<'\n';
	
	return 0;
}
