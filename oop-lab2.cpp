// oop-lab2.cpp
// 

#include <iostream>

class Vector3D
{
private:
    float x;
    float y;
    float z;

public:
    Vector3D()
    {
        printf("Debug: Vectro3D - call of default constructor\n");
        x = y = z = 0;
    }
    Vector3D(float x, float y, float z)
    {
        printf("Debug: Vectro3D - call of constructor with parameters\n");
        this->x = x;
        this->y = y;
        this->z = z;
    }
    Vector3D(const Vector3D& vector)
    {
        std::cout << "Debug: Vectro3D - call of copy constructor\n";
        x = vector.x;
        y = vector.y;
        z = vector.z;
    }
    ~Vector3D() 
    {
        printf("Debug: Vectro3D - call of destructor\n");
    }

    void setX(float x)
    {
        this->x = x;
    }
    void setY(float y)
    {
        this->y = y;
    }
    void setZ(float z)
    {
        this->z = z;
    }

    void printDescription()
    {
        printf("(x = %f; y = %f, z = %f)", x, y, z);
    }
    float dotProduct(const Vector3D* vector)
    {
        printf("Debug: Vectro3D - call of dotProduct method\n");
        float product = x * vector->x + y * vector->y + z * vector->z;
        return product;
    }
    Vector3D crossProduct(const Vector3D* vector)
    {
        printf("Debug: Vectro3D - call of crossProduct method\n");
        Vector3D product = Vector3D(y * vector->z - z * vector->y,
                                    z * vector->x - x * vector->z,
                                    x * vector->y - y * vector->x);
        return product;
    }
};

int main()
{
    Vector3D a = Vector3D(1, 3, 2);
    Vector3D b = Vector3D(a);

}
