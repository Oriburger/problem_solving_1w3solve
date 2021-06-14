#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<string, string> umap; //key : id, val : nickname

vector<string> Divide(string str) //문자열을 문자단위로 나눔
{
    vector<string> ret;
    string temp="";
  
    for(int i=0; i<str.size(); i++)
    {
        if(str[i]!=' ')
            temp.push_back(str[i]);
        
        if(str[i]==' ' || i==str.size()-1)
        {
            ret.push_back(temp);
            temp.clear();
        }
    }
    return ret;
}

vector<string> solution(vector<string> record)
{
    vector<string> answer;
    
    for(int i=0; i<record.size(); i++) //1회차 순회 : id-닉네임 갱신 
    {
        vector<string> temp = Divide(record[i]);
        
        if(temp.size()==3 && !umap.count(temp[1])) //등록되지 않았다면
            umap[temp[1]]=temp[2];
        
        if(temp[0]=="Change" || temp[0]=="Enter") //새로운 닉네임으로 들어와도 갱신됨.
            umap[temp[1]]=temp[2];
    }
    
    for(int i=0; i<record.size(); i++) //2회차 순회 .
    {
        vector<string> temp = Divide(record[i]); 
        
        if(temp[0]=="Enter")
            answer.push_back(umap[temp[1]]+"님이 들어왔습니다.");
        else if(temp[0]=="Leave")
            answer.push_back(umap[temp[1]]+"님이 나갔습니다.");
    }
    
    return answer;
}
