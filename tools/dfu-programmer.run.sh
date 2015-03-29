#!/bin/bash -x
# determine the dir where we reside
DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
# determine platform/arch
PLATFORM=`uname`
ARCH=`uname -m`
#PATH=$PATH:/usr/local/bin
DFU_COMMAND=dfu-programmer
if [[ $PLATFORM == "Darwin" ]]; then
  DFU_COMMAND="$DIR/dfu-programmer.osx"
elif [[ $PLATFORM == "Linux" ]]; then
  if [[ $ARCH == "x86_64" ]]; then
    DFU_COMMAND="$DIR/dfu-programmer.linux.x86_64"
  elif [[ $ARCH == "i386" ]]; then
    DFU_COMMAND="$DIR/dfu-programmer.linux.i386"
  fi
fi
"$DFU_COMMAND" $1 erase
"$DFU_COMMAND" $@
"$DFU_COMMAND" $1 reset
exit 0
