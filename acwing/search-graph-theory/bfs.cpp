//844.走迷宫
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;

const int N = 1e2 + 10;

int n, m;
//存储图信息(1/0) 点(i, j)离初始点的距离
int Gph[N][N], dis[N][N];

int BFS() {
    int head = 0, tail = 0, x, y;
    int tx[4] = {-1, 0, 1, 0}, ty[4] = {0, 1, 0, -1}; //数组模拟向量 左上右下顺序搜索
    PII queue[N * N], tmp; //对类型数组模拟队列
    memset(dis, -1, sizeof(dis)); //初始化dis数组为-1 - 未走过
    dis[0][0] = 0;
    queue[tail ++] = {0, 0};
    while (head != tail) { //队不为空
        tmp = queue[head ++]; //取出队头元素
        for (int i = 0; i < 4; i ++) {
            x = tmp.first + tx[i], y = tmp.second + ty[i];
            //点位于图内 未经过 可走
            if (x >= 0 && x < n && y >= 0 && y < m && dis[x][y] == -1 && Gph[x][y] == 0) {
                queue[tail ++] = {x, y}; //入队列
                dis[x][y] = dis[tmp.first][tmp.second] + 1;
            }
        }
    }
    return dis[n - 1][m - 1]; //返回右下值
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i ++)
        for (int j = 0; j < m; j ++)
            cin >> Gph[i][j];
    cout << BFS();
    return 0;
}

//845.八数码
#include <bits/stdc++.h>
using namespace std;

int BFS(string start) {
    //数组模拟向量 左上右下顺序搜索
    int tx[4] = {-1, 0, 1, 0}, ty[4] = {0, 1, 0, -1};
    queue<string> q;
    string end = "12345678x"; //期望状态
    unordered_map<string, int> dis; //状态+初始状态转换至当前状态所需的最短步长
    q.push(start);
    dis[start] = 0;
    while (q.size()) { //队列不为空
        string tmp = q.front();
        q.pop();
        if (tmp == end) return dis[tmp]; //到达期望状态 存在解决方案 返回步长 此时最短
        int distance = dis[tmp]; //记录当前状态步长
        int spot = tmp.find('x');
        int x = spot / 3, y = spot % 3; //一维转二维坐标
        for (int i = 0; i < 4; i ++) {
            int xx = x + tx[i], yy = y + ty[i];
            if (xx >= 0 && xx < 3 && yy >= 0 && yy < 3) { //图内
                swap(tmp[spot], tmp[xx * 3 + yy]);
                if (!dis.count(tmp)) { //该状态被第一次搜索到
                    dis[tmp] = distance + 1;
                    q.push(tmp);
                }
                swap(tmp[spot], tmp[xx * 3 + yy]);
            }
        }
    }
    return -1; //不存在解决方案
}

int main() {
    char op[2];
    string start;
    for (int i = 0; i < 9; i ++) {
        cin >> op;
        start += *op;
    }
    cout << BFS(start);
    return 0;
}