// Copyright 2006-2016 Coppelia Robotics GmbH. All rights reserved.
// marc@coppeliarobotics.com
// www.coppeliarobotics.com
//
// -------------------------------------------------------------------
// THIS FILE IS DISTRIBUTED "AS IS", WITHOUT ANY EXPRESS OR IMPLIED
// WARRANTY. THE USER WILL USE IT AT HIS/HER OWN RISK. THE ORIGINAL
// AUTHORS AND COPPELIA ROBOTICS GMBH WILL NOT BE LIABLE FOR DATA LOSS,
// DAMAGES, LOSS OF PROFITS OR ANY OTHER KIND OF LOSS WHILE USING OR
// MISUSING THIS SOFTWARE.
//
// You are free to use/modify/distribute this file for whatever purpose!
// -------------------------------------------------------------------
//
// This file was automatically created for V-REP release V3.3.2 on August 29th 2016

#include <stdio.h>
#include "socketInConnection.h"
#include "GlobalLocalPlanner.h"
#include <cstdlib>
#define pi 3.141593f

int main(int argc, char* argv[])
{ // We connect to the port number passed as argument
    int portNb=0;
    if (argv[1]!=NULL)
        portNb=atoi(argv[1]);
    if (portNb==0)
    {
        printf("Indicate the connection port number as argument!\n");
        #ifdef _WIN32
            Sleep(5000);
        #else
            usleep(5000*1000);
        #endif
        return 0;
    }

    CSocketInConnection connection(portNb);
    printf("Connecting to client...\n");
    if (connection.connectToClient())
    {
    	printf("Connected with client.\n");

    	GlobalLocal_Planner planner("roadmaprealcost.graph","roadmap.coor","campus_map_573x492_uppermodi.jpg",0);

        float driveBackStartTime=-99.0f;
        float motorSpeeds[2];
        float * onedpath;
        int sz=0;
        while (true)
        { // This is the server loop (the robot's control loop):
            int receivedDataLength;
            char* receivedData=connection.receiveData(receivedDataLength);
            if (receivedData!=NULL)
            { // We received data. The server ALWAYS replies!
                // We received 2 floats (the sensorDistance and the simulation time):
               // float sensorReading=((float*)receivedData)[0];
               // float simulationTime=((float*)receivedData)[1];
                float xcurrent=((float*)receivedData)[0];
                float ycurrent=((float*)receivedData)[1];
                float xgoal=((float*)receivedData)[2];
                float ygoal=((float*)receivedData)[3];
                float obs_dist=((float*)receivedData)[4];
                float rheading=((float*)receivedData)[5];
                //cout << "obstacle position:"<<xobs << "," << yobs <<endl;
                delete[] receivedData;
                vector<floatPair> path;
                //cout << "Sensor Reading="<<sensorReading <<endl;
                if(xgoal == 99 && ygoal == 99)
                {
                    path=planner.plan(xcurrent,ycurrent);
                    sz=path.size()*2;

                }else{
                	path=planner.planlocal(xcurrent,ycurrent,xgoal,ygoal,obs_dist,rheading);
                	sz=path.size()*2;

                }
            	printf("preparing data to be sent.\n");
                /*onedpath = new float[sz];
                int j=0;
                for(int i =0 ;i<sz; i+=2)
                {
                	onedpath[i]= path[j].first;
                	onedpath[i+1]= path[j].second;
                	cout << onedpath[i] <<"," << onedpath[i+1] <<endl;
                	j++;
                }*/
            	fstream myfile;
				myfile.open("/home/youmna/ARL_Lab_researchwork/path2vrep.coor",std::fstream::out);
				if (!myfile.is_open()) cout<< "Can't open path2vrep.coor file!" <<endl;
				myfile << path.size() <<endl;
				for(int i =0 ;i<path.size(); i++)
				{
					myfile << path[i].first <<" " << path[i].second <<endl;

				}
				myfile.close();
                /*
                // We have a very simple control: when we detected something, we simply drive back while slightly turning for 3 seconds
                // If we didn't detect anything, we drive forward:
                if (simulationTime-driveBackStartTime<3.0f)
                { // driving backwards while slightly turning:
                    motorSpeeds[0]=-pi*0.5f;
                    motorSpeeds[1]=-pi*0.25f;
                }
                else
                { // going forward:
                    motorSpeeds[0]=pi;
                    motorSpeeds[1]=pi;
                    if (sensorReading>0.0f)
                        driveBackStartTime=simulationTime; // We detected something, and start the backward mode
                }*/

                printf("sending path.\n");
                int* pathsize =new int;
                *pathsize = path.size();
                // We reply with 2 floats (the left and right motor speed in rad/sec)
                if (!connection.replyToReceivedData((char*)pathsize,sizeof(int)))
                {
                    printf("Failed to send reply.\n");
                    break;
                }
                //delete onedpath;
                printf("path is sent.\n");

            }
            else
                break; // error
        }
    }
    else
        printf("Failed to connect to client.\n");
    #ifdef _WIN32
        Sleep(5000);
    #else
        usleep(5000*1000);
    #endif
    return 0;
}

