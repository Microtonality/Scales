##################################################
##
## scales.py
##
## Demonstration of function for generating a microtonal scale.
##
## Originally created: 11-4-2021
##

## These values can be obtained from a user interface (as is the demo app
##		at http://microtonality.org) or obtained from commandline arguments,
##		or simply hard coded as they are here.

##################################################
##
## Source: scales.py
## Function: generateScale
##
## Parameters:
##   referencePitch
##   numSteps
##
## Description: This is where the magin happens.
##		This function generates a microtonal scale
##		starting a referencePitch. It then walks up
##		the new scale creating the approrpriate frequency
##		for each step.
##					 __ (n-a)
##		Pn = Pa( \st/2 )
##				  \/
##
def generateScale( referencePitch, numSteps ):

	## Create a new and empty array that will contain the frequencies.
	ret = [];

	## This is the nth root that we only need to calculate once.
	NthRoot = pow(2, (1.0 / numSteps));

	## Walk through from start to end (this is inclusive of the octave equivalent).
	for i in range(numSteps+1):
		## Calculate tne new pitch.
		pitch = referencePitch * (pow(NthRoot, i));

		## Round it so we only have two decimal places.
		pitch = round(pitch * 100) / 100;

		## Store in the scale array.
		ret.append( pitch );

	return ret;

reference = 440.0
steps = 15

freqs = generateScale( reference, steps )

for value in freqs:
	print( value )
