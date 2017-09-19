/*
 * GridGraphBuilder.cpp
 *
 *  Created on: Oct 28, 2016
 *      Author: youmna
 */

#include "GridGraphBuilder.h"

GridGraphBuilder::GridGraphBuilder(string mapf) : GraphBuilder(mapf) {

}
GridGraphBuilder:: GridGraphBuilder(bmatrix m) : GraphBuilder("gridbased.graph","gridbased.coor"){
	map_matrix = m;
	map_h = m.size();
	map_w = m[0].size();
}

void GridGraphBuilder::buildGraph(){

	// 1. Initialize label matrix with the image size "map_matrix"
	labelMatrix.resize(map_h);
	for(int i=0; i<map_h ; i++){
		labelMatrix[i].resize(map_w);
	}

	//2. Fill the label Matrix by tracing the map_matrix data
	int count=1;
	for(int i=0; i<map_h ; i++)
	{
		for(int j=0; j<map_w; j++)
		{
			if(map_matrix[i][j] ==1)
				labelMatrix[i][j] =0;
			else
				labelMatrix[i][j] =count++;
			cout <<labelMatrix[i][j] <<" ";
		}
		cout << endl;
	}
	cout <<"labeled matrix has been created" <<endl;

	//3. Create the graph using the label matrix
	//:: loop over the label matrix and for each cell create node with edges to its non zero neighbors
	//:: cost of L,R,U,D is 1 and cost to DL,DR,UR,UD is 1.4
	for(int i=0; i<map_h ; i++)
	{
		for(int j=0; j<map_w; j++)
		{
			unint32 vcell =labelMatrix[i][j]; // vcell: visited cell
			if (vcell != 0)
			{
				coor_list.push_back(make_pair(vcell,make_pair(i,j)));
				vector<Neighbor> ncells = get8Neighbors(i,j,map_h,map_w); // ncells: neighbors cells
				for(int k=0; k<ncells.size() ; k++)
				{
					unint32 ng = labelMatrix[ncells[k].i][ncells[k].j];
					if( ng != 0) //there is a label: valid neighbor
					{
						if(ncells[k].relation == U || ncells[k].relation == D ||
						   ncells[k].relation == R || ncells[k].relation == L)
						   edges_list.push_back(edge(vcell,ng,1));
						else
						   edges_list.push_back(edge(vcell,ng,1.4));
					  coor_list.push_back(make_pair(ng,make_pair(ncells[k].i,ncells[k].j)));
					}
				}
			}
		}
	}
	cout <<"edges and corners has been created" <<endl;

	//4.write the result edges_list, coor_list to the file
	fstream myfile;
	graph_file = absfPath +"gridbased.graph";
	myfile.open(graph_file.c_str(),std::fstream::out);
		if(myfile.is_open()){
			cout << "Edges:" <<endl;
			myfile << coor_list.size()  << " " << edges_list.size() <<endl;
			for(unsigned int i = 0; i<edges_list.size() ; i++)
			{
				myfile <<  edges_list[i].v1 << " " << edges_list[i].v2 << " " << edges_list[i].cost <<endl;;
			}
			cout <<"End of Edges" <<endl;
			myfile.close();
		}

		coor_file = absfPath +"gridbased.coor";
		myfile.open(coor_file.c_str(),std::fstream::out);
		if(myfile.is_open())
		{  	myfile << coor_list.size() <<endl;
			for(unsigned int i = 0; i < coor_list.size() ; i++)
			{
				myfile <<  coor_list[i].first << " " << coor_list[i].second.first << " " << coor_list[i].second.second <<endl;
			}
			cout <<"End of COOR" <<endl;
			myfile.close();
		}


}

