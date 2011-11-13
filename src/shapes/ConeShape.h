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

#ifndef CONE_SHAPE_H
#define CONE_SHAPE_H

// Libraries
#include "Shape.h"
#include "../mathematics/mathematics.h"

// ReactPhysics3D namespace
namespace reactphysics3d {

/*  -------------------------------------------------------------------
    Class ConeShape :
        This class represents a cone collision shape centered at the
        origin and alligned with the Y axis. The cone is defined
        by its height and by the radius of its base. The center of the
        cone is at the half of the height. The "transform" of the
        corresponding rigid body gives an orientation and a position
        to the cone.
    -------------------------------------------------------------------
*/
class ConeShape : public Shape {
    private :
        double radius;              // Radius of the base
        double halfHeight;          // Half height of the cone
        double sinTheta;            // sine of the semi angle at the apex point
        
    public :
        ConeShape(double radius, double height);        // Constructor
        virtual ~ConeShape();                           // Destructor

        double getRadius() const;                                                                   // Return the radius
        void setRadius(double radius);                                                              // Set the radius
        double getHeight() const;                                                                   // Return the height
        void setHeight(double height);                                                              // Set the height
        virtual Vector3 getLocalSupportPoint(const Vector3& direction, double margin=0.0) const;    // Return a support point in a given direction
        virtual Vector3 getLocalExtents(double margin=0.0) const;                                   // Return the local extents in x,y and z direction
        virtual void computeLocalInertiaTensor(Matrix3x3& tensor, double mass) const;               // Return the local inertia tensor of the shape


#ifdef VISUAL_DEBUG
        virtual void draw() const;                              // Draw the sphere (only for testing purpose)
#endif
};

// Return the radius
inline double ConeShape::getRadius() const {
    return radius;
}

// Set the radius
inline void ConeShape::setRadius(double radius) {
    this->radius = radius;

    // Update sine of the semi-angle at the apex point
    sinTheta = radius / (sqrt(radius * radius + 4 * halfHeight * halfHeight));
}

// Return the height
inline double ConeShape::getHeight() const {
    return 2.0 * halfHeight;
}

// Set the height
inline void ConeShape::setHeight(double height) {
    this->halfHeight = height / 2.0;

    // Update the sine of the semi-angle at the apex point
    sinTheta = radius / (sqrt(radius * radius + height * height));
}

// Return the local extents in x,y and z direction
inline Vector3 ConeShape::getLocalExtents(double margin) const {
    return Vector3(radius + margin, halfHeight + margin, radius + margin);
}

// Return the local inertia tensor of the shape
inline void ConeShape::computeLocalInertiaTensor(Matrix3x3& tensor, double mass) const {
    double rSquare = radius * radius;
    double diagXZ = 0.15 * mass * (rSquare + halfHeight);
    tensor.setAllValues(diagXZ, 0.0, 0.0, 0.0, 0.3 * mass * rSquare, 0.0, 0.0, 0.0, diagXZ);
}

}; // End of the ReactPhysics3D namespace

#endif