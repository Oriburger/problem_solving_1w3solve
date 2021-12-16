#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	string str;
	
	cin>>str;
	
	for(int i=0; i<str.size(); i++)
	{
		if(str[i]>='a' && str[i]<='z')
			str[i] -= 'a'-'A';
		else if(str[i]>='A' && str[i]<='Z')
			str[i] += 'a'-'A';
	}
	cout<<str<<"\n";
	
	return 0;
}
