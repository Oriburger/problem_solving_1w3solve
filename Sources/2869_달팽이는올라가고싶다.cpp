#include <iostream>
using namespace std;

int a, b, v, ans;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>a>>b>>v;

	if((v-a)%(a-b)==0) ans = (v-a)/(a-b);

	else ans = (v-a)/(a-b)+1;

	cout<<++ans<<'\n';

	return 0;
}
