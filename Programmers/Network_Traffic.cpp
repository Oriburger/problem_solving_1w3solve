/*

  2018 Kakao Blind Recruitment 1차 - 추석 트래픽
  
  
  상당히 상당한 스파게티 코드이다 @.@

*/

#include <string>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

typedef pair<int, int> P;

const int MAX = 87000000;
vector<P> timeline;

int solution(vector<string> lines) 
{
    if(lines.size()==1) return 1;
    
    int answer = 0;
    int minVal=2147000000, maxVal=-1;
    
    for(int i=0; i<lines.size(); i++)
    {
        int h, m, s, start=0, end=0;
        const int len = lines[i].size();
        
        h = stoi(lines[i].substr(11, 2));
        m = stoi(lines[i].substr(14, 2));
        s = stoi(lines[i].substr(17, 2));
        end = (h*3600 + m*60 + s)*1000;
        end += stoi(lines[i].substr(20, 3));
        start = end - stoi(lines[i].substr(24, 1))*1000+1;
            
        if(len >= 27) 
        {
            int cnt=1;
            for(int j=26; j<len; j++)
                if(lines[i][j]>='0' && lines[i][j]<='9')
                    cnt++;
            
            if(cnt) start -= stoi(lines[i].substr(26, cnt));
        }
        start += 3000;
        end += 3000;
        
        timeline.push_back({start, end});
    }
    
    for(int i=0; i<timeline.size()-1; i++)
    {
        int cnt=1, curr = timeline[i].second; 

        for(int j=i+1; j<timeline.size(); j++)
        {
            int next = timeline[j].first;
            
            if(curr + 1000 > next)
                cnt+=1;
        }

        answer = max(answer, cnt);
    }
    
    //----------------------------------------------
    sort(timeline.begin(), timeline.end());
    for(int i=0; i<timeline.size()-1; i++)
    {
        int cnt=1, curr = timeline[i].second; 
        
        for(int j=i+1; j<timeline.size(); j++)
        {
            int next = timeline[j].first;
            
            if(curr + 1000 > next && curr < timeline[j].second)
                cnt+=1;
        }
        
        answer = max(answer, cnt);
    }
                 
    return answer;
}
