/*************************************************
**
** scales.c
**
** Demonstration of function for generating a microtonal scale.
**
** Originally created: 11-4-2021
*/

#include <stdio.h>
#include <malloc.h>
#include <math.h>

/*************************************************
**
** Source: scales.c
** Function: generateScale
**
** Parameters:
**   referencePitch
**   numSteps
**
** Description: This is where the magin happens.
**		This function generates a microtonal scale
**		starting a referencePitch. It then walks up
**		the new scale creating the approrpriate frequency
**		for each step.
**					 __ (n-a)
**		Pn = Pa( \st/2 )
**				  \/
*/
float *generateScale( double referencePitch, int numSteps )
{
	double NthRoot, pitch;
	int i;

	/* Create a new and empty array that will contain the frequencies. */
	float *ret = malloc( numSteps * sizeof( float ) );

	/* This is the nth root that we only need to calculate once. */
	NthRoot = pow(2, (1.0 / numSteps));

	/* Walk through from start to end (this is inclusive of the octave equivalent). */
	for( i=0; i<=numSteps; i++ )
	{
		/* Calculate tne new pitch. */
		pitch = referencePitch * (pow(NthRoot, (double)i));

		/* Round it so we only have two decimal places. */
		pitch = round(pitch * 100) / 100;

		/* Store in the scale array. */
		ret[i] = (float)pitch;
	}

	return ret;
}

void main()
{
	/* These values can be obtained from a user interface (as is the demo app
	**		at http://microtonality.org) or obtained from commandline arguments,
	**		or simply hard coded as they are here. */
	double reference = 440.0;
	double steps = 15;

	/* Local counter variable. */
	int i;

	/* Call the function that will return the calculated frequencies. */
	float *freqs = generateScale(reference, steps);

	/* Do a simple display of the values. */
	for( i=0; i<steps; i++ )
	{
		/* Output to screen. */
		printf("%.2f\n", freqs[i]);
	}
	
	free( freqs );

}
