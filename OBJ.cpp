#include "OBJ.h"

Mesh::Mesh()
{
	vertices = NULL;
	faces = NULL;
}

Mesh::~Mesh()
{
	if (vertices != NULL)
		delete vertices;
	if (faces != NULL)
		delete faces;
}

// 这个函数需要你来实现
Mesh* readOBJ(string  sFileName)
{
	Mesh *pModel = new Mesh;
	pModel->numVertices = 0;
	pModel->numFaces = 0;
	std::ifstream in(sFileName.c_str());
	if (!in.good())
	{
		std::cout << "ERROR: loading obj:(" << sFileName << ") file is not good" << endl;
		exit(0);
	}
	char buffer[256], str[256];
	float f1, f2, f3;
	int i1, i2, i3;
	Point point[4000];
	Face face[6500];
	pModel->vertices = point+1;
	pModel->faces = face + 1;
	while (!in.getline(buffer, 255).eof())
	{
		buffer[255] ='\0';
		scanf_s(buffer, "%s", str, 255);

		//read a vertex
		if (buffer[0] == 'v' && (buffer[1] == ' ' || buffer[1] == 32))
		{
			
			if (sscanf(buffer, "v %f %f %f", &f1,&f2,&f3 )==3)
			{
				
				pModel->numVertices++;
				Point V;
				V.x = f1, V.y = f2, V.z = f3;
				point[pModel->numVertices] = V;
				//pModel->vertices[pModel->numVertices] = V;
			}
			else
			{
				cout << "ERROR:Verteix is not found!";
				exit(0);
			}
		}
		 else if (buffer[0] == 'f' && (buffer[1] == ' ' || buffer[1] == '32'))
		{
			if (sscanf(buffer, "f %d %d %d", &i1, &i2, &i3) == 3)
			{

				pModel->numFaces++;
				Face F;
				F.idx0 = i1, F.idx1 = i2, F.idx2 = i3;
				face[pModel->numFaces] = F;
				//pModel->faces[pModel->numFaces] = F;
			}
			else
			{
				cout << "ERROR:Verteix is not found!";
				exit(0);
			}
		
		}
		
	}

	
	return pModel; // return the pointer to a Mesh instance
}

