// Reading a random-access file sequentially
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
    FILE *cfPtr; // credit.dat file pointer
    int result; // used to test whether fread read any bytes
    // create clientData with default information
    struct clientData client = { 0, "", "", 0.0 };
    // fopen opens the file; exits if file cannot be opened
    if ( ( cfPtr = fopen( "credit.dat", "rb" ) ) == NULL ) {
        puts( "File could not be opened." );
    } // end if
    else {
        printf( "%-6s%-16s%-11s%10s\n", "Acct", "Last Name",
        "First Name", "Balance" );
        // read all records from file (until eof)
        while ( !feof( cfPtr ) ) {
            result = fread( &client, sizeof( struct clientData ), 1, cfPtr );
            // display record
            if ( result != 0 && client.acctNum != 0 ) {
                printf( "%-6d%-16s%-11s%10.2f\n",
                client.acctNum, client.lastName,
                client.firstName, client.balance );
            } // end if
        } // end while
        fclose( cfPtr ); // fclose closes the file
    } // end else
} // end main
