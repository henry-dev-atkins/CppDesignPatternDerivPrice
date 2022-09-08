#include <iostream>
#include "Random1.cpp"
#include <cmath>

double SimpleMonteCarlo1(double Expiry, double Strike, double Spot, double Vol, double r, unsigned long NumberOfPaths)
    {
    double Varience = Vol * Vol * Expiry;
    double rootVarience = std::sqrt(Varience);
    double itoCorrection = - 0.5 * Varience;

    double movedSpot = Spot * exp(r * Expiry + itoCorrection);
    double thisSpot;
    double runningSum = 0;

    for (unsigned long i=0; i < NumberOfPaths; i++) 
        {
        double thisGaussien = GetOneGaussianByBoxMueller();
        thisSpot = movedSpot * std::exp(rootVarience * thisGaussien);

        double thisPayoff = thisSpot - Strike;
        thisPayoff = thisPayoff >0 ? thisPayoff : 0;
        runningSum += thisPayoff;
        }
    double mean = runningSum / NumberOfPaths;
    mean *= exp(-r * Expiry);
    return mean;
    }


int main()
{
double Expiry; double Strike; double Spot; double Vol; double r; unsigned long NumberOfPaths;

std::cout << "\nEnter Expiry, Strike, Spot, Vol, rate, Number of Paths"; 
std::cin >> Expiry;
std::cin >> Strike;
std::cin >> Spot;
std::cin >> Vol;
std::cin >> r;
std::cin >> NumberOfPaths;
    
double result = SimpleMonteCarlo1(Expiry, Strike, Spot, Vol, r, NumberOfPaths);
    
std::cout << "Price is: " << result << " \n" << std::endl;
double tmp;
std::cin >> tmp;

return 0;
}