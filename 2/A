#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void BubleSort(vector<string>& array) {
    for (int i = 0; i < array.size(); i++) {
        for (int j = 0; j < array.size()-1; j++) {
            string s1 = array[j]+array[j + 1];
            string s2 = array[j + 1]+array[j];
            if (s1 < s2) {
                string b = array[j];
                array[j] = array[j + 1];
                array[j + 1] = b;
            }
        }
    }
}

int main() {
    vector <string> array;
    ifstream input;
    input.open("number.in");
    ofstream output;
    string c;
    output.open("number.out");
    while (getline(input, c)) {
        array.push_back(c);
    }
    BubleSort(array);
    cout<<array[0];
    for (auto & i : array) {
        output << i;
    }
    input.close();
    output.close();
    return 0;
}
