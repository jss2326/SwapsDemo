#pragma once

class Swap
{
public:
  Swap();
  Swap(float Rate_A_Fix, float Rate_B_Flt);

  ~Swap();

  // variables
  float Client_A_Rate_Fixed;
  float Client_A_Rate_Float;

  float Client_B_Rate_Fixed;
  float Client_B_Rate_Float;

  float Notional = 100;

  // methods
  void PriceSwapFixAFloatB();
};