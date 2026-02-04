#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> one = {1,2,3,4,5};
    vector<int> two = {2,1,2,3,2,4,2,5};
    vector<int> three = {3,3,1,1,2,2,4,4,5,5};
    int count1=0, count2=0, count3=0;
    
    for(int i =0; i<answers.size(); i++){
        if(answers[i] == one[i%one.size()]) count1++;
        if(answers[i] == two[i%two.size()]) count2++;
        if(answers[i] == three[i%three.size()]) count3++;
    }
    
    int maxScore = max({count1, count2, count3});
    if(maxScore == count1) answer.push_back(1);
    if(maxScore == count2) answer.push_back(2);
    if(maxScore == count3) answer.push_back(3); 
    
    return answer;
}