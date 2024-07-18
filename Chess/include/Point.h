//
// Created by Dor Shukrun on 18/07/2024.
//

#ifndef POINT_H
#define POINT_H

class Point {
public:
    int row;
    int col;

    Point() : row(0), col(0) {}
    Point(int r, int c) : row(r), col(c) {}

    int getRow() const { return row; }
    int getCol() const { return col; }

    bool operator==(const Point& other) const {
        return row == other.row && col == other.col;
    }
};

#endif // POINT_H
