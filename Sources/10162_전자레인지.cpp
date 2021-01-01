#include <iostream>
#include <cmath>
using namespace std;

int t, answer[3];
const int a[3]={300, 60, 10};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>t;

	while(1)
	{
		if(t==0) break;

		if(t>=a[0])
		{
			answer[0]++;
			t-=a[0];
		}	
		else if(t>=a[1])
		{
			answer[1]++;
			t-=a[1];
		}
		else if(t>=a[2])
		{
			answer[2]++;
			t-=a[2];
		}
		else
		{
			cout<<-1<<'\n';
			return 0;
		}
	}

	cout<<answer[0]<<' '<<answer[1]<<' '<<answer[2]<<'\n';

	return 0;
}
