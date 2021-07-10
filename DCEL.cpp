#include "DCEL.h"

HEMesh::HEMesh()
{
	vertices = NULL;
	//faces = NULL;
	//edges = NULL;
}

HEMesh::~HEMesh()
{
	if (vertices != NULL)
		delete vertices;
	//if (faces != NULL)
		//delete faces;
	//if (edges != NULL)
		//delete edges;
}

HE_edge* HEMesh::InsertEdge(HE_vert* v1, HE_vert* v2)
{
	if (v1 == NULL || v2 == NULL)
	{
		return NULL;
	}
	if (vert_edges[v1->vidx][v2->vidx]!=0)
	{
		for (int i = 0; i < edges.size(); i++)
		{
			if(edges[i]->vert==v1&&edges[i]->next->vert==v2)
			return edges[i];
			break;
		}
		
	}
	//提前建立对偶边 并建立好点 边关系
	HE_edge* edge = new HE_edge;
	edge->vert = v1;
	v1->edge = edge;
	HE_edge* p_edge = new HE_edge;
	p_edge->vert = v2;
	v2->edge = p_edge;
	//建立对偶关系
	edge->pair = p_edge;
	p_edge->pair = edge;
	vert_edges[v1->vidx][v2->vidx] = 1;
	edges.push_back(edge);


	return edge;
}
// 这个函数需要你来实现
void HEMesh::ConstructFromMesh(Mesh* pMesh)
{
	numHalfEdges = pMesh->numVertices + pMesh->numFaces - 2;
	numFaces = pMesh->numFaces;
	numVertices = pMesh->numVertices;
	int numedges = (pMesh->numVertices + pMesh->numFaces - 2)*2;
	HE_face *Hface=new HE_face;
	Hface = NULL;
	HE_vert Hvert[4000];
	vertices = Hvert+1;
	faces.push_back(Hface);

	for (int i = 1; i <= pMesh->numVertices; i++)
	{
		Point V = *(pMesh->vertices + i - 1);
		Hvert[i].vidx = i ;
		Hvert[i].x = V.x;
		Hvert[i].y = V.y;
		Hvert[i].z = V.z;		
	}
	
	
	int k = 0;
	for (int j = 1; j <= pMesh->numFaces; j++)
	{
		Face f = *(pMesh->faces + j - 1);
		HE_edge* e1 = InsertEdge(&Hvert[f.idx0], &Hvert[f.idx1]);
		HE_edge* e2 = InsertEdge(&Hvert[f.idx1], &Hvert[f.idx2]);
		HE_edge* e3 = InsertEdge(&Hvert[f.idx2], &Hvert[f.idx0]);

		HE_face* face = new HE_face;
		face->fidx = j;
		face->idx0 = f.idx0;
		face->idx1 = f.idx1;
		face->idx2 = f.idx2;
		face->edge = e1;
		faces.push_back(face);
		
		e1->next = e2;
		e2->next = e3;
		e3->next = e1;
		e1->prev = e3;
		e2->prev = e1;
		e3->prev = e2;
		e1->face = e2->face = e3->face = face;
	}

		

		/*
		//idx0对应的两条边
		//idx0->idx1 [0]
		Hedge[k].vert = &Hvert[Hface[j].idx0];
		Hedge[k].pair = &Hedge[k+1];
		Hedge[k].face = &Hface[j];
		Hedge[k].next =&Hedge[(k+1)%3] ;
		Hedge[k].prev = &Hedge[(k-1)%3];

		//idx1->idx2 [1]
		k++;
		Hedge[k].vert = &Hvert[Hface[j].idx1];
		Hedge[k].pair = &Hedge[k + 1];
		Hedge[k].face = &Hface[j];
		Hedge[k].next = &Hedge[(k+1)%3];//4
		Hedge[k].prev = &Hedge[(k-1)%3];//0

		//idx2->idx0[2]
		k++;
		Hedge[k].vert = &Hvert[Hface[j].idx2];
		Hedge[k].pair = &Hedge[k + 1];
		Hedge[k].face = &Hface[j];
		Hedge[k].next = &Hedge[(k+1)%3];//0
		Hedge[k].prev =&Hedge[(k-1)%3];//2

	}
	for(int i=1;i<= numVertices;i++)
		for (int m = 0; m < numedges; m++)
		{
			if (Hvert[i].vidx == Hedge[m].vert->vidx)
			{
				Hvert[i].edge = &Hedge[m];
				break;
			}
		}*/
	
	return;
}
