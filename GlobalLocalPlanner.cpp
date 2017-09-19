/*
 * GlobalLocalPlanner.cpp
 *
 *  Created on: Dec 23, 2016
 *      Author: youmna
 */

#include "GlobalLocalPlanner.h"
#include "PathExecuter.h"
#include "GridGraphBuilder.h"
#include "AstarFinder.h"


#define LOW_RES_M 50
extern std::vector<int>  static_selectedpoints;

double getDistance(intPair p1, intPair p2){
	return sqrt(pow(p1.first - p2.first,2) + pow(p1.second - p2.second,2));
}

int findLabel(vector<intPair> &coor, intPair &p){
	//cout << "to find:" <<p.first << "," << p.second <<endl;
	for(int i=0; i<coor.size() ; i++)
	{
		//cout << "coor: "<<coor[i].first << " , " << coor[i].second <<endl;
		if(coor[i].first == p.first && coor[i].second == p.second)
			return i;
	}
	return -1;
}

GlobalLocal_Planner:: GlobalLocal_Planner(string roadmap_graphfile, string roadmap_coorfile, string mapfile, short graphtype)
{
	map_file = "./mapdata/"+ mapfile;
	graph_file = "" + roadmap_graphfile;
	//cout << roadmap_graphfile <<endl;
	coor_file = "" + roadmap_coorfile;
	//if(graphtype == GRID_BASED_GRAPH)
		//localbuilder = new GridGraphBuilder(mapfile);
	s_space.readMap(map_file);
	height = s_space.getWidth();
	width = s_space.getHieght();
	orignalMap = s_space.getMapMatrix();
}

vector<floatPair> GlobalLocal_Planner::plan(float startx,float starty)
{
	intPair start;
	intPair goal;

	GraphBuilder roadmapbuilder (graph_file,coor_file);
	vector<intPair> roadmap_coor = roadmapbuilder.getCoordinates();
	matrix roadmapMat            = roadmapbuilder.getGraph();

	GraphicalPathExecuter gExc(orignalMap);
	VrepExecuter vExc(orignalMap);
	gExc.drawMapwithWayPoints(roadmap_coor);
    cout << "static :" << static_selectedpoints.size() <<endl;

	if(static_selectedpoints.size() == 2)
	{
		start = vExc.transformV2P(startx,starty);
		// swap because the image(map) rotated
		int temp= start.first;
		start.first = start.second;
		start.second = temp;

		goal.second   = static_selectedpoints[0];
		goal.first    = static_selectedpoints[1];

		cout << start.first  << "," << start.second << endl;
		//cout << goal.first  << "," << goal.second << endl;

		// 3.2 find closest waypoint to start and goal point previously selected.
		int  start_wp = FindClosestWaypoint(roadmap_coor,start) ;
		int  goal_wp  = FindClosestWaypoint(roadmap_coor,goal)  ;
		cout << roadmap_coor[start_wp].first<<"," << roadmap_coor[start_wp].second
		<<" -- "<< roadmap_coor[goal_wp].first<<"," << roadmap_coor[goal_wp].second <<endl;

		// 3.4 Find a path between start waypoint and goal waypoint
		AstartFinder astar(roadmapbuilder);
		astar.findPath(start_wp,goal_wp);
		//gExc.executePath(astar.getPath(),roadmap_coor); //display roadmap points ONLY.

		// 3.5 create a global path: list of coordinates
		//	   Append the selected points(Start,Goal) to the global path
		vector<intPair> globalpath;
		vector<floatPair> vrepglobalpath;

		cout << "Global Path(pixel domain):"<<endl;
		globalpath.push_back(start);
		vector<unint32> astarpath= astar.getPath();
		for(int i = astar.getPath().size()-1; i >=1  ; i--)
		{
			intPair point1= roadmap_coor[astarpath[i]];
			intPair point2= roadmap_coor[astarpath[i-1]];
			if(i == astar.getPath().size()-1 ) getLinePoints(globalpath,start,point1);
			cout<<" -- "<< point1.first<<"," << point1.second <<endl;
			cout<<" -- "<< point2.first<<"," << point2.second <<endl;

			globalpath.push_back(point1);

			//update the global path by a detailed pixels info that lies on a straight line between point1 and point2
			getLinePoints(globalpath,point1,point2);

			globalpath.push_back(point2);



		}
		getLinePoints(globalpath,roadmap_coor[astarpath[0]],goal);
		globalpath.push_back(goal);

		//convert globalpath from pixel domain to vrep doamin


		// display the global path as pixels
		gExc.executePath(globalpath);

		//clear selected point
		static_selectedpoints.clear();

		//return the vrepdomain global path
		for(int i=0;i<globalpath.size();i++)
		{
			floatPair  vpoint = vExc.transformP2V(globalpath[i].second,globalpath[i].first);
			vrepglobalpath.push_back(vpoint);

		}
		cout <<"Global path size = " << vrepglobalpath.size() <<endl;
		return vrepglobalpath;
	}
}

