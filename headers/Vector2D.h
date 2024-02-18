#ifndef __VECTOR_2D_H__
#define __VECTOR_2D_H__

#include <cmath>
#include <math.h>

/*
    We will represent a vector as V(x, y)
*/
class Vector2D {
    float x, y;
public:
    Vector2D(float x, float y) : x(x), y(y) {}

    float getX() const { return x; }
    float getY() const { return y; }

    void setX(float x) { this->x = x; }
    void setY(float y) { this->y = y; }

    float length() const { return sqrt(x * x + y * y); }
    
    // Adding two vectors
    Vector2D operator+ (const Vector2D& v2) { 
        return Vector2D( (this->x + v2.x), (this->y + v2.y) ); 
    } 

    friend Vector2D& operator+= (Vector2D& v1, const Vector2D& v2) {
        v1.x += v2.x;
        v1.y += v2.y;
        return v1;
    }

    // Multiply by a scalar number
    Vector2D operator* (float scalar) { return Vector2D(x * scalar, y * scalar); }
   
    Vector2D& operator*= (float scalar) {
        this->x *= scalar;
        this->y *= scalar;
        return *this;
    }

    // Subtract two vectors
    Vector2D operator- (const Vector2D& v2) {
        return Vector2D( (this->x - v2.x), (this->y - v2.y));
    }

    friend Vector2D& operator-= (Vector2D& v1, const Vector2D& v2) {
        v1.x -= v2.x;
        v1.y -= v2.y;
        return v1;
    }

    // Devide by a scalar number
    Vector2D operator/ (float scalar) { 
        return Vector2D( (this->x / scalar), (this->y / scalar)); 
    }

    Vector2D operator/= (float scalar) {
        this->x /= scalar;
        this->y /= scalar;
        return *this;
    }

    // Normalizing a Vector
    void normalize() {
        float l = length();
        if (l > 0) *this *= l / l;
    }
    
};

#endif
