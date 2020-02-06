#include "basic.h"
#include "mat3.h"


Matrix3D::Matrix3D( real n00, real n01, real n02,
                    real n10, real n11, real n12,
                    real n20, real n21, real n22 )
{
	n[ 0 ][ 0 ] = n00; n[ 0 ][ 1 ] = n10; n[ 0 ][ 2 ] = n20;
	n[ 1 ][ 0 ] = n01; n[ 1 ][ 1 ] = n11; n[ 1 ][ 2 ] = n21;
	n[ 2 ][ 0 ] = n02; n[ 2 ][ 1 ] = n12; n[ 2 ][ 2 ] = n22;
}

Matrix3D::Matrix3D( Vector3D u, Vector3D v, Vector3D w )
{
	n[ 0 ][ 0 ] = u.x; n[ 0 ][ 1 ] = u.y; n[ 0 ][ 2 ] = u.z;
	n[ 1 ][ 0 ] = v.x; n[ 1 ][ 1 ] = v.y; n[ 1 ][ 2 ] = v.z;
	n[ 2 ][ 0 ] = w.x; n[ 2 ][ 1 ] = w.y; n[ 2 ][ 2 ] = w.z;
}


real& Matrix3D::operator()( uint4 i, uint4 j )
{
	return ( n[ j ][ i ] );
}

Vector3D& Matrix3D::operator[]( uint4 j )
{
	return ( *( Vector3D* )n[ j ] );
}

Vector3D Matrix3D::Row( uint4 i )
{
	return ( Vector3D( n[ 0 ][ i ], n[ 1 ][ i ], n[ 2 ][ i ] ) );
}


Matrix3D& Matrix3D::operator+=( Matrix3D a )
{
	n[ 0 ][ 0 ] += a.n[ 0 ][ 0 ]; n[ 0 ][ 1 ] += a.n[ 0 ][ 1 ]; n[ 0 ][ 2 ] += a.n[ 0 ][ 2 ];
	n[ 1 ][ 0 ] += a.n[ 1 ][ 0 ]; n[ 1 ][ 1 ] += a.n[ 1 ][ 1 ]; n[ 1 ][ 2 ] += a.n[ 1 ][ 2 ];
	n[ 2 ][ 0 ] += a.n[ 2 ][ 0 ]; n[ 2 ][ 1 ] += a.n[ 2 ][ 1 ]; n[ 2 ][ 2 ] += a.n[ 2 ][ 2 ];

	return ( *this );
}

Matrix3D& Matrix3D::operator-=( Matrix3D a )
{
	n[ 0 ][ 0 ] -= a.n[ 0 ][ 0 ]; n[ 0 ][ 1 ] -= a.n[ 0 ][ 1 ]; n[ 0 ][ 2 ] -= a.n[ 0 ][ 2 ];
	n[ 1 ][ 0 ] -= a.n[ 1 ][ 0 ]; n[ 1 ][ 1 ] -= a.n[ 1 ][ 1 ]; n[ 1 ][ 2 ] -= a.n[ 1 ][ 2 ];
	n[ 2 ][ 0 ] -= a.n[ 2 ][ 0 ]; n[ 2 ][ 1 ] -= a.n[ 2 ][ 1 ]; n[ 2 ][ 2 ] -= a.n[ 2 ][ 2 ];

	return ( *this );
}

Matrix3D& Matrix3D::operator*=( real s )
{
	n[ 0 ][ 0 ] *= s; n[ 0 ][ 1 ] *= s; n[ 0 ][ 2 ] *= s;
	n[ 1 ][ 0 ] *= s; n[ 1 ][ 1 ] *= s; n[ 1 ][ 2 ] *= s;
	n[ 2 ][ 0 ] *= s; n[ 2 ][ 1 ] *= s; n[ 2 ][ 2 ] *= s;

	return ( *this );
}

Matrix3D& Matrix3D::operator/=( real s )
{
	n[ 0 ][ 0 ] /= s; n[ 0 ][ 1 ] /= s; n[ 0 ][ 2 ] /= s;
	n[ 1 ][ 0 ] /= s; n[ 1 ][ 1 ] /= s; n[ 1 ][ 2 ] /= s;
	n[ 2 ][ 0 ] /= s; n[ 2 ][ 1 ] /= s; n[ 2 ][ 2 ] /= s;

	return ( *this );
}


Matrix3D operator+( Matrix3D a, Matrix3D b )
{
	return ( a += b );
}

Matrix3D operator-( Matrix3D a, Matrix3D b )
{
	return ( a -= b );
}

Matrix3D operator*( real s, Matrix3D a )
{
	return ( a *= s );
}

Matrix3D operator*( Matrix3D a, real s )
{
	return ( a *= s );
}

Matrix3D operator/( Matrix3D a, real s )
{
	return ( a /= s );
}

Matrix3D operator-( Matrix3D a )
{
	return ( -1.0f * a );
}


Matrix3D Scale( real sx, real sy, real sz )
{
	return ( Matrix3D( Vector3D( sx, 0.0f, 0.0f ),
	                   Vector3D( 0.0f, sy, 0.0f ),
	                   Vector3D( 0.0f, 0.0f, sz ) ) );
}

Matrix3D RotateX( real t )
{
	real c = Cos( t );
	real s = Sin( t ) * ( ( RIGHT_HANDED ) ? ( -1.0f ) : ( 1.0f ) );

	return ( Matrix3D( Vector3D( 1.0f, 0.0f, 0.0f ),
	                   Vector3D( 0.0f, c, -s ),
	                   Vector3D( 0.0f, s, c ) ) );
}

Matrix3D RotateY( real t )
{
	real c = Cos( t );
	real s = Sin( t ) * ( ( RIGHT_HANDED ) ? ( -1.0f ) : ( 1.0f ) );

	return ( Matrix3D( Vector3D( c, 0.0f, s ),
	                   Vector3D( 0.0f, 1.0f, 0.0f ),
	                   Vector3D( -s, 0.0f, c ) ) );
}

Matrix3D RotateZ( real t )
{
	real c = Cos( t );
	real s = Sin( t ) * ( ( RIGHT_HANDED ) ? ( -1.0f ) : ( 1.0f ) );

	return ( Matrix3D( Vector3D( c, -s, 0.0f ),
	                   Vector3D( s, c, 0.0f ),
	                   Vector3D( 0.0f, 0.0f, 1.0f ) ) );
}


Vector3D Transform( Vector3D u, Matrix3D a )
{
	return ( Vector3D( Dot( a.Row( 0 ), u ), Dot( a.Row( 1 ), u ), Dot( a.Row( 2 ), u ) ) );
}

Vector3D operator*( Matrix3D a, Vector3D u )
{
	return ( Transform( u, a ) );
}


Matrix3D Transform( Matrix3D a, Matrix3D b )
{
	return ( Matrix3D( Transform( a[ 0 ], b ), Transform( a[ 1 ], b ), Transform( a[ 2 ], b ) ) );
}

Matrix3D operator*( Matrix3D a, Matrix3D b )
{
	return ( Transform( b, a ) );
}