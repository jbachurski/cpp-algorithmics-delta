#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);

    size_t n; size_t q;
    cin >> n >> q;

    int maximum = 0;
    vector<int> A(n);
    vector<int64_t> St(n+1);
    for(size_t i = 0; i < n; i++)
        cin >> A[i], maximum = max(maximum, A[i]), St[i+1] = St[i] + A[i];

    auto S = [&](size_t i) {
        return i >= n ? St[n] + St[i - n] : St[i];
    };

    vector<uint32_t> U(n+1);
    mt19937 gen(1337);
    vector<uint32_t> where(n); iota(where.begin(), where.end(), 0);
    shuffle(where.begin(), where.end(), gen);

    while(q --> 0)
    {
        int64_t s;
        cin >> s;

        if(s < maximum)
        {
            cout << "NIE\n";
            continue;
        }

        for(size_t i = 0; i <= n; i++)
        {
            U[i] = i ? U[i - 1] - 1 : 0;
            while(i + U[i] <= 2*n and S(i + U[i]) <= S(i) + s)
                U[i]++;
        }

        auto get = [&](size_t p) {
            size_t i = p, c = 0;
            while(i < n+p)
                i += U[i >= n ? i - n : i] - 1, c++;
            return c;
        };

        size_t result = get(where[0]);
        if(result > 2)
        {
            if(result < n)
            {
                const size_t t = max(1.0, 3.0 * n / (result - 1));
                auto rr = result - 1;
                for(size_t i = 1; i < t and i < n and result > rr; i++)
                {
                    auto r = get(where[i]);
                    if(r == result + 1)
                        break;
                    result = min(result, r);
                }
            }
            else
            {
                for(size_t i = 0; i+1 < n; i++)
                    if(A[i] + A[i+1] < s)
                        { result--; break; }
            }
        }

        cout << result << '\n';
    }

}
