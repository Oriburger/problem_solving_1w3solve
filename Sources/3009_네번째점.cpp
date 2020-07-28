#include <iostream>
using namespace std;

int x[3], y[3], x_ans, y_ans;

bool IsConnected(int x_val, int y_val)
{
	for(int i=0; i<3; i++)
		if(x[i]==x_val && y[i]==y_val)
			return true;
	
	return false;	
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	for(int i=0; i<3; i++)
		cin>>x[i]>>y[i];
		
	for(int i=0; i<3; i++)
	{
		x_ans = x[i];
		for(int j=0; j<3; j++)
		{
			y_ans = y[j];
			
			if(!IsConnected(x_ans, y_ans))
			{
				cout<<x_ans<<' '<<y_ans<<'\n';
				return 0;
			}
		}
	}
}
