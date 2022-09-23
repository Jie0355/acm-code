//59.螺旋矩阵Ⅱ
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int startx = 0, starty = 0, offset = 1, i, j;
        int middle = n / 2, loop = n / 2, count = 1;
        //左闭右开
        while (loop --) {
            for (i = startx; i < n + startx - offset; i ++) res[startx][i] = count ++;
            for (j = starty; j < n + starty - offset; j ++) res[j][i] = count ++;
            for (; i > startx; i --) res[j][i] = count ++;
            for (; j > starty; j --) res[j][i] = count ++;
            startx ++; starty ++;
            offset += 2;
        }
        if (n & 1) res[middle][middle] = count ++;
        return res;
    }
};