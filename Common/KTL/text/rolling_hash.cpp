// Rolling hashes, modulo is functor-based for tricks usage.
// (e.g. Mersenne prime modulo, overflow modulo)
// Also template-based double hashes.

// Last revision: December 2018

#pragma once

#include <cstddef>
#include <cstdint>
#include <vector>
#include <functional>
#include <utility>
using std::size_t; using std::uint32_t; using std::pair;
using std::vector; using std::result_of;

// Mods: 1e9+7, 1e9+11, 1e9+21, 1e9+33, 2^31 - 1

template<typename T, T Base, typename ModuloOperation>
struct rolling_hash
{
    ModuloOperation M;
    vector<T> H, P;
    size_t n;
    template<typename Iterator>
    rolling_hash(Iterator first, Iterator last, T fix = 0)
    {
        n = distance(first, last);
        H.resize(n+1); P.resize(n+1);
        H[0] = 0; P[0] = 1;
        for(size_t i = 0; i < n; i++, first++)
        {
            H[i+1] = M(H[i]*Base + (T(*first)+T(fix)));
            P[i+1] = M(P[i]*Base);
        }
    }
    T operator() (size_t i, size_t j) const
        { return M(M.divisor*M.divisor + H[j+1] - H[i]*P[j-i+1]); }
    bool equals(size_t a, size_t b, size_t c, size_t d) const
        { return (*this)(a, b) == (*this)(c, d); }
};

template<typename T>
struct identity
{
    static constexpr T divisor = 0;
    T operator() (T x) const { return x; }
};
template<typename T, T Divisor>
struct const_modulus
{
    static constexpr T divisor = Divisor;
    T operator() (T x) const { return x % Divisor; }
};
template<typename T, uint32_t K>
struct mersenne_modulus
{
    static constexpr T P = (T(1) << K) - 1, divisor = P;
    T operator() (T x) const
    {
        x = (x >> K) + (x & P);
        x = (x >> K) + (x & P);
        return x == P ? 0 : x;
    }
};

template<typename First, typename Second>
struct rolling_hash_pair
{
    First H; Second G;
    rolling_hash_pair(First h, Second g) : H(move(h)), G(move(g)) {}
    using T1 = typename result_of< First(size_t, size_t)>::type;
    using T2 = typename result_of<Second(size_t, size_t)>::type;
    pair<T1, T2> operator() (size_t i, size_t j) const
        { return {H(i, j), G(i, j)}; }
    bool equals(size_t a, size_t b, size_t c, size_t d)
        { return H.equals(a, b, c, d) and G.equals(a, b, c, d); }
};


/*
Examples:
rolling_hash<uint64_t, 31, const_modulus<uint64_t, uint64_t(1e9+33)>
    H(S.begin(), S.end(), -('a' - 1));
rolling_hash<uint64_t, 1e9+7, mersenne_modulus<uint64_t, 31>
    G(A.begin(), A.end());

rolling_hash_pair<
    rolling_hash<uint64_t, uint64_t(1e6+11), identity>,
    rolling_hash<uint64_t, uint64_t(1e6+13), mersenne_modulus<uint64_t, 31>>
>
*/
