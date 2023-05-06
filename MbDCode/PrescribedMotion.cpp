#include <memory>
#include <typeinfo>
#include <assert.h>

#include "PrescribedMotion.h"
#include "EndFrameqct.h"

using namespace MbD;

PrescribedMotion::PrescribedMotion() {
	initialize();
}

PrescribedMotion::PrescribedMotion(const char* str) : Joint(str) {
	initialize();
}

void PrescribedMotion::initialize()
{
}

void PrescribedMotion::connectsItoJ(std::shared_ptr<EndFramec> frmi, std::shared_ptr<EndFramec> frmj)
{
	Joint::connectsItoJ(frmi, frmj);
	if (typeid(frmI).name() != "EndFrameqct") {
		std::shared_ptr<EndFramec> newFrmI;
		newFrmI = std::make_shared<EndFrameqct>();
		std::swap(frmI, newFrmI);
		assert(typeid(frmI).name() != "EndFrameqct");
	}
}
