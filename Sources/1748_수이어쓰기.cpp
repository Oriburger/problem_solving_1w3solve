#include <iostream>
using namespace std;

int n, answer;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>n;
	
	for(int i=1; i<=n; i++)
	{
		int temp=i;
		do
		{
			answer++;
			temp/=10;	
		}while(temp>0);
	}
	
	cout<<answer<<'\n';
	
	return 0;
}
