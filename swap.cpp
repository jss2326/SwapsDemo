#include <iostream>
#include <cmath>
#include <vector>
#include <numeric>
#include "swap.h"

Swap::Swap()
{
}

Swap::Swap(float Rate_A_Fix, float Rate_B_Flt)
{
  this->Client_A_Rate_Fixed = Rate_A_Fix;

  this->Client_B_Rate_Float = Rate_B_Flt;
}

Swap::~Swap()
{
}

void Swap::PriceSwapFixAFloatB()
{

  // storage vectors
  std::vector<float> LIBOR = {.05, .06, 0.07};
  std::vector<float> Time = {0.25, 0.75, 1.25};

  std::cout << "Displaying Profile: \n";
  std::cout << "Expiry in 15 Months: \n";
  std::cout << "Fixed Leg Rate: 8%" << std::endl;
  std::cout << "LIBOR CURVE: " << std::endl;

  for (auto &x : LIBOR)
  {
    std::cout << x * 100 << "% \n";
  }

  std::cout << "Valuing Swap....." << std::endl;

  // debug rates
  float FixedRate = 0.08;

  std::vector<float> DiscountFactor;

  for (int i = 0; i < LIBOR.size(); i++)
  {
    DiscountFactor.push_back(exp(-Time[i] * LIBOR[i]));
  }

  std::vector<float> FVFixed;

  for (int i = 0; i < Time.size(); i++)
  {
    FVFixed.push_back((this->Notional * FixedRate) / 2);
  }

  // alter the last FV
  FVFixed[FVFixed.size() - 1] = this->Notional + (this->Notional * FixedRate) / 2;

  std::vector<float> PVFixed;

  for (int i = 0; i < Time.size(); i++)
  {
    PVFixed.push_back(

        FVFixed[i] * exp(-LIBOR[i] * Time[i]));
  }

  float SumFixedCF = 0;

  for (auto x : PVFixed)
  {
    SumFixedCF += x;
  }

  float SixMLibor = 0.055;

  float FVFloat = ((.5 * SixMLibor) * this->Notional) + this->Notional;

  float PVFloat = FVFloat * exp(-LIBOR[0] * Time[0]);

  float VALUEOFSWAP = SumFixedCF - PVFloat;

  std::cout << "[ANSWER]: $" << VALUEOFSWAP << std::endl;
}
