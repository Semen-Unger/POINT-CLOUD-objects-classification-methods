#include "fractalDimension.h"

// квадрат в z = 0
std::vector<Point3D> generatePlaneZ(double size = 5, double density = 0.1, double bias = 0.0) {
    double step = size / (density * 100);
    std::vector<Point3D> points;
    double x = 0;
    while(x <= size){
        double y = 0;
        while (y <= size) {
            points.emplace_back(Point3D{ x, y, bias });
            y += step;
        }
        x += step;
    }
    return points;
}

void testSquare() {
    int numScales = 5;
    std::vector<Point3D> squareXY = generatePlaneZ();
    float dim1 = computeFractalDimensionGeometry(squareXY, numScales);
    float dim2 = computeFractalDimensionMass(squareXY, numScales);
    std::cout << "FD of square with geometry " << dim1 << " and mass " << dim2 << std::endl;
    return;
}

//квадрат с вырезом 1 на 1 по середине (в плоскости z=0)
std::vector<Point3D> generatePlaneWithCentreHole(double size = 5, double density = 0.1, double bias = 0.0) {
    double step = size / (density * 100);
    std::vector<Point3D> points;
    double x = 0;
    while (x <= size) {
        double y = 0;
        while (y <= size) {
            if (!(size/2. - 0.5 < x && x < size/2. + 0.5 && size/2. - 0.5 < y && y < size/2. + 0.5)) {
                points.emplace_back(Point3D{ x, y, bias });
            }
            y += step;
        }
        x += step;
    }
    return points;
}

void testSquareWithHole() {
    int numScales = 5;
    std::vector<Point3D> squareWithHole = generatePlaneWithCentreHole();
    float dim1 = computeFractalDimensionGeometry(squareWithHole, numScales);
    float dim2 = computeFractalDimensionMass(squareWithHole, numScales);
    std::cout << "FD of square with one hole with geometry " << dim1 << " and mass " << dim2 << std::endl;
    return;

}

