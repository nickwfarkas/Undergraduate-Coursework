#!/bin/bash

for file in *.MP3 
do
    if [ -f "$file" ]
    then
        temp=$file
        mv -- "$file" "${file%.MP3}.mp3"
        echo "move $temp to ${file%.MP3}.mp3"
        i="$(($i + 1))"
    else
        echo "there are no *.MP3 files"
    fi
done