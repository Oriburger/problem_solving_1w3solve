#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int n;

bool IsPrime(int num)
{
	if(num==1 || num==0) return false;

	int cnt=0;
	for(int i=2; i*i<=num; i++)
		if(num%i==0) return false;
	
	return true;
}

void PrtAnswer(int num, int toPick)
{
	if(toPick==0)
	{
		bool flag=true;
		int num2=num;
		while(num2!=0)
		{
			if(!IsPrime(num2))
			{
				flag = false;
				break;
			}
			num2/=10;
		}
		if(flag) cout<<num<<'\n';

		return;
	}

	for(int i=1; i<=9; i+=2)
		PrtAnswer(num*10+i, toPick-1);
	
	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n;

	PrtAnswer(2, n-1);	
	PrtAnswer(3, n-1);	
	PrtAnswer(5, n-1);	
	PrtAnswer(7, n-1);	

	return 0;
}
