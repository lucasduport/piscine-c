#!/bin/sh

for arg in "$@"; do
  printf "$arg: "
  if [ -f "$arg" ]; then
    echo "file"
  elif [ -d "$arg" ]; then
    echo "directory"
  else
    echo "unknown"
  fi
done
