#!/bin/bash

read -p "Enter a number: " NUM

if [ $NUM = 10 ]
then
  echo "Number is equal to 10"
fi

if [ $NUM -gt 10 ]
then
  echo "Number is greater than 10"
fi

if [ $NUM -lt 10 ]
then
  echo "Number is less than 10"
fi