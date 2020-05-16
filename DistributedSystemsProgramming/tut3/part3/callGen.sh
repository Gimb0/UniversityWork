#!/bin/bash

# Execute box_client with increasing dimensions
# Present results in a clear way

# Usage
# ./callGen.sh [min Dimensions] [max Dimensions] [increment] [weight] 

count=$1
while [ $count -lt $2 ]
do
		echo "Dimensions: " $count ", mass: " $4
		./box_client 137.154.149.28 $count $count $count $4 | grep Has 
		count="$(($count+$3))"
		echo " "
done
