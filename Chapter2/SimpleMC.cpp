#include "SimpleMC.h"
#include "PayOff1.cpp"
#include "../Chapter1/Random1.cpp"
#include <cmath>

double SimpleMonteCarlo2(const PayOff& thePayOff, double Expiry, double Spot, double Vol, double r, unsigned long NumberOfPaths)
    {
    double var = Vol * Vol * Expiry;
    double rootVar = std::sqrt(var);
    double itoCorrection = -0.5 * var;
    double movedSpot = Spot * std::exp(r * Expiry * itoCorrection);
    double thisSpot;
    double runningSum = 0;
    for (unsigned long i=0; i < NumberOfPaths; i++)
        {
        double thisGaussian = GetOneGaussianByBoxMueller();
        thisSpot = movedSpot * std::exp(rootVar * thisGaussian);
        double thisPayOff = thePayOff(thisSpot);
        runningSum += thisPayOff;
        }
    double mean = runningSum / NumberOfPaths;
    mean *= std::exp(-r * Expiry);
    return mean;
    }