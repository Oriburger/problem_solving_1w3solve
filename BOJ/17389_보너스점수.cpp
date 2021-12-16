#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, sum=0;
	string str; 
	
	cin>>n>>str;
	
	int bonus=0;
	for(int i=0; i<n; i++)
	{
		if(str[i]=='X')
			bonus=0;
		
		else
			sum=sum+(i+1)+(bonus++);
	}
	 
	 cout<<sum<<'\n';
	
	return 0;
}
