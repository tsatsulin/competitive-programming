#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <cstdint>
using namespace std;

typedef vector<int64_t> Items;

int64_t solution(size_t n, const Items& items) {
    int64_t sum = 0;
    int64_t curr_val = 0;
    for (auto i=0; i<n; ++i) {
        curr_val += (i+1) * items[i];
        sum += items[i];
    }
    
    int64_t res = curr_val;
    
    for (auto i=1; i<n; ++i) {
        int64_t next_val = curr_val - (sum - items[i-1]) + items[i-1] * (n-1);
        curr_val = next_val;
        res = max(res, next_val);
    }
    
    return res;
}

int main() {
    size_t n;
    cin >> n;
    Items items(n);
    for (auto&& item : items)
        cin >> item;
    cout << solution (n, items) << endl;
    return 0;
}
