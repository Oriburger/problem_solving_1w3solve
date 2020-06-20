#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

int n, cnt=9, answer;
vector<int> alphabet;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	alphabet.resize(26, false);
	cin>>n;
	
	for(int i=0; i<n; i++)
	{
		string input;
		cin>>input;
		
		for(int j=input.length()-1; j>=0; j--)
			alphabet[input.at(j)-'A'] += 1*pow(10, input.length()-j-1);
	}
	
	sort(alphabet.begin(), alphabet.end(), greater<int>());
	
//	for(int i=0; i<26; i++)
//		cout<<alphabet[i]<<' ';
//	cout<<'\n'; 
	
	for(int i=0; i<26; i++)
	{
		if(alphabet[i]==0) break;
		
		answer = answer + alphabet[i]*cnt--;
	}
	
	cout<<answer<<'\n';
	
	return 0;
}
