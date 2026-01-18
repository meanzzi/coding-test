#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> priorities, int location) {
    queue<pair<int, int>> q;
    priority_queue<int> pq;
    vector<int> v;
    
    for(int i =0; i<priorities.size(); i++){
        q.push({priorities[i], i}); //우선순위, index;
        pq.push(priorities[i]); //우선순위 정렬
    }
    
    while(!q.empty()){
        if(q.front().first == pq.top()){ //우선순위가 가장 높다면
            v.push_back(q.front().second);
            q.pop();
            pq.pop();
        }
        else {
            q.push(q.front());
            q.pop();    
        } 
    }
    
    for(int i =0; i<v.size(); i++){
        if(location == v[i]) return i+1;
    }
}