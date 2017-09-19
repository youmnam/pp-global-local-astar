/*
 * PathFinder is used to find a path in a graph which represented by a  matrix
 * it produces a vector of nodes(number of node) that can be then used to execute the path.
 * */
#ifndef PATHFINDER_H
#define PATHFINDER_H

#include <vector>
#include <queue>
#include "datatypes.h"
#include "GraphBuilder.h"

#define MAX 999999999
#define UNDEFINE -1
using namespace std;

class compare
{
public:
    bool operator() (std::pair<int, int> a, std::pair<int, int> b)
	    {
		return a.second <b.second;
	    }
};

class PathFinder{
protected:
	matrix graph;
	vector<unint32> path; //nodes sorted n1,n2,n3 --> n1 connects to n2, n2 connects n3
	vector<pair<int,int> > all_pos;   // index -> pos ; index = node number , pos = i,j in the original map
public:
	PathFinder(GraphBuilder g);
	virtual void findPath(unint32 start, unint32 end) = 0 ;
	vector<unint32> getPath();
};

class DijkstraFinder : public PathFinder {
private:
	priority_queue< intPair, std::vector<intPair>, compare > Q;
	vector<unint32> dist;
	vector<sint32> prev; //holds the previous of each node -- form where I reach node i
	void formulatePath(unint32 end);

public:
	DijkstraFinder(GraphBuilder gb) : PathFinder(gb) {}
	void findPath(unint32 start, unint32 end);

};

#endif
