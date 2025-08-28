/*#include <iostream>
#include <vector>
using namespace std;
// n+1/2 - 1 
typedef long long ll;
const int MOD = 10007;
ll n, m;
ll num[100005];
ll color[100005];

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> num[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> color[i];
	}
	vector<vector<vector<int>>> groups(m + 1, vector<vector<int>>(2));
	for (int i = 1; i <= n; i++) {
		groups[color[i]][i%2].push_back(i);
	}
	ll ans = 0;
	for (int c = 1; c <= m; c++) {
		for (int p = 0; p < 2; ++p) {
			ll f = 0, sn = 0, sfn = 0,cnt = 0;
			if (groups[c][p].size()<2) continue;
			for (int j = 0;j< groups[c][p].size();j++)
			{
				    int i = groups[c][p][j];
					//cout << i << " ";
					f = (f + i) % MOD;
					sn = (sn + num[i]) % MOD;
					if (j == 1)
					{
						//cout << "f: " << f << " sn: " << sn << endl;
						ans = (ans + f * sn%MOD) % MOD;
					}
					if(j>1)
					ans = (ans%MOD + f * num[i]%MOD + sn * i%MOD + sfn%MOD) % MOD;
					sfn = (sfn + num[i] * i%MOD) % MOD;
					//cout << ans << endl;
			}
			//cout << endl;
		}
	}
	cout << ans%MOD<< endl;
	
	/*ll ans = 0;
	for (ll len = 1; len <= (n + 1) / 2 - 1; len++)
	{
		for (int i = 1; i + 2 * len <= n; i++)
		{
			if (color[i] == color[i + 2*len])
			{
				ans = (ans + (i + i + 2*len) * (num[i] + num[i + 2 * len])) % MOD;
				//cout <<i<<" " << i + 2 * len << " " << ans << endl;
			}
		}
	}
	cout << ans % MOD << endl;*/
	//return 0;
//}*/


#include <cstdio>
#include <iostream>
using namespace std;
const int N = 100000;
const int M = 10007;
int n, m;
int sum[N + 1][2], nt[N + 1][2];
int color[N + 1], num[N + 1];
long long ans;

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> num[i];
		num[i] %= M;
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> color[i];
		int c = color[i];
		int g = i % 2;
		nt[c][g]++;
		sum[c][g] += num[i];
		sum[c][g] %= M;
	}

	for (int i = 1; i <= n; i++) {
		int c = color[i];
		int g = i % 2;
		ans += i % M * ((sum[c][g] + (nt[c][g] - 2) % M * num[i]+M) % M);
		ans %= M;
	}
	cout << ans % M << endl;
	return 0;
}
