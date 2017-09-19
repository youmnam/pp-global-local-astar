/*
 * GraphBuilder module used for reading a zero and 1 maps and generate 2 data structures:
 * (1) 2d array which represent graph : nodes, edges with cost
 * 		0	1	2
 * 		---------
 *  0 |	0	2	3
 *  1 |	2	0	1
 *  2 |	3	1	0
 * 3 nodes: n0 connected to node 1 with cost
 *
 * (2) vector of coordinate: store the x,y position of the defined node
 *  n | (x,y)
 * 	0 | (3,3)
 * 	1 | (2,4)
 * 	2 | (4,5)
 *
 * 	there are 4 ways of generating the graph: visibility, Voronoi, fixed/variable cell decomp, lattice graph
*/

#ifndef GRAPH_BULDER_H
#define GRAPH_BULDER_H
#include "datatypes.h"
#include "StateSpace.h"
#include <iostream>
#include <fstream>
#include <string>
#include<cmath>
using namespace std;

class GraphBuilder{
	protected:
		string map_file;
		string graph_file;
		string coor_file;
		string absfPath = "./mapdata/";
		bmatrix map_matrix;
		unint32 map_h, map_w;
		StateSpace s_space;

	public:
		GraphBuilder(){}
		GraphBuilder(string mapf); //image represents map 0,1
		GraphBuilder(string mapf,string coorf); //files that contain graph information
		void setAbsoluteFilePath(char * absf);
		matrix getGraph();		// open graph_file, construct graph matrix
		vector<intPair> getCoordinates();
	    void buildGraph(){}; //abstract function, take input map and generate graph_file and coor_file
	    void readMap();
	    bmatrix getMapMatrix();
        bool isCorner(int i,int j);
        bool isCorner(int i,int j, int &type); //type : 1:LU 2:LB 3:RU 4:RB
        bool isLeftUpper  (int i, int j);
		bool isLeftBottom (int i, int j);
		bool isRightUpper (int i, int j);
		bool isRightBottom(int i, int j);

};



#endif
