/********************************************************************************
* ReactPhysics3D physics library, http://code.google.com/p/reactphysics3d/      *
* Copyright (c) 2010-2012 Daniel Chappuis                                       *
*********************************************************************************
*                                                                               *
* This software is provided 'as-is', without any express or implied warranty.   *
* In no event will the authors be held liable for any damages arising from the  *
* use of this software.                                                         *
*                                                                               *
* Permission is granted to anyone to use this software for any purpose,         *
* including commercial applications, and to alter it and redistribute it        *
* freely, subject to the following restrictions:                                *
*                                                                               *
* 1. The origin of this software must not be misrepresented; you must not claim *
*    that you wrote the original software. If you use this software in a        *
*    product, an acknowledgment in the product documentation would be           *
*    appreciated but is not required.                                           *
*                                                                               *
* 2. Altered source versions must be plainly marked as such, and must not be    *
*    misrepresented as being the original software.                             *
*                                                                               *
* 3. This notice may not be removed or altered from any source distribution.    *
*                                                                               *
********************************************************************************/

// Libraries
#include "SphereShape.h"
#include <cassert>

#ifdef VISUAL_DEBUG
   #include <GLUT/glut.h>        // TODO : Remove this in the final version
   #include <OpenGL/gl.h>              // TODO : Remove this in the final version
#endif

using namespace reactphysics3d;
using namespace std;

// Constructor
SphereShape::SphereShape(double radius) : radius(radius) {

}

// Destructor
SphereShape::~SphereShape() {

}

#ifdef VISUAL_DEBUG
// Draw the sphere (only for testing purpose)
void SphereShape::draw() const {

    // Draw in red
    glColor3f(1.0, 0.0, 0.0);

    // Draw the sphere
    glutWireSphere(radius, 50, 50);
}
#endif