#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n>>m;

	if(m<=2) cout<<"NEWBIE!\n";
	else if(m<=n) cout<<"OLDBIE!\n";
	else cout<<"TLE!\n";

	return 0;
}
