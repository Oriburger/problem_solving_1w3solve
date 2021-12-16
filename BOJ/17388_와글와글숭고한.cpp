#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int s, k, h;
	
	cin>>s>>k>>h;
	
	if(s+k+h < 100)
	{
		int minVal = min(s, min(k, h));
		
		if(minVal==s)
			cout<<"Soongsil\n";
		else if(minVal==k)
			cout<<"Korea\n";
		else
			cout<<"Hanyang\n";
	}
	
	else
		cout<<"OK\n";
	
	return 0;
}
