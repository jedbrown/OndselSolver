#include "Part.h"
#include "PartFrame.h"
#include "EulerConstraint.h"
#include "AbsConstraint.h"
#include "MarkerFrame.h"

using namespace MbD;

PartFrame::PartFrame()
{
	aGeu = std::make_shared<EulerConstraint>("EulerCon");
	aGeu->setOwner(this);
	aGabs = std::make_unique<std::vector<std::shared_ptr<AbsConstraint>>>();
	markerFrames = std::make_unique<std::vector<std::shared_ptr<MarkerFrame>>>();
}
MbD::PartFrame::PartFrame(const char* str) : CartesianFrame(str)
{
}
void MbD::PartFrame::initialize()
{
}
void PartFrame::setqX(FullColDptr x) {
	qX->copy(x);
}
FullColDptr PartFrame::getqX() {
	return qX;
}
void PartFrame::setqE(FullColDptr x) {
	qE->copy(x);
}
FullColDptr PartFrame::getqE() {
	return qE;
}
void PartFrame::setPart(Part* x) {
	part = x;
}
Part* PartFrame::getPart() {
	return part;
}

void PartFrame::addMarkerFrame(std::shared_ptr<MarkerFrame> markerFrame)
{
	markerFrame->setPartFrame(this);
	markerFrames->push_back(markerFrame);
}

std::shared_ptr<EndFramec> PartFrame::endFrame(std::string name)
{
	auto match = std::find_if(markerFrames->begin(), markerFrames->end(), [&](auto mkr) {return mkr->getName() == name; });
	return (*match)->endFrames->at(0);
}
