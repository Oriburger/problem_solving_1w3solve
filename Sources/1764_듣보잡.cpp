#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <vector>
using namespace std;

int n, m;
set<string> notSeen; 
set<string> notHeard;
set<string> * setA; //ÀûÀº°Ô A 
set<string> * setB;
vector<string> ans;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>n>>m;
	
	string input;
	for(int i=0; i<n; i++)
	{
		cin>>input;
		notSeen.insert(input);
	}
	for(int i=0; i<n; i++)
	{
		cin>>input;
		notHeard.insert(input);
	}
	
	if(notSeen.size() < notHeard.size())
	{
		setA = &notSeen;
		setB = &notHeard;
	}
	else
	{
		setA = &notHeard;
		setB = &notSeen;
	}
	
	set<string>::iterator iPosA;
	set<string>::iterator iPosB;
	for(iPosA=setA->begin(); 
		iPosA != setA->end(); iPosA++)
	{
		iPosB = setB->find(*iPosA);
		if(iPosB != setB->end())
			ans.push_back(*iPosB);
	}
	
	sort(ans.begin(), ans.end());
	cout<<ans.size()<<'\n';
	for(int i=0; i<ans.size(); i++)
		cout<<ans[i]<<'\n';
	
	return 0;
}
