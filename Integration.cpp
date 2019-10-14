// =============================================================================
//             Name: Sreece Goldberger
//           Course: CMPSC 201
//   Project Number: 3
//     NSD Due Date: 25 October 2011
// Project Due Date: 10 November 2011
// Program Filename: Integration
//   Input Filename: Not Applicable
//  Output Filename: Integration.txt
// =============================================================================
// Program Abstract: This program finds the the approximate value of an integral
//	             from points a to b of a function with at most degree nine.
//   Input Required: All of the coefficients of x, from x^9 down to the constant,
//                   the degree, and the bounds of the integral
//   Output Desired: The approximate value of the integral from a to b 
// =============================================================================

#include <conio.h>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <cmath>
#include <stdlib.h>

using namespace std;

ofstream fout;

//Utility functions
void vertspc (int, char);//vertical spacing console or file
void pause (void);       //a pause to the console
void divider (void);     //divide the textfile
void dividerC (void);    // divide the console

//Global Functions
int getreply (char);  //char to int, console
void display (double [], int, int, int, int); //displays the F(x) to console 
void correct (double [], int, int, int, int);//Display F(x) to textfile
double horners (double [], int, double);

//==============================================================================

int main ()
  {
    //Funtion Declaration
    void intro (void);  
    void inputs (double [], int&, int&, int&, int);
    void find (double [], int, int, int); //finds the value
    void another (int&);
    void exit (void);

    //Variable declaration
    int a, ans, b, deg, j;
    double coef [10];

    // =========================================================================
    // Alphabetized Variable Dictionary
    // =========================================================================
    //        a: lower bound
    //      ans: the return from the switch, 1 for y, 0 for n, 2 for all else
    //        b: upper bound
    //     coef: the array for the coefficients of x
    //      deg: the degree of f(x)
    //        j: counter for the fout form feed
    // =========================================================================

    fout.open ("Integration.txt");

    cout << fixed << setprecision (3);
    fout << fixed << setprecision (3);

    deg = 0;
    j = 0;
    a = 0;
    b = 0;

    intro ();

    do
      {	//while there is another f(x): Start of first Do-While
 	j++;
	inputs (coef, deg, a, b, j);
	correct (coef, deg, a, b, j);  //textfile display
	display (coef, deg, a, b, j);  //console display
	find (coef, deg, a, b);
	another(ans);
      }
    while (ans == 1);//while there is another f(x): Ends of first Do-While

    exit ();

    fout.close ();

    return 0;
  }

// =============================================================================
//   Abstract: To the console, the introduction
// Parameters: Nothing is passed to the function
//     Output: Nothing is passed back to the program
// =============================================================================

void intro (void)
  {
    vertspc (6, 'c');
    cout << setw (52) << "INTEGRATION APPROXIMATER";
    vertspc (5, 'c');
    cout << setw (64) << "finds the approximate integral, from a to b, for";
    vertspc (3, 'c');
    cout << setw (67) << "at most a function with degree nine.  In the form of...";
    vertspc (3, 'c');
    cout << setw (65) << "F(x) = C9 x^9 + C8 x^8 + C7 x^7 + C6 x^6 + C5 x^5 +";
    vertspc (3, 'c');
    cout << setw (61) << "C4 x^4 + C3 x^3 + C2 x^2 + C1 x^1 + C0 x^0";
    pause ();

    return;
  }

// =============================================================================
//   Abstract: Collects from the user all inputs
// Parameters: Variables deg, a, b, counter j, and the array passed to function
//     Output: Collect and pass all back to function
// =============================================================================

void inputs (double coef [], int &deg, int &a, int &b, int j)
  {
    void degree (int&, int);
    void lower (int&, int);
    void upper (int&, int);
    void coeff (double [], int, int);
    void display (double[], int, int, int, int);

    char reply;
    int ans;

    // =========================================================================
    // Local Alphabetized Variable Dictionary
    // =========================================================================
    //      a: An integer for lower bound
    //    ans: The integer value of reply
    //      b: An integer for lower bound
    //   coef: The array of coefficients
    //    deg: The degree of the funtion
    //      j: An integer counter, number of equations user has done
    //  reply: A character value of y, n, or other from user
    // =========================================================================

    do
      {  //While f(x) is incorrect
	degree (deg, j);
	lower (a, j);
	upper (b, j);
        coeff (coef, deg, j);

        do
	  {  // While reply is other than y or n
            display (coef, deg, a, b, j);

            vertspc (5, 'c');
            cout << setw (48) << "Is F(x) correct?";
            vertspc (3, 'c');
            cout << setw (55) << "Enter y for yes and n for no: " ;
            cin >> reply;
	    ans = getreply (reply);
            system ("cls");
          }
        while (ans > 1);

	system ("cls");
      }
    while (ans < 1);

    return;
  }

