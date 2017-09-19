//#include "PathFinder.h"
//#include "AstarFinder.h"
//#include "PathExecuter.h"
//#include "VisibilityBuilder.h"
//#include "VoronoiBuilder.h"
//#include "GridGraphBuilder.h"
//#include "SAnnealingPlanner.h"
//#include "ACO_Planner.h"
//#include "PSOPlanner.h"
//#include "RRT.h"
//#include "LRMap.h"
//#include <iostream>
//using namespace std;//#include "PathFinder.h"
//#include "AstarFinder.h"
//#include "PathExecuter.h"
//#include "VisibilityBuilder.h"
//#include "VoronoiBuilder.h"
//#include "GridGraphBuilder.h"
//#include "SAnnealingPlanner.h"
//#include "ACO_Planner.h"
//#include "PSOPlanner.h"
//#include "RRT.h"
//#include "LRMap.h"
//#include <iostream>
//using namespace std;
//
//void printGraphMatrix(matrix graph);
//void printPath(vector<unint32> path);
//
//int main(){
///* Test 1 : two simple graph and coordinate files
//	//Build Graph
//	char * graph_file ="s_graph_file";
//	char * coor_file ="s_coor_file";
//
//	GraphBuilder gbuild(graph_file,coor_file);
//	matrix graph= gbuild.getGraph();
//	printGraphMatrix(graph);
//
//	//Find a Path using Dijkstra
//	PathFinder * pfinder = new DijkstraFinder(gbuild);
//	pfinder->findPath(2,3);
//	printPath(pfinder->getPath());
//
//	//Execute Path : Draw graphically
//	PathExecuter * pExec = new GraphicalPathExecuter();
//	pExec->executePath(pfinder->getPath(),gbuild.getCoordinates());
//*/
//
///* Test 2 : Visibility Graph + Dijkstra path Finder
// * 	char * map_file ="building1.jpg";
//	VisibilityBuilder gbuild(map_file);
//	gbuild.readMap();
//	gbuild.buildGraph();
//
//	GraphicalPathExecuter * pExec = new GraphicalPathExecuter(gbuild.getMapMatrix());
//	pExec->drawVisibilityGraph(gbuild.edges_list, gbuild.corners_list);
//
//	PathFinder * pfinder = new DijkstraFinder(gbuild);
//	pfinder->findPath(2,20);
//	printPath(pfinder->getPath());
//
//	pExec->executePath(pfinder->getPath(),gbuild.getCoordinates());
//*/
///* Test 3 : Voronoi Graph + Dijkstra
//    char * map_file ="building1_450.jpg";
//	VoronoiBuilder gbuild(map_file);
//	gbuild.readMap();
//	gbuild.buildGraph();
//
//	GraphicalPathExecuter * pExec = new GraphicalPathExecuter(gbuild.getMapMatrix());
//	pExec->drawVoronoiGraph(gbuild.edges_list, gbuild.vertex_list);
//
//	PathFinder * pfinder = new DijkstraFinder(gbuild);
//	pfinder->findPath(870,3080);
//	printPath(pfinder->getPath());
//	pExec->executePath(pfinder->getPath(),gbuild.getCoordinates());
//	return 0;*/
//
///* Test 4: A* Algorithm with simple graph
//	//Build Graph
//	char * graph_file ="s_graph_file";
//	char * coor_file ="s_coor_file";
//
//	GraphBuilder gbuild(graph_file,coor_file);
//	matrix graph= gbuild.getGraph();
//	printGraphMatrix(graph);
//
//	//Find a Path using Dijkstra
//	PathFinder * pfinder = new AstartFinder(gbuild);
//	pfinder->findPath(2,3);
//	printPath(pfinder->getPath());
//
//	//Execute Path : Draw graphically
//	PathExecuter * pExec = new GraphicalPathExecuter();
//	pExec->executePath(pfinder->getPath(),gbuild.getCoordinates());
//	 */
//
///*
//	const clock_t begin_time = clock();
//	char * map_file ="building1.jpg";
//	VisibilityBuilder gbuild(map_file);
//	gbuild.readMap();
//	gbuild.buildGraph();
//
//
//	GraphicalPathExecuter * pExec = new GraphicalPathExecuter(gbuild.getMapMatrix());
//	//pExec->drawVoronoiGraph(gbuild.edges_list, gbuild.vertex_list);
//	pExec->drawVisibilityGraph(gbuild.edges_list, gbuild.corners_list);
//
//	PathFinder * pfinder = new AstartFinder(gbuild);
//	//pfinder->findPath(30,5956);
//	pfinder->findPath(10,54);
//	printPath(pfinder->getPath());
//	pExec->executePath(pfinder->getPath(),gbuild.getCoordinates());
//
//
//	 std::cout << "\nTime Taken:"<<float( clock () - begin_time ) /  CLOCKS_PER_SEC;
//
//*/
//	/*
//	 RRT planner("/home/youmna/ARL_Lab_researchwork/PathPlanner_v3.0/mapdata/campus1.jpg",10000000,30,0.5);
//
//	StatePoint start(30,227);
//	StatePoint goal(270,200);
//	cout<< "Done?" <<  planner.planPath(start,goal) <<endl;
//	GraphicalPathExecuter pExec(planner.grid.getMapMatrix());
//	pExec.executePath(planner.path);
//	*/
///*
// * ACO with Visibility
//	char * map_file ="building1.jpg";
//	VisibilityBuilder gbuild(map_file);
//	gbuild.readMap();
//	gbuild.buildGraph();
//
//	GraphicalPathExecuter * pExec = new GraphicalPathExecuter(gbuild.getMapMatrix());
//	pExec->drawVisibilityGraph(gbuild.edges_list, gbuild.corners_list);
//	//cv::waitKey( 0 );
//
//	PathFinder * pfinder = new ACOPlanner(gbuild);
//	pfinder->findPath(0,20);
//	printPath(pfinder->getPath());
//	pExec->executePath(pfinder->getPath(),gbuild.getCoordinates());
//*/
//
//	/*
//	 * ACO with Voronoi
//		char * map_file ="building1.jpg";
//		VoronoiBuilder gbuild(map_file);
//		gbuild.readMap();
//		gbuild.buildGraph();
//
//		GraphicalPathExecuter * pExec = new GraphicalPathExecuter(gbuild.getMapMatrix());
//		pExec->drawVoronoiGraph(gbuild.edges_list, gbuild.vertex_list);
//		//cv::waitKey( 0 );
//
//		PathFinder * pfinder = new ACOPlanner(gbuild);
//		pfinder->findPath(30,100);
//		printPath(pfinder->getPath());
//		pExec->executePath(pfinder->getPath(),gbuild.getCoordinates());
//*/
//
//	/*
//	 * ACO with Grid : Cell Decomposition
//		char * map_file ="map30.jpg";
//		GridGraphBuilder gbuild(map_file);
//		gbuild.readMap();
//		gbuild.buildGraph();
//
//		GraphicalPathExecuter * pExec = new GraphicalPathExecuter(gbuild.getMapMatrix());
//
//		PathFinder * pfinder = new ACOPlanner(gbuild);
//		pfinder->findPath(1,200);
//		printPath(pfinder->getPath());
//		pExec->executePath(pfinder->getPath(),gbuild.getCoordinates());
//
//*/
//	/*
//	 * A*  with Grid : Cell Decomposition
//
//	char * map_file ="map30.jpg";
//		GridGraphBuilder gbuild(map_file);
//		gbuild.readMap();
//		gbuild.buildGraph();
//
//		GraphicalPathExecuter * pExec = new GraphicalPathExecuter(gbuild.getMapMatrix());
//
//		PathFinder * pfinder = new DijkstraFinder(gbuild);
//		pfinder->findPath(1,200);
//		//printPath(pfinder->getPath());
//		pExec->executePath(pfinder->getPath(),gbuild.getCoordinates());
//
//	 */
//
//	/*
//	 * Simulated Annealing with Grid : Cell Decomposition
//		char * map_file ="map30.jpg";
//		GridGraphBuilder gbuild(map_file);
//		gbuild.readMap();
//		gbuild.buildGraph();
//
//		GraphicalPathExecuter * pExec = new GraphicalPathExecuter(gbuild.getMapMatrix());
//		PathFinder * pfinder = new SAnnealingPlanner(gbuild,2000,0.00001,100,6,0.9);
//		pfinder->findPath(1,200);
//
//		VrepExecuter * pvrepExec = new VrepExecuter(gbuild.getMapMatrix());
//		pvrepExec->executePath(pfinder->getPath(),gbuild.getCoordinates());
//		//printPath(pfinder->getPath());
//		pExec->executePath(pfinder->getPath(),gbuild.getCoordinates());
//*/
//	/*
//	 * PSO with Grid : Cell Decomposition
//		//char * map_file ="map30.jpg";
//		char * map_file ="campus_map_573x492.jpg";
//		GridGraphBuilder gbuild(map_file);
//		gbuild.readMap();
//		gbuild.buildGraph();
//
//		GraphicalPathExecuter * pExec = new GraphicalPathExecuter(gbuild.getMapMatrix());
//		//VrepExecuter * pvrepExec = new VrepExecuter(gbuild.getMapMatrix());
//
//		PathFinder * pfinder = new PSO_Planner(gbuild,100,1);
//		//PathFinder * pfinder = new AstartFinder(gbuild);
//		pfinder->findPath(90,53);
//		//printPath(pfinder->getPath());
//		//vector<>
//	//	pvrepExec->executePath(pfinder->getPath(),gbuild.getCoordinates());
//		pExec->executePath(pfinder->getPath(),gbuild.getCoordinates());
//*/
//
//
//	/*
//	 * Sub map creation
//		//char * map_file ="map30.jpg";
//		char * map_file ="campus_map_573x492.jpg";
//		LR_Map lrmap(map_file,10);
//		lrmap.writeSubMaps(); //convert big map image to sub images
//
//		GridGraphBuilder global_gbuild(lrmap.getLRMap());
//		global_gbuild.buildGraph();
//
//
//	    string submapfile = //#include "PathFinder.h"
//#include "AstarFinder.h"
//#include "PathExecuter.h"
//#include "VisibilityBuilder.h"
//#include "VoronoiBuilder.h"
//#include "GridGraphBuilder.h"
//#include "SAnnealingPlanner.h"
//#include "ACO_Planner.h"
//#include "PSOPlanner.h"
//#include "RRT.h"
//#include "LRMap.h"
//#include <iostream>
//using namespace std;
//
//void printGraphMatrix(matrix graph);
//void printPath(vector<unint32> path);
//
//int main(){
///* Test 1 : two simple graph and coordinate files
//	//Build Graph
//	char * graph_file ="s_graph_file";
//	char * coor_file ="s_coor_file";
//
//	GraphBuilder gbuild(graph_file,coor_file);
//	matrix graph= gbuild.getGraph();
//	printGraphMatrix(graph);
//
//	//Find a Path using Dijkstra
//	PathFinder * pfinder = new DijkstraFinder(gbuild);
//	pfinder->findPath(2,3);
//	printPath(pfinder->getPath());
//
//	//Execute Path : Draw graphically
//	PathExecuter * pExec = new GraphicalPathExecuter();
//	pExec->executePath(pfinder->getPath(),gbuild.getCoordinates());
//*/
//
///* Test 2 : Visibility Graph + Dijkstra path Finder
// * 	char * map_file ="building1.jpg";
//	VisibilityBuilder gbuild(map_file);
//	gbuild.readMap();
//	gbuild.buildGraph();
//
//	GraphicalPathExecuter * pExec = new GraphicalPathExecuter(gbuild.getMapMatrix());
//	pExec->drawVisibilityGraph(gbuild.edges_list, gbuild.corners_list);
//
//	PathFinder * pfinder = new DijkstraFinder(gbuild);
//	pfinder->findPath(2,20);
//	printPath(pfinder->getPath());
//
//	pExec->executePath(pfinder->getPath(),gbuild.getCoordinates());
//*/
///* Test 3 : Voronoi Graph + Dijkstra
//    char * map_file ="building1_450.jpg";
//	VoronoiBuilder gbuild(map_file);
//	gbuild.readMap();
//	gbuild.buildGraph();
//
//	GraphicalPathExecuter * pExec = new GraphicalPathExecuter(gbuild.getMapMatrix());
//	pExec->drawVoronoiGraph(gbuild.edges_list, gbuild.vertex_list);
//
//	PathFinder * pfinder = new DijkstraFinder(gbuild);
//	pfinder->findPath(870,3080);
//	printPath(pfinder->getPath());
//	pExec->executePath(pfinder->getPath(),gbuild.getCoordinates());
//	return 0;*/
//
///* Test 4: A* Algorithm with simple graph
//	//Build Graph
//	char * graph_file ="s_graph_file";
//	char * coor_file ="s_coor_file";
//
//	GraphBuilder gbuild(graph_file,coor_file);
//	matrix graph= gbuild.getGraph();
//	printGraphMatrix(graph);
//
//	//Find a Path using Dijkstra
//	PathFinder * pfinder = new AstartFinder(gbuild);
//	pfinder->findPath(2,3);
//	printPath(pfinder->getPath());
//
//	//Execute Path : Draw graphically
//	PathExecuter * pExec = new GraphicalPathExecuter();
//	pExec->executePath(pfinder->getPath(),gbuild.getCoordinates());
//	 */
//
///*
//	const clock_t begin_time = clock();
//	char * map_file ="building1.jpg";
//	VisibilityBuilder gbuild(map_file);
//	gbuild.readMap();
//	gbuild.buildGraph();
//
//
//	GraphicalPathExecuter * pExec = new GraphicalPathExecuter(gbuild.getMapMatrix());
//	//pExec->drawVoronoiGraph(gbuild.edges_list, gbuild.vertex_list);
//	pExec->drawVisibilityGraph(gbuild.edges_list, gbuild.corners_list);
//
//	PathFinder * pfinder = new AstartFinder(gbuild);
//	//pfinder->findPath(30,5956);
//	pfinder->findPath(10,54);
//	printPath(pfinder->getPath());
//	pExec->executePath(pfinder->getPath(),gbuild.getCoordinates());
//
//
//	 std::cout << "\nTime Taken:"<<float( clock () - begin_time ) /  CLOCKS_PER_SEC;
//
//*/
//	/*
//	 RRT planner("/home/youmna/ARL_Lab_researchwork/PathPlanner_v3.0/mapdata/campus1.jpg",10000000,30,0.5);
//
//	StatePoint start(30,227);
//	StatePoint goal(270,200);
//	cout<< "Done?" <<  planner.planPath(start,goal) <<endl;
//	GraphicalPathExecuter pExec(planner.grid.getMapMatrix());
//	pExec.executePath(planner.path);
//	*/
///*
// * ACO with Visibility
//	char * map_file ="building1.jpg";
//	VisibilityBuilder gbuild(map_file);
//	gbuild.readMap();
//	gbuild.buildGraph();
//
//	GraphicalPathExecuter * pExec = new GraphicalPathExecuter(gbuild.getMapMatrix());
//	pExec->drawVisibilityGraph(gbuild.edges_list, gbuild.corners_list);
//	//cv::waitKey( 0 );
//
//	PathFinder * pfinder = new ACOPlanner(gbuild);
//	pfinder->findPath(0,20);
//	printPath(pfinder->getPath());
//	pExec->executePath(pfinder->getPath(),gbuild.getCoordinates());
//*/
//
//	/*
//	 * ACO with Voronoi
//		char * map_file ="building1.jpg";
//		VoronoiBuilder gbuild(map_file);
//		gbuild.readMap();
//		gbuild.buildGraph();
//
//		GraphicalPathExecuter * pExec = new GraphicalPathExecuter(gbuild.getMapMatrix());
//		pExec->drawVoronoiGraph(gbuild.edges_list, gbuild.vertex_list);
//		//cv::waitKey( 0 );
//
//		PathFinder * pfinder = new ACOPlanner(gbuild);
//		pfinder->findPath(30,100);
//		printPath(pfinder->getPath());
//		pExec->executePath(pfinder->getPath(),gbuild.getCoordinates());
//*/
//
//	/*
//	 * ACO with Grid : Cell Decomposition
//		char * map_file ="map30.jpg";
//		GridGraphBuilder gbuild(map_file);
//		gbuild.readMap();
//		gbuild.buildGraph();
//
//		GraphicalPathExecuter * pExec = new GraphicalPathExecuter(gbuild.getMapMatrix());
//
//		PathFinder * pfinder = new ACOPlanner(gbuild);
//		pfinder->findPath(1,200);
//		printPath(pfinder->getPath());
//		pExec->executePath(pfinder->getPath(),gbuild.getCoordinates());
//
//*/
//	/*
//	 * A*  with Grid : Cell Decomposition
////#include "PathFinder.h"
//#include "AstarFinder.h"
//#include "PathExecuter.h"
//#include "VisibilityBuilder.h"
//#include "VoronoiBuilder.h"
//#include "GridGraphBuilder.h"
//#include "SAnnealingPlanner.h"
//#include "ACO_Planner.h"
//#include "PSOPlanner.h"
//#include "RRT.h"
//#include "LRMap.h"
//#include <iostream>
//using namespace std;
//
//void printGraphMatrix(matrix graph);
//void printPath(vector<unint32> path);
//
//int main(){
///* Test 1 : two simple graph and coordinate files
//	//Build Graph
//	char * graph_file ="s_graph_file";
//	char * coor_file ="s_coor_file";
//
//	GraphBuilder gbuild(graph_file,coor_file);
//	matrix graph= gbuild.getGraph();
//	printGraphMatrix(graph);
//
//	//Find a Path using Dijkstra
//	PathFinder * pfinder = new DijkstraFinder(gbuild);
//	pfinder->findPath(2,3);
//	printPath(pfinder->getPath());
//
//	//Execute Path : Draw graphically
//	PathExecuter * pExec = new GraphicalPathExecuter();
//	pExec->executePath(pfinder->getPath(),gbuild.getCoordinates());
//*/
//
///* Test 2 : Visibility Graph + Dijkstra path Finder
// * 	char * map_file ="building1.jpg";
//	VisibilityBuilder gbuild(map_file);
//	gbuild.readMap();
//	gbuild.buildGraph();
//
//	GraphicalPathExecuter * pExec = new GraphicalPathExecuter(gbuild.getMapMatrix());
//	pExec->drawVisibilityGraph(gbuild.edges_list, gbuild.corners_list);
//
//	PathFinder * pfinder = new DijkstraFinder(gbuild);
//	pfinder->findPath(2,20);
//	printPath(pfinder->getPath());
//
//	pExec->executePath(pfinder->getPath(),gbuild.getCoordinates());
//*/
///* Test 3 : Voronoi Graph + Dijkstra
//    char * map_file ="building1_450.jpg";
//	VoronoiBuilder gbuild(map_file);
//	gbuild.readMap();
//	gbuild.buildGraph();
//
//	GraphicalPathExecuter * pExec = new GraphicalPathExecuter(gbuild.getMapMatrix());
//	pExec->drawVoronoiGraph(gbuild.edges_list, gbuild.vertex_list);
//
//	PathFinder * pfinder = new DijkstraFinder(gbuild);
//	pfinder->findPath(870,3080);
//	printPath(pfinder->getPath());
//	pExec->executePath(pfinder->getPath(),gbuild.getCoordinates());
//	return 0;*/
//
///* Test 4: A* Algorithm with simple graph
//	//Build Graph
//	char * graph_file ="s_graph_file";
//	char * coor_file ="s_coor_file";
//
//	GraphBuilder gbuild(graph_file,coor_file);
//	matrix graph= gbuild.getGraph();
//	printGraphMatrix(graph);
//
//	//Find a Path using Dijkstra
//	PathFinder * pfinder = new AstartFinder(gbuild);
//	pfinder->findPath(2,3);
//	printPath(pfinder->getPath());
//
//	//Execute Path : Draw graphically
//	PathExecuter * pExec = new GraphicalPathExecuter();
//	pExec->executePath(pfinder->getPath(),gbuild.getCoordinates());
//	 */
//
///*
//	const clock_t begin_time = clock();
//	char * map_file ="building1.jpg";
//	VisibilityBuilder gbuild(map_file);
//	gbuild.readMap();
//	gbuild.buildGraph();
//
//
//	GraphicalPathExecuter * pExec = new GraphicalPathExecuter(gbuild.getMapMatrix());
//	//pExec->drawVoronoiGraph(gbuild.edges_list, gbuild.vertex_list);
//	pExec->drawVisibilityGraph(gbuild.edges_list, gbuild.corners_list);
//
//	PathFinder * pfinder = new AstartFinder(gbuild);
//	//pfinder->findPath(30,5956);
//	pfinder->findPath(10,54);
//	printPath(pfinder->getPath());
//	pExec->executePath(pfinder->getPath(),gbuild.getCoordinates());
//
//
//	 std::cout << "\nTime Taken:"<<float( clock () - begin_time ) /  CLOCKS_PER_SEC;
//
//*/
//	/*
//	 RRT planner("/home/youmna/ARL_Lab_researchwork/PathPlanner_v3.0/mapdata/campus1.jpg",10000000,30,0.5);
//
//	StatePoint start(30,227);
//	StatePoint goal(270,200);
//	cout<< "Done?" <<  planner.planPath(start,goal) <<endl;
//	GraphicalPathExecuter pExec(planner.grid.getMapMatrix());
//	pExec.executePath(planner.path);
//	*/
///*
// * ACO with Visibility
//	char * map_file ="building1.jpg";
//	VisibilityBuilder gbuild(map_file);
//	gbuild.readMap();
//	gbuild.buildGraph();
//
//	GraphicalPathExecuter * pExec = new GraphicalPathExecuter(gbuild.getMapMatrix());
//	pExec->drawVisibilityGraph(gbuild.edges_list, gbuild.corners_list);
//	//cv::waitKey( 0 );
//
//	PathFinder * pfinder = new ACOPlanner(gbuild);
//	pfinder->findPath(0,20);
//	printPath(pfinder->getPath());
//	pExec->executePath(pfinder->getPath(),gbuild.getCoordinates());
//*/
//
//	/*
//	 * ACO with Voronoi
//		char * map_file ="building1.jpg";
//		VoronoiBuilder gbuild(map_file);
//		gbuild.readMap();
//		gbuild.buildGraph();
//
//		GraphicalPathExecuter * pExec = new GraphicalPathExecuter(gbuild.getMapMatrix());
//		pExec->drawVoronoiGraph(gbuild.edges_list, gbuild.vertex_list);
//		//cv::waitKey( 0 );
//
//		PathFinder * pfinder = new ACOPlanner(gbuild);
//		pfinder->findPath(30,100);
//		printPath(pfinder->getPath());
//		pExec->executePath(pfinder->getPath(),gbuild.getCoordinates());
//*/
//
//	/*
//	 * ACO with Grid : Cell Decomposition
//		char * map_file ="map30.jpg";
//		GridGraphBuilder gbuild(map_file);
//		gbuild.readMap();
//		gbuild.buildGraph();
//
//		GraphicalPathExecuter * pExec = new GraphicalPathExecuter(gbuild.getMapMatrix());
//
//		PathFinder * pfinder = new ACOPlanner(gbuild);
//		pfinder->findPath(1,200);
//		printPath(pfinder->getPath());
//		pExec->executePath(pfinder->getPath(),gbuild.getCoordinates());
//
//*/
//	/*
//	 * A*  with Grid : Cell Decomposition
//
//	char * map_file ="map30.jpg";
//		GridGraphBuilder gbuild(map_file);
//		gbuild.readMap();
//		gbuild.buildGraph();
//
//		GraphicalPathExecuter * pExec = new GraphicalPathExecuter(gbuild.getMapMatrix());
//
//		PathFinder * pfinder = new DijkstraFinder(gbuild);
//		pfinder->findPath(1,200);
//		//printPath(pfinder->getPath());
//		pExec->executePath(pfinder->getPath(),gbuild.getCoordinates());
//
//	 */
//
//	/*
//	 * Simulated Annealing with Grid : Cell Decomposition
//		char * map_file ="map30.jpg";
//		GridGraphBuilder gbuild(map_file);
//		gbuild.readMap();
//		gbuild.buildGraph();
//
//		GraphicalPathExecuter * pExec = new GraphicalPathExecuter(gbuild.getMapMatrix());
//		PathFinder * pfinder = new SAnnealingPlanner(gbuild,2000,0.00001,100,6,0.9);
//		pfinder->findPath(1,200);
//
//		VrepExecuter * pvrepExec = new VrepExecuter(gbuild.getMapMatrix());
//		pvrepExec->executePath(pfinder->getPath(),gbuild.getCoordinates());
//		//printPath(pfinder->getPath());
//		pExec->executePath(pfinder->getPath(),gbuild.getCoordinates());
//*/
//	/*
//	 * PSO with Grid : Cell Decomposition
//		//char * map_file ="map30.jpg";
//		char * map_file ="campus_map_573x492.jpg";
//		GridGraphBuilder gbuild(map_file);
//		gbuild.readMap();
//		gbuild.buildGraph();
//
//		GraphicalPathExecuter * pExec = new GraphicalPathExecuter(gbuild.getMapMatrix());
//		//VrepExecuter * pvrepExec = new VrepExecuter(gbuild.getMapMatrix());
//
//		PathFinder * pfinder = new PSO_Planner(gbuild,100,1);
//		//PathFinder * pfinder = new AstartFinder(gbuild);
//		pfinder->findPath(90,53);
//		//printPath(pfinder->getPath());
//		//vector<>
//	//	pvrepExec->executePath(pfinder->getPath(),gbuild.getCoordinates());
//		pExec->executePath(pfinder->getPath(),gbuild.getCoordinates());
//*/
//
//
//	/*
//	 * Sub map creation
//		//char * map_file ="map30.jpg";
//		char * map_file ="campus_map_573x492.jpg";
//		LR_Map lrmap(map_file,10);
//		lrmap.writeSubMaps(); //convert big map image to sub images
//
//		GridGraphBuilder global_gbuild(lrmap.getLRMap());
//		global_gbuild.buildGraph();
//
//
//	    string submapfile = lrmap.getSubMap(200,300);
//	    cout << submapfile <<endl;
//		GridGraphBuilder local_gbuild(submapfile);
//		local_gbuild.readMap();
//		local_gbuild.buildGraph();
//
//
//		GraphicalPathExecuter * pExec = new GraphicalPathExecuter(lrmap.getOriginalMap());
//
//		PathFinder * pfinder = new PSO_Planner(global_gbuild,0,1);
//		pfinder->findPath(4,262);
//
//		pExec->executePath(pfinder->getPath(),global_gbuild.getCoordinates());*/
//	/**/
//
///*
//	char * map_file ="campus_map_573x492.jpg";
//	GridGraphBuilder gbuild(map_file);
//	gbuild.readMap();
//	gbuild.buildGraph();
//*/
////delete pExec;
////delete pfinder;
////delete pvrepExec;
//
//}
//
//
//
//void printGraphMatrix(matrix graph){
//	int nV = graph[0].size();
//	for(int i=0; i<nV; i++){
//		cout << i << " ";
//		for(int j=0; j<nV ; j++){
//			cout << graph[i][j] << " ";
//		}
//		cout << endl;
//	}
//}
//
//void printPath(vector<unint32> path){
//	cout << "Path: " ;
//	for(int i=0; i<path.size(); i++){
//		cout<< path[i] << "-->";
//	}
//cout << endl;
//}

