#include <iostream>
#include <string>
#include <vector>
using namespace std;

string str;
vector<int> arr;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>str;
	
	arr.assign(26, -1);
	
	for(int i=0; i<str.length(); i++)
		if(arr[ str[i]-'a' ] == -1)
			arr[ str[i]-'a' ] = i;
	
	for(int i=0; i<26; i++)
		cout<<arr[i]<<' ';
	
	return 0;
}
