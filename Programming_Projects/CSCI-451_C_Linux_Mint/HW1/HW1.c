// Mason Motschke - CSCI_451 - HW1
#include <stdlib.h>
#include <stdio.h>

int main (void){
  // Download PROJECTS.HTML file from below link
  system("wget -q http://undcemcs01.und.edu/~ronald.marsh/PROJECTS/PROJECTS.HTML");

  // Parse and print list of projects from file
  system("grep -E '^ {3}[0-9]?[.]?([0-9]*)?([.]*)?[A-Z][^A-Z]' PROJECTS.HTML | awk '$1=$1'");

  // Deletes PROJECTS.HTML file using unlink call
  system("unlink PROJECTS.HTML");
}
