#include "MathFunctions.hpp"
using namespace CustomMath;

int CustomMath::Factorial_int(int number)
{
  auto factorial = 1;

  for (int i = 1; i <= number; ++i)
  {
    factorial *= i;
  }
  
  return factorial;
}