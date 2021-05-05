#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <unordered_map>
using namespace std;

typedef pair<int, int> P;

int genreCnt = 0;
unordered_map<string, int> genreIdx; //key가 장르명, val이 장르식별번호
vector<vector<P> > songData; //songData[i] : i번 장르 데이터 배열. {노래 고유번호, 노래 재생횟수}
vector<P> playCntArr; // {장르의 총 재생 횟수, 장르 고유 번호}

bool compSong(const P& a, const P& b)
{
    if(a.second > b.second) return true; //장르 총 재생 횟수 : 내림차순
    else if(a.second < b.second) return false;
    
    return a.first < b.first; //노래 고유 번호는 오름차순
}

vector<int> solution(vector<string> genres, vector<int> plays) 
{
    vector<int> answer;
    
    for(int i=0; i<plays.size(); i++)
    {
        if(!genreIdx.count(genres[i]))
        {
            genreIdx[genres[i]]=genreCnt;
            songData.push_back({});
            playCntArr.push_back({0, genreCnt++});
        }
        
        songData[genreIdx[genres[i]]].push_back({i, plays[i]});
        playCntArr[genreIdx[genres[i]]].first += plays[i];
    }    
    sort(playCntArr.begin(), playCntArr.end(), greater<P>());
    
    for(auto &p : playCntArr)
    {
        int pickCnt = 0;
        const int idx = p.second;
        
        sort(songData[idx].begin(), songData[idx].end(), compSong);
        
        for(int i=0; i<songData[idx].size(); i++)
        {
            answer.push_back(songData[idx][i].first);
            if(++pickCnt==2) break;
        }
    }
    
    return answer;
}
