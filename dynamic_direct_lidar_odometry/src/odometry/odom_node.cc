// MIT License

// Copyright (c) 2022 Kenny J. Chen, Brett T. Lopez

// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include "odometry/odom.h"

void controlC(int sig)
{
  OdomNode::abort();
}

int main(int argc, char** argv)
{
  ros::init(argc, argv, "ddlo_odom_node");
  ros::NodeHandle nh("~");

  signal(SIGTERM, controlC);
  sleep(0.5);

  // timeout to attach debugger
  if (ros::param::has("sleep"))
    ros::Duration(10).sleep();

  OdomNode node;
  ros::AsyncSpinner spinner(0);
  spinner.start();
  node.start();

  ros::waitForShutdown();

  return 0;
}