// =============================================================================
//   Abstract: To the console, request for input from the user
// Parameters: The variable deg is passed to function
//     Output: Changes the value of deg
// =============================================================================

void degree (int &deg, int j)
  {
    // =========================================================================
    // Local Alphabetized Variable Dictionary
    // =========================================================================
    //    deg: Integer value of highest power of x
    //      j: An integer counter, number of equations user has done
    // =========================================================================

    vertspc (9, 'c');
    cout << setw (45) << "Equation " << j << ":";
    vertspc (4, 'c');
    cout << setw (59) << "Please enter the highest power of x: ";
    cin >> deg;
    system ("cls");

    return;
  }

// =============================================================================
//   Abstract: To the console, request for input from the user
// Parameters: The variable a is passed to function
//     Output: Changes the value of a
// =============================================================================

void lower (int &a, int j)
  {
    // =========================================================================
    // Local Alphabetized Variable Dictionary
    // =========================================================================
    //    a: Integer value of the lower bound
    //    j: An integer counter, number of equations user has done
    // =========================================================================

    vertspc (9, 'c');
    cout << setw (45) << "Equation " << j << ":";
    vertspc (4, 'c');
    cout << setw (59) << "Please enter the lower bound, a: ";
    cin >> a;
    system ("cls");

    return;
  }

// =============================================================================
//   Abstract: To the console, request for input from the user
// Parameters: The variable b is passed to function
//     Output: Changes the value of b
// =============================================================================

void upper (int &b, int j)
  {
    // =========================================================================
    // Local Alphabetized Variable Dictionary
    // =========================================================================
    //    b: Integer value of the upper bound
    //    j: An integer counter, number of equations user has done
    // =========================================================================

    vertspc (9, 'c');
    cout << setw (45) << "Equation " << j << ":";
    vertspc (4, 'c');
    cout << setw (59) << "Please enter the upper bound, b: ";
    cin >> b;
    system ("cls");

    return;
  }

// =============================================================================
//   Abstract: To the console, request for input from the user
// Parameters: The array, deg and a counter are passed to function
//     Output: The variable coef is filled
// =============================================================================

void coeff (double coef [], int deg, int j)
  {
    int i;

    // =========================================================================
    // Local Alphabetized Variable Dictionary
    // =========================================================================
    //   coef: The array of coefficients
    //    deg: The degree of the funtion
    //      i: An integer counter
    //      j: An integer counter, number of equations user has done
    // =========================================================================

    for (i = deg; i >= 0; i--)
      {
        vertspc (9, 'c');
        cout << setw (45) << "Equation " << j << ":";
        vertspc (4, 'c');
        cout << setw (59) << "Please enter the coefficient of x^";
        cout << i << ": ";
        cin >> coef [i];
        system ("cls");
      }

    return;
  }

// =============================================================================
//   Abstract: To the console, display the function
// Parameters: Program passes the array, deg and counter to the function
//     Output: Nothing is passed back to the program
// =============================================================================

void display (double coef [], int deg, int a, int b, int j)
  {
    int i, half, under, w;

    // =========================================================================
    // Local Alphabetized Variable Dictionary
    // =========================================================================
    //      a: An integer for lower bound
    //      b: An integer for lower bound
    //   coef: The array of coefficients
    //    deg: The degree of the funtion
    //   half: Half of the degree
    //      i: Counter
    //      j: An integer counter, number of equations user has done
    //  under: The variable width of setw for degree under 5
    //      w: The variable width of setw for degree 5 or over
    // =========================================================================

    half = ((deg + 1) / 2);
    w = 40 - 5 * half;
    under = 40 - 5 * deg;

    if (deg >= 5)
      {
	vertspc (4, 'c');
	cout << setw (45) << "Equation " << j << ":";
	vertspc (4, 'c');

	cout << setw (44) << "The integral from " << a << " to " << b << " of ... ";
	vertspc (3, 'c');
        cout << setw (w) << "F(x) = ";
	cout << setiosflags (ios :: fixed);
	for (i = deg; i >= half; i--)
	  {
            cout << setw (5) << coef [i] << " x^" << i << " + "; //same line as above
          }

        vertspc (3, 'c');
	cout << setiosflags (ios :: fixed) << setw (w) << " ";
        for (i = (half - 1); i >= 1; i--)
          {
	    cout << setw (5) << coef [i] << " x^" << i << " + ";
	  }
      }
    else
      {
	vertspc (6, 'c');
	cout << setw (45) << "Equation " << j << ":";
	vertspc (4, 'c');

        cout << setw (44) << "Integral from " << a << " to " << b << " of ... ";
	vertspc (3, 'c');
	cout << setw (under) << "F(x) = ";
        cout << setiosflags (ios :: fixed);
	for (i = deg; i >= 1; i--)
          {
	    cout << setw (5) << coef [i] << " x^" << i << " + ";//same line as above
	  }
      }

    cout << setw (4) << coef [0] << "."; //same line as above

    vertspc (2, 'c');

    return;
  }

