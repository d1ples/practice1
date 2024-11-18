#include <iostream>
#include <cmath>
 
class Point2d {
  public:
    double m_x;
    double m_y;

    Point2d(double x = 0.0, double y = 0.0) : m_x(x), m_y(y) {}

    void print() {
      std::cout << "Point2d(" << m_x << "," << m_y << ")\n";
    }

    double distanceTo(const Point2d &point) {
      return std::sqrt((m_x - point.m_x) * (m_x - point.m_x) +
                        (m_y - point.m_y) * (m_y - point.m_y));
    }
};

double distanceTo(Point2d& first, Point2d& second) {
  return std::sqrt((first.m_x - second.m_x) * (first.m_x - second.m_x) +
                    (first.m_y - second.m_y) * (first.m_y - second.m_y));
}

int main()
{
    Point2d first{};
    Point2d second{ 3.0, 4.0 };
    first.print();
    second.print();
 
    std::cout << "Distance between two points: "
              << first.distanceTo(second) << '\n';

    std::cout << "Distance between two points: "
              << distanceTo(first,second) << '\n';

    return 0;
}
