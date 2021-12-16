#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string Rev(string str)
{
	reverse(str.begin(), str.end());
	return str;
}

string Add(const string &str1, const string &str2)
{
	string ret;

	int temp = (stoi(str1)+stoi(str2));

	while(1)
	{
		ret.push_back(temp%10+'0');
		temp/=10;
		if(temp==0) break;
	}
	reverse(ret.begin(), ret.end());

	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string x, y;
	cin>>x>>y;
	
	string ans = Rev(Add(Rev(x), Rev(y)));

	bool flag=false;
	for(int i=0; i<ans.length(); i++)
	{
		if(ans[i]!='0') flag = true;

		if(flag) cout<<ans[i];
	}

	return 0;
}

