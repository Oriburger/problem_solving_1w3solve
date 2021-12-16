#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int x,y,p1,p2;
	cin>>x>>y>>p1>>p2;
	
	for(int i=0; i<=100; i++)
	for(int j=0; j<=100; j++)
	{
		if(i*x+p1 == j*y+p2)
		{
			cout<<i*x+p1<<"\n";
			return 0;
		}
	}
	
	cout<<-1<<"\n";
	
	return 0;
}
