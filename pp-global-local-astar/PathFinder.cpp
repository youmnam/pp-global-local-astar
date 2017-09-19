/*
 * PathFinder is used to find a path in a graph which represented by a  matrix
 * it produces a vector of nodes(number of node) that can be then used to execute the path.
 * */
#include "PathFinder.h"

PathFinder :: PathFinder(GraphBuilder g){
	graph = g.getGraph();
	all_pos = g.getCoordinates();
}



vector<unint32> PathFinder:: getPath(){
   return path;
}



void DijkstraFinder:: formulatePath(unint32 end){
	for(int i=0; i<prev.size() ; i++)
		cout << prev[i] << endl;

	int i = end;
	while(prev[i] != -1){
		path.push_back(i);
		i = prev[i];
	}
	path.push_back(i);
}


void DijkstraFinder:: findPath(unint32 start, unint32 end){
	//1. Initialization
	unint32 nV = graph[0].size();
	for(int i = 0 ; i< nV; i++){
		dist.push_back(MAX);
		prev.push_back(UNDEFINE);
		Q.push(make_pair(i,dist[i]));
	}
	//Mark start as visited with cost 0, update queue
	dist[start] = 0;
	Q.push(make_pair(start,dist[start]));

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
					Q.push(make_pair(i,dist[i]));
				}
			}
		}

	formulatePath(end);
}





