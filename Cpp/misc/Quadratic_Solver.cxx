/*
  Quadratic_Solver.cxx
  Caculate the roots of ax² + bx + c = 0
 */

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
  float coe[3], x1, x2, delta;

  // prompt for input a, b & c
  cout << "Caculate the roots of ax² + bx + c = 0, input a, b and c: ";

  for (int i = 0; i < 3; i++)
    cin >> coe[i];

  // delta = b² - 4ac
  delta = coe[1] * coe[1] - 4.0 * coe[0] * coe[2];
  cout << "The function appears to be: "
       << coe[0] << "x² + " << coe[1] << "x + " << coe[2] << " = 0" << endl;
  cout << "delta = b² - 4ac = " << delta << endl;

  // determin value of delta
  if (delta > 0)
  {
    x1 = (-coe[1] + sqrt(delta)) / 2.0 * coe[0];
    x2 = (-coe[1] - sqrt(delta)) / 2.0 * coe[0];
    cout << "∆ = " << delta << " > 0" << endl;
    cout << "x1 = " << x1 << "; x2 = " << x2 << endl;
  }
  else if (delta == 0)
  {
    x1 = x2 = -coe[1] / 2.0 * coe[0];
    cout << "∆ = " << delta << " = 0" << endl;
    cout << "x1 = x2 = " << x1 << endl;
  }
  else //delta < 0, has two complex number roots
  {
    // m + n * i format
    float m, n;
    m = -coe[1] / 2.0 * coe[0];
    n = sqrt(-delta) / 2.0 * coe[0];
    cout << "∆ = " << delta << " < 0" << endl;
    cout << "x1 = " << m << " + " << n << "i; x2 = " << m << " - " << n << "i" << endl;
  }

  return 0;
}