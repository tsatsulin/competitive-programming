#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> Vector;

int maxor(Vector::const_iterator begin, Vector::const_iterator end)
{
    int res = 0;

    for(Vector::const_iterator it = begin; it != end; ++it)
        res ^= *it;

    return res;
}

int main(int /*argc*/, char** /*argv*/)
{
    int N = 0;
    
    cin >> N;

    if (N == 1)
    {
        cout << "0" << endl;
        return 0; 
    }

    Vector items;

    items.reserve(N);

    for (int i=0, item=0; i<N; ++i)
    {
        std::cin >> item;
        items.push_back(item);
    }

    int counter = 0;

    for (int i=0; i<N; ++i)
    {
        int b1 = maxor(items.begin(), next(items.begin(), i));
        for (int j=i+1; j<N; ++j)
        {
            int a = maxor(next(items.begin(), i), next(items.begin(), j));
            int b = b1 ^ maxor(next(items.begin(), j), items.end());
            if (a == b)
                ++counter;
        }
    }

    const int MODULO = 1000000007;
    cout << counter % MODULO << endl;

    return 0;
}