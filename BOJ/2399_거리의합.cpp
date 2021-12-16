#include <iostream>
#include <vector>
using namespace std;

int n; long long ans=0;
vector<int> arr;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n;
	arr.resize(n, 0);
	for(int i=0; i<n; i++)
		cin>>arr[i];

	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
		{
			long long temp = arr[i]-arr[j];
			temp = temp<0 ? temp*-1 : temp;
			ans+=temp;
		}
	
	cout<<ans<<'\n';

	return 0;
}
