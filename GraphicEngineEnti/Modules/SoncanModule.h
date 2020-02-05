#pragma once
#include "../Modules/Module.h"
#include "../Render/Mesh/primitives.h"
#include "../Geometry/Transform.h"
#include "../Modules/RenderModule.h"
#include <vector>

class SoncanModule : public Module
{
private:
	Transform transform;
	std::vector<Transform*> transforms;
	std::vector<Transform> transfv;

	Transform *  NewCube(const float x, const float y, const float z) const;

	void newCube(const float x, const float y, const float z);
public:

	virtual void start() override;
	virtual void stop() override;
	virtual void renderDebug() override;
	virtual void update(float elapsed)override;


	SoncanModule();
	~SoncanModule();
};

