#!/usr/bin/env bash
#-----------------------------------
# slurm.sh
#
# Submit to cluster: 
#   $ sbatch slurm.sh
#
# Check completion status:
#   $ squeue | grep [userid]
#   $ squeue -u [userid]
#   $ squeue -j [jobid]
#-----------------------------------
#
#SBATCH --job-name=ct
#SBATCH --partition=talon-gpu32
#SBATCH --gres=gpu:2

# Sets the maximum time the job can run (hh:mm:ss).
#SBATCH --time=0:01:00

# Specifies tasks for the job. 
#SBATCH --ntasks=1

# Sets the output files
#SBATCH --output=./%x.%j.txt

module load shared
module load gcc
module load cuda11.2/toolkit
module list
echo ""

echo "--- hostname ---"
hostname
echo ""
echo ""

# Run the programs
echo "--- cudatest ---"
./cudatest
echo ""
echo "--- drivertest ---"
./drivertest
echo ""
echo "--- nvidia-smi ---"
nvidia-smi
echo ""
