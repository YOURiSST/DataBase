#include <algorithm>
#include <fstream>
#include "src/hash_table.hpp"

hash_table::HashTable<std::string, long long> table;
std::string FAQ = "FAQ";
std::string EXIT = "EXIT";
std::string ADD = "ADD";
std::string GET = "GET";
std::string ERASE = "ERASE";
std::string INC = "INC";
std::string CHG = "CHG";
std::string YES = "Y";
std::string NO = "N";

void faq() {
    std::cout << "======================================================================\n"
                 "currently working in a string-integer mode\n"
                 "Choose an action\n"
                 "To enter a FAQ mode choose FAQ\n"
                 "To add a value to a DataBase choose ADD, and enter a key-value pair\n"
                 "To get a value by key choose GET and enter a key\n"
                 "To erase a value by key choose ERASE and enter a key\n"
                 "To increment a value by key choose INC and enter a key, than enter a delta\n"
                 "To change a value by key choose CHG and enter a key, than enter a new value\n"
                 "To terminate operations choose EXIT\n"
                 "======================================================================\n";

}

void dump() {
    std::fstream outStream;
    outStream.open("TableInfo.dat", std::fstream::out);
/*    if (!outStream.is_open()) {
        std::cout << "An error occured while opening the file\n";
        return;
    }*/
    for (auto  [key, value] : table) {
        outStream << key << " " << value << std::endl;
    }

    std::cout << "Move your .dat file to a secure place. It is temporary";
}

void bye() {
    std::string answer;
    std::cout << "Wanna dump your Base? y - yes, n - no\n";
    std::cin >> answer;
    std::transform(answer.begin(), answer.end(), answer.begin(), toupper);
    if (answer == YES) {
        dump();
    }
    std::cout << "Bye!\n";
    exit(0);
}



void operate(const std::string& question) {
    std::string key;
    long long value;
    long long delta;
    long long newValue;

    if (question == FAQ) {
        faq();
    } else if (question == EXIT) {
        bye();
    } else if (question == GET) {
        std::cin >> key;
        try {
            auto getValue = table.Get(key);
            std::cout << "You got a {" << key << ", " << getValue << "} pair\n";

        } catch (std::invalid_argument& e) {
            std::cout << e.what() << std::endl;
        }
    } else if (question == ADD) {
        std::cin >> key;
        std::cin >> value;

        try {
            table.Insert(key, value);
            std::cout << "You added a {" << key << ", " << value << "} pair\n";

        } catch (std::logic_error& e) {
            std::cout << e.what() << std::endl;
        }
    } else if (question == ERASE) {
        std::cin >> key;
        try {
            auto erasedVal = table.Erase(key);
            std::cout << "You erased a {" << key << ", " << erasedVal << "} pair\n";
        } catch (std::invalid_argument& e) {
            std::cout << e.what() << std::endl;
        }
    } else if (question == INC) {
        std::cin >> key;
        std::cin >> delta;
        try {
            auto& getValue = table.Get(key);
            std::cout << "You made an {" << key << ", " << getValue << "} -> {" <<
                                            key << ", " << getValue + delta << "} operation\n";
            getValue += delta;
        } catch (std::invalid_argument& e) {
            std::cout << e.what() << std::endl;
        }
    } else if (question == CHG) {
        std::cin >> key;
        std::cin >> newValue;
        try {
            auto& getValue = table.Get(key);
            std::cout << "You made an {" << key << ", " << getValue << "} -> {" <<
                      key << ", " << newValue << "} operation\n";
            getValue = newValue;
        } catch (std::invalid_argument& e) {
            std::cout << e.what() << std::endl;
        }
    } else {
        std::cout << "You entered something strange. To get help, enter a FAQ\n" << question << std::endl;

    }
}


signed main() {
    std::vector<int> a = {1, 5, 2, 3, 5, 2};
    faq();
    while (true) {
        std::string question; std::cin >> question;

        std::transform(question.begin(), question.end(), question.begin(), toupper);
        operate(question);
    }
}