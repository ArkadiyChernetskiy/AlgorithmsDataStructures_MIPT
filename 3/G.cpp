#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

struct zapravka {
    int y1 = 0, y2 = 0, x  = 0;
};

bool cmp_zapravki_in (const zapravka &a, const zapravka &b) {
    if (a.y1 < b.y1)
        return true;
    if (a.y1 > b.y1)
        return false;
    if (a.y2 < b.y2)
        return true;
    if (a.y2 > b.y2)
        return false;
    return a.x < b.x;
}

bool cmp_zapravki_out (const zapravka &a, const zapravka &b) {
    if (a.y2 < b.y2)
        return true;
    if (a.y2 > b.y2)
        return false;
    if (a.y1 < b.y1)
        return true;
    if (a.y1 > b.y1)
        return false;
    return a.x < b.x;
}

void insert_trasa_zap (set<pair<int, int>> &trasa, set<pair<int, int>> &r_trasa, int x){
    auto r = trasa.upper_bound({x, 0}), l = r;
    l--;
    pair<int, int> rp = *r, lp = *l;
    
    if (trasa.upper_bound(rp) == trasa.end()) {
        rp.second = rp.first - x;
    } else {
        rp.second = max(rp.first - x, (*trasa.upper_bound(rp)).first - rp.first);
    }
    
    if (trasa.lower_bound(lp) == trasa.begin()) {
        lp.second = x - lp.first;
    } else {
        lp.second = max(x - lp.first, lp.first - (*(--trasa.lower_bound(lp))).first);
    }
    
    auto rp_old = *r, lp_old = *l;
    
    trasa.erase(lp_old);
    trasa.erase(rp_old);

    r_trasa.erase({lp_old.second, lp_old.first});
    r_trasa.erase({rp_old.second, rp_old.first});

    trasa.insert(lp);
    trasa.insert(rp);

    r_trasa.insert({lp.second, lp.first});
    r_trasa.insert({rp.second, rp.first});

    trasa.insert({x, max(x - lp.first, rp.first - x)});
    r_trasa.insert({max(x - lp.first, rp.first - x), x});
}

void delete_trasa_zap (set<pair<int, int>> &trasa, set<pair<int, int>> &r_trasa, int x) {

    pair<int, int> xp = *trasa.lower_bound({x, 0});
    trasa.erase(xp);
    r_trasa.erase({xp.second, xp.first});

    auto r = trasa.upper_bound({x, 0}), l = r;
    l--;

    pair<int, int> rp = *r, lp = *l;

    if (trasa.upper_bound(rp) == trasa.end()) {
        rp.second = rp.first - lp.first;
    } else {
        rp.second = max(rp.first - lp.first, (*trasa.upper_bound(rp)).first - rp.first);
    }

    if (trasa.lower_bound(lp) == trasa.begin()) {
        lp.second = rp.first - lp.first;
    } else {
        lp.second = max(rp.first - lp.first, lp.first - (*(--trasa.lower_bound(lp))).first);
    }

    auto rp_old = *r, lp_old = *l;

    trasa.erase(rp_old);
    trasa.erase(lp_old);

    r_trasa.erase({rp_old.second, rp_old.first});
    r_trasa.erase({lp_old.second, lp_old.first});

    trasa.insert(lp);
    trasa.insert(rp);

    r_trasa.insert({lp.second, lp.first});
    r_trasa.insert({rp.second, rp.first});
}

int main () {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, X, Y;

    cin >> n >> Y >> X;

    vector<zapravka> zapravki_in(n), zapravki_out(n);

    for (int i = 0; i < n; ++i) {
        int x, y1, y2;
        cin >> x >> y1 >> y2;
        zapravki_in[i] = {y1, y2, x};
        zapravki_out[i] = {y1, y2, x};
    }

    sort(zapravki_in.begin(), zapravki_in.end(), cmp_zapravki_in);
    sort(zapravki_out.begin(), zapravki_out.end(), cmp_zapravki_out);

    reverse(zapravki_in.begin(), zapravki_in.end());
    reverse(zapravki_out.begin(), zapravki_out.end());

    vector<int> trasa_info(X + 1, 0);
    set<pair<int, int>> trasa   = {{0, X}, {X, X}};
    set<pair<int, int>> r_trasa = {{X, 0}, {X, X}};

    for (int i = 0; i <= Y; ++i) {
        while (!zapravki_in.empty() && i >= zapravki_in.back().y1) {
            if (trasa_info[zapravki_in.back().x] == 0) {
                insert_trasa_zap(trasa, r_trasa, zapravki_in.back().x);
            }
            trasa_info[zapravki_in.back().x]++;
            zapravki_in.pop_back();
        }

        cout << (*r_trasa.rbegin()).first << "\n";

        while (!zapravki_out.empty() && i >= zapravki_out.back().y2) {
            trasa_info[zapravki_out.back().x]--;
            if (trasa_info[zapravki_out.back().x] == 0) {
                delete_trasa_zap(trasa, r_trasa, zapravki_out.back().x);
            }
            zapravki_out.pop_back();
        }
    }
    return 0;
}
