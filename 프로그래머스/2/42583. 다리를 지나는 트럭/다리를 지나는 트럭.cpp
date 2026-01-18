#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0, bridge_weight = 0, i =0;
    queue<int> q;
    
    //다리 길이 0으로 초기화
    for(int j=0; j<bridge_length; j++){
        q.push(0);
    }
    
    while(i<truck_weights.size()){
        answer++; //1초 경과
        
        bridge_weight -= q.front(); // 다리에서 트럭 나가기
        q.pop();
        
        // 트럭 올릴 수 있는 지 확인
        if(bridge_weight + truck_weights[i] <= weight){
            //올라올 수 있다면
            bridge_weight += truck_weights[i];
            q.push(truck_weights[i]);   
            i++; 
        }
        else {
            //아니라면 0 추가
            q.push(0);
        }     
    }  
    //다리를 올리는 순간 끝나므로 다 건너가는 다리 길이 더해주기
    return answer + bridge_length;
}