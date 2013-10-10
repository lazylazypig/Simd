/*
* Simd Library.
*
* Copyright (c) 2011-2013 Yermalayeu Ihar.
*
* Permission is hereby granted, free of charge, to any person obtaining a copy 
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell 
* copies of the Software, and to permit persons to whom the Software is 
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in 
* all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR 
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE 
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER 
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*/
#ifndef __SimdFill_h__
#define __SimdFill_h__

#include "Simd/SimdTypes.h"

namespace Simd
{
    namespace Base
    {
        void Fill(uchar * dst, size_t stride, size_t width, size_t height, size_t pixelSize, uchar value);

        void FillFrame(uchar * dst, size_t stride, size_t width, size_t height, size_t pixelSize, 
            size_t frameLeft, size_t frameTop, size_t frameRight, size_t frameBottom, uchar value);

        void FillBgra(uchar * dst, size_t stride, size_t width, size_t height, uchar blue, uchar green, uchar red, uchar alpha = 0xFF);
    }

#ifdef SIMD_SSE2_ENABLE    
    namespace Sse2
    {
        void FillBgra(uchar * dst, size_t stride, size_t width, size_t height, uchar blue, uchar green, uchar red, uchar alpha = 0xFF);
    }
#endif// SIMD_SSE2_ENABLE

#ifdef SIMD_AVX2_ENABLE    
    namespace Avx2
    {
        void FillBgra(uchar * dst, size_t stride, size_t width, size_t height, uchar blue, uchar green, uchar red, uchar alpha = 0xFF);
    }
#endif// SIMD_AVX2_ENABLE

    SIMD_INLINE void Fill(uchar * dst, size_t stride, size_t width, size_t height, size_t pixelSize, uchar value)
    {
        Base::Fill(dst, stride, width, height, pixelSize, value);
    }

    SIMD_INLINE void FillFrame(uchar * dst, size_t stride, size_t width, size_t height, size_t pixelSize, 
        size_t frameLeft, size_t frameTop, size_t frameRight, size_t frameBottom, uchar value)
    {
        Base::FillFrame(dst, stride, width, height, pixelSize, frameLeft, frameTop, frameRight, frameBottom, value);
    }

    void FillBgra(uchar * dst, size_t stride, size_t width, size_t height, uchar blue, uchar green, uchar red, uchar alpha = 0xFF);
}
#endif//__SimdFill_h__