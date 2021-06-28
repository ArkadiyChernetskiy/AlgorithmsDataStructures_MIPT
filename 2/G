#include <iostream>
#include <vector>
#define ll long long
using namespace std;

struct NumReq {
    ll first;
    ll second;
    NumReq (ll a, ll b) {
        this->first = a;
        this->second = b;
    }
};

void siftDown(vector <NumReq>& heap, unsigned long long i) {
    while(2 * i + 1 < heap.size()) {
        unsigned long long left = 2 * i + 1, right = 2 * i + 2, j = left;
        if(right < heap.size() && heap[right].first < heap[left].first) {
            j = right;
        }
        if (heap[i].first < heap[j].first) {
            return;
        } else {
            swap(heap[i].first, heap[j].first);
            swap(heap[i].second, heap[j].second);
            i = j;
        }
    }
}

void siftUp(vector <NumReq>& heap, unsigned long long i) {
    while(i!=0 && heap[i].first < heap[(i - 1) / 2].first) {
        swap(heap[(i - 1) / 2].first,heap[i].first);
        swap(heap[(i - 1) / 2].second,heap[i].second);
        i = (i - 1) / 2;
    }
}

void insert( vector <NumReq>& heapMin, vector <NumReq>& heapMax, ll val, ll req) {
    heapMin.emplace_back(val, req);
    heapMax.emplace_back(-val, req);
    siftUp(heapMin, heapMin.size() - 1);
    siftUp(heapMax, heapMax.size() - 1);
}

void extractMin(vector <NumReq>& heap) {
    swap(heap[heap.size() - 1].first, heap[0].first);
    swap(heap[heap.size() - 1].second, heap[0].second);
    heap.erase(heap.end());
    siftDown(heap, 0);
}

void extractMin_stupid(vector <bool>& del,vector <NumReq>& heap_min, vector <NumReq>& heap_max) {
    while(del[heap_min[0].second]==1 && heap_min.size()!=0){
        extractMin(heap_min);
    }
    del[heap_min[0].second]=1;
    cout<<heap_min[0].first<<endl;
    extractMin(heap_min);
}

void extractMax_stupid(vector <bool>& del,vector <NumReq>& heap_min, vector <NumReq>& heap_max) {
    while(del[abs(heap_min[0].second)]==1 && heap_min.size()!=0){
        extractMin(heap_min);
    }
    del[abs(heap_min[0].second)]=1;
    cout<<abs(heap_min[0].first)<<endl;
    extractMin(heap_min);
}

int main() {
    vector <NumReq> heap_min;
    vector <NumReq> heap_max;
    ll n; cin>>n;
    vector <bool> del(n);
    string command;
    for(int i = 0; i<n; ++i) {
        cin>>command;
        if(command == "GetMin"){
            extractMin_stupid(del, heap_min,heap_max);
        } else if(command == "GetMax") {
            extractMax_stupid(del,heap_max,heap_min);
        } else {
            command.erase(0,7);
            command.erase(command.find(')'), 1);
            ll x = 0;
            for(char j : command) {
                x*=10;
                x+= int(j) - int('0');
            }
            insert(heap_min, heap_max, x, i);
        }
    }
    return 0;
}
