
#include <iostream> 
#include <queue> 
#include <utility> 
#include <string> 
using namespace std; 
int t, n; 
int main() 
{
 	ios::sync_with_stdio(false);
 	cin.tie(NULL); cout.tie(NULL);
 	cin>>t;
 	while(t--) 
	{ 
		cin>>n;
 		priority_queue<pair<int, string> > pq;
 		for(int i=0; i<n; i++) 
		{ 
			string str; 
			int val;
 

			cin>>str>>val;
 			pq.push({val, str});
 		} 	
	        cout<<pq.top().second<<'\n'; 	
          } 	
         return 0; 
}
