#!/bin/bash
#Name: Orlan Oconer
#EID: ojo366
#TACC username: orlan 



g++ hw5.cpp -o fizzbuzz

#Getting an input
echo "I need a positive integer:"
read input 

#1 Checking if it exists
if [ -z "$input" ]; then
    echo "Error: No input exist!?!?!?!!"
    exit 1
fi


# 2. Help menu beep boop 
if [ "$input" == "-h" ]; then
    echo "Usage: yourscript nnn"
    echo "where nnn is a positive integer"
    exit 0
fi

#Checking if it is a positive 
if ! [[ "$input" =~ ^[0-9]+$ ]]; then
    echo "Error: Input is not positive bruhh."
    exit 1
fi

if [ "$input" -le 0 ]; then
    echo "Error: Input NEEDS TO BE greater than 0."
    exit 1
fi


#checking if the file compiled properly, everything is working well now  
if [ $? -eq 0 ]; then
    echo "Compilation was good bro, noice. Now runnign magically numbers..."
    #run the executable
    ./fizzbuzz "$input"
else
    echo "it failed and I dont know why?!?"
    exit 1 
fi 
