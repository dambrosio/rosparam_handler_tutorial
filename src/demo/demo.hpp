#pragma once

#include <dynamic_reconfigure/server.h>
#include <ros/ros.h>
/*
 *  Adding the action header before the demo parameters causes compiling error,
 *  if it is placed after the DemoParameters.h compiling succeeds
 */
#include <rosparam_handler_tutorial/TestAction.h>
#include "rosparam_handler_tutorial/DemoParameters.h"

namespace rosparam_handler_tutorial {

class Demo {
public:
    Demo(ros::NodeHandle, ros::NodeHandle);

private:
    DemoParameters params_;

    ros::Timer timer_;
    dynamic_reconfigure::Server<DemoConfig> reconfigSrv_; // Dynamic reconfiguration service

    void timerCallback(const ros::TimerEvent& event);
    void reconfigureRequest(DemoConfig&, uint32_t);
};

} // namespace rosparam_handler_tutorial
