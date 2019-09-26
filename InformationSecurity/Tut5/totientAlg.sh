#!/bin/bash

# Usage ./totientAlg.sh n

n=$1
a=2
count=1

while [ $a -lt $n ]; do # for 2 to n-1
	if [[ $(./euclids.py $a $n | grep "GCD = 1" ) ]]; then 
		count=$(($count+1))
	fi
	a="$(($a+1))"
done

echo "Φ($n) = $count"
