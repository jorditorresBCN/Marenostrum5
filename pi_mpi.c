
int main(int argc, char* argv[]) {
        int my_rank, comm_sz, n, local_n;
        double local_a, local_b;
        int source;
        double local_int, total_int;

        double a, b, h;

        MPI_Init(<parameters>);
        MPI_Comm_rank(<parameters>);
        MPI_Comm_size(<parameters>);

        n=400; /*number of trapezoids must be multiple of proc*/
        a=0;
        b=1;
        h = (b-a)/ (double)n;
        local_n = n/comm_sz;

        local_a = a + my_rank*local_n*h;
        local_b = local_a + local_n*h;
        local_int = TrapezoidalRule(local_a, local_b, h, local_n);


        if (my_rank != 0)
             MPI_Send(<parameters>);
        else {
            total_int = local_int;
            for (source = 1; source < comm_sz; source++) {
                  MPI_Recv(<parameters>);
                 total_int += local_int;
                 }
            }
        if (my_rank == 0) {
                printf("With n = %d trapezoids, ", n);
                printf("from %f to %f is  %.15e\n", a, b, total_int);
        }


        MPI_Finalize(<parameters>);
        return 0;
}