void GridGraphBuilder::buildGraph(int step){

	// 1. Initialize label matrix with the image size "map_matrix"
	labelMatrix.resize(map_h);
	for(int i=0; i<map_h ; i++){
		labelMatrix[i].resize(map_w);
	}

	//2. Fill the label Matrix by tracing the map_matrix data
	int count=1;
	for(int i=0; i<map_h ; i++)
	{
		for(int j=0; j<map_w; j++)
		{
			if(map_matrix[i][j] ==1)
				labelMatrix[i][j] =0;
			else
				labelMatrix[i][j] =count++;
			cout <<labelMatrix[i][j] <<" ";
		}
		cout << endl;
	}
	cout <<"labeled matrix has been created" <<endl;

	//3. Create the graph using the label matrix
	//:: loop over the label matrix and for each cell create node with edges to its non zero neighbors
	//:: cost of L,R,U,D is 1 and cost to DL,DR,UR,UD is 1.4
	int sz=0;
	for(int i=0; i<map_h ; i++)
	{
		for(int j=0; j<map_w; j++)
		{
			unint32 vcell =labelMatrix[i][j]; // vcell: visited cell
			if (vcell != 0)
			{
				coor_list.push_back(make_pair(vcell,make_pair(i,j)));
				vector<Neighbor> ncells = get8Neighbors(i,j,map_h,map_w); // ncells: neighbors cells
				for(int k=0; k<ncells.size() ; k++)
				{
					unint32 ng = labelMatrix[ncells[k].i][ncells[k].j];
					if( ng != 0) //there is a label: valid neighbor
					{
						if(ncells[k].relation == U || ncells[k].relation == D ||
						   ncells[k].relation == R || ncells[k].relation == L)
						   edges_list.push_back(edge(vcell,ng,1));
						else
						   edges_list.push_back(edge(vcell,ng,1.4));
					  coor_list.push_back(make_pair(ng,make_pair(ncells[k].i,ncells[k].j)));
					  sz++;
					}
				}
			}
		}
	}
	cout <<"edges and corners has been created" <<endl;

	//4.write the result edges_list, coor_list to the file
	fstream myfile;
	graph_file = absfPath +"graph_file";
	myfile.open(graph_file.c_str(),std::fstream::out);
		if(myfile.is_open()){
			cout << "Edges:" <<endl;
			myfile << coor_list.size()  << " " << edges_list.size() <<endl;
			for(unsigned int i = 0; i<edges_list.size() ; i++)
			{
				myfile <<  edges_list[i].v1 << " " << edges_list[i].v2 << " " << edges_list[i].cost <<endl;;
			}
			cout <<"End of Edges" <<endl;
			myfile.close();
		}

		coor_file = absfPath +"coor_file";
		myfile.open(coor_file.c_str(),std::fstream::out);
		if(myfile.is_open())
		{  	myfile << sz <<endl;
			for(unsigned int i = 0; i < coor_list.size() ; i++)
			{
				myfile <<  coor_list[i].first << " " << coor_list[i].second.first << " " << coor_list[i].second.second <<endl;
			}
			cout <<"End of COOR" <<endl;
			myfile.close();
		}


}

vector<Neighbor> GridGraphBuilder::get8Neighbors(int i,int j, int rows,int cols){
	vector<Neighbor> neighbors;
	bool ii,di,ij,dj;
	ii = i+1 < rows;
	di = i-1 >= 0;
	ij = j+1 < cols;
	dj = j-1 >= 0;

	if(di && dj)
		neighbors.push_back(Neighbor(i-1,j-1,UL));
	if(di)
		neighbors.push_back(Neighbor(i-1,j,U));
	if(di & ij)
		neighbors.push_back(Neighbor(i-1,j+1,UR));
	if(dj)
		neighbors.push_back(Neighbor(i,j-1,L));
	if(ij)
		neighbors.push_back(Neighbor(i,j+1,R));
	if(ii && dj)
		neighbors.push_back(Neighbor(i+1,j-1,DL));
	if(ii)
		neighbors.push_back(Neighbor(i+1,j,D));
	if(ii && ij)
		neighbors.push_back(Neighbor(i+1,j+1,DR));

	return neighbors;
}




vector<Neighbor> GridGraphBuilder::get8Neighbors(int i,int j, int rows,int cols, int step){
	vector<Neighbor> neighbors;
	bool ii,di,ij,dj;
	ii = i+1 < rows;
	di = i-1 >= 0;
	ij = j+1 < cols;
	dj = j-1 >= 0;

	if(di && dj)
		neighbors.push_back(Neighbor(i-1,j-1,UL));
	if(di)
		neighbors.push_back(Neighbor(i-1,j,U));
	if(di & ij)
		neighbors.push_back(Neighbor(i-1,j+1,UR));
	if(dj)
		neighbors.push_back(Neighbor(i,j-1,L));
	if(ij)
		neighbors.push_back(Neighbor(i,j+1,R));
	if(ii && dj)
		neighbors.push_back(Neighbor(i+1,j-1,DL));
	if(ii)
		neighbors.push_back(Neighbor(i+1,j,D));
	if(ii && ij)
		neighbors.push_back(Neighbor(i+1,j+1,DR));

	return neighbors;
}
