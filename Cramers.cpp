// =============================================================================
//             Name: Sreece Goldberger
//           Course: CMPSC 201
//   Project Number: Extra Credit
//     NSD Due Date: 15 November 2011
// Project Due Date: 8 December 2011
// Program Filename: Cramers Rule
//   Input Filename: Matrix.txt
//  Output Filename: Cramers.txt
// =============================================================================
// Program Abstract: This program finds the values of all the variables of a 
//	                  system of equations
//   Input Required: An input textfile with the coefficients of x, constant first 
//                   the from x1 up to x9
//   Output Desired: The values of all the variables of a system of equations
// =============================================================================

#include <conio.h>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <cmath>
#include <math.h>
#include <stdlib.h>
//#include <ctime>
//#include <stdio.h>

using namespace std;

ofstream fout;
ifstream fin;

//Utility functions
void vertspc (int, char);
void pause (void);       
void divider (void);     

//==============================================================================

int main ()
  {
   //Funtion Declaration
    void intro (void);
    int GetDimension (void);  
//    void inputs (double [][10], int&);
    void inputs (double [][10], int);
    void Cramers (double [][10], int, double []);
//    void copy (double [][10], double [][10], int);
//    double any (double [][10], int [], int, int, int);
//    void exchange (double [][10], double [][10], int, int);  
//	void answer ( double [], double [][10], int, int);
	void tablef (double [], double [][10], int, int);
	void tablec (double [], double [][10], int, int); 
    void exit (void);
	
    //Variable declaration
    int A [10], dimension, end, eq, i, j, n;  
    double a [10][10], b [10][10], B [10]; 

    // =========================================================================
    // Alphabetized Variable Dictionary
    // =========================================================================
    //         a: The full array
	//         b: The undisturbed array
    //         B: Array that holds the answers to each Cramer iteration
	//         c: Working copy of the array
	//         d: The array used to set up the working copy of array
    // dimension: The dimension of the array
	//       end: Causes a row to not be part of array c
	//        eq: Equation counter
	//         j: Cramer counter
	//         n: Copy of the dimension of the array
    // =========================================================================
    
    fout.open ("Cramers.txt");
	fin.open ("Matrix.txt");

    cout << fixed << setprecision (3);
    fout << fixed << setprecision (3);

    intro ();
    eq = 0;
/*
    do
      {	
		j = 0;
		end = 0;
	    inputs (a, dimension);
	    
    	if (dimension != 0)
		  {
			copy (a, b, dimension);
            n = dimension;
            
		    do 
		      {
				for (i = 0; i <= dimension; i++)
				  {
					A [i] = 0;
				  }

			    B [j] = any (a, A, dimension, n, end);
			    j++;
	            exchange (a, b, dimension, j);
              }
		    while (j <= dimension);

		    eq++;		     
            answer (B, b, dimension, eq);
		 }
      }
    while (dimension != 0);
*/

    dimension = GetDimension ();
    
    while (dimension > 0)
      {
        eq++;
        inputs (a, dimension);
        Cramers (a, dimension, B);
        tablec (B, a, dimension, eq);
        tablef (B, a, dimension, eq);
        dimension = GetDimension ();
      }
      
    exit ();

    fout.close ();
    fin.close ();
//    pause ();
    return 0;
  }

// =============================================================================
//   Abstract: To the console, the introduction
// Parameters: Nothing is passed to the function
//     Output: Nothing is passed back to the program
// =============================================================================

void intro (void)
  {
    vertspc (3, 'c');
    cout << setw (48) << "THE MATRIX SOLVER by Cramer's Rule";
    vertspc (5, 'c');
    cout << setw (65) << "finds the variable values of a system of equations";
    vertspc (3, 'c');
    cout << setw (62) << "for at most a function with nine variables.";
    vertspc (3, 'c');
    cout << setw (65) << "If you have your own system of equations, the SOLVER";
    vertspc (3, 'c');
    cout << setw (65) << "is expecting a textfile called Cramer. Please enter";
    vertspc (3, 'c');
    cout << setw (64) << "your equations according to the instruction page.";
    vertspc (4, 'c');
	pause ();
	return;
  }

// =============================================================================

int GetDimension (void)
  {
    int dim;
    
    fin >> dim;
    
    return (dim);
  }

