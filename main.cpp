#include "src/hash_table.hpp"




signed main() {
    hash_table::HashTable<std::string, int> tabla;

    //auto a = tabla.begin();
    int j = 0;

    tabla.Insert("1", 5);
    tabla.Insert("6dsl;", 4);
    tabla.Insert("skl", 123);
    tabla.Insert("fkdlkf", 23829);

    for (auto i : tabla) {
        //std::cout << j++ << std::endl;
        std::cout << i.first << " " << i.second << std::endl;
    }

    return 0;
}