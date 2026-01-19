#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(string s) {
    int answer = 0;
    vector<string> english = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    for(int i=0; i<10; i++){
        size_t pos;
        while((pos = s.find(english[i])) != string::npos){
            s.replace(pos, english[i].length(), to_string(i));
        }
    }
    answer = stoi(s);
    return answer;
}