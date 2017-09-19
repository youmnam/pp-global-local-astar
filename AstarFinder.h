#ifndef ASTAR_H
#define ASTAR_H

#include "PathFinder.h"

class AstartFinder : public PathFinder {
private:
	priority_queue< intPair, std::vector<intPair>, compare > Q;
	vector<unint32> dist;
	vector<unint32> h_value;
	vector<intPair> coor;
	vector<sint32> prev; //holds the previous of each node -- form where I reach node i
	void formulatePath(unint32 end);

public:
	AstartFinder(GraphBuilder gb) ;
	void findPath(unint32 start, unint32 end);
	void computeHeuristic(unint32 end);

};

#endif
