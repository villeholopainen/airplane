#!/bin/bash

cd Simple-OpenGL-Image-Library;
if [ ! -d soil_build ]; then
    mkdir soil_build;
fi
cd soil_build;
cmake -G "Visual Studio 14" ../;
cmake --build . --target ALL_BUILD --config Release;
cmake --build . --target ALL_BUILD --config Debug;
cd ../..;

cd glfw;
if [ ! -d glfw_build ]; then
mkdir glfw_build;
fi
cd glfw_build;
cmake -G "Visual Studio 14" ../;
cmake --build . --target ALL_BUILD --config Release;
cmake --build . --target ALL_BUILD --config Debug;
cd ../..

BAZEL_VC="C:\Program Files (x86)\Microsoft Visual Studio\2017\BuildTools"
echo $BAZEL_VC
echo build twitch
echo "`bazel build ///src:twitch --verbose_failures`"

#echo create query
#echo "`bazel query --nohost_deps --noimplicit_deps 'deps(//src:twitch)' --output graph > graph.txt`"
