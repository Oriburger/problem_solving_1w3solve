#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

int n, m;
string cache[101][101];

string BigIntAdd(string st1, string st2)
{
	long long sum=0;
	string ret;

	while(!st1.empty() || !st2.empty() || sum)
	{
		if(!st1.empty())
		{
			sum += st1.back() - '0';
			st1.pop_back();
		}
		if(!st2.empty())
		{
			sum += st2.back() - '0';
			st2.pop_back();
		}
		ret.push_back((sum%10)+'0');
		sum /= 10;
	}
	reverse(ret.begin(), ret.end());

	return ret;
}

string GetAnswer(int a, int b)
{
	if(a==b || b==0) return "1";

	string &ret = cache[a][b];
	if(ret != "") return ret;

	ret = BigIntAdd(GetAnswer(a-1, b-1), GetAnswer(a-1, b));
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n>>m;

	cout<<GetAnswer(n, m)<<'\n';

	return 0;
}
