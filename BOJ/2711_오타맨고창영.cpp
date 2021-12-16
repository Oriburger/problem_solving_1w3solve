#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int t;
	
	cin>>t;
	
	while(t--)
	{
		string s;
		int idx;
		
		cin>>idx;
		cin>>s;
		
		s.erase(idx-1, 1);
		
		cout<<s<<'\n';
	}
	
	return 0;
}
