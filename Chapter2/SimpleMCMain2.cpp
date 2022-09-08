#include "SimpleMC.cpp"
#include <iostream>


int main()
{
double Expiry; double Strike; double Spot; double Vol; double r; unsigned long NumberOfPaths;

std::cout << "\nEnter Expiry, Strike, Spot, Vol, rate, Number of Paths\n"; 
std::cin >> Expiry; std::cin >> Strike; std::cin >> Spot; std::cin >> Vol; std::cin >> r; std::cin >> NumberOfPaths;
PayOff::OptionType call;
PayOff::OptionType put;
PayOff callPayOff(Strike, call);
PayOff putPayOff(Strike, put);

double resultPut = SimpleMonteCarlo2(putPayOff, Expiry, Spot, Vol, r, NumberOfPaths);
double resultCall = SimpleMonteCarlo2(callPayOff, Expiry, Spot, Vol, r, NumberOfPaths);
    
std::cout << "\nCall Price is: " << resultCall << " \n" << "Put Price is: " << resultPut << std::endl;

return 0;
}