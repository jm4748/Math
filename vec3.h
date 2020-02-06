#pragma once


struct Vector3D
{
	real x, y, z;

	Vector3D() = default;
	Vector3D( real x, real y, real z );

	real& operator[]( uint4 i );

	Vector3D& operator+=( Vector3D u );
	Vector3D& operator-=( Vector3D u );
	Vector3D& operator*=( real s );
	Vector3D& operator/=( real s );
};


Vector3D operator+( Vector3D u, Vector3D v );
Vector3D operator-( Vector3D u, Vector3D v );
Vector3D operator*( real s, Vector3D u );
Vector3D operator*( Vector3D u, real s );
Vector3D operator/( Vector3D u, real s );
Vector3D operator-( Vector3D u );

real Length( Vector3D u );
real SqrLength( Vector3D u );
Vector3D Normalize( Vector3D u );

real Dot( Vector3D u, Vector3D v );
Vector3D Cross( Vector3D u, Vector3D v );

real UnsignedAngleBetween( Vector3D u, Vector3D v );

Vector3D Project( Vector3D u, Vector3D v );
Vector3D Reject( Vector3D u, Vector3D v );
Vector3D Reflect( Vector3D u, Vector3D v );

real TriangleArea( Vector3D u, Vector3D v, Vector3D w );


struct Point3D : Vector3D
{
	Point3D() = default;
	Point3D( real x, real y, real z );

	Point3D& operator=( Vector3D& u );
};