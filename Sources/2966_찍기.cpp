#include <iostream>
#include <string>
using namespace std;

int n;
string ansSheet;

string a = "ABC";
string b = "BABC";
string g = "CCAABB";

int GetCorrect(string comp)
{
	int compIdx=0, ret=0;
	for(int i=0; i<ansSheet.size(); i++)
	{
		if(comp[compIdx]==ansSheet[i]) ret++;

		compIdx++; compIdx%=comp.size();
	}

	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n;
	cin>>ansSheet;

	int aVal = GetCorrect(a);
	int bVal = GetCorrect(b);
	int gVal = GetCorrect(g);

	cout<<max(aVal, max(bVal, gVal))<<'\n';

	if(aVal>=bVal && aVal>=gVal)
		cout<<"Adrian\n";
	
	if(bVal>=gVal && bVal>=aVal)	
		cout<<"Bruno\n";

	if(gVal>=aVal && gVal>=bVal)	
		cout<<"Goran\n";

	return 0;
}
