// Chinese Remainder Theorem
// Solves systems of congruences. Works for non-coprime moduli.
// Provide congruences as pairs [x |= first (mod second)],
// returns {0, 0} if there is no solution.
// Last Revision: April 2019

#pragma once

#include <vector>
#include <utility>
#include <cstdint>
#include <tuple>
#include "egcd.cpp"

using std::int64_t; using std::uint64_t;
using std::vector;
using std::pair;
using std::tie;

uint64_t umod(int64_t a, int64_t b) { int64_t x = a%b; return x < 0 ? x + b : x; }

pair<uint64_t, uint64_t> crt(vector<pair<uint64_t, uint64_t>> congo)
{
    while(congo.size() > 1)
    {
        uint64_t a1, n1, a2, n2;
        tie(a1, n1) = congo.back(); congo.pop_back();
        tie(a2, n2) = congo.back(); congo.pop_back();

        auto r = egcd(n1, n2);
        uint64_t d = r.d, m = n1 / d * n2;
        uint64_t m1 = umod(r.x, m), m2 = umod(r.y, m);
        if(umod(a1 - a2, d))
            return {0, 0};
        n1 /= d; n2 /= d;
        uint64_t b = (a1*m2%m*n2 + a2*m1%m*n1) % m;

        congo.emplace_back(b, m);
    }
    return congo.back();
}

/*
// Example
#include <iostream>
using std::cout; using std::endl;
int main()
{
    auto p = crt({{1, 3}, {4, 5}, {6, 7}});
    cout << p.first << " (mod " << p.second << ")" << endl;
    auto q = crt({{5, 6}, {3, 8}});
    cout << q.first << " (mod " << q.second << ")" << endl;
    auto r = crt({{2, 6}, {5, 9}, {7, 15}});
    cout << r.first << " (mod " << r.second << ")" << endl;
}
*/
