// 图可自行构造

#include<iostream>
#include<string>
#include<queue>
#define TIME std::ios::sync_with_stdio(false)
#define MAX 233
#define INF 0x3f3f3f3f

using namespace std;

int dis[MAX];
int vec[MAX][MAX];
int begins;
string road[MAX];

struct dis_node{
    int dis,value; // dis与value组成一个二元组，可以利用pair
    bool operator < (const dis_node& disn) const { // 重载操作符，用于优先队列
        return value < disn.value;
    }
};

priority_queue<dis_node> pq;

void test_print_road(){
    for(int i = 1;i <= 6;i++){
        cout << "v" << i << " road is : " << road[i];
        cout << "   value is :" << dis[i] << endl;
    }
}

void init(){
    memset(dis,0,sizeof(dis));
    memset(vec,0,sizeof(vec));
    while(!pq.empty()){
        pq.pop();
    }
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
    dis[begins] = 0;
    for(int i = 1;i <= 6;i++){ // 将原来的dis整合后封装成对象进入优先队列，可以在前面的for循环中执行
        dis_node disn;
        disn.dis = i;
        disn.value = dis[i];
        pq.push(disn);
    }
}

void dijkstra(){
    pq.pop(); // 将源点抛出
    while(!pq.empty()){
        dis_node dis_min = pq.top();
        pq.pop();
        int n_dis = dis_min.dis;
        int n_value = dis_min.value;
        if(n_value > dis[n_dis]) continue; // 由于队列是不断加入的，要把权值大的点删除
        for(int i = 1;i <= 6;i++){
            if(vec[n_dis][i] == 0) continue;
            if(dis[i] < n_value+vec[n_dis][i]) continue;
            dis[i] = n_value+vec[n_dis][i];
            dis_node new_node; // 最重要的一步，优先队列无法使用更新，那就把更新的点再加入到队列中
            new_node.dis = n_dis;
            new_node.value = dis[i];
            pq.push(new_node);
            road[i] = road[n_dis]+"->v"+to_string(i);
        }
    }
    test_print_road();
}

int main() {
    TIME;
    init();
    dijkstra();

    system("pause");
    return 0;
}
