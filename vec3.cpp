#include "basic.h"
#include "vec3.h"


Vector3D::Vector3D( real x, real y, real z )
{
	this->x = x;
	this->y = y;
	this->z = z;
}


real& Vector3D::operator[]( uint4 i )
{
	return ( ( &x )[ i ] );
}


Vector3D& Vector3D::operator+=( Vector3D u )
{
	x += u.x;
	y += u.y;
	z += u.z;

	return ( *this );
}

Vector3D& Vector3D::operator-=( Vector3D u )
{
	x -= u.x;
	y -= u.y;
	z -= u.z;

	return ( *this );
}

Vector3D& Vector3D::operator*=( real s )
{
	x *= s;
	y *= s;
	z *= s;

	return ( *this );
}

Vector3D& Vector3D::operator/=( real s )
{
	x /= s;
	y /= s;
	z /= s;

	return ( *this );
}


Vector3D operator+( Vector3D u, Vector3D v )
{
	return ( u += v );
}

Vector3D operator-( Vector3D u, Vector3D v )
{
	return ( u -= v );
}

Vector3D operator*( real s, Vector3D u )
{
	return ( u *= s );
}

Vector3D operator*( Vector3D u, real s )
{
	return ( u *= s );
}

Vector3D operator/( Vector3D u, real s )
{
	return ( u /= s );
}

Vector3D operator-( Vector3D u )
{
	return ( -1.0f * u );
}


real Length( Vector3D u )
{
	return ( Sqrt( u.x * u.x + u.y * u.y + u.z * u.z ) );
}

real SqrLength( Vector3D u )
{
	return ( u.x * u.x + u.y * u.y + u.z * u.z );
}

Vector3D Normalize( Vector3D u )
{
	return ( u / Length( u ) );
}


real Dot( Vector3D u, Vector3D v )
{
	return ( u.x * v.x + u.y * v.y + u.z * v.z );
}

Vector3D Cross( Vector3D u, Vector3D v )
{
	return ( Vector3D( u.y * v.z - u.z * v.y, u.z * v.x - u.x * v.z, u.x * v.y - u.y * v.x ) );
}


real UnsignedAngleBetween( Vector3D u, Vector3D v )
{
	return ( Acos( Dot( u, v ) / ( Length( u ) * Length( v ) ) ) );
}


Vector3D Project( Vector3D u, Vector3D v )
{
	return ( ( Dot( u, v ) / Dot( v, v ) ) * v );
}

Vector3D Reject( Vector3D u, Vector3D v )
{
	return ( u - Project( u, v ) );
}

Vector3D Reflect( Vector3D u, Vector3D v )
{
	return ( 2.0f * Project( u, v ) - u );
}


real TriangleArea( Vector3D u, Vector3D v, Vector3D w )
{
	return ( Length( Cross( v - u, w - u ) ) / 2.0f );
}


Point3D::Point3D( real x, real y, real z )
: Vector3D( x, y, z )
{
}


Point3D& Point3D::operator=( Vector3D& u )
{
	x = u.x;
	y = u.y;
	z = u.z;

	return ( *this );
}