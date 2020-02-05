#include "precompiledHeader.h"
#include "SoncanModule.h"

extern Mesh cube;
void SoncanModule::start()
{
	transform.setPosition(0.0f, -1.0f, -3.0f);
	transforms.push_back(NewCube(0, 0, -20));
}

void SoncanModule::stop()
{
	for (auto & it : transforms)
	{
		delete it;
	}
}

Transform * SoncanModule::NewCube(const float x, const float y, const float z) const
{
	Transform  *  modelT = new Transform ;

	//glm::vec3 euler = modelT.getEulerAngles();
	//modelT.setEulerAngles(euler.x , euler.y + glfwGetTime(), euler.z);

	modelT->setPosition(glm::vec3(x, y, z));
	

	return modelT;
}

void SoncanModule::newCube(const float x, const float y, const float z)
{
	transfv.emplace_back(x, y, z);
	Engine::get().setModelObjectConstants(transfv[0].asMatrix(), glm::vec4(1.0f));

	cube.activateAndRender();
}

void SoncanModule::renderDebug()
{
	
	NewCube(5, 0, -20);
	NewCube(-5, 0, -20);


	newCube(5, 0, -20);
	Engine::get().setModelObjectConstants(transforms[0]->asMatrix(), glm::vec4(1.0f));
	
	cube.activateAndRender();


}



void SoncanModule::update(float elapsed)
{
	//if (transforms.at(0) != nullptr)
	{
		glm::vec3 euler = transforms[0]->getEulerAngles();
		transforms[0]->setEulerAngles(euler.x, euler.y + glfwGetTime(), euler.z);
	}


}



SoncanModule::SoncanModule()
{


}


SoncanModule::~SoncanModule()
{


}
