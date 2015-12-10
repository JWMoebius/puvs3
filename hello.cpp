#include <stdio.h>
#include <mpi.h>                              // benutze die Headerdatei für die OpenMPI-Spezifikationen

int main(int argc, char* argv[])
{
  int nodeID, numNodes;
  
  /* Reihhe von Operationenm die MPI initialisiert und die speichere Anzahl sowie ID  der aktiven Prozesse */
  MPI_Init(&argc, &argv);                      // initialisiere MPI-Laufzeitsystem mit Eingabe n vielen Prozessen/Knoten
  MPI_Comm_size(MPI_COMM_WORLD, &numNodes);    // speichere die Anzahl aller Prozesse/Knoten in numNodes
  MPI_Comm_rank(MPI_COMM_WORLD, &nodeID);      // speichere Identifikationsnummer der Prozesse/Knoten
  
  /* Gebe unteres Grußnachrucht durch jeden Prozess/Knoten einmal aus, bei der auch jeweilige ProzessID mit der Anzahl der Gesamtknoten ausgegeben wird */
  printf("Hello world from process %d of %d\n", nodeID, numNodes);
  
  /* Abmelden des Prozess von Laufzeitsystem, (kann bis Abschluss aller MPI-Operationen blockieren) */
  MPI_Finalize();
  
  return 0;
}

/* Aufgabe 1 c)
Ausgabe von hello world mit Nummer der ProzessID und Anzahl aller Prozesse
Windows 8.1 OpenMPI 1.6.1 : mit Zwei Prozessen
C:\Users\User\Documents\Coding\C++\Uni\puvs3>mpirun -mca btl_tcp_if_exclude lo -np 2 hello.exe
Hello world from process 0 of 2
Hello world from process 1 of 2

C:\Users\User\Documents\Coding\C++\Uni\puvs3>mpirun -mca btl_tcp_if_exclude l
o -np 8 hello.exe
Hello world from process 0 of 8
Hello world from process 1 of 8
Hello world from process 2 of 8
Hello world from process 3 of 8
Hello world from process 4 of 8
Hello world from process 5 of 8
Hello world from process 7 of 8
Hello world from process 6 of 8


//Man sieht, dass wie bei OpenMP möglicherweise die Reihenfolge der Prozesse nicht zwingend in der Reihenfolge ihrer Nummerierung erfolgt
/*
mpic++ hello.cpp
mpirun -mca btl_tcp_if_exclude lo -np 2 hello.exe
*/