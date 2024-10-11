#!/bin/bash
#SBATCH --account=
#SBATCH --partition=acc
##SBATCH --qos=acc_debug
#SBATCH --qos=acc_bsccs
#SBATCH --nodes=
#SBATCH --time=
#SBATCH --ntasks-per-node=4
#SBATCH --cpus-per-task=1
#SBATCH --gres=gpu:4
#SBATCH --exclusive
#SBATCH --gpu-bind=none
#SBATCH --err=
#SBATCH --out=
#SBATCH --job-name=


module purge
module load nvidia-hpc-sdk/23.11-cuda11.8


make clean
make default


mpirun -np 4 ./jacobi -niter 100000 -nx 16384 -ny 16384


