#include <iostream>
using namespace std;

int main()
{
	int a, b, answer=0;
	
	cin>>a>>b;
	
	if(a<0 && b<0) answer=3;
	else if(a>0 && b>0) answer=1;
	else answer = a < 0 ? 2 : 4;
	
	cout<<answer<<'\n';
	
	return 0;
}
