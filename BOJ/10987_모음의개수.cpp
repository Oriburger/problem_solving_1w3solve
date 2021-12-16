#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	string str;
	int answer=0;
	
	cin>>str;
	
	for(auto p : str)
	{
		if(p == 'a' or p == 'e' or 
		   p == 'i' or p == 'o' or 
		   p == 'u')
		   answer++;
	}
	
	cout<<answer<<"\n";
	
	return 0;
}
