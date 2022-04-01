#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> arr(8, "0000");
string str;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin>>str;
	
	int target = str.size();
	for(int i=0; i<str.size()-1; i++)
		if(str[i]==':' && str[i]==str[i+1])
			target = i;
	
	int lo = 0, hi = 7, pos = 3;
	string tmp = "";
	for(int i=0; i<=target; i++)
	{
		if(str[i]==':' || i==target)
		{
			arr[lo]="";
			for(int j=0; j<4-tmp.size(); j++)
				arr[lo].push_back('0');
			arr[lo]+=tmp;
			tmp = "";
			lo++;
			continue;
		}
		
		tmp.push_back(str[i]);	
	}
	for(int i=str.size()-1; i>target; i--)
	{
		if(str[i]==':')
		{
			hi -= 1;
			pos = 3;
			continue;
		}
		arr[hi][pos--] = str[i];
	}
	
	for(int i=0; i<arr.size(); i++)
	{
		cout<<arr[i];
		if(i==arr.size()-1) break;
		cout<<':';
	}
	
	return 0;
}
