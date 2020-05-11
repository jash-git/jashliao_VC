#include <iostream>
#include "..\include\PointDemo.h"
using namespace std;

// 實作內部類別
PointDemo::Point::Point() {
    _x = 0;
    _y = 0;
}

// 實作內部類別
PointDemo::Point::Point(int x, int y) {
    _x = x;
    _y = y;
}

PointDemo::PointDemo(int length) : _length(length) {
    _points = new Point*[_length];
    for(int i = 0; i < _length; i++) {
        _points[i] = new Point();
        _points[i]->x(i*5);
        _points[i]->y(i*5);
    }
}

void PointDemo::show() {
    for(int i = 0; i < _length; i++) {
    cout << "(x, y) = ("
         << _points[i]->x() << ", "
         << _points[i]->y() << ")"
         << endl;
    }
}

PointDemo::~PointDemo() {
    for(int i = 0; i < _length; i++) {
        delete _points[i];
    }
    delete [] _points;
}
