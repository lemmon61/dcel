#ifndef DCEL_H
#define DCEL_H

#include <stdio.h>
#include "OBJ.h"

// struct declarations
struct HE_vert;
struct HE_edge;
struct HE_face;

// the struct of vertex in DCEL
struct HE_vert
{
	float x, y, z;
	HE_edge *edge;
	int vidx;
};

// the struct of half edge in DCEL
struct HE_edge
{
	HE_vert* vert; // the start vertex
	HE_edge* pair; // the twin half edge
	HE_face* face; // the adjacent face
	HE_edge* next; // the next half edge
	HE_edge* prev; // the previous half edge
};

// the struct of face in DCEL
struct HE_face
{
	int idx0, idx1, idx2;
	HE_edge* edge;
	int fidx;
};

// the mesh class in DCEL
class HEMesh
{
public:
	HE_vert* vertices;
	vector <HE_face*> faces;
	vector <HE_edge*> edges;

	int numVertices;
	int numFaces;
	int numHalfEdges;
	int vert_edges[4000][4000] = { 0 };

	HEMesh();
	~HEMesh();

	//int vert_pair(HE_vert* v1, HE_vert* v2);
	void ConstructFromMesh(Mesh* pMesh);
	HE_edge* InsertEdge(HE_vert* v3, HE_vert* v4);
};



#endif
