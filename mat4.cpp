#include "basic.h"
#include "mat4.h"


Matrix4D::Matrix4D( real n00, real n01, real n02, real n03,
                    real n10, real n11, real n12, real n13,
                    real n20, real n21, real n22, real n23,
                    real n30, real n31, real n32, real n33 )
{
	n[ 0 ][ 0 ] = n00; n[ 0 ][ 1 ] = n10; n[ 0 ][ 2 ] = n20; n[ 0 ][ 3 ] = n30;
	n[ 1 ][ 0 ] = n01; n[ 1 ][ 1 ] = n11; n[ 1 ][ 2 ] = n21; n[ 1 ][ 3 ] = n31;
	n[ 2 ][ 0 ] = n02; n[ 2 ][ 1 ] = n12; n[ 2 ][ 2 ] = n22; n[ 2 ][ 3 ] = n32;
	n[ 3 ][ 0 ] = n03; n[ 3 ][ 1 ] = n13; n[ 3 ][ 2 ] = n23; n[ 3 ][ 3 ] = n33;
}

Matrix4D::Matrix4D( Vector4D u, Vector4D v, Vector4D w, Vector4D x )
{
	n[ 0 ][ 0 ] = u.x; n[ 0 ][ 1 ] = u.y; n[ 0 ][ 2 ] = u.z; n[ 0 ][ 3 ] = u.w;
	n[ 1 ][ 0 ] = v.x; n[ 1 ][ 1 ] = v.y; n[ 1 ][ 2 ] = v.z; n[ 1 ][ 3 ] = v.w;
	n[ 2 ][ 0 ] = w.x; n[ 2 ][ 1 ] = w.y; n[ 2 ][ 2 ] = w.z; n[ 2 ][ 3 ] = w.w;
	n[ 3 ][ 0 ] = x.x; n[ 3 ][ 1 ] = x.y; n[ 3 ][ 2 ] = x.z; n[ 3 ][ 3 ] = x.w;
}


real& Matrix4D::operator()( uint4 i, uint4 j )
{
	return ( n[ j ][ i ] );
}

Vector4D& Matrix4D::operator[]( uint4 j )
{
	return ( *( Vector4D* )n[ j ] );
}

Vector4D Matrix4D::Row( uint4 i )
{
	return ( Vector4D( n[ 0 ][ i ], n[ 1 ][ i ], n[ 2 ][ i ], n[ 3 ][ i ] ) );
}


Matrix4D& Matrix4D::operator+=( Matrix4D a )
{
	n[ 0 ][ 0 ] += a[ 0 ][ 0 ]; n[ 0 ][ 1 ] += a[ 0 ][ 1 ]; n[ 0 ][ 2 ] += a[ 0 ][ 2 ]; n[ 0 ][ 3 ] += a[ 0 ][ 3 ];
	n[ 1 ][ 0 ] += a[ 1 ][ 0 ]; n[ 1 ][ 1 ] += a[ 1 ][ 1 ]; n[ 1 ][ 2 ] += a[ 1 ][ 2 ]; n[ 1 ][ 3 ] += a[ 1 ][ 3 ];
	n[ 2 ][ 0 ] += a[ 2 ][ 0 ]; n[ 2 ][ 1 ] += a[ 2 ][ 1 ]; n[ 2 ][ 2 ] += a[ 2 ][ 2 ]; n[ 2 ][ 3 ] += a[ 2 ][ 3 ];
	n[ 3 ][ 0 ] += a[ 3 ][ 0 ]; n[ 3 ][ 1 ] += a[ 3 ][ 1 ]; n[ 3 ][ 2 ] += a[ 3 ][ 2 ]; n[ 3 ][ 3 ] += a[ 3 ][ 3 ];

	return ( *this );
}

