#include <iostream>
#include <string>
using namespace std;

const int INF = 1000000;
string str;
long long cache[5001];

int ctoi(const char c) { return c-'0'; }

int GetAnswer(int x)
{
	if(x>=str.size()) return 0;
	if(cache[x]!=0) return cache[x];

	if(x+1<str.size())
		if(ctoi(str[x])*10+ctoi(str[x+1])<=26)
			cache[x]=1+GetAnswer(x+2)%INF;
	
	cache[x]=(cache[x]+GetAnswer(x+1))%INF+1;

	return cache[x];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>str;

	cout<<GetAnswer(0)<<'\n';

	return 0;
}
