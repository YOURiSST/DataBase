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



template <typename T1, typename T2>
std::ostream& operator << (std::ostream& out, std::pair<T1, T2> p) {
    out << '{' << p.first << ", " << p.second << '}';
    return out;
}

signed main() {
    hash_table::HashTable<int, int> myTable;
    {
        std::cout << myTable.Info() << std::endl;
    }

    myTable.Insert(1, 5);
    myTable.Insert(3, 5);
    myTable.Insert(-25, -129);
    myTable.Insert(2, 1);
    myTable.Insert(-32, 1);
    myTable.Insert(20, 29302);

    {
        std::cout << "\n=================\n\n";
        std::cout << myTable.Info() << std::endl;
        std::cout << "\n------------------\n\n";
        for (auto i : myTable) {
            std::cout << i << "\n";
        }
        std::cout << "\n------------------\n\n";
    }


    myTable.Erase(-32);
    {
        std::cout << "\n=================\n\n";
        std::cout << myTable.Info() << std::endl;
        std::cout << "\n------------------\n\n";
        for (auto i : myTable) {
            std::cout << i << "\n";
        }
        std::cout << "\n------------------\n\n";
    }

    //myTable.FastCheck(-1);

    return 0;
}