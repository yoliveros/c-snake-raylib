#!/bin/bash

# Project name
p_name='snake'

# Setup and build folders
out="out"
bin="bin"

# Release folders
out_dist="meson-dist"
dist="dist"

# 
meson setup $out

if [ ! -z $1 ] && [[ $1 == "prod" ]];then
  meson dist -C $out --allow-dirty

  mv $out/$out_dist $dist 
else
  if [ ! -d $bin ]; then
    mkdir $bin
  fi
  
  meson compile -C $out
  
  mv $out/$p_name $bin
fi

