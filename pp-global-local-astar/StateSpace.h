#ifndef STATE_H
#define STATE_H
#include "datatypes.h"
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include "opencv2/opencv.hpp"

using namespace std;

class StateSpace{
private:
	unint32 width;
    unint32 height;
    bmatrix map_matrix;

public:
    vector<StatePoint> C_obs;
    void readMap(string fileName);
    unint32 getWidth(){return width;}
    unint32 getHieght(){return height;}
    bmatrix getMapMatrix(){return map_matrix;}
};

#endif
