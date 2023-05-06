#pragma once
#include <memory>
#include <vector>

#include "Constraint.h"
#include "FullRow.h"

namespace MbD {
    class Temp : public Constraint
    {
		//pGpE iqE 
	public:
		Temp() {};
		Temp(Item* item) {};

		FullRowDptr pGpE = std::make_shared<FullRow<double>>(4);    //partial derivative of G wrt pE
		int iqE = -1;
	};
}

