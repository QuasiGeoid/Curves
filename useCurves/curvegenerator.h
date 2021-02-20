#ifndef CURVEGENERATOR_H
#define CURVEGENERATOR_H

#include <memory>

#include <../lib/curves.h>

using pCurve = std::shared_ptr<AbstractCurve>;

class CurveGenerator
{
public:
    CurveGenerator();

    pCurve createRandomCircle();
    pCurve createRandomEllipse();
    pCurve createRandomHelix();

    pCurve createRandomCurve();

private:
    double randomCurveParameter();
    int randomCurveType();
};

#endif // CURVEGENERATOR_H
