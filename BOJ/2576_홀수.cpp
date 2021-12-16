#include <iostream>
#include <vector>
using namespace std;

int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int answer=100, sum=0;
	
	for(int i=0; i<7; i++)
	{
		int n; cin>>n;
		
		if(n%2==1)
		{	
			answer=min(n, answer);
			sum+=n;
		}
	}
	
	if(answer==100) cout<<-1<<'\n';
	else
	{
		cout<<sum<<'\n';
		cout<<answer<<'\n';
	}


	return 0;
}	
