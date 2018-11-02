#ifdef _WIN32
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <functional>
#include <algorithm>
#include <map>
#else
#include <bits/stdc++.h>
#endif

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

class QueryProcessor
{
    using FrequencyMap = std::map<int, int>;

    FrequencyMap num2freq_;
    FrequencyMap freq2num_;

    using Results = vector<int>;

    Results results_;

    void decreaseFreq(int arg)
    {
        if (!freq2num_.count(arg))
            return;

        if (freq2num_[arg] == 1)
        {
            freq2num_.erase(arg);
            return;
        }

        --freq2num_[arg];
    }

    void increaseFreq(int arg)
    {
        if (!freq2num_.count(arg))
        {
            freq2num_[arg] = 1;
            return;
        }

        ++freq2num_[arg];
    }

    void addCmd (int arg)
    {
        if (num2freq_.count(arg))
        {
            decreaseFreq(num2freq_[arg]);
            ++num2freq_[arg];
        }
        else
        {
            num2freq_[arg] = 1;
        }

        increaseFreq(num2freq_[arg]);
    }

    void removeCmd(int arg)
    {
        if (!num2freq_.count(arg))
            return;

        decreaseFreq(num2freq_[arg]);
        --num2freq_[arg];
        
        if (!num2freq_[arg])
        {
            num2freq_.erase(arg);
            return;
        }

        increaseFreq(num2freq_[arg]);
    }

    void getCmd(int arg)
    {
        results_.push_back(freq2num_.count(arg) ? 1 : 0);
    }

public:
    void processQuery(const std::vector<int>& query)
    {
        int cmd = query[0];
        int arg = query[1];

        switch(cmd)
        {
            case 1:
                addCmd(arg);
                break;
            case 2:
                removeCmd(arg);
                break;
            case 3:
                getCmd(arg);
                break;
        }
    }

    const Results& results() const
    {
        return results_;
    }
};

// Complete the freqQuery function below.
vector<int> freqQuery(const vector<vector<int>>& queries) {
    QueryProcessor qp;

    for (auto& q : queries)
        qp.processQuery(q);

    return qp.results();
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    vector<vector<int>> queries(q);

    for (int i = 0; i < q; i++) {
        queries[i].resize(2);

        string queries_row_temp_temp;
        getline(cin, queries_row_temp_temp);

        vector<string> queries_row_temp = split(rtrim(queries_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            int queries_row_item = stoi(queries_row_temp[j]);

            queries[i][j] = queries_row_item;
        }
    }

    vector<int> ans = freqQuery(queries);

    for (int i = 0; i < ans.size(); i++) {
        fout << ans[i];

        if (i != ans.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
