#include <iostream>
#include <vector>
using namespace std;

int n, m, answer=0;
vector<int> card;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>n>>m;
	
	int input;
	for(int i=0; i<n; i++)
	{
		cin>>input;
		card.push_back(input);	
	}

	for(int i=0; i<n; i++)
	for(int j=i+1; j<n; j++)
	for(int k=j+1; k<n; k++)
		if(card[i]+card[j]+card[k] <= m)
			answer = max(answer, card[i]+card[j]+card[k]);
	
	cout<<answer<<'\n';
				
	return 0;
} 
