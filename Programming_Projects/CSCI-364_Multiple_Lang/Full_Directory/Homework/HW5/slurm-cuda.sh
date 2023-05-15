#!/usr/bin/env bash
# 
#SBATCH --job-name=hw5-cuda
#
#SBATCH --time=00:05:00
#SBATCH --partition=talon-gpu32
#SBATCH --gres=gpu:1
#SBATCH --ntasks=1
#
#SBATCH --output=%x.%j.txt
##SBATCH --mail-type=fail
##SBATCH --mail-user=firstname.lastname@und.edu

module load shared
module load gcc9
module load cuda11.2/toolkit
module list

./rgb2grey-cuda bw-black-lab-cuda.txt rgb-black-lab.txt 3000 4499 


