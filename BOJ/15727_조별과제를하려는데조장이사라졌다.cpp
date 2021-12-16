#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int l; cin>>l;

	cout<<l/5+(l%5>0 ? 1 : 0)<<'\n';
	
	return 0;
}
