#include <iostream>
#include <vector>
#include <deque> // 双端队列, 方便在两端插入和删除元素
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> nums(n);
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	deque<int> q;
	vector<int> result; // 存储每个窗口的最大值
	
	for (int i = 0; i < n; i++) {
		if(!q.empty()&&q.front()<i-k+1) // 当前窗口的左边界是 i - k + 1，若队头索引 < 左边界，则弹出
			q.pop_front(); // 移除窗口外的元素
		while(!q.empty()&&nums[q.back()]<nums[i]) // 这些元素在当前元素左侧，且值更小，永远不可能成为后续窗口的最大值
			q.pop_back(); // 移除所有小于当前元素的索引
		q.push_back(i); // 将当前元素的索引加入队列
		if (i >= k - 1) { //这里i是木板的右端点
			result.push_back(nums[q.front()]); // 队头元素即为当前窗口的最大值
		}
	}
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] <<endl;
	}
	return 0;
}
