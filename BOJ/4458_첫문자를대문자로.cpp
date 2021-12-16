#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n; cin>>n;
	string str;
	
	for(int i=0; i<=n; i++)
	{
	    getline(cin, str);
		if(i==0) continue;
		
		if(str[0]>='a' and str[0]<='z')
			str[0]-='a'-'A';
			
		cout<<str<<"\n";
	}
	
	return 0;
}
