#include <fstream>
#include <stack>

using namespace std;

ifstream in("skyline.in");
ofstream out("skyline.out");

const int max_size = 4e4 + 5;

stack<long long> stiva;
long long sp[max_size], h[max_size], st[max_size], dr[max_size];

int main()
{
    int n;
    in >> n;
    for (int i = 1; i <= n; i++)
    {
        long long x;
        in >> h[i] >> x;
        sp[i] = sp[i - 1] + x;
    }
    for (int i = 1; i <= n; i++)
    {
        while (!stiva.empty() && h[stiva.top()] >= h[i])
            stiva.pop();
        if (stiva.empty())
            st[i] = 0;
        else
            st[i] = stiva.top();
        stiva.push(i);
    }
    while (!stiva.empty())
        stiva.pop();
    for (int i = n; i > 0; i--)
    {
        while (!stiva.empty() && h[stiva.top()] >= h[i])
            stiva.pop();
        if (stiva.empty())
            dr[i] = n + 1;
        else
            dr[i] = stiva.top();
        stiva.push(i);
    }
    long long max1 = 0;
    for (int i = 1; i <= n; i++)
        max1 = max(max1, h[i] * (sp[dr[i] - 1] - sp[st[i]]));
    out << max1;
    return 0;
}