void testSquareDimension() {
    //облако задано вручную, фрактальная размерность 1.59
    vector<Point3D> points = {
        Point3D(0.0, 0.0, 0.0),
        Point3D(0.1, 0.0, 0.0), Point3D(0.2, 0.0, 0.0), Point3D(0.3, 0.0, 0.0), Point3D(0.4, 0.0, 0.0), Point3D(0.5, 0.0, 0.0),
        Point3D(0.6, 0.0, 0.0), Point3D(0.7, 0.0, 0.0), Point3D(0.8, 0.0, 0.0), Point3D(0.9, 0.0, 0.0), Point3D(1.0, 0.0, 0.0),
        Point3D(1.1, 0.0, 0.0), Point3D(1.2, 0.0, 0.0), Point3D(1.3, 0.0, 0.0), Point3D(1.4, 0.0, 0.0), Point3D(1.5, 0.0, 0.0),
        Point3D(1.6, 0.0, 0.0), Point3D(1.7, 0.0, 0.0), Point3D(1.8, 0.0, 0.0), Point3D(1.9, 0.0, 0.0), Point3D(2.0, 0.0, 0.0),
        Point3D(0.1, 0.1, 0.0), Point3D(0.2, 0.1, 0.0), Point3D(0.3, 0.1, 0.0), Point3D(0.4, 0.1, 0.0), Point3D(0.5, 0.1, 0.0),
        Point3D(0.6, 0.1, 0.0), Point3D(0.7, 0.1, 0.0), Point3D(0.8, 0.1, 0.0), Point3D(0.9, 0.1, 0.0), Point3D(1.0, 0.1, 0.0),
        Point3D(1.1, 0.1, 0.0), Point3D(1.2, 0.1, 0.0), Point3D(1.3, 0.1, 0.0), Point3D(1.4, 0.1, 0.0), Point3D(1.5, 0.1, 0.0),
        Point3D(1.6, 0.1, 0.0), Point3D(1.7, 0.1, 0.0), Point3D(1.8, 0.1, 0.0), Point3D(1.9, 0.1, 0.0), Point3D(2.0, 0.1, 0.0),
        Point3D(0.1, 0.2, 0.0), Point3D(0.2, 0.2, 0.0), Point3D(0.3, 0.2, 0.0), Point3D(0.4, 0.2, 0.0), Point3D(0.5, 0.2, 0.0),
        Point3D(0.6, 0.2, 0.0), Point3D(0.7, 0.2, 0.0), Point3D(0.8, 0.2, 0.0), Point3D(0.9, 0.2, 0.0), Point3D(1.0, 0.2, 0.0),
        Point3D(1.1, 0.2, 0.0), Point3D(1.2, 0.2, 0.0), Point3D(1.3, 0.2, 0.0), Point3D(1.4, 0.2, 0.0), Point3D(1.5, 0.2, 0.0),
        Point3D(1.6, 0.2, 0.0), Point3D(1.7, 0.2, 0.0), Point3D(1.8, 0.2, 0.0), Point3D(1.9, 0.2, 0.0), Point3D(2.0, 0.2, 0.0),
        Point3D(0.1, 0.3, 0.0), Point3D(0.2, 0.3, 0.0), Point3D(0.3, 0.3, 0.0), Point3D(0.4, 0.3, 0.0), Point3D(0.5, 0.3, 0.0),
        Point3D(0.6, 0.3, 0.0), Point3D(0.7, 0.3, 0.0), Point3D(0.8, 0.3, 0.0), Point3D(0.9, 0.3, 0.0), Point3D(1.0, 0.3, 0.0),
        Point3D(1.1, 0.3, 0.0), Point3D(1.2, 0.3, 0.0), Point3D(1.3, 0.3, 0.0), Point3D(1.4, 0.3, 0.0), Point3D(1.5, 0.3, 0.0),
        Point3D(1.6, 0.3, 0.0), Point3D(1.7, 0.3, 0.0), Point3D(1.8, 0.3, 0.0), Point3D(1.9, 0.3, 0.0), Point3D(2.0, 0.3, 0.0),
        Point3D(0.0, 0.1, 0.0), Point3D(0.0, 0.2, 0.0), Point3D(0.0, 0.3, 0.0), Point3D(0.0, 0.4, 0.0), Point3D(0.0, 0.5, 0.0),
        Point3D(0.0, 0.6, 0.0), Point3D(0.0, 0.7, 0.0), Point3D(0.0, 0.8, 0.0), Point3D(0.0, 0.9, 0.0), Point3D(0.0, 1.0, 0.0),
        Point3D(0.0, 1.1, 0.0), Point3D(0.0, 1.2, 0.0), Point3D(0.0, 1.3, 0.0), Point3D(0.0, 1.4, 0.0), Point3D(0.0, 1.5, 0.0),
        Point3D(0.0, 1.6, 0.0), Point3D(0.0, 1.7, 0.0), Point3D(0.0, 1.8, 0.0), Point3D(0.0, 1.9, 0.0), Point3D(0.0, 2.0, 0.0),
        Point3D(0.1, 0.1, 0.0), Point3D(0.1, 0.2, 0.0), Point3D(0.1, 0.3, 0.0), Point3D(0.1, 0.4, 0.0), Point3D(0.1, 0.5, 0.0),
        Point3D(0.1, 0.6, 0.0), Point3D(0.1, 0.7, 0.0), Point3D(0.1, 0.8, 0.0), Point3D(0.1, 0.9, 0.0), Point3D(0.1, 1.0, 0.0),
        Point3D(0.1, 1.1, 0.0), Point3D(0.1, 1.2, 0.0), Point3D(0.1, 1.3, 0.0), Point3D(0.1, 1.4, 0.0), Point3D(0.1, 1.5, 0.0),
        Point3D(0.1, 1.6, 0.0), Point3D(0.1, 1.7, 0.0), Point3D(0.1, 1.8, 0.0), Point3D(0.1, 1.9, 0.0), Point3D(0.1, 2.0, 0.0),
        Point3D(0.2, 0.1, 0.0), Point3D(0.2, 0.2, 0.0), Point3D(0.2, 0.3, 0.0), Point3D(0.2, 0.4, 0.0), Point3D(0.2, 0.5, 0.0),
        Point3D(0.2, 0.6, 0.0), Point3D(0.2, 0.7, 0.0), Point3D(0.2, 0.8, 0.0), Point3D(0.2, 0.9, 0.0), Point3D(0.2, 1.0, 0.0),
        Point3D(0.2, 1.1, 0.0), Point3D(0.2, 1.2, 0.0), Point3D(0.2, 1.3, 0.0), Point3D(0.2, 1.4, 0.0), Point3D(0.2, 1.5, 0.0),
        Point3D(0.2, 1.6, 0.0), Point3D(0.2, 1.7, 0.0), Point3D(0.2, 1.8, 0.0), Point3D(0.2, 1.9, 0.0), Point3D(0.2, 2.0, 0.0),
        Point3D(2.0, 0.1, 0.0), Point3D(2.0, 0.2, 0.0), Point3D(2.0, 0.3, 0.0), Point3D(2.0, 0.4, 0.0), Point3D(2.0, 0.5, 0.0),
        Point3D(2.0, 0.6, 0.0), Point3D(2.0, 0.7, 0.0), Point3D(2.0, 0.8, 0.0), Point3D(2.0, 0.9, 0.0), Point3D(2.0, 1.0, 0.0),
        Point3D(2.0, 1.1, 0.0), Point3D(2.0, 1.2, 0.0), Point3D(2.0, 1.3, 0.0), Point3D(2.0, 1.4, 0.0), Point3D(2.0, 1.5, 0.0),
        Point3D(2.0, 1.6, 0.0), Point3D(2.0, 1.7, 0.0), Point3D(2.0, 1.8, 0.0), Point3D(2.0, 1.9, 0.0), Point3D(2.0, 2.0, 0.0),
        Point3D(1.9, 0.1, 0.0), Point3D(1.9, 0.2, 0.0), Point3D(1.9, 0.3, 0.0), Point3D(1.9, 0.4, 0.0), Point3D(1.9, 0.5, 0.0),
        Point3D(1.9, 0.6, 0.0), Point3D(1.9, 0.7, 0.0), Point3D(1.9, 0.8, 0.0), Point3D(1.9, 0.9, 0.0), Point3D(1.9, 1.0, 0.0),
        Point3D(1.9, 1.1, 0.0), Point3D(1.9, 1.2, 0.0), Point3D(1.9, 1.3, 0.0), Point3D(1.9, 1.4, 0.0), Point3D(1.9, 1.5, 0.0),
        Point3D(1.9, 1.6, 0.0), Point3D(1.9, 1.7, 0.0), Point3D(1.9, 1.8, 0.0), Point3D(1.9, 1.9, 0.0), Point3D(1.9, 2.0, 0.0),
        Point3D(1.8, 0.1, 0.0), Point3D(1.8, 0.2, 0.0), Point3D(1.8, 0.3, 0.0), Point3D(1.8, 0.4, 0.0), Point3D(1.8, 0.5, 0.0),
        Point3D(1.8, 0.6, 0.0), Point3D(1.8, 0.7, 0.0), Point3D(1.8, 0.8, 0.0), Point3D(1.8, 0.9, 0.0), Point3D(1.8, 1.0, 0.0),
        Point3D(1.8, 1.1, 0.0), Point3D(1.8, 1.2, 0.0), Point3D(1.8, 1.3, 0.0), Point3D(1.8, 1.4, 0.0), Point3D(1.8, 1.5, 0.0),
        Point3D(1.8, 1.6, 0.0), Point3D(1.8, 1.7, 0.0), Point3D(1.8, 1.8, 0.0), Point3D(1.8, 1.9, 0.0), Point3D(1.8, 2.0, 0.0),
        Point3D(0.1, 2.0, 0.0), Point3D(0.2, 2.0, 0.0), Point3D(0.3, 2.0, 0.0), Point3D(0.4, 2.0, 0.0), Point3D(0.5, 2.0, 0.0),
        Point3D(0.6, 2.0, 0.0), Point3D(0.7, 2.0, 0.0), Point3D(0.8, 2.0, 0.0), Point3D(0.9, 2.0, 0.0), Point3D(1.0, 2.0, 0.0),
        Point3D(1.1, 2.0, 0.0), Point3D(1.2, 2.0, 0.0), Point3D(1.3, 2.0, 0.0), Point3D(1.4, 2.0, 0.0), Point3D(1.5, 2.0, 0.0),
        Point3D(1.6, 2.0, 0.0), Point3D(1.7, 2.0, 0.0), Point3D(1.8, 2.0, 0.0), Point3D(1.9, 2.0, 0.0), Point3D(2.0, 2.0, 0.0),
        Point3D(0.1, 1.9, 0.0), Point3D(0.2, 1.9, 0.0), Point3D(0.3, 1.9, 0.0), Point3D(0.4, 1.9, 0.0), Point3D(0.5, 1.9, 0.0),
        Point3D(0.6, 1.9, 0.0), Point3D(0.7, 1.9, 0.0), Point3D(0.8, 1.9, 0.0), Point3D(0.9, 1.9, 0.0), Point3D(1.0, 1.9, 0.0),
        Point3D(1.1, 1.9, 0.0), Point3D(1.2, 1.9, 0.0), Point3D(1.3, 1.9, 0.0), Point3D(1.4, 1.9, 0.0), Point3D(1.5, 1.9, 0.0),
        Point3D(1.6, 1.9, 0.0), Point3D(1.7, 1.9, 0.0), Point3D(1.8, 1.9, 0.0), Point3D(1.9, 1.9, 0.0), Point3D(2.0, 1.9, 0.0),
        Point3D(0.1, 1.8, 0.0), Point3D(0.2, 1.8, 0.0), Point3D(0.3, 1.8, 0.0), Point3D(0.4, 1.8, 0.0), Point3D(0.5, 1.8, 0.0),
        Point3D(0.6, 1.8, 0.0), Point3D(0.7, 1.9, 0.0), Point3D(0.8, 1.8, 0.0), Point3D(0.9, 1.8, 0.0), Point3D(1.0, 1.8, 0.0),
        Point3D(1.1, 1.8, 0.0), Point3D(1.2, 1.8, 0.0), Point3D(1.3, 1.8, 0.0), Point3D(1.4, 1.8, 0.0), Point3D(1.5, 1.8, 0.0),
        Point3D(1.6, 1.8, 0.0), Point3D(1.7, 1.8, 0.0), Point3D(1.8, 1.8, 0.0), Point3D(1.9, 1.8, 0.0), Point3D(2.0, 1.8, 0.0)
        };
    int numScales = 5;
    double dim1 = computeFractalDimensionGeometry(points, numScales);
    double dim2 = computeFractalDimensionMass(points, numScales);
    std::cout << "FD of sample with geometry " << dim1 << " and mass " << dim2 << ". Exact FD is " << "1.59" << std::endl;
    return;
}

