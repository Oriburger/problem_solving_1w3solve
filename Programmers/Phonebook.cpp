#include <string>
#include <cstring>
#include <vector>
using namespace std;

struct TrieNode
{
    TrieNode * children[10];
    bool isTerminal; 
    int childCnt;
    
    TrieNode() : isTerminal(false), childCnt(0)
    {
        memset(children, 0, sizeof(children));
    }
    ~TrieNode()
    {   
        for(int i=0; i<10; i++)
            if(children[i])
               delete children[i];
    }
    
    void insert(const char * key)
    {   
        if(*key == '\0') isTerminal = true;
        else
        {
            int next = *key - '0';
            if(children[next]==NULL)
            {
                children[next] = new TrieNode;
                childCnt += 1;
            }
            children[next]->insert(key+1);
        }
    }
    
    bool getAnswer()
    {
        if(isTerminal && childCnt >= 1) return false;
        for(int next=0; next<10; next++)
            if(children[next] && !children[next]->getAnswer())
                return false;
        return true; 
    }
};

bool solution(vector<string> pnum) 
{   
    TrieNode * root = new TrieNode; 
    for(auto &s : pnum)
        root->insert(s.c_str());
    return root->getAnswer();
}

/* -- unorder set 을 활용한 소스


#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

unordered_set<string> uset;

bool solution(vector<string> phone_book)
{
    sort(phone_book.begin(), phone_book.end());
    
    for(const auto& s : phone_book)
    {
        for(int i=1; i<s.size(); i++)
            if(uset.find(s.substr(0, i)) != uset.end())
                return false;
        uset.insert(s);
    }
    return true;
}

*/
