/*
 * FoldPaper.cc - Estimate the height and length of paper needed to perform n time folds
 * freeants (c), 2017. 
 */

 #include <iostream>
 #include <cmath>

 int N; // folding times
 double L, H; // Length, Height of the whole pile of paper
 using namespace std;
 
 //Britney Gallivan's equation for folding paper
 double getLength(int n, double t)
 {
     return (t * 3.14159265359 / 6.0) * ( pow(2.0,n) + 4 ) * ( pow(2.0,n) - 1 );  
 }

 //Returns thickness of the folded paper
 double getThickness(int n, double t )
 {
     if( n==0 ) return t;
     return pow( 2.0, n ) * t ;
 }

//Convert milimeter to kilometer
 double mm2km(double mm)
 {
     return mm / 1000000.0;
 }

//Convert milimeter to light year
 double mm2ly(double mm)
 {
     return mm / 9460528404879358812.6;
 }

 int main()
 {
     cout << "Enter paper folding time: " ;
     cin >> N;

     cout << endl << "N" << '\t' << "Height(km/light year)" << '\t' << "Length(km/ly)" << endl;

     for( int i = 0; i <=N; i++ )
     {
         L = getLength(i, 0.1);
         H = getThickness(i, 0.1);
         
         cout << i << '\t' << mm2km(H) << "/" << mm2ly(H)  << '\t';
         cout << mm2km(L) << "/" << mm2ly(L)<< endl;         
     }
 }