#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int Partition( vector<long int>& arr, int l, int r ) {
    if( l == r ) {
        return l;
    }
    swap( arr[l + rand()%(r-l)], arr[l] );
    int pivot=arr[l];
    int i=r+1;
    int j=r;
    for( ; j > l; j-- ) {
        if( arr[j] >= pivot ) {
            swap( arr[--i], arr[j] );
        }
    }
    swap( arr[--i], arr[l] );
    return i;
}

int StatisticsK( vector<long int>& arr, int k, int l, int r ) {
    while(1) {
        int position = Partition( arr, l, r );
        if (position < k) {
            l = position + 1;
        } else if (position > k) {
            r = position - 1;
        } else {
            return arr[k];
        }
    }
}

int main() {
    int n, k;
    char b;
    cin>>n;
    cin>>k;
    vector<long int> arr;
    long int x;
    for(int i=0; i<n;i++) {
        scanf("%1000ld",&x);
        arr.emplace_back(x);
    }
    cout<<StatisticsK(arr, k, 0, n-1);
    return 0;
}
