#!/usr/bin/python

from math import *
import os

# Parameters
x =  0         # x-peri
y =  -0.05419        # y-peri
vx = 0.101            # vx_peri
vy = 0.02        # vy_peri
m_massive = 1e-8   # massive particle mass
m_small = 1e-8     # small particle mass
r = 0.0015         # radius

# dummy, iord, mass, radius, x, y, z, vx, vy, vz, wx, wy, wz, color
btfile = open('ssic.bt', 'w')
btfile.write('%d %d %g %g %g %g %g %g %g %g %g %g %g %d\n' % (0,0, m_small, r, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0))
btfile.write('%d %d %g %g %g %g %g %g %g %g %g %g %g %d\n' % (1,1, m_small, r, x, y, 0.0, vx, vy, 0.0, 0.0, 0.0, 0.0, 0))
btfile.close()

# The below converts the .bt file that this generates into a .ss file that is readable by pkdgrav.
# Make sure to rewrite the below line to be the absolute path to the bt2ss script, which has been included in this repo.
os.system('/jet/home/bxchen/ss_core/src/ss/Linux-x86_64/bt2ss ssic.bt')
