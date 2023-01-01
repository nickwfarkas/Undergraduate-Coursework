#!/bin/bash

read -p "Enter a number: " NUM

while [ $NUM -gt 0 ] 
do
  echo $NUM
  NUM="$(($NUM - 1))"
done