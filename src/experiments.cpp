#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

void at_home(bool is_true) {
    if (is_true) {
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    }
}



void print_ft(int& a) {
    a++;
}

template <typename T>
ostream &operator << (ostream& s, const vector<T> a) {
    for (auto & i : a) {
        s << i << " ";
    }
    s << endl;
    return s;
}

const long long HASH = 1e9 + 7;

long long isprime(long long num)
{

    if ((num * num) % 24 == 1)
    {
        return true;
    }

    return false;

}

template <typename T>
std::hash<T> hash_generator;

signed main() {
    at_home(true);



    cout << hash_generator<string>("abacaba") % HASH << endl;



    return 0;
}