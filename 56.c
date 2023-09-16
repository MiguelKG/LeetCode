#include <stdio.h>
#include <stdlib.h>

int** merge(int** intervals, int intervalsSize, int *intervalsColSize, int* returnSize, int** returnColumnSizes);

int main () {
    const int SIZE = 5;
    int **entry = ( int** ) malloc( SIZE * sizeof( int* ) );
    for ( int i = 0; i < SIZE; i++ ) {
        entry[ i ] = ( int* ) malloc ( 2 * sizeof( int ) );
    }
    entry[ 0 ][ 0 ] = 2;
    entry[ 0 ][ 1 ] = 3;
    entry[ 1 ][ 0 ] = 4;
    entry[ 1 ][ 1 ] = 5;
    entry[ 2 ][ 0 ] = 6;
    entry[ 2 ][ 1 ] = 7;
    entry[ 3 ][ 0 ] = 8;
    entry[ 3 ][ 1 ] = 9;
    entry[ 4 ][ 0 ] = 1;
    entry[ 4 ][ 1 ] = 10;

    int intervalsColSize = 2;
    int *returnColumnSizes;
    int returnSize;
    int **result = merge ( entry, SIZE, &intervalsColSize, &returnSize, &returnColumnSizes);
    for ( int i = 0; i < returnSize; i++ ) {
        for ( int i2 = 0; i2 < 2; i2++ ) {
            printf( "%d ", result[ i ][ i2 ] );
        }
        printf( "\n" );
    }
}

int** merge( int** intervals, int intervalsSize, int *intervalsColSize, int* returnSize, int** returnColumnSizes ) {

    *returnSize = intervalsSize;

    int toggle = 0;
    int *pElem;
    int *elem;

    for ( int i = 0; i < intervalsSize; i++ ) {
        pElem = intervals[ i ];
        
        for ( int i2 = 0; i2 < intervalsSize; i2++ ) {
            if ( intervals[ i ][ 0 ] == -1 ) break;

            if (
                intervals[ i ] == intervals[ i2 ] ||
                intervals[ i2 ][ 0 ] == -1 
            ) continue;

            elem = intervals[ i2 ];
            toggle = 0;

            if ( pElem[ 0 ] >= elem[ 0 ] && pElem[ 1 ] <= elem[ 1 ] ) {
                pElem[ 0 ] = -1;
                toggle = 1;
            } else
            if ( elem[ 0 ] >= pElem[ 0 ] && elem[ 1 ] <= pElem[ 1 ] ) {
                elem[ 0 ] = pElem[ 0 ];
                elem[ 1 ] = pElem[ 1 ];
                pElem[ 0 ] = -1;
                toggle = 1;
            } else
            if ( pElem[ 1 ] >= elem[ 0 ] && pElem[ 1 ] <= elem[ 1 ] ) {
                elem[ 0 ] = pElem[ 0 ];
                pElem[ 0 ] = -1;
                toggle = 1;
            } else
            if ( elem[ 1 ] >= pElem[ 0 ] && elem[ 1 ] <= pElem[ 1 ] ) {
                elem[ 1 ] = pElem[ 1 ]; 
                pElem[ 0 ] = -1;
                toggle = 1;
            } else
            if ( pElem[ 0 ] <= elem[ 1 ] && pElem[ 0 ] >= elem[ 0 ] ) {
                elem[ 1 ] = pElem[ 1 ];
                pElem[ 0 ] = -1;
                toggle = 1;
            } else
            if ( elem[ 0 ] <= pElem[ 1 ] && elem[ 0 ] >= pElem[ 0 ] ) {
                elem[ 0 ] = pElem[ 0 ];
                pElem[ 0 ] = -1;
                toggle = 1;
            }

            if ( toggle == 1 ) {
                ( *returnSize )--;
            }
        }
    }

    int subIndex = 0;
    int **result = ( int** ) malloc( *returnSize * sizeof( int* ) );
    *returnColumnSizes = ( int* ) malloc ( *returnSize * sizeof( int ) );
    
    for ( int i = 0; i < intervalsSize; i++ ) {
        if ( intervals[ i ][ 0 ] != -1 ) {
            result[ i - subIndex ] = ( int* ) malloc ( 2 * sizeof( int ) );
            result[ i - subIndex ][ 0 ] = intervals[ i ][ 0 ];
            result[ i - subIndex ][ 1 ] = intervals[ i ][ 1 ];
            ( *returnColumnSizes )[ i - subIndex ] = 2;
        } else {
            subIndex++;
        }
    }

    return result;
}