//поверхность куба
std::vector<Point3D> generateHollowCube(double size = 4, double density = 0.2) {
    std::vector<Point3D> points;
    double step = size / (density * 100);
    double x = 0, y = 0, z = 0;
    while (x <= size) {
        y = 0;
        while (y <= size) {
            points.emplace_back(Point3D{ x, y, 0});
            points.emplace_back(Point3D{ x, y, static_cast<int>(size) % 2 == 0 ? size - step : size });
            y += step;
        }
        x += step;
    }
    y = 0;
    while (y <= size) {
        z = 0 + step;
        while (z < size) {
            points.emplace_back(Point3D{ 0, y, z });
            points.emplace_back(Point3D{ static_cast<int>(size) % 2 == 0 ? size - step : size , y, z });
            z += step;
        }
        y += step;
    }
    x = 0 + step;
    while (x < size) {
        z = 0 + step;
        while (z < size) {
            points.emplace_back(Point3D{ x, 0, z });
            points.emplace_back(Point3D{ x, static_cast<int>(size) % 2 == 0 ? size - step : size, z });
            z += step;
        }
        x += step;
    }
    return points;
}

void testHollowCube() {
    int numScales = 5;
    std::vector<Point3D> HollowCube = generateHollowCube();
    float dim1 = computeFractalDimensionGeometry(HollowCube, numScales);
    float dim2 = computeFractalDimensionMass(HollowCube, numScales);
    std::cout << "FD of hollow cube with geometry " << dim1 << " and mass " << dim2 << std::endl;
    return;

}

int main()
{
    testSquareDimension();
    testSquare();
    testSquareWithHole();
    testHollowCube();
    return 0;
}
