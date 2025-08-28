#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

int m,n;
int a[1000005];
int main() {
	cin >> n >> m;
	for(int i = 1;i<= n; i++) {
		cin >> a[i];
	}
	unordered_map<int, int> mp;
	int l = 1;
	int mlen = n + 1;
	int rx = 0, ry = 0;
	int unique = 0;
	for (int r = 1; r <= n; r++) {
		int count = a[r];
		if (mp[count] == 0) unique++;
		mp[count]++;
		while (unique == m) {
			int cur = r - l + 1;
			if (cur < mlen) {
								mlen = cur;
				rx = l;
				ry = r;
			}
			else if (cur == mlen) {
				if(l<rx){
					rx = l;
					ry = r;
				}
			}
			int lval = a[l];
			mp[lval]--;
			if (mp[lval] == 0) unique--;
			l++;
		}

	}
	cout << rx << " " << ry << endl;
	return 0;
}