// =============================================================================
//   Abstract: Collects from a textfile all inputs
// Parameters: Array a and dimension
//     Output: Nothing is passed back
// =============================================================================

//void inputs (double a [][10], int &dimension)
void inputs (double a [][10], int dimension)
  {    
    int col, row;

    // =========================================================================
    // Local Alphabetized Variable Dictionary
    // =========================================================================
	//         a: Array of dimension rows by dimension + 1 columns
    //       col: Column counter
    // dimension: Dimension of the Matrix
    //       row: Row counter
    // =========================================================================
    
//	fin >> dimension;

	for (row = 1; row <= dimension; row ++)
	  {
		for (col = 0; col <= dimension; col ++)
		  {
			fin >> a [row][col];
		  }
	  }

    return;
  }
  
// =============================================================================

void Cramers (double a [][10], int dimension, double x [])
  {
    void copy (double [][10], int, double [10][10], int);
    double any (double [][10], int);
             
    double determinant [10], b [10][10];
    int k;
    
    for (k = 0; k <= dimension; k++)
      {
        copy (a, dimension, b, k);
        determinant [k] = any (b, dimension);
      }
      
    for (k = 1; k <= dimension; k++)
      {
        x [k] = determinant [k] / determinant [0];
      }
    
    return;
             
  }

// =============================================================================
//   Abstract: Copies the array three times
// Parameters: Arrays a, b, and the dimension
//     Output: Passes nothing back
// =============================================================================

//void copy (double a [][10], double b [][10], int dimension) 
void copy (double a [][10], int dimension, double b [][10], int k) 
  {    
    int col, row;

    // =========================================================================
    // Local Alphabetized Variable Dictionary
    // =========================================================================
	//         a: The full array 
	//         b: The undisturbed array
    //       col: Column counter
	// dimension: Dimension of the Matrix
	//       row: Row counter
    // =========================================================================
  
	for (row = 1; row <= dimension; row ++)
	  {
		for (col = 0; col <= dimension; col ++)
		  {
			b [row][col] = a [row][col];
		  }
		  
        if (k != 0)
          {
            b [row][k] = b [row][0];
          }
	  }

    return;
  }

//==============================================================================
//   Abstract: Finds the determinant 
// Parameters: Arrays a, A, the dimension, current dimension(n), end
//     Output: Passes back the value of the determinant 
// =============================================================================

//double any (double a [][10], int A [], int dimension, int n, int end)
double any (double a [][10], int dimension)
  {
    int Power (int, int);
    void ReduceMatrix (double [][10], int, double [][10], int);
//    void neg (int, int&);

	int col, i, j, m, row;
	double b [10][10], c [2][2], cofactor, det;

    // =========================================================================
    //Local Alphabetized Variable Dictionary
    // =========================================================================
	//         a: The full array
	//         A: The array the keeps track of what rows to skip
    //         c: Local place holders 
	//       col: The column counter
	//       det: The answer 
	// dimension: The dimension of the martix
	//       end: The any(recursive) counter
	//         i: Counter for array A
	//         j: Counter, because I needed another one
	//         m: The negative one starter
	//         n: The current dimension 
	//       row: Row counter for the full array
    // =========================================================================
/*
    det = 0;
	
	if (n == 2) // base case
	  {
	    col = 1;
	    
		for (row = 1; row <= dimension; row++)
		  { 
            for (j = 1; j <= end; j++)	
		      {
			    for (i = 0; i <= end; i++)
			      {
				    if (row == A[i])
				      {
					    if (A[i] == dimension)
					      {
						    //check next A[i]
					      }
					    else
					      {
					        row++;
					      }
				      }
				    else
				      {
					    //check next A[i]
			          }
			      }
			  }

			c [col][1] = a [row][1];
			c [col][2] = a [row][2];
			col++;
		  }		
		
	    det = c [1][1] * c [2][2] - c [1][2] * c [2][1];
        return det;
	  }	
	else // recursion
	  { 
		neg (n, m);
		
        for (row = 1; row <= dimension; row ++)
          {  
		    if (end == 0)
			  {
                A[0] = row;
			  }
			else
			  {
				for (j = 1; j <= end; j++)	
		          {
				    for (i = 0; i < end; i++)
				      {
					    if (row == A[i])
					      {
						    if (A[i] == dimension)
						      {
							    if (row == dimension)
							      {
								    return det;
							      }
							    else
							     {
								   //check next A[i]
							     }
						      }
						    else
						      {
						        row++;
						      }
					      }
				      }
				   }
				   
			    A [end] = row;
  		      }
  		     
		    m = m * -1;
		    cout << " a" << row << n << " " << a[row][n] << endl; 
		    system ("pause");
		    det = det + a [row][n] * m * 
                  any (a, A, dimension, (n - 1), (end + 1));
		  }		
	  }
*/

    if (dimension > 2) // recursive case
      {
        det = 0.0;
        
        for (col = 1; col <= dimension; col++)
          {
            ReduceMatrix (a, dimension, b, col);
            cofactor = Power (-1, dimension + col) * a [dimension][col];
            det = det + cofactor * any (b, dimension - 1); // recursive call
          }
      }
    else // base case
      {
        if (dimension == 2)
          {
            det = a [1][1] * a [2][2] - a [2][1] * a [1][2];
          }
      }
      
    return (det);
  }

