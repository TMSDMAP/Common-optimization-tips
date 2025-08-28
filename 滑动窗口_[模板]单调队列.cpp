#include <iostream>
#include <deque>
#include <vector>
using namespace std;

vector<int> maxwindow(const vector<int>& nums, int k) {
	deque<int> dq;
	vector<int> res;
	for (int i = 0; i < nums.size(); ++i) {  //维护单调递减队列
		while (!dq.empty() && dq.front() <= i - k) dq.pop_front();  //弹出窗口外元素
		while (!dq.empty() && nums[dq.back()] < nums[i]) dq.pop_back(); //弹出比当前元素小的元素
		dq.push_back(i);  //加入当前元素下标
		if (i >= k - 1) res.push_back(nums[dq.front()]);
	}
	return res;
}
vector<int> minwindow(const vector<int>& nums, int k) {
	deque<int> dq;
	vector<int> res;
	for (int i = 0; i < nums.size(); ++i) {
		while (!dq.empty() && dq.front() <= i - k) dq.pop_front();
		while (!dq.empty() && nums[dq.back()] > nums[i]) dq.pop_back();
		dq.push_back(i);
		if (i >= k - 1) res.push_back(nums[dq.front()]);
	}
	return res;
}

int main() 
{
	int n, k;
	vector<int> nums;
	cin >> n >> k;
	nums.resize(n);
	for (int i = 0; i < n; ++i) cin >> nums[i];
	vector<int> max_res = maxwindow(nums, k);
	vector<int> min_res = minwindow(nums, k);
	for(int i = 0; i < min_res.size(); ++i) {
		if (i) cout << " ";
		cout << min_res[i];
	}
	cout << endl;
	for (int i = 0; i < max_res.size(); ++i) {
		if (i) cout << " ";
		cout << max_res[i];
	}
	return 0;
}