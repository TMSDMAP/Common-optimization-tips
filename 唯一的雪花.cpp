#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;
int T;
int a[1000005];
//滑动窗口+哈希表（存索引）
int main() {
	cin >> T;
	while (T--) {
		int n;
		cin >> n;

		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		unordered_map<int, int> mp;
		int left = 0, maxL = 0;
		for (int right = 0; right < n; right++)
		{
			int t = a[right];
			if(mp.count(t) && mp[t] >= left) {
				left = mp[t] + 1;
			}
			mp[t] = right;
			maxL = max(maxL, right - left + 1);
		}
		cout << maxL << endl;
	}
	return 0;
}
