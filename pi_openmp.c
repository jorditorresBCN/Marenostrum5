#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

double f(double x){
return (4.0 / (1.0 + x*x));
}

void TrapezoidalRule(double a, double b, int n, 
                                   double* global_result_p) {
   double  h, x, my_result;
   double  local_a, local_b;
   int  i, local_n;
   int my_rank = omp_get_thread_num();
   int thread_count = omp_get_num_threads();

   h = (b-a)/n;
   local_n = n/thread_count;
   local_a = a + my_rank*local_n*h;
   local_b = local_a + local_n*h;
   my_result = (f(local_a) + f(local_b))/2.0;
   for (i = 1; i <= local_n-1; i++) {
     x = local_a + i*h;
     my_result += f(x);
   }
   my_result = my_result*h;


   *global_result_p += my_result;
}


int main(int argc, char* argv[]) {
   double  global_result = 0.0;
   double  a, b;
   int     n;
   int     thread_count;


   n=268435456;  /*16^7 */
   a=0;
   b=1;

   thread_count = strtol(argv[1], NULL, 10);


   TrapezoidalRule(a, b, n, &global_result);

   printf("OpenMP with %d threads and  n = %d trapezoids, ", 
             thread_count,n);
   printf("the integral from %f to %f is  %.15e\n", a, b, 
             global_result);
   return 0;
}
