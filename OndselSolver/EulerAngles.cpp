/***************************************************************************
 *   Copyright (c) 2023 Ondsel, Inc.                                       *
 *                                                                         *
 *   This file is part of OndselSolver.                                    *
 *                                                                         *
 *   See LICENSE file for details about copyright.                         *
 ***************************************************************************/
 
#include "EulerAngles.h"

namespace MbD {
    template<typename T>
    inline void EulerAngles<T>::initialize()
    {
        assert(false);
    }
    template<>
    inline void EulerAngles<Symsptr>::calc()
    {
        cA = std::make_shared<FullColumn<FMatDsptr>>(3);
        for (int i = 0; i < 3; i++)
        {
            auto axis = rotOrder->at(i);
            auto angle = this->at(i)->getValue();
            if (axis == 1) {
                cA->atiput(i, FullMatrixDouble::rotatex(angle));
            }
            else if (axis == 2) {
                cA->atiput(i, FullMatrixDouble::rotatey(angle));
            }
            else if (axis == 3) {
                cA->atiput(i, FullMatrixDouble::rotatez(angle));
            }
            else {
                throw std::runtime_error("Euler angle rotation order must be any permutation of 1,2,3 without consecutive repeats.");
            }
        }
        aA = cA->at(0)->timesFullMatrix(cA->at(1)->timesFullMatrix(cA->at(2)));
    }
    template<>
    inline void EulerAngles<double>::calc()
    {
        cA = std::make_shared<FullColumn<FMatDsptr>>(3);
        for (int i = 0; i < 3; i++)
        {
            auto axis = rotOrder->at(i);
            auto angle = this->at(i);
            if (axis == 1) {
                cA->atiput(i, FullMatrixDouble::rotatex(angle));
            }
            else if (axis == 2) {
                cA->atiput(i, FullMatrixDouble::rotatey(angle));
            }
            else if (axis == 3) {
                cA->atiput(i, FullMatrixDouble::rotatez(angle));
            }
            else {
                throw std::runtime_error("Euler angle rotation order must be any permutation of 1,2,3 without consecutive repeats.");
            }
        }
        aA = cA->at(0)->timesFullMatrix(cA->at(1)->timesFullMatrix(cA->at(2)));
    }
    template<typename T>
    inline void EulerAngles<T>::calc()
    {
        assert(false);
    }
    template<typename T>
    inline std::shared_ptr<EulerAnglesDot<T>> EulerAngles<T>::differentiateWRT(T var)
    {
        auto derivatives = std::make_shared<EulerAnglesDot<T>>();
        std::transform(this->begin(), this->end(), derivatives->begin(),
                       [var](T term) { return term->differentiateWRT(var); }
        );
        derivatives->aEulerAngles = this;
        return derivatives;
    }
    template<typename T>
    inline void EulerAngles<T>::setRotOrder(int i, int j, int k)
    {
        rotOrder = std::make_shared<FullColumn<int>>(3);
        rotOrder->at(0) = i;
        rotOrder->at(1) = j;
        rotOrder->at(2) = k;
    }
    template class EulerAngles<std::shared_ptr<MbD::Symbolic>>;
}

