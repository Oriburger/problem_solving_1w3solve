#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n, answer=0;
string str, stdStr;
vector<int> stdAB(26);
vector<int> compAB(26);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n;
	
	for(int i=0; i<n; i++)
	{
		cin>>str;

		for(int j=0; j<str.length(); j++)
		{
			if(i==0)
			{
				stdAB[str[j]-'A']++;
				stdStr = str;
			}
			else
				compAB[str[j]-'A']++;
		}

		int cnt=0;
		for(int j=0; j<26; j++)
		{
			if(stdAB[j]==compAB[j]) continue;
			else if(abs(stdAB[j]-compAB[j])==1) cnt++;
			else cnt=9999;
		}
		if(cnt<=1 || (cnt==2 && stdStr.length() == str.length())) answer++;

		compAB.clear();
		compAB.resize(26, 0);
	}
	cout<<answer<<'\n';

	return 0;
}
