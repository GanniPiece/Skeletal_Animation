#!/bin/sh
set -e
if test "$CONFIGURATION" = "Debug"; then :
  cd /Users/popo/Desktop/phd-fall2021/openGL/Hw3/skeletal_animation/build-xcode
  make -f /Users/popo/Desktop/phd-fall2021/openGL/Hw3/skeletal_animation/build-xcode/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "Release"; then :
  cd /Users/popo/Desktop/phd-fall2021/openGL/Hw3/skeletal_animation/build-xcode
  make -f /Users/popo/Desktop/phd-fall2021/openGL/Hw3/skeletal_animation/build-xcode/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "MinSizeRel"; then :
  cd /Users/popo/Desktop/phd-fall2021/openGL/Hw3/skeletal_animation/build-xcode
  make -f /Users/popo/Desktop/phd-fall2021/openGL/Hw3/skeletal_animation/build-xcode/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "RelWithDebInfo"; then :
  cd /Users/popo/Desktop/phd-fall2021/openGL/Hw3/skeletal_animation/build-xcode
  make -f /Users/popo/Desktop/phd-fall2021/openGL/Hw3/skeletal_animation/build-xcode/CMakeScripts/ReRunCMake.make
fi

