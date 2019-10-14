// =============================================================================
//             Name: Sreece Goldberger
//           Course: CMPSC 201
//   Project Number: 4
//     NSD Due Date: 15 November 2011
// Project Due Date: 8 December 2011
// Program Filename: GaussJordan.cpp
//   Input Filename: Matrix.txt
//  Output Filename: Matricies.txt
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
#include <stdlib.h>
#include <ctime>
#include <stdio.h>

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
    void inputs (double [][10], int&);
    void copy (double [][10], double [][10], int);
	void tablef (double [][10], double [][10], int, int);
	void tablec (double [][10], double [][10], int, int); 
    void find (double [][10], int, int);     
    void exit (void);
	
    //Variable declaration
    int dimension, j;
    double a [10][10], b [10][10];

    // =========================================================================
    // Alphabetized Variable Dictionary
    // =========================================================================
    //         a: Multi-dimensional array
	//         b: Copy of the Multi-dimensional array
    // dimension: The return from the switch, 1 for y, 0 for n, 2 for all else
	//         j: Matrix counter
    // =========================================================================

    fout.open ("Matricies.txt");
	fin.open ("Matrix.txt");

    cout << fixed << setprecision (3);
    fout << fixed << setprecision (3);
    
    j = 0;
    intro ();

    do
      {	
	    j++;
	    inputs (a, dimension);
	    
    	if (dimension != 0)
		  {
			copy (a, b, dimension);
    	    find (a, dimension, j);
		    tablec (a, b, dimension, j);
		    tablef (a, b, dimension, j);   
		  }
      }
    while (dimension != 0);

    exit ();
    
    fout.close ();
	fin.close ();

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
    cout << setw (48) << "THE MATRIX SOLVER";
    vertspc (5, 'c');
    cout << setw (65) << "finds the variable values of a system of equations";
    vertspc (3, 'c');
    cout << setw (62) << "for at most a function with nine variables.";
    vertspc (3, 'c');
    cout << setw (65) << "If you have your own system of equations, the SOLVER";
    vertspc (3, 'c');
    cout << setw (65) << "is expecting a textfile called Matrix. Please enter";
    vertspc (3, 'c');
    cout << setw (64) << "your equations according to the instruction page.";
    vertspc (4, 'c');

	pause ();

	return;
  }

// =============================================================================
//   Abstract: Collects from the user all inputs
// Parameters: Array a and the dimension
//     Output: Collect and pass all back to function
// =============================================================================

void inputs (double a [][10], int &dimension)
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
    
	fin >> dimension;

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
//   Abstract: Copies the inputs from the user
// Parameters: Arrays a, b, and the dimension
//     Output: Collect and pass all back to function
// =============================================================================

void copy (double a [][10], double b [][10], int dimension)
  {    
    int col, row;

    // =========================================================================
    // Local Alphabetized Variable Dictionary
    // =========================================================================
	//         a: Array of dimension rows by dimension + 1 columns
	//         b: Copy of the array
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
	  }

    return;
  }

// =============================================================================
//   Abstract: Calculates the answer
// Parameters: Array a, the dimension , and the equation counter
//     Output: Nothing is passed back to the program
// =============================================================================

void find (double a [][10], int dimension, int j)
  {    
	void matrix (double [][10], int);

	int col, diag, row;
	double neg, recip;

    // =========================================================================
    // Local Alphabetized Variable Dictionary
    // =========================================================================
	//         a: Array of dimension rows by dimension + 1 columns
    //       col: Column counter
	//      diag: Diagonal trakcer, the 1s
    // dimension: Dimension of the Matrix
	//         j: Equation counter
	//       neg: Negative of the working row
	//     recip: Reciprical of the Diagonal 
    //       row: Row counter
    // =========================================================================

    vertspc (5, 'c');
    cout << setw (54) << "The Equations for System #" << j << ":";
    vertspc (4, 'c');

	matrix (a, dimension);
    
    for (diag = 1; diag <= dimension; diag ++)
	  {
	    recip = a [diag][diag];

		for (col = 0; col <= dimension; col ++)
		  {
			a [diag][col] = (a [diag][col]) / recip;
		  }
		  
        matrix (a, dimension);

		for (row = 1; row <= dimension; row ++)
		  {
			if (row != diag)
			  {
				neg = - a [row][diag];

				for (col = 0; col <= dimension; col ++)
				  {
					a [row][col] = a [row][col] + a [diag][col] * neg;
  				  }
  				  
				matrix (a, dimension);
			  }
		  }
      }

    return;
  }

// =============================================================================
//   Abstract: The system of equations progressing towards the answers
// Parameters: Array a and dimension
//     Output: Nothing is passed back to the program
// =============================================================================

