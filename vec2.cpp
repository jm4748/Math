#include "basic.h"
#include "vec2.h"


Vector2D::Vector2D( real x, real y )
{
	this->x = x;
	this->y = y;
}

Vector2D::Vector2D( real t )
{
	x = Cos( t );
	y = Sin( t );
}


real& Vector2D::operator[]( uint4 i )
{
	return ( ( &x )[ i ] );
}


Vector2D& Vector2D::operator+=( Vector2D u )
{
	x += u.x;
	y += u.y;

	return ( *this );
}

Vector2D& Vector2D::operator-=( Vector2D u )
{
	x -= u.x;
	y -= u.y;

	return ( *this );
}

Vector2D& Vector2D::operator*=( real s )
{
	x *= s;
	y *= s;

	return ( *this );
}

Vector2D& Vector2D::operator/=( real s )
{
	x /= s;
	y /= s;

	return ( *this );
}


Vector2D operator+( Vector2D u, Vector2D v )
{
	return ( u += v );
}

Vector2D operator-( Vector2D u, Vector2D v )
{
	return ( u -= v );
}

Vector2D operator*( real s, Vector2D u )
{
	return ( u *= s );
}

Vector2D operator*( Vector2D u, real s )
{
	return ( u *= s );
}

Vector2D operator/( Vector2D u, real s )
{
	return ( u /= s );
}

Vector2D operator-( Vector2D u )
{
	return ( -1.0f * u );
}


real Length( Vector2D u )
{
	return ( Sqrt( u.x * u.x + u.y * u.y ) );
}

real SqrLength( Vector2D u )
{
	return ( u.x * u.x + u.y * u.y );
}

Vector2D Normalize( Vector2D u )
{
	return ( u / Length( u ) );
}


real Dot( Vector2D u, Vector2D v )
{
	return ( u.x * v.x + u.y * v.y );
}

Vector2D Perp( Vector2D u )
{
	return ( Vector2D( -u.y, u.x ) );
}


real UnsignedAngleBetween( Vector2D u, Vector2D v )
{
	return ( Acos( Dot( u, v ) / ( Length( u ) * Length( v ) ) ) );
}

real SignedAngleBetween( Vector2D u, Vector2D v )
{
	real t = PositiveAngleFromX( v.x, v.y ) - PositiveAngleFromX( u.x, u.y );

	return ( ( Abs( t ) > pi ) ? ( ( piMul2 - Abs( t ) ) * -Sign( t ) ) : ( t ) );
}


Vector2D Project( Vector2D u, Vector2D v )
{
	return ( ( Dot( u, v ) / Dot( v, v ) ) * v );
}

Vector2D Reject( Vector2D u, Vector2D v )
{
	return ( u - Project( u, v ) );
}

Vector2D Reflect( Vector2D u, Vector2D v )
{
	return ( 2.0f * Project( u, v ) - u );
}


real TriangleArea( Vector2D u, Vector2D v, Vector2D w )
{
	Vector2D vu = v - u;
	Vector2D wu = w - u;

	return ( Abs( vu.x * wu.y - vu.y * wu.x ) / 2.0f );
}