// =============================================================================
//   Abstract: To the textfile, display the correct function
// Parameters: Program passes the array, degree and counter to the function
//     Output: Nothing is passed back to the program
// =============================================================================

void correct (double coef [], int deg, int a, int b, int j)
  {
    int i, half, under, w;

    // =========================================================================
    // Local Alphabetized Variable Dictionary
    // =========================================================================
    //      a: An integer for lower bound
    //      b: An integer for lower bound
    //   coef: The array of coefficients
    //    deg: The degree of the funtion
    //   half: Half of the degree
    //      i: Counter
    //      j: An integer counter, number of equations user has done
    //  under: The variable width of setw for degree under 5
    //      w: The variable width of setw for degree 5 or over
    // =========================================================================

    half = ((deg + 1) / 2);
    w = 40 - 5 * half;
    under = 40 - 5 * deg;

    vertspc (3, 'f');
    fout << setw (62) << "The Function And The Approximate Integral";
    vertspc (3, 'f');

    if (deg >= 5)
      {
	fout << setw (45) << "Equation " << j << ":";
        vertspc (3, 'f');
        fout << setiosflags (ios :: fixed);
        fout << setw (46) << "Integral from " << a << " to " << b << "... ";
	vertspc (3, 'f');
	fout << setw (w) << " F(x) = ";
	for (i = deg; i >= half; i--)
	  {
	    fout << setw (5) << coef [i] << " x^" << i << " + "; //same line as above
          }

	vertspc (3, 'f');
	fout << setiosflags (ios :: fixed)<< setw (20) << " ";
        for (i = (half - 1); i > 0; i--)
          {
	    fout << setw (5) << coef [i] << " x^" << i << " + ";
          }
      }
    else
      {
	fout << setw (45) << "Equation " << j << ":";
	vertspc (3, 'f');
        fout << setw (44) << "Integral from " << a << " to " << b << " of ... ";
	vertspc (3, 'f');
	fout << setw (under) << "F(x) = ";
	fout << setiosflags (ios :: fixed);
	for (i = deg; i > 0; i--)
          {
	    fout << setw (5) << coef [i] << " x^" << i << " + ";//same line as above
          }
      }

    fout << setw (4) << coef [0] << " x^0."; //same line as above

    vertspc (2, 'f');

    return;
  }

// =============================================================================
//   Abstract: Finds the approximate value of integral
// Parameters: Program passes the array, deg, and counter to the function
//     Output: Nothing is passed back to the program
// =============================================================================

void find (double coef [], int deg, int a, int b)
  {
    double trapezoidal (double [], double, double, double, double, int);
    double simpsons (double, double);
    void table (int, double, double, double);

    int k;
    double delta, fa, fb, fx, uplim, snew, sold, tnew, told, x;

    // =========================================================================
    // Local Alphabetized Variable Dictionary
    // =========================================================================
    //      a: An integer for lower bound
    //      b: An integer for lower bound
    //  delta: The width of the partition
    //     fa: The value of the equation at a
    //     fb: The value of the equation at b
    //     fx: The value of the equation at x
    //      k: The trapezoidal counter
    //   snew: The new simpsons value
    //   sold: The old simpsons value
    //   tnew: The new trapezoidal value
    //   told: The old trapezoidal value
    //  uplim: The number of new partitions
    //      x: The new partitions
    // =========================================================================

    delta = b - a;
    k = 0;
    fa = horners (coef, deg, a);
    fb = horners (coef, deg, b);
    told = delta * (fa + fb) / 2.0;
    delta = delta / 2;
    k = k + 1;
    x = a + delta;
    fx = horners (coef, deg, x);
    tnew = told / 2.0 + delta * fx;
    snew = simpsons (tnew, told);
    uplim = 1;
    table (k, delta, snew, uplim);

    do
      {
	told = tnew;
	sold = snew;
	delta = delta / 2.0;
	k = k + 1;
	uplim = uplim * 2;

	tnew = trapezoidal (coef, told, delta, uplim, a, deg);
	snew = simpsons (tnew, told);
	table (k, delta, snew, uplim);
      }
    while (fabs (snew - sold) > 0.001);

    vertspc (3, 'c');
    cout << setw (56) << "The final estimate of the integral is " << snew;

    vertspc (3, 'f');
    fout << setw (56) << "The final estimate of the integral is " << snew;
    fout << "\f";

    vertspc (3, 'c');
    cin.get ();
    pause ();
    return;
  }

