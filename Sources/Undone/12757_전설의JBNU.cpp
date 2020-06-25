#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

typedef vector<int>::iterator viter;

int n, m, k;
map<int, int> mData;
vector<int> karr;

int main()
{
	scanf("%d %d %d", &n, &m, &k);
	
	for(int i=0; i<n; i++)
	{
		int key, value;
		scanf("%d %d", &key, &value);
		
		karr.push_back(key);
		mData.insert(make_pair(key, value));
	}
	sort(karr.begin(), karr.end());
	
	for(int i=0; i<m; i++)
	{
		int cmd, key, value;
		scanf("%d", &cmd);
		
	//	cout<<"> "<<mData.count(0)<<'\n';
		
		if(cmd==1)
		{
			scanf("%d %d", &key, &value);
			
			karr.push_back(key);
			sort(karr.begin(), karr.end());
			
			mData.insert(make_pair(key, value));
		}
		else if(cmd==2)
		{
			scanf("%d %d", &key, &value);
			
			printf("(%d)-", key);
			
			if(mData.count(key))
			{
				mData[key]=value;
			}
			else
			{
				viter iterPos1 = lower_bound(karr.begin(), karr.end(), key);
				viter iterPos2 = lower_bound(karr.begin(), karr.end(), key-k);
				
			//	printf("iterPos1 : %d, iterPos2 : %d\n", *iterPos1, *iterPos2);
				
				
				if(iterPos1 == karr.end() || abs(*iterPos1-key) > k) 
				{
					if(iterPos2 != karr.end() && abs(*iterPos2-key) <= k)
						mData[*iterPos2] = value;
				}
					
				else if(iterPos2 == karr.end() || abs(*iterPos2-key) > k) 
				{
					if(iterPos1 != karr.end() && abs(*iterPos1-key) <= k)
						mData[*iterPos1] = value;
				}
				
				else
				{
					if(abs(*iterPos1-key) >= abs(*iterPos2-key))
						mData[*iterPos2] = value;
					else
						mData[*iterPos1] = value;
				}
			}
		}
		else if(cmd==3)
		{
			scanf("%d", &key);
			
			
			if(mData.count(key)==1)
				printf("%d\n", mData[key]);
			else 
			{
				viter iterPos1 = lower_bound(karr.begin(), karr.end(), key);
				viter iterPos2 = lower_bound(karr.begin(), karr.end(), key-k);
				
				if(abs(*iterPos1-key) > k && abs(*iterPos2-key) > k)
					printf("-1\n");
				
				else if(iterPos1 == karr.end() || abs(*iterPos1-key) > k) 
				{
					if(iterPos2 != karr.end() && abs(*iterPos2-key) <= k)
						printf("%d\n", mData[*iterPos2]);
				}
					
				else if(iterPos2 == karr.end() || abs(*iterPos2-key) > k) 
				{
					if(iterPos1 != karr.end() && abs(*iterPos1-key) <= k)
						printf("%d\n", mData[*iterPos1]);
				}
				
				else
				{
					if(abs(*iterPos1-key) == abs(*iterPos2-key) )
						printf("?\n");
				}
			}
			
		}
	}

	
	return 0;
}
