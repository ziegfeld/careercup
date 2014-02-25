//Assume that you have a CPU with 4 (r1, r2, r3, r4) registers, which supports the following operations
//zero(r) -- resets register value to zero
//inc(r) - increments register value by one
//loop(r) { /* loop body */ } repeats everything in the loop body x times where x is the value in the register r. 
//The number of iterations does not change if x changes inside the loop body.
//All the registers are integer numbers, not less than zero, and less than infinity. 
//No operations, except from described above. One can not create additional registers or variables.
//
//In this language, implement a function "r1 = r4 - 1" (assuming that r4 > 0)

zero(r2);
loop(r4)
{
	zero(r1);
	loop(r2)
	{
		inc(r1);
	}

	inc(r2);
}