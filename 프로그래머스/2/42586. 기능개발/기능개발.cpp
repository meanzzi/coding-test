#include <string>
#include <vector>
#include <cmath>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> days;
    for(int i=0; i < progresses.size(); i++ ){
        double pos = (double)(100 - progresses[i]) / speeds[i];
        days.push_back(ceil(pos));
    }
    
    int Max = days[0], count = 1;
    for(int i=1; i<days.size(); i++){
        if(Max >= days[i]){
            count++;
        }
        else {
            answer.push_back(count);
            count = 1;
            Max = days[i];
        }
    }
    answer.push_back(count); //마지막은 안들어가져서
    return answer;
}