// =============================================================================
//   Abstract: This finds the value of the fx
// Parameters: Program passes the array, deg, and the value at x
//     Output: The value of fx is returned to the program
// =============================================================================

double horners (double coef [], int deg, double x)
  {
    int i;
    double fx;

    // =========================================================================
    // Local Alphabetized Variable Dictionary
    // =========================================================================
    //   coef: The array of coefficients
    //    deg: The degree of the funtion
    //     fx: The value of the function at x
    //      i: A counter
    // =========================================================================

    fx = 1;

    for ( i = 0; i > deg; i++)
      {
        fx = fx * x + coef [i];
      }

    return fx;
  }

// =============================================================================
//   Abstract: Finds any Tk
// Parameters: Program passes told, delta, and uplim
//     Output: Nothing is passed back to the program
// =============================================================================

double trapezoidal (double coef [], double told, double delta,
                        double uplim, double a, int deg)
  {
    int i;
    double fx, sum, tnew, x;

    // =========================================================================
    // Local Alphabetized Variable Dictionary
    // =========================================================================
    //     a: An integer for lower bound
    //  coef: The array of coefficients
    // delta: The width of the partition
    //    fx: The value of the function at x
    //     i: A counter
    //   sum: The sum of all tk
    //  tnew: An integer value, based on a y or n from the user
    // uplim: The number of partitions
    //     x: The integer value at the new partition
    // =========================================================================

    sum = 1;

    for (i = 0; i < uplim; i++)
      {
        x = a + (2 * i - 1) * delta;
        fx = horners (coef, deg, x);
        sum = sum + fx;
      }

    tnew = told / 2.0 + delta * sum;

    return tnew;
  }

// =============================================================================
//   Abstract: Calculates the value of snew
// Parameters: Passed told and tnew
//     Output: Returns snew
// =============================================================================

double simpsons (double tnew, double told)
  {
    double snew;

    // =========================================================================
    // Local Alphabetized Variable Dictionary
    // =========================================================================
    //   snew: The new estimated value of the integral between a and b
    //   tnew: The new Trapezoidal value
    //   told: The old Trapezoidal value
    // =========================================================================

    snew = (4 * tnew - told) / 3.0;

    return snew;
  }

// =============================================================================
//   Abstract: The table of values progressing towards the approximation
// Parameters: The values of dk, sk, and counter
//     Output: Nothing is passed back to the program
// =============================================================================

void table (int k, double dk, double sk, double uplim)
  {
    double p;

    // =========================================================================
    // Local Alphabetized Variable Dictionary
    // =========================================================================
    //   dk: The delta between two partitions
    //    k: The number of iterations
    //    p: The number of partitions
    //   sk: The new Simpsons value
    // =========================================================================

    p = 1 + uplim;
    
    if (k == 1) //outputs to the console
      {
        dividerC ();
	cout << setiosflags (ios :: fixed);
	cout << setw (15) << "k" << setw (14) << "p";
	cout << setw (16) << "dk" << setw (19) << "sk";
	dividerC ();
      }

    cout << setiosflags (ios :: fixed) << setprecision (3);
    cout << setw (15) << k << setw (16) << p << setw (16) << dk;
    cout << setw (19) << sk;
    vertspc (2, 'c');

    if (k == 1) //outputs to the file
      {
	divider ();
        vertspc (3, 'f');
        fout << setw (15) << "k" << setw (15) << "p";
	fout << setw (15) << "dk" << setw (18) << "sk";
        divider ();
      }

    fout << setiosflags (ios :: fixed) << setprecision (3);
    fout << setw (15) << k << setw (17) << p << setw (15) << dk;
    fout << setw (18) << sk;
    vertspc (2, 'f');

    return;
  }

