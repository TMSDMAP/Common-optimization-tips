/*#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
int n, w;
//int score[100005];
const int maxn = 100000;
int cnt[maxn + 5];
vector<int> ans;
//multiset<int,greater<int>> p;
set<int> ap; //用一个 set 或 vector 记录已出现的分数，每次只遍历这些分数。
bool cmp(int a, int b) {
	return a > b;
}
int main() {
	cin >> n >> w;
	int total = 0;
	for (int i = 1; i <=n; i++)
	{
		int x;
		//cin >> score[i];
		cin >> x;
		cnt[x]++; //桶排序
		//total++;
		ap.insert(x);
		//p.insert(x);
		//sort(score + 1, score + i + 1,cmp);
		int t = max(1, int(i * w*0.01));
		//ans.push_back(t);
		int sum = 0;
		auto it = ap.rbegin(); //set是升序，需反向遍历
		for (; it != ap.rend(); ++it) {
			sum += cnt[*it];
			if (sum >= t) {
				if (i > 1) cout << " ";
				cout << *it;
				break;
			}
		}
	}
	return 0;
}
*/

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
int n, w;
//int score[100005];
const int maxn = 607;
int cnt[maxn + 5];
vector<int> ans;  //不用set的桶排序
multiset<int, greater<int>> p;
bool cmp(int a, int b) {
	return a > b;
}
int main() {
	cin >> n >> w;
	int total = 0;
	for (int i = 1; i <= n; i++)
	{
		int x;
		//cin >> score[i];
		cin >> x;
		cnt[x]++;
		total++;
		//p.insert(x);
		//sort(score + 1, score + i + 1,cmp);
		int t = max(1, int(i * w * 0.01));
		//ans.push_back(t);
		int sum = 0;
		for (int s = maxn; s >= 0; --s) {
			sum += cnt[s];
			if (sum >= t) {
				if (i > 1) cout << " ";
				cout << s;
				break;
			}
		}
	}
	return 0;
}