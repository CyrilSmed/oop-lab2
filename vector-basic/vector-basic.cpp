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
        printf("Debug: Vector3D - default constructor\n");
        x = y = z = 0;
    }
    Vector3D(int x, int y, int z)
    {
        printf("Debug: Vector3D - constructor with parameters\n");
        this->x = x;
        this->y = y;
        this->z = z;
    }
    Vector3D(const Vector3D& vector)
    {
        std::cout << "Debug: Vector3D - copy constructor\n";
        x = vector.x;
        y = vector.y;
        z = vector.z;
    }
    ~Vector3D()
    {
        printf("Debug: Vector3D - destructor\n");
    }

    void setX(int x)
    {
        printf("Debug: Vector3D::setX()\n");
        this->x = x;
    }
    void setY(int y)
    {
        printf("Debug: Vector3D::setY()\n");
        this->y = y;
    }
    void setZ(int z)
    {
        printf("Debug: Vector3D::setZ()\n");
        this->z = z;
    }

    void printDescription()
    {
        printf("(%d, %d, %d)\n", x, y, z);
        printf("Debug: Vector3D::printDescription()\n");
    }
    int dotProduct(const Vector3D* vector)
    {
        printf("Debug: Vector3D::dotProduct()\n");
        int product = x * vector->x + y * vector->y + z * vector->z;
        return product;
    }
    Vector3D* crossProduct(const Vector3D* vector)
    {
        printf("Debug: Vector3D::crossProduct()\n");
        Vector3D* product = new Vector3D(y * vector->z - z * vector->y,
            z * vector->x - x * vector->z,
            x * vector->y - y * vector->x);
        return product;
    }
};

int main()
{
    Vector3D a = Vector3D(1, 3, 2);
    Vector3D b = Vector3D(a);
    b.setY(-1);
    printf("\n");

    printf("Vector a: ");
    a.printDescription();
    printf("\n");
    printf("Vector b: ");
    b.printDescription();
    printf("\n\n");

    int dotProduct = a.dotProduct(&b);
    printf("Dot product of vectors a and b: %d\n\n", dotProduct);

    Vector3D* crossProduct = a.crossProduct(&b);
    printf("Cross product of vectors a and b: ");
    crossProduct->printDescription();
    printf("\n\n");

    delete crossProduct;
}
