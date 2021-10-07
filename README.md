# Interest Rate Swap Pricer
Simple fixed-for-floating interest rate swap pricer using discount factors derived from a LIBOR curve.

## Overview
- Prices a swap where **Client A pays fixed** and **Client B pays floating**
- Uses a small LIBOR term structure to compute discount factors
- Computes fixed-leg cash flows (including notional exchange), PV of fixed and floating legs, and net swap value
- Includes configurable fixed and floating rates

## Notes
- No day count conventions or curve bootstrapping  
- Easily extendable to OIS discounting, multi-period floating legs, swaption pricing 