// =============================================================================

void ReduceMatrix (double x [][10], int dim, double y [][10], int column)
  {
    int col, row;
    
    for (row = 1; row <= dim - 1; row++)
      {
        for (col = 1; col < column; col++)
          {
            y [row][col] = x [row][col];                   
          }
          
        for (col = column + 1; col <= dim; col++)
          {
            y [row][col - 1] = x [row][col];     
          }
      }
      
    return;
  }

// =============================================================================

int Power (int b, int p)
  {
    int x;
    
    if (p > 0)
      {
        x = b * Power (b, p - 1);
      }
    else
      {
        if (p == 0)
          {
            x = 1;
          }
      }
      
    return (x);
  }

// =============================================================================
//   Abstract: Determines whether the matrix starts at -1 or 1
// Parameters: The current dimension and the -1 starter
//     Output: Passes nothing back 
// =============================================================================

void neg (int n, int &m)
  {

	// =========================================================================
    // Local Alphabetized Variable Dictionary
    // =========================================================================
	//         m: The negative one starter
	//         n: The current dimension 
    // =========================================================================
  
	if (n % 2 == 0)
	  {
	 	m = 1;
	  }
	else
	  {
	    m = -1;
	  }

	return;
  }

//==============================================================================
//   Abstract: Exchanges the answers for the row we are on
// Parameters: Arrays a, b, dimension and the counter j
//     Output: The function passes the new array back 
// =============================================================================

void exchange (double a[][10], double b[][10], int dimension, int j)
  {
    int row, col;
    double k; 

    // =========================================================================
    // Local Alphabetized Variable Dictionary
    // =========================================================================
	//         a: The full array
	//         b: The undisurbed copy of the array
    //       col: Column, set value passed from the function
	//         d: Array used to set up the array c
	// dimension: The dimension of the matrix
    //         j: Cramer counter
	//         k: The empty space that exchanges one value for another 
	//       row: Row counter
    // =========================================================================

    for (row = 1; row <= dimension; row ++)
	  {
        for (col = 0; col <= dimension; col ++)
	      {
            a [row][col] = b [row][col];
	      }
      }

    for (row = 1; row <= dimension; row ++)
      {
	    k = a [row][0];
	    a [row][0] = a [row][j];
	    a [row][j] = k;
      }
   
    return ;

  }

// =============================================================================
//   Abstract: Calculates the answers and calls the output tables
// Parameters: Answers, the undisturbed array, dimension and the eq counter
//     Output: Calls outputs to the console and textfile
// =============================================================================

void answer (double B [], double b [][10], int dimension, int eq)
  {
	void tablef (double [], double [][10], int, int);
	void tablec (double [], double [][10], int, int); 

	int j;
	double ans [10];

	// =========================================================================
    //Local Alphabetized Variable Dictionary
    // =========================================================================
	//         a: The full array
	//       ans: The array that holds the answers
	//         b: The undisurbed copy of the array
    //         B: Array that holds the answers to each Cramer iteration
	// dimension: The dimension of the matrix
	//        eq: Equation counter
    //         j: Cramer counter
    // =========================================================================

	for (j = 1; j <= dimension; j++)
	  {
		ans [j] = B [j] / B [0];
      }

	tablec (ans, b, dimension, eq);
    tablef (ans, b, dimension, eq);  

	return;
  }
  
