#include <fstream>

using namespace std;

ifstream in ("evaluare.in");
ofstream out ("evaluare.out");

const int max_size = 1e5 + 1;

char s[max_size];
int p;
int termen();
int factor();
int expresie();

int expresie()
{
    int sum = termen();
    while(s[p] == '+' || s[p] == '-')
    {
        if (s[p] == '+')
        {
            p++;
            sum += termen();
        }
        else
        {
            p++;
            sum -= termen();
        }
    }
    return sum;
}

int termen()
{
    int prod = factor();
    while(s[p] == '*' || s[p] == '/')
    {
        if (s[p] == '*')
        {
            p++;
            prod *= factor();
        }
        else
        {
            p++;
            prod /= factor();
        }
    }
    return prod;
}

int factor()
{
    int semn = 1, val = 0;
    while(s[p] == '-')
    {
        p++;
        semn = -semn;
    }
    if (s[p] == '(')
    {
        p++;
        val = expresie();
        p++;
        return semn * val;
    }
    while (s[p] >= '0' && s[p] <= '9')
    {
        val = val * 10 + (s[p] - '0');
        p++;
    }
    return semn * val;
}

int main ()
{
    in.getline(s, max_size - 1);
    out << expresie();
    in.close();
    out.close();
    return 0;
}