#pragma once


#include "vec3.h"


#ifndef RIGHT_HANDED
#define RIGHT_HANDED false
#endif


struct Matrix3D
{
private:
	real n[ 3 ][ 3 ];

public:
	Matrix3D() = default;
	Matrix3D( real n00, real n01, real n02,
	          real n10, real n11, real n12,
	          real n20, real n21, real n22 );
	Matrix3D( Vector3D u, Vector3D v, Vector3D w );

	real& operator()( uint4 i, uint4 j );
	Vector3D& operator[]( uint4 j );
	Vector3D Row( uint4 i );

	Matrix3D& operator+=( Matrix3D a );
	Matrix3D& operator-=( Matrix3D a );
	Matrix3D& operator*=( real s );
	Matrix3D& operator/=( real s );
};


Matrix3D operator+( Matrix3D a, Matrix3D b );
Matrix3D operator-( Matrix3D a, Matrix3D b );
Matrix3D operator*( real s, Matrix3D a );
Matrix3D operator*( Matrix3D a, real s );
Matrix3D operator/( Matrix3D a, real s );
Matrix3D operator-( Matrix3D a );

Matrix3D Scale( real sx, real sy, real sz );
Matrix3D RotateX( real t );
Matrix3D RotateY( real t );
Matrix3D RotateZ( real t );

Vector3D Transform( Vector3D u, Matrix3D a ); //use a to transform u (au)
Vector3D operator*( Matrix3D a, Vector3D u );

Matrix3D Transform( Matrix3D a, Matrix3D b ); //use b to transform a (ba)
Matrix3D operator*( Matrix3D a, Matrix3D b );