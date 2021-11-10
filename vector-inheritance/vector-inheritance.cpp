#include <iostream>
#include <string>

using namespace std;

class Vector
{
public:
    virtual void printVectorDescription() 
    {
        printf("Debug: Vector::printDescription()\n");
    }
};

class Vector3D : public Vector
{
protected:
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
        printf("Debug: Vector3D::setX(int x)\n");
        this->x = x;
    }
    int getX() const
    {
        printf("Debug: Vector3D::getX()\n");
        return x;
    }
    void setY(int y)
    {
        printf("Debug: Vector3D::setY(int y)\n");
        this->y = y;
    }
    int getY() const
    {
        printf("Debug: Vector3D::getY()\n");
        return y;
    }
    void setZ(int z)
    {
        printf("Debug: Vector3D::setZ(int z)\n");
        this->z = z;
    }
    int getZ() const
    {
        printf("Debug: Vector3D::getZ()\n");
        return z;
    }

    void printVectorDescription()
    {
        printf("(%d, %d, %d)\n", x, y, z);
        printf("Debug: Vector3D::printDescription()\n");
    }
    int dotProduct(const Vector3D* vector);
    Vector3D* crossProduct(const Vector3D* vector);
};

int Vector3D::dotProduct(const Vector3D* vector)
{
    printf("Debug: Vector3D::dotProduct()\n");
    int product = x * vector->x + y * vector->y + z * vector->z;
    return product;
}
Vector3D* Vector3D::crossProduct(const Vector3D* vector)
{
    printf("Debug: Vector3D::crossProduct()\n");
    Vector3D* product = new Vector3D(y * vector->z - z * vector->y,
        z * vector->x - x * vector->z,
        x * vector->y - y * vector->x);
    return product;
}

class LabeledVector3D : public Vector3D
{
private:
    string label = "";
public:
    LabeledVector3D() : Vector3D()
    {
        printf("Debug: LabeledVector3D - default constructor\n");
        x = y = z = 0;
    }
    LabeledVector3D(int x, int y, int z, string label) : Vector3D(x, y, z)
    {
        printf("Debug: LabeledVector3D - constructor with parameters\n");
        this->label = label;
    }
    LabeledVector3D(const LabeledVector3D& vector) : Vector3D(vector)
    {
        std::cout << "LabeledVector3D: Vector - copy constructor\n";
        label = vector.label;
    }
    ~LabeledVector3D()
    {
        printf("Debug: Vector - destructor\n");
    }
    void printVectorDescription()
    {
        cout << label << ": ";
        printf("(%d, %d, %d)\n", x, y, z);
        printf("Debug: LabeledVector3D::printDescription()\n");
    }

    string getLabel() const
    {
        return label;
    }
};

int main()
{
    Vector* vectors[3] = {
        new Vector3D(-1, 3, 0),
        new LabeledVector3D(2, 6, 4, "Even Vector"),
        new Vector3D()
    };

    for (int i = 0; i < sizeof(vectors) / sizeof(vectors[0]); i++)
    {
        vectors[i]->printVectorDescription();
    }

    for (int i = 0; i < sizeof(vectors) / sizeof(vectors[0]); i++)
    {
        delete vectors[i];
    }
}
