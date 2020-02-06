#pragma once


struct Vector4D
{
	real x, y, z, w;

	Vector4D() = default;
	Vector4D( real x, real y, real z, real w );

	real& operator[]( int i );

	Vector4D& operator+=( Vector4D u );
	Vector4D& operator-=( Vector4D u );
	Vector4D& operator*=( real s );
	Vector4D& operator/=( real s );
};


Vector4D operator+( Vector4D u, Vector4D v );
Vector4D operator-( Vector4D u, Vector4D v );
Vector4D operator*( real s, Vector4D u );
Vector4D operator*( Vector4D u, real s );
Vector4D operator/( Vector4D u, real s );
Vector4D operator-( Vector4D u );

real Length( Vector4D u );
real SqrLength( Vector4D u );
Vector4D Normalize( Vector4D u );

real Dot( Vector4D u, Vector4D v );