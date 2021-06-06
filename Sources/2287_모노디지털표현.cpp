#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

unordered_set<int> uset[9];
const int temp[8] = {1, 11, 111, 1111, 11111, 111111, 1111111, 11111111};

int main()
{    
	int k, n;

	cin>>k>>n;

    for(int i=1; i<=8; i++)
        uset[i].insert(temp[i-1]*k);
    
    for(int i=1; i<=8; i++)
    {
        for(int j=1; j<=i; j++)
        {
            if(i + j > 8) continue;
            
            for(int a : uset[i])
            {
                for(int b : uset[j])
                {
                    if(a!=b) uset[i+j].insert(abs(a-b));
                    uset[i+j].insert(a+b);
                    uset[i+j].insert(a*b);
                    if(a && b) uset[i+j].insert(max(a, b)/min(a, b));
                }
            }
        }
    }

	while(n--)
	{
		int target;
		cin>>target;

	    int answer = -1;
	
	    for(int i=1; i<=8; i++)
        	if(uset[i].count(target))
        	{
	            answer = i;
            	break;
        	}
		
		if(answer==-1) cout<<"NO\n";
		else cout<<answer<<'\n';
	}

	return 0;
}
