
#include <iostream> 
using namespace std; 
int t, n; 

int main() 
{
 	ios::sync_with_stdio(false);
 	cin.tie(NULL); cout.tie(NULL);

 	cin>>t;
 	while(t--)
 	{
 		int y=0, k=0;
 		for(int i=0; i<9; i++)
 		{
 			int a, b;
 			cin>>a>>b;
 			y+=a; k+=b;
 		}
 		if(y>k) cout<<"Yonsei\n";
 		else if(y<k) cout<<"Korea\n";
 		else cout<<"Draw\n";
 	}
 	return 0;
}
