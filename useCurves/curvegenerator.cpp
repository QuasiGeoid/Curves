#include <cmath>
#include <ctime>

#include "curvegenerator.h"

const double MIN_VALUE = 1.0;
const double MAX_VALUE = 10.0;

CurveGenerator::CurveGenerator()
{
    srand(time(nullptr));
}

double CurveGenerator::randomCurveParameter()
{
    return (double)(rand()) / RAND_MAX * (MAX_VALUE - MIN_VALUE) + MIN_VALUE; // returns a random number in a range [MIN_VALUE, MAX_VALUE)
}

int CurveGenerator::randomCurveType()
{
    return rand() % (HELIX + 1); // returns a number between in a range [0, 2]
}

pCurve CurveGenerator::createRandomCircle()
{
    double radius = fabs(randomCurveParameter());
    return std::make_shared<Circle>(radius);
}

pCurve CurveGenerator::createRandomEllipse()
{
    double radiusX = fabs(randomCurveParameter());
    double radiusY = fabs(randomCurveParameter());
    return std::make_shared<Ellipse>(radiusX, radiusY);
}

pCurve CurveGenerator::createRandomHelix()
{
    double radius = fabs(randomCurveParameter());
    double step = fabs(randomCurveParameter());
    return std::make_shared<Helix>(radius, step);
}

pCurve CurveGenerator::createRandomCurve()
{
    switch (randomCurveType()) {
        case CIRCLE:
            return createRandomCircle();
        case ELLIPSE:
            return createRandomEllipse();
        case HELIX:
            return createRandomHelix();
    }
}
