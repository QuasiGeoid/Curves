#include <cmath>
#include <ctime>

#include "curvegenerator.h"

const double MIN_VALUE = -10.0;
const double MAX_VALUE = 10.0;

double CurveGenerator::randomCurveParameter()
{
    return (double)(rand()) / RAND_MAX * (MAX_VALUE - MIN_VALUE) + MIN_VALUE; // returns a random number in a range [MIN_VALUE, MAX_VALUE)
}

int CurveGenerator::randomCurveType()
{
    return rand() % (e_Helix + 1); // returns a number between in a range [0, 2]
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
        case e_Circle:
            return createRandomCircle();
        case e_Ellipse:
            return createRandomEllipse();
        case e_Helix:
            return createRandomHelix();
    }
}
