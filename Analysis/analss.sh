#!/bin/sh
#
# convert ss files of single particle orbit into something with which we can
# plot an orbit
#
# Convert to "boxtree" format.
for i in ss.?????? ; do	
	/jet/home/bxchen/tipsy_tools/totipnat < $i | /jet/home/bxchen/tipsy_tools/bin2simple > $i.simple
done
/jet/home/bxchen/tipsy_tools/totipnat < gas.tbin | /jet/home/bxchen/tipsy_tools/bin2simple > gas.simple
# Concatenate into a single file for plotting
#
echo "# i org_idx mass radius X Y Z vX vY vZ spinX spinY spinZ color" > bt.out
rm bt.txt
for i in ss.??????.Metalsdot ; do
   cat $i | tail -1 >> bt.txt
done
