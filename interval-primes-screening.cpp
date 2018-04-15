/*
直接给出的函数就是大区间素数筛法，所以没有使用int而是long long数据类型，预定义使LL即为long long。
primes存放区间内素数，prime_num是素数数量

函数是筛法的算法，整个程序解决了poj-2689题。该题也是区间筛法的模板题
*/

#include<iostream>
#include<string>
#include<math.h>
#include<algorithm>
#define TIME std::ios::sync_with_stdio(false)
#define LL long long
#define MAX 1001000
#define INF 0x3f3f3f3f

using namespace std;

int l, r;
bool is_prime_small[MAX];
bool is_prime[MAX];
LL primes[MAX];
LL prime_num;

LL Max(LL a, LL b) {
    return a > b ? a : b;
}

void interval_sieve(LL a, LL b) {
    memset(is_prime, true, sizeof(is_prime));
    memset(is_prime_small, true, sizeof(is_prime_small));
    for (LL i = 2; i <= (LL)sqrt((double)b); i++) {
        if (is_prime_small[i]) {
            for (LL j = i*i; j <= (LL)sqrt((double)b); j += i) {
                is_prime_small[j] = false;
            }
            for (LL j = Max(2LL, (a + i - 1) / i)*i; j <= b; j += i) {
                is_prime[j - a] = false;
            }
        }
    }
    for (LL i = 0; i <= b - a; i++) {
        if (is_prime[i]) {
            if (i + a == 1) continue;
            primes[prime_num++] = i + a;
        }
    }
}

int main() {
    TIME;
    while (cin >> l >> r) {
        memset(primes, 0, sizeof(primes));
        prime_num = 0;
        interval_sieve(l, r);
        if (prime_num == 0 || prime_num == 1) {
            cout << "There are no adjacent primes." << endl;
            continue;
        }
        LL max_ans = -1;
        LL min_ans = INF;
        LL max_p, min_p;
        for (LL i = 1; i < prime_num; i++) {
            LL m = primes[i] - primes[i - 1];
            if (m > max_ans) {
                max_ans = m;
                max_p = i;
            }
            if (m < min_ans) {
                min_ans = m;
                min_p = i;
            }
        }
        cout << primes[min_p - 1] << "," << primes[min_p] << " are closest, ";
        cout << primes[max_p - 1] << "," << primes[max_p] << " are most distant." << endl;
    }

    system("pause");
    return 0;
}
