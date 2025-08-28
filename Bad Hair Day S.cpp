#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int N;
//这道题用到了单调栈优化：
//单调栈的思想是维护一个单调递增或递减的栈，可以高效找到“某个元素左侧/右侧第一个比它大/小的元素”
int main() {
	cin >> N;
	vector<int> h(N + 1);
	for (int i = 1; i <= N; ++i) {
		cin >> h[i];
	}
	stack<int> st;
	long long total = 0;
	for (int i = N; i >= 1; --i) {
		while (!st.empty() && h[st.top()] < h[i]) st.pop();
		int j;
		if (st.empty()) j = N + 1;
		else j = st.top();
		int Ci = j - i - 1; // 计算当前元素右侧比它大的元素个数
		total += Ci;
		st.push(i);// 将当前元素入栈,维护单调递减性
	}
	cout << total << endl;
	return 0;
}