#include <string>
#include <vector>
#include <map>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    map<string, int> mp;
    for(int i=0; i<participant.size(); i++){
        mp[participant[i]]++;
    }
    for(int i=0; i<completion.size(); i++){
        mp[completion[i]]--;
    }
    for(auto p: mp){
        if(p.second > 0){
            answer = p.first;
        }
    }
    
    return answer;
}