//	char * map_file ="map30.jpg";
//		GridGraphBuilder gbuild(map_file);
//		gbuild.readMap();
//		gbuild.buildGraph();
//
//		GraphicalPathExecuter * pExec = new GraphicalPathExecuter(gbuild.getMapMatrix());
//
//		PathFinder * pfinder = new DijkstraFinder(gbuild);
//		pfinder->findPath(1,200);
//		//printPath(pfinder->getPath());
//		pExec->executePath(pfinder->getPath(),gbuild.getCoordinates());
//
//	 */
//
//	/*
//	 * Simulated Annealing with Grid : Cell Decomposition
//		char * map_file ="map30.jpg";
//		GridGraphBuilder gbuild(map_file);
//		gbuild.readMap();
//		gbuild.buildGraph();
//
//		GraphicalPathExecuter * pExec = new GraphicalPathExecuter(gbuild.getMapMatrix());
//		PathFinder * pfinder = new SAnnealingPlanner(gbuild,2000,0.00001,100,6,0.9);
//		pfinder->findPath(1,200);
//
//		VrepExecuter * pvrepExec = new VrepExecuter(gbuild.getMapMatrix());
//		pvrepExec->executePath(pfinder->getPath(),gbuild.getCoordinates());
//		//printPath(pfinder->getPath());
//		pExec->executePath(pfinder->getPath(),gbuild.getCoordinates());
//*/
//	/*
//	 * PSO with Grid : Cell Decomposition
//		//char * map_file ="map30.jpg";
//		char * map_file ="campus_map_573x492.jpg";
//		GridGraphBuilder gbuild(map_file);
//		gbuild.readMap();
//		gbuild.buildGraph();
//
//		GraphicalPathExecuter * pExec = new GraphicalPathExecuter(gbuild.getMapMatrix());
//		//VrepExecuter * pvrepExec = new VrepExecuter(gbuild.getMapMatrix());
//
//		PathFinder * pfinder = new PSO_Planner(gbuild,100,1);
//		//PathFinder * pfinder = new AstartFinder(gbuild);
//		pfinder->findPath(90,53);
//		//printPath(pfinder->getPath());
//		//vector<>
//	//	pvrepExec->executePath(pfinder->getPath(),gbuild.getCoordinates());
//		pExec->executePath(pfinder->getPath(),gbuild.getCoordinates());
//*/
//
//
//	/*
//	 * Sub map creation
//		//char * map_file ="map30.jpg";
//		char * map_file ="campus_map_573x492.jpg";
//		LR_Map lrmap(map_file,10);
//		lrmap.writeSubMaps(); //convert big map image to sub images
//
//		GridGraphBuilder global_gbuild(lrmap.getLRMap());
//		global_gbuild.buildGraph();
//
//
//	    string submapfile = lrmap.getSubMap(200,300);
//	    cout << submapfile <<endl;
//		GridGraphBuilder local_gbuild(submapfile);
//		local_gbuild.readMap();
//		local_gbuild.buildGraph();
//
//
//		GraphicalPathExecuter * pExec = new GraphicalPathExecuter(lrmap.getOriginalMap());
//
//		PathFinder * pfinder = new PSO_Planner(global_gbuild,0,1);
//		pfinder->findPath(4,262);
//
//		pExec->executePath(pfinder->getPath(),global_gbuild.getCoordinates());*/
//	/**/
//
///*
//	char * map_file ="campus_map_573x492.jpg";
//	GridGraphBuilder gbuild(map_file);
//	gbuild.readMap();
//	gbuild.buildGraph();
//*/
////delete pExec;
////delete pfinder;
////delete pvrepExec;
//
//}
//
//
//
//void printGraphMatrix(matrix graph){
//	int nV = graph[0].size();
//	for(int i=0; i<nV; i++){
//		cout << i << " ";
//		for(int j=0; j<nV ; j++){
//			cout << graph[i][j] << " ";
//		}
//		cout << endl;
//	}
//}
//
//void printPath(vector<unint32> path){
//	cout << "Path: " ;
//	for(int i=0; i<path.size(); i++){
//		cout<< path[i] << "-->";
//	}
//cout << endl;
//}
//lrmap.getSubMap(200,300);
//	    cout << submapfile <<endl;
//		GridGraphBuilder local_gbuild(submapfile);
//		local_gbuild.readMap();
//		local_gbuild.buildGraph();
//
//
//		GraphicalPathExecuter * pExec = new GraphicalPathExecuter(lrmap.getOriginalMap());
//
//		PathFinder * pfinder = new PSO_Planner(global_gbuild,0,1);
//		pfinder->findPath(4,262);
//
//		pExec->executePath(pfinder->getPath(),global_gbuild.getCoordinates());*/
//	/**/
//
///*
//	char * map_file ="campus_map_573x492.jpg";
//	GridGraphBuilder gbuild(map_file);
//	gbuild.readMap();
//	gbuild.buildGraph();
//*/
////delete pExec;
////delete pfinder;
////delete pvrepExec;
//
//}
//
//
//
//void printGraphMatrix(matrix graph){
//	int nV = graph[0].size();
//	for(int i=0; i<nV; i++){
//		cout << i << " ";
//		for(int j=0; j<nV ; j++){
//			cout << graph[i][j] << " ";
//		}
//		cout << endl;
//	}
//}
//
//void printPath(vector<unint32> path){
//	cout << "Path: " ;
//	for(int i=0; i<path.size(); i++){
//		cout<< path[i] << "-->";
//	}
//cout << endl;
//}

