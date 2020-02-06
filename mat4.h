#pragma once


#include "vec4.h"


struct Matrix4D
{
private:
	real n[ 4 ][ 4 ];

public:
	Matrix4D() = default;
	Matrix4D( real n00, real n01, real n02, real n03,
	          real n10, real n11, real n12, real n13,
	          real n20, real n21, real n22, real n23,
	          real n30, real n31, real n32, real n33 );
	Matrix4D( Vector4D u, Vector4D v, Vector4D w, Vector4D x );

	real& operator()( uint4 i, uint4 j );
	Vector4D& operator[]( uint4 j );
	Vector4D Row( uint4 i );

	Matrix4D& operator+=( Matrix4D a );
	Matrix4D& operator-=( Matrix4D a );
	Matrix4D& operator*=( real s );
	Matrix4D& operator/=( real s );
};


Matrix4D operator+( Matrix4D a, Matrix4D b );
Matrix4D operator-( Matrix4D a, Matrix4D b );
Matrix4D operator*( real s, Matrix4D a );
Matrix4D operator*( Matrix4D a, real s );
Matrix4D operator/( Matrix4D a, real s );
Matrix4D operator-( Matrix4D a );

Vector4D Transform( Vector4D u, Matrix4D a ); //use a to transform u (au)
Vector4D operator*( Matrix4D a, Vector4D u );

Matrix4D Transform( Matrix4D a, Matrix4D b ); //use b to transform a (ba)
Matrix4D operator*( Matrix4D a, Matrix4D b );