#include <algorithm>
#include <iostream>
#include <cmath>
#include <ctime>
#include <vector>

#include <curvegenerator.h>
#include <omp.h>

using namespace std;

const size_t NUM_CURVES = 100;

int main()
{
    srand(time(0));
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
        c->getCurveType();
        cout << c->getPoint(M_PI / 4) << endl;
        cout << c->getVector(M_PI / 4) << endl;

        // fill the "circles" container
        if(typeid(*c).hash_code() == typeid(Circle).hash_code())
            circles.emplace_back(dynamic_pointer_cast<Circle>(c));
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
