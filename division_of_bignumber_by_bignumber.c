#include<stdio.h>
#include<string.h>
#include<stdlib.h> 

typedef signed short int_least16_t;

// swapping two charaters
void swap( char* a, char* b ) {
  char p = *a;
  *a = *b;
  *b = p;
}

//reversing string
void reverse( char* str ) {
	int_least16_t len = strlen( str );
	int i;
	for( i = 0; i < len / 2; i++ ) swap( str + i, str + len - i -1 );
}


// substracting divs from divd 

_Bool sub( char* divd, char* divs, char* result ) {
	int_least16_t len1 = strlen( divd ), len2 = strlen( divs );
	while( divd[ len1 - 1 ] == '0' && len1 > 1 ) len1--, divd[ len1 ] = '\0';
	while( divs[ len2 - 1 ] == '0' && len2 > 1 ) len2--, divs[ len2 ] = '\0';
	if( len2 > len1 ) return 1;
	int_least16_t i;
	if( len2 == len1 ) {
		for( i = len1-1; i >= 0; i-- ) {
			if( divs[ i ] > divd[ i ] ) return 1;
			if( divd[ i ] > divs[ i ] ) break;
		}
	}
	
	char* _result = ( char* )malloc( ( len1 + 1 ) * sizeof( char ) );
	char* _divs   = ( char* )malloc( ( len1 + 1 ) * sizeof( char ) );
	memset( _result, 0, sizeof( _result ) );
	memset( _divs,   0, sizeof( divs ) );
	strcpy( _divs, divs );
	for( i = len2; i < len1; i++ ) _divs[ i ] = '0';
	int_least16_t s = 0;
	for( i = 0; i < len1; i++ ) {
		int_least16_t a = divd[ i ] - _divs[ i ] - s;
		if( a < 0 ) a += 10, s = 1;
		else s = 0;
		_result[ i ] = a + '0';
	}
	while( _result[ len1 - 1 ] == '0' && len1 > 1 ) len1--, _result[ len1 ] = '\0';
	strcpy(result, _result);
	return 0;
} 	

// dividing between two big number

void divide( char* divd, char* divs, char** quot, char** rest ) {
	reverse( divd ); reverse( divs );
	int_least16_t i;
	int_least16_t len1 = strlen( divd ), len2 = strlen( divs );
	*quot = ( char* )malloc( ( len1 + 1 ) * sizeof( char ) );
	*rest = ( char* )malloc( ( len1 + 1 ) * sizeof( char ) );
	memset( *quot, 0, sizeof( *quot ) );
	memset( *rest, 0, sizeof( *rest ) );
	while( divd[ len1 - 1 ] == '0' && len1 > 1 ) len1--, divd[ len1 ] = '\0';
	while( divs[ len2 - 1 ] == '0' && len2 > 1 ) len2--, divs[ len2 ] = '\0';
	for( i = len1 - 1;i >= 0; i--) {
    char *trest = ( char* )malloc( ( len1 - i + 1 ) * sizeof( char ) );
    strcpy( trest, *rest );
// 		strcpy((*rest)+1, *rest);
		( *rest )[ 0 ] = divd[ i ];
		strcpy( ( *rest ) + 1, trest );
		( *quot )[ i ] = '0';
		while( !sub( *rest, divs, *rest ) ) ( *quot )[ i ]++;
	}
	
	while( ( *quot )[ len1 - 1 ] == '0' && len1 > 1 ) len1--, ( *quot )[ len1 ] = '\0';
	len1 = strlen( *rest );
	while( ( *rest )[ len1 - 1 ] == '0' && len1 > 1 ) len1--, ( *rest )[ len1 ] = '\0';
	reverse( *quot );
	reverse( *rest );
}

int main() {
    char divd[] = "15423151234513451345134513451345345134515423151234513451345134513451345345134515423151234513451345134513451345345134515423151234513451345134513451345345134515423151234513451345134513451345345134515423151234513451345134513451345345134523", 
         divs[] = "154231512345134513451345134513453451345",
         *quotient,
         *rest;
    divide( divd, divs, &quotient, &rest );
    printf( "%s %s\n", quotient, rest );
}
