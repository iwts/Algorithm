/*第一种递归的方法太麻烦了，写了一个更简单的，最后一个函数ck()*/

#include<iostream>
#define LL long long

using namespace std;

LL jie(LL n) {
	if (n == 1) {
		return 1;
	}
	return n*jie(n - 1);
}

LL fun(LL n, LL m) {
	if (m == 1) {
		return 1;
	}
	if (n == 1) {
		return m;
	}else {
		return m*fun(n - 1, m - 1);
	}
}

LL C(LL n, LL m) { // n在上
	if (n == 0) {
		return 1;
	}else {
		return fun(n, m) / jie(n);
	}
}


LL ck(int n,int m){
	int i,j;
	LL up = 1;
	LL down = 1;
	for(i = m,j = n;i > m-n;i--,j--){
		up *= i;
		down *= j;
	}
	return up / down;
}
