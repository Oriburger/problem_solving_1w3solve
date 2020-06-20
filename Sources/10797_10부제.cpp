#include <iostream>
using namespace std;

int day, ans;
int car[5];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>day;
	
	for(int i=0; i<5; i++)
	{
		cin>>car[i];
		if(car[i]%10==day)
			ans++;
	}
	cout<<ans<<'\n';
	
	return 0;
}
