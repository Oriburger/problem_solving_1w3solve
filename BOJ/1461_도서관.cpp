#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int n, m;
bool zero_flag = true;
vector<int> book_pos[2]; //[bIsNegative]

int GetAnswer()
{
    if(zero_flag) return 0;
    if(n==1) return book_pos[0].empty() ? abs(book_pos[1][0]) : abs(book_pos[0][0]);
    
    for(int i=0; i<2; i++)
        sort(book_pos[i].begin(), book_pos[i].end());
    
    int ret = 0;
    for(int i=0; i<2; i++)
    {
        int cnt = 0, front=-1;
        for(int j=book_pos[i].size()-1; j >= 0; j--)
        {
            if(front==-1) front = book_pos[i][j];
            if(++cnt==m)
            {
                ret += front*2;
                front=-1;
                cnt=0;
            }
        }
        if(front!=-1) ret += front*2;
    }
    if(book_pos[0].empty()) ret -= book_pos[1].back();
    else if(book_pos[1].empty()) ret -= book_pos[0].back();
    else ret -= max(book_pos[0].back(), book_pos[1].back());
    
    return ret; 
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin>>n>>m;
    
    for(int i=0; i<n; i++)
    {
        int tmp; cin>>tmp;
        if(tmp!=0) zero_flag = false; 
        book_pos[tmp < 0].push_back(abs(tmp));
    }
    
    cout<<GetAnswer()<<'\n';
        
    return 0;
}
