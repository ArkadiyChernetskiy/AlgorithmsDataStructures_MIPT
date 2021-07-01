#include <iostream>
#include <vector>
#include <set>
using namespace std;

int countingMomsMotions(int n, int k, int p,vector<int>& last, vector<int>& cars, vector<int>& next ){
    int counter =0;
    for(int i=0;i<p;++i) {
        if (last[cars[i]] == 1e9) {
            last[cars[i]] = i;
        }
        else {
            next[last[cars[i]]]=i;
            last[cars[i]] = i;
        }
    }
    vector <bool> isUse(n);
    for(int i=0;i<n;++i) {
        isUse[i]=false;
    }
    set <pair<int,int>> carPairs;
    for(int i=0;i<p;++i) {
        if (!isUse[cars[i]]) {
            if (carPairs.size()==k){
                pair<int, int> helpPair = *carPairs.begin();
                isUse[helpPair.second] = false;
                carPairs.erase(carPairs.begin());
            }
            carPairs.insert({-next[i], cars[i]});
            isUse[cars[i]] = true;
            ++counter;
        } else {
            carPairs.erase({-i,cars[i]});
            carPairs.insert({-next[i], cars[i]});
        }
    }
    return counter;
}

int main(){
    int n,k,p;
    cin>>n>>k>>p;
    vector<int> cars(p);
    vector<int> last(n); //l=n
    vector<int> next(p); //l=p
    set<pair<int, int>> isUsed;
    for(int i=0; i<p ;++i){
        next[i] = 1e9;
        cin>>cars[i];
        --cars[i];
    }
    for(int i=0; i<n ;++i){
        last[i] = 1e9;
    }
    cout<<countingMomsMotions(n, k,p,last,cars,next);
    return 0;
}
