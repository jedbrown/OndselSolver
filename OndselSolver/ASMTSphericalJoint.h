/***************************************************************************
 *   Copyright (c) 2023 Ondsel, Inc.                                       *
 *                                                                         *
 *   This file is part of OndselSolver.                                    *
 *                                                                         *
 *   See LICENSE file for details about copyright.                         *
 ***************************************************************************/
 
#pragma once

#include "ASMTJoint.h"
#include "SphericalJoint.h"

namespace MbD {
    class EXPORT ASMTSphericalJoint : public ASMTJoint
    {
        //
    public:
        std::shared_ptr<Joint> mbdClassNew() override;
        void storeOnLevel(std::ofstream& os, int level) override;
        void storeOnTimeSeries(std::ofstream& os) override;

    };
}

