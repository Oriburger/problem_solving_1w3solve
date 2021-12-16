#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> ans;
string str;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for(int i=1; ;i++)
	{
		getline(cin, str);
		if(cin.eof()) break;

		bool flag = false;

		if(str.find("FBI")!=string::npos)
			ans.push_back(i);
	}

	if(ans.size()==0) cout<<"HE GOT AWAY!\n";
	else
		for(auto &p : ans)
			cout<<p<<' ';

	return 0;
}
