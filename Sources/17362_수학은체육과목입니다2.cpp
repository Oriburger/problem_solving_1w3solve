#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n; cin>>n;
	const int arr[8]={1,2,3,4,5,4,3,2};
	
	cout<<arr[n%8==0 ? 7 : n%8-1 ]<<"\n";

	return 0;
}
