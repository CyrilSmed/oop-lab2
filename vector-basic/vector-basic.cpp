#include <iostream>

class Vector3D
{
private:
    int x;
    int y;
    int z;

public:
    Vector3D()
    {
        printf("Debug: Vectro3D - call of default constructor\n");
        x = y = z = 0;
    }
    Vector3D(int x, int y, int z)
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

    void setX(int x)
    {
        printf("Debug: Vectro3D - setX()\n");
        this->x = x;
    }
    void setY(int y)
    {
        printf("Debug: Vectro3D - setY()\n");
        this->y = y;
    }
    void setZ(int z)
    {
        printf("Debug: Vectro3D - setZ()\n");
        this->z = z;
    }

    void printDescription()
    {
        printf("(%d, %d, %d)", x, y, z);
    }
    int dotProduct(const Vector3D* vector)
    {
        printf("Debug: Vectro3D - dotProduct()\n");
        int product = x * vector->x + y * vector->y + z * vector->z;
        return product;
    }
    Vector3D* crossProduct(const Vector3D* vector)
    {
        printf("Debug: Vectro3D - crossProduct()\n");
        Vector3D* product = new Vector3D(y * vector->z - z * vector->y,
            z * vector->x - x * vector->z,
            x * vector->y - y * vector->x);
        return product;
    }
};

int main()
{
    Vector3D* a = new Vector3D(1, 3, 2);
    Vector3D* b = new Vector3D(*a);
    b->setY(-1);
    printf("\n");

    printf("Vector a: ");
    a->printDescription();
    printf("\n");
    printf("Vector b: ");
    b->printDescription();
    printf("\n\n");

    int dotProduct = a->dotProduct(b);
    printf("Dot product of vectors a and b: %d\n\n", dotProduct);

    Vector3D* crossProduct = a->crossProduct(b);
    printf("Cross product of vectors a and b: ");
    crossProduct->printDescription();
    printf("\n\n");

    delete a;
    delete b;
    delete crossProduct;
}
