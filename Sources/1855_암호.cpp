#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int k; string str, str2, ans;

	cin>>k>>str;

	int flag = 1;
	for(int i=0; i<str.length(); i+=k)
	{
		if(flag == 1)
		for(int j=i; j<i+k; j++)
			str2.push_back(str[j]);

		else
		for(int j=i+k-1; j>=i; j--)
			str2.push_back(str[j]);
		
		flag*=-1;
	}

	for(int i=0; i<k; i++)
		for(int j=0; j<str2.length(); j+=k)
			cout<<str2[j+i];

	return 0;
}