//
//void printGraphMatrix(matrix graph);
//void printPath(vector<unint32> path);
//
//int main(){
///* Test 1 : two simple graph and coordinate files
//	//Build Graph
//	char * graph_file ="s_graph_file";
//	char * coor_file ="s_coor_file";
//
//	GraphBuilder gbuild(graph_file,coor_file);
//	matrix graph= gbuild.getGraph();
//	printGraphMatrix(graph);
//
//	//Find a Path using Dijkstra
//	PathFinder * pfinder = new DijkstraFinder(gbuild);
//	pfinder->findPath(2,3);
//	printPath(pfinder->getPath());
//
//	//Execute Path : Draw graphically
//	PathExecuter * pExec = new GraphicalPathExecuter();
//	pExec->executePath(pfinder->getPath(),gbuild.getCoordinates());
//*/
//
///* Test 2 : Visibility Graph + Dijkstra path Finder
// * 	char * map_file ="building1.jpg";
//	VisibilityBuilder gbuild(map_file);
//	gbuild.readMap();
//	gbuild.buildGraph();
//
//	GraphicalPathExecuter * pExec = new GraphicalPathExecuter(gbuild.getMapMatrix());
//	pExec->drawVisibilityGraph(gbuild.edges_list, gbuild.corners_list);
//
//	PathFinder * pfinder = new DijkstraFinder(gbuild);
//	pfinder->findPath(2,20);
//	printPath(pfinder->getPath());
//
//	pExec->executePath(pfinder->getPath(),gbuild.getCoordinates());
//*/
///* Test 3 : Voronoi Graph + Dijkstra
//    char * map_file ="building1_450.jpg";
//	VoronoiBuilder gbuild(map_file);
//	gbuild.readMap();
//	gbuild.buildGraph();
//
//	GraphicalPathExecuter * pExec = new GraphicalPathExecuter(gbuild.getMapMatrix());
//	pExec->drawVoronoiGraph(gbuild.edges_list, gbuild.vertex_list);
//
//	PathFinder * pfinder = new DijkstraFinder(gbuild);
//	pfinder->findPath(870,3080);
//	printPath(pfinder->getPath());
//	pExec->executePath(pfinder->getPath(),gbuild.getCoordinates());
//	return 0;*/
//
///* Test 4: A* Algorithm with simple graph
//	//Build Graph
//	char * graph_file ="s_graph_file";
//	char * coor_file ="s_coor_file";
//
//	GraphBuilder gbuild(graph_file,coor_file);
//	matrix graph= gbuild.getGraph();
//	printGraphMatrix(graph);
//
//	//Find a Path using Dijkstra
//	PathFinder * pfinder = new AstartFinder(gbuild);
//	pfinder->findPath(2,3);
//	printPath(pfinder->getPath());
//
//	//Execute Path : Draw graphically
//	PathExecuter * pExec = new GraphicalPathExecuter();
//	pExec->executePath(pfinder->getPath(),gbuild.getCoordinates());
//	 */
//
///*
//	const clock_t begin_time = clock();
//	char * map_file ="building1.jpg";
//	VisibilityBuilder gbuild(map_file);
//	gbuild.readMap();
//	gbuild.buildGraph();
//
//
//	GraphicalPathExecuter * pExec = new GraphicalPathExecuter(gbuild.getMapMatrix());
//	//pExec->drawVoronoiGraph(gbuild.edges_list, gbuild.vertex_list);
//	pExec->drawVisibilityGraph(gbuild.edges_list, gbuild.corners_list);
//
//	PathFinder * pfinder = new AstartFinder(gbuild);
//	//pfinder->findPath(30,5956);
//	pfinder->findPath(10,54);
//	printPath(pfinder->getPath());
//	pExec->executePath(pfinder->getPath(),gbuild.getCoordinates());
//
//
//	 std::cout << "\nTime Taken:"<<float( clock () - begin_time ) /  CLOCKS_PER_SEC;
//
//*/
//	/*
//	 RRT planner("/home/youmna/ARL_Lab_researchwork/PathPlanner_v3.0/mapdata/campus1.jpg",10000000,30,0.5);
//
//	StatePoint start(30,227);
//	StatePoint goal(270,200);
//	cout<< "Done?" <<  planner.planPath(start,goal) <<endl;
//	GraphicalPathExecuter pExec(planner.grid.getMapMatrix());
//	pExec.executePath(planner.path);
//	*/
///*
// * ACO with Visibility
//	char * map_file ="building1.jpg";
//	VisibilityBuilder gbuild(map_file);
//	gbuild.readMap();
//	gbuild.buildGraph();
//
//	GraphicalPathExecuter * pExec = new GraphicalPathExecuter(gbuild.getMapMatrix());
//	pExec->drawVisibilityGraph(gbuild.edges_list, gbuild.corners_list);
//	//cv::waitKey( 0 );
//
//	PathFinder * pfinder = new ACOPlanner(gbuild);
//	pfinder->findPath(0,20);
//	printPath(pfinder->getPath());
//	pExec->executePath(pfinder->getPath(),gbuild.getCoordinates());
//*/
//
//	/*
//	 * ACO with Voronoi
//		char * map_file ="building1.jpg";
//		VoronoiBuilder gbuild(map_file);
//		gbuild.readMap();
//		gbuild.buildGraph();
//
//		GraphicalPathExecuter * pExec = new GraphicalPathExecuter(gbuild.getMapMatrix());
//		pExec->drawVoronoiGraph(gbuild.edges_list, gbuild.vertex_list);
//		//cv::waitKey( 0 );
//
//		PathFinder * pfinder = new ACOPlanner(gbuild);
//		pfinder->findPath(30,100);
//		printPath(pfinder->getPath());
//		pExec->executePath(pfinder->getPath(),gbuild.getCoordinates());
//*/
//
//	/*
//	 * ACO with Grid : Cell Decomposition
//		char * map_file ="map30.jpg";
//		GridGraphBuilder gbuild(map_file);
//		gbuild.readMap();
//		gbuild.buildGraph();
//
//		GraphicalPathExecuter * pExec = new GraphicalPathExecuter(gbuild.getMapMatrix());
//
//		PathFinder * pfinder = new ACOPlanner(gbuild);
//		pfinder->findPath(1,200);
//		printPath(pfinder->getPath());
//		pExec->executePath(pfinder->getPath(),gbuild.getCoordinates());
//
//*/
//	/*
//	 * A*  with Grid : Cell Decomposition
//
//	char * map_file ="map30.jpg";
//		GridGraphBuilder gbuild(map_file);
//		gbuild.readMap();
//		gbuild.buildGraph();
//
//		GraphicalPathExecuter * pExec = new GraphicalPathExecuter(gbuild.getMapMatrix());
//
//		PathFinder * pfinder = new DijkstraFinder(gbuild);
//		pfinder->findPath(1,200);
//		//printPath(pfinder->getPath());
//		pExec->executePath(pfinder->getPath(),gbuild.getCoordinates());
//
//	 */
//
//	/*
//	 * Simulated Annealing with Grid : Cell Decomposition
//		char * map_file ="map30.jpg";
//		GridGraphBuilder gbuild(map_file);
//		gbuild.readMap();
//		gbuild.buildGraph();
//
//		GraphicalPathExecuter * pExec = new GraphicalPathExecuter(gbuild.getMapMatrix());
//		PathFinder * pfinder = new SAnnealingPlanner(gbuild,2000,0.00001,100,6,0.9);
//		pfinder->findPath(1,200);
//
//		VrepExecuter * pvrepExec = new VrepExecuter(gbuild.getMapMatrix());
//		pvrepExec->executePath(pfinder->getPath(),gbuild.getCoordinates());
//		//printPath(pfinder->getPath());
//		pExec->executePath(pfinder->getPath(),gbuild.getCoordinates());
//*/
//	/*
//	 * PSO with Grid : Cell Decomposition
//		//char * map_file ="map30.jpg";
//		char * map_file ="campus_map_573x492.jpg";
//		GridGraphBuilder gbuild(map_file);
//		gbuild.readMap();
//		gbuild.buildGraph();
//
//		GraphicalPathExecuter * pExec = new GraphicalPathExecuter(gbuild.getMapMatrix());
//		//VrepExecuter * pvrepExec = new VrepExecuter(gbuild.getMapMatrix());
//
//		PathFinder * pfinder = new PSO_Planner(gbuild,100,1);
//		//PathFinder * pfinder = new AstartFinder(gbuild);
//		pfinder->findPath(90,53);
//		//printPath(pfinder->getPath());
//		//vector<>
//	//	pvrepExec->executePath(pfinder->getPath(),gbuild.getCoordinates());
//		pExec->executePath(pfinder->getPath(),gbuild.getCoordinates());
//*/
//
//
//	/*
//	 * Sub map creation
//		//char * map_file ="map30.jpg";
//		char * map_file ="campus_map_573x492.jpg";
//		LR_Map lrmap(map_file,10);
//		lrmap.writeSubMaps(); //convert big map image to sub images
//
//		GridGraphBuilder global_gbuild(lrmap.getLRMap());
//		global_gbuild.buildGraph();
//
//
//	    string submapfile = lrmap.getSubMap(200,300);
//	    cout << submapfile <<endl;
//		GridGraphBuilder local_gbuild(submapfile);
//		local_gbuild.readMap();
//		local_gbuild.buildGraph();
//
//
//		GraphicalPathExecuter * pExec = new GraphicalPathExecuter(lrmap.getOriginalMap());
//
//		PathFinder * pfinder = new PSO_Planner(global_gbuild,0,1);
//		pfinder->findPath(4,262);
//
//		pExec->executePath(pfinder->getPath(),global_gbuild.getCoordinates());*/
//	/**/
//
///*
//	char * map_file ="campus_map_573x492.jpg";
//	GridGraphBuilder gbuild(map_file);
//	gbuild.readMap();
//	gbuild.buildGraph();
//*/
////delete pExec;
////delete pfinder;
////delete pvrepExec;
//
//}
//
//
//
//void printGraphMatrix(matrix graph){
//	int nV = graph[0].size();
//	for(int i=0; i<nV; i++){
//		cout << i << " ";
//		for(int j=0; j<nV ; j++){
//			cout << graph[i][j] << " ";
//		}
//		cout << endl;
//	}
//}
//
//void printPath(vector<unint32> path){
//	cout << "Path: " ;
//	for(int i=0; i<path.size(); i++){
//		cout<< path[i] << "-->";
//	}
//cout << endl;
//}
