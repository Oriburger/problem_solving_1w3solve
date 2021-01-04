#include <iostream>
using namespace std;

int input[6];
const int chess[6]={1,1,2,2,2,8};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for(int i=0; i<6; i++)
		cin>>input[i];

	for(int i=0; i<6; i++)
		cout<<chess[i]-input[i]<<' ';
	
	return 0;
}
