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

#include "GraphBuilder.h"

GraphBuilder:: GraphBuilder(string mapf)
{
	map_file = absfPath + mapf;
 	//cout << "map file:"<<map_file << endl;
}

GraphBuilder:: GraphBuilder(string mapf,string coorf)
{
	graph_file = absfPath + mapf;
	coor_file = absfPath + coorf;

 	cout << "map file:"<<graph_file << endl;
}

void  GraphBuilder::  setAbsoluteFilePath(char * absf)
{
		absfPath = absf;
}

matrix  GraphBuilder::getGraph()
{
	matrix graph;

	fstream myfile;
	myfile.open(graph_file.c_str(),std::fstream::in);
	if (!myfile.is_open()) cout<< "Can't open graph file!" <<endl;

     if (myfile.is_open()){
   	  int nvetices , nedges;

   	  myfile >> nvetices >> nedges;
	  graph.resize(nvetices);

	  for(int i=0; i<nvetices; i++){
		  for(int j=0; j<nvetices; j++){
			  graph[i].push_back(0);
		    }
		}

		int v1,v2;
		sfloat cost;
		for(int i=0; i<nedges; i++){
			myfile >> v1 >> v2 >> cost;
			//cout << v1 <<","<<v2 <<":" <<cost ;
			graph[v1][v2] = cost;
		    graph[v2][v1] = cost;
		}
		myfile.close();
		}

	return graph;
}


vector<intPair> GraphBuilder:: getCoordinates(){
   	vector<intPair> coor;

   	fstream myfile;
   		myfile.open(coor_file.c_str(),std::fstream::in);
   		if (!myfile.is_open()) cout<< "Can't open coor file!" <<endl;

   	     if (myfile.is_open()){
   	   	  int nvetices;
   	   	  myfile >> nvetices ;
   	   	  coor.resize(nvetices);
   	   	  for(int i = 0 ; i<nvetices ; i++){
   	   		  int v,x,y;
   	   		  myfile >> v >> x >> y ;
   	   		  coor[v] = make_pair(x,y);
   	   	  }
   	   myfile.close();
 	   /* TEST
 	    for(int i = 0 ; i<nvetices ; i++){
 	     cout << i << " " <<coor[i].first << " -- "<< coor[i].second <<endl;
 	    }
 	    */
   	 }
   	return coor;
}


void GraphBuilder:: readMap()
{
	s_space.readMap(map_file);
	map_h = s_space.getWidth();
	map_w = s_space.getHieght();
	map_matrix = s_space.getMapMatrix();
	cout << map_h << "  " << map_w << endl;
}

bmatrix GraphBuilder::getMapMatrix()
{
	return map_matrix;
}

bool GraphBuilder::isLeftUpper  (int i, int j)
{
	if(map_matrix[i][j] == 1
	 && (i-1 >=0 && map_matrix[i-1][j]==0)
	 && (j-1>=0  && map_matrix[i][j-1]==0)
	 && map_matrix[i-1][j-1]==0){
	// cout << i << "," << j << " is left upper"<<endl;
		return true;

	}
	return false;
}

bool GraphBuilder::isLeftBottom (int i, int j)
{
	if(map_matrix[i][j] == 1
	 && i+1 < map_h && map_matrix[i+1][j]==0
	 && j-1 >=0     && map_matrix[i][j-1]==0
	 && map_matrix[i+1][j-1]==0)
		return true;

	return false;
}

bool GraphBuilder::isRightUpper (int i, int j)
{
	if(map_matrix[i][j] == 1
	 && i-1 >= 0  && j-1 >=0 && map_matrix[i-1][j-1]==0
	 && j+1 < map_w  && map_matrix[i-1][j+1]==0
	 && map_matrix[i][j+1]==0)
		return true;

	return false;
}

bool GraphBuilder::isRightBottom(int i, int j)
{
	if(map_matrix[i][j] == 1
		 && i+1 < map_h  && map_matrix[i+1][j]==0
		 && j+1 < map_w  && map_matrix[i][j+1]==0
		 && map_matrix[i+1][j+1]==0)
			return true;

		return false;
}

bool GraphBuilder::isCorner(int i,int j)
{
	if( isLeftUpper(i,j)  || isLeftBottom(i,j)
	  ||isRightUpper(i,j) || isRightBottom(i,j))
	{
		return true;
	}else{
		return false;
	}
}


bool GraphBuilder::isCorner(int i,int j,int &type)
{
	if( isLeftUpper(i,j))
	{
		type=LU;
		return true;
	}
	else if(isLeftBottom(i,j))
	{
		type=LB;
		return true;
	}
	else if (isRightUpper(i,j) )
	{
		type = RU;
		return true;
	}
	else if(isRightBottom(i,j))
	{
		type= RB;
		return true;
	}else{
		type =_NAN;
		return false;
	}
}
