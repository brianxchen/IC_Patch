# IC_Patch


This is a collection of initial condition generation code and analysis scripts for testing the implementation of the Hill approximation in [ChaNGa](https://github.com/N-BodyShop/changa) and pkdgrav.

I've split this repo into a folder for IC scripts and a folder for analysis scripts. Some ICs call scripts from the analysis folder (or elsewhere), so make sure you edit the IC scripts to call from the correct path.

## IC script usage

### encounteric_3body.py
This generates an IC for a 3-body problem for pkdgrav, with one massive body in orbit around another massive body and a small test particle in an elliptical orbit encountering both massive bodies.

```bash
py encounter_3body.py
```

### pgaspart.c
This generates an IC for a grid distribution or a Poisson distribution of particles. Comment out the part of the code that you do not need and uncomment the part that you do.

To build:
```bash
make clean
make pgaspart
```

To run:

./pgaspart ngas xmin xmax seed > outputfile,

e.g.

```bash
./pgaspart 1000 -0.5 0.5 1 > gas.tbin
```

### analss.sh
Shell script that converts ss format ChaNGa outputs into human readable form. It calls bin2simple and totipnat, which are in Analysis/tipsytools.

To use:
```bash
sh analss.sh
```

### shear.py
Plots the human readable form outputted by analss.sh using matplotlib.