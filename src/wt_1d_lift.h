/////////////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2010, Lawrence Livermore National Security, LLC.  
// Produced at the Lawrence Livermore National Laboratory  
// Written by Todd Gamblin, tgamblin@llnl.gov.
// LLNL-CODE-417602
// All rights reserved.  
// 
// This file is part of Nami. For details, see http://github.com/tgamblin/nami.
// Please also read the LICENSE file for further information.
// 
// Redistribution and use in source and binary forms, with or without modification, are
// permitted provided that the following conditions are met:
// 
//  * Redistributions of source code must retain the above copyright notice, this list of
//    conditions and the disclaimer below.
//  * Redistributions in binary form must reproduce the above copyright notice, this list of
//    conditions and the disclaimer (as noted below) in the documentation and/or other materials
//    provided with the distribution.
//  * Neither the name of the LLNS/LLNL nor the names of its contributors may be used to endorse
//    or promote products derived from this software without specific prior written permission.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS
// OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
// MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL
// LAWRENCE LIVERMORE NATIONAL SECURITY, LLC, THE U.S. DEPARTMENT OF ENERGY OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
// (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
// WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
// ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
/////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef WT_1D_LIFT_H
#define WT_1D_LIFT_H

#include "wt_1d.h"

namespace wavelet {

  /// 1d lifted wavelet transform.  Currently only supports CDF97 wavelets.
  ///
  /// Provides implementation of wt_1d_single routines for wt_1d interface.
  /// 
  /// Based on the 1d version by Gregoire Pau that is available here:
  ///   http://www.ebi.ac.uk/~gpau/misc/dwt97.c
  class wt_1d_lift : public wt_1d {
  public: 
    /// Default Constructor
    wt_1d_lift() { }
    
    /// Destructor
    virtual ~wt_1d_lift() { }

    /// Foward transform for raw contiguous data.
    virtual void fwt_1d_single(double *data, size_t n);

    /// Inverse transform for raw contiguous data.
    virtual void iwt_1d_single(double *data, size_t n);

  protected:
    /// temporary storage for packing
    std::vector<double> temp_;
  }; // wt_1d_lift

} // namespace wavelet

#endif // WT_1D_LIFT_H
