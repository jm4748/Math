#pragma once


#include "vec2.h"


struct Matrix2D
{
private:
	real n[ 2 ][ 2 ];

public:
	Matrix2D() = default;
	Matrix2D( real n00, real n01, real n10, real n11 );
	Matrix2D( Vector2D u, Vector2D v );

	real& operator()( uint4 i, uint4 j );
	Vector2D& operator[]( uint4 j );
	Vector2D Row( uint4 i );

	Matrix2D& operator+=( Matrix2D a );
	Matrix2D& operator-=( Matrix2D a );
	Matrix2D& operator*=( real s );
	Matrix2D& operator/=( real s );
};


Matrix2D operator+( Matrix2D a, Matrix2D b );
Matrix2D operator-( Matrix2D a, Matrix2D b );
Matrix2D operator*( real s, Matrix2D a );
Matrix2D operator*( Matrix2D a, real s );
Matrix2D operator/( Matrix2D a, real s );
Matrix2D operator-( Matrix2D a );

Matrix2D Scale( real sx, real sy );
Matrix2D Rotate( real t );
Matrix2D Reflect( Vector2D u );

Vector2D Transform( Vector2D u, Matrix2D a ); //use a to transform u (au)
Vector2D operator*( Matrix2D a, Vector2D u );

Matrix2D Transform( Matrix2D a, Matrix2D b ); //use b to transform a (ba)
Matrix2D operator*( Matrix2D a, Matrix2D b );

real Determinant( Matrix2D a );