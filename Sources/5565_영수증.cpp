#include <iostream>
using namespace std;

int total;
int books[9];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>total;
	
	for(int i=0; i<9; i++)
	{
		cin>>books[i];
		total-=books[i];
	}
	cout<<total<<'\n';
	
	return 0;
}
