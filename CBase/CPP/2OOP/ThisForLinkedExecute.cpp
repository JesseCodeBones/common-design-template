#include <iostream>
using namespace std;

class Point
{
private:
    int m_x, m_y;

public:
    Point(int x, int y);
    ~Point();
    Point &move(int x, int y);
    void printPoint();
};

Point::Point(int x, int y) : m_x(x), m_y(y)
{
}

Point::~Point()
{
}

Point &Point::move(int x, int y)
{
    m_x += x;
    m_y += y;
    return *this;
}

void Point::printPoint()
{
    cout << to_string(m_x) << " - " << to_string(m_y) << endl;
}

int main(void)
{
    Point p1(1, 2);
    p1.move(2, 3).move(9, 1);
    p1.printPoint();
    return 0;
}