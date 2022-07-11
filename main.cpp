#include "src/hash_table.hpp"

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