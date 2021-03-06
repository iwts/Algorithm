/*
source：浙江大学数据结构-陈越
使用了在线处理的思想，输入一个数就处理一个数。O(n)的时间复杂度。
每输入一个数就进行累加，然后与最大数比较。如果大于当前最大值，就
更新。否则进行判断，如果小于0就重置为0。
因为小于0就进行重置，所以不存在maxsum中的子列和比maxsum大的情况。
*/

#include<iostream>

using namespace std;

int MaxSubSeqSum(int arr[],int n) {
    int sum, maxsum;
    sum = maxsum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        if (sum > maxsum) {
            maxsum = sum;
        }else {
            if (sum < 0) {
                sum = 0;
            }
        }
    }
    return maxsum;
}

int main() {
    int k = 0;
    cin >> k;
    int *arr = new int[k];
    for (int i = 0; i < k; i++) {
        cin >> arr[i];
    }
    cout << MaxSubSeqSum(arr, k);
	
    system("pause");
    return 0;
}
