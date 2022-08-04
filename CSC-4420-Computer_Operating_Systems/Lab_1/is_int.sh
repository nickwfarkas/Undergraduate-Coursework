#!/bin/bash

if [[ $1 =~ ^[+-]?[0-9]+$ ]] 
then
  echo "$1 is an integer"
else
  echo "$1 is not an integer"
fi
