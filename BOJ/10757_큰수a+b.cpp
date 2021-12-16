#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> a, b, c;
string str1, str2;

int main()
{
	cin>>str1>>str2;
    int maxLen = max(str1.length(), str2.length());

	a.resize(maxLen+1, 0);
	b.resize(maxLen+1, 0);

	int cnt=0;
	for(int i=str1.length()-1; i>=0; i--)
		a[cnt++]=(str1[i]-'0');
	cnt=0;
	for(int i=str2.length()-1; i>=0; i--)
		b[cnt++]=(str2[i]-'0');

	c.resize(maxLen+1, 0);
	for(int i=0; i<maxLen; i++)
	{
		int temp=0;
		c[i]+=(a[i]+b[i]);
		temp=c[i]/10;
		c[i]%=10;
		c[i+1]+=temp;
	}

	for(int i=maxLen; i>=0; i--)
	{
		if(i==maxLen && c[i]==0) continue;
		cout<<c[i];
	}

	return 0;
}

