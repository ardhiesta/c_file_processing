// Creating a sequential file
#include <stdio.h>
int main( void )
{
    unsigned int account; // account number
    char name[ 30 ]; // account name
    double balance; // account balance
    FILE *cfPtr; // cfPtr = clients.dat file pointer
    // fopen opens file. Exit program if unable to create file
    if ( ( cfPtr = fopen( "clients.dat", "w" ) ) == NULL ) {
        puts( "File could not be opened" );
    } // end if
    else {
        puts( "Enter the account, name, and balance." );
        puts( "Enter EOF to end input." );
        printf( "%s", "? " );
        scanf( "%d%29s%lf", &account, name, &balance );
        // write account, name and balance into file with fprintf
        while ( !feof( stdin ) ) {
            fprintf( cfPtr, "%d %s %.2f\n", account, name, balance );
            printf( "%s", "? " );
            scanf( "%d%29s%lf", &account, name, &balance );
        } // end while
        fclose( cfPtr ); // fclose closes file
    } // end else
} // end main
