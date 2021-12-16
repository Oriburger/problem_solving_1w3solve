#include <iostream>
#include <string>

using namespace std;

int month[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int x, y, sum;
string week[7]={"Wednesday", "Thursday", "Friday", "Saturday", "Sunday", 
			    "Monday", "Tuesday"};

int main()
{
	cin>>y>>x;
	
	for(int i=1; i<x; i++)
		sum+=month[i];
	sum+=y;
	
	cout<<week[sum%7]<<endl;
	
	return 0;
}
