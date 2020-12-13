#include "ros/ros.h"
#include "tasksrv/test.h"

bool add(tasksrv::test::Request &req,
	 tasksrv::test::Response &res)
{
res.sum = req.a+req.b;
ROS_INFO("request: x = %ld, y = %ld",(long int)req.a,(long int)req.b);
ROS_INFO("sending back response: [%ld]",(long int)res.sum);
return true;
}

int main(int argc,char **argv)
{
 ros::init(argc,argv,"server");
 ros::NodeHandle n;

 ros::ServiceServer service = n.advertiseService("test",add);
 ROS_INFO("Ready");
 ros::spin();

 return 0;
}
