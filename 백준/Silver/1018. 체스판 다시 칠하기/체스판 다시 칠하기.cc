#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
// #1018

char board[51][51];
string w[8] = { //흰색부터 시작하는 경우의 체스판
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW"
};
string b[8] = { //검정부터 시작하는 경우의 체스판
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB"
};

int w_start(int x, int y) { //w부터 시작하는 경우
    int count = 0;
    for (int i = 0; i < 8; i++) { //8*8이므로 
        for (int j = 0; j < 8; j++) {
            if (board[x + i][y + j] != w[i][j]) {
                count++; //주어진 체스판과 다른 경우 count 증가
            }
        }
    }
    return count;
}

int b_start(int x, int y) { //b부터 시작하는 경우
    int count = 0;
    for (int i = 0; i < 8; i++) { //8*8이므로 
        for (int j = 0; j < 8; j++) {
            if (board[x + i][y + j] != b[i][j]) {
                count++; //주어진 체스판과 다른 경우 count 증가
            }
        }
    }
    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }
    int min_count = 99999;
    for (int i = 0; i + 8 <= n; i++) {
        for (int j = 0; j + 8 <= m; j++) {
            min_count = min(min_count, min(w_start(i, j), b_start(i, j)));
        }
    }
    cout << min_count;
    return 0;
}