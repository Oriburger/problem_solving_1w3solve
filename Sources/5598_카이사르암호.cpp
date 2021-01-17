#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
string str;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>str;

	for(int i=0; i<str.size(); i++)
	{
		if(str[i]<='C') str[i]+=26;
		str[i]-=3;
	}

	cout<<str<<'\n';

	return 0;
}
