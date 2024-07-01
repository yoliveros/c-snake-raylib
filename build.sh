#!/bin/bash

dir="out"

if [ ! -d $dir ]; then
  meson setup $dir
fi

meson compile -C $dir
