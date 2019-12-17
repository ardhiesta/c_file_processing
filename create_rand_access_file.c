// Creating a random-access file sequentially
#include <stdio.h>
// clientData structure definition
struct clientData {
    unsigned int acctNum; // account number
    char lastName[ 15 ]; // account last name
    char firstName[ 10 ]; // account first name
    double balance; // account balance
}; // end structure clientData

int main( void )
{
    unsigned int i; // counter used to count from 1-100
    // create clientData with default information
    struct clientData blankClient = { 0, "", "", 0.0 };
    FILE *cfPtr; // credit.dat file pointer
    // fopen opens the file; exits if file cannot be opened
    if ( ( cfPtr = fopen( "credit.dat", "wb" ) ) == NULL ) {
        puts( "File could not be opened." );
    } // end if
    else {
        // output 100 blank records to file
        for ( i = 1; i <= 100; ++i ) {
            fwrite( &blankClient, sizeof( struct clientData ), 1, cfPtr );
        } // end for
        fclose ( cfPtr ); // fclose closes the file
    } // end else
} // end main
