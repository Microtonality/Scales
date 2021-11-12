//////////////////////////////////////////////////
//
// scales.cs
//
// Demonstration of function for generating a microtonal scale.
//
// Originally created: 11-4-2021
//
using System;

class Program
{
	// These values can be obtained from a user interface (as is the demo app
	//		at http://microtonality.org) or obtained from commandline arguments,
	//		or simply hard coded as they are here.
	static double reference = 440.0;
	static int steps = 15;

	static void Main(string[] args)
	{
		// Call the function that will return the calculated frequencies.
		float[] freqs = generateScale(reference, steps);

		// Do a simple display of the values.
		foreach( float f in freqs )
		{
			// Output to screen.
			Console.WriteLine(f.ToString("0.00"));
		}
	}

	//////////////////////////////////////////////////
	//
	// Source: scales.cs
	// Function: generateScale
	//
	// Parameters:
	//   referencePitch
	//   numSteps
	//
	// Description: This is where the magin happens.
	//		This function generates a microtonal scale
	//		starting a referencePitch. It then walks up
	//		the new scale creating the approrpriate frequency
	//		for each step.
	//					 __ (n-a)
	//		Pn = Pa( \st/2 )
	//				  \/
	//
	static float[] generateScale(double referencePitch, int numSteps)
	{
		// Create a new and empty array that will contain the frequencies.
		float[] ret = new float[numSteps + 1];

		// This is the nth root that we only need to calculate once.
		double NthRoot = Math.Pow(2, (1.0 / numSteps));

		// Walk through from start to end (this is inclusive of the octave equivalent).
		for (int i = 0; i <= numSteps; i++)
		{
			// Calculate tne new pitch.
			double pitch = referencePitch * (Math.Pow(NthRoot, (double)i));

			// Round it so we only have two decimal places.
			pitch = Math.Round(pitch * 100) / 100;

			// Store in the scale array.
			ret[i] = (float)pitch;
		}

		// Return the array.
		return ret;
	}

}
