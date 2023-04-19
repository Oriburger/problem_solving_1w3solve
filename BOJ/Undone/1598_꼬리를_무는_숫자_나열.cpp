#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a, b; cin>>a>>b; 
	cout<<abs(a/4-b/4)+abs((a%4==0?3:a%4)-(b%4==0?3:a%4))<<'\n';
	return 0;
}
