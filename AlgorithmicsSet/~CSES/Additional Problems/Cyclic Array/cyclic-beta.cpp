#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);

    size_t n; int64_t s;
    cin >> n >> s;

    vector<int64_t> A(2*n);
    for(size_t i = 0; i < n; i++)
        cin >> A[i], A[n+i] = A[i];

    vector<int64_t> S(2*n+1);
    partial_sum(A.begin(), A.end(), S.begin() + 1);

    vector<size_t> U(2*n+1);
    for(size_t i = 0; i <= 2*n; i++)
    {
        if(i)
            U[i] = U[i - 1];
        while(U[i] <= 2*n and S[U[i]] <= S[i] + s)
            U[i]++;
    }

    auto get = [&](size_t p) {
        size_t i = p, c = 0;
        while(i < n+p)
            i = U[i] - 1, c++;
        return c;
    };

    size_t result = get(0);
    vector<size_t> where(n); iota(where.begin(), where.end(), 0);
    shuffle(where.begin(), where.end(), mt19937{(size_t)time(0)});
    const size_t t = max(10.0, 5.0 * n / (result - (result>1)));

    for(size_t i = 0; i < t and i < n; i++)
        result = min(result, get(where[i]));

    cout << result << endl;
}
