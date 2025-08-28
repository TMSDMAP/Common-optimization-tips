/*#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
ll N, K;
ll d[50005];
ll sum = 0;
//1 5 5 9 10 12 14
//题目大意就是要在排好序的数列中找出两段长度和最大的不重合的区间，并使两个区间中的最大值与最小值的差不大于k。
//注意审题！
int main() {
	cin >> N >> K;
	for (int i = 0; i < N; i++)
		cin >> d[i];
	sort(d, d + N);
	int left = 0;
	int right;
	for ( right = 0; right < N; right++)
	{
		 while(d[right] - d[left] > K)
		{
			
			left++;
			//cout << left << " " << right << endl;
			sum += right - left;
		}
	}
	//cout << left << " " << right << endl;
	if (d[right - 1] - d[left] <= K)
	sum += right - left-1;
	cout << sum << endl;
	return 0;
}*/
/*
l 0 r 0 s 0
l 0 r 1 

*/
/*

#include<cstdio>
#include<algorithm>
using namespace std;
int n,k,a[50005],c[50005],r=2,ma,ans;//c[i]用来存从i-1向左最多可以取多少颗钻石。
int main(){
	scanf("%d %d",&n,&k);
	a[n+1]=2100000000;//立个哨兵，防止r"跑丢"...
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i){
		while(a[r]<=a[i]+k)r++;//可以往右就尽量往右，因为我们只需要最长的。
		c[r]=max(r-i,c[r]);
		ma=max(ma,c[i]);//记录第i颗钻石（不包括i）前可以摆最多的钻石。即第一个架子上的钻石。ans动态维护
		ans=max(ans,ma+r-i);//为什么是'r-i'而不是'c[r]'? 因为要防区间重叠.注：c[r]左端点可能小于i
	}
	printf("%d",ans);
	return 0;
}
*/

//排序+双指针+动态规划
#include <iostream>
#include <algorithm>
#define N 50077
using namespace std;
int n, k;
int a[N], al[N], ar[N];
//al[i]表示 “前i颗钻石中，最长合法区间的长度”
//ar[i]表示 “后i颗钻石中，最长合法区间的长度”

int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	int l = 1, r = n;
	for (int i = 1; i <= n; i++) {
		while (a[i] - a[l] > k && l <= i) l++;
		al[i] = max(al[i - 1], i - l + 1);
	}
	for (int i = n; i >= 1; i--) {
		while (a[r] - a[i] > k && r >= i) r--;
		ar[i] = max(ar[i + 1], r - i + 1);
	}
	int ans = 0;
	for (int i = 1; i < n; i++) ans = max(ans, al[i] + ar[i + 1]);
	cout << ans << endl;
	return 0;
}



