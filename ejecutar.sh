
#! /bin/bash

for j in {1..5}
do
	for i in 50 100 200 400 800 1600 3200 4000
	do
		./secuencial $i
	done
done
