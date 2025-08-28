#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
int n, Q;
int a[8005];
int main() {
	scanf("%d%d", &n, &Q);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	while (Q--) {
		int xx;
		scanf("%d", &xx);
		if (xx == 1)
		{
			int x, v;
			scanf("%d%d", &x, &v);
			a[x] = v;
		}
		else {
			int x;
			scanf("%d", &x);
			int sum = 1;
			/*for (int i = 1; i <x; i++)
				if (a[i] > a[x]) sum--;
			for(int i = x+1;i<=n;i++)
				if (a[i] >= a[x]) sum--;*/
			for (int i = 1; i < x; i++)
				if (a[i] <= a[x]) sum++;
			for (int i = x + 1; i <= n; i++)
				if (a[i] < a[x]) sum++;
			printf("%d\n", sum);
		}
	}
	return 0;
}

