#include "AstarFinder.h"

AstartFinder::AstartFinder(GraphBuilder gb) : PathFinder(gb)
{
	coor = gb.getCoordinates();
}

void AstartFinder:: formulatePath(unint32 end){
	//for(int i=0; i<prev.size() ; i++)
	//	cout << prev[i] << endl;

	int i = end;
	while(prev[i] != -1){
		path.push_back(i);
		i = prev[i];
	}
	path.push_back(i);
}


void AstartFinder:: findPath(unint32 start, unint32 end){
	//1. Initialization
	unint32 nV = graph[0].size();
	for(int i = 0 ; i< nV; i++){
		dist.push_back(MAX);
		h_value.push_back(0);
		prev.push_back(UNDEFINE);
		Q.push(make_pair(i,dist[i]));
	}
	computeHeuristic(end);
	//Mark start as visited with cost 0, update queue
	dist[start] = 0;
	Q.push(make_pair(start,dist[start]+h_value[start]));

	//loop of dijkstra algorithm
	while(!Q.empty()){
		int currentNode = Q.top().first;
		Q.pop();
		//for all currentNode neighbors
		for(int i =0; i<nV; i++){
			if(graph[currentNode][i] !=0) //there is and edge
				if(dist[currentNode] + graph[currentNode][i] < dist [i]){
					dist[i] = dist[currentNode] + graph[currentNode][i];
					prev[i] = currentNode;
					Q.push(make_pair(i,dist[i]+h_value[i]));
				}
			}
		}

	formulatePath(end);
}


void AstartFinder:: computeHeuristic(unint32 end)
{
	//loop in the number of vertices
	for(int i=0; i<graph.size(); i++)
	{
		h_value[i] = sqrt(pow(coor[i].first- coor[end].first,2) + pow(coor[i].second- coor[end].second,2));
	}
}
