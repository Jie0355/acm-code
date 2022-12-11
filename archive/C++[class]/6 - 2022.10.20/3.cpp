#include <iostream>
#include <cstring>
using namespace std;
const int M = 110, N = 110;
class Array {
    public:
            Array(int (*_arr)[4], int _lenM, int _lenN) {
                lenM = _lenM + 1, lenN = _lenN;
                memset(A, 0, sizeof A);
                for (int i = 0; i < _lenM; i ++) {
                    for (int j = 0; j < _lenN; j ++) {
                        A[i + 1][j] = _arr[i][j];
                        A[0][j] += _arr[i][j];
                    }
                }
            }
        void Disp() {
            for (int i = 0; i < lenM; i ++) {
                for (int j = 0; j < lenN; j ++) {
                    cout << A[i][j] << " ";
                }
                cout << '\n';
            }
            cout << '\n';
        }
    private:
        int A[M][N];
        int lenM, lenN;
};
int main() {
    int T1[2][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}};
    Array arr1(T1, 2, 4);
    arr1.Disp();
    int T2[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    Array arr2(T2, 3, 4);
    arr2.Disp();
    int T3[1][4] = {{1, 2, 3, 4}};
    Array arr3(T3, 1, 4);
    arr3.Disp();
    return 0;
}