#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

string solution(string my_string) {
    string answer = "";
    unordered_set<char> s;
    
    for(int i=0;i<my_string.length(); i++){
        char c = my_string[i];
        if(s.find(c) == s.end()){
            s.insert(c);
            answer += c;
        }
    }
   
    return answer;
}