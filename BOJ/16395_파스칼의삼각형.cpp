#include <iostream>
#include <algorithm>
using namespace std;

int a, b;
int cache[31][31];

int getAnswer(int a, int b)
{
	int& ret = cache[a][b];
	if(b==1 || a==b) return ret = 1;
	return ret = getAnswer(a-1, b) + getAnswer(a-1, b-1);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin>>a>>b;
	cout<<getAnswer(a, b)<<'\n';
	
	return 0;
}
