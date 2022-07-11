#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <deque>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <map>
#include <chrono>
#include <random>
#include <bitset>
#include <cassert>
#include <functional>
#include <sstream>
#include <thread>
#include <optional>

#include "primes.h"

namespace hash_table {

template <typename K, typename V>
class Node;

template <typename K, typename V>
class Bucket;

template <typename K, typename V>
class HashTable;

template <typename K, typename V>
void PrintBucket(Node<K, V>*);

template <typename K, typename V>
struct Node {
private:
    K key;
    V val;
    Node<K, V>* next;
    friend class Bucket<K, V>;

public:
    Node() = default;

    Node(const K& key_, const V& val_) {
        key = key_;
        val = val_;
        next = nullptr;
    }
};


template <typename K, typename V>
class Bucket {
private:
    Node<K, V>* head;
    int numOfKeys = 0;
    friend class HashTable<K, V>;

    std::pair<K, V> * GetBucket() {
        std::pair<K, V> * bucketInfo = new std::pair<K, V>[numOfKeys];
        int i = 0;
        for (Node<K, V> * cur = head; cur != nullptr; cur = cur->next, ++i) {
            bucketInfo[i] = {cur->key, cur->val};
        }
        return bucketInfo;
    }

public:
    Bucket() {
        head = nullptr;
    }

    bool IsEmpty() const {
        return head == nullptr;
    }

    void PushFront(const K& key, const V& val) {
        Node<K, V>* temp = head;
        head = new Node(key, val);
        head->next = temp;
        ++numOfKeys;
    }

    std::optional<V> Find(const K& key) {
        if (IsEmpty()) return std::nullopt;

        for (Node<K, V> * cur = head; cur != nullptr; cur = cur->next) {
            if (cur->key == key) {
                return cur->val;
            }
        }

        return std::nullopt;
    }

    std::optional<V> Erase(const K& key) {
        if (IsEmpty()) return std::nullopt;

        if (head->key == key) {
            V result = head->val;
            Node<K, V>* old_head = head;
            head = head->next;
            delete old_head;
            --numOfKeys;
            return result;
        }


        for (Node<K, V>* prev = head, * cur = head->next; cur != nullptr; prev = prev->next, cur = cur->next) {
            if (cur->key == key) {
                V result = cur->val;
                prev->next = cur->next;
                delete cur;
                --numOfKeys;
                return result;
            }
        }

        return std::nullopt;
    }


};

template <typename K, typename V>
class HashTable {
private:
    int module;
    int numOfKeys = 0;
    Bucket<K, V> * table;
    std::hash<K> hashGenerator;


public:
    HashTable() {
        module = 1e6 + 3;
        table = new Bucket<K, V>[module];
    }

    explicit HashTable(const int& expectedModule) {
        module = primes::FindPrime(expectedModule);
        table = new Bucket<K, V>[module];
    }

    int hashFunction(const K& key) const {
        return hashGenerator(key) % module;
    }



    std::pair < std::pair<K, V> * , int > GetMas() {
        std::pair<K, V> * tableInfo = new std::pair<K, V>[numOfKeys];
        int i = 0;
        for (int currentBucket = 0; currentBucket < module; ++currentBucket) {
            std::pair<K, V> * curBucketInfo = table[currentBucket].GetBucket(); // !!!!
            for (int j = 0; j < table[currentBucket].numOfKeys; ++j) {
                tableInfo[i++] = curBucketInfo[j];
            }
        }
        return {tableInfo, numOfKeys};
    }


    void Insert0 (const K& key, const V& value) {

        int bucketInd = hashFunction(key);
        table[bucketInd].PushFront(key, value);
        numOfKeys++;
    }

    class iterator {
    private:
        Bucket<K, V> * table;
        int bucketNumber;
        int nodeNumber;
        iterator(Bucket<K, V> * table_, int bucketNumber_, int nodeNumber_) {
            table = table_;
            bucketNumber = bucketNumber_;
            nodeNumber = nodeNumber_;
        }

        std::pair<K, V&> operator *() {

        }
    };

};
}


/*signed main() {
    Bucket<int, int> bucket;
    HashTable<string, int> tabla;
    //cout << tabla.hashFunction("abacaba") << endl;


    tabla.Insert("andsk", 4);
    tabla.Insert("dskl", 1);
    tabla.Insert("fkdlkfd", 439);

    {
        auto [a, b] = tabla.GetMas();
        for (int i = 0; i < b; ++i) {
            cout << a[i] << endl;
        }
    }



    {
        auto [a, b] = tabla.GetMas();
        for (int i = 0; i < b; ++i) {
            cout << a[i] << endl;
        }
    }
    return 0;
}*/
