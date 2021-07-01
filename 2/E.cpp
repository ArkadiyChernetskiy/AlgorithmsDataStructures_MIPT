#include <iostream>
#include <vector>

using namespace std;

void SiftDown(vector <int>& heap, int i, int size) {
    while(2 * i + 1 < size) {
        int left = 2 * i + 1, right = 2 * i + 2, j = left;
        if(right < size && heap[right] > heap[left]) {
            j = right;
        }
        if(heap[i] < heap[j]) {
            swap(heap[i], heap[j]);
            i = j;
        } else {
            break;
        }
    }
}

void SiftUp(vector <int>& heap, int i) {
    while(i && heap[i] >= heap[(i - 1) / 2]) {
        swap(heap[(i - 1) / 2],heap[i]);
        i = (i - 1) / 2;
    }
}

void Insert(vector <int>& heap, int x) {
    heap.push_back(x);
    SiftUp(heap, heap.size() - 1);
}

void HeapSort(vector <int>& heap, int size) {
    for(int i = size - 1; i >= 0; i--) {
        swap(heap[i],heap[0]);
        SiftDown(heap, 0, i);
    }
}

void PrintingAnswers(vector <int>& heap, int heapsize) {
    for(int k=0;k<heapsize;k++){
        cout<<heap[k]<<" ";
    }
} 

int main(){
    vector <int> heap;
    int n, heapsize, elem;
    cin>>n;
    cin>>heapsize;
    for(int i=0; i<heapsize;++i){
        cin>>elem;
        Insert(heap, elem);
    }
    int k;
    for (int i = heapsize; i < n; ++i) {
        cin >> k;
        if (k < heap[0]) {
            heap[0] = k;
            SiftDown(heap, 0, heap.size());
        }
    }
    HeapSort(heap, heap.size());
    PrintingAnswers(heap, heapsize);
    return 0; 
}