void GlobalLocal_Planner::getLinePoints(vector<intPair> &globalpath,intPair point1,intPair point2){

	int x0 = point1.first;
	int y0 = point1.second;
	int x1 = point2.first;
	int y1 = point2.second;

	int dx = x1-x0;
	int dy = y1-y0;
	int D = 2*dy - dx;
    int &y=y0; int c=0;

  //  if(y0<y1)
    	//y = y0;
    //else
    	//y = y1;

    if(x0<x1)
    {
		for(; x0< x1; x0++)
		{
			cout<< "line points:" << x0 <<"," <<y <<";" <<endl;
			globalpath.push_back(make_pair(x0,y));
			if (D > 0){
			   y = y + 1;
			   D = D - 2*dx;
			}
			D = D + 2*dy;
			//cin >> c;
		}
    }
    if(x0>x1)
    {
		for(;  x1< x0; x1++)
		{
			cout<< "line points:" << x1 <<"," <<y <<";" <<endl;
			globalpath.push_back(make_pair(x1,y));
			if (D < 0){
			   y = y + 1;
			   D = D - 2*dx;
			}
			D = D + 2*dy;
			//cin >> c;
		}
    } //x0 ==x1
    if(x0 == x1){
    	int i=0,j=0;
		if(y0>y1)
		{
			i=y1;
			j=y0;
		}
		else
		{
			i=y0;
			j=y1;
		}
		for(;i<j;i++)
		{		cout<< "line points:" << x0 <<"," <<i <<";" <<endl;

			globalpath.push_back(make_pair(x0,i));
		}

    }
	/*int i=0,j=0;
	if(x0 == x1) //horizontal line
	{
		if(y0>y1)
		{
			i=y1;
			j=y0;
		}
		else
		{
			i=y0;
			j=y1;
		}
		for(;i<j;i++)
			globalpath.push_back(make_pair(x0,i));
		return;
	}
	if(y0 == y1) //vertical line
	{
		if(x0>x1)
		{
			i=x1;
			j=x0;
		}
		else
		{
			i=x0;
			j=x1;
		}
		for(;i<j;i++)
			globalpath.push_back(make_pair(i,y0));
		return;
	}
	float slope = (y1-y0)/(x1-x0);
	if(x0 < x1)
	{
		i=x0;
		j=x1;
	}
	else
	{
		i=x1;
		j=x0;
	}
	for(;i<j;i++)
	{
		int ny= slope*(i-x0)+y0;
		globalpath.push_back(make_pair(i,ny));
	}
*/
}

