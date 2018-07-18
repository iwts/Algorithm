// 详细的图可自行构造

#include<iostream>
#include<string>
#define MAX 233
#define INF 0x3f3f3f3f

using namespace std;

int T[MAX],dis[MAX];
int vec[MAX][MAX];
int begins;
string road[MAX];

void test_print_dis(){
    for(int i = 1;i <= 6;i++){
        cout << dis[i] << " ";
    }
    cout << endl;
}

void test_print_road(){
    for(int i = 1;i <= 6;i++){
        cout << "v" << i << " road is : " << road[i] << endl;
    }
}

void init(){
    memset(T,0,sizeof(T));
    memset(dis,0,sizeof(dis));
    memset(vec,0,sizeof(vec));
    begins = 1; // 源点，应由键盘读入或传参进入该函数
    // 构造边，实际上应该从键盘读取，这里直接把图写入了。实际应用需要修改
    vec[1][3] = 10;
    vec[1][5] = 30;
    vec[1][6] = 100;
    vec[2][3] = 5;
    vec[3][4] = 50;
    vec[4][6] = 10;
    vec[5][4] = 20;
    vec[5][6] = 60;
    for(int i = 1;i <= 6;i++){
        road[i] = "no road";
        if(vec[begins][i] == 0){ 
            dis[i] = INF;
            continue;
        }
        dis[i] = vec[begins][i];
        road[i] = "v1->v"+to_string(i);
        road[begins] = "v"+to_string(begins);
    }
    dis[0] = INF; // dijkstra第一次运行时作为比较使用
    dis[begins] = 0;
    T[begins] = 1;
}

void dijkstra(){
    int step = 1;
    while(step != 6){
        int min = 0; // init()函数中已定义，dis[0]=INF
        for(int i = 1;i <= 6;i++){
            if(T[i] == 1) continue;
            if(dis[min] < dis[i]) continue;
            min = i;
        }
        T[min] = 1; // 必定存在最小值，所有点都被遍历的情况下已经出while循环了
        step++;
        for(int i = 1;i <= 6;i++){
            if(vec[min][i] == 0) continue;
            if (dis[i] == 0) continue;
            if (dis[i] < vec[min][i] + dis[min]) continue;
            dis[i] = vec[min][i] + dis[min];
            road[i] = road[min]+"->v"+to_string(i);
        }
        test_print_dis();
    }
    test_print_road();
}

int main() {
    init();
    dijkstra();

    system("pause");
    return 0;
}
