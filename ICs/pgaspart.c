/* program to create an initial Poisson distribution particles */
/* This is stripped down from the version in "initial" to make it
   easier to use for a non-cosmologist. */
/* This version produces gas to test SPH */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "tipsydefs.h"
#include <rpc/types.h>
#include <rpc/xdr.h>

int
main(argc, argv)
     int argc;
     char **argv;
{
  double mass;
  double xmin;
  double xmax;
  double eps;
  struct dump h;
  double deltax;
  int i;
  int seed;
  XDR xdrs;

  if(argc != 5) {
      fprintf(stderr, "Usage: pgaspartt ngas xmin xmax seed\n");
      return 1;
      }
  
  xmin = atof(argv[2]);
  xmax = atof(argv[3]);
  seed = atoi(argv[4]);

  srand(seed);
  
  h.nsph = atoi(argv[1]);
  h.ndark = 0;
  h.nbodies = h.nsph;
  h.nstar = 0;
  h.ndim = 3;
  h.time = 0.1;

  mass = 0.0007957747;
  eps = pow(h.nsph, -1.0/3.0)*(xmax - xmin)/20.0;
  
  xdrstdio_create(&xdrs, stdout, XDR_ENCODE);

  xdr_header(&xdrs, &h);

  deltax = (xmax - xmin);
  double len = cbrt(h.nsph);
/* 10x10x20 hydrostatic equilibrium test
  int zmin = -2;
  int zmax = 2;
  int deltaz = (zmax - zmin);
    for(double ix = 0; ix < 10; ix++){
        for(double iy = 0; iy < 10; iy++){
                for(double iz = 0; iz < 20; iz++){
                        struct gas_particle gp;
                        gp.mass = mass;

                        gp.pos[0] = xmin + (ix + 0.5)*deltax/10;
                        gp.pos[1] = xmin + iy*deltax/10;
                        gp.pos[2] = zmin + iz*deltaz/20;
                        gp.vel[0] = 0.0;
                        gp.vel[1] = 0.0;
                        gp.vel[2] = 0.0;
                        gp.hsmooth = eps;
                        gp.rho = 0.0;
                        gp.temp = 100.0;
                        gp.phi = 0.0;
                        xdr_gas(&xdrs, &gp);
                }
        }
  }
*/
/* Grid distribution
  for(double ix = 0; ix < len; ix++){
  	for(double iy = 0; iy < len; iy++){
		for(double iz = 0; iz < len; iz++){
			struct gas_particle gp;
			gp.mass = mass;

			gp.pos[0] = xmin + (ix + 0.5)*deltax/len;
			gp.pos[1] = xmin + iy*deltax/len;
			gp.pos[2] = xmin + iz*deltax/len;
			gp.vel[0] = 0.0;
          	 	gp.vel[1] = 0.0;
         		gp.vel[2] = 0.0;
          		gp.hsmooth = eps;
          		gp.rho = 0.0;
          		gp.temp = 100.0;
          		gp.phi = 0.0;
			xdr_gas(&xdrs, &gp);
		}
	} 
  }

*/

// Poisson distribution
 for(i = 0; i < h.nsph; i++)
	{
	  struct gas_particle gp;
	  gp.mass = mass;
	  gp.pos[0] = xmin + rand()/((double) RAND_MAX)*deltax;
	  gp.pos[1] = xmin + rand()/((double) RAND_MAX)*deltax;
	  gp.pos[2] = rand()/((double) RAND_MAX) - 0.5;

	  gp.vel[0] = 0.0;
	  gp.vel[1] = -1.5 * gp.pos[0]; // y-velocity proportional to shear = -1.5*omega*x, where omega = 1
	  gp.vel[2] = 0.0;
	  gp.hsmooth = eps;
	  gp.rho = 0.0;
	  gp.temp = 100.0;
	  gp.phi = 0.0;

	  xdr_gas(&xdrs, &gp);

	}
  xdr_destroy(&xdrs);
  return(0);
}
