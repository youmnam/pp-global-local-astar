/*#include "GlobalLocalPlanner.h"
#include "StateSpace.h"
double getDistance1(intPair p1, intPair p2){
	return sqrt(pow(p1.first - p2.first,2) + pow(p1.second - p2.second,2));
}

int main(){

	GlobalLocal_Planner planner("roadmaprealcost.graph","roadmap.coor","campus_map_573x492_uppermodi.jpg",0);
   // while(1)
	//planner.plan(-4.2912,21.09);
	planner.planlocal(-4.2912,21.09,-4.2912,19.00);


	vector<intPair> coor;

	   fstream myfile;
	   	myfile.open("/home/youmna/ARL_Lab_researchwork/PathPlanner_v5.0/mapdata/roadmap.coor",std::fstream::in);
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
	   	     }
	fstream outfile;
	myfile.open("/home/youmna/ARL_Lab_researchwork/PathPlanner_v5.0/mapdata/roadmap.graph",std::fstream::in);
	outfile.open("/home/youmna/ARL_Lab_researchwork/PathPlanner_v5.0/mapdata/roadmaprealcost.graph",std::fstream::out);
	if (!myfile.is_open()) cout<< "Can't open graph file!" <<endl;

     if (myfile.is_open()){
   	  int nvetices , nedges;

   	  myfile >> nvetices >> nedges;
   	  outfile <<  nvetices << " " << nedges <<endl;
     for(int i =0; i < nedges ; i++){
int v1, v2,cost;
myfile >> v1 >> v2 >> cost;

    	 outfile << v1 <<" " <<v2 <<" " << getDistance1(coor[v1],coor[v2]) << endl;

     }
 	   myfile.close();
   	   outfile.close();
     }
	return 0;

	StateSpace state;
	state.readMap("../mapdata/campus_map_573x492_roadboundary.jpg");

	fstream outfile;
	outfile.open("../mapdata/roadboundarylua.data",std::fstream::out);

	bmatrix map= state.getMapMatrix();
	outfile<< state.getWidth() <<" " << state.getHieght() << std::endl;
	for(int i=0; i<map.size(); i++){
		for(int j=0; j<map.size(); j++){
			outfile << map[i][i] <<" ";
		}
		outfile << endl;
	}

	outfile.close();
}
*/
