#ifndef CURVEGENERATOR_H
#define CURVEGENERATOR_H

#include <memory>

#include <../curvesLib/curves.h>

using pCurve = std::shared_ptr<AbstractCurve>;

class CurveGenerator
{
public:
    pCurve createRandomCircle();
    pCurve createRandomEllipse();
    pCurve createRandomHelix();

    pCurve createRandomCurve();

private:
    enum CurveType {e_Circle, e_Ellipse, e_Helix};

    double randomCurveParameter();
    int randomCurveType();
};

#endif // CURVEGENERATOR_H
