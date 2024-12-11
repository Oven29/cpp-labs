#include "RSA.h"

#include <cmath>

namespace {

long Power(long base, long exp, long mod) {
    long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp = exp >> 1;  // Делим exp на 2
    }
    return result;
}

int GetGreatestCommonDivisor(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }

    return a;
}

}  // namespace

namespace RSA {

int GetD(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1) {
            return x;
        }
    }

    return -1;
}

int GetN(int p, int q) {
    return p * q;
}

int GetPhi(int p, int q) {
    return (p - 1) * (q - 1);
}

int GetE(int phi) {
    int e = 3;
    while (GetGreatestCommonDivisor(e, phi) != 1) {
        e += 2;
    }

    return e;
}

long Encode(long message, long e, long n) {
    return Power(message, e, n);
}

long Decode(long message, long d, long n) {
    return Power(message, d, n);
}

}  // namespace RSA
