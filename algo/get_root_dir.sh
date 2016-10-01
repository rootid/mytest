#!/bin/sh

ROOT_DIR=`git rev-parse --show-toplevel`

if [ ${?} -eq 0 ]
then
  GTEST_DIR=$ROOT_DIR/gtest
  ALGO_DIR=$ROOT_DIR/algo
  SRC_DIR=$ROOT_DIR/src
  echo ${GTEST_DIR}
  exit 0
fi

exit 1
