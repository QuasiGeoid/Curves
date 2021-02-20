#include <algorithm>
#include <iostream>
#include <cmath>
#include <ctime>
#include <vector>

#include <curvegenerator.h>
#include <omp.h>

using namespace std;

const size_t NUM_CURVES = 10;

int main()
{
    vector<shared_ptr<AbstractCurve> > randomCurves;

    CurveGenerator curveGen;

    size_t i = 0;
    while(i < NUM_CURVES) {
        randomCurves.emplace_back(curveGen.createRandomCurve());
        ++i;
    }

    vector<shared_ptr<Circle> > circles;
    for(auto &c : randomCurves)
    {
        // show the name of type, 3D point and 3D vector
        switch (c->getCurveType()) {
            case 0:
                cout << "Type: Circle" << endl;
                break;
            case 1:
                cout << "Type: Ellipse" << endl;
                break;
            case 2:
                cout << "Type: Helix" << endl;
                break;
        }
        cout << c->getPoint(M_PI / 4) << endl;
        cout << c->getVector(M_PI / 4) << endl;

        if(c->getCurveType() == CIRCLE)
            circles.emplace_back(static_pointer_cast<Circle>(c));
    }

    // sort the "circles" container by radii
    sort(circles.begin(), circles.end(),
         [](const auto& r1, const auto& r2){ return r1->getRadius() < r2->getRadius(); });

    // show the radii of the circles
    cout << "\nRadii of circles: " << "\n";
    for(auto &c : circles)
        cout << c->getRadius() << endl;

    //calculating the sum of the radii of circles using OpenMP
    double sumRadiusCircle = 0.0;

    #pragma omp parallel shared(circles) reduction (+: sumRadiusCircle) num_threads(4)
    {
    #pragma omp for
    for(auto it = circles.begin(); it < circles.end(); ++it)
        sumRadiusCircle += (*it)->getRadius();
    }

    cout << "\nSum of circle radii: " << sumRadiusCircle << endl;
    return 0;
}
