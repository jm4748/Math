#include "basic.h"
#include "vec4.h"


Vector4D::Vector4D( real x, real y, real z, real w )
{
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = w;
}


real& Vector4D::operator[]( int i )
{
	return ( ( &x )[ i ] );
}


Vector4D& Vector4D::operator+=( Vector4D u )
{
	x += u.x;
	y += u.y;
	z += u.z;
	w += u.w;

	return ( *this );
}

Vector4D& Vector4D::operator-=( Vector4D u )
{
	x -= u.x;
	y -= u.y;
	z -= u.z;
	w -= u.w;

	return ( *this );
}

Vector4D& Vector4D::operator*=( real s )
{
	x *= s;
	y *= s;
	z *= s;
	w *= s;

	return ( *this );
}

Vector4D& Vector4D::operator/=( real s )
{
	x /= s;
	y /= s;
	z /= s;
	w /= s;

	return ( *this );
}


Vector4D operator+( Vector4D u, Vector4D v )
{
	return ( u += v );
}

Vector4D operator-( Vector4D u, Vector4D v )
{
	return ( u -= v );
}

Vector4D operator*( real s, Vector4D u )
{
	return ( u *= s );
}

Vector4D operator*( Vector4D u, real s )
{
	return ( u *= s );
}

Vector4D operator/( Vector4D u, real s )
{
	return ( u /= s );
}

Vector4D operator-( Vector4D u )
{
	return ( -1.0f * u );
}


real Length( Vector4D u )
{
	return ( Sqrt( u.x * u.x + u.y * u.y + u.z * u.z + u.w * u.w ) );
}

real SqrLength( Vector4D u )
{
	return ( u.x * u.x + u.y * u.y + u.z * u.z + u.w * u.w );
}

Vector4D Normalize( Vector4D u )
{
	return ( u / Length( u ) );
}


real Dot( Vector4D u, Vector4D v )
{
	return ( u.x * v.x + u.y * v.y + u.z * v.z + u.w * v.w );
}