#!/usr/bin/env bash

#SBATCH --job-name=hello
#SBATCH --partition=talon
#SBATCH --time=00:01:00

#SBATCH --ntasks=1

#SBATCH --output=%x.%j.txt

echo "Job started at $(date)"
hostname
./hello 

echo "Job ended at $(date)"
