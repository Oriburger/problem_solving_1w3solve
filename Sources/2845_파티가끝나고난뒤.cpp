#include <iostream>
using namespace std;

int l, p, arr[5];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>l>>p;
	for(int i=0; i<5; i++)
		cin>>arr[i];
	for(int i=0; i<5; i++)
		cout<<arr[i]-l*p<<' ';
	
	return 0;
}
