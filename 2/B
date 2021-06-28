#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void CountCoverage(vector<pair<long int, bool>> &arr) {
    int layers = 0;
    int len = 0;
    for(int i=0; i<arr.size(); ++i) {
        if( arr[i].second == 0) {
            if(layers ==1){
                len += arr[i].first-arr[i-1].first;
            }
            ++layers;
        } else {
            if(layers ==1) {
                len += arr[i].first-arr[i-1].first;
            }
            --layers;
        }
    }
    cout << len;
}

void Input(vector<pair<long int, bool>>& arr) {
    int N;
    cin >> N;
    long int x;
    for(int i = 0; i < N; ++i) {
        cin >> x;
        arr.emplace_back(x, 0);
        cin >> x;
        arr.emplace_back(x, 1);
    }

}

int main() {
    vector<pair<long int, bool>> arr;
    Input(arr);
    sort(arr.begin(), arr.end(),
         [](const std::pair<long int, bool> &p1, const std::pair<long int, bool> &p2) {
             if (p2.first > p1.first) {
                 return true;
             } else {
                 return p2.first >= p1.first && p1.first > p2.first;
             }
         });
    CountCoverage(arr);
    return 0;
}
