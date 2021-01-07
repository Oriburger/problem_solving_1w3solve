#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string str;
vector<string> arr;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin>>str;

	arr.push_back(str);
	while(1)
	{
		str.erase(str.begin(), str.begin()+1);
		if(str.size()==0) break;
		arr.push_back(str);
	}
	sort(arr.begin(), arr.end());

	for(string &p : arr)
		cout<<p<<'\n';

	return 0;
}
