#!/bin/bash
#####################################################
# Exercise:                                         #
# * Prepare the jobscript for appropriate execution #
# * Check the script's content Fill in the "<  >"   #
# * Submit, examine and compare results             #
#####################################################

#SBATCH -t <indicate the time> 
#SBATCH --account <indicate the Unixgroup/Account>
#SBATCH --qos <indicate the Queue>

module purge
module load intel
./compilation-icx.sh
