#ifndef PATHEX_H
#define PATHEX_H
#include "datatypes.h"
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "opencv2/opencv.hpp"
using namespace std;



class PathExecuter{
public:
	PathExecuter(){}
	virtual void executePath(vector<unint32> path,vector<intPair> coord) = 0;
};


class GraphicalPathExecuter : public PathExecuter{
private:
	int w = 480;
	int h = 640;
	bmatrix bmap;

public:
	GraphicalPathExecuter(): PathExecuter(){ }
	GraphicalPathExecuter(int w, int h): PathExecuter(){this->w=w; this->h=h;}
	GraphicalPathExecuter(bmatrix map){ bmap = map; this->w=bmap.size(); this->h=bmap[0].size();}
	void drawLine( cv::Mat img, cv::Point start, cv::Point end , cv::Scalar sc);
	void drawFilledCircle( cv::Mat img, cv::Point center ,float rad, int r,int g, int b );
	void executePath(vector<unint32> path,vector<intPair> coord) ;
	void drawVisibilityGraph(vector<edge> path,vector<corner> coord);
	void drawVoronoiGraph(vector<edge> path,vector<intPair> coord);
	void executePath(vector<RRTNode> path);
	void executePath(vector<intPair> path);

	void drawMapwithWayPoints(vector<intPair> coord);
  //  static void onMouse( int event, int x, int y, int, void* );


};

class VrepExecuter : public PathExecuter{
private:
	int w = 480;
	int h = 640;

	bmatrix bmap;

public:

	VrepExecuter(bmatrix map){ bmap = map; this->w=bmap.size(); this->h=bmap[0].size();}
	void executePath(vector<unint32> path,vector<intPair> coord);
	void executePath(vector<intPair> coord);
	intPair transformV2P(float x,float y);
	pair<float,float>  transformP2V(int x,int y);
};

#endif