vector<floatPair> GlobalLocal_Planner::planlocal(float startx,float starty,float endx,float endy,float obs_dist,float robo_heading){

	GraphicalPathExecuter gExc(orignalMap);
	VrepExecuter vExc(orignalMap);
	vector<intPair> completepath;
	vector<intPair> local_coor;
	//1. input points is vrep_points : transformation required
	intPair p1 = vExc.transformV2P(startx,starty);
	intPair p2 = vExc.transformV2P(endx,endy);

	int temp= p1.first;
	p1.first = p1.second;
	p1.second = temp;

	temp= p2.first;
	p2.first = p2.second;
	p2.second = temp;

	/*handling obstacle*/
	float xobs = startx + (cos(robo_heading*3.14/180)*obs_dist);
	float yobs = starty + (sin(robo_heading*3.14/180)*obs_dist);

	intPair obs = vExc.transformV2P(xobs,yobs);

	temp= obs.first;
	obs.first = obs.second;
	obs.second = temp;

	orignalMap[obs.first][obs.second] = 1;


	//2. create local path betweem two points
	// 2.1 if the distance is so small, no fine details could be found -- terminate

	if(getDistance(p1,p2) <1)
	{
		cout << "distance is less than 1: " << getDistance(p1,p2) <<" no local path could be found";
		completepath.push_back(p1);
		completepath.push_back(p2);
		vector<floatPair> vreppath;
			for(int j=0; j<completepath.size(); j++)
			{
				 vreppath.push_back(vExc.transformP2V(completepath[j].second, completepath[j].first));
			}
			return vreppath;
		//return completepath;
	}

	//2.2 create submap between two points and get the gridbased graph of the submap
	cout <<"creating submap between "<< p1.first << "," << p1.second << " *** " << p2.first <<"," << p2.second <<endl;
	intPair np1,np2;
	int sx,sy;
	GridGraphBuilder local_builder(createSubMap(p1,p2,np1,np2,sx,sy));
	local_builder.buildGraph();
	local_coor = local_builder.getCoordinates();

	//2.3 find path between the two points using submap
	int p1_label = findLabel(local_coor,np1);
	int p2_label = findLabel(local_coor,np2);
	cout << p1_label << " ^^  " << p2_label << endl;

	AstartFinder astar2(local_builder);
	astar2.findPath(p1_label,p2_label);
	//gExc.executePath(astar2.getPath(),local_coor);
	cout << "local path:" <<endl;
	for(int j=astar2.getPath().size()-1; j>=0; j--)
	{
			int newx = local_coor[astar2.getPath()[j]].second + sx;
			int newy = local_coor[astar2.getPath()[j]].first + sy;
			completepath.push_back(make_pair(newx,newy));
			//cout << astar2.getPath()[j] << endl;
			cout << j << " -> "<< newx <<" -- " << newy <<endl;
	}
	gExc.executePath(completepath);
	//3. smooth the resulted path if possible
/*	for(int j=1; j<completepath.size()-1; j++)
	{
					cout << completepath[j].first <<" -- " << completepath[j].second <<endl;
					char afters=0,afterf=0;
					int nj = j+1;
					while(completepath[j-1].first == completepath[nj].first+1 && nj < completepath.size())
					{
						nj++;
						if(completepath[j-1].first == completepath[nj].first)
						{
							afterf = 1;
						}
					}
					while(completepath[j-1].first == completepath[nj].first-1 && nj < completepath.size())
					{
						nj++;
						if(completepath[j-1].first == completepath[nj].first)
						{
							afterf = 1;
						}
					}

					if(!afterf) nj = j+1;

					while( completepath[j-1].second == completepath[nj].second+1 &&  nj < completepath.size())
					{
						nj++;
						if(completepath[j-1].second == completepath[nj].second)
						{
							afters = 1;
						}
					}
					while(completepath[j-1].second == completepath[nj].second-1 &&  nj < completepath.size())
					{
					   nj++;
					   if(completepath[j-1].second == completepath[nj].second)
					   {
						 afters = 1;
					   }
					}
					if(afterf)
					{
						for(int kj = j-1; kj<=nj ; kj++)
						{
							completepath[kj].first = completepath[j-1].first;
						}
						j = nj+1;
					}
					if(afters)

					{
						for(int kj = j-1; kj<=nj ; kj++)
						{
					  	 completepath[kj].second = completepath[j-1].second;
						}
						j = nj+1;
					}
				}
				//cout << "astar done" <<endl;
				gExc.executePath(completepath);
				//vExc.executePath(completepath);
*/
		//transform to vrep
		vector<floatPair> vreppath;
		for(int j=1; j<completepath.size(); j++)
		{
			 vreppath.push_back(vExc.transformP2V(completepath[j].second, completepath[j].first));
		}
		return vreppath;

}
int GlobalLocal_Planner::FindClosestWaypoint(vector<intPair> &waypoints, intPair point)
{
	double mindis =  9999999;
	int minwayp = -1;
	for(int i = 0; i<waypoints.size(); i++){
		//cout <<" waypoint:"<< waypoints[i].first <<"," << waypoints[i].second <<endl;
		if(  getDistance(waypoints[i],point) < mindis ){
			mindis = getDistance(waypoints[i],point);
			minwayp = i;
		}
	}
	return minwayp;
}



