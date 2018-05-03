/*
这里固定了数组大小，但是核心算法全部在sort()函数中。直接运行即可得到排序后的值。
*/

#include<iostream>
#include<stdlib.h>

using namespace std;

int num[10] = {6,15,3,2,8,4,7,6,16,2};

void my_swap(int a,int b){
    int temp = num[a];
    num[a] = num[b];
    num[b] = temp;
}

void sort(){
    for(int i = 0;i < 9;i++){
        for(int j = i+1;j < 10;j++){
            if(num[i] <= num[j]) continue;
            my_swap(i,j);
        }
    }
}

int main(){
    sort();
    for(int i = 0;i < 9;i++){
        cout << num[i] << " ";
    }
    cout << num[9] << endl;

    system("pause");
    return 0;
}