// =============================================================================
//   Abstract: To the console, another F(x)
// Parameters: Nothing passes to the function
//     Output: Ans is passed back to the program
// =============================================================================

void another (int &ans)
  {
    char reply;

    // =========================================================================
    // Local Alphabetized Variable Dictionary
    // =========================================================================
    //    ans: An integer value, that is then passed to the program
    //  reply: An character value, y, n, or other from the user
    // =========================================================================

    do
      {
        vertspc (7, 'c');
        cout << setw (58) << "Do you want to evaluate another F(x)?";
        vertspc (3, 'c');
        cout << setw (58) << "Please enter y for yes and n for no: " ;
        cin >> reply;
        ans = getreply (reply);
        system ("cls");
      }
    while (ans > 1);

    return;
  }

// =============================================================================
//   Abstract: This is the end
// Parameters: Nothing passed to function
//     Output: Nothing passed back to program
// =============================================================================

void exit ()
  {
    vertspc (9, 'c');
    cout << setw (63) << "Thank you for using the INTEGRATION APPROXIMATER." ;
    vertspc (3, 'c');
	cin.get ();
    pause ();

    return;
  }

// =============================================================================
// Utility Functions
// =============================================================================
//   Abstract: For changing a char reply from user into an integer value
// Parameters: A character value from the user
//     Output: A interger value that corresponds to a response
// =============================================================================

int getreply (char userreply)
  {
    int ans;

    // =========================================================================
    // Local Alphabetized Variable Dictionary
    // =========================================================================
    //      ans: Will return to the main program a integer value
    //userreply: The Character value entered by the user
    // =========================================================================

    switch (userreply)
      {
        case 'y': ans = 1;//answer 1/correct, 2/another f(x)
        case 'Y': ans = 1;
		break;

        case 'n': ans = 0;//answer 1/incorrect, 2/done
        case 'N': ans = 0;
		break;

        default: ans = 2;  //answer invalid
		 break;
      }

    return ans;
  }

// =============================================================================
//   Abstract: for Vertical Spacing for console or textfile
// Parameters: An integer value, indicating the number of spaces needed and a
//             character value, indicating spaces meant for console or text file 
//     Output: Nothing is returned to the program
// =============================================================================

void vertspc ( int num, char destination)		
  {
    int i;

    // =========================================================================
    // Local Alphabetized Variable Dictionary
    // =========================================================================
    // destination: Charactor value passed from program to indicate the intended
    //              use for the spacing
    //           i: Counts from one to the number passed from the program
    //         num: Value passed from program indicating number of spaces needed
    // =========================================================================

    switch (destination)
      {
	case 'c': for ( i = 1; i < num; i++)
                    {
	              cout << endl;
                    }
		  break;
                  
        case 'f': for ( i = 1; i < num; i++)
                    {
		      fout << endl;
                    }
		  break;
      }

    return;
  }

// =============================================================================
//   Abstract: A pause in the printing to the console then clear the screen
// Parameters: Nothing is passed to the function
//     Output: Nothing is returned to the program
// =============================================================================

void pause (void)
  {
    vertspc (5, 'c');
    cout << setw (54) <<"Press Enter to continue...";
    cin.get ();
    system ("cls");                   
  }

// =============================================================================
//   Abstract: A dividing line to the textfile 
// Parameters: Nothing is passed to the function
//     Output: Nothing is returned to the program
// =============================================================================

void divider ()
  {
    int i;

    // =========================================================================
    // Local Alphabetized Variable Dictionary
    // =========================================================================
    //    i: Counts from one to the number passed from the program
    // =========================================================================

    vertspc (2, 'f');

    for ( i = 1; i < 79; i++)
      {
        fout << "=";
      }

    vertspc (2, 'f');

    return;
  }

// =============================================================================
//   Abstract: A dividing line to the console
// Parameters: Nothing is passed to the function
//     Output: Nothing is returned to the program
//==============================================================================

void dividerC ()
  {
    int i;

    // =========================================================================
    // Local Alphabetized Variable Dictionary
    // =========================================================================
    //    i: Counter
    // =========================================================================

    vertspc (2, 'c');

    for ( i = 1; i < 79; i++)
      {
        cout << "=";
      }

    vertspc (2, 'c');

    return;
  }

//==============================================================================



 