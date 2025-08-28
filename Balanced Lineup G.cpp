#include <iostream>
#include <cmath>
using namespace std;
int n, q;
int st_max[50005][500], st_min[50005][500]; //st表时间复杂度O(nlogn) 询问时间复杂度O(1)
int h[50005];  
int main()  
{
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> h[i];
	for (int i = 1; i <= n; i++)
	{
		st_max[i][0] = h[i];
		st_min[i][0] = h[i];  //初始化，这里i是起点，j是2的j次方长度
	}
	for(int j = 1;(1<<j)<=n;++j)
		for (int i = 1; i + (1 << j) - 1 <= n; ++i) //i+(1<<j)-1表示区间终点
		{
			st_max[i][j] = max(st_max[i][j - 1], st_max[i + (1 << j - 1)][j - 1]);
			st_min[i][j] = min(st_min[i][j - 1], st_min[i + (1 << j - 1)][j - 1]);
		}
	while (q--)
	{
		int l, r;
		cin >> l >> r;
		int len = r - l + 1;
		int k = log2(len); //k为2的k次方小于等于len的最大值,被两个2的k次方覆盖再比较就行了
		int maxv = max(st_max[l][k], st_max[r - (1 << k) + 1][k]);
		int minv = min(st_min[l][k], st_min[r - (1 << k) + 1][k]);
		cout << maxv - minv << endl;
	}
}