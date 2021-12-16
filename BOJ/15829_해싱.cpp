#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	const int r = 31;
	const int m = 1234567891;
	int l;	string str;

	cin>>l>>str;

	long long sum=0;
	long long temp=1;
	for(int i=0; i<l; i++)
	{
		sum = sum + ((str[i]-'a'+1) * temp) % m;
		temp*=r;
		temp%=m;
	}

	cout<<sum%m<<'\n';

	return 0;
}
