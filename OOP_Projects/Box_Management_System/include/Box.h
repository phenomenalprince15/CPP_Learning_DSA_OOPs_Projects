#ifdef BOX_H
#define BOX_H

class Box {
    private:
        double length;
        double breadth;
        double height;
    
    public:
        Box(double l = 1.0, double b = 1.0, double h = 1.0); // Constructor
        Box(const Box& other); // Copy Constructor
        Box(Box&& other) noexcept; // Move Constructor
        ~Box(); // Destructor

        Box& operator=(const Box& other); // Copy Assignment
        Box& operator=(Box&& other) noexcept; // Move Assignment

        virtual double volume () const;

        // Operator Overloads
        bool operator==(const Box& other) const;
        bool operator!=(const Box& other) const;
        bool operator<(const Box& other) const;
        bool operator>(const Box& other) const;
        Box operator+(const Box& other) const;
        Box operator*(double scale) const;

};

#endif
