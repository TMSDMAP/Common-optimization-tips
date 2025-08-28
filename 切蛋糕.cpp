#include <iostream>
#include <cstdio>
#include <deque>
#include <algorithm>
using namespace std;
typedef long long ll;
int m, n;
ll pre[500005];
ll p[500005];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
		pre[i] = pre[i - 1] + p[i];
	} //前缀和+单调队列
	deque<ll> dq;  //dq是单调队列，存储前缀和的下标，且保证pre[dq]单调递增，这样可以取到最小的左侧前缀和，得到最大区间和
	ll ans = -1e18;
	for (ll r = 1; r <= n; r++) {
		while (!dq.empty() && pre[dq.back()] >= pre[r-1]) dq.pop_back();
		dq.push_back(r-1);
		while (!dq.empty() && dq.front() < r - m) dq.pop_front();
		if (!dq.empty()) {
			ans = max(ans, pre[r] - pre[dq.front()]);
		}
	}
	cout << ans << "\n";
	return 0;
}
//不用st表，是因为st表是静态区间查询，它适合 idempotent 查询（如 min/max），不适合区间和。
//这个算法的时间复杂度是O(n),每个前缀索引最多入队一次，出队一次，每次都是O(1);