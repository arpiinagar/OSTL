#!/bin/bash
clear
echo "Enter the number"
read number
c=0
i=1

while [ $i -le $number ]
do
	x=`expr $number \% $i`
	((++i))
	if [ $x -eq 0 ]
		then ((c++))
fi
done
if [ $counter -eq 2 ]
then echo "Prime"
fi

exit 
