//////////////////////////////////////////////////
//
// scales.js
//
// Demonstration of function for generating a microtonal scale.
//
// Originally created: 11-4-2021
//

// Run with RunJS on windows or Node.js on Linux.

// These values can be obtained from a user interface (as is the demo app
//		at http://microtonality.org) or obtained from commandline arguments,
//		or simply hard coded as they are here.
var reference = 440.0;
var steps = 15;

// Call the function that will return the calculated frequencies.
var freqs = generateScale( reference, steps );

// Do a simple display of the values.
for( var i=0; i<freqs.length; i++ )
{
	// Output to screen.
	console.log( freqs[i] );
}

//////////////////////////////////////////////////
//
// Source: scales.js
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
function generateScale(referencePitch, numSteps)
{
	// Create a new and empty array that will contain the frequencies.
	var scale = [];
	
	// This is the nth root that we only need to calculate once.
	var NthRoot = Math.pow(2, (1.0/numSteps));
	
	// Walk through from start to end (this is inclusive of the octave equivalent).
	for (var i = 0; i <= numSteps; i++ )
	{
		// Calculate tne new pitch.
		var pitch = referencePitch * (Math.pow(NthRoot, i));
		
		// Round it so we only have two decimal places.
		pitch = Math.round(pitch * 100) / 100
		
		// Store in the scale array.
		scale[i] = pitch;
	}

	// Return the array.
	return scale;
}
