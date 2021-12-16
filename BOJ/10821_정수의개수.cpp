#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	string s;
	int ans=0;
	
	cin>>s;
	
	for(auto p : s)
		if(p==',') ans++;
		
	cout<<ans+1<<"\n";
	
	return 0;
}
