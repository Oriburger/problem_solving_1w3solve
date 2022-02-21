#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int n, k, ans;
string str, tmp;

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(NULL); cout.tie(NULL);

    cin>>n>>k>>str;

    k = n-k;
    for(int i=0; i<n; i++)
    {
        char curr = str[i];
    	  char top = tmp.empty() ? '0' : tmp[tmp.size()-1];
    	   	
        if(tmp.size() + n-i > k)
        {
            if(curr == top) tmp.push_back(curr);
        	  else
        	  {
        	    	while(!tmp.empty())
        		    {
        			      if(tmp.size() + n-i == k) break;
        			      if(curr <= top) break;
        			      tmp.pop_back();
        			      top = tmp.empty() ? '0' : tmp[tmp.size()-1];
				        }
				        tmp.push_back(curr);
			      }
        }
		else 
			tmp.push_back(curr);
    }
    cout<<tmp.substr(0, k)<<'\n';

    return 0;
}
