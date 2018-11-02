#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

void remove_duplicate_characters(string& s)
{
    if (1 >= s.size())
        return;

    auto start = s.begin();
    auto end = start + 1;

    while (end != s.end())
    {
        while(end != s.end() && *start == *end)
        {
            s.erase(end);
            end = start + 1;
        };
        if (end == s.end())
            break;
        start = end++;
    }
}

int main(int argc, char** argv)
{
    string s;
    getline(cin, s);
    remove_duplicate_characters(s);
    cout << s << endl;

    return EXIT_SUCCESS;
}