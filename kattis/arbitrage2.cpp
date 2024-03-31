#include <bits/stdc++.h>


using namespace std;

int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47,
    53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101}; 
const int NPrimes = sizeof(primes)/sizeof(primes[0]);

class Rational
{
    bool zero;
    int power[NPrimes];
public:
    Rational()
    {
        zero = true;
    }

    Rational(int x)
    {            
        if (x == 0)
            zero = true;
        else
        {
            zero = false;
            for (int i = 0; i < NPrimes; i++)
            {
                power[i] = 0;
                while (x > 0 && x % primes[i] == 0)
                {
                    x /= primes[i];
                    power[i]++;
                }
            }
        }
    }

    Rational operator*(const Rational& y);
    Rational operator/(const Rational& y);
    bool operator>(const Rational& y);
};

Rational Rational::operator*(const Rational& y)
{
    Rational z; 
    if (zero || y.zero)
    {
        z.zero = true; 
    }
    else
    {
        z.zero = false;
        for (int i = 0; i < NPrimes; i++)
            z.power[i] = power[i] + y.power[i];
    }
    return z;
}

Rational Rational::operator/(const Rational& y)
{
    Rational z;   
    if (zero)
    {
        z.zero = true;
    }
    else if (y.zero)
    {
        throw runtime_error("Denominator of a rational is zero");
    }
    else
    {
        z.zero = false;
        for (int i = 0; i < NPrimes; i++)
            z.power[i] = power[i] - y.power[i];
    }
    return z;
}

bool Rational::operator>(const Rational& y)
{
    if (zero && y.zero)
        return false;
    else if (!zero && y.zero)
        return true;
    else if (zero && !y.zero)
        return false;
    Rational z = *(this) / y;
    double logarithm = 0.0;
    for (int i = 0; i < NPrimes; i++)
        logarithm += (double)(z.power[i]) * log((double)primes[i]);
    return logarithm > 0;
}


Rational Cost[200][200];

void work(int n){
    map<string,long long> m;
    vector<list<int>> g(n);
    long long id = 0;
    bool end = 0;
    for (int i=0;i<n;i++){
        string s;
        cin >> s;
        m[s] = id++;
    }

    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
            Cost[i][j] = 0;

    int r;
    cin >> r;
    for (int i=0;i<r;i++){
        string a,b;
        cin >> a >> b;
        long double na,nb;
        cin >> na;
        cin.get();
        cin >> nb;
        g[m[a]].push_back(m[b]);

        Rational ra = na;
        Rational rb = nb;

        if (Cost[m[a]][m[b]] > 0 && (Cost[m[a]][m[b]] > ra/rb || ra/rb > Cost[m[a]][m[b]])){
            end = 1;
        }
        Cost[m[a]][m[b]] = ra/rb;
    }

    if (end){
        cout << "Arbitrage\n";
        return;
    }

    for (int i=0;i<n;i++) Cost[i][i] = 1;

    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            for (int k=0;k<n;k++){
                if (Cost[j][i] > 0 && Cost[i][k] > 0 && Cost[j][k] > Cost[j][i]*Cost[i][k]) Cost[j][k] = Cost[j][i]*Cost[i][k];
                if (j == k && (Rational(1) > Cost[j][j] || Cost[j][j] > Rational(1))){
                    cout << "Arbitrage\n";
                    return;
                }
            }
        }
    }

    for (int i=0;i<n;i++)
        if (Rational(1) > Cost[i][i] || Cost[i][i] > Rational(1)){
            cout << "Arbitrage\n";
            return;
        }
        
    cout << "Ok\n";
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    while (cin >> n){
        if (!n) break;
        work(n);
    }


    return 0;
}