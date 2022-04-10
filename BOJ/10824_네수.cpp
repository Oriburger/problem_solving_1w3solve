#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	string st[4];
	
	for(int i=0; i<4; i++)
		cin>>st[i];
	
	cout<<stoll(st[0]+st[1])+stoll(st[2]+st[3])<<'\n';
	
	return 0;
}