Matrix4D& Matrix4D::operator-=( Matrix4D a )
{
	n[ 0 ][ 0 ] -= a[ 0 ][ 0 ]; n[ 0 ][ 1 ] -= a[ 0 ][ 1 ]; n[ 0 ][ 2 ] -= a[ 0 ][ 2 ]; n[ 0 ][ 3 ] -= a[ 0 ][ 3 ];
	n[ 1 ][ 0 ] -= a[ 1 ][ 0 ]; n[ 1 ][ 1 ] -= a[ 1 ][ 1 ]; n[ 1 ][ 2 ] -= a[ 1 ][ 2 ]; n[ 1 ][ 3 ] -= a[ 1 ][ 3 ];
	n[ 2 ][ 0 ] -= a[ 2 ][ 0 ]; n[ 2 ][ 1 ] -= a[ 2 ][ 1 ]; n[ 2 ][ 2 ] -= a[ 2 ][ 2 ]; n[ 2 ][ 3 ] -= a[ 2 ][ 3 ];
	n[ 3 ][ 0 ] -= a[ 3 ][ 0 ]; n[ 3 ][ 1 ] -= a[ 3 ][ 1 ]; n[ 3 ][ 2 ] -= a[ 3 ][ 2 ]; n[ 3 ][ 3 ] -= a[ 3 ][ 3 ];

	return ( *this );
}

Matrix4D& Matrix4D::operator*=( real s )
{
	n[ 0 ][ 0 ] *= s; n[ 0 ][ 1 ] *= s; n[ 0 ][ 2 ] *= s; n[ 0 ][ 3 ] *= s;
	n[ 1 ][ 0 ] *= s; n[ 1 ][ 1 ] *= s; n[ 1 ][ 2 ] *= s; n[ 1 ][ 3 ] *= s;
	n[ 2 ][ 0 ] *= s; n[ 2 ][ 1 ] *= s; n[ 2 ][ 2 ] *= s; n[ 2 ][ 3 ] *= s;
	n[ 3 ][ 0 ] *= s; n[ 3 ][ 1 ] *= s; n[ 3 ][ 2 ] *= s; n[ 3 ][ 3 ] *= s;

	return ( *this );
}

Matrix4D& Matrix4D::operator/=( real s )
{
	n[ 0 ][ 0 ] /= s; n[ 0 ][ 1 ] /= s; n[ 0 ][ 2 ] /= s; n[ 0 ][ 3 ] /= s;
	n[ 1 ][ 0 ] /= s; n[ 1 ][ 1 ] /= s; n[ 1 ][ 2 ] /= s; n[ 1 ][ 3 ] /= s;
	n[ 2 ][ 0 ] /= s; n[ 2 ][ 1 ] /= s; n[ 2 ][ 2 ] /= s; n[ 2 ][ 3 ] /= s;
	n[ 3 ][ 0 ] /= s; n[ 3 ][ 1 ] /= s; n[ 3 ][ 2 ] /= s; n[ 3 ][ 3 ] /= s;

	return ( *this );
}


Matrix4D operator+( Matrix4D a, Matrix4D b )
{
	return ( a += b );
}

Matrix4D operator-( Matrix4D a, Matrix4D b )
{
	return ( a -= b );
}

Matrix4D operator*( real s, Matrix4D a )
{
	return ( a *= s );
}

Matrix4D operator*( Matrix4D a, real s )
{
	return ( a *= s );
}

Matrix4D operator/( Matrix4D a, real s )
{
	return ( a /= s );
}

Matrix4D operator-( Matrix4D a )
{
	return ( -1.0f * a );
}


Vector4D Transform( Vector4D u, Matrix4D a )
{
	return ( Vector4D( Dot( a.Row( 0 ), u ),
	                   Dot( a.Row( 1 ), u ),
	                   Dot( a.Row( 2 ), u ),
	                   Dot( a.Row( 3 ), u ) ) );
}

Vector4D operator*( Matrix4D a, Vector4D u )
{
	return ( Transform( u, a ) );
}


Matrix4D Transform( Matrix4D a, Matrix4D b )
{
	return ( Matrix4D( Transform( a[ 0 ], b ),
	                   Transform( a[ 1 ], b ),
	                   Transform( a[ 2 ], b ),
	                   Transform( a[ 3 ], b ) ) );
}

Matrix4D operator*( Matrix4D a, Matrix4D b )
{
	return ( Transform( b, a ) );
}