#include <iostream>
#include <vector>
#include <string>
#include <cmath> 
#include <algorithm>
using namespace std;

typedef long long ll;

int n;
string s;
vector<int> op; //0 none, 1 plus, 2 minus
const int opArr[3]={0, 1, -1};

bool IsUgly(ll val)
{
	if(val<0) val*=-1;
	if(!val || !(val%2) || !(val%3)
		    || !(val%5) || !(val%7))
		return true;
	
	return false;
}

ll GetValue()
{
	ll ret=0, temp=0, lastOp=1;

	for(int i=0; i<s.length(); i++)
	{
		temp*=10;
		temp+=(s[i]-'0');

		if(i!=s.length()-1)
		{
			if(op[i]==0) continue;
			else 
			{
				ret += temp * opArr[lastOp];
				lastOp = op[i];
				temp=0;
			}
		}
		else ret += temp * opArr[lastOp];
	}

	return ret;
}

int Solve(int idx)
{
	if(idx==s.length()-1)
		return IsUgly(GetValue());
	
	int ret=0;

	for(int i=0; i<3; i++)
	{
		op.push_back(i);
		ret += Solve(idx+1);
		op.pop_back();
	}

	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin>>n;

	for(int i=1; i<=n; i++)
	{
		cin>>s;
		cout<<"Case #"<<i<<": "<<Solve(0)<<'\n';
		s.clear(); op.clear();
	}

	return 0;
}
