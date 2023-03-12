#include <bits/stdc++.h>
using namespace std;

struct Student
{
    string name;
    int score[3];
};

int n;
vector<Student> stList;

bool comp(const Student& a, const Student& b)
{  
	for(int i=0; i<3; i++)
        if(a.score[i] != b.score[i]) 
            return i!=1 ? a.score[i] > b.score[i] : a.score[i] < b.score[i];
	
    return a.name <= b.name;
}

int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin>>n;
	for(int i=0; i<n; i++)
	{
		Student st;
		cin>>st.name;
		for(int j=0; j<3; j++)
			cin>>st.score[j];
		stList.push_back(st);
	}
    sort(stList.begin(), stList.end(), comp);

	for(auto& s : stList)
        cout<<s.name<<'\n';

	return 0;
}
