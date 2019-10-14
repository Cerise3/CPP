// =============================================================================
//             Name: Sreece Goldberger
//           Course: CMPSC 201
//   Project Number: 1
//     NSD Due Date: 
// Project Due Date: 29 Sept 2011
// Program Filename: Quadratic2_0
//   Input Filename: Not Applicable
//  Output Filename: Quadratic2_0.txt
// =============================================================================
// Program Abstract: This program will find the roots of at most a quadratic
//                      equation.
//   Input Required: Three values from the user
//   Output Desired: The roots of the equation, 5 per page
// =============================================================================

#include <conio.h>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <cmath>

using namespace std;

int getreply (char userreply);  //declaring a subroutine for y and n
void vertspc (int numlines);    //declaring a subroutine for vertical spacing
void twolines (double A, double B, double C);//declaring a subroutine for outputs
void clearscreen ();    //declaring a subroutine for clear screen
void thetextfile ();    //declaring a subroutine for the textfile

ofstream fout;

int main ()
  {
    int numlines, ans, j;
    double disc, X1, X2, R, P, T, A, B, C;
    char reply;

    // =========================================================================
    // Alphabetized Variable Dictionary
    //        A: the coefficient of x^2
    //      ans: the return from the switch, 1 for y, 0 for n, 2 for all else
    //        B: the coefficient of x^1
    //        C: the coefficient of x^0
    //     disc: the discriminant
    //        j: counter for the fout form feed
    // numlines: number of lines called for vertical spacing
    //        P: the absolute value of the discriminant
    //        R: is the real part of the quadratic equation -b/2a
    //    reply: input from the user of y or n or other
    //        T: is the real or imaginary part of the quadratic equation
    //           ( sqrt (P)) / ( 2 * A )
    //       X1: the first real root
    //       X2: the second real root
    // =========================================================================

    fout.open ("Quadratic2_0.txt");
    fout << setw (49) << "FUNCTIONS and SOLUTIONS";
    fout << endl << endl;

    j = 0;
    thetextfile ();
    numlines = 5;
    vertspc (numlines);

    // Page 1: Title page and explaination of project
    cout << setw (49) << "QUADRATIC SOLVER";
    numlines = 4;
    vertspc (numlines);
    cout << setw (52) << " finds the roots for " << endl << endl;
    cout << setw (56) << " at most a quadratic function " << endl << endl;
    cout << setw (52) << "in the form of ... " << endl << endl;
    cout << setw (56) << "F(x) = A x^2 + B x^1 + C x^0" << endl;
    numlines = 7;
    vertspc (numlines);
    cout << setw (54) << "Press Enter to continue...";
    cin.get ();
    clearscreen ();

    do
      {	//while there is another f(x): Start of first Do-While
        do
          { //while f(x) is incorrect, answer equals 0: Start second Do-While
            numlines = 3;
            vertspc (numlines);
            //Page 2: Query's user for coefficients
            cout << setw (43) << "The form of the equation ";
            cout << "you are entering is... " << endl << endl << endl;
            cout << setw (54) << "F(x) = A x^2 + B x^1 + C x^0";
            cout << endl << endl << endl;
            cout << setw (55) << "enter the coefficient of x^2: ";
            cin >> A;
            cout << endl;
            cout << setw (55) << "enter the coefficient of x^1: ";
            cin >> B;
            cout << endl;
            cout << setw (55) << "enter the coefficient of x^0: ";
            cin >> C;

            clearscreen ();
            numlines = 4;
            vertspc (numlines);

            // Page 3: Verifies the  user's entry
            cout << setw (51) << "The equation you entered is ...";
            cout << endl << endl << endl;
            cout << setw (27) << "F(x) = " << A <<" x^2 + " << B << " x^1 + ";
            cout << C << " x^0" << endl <<endl;
            cout << setw (43) << "Is F(x) correct?" << endl << endl << endl;
            cout << setw (50) << "Enter y for yes and n for no: " ;
            cin >> reply;
            ans = getreply (reply);

            while( ans > 1 ) //while-do response is invalid:Start Third Do-while
              {
                clearscreen ();
                numlines =4;
                vertspc (numlines);
                cout << setw (51) << "That is not a valid response." ;
                numlines =4;
                vertspc (numlines);

                cout << setw (51) << "The equation you entered is ...";
                cout << endl << endl << endl;
                cout << setw (27) << "F(x) = " << A <<" x^2 + " << B;
                cout << " x^1 + " << C << " x^0" << endl <<endl << endl;
                cout << setw (43) << "Is F(x) correct?" << endl << endl << endl;
                cout << setw (50) << "Please enter y for yes and n for no: " ;

                cin >> reply;
                ans = getreply (reply);
              } //invalid response: ends Third Do-While

            if (ans < 1) //Start of fourth while:just for answer no
              {
                clearscreen ();
                cout << endl << endl;
                cout << setw (50) << "Returning to the beginning!!";
                numlines = 3;
                vertspc (numlines);
              }
            else
              {
                cout << ans;
                cout << setw (54) <<"Press Enter to continue...";
                cin.get ();
              } //ends if,  just for answer no

          }
        while (ans < 1); //while f(x) is incorrect: ends Second Do-While

        clearscreen ();

        //This part is for determining the roots of the equation
        if ( A == 0)
          {
            if ( B == 0)
              {
	          if ( C == 0)
                {
                  j++;
                  numlines = 4;
                  vertspc (numlines);
                  twolines ( A, B, C);

                    cout << setw (50) << "is a constant function with";
                    cout << endl << endl;
                    cout << setw (51) << "trivial solution, the x-axis.";

                    fout << setw (53) << "Has trivial solution, the x-axis.";

                    numlines = 7;
                    vertspc (numlines);
                    cout << setw (49) <<"Press Enter to continue...";
                    cin.get ();
                  }
                else
                  {
                    j++;
                    numlines = 4;
                    vertspc (numlines);
                    twolines ( A , B, C);

                    cout << setw (44) << "is a constant function";
                    cout << endl << endl;
                    cout << setw (40) << "with no solution.";

                    fout << setw (51) << "Is a constant function";
                    fout << endl << endl;
                    fout << setw (43) <<"with no solution.";

                    numlines = 7;
                    vertspc (numlines);
                    cout << setw (49) <<"Press Enter to continue...";
                    cin.get ();
                  }
               }  
             else
               {
                 j++;
                 X1 = - C / B;
                 numlines = 4;
                 vertspc (numlines);
                 twolines ( A, B, C);
                 
                 if ( C == 0)
                   {
                     cout << setw (44) << "is a linear function" << endl;
                     cout << endl << setw (40)  << "with root x = 0.";

                     fout << setw (53) << "Is a linear function with root";
                     fout << setprecision (3) << "x = 0.";
                   }
                 else
                   {
                     cout << setw (42) << "is a linear function" << endl;
                     cout << endl << setw (40)  << "with root x = ";
                     cout << setprecision (3) << X1 << ".";

                     fout << setw (53) << "Is a linear function with root";
                     fout << setprecision (3) << "x = " << X1 << ".";
                   }

                 numlines = 7;
                 vertspc (numlines);
                 cout << setw (49) <<"Press Enter to continue...";
                 cin.get ();
               }
             }
           else
             {
               disc = ( B * B )- (4 * A * C);
               R = - B / ( 2 * A );
               P = fabs ( disc);
               T = ( sqrt (P)) / ( 2 * A );

               if ( disc >= 0 )
                 {
                   if ( disc == 0 )
                     {
                       j++;
                       numlines = 4;
                       vertspc (numlines);
                       twolines ( A, B, C);

                       cout << setw (42) << "is a linear function";
                       cout << endl << endl;
                       cout << setw (40) << "with root x = ";
                       cout << setprecision (3) << R << ".";

                       fout << setw (53) << "Is a linear function ";
                       fout << "with root x = ";
                       fout << setprecision (3) << R << ".";

                       numlines = 7;
                       vertspc (numlines);
                       cout << setw (49) <<"Press Enter to continue...";
                       cin.get ();
                     }
                   else
                     {
                       j++;
                       numlines = 4;
                       vertspc (numlines);
                       twolines ( A, B, C);

                       X1 = R + T;
                       X2 = R - T;

                       cout << setw (51) << "is a quadratic function with ";
                       cout << "roots" << endl << endl;
                       cout << setw (32) <<"x = ";
                       cout << setprecision (3) << X1 << " and x = ";
                       cout << setprecision (3) << X2 <<".";

                       fout << setw (47) << "Is a quadratic function with ";
                       fout << "roots" << endl << endl;
                       fout << setw (38) <<"x = ";
                       fout << setprecision (3) << X1 << " and x = ";
                       fout << setprecision (3) << X2 <<".";

                       numlines = 7;
                       vertspc (numlines);
                       cout << setw (49) <<"Press Enter to continue...";
                       cin.get ();
                     }
                   }
                 else
                   {
                     j++;
                     numlines = 4;
                     vertspc (numlines);
                     twolines ( A, B, C);

                     cout << setw (49) << "is a quadratic function with ";
                     cout << "roots" << endl << endl;
                     cout << setw (24) << setprecision (3) << "x = " << R;
                     cout << setprecision (3) << " + " << T << "i and x = ";
                     cout << setprecision (3) << R <<" - " << T <<"i.";

                     fout << setw (49) << "Is a quadratic function with ";
                     fout << "roots" << endl << endl;
                     fout << setw (24) << setprecision (3) << "x = " << R;
                     fout << setprecision (3) << " + " << T << "i and x = ";
                     fout << setprecision (3) << R <<" - " << T <<"i.";

                     numlines = 7;
                     vertspc (numlines);
                     cout << setw (49) <<"Press Enter to continue...";
                     cin.get ();
                   }
             }//closes the last else

           clearscreen ();
           numlines = 7;
           vertspc (numlines);
           cout << setw (50) << "Do you want to evaluate another F(x)?";
           cout << endl << endl << endl;
           cout << setw (50) << "Please enter y for yes and n for no: " ;
           cin >> reply;
           ans = getreply (reply);

           //invalid reply
           while ( ans > 1)//While answer is invalid: Start of fifth Do-While
             {
               cout << setw (51) << "That is not a valid response." ;
               numlines =4;
               vertspc (numlines);
               cout << setw (50) << "Do you want to evaluate another F(x)?";
               cout << endl << endl << endl;
               cout << setw (50) << "Please enter y for yes and n for no: " ;
               cin >> reply;
               ans = getreply (reply);
               clearscreen ();
             }//While answer is invalid: Ends of fifth Do-While

           if ( j == 5 )
             {
               thetextfile ();
               fout << "\f";
               j = 0;
               fout << setw (49) << "FUNCTIONS and SOLUTIONS";
               fout << endl << endl;
               thetextfile ();
             }
           else
             {
               thetextfile ();
             }

           clearscreen ();
      }
    while (ans == 1);//while there is another f(x): Ends of first Do-While

    numlines = 15;
    vertspc (numlines);
    cout << setw (50) << "Thank you for using the Quadratic Solver." ;
    cin.get ();
    fout.close ();
    return 0;
  }

