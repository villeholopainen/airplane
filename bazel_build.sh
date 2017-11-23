#!/bin/bash
BAZEL_VC="C:\Program Files (x86)\Microsoft Visual Studio\2017\BuildTools"
echo $BAZEL_VC
echo build twitch
echo "`bazel build ///src:twitch --verbose_failures`"

#echo create query
#echo "`bazel query --nohost_deps --noimplicit_deps 'deps(//src:twitch)' --output graph > graph.txt`"
