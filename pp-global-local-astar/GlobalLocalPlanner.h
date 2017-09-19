/*
 * GlobalLocalPlanner.h
 *
 *  Created on: Dec 23, 2016
 *      Author: youmna
 */

#ifndef GLOBALLOCALPLANNER_H_
#define GLOBALLOCALPLANNER_H_

#include "PathFinder.h"
#include "GraphBuilder.h"
#include "datatypes.h"
#include <string>
using namespace std;

#define GRID_BASED_GRAPH 0
#define VORONOI_BASED_GRAPH 1
#define VISIBILITY_BASED_GRAPH 2

class GlobalLocal_Planner {

private:
	string map_file = "";
	string graph_file ="";
	string coor_file = "";
	StateSpace s_space;
	bmatrix orignalMap;
	int width;
	int height;
	vector<int> path;

public:
	 GlobalLocal_Planner( string roadmapfile,string roadmap_coorfile, string mapfile, short graphtype);
	 bmatrix createSubMap( intPair,intPair,intPair&,intPair&,int&,int&);
	 int FindClosestWaypoint(vector<intPair> &waypoints, intPair point);
	 vector<floatPair> plan(float,float);
	 vector<floatPair> planlocal(float sx,float sy,float ex,float ey,float obs_dist,float robo_heading);
	 void getLinePoints(vector<intPair> &globalpath,intPair point1,intPair point2);
};

#endif /* GLOBALLOCALPLANNER_H_ */
