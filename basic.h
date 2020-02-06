#pragma once


#include "types.h"


extern const real pi;
extern const real piMul2;
extern const real piDiv2;
extern const real piDiv4;


real Sign( real t );

real Abs( real t );

real Pow( real t, sint4 s );

real Factorial( uint4 t );

real Sqrt( real t );

real Cos( real t );
real Sin( real t );
real Tan( real t );
real Sec( real t );
real Csc( real t );
real Cot( real t );

real Acos( real t );
real Asin( real t );
real Atan( real t );
real Asec( real t );
real Acsc( real t );
real Acot( real t );

real Atan2( real x, real y );
real PositiveAngleFromX( real x, real y );

real DegToRad( real t );
real RadToDeg( real t );

real Min( real t, real s );
real Max( real t, real s );

real LinearInterp( real t, real s, real r );