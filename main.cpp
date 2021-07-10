#include "OBJ.h"
#include "DCEL.h"


// ���������Ҫ����ʵ��
int main()
{
	int idx1,idx2,idx3, n, n0, n1, n2;
	Mesh *pMesh = readOBJ("E:\\cube.obj");
	HEMesh *pHEMesh = new HEMesh;
	pHEMesh->ConstructFromMesh(pMesh);
	int numedges = (pMesh->numVertices + pMesh->numFaces - 2) * 2;
	//HE_face* AndFace;
	 
	cout << "����һ����������ţ���������������ڶ���������" << endl;
	cin >> idx1;
	for (unsigned int i = 0; i < pHEMesh->edges.size(); i++)
	{
		if (pHEMesh->edges[i]->vert->vidx == idx1)
		{
			cout << "���ڵ�������" << pHEMesh->edges[i]->next->vert->vidx << endl;
		}
	}
	cout << "����һ����������ţ������������������Ƭ������" << endl;
	cin >> idx2;
	for (unsigned int i = 0; i < pHEMesh->edges.size(); i++)
	{
		if (pHEMesh->edges[i]->vert->vidx == idx2)
		{
			cout << "���ڵ�������" << pHEMesh->edges[i]->face->fidx << endl;
		}
	}
	cout << "����һ����Ƭ�������ţ������������������Ƭ������" << endl;
	cin >> idx3;
	for (unsigned int i = 1; i < pHEMesh->faces.size(); i++)
	{
		if (pHEMesh->faces[i]->fidx == idx3)
		{
			n0 = pHEMesh->faces[i]->idx0;
			n1 = pHEMesh->faces[i]->idx1;
			n2 = pHEMesh->faces[i]->idx2;	
			n = i;
			break;
		}		
	}
	for (unsigned int j = 1; j <pHEMesh->faces.size(); j++)
	{
		
		if ((j != n)&&((pHEMesh->faces[j]->idx0 == n0)|| (pHEMesh->faces[j]->idx1 == n0) || (pHEMesh->faces[j]->idx2 == n0)) && ((pHEMesh->faces[j]->idx0 == n1) || (pHEMesh->faces[j]->idx1 == n1) ||( pHEMesh->faces[j]->idx2 == n1)))
		{
			cout << "������Ƭ������" <<j<< endl;
		}
		else if((j != n) && ((pHEMesh->faces[j]->idx0 == n0) ||( pHEMesh->faces[j]->idx1 == n0 )|| (pHEMesh->faces[j]->idx2 == n0)) && ((pHEMesh->faces[j]->idx0 == n2) || (pHEMesh->faces[j]->idx1 == n2) || (pHEMesh->faces[j]->idx2 == n2)))
		{
			cout << "������Ƭ������" << j << endl;
		}
		else if((j != n)&& ((pHEMesh->faces[j]->idx0 == n1) || (pHEMesh->faces[j]->idx1 == n1) || (pHEMesh->faces[j]->idx2 == n1)) && ((pHEMesh->faces[j]->idx0 == n2) || (pHEMesh->faces[j]->idx1 == n2) || (pHEMesh->faces[j]->idx2 == n2)))
		{
			cout << "������Ƭ������" <<j << endl;
		}
		else
		{
			continue;
		}
	}
	delete pMesh;
	delete pHEMesh;
	return 0;
}