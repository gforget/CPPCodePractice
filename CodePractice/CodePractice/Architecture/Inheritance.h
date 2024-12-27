#include <iostream>

class BaseClass {
private:
    const float x;
    const float y;
    const float z;

public:
    // Constructor for BaseClass
    BaseClass(float x, float y, float z)
        : x(x), y(y), z(z) {}

    // Getter functions
    float getX() const { return x; }
    float getY() const { return y; }
    float getZ() const { return z; }

    // Virtual destructor
    virtual ~BaseClass() = default;
};

class DerivedClass : public BaseClass {
private:
    const float w; // Additional parameter for DerivedClass

public:
    // Constructor for DerivedClass
    DerivedClass(float x, float y, float z, float w)
        : BaseClass(x, y, z), w(w) {}

    // Getter function for the additional parameter
    float getW() const { return w; }

    // Destructor
    ~DerivedClass() override = default;
};