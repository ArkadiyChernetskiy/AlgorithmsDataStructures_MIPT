#include <iostream>
#include <vector>

using namespace std;

struct NumReq {
    long long first; //численное значение
    long long second; //на каком шаге было добавлено значение
    
    NumReq (long long a, long long b) { 
        this->first = a;
        this->second = b;
    }
};

void SiftUp(vector <NumReq>& heap, long long i) {
    while(i!=0 && heap[i].first < heap[(i - 1) / 2].first) {
        swap(heap[(i - 1) / 2].first,heap[i].first);
        swap(heap[(i - 1) / 2].second,heap[i].second);
        i = (i - 1) / 2;
    }
}

void SiftDown(vector <NumReq>& heap, long long i) {
    while(2 * i + 1 < heap.size()) {
        long long left = 2 * i + 1, right = 2 * i + 2, j = left;
        if(right < heap.size() && heap[right].first < heap[left].first) {
            j = right;
        }
        if(heap[i].first < heap[j].first) {
            return;
        } else {
            swap(heap[i].first, heap[j].first);
            swap(heap[i].second, heap[j].second);
            i = j;
        }
    }
}

void Insert(vector <NumReq>& heap, long long x, int counter) {
    heap.push_back(NumReq(x,counter));
    SiftUp(heap, heap.size() - 1);
}

void GetMin(vector <NumReq>& heap){
    cout<<heap[0].first<<'\n';
}

void ExtractMin(vector <NumReq>& heap){
    swap(heap[heap.size()-1].first,heap[0].first);
    swap(heap[heap.size()-1].second,heap[0].second);
    heap.erase(heap.end());
    SiftDown(heap, 0);
}

void DecreaseKey(vector <NumReq>& heap,long long delta, long long num){
    int k;
    for(int i=0; i< heap.size(); i++) {
        if(num==heap[i].second) {
            k=i;
            break;
        }
    }
    heap[k].first-=delta;
    SiftUp(heap,k);
}

void ProcessCommands() {
    vector <NumReq> heap;
    long long HeapSize;
    string str;
    cin>>HeapSize;
    long long num,m, delta;
    long long counter=0;
    for(long long i=0; i<HeapSize;i++) {
        cin >> str;
        if(str=="getMin"){
            counter++;
            GetMin(heap);
        } else if(str=="extractMin") {
            counter++;
            ExtractMin(heap);
        } else if(str=="decreaseKey") {
            counter++;
            cin >> num >> delta;
            DecreaseKey( heap,delta, num);
        } else if(str=="insert"){
            counter++;
            cin >> m;
            Insert(heap, m, counter);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ProcessCommands();
    return 0;
}
