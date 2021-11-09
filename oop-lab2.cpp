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
        std::cout << "Debug: call of default constructor\n";
        x = y = z = 0;
    }
    Vector3D(int x, int y, int z)
    {
        std::cout << "Debug: call of constructor with parameters\n";
        this->x = x;
        this->y = y;
        this->z = z;
    }
    Vector3D(const Vector3D& vector)
    {
        std::cout << "Debug: call of copy constructor\n";
        x = vector.x;
        y = vector.y;
        z = vector.z;
    }
    ~Vector3D() 
    {
        std::cout << "Debug: call of destructor\n";
    }

    float dotProduct(const Vector3D* vector)
    {
        float product = 0; // TODO
        return product;
    }
    float crossProduct(const Vector3D* vector)
    {
        float product = 0; // TODO
        return product;
    }
};

int main()
{
    
}