bmatrix GlobalLocal_Planner::createSubMap(intPair p1,intPair p2, intPair &np1,intPair &np2,int &sx1,int &sy1)
{
	int sx,sy,ex,ey;
    if((p1.second <   p2.second))
    {
    	sy = p1.second;
    	ey = p2.second;
    }else{
    	sy = p2.second;
    	ey = p1.second;
    }
    if((p1.first <   p2.first))
    {
    	sx = p1.first;
    	ex = p2.first;
    }else{
    	sx = p2.first;
    	ex = p1.first;
    }

    //local_coor.clear();

    int wz =10;
    int wzx = wz;
    int wzy = wz;

    while ( sx - wzx < 0){
    	wzx--;
    }

    while ( sy - wzy < 0){
    	wzy--;
    }
    sx1 = sx - wzx;
    sy1 = sy - wzy;

    int resW = ex-sx +1 + (2*wz);
    int resH = ey-sy +1 + (2*wz) ;
	bmatrix mat;
	mat.resize(resH); //number of rows
	for(int i=0 ; i<mat.size() ; i++)
		mat[i].resize(resW,1); //number of columns

	cv::Mat submap_imag= cv::Mat::eye(resH, resW, CV_8UC1); // eye(rows, cols)
    cout << resH << "  " << mat[1].size() <<" ex+wz=" << ex+wz <<endl; ;
    for(int i = sx-wzx, k =0; i<= ex+wzx; i++,k++)
    {
    	for(int j = sy-wzy, l =0; j<= ey+wzy; j++,l++)
    	{

    	   cout << "create submap i,j:" <<i <<"," <<j<<" val:" << orignalMap[i][j] <<endl;
    	  // cout << "create submap k,l:" <<k <<"," <<l<<" val:" << endl;//mat[k][l] <<endl;//<< orignalMap[i][j] <<endl;
    	   mat[l][k] = orignalMap[i][j];



    	   if(i == p1.first && j ==p1.second ) {np1.first = l; np1.second = k;}
    	   if(i == p2.first && j ==p2.second ) {np2.first = l; np2.second = k;}

    	   if (orignalMap[i][j] == 0)
 		   {
 		   		submap_imag.at<uchar>(l,k) = 255; //white
 		   }else{
 		   		submap_imag.at<uchar>(l,k) = 0; //black
 		   	}
    	}
	}
cout <<"done creating submap..." <<endl;
    vector<int> compression_params;
    compression_params.push_back(CV_IMWRITE_JPEG_QUALITY);
    compression_params.push_back(95);

   	try {
   	  	 cv::imwrite("submap_test.jpg", submap_imag, compression_params);
   	}catch (runtime_error& ex) {
   	  	 fprintf(stderr, "Exception converting image to JPGE format: %s\n", ex.what());
   	 }


	return mat;
}

