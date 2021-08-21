# Change the N here to make a new size dataset.
N=1000

pgaspart: pgaspart.c tipsydefs.h
	$(CC) -o pgaspart -I/usr/include/tirpc pgaspart.c -lm -ltirpc

clean:
	-rm -rf pgaspart testdata
