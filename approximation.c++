#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

const long double target = 6.283185307179586476925286766559005768394338798750211;
const long int limit = pow(10,10);
const long double close_enough = pow(10,-20);

int main()
{
        cout << fixed << setprecision(20);

        long double numerator = 1;
        long double denominator = 1;
        long double smallest_error = target;

        while ( max(numerator, denominator) <= limit )
        {
                if ( abs(numerator/denominator - target) < smallest_error )
                {
                        smallest_error = abs(numerator/denominator - target);
                        cout << int(numerator) << "/" << int(denominator) << " = " << numerator/denominator << endl;
                }

                if ( smallest_error < close_enough )
                {
                        cout << "Close enough." << endl;
                        break;
                }

                if ( numerator/denominator < target )
                {
                        ++numerator;
                }
                else if ( numerator/denominator > target )
                {
                        ++denominator;
                }
                
        }

        cout << "Ended search." << endl;

        return 0;
}