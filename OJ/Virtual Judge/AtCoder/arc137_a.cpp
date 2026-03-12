#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
    long long l, r;
    cin >> l >> r ;
    long long diff=0;
    for (long long i=l; i<r; i++)
    {
        for (long long j=0; j<r-l; j++)
        {
            long long gcd = __gcd(i, r-j);
            //cout << "gcd=" << gcd << endl;
            if (gcd==1)
            {
                if ( (r-j)-i <= diff )
                    break;
                else
                    diff = (r-j)-i;
                //cout << "diff=" << diff << endl;
            }
            else
                continue;
        }
        if ( i+diff >= r)
            break;
    }
    cout << diff << endl;
    return 0;
}