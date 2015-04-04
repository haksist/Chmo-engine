//
//  TestComponent.h
//  EngineTesting
//
//  Created by Hakob on 11/13/14.
//  Copyright (c) 2014 Haksist. All rights reserved.
//
#include <iostream>

#include "Engine.h"
#include "GameLogic.h"
#include "Input.h"
#include "GameTime.h"
#include "FPSCounter.cpp"
#include "SpriteRenderer.h"
#include "MeshRenderer.h"

using namespace std;

class GLTestComponent : public GameLogic
{
public:
	~GLTestComponent()
    {
       cout << "GLTestComponent:: ~~~deleted~~~" << endl; 
    }
    
	void Create()
	{
		cout << "GLTestComponent:: Create" << endl;
	}

	void Init()
	{	
		std::cout << "GL TEST INITED" << std::endl;
	}
    
    void Update()
    {
		if (Input::IsKeyDownNow(KeyCode::RIGHT_ALT))
		{
			MeshRenderer* meshRend = GameObject::FindComponent<MeshRenderer>();

			if (meshRend != NULL)
			{
				smart_pointer<Mesh> mesh = meshRend->getSharedMesh();

				std::vector<unsigned int> indices{ 0, 1, 2 };
				std::vector<Vector3> verts{ Vector3(-1.0f, -1.0f, 0.0f), Vector3(1.0f, -1.0f, 0.0f), Vector3(1.0f, 1.0f, 0.0f), Vector3(-1.0f, 1.0f, 0.0f) };
				std::vector<Vector3> norms{ Vector3(0.0f, 0.0f, 1.0f), Vector3(0.0f, 0.0f, 1.0f), Vector3(0.0f, 0.0f, 1.0f) };

				mesh->setVertices(verts);
				//mesh->setNormals(norms);
				mesh->setIndices(indices);
			}
			else
				std::cout << "CAN'T FIND\n";
		}

		if (Input::IsKeyDownNow(KeyCode::LEFT_CTRL))
		{
			MeshRenderer* meshRend = GameObject::FindComponent<MeshRenderer>();

			if (meshRend != NULL)
			{
				smart_pointer<Mesh> mesh = meshRend->getSharedMesh();

				std::vector<unsigned int> indices{ 3,0,2 };
				std::vector<Vector3> verts{ Vector3(-1.0f, -3.0f, 0.0f), Vector3(1.0f, -1.0f, 0.0f), Vector3(1.0f, 1.0f, 0.0f), Vector3(-1.0f, 1.0f, 0.0f) };
				std::vector<Vector3> norms{ Vector3(0.0f, 0.0f, 1.0f), Vector3(0.0f, 0.0f, 1.0f), Vector3(0.0f, 0.0f, 1.0f) };

				mesh->setVertices(verts);
				//mesh->setNormals(norms);
				mesh->setIndices(indices);
			}
			else
				std::cout << "CAN'T FIND\n";
		}

		//glMaterialfv(GL_FRONT, GL_DIFFUSE, new float[4]{ 1.0f, 0.0f, 0.0f, 1.0f });
		//glBegin(GL_LINES);
		//{
		//	float z = -5.0f;

		//	glVertex3f(0.0f, 1.0f, z);
		//	glVertex3f(0.0f, -1.0f, z);

		//	glVertex3f(-1.0f, 0.0f, z);
		//	glVertex3f(1.0f, 0.0f, z);
		//}
		//glEnd();

		if (Input::IsKeyDown(27))
		{
			printf("AUUUUUU\n");
			exit(0);
		}

		float speed = 15.0f;
		float rotationSpeed = 100.0f;
		if (Input::IsKeyDown(KeyCode::a))
			getTransform()->RotateY(rotationSpeed*GameTime::DeltaTime());
		if (Input::IsKeyDown(KeyCode::d))
			getTransform()->RotateY(-rotationSpeed*GameTime::DeltaTime());
		if (Input::IsKeyDown(KeyCode::w))
			getTransform()->TranslateForward(-speed*GameTime::DeltaTime());
		if (Input::IsKeyDown(KeyCode::s))
			getTransform()->TranslateForward(speed*GameTime::DeltaTime());

		if (Input::IsKeyDown(KeyCode::n))
		{
			getTransform()->RotateX(rotationSpeed*GameTime::DeltaTime());
		}
		if (Input::IsKeyDown(KeyCode::m))
		{
			getTransform()->RotateX(-rotationSpeed*GameTime::DeltaTime());
		}
    }

	void OnAction(string action, void*const data)
	{
		cout << "GLTestComponent::Action:" << action << endl;
	}

	void OnEnable()
	{
		std::cout << "GLTestComponent: OnEnable" << std::endl;
	}

	void OnDisable()
	{
		std::cout << "GLTestComponent: OnDisable" << std::endl;
	}

	void OnDestroy()
	{
		std::cout << "GLTestComponent: OnDestroy" << std::endl;
	}
};

