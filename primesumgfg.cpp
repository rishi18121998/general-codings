#include <iostream>
using namespace std;
using namespace std;
#define max 1000000

int main() 
{
    vector<bool> sieve(max,TRUE);
    vector<int> prime(max);
    sieve[1]=FALSE;
    for(int i=2;i<max;i++)
    {
        if(sieve[i]==TRUE)
        {
            prime.push_back(i);
            for(int j=2*i;j<max;j+=i)
            {
                if(sieve[j]==TRUE)
                    sieve[j]=FALSE;
            }
        }
    }
    int k=prime.size();
    vector<int> primesum(k);
    primesum[0]=prime[0];
    for(int i=1;i<n;i++)
    {
        primesum[i]=primesum[i-1]+prime[i];
    }
    int place=lowerbound(prime.begin(),prime.end())-prime.begin();
    place-=1;
    for(int i=place;i>=1;i--)
    {
        if(sieve[primesum[i]]==true && primesum[i]<=limit])
        {
            cout<<primesum[i];
            break;
        }
    }
	return 0;
}