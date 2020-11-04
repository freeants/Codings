//: Paper2Fold.cc - estimate what happens when folding paper

#include <iostream>
#include <cmath>
using namespace std;

int N; // folding times
double Length, Depth, Height; 
double Area; // rectangle area

double Sn(float l, int n)
{
    if( n == 0 ) return l * l;
    return l*l / pow(2.0, n);
}

double Hn(float l, float d, int n)
{
    if( n==0 ) return d;
    return pow( 2.0, n ) * d ;
}

int main()
{
    cout << "Enter rectangle Length, Depth and folding times: ";
    cin >> Length >> Depth >> N;
    cout << endl << "N" << '\t' <<  "Height" <<'\t' << "Volume" << '\t'<< "Top area "<< endl;

    for( int i = 0; i <= N; i++)
    {
        Area    = Sn (Length, i); 
        Height  = Hn (Length, Depth, i);

        cout << i << '\t' << Height << '\t' << Area * Height  << '\t' << Area << endl;
    }
    
    return 0; 
}