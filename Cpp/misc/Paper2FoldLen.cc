/*
 * Paper2FoldLen.cc - Estimate the length of paper needed to perform n time folds
 * freeants (c), 2017. 
 */

#include <iostream>
#include <cmath>

int N; // folding times
double L, T; // Length, Thickness of the whole pile of paper

using namespace std;

//Britney Gallivan's equation for folding paper
double getLength(int n, float t)
{
    return (t * 3.141592654 / 6.0) * ( pow(2.0,n) + 4 ) * ( pow(2.0,n) - 1 );  
}

//Returns thickness of the folded paper
double getThickness(int n, float t )
{
    if( n==0 ) return t;
    return pow( 2.0, n ) * t ;
}

int main()
{
    float l_m, l_km, l_ly; // meter, kilo-meter, light year
    float t_m, t_km, t_ly;
    cout << "Enter paper folding time: ";
    cin >> N;
    
    // t = 0.1 - the usual thickness of a peice of paper is 0.1 mili-meter
    L = getLength(N, 0.1);
    T = getThickness(N, 0.1);
    
    l_m = L / 1000.0;
    l_km = l_m / 1000.0;
    l_ly = l_m / 9460528404879358.8126;

    t_m = T / 1000.0;
    t_km = t_m / 1000.0;
    t_ly = t_m / 9460528404879358.8126;

    cout << endl << "Paper Length: "  << L << " mm / " << l_m << " m / " << l_km << " km / " << l_ly << " light year" << endl;
    cout << "Thickness: " << T << " mm / " << t_m << " m /" << t_km << " km / " << t_ly << " light year" << endl; 

    return 0; 
}