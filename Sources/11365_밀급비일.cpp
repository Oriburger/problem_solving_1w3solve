#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	while(1)
	{
		char str[10000];
		cin.getline(str,10000, '\n');
		
		if(!strcmp(str, "END")) break;
		
		for(int i=strlen(str)-1; i>=0; i--)
		  cout<<str[i];
		cout<<"\n";
	}
	
	return 0;
}
