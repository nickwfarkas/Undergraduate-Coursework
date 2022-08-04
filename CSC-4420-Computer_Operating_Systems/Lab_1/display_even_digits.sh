#!/bin/bash

read -p "Enter a number: " NUM

i=1

while [ $i -le $NUM ] 
do
  if [ $(expr $i % 2) = 0 ]
  then
    echo $i
  fi
  i="$(($i + 1))"
done