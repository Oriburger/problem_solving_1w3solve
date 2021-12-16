#include <iostream>
#include <string>
using namespace std;

void Answer(string str1, string str2, char c)
{
	if(c=='*')
		for(int i=0; i<str2.length()-1; i++)
			str1.push_back('0');
	else
	{
		if(str1.length() == str2.length())
			str1[0]='2';
		else
			str1[str1.length()-str2.length()]='1';
	}
	
	cout<<str1<<'\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	char c;
	string a, b;
	cin>>a>>c>>b;
	
	if(a.length() > b.length())	Answer(a, b, c);
	else Answer(b, a, c);
	
	return 0;
}
