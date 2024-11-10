#include <string>

template <typename T>
struct Vec {
    Vec() : x(0), y(0) {};
    Vec(int _x, int _y) : x(_x), y(_y) {};

    bool operator<(const Vec& c2) const {
        if (x == c2.x) {
            return y > c2.y;
        }
        return x < c2.x;
    }

    bool operator==(const Vec& c2) const { return x == c2.x && y == c2.y; }

    Vec operator+(const Vec& right) const { return Vec(x + right.x, y + right.y ); }
    Vec operator-(const Vec& right) const { return Vec(x - right.x, y - right.y); }

    Vec del(float d) const { 
        return Vec(static_cast<T>(x / d), static_cast<T>(y / d));
    }
    
    Vec operator/(float d) const { 
        return del(d); 
    }

    std::string toString() const {  return std::string("[") + std::to_string(x) + "," + std::to_string(y) + "]"; }
    float length() const { return static_cast<float>(sqrt(x * x + y * y)); }

    Vec revert() const { return { -x, -y }; }

    T x;
    T y;
};
