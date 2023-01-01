#!/bin/bash
sum=0
arr=("$@")

array_sum(){
    for i in "${arr[@]}"
    do
        sum="$(($sum + $i))"
        printf " $sum"
    done

    printf "\n\tfinal sum: $sum\n"
}

array_sum