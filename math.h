#pragma once


#include <iostream>

#include "basic.h"

#include "vec2.h"
#include "vec3.h"
#include "vec4.h"
#include "mat2.h"
#include "mat3.h"
#include "mat4.h"


#define V2D_X Vector2D( 1.0f, 0.0f )
#define V2D_Y Vector2D( 0.0f, 1.0f )
#define V3D_X Vector3D( 1.0f, 0.0f, 0.0f )
#define V3D_Y Vector3D( 0.0f, 1.0f, 0.0f )
#define V3D_Z Vector3D( 0.0f, 0.0f, 1.0f )


std::ostream& operator<<( std::ostream& out, Vector2D u );
std::ostream& operator<<( std::ostream& out, Vector3D u );
std::ostream& operator<<( std::ostream& out, Vector4D u );