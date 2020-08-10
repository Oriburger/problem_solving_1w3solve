#include <iostream>
#include <vector>
using namespace std;

vector<int>arr(9), ans;

void Answer(int toPick, int sum, int lastPick)
{
	if(toPick==0)
	{
		if(sum==100)
		{
			for(auto p : ans)
			    cout<<p<<"\n";
		}
		return;
	}
	
	for(int i = lastPick+1; i<9; i++)
	{
		ans.push_back(arr[i]);
		Answer(toPick-1, sum+arr[i], i);
		ans.pop_back();
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	for(int i=0; i<9; i++)
	    cin>>arr[i];
	
	Answer(7, 0, -1);
	
	return 0;
}
