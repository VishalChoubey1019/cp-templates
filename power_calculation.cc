#include <iostream>
#include <bits/stdc++.h>
#include <map>
#include <list>
#include <utility>
#include <algorithm>
#include <vector>
#define INF 10000000000
#define lli long long int
#define pb push_back
#define mp make_pair
#define FOR(i, n) for (int i = 0; i < n; i++)
#define FORR(i, a, b) for (int i = a; i < b; i++)
using namespace std;

//don't use mod if u don't need it. useful when values are too large and modulo is asked
lli power(lli a, lli b, lli mod) //a to the power b
{
    if (b == 0)
    {
        return 1;
    }
    lli ans = power(a, b / 2, mod);

    ans = (ans * ans) % mod;

    if (b % 2 == 1)
    {
        ans = (ans * a) % mod;
    }

    return ans % mod;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}