#include <iostream>
#include <string>
using namespace std;

int a, b;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>a>>b;

	if(a==2 && b==18)
		cout<<"Special\n";

	else if(a<2 || (a==2 && b<18))
		cout<<"Before\n";

	else cout<<"After\n";
	
	return 0;
}
