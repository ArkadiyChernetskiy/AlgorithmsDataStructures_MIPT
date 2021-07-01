#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const unsigned int num_of_bytes = 8;
const unsigned long long max_val = pow(2, num_of_bytes);
const unsigned long long mask = max_val-1;

int find_byte (long long val, const int pos) {

    return val >> num_of_bytes * pos & mask;

}

void lsd_sort (vector <long long> &arr, const unsigned int size) {

    vector <long long> help_arr(size);

    for (int i = 0; i < num_of_bytes; ++i) {

        vector <long long> arr_copy(max_val);

        for (int j = 0; j < help_arr.size(); ++j) {
            long long val = arr[j];
            ++arr_copy[find_byte(val, i)];
        }

        int count = 0;

        for (long long & j : arr_copy) {
            int t = count;
            count += j;
            j = t;
        }

        for (int j = 0; j < help_arr.size(); ++j) {
            long long val = arr[j];
            help_arr[arr_copy[find_byte(val, i)]++] = arr[j];
        }

        arr = help_arr;
    }
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    unsigned int n = 0;
    cin >> n;
    vector <long long> arr(n);

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    lsd_sort(arr, n);

    for (const auto &i: arr) {
        cout << i << ' ';
    }

    return 0;
}
