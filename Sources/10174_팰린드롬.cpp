#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int n; string str;

bool IsEqual(char ch1, char ch2)
{
	if(ch1 == ch2) return true;
	
	else if((ch1<'a' && ch1 >'z' && ch1<'A' && ch1>'Z') 
			&& (ch2<'a' && ch2 >'z' && ch2<'A' && ch2>'Z')) return false;

	else
	{
		if(ch1>ch2) //ch2가 무조건 소문자
		{
			char temp = ch1;
			ch1 = ch2;
			ch2 = temp;
		}

		//cout<<ch1<<' '<<ch2<<'\n';

		if(ch2 - ('a'-'A') == ch1) return true;
		else return false;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n;

	string flushBuffer;
	getline(cin, flushBuffer);
	while(n--)
	{
		getline(cin, str);

		//cout<<str<<' '<<str.size()<<'\n';

		bool flag = false;
		for(int i=0; i<str.size()/2; i++)
		{
			if(!IsEqual(str[i],str[str.size()-i-1]))
			{
				flag=true;
				break;
			}
		}

		if(flag) cout<<"No\n";
		else cout<<"Yes\n";
	}

	return 0;
}
