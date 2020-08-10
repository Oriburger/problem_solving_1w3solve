#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int k, n;
	cin>>k;
	
	for(int i=1; i<=k; i++)
	{
		cin>>n;
		
		vector<int> score(n);
		int highest = -1, lowest = 2147000000;
		int maxGap=-1;
		
		for(int i=0; i<n; i++)
		{
		    cin>>score[i];
            
            highest = max(highest, score[i]);
            lowest = min(lowest, score[i]);
		}
		sort(score.begin(), score.end(), greater<int>());
		
		for(int i=0; i<n-1; i++)
		    maxGap=max(maxGap, score[i]-score[i+1]);
	    
	    cout<<"Class "<<i<<"\n";
	    cout<<"Max "<<highest<<", ";
	    cout<<"Min "<<lowest<<", ";
		cout<<"Largest gap "<<maxGap<<"\n";
	}
	
	return 0;
}
