#include <iostream>
using namespace std;

int n;
int sum; 

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>n;
	
	for(int i=0; i<n; i++)
	{
		int input=0;
		cin>>input;
		sum+=input;
	}
	if(n < sum*2)
		cout<<"Junhee is cute!\n";
	else
		cout<<"Junhee is not cute!\n";
	
	return 0;
}
