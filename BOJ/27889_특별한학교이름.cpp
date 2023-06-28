#include <bits/stdc++.h>
using namespace std;

unordered_map<string, string> umap;

int main()
{
     umap["NLCS"] = "North London Collegiate School";
     umap["BHA"] = "Branksome Hall Asia";
     umap["KIS"] = "Korea International School";
     umap["SJA"] = "St. Johnsbury Academy";
     string str; cin>>str;

     cout<<umap[str]<<'\n';
     return 0;
}
