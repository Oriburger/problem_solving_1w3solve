#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int n; 
vector<string> arr;

struct TrieNode
{
	TrieNode* children[10];
	bool isTerminal, childExist;
	
	TrieNode() : isTerminal(false), childExist(false)
	{
		memset(children, 0, sizeof(children));
	}
	~TrieNode()
	{
		for(int i=0; i<10; i++)
			if(children[i])
				delete children[i];
	}
	
	void insert(const char* key)
	{
		if(*key == '\0') isTerminal = true;
		else
		{
			int next = *key - '0';
			if(children[next]==NULL)
				children[next] = new TrieNode();
			childExist = true; 
			children[next]->insert(key+1);
		}		
	}
	
	bool isConsistent()
	{
		if(isTerminal && childExist) return false;
		for(int i=0; i<10; i++)
			if(children[i] && !children[i]->isConsistent()) return false;
		return true;
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int t; cin>>t;
	
	while(t--)
	{
		cin>>n;
		
		TrieNode *root = new TrieNode;
		for(int i=0; i<n; i++)
		{
			char temp[11];
			cin>>temp;
			root->insert(temp);
		}
		if(root->isConsistent()) cout<<"YES\n";
		else cout<<"NO\n";		
	}
}
