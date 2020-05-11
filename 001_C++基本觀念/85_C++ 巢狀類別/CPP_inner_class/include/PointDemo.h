#ifndef POINTDEMO_H
#define POINTDEMO_H


class PointDemo
{
public:
    PointDemo(int);
    ~PointDemo();

    void show();
private:
    // Nested Class
    class Point {
    public:
        Point();
        Point(int, int);
        int x() { return _x; }
        int y() { return _y; }
        void x(int x) { _x = x; }
        void y(int y) { _y = y; }
    private:
        int _x;
        int _y;
    };

    Point **_points;
    int _length;
};

#endif // POINTDEMO_H
