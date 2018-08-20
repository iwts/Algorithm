#include<iostream>
#define MAX 101000

using namespace std;

int arr[MAX],temp[MAX];
int ans; // 一般情况下是long long

void init(){
    memset(arr,0,sizeof(arr));
    memset(temp,0,sizeof(temp));
    ans = 0;
}

void merge(int l,int r,int m){
    int i = l;
    int j = m + 1;
    int k = l;
    while(i <= m && j <= r){
        if(arr[i] > arr[j]){
            ans += m - i + 1;
            temp[k++] = arr[j++];
        }else{
            temp[k++] = arr[i++];
        }
    }
    while(i<=m) temp[k++] = arr[i++];
    while(j<=r) temp[k++] = arr[j++];
    for(i = l;i<=r;i++) arr[i] = temp[i];
}

void merge_sort(int l,int r){
    if(l < r){
        int m = (l + r) / 2;
        merge_sort(l,m);
        merge_sort(m+1,r);
        merge(l,r,m);
    }
}

int main(){
    int n; // 数据数量
    while(cin >> n){
        init();
        for(int i = 0;i < n;i++){ // 数据是从0开始
            cin >> arr[i];
        }
        merge_sort(0,n-1);
        cout << "ans is : " << ans << endl;
    }

    system("pause");
    return 0;
}
