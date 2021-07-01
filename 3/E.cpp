#include <iostream>
#include <map>
#include <set>

using namespace std;

class Set{
public:
    void deleteMeth(long long element, long long set){
        del(element,set);
    };
    void clearMeth(long long set){
        clear(set);
    };
    void listsetMeth(long long set){
        listset(set);
    };
    void addMeth(long long element, long long set){
        add(element, set);
    };
    void listsetofMeth(long long element){
        listsetof(element);
    };
private:
    map<long long, set<long long>> set_values;
    map<long long, set<long long>> value_sets;
    void listset(long long set);
    void listsetof(long long element);
    static void print(map<long long, set<long long>> &map, long long number);
    void clear(long long set);
    void add(long long element, long long set);
    void del(long long element, long long set);
};

void Set::del(long long int element, long long int set) {
    set_values[set].erase(set_values[set].find(element));
    value_sets[element].erase(value_sets[element].find(set));
}

void Set::add(long long int element, long long int set) {
    set_values[set].insert(element);
    value_sets[element].insert(set);
}

void Set::clear(long long int set) {
    for (auto i : set_values[set]) {
        value_sets[i].erase(value_sets[i].find(set));
    }
    set_values[set].clear();
}

void Set::print(map<long long int, set<long long int>> &map, long long int number) {
    if (map[number].empty()) {
        cout << -1 << endl;
        return;
    }
    for (auto i : map[number]) {
        cout << i << ' ';
    }
    cout << endl;
}

void Set::listsetof(long long int element) {
    print(value_sets, element);
}

void Set::listset(long long int set) {
    print(set_values, set);
}

int main() {
    long long n, m, k;
    Set obj;
    cin >> n >>m >> k;
    for ( long long i = 0; i < k; ++i) {
        string operation;
        long long element, set;
        cin >> operation;
        if (operation == "ADD") {
            cin >> element >> set;
            obj.addMeth(element, set);
        } else if (operation == "LISTSET") {
            cin >> set;
            obj.listsetMeth(set);
        } else if  (operation == "LISTSETSOF") {
            cin >> element;
            obj.listsetofMeth(element);
        } else if (operation == "CLEAR"){
            cin >> set;
            obj.clearMeth(set);
        } else if (operation == "DELETE"){
            cin >> element >> set;
            obj.deleteMeth(element, set);
        }
    }
}
