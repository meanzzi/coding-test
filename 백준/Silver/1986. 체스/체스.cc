#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, q, k, p;
bool visit[1009][1009];
char chess[1009][1009];
vector<pair<int, int>> queen;
vector<pair<int, int>> knight;
vector<pair<int, int>> pawn;

int area(int x, int y) {
	if (x >= 1 && x <= n && y >= 1 && y <= m) return true;
	else return false;
}

void queen_move(int x, int y) {
	int dx[8] = { -1,-1,0,1,1,1,0,-1 };
	int dy[8] = { 0,1,1,1,0,-1,-1,-1 };
	for (int i = 0; i < 8; i++) {
		for (int j = 1; j <= max(n, m); j++) {
			int xx = x + dx[i] * j;
			int yy = y + dy[i] * j;
			if (area(xx, yy) == 1 && chess[xx][yy] == '.') {
				visit[xx][yy] = 1;
			}
			else break;
		}
	}
}

void knight_move(int x, int y) {
	int dx[8] = { -2,-1,1,2,-2,-1,1,2 };
	int dy[8] = { 1,2,2,1,-1,-2,-2,-1 };
	for (int i = 0; i < 8; i++) {
		int xx = x + dx[i];
		int yy = y + dy[i];
		if (area(xx, yy) == 1 && chess[xx][yy] == '.') {
			visit[xx][yy] = 1;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			chess[i][j] = '.';
		}
	}

	cin >> q;
	for (int i = 1; i <= q; i++) {
		int x, y;
		cin >> x >> y;
		visit[x][y] = 1;
		queen.push_back({ x,y });
		chess[x][y] = 'q';
	}
	cin >> k;
	for (int i = 1; i <= k; i++) {
		int x, y;
		cin >> x >> y;
		visit[x][y] = 1;
		knight.push_back({ x,y });
		chess[x][y] = 'k';
	}
	cin >> p;
	for (int i = 1; i <= p; i++) {
		int x, y;
		cin >> x >> y;
		visit[x][y] = 1;
		pawn.push_back({ x,y });
		chess[x][y] = 'p';
	}

	for (int i = 0; i < queen.size(); i++) {
		queen_move(queen[i].first, queen[i].second);
	}
	for (int i = 0; i < knight.size(); i++) {
		knight_move(knight[i].first, knight[i].second);
	}

	int sum = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (visit[i][j] == 0) sum++;
		}
	}
	cout << sum;

	return 0;
}