// =============================================================================
 //This if-else function will be called into play when we need...
 //an answer from the user of yes or no
int getreply (char userreply)
  {
    int ans;

      switch (userreply)
        {
          case 'y': //answer 1/correct, 2/another f(x)
          case 'Y':
            ans = 1;
            return ans;

          case 'n': //answer 1/incorrect, 2/done
          case 'N':
            ans = 0;
            return ans;

          default:  //answer invalid
            ans = 2;
	        return ans;
        }
  }
 // =============================================================================
 //This for function will be called into play when we need...
 //Vertical Spacing
void vertspc (int num)		
  {
    int i;

    for ( i = 1; i < num; i++)
      {
	cout << endl;
      }
  }
//==============================================================================
//This void will output two lines that are common to all of the root outputs

void twolines (double A, double B, double C)
  {
    cout << setw (51) << "The solution for the function" << endl << endl;
    cout << setw (29) << "F(x) = " << A <<" x^2 + ";
    cout << B << " x^1 + " << C << " x^0" << endl << endl;

    fout << endl << endl << endl;
    fout << setw (29) << "F(x) = " << A <<" x^2 + ";
    fout << B << " x^1 + " << C << " x^0" << endl << endl << endl;
  }
//==============================================================================

void clearscreen ()
  {
    //clrscr ();                      // clear screen  borland c++
    system ("cls");                   // clear screen for others
  }
//==============================================================================

void thetextfile ()
  {
    fout << endl << endl << endl << endl;
    int i;

    for ( i = 1; i < 79; i++)
      {
        fout << "=";
      }
  }
//==============================================================================