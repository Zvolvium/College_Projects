#!/usr/bin/env bash 
#-----------------------------------
# slurm.sh
#
# Submit: 
#   sbatch slurm.sh
#
# Check status:
#   squeue | grep [userid]
#   squeue -u [userid]
#   squeue -j [jobid]
#-----------------------------------

#SBATCH --job-name=hw4_1
#SBATCH --partition=talon

# Sets the maximum time the job can run (hh:mm:ss).
#SBATCH --time=00:05:00

# Specifies nodes for the job. 
#SBATCH --ntasks=1      
#SBATCH --cpus-per-task=16    # cores 

# Sets the output files.
#SBATCH --output=./%x.%j.txt

module list
echo "Job Started at $(date)"

# Sets the default team size
export OMP_NUM_THREADS=$SLURM_CPUS_PER_TASK
echo "Number of OpenMP Threads: $OMP_NUM_THREADS"

./O3 100000000

