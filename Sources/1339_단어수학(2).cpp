#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

int n, longest, cnt=9, total;
vector<string> str;
int check[26];

bool Comp(string st1, string st2)
{
	return st1.length() > st2.length();
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	memset(check, -1, sizeof(check));
	
	cin>>n;
	
	for(int i=0; i<n; i++)
	{
		string input;
		cin>>input;
		
		str.push_back(input);
	}
	
	sort(str.begin(), str.end(), Comp);
	
	for(int i=str[0].length()-1; i>=0; i--)
	{
		for(int j=0; j<n; j++)
		{
			int curr = str[j].length()-i-1;
			
			if(curr < 0) break;	
			
			if(check[str[j].at(curr)-'A']==-1)
				check[str[j].at(curr)-'A'] = cnt--;
		}
	}
	
	for(int i=0; i<26; i++)
		cout<<check[i]<<' ';
	cout<<'\n';
	
	for(int i=0; i<n; i++)
	{
		int subSum=0;
		for(int j=0; j<str[i].length(); j++)
		{
			subSum = subSum + check[str[i].at(j)-'A'] * pow(10, str[i].length()-j-1);
		}
		total += subSum;
	}
	
	cout<<total<<'\n';
	
	return 0;
}
