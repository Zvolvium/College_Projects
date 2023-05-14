#!/usr/bin/env bash
# 
#SBATCH --job-name=hw5
#
#SBATCH --time=00:05:00
#SBATCH --partition=talon
#SBATCH --ntasks=1
#
#SBATCH --output=%x.%j.txt
##SBATCH --mail-type=fail
##SBATCH --mail-user=firstname.lastname@und.edu

module load shared
module load gcc9
module load cuda11.2/toolkit
module list

./rgb2grey bw-black-lab-cpu.txt rgb-black-lab.txt 3000 4499 


