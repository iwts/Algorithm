/*
二分查找，注意：
1.low与height的变化，如果实际值大于key，那么low = key+1，因为key一定不正确，height值变化亦然。
2.while循环的跳出，low <= height，low与height可以相等，例如下例查找“5”

这里只是给出一个例子，数组已经确定了。
*/

#include<iostream>

using namespace std;

int num[10] = { 1,2,3,4,5,6,7,8,9,10 };

int binary_search(int n) {
    int low = 0;
    int height = 9;
    int key = 5;
    while (low <= height) {
        if (num[key] == n) return key;
        if (num[key] < n) {
            low = key + 1;
            key = (height + low) / 2;
        }else {
            height = key - 1;
            key = (height + low) / 2;
        }
    }
    return -1;
}

int main() {
    int n;
    cin >> n;
    int ans = binary_search(n);
    if (ans == -1) {
        cout << "not found!" << endl;
    }else {
        cout << "the key is " << ans << endl;
    }

    system("pause");
    return 0;
}
