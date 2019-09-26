#!/bin/bash

# Generate input for box_client.
# Try to figure out how changes in 
# dimensions and mass change shipping cost

# Usage ./costGen.sh [min dim & mass] [max dim and mass] [iteration]

# While first cmd line arg is less than the second cmd line arg
# Execure box_client and increment values passed to box_client
start=$1
while [ $start -lt $2 ]
do
	echo "Dimesnions and Mass: " $start
	./box_client 137.154.149.28 1 1 1 $start | grep Will
	start=$(($start+$3))
	echo " " # New Line 
done
