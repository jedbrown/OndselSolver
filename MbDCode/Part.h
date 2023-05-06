#pragma once
#include <memory>

#include "Item.h"
#include "System.h"
#include "PartFrame.h"
#include "FullColumn.h"

namespace MbD {
	class System;
	class PartFrame;

	class Part : public Item
	{
		//ToDo: ipX ipE m aJ partFrame pX pXdot pE pEdot mX mE mEdot pTpE ppTpEpE ppTpEpEdot 
	public:
		Part();
		Part(const char* str);
		void initialize();
		void setqX(FullColDptr x);
		FullColDptr getqX();
		void setqE(FullColDptr x);
		FullColDptr getqE();
		void setSystem(System& sys);
		void initializeLocally();
		void initializeGlobally();

		std::shared_ptr<PartFrame> partFrame;
	};
}

