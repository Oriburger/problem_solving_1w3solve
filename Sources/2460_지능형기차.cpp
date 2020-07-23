#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int answer=0;
	
	int total=0;
	for(int i=0; i<10; i++)
	{
		int a, b;
		cin>>a>>b;
		
		total+=b;
		total-=a;
		
		answer=max(answer, total);
	}
	
	cout<<answer<<'\n';
	
	return 0;
}
