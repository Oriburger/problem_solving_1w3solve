#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string str;
const string word = "CAMBRIDGE";

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>str;

	int pos=0;
	for(int i=0; i<word.size(); i++)
	{
		while(1)
		{
			pos = str.find(word[i]);
			if(pos == string::npos) break;

			str.erase(pos, 1);
		}
	}

	cout<<str<<'\n';

	return 0;
}
