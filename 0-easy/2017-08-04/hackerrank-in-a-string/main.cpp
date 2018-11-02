#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

bool solution_impl(const string& s)
{
    static const string HACKERRANK = "hackerrank";
    
    if (s.size() < HACKERRANK.size())
        return false;

    auto it1 = HACKERRANK.begin();
    auto it2 = s.begin();
    
    while(it1 != HACKERRANK.end() && it2 != s.end())
    {
        if (*it1 == *it2)
            ++it1;
        ++it2;
    }

    return it1 == HACKERRANK.end();    
}

const char* solution(const string& s)
{
    return solution_impl(s) ? "YES" : "NO";
}

int main() {
    size_t q;
    cin >> q;
    while(q--) {
        string s;
        cin >> s;
        cout << solution(s) << endl;
    }
    return 0;
}
