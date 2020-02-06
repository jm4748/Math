#include "math.h"


std::ostream& operator<<( std::ostream& out, Vector2D u )
{
	out << "( " << u.x << ", " << u.y << " )";

	return out;
}

std::ostream& operator<<( std::ostream& out, Vector3D u )
{
	out << "( " << u.x << ", " << u.y << ", " << u.z << " )";

	return out;
}

std::ostream& operator<<( std::ostream& out, Vector4D u )
{
	out << "( " << u.x << ", " << u.y << ", " << u.z << ", " << u.w << " )";

	return out;
}