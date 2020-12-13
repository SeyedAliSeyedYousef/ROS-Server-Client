#include "ros/ros.h"
#include "tasksrv/test.h"
#include <cstdlib>

int main(int argc,char **argv)
{
 ros::init(argc,argv,"client");
 if(argc != 3)
 {
  ROS_INFO("usage:client X Y");
  return 1;
 }

 ros::NodeHandle n;
 ros::ServiceClient client = n.serviceClient<tasksrv::test>("test");
 tasksrv::test srv;
 srv.request.a = atoll(argv[1]);
 srv.request.b = atoll(argv[2]);
 if (client.call(srv))
 {
  ROS_INFO("Sum: %ld", (long int)srv.response.sum);
 }
 else
 {
  ROS_ERROR("Failed to call service tasksrv");
 }
 return 0;
}
