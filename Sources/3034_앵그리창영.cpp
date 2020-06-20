#include <iostream>
using namespace std;

int n, w, h;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>n>>w>>h;
	
	for(int i=0; i<n; i++)
	{
		double a;
		cin>>a;
		
		if(a*a <= w*w+h*h)
			cout<<"DA\n";
		else
			cout<<"NE\n";
	}
	
	return 0;
}
