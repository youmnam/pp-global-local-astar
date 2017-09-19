#include "StateSpace.h"


void StateSpace::readMap(string map_file)
{
	cv::Mat image;
	image = cv::imread(map_file, CV_LOAD_IMAGE_GRAYSCALE);   // Read the file
	if(! image.data )    // Check for invalid input
	{

	  cout <<  "Could not open or find the map image :" << map_file << std::endl ;
	}
	else
	{
		width = image.rows;
		height = image.cols;

		//Initialization of map matrix
		map_matrix.resize(image.rows);
		for(int i =0 ; i< image.rows ; i++)
		   map_matrix[i].resize(image.cols);

		//load image data in map_matrix and in the obstacles vector.
		for(int i=0 ; i<image.rows ; i++)
		{
		   for(int j=0 ; j<image.cols ; j++)
		   {
			   if((int)image.at<uchar>(i,j) < 230)
			   {
					map_matrix[i][j] = 1;
					C_obs.push_back(StatePoint(i,j));
			   }
			   else
			   {
					map_matrix[i][j] = 0;
			   }
			}
	   }
   }
}
