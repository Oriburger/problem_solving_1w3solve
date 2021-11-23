#include <bits/stdc++.h>
using namespace std; 
typedef pair<int, int> P;

class comp //Priority_Queue 비교 클래스 
{
public:
    bool operator() (const P& a, const P& b)  
    {
        return a.second > b.second; //소요시간이 덜 드는 작업이 top로 감
    }
};

priority_queue<P, vector<P>, comp> pq; //comp를 기준으로 원소를 정렬

int solution(vector<vector<int>> jobs)
{
    int answer = 0, idx = 0; 
    int curr_time = 0; //현재 작업을 완료했을때의 시각
    sort(jobs.begin(), jobs.end()); //요청 시간에 따라 오름차순으로 정렬
    
    while(idx < jobs.size() || !pq.empty())
    {
        if(idx < jobs.size() && jobs[idx][0] <= curr_time) //idx번째 작업이 힙에 들어갈 수 있다면?
        {                                                  // - jobs[idx]의 요청시간이 현재 시각보다 빠르다면
            pq.push({jobs[idx][0], jobs[idx][1]});
            idx += 1; //최소힙에 넣고, idx 증가
            continue; //가능한 모든 작업들을 힙에 넣음
        }
        
        if(pq.empty()) //만약 고르지 못했다면?
            curr_time = jobs[idx][0]; //작업 완료 시각을 바로 다음 작업으로 갱신
            
        else //골랐다면
        {
            P temp = pq.top(); //최소 힙에서 하나 작업을 꺼내어서
            pq.pop();
            
            curr_time += temp.second; //작업 완료 시각을 갱신
            answer += (curr_time - temp.first); //정답도 갱신
        }
        
    }
    
    return answer/jobs.size(); //나머지가 없는 평균 반환
}
