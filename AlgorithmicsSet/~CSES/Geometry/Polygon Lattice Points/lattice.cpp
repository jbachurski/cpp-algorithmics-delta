#include <bits/stdc++.h>

using namespace std;

using vec = complex<int64_t>;

istream& operator>> (istream& in, vec& v)
{
    int64_t x, y;
    in >> x >> y;
    v = vec(x, y);
    return in;
}
int64_t cross(vec a, vec b)
{
    return (conj(a) * b).imag();
}

int64_t area(const vector<vec>& vertices)
{
     int64_t result = 0;
     for(size_t i = 0; i+1 < vertices.size(); i++)
        result += cross(vertices[i], vertices[i+1]);
    result += cross(vertices.back(), vertices.front());
    return result;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);

    size_t n;
    cin >> n;

    vector<vec> vertices(n);
    for(auto& v : vertices)
        cin >> v;

    int64_t double_area = abs(area(vertices)), boundary = 0;
    for(size_t i = 0; i < n; i++)
    {
        auto u = vertices[i], v = vertices[i+1 == n ? 0 : i+1];
        auto w = v - u;
        boundary += gcd(w.real(), w.imag());
    }
    int64_t inside = (double_area - boundary) / 2 + 1;

    cout << inside << " " << boundary << endl;
}
