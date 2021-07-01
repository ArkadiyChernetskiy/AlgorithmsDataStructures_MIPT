#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

struct Req {
    string word;
    int val;
};

class HashTable {
public:
    HashTable() {
        table.resize(2000);
        count_degrees();
    }
    int hash_table_insert(int val, const string &word);

private:
    vector<vector<Req>> table;
    vector<unsigned long long> pow;
    void count_degrees();
    unsigned long long hash_evaluate(const string &str);
};

unsigned long long HashTable::hash_evaluate(const string &str) {
    unsigned long long hash = 0;
    for (size_t i = 0; i < str.length(); ++i) {
        hash += (str[i] - 'a' + 1) * pow[i];
    }
    return (hash % 1990) + 1;
}

int HashTable::hash_table_insert(int val, const string &word) {
    unsigned long long index = hash_evaluate(word);
    int flag = -1;
    for (int i = 0; i < table[index].size(); ++i) {
        if (table[index][i].word == word) {
            flag = i;
        }
    }
    if (flag != -1) {
        table[index][flag].val += val;
        return table[index][flag].val;
    } else {
        table[index].push_back({word, val});
        return val;
    }
}

void HashTable::count_degrees() {
    pow.resize(100000);
    pow[0] = 1;
    for (unsigned long long i = 1; i < pow.size(); ++i) {
        pow[i] = pow[i - 1] * 31;
    }
}

int main() {
    HashTable table;
    int val = 0;
    vector<Req> values;
    string str_req;
    
    while (cin >> str_req) {
        cin >> val;
        values.push_back({str_req, val});
    }
    
    for (auto &value : values) {
        cout << table.hash_table_insert(value.val, value.word) << endl;
    }
    return 0;
}
