/*
main函数提供测试数据，按照每行8个素数输出，可以输出前n位的素
数。百度素数表对比即可验证算法正确性

----------update--------
增加prime_num函数，优化了一下，在纯粹搜索素数数量的时间复杂度要低于
prime算法，主要在筛选i的素数的时候，判定条件改成i*i <= n，忽略了已
经筛掉的内容。
*/

#include<iostream>
#define MAX 233333

using namespace std;

int not_prime[MAX]; // 非素数存放数组，值为1的不是素数，0是素数
int primes[MAX]; // 素数存放数组，按照顺序存放素数

int prime(int n){
	memset(not_prime, 0, sizeof(not_prime));
	memset(primes, 0, sizeof(primes));
	int flag = 1;
	for (int i = 2; i <= n; i++) {
		if (not_prime[i] == 0) {
			primes[flag++] = i;
			for (int j = i*i; j <= n; j += i) {
				not_prime[j] = 1;
			}
		}
	}
	return flag - 1; // 返回值是素数的数量
}

int prime_num(int n){
	memset(not_prime, 0, sizeof(not_prime));
	int flag = n;
	for (int i = 2; i*i <= n; i++) {
		if (not_prime[i] == 0) {
			for (int j = i*i; j <= n; j += i) {
				if (not_prime[j] == 1) continue;
				not_prime[j] = 1;
				flag--;
			}
		}
	}
	return flag - 1;
}

int main(){
	int n;
	while (cin >> n) {
		int number = prime(n);
		int j = 1;
		for (int i = 1; i <= number; i++,j++) {
			cout << primes[i] << " ";
			if (j == 8) {
				cout << endl;
				j = 0;
			}
		}
	}

	system("pause");
	return 0;
}
