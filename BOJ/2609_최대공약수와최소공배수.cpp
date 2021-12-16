#include <iostream>
using namespace std;

int a, b;

int GCD(int n1, int n2)
{
	int temp = n2;
	n2 = n1%n2;
	n1 = temp;

	if(n2==0) return temp;

	return GCD(n1, n2);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>a>>b;

	if(a<b) swap(a, b);

	cout<<GCD(a,b)<<'\n';

	for(int i=min(a,b); i<=a*b; i++)
	{
		if(i%a==0 && i%b==0) 
		{
			cout<<i<<'\n';
			break;
		}
	}

	return 0;
}
