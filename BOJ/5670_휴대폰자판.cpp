#include <iostream>
#include <cstring>
using namespace std;

int n;
const int MAX_N = 100000;
typedef long long ll;
char tmp[MAX_N][80];

struct TrieNode
{
	TrieNode * children[26];
	int wordCnt, childCnt;
	bool isTerminal;
	
	TrieNode() : wordCnt(0), childCnt(0), isTerminal(false)
	{
		memset(children, 0, sizeof(children));
	}
	~TrieNode()
	{
		for(int i=0; i<26; i++)
			if(children[i])
				delete children[i];
	}
	
	void insert(const char* key)
	{
		if(*key=='\0')
		{
			isTerminal = true;
			childCnt++; 
		}
		else
		{
			int next = *key - 'a';
			if(children[next]==NULL)
			{
				children[next] = new TrieNode;
				childCnt++;
			}
			children[next]->insert(key+1);
			wordCnt++;
		}
	}
	
	ll GetTypingCnt(bool isRoot)
	{
		ll ret = 0;
		if(isRoot || childCnt > 1) ret = wordCnt;
		for(int i=0; i<26; i++)
			if(children[i])
				ret += children[i]->GetTypingCnt(false);	
		return ret;
	}
};

int main()
{
	cout<<fixed;
	cout.precision(2);
	
	while(cin>>n)
	{
		TrieNode* root = new TrieNode;
		
		for(int i=0; i<n; i++)
		{
			cin>>tmp[i]; 
			root->insert(tmp[i]);
		}
		
		int total = 0;
		
		cout<<(double)root->GetTypingCnt(true) / n<<'\n';
		
		delete root;
	}
}
