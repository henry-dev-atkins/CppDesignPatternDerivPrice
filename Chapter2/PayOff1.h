#ifndef PAYOFF_H
#define PAYOFF_H

class PayOff
    {
    public:
        enum OptionType {call, put};    //Allows us to choose between.
        PayOff(double Strike_, OptionType TheOptionsType_);
        double operator()(double Spot) const;
    private:
        double Strike;
        OptionType TheOptionsType;
    };

#endif