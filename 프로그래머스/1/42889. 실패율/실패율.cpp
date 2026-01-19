#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<int> fail(N+2);
    
    // 클리어 못한 플레이어 수 
    for(int i =0; i<stages.size(); i++){
        if(stages[i] <= N){ // N+1은 클리어해서 실패에 포함X
          fail[stages[i]]++;  
        }
    }
    
    int total = stages.size(); //스테이지 도달 플레이어 수 
    vector<pair<double, int>> rates;
        
    for(int i=1; i<=N; i++){
        double rate = 0.0; // 실패율
        
        if(total > 0) {
            rate = (double)fail[i] / total;
        }
        rates.push_back({rate, i}); // 실패율, 스테이지 번호
        total -= fail[i]; // 남은사람 - 이전 스테이지 실패 사람         
    }
    
    sort(rates.begin(), rates.end(), [](pair<double, int> &a, pair<double, int> &b){
        if(a.first == b.first) return a.second < b.second;
        return a.first > b.first;
    });
    
    for(int i=0; i<rates.size(); i++){
        answer.push_back(rates[i].second);
    }
    
    return answer;
}