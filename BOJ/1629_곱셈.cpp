#include <iostream>
using namespace std;

int a, b, c, ans;

int Answer(int n, int k)
{
	if(k==0) return 1;
	
	long long temp = Answer(n, k/2) % c;

	if(k%2==0) return ((temp % c) * (temp % c))%c ;
	else return (((temp % c) * (temp % c)) %c * (n % c)) % c; 
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>a>>b>>c;

	cout<<Answer(a, b)<<'\n';

	return 0;
}
