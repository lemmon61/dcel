#ifndef OBJ_H
#define OBJ_H

#include <stdio.h>
#include <vector>
#include<iostream>
#include<fstream>
#include<string>
using namespace std;


// the struct for vertex, each vertex has x,y,z coordinates
struct Point
{
	float x, y, z;
};

// the struct for face, each face is a triangle and has three vertex indexs
struct Face
{
	int idx0, idx1, idx2;
};

// the class for Mesh
class Mesh
{
public:
	Mesh();
	~Mesh();

	Point* vertices;
	int numVertices;
	Face* faces;
	int numFaces;
};

// the function is to read the OBJ file specified by "sFileName", 
// and return the pointer to a Mesh instance
Mesh* readOBJ(string  sFileName);





#endif
