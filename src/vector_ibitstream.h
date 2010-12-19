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
#ifndef VECTOR_IBITSTREAM_H
#define VECTOR_IBITSTREAM_H

#include <istream>
#include "ibitstream.h"
#include "obitstream.h"

namespace wavelet {

  ///
  /// Class for reading individual bits at a time from an input stream.
  // 
  class vector_ibitstream : public ibitstream {
  protected:
    const unsigned char *buf_;        ///< Buffer of input characters
    const size_t end_;                ///< End of buffer in memory (1 past last byte)
    size_t pos_;                      ///< Position in buffer to read next byte
    unsigned char mask_;              ///< Mask of next bit to read.
    
    size_t total_bits_;               ///< Total bits read in.

  public:
    /// Constructs an vector_ibitstream to read from the prvided input stream.
    /// Params:
    ///    buf   buffer to read from
    ///    size  size in bytes of buffer
    vector_ibitstream(const unsigned char *buf, size_t size);

    /// Destructor; does nothing.
    virtual ~vector_ibitstream();

    /// Gets a single bit of input.  Left in header to enable inlining.
    unsigned read_bit() {
      unsigned bit = (mask_ & buf_[pos_]) ? 1 : 0;
      mask_ >>= 1;

      if (mask_ == 0) {
        pos_++;
        mask_ = 0x80;
      }

      total_bits_++;
      return bit;
    }

    /// True if there are more bits to be input.
    virtual bool good() {
      return (pos_ < end_);
    }


    virtual size_t in_bytes();


    virtual void next_byte();

  }; // vector_ibitstream

} // namespace

#endif // VECTOR_IBITSTREAM_H

