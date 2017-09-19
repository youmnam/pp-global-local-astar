/*
 * GridGraphBuilder.h
 *
 *  Created on: Oct 28, 2016
 *      Author: youmna
 */

#ifndef GRIDGRAPHBUILDER_H_
#define GRIDGRAPHBUILDER_H_
#include "datatypes.h"
#include "GraphBuilder.h"
#include <vector>
using namespace std;

enum Direction{L,R,U,D,DL,DR,UR,UL};
struct Neighbor{
	int i;
	int j;
	Direction relation;
	Neighbor(int x,int y, Direction d){
		i=x;
		j=y;
		relation = d;
	}
};

class GridGraphBuilder : public GraphBuilder {

public:
	GridGraphBuilder(string mapf);
	GridGraphBuilder(bmatrix);
	void buildGraph();
	void buildGraph(int);
private:
	vector<vector<unint32> > labelMatrix;
	vector<edge> edges_list;
	vector<pair<int,intPair> > coor_list;
	vector<Neighbor> get8Neighbors(int i,int j, int rows,int cols);
	vector<Neighbor> get8Neighbors(int i,int j, int rows,int cols, int step);



};



#endif /* GRIDGRAPHBUILDER_H_ */
