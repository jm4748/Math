#pragma once


struct Vector2D
{
	real x, y;

	Vector2D() = default;
	Vector2D( real x, real y );
	Vector2D( real t );

	real& operator[]( uint4 i );

	Vector2D& operator+=( Vector2D u );
	Vector2D& operator-=( Vector2D u );
	Vector2D& operator*=( real s );
	Vector2D& operator/=( real s );
};


Vector2D operator+( Vector2D u, Vector2D v );
Vector2D operator-( Vector2D u, Vector2D v );
Vector2D operator*( real s, Vector2D u );
Vector2D operator*( Vector2D u, real s );
Vector2D operator/( Vector2D u, real s );
Vector2D operator-( Vector2D u );

real Length( Vector2D u );
real SqrLength( Vector2D u );
Vector2D Normalize( Vector2D u );

real Dot( Vector2D u, Vector2D v );
Vector2D Perp( Vector2D u );

real UnsignedAngleBetween( Vector2D u, Vector2D v );
real SignedAngleBetween( Vector2D u, Vector2D v );

Vector2D Project( Vector2D u, Vector2D v );
Vector2D Reject( Vector2D u, Vector2D v );
Vector2D Reflect( Vector2D u, Vector2D v );

real TriangleArea( Vector2D u, Vector2D v, Vector2D w );