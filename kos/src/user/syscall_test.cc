#include "syscalls.h"
#include <iostream>



//Part 2 deliverable procadd function
long procadd(long a, long b)
{
	return a + b;
}


//Pentium Time Stamp Counter
// method below was obtained from: 
// http://www.cs.wm.edu/~kearns/001lab.d/rdtsc.html
unsigned long long int rdtsc(void)
{
   unsigned long long int x;
   unsigned a, d;

   __asm__ volatile("rdtsc" : "=a" (a), "=d" (d));

   return ((unsigned long long)a) | (((unsigned long long)d) << 32);;
}



int main()
{
	//set variables
	long a = 5;
	long b = 6;
	long procSum = 0;
	long sysSum = 0;
	double cpu;

	long long  start;
	long long end;
	long long total = 0;
	
	
	//part 3 deliverable
	//procadd loop
	for(int i = 0; i<50000; i++)
	{	
        start = rdtsc();
		procSum = procadd(a, b);
		end = rdtsc();
		total += (end - start);
	}
	 
	 //TODO verify if the avg is avg calls/50k or (total time for the loop)/50K
	 long long avg = total/50000;
	
	
	
	
	std::cout << "procadd sum: " << procSum << "\n";
	std::cout << "procadd_cpu_cycles: " << avg << "\n";
	
	 //TODO verify if the avg is avg calls/50k or (total time for the loop)/50K
	start = rdtsc();
	for(int i = 0; i<50000; i++)
	{	
        start = rdtsc();
		sysSum = sysadd(a, b);
		end = rdtsc();
		total += (end - start);
	}	
	
	std::cout << "syscall_add sum: " << sysSum << "\n";
	std::cout << "syscall_add_cpu_cycles: " << total << std::endl;
	

	return(0);
}
