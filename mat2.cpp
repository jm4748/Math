#include "basic.h"
#include "mat2.h"


Matrix2D::Matrix2D( real n00, real n01, real n10, real n11 )
{
	n[ 0 ][ 0 ] = n00; n[ 0 ][ 1 ] = n10;
	n[ 1 ][ 0 ] = n01; n[ 1 ][ 1 ] = n11;
}

Matrix2D::Matrix2D( Vector2D u, Vector2D v )
{
	n[ 0 ][ 0 ] = u.x; n[ 0 ][ 1 ] = u.y;
	n[ 1 ][ 0 ] = v.x; n[ 1 ][ 1 ] = v.y;
}


real& Matrix2D::operator()( uint4 i, uint4 j )
{
	return ( n[ j ][ i ] );
}

Vector2D& Matrix2D::operator[]( uint4 j )
{
	return ( *( Vector2D* )n[ j ] );
}

Vector2D Matrix2D::Row( uint4 i )
{
	return ( Vector2D( n[ 0 ][ i ], n[ 1 ][ i ] ) );
}


Matrix2D& Matrix2D::operator+=( Matrix2D a )
{
	n[ 0 ][ 0 ] += a.n[ 0 ][ 0 ]; n[ 0 ][ 1 ] += a.n[ 0 ][ 1 ];
	n[ 1 ][ 0 ] += a.n[ 1 ][ 0 ]; n[ 1 ][ 1 ] += a.n[ 1 ][ 1 ];

	return ( *this );
}

Matrix2D& Matrix2D::operator-=( Matrix2D a )
{
	n[ 0 ][ 0 ] -= a.n[ 0 ][ 0 ]; n[ 0 ][ 1 ] -= a.n[ 0 ][ 1 ];
	n[ 1 ][ 0 ] -= a.n[ 1 ][ 0 ]; n[ 1 ][ 1 ] -= a.n[ 1 ][ 1 ];

	return ( *this );
}

Matrix2D& Matrix2D::operator*=( real s )
{
	n[ 0 ][ 0 ] *= s; n[ 0 ][ 1 ] *= s;
	n[ 1 ][ 0 ] *= s; n[ 1 ][ 1 ] *= s;

	return ( *this );
}

Matrix2D& Matrix2D::operator/=( real s )
{
	n[ 0 ][ 0 ] /= s; n[ 0 ][ 1 ] /= s;
	n[ 1 ][ 0 ] /= s; n[ 1 ][ 1 ] /= s;

	return ( *this );
}


Matrix2D operator+( Matrix2D a, Matrix2D b )
{
	return ( a += b );
}

Matrix2D operator-( Matrix2D a, Matrix2D b )
{
	return ( a -= b );
}

Matrix2D operator*( real s, Matrix2D a )
{
	return ( a *= s );
}

Matrix2D operator*( Matrix2D a, real s )
{
	return ( a *= s );
}

Matrix2D operator/( Matrix2D a, real s )
{
	return ( a /= s );
}

Matrix2D operator-( Matrix2D a )
{
	return ( -1.0f * a );
}


Matrix2D Scale( real sx, real sy )
{
	return ( Matrix2D( Vector2D( sx, 0.0f ), Vector2D( 0.0f, sy ) ) );
}

Matrix2D Rotate( real t )
{
	real c = Cos( t );
	real s = Sin( t );

	return ( Matrix2D( Vector2D( c, s ), Vector2D( -s, c ) ) );
}

Matrix2D Reflect( Vector2D u )
{
	Vector2D x( 1.0f, 0.0f );
	Vector2D y( 0.0f, 1.0f );

	return ( Matrix2D( 2.0f * Project( x, u ) - x, 2.0f * Project( y, u ) - y ) );
}


Vector2D Transform( Vector2D u, Matrix2D a )
{
	return ( Vector2D( Dot( a.Row( 0 ), u ), Dot( a.Row( 1 ), u ) ) );
}

Vector2D operator*( Matrix2D a, Vector2D u )
{
	return ( Transform( u, a ) );
}


Matrix2D Transform( Matrix2D a, Matrix2D b )
{
	return ( Matrix2D( Transform( a[ 0 ], b ), Transform( a[ 1 ], b ) ) );
}

Matrix2D operator*( Matrix2D a, Matrix2D b )
{
	return ( Transform( b, a ) );
}


real Determinant( Matrix2D a )
{
	return ( a( 0, 0 ) * a( 1, 1 ) - a( 0, 1 ) * a( 1, 0 ) );
}