#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, k, x, count = 0, time = -1;
	cin >> n >> k;

	int dist[100001];
	fill(dist, dist + 100001, -1); // 방문안한거랑 구분을 위함. -1이면 방문 X
	queue<int> q;

	q.push(n);
	dist[n] = 0; // 거리는 0 

	while (!q.empty()) {
		x = q.front();
		q.pop();
		

		if (x == k) {
			if (time == -1) {
				time = dist[x];
				count++;
			}
			else {
				if (time == dist[x]) count++;
				if (dist[x] > time) break;
			}
		}

		int next;

		next = x - 1;
		if (next >= 0 && next <= 100000) { // 범위 체크
			if (dist[next] == -1 || dist[next] == dist[x] + 1) {
				dist[next] = dist[x] + 1; // 시간 증가
				q.push(next);
			}
		}

		next = x + 1;
		if (next >= 0 && next <= 100000) {
			if (dist[next] == -1 || dist[next] == dist[x] + 1) {
				dist[next] = dist[x] + 1;
				q.push(next);
			}
		}

		next = x * 2;
		if (next >= 0 && next <= 100000) {
			if (dist[next] == -1 || dist[next] == dist[x] + 1) {
				dist[next] = dist[x] + 1;
				q.push(next);
			}
		}
	}
	cout << time << '\n' << count;
	return 0;
}