void matrix (double a [][10], int dimension)
  {
    void step (void);

    int col, half, row, w;

    // =========================================================================
    // Local Alphabetized Variable Dictionary
    // =========================================================================
	//         a: Array of dimension rows by dimension + 1 columns
    //       col: Column counter
	// dimension: Dimension of the Matrix
	//      half: Half of the dimension
    //       row: Row counter
    //         w: Variable setw based on dimension
    // =========================================================================

	half = ((dimension + 3) / 2);
	w = 51 - 12 * half;
    
	for (row = 1; row <= dimension; row ++)
	  {
        cout << setiosflags (ios :: fixed) << setw (w) << " ";

	    for (col = 0; col <= dimension; col ++)
		  {
			cout << setw (10) << a [row][col];
		  }

        vertspc (2, 'c');
	  }

	step ();
    vertspc (3, 'c');
    return;
  }

// =============================================================================
//   Abstract: The stepped pause, with no need to press enter
// Parameters: Nothing passed to function
//     Output: Nothing is passed back to the program
// =============================================================================

void step (void) 
  {
	time_t time1, time2;

    // =========================================================================
    // Local Alphabetized Variable Dictionary
    // =========================================================================
    // time1: ???
    // time2: ???
    // =========================================================================
    
    time1 = time(NULL);

    do
      {
        time2 = time(NULL);
      }
    while (time1 == time2);

    return;
  }

// =============================================================================
//   Abstract: Prints the system of equations and answers to the console
// Parameters: Arrays a and b, dimension, and equation counter
//     Output: Nothing is passed back to the program
// =============================================================================

void tablec (double a[][10], double b[][10], int dimension, int j)
  {
    int col, half, row, w;

    // =========================================================================
    // Local Alphabetized Variable Dictionary
    // =========================================================================
    //         a: The array
    //         b: A copy of the array
    //       col: Column counter
	// dimension: Dimension of the Matrix
	//         j: Equation counter
	//      half: Half of the dimension
    //       row: Row counter
    //         w: Variable setw based on dimension
    // =========================================================================

    half = ((dimension + 3) / 2);
	w = 45 - 12 * half;

    pause ();

	vertspc (3, 'c');
	cout << setw (53) << "The Equations for System #" << j << ":";
	vertspc (5, 'c');

	for (row = 1; row <= dimension; row ++)
	  {
		cout << setiosflags (ios :: fixed) << setw (w) << " ";;

	    for (col = 1; col <dimension; col ++)
		  {
		    cout << setw (7) << b [row][col] << " x" << col << " + ";
		  }

		cout << setw (7) << b [row][dimension] << " x" << col;
		cout << " = " << setw (7) << b [row][0];

	    vertspc (2, 'c');
      }
      
	vertspc (3, 'c');
	cout << setw (49) << "The Results are...";
	vertspc (3, 'c');

	for (row = 1; row <= dimension; row ++)
	  {
		cout << setw (35) << " x" << row << " = " << setw(7) << a [row][0];
		vertspc (2, 'c');
	  }

    pause ();
    return;
  }

// =============================================================================
//   Abstract: Prints the system of equations and answers to the textfile
// Parameters: Arrays a and b, dimension, and equation counter
//     Output: Nothing is passed back to the program
// =============================================================================

void tablef (double a [][10], double b [][10], int dimension, int j)
  {
    int col, half, row,  w;

    // =========================================================================
    // Local Alphabetized Variable Dictionary
    // =========================================================================
	//         a: The array
    //       col: Column counter
	// dimension: Dimension of the Matrix
	//         j: Equation counter
	//      half: Half of the dimension
    //       row: Row counter
    //         w: Variable setw based on dimension
    // =========================================================================

    half = ((dimension + 1) / 2);
	w = 40 + 5 * half;

	vertspc (3, 'f');
	fout << setw (53) << "The Equations for System #" << j << ":";
    divider ();
	vertspc (3, 'f');
    
	for (row = 1; row <= dimension; row ++)
	  { 
		fout << setiosflags (ios :: fixed) << setw (w) << " ";

        for (col = 1; col < dimension; col ++)
          {
	        fout << setw (6) << b [row][col] << " x" << col << " + ";
	      }

        fout << setw (6) << b [row][dimension] << " x" << col;
	    fout << " = " << setw (7) << b [row][0];

	    vertspc (2, 'f');
	  }

	vertspc (3, 'f');
    fout << setw (49) << "The Results are...";
	vertspc (3, 'f');
	
	for (row = 1; row <= dimension; row ++)
	  {
		fout << setw (35) << " x" << row << " = " << setw (7) << a [row][0];
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

void exit (void)
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
	    case 'c': for (i = 1; i < num; i++)
                    {
	                  cout << endl;
                    }
                    
		          break;
                  
        case 'f': for (i = 1; i < num; i++)
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

void divider ()
  {
    int i;

    // =========================================================================
    // Local Alphabetized Variable Dictionary
    // =========================================================================
    //    i: Counts from one to the number passed from the program
    // =========================================================================

    vertspc (2, 'f');

    for (i = 1; i < 79; i++)
      {
        fout << "=";
      }

    vertspc (2, 'f');

    return;
  }

//==============================================================================



 

 
