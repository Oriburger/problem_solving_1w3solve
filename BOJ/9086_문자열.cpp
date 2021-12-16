#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n;
	string str;
	
	cin>>n;
	while(n--)
	{
	  cin>>str;
	  cout<<str.front()<<str.back()<<"\n";
	}
	
	
	return 0;
}
