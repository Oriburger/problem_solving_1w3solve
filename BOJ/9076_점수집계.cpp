#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    int t; vector<int>arr(5);
    
    cin>>t;
    
    while(t--)
    {
    	for(int i=0; i<5; i++)
    	    cin>>arr[i];
    	    
    	sort(arr.begin(), arr.end());
    	
    	if(abs(arr[1]-arr[3])>=4)
    	    cout<<"KIN\n";
    	else cout<<arr[1]+arr[2]+arr[3]<<"\n";
    }
    
	return 0;
}
