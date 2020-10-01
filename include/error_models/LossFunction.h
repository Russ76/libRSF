/***************************************************************************
 * libRSF - A Robust Sensor Fusion Library
 *
 * Copyright (C) 2018 Chair of Automation Technology / TU Chemnitz
 * For more information see https://www.tu-chemnitz.de/etit/proaut/self-tuning
 *
 * libRSF is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * libRSF is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with libRSF.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Author: Tim Pfeifer (tim.pfeifer@etit.tu-chemnitz.de)
 ***************************************************************************/

/**
 * @file LossFunction.h
 * @author Tim Pfeifer
 * @date 22.11.2016
 * @brief Collection of classes that represent robust cost functions
 * @copyright GNU Public License.
 *
 */

#ifndef LOSSFUNCTION_H
#define LOSSFUNCTION_H

#include <ceres/ceres.h>

using ceres::LossFunction;

namespace libRSF
{
  /** \brief The robust Dynamic Covariance Scaling loss function
   * Based on:
   * P. Agarwal, G. D. Tipaldi, L. Spinello, C. Stachniss and W. Burgard
   * "Robust map optimization using dynamic covariance scaling"
   * 2013 IEEE International Conference on Robotics and Automation, Karlsruhe, 2013
   * DOI: 10.1109/ICRA.2013.6630557
   *
   * \param Phi Tuning parameter of DCS
   *
   */
  class DCSLoss : public LossFunction
  {
  public:
      explicit DCSLoss(double Phi) : Phi_(Phi) {};
      ~DCSLoss(){};

      virtual void Evaluate(double, double*) const;

  private:
    const double Phi_;
  };

  /** \brief The robust closed form of Dynamic Covariance Estimation
   * Based on:
   * T. Pfeifer, S. Lange and P. Protzel
   * "Dynamic Covariance Estimation — A parameter free approach to robust Sensor Fusion"
   * 2017 IEEE International Conference on Multisensor Fusion and Integration for Intelligent Systems (MFI), Daegu, 2017
   * DOI: 10.1109/MFI.2017.8170347
   *
   * \param Sigma Standard deviation without outliers
   *
   */
  class cDCELoss : public LossFunction
  {
  public:
      explicit cDCELoss(double Sigma) : Sigma_(Sigma) {};
      ~cDCELoss(){};

      virtual void Evaluate(double, double*) const;

  private:
    const double Sigma_;
  };


}

#endif // LOSSFUNCTION_H
