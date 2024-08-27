#include <iostream>
#include <vector>
#include <cstring>
#include <memory>

// Base Class
#include <iostream>
#include <vector>
#include <cstring>

// Base Class
class Shape {
protected:
    char* name;
    int id;
    std::vector<int> properties;

public:

    Shape(const char* n, int i) {
        name = new char[strlen(n) + 1];
        strcpy(name, n);
        id = i;
    }

    // Copy constructor
    Shape(const Shape& obj) {
        name = new char[strlen(obj.name) + 1];
        strcpy(name, obj.name);
        id = obj.id;
        properties = obj.properties;
    }

    // Copy assignment operator
    Shape& operator=(const Shape& obj) {
        if (this != &obj) { // Self-assigned check
            delete[] name; // Free existing resource
            name = new char[strlen(obj.name) + 1];
            strcpy(name, obj.name); // Deep copy
            id = obj.id;
            properties = obj.properties;
        }
        return *this;
    }

    // Move constructor
    Shape(Shape&& obj) noexcept : name(obj.name), id(obj.id), properties(std::move(obj.properties)) {
        obj.name = nullptr;
    }

    // Move assignment operator
    Shape& operator=(Shape&& obj) noexcept {
        if (this != &obj) {
            delete[] name;
            name = obj.name;
            id = obj.id;
            properties = std::move(obj.properties);
            obj.name = nullptr;
        }
        return *this;
    }

    // Destructor
    virtual ~Shape() {
        delete[] name;
    }

    // Getters
    const char* getName() const {
        return name;
    }
    
    int getId() const {
        return id;
    }

    const std::vector<int>& getProperties() const {
        return properties;
    }

    // Method to add a property
    void addProperty(int prop) {
        properties.push_back(prop);
    }

    // Static Friend Function
    static void displayShape(const Shape& s) {
        std::cout << "Shape Name: " << s.getName() << ", ID: " << s.getId() << std::endl;
        std::cout << "Properties: ";
        for (int prop : s.getProperties()) {
            std::cout << prop << " ";
        }
        std::cout << std::endl;
    }

    // Function Overloading
    int CalculatePerimeter(int width, int length) const {
        return 2 * (width + length);
    }

    double CalculatePerimeter(double radius) const {
        return 2 * 3.14159 * radius;
    }

    virtual double CalculateArea() const = 0;
    virtual Shape* operator+(const Shape& obj) const = 0;
};


// Dervied Class 1
class Circle : public Shape {
private:
    int radius;

public:
    Circle(const char* n, int id, int r) : Shape(n, id), radius(r) {}

    Shape* operator+(const Shape& obj) const override {
        const Circle* c = dynamic_cast<const Circle*>(&obj);
        if (c) {
            return new Circle("CombinedCircle", getId() + c->getId(), this->radius + c->radius);
        }
        return nullptr; // Handle error if `obj` is not a Circle
    }

    double CalculateArea() const override {
        return 3.14159 * radius * radius;
    }
};


// Derived Class 2
class Rectangle : public Shape {
private:
    int width;
    int length;

public:
    Rectangle(const char* n, int id, int w, int l) : Shape(n, id), width(w), length(l) {}

    Shape* operator+(const Shape& obj) const override {
        const Rectangle* r = dynamic_cast<const Rectangle*>(&obj);
        if (r) {
            return new Rectangle("CombinedRectangle", getId() + r->getId(), this->width + r->width, this->length + r->length);
        }
        return nullptr; // Handle error if `obj` is not a Rectangle
    }

    double CalculateArea() const override {
        return width * length;
    }
};

int main() {
    // Create unique pointers to Circle instances
    auto circle1 = std::make_unique<Circle>("Circle1", 1, 5);
    auto circle2 = std::make_unique<Circle>("Circle2", 2, 10);

    // Add properties to circles
    circle1->addProperty(100);
    circle1->addProperty(200);
    circle2->addProperty(300);

    // Combine circles using the overloaded operator+
    std::unique_ptr<Shape> combinedShape = std::unique_ptr<Shape>(circle1->operator+(*circle2));
    auto combinedCircle = dynamic_cast<Circle*>(combinedShape.get());
    if (combinedCircle) {
        Shape::displayShape(*circle1);
        Shape::displayShape(*circle2);
        Shape::displayShape(*combinedCircle);
        std::cout << "Combined Circle Area: " << combinedCircle->CalculateArea() << std::endl;
    }

    // Create unique pointers to Rectangle instances
    auto rect1 = std::make_unique<Rectangle>("Rectangle1", 3, 4, 5);
    auto rect2 = std::make_unique<Rectangle>("Rectangle2", 4, 6, 7);

    // Add properties to rectangles
    rect1->addProperty(400);
    rect1->addProperty(500);
    rect2->addProperty(600);

    // Combine rectangles using the overloaded operator+
    std::unique_ptr<Shape> combinedShapeRect = std::unique_ptr<Shape>(rect1->operator+(*rect2));
    auto combinedRectangle = dynamic_cast<Rectangle*>(combinedShapeRect.get());
    if (combinedRectangle) {
        Shape::displayShape(*rect1);
        Shape::displayShape(*rect2);
        Shape::displayShape(*combinedRectangle);
        std::cout << "Combined Rectangle Area: " << combinedRectangle->CalculateArea() << std::endl;
    }

    return 0;
}

// int main() {
//     // Create Circle instances
//     Circle circle1("Circle1", 1, 5);
//     Circle circle2("Circle2", 2, 10);

//     // Add properties to circles
//     circle1.addProperty(100);
//     circle1.addProperty(200);
//     circle2.addProperty(300);

//     // Combine circles
//     Shape* combinedShape = circle1 + circle2;
//     Circle* combinedCircle = dynamic_cast<Circle*>(combinedShape);
//     if (combinedCircle) {
//         Shape::displayShape(circle1);
//         Shape::displayShape(circle2);
//         Shape::displayShape(*combinedCircle);
//         std::cout << "Combined Circle Area: " << combinedCircle->CalculateArea() << std::endl;
//         delete combinedCircle; // Don't forget to delete the dynamically allocated object
//     }

//     // Create Rectangle instances
//     Rectangle rect1("Rectangle1", 3, 4, 5);
//     Rectangle rect2("Rectangle2", 4, 6, 7);

//     // Add properties to rectangles
//     rect1.addProperty(400);
//     rect1.addProperty(500);
//     rect2.addProperty(600);

//     // Combine rectangles
//     Shape* combinedShapeRect = rect1 + rect2;
//     Rectangle* combinedRectangle = dynamic_cast<Rectangle*>(combinedShapeRect);
//     if (combinedRectangle) {
//         Shape::displayShape(rect1);
//         Shape::displayShape(rect2);
//         Shape::displayShape(*combinedRectangle);
//         std::cout << "Combined Rectangle Area: " << combinedRectangle->CalculateArea() << std::endl;
//         delete combinedRectangle; // Don't forget to delete the dynamically allocated object
//     }

//     return 0;
// }


