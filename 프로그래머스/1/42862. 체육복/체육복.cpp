#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;

    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());

    vector<bool> count(n+1, true); // 수업 들을 수 있는 학생 수
    vector<bool> lend(n+1, false); // 체육복 빌려줄 수 있는 학생 수

    // lost 학생 체육복 없음
    for(int i = 0; i < lost.size(); i++) {
        count[lost[i]] = false;
    }

    // reserve 학생 여벌 있음
    for(int i = 0; i < reserve.size(); i++) {
        lend[reserve[i]] = true;
    }

    // lost와 reserve 겹치는 학생 처리
    for(int i = 0; i < lost.size(); i++) {
        int student = lost[i];
        if(lend[student]) { // 여벌 갖고 있으면서 도난당함 → 본인 사용
            count[student] = true;
            lend[student] = false;
            lost[i] = -1; // 처리 완료 표시 (체육복 있음)
        }
    }

    // 체육복 빌리기
    for(int i = 0; i < lost.size(); i++) {
        int student = lost[i];
        if(student == -1) continue; // 이미 체육복 있음
        if(student > 1 && lend[student-1]) { // 왼쪽 친구
            count[student] = true;
            lend[student-1] = false;
        }
        else if(student < n && lend[student+1]) { // 오른쪽 친구
            count[student] = true;
            lend[student+1] = false;
        }
    }

    // 최종 수업 참여 가능한 학생 수 계산
    for(int i = 1; i <= n; i++) {
        if(count[i]) answer++;
    }

    return answer;
}
