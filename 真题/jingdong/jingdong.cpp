#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct car {
    long long x;
    long long v;
    car(long long p,long long s):x(p),v(s){}
};


long long findMinRemove(vector<long long>& x, vector<long long>& v ) {
    long long n = x.size();
    vector<car> cars;
    for (long long i = 0; i < n; i++) {
        cars.emplace_back(x[i], v[i]);
    }

    sort(cars.begin(), cars.end(), [](const car& a, const car& b) {
        return a.x < b.x;
    });

    vector<long long> seq;

    for (const car& car : cars) {
        if (seq.empty() || seq.back() <= car.v) {
            seq.push_back(car.v);
        } else {
            auto it = lower_bound(seq.begin(), seq.end(), car.v);
            *it = car.v;
        }
    }
    return n - seq.size();
}

int main() {
    long long n;
    cin >> n;
    vector<long long> xarr;
    vector<long long> varr;

    for (long long i = 0; i < n; i++) {
        long long x, v;
        cin >> x;
        cin >> v;
        xarr.push_back(x);
        varr.push_back(v);
    }
    cout << findMinRemove(xarr, varr);

    return 0;
}