// =============================================================================
//   Abstract: The matrix, and the answers
// Parameters: The answers, a copy of the array, dimension and the eq counter
//     Output: Output to the console
// =============================================================================

void tablec (double ans [], double b [][10], int dimension, int eq)
  {
      int col, half, row, w;

    // =========================================================================
    // Local Alphabetized Variable Dictionary
    // =========================================================================
	//       ans: The answers to the matrix
    //         b: An undisturbed copy of the array 
    //       col: Column counter
	// dimension: Dimension of the Matrix
    //        eq: Equation counter
	//      half: Half of the dimension
    //       row: Row counter
	//         w: The variable width of setw based on dimension
    // =========================================================================

    half = ((dimension + 1) / 2);
	w = 40 - 15 * half;

	vertspc (3, 'c');
	cout << setw (50) << "The Equations for System #" << eq << ":";
	vertspc (5, 'c');

	for (row = 1; row <= dimension; row ++)
	  {
		cout << setiosflags (ios :: fixed) << setw (w) << " ";

	    for (col = 1; col < dimension; col ++)
	      {
		    cout << setw (8) << b [row][col] << " x" << col << " + ";
	      }
	      
        cout << setw (8) << b [row][dimension] << " x" << dimension;
	    cout << " = " << setw (8) << b [row][0];
        vertspc (3, 'c');
      }
      
	vertspc (2, 'c');
	cout << setw (46) << "The Results:";
	vertspc (3, 'c');

	for (row = 1; row <= dimension; row ++)
	  {
		cout << setw (35) << " x" << row << " = " << setw (7) << ans [row];
		vertspc (2, 'c');
	  }

    pause ();
    return;
  }

// =============================================================================
//   Abstract: The table of values progressing towards the approximation
// Parameters: The values of dk, sk, and counter
//     Output: Nothing is passed back to the program
// =============================================================================

void tablef (double ans [], double b [][10], int dimension, int eq)
  {
    int col, half, row, w;

    // =========================================================================
    // Local Alphabetized Variable Dictionary
    // =========================================================================
	//       ans: The answers to the matrix
    //         b: An undisturbed copy of the array 
    //       col: Column counter
	// dimension: Dimension of the Matrix
    //        eq: Equation counter
	//      half: Half of the dimension
    //       row: Row counter
	//         w: The variable width of setw based on dimension
    // =========================================================================

    half = ((dimension + 1) / 2);
	w = 40 - 15 * half;

	vertspc (3, 'f');
	fout << setw (50) << "The Equations for System #" << eq << ":";
	divider ();
	vertspc (3, 'f');

	for (row = 1; row <= dimension; row ++)
	  { 
		fout << setiosflags (ios :: fixed) << setw (w) << " ";
	      
	    for (col = 1; col < dimension; col ++)
	      {
		    fout << setw (8) << b [row][col] << " x" << col << " + ";
	      }
 
	    fout << setw (8) << b [row][dimension] << " x" << dimension;
	    fout << " = " << setw (7) << b [row][0];
	    vertspc (3, 'f');
	  }

	vertspc (4, 'f');
	fout << setw (46) << "The Results:";
	vertspc (3, 'f');
	
	for (row = 1; row <= dimension; row ++)
	  {
		fout << setw (35) << " x" << row << " = " << setw (7) << ans [row];
		vertspc (3, 'f');
	  }

    fout << "\f";
    return;
  }

// =============================================================================
//   Abstract: This is the end
// Parameters: Nothing passed to function
//     Output: Nothing passed back to program
// =============================================================================

void exit ()
  {
    vertspc (10, 'c');
    cout << setw (59) << "Thank you for using the MATRIX SOLVER." ;
    vertspc (3, 'c');
	cin.get ();
//    pause ();

    return;
  }

// =============================================================================
// Utility Functions
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
    vertspc (3, 'c');
    cout << setw (54) <<"Press Enter to continue...";
    cin.get ();
    system ("cls");
    return;                   
  }

// =============================================================================
//   Abstract: A dividing line to the textfile 
// Parameters: Nothing is passed to the function
//     Output: Nothing is returned to the program
// =============================================================================

void divider (void)
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
  
			
	       
