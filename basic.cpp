#include "basic.h"


#ifndef CUSTOM_MATH
#define _USE_MATH_DEFINES
#include <cmath>
#endif


#ifdef CUSTOM_MATH
const real pi      = 3.1415926535f;
const real piMul2  = pi * 2.0f;
const real piDiv2  = pi / 2.0f;
const real piDiv4  = pi / 4.0f;
#else
const real pi      = ( real )M_PI;
const real piMul2  = ( real )M_PI * 2.0f;
const real piDiv2  = ( real )M_PI_2;
const real piDiv4  = ( real )M_PI_4;
#endif


real Sign( real t )
{
	     if ( t > 0.0f ) return (  1.0f );
	else if ( t < 0.0f ) return ( -1.0f );
	else                 return (  0.0f );
}


real Abs( real t )
{
#ifdef CUSTOM_MATH
	return ( ( t < 0.0f ) ? ( -t ) : ( t ) );
#else
	return ( abs( t ) );
#endif
}


real Pow( real t, sint4 s )
{
#ifdef CUSTOM_MATH
	if ( s < 0 )
	{
		t = 1.0f / t;
		s *= -1;
	}

	real r = 1.0f;

	for ( uint4 i = 0; i < ( uint4 )s; ++i )
	{
		r *= t;
	}

	return ( r );
#else
	return ( pow( t, s ) );
#endif
}


real Factorial( uint4 t )
{
	return ( ( t == 0 ) ? ( 1.0f ) : ( t * Factorial( t - 1 ) ) );
}


const real guess = 1.0f;
const real sqrtEps = 0.00001f;

real Sqrt( real t )
{
#ifdef CUSTOM_MATH
	real s = guess;

	while ( Abs( s * s - t ) > sqrtEps )
	{
		s -= ( s * s - t ) / ( 2.0f * s );
	}

	return ( s );
#else
	return ( sqrt( t ) );
#endif
}


const uint4 nonzeroTermCount = 5; //applies to acos too

real Cos( real t )
{
#ifdef CUSTOM_MATH
	//cos( -t ) = cos( t ), so make t positive
	if ( t < 0.0f ) t *= -1.0f;

	//cos( t ) is periodic, so make t <= 2pi
	//set t equal to 2pi times the fractional part of ( t / 2pi )
	if ( t > piMul2 ) t = piMul2 * ( ( t / piMul2 ) - ( uint4 )( t / piMul2 ) );

	//cos( t ) = -cos( t - pi ), so make t <= pi
	if ( t > pi ) return -Cos( t - pi );

	//taylor series centered at pi/2 ( halfway between 0 and pi )
	real s = 0.0f;

	for ( uint4 i = 0; i < nonzeroTermCount; ++i )
	{
		uint4 j = 2 * i + 1;

		s += Pow( -1.0f, i + 1 ) * Pow( t - piDiv2, j ) / Factorial( j );
	}

	return ( s );
#else
	return ( cos( t ) );
#endif
}

real Sin( real t )
{
#ifdef CUSTOM_MATH
	return ( Cos( piDiv2 - t ) );
#else
	return ( sin( t ) );
#endif
}

real Tan( real t )
{
#ifdef CUSTOM_MATH
	return ( Sin( t ) / Cos( t ) );
#else
	return ( tan( t ) );
#endif
}

real Sec( real t )
{
	return ( 1.0f / Cos( t ) );
}

real Csc( real t )
{
	return ( 1.0f / Sin( t ) );
}

real Cot( real t )
{
	return ( 1.0f / Tan( t ) );
}


real Acos( real t )
{
#ifdef CUSTOM_MATH
	//taylor series centered at 0
	real s = piDiv2;

	for ( uint4 i = 0; i < nonzeroTermCount; ++i )
	{
		s -= Factorial( 2 * i ) * Pow( t, 2 * i + 1 )
		     / ( Pow( 2.0f, 2 * i ) * Factorial( i ) * ( 2.0f * i + 1.0f ) );
	}

	return ( s );
#else
	return ( acos( t ) );
#endif
}

real Asin( real t )
{
#ifdef CUSTOM_MATH
	return ( piDiv2 - Acos( t ) );
#else
	return ( asin( t ) );
#endif
}

real Atan( real t )
{
#ifdef CUSTOM_MATH
	return ( Asin( t / Sqrt( t * t + 1.0f ) ) );
#else
	return ( atan( t ) );
#endif
}

real Asec( real t )
{
	return ( Acos( 1.0f / t ) );
}

real Acsc( real t )
{
	return ( Asin( 1.0f / t ) );
}

real Acot( real t )
{
	return ( piDiv2 - Atan( t ) );
}


real Atan2( real x, real y )
{
#ifdef CUSTOM_MATH
	     if ( x >  0.0f )                return (  Atan( y / x )      );
	else if ( x <  0.0f && y >= 0.0f )   return (  Atan( y / x ) + pi );
	else if ( x <  0.0f && y <  0.0f )   return (  Atan( y / x ) - pi );
	else if ( x == 0.0f && y >  0.0f )   return ( +piDiv2             );
	else if ( x == 0.0f && y <  0.0f )   return ( -piDiv2             );
	else  /*( x == 0.0f && y == 0.0f )*/ return (  0.0f               );
#else
	return ( atan2( y, x ) );
#endif
}

real PositiveAngleFromX( real x, real y )
{
	return ( Atan2( x, y ) + ( ( y < 0.0f ) ? ( piMul2 ) : ( 0.0f ) ) );
}


real DegToRad( real t )
{
	return ( t * ( pi / 180.0f ) );
}

real RadToDeg( real t )
{
	return ( t * ( 180.0f / pi ) );
}


real Min( real t, real s )
{
	return ( ( t < s ) ? ( t ) : ( s ) );
}

real Max( real t, real s )
{
	return ( ( t > s ) ? ( t ) : ( s ) );
}


real LinearInterp( real t, real s, real r )
{
	return ( t + ( s - t ) * r );
}