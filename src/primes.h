#include <cmath>

namespace primes {

bool SimpleCompositePrediction(const long long& expectedComposite) {
    return ((expectedComposite * expectedComposite) % 24 != 1);
}

bool IsPrime(const int& expectedPrime) {
    if (SimpleCompositePrediction(expectedPrime)) {
        return false;
    }
    for (int i = 2; i < sqrt(expectedPrime) + 1; ++i) {
        if (expectedPrime % i == 0)
            return false;
    }
    return true;
}

int FindPrime(const int& startNum) {
    for (int i = startNum + (startNum % 2 == 0); ; i += 2) {
        if (IsPrime(i)) {
            return i;
        }
    }
}
}