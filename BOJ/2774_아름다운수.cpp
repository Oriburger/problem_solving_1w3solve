#include <iostream>
#include <string>
#include <vector>
using namespace std;

int t, cnt;
string str;
vector<bool> chk(10, false);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>t;

	while(t--)
	{
		cin>>str;
		
		for(int i=0; i<str.length(); i++)
		{
			if(!chk[str[i]-'0']) cnt++;
			chk[str[i]-'0']=true;
		}
		cout<<cnt<<'\n';
		chk.clear();
		chk.resize(10,  false);
		cnt=0;
	}

	return 0;
}
