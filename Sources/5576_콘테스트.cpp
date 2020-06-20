#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> w;
vector<int> k;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	for(int i=0; i<10; i++)
	{
		int input;
		cin>>input;
		w.push_back(input);	
	}
	for(int i=0; i<10; i++)
	{
		int input;
		cin>>input;
		k.push_back(input);	
	}
	sort(w.begin(), w.end(), greater<int>());
	sort(k.begin(), k.end(), greater<int>());
	
	cout<<w[0]+w[1]+w[2]<<' ';
	cout<<k[0]+k[1]+k[2]<<'\n';
	
	return 0;
} 
