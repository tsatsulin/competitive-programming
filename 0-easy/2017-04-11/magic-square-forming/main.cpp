#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

const int ALL_MAGIC_SQUARES_COUNT = 8;
const int N = 3;

const int ALL_MAGIC_SQUARES[ALL_MAGIC_SQUARES_COUNT][N][N] = {
    {{8, 1, 6}, {3, 5, 7}, {4, 9, 2}},
    {{6, 1, 8}, {7, 5, 3}, {2, 9, 4}},
    {{4, 9, 2}, {3, 5, 7}, {8, 1, 6}},
    {{2, 9, 4}, {7, 5, 3}, {6, 1, 8}}, 
    {{8, 3, 4}, {1, 5, 9}, {6, 7, 2}},
    {{4, 3, 8}, {9, 5, 1}, {2, 7, 6}}, 
    {{6, 7, 2}, {1, 5, 9}, {8, 3, 4}}, 
    {{2, 7, 6}, {9, 5, 1}, {4, 3, 8}},
};



int main() {
    int array[N][N];
    for (auto i = 0; i < N; ++i) {
        for (auto j = 0; j < N; ++j) {
            cin >> array[i][j];
        }
    }

    int cost = 1000;
    for (auto k=0; k<ALL_MAGIC_SQUARES_COUNT; ++k) {
        int current_cost = 0;
        for (auto i = 0; i < N; ++i) {
            for (auto j = 0; j < N; ++j) {
                current_cost += abs(ALL_MAGIC_SQUARES[k][i][j] - array[i][j]);
            }
        }
        cost = min(cost, current_cost);
    }

    cout << cost << endl;

    return 0;
}
