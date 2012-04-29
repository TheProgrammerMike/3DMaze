//v0.56 copyright Comine.com 20070427F10
#ifndef MSGAEngine3D_h
#define MSGAEngine3D_h

/////////////////////////////////////////////////////
#include <windows.h>
//v1.3 copyright Comine.com 20070405R11
#ifndef MSGAEngine3DObjectInfo_h
#define MSGAEngine3DObjectInfo_h

/////////////////////////////////////////////////////
/* irrlicht.h -- interface of the 'Irrlicht Engine'

  Copyright (C) 2002-2007 Nikolaus Gebhardt

  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.

  Permission is granted to anyone to use this software for any purpose,
  including commercial applications, and to alter it and redistribute it
  freely, subject to the following restrictions:

  1. The origin of this software must not be misrepresented; you must not
     claim that you wrote the original software. If you use this software
     in a product, an acknowledgment in the product documentation would be
     appreciated but is not required.
  2. Altered source versions must be plainly marked as such, and must not be
     misrepresented as being the original software.
  3. This notice may not be removed or altered from any source distribution.

  Please note that the Irrlicht Engine is based in part on the work of the 
  Independent JPEG Group, the zlib and the libPng. This means that if you use
  the Irrlicht Engine in your product, you must acknowledge somewhere in your
  documentation that you've used the IJG code. It would also be nice to mention
  that you use the Irrlicht Engine, the zlib and libPng. See the README files 
  in the jpeglib, the zlib and libPng for further informations.
*/

#ifndef __IRRLICHT_H_INCLUDED__
#define __IRRLICHT_H_INCLUDED__

// Copyright (C) 2002-2007 Nikolaus Gebhardt

#pragma comment(lib,"irrlicht.lib")

// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __IRR_COMPILE_CONFIG_H_INCLUDED__
#define __IRR_COMPILE_CONFIG_H_INCLUDED__

//! Irrlicht SDK Version
#define IRRLICHT_SDK_VERSION "1.3"

//! The defines for different operating system are:
//! _XBOX for XBox
//! WIN32 for Windows32
//! WIN64 for Windows64
//! _IRR_WINDOWS_ for all irrlicht supported windows versions
//! OS2 for OS/2
//! MACOSX for Mac OS X
//! LINUX for linux and unix (it is defined here if no other os is defined)

#if defined(WIN32) || defined(WIN64)
#define _IRR_WINDOWS_
#endif

#if !defined(_IRR_WINDOWS_) && !defined(_XBOX) && !defined(OS2) && !defined(MACOSX)
#define LINUX
#endif

#if defined(__sparc__) || defined(__sun__)
#define __BIG_ENDIAN__
#endif

#include <stdio.h>
//! Define _IRR_COMPILE_WITH_DIRECT3D_8_ and _IRR_COMPILE_WITH_DIRECT3D_9_ to compile 
//! the Irrlicht engine with Direct3D8 and/or DIRECT3D9.
/* If you only want to use the software device or opengl this can be useful.
This switch is mostly disabled because people do not get the g++ compiler compile
directX header files, and directX is only available on windows platforms. If you
are using Dev-Cpp, and want to compile this using a DX dev pack, you can define
_IRR_COMPILE_WITH_DX9_DEV_PACK_. So you simply need to add something like this
to the compiler settings: -DIRR_COMPILE_WITH_DX9_DEV_PACK
and this to the linker settings: -ld3dx9 -ld3dx8 **/
#if (defined(_IRR_WINDOWS_) || defined(_XBOX)) &&  (!defined(__GNUC__) || defined(IRR_COMPILE_WITH_DX9_DEV_PACK))

#define _IRR_COMPILE_WITH_DIRECT3D_8_
#define _IRR_COMPILE_WITH_DIRECT3D_9_

#endif

//! Define _IRR_COMPILE_WITH_OPENGL_ to compile the Irrlicht engine with OpenGL.
/* If you do not wish the engine to be compiled with OpengGL, comment this
define out. */
#if !defined(_XBOX)

#define _IRR_COMPILE_WITH_OPENGL_

#endif // ! _XBOX

//! Define _IRR_COMPILE_WITH_SOFTWARE_ to compile the Irrlicht engine with software driver
/* If you do not need the software driver, or want to use Burning's Video instead, 
comment this define out */
#define _IRR_COMPILE_WITH_SOFTWARE_

//! Define _IRR_COMPILE_WITH_BURNINGSVIDEO_ to compile the Irrlicht engine with Burning's video driver
/* If you do not need this software driver, you can comment this define out. */
#define _IRR_COMPILE_WITH_BURNINGSVIDEO_

//! Define _IRR_COMPILE_WITH_X11_ to compile the Irrlicht engine with X11 support.
/* If you do not wish the engine to be compiled with X11, comment this
define out. */
#if defined(LINUX)

#define _IRR_COMPILE_WITH_X11_

#endif


//! Define _IRR_OPENGL_USE_EXTPOINTER_ if the OpenGL renderer should use OpenGL extensions via function pointers.
/* On some systems there is no support for the dynamic extension of OpenGL
 via function pointers such that this has to be undef'ed. */
#if !defined(MACOSX) && !defined(__sun__)
#define _IRR_OPENGL_USE_EXTPOINTER_
#endif

//! On some Linux systems the XF86 vidmode extension or X11 RandR are missing. Use these flags
//! to remove the dependencies such that Irrlicht will compile on those systems, too.
#if defined(LINUX) && !defined(__sun__)
#define _IRR_LINUX_X11_VIDMODE_
//#define _IRR_LINUX_X11_RANDR_
#endif


//! Define _IRR_COMPILE_WITH_ZLIB_ to enable compiling the engine using zlib.
/* This enables the engine to read from compressed .zip archives. If you
disable this feature, the engine can still read archives, but only uncompressed
ones. */
#define _IRR_COMPILE_WITH_ZLIB_

//! Define _IRR_USE_NON_SYSTEM_ZLIB_ to let irrlicht use the zlib which comes with irrlicht.
/* If this is commented out, Irrlicht will try to compile using the zlib installed in the system.
 This is only used when _IRR_COMPILE_WITH_ZLIB_ is defined. */
#define _IRR_USE_NON_SYSTEM_ZLIB_


//! Define _IRR_COMPILE_WITH_JPEGLIB_ to enable compiling the engine using libjpeg.
/* This enables the engine to read jpeg images. If you comment this out,
the engine will no longer read .jpeg images. */
#define _IRR_COMPILE_WITH_LIBJPEG_

//! Define _IRR_USE_NON_SYSTEM_JPEG_LIB_ to let irrlicht use the jpeglib which comes with irrlicht.
/* If this is commented out, Irrlicht will try to compile using the jpeg lib installed in the system.
 This is only used when _IRR_COMPILE_WITH_LIBJPEG_ is defined. */
#define _IRR_USE_NON_SYSTEM_JPEG_LIB_


//! Define _IRR_COMPILE_WITH_LIBPNG_ to enable compiling the engine using libpng.
/* This enables the engine to read png images. If you comment this out,
the engine will no longer read .png images. */
#define _IRR_COMPILE_WITH_LIBPNG_

//! Define _IRR_USE_NON_SYSTEM_LIBPNG_ to let irrlicht use the libpng which comes with irrlicht.
/* If this is commented out, Irrlicht will try to compile using the libpng installed in the system.
 This is only used when _IRR_COMPILE_WITH_LIBPNG_ is defined. */
#define _IRR_USE_NON_SYSTEM_LIB_PNG_


//! Define _IRR_D3D_NO_SHADER_DEBUGGING to disable shader debugging in D3D9
/* If _IRR_D3D_NO_SHADER_DEBUGGING is undefined in IrrCompileConfig.h,
it is possible to debug all D3D9 shaders in VisualStudio. All shaders 
(which have been generated in memory or read from archives for example) will be emitted
into a temporary file at runtime for this purpose. To debug your shaders, choose  
Debug->Direct3D->StartWithDirect3DDebugging in Visual Studio, and for every shader a
file named 'irr_dbg_shader_%%.vsh' or 'irr_dbg_shader_%%.psh' will be created. Drag'n'drop
the file you want to debug into visual studio. That's it. You can now set breakpoints and
watch registers, variables etc. This works with ASM, HLSL, and both with pixel and vertex shaders.
Note that the engine will run in D3D REF for this, which is a lot slower than HAL. */
#define _IRR_D3D_NO_SHADER_DEBUGGING 


#ifdef _IRR_WINDOWS_

#ifndef _IRR_STATIC_LIB_
#ifdef IRRLICHT_EXPORTS
#define IRRLICHT_API __declspec(dllexport)
#else
#define IRRLICHT_API __declspec(dllimport)
#endif // IRRLICHT_EXPORT
#else
#define IRRLICHT_API
#endif // _IRR_STATIC_LIB_

// Declare the calling convention.
#if defined(_STDCALL_SUPPORTED)
#define IRRCALLCONV __stdcall
#else
#define IRRCALLCONV __cdecl
#endif // STDCALL_SUPPORTED

#else
#define IRRLICHT_API 
#define IRRCALLCONV
#endif // _IRR_WINDOWS_

// We need to disable DIRECT3D9 support for Visual Studio 6.0 because 
// those $%&$!! disabled support for it since Dec. 2004 and users are complaining
// about linker errors. Comment this out only if you are knowing what you are 
// doing. (Which means you have an old DX9 SDK and VisualStudio6).
#ifdef _MSC_VER
#if (_MSC_VER < 1300 && !defined(__GNUC__)) 
#undef _IRR_COMPILE_WITH_DIRECT3D_9_
#pragma message("Compiling Irrlicht with Visual Studio 6.0, support for DX9 is disabled.")
#endif
#endif

//! Define one of the three setting for Burning's Video Software Rasterizer
/* So if we were marketing guys we could says Irrlicht has 4 Software-Rasterizers.
	In a Nutshell:
		All Burnings Rasterizers use 32 Bit Backbuffer, 32Bit Texture & 32 Bit Z or WBuffer,
		16 Bit/32 Bit can be adjusted on a global flag.

		BURNINGVIDEO_RENDERER_BEAUTIFUL 
			32 Bit + Vertexcolor + Lighting + Per Pixel Perspective Correct + SubPixel/SubTexel Correct + 
			Bilinear Texturefiltering + WBuffer

		BURNINGVIDEO_RENDERER_FAST
			32 Bit + Per Pixel Perspective Correct + SubPixel/SubTexel Correct + WBuffer +
			Bilinear Dithering TextureFilterung + WBuffer

		BURNINGVIDEO_RENDERER_ULTRA_FAST
			16Bit + SubPixel/SubTexel Correct + ZBuffer
*/

#define BURNINGVIDEO_RENDERER_BEAUTIFUL
//#define BURNINGVIDEO_RENDERER_FAST
//#define BURNINGVIDEO_RENDERER_ULTRA_FAST


//! Set FPU settings
/* Irrlicht should use approximate float and integer fpu techniques
precision will be lower but speed higher. currently X86 only
*/
#if !defined(MACOSX) && !defined(__sun__)
	//#define IRRLICHT_FAST_MATH
#endif

#endif // __IRR_COMPILE_CONFIG_H_INCLUDED__
// Copyright (C) 2002-2007 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __IRR_AABBOX_3D_H_INCLUDED__
#define __IRR_AABBOX_3D_H_INCLUDED__

// Copyright (C) 2002-2007 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __IRR_MATH_H_INCLUDED__
#define __IRR_MATH_H_INCLUDED__

// Copyright (C) 2002-2007 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __IRR_TYPES_H_INCLUDED__
#define __IRR_TYPES_H_INCLUDED__


namespace irr
{

//! 8 bit unsigned variable.
/* This is a typedef for unsigned char, it ensures portability of the engine. */
typedef unsigned char		u8; 

//! 8 bit signed variable.
/* This is a typedef for signed char, it ensures portability of the engine. */
typedef signed char		s8; 

//! 8 bit character variable.
/* This is a typedef for char, it ensures portability of the engine. */
typedef char			c8; 



//! 16 bit unsigned variable.
/* This is a typedef for unsigned short, it ensures portability of the engine. */
typedef unsigned short		u16;

//! 16 bit signed variable.
/* This is a typedef for signed short, it ensures portability of the engine. */
typedef signed short		s16; 



//! 32 bit unsigned variable.
/* This is a typedef for unsigned int, it ensures portability of the engine. */
typedef unsigned int		u32;

//! 32 bit signed variable.
/* This is a typedef for signed int, it ensures portability of the engine. */
typedef signed int		s32; 



// 64 bit signed variable.
// This is a typedef for __int64, it ensures portability of the engine. 
// This type is currently not used by the engine and not supported by compilers
// other than Microsoft Compilers, so it is outcommented.
//typedef __int64				s64; 



//! 32 bit floating point variable.
/* This is a typedef for float, it ensures portability of the engine. */
typedef float				f32; 

//! 64 bit floating point variable.
/* This is a typedef for double, it ensures portability of the engine. */
typedef double				f64; 


} // end namespace irr


#include <wchar.h>
#ifdef _IRR_WINDOWS_
//! Defines for s{w,n}printf because these methods do not match the ISO C
//! standard on Windows platforms, but it does on all others.
#define swprintf _snwprintf
#define snprintf _snprintf

// define the wchar_t type if not already built in.
#ifdef _MSC_VER 
#ifndef _WCHAR_T_DEFINED
//! A 16 bit wide character type.
/**
	Defines the wchar_t-type.
	In VS6, its not possible to tell
	the standard compiler to treat wchar_t as a built-in type, and 
	sometimes we just don't want to include the huge stdlib.h or wchar.h,
	so we'll use this.
*/
typedef unsigned short wchar_t;
#define _WCHAR_T_DEFINED
#endif // wchar is not defined
#endif // microsoft compiler
#endif // _IRR_WINDOWS_

//! define a break macro for debugging.
#if defined(_DEBUG)
#if defined(_IRR_WINDOWS_) && defined(_MSC_VER)
#define _IRR_DEBUG_BREAK_IF( _CONDITION_ ) if (_CONDITION_) {_asm int 3}
#else 
#include <assert.h>
#define _IRR_DEBUG_BREAK_IF( _CONDITION_ ) assert( !(_CONDITION_) );
#endif
#else 
#define _IRR_DEBUG_BREAK_IF( _CONDITION_ )
#endif

//! Defines a small statement to work around a microsoft compiler bug.
/* The microsft compiler 7.0 - 7.1 has a bug:
When you call unmanaged code that returns a bool type value of false from managed code, 
the return value may appear as true. See 
http://support.microsoft.com/default.aspx?kbid=823071 for details. 
Compiler version defines: VC6.0 : 1200, VC7.0 : 1300, VC7.1 : 1310, VC8.0 : 1400*/
#if defined(_IRR_WINDOWS_) && defined(_MSC_VER) && (_MSC_VER > 1299) && (_MSC_VER < 1400)
#define _IRR_IMPLEMENT_MANAGED_MARSHALLING_BUGFIX __asm mov eax,100
#else
#define _IRR_IMPLEMENT_MANAGED_MARSHALLING_BUGFIX
#endif // _IRR_MANAGED_MARSHALLING_BUGFIX


#if defined(_DEBUG) && defined(IRRLICHT_EXPORTS) && defined(_MSC_VER) && 	(_MSC_VER > 1299) && !defined(_IRR_DONT_DO_MEMORY_DEBUGGING_HERE)
	
	#define CRTDBG_MAP_ALLOC
	#define _CRTDBG_MAP_ALLOC
	#define DEBUG_CLIENTBLOCK   new( _CLIENT_BLOCK, __FILE__, __LINE__)
	#include <stdlib.h>
	#include <crtdbg.h>
	#define new DEBUG_CLIENTBLOCK
#endif 

// disable truncated debug information warning in visual studio 6 by default
#if defined(_MSC_VER) && (_MSC_VER < 1300 )
#pragma warning( disable: 4786)
#endif // _MSC

//! ignore VC8 warning deprecated
/* The microsoft compiler */
#if defined(_IRR_WINDOWS_) && defined(_MSC_VER) && (_MSC_VER >= 1400)
	//#pragma warning( disable: 4996)
	//#define _CRT_SECURE_NO_DEPRECATE 1
	//#define _CRT_NONSTDC_NO_DEPRECATE 1
#endif


#endif // __IRR_TYPES_H_INCLUDED__

#include <math.h>

#ifdef __sun__
	#define sqrtf(X) sqrt(X)
	#define sinf(X) sin(X)
	#define cosf(X) cos(X)
	#define ceilf(X) ceil(X)
	#define floorf(X) floor(X)
	#define powf(X,Y) pow(X,Y)
	#define fmodf(X,Y) fmod(X,Y)
#endif

namespace irr
{
namespace core
{


	//! Rounding error constant often used when comparing f32 values.

#ifdef IRRLICHT_FAST_MATH
	const f32 ROUNDING_ERROR_32	= 0.00005f;
	const f64 ROUNDING_ERROR_64	= 0.000005f;
#else
	const f32 ROUNDING_ERROR_32	= 0.000001f;
	const f64 ROUNDING_ERROR_64	= 0.00000001f;
#endif

	//! Constant for PI.
	const f32 PI			= 3.14159265359f;

	//! Constant for 64bit PI.
	const f64 PI64			= 3.1415926535897932384626433832795028841971693993751;

	//! 32bit Constant for converting from degrees to radians
	const f32 DEGTORAD   = PI / 180.0f;

	//! 32bit constant for converting from radians to degrees
	const f32 RADTODEG   = 180.0f / PI;

	//! 64bit constant for converting from degrees to radians
	const f64 DEGTORAD64 = PI64 / 180.0;

	//! 64bit constant for converting from radians to degrees
	const f64 RADTODEG64 = 180.0 / PI64;

	//! returns minimum of two values. Own implementation to get rid of the STL (VS6 problems)
	template<class T>
	inline const T min_(const T a, const T b)
	{
		return a < b ? a : b;
	}

	//! returns maximum of two values. Own implementation to get rid of the STL (VS6 problems)
	template<class T>
	inline T max_(const T a, const T b)
	{
		return a < b ? b : a;
	}

	//! returns abs of two values. Own implementation to get rid of STL (VS6 problems)
	template<class T>
	inline T abs_(const T a)
	{
		return a < 0 ? -a : a;
	}

	//! returns linear interpolation of a and b with ratio t
	//! \return: a if t==0, b if t==1, and the linear interpolation else
	template<class T>
	inline T lerp(const T a, const T b, const T t)
	{
		return (a*(1-t)) + (b*t);
	}

	//! clamps a value between low and high
	template <class T>
	inline const T clamp (const T value, const T low, const T high) 
	{
		return min_ (max_(value,low), high);
	}

	//! returns if a float equals the other one, taking floating 
	//! point rounding errors into account
	inline bool equals(const f32 a, const f32 b, const f32 tolerance = ROUNDING_ERROR_32)
	{
		return (a + tolerance > b) && (a - tolerance < b);
	}

	//! returns if a float equals zero, taking floating 
	//! point rounding errors into account
	inline bool iszero(const f32 a, const f32 tolerance = ROUNDING_ERROR_32)
	{
		return fabs ( a ) < tolerance;
	}

	inline s32 s32_min ( s32 a, s32 b)
	{
		s32 mask = (a - b) >> 31;
		return (a & mask) | (b & ~mask);
	}

	inline s32 s32_max ( s32 a, s32 b)
	{
		s32 mask = (a - b) >> 31;
		return (b & mask) | (a & ~mask);
	}

	inline s32 s32_clamp (s32 value, s32 low, s32 high) 
	{
		return s32_min (s32_max(value,low), high);
	}

	/* 
	
		float IEEE-754 bit represenation

		0      0x00000000
		1.0    0x3f800000
		0.5    0x3f000000
		3      0x40400000
		+inf   0x7f800000
		-inf   0xff800000
		+NaN   0x7fc00000 or 0x7ff00000
		in general: number = (sign ? -1:1)  2^(exponent)  1.(mantissa bits)
	*/

	#define F32_AS_S32(f)			(*((s32 *) &(f)))
	#define F32_AS_U32(f)			(*((u32 *) &(f)))
	#define F32_AS_U32_POINTER(f)	( ((u32 *) &(f)))

	#define F32_VALUE_0			0x00000000
	#define F32_VALUE_1			0x3f800000	
	#define F32_SIGN_BIT			0x80000000U
	#define F32_EXPON_MANTISSA		0x7FFFFFFFU

	//! code is taken from IceFPU
	//! Integer representation of a floating-point value.
	#define IR(x)					((u32&)(x))

	//! Absolute integer representation of a floating-point value
	#define AIR(x)					(IR(x)&0x7fffffff)

	//! Floating-point representation of an integer value.
	#define FR(x)					((f32&)(x))

	#define IEEE_1_0			0x3f800000						//!<	integer representation of 1.0
	#define IEEE_255_0			0x437f0000						//!<	integer representation of 255.0

	
	#define	F32_LOWER_0(f)			(F32_AS_U32(f) >  F32_SIGN_BIT)
	#define	F32_LOWER_EQUAL_0(f)	(F32_AS_S32(f) <= F32_VALUE_0)
	#define	F32_GREATER_0(f)		(F32_AS_S32(f) >  F32_VALUE_0)
	#define	F32_GREATER_EQUAL_0(f)	(F32_AS_U32(f) <= F32_SIGN_BIT)
	#define	F32_EQUAL_1(f)			(F32_AS_U32(f) == F32_VALUE_1)
	#define	F32_EQUAL_0(f)			( (F32_AS_U32(f) & F32_EXPON_MANTISSA ) == F32_VALUE_0)

	// only same sign
	#define	F32_A_GREATER_B(a,b)	(F32_AS_S32((a)) >  F32_AS_S32((b)))


#ifndef REALINLINE
	#ifdef _MSC_VER
		#define REALINLINE __forceinline
	#else
		#define REALINLINE inline
	#endif
#endif


	//! conditional set based on mask and arithmetic shift
	REALINLINE u32 if_c_a_else_b ( const s32 condition, const u32 a, const u32 b )
	{
		return ( ( -condition >> 31 ) & ( a ^ b ) ) ^ b;
	}

	//! conditional set based on mask and arithmetic shift
	REALINLINE u32 if_c_a_else_0 ( const s32 condition, const u32 a )
	{
		return ( -condition >> 31 ) & a;
	}

	/*
		if (condition) state |= m; else state &= ~m; 
	*/
	REALINLINE void setbit ( u32 &state, s32 condition, u32 mask )
	{
		// 0, or any postive to mask
		//s32 conmask = -condition >> 31;
		state ^= ( ( -condition >> 31 ) ^ state ) & mask;
	}


#ifdef IRRLICHT_FAST_MATH

	REALINLINE void clearFPUException ()
	{
		__asm fnclex;
	}
		
// comes from Nvidia
#if 1
	REALINLINE f32 reciprocal_squareroot(const f32 x)
	{
		u32 tmp = (u32(IEEE_1_0 << 1) + IEEE_1_0 - *(u32*)&x) >> 1;   
		f32 y = *(f32*)&tmp;                                             
		return y * (1.47f - 0.47f * x * y * y);
	}
#endif

// an sse2 version
#if 0
	REALINLINE f32 reciprocal_squareroot(const f32 x)
	{
		__asm
		{
			movss	xmm0, x
			rsqrtss	xmm0, xmm0
			movss	x, xmm0
		}
		return x;
	}
#endif


	//! i do not divide through 0.. (fpu expection)
	// instead set f to a high value to get a return value near zero..
	// -1000000000000.f.. is use minus to stay negative..
	// must test's here (plane.normal dot anything ) checks on <= 0.f
	REALINLINE f32 reciprocal ( const f32 f )
	{
		return 1.f / f;
		//u32 x = (-(AIR(f) != 0 ) >> 31 ) & ( IR(f) ^ 0xd368d4a5 ) ^ 0xd368d4a5;
		//return 1.f / FR ( x );
	}

	REALINLINE f32 reciprocal_approxim ( const f32 p )
	{
		register u32 x = 0x7F000000 - IR ( p );
		const f32 r = FR ( x );
		return r * (2.0f - p * r);
	}


	REALINLINE s32 floor32(f32 x)
	{
		const f32 h = 0.5f;

		s32 t;

		__asm
		{
			fld   x
			fsub	h
			fistp t
		}

		return t;
	}

	REALINLINE s32 ceil32 ( f32 x )
	{
		const f32 h = 0.5f;

		s32 t;

		__asm
		{
			fld   x
			fadd	h
			fistp t
		}

		return t;

	}


	REALINLINE s32 round32(f32 x)
	{
		s32 t;

		__asm
		{
			fld   x
			fistp t
		}

		return t;
	}


#else

	REALINLINE void clearFPUException ()
	{
	}


	inline f32 reciprocal_squareroot(const f32 x)
	{
		return 1.f / sqrtf ( x );
	}


	inline f32 reciprocal ( const f32 x )
	{
		return 1.f / x;
	}

	inline f32 reciprocal_approxim ( const f32 x )
	{
		return 1.f / x;
	}


	inline s32 floor32 ( f32 x )
	{
		return (s32) floorf ( x );
	}

	inline s32 ceil32 ( f32 x )
	{
		return (s32) ceilf ( x );
	}

	inline s32 round32 ( f32 x )
	{
		return (s32) ( x + 0.5f );
	}


	inline f32 f32_max3(const f32 a, const f32 b, const f32 c)
	{
		return a > b ? (a > c ? a : c) : (b > c ? b : c);
	}

	inline f32 f32_min3(const f32 a, const f32 b, const f32 c)
	{
		return a < b ? (a < c ? a : c) : (b < c ? b : c);
	}

#endif

	inline f32 fract ( f32 x )
	{
		return x - floorf ( x );
	}

	inline f32 round ( f32 x )
	{
		return floorf ( x + 0.5f );
	}


} // end namespace core
} // end namespace irr

#endif

// Copyright (C) 2002-2007 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __IRR_PLANE_3D_H_INCLUDED__
#define __IRR_PLANE_3D_H_INCLUDED__

// Copyright (C) 2002-2007 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __IRR_POINT_3D_H_INCLUDED__
#define __IRR_POINT_3D_H_INCLUDED__


namespace irr
{
namespace core
{
	
	//! 3d vector template class with lots of operators and methods.
	template <class T>
	class vector3d  
	{
	public:

#ifdef IRRLICHT_FAST_MATH
		vector3d() {};
#else
		vector3d() : X(0), Y(0), Z(0) {};
#endif
		
		vector3d(T nx, T ny, T nz) : X(nx), Y(ny), Z(nz) {};
		vector3d(const vector3d<T>& other) : X(other.X), Y(other.Y), Z(other.Z) {};

		// operators

		vector3d<T> operator-() const { return vector3d<T>(-X, -Y, -Z);   }

		vector3d<T>& operator=(const vector3d<T>& other)	{ X = other.X; Y = other.Y; Z = other.Z; return *this; }

		vector3d<T> operator+(const vector3d<T>& other) const { return vector3d<T>(X + other.X, Y + other.Y, Z + other.Z);	}
		vector3d<T>& operator+=(const vector3d<T>& other)	{ X+=other.X; Y+=other.Y; Z+=other.Z; return *this; }

		vector3d<T> operator-(const vector3d<T>& other) const { return vector3d<T>(X - other.X, Y - other.Y, Z - other.Z);	}
		vector3d<T>& operator-=(const vector3d<T>& other)	{ X-=other.X; Y-=other.Y; Z-=other.Z; return *this; }

		vector3d<T> operator*(const vector3d<T>& other) const { return vector3d<T>(X * other.X, Y * other.Y, Z * other.Z);	}
		vector3d<T>& operator*=(const vector3d<T>& other)	{ X*=other.X; Y*=other.Y; Z*=other.Z; return *this; }
		vector3d<T> operator*(const T v) const { return vector3d<T>(X * v, Y * v, Z * v);	}
		vector3d<T>& operator*=(const T v) { X*=v; Y*=v; Z*=v; return *this; }

		vector3d<T> operator/(const vector3d<T>& other) const { return vector3d<T>(X / other.X, Y / other.Y, Z / other.Z);	}
		vector3d<T>& operator/=(const vector3d<T>& other)	{ X/=other.X; Y/=other.Y; Z/=other.Z; return *this; }
		vector3d<T> operator/(const T v) const { T i=(T)1.0/v; return vector3d<T>(X * i, Y * i, Z * i);	}
		vector3d<T>& operator/=(const T v) { T i=(T)1.0/v; X*=i; Y*=i; Z*=i; return *this; }

		bool operator<=(const vector3d<T>&other) const { return X<=other.X && Y<=other.Y && Z<=other.Z;};
		bool operator>=(const vector3d<T>&other) const { return X>=other.X && Y>=other.Y && Z>=other.Z;};
		bool operator<(const vector3d<T>&other) const { return X<other.X && Y<other.Y && Z<other.Z;};
		bool operator>(const vector3d<T>&other) const { return X>other.X && Y>other.Y && Z>other.Z;};

		//! use week float compare
		//bool operator==(const vector3d<T>& other) const { return other.X==X && other.Y==Y && other.Z==Z; }
		//bool operator!=(const vector3d<T>& other) const { return other.X!=X || other.Y!=Y || other.Z!=Z; }

		bool operator==(const vector3d<T>& other) const
		{
			return core::equals(X, other.X) &&
				   core::equals(Y, other.Y) &&
				   core::equals(Z, other.Z);
		}

		bool operator!=(const vector3d<T>& other) const
		{
			return !core::equals(X, other.X) ||
				   !core::equals(Y, other.Y) ||
				   !core::equals(Z, other.Z);
		}

		// functions

		//! returns if this vector equals the other one, taking floating point rounding errors into account
		bool equals(const vector3d<T>& other, const f32 tolerance = ROUNDING_ERROR_32 ) const
		{
			return core::equals(X, other.X, tolerance) &&
				   core::equals(Y, other.Y, tolerance) &&
				   core::equals(Z, other.Z, tolerance);
		}

		void set(const T nx, const T ny, const T nz) {X=nx; Y=ny; Z=nz; }
		void set(const vector3d<T>& p) { X=p.X; Y=p.Y; Z=p.Z;}

		//! Returns length of the vector.
		T getLength() const { return (T) sqrt(X*X + Y*Y + Z*Z); }

		//! Returns squared length of the vector.
		/* This is useful because it is much faster than
		getLength(). */
		T getLengthSQ() const { return X*X + Y*Y + Z*Z; }

		//! Returns the dot product with another vector.
		T dotProduct(const vector3d<T>& other) const
		{
			return X*other.X + Y*other.Y + Z*other.Z;
		}

		//! Returns distance from another point.
		/* Here, the vector is interpreted as point in 3 dimensional space. */
		f64 getDistanceFrom(const vector3d<T>& other) const
		{
			return vector3d<T>(X - other.X, Y - other.Y, Z - other.Z).getLength();
		}

		//! Returns squared distance from another point. 
		/* Here, the vector is interpreted as point in 3 dimensional space. */
		T getDistanceFromSQ(const vector3d<T>& other) const
		{
			return vector3d<T>(X - other.X, Y - other.Y, Z - other.Z).getLengthSQ();
		}

		//! Calculates the cross product with another vector
 		//! \param p: vector to multiply with.
 		//! \return Crossproduct of this vector with p.
		vector3d<T> crossProduct(const vector3d<T>& p) const
		{
			return vector3d<T>(Y * p.Z - Z * p.Y, Z * p.X - X * p.Z, X * p.Y - Y * p.X);
		}

		//! Returns if this vector interpreted as a point is on a line between two other points.
		/* It is assumed that the point is on the line. */
 		//! \param begin: Beginning vector to compare between.
 		//! \param end: Ending vector to compare between.
 		//! \return True if this vector is between begin and end.  False if not.
		bool isBetweenPoints(const vector3d<T>& begin, const vector3d<T>& end) const
		{
			T f = (end - begin).getLengthSQ();
			return getDistanceFromSQ(begin) < f && 
				getDistanceFromSQ(end) < f;
		}

		//! Normalizes the vector.
		//! Todo: 64 Bit template doesnt work.. need specialized template
		vector3d<T>& normalize()
		{
			T l = (T) reciprocal_squareroot ( f32(X*X + Y*Y + Z*Z) );

			X *= l;
			Y *= l;
			Z *= l;
			return *this;

/*
			T l = (T)getLength();
			if (l == 0)
				return this;

			l = (T)1.0 / l;
			X = l;
			Y = l;
			Z = l;
			return this;
*/
		}

		//! Sets the length of the vector to a new value
		void setLength(T newlength)
		{
			normalize();
			*this *= newlength;
		}

		//! Inverts the vector.
		void invert()
		{
			X *= -1.0f;
			Y *= -1.0f;
			Z *= -1.0f;
		}

		//! Rotates the vector by a specified number of degrees around the Y 
		//! axis and the specified center.
		//! \param degrees: Number of degrees to rotate around the Y axis.
		//! \param center: The center of the rotation.
		void rotateXZBy(f64 degrees, const vector3d<T>& center)
		{
			degrees *= DEGTORAD64;
			T cs = (T)cos(degrees);
			T sn = (T)sin(degrees);
			X -= center.X;
			Z -= center.Z;
			set(X*cs - Z*sn, Y, X*sn + Z*cs);
			X += center.X;
			Z += center.Z;
		}

		//! Rotates the vector by a specified number of degrees around the Z 
		//! axis and the specified center.
		//! \param degrees: Number of degrees to rotate around the Z axis.
		//! \param center: The center of the rotation.
		void rotateXYBy(f64 degrees, const vector3d<T>& center)
		{
			degrees *= DEGTORAD64;
			T cs = (T)cos(degrees);
			T sn = (T)sin(degrees);
			X -= center.X;
			Y -= center.Y;
			set(X*cs - Y*sn, X*sn + Y*cs, Z);
			X += center.X;
			Y += center.Y;
		}

		//! Rotates the vector by a specified number of degrees around the X
		//! axis and the specified center.
		//! \param degrees: Number of degrees to rotate around the X axis.
		//! \param center: The center of the rotation.
		void rotateYZBy(f64 degrees, const vector3d<T>& center)
		{
			degrees *= DEGTORAD64;
			T cs = (T)cos(degrees);
			T sn = (T)sin(degrees);
			Z -= center.Z;
			Y -= center.Y;
			set(X, Y*cs - Z*sn, Y*sn + Z*cs);
			Z += center.Z;
			Y += center.Y;
		}

		//! Returns interpolated vector.
		/* \param other: other vector to interpolate between
		\param d: value between 0.0f and 1.0f. */
		vector3d<T> getInterpolated(const vector3d<T>& other, const T d) const
		{
			const T inv = (T) 1.0 - d;
			return vector3d<T>(other.X*inv + X*d, other.Y*inv + Y*d, other.Z*inv + Z*d);
		}

		//! Returns interpolated vector. ( quadratic )
		/* \param other0: other vector to interpolate between
			\param other1: other vector to interpolate between
		\param factor: value between 0.0f and 1.0f. */
		vector3d<T> getInterpolated_quadratic(const vector3d<T>& v2, const vector3d<T>& v3, const T d) const
		{
			// this*(1-d)*(1-d) + 2 * v2 * (1-d) + v3 * d * d;
			const T inv = (T) 1.0 - d;
			const T mul0 = inv * inv;
			const T mul1 = (T) 2.0 * d * inv;
			const T mul2 = d * d;

			return vector3d<T> ( X * mul0 + v2.X * mul1 + v3.X * mul2,
								 Y * mul0 + v2.Y * mul1 + v3.Y * mul2,
								 Z * mul0 + v2.Z * mul1 + v3.Z * mul2
								);
		}

		//! Gets the Y and Z rotations of a vector.
		/* Thanks to Arras on the Irrlicht forums to add this method.
		 \return A vector representing the rotation in degrees of
		this vector. The Z component of the vector will always be 0. */
		vector3d<T> getHorizontalAngle()
		{
			vector3d<T> angle;

			angle.Y = (T)atan2(X, Z); 
			angle.Y *= (f32)RADTODEG64;
			    
			if (angle.Y < 0.0f) angle.Y += 360.0f; 
			if (angle.Y >= 360.0f) angle.Y -= 360.0f; 
			    
			f32 z1 = (f32)sqrt(X*X + Z*Z); 
			    
			angle.X = (T)atan2(z1, Y); 
			angle.X *= (f32)RADTODEG64;
			angle.X -= 90.0f; 
			    
			if (angle.X < 0.0f) angle.X += 360.0f; 
			if (angle.X >= 360.0f) angle.X -= 360.0f; 

			return angle;
		}

		//! Fills an array of 4 values with the vector data (usually floats).
		/* Useful for setting in shader constants for example. The fourth value
		 will always be 0. */
		void getAs4Values(T* array) const
		{
			array[0] = X;
			array[1] = Y;
			array[2] = Z;
			array[3] = 0;
		}


		// member variables

		T X, Y, Z;
	};


	//! Typedef for a f32 3d vector.
	typedef vector3d<f32> vector3df;
	//! Typedef for an integer 3d vector.
	typedef vector3d<s32> vector3di;

	template<class S, class T> vector3d<T> operator*(const S scalar, const vector3d<T>& vector) { return vector*scalar; }

} // end namespace core
} // end namespace irr

#endif


namespace irr
{
namespace core
{

//! Enumeration for intersection relations of 3d objects
enum EIntersectionRelation3D 
{
	ISREL3D_FRONT = 0,
	ISREL3D_BACK,
	ISREL3D_PLANAR,
	ISREL3D_SPANNING,
	ISREL3D_CLIPPED
};

//! Template plane class with some intersection testing methods.
template <class T>
class plane3d
{
	public:

		// Constructors

		plane3d(): Normal(0,1,0) { recalculateD(vector3d<T>(0,0,0)); };
		plane3d(const vector3d<T>& MPoint, const vector3d<T>& Normal) : Normal(Normal) { recalculateD(MPoint); };
		plane3d(T px, T py, T pz, T nx, T ny, T nz) : Normal(nx, ny, nz) { recalculateD(vector3d<T>(px, py, pz)); };
		plane3d(const plane3d<T>& other) : Normal(other.Normal), D(other.D) {};
		plane3d(const vector3d<T>& point1, const vector3d<T>& point2, const vector3d<T>& point3) { setPlane(point1, point2, point3); };

		// operators

		inline bool operator==(const plane3d<T>& other) const { return (D==other.D && Normal==other.Normal);};
		inline bool operator!=(const plane3d<T>& other) const { return !(D==other.D && Normal==other.Normal);};

		// functions

		void setPlane(const vector3d<T>& point, const vector3d<T>& nvector)
		{
			Normal = nvector;
			Normal.normalize();
			recalculateD(point);
		}

		void setPlane(const vector3d<T>& nvect, T d)
		{
			Normal = nvect;
			D = d;
		}

		void setPlane(const vector3d<T>& point1, const vector3d<T>& point2, const vector3d<T>& point3)
		{
			// creates the plane from 3 memberpoints
			Normal = (point2 - point1).crossProduct(point3 - point1);
			Normal.normalize();

			recalculateD(point1);
		}


		//! Returns an intersection with a 3d line.
		//! \param lineVect: Vector of the line to intersect with.
		//! \param linePoint: Point of the line to intersect with.
		//! \param outIntersection: Place to store the intersection point, if there is one.
		//! \return Returns true if there was an intersection, false if there was not.
		bool getIntersectionWithLine(const vector3d<T>& linePoint, const vector3d<T>& lineVect,
					vector3d<T>& outIntersection) const
		{
			T t2 = Normal.dotProduct(lineVect);

			if (t2 == 0)
				return false;

			T t =- (Normal.dotProduct(linePoint) + D) / t2;			
			outIntersection = linePoint + (lineVect * t);
			return true;
		}

		//! Returns where on a line between two points an intersection with this plane happened.
		//! Only useful if known that there is an intersection.
		//! \param linePoint1: Point1 of the line to intersect with.
		//! \param linePoint2: Point2 of the line to intersect with.
		//! \return Returns where on a line between two points an intersection with this plane happened.
		//! For example, 0.5 is returned if the intersection happened exectly in the middle of the two points.
		f32 getKnownIntersectionWithLine(const vector3d<T>& linePoint1,
			const vector3d<T>& linePoint2) const
		{
			vector3d<T> vect = linePoint2 - linePoint1;
			T t2 = (f32)Normal.dotProduct(vect);
			return (f32)-((Normal.dotProduct(linePoint1) + D) / t2);
		}

		//! Returns an intersection with a 3d line, limited between two 3d points.
		//! \param linePoint1: Point 1 of the line.
		//! \param linePoint2: Point 2 of the line.
		//! \param outIntersection: Place to store the intersection point, if there is one.
		//! \return Returns true if there was an intersection, false if there was not.
		bool getIntersectionWithLimitedLine(const vector3d<T>& linePoint1, 
					const vector3d<T>& linePoint2, vector3d<T>& outIntersection) const
		{
			return (	getIntersectionWithLine(linePoint1, linePoint2 - linePoint1, outIntersection) &&
						outIntersection.isBetweenPoints(linePoint1, linePoint2));
		}

		//! Classifies the relation of a point to this plane.
		//! \param point: Point to classify its relation.
		//! \return Returns ISREL3D_FRONT if the point is in front of the plane,
		//! ISREL3D_BACK if the point is behind of the plane, and
		//! ISREL3D_PLANAR if the point is within the plane.
		EIntersectionRelation3D classifyPointRelation(const vector3d<T>& point) const
		{
			const T d = Normal.dotProduct(point) + D;

			if (d < -ROUNDING_ERROR_32)
				return ISREL3D_FRONT;

			if (d > ROUNDING_ERROR_32)
				return ISREL3D_BACK;

			return ISREL3D_PLANAR;
		}

		//! Recalculates the distance from origin by applying
		//! a new member point to the plane.
		void recalculateD(const vector3d<T>& MPoint)
		{
			D = - MPoint.dotProduct(Normal);
		}

		//! Returns a member point of the plane.
		vector3d<T> getMemberPoint() const
		{
			return Normal * -D;
		}

		//! Tests if there is a intersection between this plane and another
		//! \return Returns true if there is a intersection.
		bool existsInterSection(const plane3d<T>& other) const
		{
			vector3d<T> cross = other.Normal.crossProduct(Normal);
			return cross.getLength() > core::ROUNDING_ERROR_32;
		}

		//! Intersects this plane with another.
		//! \return Returns true if there is a intersection, false if not.
		bool getIntersectionWithPlane(const plane3d<T>& other, vector3d<T>& outLinePoint,
				vector3d<T>& outLineVect) const
		{
			f64 fn00 = Normal.getLength();
			f64 fn01 = Normal.dotProduct(other.Normal);
			f64 fn11 = other.Normal.getLength();
			f64 det = fn00*fn11 - fn01*fn01;

			if (fabs(det) < ROUNDING_ERROR_64 )
				return false;

			det = 1.0 / det;
			f64 fc0 = (fn11*-D + fn01*other.D) * det;
			f64 fc1 = (fn00*-other.D + fn01*D) * det;

			outLineVect = Normal.crossProduct(other.Normal);
			outLinePoint = Normal*(T)fc0 + other.Normal*(T)fc1;
			return true;
		}

		//! Returns the intersection point with two other planes if there is one.
		bool getIntersectionWithPlanes(const plane3d<T>& o1, 
				const plane3d<T>& o2, vector3d<T>& outPoint) const
		{
			vector3d<T> linePoint, lineVect;
			if (getIntersectionWithPlane(o1, linePoint, lineVect))
				return o2.getIntersectionWithLine(linePoint, lineVect, outPoint);

			return false;
		}

		//! Returns if the plane is front of backfacing. Note that this only
		//! works if the normal is Normalized.
		//! \param lookDirection: Look direction.
		//! \return Returns true if the plane is front facing, which mean it would
		//! be visible, and false if it is backfacing.
		bool isFrontFacing(const vector3d<T>& lookDirection) const
		{
			const f32 d = Normal.dotProduct(lookDirection);
			return F32_LOWER_EQUAL_0 ( d );
		}

		//! Returns the distance to a point.  Note that this only
		//! works if the normal is Normalized.
		T getDistanceTo(const vector3d<T>& point) const
		{
			return point.dotProduct(Normal) + D;
		}
	
		// member variables
		
		vector3d<T> Normal;		// normal vector
		T D;					// distance from origin
};


//! Typedef for a f32 3d plane.
typedef plane3d<f32> plane3df;
//! Typedef for an integer 3d plane.
typedef plane3d<s32> plane3di;

} // end namespace core
} // end namespace irr

#endif

// Copyright (C) 2002-2007 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __IRR_LINE_3D_H_INCLUDED__
#define __IRR_LINE_3D_H_INCLUDED__


namespace irr
{
namespace core
{

//! 3D line between two points with intersection methods.
template <class T>
class line3d
{
	public:

		// Constructors

		line3d() : start(0,0,0), end(1,1,1) {};
		line3d(T xa, T ya, T za, T xb, T yb, T zb) : start(xa, ya, za), end(xb, yb, zb) {};
		line3d(const vector3d<T>& start, const vector3d<T>& end) : start(start), end(end) {};
		line3d(const line3d<T>& other) : start(other.start), end(other.end) {};

		// operators

		line3d<T> operator+(const vector3d<T>& point) const { return line3d<T>(start + point, end + point); };
		line3d<T>& operator+=(const vector3d<T>& point) { start += point; end += point; return *this; };

		line3d<T> operator-(const vector3d<T>& point) const { return line3d<T>(start - point, end - point); };
		line3d<T>& operator-=(const vector3d<T>& point) { start -= point; end -= point; return *this; };

		bool operator==(const line3d<T>& other) const { return (start==other.start && end==other.end) || (end==other.start && start==other.end);};
		bool operator!=(const line3d<T>& other) const { return !(start==other.start && end==other.end) || (end==other.start && start==other.end);};

		// functions

		void setLine(const T& xa, const T& ya, const T& za, const T& xb, const T& yb, const T& zb){start.set(xa, ya, za); end.set(xb, yb, zb);}
		void setLine(const vector3d<T>& nstart, const vector3d<T>& nend){start.set(nstart); end.set(nend);}
		void setLine(const line3d<T>& line){start.set(line.start); end.set(line.end);}

		//! Returns length of line
		//! \return Returns length of line.
		f64 getLength() const { return start.getDistanceFrom(end); };

		//! Returns sqared length of line
		//! \return Returns sqared length of line.
		T getLengthSQ() const { return start.getDistanceFromSQ(end); };

		//! Returns middle of line
		vector3d<T> getMiddle() const
		{
			return (start + end) * (T)0.5;
		}

		//! Returns vector of line
		vector3d<T> getVector() const
		{
			return end - start;
		}

		//! Returns if the given point is between start and end of the
		//! line. Assumes that the point is already somewhere on the line.
		bool isPointBetweenStartAndEnd(const vector3d<T>& point) const
		{
			return point.isBetweenPoints(start, end);
		}

		//! Returns the closest point on this line to a point
		vector3d<T> getClosestPoint(const vector3d<T>& point) const
		{
			vector3d<T> c = point - start;
			vector3d<T> v = end - start;
			T d = (T)v.getLength();
			v /= d;
			T t = v.dotProduct(c);

			if (t < (T)0.0) return start;
			if (t > d) return end;

			v *= t;
			return start + v;
		}

		//! Returns if the line intersects with a shpere
		//! \param sorigin: Origin of the shpere.
		//! \param sradius: Radius if the sphere.
		//! \param outdistance: The distance to the first intersection point.
		//! \return Returns true if there is an intersection.
		//! If there is one, the distance to the first intersection point
		//! is stored in outdistance.
		bool getIntersectionWithSphere(vector3d<T> sorigin, T sradius, f64& outdistance) const
		{
			vector3d<T> q = sorigin - start;
			f64 c = q.getLength();
			f64 v = q.dotProduct(getVector().normalize());
			f64 d = sradius * sradius - (c*c - v*v);

			if (d < 0.0) 
				return false;

			outdistance = v - sqrt(d);
			return true;
		}

		// member variables
		
		vector3d<T> start;
		vector3d<T> end;
};

	//! Typedef for a f32 line.
	typedef line3d<f32> line3df;
	//! Typedef for an integer line.
	typedef line3d<s32> line3di;

} // end namespace core
} // end namespace irr

#endif


namespace irr
{
namespace core
{

//! Axis aligned bounding box in 3d dimensional space.
/* Has some useful methods used with occlusion culling or clipping.
*/
template <class T>
class aabbox3d
{
	public:

		// Constructors

		aabbox3d(): MinEdge(-1,-1,-1), MaxEdge(1,1,1) {};
		aabbox3d(const aabbox3d<T>& other): MinEdge(other.MinEdge), MaxEdge(other.MaxEdge) {};
		aabbox3d(const vector3d<T>& min, const vector3d<T>& max): MinEdge(min), MaxEdge(max) {};
		aabbox3d(const vector3d<T>& init): MinEdge(init), MaxEdge(init) {};
		aabbox3d(T minx, T miny, T minz, T maxx, T maxy, T maxz): MinEdge(minx, miny, minz), MaxEdge(maxx, maxy, maxz) {};

		// operators

		inline bool operator==(const aabbox3d<T>& other) const { return (MinEdge == other.MinEdge && other.MaxEdge == MaxEdge);};
		inline bool operator!=(const aabbox3d<T>& other) const { return !(MinEdge == other.MinEdge && other.MaxEdge == MaxEdge);};

		// functions

		//! Adds a point to the bounding box, causing it to grow bigger, 
		//! if point is outside of the box
		//! \param p: Point to add into the box.
		void addInternalPoint(const vector3d<T>& p)
		{
			addInternalPoint(p.X, p.Y, p.Z);
		}

		//! Adds an other bounding box to the bounding box, causing it to grow bigger,
		//! if the box is outside of the box
		//! \param b: Other bounding box to add into this box.
		void addInternalBox(const aabbox3d<T>& b)
		{
			addInternalPoint(b.MaxEdge);
			addInternalPoint(b.MinEdge);
		}

		//! Resets the bounding box.
		void reset(T x, T y, T z)
		{
			MaxEdge.set(x,y,z);
			MinEdge = MaxEdge;
		}

		//! Resets the bounding box.
		void reset(const aabbox3d<T>& initValue)
		{
			*this = initValue;
		}

		//! Resets the bounding box.
		void reset(const vector3d<T>& initValue)
		{
			MaxEdge = initValue;
			MinEdge = initValue;
		}

		//! Adds a point to the bounding box, causing it to grow bigger, 
		//! if point is outside of the box.
		//! \param x: X Coordinate of the point to add to this box.
		//! \param y: Y Coordinate of the point to add to this box.
		//! \param z: Z Coordinate of the point to add to this box.
		void addInternalPoint(T x, T y, T z)
		{
			if (x>MaxEdge.X) MaxEdge.X = x;
			if (y>MaxEdge.Y) MaxEdge.Y = y;
			if (z>MaxEdge.Z) MaxEdge.Z = z;

			if (x<MinEdge.X) MinEdge.X = x;
			if (y<MinEdge.Y) MinEdge.Y = y;
			if (z<MinEdge.Z) MinEdge.Z = z;
		}

		//! Determinates if a point is within this box.
		//! \param p: Point to check.
		//! \return Returns true if the point is withing the box, and false if it is not.
		bool isPointInside(const vector3d<T>& p) const
		{
			return (p.X >= MinEdge.X && p.X <= MaxEdge.X &&
				p.Y >= MinEdge.Y && p.Y <= MaxEdge.Y &&
				p.Z >= MinEdge.Z && p.Z <= MaxEdge.Z);
		};

		//! Determinates if a point is within this box and its borders.
		//! \param p: Point to check.
		//! \return Returns true if the point is withing the box, and false if it is not.
		bool isPointTotalInside(const vector3d<T>& p) const
		{
			return (p.X > MinEdge.X && p.X < MaxEdge.X &&
				p.Y > MinEdge.Y && p.Y < MaxEdge.Y &&
				p.Z > MinEdge.Z && p.Z < MaxEdge.Z);
		};

		//! Determinates if the box intersects with an other box.
		//! \param other: Other box to check a intersection with.
		//! \return Returns true if there is a intersection with the other box, 
		//! otherwise false.
		bool intersectsWithBox(const aabbox3d<T>& other) const
		{
			return (MinEdge <= other.MaxEdge && MaxEdge >= other.MinEdge);
		}

		bool isFullInside(const aabbox3d<T>& other) const
		{
			return MinEdge >= other.MinEdge && MaxEdge <= other.MaxEdge;
		}

		//! Tests if the box intersects with a line
		//! \param line: Line to test intersection with.
		//! \return Returns true if there is an intersection and false if not.
		bool intersectsWithLine(const line3d<T>& line) const
		{
			return intersectsWithLine(line.getMiddle(), line.getVector().normalize(), 
					(T)(line.getLength() * 0.5));
		}

		//! Tests if the box intersects with a line
		//! \return Returns true if there is an intersection and false if not.
		bool intersectsWithLine(const vector3d<T>& linemiddle, 
					const vector3d<T>& linevect,
					T halflength) const
		{
			const vector3d<T> e = getExtent() * (T)0.5;
			const vector3d<T> t = getCenter() - linemiddle;
			T r;

			if ((fabs(t.X) > e.X + halflength * fabs(linevect.X)) || 
				(fabs(t.Y) > e.Y + halflength * fabs(linevect.Y)) ||
				(fabs(t.Z) > e.Z + halflength * fabs(linevect.Z)) )
				return false;

			r = e.Y * (T)fabs(linevect.Z) + e.Z * (T)fabs(linevect.Y);
			if (fabs(t.Y*linevect.Z - t.Z*linevect.Y) > r )
				return false;

			r = e.X * (T)fabs(linevect.Z) + e.Z * (T)fabs(linevect.X);
			if (fabs(t.Z*linevect.X - t.X*linevect.Z) > r )
				return false;

			r = e.X * (T)fabs(linevect.Y) + e.Y * (T)fabs(linevect.X);
			if (fabs(t.X*linevect.Y - t.Y*linevect.X) > r)
				return false;

			return true;
		}

		//! Classifies a relation with a plane.
		//! \param plane: Plane to classify relation to.
		//! \return Returns ISREL3D_FRONT if the box is in front of the plane,
		//! ISREL3D_BACK if the box is back of the plane, and
		//! ISREL3D_CLIPPED if is on both sides of the plane.
		EIntersectionRelation3D classifyPlaneRelation(const plane3d<T>& plane) const
		{
			vector3d<T> nearPoint(MaxEdge);
			vector3d<T> farPoint(MinEdge);

			if (plane.Normal.X > (T)0)
			{
				nearPoint.X = MinEdge.X;
				farPoint.X = MaxEdge.X;
			}

			if (plane.Normal.Y > (T)0)
			{
				nearPoint.Y = MinEdge.Y;
				farPoint.Y = MaxEdge.Y;
			}

			if (plane.Normal.Z > (T)0)
			{
				nearPoint.Z = MinEdge.Z;
				farPoint.Z = MaxEdge.Z;
			}

			if (plane.Normal.dotProduct(nearPoint) + plane.D > (T)0)
				return ISREL3D_FRONT;

			if (plane.Normal.dotProduct(farPoint) + plane.D > (T)0)
				return ISREL3D_CLIPPED;

			return ISREL3D_BACK;
		}


		//! returns center of the bounding box
		vector3d<T> getCenter() const
		{
			return (MinEdge + MaxEdge) / 2;
		}

		//! returns extend of the box
		vector3d<T> getExtent() const
		{
			return MaxEdge - MinEdge;
		}


		//! stores all 8 edges of the box into a array
		//! \param edges: Pointer to array of 8 edges
		void getEdges(vector3d<T> *edges) const
		{
			const core::vector3d<T> middle = getCenter();
			const core::vector3d<T> diag = middle - MaxEdge;

			/*
			Edges are stored in this way:
			Hey, am I an ascii artist, or what? :) niko.
                  /4--------/0
                 /  |      / |
                /   |     /  |
                6---------2  |
                |   5- - -| -1
                |  /      |  /
                |/        | /
                7---------3/ 
			*/

			edges[0].set(middle.X + diag.X, middle.Y + diag.Y, middle.Z + diag.Z);
			edges[1].set(middle.X + diag.X, middle.Y - diag.Y, middle.Z + diag.Z);
			edges[2].set(middle.X + diag.X, middle.Y + diag.Y, middle.Z - diag.Z);
			edges[3].set(middle.X + diag.X, middle.Y - diag.Y, middle.Z - diag.Z);
			edges[4].set(middle.X - diag.X, middle.Y + diag.Y, middle.Z + diag.Z);
			edges[5].set(middle.X - diag.X, middle.Y - diag.Y, middle.Z + diag.Z);
			edges[6].set(middle.X - diag.X, middle.Y + diag.Y, middle.Z - diag.Z);
			edges[7].set(middle.X - diag.X, middle.Y - diag.Y, middle.Z - diag.Z);
		}


		//! returns if the box is empty, which means that there is
		//! no space within the min and the max edge.
		bool isEmpty() const
		{
			return MinEdge.equals ( MaxEdge );
		}

		//! repairs the box, if for example MinEdge and MaxEdge are swapped.
		void repair()
		{
			T t;

			if (MinEdge.X > MaxEdge.X)
				{ t=MinEdge.X; MinEdge.X = MaxEdge.X; MaxEdge.X=t; }
			if (MinEdge.Y > MaxEdge.Y)
				{ t=MinEdge.Y; MinEdge.Y = MaxEdge.Y; MaxEdge.Y=t; }
			if (MinEdge.Z > MaxEdge.Z)
				{ t=MinEdge.Z; MinEdge.Z = MaxEdge.Z; MaxEdge.Z=t; }
		}

		//! Calculates a new interpolated bounding box.
		//! \param other: other box to interpolate between
		//! \param d: value between 0.0f and 1.0f.
		aabbox3d<T> getInterpolated(const aabbox3d<T>& other, f32 d) const
		{
			f32 inv = 1.0f - d;
			return aabbox3d<T>((other.MinEdge*inv) + (MinEdge*d),
				(other.MaxEdge*inv) + (MaxEdge*d));
		}

		// member variables
		
		vector3d<T> MinEdge;
		vector3d<T> MaxEdge;
};

	//! Typedef for a f32 3d bounding box.
	typedef aabbox3d<f32> aabbox3df;
	//! Typedef for an integer 3d bounding box.
	typedef aabbox3d<s32> aabbox3di;


} // end namespace core
} // end namespace irr

#endif

// Copyright (C) 2002-2007 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine" and the "irrXML" project.
// For conditions of distribution and use, see copyright notice in irrlicht.h and irrXML.h

#ifndef __IRR_ARRAY_H_INCLUDED__
#define __IRR_ARRAY_H_INCLUDED__

// Copyright (C) 2002-2007 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __IRR_HEAPSORT_H_INCLUDED__
#define __IRR_HEAPSORT_H_INCLUDED__


namespace irr
{
namespace core
{

//! Sinks an element into the heap.
template<class T>
inline void heapsink(T*array, s32 element, s32 max)
{
	while ((element<<1) < max)	// there is a left child
	{
		s32 j = (element<<1);
	
		if (j+1 < max && array[j] < array[j+1])
			j = j+1;							// take right child

		if (array[element] < array[j])
		{
			T t = array[j];						// swap elements
			array[j] = array[element];
			array[element] = t;
			element = j;
		}
		else
			return;
	}
}


//! Sorts an array with size 'size' using heapsort.
template<class T>
inline void heapsort(T* array_, s32 size)
{
	// for heapsink we pretent this is not c++, where
	// arrays start with index 0. So we decrease the array pointer,
	// the maximum always +2 and the element always +1

	T* virtualArray = array_ - 1;
	s32 virtualSize = size + 2;
	s32 i;

	// build heap

	for (i=((size-1)/2); i>=0; --i)	
		heapsink(virtualArray, i+1, virtualSize-1);

	// sort array

	for (i=size-1; i>=0; --i)	
	{
		T t = array_[0];
		array_[0] = array_[i];
		array_[i] = t;
		heapsink(virtualArray, 1, i + 1);
	}
}

} // end namespace core
} // end namespace irr



#endif

// Copyright (C) 2002-2007 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine" and the "irrXML" project.
// For conditions of distribution and use, see copyright notice in irrlicht.h and irrXML.h

#ifndef __IRR_ALLOCATOR_H_INCLUDED__
#define __IRR_ALLOCATOR_H_INCLUDED__

#include <new>
#include <memory.h>

namespace irr
{
namespace core
{

#ifdef DEBUG_CLIENTBLOCK
#undef DEBUG_CLIENTBLOCK
#define DEBUG_CLIENTBLOCK new
#endif

//!	Very simple allocator implementation, containers using it are able to
//! be used it across dll boundaries
template<typename T>
class irrAllocator
{
public:

	//! destructor
	virtual ~irrAllocator() {}

	//! allocate memory for an array of objects
	T* allocate(size_t cnt)
	{
		return (T*)internal_new(cnt* sizeof(T));
	}

	//! deallocate memory for an array of objects
	void deallocate(T* ptr)
	{
		internal_delete(ptr);
	}

	//! construct an element
	void construct(T* ptr, const T&e)
	{
		new ((void*)ptr) T(e);
	}

	//! destruct an element
	void destruct(T* ptr)
	{
		ptr->~T();
	}

protected:

	virtual void* internal_new(size_t cnt)
	{
		return operator new(cnt);
	}

	virtual void internal_delete(void* ptr)
	{
		operator delete(ptr);
	}

};


//! fast allocator, only to be used in containers inside the same memory heap.
/* Containers using it are NOT able to be used it across dll boundaries. Use this
when using in an internal class or function or when compiled into a static lib */
template<typename T>
class irrAllocatorFast
{
public:

	//! allocate memory for an array of objects
	T* allocate(size_t cnt)
	{
		return (T*)operator new(cnt* sizeof(T));
	}

	//! deallocate memory for an array of objects
	void deallocate(T* ptr)
	{
		operator delete(ptr);
	}

	//! construct an element
	void construct(T* ptr, const T&e)
	{
		new ((void*)ptr) T(e);
	}

	//! destruct an element
	void destruct(T* ptr)
	{
		ptr->~T();
	}
};



#ifdef DEBUG_CLIENTBLOCK
#undef DEBUG_CLIENTBLOCK
#define DEBUG_CLIENTBLOCK new( _CLIENT_BLOCK, __FILE__, __LINE__)
#endif


} // end namespace core
} // end namespace irr

#endif


namespace irr
{
namespace core
{

//!	Self reallocating template array (like stl vector) with additional features.
/* Some features are: Heap sorting, binary search methods, easier debugging.
*/
template <class T, typename TAlloc = irrAllocator<T> >
class array
{

public:

	array()
		: data(0), allocated(0), used(0),
			free_when_destroyed(true), is_sorted(true)
	{
	}

	//! Constructs a array and allocates an initial chunk of memory.
	//! \param start_count: Amount of elements to allocate.
	array(u32 start_count)
		: data(0), allocated(0), used(0),
			free_when_destroyed(true), is_sorted(true)
	{
		reallocate(start_count);
	}


	//! Copy constructor
	array(const array<T>& other)
		: data(0)
	{
		*this = other;
	}



	//! Destructor. Frees allocated memory, if set_free_when_destroyed
	//! was not set to false by the user before.
	~array()
	{
		if (free_when_destroyed)
		{
			for (u32 i=0; i<used; ++i)
				allocator.destruct(&data[i]);

			allocator.deallocate(data);
		}
	}



	//! Reallocates the array, make it bigger or smaller.
	//! \param new_size: New size of array.
	void reallocate(u32 new_size)
	{
		T* old_data = data;

		data = allocator.allocate(new_size); //new T[new_size];
		allocated = new_size;

		// copy old data
		s32 end = used < new_size ? used : new_size;
		
		for (s32 i=0; i<end; ++i)
		{
			// data[i] = old_data[i];
			allocator.construct(&data[i], old_data[i]);
		}

		// destruct old data
		for (u32 j=0; j<used; ++j)
			allocator.destruct(&old_data[j]);

		if (allocated < used)
			used = allocated;

		allocator.deallocate(old_data); //delete [] old_data;
	}

	//! Adds an element at back of array. If the array is too small to
	//! add this new element it is made bigger.
	//! \param element: Element to add at the back of the array.
	void push_back(const T& element)
	{
		if (used + 1 > allocated)
		{
			// reallocate(used * 2 +1);
			// this doesn't work if the element is in the same array. So
			// we'll copy the element first to be sure we'll get no data
			// corruption

			T e(element);
			reallocate(used * 2 +1); // increase data block

			allocator.construct(&data[used++], e); // data[used++] = e;  // push_back
		}
		else
		{
			//data[used++] = element;
			// instead of using this here, we copy it the safe way:
			allocator.construct(&data[used++], element);
		}

		is_sorted = false;
	}


	//! Adds an element at the front of the array. If the array is to small to
	//! add this new element, the array is made bigger. Please note that this
	//! is slow, because the whole array needs to be copied for this.
	//! \param element: Element to add at the back of the array.
	void push_front(const T& element)
	{
		if (used + 1 > allocated)
			reallocate(used +1);

		for (u32 i=used; i>0; --i)
		{
			//data[i] = data[i-1];
			allocator.construct(&data[i], data[i-1]);
		}

		// data[0] = element;
		allocator.construct(&data[0], element);

		is_sorted = false;
		++used;
	}


	//! Insert item into array at specified position. Please use this
	//! only if you know what you are doing (possible performance loss).
	//! The preferred method of adding elements should be push_back().
	//! \param element: Element to be inserted
	//! \param index: Where position to insert the new element.
	void insert(const T& element, u32 index=0)
	{
		_IRR_DEBUG_BREAK_IF(index>used) // access violation

		if (used + 1 > allocated)
			reallocate(used +1);

		for (u32 i=used++; i>index; --i)
			allocator.construct(&data[i], data[i-1]); // data[i] = data[i-1];

		allocator.construct(&data[index], element); // data[index] = element;
		is_sorted = false;
	}




	//! Clears the array and deletes all allocated memory.
	void clear()
	{
		for (u32 i=0; i<used; ++i)
			allocator.destruct(&data[i]);

		allocator.deallocate(data); // delete [] data;
		data = 0;
		used = 0;
		allocated = 0;
		is_sorted = true;
	}



	//! Sets pointer to new array, using this as new workspace.
	//! \param newPointer: Pointer to new array of elements.
	//! \param size: Size of the new array.
	void set_pointer(T* newPointer, u32 size)
	{
		for (u32 i=0; i<used; ++i)
			allocator.destruct(&data[i]);

		allocator.deallocate(data); // delete [] data;
		data = newPointer;
		allocated = size;
		used = size;
		is_sorted = false;
	}



	//! Sets if the array should delete the memory it used.
	//! \param f: If true, the array frees the allocated memory in its
	//! destructor, otherwise not. The default is true.
	void set_free_when_destroyed(bool f)
	{
		free_when_destroyed = f;
	}



	//! Sets the size of the array and adds some new elements if necessary.
	/* Please note: This is only secure when using it with simple types, because
	no default constructor will be called for the added new elements.
	\param usedNow: Amount of elements now used. */
	void set_used(u32 usedNow)
	{
		if (allocated < usedNow)
			reallocate(usedNow);

		used = usedNow;
	}



	//! Assignment operator
	void operator=(const array<T>& other)
	{
		if (data)
		{
			for (u32 i=0; i<used; ++i)
				allocator.destruct(&data[i]);

			allocator.deallocate(data); // delete [] data;
		}

		//if (allocated < other.allocated)
		if (other.allocated == 0)
			data = 0;
		else
			data = allocator.allocate(other.allocated); // new T[other.allocated];

		used = other.used;
		free_when_destroyed = other.free_when_destroyed;
		is_sorted = other.is_sorted;
		allocated = other.allocated;

		for (u32 i=0; i<other.used; ++i)
			allocator.construct(&data[i], other.data[i]); // data[i] = other.data[i];
	}

	// equality operator
	bool operator == (const array<T>& other) const
	{
		if (used != other.used)
			return false;

		for (u32 i=0; i<other.used; ++i)
			if (data[i] != other[i])
				return false;
		return true;
	}

	// inequality operator
	bool operator != (const array<T>& other) const
	{
		return !(*this==other);
	}

	//! Direct access operator
	T& operator [](u32 index)
	{
		_IRR_DEBUG_BREAK_IF(index>=used) // access violation

		return data[index];
	}



	//! Direct access operator
	const T& operator [](u32 index) const
	{
		_IRR_DEBUG_BREAK_IF(index>=used) // access violation

		return data[index];
	}

	//! Gets last frame
	T& getLast()
	{
		_IRR_DEBUG_BREAK_IF(!used) // access violation

		return data[used-1];
	}


	//! Gets last frame
	const T& getLast() const
	{
		_IRR_DEBUG_BREAK_IF(!used) // access violation

		return data[used-1];
	}

	//! Returns a pointer to the array.
	//! \return Pointer to the array.
	T* pointer()
	{
		return data;
	}



	//! Returns a const pointer to the array.
	//! \return Pointer to the array.
	const T* const_pointer() const
	{
		return data;
	}



	//! Returns size of used array.
	//! \return Size of elements in the array.
	u32 size() const
	{
		return used;
	}



	//! Returns amount memory allocated.
	//! \return Returns amount of memory allocated. The amount of bytes
	//! allocated would  be allocated_size() * sizeof(ElementsUsed);
	u32 allocated_size() const
	{
		return allocated;
	}



	//! Returns true if array is empty
	//! \return True if the array is empty, false if not.
	bool empty() const
	{
		return used == 0;
	}



	//! Sorts the array using heapsort. There is no additional memory waste and
	//! the algorithm performs O(n*log n) in worst case.
	void sort()
	{
		if (is_sorted || used<2)
			return;

		heapsort(data, used);
		is_sorted = true;
	}



	//! Performs a binary search for an element, returns -1 if not found.
	//! The array will be sorted before the binary search if it is not
	//! already sorted.
	//! \param element: Element to search for.
	//! \return Returns position of the searched element if it was found,
	//! otherwise -1 is returned.
	s32 binary_search(const T& element)
	{
		sort();
		return binary_search(element, 0, used-1);
	}

	//! Performs a binary search for an element, returns -1 if not found.
	//! The array must be sorted prior
	//! \param element: Element to search for.
	//! \return Returns position of the searched element if it was found,
	//! otherwise -1 is returned.
	s32 binary_search_const(const T& element) const
	{
		return binary_search(element, 0, used-1);
	}



	//! Performs a binary search for an element, returns -1 if not found.
	//! \param element: Element to search for.
	//! \param left: First left index
	//! \param right: Last right index.
	//! \return Returns position of the searched element if it was found,
	//! otherwise -1 is returned.
	s32 binary_search(const T& element, s32 left, s32 right) const
	{
		if (!used)
			return -1;

		s32 m;

		do
		{
			m = (left+right)>>1;

			if (element < data[m])
				right = m - 1;
			else
				left = m + 1;

		} while((element < data[m] || data[m] < element) && left<=right);

		// this last line equals to:
		// " while((element != array[m]) && left<=right);"
		// but we only want to use the '<' operator.
		// the same in next line, it is "(element == array[m])"

		if (!(element < data[m]) && !(data[m] < element))
			return m;

		return -1;
	}


	//! Finds an element in linear time, which is very slow. Use
	//! binary_search for faster finding. Only works if =operator is implemented.
	//! \param element: Element to search for.
	//! \return Returns position of the searched element if it was found,
	//! otherwise -1 is returned.
	s32 linear_search(const T& element) const
	{
		for (u32 i=0; i<used; ++i)
			if (!(element < data[i]) && !(data[i] < element))
				return (s32)i;

		return -1;
	}


	//! Finds an element in linear time, which is very slow. Use
	//! binary_search for faster finding. Only works if =operator is implemented.
	//! \param element: Element to search for.
	//! \return Returns position of the searched element if it was found,
	//! otherwise -1 is returned.
	s32 linear_reverse_search(const T& element) const
	{
		for (s32 i=used-1; i>=0; --i)
			if (data[i] == element)
				return i;

		return -1;
	}



	//! Erases an element from the array. May be slow, because all elements
	//! following after the erased element have to be copied.
	//! \param index: Index of element to be erased.
	void erase(u32 index)
	{
		_IRR_DEBUG_BREAK_IF(index>=used) // access violation

		for (u32 i=index+1; i<used; ++i)
		{
			allocator.destruct(&data[i-1]);
			allocator.construct(&data[i-1], data[i]); // data[i-1] = data[i];
		}

		allocator.destruct(&data[used-1]);

		--used;
	}


	//! Erases some elements from the array. may be slow, because all elements
	//! following after the erased element have to be copied.
	//! \param index: Index of the first element to be erased.
	//! \param count: Amount of elements to be erased.
	void erase(u32 index, s32 count)
	{
		_IRR_DEBUG_BREAK_IF(index>=used || count<1 || index+count>used) // access violation

		u32 i;
		for (i=index; i<index+count; ++i)
			allocator.destruct(&data[i]);

		for (i=index+count; i<used; ++i)
		{
			if (i > index+count)
				allocator.destruct(&data[i-count]);

			allocator.construct(&data[i-count], data[i]); // data[i-count] = data[i];

			if (i >= used-count)
				allocator.destruct(&data[i]);
		}

		used-= count;
	}


	//! Sets if the array is sorted
	void set_sorted(bool _is_sorted)
	{
		is_sorted = _is_sorted;
	}


	private:

		T* data;
		u32 allocated;
		u32 used;
		bool free_when_destroyed;
		bool is_sorted;
		TAlloc allocator;
};


} // end namespace core
} // end namespace irr


#endif

// Copyright 2006-2007 by Kat'Oun
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __IRR_MAP_H_INCLUDED__
#define __IRR_MAP_H_INCLUDED__


namespace irr
{
namespace core
{

//! map template for associative arrays using a red-black tree
template <class KeyType, class ValueType>
class map
{
	//! red/black tree for map
	template <class KeyTypeRB, class ValueTypeRB>
	class RBTree
	{
	public:

		RBTree(const KeyTypeRB& k, const ValueTypeRB& v)
			: mLeftChild(0), mRightChild(0), mParent(0), mKey(k),
				mValue(v), mIsRed(true) {}

		virtual ~RBTree(){}

		void setLeftChild(RBTree* p)	{ mLeftChild=p; if (p) p->setParent(this); }
		void setRightChild(RBTree* p)	{ mRightChild=p;if (p) p->setParent(this); }
		void setParent(RBTree* p)		{ mParent=p; }

		void setValue(const ValueTypeRB& v)	{ mValue = v; }

		void setRed()					{ mIsRed = true; }
		void setBlack()					{ mIsRed = false; }

		RBTree* getLeftChild() const	{ return mLeftChild; }
		RBTree* getRightChild() const	{ return mRightChild; }
		RBTree* getParent() const		{ return mParent; }

		ValueTypeRB getValue() const	
		{ 
			_IRR_IMPLEMENT_MANAGED_MARSHALLING_BUGFIX;
			return mValue; 
		}

		KeyTypeRB getKey() const		
		{ 
			_IRR_IMPLEMENT_MANAGED_MARSHALLING_BUGFIX;
			return mKey; 
		}


		bool isRoot() const				
		{ 
			_IRR_IMPLEMENT_MANAGED_MARSHALLING_BUGFIX;
			return mParent==0;
		}

		bool isLeftChild() const
		{
			_IRR_IMPLEMENT_MANAGED_MARSHALLING_BUGFIX;
			return mParent!=0 && mParent->getLeftChild()==this;
		}

		bool isRightChild() const		
		{
			_IRR_IMPLEMENT_MANAGED_MARSHALLING_BUGFIX;
			return mParent!=0 && mParent->getRightChild()==this;
		}

		bool isLeaf() const				
		{ 
			_IRR_IMPLEMENT_MANAGED_MARSHALLING_BUGFIX;
			return mLeftChild==0 && mRightChild==0;
		}

		unsigned int getLevel() const	
		{ 
			if (isRoot()) 
				return 1;
			else 
				return getParent()->getLevel() + 1;
		}


		bool isRed()	const	
		{ 
			_IRR_IMPLEMENT_MANAGED_MARSHALLING_BUGFIX;
			return  mIsRed;
		}

		bool isBlack()	const
		{ 
			_IRR_IMPLEMENT_MANAGED_MARSHALLING_BUGFIX;
			return !mIsRed;
		}

	private:
		RBTree();

		RBTree*		mLeftChild;
		RBTree*		mRightChild;

		RBTree*		mParent;

		KeyTypeRB	mKey;
		ValueTypeRB	mValue;

		bool mIsRed;
	};

	public:

	typedef RBTree<KeyType,ValueType> Node;

	//! Normal Iterator
	class Iterator
	{
	public:

		Iterator() : mRoot(0), mCur(0) {}

		// Constructor(Node*)
		Iterator(Node* root):mRoot(root)
		{
			reset();
		}

		// Copy constructor
		Iterator(const Iterator& src) : mRoot(src.mRoot), mCur(src.mCur){}

		void reset(bool atLowest=true)
		{
			if (atLowest)
				mCur = getMin(mRoot);
			else
				mCur = getMax(mRoot);
		}

		bool atEnd() const
		{
			_IRR_IMPLEMENT_MANAGED_MARSHALLING_BUGFIX;
			return mCur==0;
		}

		Node* getNode()
		{
			return mCur;
		}

		Iterator& operator=(const Iterator& src)
		{
			mRoot = src.mRoot;
			mCur = src.mCur;
			return (*this);
		}

		void operator++(int)
		{
			inc();
		}

		void operator--(int)
		{
			dec();
		}


		Node* operator -> ()
		{
			return getNode();
		}

		Node& operator* ()
		{
			if (atEnd())
				throw "Iterator at end";

			return *mCur;
		}

	private:

		Node* getMin(Node* n)
		{
			while(n && n->getLeftChild())
				n = n->getLeftChild();
			return n;
		}

		Node* getMax(Node* n)
		{
			while(n && n->getRightChild())
				n = n->getRightChild();
			return n;
		}

		void inc()
		{
			// Already at end?
			if (mCur==0)
				return;

			if (mCur->getRightChild())
			{
				// If current node has a right child, the next higher node is the
				// node with lowest key beneath the right child.
				mCur = getMin(mCur->getRightChild());
			}
			else if (mCur->isLeftChild())
			{
				// No right child? Well if current node is a left child then
				// the next higher node is the parent
				mCur = mCur->getParent();
			}
			else
			{
				// Current node neither is left child nor has a right child.
				// Ie it is either right child or root
				// The next higher node is the parent of the first non-right
				// child (ie either a left child or the root) up in the
				// hierarchy. Root's parent is 0.
				while(mCur->isRightChild())
					mCur = mCur->getParent();
				mCur = mCur->getParent();
			}
		}

		void dec()
		{
			// Already at end?
			if (mCur==0)
				return;

			if (mCur->getLeftChild())
			{
				// If current node has a left child, the next lower node is the
				// node with highest key beneath the left child.
				mCur = getMax(mCur->getLeftChild());
			}
			else if (mCur->isRightChild())
			{
				// No left child? Well if current node is a right child then
				// the next lower node is the parent
				mCur = mCur->getParent();
			}
			else
			{
				// Current node neither is right child nor has a left child.
				// Ie it is either left child or root
				// The next higher node is the parent of the first non-left
				// child (ie either a right child or the root) up in the
				// hierarchy. Root's parent is 0.

				while(mCur->isLeftChild())
					mCur = mCur->getParent();
				mCur = mCur->getParent();
			}
		}

		Node* mRoot;
		Node* mCur;
	}; // Iterator



	//! Parent First Iterator.
	//! Traverses the tree from top to bottom. Typical usage is
	//! when storing the tree structure, because when reading it
	//! later (and inserting elements) the tree structure will
	//! be the same.
	class ParentFirstIterator
	{
	public:


	ParentFirstIterator():mRoot(0),mCur(0)
	{
	}


	explicit ParentFirstIterator(Node* root):mRoot(root),mCur(0)
	{
		reset();
	}

	void reset()
	{
		mCur = mRoot;
	}


	bool atEnd() const
	{
		_IRR_IMPLEMENT_MANAGED_MARSHALLING_BUGFIX;
		return mCur==0;
	}

	Node* getNode()
	{
		return mCur;
	}


	ParentFirstIterator& operator=(const ParentFirstIterator& src)
	{
		mRoot = src.mRoot;
		mCur = src.mCur;
		return (*this);
	}


	void operator++(int)
	{
		inc();
	}


	Node* operator -> ()
	{
		return getNode();
	}

	Node& operator* ()
	{
		if (atEnd())
			throw "ParentFirstIterator at end";
		return *getNode();
	}

	private:

	void inc()
	{
		// Already at end?
		if (mCur==0)
			return;

		// First we try down to the left
		if (mCur->getLeftChild())
		{
			mCur = mCur->getLeftChild();
		}
		else if (mCur->getRightChild())
		{
			// No left child? The we go down to the right.
			mCur = mCur->getRightChild();
		}
		else
		{
			// No children? Move up in the hierarcy until
			// we either reach 0 (and are finished) or
			// find a right uncle.
			while (mCur!=0)
			{
				// But if parent is left child and has a right "uncle" the parent
				// has already been processed but the uncle hasn't. Move to
				// the uncle.
				if (mCur->isLeftChild() && mCur->getParent()->getRightChild())
				{
					mCur = mCur->getParent()->getRightChild();
					return;
				}
				mCur = mCur->getParent();
			}
		}
	}

	Node* mRoot;
	Node* mCur;

	}; // ParentFirstIterator


	//! Parent Last Iterator
	//! Traverse the tree from bottom to top.
	//! Typical usage is when deleting all elements in the tree
	//! because you must delete the children before you delete
	//! their parent.
	class ParentLastIterator
	{
	public:

		ParentLastIterator():mRoot(0),mCur(0){}

		explicit ParentLastIterator(Node* root) : mRoot(root), mCur(0)
		{
			reset();
		}

		void reset()
		{
			mCur = getMin(mRoot);
		}

		bool atEnd() const
		{
			_IRR_IMPLEMENT_MANAGED_MARSHALLING_BUGFIX;
			return mCur==0;
		}

		Node* getNode()
		{
			return mCur;
		}

		ParentLastIterator& operator=(const ParentLastIterator& src)
		{
			mRoot = src.mRoot;
			mCur = src.mCur;
			return (*this);
		}

		void operator++(int)
		{
			inc();
		}

		Node* operator -> ()
		{
			return getNode();
		}

		Node& operator* ()
		{
			if (atEnd())
				throw "ParentLastIterator at end";
			return *getNode();
		}
	private:

		Node* getMin(Node* n)
		{
			while(n!=0 && (n->getLeftChild()!=0 || n->getRightChild()!=0))
			{
				if (n->getLeftChild())
					n = n->getLeftChild();
				else
					n = n->getRightChild();
			}
			return n;
		}

		void inc()
		{
			// Already at end?
			if (mCur==0)
				return;

			// Note: Starting point is the node as far down to the left as possible.

			// If current node has an uncle to the right, go to the
			// node as far down to the left from the uncle as possible
			// else just go up a level to the parent.
			if (mCur->isLeftChild() && mCur->getParent()->getRightChild())
			{
				mCur = getMin(mCur->getParent()->getRightChild());
			}
			else
				mCur = mCur->getParent();
		}


		Node* mRoot;
		Node* mCur;
	}; // ParentLastIterator


	// AccessClass is a temporary class used with the [] operator.
	// It makes it possible to have different behavior in situations like:
	// myTree["Foo"] = 32;
	//   If "Foo" already exists, just update its value else insert a new
	//   element.
	// int i = myTree["Foo"]
	// If "Foo" exists return its value, else throw an exception.
	class AccessClass
	{
		// Let map be the only one who can instantiate this class.
		friend class map<KeyType, ValueType>;

	public:

		// Assignment operator. Handles the myTree["Foo"] = 32; situation
		void operator=(const ValueType& value)
		{
			// Just use the Set method, it handles already exist/not exist situation
			mTree.set(mKey,value);
		}

		// ValueType operator
		operator ValueType()
		{
			Node* node = mTree.find(mKey);

			// Not found
			if (node==0)
				throw "Item not found";

			_IRR_IMPLEMENT_MANAGED_MARSHALLING_BUGFIX;
			return node->getValue();
		}

	private:

		AccessClass(map& tree, const KeyType& key):mTree(tree),mKey(key){}

		AccessClass();

		map& mTree;
		const KeyType& mKey;
	}; // AccessClass


	// Constructor.
	map() : mRoot(0),mSize(0) {}

	// Destructor
	~map()
	{
		clear();
	}

	//------------------------------
	// Public Commands
	//------------------------------

	//! Inserts a new node into the tree
	//! \param keyNew: the index for this value
	//! \param v: the value to insert
	//! \return Returns true if successful,
	//! false if it fails (already exists)
	bool insert(const KeyType& keyNew, const ValueType& v)
	{
		// First insert node the "usual" way (no fancy balance logic yet)
		Node* newNode = new Node(keyNew,v);
		if (!insert(newNode))
		{
			delete newNode;
			_IRR_IMPLEMENT_MANAGED_MARSHALLING_BUGFIX;
			return false;
		}

		// Then attend a balancing party
		while (!newNode->isRoot() && (newNode->getParent()->isRed()))
		{
			if (newNode->getParent()->isLeftChild())
			{
				// If newNode is a left child, get its right 'uncle'
				Node* newNodesUncle = newNode->getParent()->getParent()->getRightChild();
				if ( newNodesUncle!=0 && newNodesUncle->isRed())
				{
					// case 1 - change the colours
					newNode->getParent()->setBlack();
					newNodesUncle->setBlack();
					newNode->getParent()->getParent()->setRed();
					// Move newNode up the tree
					newNode = newNode->getParent()->getParent();
				}
				else
				{
					// newNodesUncle is a black node
					if ( newNode->isRightChild())
					{
						// and newNode is to the right
						// case 2 - move newNode up and rotate
						newNode = newNode->getParent();
						rotateLeft(newNode);
					}
					// case 3
					newNode->getParent()->setBlack();
					newNode->getParent()->getParent()->setRed();
					rotateRight(newNode->getParent()->getParent());
				}
			}
			else
			{
				// If newNode is a right child, get its left 'uncle'
				Node* newNodesUncle = newNode->getParent()->getParent()->getLeftChild();
				if ( newNodesUncle!=0 && newNodesUncle->isRed())
				{
					// case 1 - change the colours
					newNode->getParent()->setBlack();
					newNodesUncle->setBlack();
					newNode->getParent()->getParent()->setRed();
					// Move newNode up the tree
					newNode = newNode->getParent()->getParent();
				}
				else
				{
					// newNodesUncle is a black node
					if (newNode->isLeftChild())
					{
						// and newNode is to the left
						// case 2 - move newNode up and rotate
						newNode = newNode->getParent();
						rotateRight(newNode);
					}
					// case 3
					newNode->getParent()->setBlack();
					newNode->getParent()->getParent()->setRed();
					rotateLeft(newNode->getParent()->getParent());
				}

			}
		}
		// Color the root black
		mRoot->setBlack();
		return true;
	}

	//! Replaces the value if the key already exists,
	//! otherwise inserts a new element.
	//! \param key: the index for this value
	//! \param v: the new value of
	void set(const KeyType& k, const ValueType& v)
	{
		Node* p = find(k);
		if (p)
			p->setValue(v);
		else
			insert(k,v);
	}

	//! Removes a node from the tree and returns it.
	//! The returned node must be deleted by the user
	//! \param k: the key to remove
	//! \return: A pointer to the node, or 0 if not found
	Node* delink(const KeyType& k)
	{
		Node* p = Find(k);
		if (p == 0)
			return 0;

		// Rotate p down to the left until it has no right child, will get there
		// sooner or later.
		while(p->getRightChild())
		{
			// "Pull up my right child and let it knock me down to the left"
			rotateLeft(p);
		}
		// p now has no right child but might have a left child
		Node* left = p->getLeftChild();

		// Let p's parent point to p's child instead of point to p
		if (p->isLeftChild())
			p->getParent()->setLeftChild(left);

		else if (p->isRightChild())
			p->getParent()->setRightChild(left);

		else
		{
			// p has no parent => p is the root.
			// Let the left child be the new root.
			setRoot(left);
		}

		// p is now gone from the tree in the sense that
		// no one is pointing at it, so return it.

		mSize--;
		return p;
	}

	//! Removes a node from the tree and deletes it.
	//! \return True if the node was found and deleted
	bool remove(const KeyType& k)
	{
		Node* p = find(k);
		if (p == 0)
		{
			_IRR_IMPLEMENT_MANAGED_MARSHALLING_BUGFIX;
			return false;
		}

		// Rotate p down to the left until it has no right child, will get there
		// sooner or later.
		while(p->getRightChild())
		{
			// "Pull up my right child and let it knock me down to the left"
			rotateLeft(p);
		}
		// p now has no right child but might have a left child
		Node* left = p->getLeftChild();

		// Let p's parent point to p's child instead of point to p
		if (p->isLeftChild())
			p->getParent()->setLeftChild(left);

		else if (p->isRightChild())
			p->getParent()->setRightChild(left);

		else
		{
			// p has no parent => p is the root.
			// Let the left child be the new root.
			setRoot(left);
		}

		// p is now gone from the tree in the sense that
		// no one is pointing at it. Let's get rid of it.
		delete p;

		mSize--;
		return true;
	}

	//! Clear the entire tree
	void clear()
	{
		ParentLastIterator i(getParentLastIterator());

		while(!i.atEnd())
		{
			Node* p = i.getNode();
			i++; // Increment it before it is deleted
				// else iterator will get quite confused.
			delete p;
		}
		mRoot = 0;
		mSize= 0;
	}

	//! Is the tree empty?
	//! \return Returns true if empty, false if not
	bool isEmpty() const
	{
		_IRR_IMPLEMENT_MANAGED_MARSHALLING_BUGFIX;
		return mRoot == 0;
	}

	//! Search for a node with the specified key.
	//! \param keyToFind: The key to find
	//! \return Returns 0 if node couldn't be found.
	Node* find(const KeyType& keyToFind) const
	{
		Node* pNode = mRoot;

		while(pNode!=0)
		{
			KeyType key(pNode->getKey());

			if (keyToFind == key)
				return pNode;
			else if (keyToFind < key)
				pNode = pNode->getLeftChild();
			else //keyToFind > key
				pNode = pNode->getRightChild();
		}

		return 0;
	}

	//! Gets the root element.
	//! \return Returns a pointer to the root node, or
	//! 0 if the tree is empty.
	Node* getRoot() const
	{
		return mRoot;
	}

	//! Returns the number of nodes in the tree.
	u32 size() const
	{
		return mSize;
	}

	//------------------------------
	// Public Iterators
	//------------------------------

	//! Returns an iterator
	Iterator getIterator()
	{
		Iterator it(getRoot());
		return it;
	}
	//! Returns a ParentFirstIterator.
	//! Traverses the tree from top to bottom. Typical usage is
	//! when storing the tree structure, because when reading it
	//! later (and inserting elements) the tree structure will
	//! be the same.
	ParentFirstIterator getParentFirstIterator()
	{
		ParentFirstIterator it(getRoot());
		return it;
	}
	//! Returns a ParentLastIterator to traverse the tree from
	//! bottom to top.
	//! Typical usage is when deleting all elements in the tree
	//! because you must delete the children before you delete
	//! their parent.
	ParentLastIterator getParentLastIterator()
	{
		ParentLastIterator it(getRoot());
		return it;
	}

	//------------------------------
	// Public Operators
	//------------------------------

	//! operator [] for accesss to elements
	//! for example myMap["key"]
	AccessClass operator[](const KeyType& k)
	{
		return AccessClass(*this, k);
	}
	private:

	//------------------------------
	// Disabled methods
	//------------------------------
	//! Copy constructor and assignment operator deliberately
	//! defined but not implemented. The tree should never be
	//! copied, pass along references to it instead (or use auto_ptr to it).
	explicit map(const map& src);
	map& operator = (const map& src);

	void setRoot(Node* newRoot)
	{
		mRoot = newRoot;
		if (mRoot!=0)
			mRoot->setParent(0);
	}

	//! Insert a node into the tree without using any fancy balancing logic.
	//! Returns false if that key already exist in the tree.
	bool insert(Node* newNode)
	{
		bool result=true; // Assume success

		if (mRoot==0)
		{
			setRoot(newNode);
			mSize = 1;
		}
		else
		{
			Node* pNode = mRoot;
			KeyType keyNew = newNode->getKey();
			while (pNode)
			{
				KeyType key(pNode->getKey());

				if (keyNew == key)
				{
					result = false;
					pNode = 0;
				}
				else if (keyNew < key)
				{
					if (pNode->getLeftChild() == 0)
					{
						pNode->setLeftChild(newNode);
						pNode = 0;
					}
					else
						pNode = pNode->getLeftChild();
				}
				else // keyNew > key
				{
					if (pNode->getRightChild()==0)
					{
						pNode->setRightChild(newNode);
						pNode = 0;
					}
					else
					{
						pNode = pNode->getRightChild();
					}
				}
			}

			if (result)
				mSize++;
		}

		_IRR_IMPLEMENT_MANAGED_MARSHALLING_BUGFIX;
		return result;
	}

	//! Rotate left.
	//! Pull up node's right child and let it knock node down to the left
	void rotateLeft(Node* p)
	{
		Node* right = p->getRightChild();

		p->setRightChild(right->getLeftChild());

		if (p->isLeftChild())
			p->getParent()->setLeftChild(right);
		else if (p->isRightChild())
			p->getParent()->setRightChild(right);
		else
			setRoot(right);

		right->setLeftChild(p);
	}

	//! Rotate right.
	//! Pull up node's left child and let it knock node down to the right
	void rotateRight(Node* p)
	{

		Node* left = p->getLeftChild();

		p->setLeftChild(left->getRightChild());

		if (p->isLeftChild())
			p->getParent()->setLeftChild(left);
		else if (p->isRightChild())
			p->getParent()->setRightChild(left);
		else
			setRoot(left);

		left->setRightChild(p);
	}

	//------------------------------
	// Private Members
	//------------------------------
	Node* mRoot; // The top node. 0 if empty.
	u32 mSize; // Number of nodes in the tree

};

} // end namespace core
} // end namespace irr

#endif // __IRR_MAP_H_INCLUDED__

// Copyright (C) 2002-2007 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __COLOR_H_INCLUDED__
#define __COLOR_H_INCLUDED__


namespace irr
{
namespace video
{
	//! Creates a 16 bit A1R5G5B5 color
	inline u16 RGBA16(u32 r, u32 g, u32 b, u32 a)
	{
		return ((a & 0x80) << 8 |
			(r & 0xF8) << 7 |
			(g & 0xF8) << 2 |
			(b & 0xF8) >> 3);
	}


	//! Creates a 16 bit A1R5G5B5 color
	inline u16 RGB16(u32 r, u32 g, u32 b)
	{
		return RGBA16(r,g,b,0xFF);
	}


	//! Creates a 16 bit A1R5G5B5 color, based on 16 bit input values
	inline u16 RGB16from16(u16 r, u16 g, u16 b)
	{
		return (r & 0x1F) << 10 |
			   (g & 0x1F) << 5  |
			   (b & 0x1F);
	}


	//! Converts a 32 bit (X8R8G8B8) color to a 16 A1R5G5B5 color
	inline u16 X8R8G8B8toA1R5G5B5(u32 color)
	{
		return (	0x8000 |
			( color & 0x00F80000) >> 9 |
			( color & 0x0000F800) >> 6 |
			( color & 0x000000F8) >> 3);
	}


	//! Converts a 32 bit (A8R8G8B8) color to a 16 A1R5G5B5 color
	inline u16 A8R8G8B8toA1R5G5B5(u32 color)
	{
		return (( color & 0x80000000) >> 16|
			( color & 0x00F80000) >> 9 |
			( color & 0x0000F800) >> 6 |
			( color & 0x000000F8) >> 3);
	}


	//! Returns A8R8G8B8 Color from A1R5G5B5 color
	//! build a nicer 32 Bit Color by extending dest lower bits with source high bits
	inline u32 A1R5G5B5toA8R8G8B8(u32 color)
	{
		return	( (( -( (s32) color & 0x00008000 ) >> (s32) 31 ) & 0xFF000000 ) |
				(( color & 0x00007C00 ) << 9) | (( color & 0x00007000 ) << 4) |
				(( color & 0x000003E0 ) << 6) | (( color & 0x00000380 ) << 1) |
				(( color & 0x0000001F ) << 3) | (( color & 0x0000001C ) >> 2) 
				);
	}


	//! Returns A8R8G8B8 Color from R5G6B5 color
	inline u32 R5G6B5toA8R8G8B8(u16 color)
	{
		return 0xFF000000 |
			((color & 0xF800) << 8)|
			((color & 0x07E0) << 5)|
			((color & 0x001F) << 3);
	}


	//! Returns A1R5G5B5 Color from R5G6B5 color
	inline u16 R5G6B5toA1R5G5B5(u16 color)
	{
		return 0x8000 | (((color & 0xFFC0) >> 1) | (color & 0x1F));
	}


	//! Returns R5G6B5 Color from A1R5G5B5 color
	inline u16 A1R5G5B5toR5G6B5(u16 color)
	{
		return (((color & 0x7FE0) << 1) | (color & 0x1F));
	}



	//! Returns the alpha component from A1R5G5B5 color
	inline u32 getAlpha(u16 color)
	{
		return ((color >> 15)&0x1);
	}


	//! Returns the red component from A1R5G5B5 color.
	//! Shift left by 3 to get 8 bit value.
	inline u32 getRed(u16 color)
	{
		return ((color >> 10)&0x1F);
	}


	//! Returns the green component from A1R5G5B5 color
	//! Shift left by 3 to get 8 bit value.
	inline u32 getGreen(u16 color)
	{
		return ((color >> 5)&0x1F);
	}


	//! Returns the blue component from A1R5G5B5 color
	//! Shift left by 3 to get 8 bit value.
	inline u32 getBlue(u16 color)
	{
		return (color & 0x1F);
	}

		//! Returns the red component from A1R5G5B5 color.
	//! Shift left by 3 to get 8 bit value.
	inline s32 getRedSigned(u16 color)
	{
		return ((color >> 10)&0x1F);
	}


	//! Returns the green component from A1R5G5B5 color
	//! Shift left by 3 to get 8 bit value.
	inline s32 getGreenSigned(u16 color)
	{
		return ((color >> 5)&0x1F);
	}


	//! Returns the blue component from A1R5G5B5 color
	//! Shift left by 3 to get 8 bit value.
	inline s32 getBlueSigned(u16 color)
	{
		return (color & 0x1F);
	}

	//! Returns the average from a 16 bit A1R5G5B5 color
	inline s32 getAverage(s16 color)
	{
		return ((getRed(color)<<3) + (getGreen(color)<<3) + (getBlue(color)<<3)) / 3;
	}



	//! Class representing a 32 bit ARGB color.
	/* The color values for alpha, red, green, and blue are
	stored in a single s32. So all four values may be between 0 and 255.
	This class is used by most parts of the Irrlicht Engine
	to specify a color. Another way is using the class Colorf, which
	stores the color values in 4 floats.
	*/
	class SColor
	{
	public:

		//! Constructor of the Color. Does nothing. The color value
		//! is not initialized to save time.
		inline SColor() {}

		//! Constructs the color from 4 values representing the alpha, red, green and
		//! blue components of the color. Must be values between 0 and 255.
		inline SColor (u32 a, u32 r, u32 g, u32 b)
			: color(((a & 0xff)<<24) | ((r & 0xff)<<16) | ((g & 0xff)<<8) | (b & 0xff))	{}

		//! Constructs the color from a 32 bit value. Could be another color.
		inline SColor(u32 clr)
			: color(clr) {}

		//! Returns the alpha component of the color. The alpha component
		//! defines how transparent a color should be.
		//! 0 means not transparent (opaque), 255 means fully transparent.
		inline u32 getAlpha() const { return color>>24; }

		//! Returns the red component of the color.
		//! \return Returns a value between 0 and 255, specifying how red the color is.
		//! 0 means no red, 255 means full red.
		inline u32 getRed() const { return (color>>16) & 0xff; }

		//! Returns the green component of the color.
		//! \return Returns a value between 0 and 255, specifying how green the color is.
		//! 0 means no green, 255 means full green.
		inline u32 getGreen() const { return (color>>8) & 0xff; }

		//! Returns the blue component of the color.
		//! \return Returns a value between 0 and 255, specifying how blue the color is.
		//! 0 means no blue, 255 means full blue.
		inline u32 getBlue() const { return color & 0xff; }

		//! Returns the luminance of the color.
		inline f32 getLuminance() const
		{
			return 0.3f*getRed() + 0.59f*getGreen() + 0.11f*getBlue();
		}

		//! Returns the average intensity of the color.
		inline u32 getAverage() const
		{
			return ( getRed() + getGreen() + getBlue() ) / 3;
		}

		//! Sets the alpha component of the Color. The alpha component
		//! defines how transparent a color should be.
		//! \param a: Has to be a value between 0 and 255.
		//! 0 means not transparent (opaque), 255 means fully transparent.
		inline void setAlpha(u32 a) { color = ((a & 0xff)<<24) | (color & 0x00ffffff); }

		//! Sets the red component of the Color.
		//! \param r: Has to be a value between 0 and 255.
		//! 0 means no red (=black), 255 means full red.
		inline void setRed(u32 r) { color = ((r & 0xff)<<16) | (color & 0xff00ffff); }

		//! Sets the green component of the Color.
		//! \param g: Has to be a value between 0 and 255.
		//! 0 means no green (=black), 255 means full green.
		inline void setGreen(u32 g) { color = ((g & 0xff)<<8) | (color & 0xffff00ff); }

		//! Sets the blue component of the Color.
		//! \param b: Has to be a value between 0 and 255.
		//! 0 means no blue (=black), 255 means full blue.
		inline void setBlue(u32 b) { color = (b & 0xff) | (color & 0xffffff00); }

		//! Calculates a 16 bit A1R5G5B5 value of this color.
		//! \return Returns the 16 bit A1R5G5B5 value of this color.
		inline u16 toA1R5G5B5() const { return A8R8G8B8toA1R5G5B5(color); };

		//! Converts color to OpenGL color format,
		//! from ARGB to RGBA in 4 byte components for endian aware
		//! passing to OpenGL
		//! \param dest: address where the 4x8 bit OpenGL color is stored.
		inline void toOpenGLColor(u8* dest) const
		{
			*dest =   getRed();
			*++dest = getGreen();
			*++dest = getBlue();
			*++dest = getAlpha();
		};

		//! Sets all four components of the color at once.
		//! Constructs the color from 4 values representing the alpha, red, green and
		//! blue components of the color. Must be values between 0 and 255.
		//! \param a: Alpha component of the color.
		//! The alpha component defines how transparent a color should be.
		//! Has to be a value between 0 and 255.
		//! 0 means not transparent (opaque), 255 means fully transparent.
		//! \param r: Sets the red component of the Color.
		//! Has to be a value between 0 and 255.
		//! 0 means no red (=black), 255 means full red.
		//! \param g: Sets the green component of the Color.
		//! Has to be a value between 0 and 255.
		//! 0 means no green (=black), 255 means full green.
		//! \param b: Sets the blue component of the Color.
		//! Has to be a value between 0 and 255.
		//! 0 means no blue (=black), 255 means full blue.
		inline void set(u32 a, u32 r, u32 g, u32 b) { color = (((a & 0xff)<<24) | ((r & 0xff)<<16) | ((g & 0xff)<<8) | (b & 0xff)); }
		inline void set(u32 col) { color = col; }

		//! Compares the color to another color.
		//! \return Returns true if the colors are the same, and false if not.
		inline bool operator==(const SColor& other) const { return other.color == color; }

		//! Compares the color to another color.
		//! \return Returns true if the colors are different, and false if they are the same.
		inline bool operator!=(const SColor& other) const { return other.color != color; }

		//! Interpolates the color with a f32 value to another color
		//! \param other: Other color
		//! \param d: value between 0.0f and 1.0f
		//! \return Returns interpolated color.
		inline SColor getInterpolated(const SColor &other, f32 d) const
		{
			const f32 inv = 1.0f - d;
			return SColor((u32)(other.getAlpha()*inv + getAlpha()*d),
				(u32)(other.getRed()*inv + getRed()*d),
				(u32)(other.getGreen()*inv + getGreen()*d),
				(u32)(other.getBlue()*inv + getBlue()*d));
		}

		//! Returns interpolated color. ( quadratic )
		/* \param other0: other vector to interpolate between
			\param other1: other vector to interpolate between
		\param factor: value between 0.0f and 1.0f. */
		inline SColor getInterpolated_quadratic(const SColor& v2, const SColor& v3, const f32 d) const
		{
			// this*(1-d)*(1-d) + 2 * v2 * (1-d) + v3 * d * d;
			const f32 inv = 1.f - d;
			const f32 mul0 = inv * inv;
			const f32 mul1 = 2.f * d * inv;
			const f32 mul2 = d * d;

			return SColor ( core::clamp ( core::floor32 ( getAlpha() * mul0 + v2.getAlpha() * mul1 + v3.getAlpha() * mul2 ), 0, 255 ),
							core::clamp ( core::floor32 ( getRed()   * mul0 + v2.getRed()   * mul1 + v3.getRed()   * mul2 ), 0, 255 ),
							core::clamp ( core::floor32 ( getGreen() * mul0 + v2.getGreen() * mul1 + v3.getGreen() * mul2 ), 0, 255 ),
							core::clamp ( core::floor32 ( getBlue()  * mul0 + v2.getBlue()  * mul1 + v3.getBlue()  * mul2 ), 0, 255 )
						);
		}


		//! color in A8R8G8B8 Format
		u32 color;
	};


	//! Class representing a color with four floats.
	/*	The color values for red, green, blue
	and alpha are each stored in a 32 bit floating point variable.
	So all four values may be between 0.0f and 1.0f.
	This class is rarely used by the Irrlicht Engine
	to specify a color. Another, faster way is using the class Color, which
	stores the color values in a single 32 bit integer.
	*/
	class SColorf
	{
	public:

		//! Constructs a color. All values are initialised with 0.0f, resulting
		//! in a black color.
		SColorf() : r(0.0f), g(0.0f), b(0.0f), a(0.0f) {};

		//! Constructs a color from three color values: red, green and blue.
		//! \param r: Red color component. Should be a value between 0.0f meaning
		//! no red (=black) and 1.0f, meaning full red.
		//! \param g: Green color component. Should be a value between 0.0f meaning
		//! no green (=black) and 1.0f, meaning full green.
		//! \param b: Blue color component. Should be a value between 0.0f meaning
		//! no blue (=black) and 1.0f, meaning full blue.
		SColorf(f32 r, f32 g, f32 b) : r(r), g(g), b(b), a(1.0f) {};

		//! Constructs a color from four color values: alpha, red, green and blue.
		//! \param a: Alpha color component of the color.
		//! The alpha component defines how transparent a color should be.
		//! Has to be a value between 0.0f and 1.0f,
		//! 0.0f means not transparent (opaque), 1.0f means fully transparent.
		//! \param r: Red color component. Should be a value between 0.0f meaning
		//! no red (=black) and 1.0f, meaning full red.
		//! \param g: Green color component. Should be a value between 0.0f meaning
		//! no green (=black) and 1.0f, meaning full green.
		//! \param b: Blue color component. Should be a value between 0.0f meaning
		//! no blue (=black) and 1.0f, meaning full blue.
		SColorf(f32 r, f32 g, f32 b, f32 a) : r(r), g(g), b(b), a(a) {};

		//! Constructs a color from 32 bit Color.
		//! \param c: 32 bit color value from which this Colorf class is
		//! constructed from.
		SColorf(SColor c) { const f32 inv = 1.0f / 255.0f; r = c.getRed() * inv; g = c.getGreen() * inv; b = c.getBlue() * inv;	a = c.getAlpha() * inv;	};

		//! Converts this color to a SColor without floats.
		SColor toSColor() const
		{
			return SColor((s32)(a*255.0f), (s32)(r*255.0f), (s32)(g*255.0f), (s32)(b*255.0f));
		}

		//! red color component
		f32 r;

		//! green color component
		f32 g;

		//! blue component
		f32 b;

		//! alpha color component
		f32 a;

		//! Sets three color components to new values at once.
		//! \param rr: Red color component. Should be a value between 0.0f meaning
		//! no red (=black) and 1.0f, meaning full red.
		//! \param gg: Green color component. Should be a value between 0.0f meaning
		//! no green (=black) and 1.0f, meaning full green.
		//! \param bb: Blue color component. Should be a value between 0.0f meaning
		//! no blue (=black) and 1.0f, meaning full blue.
		void set(f32 rr, f32 gg, f32 bb) {r = rr; g =gg; b = bb; };

		//! Sets all four color components to new values at once.
		//! \param a: Alpha component.
		//! \param rr: Red color component. Should be a value between 0.0f meaning
		//! no red (=black) and 1.0f, meaning full red.
		//! \param gg: Green color component. Should be a value between 0.0f meaning
		//! no green (=black) and 1.0f, meaning full green.
		//! \param bb: Blue color component. Should be a value between 0.0f meaning
		//! no blue (=black) and 1.0f, meaning full blue.
		void set(f32 aa, f32 rr, f32 gg, f32 bb) {a = aa; r = rr; g =gg; b = bb; };

		//! Interpolates the color with a f32 value to another color
		//! \param other: Other color
		//! \param d: value between 0.0f and 1.0f
		//! \return Returns interpolated color.
		inline SColorf getInterpolated(const SColorf &other, f32 d) const
		{
			const f32 inv = 1.0f - d;
			return SColorf(other.r*inv + r*d,
				other.g*inv + g*d, other.b*inv + b*d, other.a*inv + a*d);
		}

		//! Returns interpolated color. ( quadratic )
		/* \param other0: other vector to interpolate between
			\param other1: other vector to interpolate between
		\param factor: value between 0.0f and 1.0f. */
		inline SColorf getInterpolated_quadratic(const SColorf& v2, const SColorf& v3, const f32 d) const
		{
			// this*(1-d)*(1-d) + 2 * v2 * (1-d) + v3 * d * d;
			const f32 inv = 1.f - d;
			const f32 mul0 = inv * inv;
			const f32 mul1 = 2.f * d * inv;
			const f32 mul2 = d * d;

			return SColorf ( r * mul0 + v2.r * mul1 + v3.r * mul2,
							 g * mul0 + v2.g * mul1 + v3.g * mul2,
							 g * mul0 + v2.b * mul1 + v3.b * mul2,
							 a * mul0 + v2.a * mul1 + v3.a * mul2
							);
		}



		//! Sets a color component by index. R=0, G=1, B=2, A=3
		inline void setColorComponentValue(s32 index, f32 value)
		{
			switch(index)
			{
			case 0: r = value; break;
			case 1: g = value; break;
			case 2: b = value; break;
			case 3: a = value; break;
			}
		}
	};

	//! Class representing a color in HSV format
	/*	The color values for hue, saturation, value
	are stored in a 32 bit floating point variable.
	*/
	class SColorHSL
	{
	public:
		SColorHSL ( f32 h = 0.f, f32 s = 0.f, f32 l = 0.f )
			: Hue ( h ), Saturation ( s ), Luminance ( l ) {}

		void setfromRGB ( const SColor &color );
		void settoRGB ( SColor &color ) const;

		f32 Hue;
		f32 Saturation;
		f32 Luminance;

		private:
			inline u32 toRGB1(f32 rm1, f32 rm2, f32 rh) const;

	};

	inline void SColorHSL::settoRGB ( SColor &color ) const
	{
		if ( Saturation == 0.0f) // grey
		{
			u8 c = (u8) ( Luminance * 255.0 );
			color.setRed ( c );
			color.setGreen ( c );
			color.setBlue ( c );
			return;
		}

		f32 rm1, rm2;
			
		if ( Luminance <= 0.5f )
		{
			rm2 = Luminance + Luminance * Saturation;  
		}
		else
		{
			rm2 = Luminance + Saturation - Luminance * Saturation;
		}

		rm1 = 2.0f * Luminance - rm2;   

		color.setRed ( toRGB1(rm1, rm2, Hue + (120.0f * core::DEGTORAD )) );
		color.setGreen ( toRGB1(rm1, rm2, Hue) );
		color.setBlue ( toRGB1(rm1, rm2, Hue - (120.0f * core::DEGTORAD) ) );
	}


	inline u32 SColorHSL::toRGB1(f32 rm1, f32 rm2, f32 rh) const
	{
		while ( rh > 2.f * core::PI )
			rh -= 2.f * core::PI;

		while ( rh < 0.f )
			rh += 2.f * core::PI;

		if      (rh <  60.0f * core::DEGTORAD ) rm1 = rm1 + (rm2 - rm1) * rh / (60.0f * core::DEGTORAD);
		else if (rh < 180.0f * core::DEGTORAD ) rm1 = rm2;
		else if (rh < 240.0f * core::DEGTORAD ) rm1 = rm1 + (rm2 - rm1) * ( ( 240.0f * core::DEGTORAD ) - rh) / (60.0f * core::DEGTORAD);
		                
		return (u32) (rm1 * 255.f);
	}

} // end namespace video
} // end namespace irr

#endif

// Copyright (C) 2002-2007 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __S_LIGHT_H_INCLUDED__
#define __S_LIGHT_H_INCLUDED__


namespace irr
{
namespace video
{

//! Enumeration for different types of lights
enum E_LIGHT_TYPE
{
	//! point light, it has a position in space and radiates light in all directions
	ELT_POINT,

	//! directional light, coming from a direction from an infinite distance
	ELT_DIRECTIONAL
};

//! Names for light types
const c8* const LightTypeNames[] =
{
	"Point",
	"Directional",
	0
};

//! structure for holding data describing a dynamic point light.
/* ambient light and point lights are the only light supported 
by the irrlicht engine.
*/
struct SLight
{
	SLight() : AmbientColor(0.0f,0.0f,0.0f), DiffuseColor(1.0f, 1.0f, 1.0f), 
		SpecularColor(1.0f,1.0f,1.0f), Position(0.0f, 0.0f, 0.0f), Radius(100.0f),
		CastShadows(true), Type(ELT_POINT)
		 {};

	//! Ambient color emitted by the light
	SColorf AmbientColor;

	//! Diffuse color emitted by the light.
	/* This is the primary color you might want to set. */
	SColorf DiffuseColor; 

	//! Specular color emitted by the light. 
	/* For details how to use specular highlights, see SMaterial::Shininess */
	SColorf SpecularColor;

	//! Position of the light. If Type is ELT_DIRECTIONAL, this is the direction vector the light is coming from.
	core::vector3df Position;

	//! Radius of light. Everything within this radius be be lighted.
	f32 Radius;

	//! Does the light cast shadows?
	bool CastShadows;

	//! Type of the light. Default: ELT_POINT
	E_LIGHT_TYPE Type;
};

} // end namespace video
} // end namespace irr

#endif

// Copyright (C) 2002-2007 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __IRR_DIMENSION2D_H_INCLUDED__
#define __IRR_DIMENSION2D_H_INCLUDED__


namespace irr
{
namespace core
{

	//! Specifies a 2 dimensional size.
	template <class T>
	class dimension2d
	{
		public:

			dimension2d()
				: Width(0), Height(0) {};

			dimension2d(T width, T height)
				: Width(width), Height(height) {};

			dimension2d(const dimension2d<T>& other)
				: Width(other.Width), Height(other.Height) {};


			bool operator == (const dimension2d<T>& other) const
			{
				return Width == other.Width && Height == other.Height;
			}


			bool operator != (const dimension2d<T>& other) const
			{
				return Width != other.Width || Height != other.Height;
			}

			const dimension2d<T>& operator=(const dimension2d<T>& other) 
			{
				Width = other.Width;
				Height = other.Height;
				return *this;
			}

			dimension2d<T> operator/(T scale) 
			{
				return dimension2d<T>(Width/scale, Height/scale);
			}

			dimension2d<T> operator*(T scale) 
			{
				return dimension2d<T>(Width*scale, Height*scale);
			}

			T Width, Height;
	};

	//! Typedef for a f32 dimension.
	typedef dimension2d<f32> dimension2df;
	//! Typedef for an integer dimension.
	typedef dimension2d<s32> dimension2di;

} // end namespace core
} // end namespace irr

#endif

// Copyright (C) 2002-2007 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __E_DRIVER_TYPES_H_INCLUDED__
#define __E_DRIVER_TYPES_H_INCLUDED__

namespace irr
{
namespace video  
{
	//! An enum for all types of drivers the Irrlicht Engine supports.
	enum E_DRIVER_TYPE
	{
		//! Null device, useful for applications to run the engine without visualisation. 
		//! The null device is able to load textures, but does not render and display
		//! any graphics.
		EDT_NULL,     

		//! The Irrlicht Engine Software renderer, runs on all platforms,
		//! with every hardware. It should only be used for 2d graphics, 
		//! but it can also perform some primitive 3d functions. These 3d drawing 
		//! functions are quite fast, but very inaccurate, and don't even support 
		//! clipping in 3D mode.
		EDT_SOFTWARE, 

		//! The Burning's Software Renderer, an alternative software renderer for Irrlicht.
		//! Basically it can be described as the Irrlicht Software renderer on steroids. It rasterizes
		//! 3D geometry perfectly: It is able to perform correct 3d clipping, perspective 
		//! correct texture mapping, perspective correct color mapping, and renders 
		//! sub pixel correct, sub texel correct primitives. In addition, it does
		//! bilinear texel filtering and supports more materials than the EDT_SOFTWARE driver.
		//! This renderer has been written entirely by Thomas Alten, thanks a lot for this huge
		//! contribution.
		EDT_BURNINGSVIDEO,

		//! Direct3D 8 device, only available on Win32 platforms including Win95, Win98, WinNT,
		//! Win2K, WinXP. Performs hardware accelerated rendering of 3D and 2D primitives.
		EDT_DIRECT3D8, 

		//! Direct3D 9 device, only available on Win32 platforms including Win95, Win98, WinNT,
		//! Win2K, WinXP. Performs hardware accelerated rendering of 3D and 2D primitives.
		EDT_DIRECT3D9,

		//! OpenGL device, available on all Win32 platforms and on Linux.
		//! Performs hardware accelerated rendering of 3D and 2D primitives.
		EDT_OPENGL    
	};

} // end namespace video
} // end namespace irr


#endif

// Copyright (C) 2002-2007 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __I_ATTRIBUTES_H_INCLUDED__
#define __I_ATTRIBUTES_H_INCLUDED__

// Copyright (C) 2002-2007 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __I_UNKNOWN_H_INCLUDED__
#define __I_UNKNOWN_H_INCLUDED__


namespace irr
{

	//! Base class of most objects of the Irrlicht Engine.
	/* This class provides reference counting through the methods grab() and drop().
	It also is able to store a debug string for every instance of an object.
	Most objects of the Irrlicht
	Engine are derived from IUnknown, and so they are reference counted.

	When you create an object in the Irrlicht engine, calling a method
	which starts with 'create', an object is created, and you get a pointer
	to the new object. If you no longer need the object, you have 
	to call drop(). This will destroy the object, if grab() was not called
	in another part of you program, because this part still needs the object.
	Note, that you only need to call drop() to the object, if you created it,
	and the method had a 'create' in it. 

	A simple example:

	If you want to create a texture, you may want to call an imaginable method
	IDriver::createTexture. You call
	ITexture texture = driver->createTexture(dimension2d<s32>(128, 128));
	If you no longer need the texture, call texture->drop().

	If you want to load a texture, you may want to call imaginable method
	IDriver::loadTexture. You do this like
	ITexture texture = driver->loadTexture("example.jpg");
	You will not have to drop the pointer to the loaded texture, because
	the name of the method does not start with 'create'. The texture
	is stored somewhere by the driver.
	*/
	class IUnknown
	{
	public:

		//! Constructor.
		IUnknown()
			: ReferenceCounter(1), DebugName(0)
		{
		}

		//! Destructor.
		virtual ~IUnknown()
		{
		}

		//! Grabs the object. Increments the reference counter by one.
		//! Someone who calls grab() to an object, should later also call
		//! drop() to it. If an object never gets as much drop() as grab()
		//! calls, it will never be destroyed.
		//! The IUnknown class provides a basic reference counting mechanism
		//! with its methods grab() and drop(). Most objects of the Irrlicht
		//! Engine are derived from IUnknown, and so they are reference counted.
		//!
		//! When you create an object in the Irrlicht engine, calling a method
		//! which starts with 'create', an object is created, and you get a pointer
		//! to the new object. If you no longer need the object, you have 
		//! to call drop(). This will destroy the object, if grab() was not called
		//! in another part of you program, because this part still needs the object.
		//! Note, that you only need to call drop() to the object, if you created it,
		//! and the method had a 'create' in it. 
		//!
		//! A simple example:
		//!
		//! If you want to create a texture, you may want to call an imaginable method
		//! IDriver::createTexture. You call
		//! ITexture* texture = driver->createTexture(dimension2d<s32>(128, 128));
		//! If you no longer need the texture, call texture->drop().
		//! If you want to load a texture, you may want to call imaginable method
		//! IDriver::loadTexture. You do this like
		//! ITexture* texture = driver->loadTexture("example.jpg");
		//! You will not have to drop the pointer to the loaded texture, because
		//! the name of the method does not start with 'create'. The texture
		//! is stored somewhere by the driver.
		void grab() { ++ReferenceCounter; }

		//! Drops the object. Decrements the reference counter by one.
		//! Returns true, if the object was deleted.
		//! The IUnknown class provides a basic reference counting mechanism
		//! with its methods grab() and drop(). Most objects of the Irrlicht
		//! Engine are derived from IUnknown, and so they are reference counted.
		//!
		//! When you create an object in the Irrlicht engine, calling a method
		//! which starts with 'create', an object is created, and you get a pointer
		//! to the new object. If you no longer need the object, you have 
		//! to call drop(). This will destroy the object, if grab() was not called
		//! in another part of you program, because this part still needs the object.
		//! Note, that you only need to call drop() to the object, if you created it,
		//! and the method had a 'create' in it. 
		//!
		//! A simple example:
		//!
		//! If you want to create a texture, you may want to call an imaginable method
		//! IDriver::createTexture. You call
		//! ITexture* texture = driver->createTexture(dimension2d<s32>(128, 128));
		//! If you no longer need the texture, call texture->drop().
		//! If you want to load a texture, you may want to call imaginable method
		//! IDriver::loadTexture. You do this like
		//! ITexture* texture = driver->loadTexture("example.jpg");
		//! You will not have to drop the pointer to the loaded texture, because
		//! the name of the method does not start with 'create'. The texture
		//! is stored somewhere by the driver.
		bool drop()
		{
			_IRR_DEBUG_BREAK_IF(ReferenceCounter <= 0) // someone is doing bad reference counting.

			--ReferenceCounter;
			if (!ReferenceCounter)
			{
				delete this;
				return true;
			}

			return false;
		}

		//! Returns the debug name of the object. The Debugname may only be set and
		//! changed by the object itself. This method should only be used in Debug mode.
		//! \return Returns a string, previously set by setDebugName();
		const c8* getDebugName() const
		{
			return DebugName;
		} 

	protected:

		//! Sets the debug name of the object. The Debugname may only be set and
		//! changed by the object itself. This method should only be used in Debug mode.
		//! \param newName: New debug name to set.
		void setDebugName(const c8* newName)
		{
			DebugName = newName;
		}

	private:

		s32	ReferenceCounter;
		const c8* DebugName;
	};

} // end namespace irr

#endif

// Copyright (C) 2002-2007 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __IRR_POINT_2D_H_INCLUDED__
#define __IRR_POINT_2D_H_INCLUDED__


namespace irr
{
namespace core
{


//! 2d vector template class with lots of operators and methods.
template <class T>
class vector2d
{
public:

	vector2d() : X(0), Y(0) {};
	vector2d(T nx, T ny) : X(nx), Y(ny) {};
	vector2d(const vector2d<T>& other) : X(other.X), Y(other.Y) {};

	// operators

	vector2d<T> operator-() const { return vector2d<T>(-X, -Y);   }

	vector2d<T>& operator=(const vector2d<T>& other)	{ X = other.X; Y = other.Y; return *this; }

	vector2d<T> operator+(const vector2d<T>& other) const { return vector2d<T>(X + other.X, Y + other.Y);	}
	vector2d<T>& operator+=(const vector2d<T>& other)	{ X+=other.X; Y+=other.Y; return *this; }

	vector2d<T> operator-(const vector2d<T>& other) const { return vector2d<T>(X - other.X, Y - other.Y);	}
	vector2d<T>& operator-=(const vector2d<T>& other)	{ X-=other.X; Y-=other.Y; return *this; }

	vector2d<T> operator*(const vector2d<T>& other) const { return vector2d<T>(X * other.X, Y * other.Y);	}
	vector2d<T>& operator*=(const vector2d<T>& other)	{ X*=other.X; Y*=other.Y; return *this; }
	vector2d<T> operator*(const T v) const { return vector2d<T>(X * v, Y * v);	}
	vector2d<T>& operator*=(const T v) { X*=v; Y*=v; return *this; }

	vector2d<T> operator/(const vector2d<T>& other) const { return vector2d<T>(X / other.X, Y / other.Y);	}
	vector2d<T>& operator/=(const vector2d<T>& other)	{ X/=other.X; Y/=other.Y; return *this; }
	vector2d<T> operator/(const T v) const { return vector2d<T>(X / v, Y / v);	}
	vector2d<T>& operator/=(const T v) { X/=v; Y/=v; return *this; }

	bool operator<=(const vector2d<T>&other) const { return X<=other.X && Y<=other.Y; }
	bool operator>=(const vector2d<T>&other) const { return X>=other.X && Y>=other.Y; }

	bool operator<(const vector2d<T>&other) const { return X<other.X && Y<other.Y; }
	bool operator>(const vector2d<T>&other) const { return X>other.X && Y>other.Y; }

	bool operator==(const vector2d<T>& other) const { return other.X==X && other.Y==Y; }
	bool operator!=(const vector2d<T>& other) const { return other.X!=X || other.Y!=Y; }

	// functions

	//! returns if this vector equals the other one, taking floating point rounding errors into account
	bool equals(const vector2d<T>& other) const
	{
		return core::equals(X, other.X) &&
			   core::equals(Y, other.Y);
	}

	void set(T nx, T ny) {X=nx; Y=ny; }
	void set(const vector2d<T>& p) { X=p.X; Y=p.Y;}

	//! Returns the length of the vector
	//! \return Returns the length of the vector.
	f64 getLength() const { return sqrt(X*X + Y*Y); }

	//! Returns the squared lenth of this vector
	/* This is useful because it is much faster than getLength(). */
	T getLengthSQ() const { return X*X + Y*Y; }

	//! Returns the dot product of this vector with another.
	T dotProduct(const vector2d<T>& other) const
	{
		return X*other.X + Y*other.Y;
	}

	//! Returns distance from another point. Here, the vector is interpreted as
	//! point in 2 dimensional space.
	f64 getDistanceFrom(const vector2d<T>& other) const
	{
		return vector2d<T>(X - other.X, Y - other.Y).getLength();
	}

	//! Returns squared distance from another point. Here, the vector is interpreted as
	//! point in 2 dimensional space.
	T getDistanceFromSQ(const vector2d<T>& other) const
	{
		return vector2d<T>(X - other.X, Y - other.Y).getLengthSQ();
	}

	//! rotates the point around a center by an amount of degrees.
	void rotateBy(f64 degrees, const vector2d<T>& center)
	{
		degrees *= DEGTORAD64;
		T cs = (T)cos(degrees);
		T sn = (T)sin(degrees);

		X -= center.X;
		Y -= center.Y;

		set(X*cs - Y*sn, X*sn + Y*cs);

		X += center.X;
		Y += center.Y;
	}

	//! normalizes the vector.
	vector2d<T>& normalize()
	{
		T l = core::reciprocal_squareroot ( X*X + Y*Y );
/*
		T l = (T)getLength();
		if (l == 0)
			return this;

		l = (T)1.0 / l;
*/
		X *= l;
		Y *= l;
		return *this;
	}

	//! Calculates the angle of this vector in grad in the trigonometric sense.
	//! This method has been suggested by Pr3t3nd3r.
	//! \return Returns a value between 0 and 360.
	f64 getAngleTrig() const
	{
		if (X == 0.0)
			return Y < 0.0 ? 270.0 : 90.0;
		else
		if (Y == 0)
			return X < 0.0 ? 180.0 : 0.0;

		if ( Y > 0.0)
			if (X > 0.0)
				return atan(Y/X) * RADTODEG64;
			else
				return 180.0-atan(Y/-X) * RADTODEG64;
		else
			if (X > 0.0)
				return 360.0-atan(-Y/X) * RADTODEG64;
			else
				return 180.0+atan(-Y/-X) * RADTODEG64;
	} 

	//! Calculates the angle of this vector in grad in the counter trigonometric sense.
	//! \return Returns a value between 0 and 360.
	inline f64 getAngle() const
	{
		if (Y == 0.0)  // corrected thanks to a suggestion by Jox
			return X < 0.0 ? 180.0 : 0.0; 
		else if (X == 0.0) 
			return Y < 0.0 ? 90.0 : 270.0;

		f64 tmp = Y / getLength();
		tmp = atan(sqrt(1 - tmp*tmp) / tmp) * RADTODEG64;

		if (X>0.0 && Y>0.0)
			return tmp + 270;
		else
		if (X>0.0 && Y<0.0)
			return tmp + 90;
		else
		if (X<0.0 && Y<0.0)
			return 90 - tmp;
		else
		if (X<0.0 && Y>0.0)
			return 270 - tmp;

		return tmp;
	}

	//! Calculates the angle between this vector and another one in grad.
	//! \return Returns a value between 0 and 90.
	inline f64 getAngleWith(const vector2d<T>& b) const
	{
		f64 tmp = X*b.X + Y*b.Y;

		if (tmp == 0.0)
			return 90.0;

		tmp = tmp / sqrt((X*X + Y*Y) * (b.X*b.X + b.Y*b.Y));
		if (tmp < 0.0) tmp = -tmp;

		return atan(sqrt(1 - tmp*tmp) / tmp) * RADTODEG64;
	}

	//! Returns if this vector interpreted as a point is on a line between two other points.
	/* It is assumed that the point is on the line. */
	//! \param begin: Beginning vector to compare between.
	//! \param end: Ending vector to compare between.
	//! \return True if this vector is between begin and end.  False if not.
	bool isBetweenPoints(const vector2d<T>& begin, const vector2d<T>& end) const
	{
		T f = (end - begin).getLengthSQ();
		return getDistanceFromSQ(begin) < f && 
			getDistanceFromSQ(end) < f;
	}

	//! returns interpolated vector
	//! \param other: other vector to interpolate between
	//! \param d: value between 0.0f and 1.0f.
	vector2d<T> getInterpolated(const vector2d<T>& other, f32 d) const
	{
		T inv = (T) 1.0 - d;
		return vector2d<T>(other.X*inv + X*d, other.Y*inv + Y*d);
	}

	//! Returns interpolated vector. ( quadratic )
	/* \param other0: other vector to interpolate between
		\param other1: other vector to interpolate between
	\param factor: value between 0.0f and 1.0f. */
	vector2d<T> getInterpolated_quadratic(const vector2d<T>& v2, const vector2d<T>& v3, const T d) const
	{
		// this*(1-d)*(1-d) + 2 * v2 * (1-d) + v3 * d * d;
		const T inv = (T) 1.0 - d;
		const T mul0 = inv * inv;
		const T mul1 = (T) 2.0 * d * inv;
		const T mul2 = d * d;

		return vector2d<T> ( X * mul0 + v2.X * mul1 + v3.X * mul2,
							 Y * mul0 + v2.Y * mul1 + v3.Y * mul2
							);
	}

	//! sets this vector to the interpolated vector between a and b. 
	void interpolate(const vector2d<T>& a, const vector2d<T>& b, const f32 t)
	{
		X = b.X + ( ( a.X - b.X ) * t );
		Y = b.Y + ( ( a.Y - b.Y ) * t );
	}

	// member variables
	T X, Y;
};

	//! Typedef for f32 2d vector.
	typedef vector2d<f32> vector2df;
	//! Typedef for integer 2d vector.
	typedef vector2d<s32> vector2di;

	template<class S, class T> vector2d<T> operator*(const S scalar, const vector2d<T>& vector) { return vector*scalar; }

} // end namespace core
} // end namespace irr

#endif

// Copyright (C) 2002-2007 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __IRR_LINE_2D_H_INCLUDED__
#define __IRR_LINE_2D_H_INCLUDED__


namespace irr
{
namespace core
{

//! 2D line between two points with intersection methods.
template <class T>
class line2d
{
	public:

		line2d() : start(0,0), end(1,1) {};
		line2d(T xa, T ya, T xb, T yb) : start(xa, ya), end(xb, yb) {};
		line2d(const vector2d<T>& start, const vector2d<T>& end) : start(start), end(end) {};
		line2d(const line2d<T>& other) : start(other.start), end(other.end) {};

		// operators

		line2d<T> operator+(const vector2d<T>& point) const { return line2d<T>(start + point, end + point); };
		line2d<T>& operator+=(const vector2d<T>& point) { start += point; end += point; return *this; };

		line2d<T> operator-(const vector2d<T>& point) const { return line2d<T>(start - point, end - point); };
		line2d<T>& operator-=(const vector2d<T>& point) { start -= point; end -= point; return *this; };

		bool operator==(const line2d<T>& other) const { return (start==other.start && end==other.end) || (end==other.start && start==other.end);};
		bool operator!=(const line2d<T>& other) const { return !(start==other.start && end==other.end) || (end==other.start && start==other.end);};

		// functions

		void setLine(const T& xa, const T& ya, const T& xb, const T& yb){start.set(xa, ya); end.set(xb, yb);}
		void setLine(const vector2d<T>& nstart, const vector2d<T>& nend){start.set(nstart); end.set(nend);}
		void setLine(const line2d<T>& line){start.set(line.start); end.set(line.end);}

		//! Returns length of line
		//! \return Returns length of the line.
		f64 getLength() const { return start.getDistanceFrom(end); };

		//! Returns squared length of the line
		//! \return Returns squared length of line.
		T getLengthSQ() const { return start.getDistanceFromSQ(end); };

		//! Returns middle of the line
		vector2d<T> getMiddle() const
		{
			return (start + end) * (T)0.5;
		}

		//! Returns the vector of the line.
		//! \return Returns the vector of the line.
		vector2d<T> getVector() const { return vector2d<T>(start.X - end.X, start.Y - end.Y); };

		//! Tests if this line intersects with another line.
		//! \param l: Other line to test intersection with.
		//! \param out: If there is an intersection, the location of the intersection will
		//! be stored in this vector.
		//! \return Returns true if there is an intersection, false if not.
		bool intersectWith(const line2d<T>& l, vector2d<T>& out) const
		{
			bool found=false;

			f32 a1,a2,b1,b2;

			// calculate slopes, deal with infinity
			if (end.X-start.X == 0)
				b1 = (f32)1e+10;
			else
				b1 = (end.Y-start.Y)/(end.X-start.X);
			if (l.end.X-l.start.X == 0)
				b2 = (f32)1e+10;
			else
				b2 = (l.end.Y-l.start.Y)/(l.end.X-l.start.X);

			// calculate position
			a1 = start.Y   - b1 *  start.X;
			a2 = l.start.Y - b2 * l.start.X;
			out.X = - (a1-a2)/(b1-b2);
			out.Y = a1 + b1*out.X;

			// did the lines cross?
			if (	(start.X-out.X) *(out.X-end.X)	 >= -ROUNDING_ERROR_32 &&
				(l.start.X-out.X)*(out.X-l.end.X)>= -ROUNDING_ERROR_32 &&
				(start.Y-out.Y)  *(out.Y-end.Y)  >= -ROUNDING_ERROR_32 &&
				(l.start.Y-out.Y)*(out.Y-l.end.Y)>= -ROUNDING_ERROR_32 )
			{
				found = true;
			}
			return found;
		}

		//! Returns unit vector of the line.
		//! \return Returns unit vector of this line.
		vector2d<T> getUnitVector()
		{
			T len = (T)(1.0 / getLength());
			return vector2d<T>((end.X - start.X) * len, (end.Y - start.Y) * len);
		}

		f64 getAngleWith(const line2d<T>& l)
		{
			vector2d<T> vect = getVector();
			vector2d<T> vect2 = l.getVector();
			return vect.getAngleWith(vect2);
		}

		//! Tells us if the given point lies to the left, 
		//! right, or on the direction of the line
		//! \return Returns 0 if the point is on the line
		//! <0 if to the left, or >0 if to the right.
		T getPointOrientation(const vector2d<T>& point)
		{
			return ( (end.X   - start.X) * (point.Y - start.Y) - 
					 (point.X - start.X) * (end.Y   - start.Y) );
		}

		//! Returns if the given point is a member of the line
		//! \return Returns true if 
		bool isPointOnLine(const vector2d<T>& point)
		{
			T d = getPointOrientation(point);
			return (d == 0 && point.isBetweenPoints(start, end));
		}

		//! Returns if the given point is between start and end of the
		//! line. Assumes that the point is already somewhere on the line.
		bool isPointBetweenStartAndEnd(const vector2d<T>& point) const
		{
			return point.isBetweenPoints(start, end);
		}

		//! Returns the closest point on this line to a point
		vector2d<T> getClosestPoint(const vector2d<T>& point) const
		{
			vector2d<T> c = point - start;
			vector2d<T> v = end - start;
			T d = (T)v.getLength();
			v /= d;
			T t = v.dotProduct(c);

			if (t < (T)0.0) return start;
			if (t > d) return end;

			v *= t;
			return start + v;
		}

		// member variables

		vector2d<T> start;
		vector2d<T> end;
};

	//! Typedef for a f32 line.
	typedef line2d<f32> line2df;
	//! Typedef for an integer line.
	typedef line2d<s32> line2di;

} // end namespace core
} // end namespace irr

#endif

// Copyright (C) 2002-2007 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __IRR_TRIANGLE_3D_H_INCLUDED__
#define __IRR_TRIANGLE_3D_H_INCLUDED__


namespace irr
{
namespace core
{
	
	//! 3d triangle template class for doing collision detection and other things.
	template <class T>
	class triangle3d  
	{
	public:

		//! Determines if the triangle is totally inside a bounding box.
		//! \param box: Box to check.
		//! \return Returns true if the triangle is withing the box,
		//! and false otherwise.
		bool isTotalInsideBox(const aabbox3d<T>& box) const
		{
			return (box.isPointInside(pointA) && 
				box.isPointInside(pointB) &&
				box.isPointInside(pointC));
		}

		bool operator==(const triangle3d<T>& other) const { return other.pointA==pointA && other.pointB==pointB && other.pointC==pointC; }
		bool operator!=(const triangle3d<T>& other) const { return other.pointA!=pointA || other.pointB!=pointB || other.pointC!=pointC; }

		//! Returns the closest point on a triangle to a point on the same plane.
		//! \param p: Point which must be on the same plane as the triangle.
		core::vector3d<T> closestPointOnTriangle(const core::vector3d<T>& p) const
		{
			core::vector3d<T> rab = line3d<T>(pointA, pointB).getClosestPoint(p);
			core::vector3d<T> rbc = line3d<T>(pointB, pointC).getClosestPoint(p);
			core::vector3d<T> rca = line3d<T>(pointC, pointA).getClosestPoint(p);

			T d1 = rab.getDistanceFrom(p);
			T d2 = rbc.getDistanceFrom(p);
			T d3 = rca.getDistanceFrom(p);

			if (d1 < d2)
				return d1 < d3 ? rab : rca;
            
			return d2 < d3 ? rbc : rca;
		}

		//! Returns if a point is inside the triangle
		//! \param p: Point to test. Assumes that this point is already on the plane
		//! of the triangle.
		//! \return Returns true if the point is inside the triangle, otherwise false.
		bool isPointInside(const vector3d<T>& p) const
		{
			return (isOnSameSide(p, pointA, pointB, pointC) &&
				isOnSameSide(p, pointB, pointA, pointC) &&
				isOnSameSide(p, pointC, pointA, pointB));
		}

		//! Returns if a point is inside the triangle. This method is an implementation
		//! of the example used in a paper by Kasper Fauerby original written
		//! by Keidy from Mr-Gamemaker.
		//! \param p: Point to test. Assumes that this point is already on the plane
		//! of the triangle.
		//! \return Returns true if the point is inside the triangle, otherwise false.
		bool isPointInsideFast(const vector3d<T>& p) const
		{
			vector3d<T> f = pointB - pointA;
			vector3d<T> g = pointC - pointA;

			f32 a = f.dotProduct(f);
			f32 b = f.dotProduct(g);
			f32 c = g.dotProduct(g);

			f32 ac_bb = (a*c)-(b*b);
			vector3d<T> vp = p - pointA;

			f32 d = vp.dotProduct(f);
			f32 e = vp.dotProduct(g);
			f32 x = (d*c)-(e*b);
			f32 y = (e*a)-(d*b);
			f32 z = x+y-ac_bb;

			return (( ((u32&)z)& ~(((u32&)x)|((u32&)y))) & 0x80000000)!=0;
		}


		bool isOnSameSide(const vector3d<T>& p1, const vector3d<T>& p2, 
			const vector3d<T>& a, const vector3d<T>& b) const
		{
			vector3d<T> bminusa = b - a;
			vector3d<T> cp1 = bminusa.crossProduct(p1 - a);
			vector3d<T> cp2 = bminusa.crossProduct(p2 - a);
			return (cp1.dotProduct(cp2) >= core::ROUNDING_ERROR_32);
		}


		//! Returns an intersection with a 3d line.
		//! \param line: Line to intersect with.
		//! \param outIntersection: Place to store the intersection point, if there is one.
		//! \return Returns true if there was an intersection, false if there was not.
		bool getIntersectionWithLimitedLine(const line3d<T>& line,
			vector3d<T>& outIntersection) const
		{
			return getIntersectionWithLine(line.start,
				line.getVector(), outIntersection) &&
				outIntersection.isBetweenPoints(line.start, line.end);
		}


		//! Returns an intersection with a 3d line.
		//! Please note that also points are returned as intersection, which
		//! are on the line, but not between the start and end point of the line.
		//! If you want the returned point be between start and end, please
		//! use getIntersectionWithLimitedLine().
		//! \param lineVect: Vector of the line to intersect with.
		//! \param linePoint: Point of the line to intersect with.
		//! \param outIntersection: Place to store the intersection point, if there is one.
		//! \return Returns true if there was an intersection, false if there was not.
		bool getIntersectionWithLine(const vector3d<T>& linePoint,
			const vector3d<T>& lineVect, vector3d<T>& outIntersection) const
		{
			if (getIntersectionOfPlaneWithLine(linePoint, lineVect, outIntersection))
				return isPointInside(outIntersection);

			return false;			
		}


		//! Calculates the intersection between a 3d line and 
		//! the plane the triangle is on.
		//! \param lineVect: Vector of the line to intersect with.
		//! \param linePoint: Point of the line to intersect with.
		//! \param outIntersection: Place to store the intersection point, if there is one.
		//! \return Returns true if there was an intersection, false if there was not.
		bool getIntersectionOfPlaneWithLine(const vector3d<T>& linePoint,
			const vector3d<T>& lineVect, vector3d<T>& outIntersection) const
		{
			const vector3d<T> normal = getNormal().normalize();
			T t2;
            
			if ( core::iszero ( t2 = normal.dotProduct(lineVect) ) )
				return false;

			T d = pointA.dotProduct(normal);
			T t = -(normal.dotProduct(linePoint) - d) / t2;
			outIntersection = linePoint + (lineVect * t);
			return true;
		}

		
		//! Returns the normal of the triangle.
		//! Please note: The normal is not normalized.
		vector3d<T> getNormal() const
		{
			return (pointB - pointA).crossProduct(pointC - pointA);
		}

		//! Returns if the triangle is front of backfacing.
		//! \param lookDirection: Look direction.
		//! \return Returns true if the plane is front facing, which mean it would
		//! be visible, and false if it is backfacing.
		bool isFrontFacing(const vector3d<T>& lookDirection) const
		{
			vector3d<T> n = getNormal();
			n.normalize();
			return n.dotProduct(lookDirection) <= 0.0f;
		}

		//! Returns the plane of this triangle.
		plane3d<T> getPlane() const
		{
			return plane3d<T>(pointA, pointB, pointC);
		}

		//! Returns the area of the triangle
		T getArea() const
		{
			return (pointB - pointA).crossProduct(pointC - pointA).getLength() * 0.5;

		}

		//! sets the triangle's points
		void set(const core::vector3d<T>& a, const core::vector3d<T>& b, const core::vector3d<T>& c)
		{
			pointA = a;
			pointB = b;
			pointC = c;
		}

		//! the three points of the triangle
		vector3d<T> pointA; 
		vector3d<T> pointB; 
		vector3d<T> pointC; 
	};


	//! Typedef for a f32 3d triangle.
	typedef triangle3d<f32> triangle3df;

	//! Typedef for an integer 3d triangle.
	typedef triangle3d<s32> triangle3di;

} // end namespace core
} // end namespace irr

#endif

// Copyright (C) 2002-2007 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __IRR_QUATERNION_H_INCLUDED__
#define __IRR_QUATERNION_H_INCLUDED__

// Copyright (C) 2002-2007 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __IRR_MATRIX_H_INCLUDED__
#define __IRR_MATRIX_H_INCLUDED__

// Copyright (C) 2002-2007 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __IRR_RECT_H_INCLUDED__
#define __IRR_RECT_H_INCLUDED__

// Copyright (C) 2002-2007 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __IRR_POSITION_H_INCLUDED__
#define __IRR_POSITION_H_INCLUDED__


namespace irr
{
namespace core
{

	//! Simple class for holding 2d coordinates.
	/* Not supposed for doing geometric calculations.
	use vector2d instead for things like that. 
	*/
	template <class T>
	class position2d
	{
		public:
			position2d(T x, T y)
				: X(x), Y(y) {};


			position2d()
				: X(0), Y(0) {};


			position2d(const position2d<T>& other)
				: X(other.X), Y(other.Y) {};


			bool operator == (const position2d<T>& other) const
			{
				return X == other.X && Y == other.Y;
			}


			bool operator != (const position2d<T>& other) const
			{
				return X != other.X || Y != other.Y;
			}

			const position2d<T>& operator+=(const position2d<T>& other)
			{
				X += other.X;
				Y += other.Y;
				return *this;
			}

			const position2d<T>& operator-=(const position2d<T>& other)
			{
				X -= other.X;
				Y -= other.Y;
				return *this;
			}

			const position2d<T>& operator+=(const dimension2d<T>& other)
			{
				X += other.Width;
				Y += other.Height;
				return *this;
			}

			const position2d<T>& operator-=(const dimension2d<T>& other)
			{
				X -= other.Width;
				Y -= other.Height;
				return *this;
			}

			position2d<T> operator-(const position2d<T>& other) const
			{
				return position2d<T>(X-other.X, Y-other.Y);
			}

			position2d<T> operator+(const position2d<T>& other) const
			{
				return position2d<T>(X+other.X, Y+other.Y);
			}

			position2d<T> operator*(const position2d<T>& other) const
			{
				return position2d<T>(X*other.X, Y*other.Y);
			}

			position2d<T> operator*(const T& scalar) const
			{
				return position2d<T>(X*scalar, Y*scalar);
			}

			position2d<T> operator+(const dimension2d<T>& other) const
			{
				return position2d<T>(X+other.Width, Y+other.Height);
			}

			position2d<T> operator-(const dimension2d<T>& other) const
			{
				return position2d<T>(X-other.Width, Y-other.Height);
			}

			const position2d<T>& operator=(const position2d<T>& other) 
			{
				X = other.X;
				Y = other.Y;
				return *this;
			}

			T X, Y;
	};

	//! Typedef for a f32 position.
	typedef position2d<f32> position2df;
	//! Typedef for an integer position.
	typedef position2d<s32> position2di;

} // end namespace core
} // end namespace irr

#endif


namespace irr
{
namespace core
{

	//!	Rectangle template.
	/* Mostly used by 2D GUI elements and for 2D drawing methods.
	    It has 2 positions instead of position and dimension
		and a fast method for collision detection with other rectangles and points.
	*/
	template <class T>
	class rect
	{
	public:

		rect()
			: UpperLeftCorner(0,0), LowerRightCorner(0,0) {};


		rect(T x, T y, T x2, T y2)
			: UpperLeftCorner(x,y), LowerRightCorner(x2,y2) {};


		rect(const position2d<T>& upperLeft, const position2d<T>& lowerRight)
			: UpperLeftCorner(upperLeft), LowerRightCorner(lowerRight) {};

		rect(const rect<T>& other)
			: UpperLeftCorner(other.UpperLeftCorner), LowerRightCorner(other.LowerRightCorner) {};

		rect(const position2d<T>& pos, const dimension2d<T>& size)
			: UpperLeftCorner(pos), LowerRightCorner(pos.X + size.Width, pos.Y + size.Height) {};


		rect<T> operator+(const position2d<T>& pos) const
		{
			rect<T> ret(*this);
			ret.UpperLeftCorner += pos;
			ret.LowerRightCorner += pos;
			return ret;
		}

		const rect<T>& operator+=(const position2d<T>& pos)
		{
			UpperLeftCorner += pos;
			LowerRightCorner += pos;
			return *this;
		}

		rect<T> operator-(const position2d<T>& pos) const
		{
			rect<T> ret(*this);
			ret.UpperLeftCorner -= pos;
			ret.LowerRightCorner -= pos;
			return ret;
		}

		const rect<T>& operator-=(const position2d<T>& pos)
		{
			UpperLeftCorner -= pos;
			LowerRightCorner -= pos;
			return *this;
		}

		bool operator == (const rect<T>& other) const
		{
			return (UpperLeftCorner == other.UpperLeftCorner &&
				LowerRightCorner == other.LowerRightCorner);
		}


		bool operator != (const rect<T>& other) const
		{
			return (UpperLeftCorner != other.UpperLeftCorner ||
				LowerRightCorner != other.LowerRightCorner);
		}

		const rect<T>& operator = (const rect<T>& other)
		{
			UpperLeftCorner = other.UpperLeftCorner;
			LowerRightCorner = other.LowerRightCorner;
			return *this;
		}

		//! Returns if a 2d point is within this rectangle.
		//! \param pos: Position to test if it lies within this rectangle.
		//! \return Returns true if the position is within the rectangle, false if not.
		bool isPointInside(const position2d<T>& pos) const
		{
			return (UpperLeftCorner.X <= pos.X &&
				UpperLeftCorner.Y <= pos.Y &&
				LowerRightCorner.X >= pos.X &&
				LowerRightCorner.Y >= pos.Y);
		}

		//! Returns if the rectangle collides with another rectangle.
		bool isRectCollided(const rect<T>& other) const
		{
			return (LowerRightCorner.Y > other.UpperLeftCorner.Y &&
				UpperLeftCorner.Y < other.LowerRightCorner.Y &&
				LowerRightCorner.X > other.UpperLeftCorner.X &&
				UpperLeftCorner.X < other.LowerRightCorner.X);
		}

		//! Clips this rectangle with another one.
		void clipAgainst(const rect<T>& other) 
		{
			if (other.LowerRightCorner.X < LowerRightCorner.X)
				LowerRightCorner.X = other.LowerRightCorner.X;
			if (other.LowerRightCorner.Y < LowerRightCorner.Y)
				LowerRightCorner.Y = other.LowerRightCorner.Y;

			if (other.UpperLeftCorner.X > UpperLeftCorner.X)
				UpperLeftCorner.X = other.UpperLeftCorner.X;
			if (other.UpperLeftCorner.Y > UpperLeftCorner.Y)
				UpperLeftCorner.Y = other.UpperLeftCorner.Y;

			// correct possible invalid rect resulting from clipping
			if (UpperLeftCorner.Y > LowerRightCorner.Y)
				UpperLeftCorner.Y = LowerRightCorner.Y;
			if (UpperLeftCorner.X > LowerRightCorner.X)
				UpperLeftCorner.X = LowerRightCorner.X;
		}

		//! Returns width of rectangle.
		T getWidth() const
		{
			return LowerRightCorner.X - UpperLeftCorner.X;
		}

		//! Returns height of rectangle.
		T getHeight() const
		{
			return LowerRightCorner.Y - UpperLeftCorner.Y;
		}

		//! If the lower right corner of the rect is smaller then the
		//! upper left, the points are swapped.
		void repair()
		{
			if (LowerRightCorner.X < UpperLeftCorner.X)
			{
				T t = LowerRightCorner.X;
				LowerRightCorner.X = UpperLeftCorner.X;
				UpperLeftCorner.X = t;
			}

			if (LowerRightCorner.Y < UpperLeftCorner.Y)
			{
				T t = LowerRightCorner.Y;
				LowerRightCorner.Y = UpperLeftCorner.Y;
				UpperLeftCorner.Y = t;
			}
		}

		//! Returns if the rect is valid to draw. It could be invalid
		//! if the UpperLeftCorner is lower or more right than the
		//! LowerRightCorner, or if the area described by the rect is 0.
		bool isValid() const
		{
			// thx to jox for a correction to this method

			T xd = LowerRightCorner.X - UpperLeftCorner.X;
			T yd = LowerRightCorner.Y - UpperLeftCorner.Y;

			return !(xd < 0 || yd < 0 || (xd == 0 && yd == 0));
		}

		//! Returns the center of the rectangle
		position2d<T> getCenter() const
		{
			return position2d<T>((UpperLeftCorner.X + LowerRightCorner.X) / 2,
				(UpperLeftCorner.Y + LowerRightCorner.Y) / 2);
		}

		//! Returns the dimensions of the rectangle
		dimension2d<T> getSize() const
		{
			return dimension2d<T>(getWidth(), getHeight());
		}


		//! Adds a point to the rectangle, causing it to grow bigger, 
		//! if point is outside of the box
		//! \param p: Point to add into the box.
		void addInternalPoint(const position2d<T>& p)
		{
			addInternalPoint(p.X, p.Y);
		}

		//! Adds a point to the bounding rectangle, causing it to grow bigger, 
		//! if point is outside of the box.
		//! \param x: X Coordinate of the point to add to this box.
		//! \param y: Y Coordinate of the point to add to this box.
		void addInternalPoint(T x, T y)
		{
			if (x>LowerRightCorner.X) LowerRightCorner.X = x;
			if (y>LowerRightCorner.Y) LowerRightCorner.Y = y;

			if (x<UpperLeftCorner.X) UpperLeftCorner.X = x;
			if (y<UpperLeftCorner.Y) UpperLeftCorner.Y = y;
		}




		position2d<T> UpperLeftCorner;
		position2d<T> LowerRightCorner;
	};

} // end namespace core
} // end namespace irr


#endif

// Copyright (C) 2002-2007 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine" and the "irrXML" project.
// For conditions of distribution and use, see copyright notice in irrlicht.h and irrXML.h

#ifndef __IRR_STRING_H_INCLUDED__
#define __IRR_STRING_H_INCLUDED__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

namespace irr
{
namespace core
{

//!	Very simple string class with some useful features.
/*	string<c8> and string<wchar_t> work both with unicode AND ascii,
so you can assign unicode to string<c8> and ascii to string<wchar_t>
(and the other way round) if your ever would want to.
Note that the conversation between both is not done using an encoding.

Known bugs:
Special characters like '', '' and '' are ignored in the
methods make_upper, make_lower and equals_ignore_case.
*/
template <typename T, typename TAlloc = irrAllocator<T> >
class string
{
public:

	//! Default constructor
	string()
	: array(0), allocated(1), used(1)
	{
		array = allocator.allocate(1); // new T[1];
		array[0] = 0x0;
	}



	//! Constructor
	string(const string<T>& other)
	: array(0), allocated(0), used(0)
	{
		*this = other;
	}


	//! Constructs a string from a float
	string(double number)
	: array(0), allocated(0), used(0)
	{
		c8 tmpbuf[255];
		sprintf(tmpbuf,"%0.6f",number);
		*this = tmpbuf;
	}



	//! Constructs a string from an int
	string(int number)
	: array(0), allocated(0), used(0)
	{
		// store if negative and make positive

		bool negative = false;
		if (number < 0)
		{
			number *= -1;
			negative = true;
		}

		// temporary buffer for 16 numbers

		c8 tmpbuf[16];
		tmpbuf[15] = 0;
		u32 idx = 15;

		// special case '0'

		if (!number)
		{
			tmpbuf[14] = '0';
			*this = &tmpbuf[14];
			return;
		}

		// add numbers

		while(number && idx)
		{
			--idx;
			tmpbuf[idx] = (c8)('0' + (number % 10));
			number /= 10;
		}

		// add sign

		if (negative)
		{
			--idx;
			tmpbuf[idx] = '-';
		}

		*this = &tmpbuf[idx];
	}



	//! Constructs a string from an unsigned int
	string(unsigned int number)
	: array(0), allocated(0), used(0)
	{
		// temporary buffer for 16 numbers

		c8 tmpbuf[16];
		tmpbuf[15] = 0;
		u32 idx = 15;

		// special case '0'

		if (!number)
		{
			tmpbuf[14] = '0';
			*this = &tmpbuf[14];
			return;
		}

		// add numbers

		while(number && idx)
		{
			--idx;
			tmpbuf[idx] = (c8)('0' + (number % 10));
			number /= 10;
		}

		*this = &tmpbuf[idx];
	}



	//! Constructor for copying a string from a pointer with a given length
	template <class B>
	string(const B* const c, u32 length)
	: array(0), allocated(0), used(0)
	{
		if (!c)
		{
			// correctly init the string to an empty one
			*this="";
			return;
		}

		allocated = used = length+1;
		array = allocator.allocate(used); // new T[used];

		for (u32 l = 0; l<length; ++l)
			array[l] = (T)c[l];

		array[length] = 0;
	}



	//! Constructor for unicode and ascii strings
	template <class B>
	string(const B* const c)
	: array(0), allocated(0), used(0)
	{
		*this = c;
	}



	//! destructor
	~string()
	{
		allocator.deallocate(array); // delete [] array;
	}



	//! Assignment operator
	string<T>& operator=(const string<T>& other)
	{
		if (this == &other)
			return *this;

		allocator.deallocate(array); // delete [] array;
		allocated = used = other.size()+1;
		array = allocator.allocate(used); //new T[used];

		const T* p = other.c_str();
		for (u32 i=0; i<used; ++i, ++p)
			array[i] = *p;

		return *this;
	}



	//! Assignment operator for strings, ascii and unicode
	template <class B>
	string<T>& operator=(const B* const c)
	{
		if (!c)
		{
			if (!array)
			{
				array = allocator.allocate(1); //new T[1];
				allocated = 1;
			}
			used = 1;
			array[0] = 0x0;
			return *this;
		}

		if ((void*)c == (void*)array)
			return *this;

		u32 len = 0;
		const B* p = c;
		while(*p)
		{
			++len;
			++p;
		}

		// we'll take the old string for a while, because the new
		// string could be a part of the current string.
		T* oldArray = array;

		++len;
		allocated = used = len;
		array = allocator.allocate(used); //new T[used];

		for (u32 l = 0; l<len; ++l)
			array[l] = (T)c[l];

		allocator.deallocate(oldArray); // delete [] oldArray;
		return *this;
	}

	//! Add operator for other strings
	string<T> operator+(const string<T>& other) const
	{
		string<T> str(*this);
		str.append(other);

		return str;
	}

	//! Add operator for strings, ascii and unicode
	template <class B>
	string<T> operator+(const B* const c) const
	{
		string<T> str(*this);
		str.append(c);

		return str;
	}



	//! Direct access operator
	T& operator [](const u32 index) const
	{
		_IRR_DEBUG_BREAK_IF(index>=used) // bad index

		return array[index];
	}


	//! Comparison operator
	bool operator ==(const T* const str) const
	{
		if (!str)
			return false;

		u32 i;
		for(i=0; array[i] && str[i]; ++i)
			if (array[i] != str[i])
				return false;

		return !array[i] && !str[i];
	}



	//! Comparison operator
	bool operator ==(const string<T>& other) const
	{
		for(u32 i=0; array[i] && other.array[i]; ++i)
			if (array[i] != other.array[i])
				return false;

		return used == other.used;
	}


	//! Is smaller operator
	bool operator <(const string<T>& other) const
	{
		for(u32 i=0; array[i] && other.array[i]; ++i)
		{
			s32 diff = array[i] - other.array[i];
			if ( diff )
				return diff < 0;
/*
			if (array[i] != other.array[i])
				return (array[i] < other.array[i]);
*/
		}

		return used < other.used;
	}



	//! Equals not operator
	bool operator !=(const T* const str) const
	{
		return !(*this == str);
	}



	//! Equals not operator
	bool operator !=(const string<T>& other) const
	{
		return !(*this == other);
	}



	//! Returns length of string
	/* \return Returns length of the string in characters. */
	u32 size() const
	{
		return used-1;
	}



	//! Returns character string
	/* \return Returns pointer to C-style zero terminated string. */
	const T* c_str() const
	{
		return array;
	}



	//! Makes the string lower case.
	void make_lower()
	{
		for (u32 i=0; i<used; ++i)
			array[i] = ansi_lower ( array[i] );
	}



	//! Makes the string upper case.
	void make_upper()
	{
		const T a = (T)'a';
		const T z = (T)'z';
		const T diff = (T)'A' - a;

		for (u32 i=0; i<used; ++i)
		{
			if (array[i]>=a && array[i]<=z)
				array[i] += diff;
		}
	}



	//! Compares the string ignoring case.
	/* \param other: Other string to compare.
	\return Returns true if the string are equal ignoring case. */
	bool equals_ignore_case(const string<T>& other) const
	{
		for(u32 i=0; array[i] && other[i]; ++i)
			if (ansi_lower(array[i]) != ansi_lower(other[i]))
				return false;

		return used == other.used;
	}

	//! Compares the string ignoring case.
	/* \param other: Other string to compare.
	\return Returns true if the string is smaller ignoring case. */
	bool lower_ignore_case(const string<T>& other) const
	{
		for(u32 i=0; array[i] && other.array[i]; ++i)
		{
			s32 diff = (s32) ansi_lower ( array[i] ) - (s32) ansi_lower ( other.array[i] );
			if ( diff )
				return diff < 0;
		}

		return used < other.used;
	}



	//! compares the first n characters of the strings
	bool equalsn(const string<T>& other, int len) const
	{
		u32 i;
		for(i=0; array[i] && other[i] && i < len; ++i)
			if (array[i] != other[i])
				return false;

		// if one (or both) of the strings was smaller then they
		// are only equal if they have the same length
		return (i == len) || (used == other.used);
	}


	//! compares the first n characters of the strings
	bool equalsn(const T* const str, int len) const
	{
		if (!str)
			return false;
		u32 i;
		for(i=0; array[i] && str[i] && i < len; ++i)
			if (array[i] != str[i])
				return false;

		// if one (or both) of the strings was smaller then they
		// are only equal if they have the same length
		return (i == len) || (array[i] == 0 && str[i] == 0);
	}


	//! Appends a character to this string
	/* \param character: Character to append. */
	void append(T character)
	{
		if (used + 1 > allocated)
			reallocate(used + 1);

		++used;

		array[used-2] = character;
		array[used-1] = 0;
	}

	//! Appends a char string to this string
	/* \param other: Char string to append. */
	void append(const T* const other)
	{
		if (!other)
			return;

		u32 len = 0;
		const T* p = other;
		while(*p)
		{
			++len;
			++p;
		}

		if (used + len > allocated)
			reallocate(used + len);

		--used;
		++len;

		for (u32 l=0; l<len; ++l)
			array[l+used] = *(other+l);

		used += len;
	}


	//! Appends a string to this string
	/* \param other: String to append. */
	void append(const string<T>& other)
	{
		--used;
		u32 len = other.size()+1;

		if (used + len > allocated)
			reallocate(used + len);

		for (u32 l=0; l<len; ++l)
			array[used+l] = other[l];

		used += len;
	}


	//! Appends a string of the length l to this string.
	/* \param other: other String to append to this string.
	 \param length: How much characters of the other string to add to this one. */
	void append(const string<T>& other, u32 length)
	{
		if (other.size() < length)
		{
			append(other);
			return;
		}

		if (used + length > allocated)
			reallocate(used + length);

		--used;

		for (u32 l=0; l<length; ++l)
			array[l+used] = other[l];
		used += length;

		// ensure proper termination
		array[used]=0;
		++used;
	}


	//! Reserves some memory.
	/* \param count: Amount of characters to reserve. */
	void reserve(u32 count)
	{
		if (count < allocated)
			return;

		reallocate(count);
	}


	//! finds first occurrence of character in string
	/* \param c: Character to search for.
	\return Returns position where the character has been found,
	or -1 if not found. */
	s32 findFirst(T c) const
	{
		for (u32 i=0; i<used; ++i)
			if (array[i] == c)
				return i;

		return -1;
	}

	//! finds first occurrence of a character of a list in string
	/* \param c: List of strings to find. For example if the method
	should find the first occurrence of 'a' or 'b', this parameter should be "ab".
	\param count: Amount of characters in the list. Ususally,
	this should be strlen(ofParameter1)
	\return Returns position where one of the character has been found,
	or -1 if not found. */
	s32 findFirstChar(const T* const c, u32 count) const
	{
		if (!c)
			return -1;

		for (u32 i=0; i<used; ++i)
			for (u32 j=0; j<count; ++j)
				if (array[i] == c[j])
					return i;

		return -1;
	}


	//! Finds first position of a character not in a given list.
	/* \param c: List of characters not to find. For example if the method
	 should find the first occurrence of a character not 'a' or 'b', this parameter should be "ab".
	\param count: Amount of characters in the list. Ususally,
	this should be strlen(ofParameter1)
	\return Returns position where the character has been found,
	or -1 if not found. */
	template <class B>
	s32 findFirstCharNotInList(const B* const c, u32 count) const
	{
		for (u32 i=0; i<used-1; ++i)
		{
			u32 j;
			for (j=0; j<count; ++j)
				if (array[i] == c[j])
					break;

			if (j==count)
				return i;
		}

		return -1;
	}

	//! Finds last position of a character not in a given list.
	/* \param c: List of characters not to find. For example if the method
	 should find the first occurrence of a character not 'a' or 'b', this parameter should be "ab".
	\param count: Amount of characters in the list. Ususally,
	this should be strlen(ofParameter1)
	\return Returns position where the character has been found,
	or -1 if not found. */
	template <class B>
	s32 findLastCharNotInList(const B* const c, u32 count) const
	{
		for (s32 i=(s32)(used-2); i>=0; --i)
		{
			u32 j;
			for (j=0; j<count; ++j)
				if (array[i] == c[j])
					break;

			if (j==count)
				return i;
		}

		return -1;
	}

	//! finds next occurrence of character in string
	/* \param c: Character to search for.
	\param startPos: Position in string to start searching.
	\return Returns position where the character has been found,
	or -1 if not found. */
	s32 findNext(T c, u32 startPos) const
	{
		for (u32 i=startPos; i<used; ++i)
			if (array[i] == c)
				return i;

		return -1;
	}


	//! finds last occurrence of character in string
	//! \param c: Character to search for.
	//! \param start: start to search reverse ( default = -1, on end )
	//! \return Returns position where the character has been found,
	//! or -1 if not found.
	s32 findLast(T c, s32 start = -1) const
	{
		start = core::clamp ( start < 0 ? (s32)(used) - 1 : start, 0, (s32)(used) - 1 );
		for (s32 i=start; i>=0; --i)
			if (array[i] == c)
				return i;

		return -1;
	}

	//! finds another string in this string
	//! \param str: Another string
	//! \return Returns positions where the string has been found, 
	//! or -1 if not found.
	template <class B>
	s32 find(const B* const str) const
	{
		if (str && *str)
		{
			u32 len = 0;

			while (str[len])
				++len;

			if (len > used-1)
				return -1;

			for (u32 i=0; i<used-len; ++i)
			{
				u32 j=0;

				while(str[j] && array[i+j] == str[j])
					++j;

				if (!str[j])
					return i;
			}
		}

		return -1;
	}


	//! Returns a substring
	//! \param begin: Start of substring.
	//! \param length: Length of substring.
	string<T> subString(u32 begin, s32 length) const
	{
		if ((length+begin) > size())
			length = size()-begin;
		if (length <= 0)
			return string<T>("");

		string<T> o;
		o.reserve(length+1);

		for (s32 i=0; i<length; ++i)
			o.array[i] = array[i+begin];

		o.array[length] = 0;
		o.used = o.allocated;

		return o;
	}


	void operator += (T c)
	{
		append(c);
	}

	void operator += (const T* const c)
	{
		append(c);
	}

	void operator += (const string<T>& other)
	{
		append(other);
	}

	void operator += (int i)
	{
		append(string<T>(i));
	}

	void operator += (double i)
	{
		append(string<T>(i));
	}

	//! replaces all characters of a special type with another one
	void replace(T toReplace, T replaceWith)
	{
		for (u32 i=0; i<used; ++i)
			if (array[i] == toReplace)
				array[i] = replaceWith;
	}

	//! trims the string.
	/* Removes whitespace from begin and end of the string. */
	void trim()
	{
		const c8 whitespace[] = " \t\n\r";
		const u32 whitespacecount = 4;

		// find start and end of real string without whitespace
		s32 begin = findFirstCharNotInList(whitespace, whitespacecount);
		if (begin == -1)
		{
			*this="";
			return;
		}

		s32 end = findLastCharNotInList(whitespace, whitespacecount);

		*this = subString(begin, (end +1) - begin);
	}


	//! Erases a character from the string. May be slow, because all elements
	//! following after the erased element have to be copied.
	//! \param index: Index of element to be erased.
	void erase(u32 index)
	{
		_IRR_DEBUG_BREAK_IF(index>=used) // access violation

		for (u32 i=index+1; i<used; ++i)
			array[i-1] = array[i];

		--used;
	}



private:
/*
	T toLower(const T& t) const
	{
		if (t>=(T)'A' && t<=(T)'Z')
			return t + ((T)'a' - (T)'A');
		else
			return t;
	}
*/
	//! Returns a character converted to lower case
	inline T ansi_lower ( u32 x ) const
	{
		return x >= 'A' && x <= 'Z' ? (T) x + 0x20 : (T) x;
	}


	//! Reallocate the array, make it bigger or smaller
	void reallocate(u32 new_size)
	{
		T* old_array = array;

		array = allocator.allocate(new_size); //new T[new_size];
		allocated = new_size;

		u32 amount = used < new_size ? used : new_size;
		for (u32 i=0; i<amount; ++i)
			array[i] = old_array[i];

		if (allocated < used)
			used = allocated;

		allocator.deallocate(old_array); // delete [] old_array;
	}


	//--- member variables

	T* array;
	u32 allocated;
	u32 used;
	TAlloc allocator;
};


//! Typedef for character strings
typedef string<irr::c8> stringc;

//! Typedef for wide character strings
typedef string<wchar_t> stringw;

} // end namespace core
} // end namespace irr

#endif


namespace irr
{
namespace core
{

	//! 4x4 matrix. Mostly used as transformation matrix for 3d calculations.
	/* Matrix4 is mainly used by the Irrlicht engine for doing transformations.
	The matrix is a D3D style matrix, row major with translations in the 4th row.
	*/
	class matrix4
	{
		public:

			//! Constructor Flags
			enum eConstructor
			{
				EM4CONST_NOTHING = 0,
				EM4CONST_COPY,
				EM4CONST_IDENTITY,
				EM4CONST_TRANSPOSED,
				EM4CONST_INVERSE,
				EM4CONST_INVERSE_TRANSPOSED
			};

			matrix4( eConstructor constructor = EM4CONST_IDENTITY );
			matrix4( const matrix4& other,eConstructor constructor = EM4CONST_COPY);

			//! Simple operator for directly accessing every element of the matrix.
			f32& operator()(const s32 row, const s32 col) { definitelyIdentityMatrix=false; return M[ row * 4 + col ]; }

			//! Simple operator for directly accessing every element of the matrix.
			const f32& operator()(const s32 row, const s32 col) const { return M[row * 4 + col]; }

			//! Simple operator for linearly accessing every element of the matrix.
			f32& operator[](u32 index) { definitelyIdentityMatrix=false; return M[index]; }

			//! Simple operator for linearly accessing every element of the matrix.
			const f32& operator[](u32 index) const { return M[index]; }

			//! Sets this matrix equal to the other matrix.
			inline matrix4& operator=(const matrix4 &other);

			//! Sets all elements of this matrix to the value.
			inline matrix4& operator=(const f32 scalar);

			//! Returns pointer to internal array
			const f32* pointer() const { return M; }
			f32* pointer() { definitelyIdentityMatrix=false; return M; }

			//! Returns true if other matrix is equal to this matrix.
			bool operator==(const matrix4 &other) const;

			//! Returns true if other matrix is not equal to this matrix.
			bool operator!=(const matrix4 &other) const;

			//! Add another matrix.
			matrix4 operator+(const matrix4& other) const;

			//! Add another matrix.
			matrix4& operator+=(const matrix4& other);

			//! Subtract another matrix.
			matrix4 operator-(const matrix4& other) const;

			//! Subtract another matrix.
			matrix4& operator-=(const matrix4& other);

			//! set this matrix to the product of two matrices
			inline void setbyproduct(const matrix4& other_a,const matrix4& other_b );

			//! set this matrix to the product of two matrices, no logical optimation
			//! use it if you know you never have a identity matrix
			void setbyproduct_nocheck(const matrix4& other_a,const matrix4& other_b );

			//! Multiply by another matrix.
			matrix4 operator*(const matrix4& other) const;

			//! Multiply by another matrix.
			matrix4& operator*=(const matrix4& other);

			//! Multiply by scalar.
			matrix4 operator*(const f32 scalar) const;

			//! Multiply by scalar.
			matrix4& operator*=(const f32 scalar);

			//! Set matrix to identity.
			inline void makeIdentity();

			//! Returns true if the matrix is the identity matrix
			inline bool isIdentity() const;

			//! Returns true if the matrix is the identity matrix
			bool isIdentity_integer_base () const;

			//! Set the translation of the current matrix. Will erase any previous values.
			void setTranslation( const vector3df& translation );

			//! Gets the current translation
			vector3df getTranslation() const;

			//! Set the inverse translation of the current matrix. Will erase any previous values.
			void setInverseTranslation( const vector3df& translation );

			//! Make a rotation matrix from Euler angles. The 4th row and column are unmodified.
			inline void setRotationRadians( const vector3df& rotation );

			//! Make a rotation matrix from Euler angles. The 4th row and column are unmodified.
			void setRotationDegrees( const vector3df& rotation );

			//! Returns the rotation, as set by setRotation(). This code was orginally written by by Chev.
			core::vector3df getRotationDegrees() const;

			//! Make an inverted rotation matrix from Euler angles. The 4th row and column are unmodified.
			inline void setInverseRotationRadians( const vector3df& rotation );

			//! Make an inverted rotation matrix from Euler angles. The 4th row and column are unmodified.
			void setInverseRotationDegrees( const vector3df& rotation );

			//! Set Scale
			void setScale( const vector3df& scale );

			//! Get Scale
			core::vector3df getScale() const;

			//! Translate a vector by the inverse of the translation part of this matrix.
			void inverseTranslateVect( vector3df& vect ) const;

			//! Rotate a vector by the inverse of the rotation part of this matrix.
			void inverseRotateVect( vector3df& vect ) const;

			//! Rotate a vector by the rotation part of this matrix.
			void rotateVect( vector3df& vect ) const;

			//! Transforms the vector by this matrix
			void transformVect( vector3df& vect) const;

			//! Transforms input vector by this matrix and stores result in output vector
			void transformVect( vector3df& out, const vector3df& in ) const;

			//! An alternate transform vector method, writing into an array of 4 floats
			void transformVect(f32 *out,const core::vector3df &in) const;

			//! An alternate transform vector method, writing into an array of 3 floats
			void rotateVect(f32 *out,const core::vector3df &in) const;

			//! Translate a vector by the translation part of this matrix.
			void translateVect( vector3df& vect ) const;

			//! Transforms a plane by this matrix
			void transformPlane( core::plane3d<f32> &plane) const;

			//! Transforms a plane by this matrix ( some problems to solve..)
			void transformPlane_new( core::plane3d<f32> &plane) const;

			//! Transforms a plane by this matrix
			void transformPlane( const core::plane3d<f32> &in, core::plane3d<f32> &out) const;

			//! Transforms a axis aligned bounding box
			/* The result box of this operation may not be very accurate. For
			accurate results, use transformBoxEx() */
			void transformBox(core::aabbox3d<f32>& box) const;

			//! Transforms a axis aligned bounding box more accurately than transformBox()
			/* The result box of this operation should by quite accurate, but this operation
			is slower than transformBox(). */
			void transformBoxEx(core::aabbox3d<f32>& box) const;

			//! Multiplies this matrix by a 1x4 matrix
			void multiplyWith1x4Matrix(f32* matrix) const;

			//! Calculates inverse of matrix. Slow.
			//! \return Returns false if there is no inverse matrix.
			bool makeInverse();


			//! Inverts a primitive matrix which only contains a translation and a rotation
			//! \param out: where result matrix is written to.
			bool getInversePrimitive ( matrix4& out ) const;

			//! returns the inversed matrix of this one
			//! \param out: where result matrix is written to.
			//! \return Returns false if there is no inverse matrix.
			bool getInverse(matrix4& out) const;

			//! Builds a right-handed perspective projection matrix based on a field of view
			void buildProjectionMatrixPerspectiveFovRH(f32 fieldOfViewRadians, f32 aspectRatio, f32 zNear, f32 zFar);

			//! Builds a left-handed perspective projection matrix based on a field of view
			void buildProjectionMatrixPerspectiveFovLH(f32 fieldOfViewRadians, f32 aspectRatio, f32 zNear, f32 zFar);

			//! Builds a right-handed perspective projection matrix.
			void buildProjectionMatrixPerspectiveRH(f32 widthOfViewVolume, f32 heightOfViewVolume, f32 zNear, f32 zFar);

			//! Builds a left-handed perspective projection matrix.
			void buildProjectionMatrixPerspectiveLH(f32 widthOfViewVolume, f32 heightOfViewVolume, f32 zNear, f32 zFar);

			//! Builds a left-handed orthogonal projection matrix.
			void buildProjectionMatrixOrthoLH(f32 widthOfViewVolume, f32 heightOfViewVolume, f32 zNear, f32 zFar);

			//! Builds a right-handed orthogonal projection matrix.
			void buildProjectionMatrixOrthoRH(f32 widthOfViewVolume, f32 heightOfViewVolume, f32 zNear, f32 zFar);

			//! Builds a left-handed look-at matrix.
			void buildCameraLookAtMatrixLH(const vector3df& position, const vector3df& target, const vector3df& upVector);

			//! Builds a right-handed look-at matrix.
			void buildCameraLookAtMatrixRH(const vector3df& position, const vector3df& target, const vector3df& upVector);

			//! Builds a matrix that flattens geometry into a plane.
			//! \param light: light source
			//! \param plane: plane into which the geometry if flattened into
			//! \param point: value between 0 and 1, describing the light source.
			//! If this is 1, it is a point light, if it is 0, it is a directional light.
			void buildShadowMatrix(const core::vector3df& light, core::plane3df plane, f32 point=1.0f);

			//! Builds a matrix which transforms a normalized Device Coordinate to Device Coordinates.
			/* Used to scale <-1,-1><1,1> to viewport, for example from von <-1,-1> <1,1> to the viewport <0,0><0,640> */
			void buildNDCToDCMatrix( const core::rect<s32>& area, f32 zScale);

			//! creates a new matrix as interpolated matrix from two other ones.
			//! \param b: other matrix to interpolate with
			//! \param time: Must be a value between 0 and 1.
			matrix4 interpolate(const core::matrix4& b, f32 time) const;

			//! returns transposed matrix
			matrix4 getTransposed() const;

			//! returns transposed matrix to a plain 4x4 float matrix
			inline void getTransposed( matrix4& dest ) const;

			/*!
				construct 2D Texture transformations
				rotate about center, scale, and transform.
			*/
			void setTextureScale ( f32 sx, f32 sy );

			void setTextureRotationCenter( f32 radAngle );
			void setTextureScaleCenter( f32 sx, f32 sy );

			void setTextureTranslate ( f32 x, f32 y );

			void buildTextureTransform( f32 rotateRad,
					const core::vector2df &rotatecenter,
					const core::vector2df &translate,
					const core::vector2df &scale);

		private:
			//! Matrix data, stored in row-major order
			f32 M[16];
			bool definitelyIdentityMatrix;
	};

	inline matrix4::matrix4( matrix4::eConstructor constructor ) : definitelyIdentityMatrix(false)
	{
		switch ( constructor )
		{
			case EM4CONST_NOTHING:
			case EM4CONST_COPY:
				break;
			case EM4CONST_IDENTITY:
			case EM4CONST_INVERSE:
			default:
				makeIdentity();
				break;
		}
	}

	inline matrix4::matrix4( const matrix4& other,matrix4::eConstructor constructor) : definitelyIdentityMatrix(false)
	{
		switch ( constructor )
		{
			case EM4CONST_IDENTITY:
				makeIdentity();
				break;
			case EM4CONST_NOTHING:
				break;
			case EM4CONST_COPY:
				*this = other;
				break;
			case EM4CONST_TRANSPOSED:
				other.getTransposed(*this);
				break;
			case EM4CONST_INVERSE:
				if (!other.getInverse(*this))
					memset(M, 0, 16*sizeof(f32));
				break;
			case EM4CONST_INVERSE_TRANSPOSED:
				if (!other.getInverse(*this))
					memset(M, 0, 16*sizeof(f32));
				else
					*this=getTransposed();
				break;
		}
	}

	//! Add another matrix.
	inline matrix4 matrix4::operator+(const matrix4& other) const
	{
		matrix4 temp ( EM4CONST_NOTHING );

		temp[0] = M[0]+other[0];
		temp[1] = M[1]+other[1];
		temp[2] = M[2]+other[2];
		temp[3] = M[3]+other[3];
		temp[4] = M[4]+other[4];
		temp[5] = M[5]+other[5];
		temp[6] = M[6]+other[6];
		temp[7] = M[7]+other[7];
		temp[8] = M[8]+other[8];
		temp[9] = M[9]+other[9];
		temp[10] = M[10]+other[10];
		temp[11] = M[11]+other[11];
		temp[12] = M[12]+other[12];
		temp[13] = M[13]+other[13];
		temp[14] = M[14]+other[14];
		temp[15] = M[15]+other[15];

		return temp;
	}

	//! Add another matrix.
	inline matrix4& matrix4::operator+=(const matrix4& other)
	{
		M[0]+=other[0];
		M[1]+=other[1];
		M[2]+=other[2];
		M[3]+=other[3];
		M[4]+=other[4];
		M[5]+=other[5];
		M[6]+=other[6];
		M[7]+=other[7];
		M[8]+=other[8];
		M[9]+=other[9];
		M[10]+=other[10];
		M[11]+=other[11];
		M[12]+=other[12];
		M[13]+=other[13];
		M[14]+=other[14];
		M[15]+=other[15];

		return *this;
		matrix4 temp ( *this );
		setbyproduct ( temp, other );
		return *this;
	}

	//! Subtract another matrix.
	inline matrix4 matrix4::operator-(const matrix4& other) const
	{
		matrix4 temp ( EM4CONST_NOTHING );

		temp[0] = M[0]-other[0];
		temp[1] = M[1]-other[1];
		temp[2] = M[2]-other[2];
		temp[3] = M[3]-other[3];
		temp[4] = M[4]-other[4];
		temp[5] = M[5]-other[5];
		temp[6] = M[6]-other[6];
		temp[7] = M[7]-other[7];
		temp[8] = M[8]-other[8];
		temp[9] = M[9]-other[9];
		temp[10] = M[10]-other[10];
		temp[11] = M[11]-other[11];
		temp[12] = M[12]-other[12];
		temp[13] = M[13]-other[13];
		temp[14] = M[14]-other[14];
		temp[15] = M[15]-other[15];

		return temp;
	}

	//! Subtract another matrix.
	inline matrix4& matrix4::operator-=(const matrix4& other)
	{
		M[0]-=other[0];
		M[1]-=other[1];
		M[2]-=other[2];
		M[3]-=other[3];
		M[4]-=other[4];
		M[5]-=other[5];
		M[6]-=other[6];
		M[7]-=other[7];
		M[8]-=other[8];
		M[9]-=other[9];
		M[10]-=other[10];
		M[11]-=other[11];
		M[12]-=other[12];
		M[13]-=other[13];
		M[14]-=other[14];
		M[15]-=other[15];

		return *this;
	}

	//! Multiply by scalar.
	inline matrix4 matrix4::operator*(const f32 scalar) const
	{
		matrix4 temp ( EM4CONST_NOTHING );

		temp[0] = M[0]*scalar;
		temp[1] = M[1]*scalar;
		temp[2] = M[2]*scalar;
		temp[3] = M[3]*scalar;
		temp[4] = M[4]*scalar;
		temp[5] = M[5]*scalar;
		temp[6] = M[6]*scalar;
		temp[7] = M[7]*scalar;
		temp[8] = M[8]*scalar;
		temp[9] = M[9]*scalar;
		temp[10] = M[10]*scalar;
		temp[11] = M[11]*scalar;
		temp[12] = M[12]*scalar;
		temp[13] = M[13]*scalar;
		temp[14] = M[14]*scalar;
		temp[15] = M[15]*scalar;

		return temp;
	}

	//! Multiply by scalar.
	inline matrix4& matrix4::operator*=(const f32 scalar)
	{
		M[0]*=scalar;
		M[1]*=scalar;
		M[2]*=scalar;
		M[3]*=scalar;
		M[4]*=scalar;
		M[5]*=scalar;
		M[6]*=scalar;
		M[7]*=scalar;
		M[8]*=scalar;
		M[9]*=scalar;
		M[10]*=scalar;
		M[11]*=scalar;
		M[12]*=scalar;
		M[13]*=scalar;
		M[14]*=scalar;
		M[15]*=scalar;

		return *this;
	}

	//! Multiply by another matrix.
	inline matrix4& matrix4::operator*=(const matrix4& other)
	{
		matrix4 temp ( *this );
		setbyproduct ( temp, other );
		return *this;
	}

	//! multiply by another matrix
	// set this matrix to the product of two other matrices
	// goal is to reduce stack use and copy
	inline void matrix4::setbyproduct_nocheck(const matrix4& other_a,const matrix4& other_b )
	{
		const f32 *m1 = other_a.M;
		const f32 *m2 = other_b.M;

		M[0] = m1[0]*m2[0] + m1[4]*m2[1] + m1[8]*m2[2] + m1[12]*m2[3];
		M[1] = m1[1]*m2[0] + m1[5]*m2[1] + m1[9]*m2[2] + m1[13]*m2[3];
		M[2] = m1[2]*m2[0] + m1[6]*m2[1] + m1[10]*m2[2] + m1[14]*m2[3];
		M[3] = m1[3]*m2[0] + m1[7]*m2[1] + m1[11]*m2[2] + m1[15]*m2[3];

		M[4] = m1[0]*m2[4] + m1[4]*m2[5] + m1[8]*m2[6] + m1[12]*m2[7];
		M[5] = m1[1]*m2[4] + m1[5]*m2[5] + m1[9]*m2[6] + m1[13]*m2[7];
		M[6] = m1[2]*m2[4] + m1[6]*m2[5] + m1[10]*m2[6] + m1[14]*m2[7];
		M[7] = m1[3]*m2[4] + m1[7]*m2[5] + m1[11]*m2[6] + m1[15]*m2[7];

		M[8] = m1[0]*m2[8] + m1[4]*m2[9] + m1[8]*m2[10] + m1[12]*m2[11];
		M[9] = m1[1]*m2[8] + m1[5]*m2[9] + m1[9]*m2[10] + m1[13]*m2[11];
		M[10] = m1[2]*m2[8] + m1[6]*m2[9] + m1[10]*m2[10] + m1[14]*m2[11];
		M[11] = m1[3]*m2[8] + m1[7]*m2[9] + m1[11]*m2[10] + m1[15]*m2[11];

		M[12] = m1[0]*m2[12] + m1[4]*m2[13] + m1[8]*m2[14] + m1[12]*m2[15];
		M[13] = m1[1]*m2[12] + m1[5]*m2[13] + m1[9]*m2[14] + m1[13]*m2[15];
		M[14] = m1[2]*m2[12] + m1[6]*m2[13] + m1[10]*m2[14] + m1[14]*m2[15];
		M[15] = m1[3]*m2[12] + m1[7]*m2[13] + m1[11]*m2[14] + m1[15]*m2[15];
		definitelyIdentityMatrix=false;
	}


	//! multiply by another matrix
	// set this matrix to the product of two other matrices
	// goal is to reduce stack use and copy
	inline void matrix4::setbyproduct(const matrix4& other_a,const matrix4& other_b )
	{
		if ( other_a.isIdentity () )
		{
			*this = other_b;
			return;
		}
		else
		if ( other_b.isIdentity () )
		{
			*this = other_a;
			return;
		}
		setbyproduct_nocheck(other_a,other_b);
	}

	//! multiply by another matrix
	inline matrix4 matrix4::operator*(const matrix4& m2) const
	{
		// Testing purpose.. 
		if ( this->isIdentity() )
			return m2;
		if ( m2.isIdentity() )
			return *this;

		matrix4 m3 ( EM4CONST_NOTHING );

		const f32 *m1 = M;

		m3[0] = m1[0]*m2[0] + m1[4]*m2[1] + m1[8]*m2[2] + m1[12]*m2[3];
		m3[1] = m1[1]*m2[0] + m1[5]*m2[1] + m1[9]*m2[2] + m1[13]*m2[3];
		m3[2] = m1[2]*m2[0] + m1[6]*m2[1] + m1[10]*m2[2] + m1[14]*m2[3];
		m3[3] = m1[3]*m2[0] + m1[7]*m2[1] + m1[11]*m2[2] + m1[15]*m2[3];

		m3[4] = m1[0]*m2[4] + m1[4]*m2[5] + m1[8]*m2[6] + m1[12]*m2[7];
		m3[5] = m1[1]*m2[4] + m1[5]*m2[5] + m1[9]*m2[6] + m1[13]*m2[7];
		m3[6] = m1[2]*m2[4] + m1[6]*m2[5] + m1[10]*m2[6] + m1[14]*m2[7];
		m3[7] = m1[3]*m2[4] + m1[7]*m2[5] + m1[11]*m2[6] + m1[15]*m2[7];

		m3[8] = m1[0]*m2[8] + m1[4]*m2[9] + m1[8]*m2[10] + m1[12]*m2[11];
		m3[9] = m1[1]*m2[8] + m1[5]*m2[9] + m1[9]*m2[10] + m1[13]*m2[11];
		m3[10] = m1[2]*m2[8] + m1[6]*m2[9] + m1[10]*m2[10] + m1[14]*m2[11];
		m3[11] = m1[3]*m2[8] + m1[7]*m2[9] + m1[11]*m2[10] + m1[15]*m2[11];

		m3[12] = m1[0]*m2[12] + m1[4]*m2[13] + m1[8]*m2[14] + m1[12]*m2[15];
		m3[13] = m1[1]*m2[12] + m1[5]*m2[13] + m1[9]*m2[14] + m1[13]*m2[15];
		m3[14] = m1[2]*m2[12] + m1[6]*m2[13] + m1[10]*m2[14] + m1[14]*m2[15];
		m3[15] = m1[3]*m2[12] + m1[7]*m2[13] + m1[11]*m2[14] + m1[15]*m2[15];
		return m3;
	}



	inline vector3df matrix4::getTranslation() const
	{
		return vector3df(M[12], M[13], M[14]);
	}


	inline void matrix4::setTranslation( const vector3df& translation )
	{
		M[12] = translation.X;
		M[13] = translation.Y;
		M[14] = translation.Z;
		definitelyIdentityMatrix=false;
	}

	inline void matrix4::setInverseTranslation( const vector3df& translation )
	{
		M[12] = -translation.X;
		M[13] = -translation.Y;
		M[14] = -translation.Z;
		definitelyIdentityMatrix=false;
	}

	inline void matrix4::setScale( const vector3df& scale )
	{
		M[0] = scale.X;
		M[5] = scale.Y;
		M[10] = scale.Z;
		definitelyIdentityMatrix=false;
	}

	inline vector3df matrix4::getScale() const
	{
		return vector3df(M[0],M[5],M[10]);
	}

	inline void matrix4::setRotationDegrees( const vector3df& rotation )
	{
		setRotationRadians( rotation * core::DEGTORAD );
	}

	inline void matrix4::setInverseRotationDegrees( const vector3df& rotation )
	{
		setInverseRotationRadians( rotation * core::DEGTORAD );
	}

	inline void matrix4::setRotationRadians( const vector3df& rotation )
	{
		f64 cr = cos( rotation.X );
		f64 sr = sin( rotation.X );
		f64 cp = cos( rotation.Y );
		f64 sp = sin( rotation.Y );
		f64 cy = cos( rotation.Z );
		f64 sy = sin( rotation.Z );

		M[0] = (f32)( cp*cy );
		M[1] = (f32)( cp*sy );
		M[2] = (f32)( -sp );

		f64 srsp = sr*sp;
		f64 crsp = cr*sp;

		M[4] = (f32)( srsp*cy-cr*sy );
		M[5] = (f32)( srsp*sy+cr*cy );
		M[6] = (f32)( sr*cp );

		M[8] = (f32)( crsp*cy+sr*sy );
		M[9] = (f32)( crsp*sy-sr*cy );
		M[10] = (f32)( cr*cp );
		definitelyIdentityMatrix=false;
	}



	//! Returns the rotation, as set by setRotation(). This code was sent
	//! in by Chev.
	inline core::vector3df matrix4::getRotationDegrees() const
	{
		const matrix4 &mat = *this;

		f64 Y = -asin(mat(0,2));
		f64 C = cos(Y);
		Y *= RADTODEG64;

		f64 rotx, roty, X, Z;

		if (fabs(C)>0.0005f)
		{
			rotx = mat(2,2) / C;
			roty = mat(1,2) / C;
			X = atan2( roty, rotx ) * RADTODEG64;
			rotx = mat(0,0) / C;
			roty = mat(0,1) / C;
			Z = atan2( roty, rotx ) * RADTODEG64;
		}
		else
		{
			X = 0.0f;
			rotx = mat(1,1);
			roty = -mat(1,0);
			Z = atan2( roty, rotx ) * RADTODEG64;
		}

		// fix values that get below zero
		// before it would set (!) values to 360
		// that where above 360:
		if (X < 0.0) X += 360.0;
		if (Y < 0.0) Y += 360.0;
		if (Z < 0.0) Z += 360.0;

		return vector3df((f32)X,(f32)Y,(f32)Z);
	}

	inline void matrix4::setInverseRotationRadians( const vector3df& rotation )
	{
		f64 cr = cos( rotation.X );
		f64 sr = sin( rotation.X );
		f64 cp = cos( rotation.Y );
		f64 sp = sin( rotation.Y );
		f64 cy = cos( rotation.Z );
		f64 sy = sin( rotation.Z );

		M[0] = (f32)( cp*cy );
		M[4] = (f32)( cp*sy );
		M[8] = (f32)( -sp );

		f64 srsp = sr*sp;
		f64 crsp = cr*sp;

		M[1] = (f32)( srsp*cy-cr*sy );
		M[5] = (f32)( srsp*sy+cr*cy );
		M[9] = (f32)( sr*cp );

		M[2] = (f32)( crsp*cy+sr*sy );
		M[6] = (f32)( crsp*sy-sr*cy );
		M[10] = (f32)( cr*cp );
		definitelyIdentityMatrix=false;
	}


	/*!
	*/
	inline void matrix4::makeIdentity()
	{
		memset(M, 0, 16*sizeof(f32));
		M[0] = M[5] = M[10] = M[15] = 1.0f;
		definitelyIdentityMatrix=true;
	}


	/*
		check identity with epsilon
		solve floating range problems..
	*/
	inline bool matrix4::isIdentity() const
	{
		if (definitelyIdentityMatrix)
			return true;
		if (	!equals ( M[ 0], 1.f ) ||
				!equals ( M[ 5], 1.f ) ||
				!equals ( M[10], 1.f ) ||
				!equals ( M[15], 1.f )
			)
			return false;

		for (s32 i=0; i<4; ++i)
			for (s32 j=0; j<4; ++j)
			if (j != i)
			{
				if ((*this)(i,j) < -ROUNDING_ERROR_32||
					(*this)(i,j) > ROUNDING_ERROR_32)
					return false;
			}
		return true;
	}

	/*
		doesn't solve floating range problems..
		but takes care on +/- 0 on translation because we are changing it..
		reducing floating point branches
		but it need's the floats in memory..
	*/
	inline bool matrix4::isIdentity_integer_base() const
	{
		if (definitelyIdentityMatrix)
			return true;
		if(IR(M[0])!=F32_VALUE_1)	return false;
		if(IR(M[1])!=0)			return false;
		if(IR(M[2])!=0)			return false;
		if(IR(M[3])!=0)			return false;

		if(IR(M[4])!=0)			return false;
		if(IR(M[5])!=F32_VALUE_1)	return false;
		if(IR(M[6])!=0)			return false;
		if(IR(M[7])!=0)			return false;

		if(IR(M[8])!=0)			return false;
		if(IR(M[9])!=0)			return false;
		if(IR(M[10])!=F32_VALUE_1)	return false;
		if(IR(M[11])!=0)		return false;

		if(IR(M[12])!=0)		return false;
		if(IR(M[13])!=0)		return false;
		if(IR(M[13])!=0)		return false;
		if(IR(M[15])!=F32_VALUE_1)	return false;
		return true;
	}



	inline void matrix4::rotateVect( vector3df& vect ) const
	{
		vector3df tmp = vect;
		vect.X = tmp.X*M[0] + tmp.Y*M[4] + tmp.Z*M[8];
		vect.Y = tmp.X*M[1] + tmp.Y*M[5] + tmp.Z*M[9];
		vect.Z = tmp.X*M[2] + tmp.Y*M[6] + tmp.Z*M[10];
	}

	//! An alternate transform vector method, writing into an array of 3 floats
	inline void matrix4::rotateVect(f32 *out,const core::vector3df &in) const
	{
		out[0] = in.X*M[0] + in.Y*M[4] + in.Z*M[8];
		out[1] = in.X*M[1] + in.Y*M[5] + in.Z*M[9];
		out[2] = in.X*M[2] + in.Y*M[6] + in.Z*M[10];
	}

	inline void matrix4::inverseRotateVect( vector3df& vect ) const
	{
		vector3df tmp = vect;
		vect.X = tmp.X*M[0] + tmp.Y*M[1] + tmp.Z*M[2];
		vect.Y = tmp.X*M[4] + tmp.Y*M[5] + tmp.Z*M[6];
		vect.Z = tmp.X*M[8] + tmp.Y*M[9] + tmp.Z*M[10];
	}

	inline void matrix4::transformVect( vector3df& vect) const
	{
		f32 vector[3];

		vector[0] = vect.X*M[0] + vect.Y*M[4] + vect.Z*M[8] + M[12];
		vector[1] = vect.X*M[1] + vect.Y*M[5] + vect.Z*M[9] + M[13];
		vector[2] = vect.X*M[2] + vect.Y*M[6] + vect.Z*M[10] + M[14];

		vect.X = vector[0];
		vect.Y = vector[1];
		vect.Z = vector[2];
	}

	inline void matrix4::transformVect( vector3df& out, const vector3df& in) const
	{
		out.X = in.X*M[0] + in.Y*M[4] + in.Z*M[8] + M[12];
		out.Y = in.X*M[1] + in.Y*M[5] + in.Z*M[9] + M[13];
		out.Z = in.X*M[2] + in.Y*M[6] + in.Z*M[10] + M[14];
	}


	// transform (x,y,z,1)
	inline void matrix4::transformVect(f32 *out,const vector3df &in) const
	{
		out[0] = in.X*M[0] + in.Y*M[4] + in.Z*M[8] + M[12];
		out[1] = in.X*M[1] + in.Y*M[5] + in.Z*M[9] + M[13];
		out[2] = in.X*M[2] + in.Y*M[6] + in.Z*M[10] + M[14];
		out[3] = in.X*M[3] + in.Y*M[7] + in.Z*M[11] + M[15];
	}


	//! Transforms a plane by this matrix
	inline void matrix4::transformPlane( core::plane3d<f32> &plane) const
	{
		vector3df member;
		transformVect(member, plane.getMemberPoint());

		vector3df origin(0,0,0);
		transformVect(plane.Normal);
		transformVect(origin);

		plane.Normal -= origin;
		plane.D = - member.dotProduct(plane.Normal);
	}

	//! Transforms a plane by this matrix
	inline void matrix4::transformPlane_new( core::plane3d<f32> &plane) const
	{
		// rotate normal -> rotateVect ( plane.n );
		vector3df n;
		n.X = plane.Normal.X*M[0] + plane.Normal.Y*M[4] + plane.Normal.Z*M[8];
		n.Y = plane.Normal.X*M[1] + plane.Normal.Y*M[5] + plane.Normal.Z*M[9];
		n.Z = plane.Normal.X*M[2] + plane.Normal.Y*M[6] + plane.Normal.Z*M[10];

		// compute new d. -> getTranslation(). dotproduct ( plane.n )
		plane.D -= M[12] * n.X + M[13] * n.Y + M[14] * n.Z;
		plane.Normal.X = n.X;
		plane.Normal.Y = n.Y;
		plane.Normal.Z = n.Z;
	}

	//! Transforms a plane by this matrix
	inline void matrix4::transformPlane( const core::plane3d<f32> &in, core::plane3d<f32> &out) const
	{
		out = in;
		transformPlane( out );
	}

	//! Transforms a axis aligned bounding box
	inline void matrix4::transformBox(core::aabbox3d<f32>& box) const
	{
		if (isIdentity() )
			return;

		transformVect(box.MinEdge);
		transformVect(box.MaxEdge);
		box.repair();
	}

	//! Transforms a axis aligned bounding box more accurately than transformBox()
	inline void matrix4::transformBoxEx(core::aabbox3d<f32>& box) const
	{
		f32 Amin[3];
		f32 Amax[3];
		f32 Bmin[3];
		f32 Bmax[3];
 
		Amin[0] = box.MinEdge.X;
		Amin[1] = box.MinEdge.Y;
		Amin[2] = box.MinEdge.Z;

		Amax[0] = box.MaxEdge.X;
		Amax[1] = box.MaxEdge.Y;
		Amax[2] = box.MaxEdge.Z;

		Bmin[0] = Bmax[0] = M[12];
		Bmin[1] = Bmax[1] = M[13];
		Bmin[2] = Bmax[2] = M[14];

		u32 i, j;
		const matrix4 &m = *this;

		for (i = 0; i < 3; ++i) 
		{
			for (j = 0; j < 3; ++j) 
			{
				f32 a = m(j,i) * Amin[j];
				f32 b = m(j,i) * Amax[j];

				if (a < b)
				{
					Bmin[i] += a;
					Bmax[i] += b;
				}
				else
				{
					Bmin[i] += b;
					Bmax[i] += a;
				}
			}
		}

		box.MinEdge.X = Bmin[0];
		box.MinEdge.Y = Bmin[1];
		box.MinEdge.Z = Bmin[2];

		box.MaxEdge.X = Bmax[0];
		box.MaxEdge.Y = Bmax[1];
		box.MaxEdge.Z = Bmax[2];
	}


	//! Multiplies this matrix by a 1x4 matrix
	inline void matrix4::multiplyWith1x4Matrix(f32* matrix) const
	{
		/*
		0  1  2  3
		4  5  6  7
		8  9  10 11
		12 13 14 15
		*/

		f32 mat[4];
		mat[0] = matrix[0];
		mat[1] = matrix[1];
		mat[2] = matrix[2];
		mat[3] = matrix[3];

		matrix[0] = M[0]*mat[0] + M[4]*mat[1] + M[8]*mat[2] + M[12]*mat[3];
		matrix[1] = M[1]*mat[0] + M[5]*mat[1] + M[9]*mat[2] + M[13]*mat[3];
		matrix[2] = M[2]*mat[0] + M[6]*mat[1] + M[10]*mat[2] + M[14]*mat[3];
		matrix[3] = M[3]*mat[0] + M[7]*mat[1] + M[11]*mat[2] + M[15]*mat[3];
	}

	inline void matrix4::inverseTranslateVect( vector3df& vect ) const
	{
		vect.X = vect.X-M[12];
		vect.Y = vect.Y-M[13];
		vect.Z = vect.Z-M[14];
	}

	inline void matrix4::translateVect( vector3df& vect ) const
	{
		vect.X = vect.X+M[12];
		vect.Y = vect.Y+M[13];
		vect.Z = vect.Z+M[14];
	}


	inline bool matrix4::getInverse(matrix4& out) const
	{
		/// Calculates the inverse of this Matrix
		/// The inverse is calculated using Cramers rule.
		/// If no inverse exists then 'false' is returned.

		const matrix4 &m = *this;

		f32 d = (m(0, 0) * m(1, 1) - m(0, 1) * m(1, 0)) * (m(2, 2) * m(3, 3) - m(2, 3) * m(3, 2)) -
			(m(0, 0) * m(1, 2) - m(0, 2) * m(1, 0)) * (m(2, 1) * m(3, 3) - m(2, 3) * m(3, 1)) +
			(m(0, 0) * m(1, 3) - m(0, 3) * m(1, 0)) * (m(2, 1) * m(3, 2) - m(2, 2) * m(3, 1)) +
			(m(0, 1) * m(1, 2) - m(0, 2) * m(1, 1)) * (m(2, 0) * m(3, 3) - m(2, 3) * m(3, 0)) -
			(m(0, 1) * m(1, 3) - m(0, 3) * m(1, 1)) * (m(2, 0) * m(3, 2) - m(2, 2) * m(3, 0)) +
			(m(0, 2) * m(1, 3) - m(0, 3) * m(1, 2)) * (m(2, 0) * m(3, 1) - m(2, 1) * m(3, 0));

		if( core::iszero ( d ) )
			return false;

		d = core::reciprocal ( d );

		out(0, 0) = d * (m(1, 1) * (m(2, 2) * m(3, 3) - m(2, 3) * m(3, 2)) + m(1, 2) * (m(2, 3) * m(3, 1) - m(2, 1) * m(3, 3)) + m(1, 3) * (m(2, 1) * m(3, 2) - m(2, 2) * m(3, 1)));
		out(0, 1) = d * (m(2, 1) * (m(0, 2) * m(3, 3) - m(0, 3) * m(3, 2)) + m(2, 2) * (m(0, 3) * m(3, 1) - m(0, 1) * m(3, 3)) + m(2, 3) * (m(0, 1) * m(3, 2) - m(0, 2) * m(3, 1)));
		out(0, 2) = d * (m(3, 1) * (m(0, 2) * m(1, 3) - m(0, 3) * m(1, 2)) + m(3, 2) * (m(0, 3) * m(1, 1) - m(0, 1) * m(1, 3)) + m(3, 3) * (m(0, 1) * m(1, 2) - m(0, 2) * m(1, 1)));
		out(0, 3) = d * (m(0, 1) * (m(1, 3) * m(2, 2) - m(1, 2) * m(2, 3)) + m(0, 2) * (m(1, 1) * m(2, 3) - m(1, 3) * m(2, 1)) + m(0, 3) * (m(1, 2) * m(2, 1) - m(1, 1) * m(2, 2)));
		out(1, 0) = d * (m(1, 2) * (m(2, 0) * m(3, 3) - m(2, 3) * m(3, 0)) + m(1, 3) * (m(2, 2) * m(3, 0) - m(2, 0) * m(3, 2)) + m(1, 0) * (m(2, 3) * m(3, 2) - m(2, 2) * m(3, 3)));
		out(1, 1) = d * (m(2, 2) * (m(0, 0) * m(3, 3) - m(0, 3) * m(3, 0)) + m(2, 3) * (m(0, 2) * m(3, 0) - m(0, 0) * m(3, 2)) + m(2, 0) * (m(0, 3) * m(3, 2) - m(0, 2) * m(3, 3)));
		out(1, 2) = d * (m(3, 2) * (m(0, 0) * m(1, 3) - m(0, 3) * m(1, 0)) + m(3, 3) * (m(0, 2) * m(1, 0) - m(0, 0) * m(1, 2)) + m(3, 0) * (m(0, 3) * m(1, 2) - m(0, 2) * m(1, 3)));
		out(1, 3) = d * (m(0, 2) * (m(1, 3) * m(2, 0) - m(1, 0) * m(2, 3)) + m(0, 3) * (m(1, 0) * m(2, 2) - m(1, 2) * m(2, 0)) + m(0, 0) * (m(1, 2) * m(2, 3) - m(1, 3) * m(2, 2)));
		out(2, 0) = d * (m(1, 3) * (m(2, 0) * m(3, 1) - m(2, 1) * m(3, 0)) + m(1, 0) * (m(2, 1) * m(3, 3) - m(2, 3) * m(3, 1)) + m(1, 1) * (m(2, 3) * m(3, 0) - m(2, 0) * m(3, 3)));
		out(2, 1) = d * (m(2, 3) * (m(0, 0) * m(3, 1) - m(0, 1) * m(3, 0)) + m(2, 0) * (m(0, 1) * m(3, 3) - m(0, 3) * m(3, 1)) + m(2, 1) * (m(0, 3) * m(3, 0) - m(0, 0) * m(3, 3)));
		out(2, 2) = d * (m(3, 3) * (m(0, 0) * m(1, 1) - m(0, 1) * m(1, 0)) + m(3, 0) * (m(0, 1) * m(1, 3) - m(0, 3) * m(1, 1)) + m(3, 1) * (m(0, 3) * m(1, 0) - m(0, 0) * m(1, 3)));
		out(2, 3) = d * (m(0, 3) * (m(1, 1) * m(2, 0) - m(1, 0) * m(2, 1)) + m(0, 0) * (m(1, 3) * m(2, 1) - m(1, 1) * m(2, 3)) + m(0, 1) * (m(1, 0) * m(2, 3) - m(1, 3) * m(2, 0)));
		out(3, 0) = d * (m(1, 0) * (m(2, 2) * m(3, 1) - m(2, 1) * m(3, 2)) + m(1, 1) * (m(2, 0) * m(3, 2) - m(2, 2) * m(3, 0)) + m(1, 2) * (m(2, 1) * m(3, 0) - m(2, 0) * m(3, 1)));
		out(3, 1) = d * (m(2, 0) * (m(0, 2) * m(3, 1) - m(0, 1) * m(3, 2)) + m(2, 1) * (m(0, 0) * m(3, 2) - m(0, 2) * m(3, 0)) + m(2, 2) * (m(0, 1) * m(3, 0) - m(0, 0) * m(3, 1)));
		out(3, 2) = d * (m(3, 0) * (m(0, 2) * m(1, 1) - m(0, 1) * m(1, 2)) + m(3, 1) * (m(0, 0) * m(1, 2) - m(0, 2) * m(1, 0)) + m(3, 2) * (m(0, 1) * m(1, 0) - m(0, 0) * m(1, 1)));
		out(3, 3) = d * (m(0, 0) * (m(1, 1) * m(2, 2) - m(1, 2) * m(2, 1)) + m(0, 1) * (m(1, 2) * m(2, 0) - m(1, 0) * m(2, 2)) + m(0, 2) * (m(1, 0) * m(2, 1) - m(1, 1) * m(2, 0)));
		out.definitelyIdentityMatrix = definitelyIdentityMatrix;
		return true;
	}


	//! Inverts a primitive matrix which only contains a translation and a rotation
	//! \param out: where result matrix is written to.
	inline bool matrix4::getInversePrimitive ( matrix4& out ) const
	{
		out.M[0 ]	= M[0];
		out.M[1 ]	= M[4];
		out.M[2 ]	= M[8];
		out.M[3 ]	= 0.0f;

		out.M[4 ]	= M[1];
		out.M[5 ]	= M[5];
		out.M[6 ]	= M[9];
		out.M[7 ]	= 0.0f;

		out.M[8 ]	= M[2];
		out.M[9 ]	= M[6];
		out.M[10]	= M[10];
		out.M[11]	= 0.0f;

		out.M[12]	= -(M[12]*M[0] + M[13]*M[1] + M[14]*M[2]);
		out.M[13]	= -(M[12]*M[4] + M[13]*M[5] + M[14]*M[6]);
		out.M[14]	= -(M[12]*M[8] + M[13]*M[9] + M[14]*M[10]);
		out.M[15]	= 1.0f;
		out.definitelyIdentityMatrix = definitelyIdentityMatrix;
		return true;
	}

	/*!
	*/
	inline bool matrix4::makeInverse()
	{
		matrix4 temp ( EM4CONST_NOTHING );

		if (getInverse(temp))
		{
			*this = temp;
			return true;
		}

		return false;
	}



	inline matrix4& matrix4::operator=(const matrix4 &other)
	{
		if (this==&other)
			return *this;
		memcpy(M, other.M, 16*sizeof(f32));
		definitelyIdentityMatrix=other.definitelyIdentityMatrix;
		return *this;
	}



	inline bool matrix4::operator==(const matrix4 &other) const
	{
		if (definitelyIdentityMatrix && other.definitelyIdentityMatrix)
			return true;
		for (s32 i = 0; i < 16; ++i)
			if (M[i] != other.M[i])
				return false;

		return true;
	}



	inline bool matrix4::operator!=(const matrix4 &other) const
	{
		return !(*this == other);
	}



	//! Builds a right-handed perspective projection matrix based on a field of view
	inline void matrix4::buildProjectionMatrixPerspectiveFovRH(f32 fieldOfViewRadians, f32 aspectRatio, f32 zNear, f32 zFar)
	{
		f32 h = (f32)(1.0/tan(fieldOfViewRadians/2.0));
		f32 w = h / aspectRatio;

		M[0] = w;
		M[1] = 0.0f;
		M[2] = 0.0f;
		M[3] = 0.0f;

		M[4] = 0.0f;
		M[5] = h;
		M[6] = 0.0f;
		M[7] = 0.0f;

		M[8] = 0.0f;
		M[9] = 0.0f;
		M[10] = zFar/(zNear-zFar); // DirectX version
//		M[10] = zFar+zNear/(zNear-zFar); // OpenGL version
		M[11] = -1.0f;

		M[12] = 0.0f;
		M[13] = 0.0f;
		M[14] = zNear*zFar/(zNear-zFar); // DirectX version
//		M[14] = 2.0f*zNear*zFar/(zNear-zFar); // OpenGL version
		M[15] = 0.0f;
		definitelyIdentityMatrix=false;
	}



	//! Builds a left-handed perspective projection matrix based on a field of view
	inline void matrix4::buildProjectionMatrixPerspectiveFovLH(f32 fieldOfViewRadians, f32 aspectRatio, f32 zNear, f32 zFar)
	{
		f32 h = (f32)(1.0/tan(fieldOfViewRadians/2.0));
		f32 w = h / aspectRatio;

		M[0] = w;
		M[1] = 0.0f;
		M[2] = 0.0f;
		M[3] = 0.0f;

		M[4] = 0.0f;
		M[5] = h;
		M[6] = 0.0f;
		M[7] = 0.0f;

		M[8] = 0.0f;
		M[9] = 0.0f;
		M[10] = zFar/(zFar-zNear);
		M[11] = 1.0f;

		M[12] = 0.0f;
		M[13] = 0.0f;
		M[14] = -zNear*zFar/(zFar-zNear);
		M[15] = 0.0f;
		definitelyIdentityMatrix=false;
	}



	//! Builds a left-handed orthogonal projection matrix.
	inline void matrix4::buildProjectionMatrixOrthoLH(f32 widthOfViewVolume, f32 heightOfViewVolume, f32 zNear, f32 zFar)
	{
		M[0] = 2/widthOfViewVolume;
		M[1] = 0;
		M[2] = 0;
		M[3] = 0;

		M[4] = 0;
		M[5] = 2/heightOfViewVolume;
		M[6] = 0;
		M[7] = 0;

		M[8] = 0;
		M[9] = 0;
		M[10] = 1/(zFar-zNear);
		M[11] = 0;

		M[12] = 0;
		M[13] = 0;
		M[14] = zNear/(zNear-zFar);
		M[15] = 1;
		definitelyIdentityMatrix=false;
	}



	//! Builds a right-handed orthogonal projection matrix.
	inline void matrix4::buildProjectionMatrixOrthoRH(f32 widthOfViewVolume, f32 heightOfViewVolume, f32 zNear, f32 zFar)
	{
		M[0] = 2/widthOfViewVolume;
		M[1] = 0;
		M[2] = 0;
		M[3] = 0;

		M[4] = 0;
		M[5] = 2/heightOfViewVolume;
		M[6] = 0;
		M[7] = 0;

		M[8] = 0;
		M[9] = 0;
		M[10] = 1/(zNear-zFar);
		M[11] = 0;

		M[12] = 0;
		M[13] = 0;
		M[14] = zNear/(zNear-zFar);
		M[15] = -1;
		definitelyIdentityMatrix=false;
	}


	//! Builds a right-handed perspective projection matrix.
	inline void matrix4::buildProjectionMatrixPerspectiveRH(f32 widthOfViewVolume, f32 heightOfViewVolume, f32 zNear, f32 zFar)
	{
		M[0] = 2*zNear/widthOfViewVolume;
		M[1] = 0;
		M[2] = 0;
		M[3] = 0;

		M[4] = 0;
		M[5] = 2*zNear/heightOfViewVolume;
		M[6] = 0;
		M[7] = 0;

		M[8] = 0;
		M[9] = 0;
		M[10] = zFar/(zNear-zFar);
		M[11] = -1;

		M[12] = 0;
		M[13] = 0;
		M[14] = zNear*zFar/(zNear-zFar);
		M[15] = 0;
		definitelyIdentityMatrix=false;
	}


	//! Builds a left-handed perspective projection matrix.
	inline void matrix4::buildProjectionMatrixPerspectiveLH(f32 widthOfViewVolume, f32 heightOfViewVolume, f32 zNear, f32 zFar)
	{
		M[0] = 2*zNear/widthOfViewVolume;
		M[1] = 0;
		M[2] = 0;
		M[3] = 0;

		M[4] = 0;
		M[5] = 2*zNear/heightOfViewVolume;
		M[6] = 0;
		M[7] = 0;

		M[8] = 0;
		M[9] = 0;
		M[10] = zFar/(zFar-zNear);
		M[11] = 1;

		M[12] = 0;
		M[13] = 0;
		M[14] = zNear*zFar/(zNear-zFar);
		M[15] = 0;
		definitelyIdentityMatrix=false;
	}


	//! Builds a matrix that flattens geometry into a plane.
	inline void matrix4::buildShadowMatrix(const core::vector3df& light, core::plane3df plane, f32 point)
	{
		plane.Normal.normalize();
		f32 d = plane.Normal.dotProduct(light);

		M[ 0] = -plane.Normal.X * light.X + d;
		M[ 1] = -plane.Normal.X * light.Y;
		M[ 2] = -plane.Normal.X * light.Z;
		M[ 3] = -plane.Normal.X * point;

		M[ 4] = -plane.Normal.Y * light.X;
		M[ 5] = -plane.Normal.Y * light.Y + d;
		M[ 6] = -plane.Normal.Y * light.Z;
		M[ 7] = -plane.Normal.Y * point;

		M[ 8] = -plane.Normal.Z * light.X;
		M[ 9] = -plane.Normal.Z * light.Y;
		M[10] = -plane.Normal.Z * light.Z + d;
		M[11] = -plane.Normal.Z * point;

		M[12] = -plane.D * light.X;
		M[13] = -plane.D * light.Y;
		M[14] = -plane.D * light.Z;
		M[15] = -plane.D * point + d; 
		definitelyIdentityMatrix=false;
	}

	//! Builds a left-handed look-at matrix.
	inline void matrix4::buildCameraLookAtMatrixLH(
				const vector3df& position,
				const vector3df& target,
				const vector3df& upVector)
	{
		vector3df zaxis = target - position;
		zaxis.normalize();

		vector3df xaxis = upVector.crossProduct(zaxis);
		xaxis.normalize();

		vector3df yaxis = zaxis.crossProduct(xaxis);

		M[0] = xaxis.X;
		M[1] = yaxis.X;
		M[2] = zaxis.X;
		M[3] = 0;

		M[4] = xaxis.Y;
		M[5] = yaxis.Y;
		M[6] = zaxis.Y;
		M[7] = 0;

		M[8] = xaxis.Z;
		M[9] = yaxis.Z;
		M[10] = zaxis.Z;
		M[11] = 0;

		M[12] = -xaxis.dotProduct(position);
		M[13] = -yaxis.dotProduct(position);
		M[14] = -zaxis.dotProduct(position);
		M[15] = 1.0f;
		definitelyIdentityMatrix=false;
	}



	//! Builds a right-handed look-at matrix.
	inline void matrix4::buildCameraLookAtMatrixRH(
				const vector3df& position,
				const vector3df& target,
				const vector3df& upVector)
	{
		vector3df zaxis = position - target;
		zaxis.normalize();

		vector3df xaxis = upVector.crossProduct(zaxis);
		xaxis.normalize();

		vector3df yaxis = zaxis.crossProduct(xaxis);

		M[0] = xaxis.X;
		M[1] = yaxis.X;
		M[2] = zaxis.X;
		M[3] = 0;

		M[4] = xaxis.Y;
		M[5] = yaxis.Y;
		M[6] = zaxis.Y;
		M[7] = 0;

		M[8] = xaxis.Z;
		M[9] = yaxis.Z;
		M[10] = zaxis.Z;
		M[11] = 0;

		M[12] = -xaxis.dotProduct(position);
		M[13] = -yaxis.dotProduct(position);
		M[14] = -zaxis.dotProduct(position);
		M[15] = 1.0f;
		definitelyIdentityMatrix=false;
	}


	//! creates a new matrix as interpolated matrix from to other ones.
	//! \param time: Must be a value between 0 and 1.
	inline matrix4 matrix4::interpolate(const core::matrix4& b, f32 time) const
	{
		matrix4 mat ( EM4CONST_NOTHING );

		for (s32 i=0; i < 16; i += 4)
		{
			mat.M[i+0] = M[i+0] + ( b.M[i+0] - M[i+0] ) * time;
			mat.M[i+1] = M[i+1] + ( b.M[i+1] - M[i+1] ) * time;
			mat.M[i+2] = M[i+2] + ( b.M[i+2] - M[i+2] ) * time;
			mat.M[i+3] = M[i+3] + ( b.M[i+3] - M[i+3] ) * time;
		}
		return mat;
	}

	//! returns transposed matrix
	inline matrix4 matrix4::getTransposed() const
	{
		matrix4 t ( EM4CONST_NOTHING );
		getTransposed ( t );
		return t;
	}

	//! returns transposed matrix
	inline void matrix4::getTransposed( matrix4& o ) const
	{
		o[ 0] = M[ 0];
		o[ 1] = M[ 4];
		o[ 2] = M[ 8];
		o[ 3] = M[12];

		o[ 4] = M[ 1];
		o[ 5] = M[ 5];
		o[ 6] = M[ 9];
		o[ 7] = M[13];

		o[ 8] = M[ 2];
		o[ 9] = M[ 6];
		o[10] = M[10];
		o[11] = M[14];

		o[12] = M[ 3];
		o[13] = M[ 7];
		o[14] = M[11];
		o[15] = M[15];
		o.definitelyIdentityMatrix=definitelyIdentityMatrix;
	}


	// used to scale <-1,-1><1,1> to viewport
	inline void matrix4::buildNDCToDCMatrix( const core::rect<s32>& viewport, f32 zScale)
	{
		f32 scaleX = (viewport.getWidth() - 0.75f ) / 2.f;
		f32 scaleY = -(viewport.getHeight() - 0.75f ) / 2.f;

		f32 dx = -0.5f + ( (viewport.UpperLeftCorner.X + viewport.LowerRightCorner.X ) / 2.f );
		f32 dy = -0.5f + ( (viewport.UpperLeftCorner.Y + viewport.LowerRightCorner.Y ) / 2.f );

		makeIdentity();
		M[0] = scaleX;
		M[5] = scaleY;
		M[10] = zScale;
		M[12] = dx;
		M[13] = dy;
		definitelyIdentityMatrix=false;
	}

	/*!
		Generate texture coordinates as linear functions so that:
			u = Uxx + Uyy + Uzz + Uw 
			v = Vxx + Vyy + Vzz + Vw
		The matrix M for this case is:
			Ux  Vx  0  0 
			Uy  Vy  0  0 
			Uz  Vz  0  0 
			Uw  Vw  0  0 
	*/

	inline void matrix4::buildTextureTransform( f32 rotateRad,
					const core::vector2df &rotatecenter,
					const core::vector2df &translate,
					const core::vector2df &scale)
	{
		f32 c = cosf(rotateRad);
		f32 s = sinf(rotateRad);

		M[0] = c * scale.X;
		M[1] = s * scale.Y;
		M[2] = 0.f;
		M[3] = 0.f;

		M[4] = -s * scale.X;
		M[5] = c * scale.Y;
		M[6] = 0.f;
		M[7] = 0.f;

		M[8] = c * scale.X * rotatecenter.X + -s * rotatecenter.Y + translate.X;
		M[9] = s * scale.Y * rotatecenter.X +  c * rotatecenter.Y + translate.Y;
		M[10] = 1.f;
		M[11] = 0.f;

		M[12] = 0.f;
		M[13] = 0.f;
		M[14] = 0.f;
		M[15] = 1.f;
		definitelyIdentityMatrix=false;
	}

	//! rotate about z axis, center ( 0.5, 0.5 )
	inline void matrix4::setTextureRotationCenter( f32 rotateRad )
	{
		f32 c = cosf(rotateRad);
		f32 s = sinf(rotateRad);
		M[0] = c;
		M[1] = s;
		M[2] = -0.5f * ( c + s) + 0.5f;

		M[4] = -s;
		M[5] = c;
		M[6] = -0.5f * (-s + c) + 0.5f;
		definitelyIdentityMatrix=false;
	}

	inline void matrix4::setTextureTranslate ( f32 x, f32 y )
	{
		M[2] = x;
		M[6] = y;
		definitelyIdentityMatrix=false;
	}

	inline void matrix4::setTextureScale ( f32 sx, f32 sy )
	{
		M[0] = sx;
		M[5] = sy;
		definitelyIdentityMatrix=false;
	}

	inline void matrix4::setTextureScaleCenter( f32 sx, f32 sy )
	{
		M[0] = sx;
		M[2] = -0.5f * sx + 0.5f;
		M[5] = sy;
		M[6] = -0.5f * sy + 0.5f;
		definitelyIdentityMatrix=false;
	}

	//! Multiply by scalar.
	inline matrix4 operator*(const f32 scalar, const matrix4& mat)
	{
		return mat*scalar;
	}

	const matrix4 IdentityMatrix(matrix4::EM4CONST_IDENTITY);
} // end namespace core
} // end namespace irr

#endif


namespace irr
{
namespace core
{

//! Quaternion class.
class quaternion
{
	public:

		//! Default Constructor
		quaternion();

		//! Constructor
		quaternion(f32 X, f32 Y, f32 Z, f32 W);

		//! Constructor which converts euler angles to a quaternion
		quaternion(f32 x, f32 y, f32 z);

		//! Constructor which converts a matrix to a quaternion
		quaternion(const matrix4& mat);

		//! equal operator
		bool operator==(const quaternion& other) const;

		//! assignment operator
		inline quaternion& operator=(const quaternion& other);

		//! matrix assignment operator
		inline quaternion& operator=(const matrix4& other);

		//! add operator
		quaternion operator+(const quaternion& other) const;

		//! multiplication operator
		quaternion operator*(const quaternion& other) const;

		//! multiplication operator
		quaternion operator*(f32 s) const;

		//! multiplication operator
		quaternion& operator*=(f32 s);

		//! multiplication operator
		vector3df operator* (const vector3df& v) const;

		//! multiplication operator
		quaternion& operator*=(const quaternion& other);

		//! calculates the dot product
		inline f32 getDotProduct(const quaternion& other) const;

		//! sets new quaternion
		inline void set(f32 x, f32 y, f32 z, f32 w);

		//! sets new quaternion based on euler angles
		inline void set(f32 x, f32 y, f32 z);

		//! normalizes the quaternion
		inline quaternion& normalize();

		//! Creates a matrix from this quaternion
		matrix4 getMatrix() const;

		//! Creates a matrix from this quaternion
		void getMatrix( matrix4 &dest ) const;

		//! Creates a matrix from this quaternion
		void getMatrix_transposed( matrix4 &dest ) const;

		//! Inverts this quaternion
		void makeInverse();

		//! set this quaternion to the result of the inpolation between two quaternions based
		void slerp( quaternion q1, const quaternion q2, f32 interpolate );

		//! axis must be unit length
		//! The quaternion representing the rotation is
		//!  q = cos(A/2)+sin(A/2)*(x*i+y*j+z*k)
		void fromAngleAxis (f32 angle, const vector3df& axis);

		void toEuler(vector3df& euler) const;

		//! set quaternion to identity
		void makeIdentity();

		f32 X, Y, Z, W;
};


//! Default Constructor
inline quaternion::quaternion()
: X(0.0f), Y(0.0f), Z(0.0f), W(1.0f)
{
}

//! Constructor
inline quaternion::quaternion(f32 x, f32 y, f32 z, f32 w)
: X(x), Y(y), Z(z), W(w)
{
}

//! Constructor which converts euler angles to a quaternion
inline quaternion::quaternion(f32 x, f32 y, f32 z)
{
	set(x,y,z);
}


//! Constructor which converts a matrix to a quaternion
inline quaternion::quaternion(const matrix4& mat)
{
	(*this) = mat;
}


//! equal operator
inline bool quaternion::operator==(const quaternion& other) const
{
	if(X != other.X)
		return false;
	if(Y != other.Y)
		return false;
	if(Z != other.Z)
		return false;
	if(W != other.W)
		return false;

	return true;
}


//! assignment operator
inline quaternion& quaternion::operator=(const quaternion& other)
{
	X = other.X;
	Y = other.Y;
	Z = other.Z;
	W = other.W;
	return *this;
}


//! matrix assignment operator
inline quaternion& quaternion::operator=(const matrix4& m)
{
	f32 diag = m(0,0) + m(1,1) + m(2,2) + 1;
	f32 scale = 0.0f;

	if( diag > 0.0f )
	{
		scale = sqrtf(diag) * 2.0f; // get scale from diagonal

		// TODO: speed this up
		X = ( m(2,1) - m(1,2)) / scale;
		Y = ( m(0,2) - m(2,0)) / scale;
		Z = ( m(1,0) - m(0,1)) / scale;
		W = 0.25f * scale;
	}
	else
	{
		if ( m(0,0) > m(1,1) && m(0,0) > m(2,2))
		{
			// 1st element of diag is greatest value
			// find scale according to 1st element, and double it
			scale = sqrtf( 1.0f + m(0,0) - m(1,1) - m(2,2)) * 2.0f;

			// TODO: speed this up
			X = 0.25f * scale;
			Y = (m(0,1) + m(1,0)) / scale;
			Z = (m(2,0) + m(0,2)) / scale;
			W = (m(2,1) - m(1,2)) / scale;
		}
		else if ( m(1,1) > m(2,2))
		{
			// 2nd element of diag is greatest value
			// find scale according to 2nd element, and double it
			scale = sqrtf( 1.0f + m(1,1) - m(0,0) - m(2,2)) * 2.0f;

			// TODO: speed this up
			X = (m(0,1) + m(1,0) ) / scale;
			Y = 0.25f * scale;
			Z = (m(1,2) + m(2,1) ) / scale;
			W = (m(0,2) - m(2,0) ) / scale;
		}
		else
		{
			// 3rd element of diag is greatest value
			// find scale according to 3rd element, and double it
			scale  = sqrtf( 1.0f + m(2,2) - m(0,0) - m(1,1)) * 2.0f;

			// TODO: speed this up
			X = (m(0,2) + m(2,0)) / scale;
			Y = (m(1,2) + m(2,1)) / scale;
			Z = 0.25f * scale;
			W = (m(1,0) - m(0,1)) / scale;
		}
	}

	normalize();
	return *this;
}


//! multiplication operator
inline quaternion quaternion::operator*(const quaternion& other) const
{
	quaternion tmp;

	tmp.W = (other.W * W) - (other.X * X) - (other.Y * Y) - (other.Z * Z);
	tmp.X = (other.W * X) + (other.X * W) + (other.Y * Z) - (other.Z * Y);
	tmp.Y = (other.W * Y) + (other.Y * W) + (other.Z * X) - (other.X * Z);
	tmp.Z = (other.W * Z) + (other.Z * W) + (other.X * Y) - (other.Y * X);

	return tmp;
}


//! multiplication operator
inline quaternion quaternion::operator*(f32 s) const
{
	return quaternion(s*X, s*Y, s*Z, s*W);
}

//! multiplication operator
inline quaternion& quaternion::operator*=(f32 s)
{
	X *= s; Y*=s; Z*=s; W*=s;
	return *this;
}

//! multiplication operator
inline quaternion& quaternion::operator*=(const quaternion& other)
{
	*this = other * (*this);
	return *this;
}

//! add operator
inline quaternion quaternion::operator+(const quaternion& b) const
{
	return quaternion(X+b.X, Y+b.Y, Z+b.Z, W+b.W);
}


//! Creates a matrix from this quaternion
inline matrix4 quaternion::getMatrix() const
{
	core::matrix4 m;

	m(0,0) = 1.0f - 2.0f*Y*Y - 2.0f*Z*Z;
	m(1,0) = 2.0f*X*Y + 2.0f*Z*W;
	m(2,0) = 2.0f*X*Z - 2.0f*Y*W;
	m(3,0) = 0.0f;

	m(0,1) = 2.0f*X*Y - 2.0f*Z*W;
	m(1,1) = 1.0f - 2.0f*X*X - 2.0f*Z*Z;
	m(2,1) = 2.0f*Z*Y + 2.0f*X*W;
	m(3,1) = 0.0f;

	m(0,2) = 2.0f*X*Z + 2.0f*Y*W;
	m(1,2) = 2.0f*Z*Y - 2.0f*X*W;
	m(2,2) = 1.0f - 2.0f*X*X - 2.0f*Y*Y;
	m(3,2) = 0.0f;

	m(0,3) = 0.0f;
	m(1,3) = 0.0f;
	m(2,3) = 0.0f;
	m(3,3) = 1.0f;

	return m;
}


//! Creates a matrix from this quaternion
inline void quaternion::getMatrix( matrix4 &dest ) const
{
	dest[0] = 1.0f - 2.0f*Y*Y - 2.0f*Z*Z;
	dest[1] = 2.0f*X*Y + 2.0f*Z*W;
	dest[2] = 2.0f*X*Z - 2.0f*Y*W;
	dest[3] = 0.0f;

	dest[4] = 2.0f*X*Y - 2.0f*Z*W;
	dest[5] = 1.0f - 2.0f*X*X - 2.0f*Z*Z;
	dest[6] = 2.0f*Z*Y + 2.0f*X*W;
	dest[7] = 0.0f;

	dest[8] = 2.0f*X*Z + 2.0f*Y*W;
	dest[9] = 2.0f*Z*Y - 2.0f*X*W;
	dest[10] = 1.0f - 2.0f*X*X - 2.0f*Y*Y;
	dest[11] = 0.0f;

	dest[12] = 0.f;
	dest[13] = 0.f;
	dest[14] = 0.f;
	dest[15] = 1.f;
}

//! Creates a matrix from this quaternion
inline void quaternion::getMatrix_transposed( matrix4 &dest ) const
{
	dest[0] = 1.0f - 2.0f*Y*Y - 2.0f*Z*Z;
	dest[4] = 2.0f*X*Y + 2.0f*Z*W;
	dest[8] = 2.0f*X*Z - 2.0f*Y*W;
	dest[12] = 0.0f;

	dest[1] = 2.0f*X*Y - 2.0f*Z*W;
	dest[5] = 1.0f - 2.0f*X*X - 2.0f*Z*Z;
	dest[9] = 2.0f*Z*Y + 2.0f*X*W;
	dest[13] = 0.0f;

	dest[2] = 2.0f*X*Z + 2.0f*Y*W;
	dest[6] = 2.0f*Z*Y - 2.0f*X*W;
	dest[10] = 1.0f - 2.0f*X*X - 2.0f*Y*Y;
	dest[14] = 0.0f;

	dest[3] = 0.f;
	dest[7] = 0.f;
	dest[11] = 0.f;
	dest[15] = 1.f;
}



//! Inverts this quaternion
inline void quaternion::makeInverse()
{
	X = -X; Y = -Y; Z = -Z;
}

//! sets new quaternion
inline void quaternion::set(f32 x, f32 y, f32 z, f32 w)
{
	X = x;
	Y = y;
	Z = z;
	W = w;
}


//! sets new quaternion based on euler angles
inline void quaternion::set(f32 x, f32 y, f32 z)
{
	f64 angle;

	angle = x * 0.5;
	f64 sr = (f32)sin(angle);
	f64 cr = (f32)cos(angle);

	angle = y * 0.5;
	f64 sp = (f32)sin(angle);
	f64 cp = (f32)cos(angle);

	angle = z * 0.5;
	f64 sy = (f32)sin(angle);
	f64 cy = (f32)cos(angle);

	f64 cpcy = cp * cy;
	f64 spcy = sp * cy;
	f64 cpsy = cp * sy;
	f64 spsy = sp * sy;

	X = (f32)(sr * cpcy - cr * spsy);
	Y = (f32)(cr * spcy + sr * cpsy);
	Z = (f32)(cr * cpsy - sr * spcy);
	W = (f32)(cr * cpcy + sr * spsy);

	normalize();
}

//! normalizes the quaternion
inline quaternion& quaternion::normalize()
{
	f32 n = X*X + Y*Y + Z*Z + W*W;

	if (n == 1)
		return *this;

	//n = 1.0f / sqrtf(n);
	n = reciprocal_squareroot ( n );
	X *= n;
	Y *= n;
	Z *= n;
	W *= n;

	return *this;
}


// set this quaternion to the result of the inpolation between two quaternions based
inline void quaternion::slerp( quaternion q1, quaternion q2, f32 time)
{
	f32 angle = q1.getDotProduct(q2);

	if (angle < 0.0f)
	{
		q1 *= -1.0f;
		angle *= -1.0f;
	}

	f32 scale;
	f32 invscale;

	if ((angle + 1.0f) > 0.05f)
	{
		if ((1.0f - angle) >= 0.05f)  // spherical interpolation
		{
			f32 theta = (f32)acos(angle);
			f32 invsintheta = 1.0f / (f32)sin(theta);
			scale = (f32)sin(theta * (1.0f-time)) * invsintheta;
			invscale = (f32)sin(theta * time) * invsintheta;
		}
		else // linear interploation
		{
			scale = 1.0f - time;
			invscale = time;
		}
	}
	else
	{
		q2 = quaternion(-q1.Y, q1.X, -q1.W, q1.Z);
		scale = (f32)sin(PI * (0.5f - time));
		invscale = (f32)sin(PI * time);
	}

	*this = (q1*scale) + (q2*invscale);
}


//! calculates the dot product
inline f32 quaternion::getDotProduct(const quaternion& q2) const
{
	return (X * q2.X) + (Y * q2.Y) + (Z * q2.Z) + (W * q2.W);
}


inline void quaternion::fromAngleAxis(f32 angle, const vector3df& axis)
{
	f32 fHalfAngle = 0.5f*angle;
	f32 fSin = (f32)sin(fHalfAngle);
	W = (f32)cos(fHalfAngle);
	X = fSin*axis.X;
	Y = fSin*axis.Y;
	Z = fSin*axis.Z;
}

inline void quaternion::toEuler(vector3df& euler) const
{
	double sqw = W*W;
	double sqx = X*X;
	double sqy = Y*Y;
	double sqz = Z*Z;

	// heading = rotation about z-axis
	euler.Z = (f32) (atan2(2.0 * (X*Y +Z*W),(sqx - sqy - sqz + sqw)));

	// bank = rotation about x-axis
	euler.X = (f32) (atan2(2.0 * (Y*Z +X*W),(-sqx - sqy + sqz + sqw)));

	// attitude = rotation about y-axis
	euler.Y = (f32) (asin(-2.0 * (X*Z - Y*W)));
}

inline vector3df quaternion::operator* (const vector3df& v) const
{
	// nVidia SDK implementation

	vector3df uv, uuv;
	vector3df qvec(X, Y, Z);
	uv = qvec.crossProduct(v);
	uuv = qvec.crossProduct(uv);
	uv *= (2.0f * W);
	uuv *= 2.0f;

	return v + uv + uuv;
}

//! set quaterion to identity
inline void quaternion::makeIdentity()
{
	W = 1.f;
	X = 0.f;
	Y = 0.f;
	Z = 0.f;
}


} // end namespace core
} // end namespace irr

#endif

// Copyright (C) 2002-2007 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __I_XML_READER_H_INCLUDED__
#define __I_XML_READER_H_INCLUDED__

// Copyright (C) 2002-2007 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine" and the "irrXML" project.
// For conditions of distribution and use, see copyright notice in irrlicht.h and/or irrXML.h

#ifndef __IRR_XML_H_INCLUDED__
#define __IRR_XML_H_INCLUDED__

#include <stdio.h>

/* \mainpage irrXML 1.2 API documentation
 <div align="center"><img src="logobig.png" ></div>

 \section intro Introduction

  Welcome to the irrXML API documentation.
  Here you'll find any information you'll need to develop applications with
  irrXML. If you look for a tutorial on how to start, take a look at the \ref irrxmlexample,
  at the homepage of irrXML at <A HREF="http://xml.irrlicht3d.org" >xml.irrlicht3d.org</A> 
  or into the SDK in the directory \example.
 
  irrXML is intended to be a high speed and easy-to-use XML Parser for C++, and
  this documentation is an important part of it. If you have any questions or
  suggestions, just send a email to the author of the engine, Nikolaus Gebhardt
  (niko (at) irrlicht3d.org). For more informations about this parser, see \ref history.

  \section features Features

  irrXML provides forward-only, read-only 
     access to a stream of non validated XML data. It was fully implemented by
	 Nikolaus Gebhardt. Its current features are:

	 - It it fast as lighting and has very low memory usage. It was 
	   developed with the intention of being used in 3D games, as it already has been.
	 - irrXML is very small: It only consists of 60 KB of code and can be added easily
	   to your existing project.
	 - Of course, it is platform independent and works with lots of compilers.
	 - It is able to parse ASCII, UTF-8, UTF-16 and UTF-32 text files, both in 
	   little and big endian format. 
	 - Independent of the input file format, the parser can return all strings in ASCII, UTF-8,
	   UTF-16 and UTF-32 format. 
	 - With its optional file access abstraction it has the advantage that it can read not
	   only from files but from any type of data (memory, network, ...). For example when 
	   used with the Irrlicht Engine, it directly reads from compressed .zip files. 
	 - Just like the Irrlicht Engine for which it was originally created, it is extremely easy 
	   to use.
	 - It has no external dependencies, it does not even need the STL. 

	 Although irrXML has some strenghts, it currently also has the following limitations:

	 - The input xml file is not validated and assumed to be correct. 

    \section irrxmlexample Example

    The following code demonstrates the basic usage of irrXML. A simple xml
	file like this is parsed:
    \code
	<?xml version="1.0"?>
	<config>
		<!-- This is a config file for the mesh viewer -->
		<model file="dwarf.dea" />
		<messageText caption="Irrlicht Engine Mesh Viewer">
		Welcome to the Mesh Viewer of the &quot;Irrlicht Engine&quot;.
		</messageText>
	</config>
	\endcode

	The code for parsing this file would look like this:
	\code
	#include <irrXML.h>
	using namespace irr; // irrXML is located in the namespace irr::io
	using namespace io;

	#include <string> // we use STL strings to store data in this example

	void main()
	{
		// create the reader using one of the factory functions

		IrrXMLReader xml = createIrrXMLReader("config.xml");

		// strings for storing the data we want to get out of the file
		std::string modelFile;
		std::string messageText;
		std::string caption;

		// parse the file until end reached

		while(xml && xml->read())
		{
			switch(xml->getNodeType())
			{
			case EXN_TEXT:
				// in this xml file, the only text which occurs is the messageText
				messageText = xml->getNodeData();
				break;
			case EXN_ELEMENT:
				{
					if (!strcmp("model", xml->getNodeName()))
						modelFile = xml->getAttributeValue("file");
					else
					if (!strcmp("messageText", xml->getNodeName()))
						caption = xml->getAttributeValue("caption");
				}
				break;
			}
		}

		// delete the xml parser after usage
		delete xml;
	}
	\endcode

	\section howto How to use

	Simply add the source files in the /src directory of irrXML to your project. Done.

	\section license License

	The irrXML license is based on the zlib license. Basicly, this means you can do with
	irrXML whatever you want:

	Copyright (C) 2002-2007 Nikolaus Gebhardt

	This software is provided 'as-is', without any express or implied
	warranty.  In no event will the authors be held liable for any damages
	arising from the use of this software.

	Permission is granted to anyone to use this software for any purpose,
	including commercial applications, and to alter it and redistribute it
	freely, subject to the following restrictions:

	1. The origin of this software must not be misrepresented; you must not
		claim that you wrote the original software. If you use this software
		in a product, an acknowledgment in the product documentation would be
		appreciated but is not required.

	2. Altered source versions must be plainly marked as such, and must not be
		misrepresented as being the original software.

	3. This notice may not be removed or altered from any source distribution.

	\section history History

	As lots of references in this documentation and the source show, this xml 
	parser has originally been a part of the 
	<A HREF="http://irrlicht.sourceforge.net" >Irrlicht Engine</A>. But because
	the parser has become very useful with the latest release, people asked for a 
	separate version of it, to be able to use it in non Irrlicht projects. With
	irrXML 1.0, this has now been done.
*/

namespace irr
{
namespace io
{
	//! Enumeration of all supported source text file formats 
	enum ETEXT_FORMAT
	{
		//! ASCII, file without byte order mark, or not a text file
		ETF_ASCII,

		//! UTF-8 format
		ETF_UTF8,

		//! UTF-16 format, big endian
		ETF_UTF16_BE,

		//! UTF-16 format, little endian
		ETF_UTF16_LE,

		//! UTF-32 format, big endian
		ETF_UTF32_BE,

		//! UTF-32 format, little endian
		ETF_UTF32_LE
	};


	//! Enumeration for all xml nodes which are parsed by IrrXMLReader
	enum EXML_NODE
	{
		//! No xml node. This is usually the node if you did not read anything yet.
		EXN_NONE,

		//! An xml element such as &lt;foo&gt;
		EXN_ELEMENT,

		//! End of an xml element such as &lt;/foo&gt;
		EXN_ELEMENT_END,

		//! Text within an xml element: &lt;foo&gt; this is the text. &lt;foo&gt;
		EXN_TEXT,

		//! An xml comment like &lt;!-- I am a comment --&gt; or a DTD definition.
		EXN_COMMENT,

		//! An xml cdata section like &lt;![CDATA[ this is some CDATA ]]&gt;
		EXN_CDATA,

		//! Unknown element.
		EXN_UNKNOWN
	};

	//! Callback class for file read abstraction. 
	/* With this, it is possible to make the xml parser read in other things 
	than just files. The Irrlicht engine is using this for example to 
	read xml from compressed .zip files. To make the parser read in 
	any other data, derive a class from this interface, implement the 
	two methods to read your data and give a pointer to an instance of
	your implementation when calling createIrrXMLReader(), 
	createIrrXMLReaderUTF16() or createIrrXMLReaderUTF32() */
	class IFileReadCallBack
	{
	public:

		//! virtual destructor
		virtual ~IFileReadCallBack() {};

		//! Reads an amount of bytes from the file.
		/* \param buffer: Pointer to buffer where to read bytes will be written to.
		\param sizeToRead: Amount of bytes to read from the file.
		\return Returns how much bytes were read. */
		virtual int read(void* buffer, int sizeToRead) = 0;

		//! Returns size of file in bytes
		virtual int getSize() = 0;
	};

	//! Empty class to be used as parent class for IrrXMLReader.
	/* If you need another class as base class for the xml reader, you can do this by creating
	the reader using for example new CXMLReaderImpl<char, YourBaseClass>(yourcallback);
	The Irrlicht Engine for example needs IUnknown as base class for every object to
	let it automaticly reference countend, hence it replaces IXMLBase with IUnknown.
	See irrXML.cpp on how this can be done in detail. */
	class IXMLBase
	{
	};	

	//! Interface providing easy read access to a XML file.
	/* You can create an instance of this reader using one of the factory functions
	createIrrXMLReader(), createIrrXMLReaderUTF16() and createIrrXMLReaderUTF32().
	If using the parser from the Irrlicht Engine, please use IFileSystem::createXMLReader() 
	instead.
	For a detailed intro how to use the parser, see \ref irrxmlexample and \ref features.

	The typical usage of this parser looks like this:
	\code
	#include <irrXML.h>
	using namespace irr; // irrXML is located in the namespace irr::io
	using namespace io;

	void main()
	{
		// create the reader using one of the factory functions
		IrrXMLReader xml = createIrrXMLReader("config.xml");

		if (xml == 0)
			return; // file could not be opened

		// parse the file until end reached
		while(xml->read())
		{
			// based on xml->getNodeType(), do something.
		}

		// delete the xml parser after usage
		delete xml;
	}
	\endcode
	See \ref irrxmlexample for a more detailed example.
	*/
	template<class char_type, class super_class>
	class IIrrXMLReader : public super_class
	{
	public:

		//! Destructor
		virtual ~IIrrXMLReader() {};

		//! Reads forward to the next xml node. 
		/* \return Returns false, if there was no further node.  */
		virtual bool read() = 0;

		//! Returns the type of the current XML node.
		virtual EXML_NODE getNodeType() const = 0;

        //! Returns attribute count of the current XML node. 
		/* This is usually
		non null if the current node is EXN_ELEMENT, and the element has attributes.
		\return Returns amount of attributes of this xml node. */
		virtual int getAttributeCount() const = 0;

		//! Returns name of an attribute. 
		/* \param idx: Zero based index, should be something between 0 and getAttributeCount()-1.
		\return Name of the attribute, 0 if an attribute with this index does not exist. */
		virtual const char_type* getAttributeName(int idx) const = 0;

		//! Returns the value of an attribute. 
		/* \param idx: Zero based index, should be something between 0 and getAttributeCount()-1.
		\return Value of the attribute, 0 if an attribute with this index does not exist. */
		virtual const char_type* getAttributeValue(int idx) const = 0;

		//! Returns the value of an attribute. 
		/* \param name: Name of the attribute.
		\return Value of the attribute, 0 if an attribute with this name does not exist. */
		virtual const char_type* getAttributeValue(const char_type* name) const = 0;

		//! Returns the value of an attribute in a safe way.
		/* Like getAttributeValue(), but does not 
		return 0 if the attribute does not exist. An empty string ("") is returned then.
		\param name: Name of the attribute.
		\return Value of the attribute, and "" if an attribute with this name does not exist */
		virtual const char_type* getAttributeValueSafe(const char_type* name) const = 0;

		//! Returns the value of an attribute as integer. 
		/* \param name Name of the attribute.
		\return Value of the attribute as integer, and 0 if an attribute with this name does not exist or
		the value could not be interpreted as integer. */
		virtual int getAttributeValueAsInt(const char_type* name) const = 0;

		//! Returns the value of an attribute as integer. 
		/* \param idx: Zero based index, should be something between 0 and getAttributeCount()-1.
		\return Value of the attribute as integer, and 0 if an attribute with this index does not exist or
		the value could not be interpreted as integer. */
		virtual int getAttributeValueAsInt(int idx) const = 0;

		//! Returns the value of an attribute as float. 
		/* \param name: Name of the attribute.
		\return Value of the attribute as float, and 0 if an attribute with this name does not exist or
		the value could not be interpreted as float. */
		virtual float getAttributeValueAsFloat(const char_type* name) const = 0;

		//! Returns the value of an attribute as float. 
		/* \param idx: Zero based index, should be something between 0 and getAttributeCount()-1.
		\return Value of the attribute as float, and 0 if an attribute with this index does not exist or
		the value could not be interpreted as float. */
		virtual float getAttributeValueAsFloat(int idx) const = 0;

		//! Returns the name of the current node. 
		/* Only non null, if the node type is EXN_ELEMENT.
		\return Name of the current node or 0 if the node has no name. */
		virtual const char_type* getNodeName() const = 0;

		//! Returns data of the current node. 
		/* Only non null if the node has some
		data and it is of type EXN_TEXT or EXN_UNKNOWN. */
		virtual const char_type* getNodeData() const = 0;

		//! Returns if an element is an empty element, like <foo />
		virtual bool isEmptyElement() const = 0;

		//! Returns format of the source xml file. 
		/* It is not necessary to use
		this method because the parser will convert the input file format
		to the format wanted by the user when creating the parser. This
		method is useful to get/display additional informations. */
		virtual ETEXT_FORMAT getSourceFormat() const = 0;

		//! Returns format of the strings returned by the parser. 
		/* This will be UTF8 for example when you created a parser with
		IrrXMLReaderUTF8() and UTF32 when it has been created using 
		IrrXMLReaderUTF32. It should not be necessary to call this
		method and only exists for informational purposes. */
		virtual ETEXT_FORMAT getParserFormat() const = 0;
	};


	//! defines the utf-16 type.
	/* Not using wchar_t for this because 
	wchar_t has 16 bit on windows and 32 bit on other operating systems. */
	typedef unsigned short char16;

	//! defines the utf-32 type. 
	/* Not using wchar_t for this because 
	wchar_t has 16 bit on windows and 32 bit on other operating systems. */
	typedef unsigned long char32;

	//! A UTF-8 or ASCII character xml parser.
	/* This means that all character data will be returned in 8 bit ASCII or UTF-8 by this parser. 
	The file to read can be in any format, it will be converted to UTF-8 if it is not
	in this format.
	Create an instance of this with createIrrXMLReader(); 
	See IIrrXMLReader for description on how to use it. */
	typedef IIrrXMLReader<char, IXMLBase> IrrXMLReader;

	//! A UTF-16 xml parser. 
	/* This means that all character data will be returned in UTF-16 by this parser. 
	The file to read can be in any format, it will be converted to UTF-16 if it is not
	in this format.
	Create an instance of this with createIrrXMLReaderUTF16(); 
	See IIrrXMLReader for description on how to use it.  */
	typedef IIrrXMLReader<char16, IXMLBase> IrrXMLReaderUTF16;

	//! A UTF-32 xml parser. 
	/* This means that all character data will be returned in UTF-32 by this parser. 
	The file to read can be in any format, it will be converted to UTF-32 if it is not
	in this format.
	Create an instance of this with createIrrXMLReaderUTF32(); 
	See IIrrXMLReader for description on how to use it. */
	typedef IIrrXMLReader<char32, IXMLBase> IrrXMLReaderUTF32;


	//! Creates an instance of an UFT-8 or ASCII character xml parser.
	/* This means that all character data will be returned in 8 bit ASCII or UTF-8. 
	The file to read can be in any format, it will be converted to UTF-8 if it is not in this format.
	If you are using the Irrlicht Engine, it is better not to use this function but
	IFileSystem::createXMLReaderUTF8() instead.
	\param filename: Name of file to be opened.
	\return Returns a pointer to the created xml parser. This pointer should be 
	deleted using 'delete' after no longer needed. Returns 0 if an error occured
	and the file could not be opened. */
	IrrXMLReader* createIrrXMLReader(const char* filename);

	//! Creates an instance of an UFT-8 or ASCII character xml parser.
	/* This means that all character data will be returned in 8 bit ASCII or UTF-8. The file to read can 
	be in any format, it will be converted to UTF-8 if it is not in this format.
	If you are using the Irrlicht Engine, it is better not to use this function but
	IFileSystem::createXMLReaderUTF8() instead.
	\param file: Pointer to opened file, must have been opened in binary mode, e.g.
	using fopen("foo.bar", "wb"); The file will not be closed after it has been read.
	\return Returns a pointer to the created xml parser. This pointer should be 
	deleted using 'delete' after no longer needed. Returns 0 if an error occured
	and the file could not be opened. */
	IrrXMLReader* createIrrXMLReader(FILE* file);

	//! Creates an instance of an UFT-8 or ASCII character xml parser. 
	/* This means that all character data will be returned in 8 bit ASCII or UTF-8. The file to read can 
	 be in any format, it will be converted to UTF-8 if it is not in this format.
	 If you are using the Irrlicht Engine, it is better not to use this function but
	 IFileSystem::createXMLReaderUTF8() instead.
	 \param callback: Callback for file read abstraction. Implement your own
	 callback to make the xml parser read in other things than just files. See
	 IFileReadCallBack for more information about this.
	 \return Returns a pointer to the created xml parser. This pointer should be 
	 deleted using 'delete' after no longer needed. Returns 0 if an error occured
	 and the file could not be opened. */
	IrrXMLReader* createIrrXMLReader(IFileReadCallBack* callback);

	//! Creates an instance of an UFT-16 xml parser. 
	/* This means that
	all character data will be returned in UTF-16. The file to read can 
	be in any format, it will be converted to UTF-16 if it is not in this format.
	If you are using the Irrlicht Engine, it is better not to use this function but
	IFileSystem::createXMLReader() instead.
	\param filename: Name of file to be opened.
	\return Returns a pointer to the created xml parser. This pointer should be 
	deleted using 'delete' after no longer needed. Returns 0 if an error occured
	and the file could not be opened. */
	IrrXMLReaderUTF16* createIrrXMLReaderUTF16(const char* filename);

	//! Creates an instance of an UFT-16 xml parser. 
	/* This means that all character data will be returned in UTF-16. The file to read can 
	be in any format, it will be converted to UTF-16 if it is not in this format.
	If you are using the Irrlicht Engine, it is better not to use this function but
	IFileSystem::createXMLReader() instead.
	\param file: Pointer to opened file, must have been opened in binary mode, e.g.
	using fopen("foo.bar", "wb"); The file will not be closed after it has been read.
	\return Returns a pointer to the created xml parser. This pointer should be 
	deleted using 'delete' after no longer needed. Returns 0 if an error occured
	and the file could not be opened. */
	IrrXMLReaderUTF16* createIrrXMLReaderUTF16(FILE* file);

	//! Creates an instance of an UFT-16 xml parser. 
	/* This means that all character data will be returned in UTF-16. The file to read can 
	be in any format, it will be converted to UTF-16 if it is not in this format.
	If you are using the Irrlicht Engine, it is better not to use this function but
	IFileSystem::createXMLReader() instead.
	\param callback: Callback for file read abstraction. Implement your own
	callback to make the xml parser read in other things than just files. See
	IFileReadCallBack for more information about this.
	\return Returns a pointer to the created xml parser. This pointer should be 
	deleted using 'delete' after no longer needed. Returns 0 if an error occured
	and the file could not be opened. */
	IrrXMLReaderUTF16* createIrrXMLReaderUTF16(IFileReadCallBack* callback);


	//! Creates an instance of an UFT-32 xml parser. 
	/* This means that all character data will be returned in UTF-32. The file to read can 
	be in any format, it will be converted to UTF-32 if it is not in this format.
	If you are using the Irrlicht Engine, it is better not to use this function but
	IFileSystem::createXMLReader() instead.
	\param filename: Name of file to be opened.
	\return Returns a pointer to the created xml parser. This pointer should be 
	deleted using 'delete' after no longer needed. Returns 0 if an error occured
	and the file could not be opened. */
	IrrXMLReaderUTF32* createIrrXMLReaderUTF32(const char* filename);

	//! Creates an instance of an UFT-32 xml parser. 
	/* This means that all character data will be returned in UTF-32. The file to read can 
	be in any format, it will be converted to UTF-32 if it is not in this format.
	if you are using the Irrlicht Engine, it is better not to use this function but
	IFileSystem::createXMLReader() instead.
	\param file: Pointer to opened file, must have been opened in binary mode, e.g.
	using fopen("foo.bar", "wb"); The file will not be closed after it has been read.
	\return Returns a pointer to the created xml parser. This pointer should be 
	deleted using 'delete' after no longer needed. Returns 0 if an error occured
	and the file could not be opened. */
	IrrXMLReaderUTF32* createIrrXMLReaderUTF32(FILE* file);

	//! Creates an instance of an UFT-32 xml parser. 
	/* This means that
	all character data will be returned in UTF-32. The file to read can 
	be in any format, it will be converted to UTF-32 if it is not in this format.
	If you are using the Irrlicht Engine, it is better not to use this function but
	IFileSystem::createXMLReader() instead.
	\param callback: Callback for file read abstraction. Implement your own
	callback to make the xml parser read in other things than just files. See
	IFileReadCallBack for more information about this.
	\return Returns a pointer to the created xml parser. This pointer should be 
	deleted using 'delete' after no longer needed. Returns 0 if an error occured
	and the file could not be opened. */
	IrrXMLReaderUTF32* createIrrXMLReaderUTF32(IFileReadCallBack* callback);
	

	/*! \file irrxml.h
    \brief Header file of the irrXML, the Irrlicht XML parser.
    
    This file includes everything needed for using irrXML, 
    the XML parser of the Irrlicht Engine. To use irrXML,
	you only need to include this file in your project:

	\code
	#include <irrXML.h>
	\endcode

	It is also common to use the two namespaces in which irrXML is included, 
	directly after #including irrXML.h:

	\code
	#include <irrXML.h>
	using namespace irr;
	using namespace io;
	\endcode
	*/

} // end namespace io
} // end namespace irr

#endif // __IRR_XML_H_INCLUDED__


namespace irr
{
namespace io
{
	//! A xml reader for wide characters, derived from IUnknown.
	//! This XML Parser can read any type of text files from any source where irrlicht
	//! can read. Just call IFileSystem::createXMLReader(). 
	//! For more informations on how to use the parser, see IIrrXMLReader
	typedef IIrrXMLReader<wchar_t, IUnknown> IXMLReader;

	//! A xml reader for ASCII or UTF-8 characters, derived from IUnknown.
	//! This XML Parser can read any type of text files from any source where irrlicht
	//! can read. Just call IFileSystem::createXMLReaderUTF8(). 
	//! For more informations on how to use the parser, see IIrrXMLReader
	typedef IIrrXMLReader<c8, IUnknown> IXMLReaderUTF8;

} // end namespace io
} // end namespace irr

#endif


namespace irr
{
namespace video
{
	class ITexture;
} // end namespace video
namespace io
{
	class IXMLWriter;

//! Types of attributes available for IAttributes
enum E_ATTRIBUTE_TYPE
{
	// integer attribute
	EAT_INT = 0,

	// float attribute
	EAT_FLOAT,

	// string attribute
	EAT_STRING,

	// boolean attribute
	EAT_BOOL,

	// enumeration attribute
	EAT_ENUM,

	// color attribute
	EAT_COLOR,

	// floating point color attribute
	EAT_COLORF,

	// 3d vector attribute
	EAT_VECTOR3D,

	// 2d position attribute
	EAT_POSITION2D,

	// vector 2d
	EAT_VECTOR2D,

	// rectangle attribute
	EAT_RECT,

	// matrix attribute
	EAT_MATRIX,

	// quaternion attribute
	EAT_QUATERNION,

	// 3d bounding box
	EAT_BBOX,

	// plane
	EAT_PLANE,

	// 3d triangle
	EAT_TRIANGLE3D,

	// line 2d
	EAT_LINE2D,

	// line 3d
	EAT_LINE3D,

	// array of stringws attribute
	EAT_STRINGWARRAY,

	// array of float
	EAT_FLOATARRAY,

	// array of int
	EAT_INTARRAY,

	// binary data attribute
	EAT_BINARY,

	// texture reference attribute
	EAT_TEXTURE,

	// known attribute type count
	EAT_COUNT,

	// unknown attribute
	EAT_UNKNOWN
};

//! Provides a generic interface for attributes and their values and the possiblity to serialize them
class IAttributes : public virtual IUnknown
{
public:

	//! Returns amount of attributes in this collection of attributes.
	virtual s32 getAttributeCount() = 0;

	//! Returns attribute name by index. 
	//! \param index: Index value, must be between 0 and getAttributeCount()-1.
	virtual const c8* getAttributeName(s32 index) = 0;

	//! Returns the type of an attribute
	//! \param attributeName: Name for the attribute
	virtual E_ATTRIBUTE_TYPE getAttributeType(const c8* attributeName) = 0;

	//! Returns attribute type by index. 
	//! \param index: Index value, must be between 0 and getAttributeCount()-1.
	virtual E_ATTRIBUTE_TYPE getAttributeType(s32 index) = 0;

	//! Returns the type string of the attribute
	//! \param attributeName: String for the attribute type
	virtual const wchar_t* getAttributeTypeString(const c8* attributeName) = 0;

	//! Returns the type string of the attribute by index. 
	//! \param index: Index value, must be between 0 and getAttributeCount()-1.
	virtual const wchar_t* getAttributeTypeString(s32 index) = 0;

	//! Returns if an attribute with a name exists
	virtual bool existsAttribute(const c8* attributeName) = 0;

	//! Returns attribute index from name, -1 if not found
	virtual s32 findAttribute(const c8* attributeName) = 0;

	//! Removes all attributes
	virtual void clear() = 0;

	//! Reads attributes from a xml file.
	//! \param readCurrentElementOnly: If set to true, reading only works if current element has the name 'attributes'.
	//! If set to false, the first appearing list attributes are read.
	virtual bool read(irr::io::IXMLReader* reader, bool readCurrentElementOnly=false) = 0;

	//! Write these attributes into a xml file
	//! \param writer: The XML writer to write to
	//! \param writeXMLHeader: Writes a header to the XML file, required if at the beginning of the file
	//! and you haven't already written one with writer->writeXMLHeader()
	virtual bool write(io::IXMLWriter* writer, bool writeXMLHeader=false) = 0;


	/*

		Integer Attribute

	*/

	//! Adds an attribute as integer
	virtual void addInt(const c8* attributeName, s32 value) = 0;

	//! Sets an attribute as integer value
	virtual void setAttribute(const c8* attributeName, s32 value) = 0;

	//! Gets an attribute as integer value
	//! \param attributeName: Name of the attribute to get.
	//! \return Returns value of the attribute previously set by setAttribute()
	virtual s32 getAttributeAsInt(const c8* attributeName) = 0;

	//! Gets an attribute as integer value
	//! \param index: Index value, must be between 0 and getAttributeCount()-1.
	virtual s32 getAttributeAsInt(s32 index) = 0;

	//! Sets an attribute as integer value
	virtual void setAttribute(s32 index, s32 value) = 0;

	/*

		Float Attribute

	*/

	//! Adds an attribute as float
	virtual void addFloat(const c8* attributeName, f32 value) = 0;

	//! Sets a attribute as float value
	virtual void setAttribute(const c8* attributeName, f32 value) = 0;

	//! Gets an attribute as float value
	//! \param attributeName: Name of the attribute to get.
	//! \return Returns value of the attribute previously set by setAttribute()
	virtual f32 getAttributeAsFloat(const c8* attributeName) = 0;

	//! Gets an attribute as float value
	//! \param index: Index value, must be between 0 and getAttributeCount()-1.
	virtual f32 getAttributeAsFloat(s32 index) = 0;

	//! Sets an attribute as float value
	virtual void setAttribute(s32 index, f32 value) = 0;

	/*

		String Attribute

	*/

	//! Adds an attribute as string
	virtual void addString(const c8* attributeName, const c8* value) = 0;

	//! Sets an attribute value as string. 
	//! \param attributeName: Name for the attribute
	//! \param value: Value for the attribute. Set this to 0 to delete the attribute
	virtual void setAttribute(const c8* attributeName, const c8* value) = 0;

	//! Gets an attribute as string.
	//! \param attributeName: Name of the attribute to get.
	//! \return Returns value of the attribute previously set by setAttribute() 
	//! or 0 if attribute is not set.
	virtual core::stringc getAttributeAsString(const c8* attributeName) = 0;

	//! Gets an attribute as string.
	//! \param attributeName: Name of the attribute to get.
	//! \param target: Buffer where the string is copied to.
	virtual void getAttributeAsString(const c8* attributeName, c8* target) = 0;

	//! Returns attribute value as string by index. 
	//! \param index: Index value, must be between 0 and getAttributeCount()-1.
	virtual core::stringc getAttributeAsString(s32 index) = 0;

	//! Sets an attribute value as string. 
	//! \param attributeName: Name for the attribute
	virtual void setAttribute(s32 index, const c8* value) = 0;

	// wide strings

	//! Adds an attribute as string
	virtual void addString(const c8* attributeName, const wchar_t* value) = 0;

	//! Sets an attribute value as string. 
	//! \param attributeName: Name for the attribute
	//! \param value: Value for the attribute. Set this to 0 to delete the attribute
	virtual void setAttribute(const c8* attributeName, const wchar_t* value) = 0;

	//! Gets an attribute as string.
	//! \param attributeName: Name of the attribute to get.
	//! \return Returns value of the attribute previously set by setAttribute() 
	//! or 0 if attribute is not set.
	virtual core::stringw getAttributeAsStringW(const c8* attributeName) = 0;

	//! Gets an attribute as string.
	//! \param attributeName: Name of the attribute to get.
	//! \param target: Buffer where the string is copied to.
	virtual void getAttributeAsStringW(const c8* attributeName, wchar_t* target) = 0;

	//! Returns attribute value as string by index. 
	//! \param index: Index value, must be between 0 and getAttributeCount()-1.
	virtual core::stringw getAttributeAsStringW(s32 index) = 0;

	//! Sets an attribute value as string. 
	//! \param attributeName: Name for the attribute
	virtual void setAttribute(s32 index, const wchar_t* value) = 0;

	/*

		Binary Data Attribute

	*/

	//! Adds an attribute as binary data
	virtual void addBinary(const c8* attributeName, void* data, s32 dataSizeInBytes) = 0;

	//! Sets an attribute as binary data
	virtual void setAttribute(const c8* attributeName, void* data, s32 dataSizeInBytes ) = 0;

	//! Gets an attribute as binary data
	//! \param attributeName: Name of the attribute to get.
	virtual void getAttributeAsBinaryData(const c8* attributeName, void* outData, s32 maxSizeInBytes) = 0;

	//! Gets an attribute as binary data
	//! \param index: Index value, must be between 0 and getAttributeCount()-1.
	virtual void getAttributeAsBinaryData(s32 index, void* outData, s32 maxSizeInBytes) = 0;

	//! Sets an attribute as binary data
	virtual void setAttribute(s32 index, void* data, s32 dataSizeInBytes ) = 0;


	/*

		Array Attribute

	*/

	//! Adds an attribute as wide string array
	virtual void addArray(const c8* attributeName, core::array<core::stringw> value) = 0;

	//! Sets an attribute value as a wide string array. 
	//! \param attributeName: Name for the attribute
	//! \param value: Value for the attribute. Set this to 0 to delete the attribute
	virtual void setAttribute(const c8* attributeName, const core::array<core::stringw> value) = 0;

	//! Gets an attribute as an array of wide strings.
	//! \param attributeName: Name of the attribute to get.
	//! \return Returns value of the attribute previously set by setAttribute() 
	//! or 0 if attribute is not set.
	virtual core::array<core::stringw> getAttributeAsArray(const c8* attributeName) = 0;

	//! Returns attribute value as an array of wide strings by index. 
	//! \param index: Index value, must be between 0 and getAttributeCount()-1.
	virtual core::array<core::stringw> getAttributeAsArray(s32 index) = 0;

	//! Sets an attribute as an array of wide strings
	virtual void setAttribute(s32 index, core::array<core::stringw> value) = 0;


	/*

		Bool Attribute

	*/

	//! Adds an attribute as bool
	virtual void addBool(const c8* attributeName, bool value) = 0;

	//! Sets an attribute as boolean value
	virtual void setAttribute(const c8* attributeName, bool value) = 0;

	//! Gets an attribute as boolean value
	//! \param attributeName: Name of the attribute to get.
	//! \return Returns value of the attribute previously set by setAttribute() 
	virtual bool getAttributeAsBool(const c8* attributeName) = 0;

	//! Gets an attribute as boolean value
	//! \param index: Index value, must be between 0 and getAttributeCount()-1.
	virtual bool getAttributeAsBool(s32 index) = 0;

	//! Sets an attribute as boolean value
	virtual void setAttribute(s32 index, bool value) = 0;

	/*

		Enumeration Attribute

	*/

	//! Adds an attribute as enum
	virtual void addEnum(const c8* attributeName, const c8* enumValue, const c8* const* enumerationLiterals) = 0;

	//! Adds an attribute as enum
	virtual void addEnum(const c8* attributeName, s32 enumValue, const c8* const* enumerationLiterals) = 0;

	//! Sets an attribute as enumeration
	virtual void setAttribute(const c8* attributeName, const c8* enumValue, const c8* const* enumerationLiterals) = 0;

	//! Gets an attribute as enumeration
	//! \param attributeName: Name of the attribute to get.
	//! \return Returns value of the attribute previously set by setAttribute()
	virtual const c8* getAttributeAsEnumeration(const c8* attributeName) = 0;

	//! Gets an attribute as enumeration
	//! \param attributeName: Name of the attribute to get.
	//! \param enumerationLiteralsToUse: Use these enumeration literals to get the index value instead of the set ones.
	//! This is useful when the attribute list maybe was read from an xml file, and only contains the enumeration string, but
	//! no information about its index.
	//! \return Returns value of the attribute previously set by setAttribute()
	virtual s32 getAttributeAsEnumeration(const c8* attributeName, const c8* const* enumerationLiteralsToUse) = 0;

	//! Gets an attribute as enumeration
	//! \param index: Index value, must be between 0 and getAttributeCount()-1.
	virtual s32 getAttributeAsEnumeration(s32 index, const c8* const* enumerationLiteralsToUse) = 0;

	//! Gets an attribute as enumeration
	//! \param index: Index value, must be between 0 and getAttributeCount()-1.
	virtual const c8* getAttributeAsEnumeration(s32 index) = 0;

	//! Gets the list of enumeration literals of an enumeration attribute 
	//! \param attributeName: Name of the attribute to get.
	virtual void getAttributeEnumerationLiteralsOfEnumeration(const c8* attributeName, core::array<core::stringc>& outLiterals) = 0;

	//! Gets the list of enumeration literals of an enumeration attribute 
	//! \param index: Index value, must be between 0 and getAttributeCount()-1.
	virtual void getAttributeEnumerationLiteralsOfEnumeration(s32 index, core::array<core::stringc>& outLiterals) = 0;

	//! Sets an attribute as enumeration
	virtual void setAttribute(s32 index, const c8* enumValue, const c8* const* enumerationLiterals) = 0;


	/*

		SColor Attribute

	*/

	//! Adds an attribute as color
	virtual void addColor(const c8* attributeName, video::SColor value) = 0;


	//! Sets a attribute as color
	virtual void setAttribute(const c8* attributeName, video::SColor color) = 0;

	//! Gets an attribute as color
	//! \param attributeName: Name of the attribute to get.
	//! \return Returns value of the attribute previously set by setAttribute()
	virtual video::SColor getAttributeAsColor(const c8* attributeName) = 0;

	//! Gets an attribute as color
	//! \param index: Index value, must be between 0 and getAttributeCount()-1.
	virtual video::SColor getAttributeAsColor(s32 index) = 0;

	//! Sets an attribute as color
	virtual void setAttribute(s32 index, video::SColor color) = 0;

	/*

		SColorf Attribute

	*/

	//! Adds an attribute as floating point color
	virtual void addColorf(const c8* attributeName, video::SColorf value) = 0;

	//! Sets a attribute as floating point color
	virtual void setAttribute(const c8* attributeName, video::SColorf color) = 0;

	//! Gets an attribute as floating point color
	//! \param attributeName: Name of the attribute to get.
	//! \return Returns value of the attribute previously set by setAttribute()
	virtual video::SColorf getAttributeAsColorf(const c8* attributeName) = 0;

	//! Gets an attribute as floating point color
	//! \param index: Index value, must be between 0 and getAttributeCount()-1.
	virtual video::SColorf getAttributeAsColorf(s32 index) = 0;

	//! Sets an attribute as floating point color
	virtual void setAttribute(s32 index, video::SColorf color) = 0;


	/*

		Vector3d Attribute

	*/

	//! Adds an attribute as 3d vector
	virtual void addVector3d(const c8* attributeName, core::vector3df value) = 0;

	//! Sets a attribute as 3d vector
	virtual void setAttribute(const c8* attributeName, core::vector3df v) = 0;

	//! Gets an attribute as 3d vector
	//! \param attributeName: Name of the attribute to get.
	//! \return Returns value of the attribute previously set by setAttribute()
	virtual core::vector3df getAttributeAsVector3d(const c8* attributeName) = 0;

	//! Gets an attribute as 3d vector
	//! \param index: Index value, must be between 0 and getAttributeCount()-1.
	virtual core::vector3df getAttributeAsVector3d(s32 index) = 0;
	
	//! Sets an attribute as vector
	virtual void setAttribute(s32 index, core::vector3df v) = 0;

	/*

		Position2d Attribute

	*/

	//! Adds an attribute as 2d position
	virtual void addPosition2d(const c8* attributeName, core::position2di value) = 0;

	//! Sets a attribute as 2d position
	virtual void setAttribute(const c8* attributeName, core::position2di v) = 0;

	//! Gets an attribute as position
	//! \param attributeName: Name of the attribute to get.
	//! \return Returns value of the attribute previously set by setAttribute()
	virtual core::position2di getAttributeAsPosition2d(const c8* attributeName) = 0;

	//! Gets an attribute as position
	//! \param index: Index value, must be between 0 and getAttributeCount()-1.
	virtual core::position2di getAttributeAsPosition2d(s32 index) = 0;

	//! Sets an attribute as 2d position
	virtual void setAttribute(s32 index, core::position2di v) = 0;

	/*

		Rectangle Attribute

	*/

	//! Adds an attribute as rectangle
	virtual void addRect(const c8* attributeName, core::rect<s32> value) = 0;

	//! Sets an attribute as rectangle
	virtual void setAttribute(const c8* attributeName, core::rect<s32> v) = 0;

	//! Gets an attribute as rectangle
	//! \param attributeName: Name of the attribute to get.
	//! \return Returns value of the attribute previously set by setAttribute()
	virtual core::rect<s32> getAttributeAsRect(const c8* attributeName) = 0;

	//! Gets an attribute as rectangle
	//! \param index: Index value, must be between 0 and getAttributeCount()-1.
	virtual core::rect<s32> getAttributeAsRect(s32 index) = 0;

	//! Sets an attribute as rectangle
	virtual void setAttribute(s32 index, core::rect<s32> v) = 0;


	/*

		matrix attribute

	*/ 

	//! Adds an attribute as matrix
	virtual void addMatrix(const c8* attributeName, core::matrix4 v) = 0;

	//! Sets an attribute as matrix
	virtual void setAttribute(const c8* attributeName, core::matrix4 v) = 0;

	//! Gets an attribute as a matrix4
	//! \param attributeName: Name of the attribute to get.
	//! \return Returns value of the attribute previously set by setAttribute()
	virtual core::matrix4 getAttributeAsMatrix(const c8* attributeName) = 0;

	//! Gets an attribute as matrix
	//! \param index: Index value, must be between 0 and getAttributeCount()-1.
	virtual core::matrix4 getAttributeAsMatrix(s32 index) = 0;

	//! Sets an attribute as matrix
	virtual void setAttribute(s32 index, core::matrix4 v) = 0;

	/*
		quaternion attribute

	*/

	//! Adds an attribute as quaternion
	virtual void addQuaternion(const c8* attributeName, core::quaternion v) = 0;

	//! Sets an attribute as quaternion
	virtual void setAttribute(const c8* attributeName, core::quaternion v) = 0;

	//! Gets an attribute as a quaternion
	//! \param attributeName: Name of the attribute to get.
	//! \return Returns value of the attribute previously set by setAttribute()
	virtual core::quaternion getAttributeAsQuaternion(const c8* attributeName) = 0;

	//! Gets an attribute as quaternion
	//! \param index: Index value, must be between 0 and getAttributeCount()-1.
	virtual core::quaternion getAttributeAsQuaternion(s32 index) = 0;

	//! Sets an attribute as quaternion
	virtual void setAttribute(s32 index, core::quaternion v) = 0;

	/*

		3d bounding box

	*/

	//! Adds an attribute as axis aligned bounding box
	virtual void addBox3d(const c8* attributeName, core::aabbox3df v) = 0;

	//! Sets an attribute as axis aligned bounding box
	virtual void setAttribute(const c8* attributeName, core::aabbox3df v) = 0;

	//! Gets an attribute as a axis aligned bounding box
	//! \param attributeName: Name of the attribute to get.
	//! \return Returns value of the attribute previously set by setAttribute()
	virtual core::aabbox3df getAttributeAsBox3d(const c8* attributeName) = 0;

	//! Gets an attribute as axis aligned bounding box
	//! \param index: Index value, must be between 0 and getAttributeCount()-1.
	virtual core::aabbox3df getAttributeAsBox3d(s32 index) = 0;

	//! Sets an attribute as axis aligned bounding box
	virtual void setAttribute(s32 index, core::aabbox3df v) = 0;

	/*

		plane

	*/

	//! Adds an attribute as 3d plane
	virtual void addPlane3d(const c8* attributeName, core::plane3df v) = 0;

	//! Sets an attribute as 3d plane
	virtual void setAttribute(const c8* attributeName, core::plane3df v) = 0;

	//! Gets an attribute as a 3d plane
	//! \param attributeName: Name of the attribute to get.
	//! \return Returns value of the attribute previously set by setAttribute()
	virtual core::plane3df getAttributeAsPlane3d(const c8* attributeName) = 0;

	//! Gets an attribute as 3d plane
	//! \param index: Index value, must be between 0 and getAttributeCount()-1.
	virtual core::plane3df getAttributeAsPlane3d(s32 index) = 0;

	//! Sets an attribute as 3d plane
	virtual void setAttribute(s32 index, core::plane3df v) = 0;


	/*

		3d triangle

	*/

	//! Adds an attribute as 3d triangle
	virtual void addTriangle3d(const c8* attributeName, core::triangle3df v) = 0;

	//! Sets an attribute as 3d trianle
	virtual void setAttribute(const c8* attributeName, core::triangle3df v) = 0;

	//! Gets an attribute as a 3d triangle
	//! \param attributeName: Name of the attribute to get.
	//! \return Returns value of the attribute previously set by setAttribute()
	virtual core::triangle3df getAttributeAsTriangle3d(const c8* attributeName) = 0;

	//! Gets an attribute as 3d triangle
	//! \param index: Index value, must be between 0 and getAttributeCount()-1.
	virtual core::triangle3df getAttributeAsTriangle3d(s32 index) = 0;

	//! Sets an attribute as 3d triangle
	virtual void setAttribute(s32 index, core::triangle3df v) = 0;


	/*

		line 2d

	*/

	//! Adds an attribute as a 2d line
	virtual void addLine2d(const c8* attributeName, core::line2df v) = 0;

	//! Sets an attribute as a 2d line
	virtual void setAttribute(const c8* attributeName, core::line2df v) = 0;

	//! Gets an attribute as a 2d line
	//! \param attributeName: Name of the attribute to get.
	//! \return Returns value of the attribute previously set by setAttribute()
	virtual core::line2df getAttributeAsLine2d(const c8* attributeName) = 0;

	//! Gets an attribute as a 2d line
	//! \param index: Index value, must be between 0 and getAttributeCount()-1.
	virtual core::line2df getAttributeAsLine2d(s32 index) = 0;

	//! Sets an attribute as a 2d line
	virtual void setAttribute(s32 index, core::line2df v) = 0;


	/*

		line 3d

	*/

	//! Adds an attribute as a 3d line
	virtual void addLine3d(const c8* attributeName, core::line3df v) = 0;

	//! Sets an attribute as a 3d line
	virtual void setAttribute(const c8* attributeName, core::line3df v) = 0;

	//! Gets an attribute as a 3d line
	//! \param attributeName: Name of the attribute to get.
	//! \return Returns value of the attribute previously set by setAttribute()
	virtual core::line3df getAttributeAsLine3d(const c8* attributeName) = 0;

	//! Gets an attribute as a 3d line
	//! \param index: Index value, must be between 0 and getAttributeCount()-1.
	virtual core::line3df getAttributeAsLine3d(s32 index) = 0;

	//! Sets an attribute as a 3d line
	virtual void setAttribute(s32 index, core::line3df v) = 0;


	/*

		Texture Attribute

	*/

	//! Adds an attribute as texture reference
	virtual void addTexture(const c8* attributeName, video::ITexture* texture) = 0;

	//! Sets an attribute as texture reference
	virtual void setAttribute(const c8* attributeName, video::ITexture* texture ) = 0;

	//! Gets an attribute as texture reference
	//! \param attributeName: Name of the attribute to get.
	virtual video::ITexture* getAttributeAsTexture(const c8* attributeName) = 0;

	//! Gets an attribute as texture reference
	//! \param index: Index value, must be between 0 and getAttributeCount()-1.
	virtual video::ITexture* getAttributeAsTexture(s32 index) = 0;

	//! Sets an attribute as texture reference
	virtual void setAttribute(s32 index, video::ITexture* texture) = 0;

};

} // end namespace io
} // end namespace irr

#endif



// Copyright (C) 2002-2007 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __I_ATTRIBUTE_EXCHANGING_OBJECT_H_INCLUDED__
#define __I_ATTRIBUTE_EXCHANGING_OBJECT_H_INCLUDED__



namespace irr
{

namespace io
{

class IAttributes;

//! Enumation flags passed through SAttributeReadWriteOptions to the IAttributeExchangingObject object
enum E_ATTRIBUTE_READ_WRITE_FLAGS
{
	//! Serialization/Deserializion is done for an xml file
	EARWF_FOR_FILE = 0x00000001,

	//! Serialization/Deserializion is done for an editor property box
	EARWF_FOR_EDITOR = 0x00000002,

	//! When writing filenames, relative paths should be used
	EARWF_USE_RELATIVE_PATHS = 0x00000004
};


//! struct holding data describing options 
struct SAttributeReadWriteOptions
{
	//! constructor
	SAttributeReadWriteOptions()
		: Flags(0), Filename(0)
	{
	}

	//! Combination of E_ATTRIBUTE_READ_WRITE_FLAGS or other, custom ones
	s32 Flags; 

	//! optional filename
	const c8* Filename;
};


//! An object which is able to serialize and deserialize its attributes into an attributes object
class IAttributeExchangingObject : public virtual IUnknown
{
public:

	//! Writes attributes of the object.
	//! Implement this to expose the attributes of your scene node animator for 
	//! scripting languages, editors, debuggers or xml serialization purposes.
	virtual void serializeAttributes(io::IAttributes* out, io::SAttributeReadWriteOptions* options=0)	{}

	//! Reads attributes of the object.
	//! Implement this to set the attributes of your scene node animator for 
	//! scripting languages, editors, debuggers or xml deserialization purposes.
	virtual void deserializeAttributes(io::IAttributes* in, io::SAttributeReadWriteOptions* options=0)	{}

};

} // end namespace io
} // end namespace irr

#endif

// Copyright (C) 2002-2007 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __I_ANIMATED_MESH_H_INCLUDED__
#define __I_ANIMATED_MESH_H_INCLUDED__

// Copyright (C) 2002-2007 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __I_MESH_H_INCLUDED__
#define __I_MESH_H_INCLUDED__

// Copyright (C) 2002-2007 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __I_MESH_BUFFER_H_INCLUDED__
#define __I_MESH_BUFFER_H_INCLUDED__

// Copyright (C) 2002-2007 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __S_MATERIAL_H_INCLUDED__
#define __S_MATERIAL_H_INCLUDED__

// Copyright (C) 2002-2007 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __I_TEXTURE_H_INCLUDED__
#define __I_TEXTURE_H_INCLUDED__

// Copyright (C) 2002-2007 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __I_IMAGE_H_INCLUDED__
#define __I_IMAGE_H_INCLUDED__


namespace irr
{
namespace video  
{

//! An enum for the color format of textures used by the Irrlicht Engine.
/* A color format specifies how color information is stored. */
enum ECOLOR_FORMAT
{
	//! 16 bit color format used by the software driver, and thus preferred
	//! by all other irrlicht engine video drivers. There are 5 bits for every
	//! color component, and a single bit is left for alpha information.
	ECF_A1R5G5B5 = 0,	

	//! Standard 16 bit color format.
	ECF_R5G6B5,

	//! 24 bit color, no alpha channel, but 8 bit for red, green and blue.
	ECF_R8G8B8,

	//! Default 32 bit color format. 8 bits are used for every component:
	//! red, green, blue and alpha.
	ECF_A8R8G8B8
};


//!	Interface for software image data.
/* Image loaders create these images from files. IVideoDrivers convert
these images into their (hardware) textures. 
*/
class IImage : public virtual IUnknown
{
public:

	//! destructor
	virtual ~IImage() {};

	//! Lock function. Use this to get a pointer to the image data. After you
	//! don't need the pointer anymore, you must call unlock().
	//! \return Returns pointer to the image data. What type of data
	//! is pointed to depends on the color format of the image. For example
	//! if the color format is ECF_A8R8G8B8, it is of s32.
	//! Be sure to call unlock() after you don't need the pointer any more.
	virtual void* lock() = 0;

	//! Unlock function.
	//! Should be called after the pointer received by lock() is not
	//! needed anymore.
	virtual void unlock() = 0;

	//! Returns width and height of image data.
	virtual const core::dimension2d<s32>& getDimension() = 0;

	//! Returns bits per pixel. 
	virtual s32 getBitsPerPixel() = 0;

	//! Returns bytes per pixel
	virtual s32 getBytesPerPixel() = 0;

	//! Returns image data size in bytes
	virtual s32 getImageDataSizeInBytes() = 0;

	//! Returns image data size in pixels
	virtual s32 getImageDataSizeInPixels() = 0;

	//! returns a pixel
	virtual SColor getPixel(s32 x, s32 y) = 0;

	//! returns the color format
	virtual ECOLOR_FORMAT getColorFormat() const = 0;

	//! returns mask for red value of a pixel
	virtual u32 getRedMask() = 0;

	//! returns mask for green value of a pixel
	virtual u32 getGreenMask() = 0;

	//! returns mask for blue value of a pixel
	virtual u32 getBlueMask() = 0;

	//! returns mask for alpha value of a pixel
	virtual u32 getAlphaMask() = 0;

	//! returns pitch of image
	virtual u32 getPitch() const = 0;

};

} // end namespace video
} // end namespace irr

#endif


namespace irr
{
namespace video  
{


//! Enumeration flags telling the video driver in which format textures
//! should be created.
enum E_TEXTURE_CREATION_FLAG
{
	//! Forces the driver to create 16 bit textures always, independent of
	//! which format the file on disk has. When choosing this you may loose
	//! some color detail, but gain much speed and memory. 16 bit textures
	//! can be transferred twice as fast as 32 bit textures and only use 
	//! half of the space in memory.
	//! When using this flag, it does not make sense to use the flags
	//! ETCF_ALWAYS_32_BIT, ETCF_OPTIMIZED_FOR_QUALITY,
	//! or ETCF_OPTIMIZED_FOR_SPEED at the same time.
	ETCF_ALWAYS_16_BIT = 0x00000001,

	//! Forces the driver to create 32 bit textures always, independent of
	//! which format the file on disk has. Please note that some drivers 
	//! (like the software device) will ignore this, because they are only
	//! able to create and use 16 bit textures.
	//! When using this flag, it does not make sense to use the flags
	//! ETCF_ALWAYS_16_BIT, ETCF_OPTIMIZED_FOR_QUALITY,
	//! or ETCF_OPTIMIZED_FOR_SPEED at the same time.
	ETCF_ALWAYS_32_BIT = 0x00000002,

	//! Lets the driver decide in which format the textures are created and
	//! tries to make the textures look as good as possible.
	//! Usually it simply chooses the format in which the texture was stored on disk.
	//! When using this flag, it does not make sense to use the flags
	//! ETCF_ALWAYS_16_BIT, ETCF_ALWAYS_32_BIT, 
	//! or ETCF_OPTIMIZED_FOR_SPEED at the same time.
	ETCF_OPTIMIZED_FOR_QUALITY  = 0x00000004,

	//! Lets the driver decide in which format the textures are created and
	//! tries to create them maximizing render speed.
	//! When using this flag, it does not make sense to use the flags
	//! ETCF_ALWAYS_16_BIT, ETCF_ALWAYS_32_BIT, or ETCF_OPTIMIZED_FOR_QUALITY,
	//! at the same time.
	ETCF_OPTIMIZED_FOR_SPEED = 0x00000008,

	//! Automatically creates mip map levels for the textures.
	ETCF_CREATE_MIP_MAPS = 0x00000010,

	//! This flag is never used, it only forces the compiler to 
	//! compile these enumeration values to 32 bit.
	ETCF_FORCE_32_BIT_DO_NOT_USE = 0x7fffffff
};


//! Helper function, helps to get the desired texture creation format from the flags.
//! Returns either ETCF_ALWAYS_32_BIT, ETCF_ALWAYS_16_BIT, ETCF_OPTIMIZED_FOR_QUALITY,
//! or ETCF_OPTIMIZED_FOR_SPEED.
inline E_TEXTURE_CREATION_FLAG getTextureFormatFromFlags(u32 flags)
{
	if (flags & ETCF_OPTIMIZED_FOR_SPEED)
		return ETCF_OPTIMIZED_FOR_SPEED;
	if (flags & ETCF_ALWAYS_16_BIT)
		return ETCF_ALWAYS_16_BIT;
	if (flags & ETCF_ALWAYS_32_BIT)
		return ETCF_ALWAYS_32_BIT;
	if (flags & ETCF_OPTIMIZED_FOR_QUALITY)
		return ETCF_OPTIMIZED_FOR_QUALITY;
	return ETCF_OPTIMIZED_FOR_SPEED;
}


//! Interface of a Video Driver dependent Texture.
/**
	An ITexture is created by an IVideoDriver by using IVideoDriver::addTexture or
	IVideoDriver::getTexture. After that, the texture may only be used by this VideoDriver.
	As you can imagine, textures of the DirectX and the OpenGL device will, e.g., not be compatible.
	An exception is the Software device and the NULL device, their textures are compatible.
	If you try to use a texture created by one device with an other device, the device
	will refuse to do that and write a warning or an error message to the output buffer.
*/
class ITexture : public virtual IUnknown
{
public:

	//! constructor
	ITexture(const c8* name) : Name(name)
	{
		Name.make_lower();
	}

	//! destructor
	virtual ~ITexture() {};

	//! Lock function. 
	/* Locks the Texture and returns a pointer to access the 
	pixels. After lock() has been called and all operations on the pixels
	are done, you must call unlock().
	\return Returns a pointer to the pixel data. The format of the pixel can
	be determinated by using getColorFormat(). NULL is returned, if
	the texture cannot be locked. */
	virtual void* lock() = 0;

	//! Unlock function. Must be called after a lock() to the texture.
	virtual void unlock() = 0;

	//! Returns original size of the texture.
	/* The texture is usually
	scaled, if it was created with an unoptimal size. For example if the size
	of the texture file it was loaded from was not a power of two. This returns
	the size of the texture, it had before it was scaled. Can be useful
	when drawing 2d images on the screen, which should have the exact size
	of the original texture. Use ITexture::getSize() if you want to know 
	the real size it has now stored in the system.
	\return Returns the original size of the texture. */
	virtual const core::dimension2d<s32>& getOriginalSize() = 0;

	//! Returns dimension (=size) of the texture.
	/* \return Returns the size of the texture. */
	virtual const core::dimension2d<s32>& getSize() = 0;

	//! Returns driver type of texture. 
	/* This is the driver, which created the texture.
	This method is used internally by the video devices, to check, if they may
	use a texture because textures may be incompatible between different
	devices.
	\return Returns driver type of texture. */
	virtual E_DRIVER_TYPE getDriverType() = 0;

	//! Returns the color format of texture.
	/* \return Returns the color format of texture. */
	virtual ECOLOR_FORMAT getColorFormat() const = 0;

	//! Returns pitch of texture (in bytes).
	/* The pitch is the amount of bytes
	used for a row of pixels in a texture.
	\return Returns pitch of texture in bytes. */
	virtual u32 getPitch() const = 0;

	//! Returns whether the texture has MipMaps
	/* \return Returns true if texture has MipMaps, else false. */
	virtual bool hasMipMaps() { return false; }

	//! Regenerates the mip map levels of the texture.
	/* Useful after locking and modifying the texture */
	virtual void regenerateMipMapLevels() = 0;

	//! Returns name of texture (in most cases this is the filename)
	const core::stringc& getName() { return Name; }

protected:

	core::stringc Name;
};


} // end namespace video
} // end namespace irr

#endif


namespace irr
{
namespace video
{
	//! Abstracted and easy to use fixed function/programmable pipeline material modes.
	enum E_MATERIAL_TYPE
	{
		//! Standard solid material. Only first texture is used, which is
		//! supposed to be the diffuse material.
		EMT_SOLID = 0,

		//! Solid material with 2 texture layers. The second is blended onto the
		//! first using the alpha value of the vertex colors.
		//! This material is currently not implemented in OpenGL, but it
		//! works with DirectX.
		EMT_SOLID_2_LAYER,

		//! Material type with standard lightmap technique:
		//! There should be 2 textures: The first texture layer is a diffuse map,
		//! the second is a light map. Vertex light is ignored.
		EMT_LIGHTMAP,

		//! Material type with lightmap technique like EMT_LIGHTMAP, but
		//! lightmap and diffuse texture are not modulated, but added instead.
		EMT_LIGHTMAP_ADD,

		//! Material type with standard lightmap technique:
		//! There should be 2 textures: The first texture layer is a diffuse map,
		//! the second is a light map. Vertex light is ignored.
		//! The texture colors are effectively multiplyied by 2 for brightening.
		//! like known in DirectX as D3DTOP_MODULATE2X.
		EMT_LIGHTMAP_M2,

		//! Material type with standard lightmap technique:
		//! There should be 2 textures: The first texture layer is a diffuse map,
		//! the second is a light map. Vertex light is ignored.
		//! The texture colors are effectively multiplyied by 4 for brightening.
		//! like known in DirectX as D3DTOP_MODULATE4X.
		EMT_LIGHTMAP_M4,

		//! Like EMT_LIGHTMAP, but also supports dynamic lighting.
		EMT_LIGHTMAP_LIGHTING,

		//! Like EMT_LIGHTMAP_M2, but also supports dynamic lighting.
		EMT_LIGHTMAP_LIGHTING_M2,

		//! Like EMT_LIGHTMAP_4, but also supports dynamic lighting.
		EMT_LIGHTMAP_LIGHTING_M4,

		//! Detail mapped material. The first texture is diffuse color map, the
		//! second is added to this and usually displayed with a bigger scale value
		//! so that it adds more detail. The detail map is added to the diffuse map using
		//! ADD_SIGNED, so that it is possible to add and substract color from the diffuse
		//! map. For example a value of (127,127,127) will not change the appearance of
		//! the diffuse map at all.
		//! Often used for terrain rendering.
		EMT_DETAIL_MAP,

		//! Makes the material look like it was reflection the environment
		//! around it. To make this possible, a texture called 'sphere map'
		//! is used, which must be set as Textures[0].
		EMT_SPHERE_MAP,

		//! A reflecting material with an
		//! optional additional non reflecting texture layer. The reflection
		//! map should be set as Texture 1.
		EMT_REFLECTION_2_LAYER,

		//! A transparent material. Only the first texture is used.
		//! The new color is calculated by simply adding the source color and
		//! the dest color. This means if for example a billboard using a texture with
		//! black background and a red circle on it is drawn with this material, the
		//! result is that only the red circle will be drawn a little bit transparent,
		//! and everything which was black is 100% transparent and not visible.
		//! This material type is useful for e.g. particle effects.
		EMT_TRANSPARENT_ADD_COLOR,

		//! Makes the material transparent based on the texture alpha channel.
		//! The final color is blended together from the destination color and the
		//! texture color, using the alpha channel value as blend factor.
		//! Only first texture is used. If you are using this material with small
		//! textures, it is a good idea to load the texture in 32 bit
		//! mode (video::IVideoDriver::setTextureCreationFlag()).
		//! Also, an alpha ref is used, which can be manipulated using SMaterial::MaterialTypeParam.
		//! If set to 0, the alpha ref gets its default value which is 0.5f and which means
		//! that pixels with an alpha value >127 will be written, others not.  In other, simple
		//! words: this value controls how sharp the edges become when going from a
		//! transparent to a solid spot on the texture.
		EMT_TRANSPARENT_ALPHA_CHANNEL,

		//! Makes the material transparent based on the texture alpha channel.
		//! If the alpha channel value is greater than 127, a pixel is written to the
		//! target, otherwise not. This material does not use alpha blending
		//! and is a lot faster than EMT_TRANSPARENT_ALPHA_CHANNEL. It
		//! is ideal for drawing stuff like leafes of plants, because the borders
		//! are not blurry but sharp.
		//! Only first texture is used. If you are using this material with small
		//! textures and 3d object, it is a good idea to load the texture in 32 bit
		//! mode (video::IVideoDriver::setTextureCreationFlag()).
		EMT_TRANSPARENT_ALPHA_CHANNEL_REF,

		//! Makes the material transparent based on the vertex alpha value.
		EMT_TRANSPARENT_VERTEX_ALPHA,

		//! A transparent reflecting material with an
		//! optional additional non reflecting texture layer. The reflection
		//! map should be set as Texture 1. The transparency depends on the
		//! alpha value in the vertex colors. A texture which will not reflect
		//! can be set als Texture 2.
		//! Please note that this material type is currently not 100% implemented
		//! in OpenGL. It works in Direct3D.
		EMT_TRANSPARENT_REFLECTION_2_LAYER,

		//! A solid normal map renderer. First texture is the color map, the
		//! second should be the normal map. Note that you should use this material
		//! only when drawing geometry consisting of vertices of type S3DVertexTangents
		//! (EVT_TANGENTS). You can convert any mesh into this format using
		//! IMeshManipulator::createMeshWithTangents() (See SpecialFX2 Tutorial).
		//! This shader runs on vertex shader 1.1 and pixel shader 1.1 capable hardware and
		//! falls back on a fixed function lighted material if this hardware is not available.
		//! Only two lights are supported by this shader, if there are more, the nearest two
		//! are chosen. Currently, this shader is only implemented for the D3D8 and D3D9 renderers.
		EMT_NORMAL_MAP_SOLID,

		//! A transparent normal map renderer. First texture is the color map, the
		//! second should be the normal map. Note that you should use this material
		//! only when drawing geometry consisting of vertices of type S3DVertexTangents
		//! (EVT_TANGENTS). You can convert any mesh into this format using
		//! IMeshManipulator::createMeshWithTangents() (See SpecialFX2 Tutorial).
		//! This shader runs on vertex shader 1.1 and pixel shader 1.1 capable hardware and
		//! falls back on a fixed function lighted material if this hardware is not available.
		//! Only two lights are supported by this shader, if there are more, the nearest two
		//! are chosen. Currently, this shader is only implemented for the D3D8 and D3D9 renderers.
		EMT_NORMAL_MAP_TRANSPARENT_ADD_COLOR,

		//! A transparent (based on the vertex alpha value) normal map renderer.
		//! First texture is the color map, the
		//! second should be the normal map. Note that you should use this material
		//! only when drawing geometry consisting of vertices of type S3DVertexTangents
		//! (EVT_TANGENTS). You can convert any mesh into this format using
		//! IMeshManipulator::createMeshWithTangents() (See SpecialFX2 Tutorial).
		//! This shader runs on vertex shader 1.1 and pixel shader 1.1 capable hardware and
		//! falls back on a fixed function lighted material if this hardware is not available.
		//! Only two lights are supported by this shader, if there are more, the nearest two
		//! are chosen. Currently, this shader is only implemented for the D3D8 and D3D9 renderers.
		EMT_NORMAL_MAP_TRANSPARENT_VERTEX_ALPHA,

		//! Just like EMT_NORMAL_MAP_SOLID, but uses parallax mapping too, which
		//! looks a lot more realistic. This only works when the hardware supports at
		//! least vertex shader 1.1 and pixel shader 1.4.
		//! First texture is the color map, the  second should be the normal map.
		//! The normal map texture should contain the height value in the
		//! alpha component. The IVideoDriver::makeNormalMapTexture() method writes
		//! this value automaticly when creating normal maps from a heightmap when using a 32 bit
		//! texture.
		//! The height scale of the material (affecting the bumpiness) is being controlled
		//! by the SMaterial::MaterialTypeParam member.
		//! If set to zero, the default value (0.02f) will be applied. Otherwise
		//! the value set in SMaterial::MaterialTypeParam is taken. This value depends on with which
		//! scale the texture is mapped on the material. Too high or low values of MaterialTypeParam
		//! can result in strange artifacts.
		EMT_PARALLAX_MAP_SOLID,

		//! A material just like EMT_PARALLAX_MAP_SOLID, but it is transparent, using
		//! EMT_TRANSPARENT_ADD_COLOR as base material.
		EMT_PARALLAX_MAP_TRANSPARENT_ADD_COLOR,

		//! A material just like EMT_PARALLAX_MAP_SOLID, but it is transparent, using
		//! EMT_TRANSPARENT_VERTEX_ALPHA as base material.
		EMT_PARALLAX_MAP_TRANSPARENT_VERTEX_ALPHA,

		//! BlendFunc = source * sourceFactor + dest * destFactor ( E_BLEND_FUNC )
		//! Using only Textures[0]. generic Blender
		EMT_ONETEXTURE_BLEND,

		//! This value is not used. It only forces this enumeration to compile in 32 bit.
		EMT_FORCE_32BIT = 0x7fffffff
	};

	//! Flag for EMT_ONETEXTURE_BLEND, ( BlendFactor )
	//! BlendFunc = source * sourceFactor + dest * destFactor
	enum E_BLEND_FACTOR
	{
		EBF_ZERO	= 0,			// src & dest	(0, 0, 0, 0)
		EBF_ONE,					// src & dest	(1, 1, 1, 1)
		EBF_DST_COLOR, 				// src			(destR, destG, destB, destA)
		EBF_ONE_MINUS_DST_COLOR, 	// src			(1-destR, 1-destG, 1-destB, 1-destA)
		EBF_SRC_COLOR,				// dest			(srcR, srcG, srcB, srcA)
		EBF_ONE_MINUS_SRC_COLOR, 	// dest			(1-srcR, 1-srcG, 1-srcB, 1-srcA)
		EBF_SRC_ALPHA,				// src & dest	(srcA, srcA, srcA, srcA)
		EBF_ONE_MINUS_SRC_ALPHA,	// src & dest	(1-srcA, 1-srcA, 1-srcA, 1-srcA)
		EBF_DST_ALPHA,				// src & dest	(destA, destA, destA, destA)
		EBF_ONE_MINUS_DST_ALPHA,	// src & dest	(1-destA, 1-destA, 1-destA, 1-destA)
		EBF_SRC_ALPHA_SATURATE		// src			(min(srcA, 1-destA), idem, ...)
	};

	//! Texture coord clamp mode
	enum E_TEXTURE_CLAMP
	{
		ETC_REPEAT = 0,
		ETC_CLAMP,
		ETC_CLAMP_TO_EDGE,
		ETC_CLAMP_TO_BORDER,
		ETC_MIRROR
	};
	static const char* const aTextureClampNames[] = {
			"texture_clamp_repeat",
			"texture_clamp_clamp",
			"texture_clamp_clamp_to_edge",
			"texture_clamp_clamp_to_border",
			"texture_clamp_mirror", 0};

	//! MaterialTypeParam: eg. DirectX: D3DTOP_MODULATE, D3DTOP_MODULATE2X, D3DTOP_MODULATE4X
	enum E_MODULATE_FUNC
	{
		EMFN_MODULATE_1X	= 1,
		EMFN_MODULATE_2X	= 2,
		EMFN_MODULATE_4X	= 4
	};

	//! EMT_ONETEXTURE_BLEND: pack srcFact & dstFact and Modulo to MaterialTypeParam
	inline f32 pack_texureBlendFunc ( const E_BLEND_FACTOR srcFact, const E_BLEND_FACTOR dstFact, const E_MODULATE_FUNC modulate )
	{
		u32 state = modulate << 16 | srcFact << 8 | dstFact;
		return (f32&) state;
	}

	//! EMT_ONETEXTURE_BLEND: unpack srcFact & dstFact and Modulo to MaterialTypeParam
	inline void unpack_texureBlendFunc ( E_BLEND_FACTOR &srcFact, E_BLEND_FACTOR &dstFact, E_MODULATE_FUNC &modulo, const f32 param )
	{
		u32 state = (u32&)(param);
		modulo	= E_MODULATE_FUNC  ( ( state & 0x00FF0000 ) >> 16 );
		srcFact = E_BLEND_FACTOR   ( ( state & 0x0000FF00 ) >> 8  );
		dstFact = E_BLEND_FACTOR   ( ( state & 0x000000FF )       );
	}

	//! Material flags
	enum E_MATERIAL_FLAG
	{
		//! Draw as wireframe or filled triangles? Default: false
		EMF_WIREFRAME = 0,

		//! Draw as point cloud or filled triangles? Default: false
		EMF_POINTCLOUD,

		//! Flat or Gouraud shading? Default: true
		EMF_GOURAUD_SHADING,

		//! Will this material be lighted? Default: true
		EMF_LIGHTING,

		//! Is the ZBuffer enabled? Default: true
		EMF_ZBUFFER,

		//! May be written to the zbuffer or is it readonly. Default: true
		//! This flag is ignored, if the material type is a transparent type.
		EMF_ZWRITE_ENABLE,

		//! Is backfaceculling enabled? Default: true
		EMF_BACK_FACE_CULLING,

		//! Is bilinear filtering enabled? Default: true
		EMF_BILINEAR_FILTER,

		//! Is trilinear filtering enabled? Default: false
		//! If the trilinear filter flag is enabled,
		//! the bilinear filtering flag is ignored.
		EMF_TRILINEAR_FILTER,

		//! Is anisotropic filtering? Default: false
		//! In Irrlicht you can use anisotropic texture filtering in
		//! conjunction with bilinear or trilinear texture filtering
		//! to improve rendering results. Primitives will look less
		//! blurry with this flag switched on.
		EMF_ANISOTROPIC_FILTER,

		//! Is fog enabled? Default: false
		EMF_FOG_ENABLE,

		//! Normalizes normals.You can enable this if you need
		//! to scale a dynamic lighted model. Usually, its normals will get scaled
		//! too then and it will get darker. If you enable the EMF_NORMALIZE_NORMALS flag,
		//! the normals will be normalized again, and the model will look as bright as it should.
		EMF_NORMALIZE_NORMALS,

		//! Access to all layers texture wrap settings. Overwrites separate layer settings.
		EMF_TEXTURE_WRAP,

		//! This is not a flag, but a value indicating how much flags there are.
		EMF_MATERIAL_FLAG_COUNT
	};

	//! Maximum number of texture an SMaterial can have.
	const u32 MATERIAL_MAX_TEXTURES = 4;


	//! struct for holding parameters for a material renderer
	class SMaterial
	{
	public:
		//! default constructor, creates a solid material with standard colors
		SMaterial()
		: MaterialType(EMT_SOLID), AmbientColor(255,255,255,255), DiffuseColor(255,255,255,255),
			EmissiveColor(0,0,0,0), SpecularColor(255,255,255,255),
			Shininess(0.0f), MaterialTypeParam(0.0f), MaterialTypeParam2(0.0f), Thickness(1.0f),
			Wireframe(false), PointCloud(false), GouraudShading(true), Lighting(true),
			ZBuffer(true), ZWriteEnable(true), BackfaceCulling(true),
			BilinearFilter(true), TrilinearFilter(false), AnisotropicFilter(false),
			FogEnable(false), NormalizeNormals(false)
		{
			for (u32 i=0; i<MATERIAL_MAX_TEXTURES; ++i)
			{
				Textures[i] = 0;
				TextureMatrix[i] = 0;
				TextureWrap[i] = ETC_REPEAT;
			}
		}

		SMaterial(const SMaterial& other)
		{
			// These pointers are checked during assignment
			for (u32 i=0; i<MATERIAL_MAX_TEXTURES; ++i)
			{
				TextureMatrix[i] = 0;
			}
			*this = other;
		}

		~SMaterial()
		{
			for (u32 i=0; i<MATERIAL_MAX_TEXTURES; ++i)
				if (TextureMatrix[i])
					delete TextureMatrix[i];
		}

		SMaterial& operator=(const SMaterial& other)
		{
			MaterialType = other.MaterialType;

			AmbientColor = other.AmbientColor;
			DiffuseColor = other.DiffuseColor;
			EmissiveColor = other.EmissiveColor;
			SpecularColor = other.SpecularColor;
			Shininess = other.Shininess;
			MaterialTypeParam = other.MaterialTypeParam;
			MaterialTypeParam2 = other.MaterialTypeParam2;
			Thickness = other.Thickness;
			for (u32 i=0; i<MATERIAL_MAX_TEXTURES; ++i)
			{
				Textures[i] = other.Textures[i];
				if (TextureMatrix[i])
				{
					if (other.TextureMatrix[i])
						*TextureMatrix[i] = *other.TextureMatrix[i];
					else
					{
						delete TextureMatrix[i];
						TextureMatrix[i] = 0;
					}
				}
				else
				{
					if (other.TextureMatrix[i])
						TextureMatrix[i] = new core::matrix4(*other.TextureMatrix[i]);
					else
						TextureMatrix[i] = 0;
				}
				TextureWrap[i] = other.TextureWrap[i];
			}

			Wireframe = other.Wireframe;
			PointCloud = other.PointCloud;
			GouraudShading = other.GouraudShading;
			Lighting = other.Lighting;
			ZBuffer = other.ZBuffer;
			ZWriteEnable = other.ZWriteEnable;
			BackfaceCulling = other.BackfaceCulling;
			BilinearFilter = other.BilinearFilter;
			TrilinearFilter = other.TrilinearFilter;
			AnisotropicFilter = other.AnisotropicFilter;
			FogEnable = other.FogEnable;
			NormalizeNormals = other.NormalizeNormals;

			return *this;
		}

		//! Type of the material. Specifies how everything is blended together
		E_MATERIAL_TYPE MaterialType;

		//! How much ambient light (a global light) is reflected by this material.
		/* The default is full white, meaning objects are completely globally illuminated.
		 Reduce this if you want to see diffuse or specular light effects. */
		SColor AmbientColor;

		//! How much diffuse light coming from a light source is reflected by this material.
		/* The default is full white. */
		SColor DiffuseColor;

		//! Light emitted by this material. Default is to emitt no light.
		SColor EmissiveColor;

		//! How much specular light (highlights from a light) is reflected.
		/* The default is to reflect white specular light.  See SMaterial::Shininess how to
		enable specular lights. */
		SColor SpecularColor;

		//! Value affecting the size of specular highlights. A value of 20 is common.
		/* If set to 0, no specular highlights are being used.
		To activate, simply set the shininess of a material to a value other than 0:
		Using scene nodes:
		\code
		sceneNode->getMaterial(0).Shininess = 20.0f;
		\endcode

		You can also change the color of the highlights using
		\code
		sceneNode->getMaterial(0).SpecularColor.set(255,255,255,255);
		\endcode

		The specular color of the dynamic lights (SLight::SpecularColor) will influence
		the the highlight color too, but they are set to a useful value by default when
		creating the light scene node. Here is a simple example on how
		to use specular highlights:
		\code
		// load and display mesh
		scene::IAnimatedMeshSceneNode node = smgr->addAnimatedMeshSceneNode(
		smgr->getMesh("data/faerie.md2"));
		node->setMaterialTexture(0, driver->getTexture("data/Faerie2.pcx")); // set diffuse texture
		node->setMaterialFlag(video::EMF_LIGHTING, true); // enable dynamic lighting
		node->getMaterial(0).Shininess = 20.0f; // set size of specular highlights

		// add white light
		scene::ILightSceneNode light = smgr->addLightSceneNode(0,
		    core::vector3df(5,5,5), video::SColorf(1.0f, 1.0f, 1.0f));
		\endcode */
		f32 Shininess;

		//! Free parameter dependend on the material type.
		/* Mostly ignored, used for example in EMT_PARALLAX_MAP_SOLID
		and EMT_TRANSPARENT_ALPHA_CHANNEL. */
		f32 MaterialTypeParam;

		//! Second free parameter dependend on the material type.
		/* Mostly ignored. */
		f32 MaterialTypeParam2;

		//! Thickness of non-3dimensional elements such as lines and points.
		f32 Thickness;

		//! Texture layer array.
		ITexture* Textures[MATERIAL_MAX_TEXTURES];

		//! Texture Matrix array
		//! Do not acces the elements directly as the internal
		//! ressource management has to cope with Null pointers etc.
		core::matrix4* TextureMatrix[MATERIAL_MAX_TEXTURES];

		//! Texture Address Mode
		E_TEXTURE_CLAMP TextureWrap[MATERIAL_MAX_TEXTURES];

		//! material flag union.
		/* This enables the user to access the
		material flag using e.g: material.Wireframe = true or
		material.setFlag(EMF_WIREFRAME, true); */
		struct
		{
			//! Draw as wireframe or filled triangles? Default: false
			bool Wireframe;

			//! Draw as point cloud or filled triangles? Default: false
			bool PointCloud;

			//! Flat or Gouraud shading? Default: true
			bool GouraudShading;

			//! Will this material be lighted? Default: true
			bool Lighting;

			//! Is the ZBuffer enabled? Default: true
			//! Changed from Bool to Integer
			// ( 0 == ZBuffer Off, 1 == ZBuffer LessEqual, 2 == ZBuffer Equal )
			u32 ZBuffer;

			//! May be written to the zbuffer or is it readonly.
			/* Default: 1 This flag is ignored, if the MaterialType
			is a transparent type. */
			bool ZWriteEnable;

			//! Is backfaceculling enabled? Default: true
			bool BackfaceCulling;

			//! Is bilinear filtering enabled? Default: true
			bool BilinearFilter;

			//! Is trilinear filtering enabled? Default: false
			/* If the trilinear filter flag is enabled,
			the bilinear filtering flag is ignored. */
			bool TrilinearFilter;

			//! Is anisotropic filtering enabled? Default: false
			/* In Irrlicht you can use anisotropic texture filtering
			    in conjunction with bilinear or trilinear texture
			    filtering to improve rendering results. Primitives
			    will look less blurry with this flag switched on. */
			bool AnisotropicFilter;

			//! Is fog enabled? Default: false
			bool FogEnable;

			//! Should normals be normalized? Default: false
			bool NormalizeNormals;
		};

		core::matrix4& getTextureMatrix(u32 i)
		{
			if (i<MATERIAL_MAX_TEXTURES && !TextureMatrix[i])
				TextureMatrix[i] = new core::matrix4(core::matrix4::EM4CONST_IDENTITY);
			return *TextureMatrix[i];
		}

		const core::matrix4& getTextureMatrix(u32 i) const
		{
			if (i<MATERIAL_MAX_TEXTURES && TextureMatrix[i])
				return *TextureMatrix[i];
			else
				return core::IdentityMatrix;
		}

		void setTextureMatrix(u32 i, const core::matrix4& mat)
		{
			if (i>=MATERIAL_MAX_TEXTURES)
				return;
			if (!TextureMatrix[i])
				TextureMatrix[i] = new core::matrix4(mat);
			else
				*TextureMatrix[i] = mat;
		}

		void setFlag(E_MATERIAL_FLAG flag, bool value)
		{
			switch (flag)
			{
				case EMF_WIREFRAME:
					Wireframe = value; break;
				case EMF_POINTCLOUD:
					PointCloud = value; break;
				case EMF_GOURAUD_SHADING:
					GouraudShading = value; break;
				case EMF_LIGHTING:
					Lighting = value; break;
				case EMF_ZBUFFER:
					ZBuffer = value; break;
				case EMF_ZWRITE_ENABLE:
					ZWriteEnable = value; break;
				case EMF_BACK_FACE_CULLING:
					BackfaceCulling = value; break;
				case EMF_BILINEAR_FILTER:
					BilinearFilter = value; break;
				case EMF_TRILINEAR_FILTER:
					TrilinearFilter = value; break;
				case EMF_ANISOTROPIC_FILTER:
					AnisotropicFilter = value; break;
				case EMF_FOG_ENABLE:
					FogEnable = value; break;
				case EMF_NORMALIZE_NORMALS:
					NormalizeNormals = value; break;
				case EMF_TEXTURE_WRAP:
					TextureWrap[0] = TextureWrap[1] = TextureWrap[2] = TextureWrap[3] = (E_TEXTURE_CLAMP)value;
					break;
				default:
					break;
			}
		}

		bool getFlag(E_MATERIAL_FLAG flag) const
		{
			switch (flag)
			{
				case EMF_WIREFRAME:
					return Wireframe; break;
				case EMF_POINTCLOUD:
					return PointCloud; break;
				case EMF_GOURAUD_SHADING:
					return GouraudShading; break;
				case EMF_LIGHTING:
					return Lighting; break;
				case EMF_ZBUFFER:
					return ZBuffer!=0; break;
				case EMF_ZWRITE_ENABLE:
					return ZWriteEnable; break;
				case EMF_BACK_FACE_CULLING:
					return BackfaceCulling; break;
				case EMF_BILINEAR_FILTER:
					return BilinearFilter; break;
				case EMF_TRILINEAR_FILTER:
					return TrilinearFilter; break;
				case EMF_ANISOTROPIC_FILTER:
					return AnisotropicFilter; break;
				case EMF_FOG_ENABLE:
					return FogEnable; break;
				case EMF_NORMALIZE_NORMALS:
					return NormalizeNormals; break;
				case EMF_TEXTURE_WRAP:
					return !(TextureWrap[0] || TextureWrap[1] || TextureWrap[2] || TextureWrap[3]);
				case EMF_MATERIAL_FLAG_COUNT:
					break;
			}

			return false;
		}

		//! Compare operator
		inline bool operator!=(const SMaterial& b) const
		{
			return 
				Textures[0] != b.Textures[0] ||
				Textures[1] != b.Textures[1] ||
				Textures[2] != b.Textures[2] ||
				Textures[3] != b.Textures[3] ||
				MaterialType != b.MaterialType ||
				AmbientColor != b.AmbientColor ||
				DiffuseColor != b.DiffuseColor ||
				EmissiveColor != b.EmissiveColor ||
				SpecularColor != b.SpecularColor ||
				Shininess != b.Shininess ||
				MaterialTypeParam != b.MaterialTypeParam ||
				MaterialTypeParam2 != b.MaterialTypeParam2 ||
				Thickness != b.Thickness ||
				Wireframe != b.Wireframe ||
				PointCloud != b.PointCloud ||
				GouraudShading != b.GouraudShading ||
				Lighting != b.Lighting ||
				ZBuffer != b.ZBuffer ||
				ZWriteEnable != b.ZWriteEnable ||
				BackfaceCulling != b.BackfaceCulling ||
				BilinearFilter != b.BilinearFilter ||
				TrilinearFilter != b.TrilinearFilter ||
				AnisotropicFilter != b.AnisotropicFilter ||
				FogEnable != b.FogEnable ||
				NormalizeNormals != b.NormalizeNormals ||
				TextureWrap[0] != b.TextureWrap[0] ||
				TextureWrap[1] != b.TextureWrap[1] ||
				TextureWrap[2] != b.TextureWrap[2] ||
				TextureWrap[3] != b.TextureWrap[3] ||
				TextureMatrix[0] != b.TextureMatrix[0] ||
				TextureMatrix[1] != b.TextureMatrix[1] ||
				TextureMatrix[2] != b.TextureMatrix[2] ||
				TextureMatrix[3] != b.TextureMatrix[3];
		}
		inline bool operator==(const SMaterial& b) const
		{ return !(b!=*this); }
	};

} // end namespace video
} // end namespace irr

#endif

// Copyright (C) 2002-2007 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __S_3D_VERTEX_H_INCLUDED__
#define __S_3D_VERTEX_H_INCLUDED__


namespace irr
{
namespace video
{

//! Enumeration for all vertex types there are.
enum E_VERTEX_TYPE
{
	//! Standard vertex type used by the Irrlicht engine, video::S3DVertex.
	EVT_STANDARD = 0,

	//! Vertex with two texture coordinates, video::S3DVertex2TCoords. Usually used
	//! for geometry with lightmaps or other special materials.
	EVT_2TCOORDS,

	//! Vertex with a tangent and binormal vector, video::S3DVertexTangents. Usually
	//! used for tangent space normal mapping.
	EVT_TANGENTS
};

//! standard vertex used by the Irrlicht engine.
struct S3DVertex
{
	//! default constructor
	S3DVertex() {};

	//! constructor
	S3DVertex(f32 x, f32 y, f32 z, f32 nx, f32 ny, f32 nz, SColor c, f32 tu, f32 tv)
		: Pos(x,y,z), Normal(nx,ny,nz), Color(c), TCoords(tu,tv) {}

	//! constructor
	S3DVertex(const core::vector3df& pos, const core::vector3df& normal,
		SColor color, const core::vector2d<f32>& tcoords)
		: Pos(pos), Normal(normal), Color(color), TCoords(tcoords) {}

	//! Position
	core::vector3df Pos;
	
	//! Normal vector
	core::vector3df Normal;

	//! Color
	SColor Color;

	//! Texture coordinates
	core::vector2d<f32> TCoords;

	bool operator == (const S3DVertex& other) const
	{
		return (Pos == other.Pos && Normal == other.Normal &&
			Color == other.Color && TCoords == other.TCoords);
	}

	bool operator != (const S3DVertex& other) const
	{
		return (Pos != other.Pos || Normal != other.Normal ||
			Color != other.Color || TCoords != other.TCoords);
	}
};


//! Vertex with two texture coordinates.
/* Usually used for geometry with lightmaps
or other special materials.
*/
struct S3DVertex2TCoords
{
	//! default constructor
	S3DVertex2TCoords() {};

	//! constructor with two different texture coords
	S3DVertex2TCoords(f32 x, f32 y, f32 z, SColor c, f32 tu, f32 tv, f32 tu2, f32 tv2)
		: Pos(x,y,z), Color(c), TCoords(tu,tv), TCoords2(tu2,tv2) {}

	//! constructor with two different texture coords
	S3DVertex2TCoords(const core::vector3df& pos, SColor color,
		const core::vector2d<f32>& tcoords, const core::vector2d<f32>& tcoords2)
		: Pos(pos), Color(color), TCoords(tcoords), TCoords2(tcoords2) {}

	//! constructor 
	S3DVertex2TCoords(const core::vector3df& pos, const core::vector3df& normal, const SColor& color,
		const core::vector2d<f32>& tcoords, const core::vector2d<f32>& tcoords2)
		: Pos(pos), Normal(normal), Color(color), TCoords(tcoords), TCoords2(tcoords2) {}

	//! constructor with the same texture coords and normal
	S3DVertex2TCoords(f32 x, f32 y, f32 z, f32 nx, f32 ny, f32 nz, SColor c, f32 tu, f32 tv)
		: Pos(x,y,z), Normal(nx,ny,nz), Color(c), TCoords(tu,tv), TCoords2(tu,tv) {}

	//! constructor with the same texture coords and normal
	S3DVertex2TCoords(const core::vector3df& pos, const core::vector3df& normal,
		SColor color, const core::vector2d<f32>& tcoords)
		: Pos(pos), Normal(normal), Color(color), TCoords(tcoords), TCoords2(tcoords) {}

	//! Position
	core::vector3df Pos;

	//! Normal
	core::vector3df Normal;

	//! Color
	SColor Color;

	//! First set of texture coordinates
	core::vector2d<f32> TCoords;

	//! Second set of texture coordinates
	core::vector2d<f32> TCoords2;

	bool operator == (const S3DVertex2TCoords& other) const
	{
		return (Pos == other.Pos && Normal == other.Normal &&
			Color == other.Color && TCoords == other.TCoords &&
			TCoords2 == other.TCoords2);
	}

	bool operator != (const S3DVertex2TCoords& other) const
	{
		return (Pos != other.Pos || Normal != other.Normal ||
			Color != other.Color || TCoords != other.TCoords ||
			TCoords2 != other.TCoords2);
	}

};


//! Vertex with a tangent and binormal vector.
/*  Usually used for tangent space normal mapping.
*/
struct S3DVertexTangents
{
	//! default constructor
	S3DVertexTangents() { };

	//! constructor
	S3DVertexTangents(f32 x, f32 y, f32 z)
	: Pos(x,y,z) { }

	//! constructor
	S3DVertexTangents(const core::vector3df& pos,
		const core::vector2df& tcoords,	SColor c)
		: Pos(pos), Color(c), TCoords(tcoords) { }

	//! Position
	core::vector3df Pos;

	//! Normal vector
	core::vector3df Normal;

	//! Color
	SColor Color;

	//! Texture coordinates
	core::vector2d<f32> TCoords;

	//! Tangent vector along the x-axis of the texture
	core::vector3df Tangent;

	//! Binormal vector (tangent x normal)
	core::vector3df Binormal;

	bool operator == (const S3DVertexTangents& other) const
	{
		return (Pos == other.Pos && Normal == other.Normal &&
			Color == other.Color && TCoords == other.TCoords &&
			Tangent == other.Tangent && Binormal == other.Binormal);
	}

	bool operator != (const S3DVertexTangents& other) const
	{
		return (Pos != other.Pos || Normal != other.Normal ||
			Color != other.Color || TCoords != other.TCoords ||
			Tangent != other.Tangent || Binormal != other.Binormal);
	}
};



} // end namespace video
} // end namespace irr

#endif


namespace irr
{
namespace scene
{
//! Enumeration for all vertex types there are.
enum E_PRIMITIVE_TYPE
{
	//! All vertices are non-connected points.
	EPT_POINTS=0,

	//! All vertices form a single connected line.
	EPT_LINE_STRIP,

	//! Just as LINE_STRIP, but the last and the first vertex is also connected.
	EPT_LINE_LOOP,

	//! Every two vertices are connected creating n/2 lines.
	EPT_LINES,

	//! After the first two vertices each vertex defines a new triangle.
	//! Always the two last and the new one form a new triangle.
	EPT_TRIANGLE_STRIP,

	//! After the first two vertices each vertex defines a new triangle.
	//! All around the common first vertex.
	EPT_TRIANGLE_FAN,

	//! Explicitly set all vertices for each triangle.
	EPT_TRIANGLES,

	//! After the first two vertices each further tw vetices create a quad with the preceding two.
	EPT_QUAD_STRIP,

	//! Every four vertices create a quad.
	EPT_QUADS,

	//! Just as LINE_LOOP, but filled.
	EPT_POLYGON
};

	//! Struct for holding a mesh with a single material
	/* SMeshBuffer is a simple implementation of a MeshBuffer. */
	class IMeshBuffer : public virtual IUnknown
	{
	public:

		//! destructor
		virtual ~IMeshBuffer() {}; 

		//! returns the material of this meshbuffer
		virtual video::SMaterial& getMaterial() = 0;

		//! returns the material of this meshbuffer
		virtual const video::SMaterial& getMaterial() const = 0;

		//! returns which type of vertex data is stored.
		virtual video::E_VERTEX_TYPE getVertexType() const = 0;

		//! returns the byte size (stride, pitch) of the vertex
		virtual u32 getVertexPitch() const = 0;

		//! returns pointer to vertex data. The data is an array of vertices. Which vertex
		//! type is used can be determined with getVertexType().
		virtual const void* getVertices() const = 0; 

		//! returns pointer to vertex data. The data is an array of vertices. Which vertex
		//! type is used can be determined with getVertexType().
		virtual void* getVertices() = 0; 

		//! returns amount of vertices
		virtual u32 getVertexCount() const = 0;

		//! returns pointer to Indices
		virtual const u16* getIndices() const = 0;

		//! returns pointer to Indices
		virtual u16* getIndices() = 0;

		//! returns amount of indices
		virtual u32 getIndexCount() const = 0;

		//! returns an axis aligned bounding box
		virtual const core::aabbox3df& getBoundingBox() const = 0;

		//! set user axis aligned bounding box
		virtual void setBoundingBox( const core::aabbox3df& box) = 0;

	};

} // end namespace scene
} // end namespace irr

#endif


namespace irr
{
namespace scene
{
	//! Class for accessing a mesh with multiple mesh buffers.
	/* An IMesh is nothing more than a collection of some mesh buffers (IMeshBuffer).
	SMesh is a simple implementation of an IMesh.
	*/
	class IMesh : public virtual IUnknown
	{
	public:

		//! destructor
		virtual ~IMesh(){};

		//! Returns the amount of mesh buffers.
		/* \return Returns the amount of mesh buffers (IMeshBuffer) in this mesh. */
		virtual u32 getMeshBufferCount() const = 0;

		//! Returns pointer to a mesh buffer.
 		/* \param nr: Zero based index of the mesh buffer. The maximum value is
		getMeshBufferCount() - 1;
		\return Returns the pointer to the mesh buffer or 
		NULL if there is no such mesh buffer. */
		virtual IMeshBuffer* getMeshBuffer(u32 nr) const = 0;

		//! Returns pointer to a mesh buffer which fits a material
 		/* \param material: material to search for
		\return Returns the pointer to the mesh buffer or 
		NULL if there is no such mesh buffer. */
		virtual IMeshBuffer* getMeshBuffer( const video::SMaterial &material) const { return 0; }

		//! Returns an axis aligned bounding box of the mesh.
		/* \return A bounding box of this mesh is returned. */
		virtual const core::aabbox3d<f32>& getBoundingBox() const = 0;

		//! set user axis aligned bounding box
		virtual void setBoundingBox( const core::aabbox3df& box) = 0;

		//! Sets a flag of all contained materials to a new value.
		/* \param flag: Flag to set in all materials.
		 \param newvalue: New value to set in all materials. */
		virtual void setMaterialFlag(video::E_MATERIAL_FLAG flag, bool newvalue) = 0;

	};

} // end namespace scene
} // end namespace irr

#endif


namespace irr
{
namespace scene
{
	enum E_ANIMATED_MESH_TYPE
	{
		//! Unknown animated mesh type.
		EAMT_UNKNOWN = 0,

		//! Quake 2 MD2 model file
		EAMT_MD2, 

		//! Quake 3 MD3 model file
		EAMT_MD3, 

		//! Milkshape 3d skeletal animation file
		EAMT_MS3D,

		//! Maya .obj not animated model
		EAMT_OBJ,

		//! Quake 3 .bsp Map, not animated
		EAMT_BSP,

		//! 3D Studio .3ds file
		EAMT_3DS,

		//! Microsoft Direct3D .x-file. Can contain static and skeletal animated 
		//! skinned meshes. This is the standard and best supported 
		//! format of the Irrlicht Engine.
		EAMT_X,

		//! My3D Mesh, the file format by Zhuck Dimitry
		EAMT_MY3D,

		//! Pulsar LMTools (.lmts) file. The Irrlicht loader for this was written by
		//! Jonas Petersen
		EAMT_LMTS,

		//! Cartography Shop .csm file. The loader for this was created by Saurav Mohapatra.
		EAMT_CSM,

		//! .oct file for Paul Nette's FSRad or from Murphy McCauley's Blender .oct exporter.
		//! The oct file format contains 3D geometry and lightmaps and can 
		//! be loaded directly by Irrlicht
		EAMT_OCT,

		//! Blitz Basic .b3d file, the file format by Mark Sibly
		EAMT_B3D

	};

	//! Interface for an animated mesh.
	/* There are already simple implementations of this interface available so 
	you don't have to implement this interface on your own if you need to:
	You might want to use irr::scene::SAnimatedMesh, irr::scene::SMesh, 
	irr::scene::SMeshBuffer etc. */
	class IAnimatedMesh : public virtual IUnknown
	{
	public:

		//! destructor
		virtual ~IAnimatedMesh() {};

		//! Gets the frame count of the animated mesh.
		/* \return Returns the amount of frames. If the amount is 1, it is a
		static, non animated mesh. */
		virtual s32 getFrameCount() = 0;

		//! Returns the IMesh interface for a frame.
		/* \param frame: Frame number as zero based index. The maximum frame number is
		getFrameCount() - 1;
		\param detailLevel: Level of detail. 0 is the lowest,
		255 the highest level of detail. Most meshes will ignore the detail level.
		\param startFrameLoop: Because some animated meshes (.MD2) are blended between 2
		static frames, and maybe animated in a loop, the startFrameLoop and the endFrameLoop
		have to be defined, to prevent the animation to be blended between frames which are
		outside of this loop. 
		If startFrameLoop and endFrameLoop are both -1, they are ignored.
		\param endFrameLoop: see startFrameLoop.
		\return Returns the animated mesh based on a detail level.  */
		virtual IMesh* getMesh(s32 frame, s32 detailLevel=255, s32 startFrameLoop=-1, s32 endFrameLoop=-1) = 0;

		//! Returns an axis aligned bounding box of the mesh.
		/* \return A bounding box of this mesh is returned. */
		virtual const core::aabbox3d<f32>& getBoundingBox() const = 0;

		//! Returns the type of the animated mesh.
		/* In most cases it is not neccessary to use this method.
		This is useful for making a save downcast, for example
		if getMeshType() returns EAMT_MD2, its save to cast the
		IAnimatedMesh to IAnimatedMeshMD2.
		\returns Type of the mesh. */
		virtual E_ANIMATED_MESH_TYPE getMeshType() const
		{
			return EAMT_UNKNOWN;
		}
	};

} // end namespace scene
} // end namespace irr

#endif

// Copyright (C) 2002-2007 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __I_ANIMATED_MESH_MD2_H_INCLUDED__
#define __I_ANIMATED_MESH_MD2_H_INCLUDED__


namespace irr
{
namespace scene
{

	//! Types of standard md2 animations
	enum EMD2_ANIMATION_TYPE
	{
		EMAT_STAND = 0,
		EMAT_RUN,
		EMAT_ATTACK,
		EMAT_PAIN_A,
		EMAT_PAIN_B,
		EMAT_PAIN_C,
		EMAT_JUMP,
		EMAT_FLIP,
		EMAT_SALUTE,
		EMAT_FALLBACK,
		EMAT_WAVE,
		EMAT_POINT,
		EMAT_CROUCH_STAND,
		EMAT_CROUCH_WALK,
		EMAT_CROUCH_ATTACK,
		EMAT_CROUCH_PAIN,
		EMAT_CROUCH_DEATH,
		EMAT_DEATH_FALLBACK,
		EMAT_DEATH_FALLFORWARD,
		EMAT_DEATH_FALLBACKSLOW,
		EMAT_BOOM,

		//! Not an animation, but amount of animation types.
		EMAT_COUNT
	};

	//! Interface for using some special functions of MD2 meshes
	class IAnimatedMeshMD2 : public IAnimatedMesh
	{
	public:

		//! Returns the beginframe, endframe and frames per second for a default MD2 animation type.
		//! \param l: The EMD2_ANIMATION_TYPE to get the frames for.
		//! \param outBegin: The returned beginning frame for animation type specified.
		//! \param outEnd: The returned ending frame for the animation type specified.
		//! \param outFPS: The number of frames per second, this animation should be played at.
		virtual void getFrameLoop(EMD2_ANIMATION_TYPE l, s32& outBegin,
			s32& outEnd, s32& outFPS) const = 0;

		//! Returns the beginframe, endframe and frames per second for a special MD2 animation type.
		//! \param name: Name of the animation.
		//! \param outBegin: The returned beginning frame for animation type specified.
		//! \param outEnd: The returned ending frame for the animation type specified.
		//! \param outFPS: The number of frames per second, this animation should be played at.
		virtual bool getFrameLoop(const c8* name, 
			s32& outBegin, s32& outEnd, s32& outFPS) const = 0;

		//! Returns amount of md2 animations in this file.
		virtual s32 getAnimationCount() const = 0;

		//! Returns name of md2 animation. 
		//! \param nr: Zero based index of animation. 
		virtual const c8* getAnimationName(s32 nr) const = 0;
        
	};

} // end namespace scene
} // end namespace irr

#endif

// Copyright (C) 2002-2007 Nikolaus Gebhardt / Thomas Alten
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __I_ANIMATED_MESH_MD3_H_INCLUDED__
#define __I_ANIMATED_MESH_MD3_H_INCLUDED__

// Copyright (C) 2002-2007 Nikolaus Gebhardt / Thomas Alten
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __I_Q3_LEVEL_SHADER_H_INCLUDED__
#define __I_Q3_LEVEL_SHADER_H_INCLUDED__

// Copyright (C) 2002-2007 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine" and the "irrXML" project.
// For conditions of distribution and use, see copyright notice in irrlicht.h and irrXML.h

#ifndef __FAST_A_TO_F_H_INCLUDED__
#define __FAST_A_TO_F_H_INCLUDED__

#include <stdlib.h>

namespace irr
{
namespace core
{

const float fast_atof_table[] =	{
										0.f,
										0.1f,
										0.01f,
										0.001f,
										0.0001f,
										0.00001f,
										0.000001f,
										0.0000001f,
										0.00000001f,
										0.000000001f,
										0.0000000001f,
										0.00000000001f,
										0.000000000001f,
										0.0000000000001f,
										0.00000000000001f,
										0.000000000000001f
									};

inline u32 strtol10( const char* in, const char* &out)
{
	u32 value = 0;
	c8 symbol;

	while ( 1 )
	{
		symbol = *in;
		if ( symbol < '0' || symbol > '9' )
			break;

		value = ( value * 10 ) + ( symbol - '0' );
		in += 1;
	}
	out = in;
	return value;
}

//! Provides a fast function for converting a string into a float,
//! about 6 times faster than atof in win32.
// If you find any bugs, please send them to me, niko (at) irrlicht3d.org.
inline const char* fast_atof_move( const char* c, float& out)
{
	bool inv = false;
	const char *t;
	float f;

	if (*c=='-')
	{
		c++;
		inv = true;
	}

	//f = (float)strtol(c, &t, 10);
	f = (float) strtol10 ( c, t );

	c = t;

	if (*c == '.')
	{
		c++;

		//float pl = (float)strtol(c, &t, 10);
		float pl = (float) strtol10 ( c, t );
		pl *= fast_atof_table[t-c];

		f += pl;

		c = t;

		if (*c == 'e')
		{
			++c;
			//float exp = (float)strtol(c, &t, 10);
			float exp = (float)strtol10(c, t);
			
			f *= (float)pow(10.0f, exp);
			c = t;
		}
	}

	if (inv)
		f *= -1.0f;
	
	out = f;
	return c;
}

inline float fast_atof(const char* c)
{
	float ret;
	fast_atof_move(c, ret);
	return ret;
}

} // end namespace core
} // end namespace irr

#endif

// Copyright (C) 2002-2007 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __I_FILE_SYSTEM_H_INCLUDED__
#define __I_FILE_SYSTEM_H_INCLUDED__


namespace irr
{
namespace video
{
	class IVideoDriver;
} // end namespace video
namespace io
{

class IReadFile;
class IWriteFile;
class IFileList;
class IXMLWriter;
class IAttributes;

//! The FileSystem manages files and archives and provides access to them.
/**
	It manages where files are, so that modules which
	use the the IO do not need to know where every file is located. A file
	could be in a .zip-Archive or as file on disk, using the IFileSystem
	makes no difference to this.
*/
class IFileSystem : public virtual IUnknown
{
public:

	//! destructor
	virtual ~IFileSystem() {};

	//! Opens a file for read access.
	/* \param filename: Name of file to open.
	\return Returns a pointer to the created file interface.
	The returned pointer should be dropped when no longer needed.
	See IUnknown::drop() for more information. */
	virtual IReadFile* createAndOpenFile(const c8* filename) = 0;

	//! Creates an IReadFile interface for accessing memory like a file.
	/* This allows you to use a pointer to memory where an IReadFile is requested.
	\param memory: A pointer to the start of the file in memory
	\param len: The length of the memory in bytes
	\param fileName: The name given to this file
	\param deleteMemoryWhenDropped: True if the memory should be deleted 
	along with the IReadFile when it is dropped.
	\return Returns a pointer to the created file interface.
	The returned pointer should be dropped when no longer needed.
	See IUnknown::drop() for more information. 
	*/
	virtual IReadFile* createMemoryReadFile(void* memory, s32 len, const c8* fileName, bool deleteMemoryWhenDropped=false) = 0;

	//! Opens a file for write access.
	/* \param filename: Name of file to open.
	\param append: If the file already exist, all write operations are 
	appended to the file.
	\return Returns a pointer to the created file interface. 0 is returned, if the
	file could not created or opened for writing.
	The returned pointer should be dropped when no longer needed.
	See IUnknown::drop() for more information. */
	virtual IWriteFile* createAndWriteFile(const c8* filename, bool append=false) = 0;

	//! Adds an zip archive to the file system.
	/* After calling this, the Irrlicht Engine will search and open files directly from this archive too. 
	 This is useful for hiding data from the end user, speeding up file access and making it possible to
	 access for example Quake3 .pk3 files, which are nothing different than .zip files.
	\param filename: Filename of the zip archive to add to the file system.
	\param ignoreCase: If set to true, files in the archive can be accessed without
	writing all letters in the right case.
	\param ignorePaths: If set to true, files in the added archive can be accessed
	without its complete path.
	\return Returns true if the archive was added successful, false if not. */
	virtual bool addZipFileArchive(const c8* filename, bool ignoreCase = true, bool ignorePaths = true) = 0;

	//! Adds an unzipped archive ( or basedirectory with subdirectories..) to the file system.
	/* Useful for handling data which will be in a zip file
	\param filename: Filename of the unzipped zip archive base directory to add to the file system.
	\param ignoreCase: If set to true, files in the archive can be accessed without
	writing all letters in the right case.
	\param ignorePaths: If set to true, files in the added archive can be accessed
	without its complete path.
	\return Returns true if the archive was added successful, false if not. */
	virtual bool addFolderFileArchive(const c8* filename, bool ignoreCase = true, bool ignorePaths = true) = 0;
	
	//! Adds an pak archive to the file system.
	/* After calling this, the Irrlicht Engine will search and open files directly from this archive too. 
	 This is useful for hiding data from the end user, speeding up file access and making it possible to
	 access for example Quake2/KingPin/Hexen2 .pak files
	\param filename: Filename of the pak archive to add to the file system.
	\param ignoreCase: If set to true, files in the archive can be accessed without
	writing all letters in the right case.
	\param ignorePaths: If set to true, files in the added archive can be accessed
	without its complete path.(should not use with Quake2 paks
	\return Returns true if the archive was added successful, false if not. */
	virtual bool addPakFileArchive(const c8* filename, bool ignoreCase = true, bool ignorePaths = true) = 0;

	//! Returns the string of the current working directory.
	virtual const c8* getWorkingDirectory() = 0;

	//! Changes the current Working Directory to the overgiven string.
	/* \param ewDirectory is a string specifiing the new working directory.
	The string is operating system dependent. Under Windows it has
	the form "<drive>:\<directory>\<sudirectory>\<..>". An example would be: "C:\Windows\"
	\return Returns true if successful, otherwise false. */
	virtual bool changeWorkingDirectoryTo(const c8* newDirectory) = 0;

	//! Converts a relative path to an absolute (unique) path, resolving symbolic links if required
	virtual irr::core::stringc getAbsolutePath(irr::core::stringc &filename) = 0;

	//! Creates a list of files and directories in the current working directory and returns it.
	/* \return a Pointer to the created IFileList is returned. After the list has been used
	it has to be deleted using its IFileList::drop() method.
	See IUnknown::drop() for more information. */
	virtual IFileList* createFileList() = 0;

	//! Determinates if a file exists and would be able to be opened.
	/* \param filename is the string identifying the file which should be tested for existance.
	\return Returns true if file exsits, and false if it does not exist or an error occured. */
	virtual bool existFile(const c8* filename) = 0;

	//! Creates a XML Reader from a file which returns all parsed strings as wide characters (wchar_t*).
	/* Use createXMLReaderUTF8() if you prefer char instead of wchar_t. See IIrrXMLReader for
	more information on how to use the parser.
	\return 0, if file could not be opened, otherwise a pointer to the created
	IXMLReader is returned. After use, the reader
	has to be deleted using its IXMLReader::drop() method.
	See IUnknown::drop() for more information. */
	virtual IXMLReader* createXMLReader(const c8* filename) = 0;

	//! Creates a XML Reader from a file which returns all parsed strings as wide characters (wchar_t*).
	/* Use createXMLReaderUTF8() if you prefer char instead of wchar_t. See IIrrXMLReader for
	more information on how to use the parser.
	\return 0, if file could not be opened, otherwise a pointer to the created
	IXMLReader is returned. After use, the reader
	has to be deleted using its IXMLReader::drop() method.
	See IUnknown::drop() for more information. */
	virtual IXMLReader* createXMLReader(IReadFile* file) = 0;

	//! Creates a XML Reader from a file which returns all parsed strings as ASCII/UTF-8 characters (char*).
	/* Use createXMLReader() if you prefer wchar_t instead of char. See IIrrXMLReader for
	more information on how to use the parser.
	\return 0, if file could not be opened, otherwise a pointer to the created
	IXMLReader is returned. After use, the reader
	has to be deleted using its IXMLReaderUTF8::drop() method.
	See IUnknown::drop() for more information. */
	virtual IXMLReaderUTF8* createXMLReaderUTF8(const c8* filename) = 0;

	//! Creates a XML Reader from a file which returns all parsed strings as ASCII/UTF-8 characters (char*).
	/* Use createXMLReader() if you prefer wchar_t instead of char. See IIrrXMLReader for
	more information on how to use the parser.
	\return 0, if file could not be opened, otherwise a pointer to the created
	IXMLReader is returned. After use, the reader
	has to be deleted using its IXMLReaderUTF8::drop() method.
	See IUnknown::drop() for more information. */
	virtual IXMLReaderUTF8* createXMLReaderUTF8(IReadFile* file) = 0;

	//! Creates a XML Writer from a file.
	/* \return 0, if file could not be opened, otherwise a pointer to the created
	IXMLWriter is returned. After use, the reader
	has to be deleted using its IXMLWriter::drop() method.
	See IUnknown::drop() for more information. */
	virtual IXMLWriter* createXMLWriter(const c8* filename) = 0;

	//! Creates a XML Writer from a file.
	/* \return 0, if file could not be opened, otherwise a pointer to the created
	IXMLWriter is returned. After use, the reader
	has to be deleted using its IXMLWriter::drop() method.
	See IUnknown::drop() for more information. */
	virtual IXMLWriter* createXMLWriter(IWriteFile* file) = 0;

	//! Creates a new empty collection of attributes, usable for serialization and more.
	/* \param: driver: Video driver to be used to load textures when specified as attribute values.
	Can be null to prevent automatic texture loading by attributes.
	\return Returns a pointer to the created object.
	If you no longer need the object, you should call IAttributes::drop().
	See IUnknown::drop() for more information. */
	virtual IAttributes* createEmptyAttributes(video::IVideoDriver* driver=0) = 0;
};

} // end namespace io
} // end namespace irr


#endif

// Copyright (C) 2002-2007 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __IRR_I_VIDEO_DRIVER_H_INCLUDED__
#define __IRR_I_VIDEO_DRIVER_H_INCLUDED__

// Copyright (C) 2002-2007 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __I_READ_FILE_H_INCLUDED__
#define __I_READ_FILE_H_INCLUDED__


namespace irr
{
namespace io
{

	//! Interface providing read acess to a file.
	class IReadFile : public virtual IUnknown
	{
	public:

		virtual ~IReadFile() {};

		//! Reads an amount of bytes from the file.
		//! \param buffer: Pointer to buffer where to read bytes will be written to.
		//! \param sizeToRead: Amount of bytes to read from the file.
		//! \return Returns how much bytes were read.
		virtual s32 read(void* buffer, u32 sizeToRead) = 0;

		//! Changes position in file, returns true if successful.
		//! \param finalPos: Destination position in the file.
		//! \param relativeMovement: If set to true, the position in the file is
		//! changed relative to current position. Otherwise the position is changed 
		//! from beginning of file.
		//! \return Returns true if successful, otherwise false.
		virtual bool seek(s32 finalPos, bool relativeMovement = false) = 0;

		//! Returns size of file.
		//! \return Returns the size of the file in bytes.
		virtual s32 getSize() = 0;

		//! Returns the current position in the file.
		//! \return Returns the current position in the file in bytes.
		virtual s32 getPos() = 0;

		//! Returns name of file.
		//! \return Returns the file name as zero terminated character string.
		virtual const c8* getFileName() = 0;
	};

	//! Internal function, please do not use.
	IReadFile* createReadFile(const c8* fileName);
	//! Internal function, please do not use.
	IReadFile* createLimitReadFile(const c8* fileName, IReadFile* alreadyOpenedFile, s32 areaSize);
	//! Internal function, please do not use.
	IReadFile* createMemoryReadFile(void* memory, s32 size, const c8* fileName, bool deleteMemoryWhenDropped);

} // end namespace io
} // end namespace irr

#endif

// Copyright (C) 2002-2007 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __I_SURFACE_LOADER_H_INCLUDED__
#define __I_SURFACE_LOADER_H_INCLUDED__


namespace irr
{
namespace video
{

//!	Class which is able to create a image from a file.
/* If you want the Irrlicht Engine be able to load textures of 
currently unsupported file formats (e.g .gif), then implement
this and add your new Surface loader with 
IVideoDriver::addExternalImageLoader() to the engine. */
class IImageLoader : public virtual IUnknown
{
public:

	//! destructor
	virtual ~IImageLoader() {};

	//! returns true if the file maybe is able to be loaded by this class
	//! based on the file extension (e.g. ".tga")
	virtual bool isALoadableFileExtension(const c8* fileName) = 0;

	//! returns true if the file maybe is able to be loaded by this class
	virtual bool isALoadableFileFormat(irr::io::IReadFile* file) = 0;

	//! creates a surface from the file
	virtual IImage* loadImage(irr::io::IReadFile* file) = 0;
};


} // end namespace video
} // end namespace irr

#endif

#ifndef _I_IMAGE_WRITER_H_INCLUDED__
#define _I_IMAGE_WRITER_H_INCLUDED__


namespace irr
{
namespace io
{
	class IWriteFile;
} // end namespace io

namespace video
{
	class IImage;


//! Interface for writing software image data.
class IImageWriter : public IUnknown
{
public:
	//! constructor
	IImageWriter()
	{
	}

	//! destructor
	virtual ~IImageWriter()
	{
	};

	//! return true if this writer can write a file with the given extension
	virtual bool isAWriteableFileExtension(const c8* fileName) = 0;

	//! write image to file
	virtual bool writeImage(io::IWriteFile *file, IImage *image, u32 param = 0) = 0;
};

} // namespace video
} // namespace irr

#endif // _I_IMAGE_WRITER_H_INCLUDED__
// Copyright (C) 2002-2007 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __S_EXPOSED_VIDEO_DATA_H_INCLUDED__
#define __S_EXPOSED_VIDEO_DATA_H_INCLUDED__

// forward declarations for internal pointers
struct IDirect3D9;
struct IDirect3DDevice9;
struct IDirect3D8;
struct IDirect3DDevice8;

namespace irr
{
namespace video
{

//! structure for holding data describing a driver and operating system specific data.
/* This data can be retrived by IVideoDriver::getExposedVideoData(). Use this with caution. 
 This only should be used to make it possible to extend the engine easily without
 modification of its source. Note that this structure does not contain any valid data, if
 you are using the software or the null device.
*/
struct SExposedVideoData
{
	union
	{
		struct
		{
			//! Pointer to the IDirect3D9 interface
			IDirect3D9* D3D9;

			//! Pointer to the IDirect3D9 interface
			IDirect3DDevice9* D3DDev9;

			//! Window handle. Get with for example 
			//! HWND h = reinterpret_cast<HWND>(exposedData.D3D9.HWnd)
			s32 HWnd;

		} D3D9;

		struct
		{
			//! Pointer to the IDirect3D8 interface
			IDirect3D8* D3D8;

			//! Pointer to the IDirect3D8 interface
			IDirect3DDevice8* D3DDev8;

			//! Window handle. Get with for example with:
			//! HWND h = reinterpret_cast<HWND>(exposedData.D3D8.HWnd)
			s32 HWnd;

		} D3D8;

		struct 
		{
			//! Private GDI Device Context. Get if for example with:
			//! HDC h = reinterpret_cast<HDC>(exposedData.OpenGLWin32.HDc)
			s32 HDc; 

			//! Permanent Rendering Context. Get if for example with:
			//! HGLRC h = reinterpret_cast<HGLRC>(exposedData.OpenGLWin32.HRc)
			s32 HRc; 

			//! Window handle. Get with for example with:
			//! HWND h = reinterpret_cast<HWND>(exposedData.OpenGLWin32.HWnd)
			s32 HWnd;
		
		} OpenGLWin32;

		struct 
		{
			// XWindow handle
			u32 Window;
		} OpenGLLinux;
	};
};

} // end namespace video
} // end namespace irr


#endif

// Copyright (C) 2002-2007 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __I_MATERIAL_RENDERER_H_INCLUDED__
#define __I_MATERIAL_RENDERER_H_INCLUDED__


namespace irr
{
namespace video  
{

class IVideoDriver;
class IMaterialRendererServices;

//!	Interface for material rendering. Can be used to extend the engine with new materials.
/* Refer to IVideoDriver::addMaterialRenderer() for more informations on how to extend the engine
 with new materials.
*/
class IMaterialRenderer : public virtual IUnknown
{
public:

	//! destructor
	virtual ~IMaterialRenderer() {};

	//! Called by the IVideoDriver implementation the let the renderer set its needed render states. 
	/* This is called during the IVideoDriver::setMaterial() call.
	When overriding this, you can set some renderstates or for example a vertex or pixel shader
	if you like.
	\param material: The new material parameters to be set. The renderer may change the material
	flags in this material. For example if this material does not accept the zbuffer = true, it
	can set it to false. This is useful, because in the next lastMaterial will be just the material
	in this call.
	\param lastMaterial: The material parameters which have been set before this material.
	\param resetAllRenderstates: True if all renderstates should really be reset. This is usually
	true if the last rendering mode was not a usual 3d rendering mode, but for example 
	a 2d rendering mode.
	You should reset really all renderstates if this is true, no matter if the lastMaterial had
	some similar settings. This is used because in most cases, some common renderstates are not
	changed if they are already there, for example bilinear filtering, wireframe, gouraudshading, 
	lighting, zbuffer, zwriteenable, backfaceculling and fogenable.
	\param services: Interface providing some methods for changing advanced, internal
	states of a IVideoDriver. */
	virtual void OnSetMaterial(SMaterial& material, const SMaterial& lastMaterial,
		bool resetAllRenderstates, IMaterialRendererServices* services) {};

	//! Called every time before a new bunch of geometry is being drawn using this material with
	//! for example drawIndexedTriangleList() call.
	/* OnSetMaterial should normally only be called if the renderer decides that the renderstates should be changed, it won't be called if for
	example two drawIndexedTriangleList() will be called with the same material set. This 
	method will be called every time. This is useful for example for materials with shaders,
	which don't only set new renderstates but also shader constants.
	\param service: Pointer to interface providing methos for setting constants and other things.
	\param vtxtype: Vertex type with which the next rendering will be done. This can be used
	by the material renderer to set some specific optimized shaders or if this is an incompatible
	vertex type for this renderer, to refuse rendering for example.
	\return Returns true if everything is ok, and false if nothing should be rendered. 
	The material renderer can choose to return false for example if he doesn't support the
	specified vertex type. This is actually done in D3D8 and D3D9 when using a 
	normal mapped material with a vertex type other than EVT_TANGENTS.  */
	virtual bool OnRender(IMaterialRendererServices* service, E_VERTEX_TYPE vtxtype) { return true; };

	//! Called by the IVideoDriver to unset this material.
	/* Called during the 
	IVideoDriver::setMaterial() call before the new material will get the OnSetMaterial()
	call. */
	virtual void OnUnsetMaterial() {};

	//! Returns if the material is transparent. 
	/* The scene managment needs to know this
	for being able to sort the materials by opaque and transparent. */
	virtual bool isTransparent() { return false; }

	//! Returns the render capability of the material. 
	/* Because some more complex materials
	are implemented in multiple ways and need special hardware capabilities, it is possible
	to query how the current material renderer is performing on the current hardware with this
	function.
	\return Returns 0 if everything is running fine. Any other value is material renderer
	specific and means for example that the renderer switched back to a fall back material because 
	it cannot use the latest shaders. More specific examples: 
	Fixed function pipeline materials should return 0 in most cases, parallax mapped
	material will only return 0 when at least pixel shader 1.4 is available on that machine. */
	virtual s32 getRenderCapability() { return 0; }
};


} // end namespace video
} // end namespace irr

#endif

// Copyright (C) 2002-2007 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __I_GPU_PROGRAMMING_SERVICES_H_INCLUDED__
#define __I_GPU_PROGRAMMING_SERVICES_H_INCLUDED__


namespace irr
{

namespace io
{
	class IReadFile;
} // end namespace io

namespace video  
{

class IVideoDriver;
class IShaderConstantSetCallBack;

//! Compile target enumeration for the addHighLevelShaderMaterial() method. 
enum E_VERTEX_SHADER_TYPE
{
	EVST_VS_1_1 = 0,
	EVST_VS_2_0,
	EVST_VS_2_a,
	EVST_VS_3_0,

	//! This is not a type, but a value indicating how much types there are.
	EVST_COUNT
};

//! Names for all vertex shader types, each entry corresponds to a E_VERTEX_SHADER_TYPE entry.
const c8* const VERTEX_SHADER_TYPE_NAMES[] = {
	"vs_1_1",
	"vs_2_0",
	"vs_2_a",
	"vs_3_0",
	0 };

//! Compile target enumeration for the addHighLevelShaderMaterial() method. 
enum E_PIXEL_SHADER_TYPE
{
	EPST_PS_1_1 = 0,
	EPST_PS_1_2,
	EPST_PS_1_3,	
	EPST_PS_1_4,
	EPST_PS_2_0,
	EPST_PS_2_a,
	EPST_PS_2_b,
	EPST_PS_3_0,

	//! This is not a type, but a value indicating how much types there are.
	EPST_COUNT
};

//! Names for all pixel shader types, each entry corresponds to a E_PIXEL_SHADER_TYPE entry.
const c8* const PIXEL_SHADER_TYPE_NAMES[] = {
	"ps_1_1", 
	"ps_1_2",
	"ps_1_3",
	"ps_1_4",
	"ps_2_0",
	"ps_2_a",
	"ps_2_b",
	"ps_3_0",
	0 };

//!	Interface making it possible to create and use programs running on the GPU.
class IGPUProgrammingServices
{
public:

	//! destructor
	virtual ~IGPUProgrammingServices() {}

	//! Adds a new material renderer to the VideoDriver, based on a high level shading 
	//! language. Currently only HLSL/D3D9 and GLSL/OpenGL is supported. 
	//! \param vertexShaderProgram: String containing the source of the vertex shader program.
	//! This can be 0 if no vertex program should be used. 
	//! \param Entry name of the function of the vertexShaderProgram
	//! \param vsCompileTarget: Vertex shader version where the high level shader should be compiled to.
	//! \param pixelShaderProgram: String containing the source of the pixel shader program.
	//! This can be 0 if no pixel shader should be used. 
	//! \param pixelShaderEntryPointName: Entry name of the function of the pixelShaderEntryPointName
	//! \param psCompileTarget: Pixel shader version where the high level shader should be compiled to.
	//! \param callback: Pointer to an implementation of IShaderConstantSetCallBack in which you 
	//! can set the needed vertex and pixel shader program constants. Set this to 0 if you don't need this.
	//! \param baseMaterial: Base material which renderstates will be used to shade the
	//! material.
	//! \param userData: a user data int. This int can be set to any value and will be set as parameter
	//! in the callback method when calling OnSetConstants(). In this way it is easily possible to 
	//! use the same callback method for multiple materials and distinguish  between them during the call.
	//! \return Returns the number of the
	//! material type which can be set in SMaterial::MaterialType to use the renderer.
	//! -1 is returned if an error occured. -1 is returned for example if a vertex or pixel shader
	//! program could not be compiled or a compile target is not reachable.
	//! The error strings are then printed out into the error log, and
	//! can be catched with a custom event receiver.
    virtual s32 addHighLevelShaderMaterial(
		const c8* vertexShaderProgram,
		const c8* vertexShaderEntryPointName = "main",
		E_VERTEX_SHADER_TYPE vsCompileTarget = EVST_VS_1_1,
		const c8* pixelShaderProgram = 0, 
		const c8* pixelShaderEntryPointName = "main",
		E_PIXEL_SHADER_TYPE psCompileTarget = EPST_PS_1_1,
		IShaderConstantSetCallBack* callback = 0,
		E_MATERIAL_TYPE baseMaterial = video::EMT_SOLID,
		s32 userData = 0 ) = 0;    

	//! Like IGPUProgrammingServices::addShaderMaterial() (look there for a detailed description),
	//! but tries to load the programs from files. 
	//! \param vertexShaderProgram: Text file containing the source of the vertex shader program.
	//! Set to null if no shader should be created.
	//! \param pixelShaderProgram: Text file containing the source of the pixel shader program. Set to 
	//! 0 if no shader should be created.
	virtual s32 addHighLevelShaderMaterialFromFiles(
		const c8* vertexShaderProgram,
		const c8* vertexShaderEntryPointName = "main",
		E_VERTEX_SHADER_TYPE vsCompileTarget = EVST_VS_1_1,
		const c8* pixelShaderProgram = 0, 
		const c8* pixelShaderEntryPointName = "main",
		E_PIXEL_SHADER_TYPE psCompileTarget = EPST_PS_1_1,
		IShaderConstantSetCallBack* callback = 0,
		E_MATERIAL_TYPE baseMaterial = video::EMT_SOLID,
		s32 userData = 0) = 0; 


	//! Like IGPUProgrammingServices::addShaderMaterial() (look there for a detailed description),
	//! but tries to load the programs from files. 
	//! \param vertexShaderProgram: Text file containing the source of the vertex shader program.
	//! Set to null if no shader should be created.
	//! \param pixelShaderProgram: Text file containing the source of the pixel shader program. Set to 
	//! 0 if no shader should be created.
	virtual s32 addHighLevelShaderMaterialFromFiles(
		io::IReadFile* vertexShaderProgram,
		const c8* vertexShaderEntryPointName = "main",
		E_VERTEX_SHADER_TYPE vsCompileTarget = EVST_VS_1_1,
		io::IReadFile* pixelShaderProgram = 0, 
		const c8* pixelShaderEntryPointName = "main",
		E_PIXEL_SHADER_TYPE psCompileTarget = EPST_PS_1_1,
		IShaderConstantSetCallBack* callback = 0,
		E_MATERIAL_TYPE baseMaterial = video::EMT_SOLID,
		s32 userData = 0) = 0; 

	//! Adds a new material renderer to the VideoDriver, using pixel and/or 
	//! vertex shaders to render geometry.
	//! Note that it is a good idea to call IVideoDriver::queryFeature() before to check 
	//! if the IVideoDriver supports the vertex and/or pixel shader version your are using.  
	//! The material is added to the VideoDriver like with IVideoDriver::addMaterialRenderer()
	//! and can be used like it had been added with that method.
	//! \param vertexShaderProgram: String containing the source of the vertex shader program. This can be
	//! 0 if no vertex program should be used. 
	//! For DX8 programs, the will always input registers look like this:
	//! v0: position, v1: normal, 
	//! v2: color, v3: texture cooridnates, v4: texture coordinates 2 if available.
	//! For DX9 programs, you can manually set the registers using the dcl_ statements.
	//! \param pixelShaderProgram: String containing the source of the pixel shader program.
	//! This can be 0 if you don't want to use a pixel shader. 
	//! \param callback: Pointer to an implementation of IShaderConstantSetCallBack in which you 
	//! can set the needed vertex and pixel shader program constants. Set this to 0 if you don't need this.
	//! \param baseMaterial: Base material which renderstates will be used to shade the
	//! material.
	//! \param userData: a user data int. This int can be set to any value and will be set as parameter
	//! in the callback method when calling OnSetConstants(). In this way it is easily possible to 
	//! use the same callback method for multiple materials and distinguish  between them during the call.
	//! \return Returns the number of the
	//! material type which can be set in SMaterial::MaterialType to use the renderer.
	//! -1 is returned if an error occured. -1 is returned for example if a vertex or pixel shader
	//! program could not be compiled, the error strings are then printed out into the error log, and
	//! can be catched with a custom event receiver.
	virtual s32 addShaderMaterial(const c8* vertexShaderProgram = 0,
		const c8* pixelShaderProgram = 0, 
		IShaderConstantSetCallBack* callback = 0,
		E_MATERIAL_TYPE baseMaterial = video::EMT_SOLID,
		s32 userData = 0) = 0;

	//! Like IGPUProgrammingServices::addShaderMaterial(), but tries to load the 
	//! programs from files.
	//! \param vertexShaderProgram: Text file containing the source of the vertex shader program.
	//! Set to null if no shader should be created.
	//! \param pixelShaderProgram: Text file containing the source of the pixel shader program. Set to 
	//! 0 if no shader should be created.
 	//! \param callback: Pointer to an IShaderConstantSetCallback object to which the
 	//! OnSetConstants function is called.
 	//! \param baseMaterial: baseMaterial
	virtual s32 addShaderMaterialFromFiles(io::IReadFile* vertexShaderProgram,
		io::IReadFile* pixelShaderProgram,
		IShaderConstantSetCallBack* callback = 0,
		E_MATERIAL_TYPE baseMaterial = video::EMT_SOLID,
		s32 userData = 0) = 0;

	//! Like IGPUProgrammingServices::addShaderMaterial(), but tries to load the 
	//! programs from files.
	//! \param vertexShaderProgramFileName: Text file name containing the source of the 
	//! vertex shader program. 
	//! Set to null if no shader should be created.
	//! \param pixelShaderProgramFileName: Text file name containing the source of the
	//! pixel shader program. Set to 0 if no shader should be created.
 	//! \param callback: Pointer to an IShaderConstantSetCallback object to which the
 	//! OnSetConstants function is called.
 	//! \param baseMaterial: baseMaterial
	virtual s32 addShaderMaterialFromFiles(const c8* vertexShaderProgramFileName,
		const c8* pixelShaderProgramFileName,
		IShaderConstantSetCallBack* callback = 0,
		E_MATERIAL_TYPE baseMaterial = video::EMT_SOLID,
		s32 userData = 0) = 0;
};


} // end namespace video
} // end namespace irr

#endif


namespace irr
{
namespace io
{
	class IAttributes;
} // end namespace io
namespace scene
{
	class IMeshBuffer;
} // end namespace scene

namespace video
{
	struct S3DVertex;
	struct S3DVertex2TCoords;
	struct S3DVertexTangents;
	struct SLight;

	//! enumeration for querying features of the video driver.
	enum E_VIDEO_DRIVER_FEATURE
	{
		//! Is driver able to render to a surface?
		EVDF_RENDER_TO_TARGET = 0,

		//! Is hardeware transform and lighting supported?
		EVDF_HARDWARE_TL,

		//! Are multiple textures per material possible?
		EVDF_MULTITEXTURE,

		//! Is driver able to render with a bilinear filter applied?
		EVDF_BILINEAR_FILTER,

		//! Can the driver handle mip maps?
		EVDF_MIP_MAP,

		//! Can the driver update mip maps automatically?
		EVDF_MIP_MAP_AUTO_UPDATE,

		//! Are stencilbuffers switched on and does the device support stencil buffers?
		EVDF_STENCIL_BUFFER,

		//! Is Vertex Shader 1.1 supported?
		EVDF_VERTEX_SHADER_1_1,

		//! Is Vertex Shader 2.0 supported?
		EVDF_VERTEX_SHADER_2_0,

		//! Is Vertex Shader 3.0 supported?
		EVDF_VERTEX_SHADER_3_0,

		//! Is Pixel Shader 1.1 supported?
		EVDF_PIXEL_SHADER_1_1,

		//! Is Pixel Shader 1.2 supported?
		EVDF_PIXEL_SHADER_1_2,

		//! Is Pixel Shader 1.3 supported?
		EVDF_PIXEL_SHADER_1_3,

		//! Is Pixel Shader 1.4 supported?
		EVDF_PIXEL_SHADER_1_4,

		//! Is Pixel Shader 2.0 supported?
		EVDF_PIXEL_SHADER_2_0,

		//! Is Pixel Shader 3.0 supported?
		EVDF_PIXEL_SHADER_3_0,

		//! Are ARB vertex programs v1.0 supported?
		EVDF_ARB_VERTEX_PROGRAM_1,

		//! Are ARB fragment programs v1.0 supported?
		EVDF_ARB_FRAGMENT_PROGRAM_1,

		//! Is GLSL supported?
		EVDF_ARB_GLSL,

		//! Is HLSL supported?
		EVDF_HLSL,

		//! Are non-power-of-two textures supported?
		EVDF_TEXTURE_NPOT,

		//! Are framebuffer objects supported?
		EVDF_FRAMEBUFFER_OBJECT
	};

	//! enumeration for geometry transformation states
	enum E_TRANSFORMATION_STATE
	{
		//! View transformation
		ETS_VIEW = 0,
		//! World transformation
		ETS_WORLD,
		//! Projection transformation
		ETS_PROJECTION,
		//! Texture transformation
		ETS_TEXTURE_0,
		//! Texture transformation
		ETS_TEXTURE_1,
		//! Texture transformation
		ETS_TEXTURE_2,
		//! Texture transformation
		ETS_TEXTURE_3,
		//! Not used
		ETS_COUNT
	};


	//! Interface to driver which is able to perform 2d and 3d gfx functions.
	/* The IVideoDriver interface is one of the most important interfaces of
	the Irrlicht Engine: All rendering and texture manipulating is done with
	this interface. You are able to use the Irrlicht Engine by only invoking methods
	of this interface if you would like to, although the irr::scene::ISceneManager interface
	provides a lot of powerful classes and methods to make the programmers life
	easier.
	*/
	class IVideoDriver : public virtual IUnknown
	{
	public:

		//! destructor
		virtual ~IVideoDriver() {}

		//! Applications must call this method before performing any rendering.
		/* \param backBuffer: Specifies if the back buffer should be cleared, which
		means that the screen is filled with a color specified with the parameter color.
		If this parameter is false, the back buffer will not be cleared and the color
		parameter is ignored.
		\param zBuffer: Specifies if the depth or z buffer should be cleared. It is
		not nesesarry to do so, if only 2d drawing is used.
		\return Returns false if failed. Begin Scene can clear the back- and the z-buffer. */
		virtual bool beginScene(bool backBuffer, bool zBuffer, SColor color) = 0;

		//! Presents the rendered image on the screen.
		/* Applications must call this method after performing any rendering.
		\param  windowId: Handle of another window, if you want the bitmap to be displayed
		on another window. If this is null, everything will be displayed in the default window.
		Note: This does not work in fullscreen mode and is not implemented for all devices (only for
		D3D8, D3D9, Software1 and Software2, and only for Windows).
		\param sourceRect: Pointer to a rectangle defining the source rectangle of the area
		to be presented. Set to null to present everything. Note: not implemented in all devices.
		\return Returns false if failed and true if succeeded. */
		virtual bool endScene( s32 windowId = 0, core::rect<s32>* sourceRect=0 ) = 0;

		//! Queries the features of the driver.
		/* Returns true if a feature is available
		\param feature: A feature to query.
		\return Returns true if the feature is available, false if not. */
		virtual bool queryFeature(E_VIDEO_DRIVER_FEATURE feature) = 0;

		//! Sets the view, world or projection transformation.
		/* \param state: Transformation type to be set. Can be view, world or projection.
		\param mat: Matrix describing the transformation. */
		virtual void setTransform(E_TRANSFORMATION_STATE state, const core::matrix4& mat) = 0;

		//! Returns the transformation set by setTransform
		virtual const core::matrix4& getTransform(E_TRANSFORMATION_STATE state) = 0;

		//! Sets a material.
		/* All 3d drawing functions draw geometry now
		using this material.
		\param material: Material to be used from now on. */
		virtual void setMaterial(const SMaterial& material) = 0;

		//! Returns a pointer to a texture.
		/* Loads the texture if it is not
		already loaded, and generates mipmap levels if wished.
		You can influence how the texture is loaded using the setTextureCreationFlag()
		method.
		The texture can be in BMP, JPG, TGA, PCX, PNG and PSD format.
		For loading BMP, TGA, PCX, and PSD files, the engine uses its own methods.
		PCX loading is based on some code by Dean P. Macri, who sent
		it in for free use by the engine, PGN loading is done using a loader
		by rt who allowed it to be used by Irrlicht.
		For loading JPG-Files the JPEG LIB 6b, written by
		The Independent JPEG Group is used by the engine. For PNG loading,
		libPNG is used. Thanx for such great libraries!
		\param filename: Filename of the texture to be loaded.
		\return Returns a pointer to the texture and NULL if the texture
		could not be loaded.
		This pointer should not be dropped. See IUnknown::drop() for more information.*/
		virtual ITexture* getTexture(const c8* filename) = 0;

		//! Returns a pointer to a texture.
		/* Loads the texture if it is not
		already loaded, and generates mipmap levels if wished.
		You can influence how the texture is loaded using the setTextureCreationFlag()
		method.
		The texture can be in BMP, JPG, TGA, PCX, PNG and PSD format.
		For loading BMP, TGA, PCX, and PSD files, the engine uses its own methods.
		PCX loading is based on some code by Dean P. Macri, who sent
		it in for free use by the engine, PGN loading is done using a loader
		by rt who allowed it to be used by Irrlicht.
		For loading JPG-Files the JPEG LIB 6b, written by
		The Independent JPEG Group is used by the engine. For PNG loading,
		libPNG is used. Thanx for such great libraries!
		\param file: Pointer to an already opened file.
		\return Returns a pointer to the texture and NULL if the texture
		could not be loaded.
		This pointer should not be dropped. See IUnknown::drop() for more information.*/
		virtual ITexture* getTexture(io::IReadFile* file) = 0;

		//! Returns a texture by index
		/* \param index: Index of the texture, must be smaller than getTextureCount()
		Please note that this index would change when adding or removing textures
		*/
		virtual ITexture* getTextureByIndex(u32 index) = 0;

		//! Returns amount of textures currently loaded
		virtual s32 getTextureCount() = 0;

		//! Creates an empty Texture of specified size.
		/* \param size: Size of the texture.
		\param name: A name for the texture. Later calls of getTexture() with this name
		will return this texture
		\param format: Desired color format of the texture. Please note that
		the driver may choose to create the texture in another color format.
		\return Returns a pointer to the new created Texture.
		This pointer should not be dropped. See IUnknown::drop() for more information.
		The format of the new texture will be chosen by the driver. */
		virtual ITexture* addTexture(const core::dimension2d<s32>& size,
			const c8* name, ECOLOR_FORMAT format = ECF_A8R8G8B8) = 0;

		//! Creates a texture from a loaded IImage.
		/* \param name: A name for the texture. Later calls of getTexture() with this name
		 will return this texture
		\param image: Image from which the texture is created from.
		\return Returns a pointer to the new created Texture.
		This pointer should not be dropped. See IUnknown::drop() for more information.
		The format of the new texture will be chosen by the driver. */
		virtual ITexture* addTexture(const c8* name, IImage* image) = 0;

		//! Creates a render target texture.
		/* \param size: Size of the texture, in pixels. Width and height should
		be a power of two (for example 64, 128, 256, 512, ...) and it should not
		be bigger than the backbuffer, because it shares the zbuffer with the
		screen buffer.
		\return Returns a pointer to the created texture or 0 if the texture could not
		be created. If you no longer need the image, you should call ITexture::drop().
		See IUnknown::drop() for more information. */
		virtual ITexture* createRenderTargetTexture(const core::dimension2d<s32>& size) = 0;

		//! Removes a texture from the texture cache and deletes it, freeing lot of memory.
		/* Please note that after calling this, the pointer to the ITexture
		may not be longer valid, if it was not grabbed before by other parts of
		the engine for storing it longer. So it would be a good idea to set all
		materials which are using this texture to null or another texture first.
		\param texture: Texture to delete from the engines cache. */
		virtual void removeTexture(ITexture* texture) = 0;

		//! Removes all texture from the texture cache and deletes them, freeing lot of	memory.
		/* Please note that after calling this, the pointer to all ITextures
		may not be longer valid, if they were not grabbed before by other parts of
		the engine for storing them longer. So it would be a good idea to set all
		materials which are using textures to null first. */
		virtual void removeAllTextures() = 0;

		//! Creates an 1bit alpha channel of the texture based of an color key.
		/* This makes the texture transparent at the regions where this color
		key can be found when using for example draw2DImage with useAlphachannel
		= true.
		\param texture: Texture of which its alpha channel is modified.
		\param color: Color key color. Every pixel with this color will get transparent
		like described above. Please note that the colors of a texture may get
		converted when loading it, so the color values may not be exactly the same
		in the engine and for example in picture edit programs. To avoid this
		problem, you could use the makeColorKeyTexture method, which takes the position
		of a pixel instead a color value. */
		virtual void makeColorKeyTexture(video::ITexture* texture, video::SColor color) = 0;

		//! Creates an 1bit alpha channel of the texture based of an color key position.
		/* This makes the texture transparent at the regions where this color
		key can be found when using for example draw2DImage with useAlphachannel
		= true.
		\param texture: Texture of which its alpha channel is modified.
		\param colorKeyPixelPos: Position of a pixel with the color key color.
		Every pixel with this color will get transparent
		like described above. */
		virtual void makeColorKeyTexture(video::ITexture* texture,
			core::position2d<s32> colorKeyPixelPos) = 0;

		//! Creates a normal map from a height map texture.
		/* If the target texture
		has 32 bit, the height value is stored in the alpha component of the texture as
		addition. This value will be used by the video::EMT_PARALLAX_MAP_SOLID
		material and similar  materials.
		\param texture: Texture of which its alpha channel is modified.
		\param amplitude: Constant value by which the height information is multiplied.*/
		virtual void makeNormalMapTexture(video::ITexture* texture, f32 amplitude=1.0f) = 0;

		//! Sets a new render target.
		/* This will only work if the driver
		supports the EVDF_RENDER_TO_TARGET feature, which can be
		queried with queryFeature(). Usually, rendering to textures is done in this
		way:
		\code
		// create render target
		ITexture target = driver->createRenderTargetTexture(core::dimension2d<s32>(128,128));

		// ...

		driver->setRenderTarget(target); // set render target
		// .. draw stuff here
		driver->setRenderTarget(0);     // set previous render target
		Please note that you cannot render 3D or 2D geometry with a render target as texture
		on it when you are rendering the scene into this render target at the same time. It is
		usually only possible to render into a texture between the IVideoDriver::beginScene() and endScene()
		method calls. And please also note that the scene will be rendered upside down into the texture
		in some devices (e.g. OpenGL vs. D3D). A simple workaround for this is to flip the
		texture coordinates of the geometry where the render target texture is displayed on.
		\endcode
		\param texture: New render target. Must be a texture created with
		IVideoDriver::createRenderTargetTexture(). If set to 0, it sets the previous render
		target which was set before the last setRenderTarget() call.
		\param clearBackBuffer: Clears the backbuffer of the render target with the color parameter
		\param clearZBuffer: Clears the zBuffer of the rendertarget. Note that, because the frame
		buffer shares the zbuffer with the rendertarget, its zbuffer will be partially cleared
		too with this.
		\return Returns true if sucessful and false if not. */
		virtual bool setRenderTarget(video::ITexture* texture,
			bool clearBackBuffer=true, bool clearZBuffer=true,
			SColor color=video::SColor(0,0,0,0)) = 0;

		//! Sets a new viewport.
		/* Every rendering operation is done into this	new area.
		\param Rectangle defining the new area of rendering operations. */
		virtual void setViewPort(const core::rect<s32>& area) = 0;

		//! Gets the area of the current viewport.
		/* \return Returns rectangle of the current vieport. */
		virtual const core::rect<s32>& getViewPort() const = 0;

		//! draws a vertex primitive list
		/* Note that there may be at maximum 65536 vertices, because the
		index list is an array of 16 bit values each with a maximum value
		of 65536. If there are more than 65536 vertices in the list,
		results of this operation are not defined.
		\param vertices: Pointer to array of vertices.
		\param vertexCount: Amount of vertices in the array.
		\param indexList: Pointer to array of indizes.
		\param triangleCount: amount of Triangles.
		\param vType: Vertex type, e.g. EVT_STANDARD for S3DVertex.
		\param pType: Primitive type, e.g. EPT_TRIANGLE_FAN for a triangle fan. */
		virtual void drawVertexPrimitiveList(const void* vertices, u32 vertexCount, const u16* indexList, u32 triangleCount, E_VERTEX_TYPE vType, scene::E_PRIMITIVE_TYPE pType) = 0;

		//! Draws an indexed triangle list.
		/* Note that there may be at maximum 65536 vertices, because the
		index list is a array of 16 bit values each with a maximum value
		of 65536. If there are more than 65536 vertices in the list,
		results of this operation are not defined.
		\param vertices: Pointer to array of vertices.
		\param vertexCount: Amount of vertices in the array.
		\param indexList: Pointer to array of indizes.
		\param triangleCount: amount of Triangles. Usually amount of indizes / 3. */
		virtual void drawIndexedTriangleList(const S3DVertex* vertices,
			u32 vertexCount, const u16* indexList, u32 triangleCount) = 0;

		//! Draws an indexed triangle list.
		/* Note that there may be at maximum 65536 vertices, because the
		index list is a array of 16 bit values each with a maximum value
		of 65536. If there are more than 65536 vertices in the list,
		results of this operation are not defined.
		\param vertices: Pointer to array of vertices.
		\param vertexCount: Amount of vertices in the array.
		\param indexList: Pointer to array of indizes.
		\param triangleCount: amount of Triangles. Usually amount of indizes / 3.*/
		virtual void drawIndexedTriangleList(const S3DVertex2TCoords* vertices,
			u32 vertexCount, const u16* indexList, u32 triangleCount) = 0;

		//! Draws an indexed triangle list.
		/* Note that there may be at maximum 65536 vertices, because the
		index list is a array of 16 bit values each with a maximum value
		of 65536. If there are more than 65536 vertices in the list,
		results of this operation are not defined.
		\param vertices: Pointer to array of vertices.
		\param vertexCount: Amount of vertices in the array.
		\param indexList: Pointer to array of indizes.
		\param triangleCount: amount of Triangles. Usually amount of indizes / 3. */
		virtual void drawIndexedTriangleList(const S3DVertexTangents* vertices,
			u32 vertexCount, const u16* indexList, u32 triangleCount) = 0;

		//! Draws an indexed triangle fan.
		/* Note that there may be at maximum 65536 vertices, because the
		index list is a array of 16 bit values each with a maximum value
		of 65536. If there are more than 65536 vertices in the list,
		results of this operation are not defined.
		Please note that some of the implementation code for this method is based on
		free code sent in by Mario Gruber, lots of thanks go to him!
		\param vertices: Pointer to array of vertices.
		\param vertexCount: Amount of vertices in the array.
		\param indexList: Pointer to array of indizes.
		\param triangleCount: amount of Triangles. Usually amount of indizes - 2. */
		virtual void drawIndexedTriangleFan(const S3DVertex* vertices,
			u32 vertexCount, const u16* indexList, u32 triangleCount) = 0;

		//! Draws an indexed triangle fan.
		/* Note that there may be at maximum 65536 vertices, because the
		index list is a array of 16 bit values each with a maximum value
		of 65536. If there are more than 65536 vertices in the list,
		results of this operation are not defined.
		Please note that some of the implementation code for this method is based on
		free code sent in by Mario Gruber, lots of thanks go to him!
		\param vertices: Pointer to array of vertices.
		\param vertexCount: Amount of vertices in the array.
		\param indexList: Pointer to array of indizes.
		\param triangleCount: amount of Triangles. Usually amount of indizes - 2. */
		virtual void drawIndexedTriangleFan(const S3DVertex2TCoords* vertices,
			u32 vertexCount, const u16* indexList, u32 triangleCount) = 0;

		//! Draws a 3d line.
		/* For some implementations, this method simply calls drawIndexedTriangles with some
		triangles. Note that the line is drawn using the current transformation
		matrix and material. So if you need to draw the 3D line independently of the
		current transformation, use
		\code
		driver->setTransform(video::ETS_WORLD, core::matrix4());
		\endcode
		before drawing the line.
		This method was created for making culling debugging easier.
		\param start: Start of the 3d line.
		\param end: End of the 3d line.
		\param color: Color of the line.  */
		virtual void draw3DLine(const core::vector3df& start,
			const core::vector3df& end, SColor color = SColor(255,255,255,255)) = 0;

		//! Draws a 3d triangle.
		/* This method usually simply calls drawIndexedTriangles with some
		triangles. Note that the line is drawn using the current transformation
		matrix and material.
		This method was created for making collision debugging easier. It works with
		all drivers because it does simply a call to drawIndexedTriangleList and
		hence is not very fast but it might be useful for further development.
		\param triangle: The triangle to draw.
		\param color: Color of the line. */
		virtual void draw3DTriangle(const core::triangle3df& triangle,
			SColor color = SColor(255,255,255,255)) = 0;

		//! Draws a 3d axis aligned box.
		/* This method usually simply calls drawIndexedTriangles with some
		triangles. Note that the line is drawn using the current transformation
		matrix and material.
		This method was created for making culling debugging easier. It works with
		all drivers because it does simply a call to drawIndexedTriangleList and
		hence is not very fast but it might be useful for further development.
		\param box: The axis aligned box to draw
		\param color: Color to use while drawing the box. */
		virtual void draw3DBox(const core::aabbox3d<f32> box,
			SColor color = SColor(255,255,255,255)) = 0;

		//! Simply draws a 2d image without any special effects
		/* \param texture: Pointer to texture to use.
		\param destPos: upper left 2d destination position where the image will be drawn. */
		virtual void draw2DImage(video::ITexture* texture,
			const core::position2d<s32>& destPos) = 0;

		//! Draws a 2d image using a color
		/* (if color is other than
		Color(255,255,255,255)) and the alpha channel of the texture if wanted.
		\param texture: Texture to be drawn.
		\param destPos: Upper left 2d destination position where the image will be drawn.
		\param sourceRect: Source rectangle in the image.
		\param clipRect: Pointer to rectangle on the screen where the image is clipped to.
		This pointer can be NULL. Then the image is not clipped.
		\param color: Color with which the image is colored. If the color equals
		Color(255,255,255,255), the color is ignored. Note that the alpha component
		is used: If alpha is other than 255, the image will be transparent.
		\param useAlphaChannelOfTexture: If true, the alpha channel of the texture is
		used to draw the image.*/
		virtual void draw2DImage(video::ITexture* texture, const core::position2d<s32>& destPos,
			const core::rect<s32>& sourceRect, const core::rect<s32>* clipRect = 0,
			SColor color=SColor(255,255,255,255), bool useAlphaChannelOfTexture=false) = 0;

		//! draws a set of 2d images, using a color and the alpha
		/* channel of the texture if desired. The images are drawn
		beginning at pos and concatenated in one line. All drawings
		are clipped against clipRect (if != 0).
		The subtextures are defined by the array of sourceRects
		and are chosen by the indices given.
		\param texture: Texture to be drawn.
		\param pos: Upper left 2d destination position where the image will be drawn.
		\param sourceRects: Source rectangles of the image.
		\param indices: List of indices which choose the actual rectangle used each time.
		\param kerningWidth: Offset to Position on X
		\param clipRect: Pointer to rectangle on the screen where the image is clipped to.
		This pointer can be 0. Then the image is not clipped.
		\param color: Color with which the image is colored.
		Note that the alpha component is used: If alpha is other than 255, the image will be transparent.
		\param useAlphaChannelOfTexture: If true, the alpha channel of the texture is
		used to draw the image. */
		virtual void draw2DImage(video::ITexture* texture,
				const core::position2d<s32>& pos,
				const core::array<core::rect<s32> >& sourceRects,
				const core::array<s32>& indices,
				s32 kerningWidth,
				const core::rect<s32>* clipRect, SColor color,
				bool useAlphaChannelOfTexture) = 0;

		//! Draws a part of the texture into the rectangle.
		/* Suggested and first implemented by zola.
		\param texture: the texture to draw from
		\param destRect: the rectangle to draw into
		\param sourceRect: the rectangle denoting a part of the texture
		\param clipRect: clips the destination rectangle (may be 0)
		\param colors: array of 4 colors denoting the color values of the corners of the destRect
		\param useAlphaChannelOfTexture: true if alpha channel will be blended. */
		virtual void draw2DImage(video::ITexture* texture, const core::rect<s32>& destRect,
			const core::rect<s32>& sourceRect, const core::rect<s32>* clipRect = 0,
			video::SColor* colors=0, bool useAlphaChannelOfTexture=false) = 0;

		//!Draws an 2d rectangle.
		/* \param color: Color of the rectangle to draw. The alpha component will not
		be ignored and specifies how transparent the rectangle will be.
		\param pos: Position of the rectangle.
		\param clip: Pointer to rectangle against which the rectangle will be clipped.
		If the pointer is null, no clipping will be performed. */
		virtual void draw2DRectangle(SColor color, const core::rect<s32>& pos,
			const core::rect<s32>* clip = 0) = 0;

		//!Draws an 2d rectangle with a gradient.
		/* \param colorLeftUp: Color of the left upper corner to draw.
		The alpha component will not be ignored and specifies how transparent the rectangle will be.
		\param colorRightUp: Color of the right upper corner to draw.
		The alpha component will not be ignored and specifies how transparent the rectangle will be.
		\param colorLeftDown: Color of the left lower corner to draw.
		The alpha component will not be ignored and specifies how transparent the rectangle will be.
		\param colorRightDown: Color of the right lower corner to draw.
		The alpha component will not be ignored and specifies how transparent the rectangle will be.
		\param pos: Position of the rectangle.
		\param clip: Pointer to rectangle against which the rectangle will be clipped.
		If the pointer is null, no clipping will be performed. */
		virtual void draw2DRectangle(const core::rect<s32>& pos,
			SColor colorLeftUp, SColor colorRightUp, SColor colorLeftDown, SColor colorRightDown,
			const core::rect<s32>* clip = 0) = 0;

		//! Draws a 2d line.
		/* \param start: Screen coordinates of the start of the line in pixels.
		\param end: Screen coordinates of the start of the line in pixels.
		\param color: Color of the line to draw. */
		virtual void draw2DLine(const core::position2d<s32>& start,
					const core::position2d<s32>& end,
					SColor color=SColor(255,255,255,255)) = 0;

		//! Draws a non filled concyclic regular 2d polyon.
		/* This method can be used to draw
		circles, but also triangles, tetragons, pentagons, hexagons, heptagons, octagons,
		enneagons, decagons, hendecagons, dodecagon, triskaidecagons, etc. I think you'll
		got it now. And all this by simply specifying the vertex count. Welcome to the
		wonders of geometry.
		\param center: Position of center of circle (pixels).
		\param radius: Radius of circle in pixels.
		\param color: Color of the circle.
		\param vertexCount: Amount of vertices of the polygon. Specify 2 to draw a line,
		3 to draw a triangle, 4 for a tetragons and a lot (>10) for nearly a circle. */
		virtual void draw2DPolygon(core::position2d<s32> center,
			f32 radius, video::SColor color=SColor(100,255,255,255), s32 vertexCount=10) = 0;

		//! Draws a shadow volume into the stencil buffer.
		/* To draw a stencil shadow, do
		this: Frist, draw all geometry. Then use this method, to draw the shadow
		volume. Then, use IVideoDriver::drawStencilShadow() to visualize the shadow.
		Please note that the code for the opengl version of the method is based on
		free code sent in by Philipp Dortmann, lots of thanks go to him!
		\param triangles: Pointer to array of 3d vectors, specifing the shadow volume.
		\param count: Amount of triangles in the array.
		\param zfail: If set to true, zfail method is used, otherwise zpass. */
		virtual void drawStencilShadowVolume(const core::vector3df* triangles, s32 count, bool zfail=true) = 0;

		//! Fills the stencil shadow with color.
		/* After the shadow volume has been drawn
		into the stencil buffer using IVideoDriver::drawStencilShadowVolume(), use this
		to draw the color of the shadow.
		Please note that the code for the opengl version of the method is based on
		free code sent in by Philipp Dortmann, lots of thanks go to him!
		\param clearStencilBuffer: Set this to false, if you want to draw every shadow
		with the same color, and only want to call drawStencilShadow() once after all
		shadow volumes have been drawn. Set this to true, if you want to paint every
		shadow with its own color.
		\param leftUpEdge: Color of the shadow in the upper left corner of screen.
		\param rightUpEdge: Color of the shadow in the upper right corner of screen.
		\param leftDownEdge: Color of the shadow in the lower left corner of screen.
		\param rightDownEdge: Color of the shadow in the lower right corner of screen. */
		virtual void drawStencilShadow(bool clearStencilBuffer=false,
			video::SColor leftUpEdge = video::SColor(255,0,0,0),
			video::SColor rightUpEdge = video::SColor(255,0,0,0),
			video::SColor leftDownEdge = video::SColor(255,0,0,0),
			video::SColor rightDownEdge = video::SColor(255,0,0,0)) = 0;

		//! Draws a mesh buffer
		/* \param mb: Buffer to draw; */
		virtual void drawMeshBuffer( const scene::IMeshBuffer* mb) = 0;

		//! Sets the fog mode.
		/* These are global values attached to each 3d object
		rendered, which has the fog flag enabled in its material.
		\param color: Color of the fog
		\param linearFog: Set this to true for linear fog, otherwise exponential fog is applied.
		\param start: Only used in linear fog mode (linearFog=true). Specifies where fog starts.
		\param end: Only used in linear fog mode (linearFog=true). Specifies where fog ends.
		\param density: Only used in expotential fog mode (linearFog=false). Must be a value between 0 and 1.
		\param pixelFog: Set this to false for vertex fog, and true if you want pixel fog.
		\param rangeFog: Set this to true to enable range-based vertex fog. The distance
		from the viewer is used to compute the fog, not the z-coordinate. This is
		better, but slower. This is only available with D3D and vertex fog. */
		virtual void setFog(SColor color=SColor(0,255,255,255), bool linearFog=true, f32 start=50.0f, f32 end=100.0f,
			f32 density=0.01f, bool pixelFog=false, bool rangeFog=false) = 0;

		//! Returns the size of the screen or render window.
		/* \return Size of screen or render window. */
		virtual core::dimension2d<s32> getScreenSize() = 0;

		//! Returns the size of the current render target, or the screen size if the driver 
		//! doesnt support render to texture
		/* \return Size of render target or screen/window */
		virtual core::dimension2d<s32> getCurrentRenderTargetSize() = 0;


		//! Returns current frames per second value.
		/* \return Returns amount of frames per second drawn. **/
		virtual s32 getFPS() = 0;

		//! Returns amount of primitives (mostly triangles) which were drawn in the last frame.
		/* Together with getFPS() very useful method for statistics.
		\return Amount of primitives drawn in the last frame. */
		virtual u32 getPrimitiveCountDrawn( u32 param = 0 ) = 0;

		//! Deletes all dynamic lights which were previously added with addDynamicLight().
		virtual void deleteAllDynamicLights() = 0;

		//! Adds a dynamic light.
		/* \param light: Data specifing the dynamic light. */
		virtual void addDynamicLight(const SLight& light) = 0;

		//! Sets the dynamic ambient light color.
		/* The default color is
		(0,0,0,0) which means it is dark.
		\param color: New color of the ambient light. */
		virtual void setAmbientLight(const SColorf& color) = 0;

		//! Returns the maximal amount of dynamic lights the device can handle
		/* \return Maximal amount of dynamic lights. */
		virtual u32 getMaximalDynamicLightAmount() = 0;

		//! Returns current amount of dynamic lights set
		/* \return Current amount of dynamic lights set */
		virtual u32 getDynamicLightCount() = 0;

		//! Returns light data which was previously set with IVideDriver::addDynamicLight().
		/* \param idx: Zero based index of the light. Must be greater than 0 and smaller
		than IVideoDriver()::getDynamicLightCount.
		\return Light data. */
		virtual const SLight& getDynamicLight(u32 idx) = 0;

		//! Gets name of this video driver.
		/* \return Returns the name of the video driver. Example: In case of the Direct3D8
		driver, it would return "Direct3D 8.1". */
		virtual const wchar_t* getName() = 0;

		//! Adds an external image loader to the engine.
		/* This is useful if
		the Irrlicht Engine should be able to load textures of currently
		unsupported file formats (e.g .gif). The IImageLoader only needs
		to be implemented for loading this file format. A pointer to
		the implementation can be passed to the engine using this method.
		\param loader: Pointer to the external loader created. */
		virtual void addExternalImageLoader(IImageLoader* loader) = 0;

		//! Adds an external image writer to the engine.
		/* This is useful if
		the Irrlicht Engine should be able to write textures of currently
		unsupported file formats (e.g .gif). The IImageWriter only needs
		to be implemented for writing this file format. A pointer to
		the implementation can be passed to the engine using this method.
		\param writer: Pointer to the external writer created. */
		virtual void addExternalImageWriter(IImageWriter* writer) = 0;

		//! Returns the maximum amount of primitives
		/* (mostly vertices) which
		the device is able to render with one drawIndexedTriangleList
		call. */
		virtual u32 getMaximalPrimitiveCount() = 0;

		//! Enables or disables a texture creation flag.
		/* This flag defines how
		textures should be created. By changing this value, you can influence for example
		the speed of rendering a lot. But please note that the video drivers
		take this value only as recommendation. It could happen that you
		enable the ETCM_ALWAYS_16_BIT mode, but the driver creates 32 bit
		textures.
		\param flag: Texture creation flag.
		\param enbabled: Specifies if the given flag should be enabled or disabled.*/
		virtual void setTextureCreationFlag(E_TEXTURE_CREATION_FLAG flag, bool enabled) = 0;

		//! Returns if a texture creation flag is enabled or disabled.
		/* You can change this value using setTextureCreationMode().
		\param flag: Texture creation flag.
		\return Returns the current texture creation mode. */
		virtual bool getTextureCreationFlag(E_TEXTURE_CREATION_FLAG flag) = 0;

		//! Creates a software image from a file.
		/* No hardware texture will
		be created for this image. This method is useful for example if
		you want to read a heightmap for a terrain renderer.
		\param filename: Name of the file from which the image is created.
		\return Returns the created image.
		If you no longer need the image, you should call IImage::drop().
		See IUnknown::drop() for more information. */
		virtual IImage* createImageFromFile(const c8* filename) = 0;

		//! Creates a software image from a file.
		/* No hardware texture will
		be created for this image. This method is useful for example if
		you want to read a heightmap for a terrain renderer.
		\param file: File from which the image is created.
		\return Returns the created image.
		If you no longer need the image, you should call IImage::drop().
		See IUnknown::drop() for more information. */
		virtual IImage* createImageFromFile(io::IReadFile* file) = 0;

		//! Writes the provided image to disk file
		/* Requires that there is a suitable image writer
		registered for writing the image to disk
		\param image: Image to write to disk
		\param filename: name of the file to write
		\param param: control parameter for the backend ( eq. compression level )
		\return Returns true on success */
		virtual bool writeImageToFile(IImage* image, const c8* filename, u32 param = 0) = 0;

		//! Creates a software image from a byte array.
		/* No hardware texture will
		be created for this image. This method is useful for example if
		you want to read a heightmap for a terrain renderer.
		\param format: Desired color format of the texture
		\param size: Desired the size of the image
		\param data: a byte array with pixelcolor information
		\param useForeignMemory: If true, the image will use the data pointer
		directly and own it from now on, which means it will also try to delete [] the
		data when the image will be destructed.
		If false, the memory will by copied internally.
		\return Returns the created image.
		If you no longer need the image, you should call IImage::drop().
		See IUnknown::drop() for more information. */
		virtual IImage* createImageFromData(ECOLOR_FORMAT format,
			const core::dimension2d<s32>& size, void *data,
			bool ownForeignMemory=false,
			bool deleteMemory = true) = 0;

		//! Only used by the internal engine.
		/* Used to notify the driver that
		the window was resized. Usually, there is no need to call this method. */
		virtual void OnResize(const core::dimension2d<s32>& size) = 0;

		//! Adds a new material renderer to the video device.
		/* Use this method to extend the VideoDriver with new MaterialTypes. To extend the
		engine using this method do the following:
		Derive a class from IMaterialRenderer and override the methods you need. For
		setting the right renderstates, you can try to get a pointer to the real rendering device
		using IVideoDriver::getExposedVideoData(). Add your class with
		IVideoDriver::addMaterialRenderer() and if you want an object in the engine to be displayed
		with your new material, set the MaterialType member of the SMaterial struct to the
		value returned by this method.
		If you simply want to create a new material using vertex and/or pixel shaders, it would
		be easier to use the video::IGPUProgrammingServices interface which you can get using
		the getGPUProgrammingServices() method.
		\param name: name for this registered material renderer entry.
		\return Returns the number of the
		material type which can be set in SMaterial::MaterialType to use the renderer.
		-1 is returned if an error occured. (For example if you tried to add
		an material renderer to the software renderer or the null device, which do not accept
		material renderers.) */
		virtual s32 addMaterialRenderer(IMaterialRenderer* renderer, const c8* name = 0) = 0;

		//! Returns pointer to material renderer or null if not existing.
		/* \param idx: Id of the material renderer. Can be a value of the E_MATERIAL_TYPE enum or a
		value which was returned by addMaterialRenderer(). */
		virtual IMaterialRenderer* getMaterialRenderer(u32 idx) = 0;

		//! Returns amount of currently available material renderers.
		virtual u32 getMaterialRendererCount() = 0;

		//! Returns name of the material renderer
		/* This string can for example be used to test if a specific renderer already has
		been registered/created, or use this string to store data about materials: This
		returned name will be also used when serializing Materials.
		\param idx: Id of the material renderer. Can be a value of the E_MATERIAL_TYPE enum or a
		value which was returned by addMaterialRenderer(). */
		virtual const c8* getMaterialRendererName(u32 idx) = 0;

		//! Sets the name of a material renderer.
		/* Will have no effect on built-in material renderers.
		\param idx: Id of the material renderer. Can be a value of the E_MATERIAL_TYPE enum or a
		value which was returned by addMaterialRenderer(). */
		virtual void setMaterialRendererName(s32 idx, const c8* name) = 0;

		//! Creates material attributes list from a material, usable for serialization and more.
		/* Please note that the videodriver will use the material renderer names from
		getMaterialRendererName() to write out the material type name, so they should be set before. */
		virtual io::IAttributes* createAttributesFromMaterial(const video::SMaterial& material) = 0;

		//! Fills an SMaterial structure from attributes.
		/* Please note that for setting material types of the material, the video driver
		will need to query the material renderers for their names, so all non built-in materials must have been created before
		calling this method. */
		virtual void fillMaterialStructureFromAttributes(video::SMaterial& outMaterial, io::IAttributes* attributes) = 0;

		//! Returns driver and operating system specific data about the IVideoDriver.
		/* This method should only be used if the engine should be extended without having
		to modify the source of the engine. */
		virtual SExposedVideoData getExposedVideoData() = 0;

		//! Returns type of video driver
		virtual E_DRIVER_TYPE getDriverType() = 0;

		//! Returns pointer to the IGPUProgrammingServices interface.
		/* Returns 0 if the
		videodriver does not support this. (For example the Software and the NULL device
		will always return 0) */
		virtual IGPUProgrammingServices* getGPUProgrammingServices() = 0;

		//! Clears the ZBuffer.
		/* Note that you usually need not to call this method,
		This is done automaticly during IVideoDriver::beginScene() or
		IVideoDriver::setRenderTarget() if you specify zBuffer=true.
		But if you have to render some special things, you can clear the zbuffer
		during the rendering process with this method another time. */
		virtual void clearZBuffer() = 0;

		//! Returns an image created from the last rendered frame.
		virtual IImage* createScreenShot() = 0;
	};

} // end namespace video
} // end namespace irr


#endif

// Copyright (C) 2002-2007 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __IRR_CORE_UTIL_H_INCLUDED__
#define __IRR_CORE_UTIL_H_INCLUDED__


namespace irr
{
namespace core
{

/*! \file irrxml.h
    \brief File containing useful basic utility functions
*/

// ----------------------------- some basic quite often used string functions --------------------------

static const stringc irrEmtpyStringc = "";

//! cut the filename extension from a string
inline stringc& cutFilenameExtension ( stringc &dest, const stringc &source )
{
	s32 endPos = source.findLast ( '.' );
	dest = source.subString ( 0, endPos < 0 ? source.size () : endPos );
	return dest;
}

//! get the filename extension from a string
inline stringc& getFileNameExtension ( stringc &dest, const stringc &source )
{
	s32 endPos = source.findLast ( '.' );
	if ( endPos < 0 )
		dest = "";
	else
		dest = source.subString ( endPos, source.size () );
	return dest;
}

//! some standard function ( to remove dependencies )
#undef isdigit
#undef isspace
#undef isupper
inline s32 isdigit(s32 c) { return c >= '0' && c <= '9'; }
inline s32 isspace(s32 c) { return	c ==  ' ' || c == '\f' || c == '\n' || c == '\r' || c == '\t' || c == '\v';	}
inline s32 isupper(s32 c) { return c >= 'A' && c <= 'Z'; }


} // end namespace core
} // end namespace irr

#endif


namespace irr
{
namespace scene
{
namespace quake3
{

	//! Hold the different Mesh Types used for getMesh
	enum eQ3MeshIndex
	{
		E_Q3_MESH_GEOMETRY = 0,
		E_Q3_MESH_ITEMS,
		E_Q3_MESH_BILLBOARD,
		E_Q3_MESH_SIZE
	};

	// we are not using gamma, so quake3 is very dark.
	// define the standard multiplication for lightmaps and vertex colors
	const video::E_MATERIAL_TYPE defaultLightMap = video::EMT_LIGHTMAP_M2;
	const video::E_MODULATE_FUNC defaultModulate = video::EMFN_MODULATE_2X;

	// some useful typedefs
	typedef core::array< core::stringc > tStringList;
	typedef core::array< video::ITexture* > tTexArray;

	// name = "a b c .."
	struct SVariable
	{
		core::stringc name;
		core::stringc content;

		void clear ()
		{
			name = core::irrEmtpyStringc;
			content = core::irrEmtpyStringc;
		}

		s32 isValid () const
		{
			return name.size();
		}

		bool operator < ( const SVariable &other ) const
		{
			return name < other.name;
		}
	};

	// string helper.. TODO: move to generic files
	inline s32 isEqual ( const core::stringc &string, u32 &pos, const c8 *list[], u32 listSize )
	{
		const char * in = string.c_str () + pos;

		for ( u32 i = 0; i != listSize; ++i )
		{
			if (string.size() < pos)
				return -2;
			u32 len = (u32) strlen ( list[i] );
			if (string.size() < pos+len)
				continue;
			if ( in [len] != 0 && in [len] != ' ' )
				continue;
			if ( strncmp ( in, list[i], len ) )
				continue;

			pos += len + 1;
			return (s32) i;
		}
		return -2;
	}

	inline f32 getAsFloat ( const core::stringc &string, u32 &pos )
	{
		const char * in = string.c_str () + pos;

		f32 value = 0.f;
		pos += (u32) ( core::fast_atof_move ( in, value ) - in ) + 1;
		return value;
	}

	inline core::vector3df getAsVector3df ( const core::stringc &string, u32 &pos )
	{
		core::vector3df v;

		v.X = getAsFloat ( string, pos );
		v.Z = getAsFloat ( string, pos );
		v.Y = getAsFloat ( string, pos );

		return v;
	}

	/*
		extract substrings
	*/
	inline void getAsStringList ( tStringList &list, s32 max, const core::stringc &string, u32 &startPos )
	{
		list.clear ();

		s32 finish = 0;
		s32 endPos;
		do
		{
			endPos = string.findNext ( ' ', startPos );
			if ( endPos == -1 )
			{
				finish = 1;
				endPos = string.size();
			}

			list.push_back ( string.subString ( startPos, endPos - startPos ) );
			startPos = endPos + 1;

			if ( list.size() >= (u32) max )
				finish = 1;

		} while ( !finish );

	}

	struct SBlendFunc
	{
		SBlendFunc () : type ( video::EMT_SOLID ), param ( 0.f ) {}

		video::E_MATERIAL_TYPE type;
		f32 param;
	};

	// parses the content of Variable cull
	inline bool getBackfaceCulling ( const core::stringc &string )
	{
		if ( string.size() == 0 )
			return true;

		bool ret = true;
		static const c8 * funclist[] = { "none", "disable" };

		u32 pos = 0;
		switch ( isEqual ( string, pos, funclist, 2 ) )
		{
			case 0:
			case 1:
				ret = false;
				break;
		}
		return ret;
	}

	// parses the content of Variable depthfunc
	// return a z-test
	inline u32 getDepthFunction ( const core::stringc &string )
	{
		if ( string.size() == 0 )
			return 1;

		u32 ret = 1;
		static const c8 * funclist[] = { "lequal","equal"  };

		u32 pos = 0;
		switch ( isEqual ( string, pos, funclist, 2 ) )
		{
			case 0:
				ret = 1;
			case 1:
				ret = 2;
				break;
		}
		return ret;
	}



	// parses the content of Variable blendfunc,alphafunc
	inline static void getBlendFunc ( const core::stringc &string, SBlendFunc &blendfunc )
	{
		if ( string.size() == 0 )
			return;

		// maps to E_BLEND_FACTOR
		static const c8 * funclist[] =
		{
			"gl_zero",
			"gl_one",
			"gl_dst_color",
			"gl_one_minus_dst_color",
			"gl_src_color",
			"gl_one_minus_src_color",
			"gl_src_alpha",
			"gl_one_minus_src_alpha",
			"gl_dst_alpha",
			"gl_one_minus_dst_alpha",
			"gl_src_alpha_sat",

			"add",
			"filter",
			"blend",

			"ge128",
			"gt0"
		};


		u32 pos = 0;
		s32 srcFact = isEqual ( string, pos, funclist, 16 );

		if ( srcFact < 0 )
			return;

		u32 resolved = 0;
		s32 dstFact = isEqual ( string, pos, funclist, 16 );

		switch ( srcFact )
		{
			case video::EBF_ONE:
				switch ( dstFact )
				{
					// gl_one gl_zero
					case video::EBF_ZERO:
						blendfunc.type = video::EMT_SOLID;
						resolved = 1;
						break;

					// gl_one gl_one
					case video::EBF_ONE:
						blendfunc.type = video::EMT_TRANSPARENT_ADD_COLOR;
						resolved = 1;
						break;
				} break;

			case video::EBF_SRC_ALPHA:
				switch ( dstFact )
				{
					// gl_src_alpha gl_one_minus_src_alpha
					case video::EBF_ONE_MINUS_SRC_ALPHA:
						blendfunc.type = video::EMT_TRANSPARENT_ALPHA_CHANNEL;
						blendfunc.param = 1.f / 255.f;
						resolved = 1;
						break;
				} break;

			case 11:
				// add
				blendfunc.type = video::EMT_TRANSPARENT_ADD_COLOR;
				resolved = 1;
				break;
			case 12:
				// filter = gl_dst_color gl_zero
				blendfunc.type = video::EMT_ONETEXTURE_BLEND;
				blendfunc.param = video::pack_texureBlendFunc ( video::EBF_DST_COLOR, video::EBF_ZERO, defaultModulate );
				resolved = 1;
				break;
			case 13:
				// blend
				blendfunc.type = video::EMT_TRANSPARENT_ALPHA_CHANNEL;
				blendfunc.param = 1.f / 255.f;
				resolved = 1;
				break;
			case 14:
				// alphafunc ge128
				blendfunc.type = video::EMT_TRANSPARENT_ALPHA_CHANNEL_REF;
				blendfunc.param = 0.5f;
				resolved = 1;
				break;
			case 15:
				// alphafunc gt0
				blendfunc.type = video::EMT_TRANSPARENT_ALPHA_CHANNEL_REF;
				blendfunc.param = 1.f / 255.f;
				resolved = 1;
				break;
		}

		// use the generic blender
		if ( 0 == resolved )
		{
			blendfunc.type = video::EMT_ONETEXTURE_BLEND;
			blendfunc.param = video::pack_texureBlendFunc (
					(video::E_BLEND_FACTOR) srcFact,
					(video::E_BLEND_FACTOR) dstFact,
					defaultModulate);
		}
	}

	struct SModifierFunction
	{
		SModifierFunction ()
			: masterfunc0 ( 0 ), masterfunc1(0), func ( 0 ),
			tcgen( 8 ), base ( 0 ), amp ( 1 ), phase ( 0 ), freq ( 1 ), wave(1) {}

		// "tcmod","deformvertexes","rgbgen", "tcgen"
		s32 masterfunc0;
		// depends
		s32 masterfunc1;
		// depends
		s32 func;

		s32 tcgen;

		union
		{
			f32 base;
			f32 bulgewidth;
		};

		union
		{
			f32 amp;
			f32 bulgeheight;
		};

		f32 phase;

		union
		{
			f32 freq;
			f32 bulgespeed;
		};

		f32 wave;

		f32 evaluate ( f32 dt ) const
		{
			// phase in 0 and 1..
			f32 x = core::fract( (dt + phase ) * freq );
			f32 y = 0.f;

			switch ( func )
			{
				// sin
				case 0:
					y = (f32) sin ( x * core::PI64 * 2.0 );
					break;
				// cos
				case 1:
					y = (f32) cos ( x * core::PI64 * 2.0 );
					break;
				// square
				case 2:
					y = x < 0.5f ? 1.f : -1.f;
					break;
				// triangle
				case 3:
					y = x < 0.5f ? ( 2.f * x ) - 1.f : ( -2.f * x ) + 2.f;
					break;
				// sawtooth:
				case 4:
					y = x;
					break;
				// inverse sawtooth:
				case 5:
					y = 1.f - x;
					break;
			}

			return base + ( y * amp );
		}


	};

	//
	inline void getModifierFunc ( SModifierFunction& fill, const core::stringc &string, u32 &pos )
	{
		if ( string.size() == 0 )
			return;

		static const c8 * funclist[] =
		{
			"sin","cos","square", "triangle", "sawtooth","inversesawtooth"
		};

		fill.func = quake3::isEqual ( string,pos, funclist,6 );
		if ( fill.func == -2 )
			fill.func = 0;

		fill.base = quake3::getAsFloat ( string, pos );
		fill.amp = quake3::getAsFloat ( string, pos );
		fill.phase = quake3::getAsFloat ( string, pos );
		fill.freq = quake3::getAsFloat ( string, pos );
	}



	struct SVarGroup
	{
		// simple assoziative array
		s32 getIndex( const c8 * name ) const
		{
			SVariable search;
			search.name = name;

			return Variable.linear_search ( search );
		}

		// searches for Variable name and returns is content
		// if Variable is not found a reference to an Empty String is returned
		const core::stringc &get( const c8 * name ) const
		{
			s32 index = getIndex ( name );
			if ( index < 0 )
				return core::irrEmtpyStringc;

			return Variable [ index ].content;
		}

		bool isDefined ( const c8 * name, const c8 * content = 0 ) const
		{
			for ( u32 i = 0; i != Variable.size (); ++i )
			{
				if ( 0 == strcmp ( Variable[i].name.c_str(), name ) )
				{
					if ( 0 == content )
						return true;
					if ( 0 == strcmp ( Variable[i].content.c_str(), content ) )
						return true;
				}
			}
			return false;
		}

		core::array < SVariable > Variable;
	};

	struct SVarGroupList: public IUnknown
	{
		SVarGroupList () {}
		virtual ~SVarGroupList () {}

		core::array < SVarGroup > VariableGroup;
	};

	//! A Parsed Shader Holding Variables ordered in Groups
	class SShader
	{
		public:
			bool operator < (const SShader &other ) const
			{
				return	name < other.name;
			}

			const SVarGroup * getGroup ( u32 stage ) const
			{
				if ( 0 == VarGroup || stage >= VarGroup->VariableGroup.size () )
					return 0;

				return &VarGroup->VariableGroup [ stage ];
			}

			// id
			s32 id;

			// Shader: shader name ( also first variable in first Vargroup )
			// Entity: classname ( variable in Group(1) )
			core::stringc name;
			SVarGroupList *VarGroup;	// reference
	};

	typedef SShader SEntity;

	typedef core::array < SEntity > tQ3EntityList;

	/*
		dump shader like original layout, regardless of internal data holding
		no recursive folding..
	*/
	inline void dumpVarGroup ( core::stringc &dest, const SVarGroup * group, s32 stack )
	{
		core::stringc buf;
		s32 i;


		if ( stack > 0 )
		{
			buf = "";
			for ( i = 0; i < stack - 1; ++i )
				buf += '\t';

			buf += "{\n";
			dest.append ( buf );
		}

		for ( u32 g = 0; g != group->Variable.size(); ++g )
		{
			buf = "";
			for ( i = 0; i < stack; ++i )
				buf += '\t';

			buf += group->Variable[g].name;
			buf += " ";
			buf += group->Variable[g].content;
			buf += "\n";
			dest.append ( buf );
		}

		if ( stack > 1 )
		{
			buf = "";
			for ( i = 0; i < stack - 1; ++i )
				buf += '\t';

			buf += "}\n";
			dest.append ( buf );
		}

	}

	inline core::stringc & dumpShader ( core::stringc &dest, const SShader * shader )
	{
		dest = "";
		if ( 0 == shader )
			return dest;

		const SVarGroup * group;

		const u32 size = shader->VarGroup->VariableGroup.size ();

		for ( u32 i = 0; i != size; ++i )
		{
			group = &shader->VarGroup->VariableGroup[ i ];
			dumpVarGroup ( dest, group, core::clamp ( (s32) i, 0, 2 ) );
		}

		if ( size <= 1 )
		{
			dest.append ( "{\n" );
		}

		dest.append ( "}\n" );
		return dest;
	}



	/*
		quake3 doesn't care much about tga & jpg
		load one or multiple files stored in name started at startPos to the texture array textures
		if texture is not loaded 0 will be added ( to find missing textures easier)
	*/
	inline void getTextures (	tTexArray &textures ,
						const core::stringc &name, u32 &startPos,
						io::IFileSystem *fileSystem,
						video::IVideoDriver* driver
					)
	{
		static const char * extension[2] = 
		{
			".jpg",
			".tga"
		};

		tStringList stringList;
		getAsStringList ( stringList, -1, name, startPos );

		textures.clear();

		core::stringc loadFile;
		for ( u32 i = 0; i!= stringList.size (); ++i )
		{
			video::ITexture* texture = 0;
			for ( u32 g = 0; g != 2 ; ++g )
			{
				irr::core::cutFilenameExtension ( loadFile, stringList[i] ).append ( extension[g] );

				if ( fileSystem->existFile ( loadFile.c_str() ) )
				{
					texture = driver->getTexture( loadFile.c_str () );
					if ( texture )
					{
						break;
					}
				}
			}
			// take 0 Texture
			textures.push_back(texture);
		}
	}


	/*!
		Manages various Quake3 Shader Styles
	*/
	class IShaderManager : public irr::IUnknown
	{
	};

} // end namespace quake3
} // end namespace scene
} // end namespace irr

#endif


namespace irr
{
namespace scene
{

	enum eMD3Models
	{
		EMD3_HEAD = 0,
		EMD3_UPPER,
		EMD3_LOWER,
		EMD3_WEAPON,
		EMD3_NUMMODELS
	};


	// Animation list
	enum EMD3_ANIMATION_TYPE
	{
		// Animations for both lower and upper parts of the player
		EMD3_BOTH_DEATH_1 = 0,
		EMD3_BOTH_DEAD_1,
		EMD3_BOTH_DEATH_2,
		EMD3_BOTH_DEAD_2,
		EMD3_BOTH_DEATH_3,
		EMD3_BOTH_DEAD_3,

		// Animations for the upper part
		EMD3_TORSO_GESTURE,
		EMD3_TORSO_ATTACK_1,
		EMD3_TORSO_ATTACK_2,
		EMD3_TORSO_DROP,
		EMD3_TORSO_RAISE,
		EMD3_TORSO_STAND_1,
		EMD3_TORSO_STAND_2,

		// Animations for the lower part
		EMD3_LEGS_WALK_CROUCH,
		EMD3_LEGS_WALK,
		EMD3_LEGS_RUN,
		EMD3_LEGS_BACK,
		EMD3_LEGS_SWIM,
		EMD3_LEGS_JUMP_1,
		EMD3_LEGS_LAND_1,
		EMD3_LEGS_JUMP_2,
		EMD3_LEGS_LAND_2,
		EMD3_LEGS_IDLE,
		EMD3_LEGS_IDLE_CROUCH,
		EMD3_LEGS_TURN,

		//! Not an animation, but amount of animation types.
		EMD3_ANIMATION_COUNT
	};

	struct SMD3AnimationInfo
	{
		s32 first;     // First frame
		s32 num;       // Last frame
		s32 looping;   // Looping frames
		s32 fps;       // Frames per second
	};


// byte-align structures
#ifdef _MSC_VER
#pragma pack( push, packing )
#pragma pack( 1 )
#define PACK_STRUCT
#elif defined( __GNUC__ )
#define PACK_STRUCT	__attribute__((packed))
#else
#error compiler not supported
#endif

	// this holds the header info of the MD3 file
	struct SMD3Header
	{
		c8	headerID[4];	//id of file, always "IDP3" 
		s32	Version;		//this is a version number, always 15 
		s8	fileName[68];	//sometimes left Blank... 65 chars, 32bit aligned == 68 chars 
		s32	numFrames;		//number of KeyFrames
		s32	numTags;		//number of 'tags' per frame
		s32	numMeshes;		//number of meshes/skins 
		s32	numMaxSkins;	//maximum number of unique skins used in md3 file 
		s32	headerSize;		//always equal to the length of this header 
		s32	tagStart;		//starting position of tag-structures 
		s32	tagEnd;			//ending position of tag-structures/starting position of mesh-structures 
		s32	fileSize;
	};

	struct SMD3MeshHeader
	{
		c8 meshID[4];			//id, must be IDP3 
		c8 meshName[68];		//name of mesh 65 chars, 32 bit aligned == 68 chars

		s32 numFrames;			//number of meshframes in mesh 
		s32 numShader;			//number of skins in mesh 
		s32 numVertices;		//number of vertices 
		s32 numTriangles;		//number of Triangles 

		s32 offset_triangles;	//starting position of Triangle data, relative to start of Mesh_Header 
		s32 offset_shaders;		//size of header 
		s32 offset_st;			//starting position of texvector data, relative to start of Mesh_Header 
		s32 vertexStart;		//starting position of vertex data,relative to start of Mesh_Header 
		s32 offset_end;
	};


	//! Compressed Vertex Data
	struct SMD3Vertex
	{
		s16 position[3];
		u8 normal[2];
	};

	//! Texure Coordinate
	struct SMD3TexCoord
	{
		f32 u;
		f32 v;
	};

	//! Triangle Index
	struct SMD3Face
	{
		s32 Index[3];
	};


// Default alignment
#ifdef _MSC_VER
#pragma pack( pop, packing )
#endif

#undef PACK_STRUCT

	//! Holding Frame Data for a Mesh
	struct SMD3MeshBuffer : public IUnknown
	{
		virtual ~ SMD3MeshBuffer () {}

		SMD3MeshHeader MeshHeader;

		core::array < core::stringc > Shader;
		core::array < s32 > Indices;
		core::array < SMD3Vertex > Vertices;
		core::array < SMD3TexCoord > Tex;
	};

	//! hold a tag info for connecting meshes
	//! basically its an alternate way to describe a transformation
	struct SMD3QuaterionTag
	{
		SMD3QuaterionTag() {}

		SMD3QuaterionTag( const core::stringc& name )
			: Name ( name ) {}

		// construct from a matrix
		SMD3QuaterionTag ( const core::stringc& name, const core::matrix4 &m )
		{
			Name = name;
			position = m.getTranslation ();
			rotation = m;
		}

		// set to matrix
		void setto ( core::matrix4 &m )
		{
			rotation.getMatrix ( m );
			m.setTranslation ( position );
		}

		// construct from a position and euler angles in degrees
		SMD3QuaterionTag ( const core::vector3df&pos, const core::vector3df &angle )
		{
			position = pos;
			rotation.set ( angle.X * core::DEGTORAD, angle.Y * core::DEGTORAD, angle.Z * core::DEGTORAD );
		}

		virtual ~SMD3QuaterionTag() {}

		core::stringc Name;
		core::vector3df position;
		core::quaternion rotation;

		bool operator < ( const SMD3QuaterionTag &other ) const
		{
			return Name < other.Name;
		}
	};

	// holds a assoziative list of named quaternions
	struct SMD3QuaterionTagList : public virtual IUnknown
	{
		SMD3QuaterionTagList () {}
		virtual ~SMD3QuaterionTagList () {}

		SMD3QuaterionTag* get ( const core::stringc& name )
		{
			SMD3QuaterionTag search ( name );
			s32 index = Container.linear_search ( search );
			if ( index >= 0 )
				return &Container[index];
			return 0;
		}

		u32 size () const
		{
			return Container.size();
		}

		SMD3QuaterionTag& operator[] (u32 index )
		{
			return Container[index];
		}


		core::array < SMD3QuaterionTag > Container;
	};



	//! Holding Frames Buffers and Tag Infos
	struct SMD3Mesh: public IUnknown
	{
		virtual ~SMD3Mesh()
		{
			for (u32 i=0; i<Buffer.size(); ++i)
				Buffer[i]->drop();
		};

		SMD3Header MD3Header;
		core::stringc Name;
		core::array < SMD3MeshBuffer * > Buffer;
		SMD3QuaterionTagList TagList;
	};



	//! Interface for using some special functions of MD3 meshes
	class IAnimatedMeshMD3 : public IAnimatedMesh
	{
	public:

		//! tune how many frames you want to render inbetween
		virtual void setInterpolationShift ( u32 shift, u32 loopMode ) = 0;

		virtual SMD3QuaterionTagList *getTagList(s32 frame, s32 detailLevel, s32 startFrameLoop, s32 endFrameLoop) = 0;

		virtual SMD3Mesh * getOriginalMesh () = 0;

	};

} // end namespace scene
} // end namespace irr

#endif

// Copyright (C) 2002-2007 Nikolaus Gebhardt / Fabio Concas / Thomas Alten
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __I_ANIMATED_MESH_MS3D_H_INCLUDED__
#define __I_ANIMATED_MESH_MS3D_H_INCLUDED__


namespace irr
{
namespace scene
{
	//! Interface for using some special functions of MS3D meshes
	class IAnimatedMeshMS3D : public IAnimatedMesh
	{
	public:

		//! Returns a pointer to a transformation matrix of a part of the 
		//! mesh based on a frame time. This is used for being able to attach
		//! objects to parts of animated meshes. For example a weapon to an animated 
		//! hand. 
		//! \param jointNumber: Zero based index of joint. The last joint has the number
		//! IAnimatedMeshMS3D::getJointCount()-1;
		//! \param frame: Frame of the animation.
		//! \return Returns a pointer to the matrix of the mesh part or 
		//! null if an error occured.
		virtual core::matrix4* getMatrixOfJoint(s32 jointNumber, s32 frame) = 0;

		//! Gets joint count.
		//! \return Returns amount of joints in the skeletal animated mesh.
		virtual s32 getJointCount() const = 0;

		//! Gets the name of a joint.
		//! \param number: Zero based index of joint. The last joint has the number
		//! IAnimatedMeshMS3D::getJointCount()-1;
		//! \return Returns name of joint and null if an error happened.
		virtual const c8* getJointName(s32 number) const = 0;

		//! Gets a joint number from its name
		//! \param name: Name of the joint.
		//! \return Returns the number of the joint or -1 if not found.
		virtual s32 getJointNumber(const c8* name) const = 0;

	};

} // end namespace scene
} // end namespace irr

#endif

// Copyright (C) 2002-2007 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __I_Q3_LEVEL_MESH_H_INCLUDED__
#define __I_Q3_LEVEL_MESH_H_INCLUDED__


namespace irr
{
namespace scene
{
	//! Interface for a Mesh wich can be loaded directly from a Quake3 .bsp-file.
	/* The Mesh tries to load all textures of the map. There are currently 
	no additional methods in this class, but maybe there will be some in later
	releases if there are feature requests. */
	class IQ3LevelMesh : public IAnimatedMesh
	{
	public:

		//! destructor
		virtual ~IQ3LevelMesh() {};

		//! releases a Mesh from the Q3 Loader
		virtual void releaseMesh ( s32 index ) = 0;

		//! loads the shader definition
		//  either from file ( we assume /scripts on fileNameIsValid == 0 )
		virtual const quake3::SShader * getShader ( const c8 * filename, s32 fileNameIsValid ) = 0;

		//! returns a already loaded Shader
		virtual const quake3::SShader * getShader ( u32 index  ) const = 0;

		//! get's an interface to the entities
		virtual const quake3::tQ3EntityList & getEntityList () = 0;

	};

} // end namespace scene
} // end namespace irr

#endif

// Copyright (C) 2002-2007 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __I_ANIMATED_MESH_X_H_INCLUDED__
#define __I_ANIMATED_MESH_X_H_INCLUDED__


namespace irr
{
namespace scene
{
	//! Interface for using some special functions of X meshes
	class IAnimatedMeshX : public IAnimatedMesh
	{
	public:

		//! Returns a pointer to a transformation matrix of a part of the 
		//! mesh based on a frame time. This is used for being able to attach
		//! objects to parts of animated meshes. For example a weapon to an animated 
		//! hand. 
		//! \param jointNumber: Zero based index of joint. The last joint has the number
		//! IAnimatedMeshX::getJointCount()-1;
		//! \param frame: Frame of the animation.
		//! \return Returns a pointer to the matrix of the mesh part or 
		//! null if an error occured.
		virtual core::matrix4* getMatrixOfJoint(s32 jointNumber, s32 frame) = 0;

		//! Gets joint count.
		//! \return Returns amount of joints in the skeletal animated mesh.
		virtual s32 getJointCount() const = 0;

		//! Gets the name of a joint.
		//! \param number: Zero based index of joint. The last joint has the number
		//! IAnimatedMeshX::getJointCount()-1;
		//! \return Returns name of joint and null if an error happened.
		virtual const c8* getJointName(s32 number) const = 0;

		//! Gets a joint number from its name
		//! \param name: Name of the joint.
		//! \return Returns the number of the joint or -1 if not found.
		virtual s32 getJointNumber(const c8* name) const = 0;

		//! Returns a pointer to list of points containing the skeleton.
		//! Draw a line between point 1 and 2, and 3 and 4 and 5 and 6
		//! and so on to visualize this. Only for debug purposes. If you
		//! use an .x-File with the IAnimatedMeshSceneNode and turn DebugDataVisible
		//! to true, the Scene node will visualize the skeleton using this
		//! method.
		virtual const core::array<core::vector3df>* getDrawableSkeleton(s32 frame) = 0;

		//! Returns amount of animations in .X-file.
		virtual s32 getAnimationCount() const = 0;

		//! Returns the name of an animation. 
		//! \param idx: Zero based Index of the animation. Must be a value between
		//! 0 and getAnimationCount()-1;
		//! \return Returns pointer to the string of the name of the animation. 
		//! Returns 0 if an animation with this index does not exist.
		virtual const c8* getAnimationName(s32 idx) const = 0;

		//! Sets an animation as animation to play back.
		//! \param idx: Zero based Index of the animation. Must be a value between
		//! 0 and getAnimationCount()-1;
		virtual void setCurrentAnimation(s32 idx) = 0;

		//! Sets an animation as animation to play back.
		//! \param name: Name of the animtion. 
		//! \return Returns true if successful, and false if the specified animation
		//! does not exist.
		virtual bool setCurrentAnimation(const c8* name) = 0;
	};

} // end namespace scene
} // end namespace irr

#endif

// Copyright (C) 2002-2006 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __I_ANIMATED_MESH_B3D_H_INCLUDED__
#define __I_ANIMATED_MESH_B3D_H_INCLUDED__

// Copyright (C) 2002-2007 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __I_SCENE_NODE_H_INCLUDED__
#define __I_SCENE_NODE_H_INCLUDED__

// Copyright (C) 2002-2007 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __E_SCENE_NODE_TYPES_H_INCLUDED__
#define __E_SCENE_NODE_TYPES_H_INCLUDED__

namespace irr
{
namespace scene  
{
	//! An enumeration for all types of built-in scene nodes 
	enum ESCENE_NODE_TYPE
	{
		//! simple cube scene node
		ESNT_CUBE = 0,

		//! Sphere scene node
		ESNT_SPHERE,

		//! Text Scene Node
		ESNT_TEXT,

		//! Water Surface Scene Node
		ESNT_WATER_SURFACE,

		//! Terrain Scene Node
		ESNT_TERRAIN,

		//! Sky Box Scene Node
		ESNT_SKY_BOX,

		//! Shadow Volume Scene Node
		ESNT_SHADOW_VOLUME,

		//! OctTree Scene Node
		ESNT_OCT_TREE,

		//! Mesh Scene Node
		ESNT_MESH,

		//! Light Scene Node
		ESNT_LIGHT,

		//! Empty Scene Node
		ESNT_EMPTY,

		//! Dummy Transformation Scene Node
		ESNT_DUMMY_TRANSFORMATION,

		//! Camera Scene Node
		ESNT_CAMERA,

		//! Maya Camera Scene Node
		ESNT_CAMERA_MAYA,

		//! First Person Shooter style Camera
		ESNT_CAMERA_FPS,

		//! Billboard Scene Node
		ESNT_BILLBOARD,

		//! Animated Mesh Scene Node
		ESNT_ANIMATED_MESH,

		//! Particle System Scene Node
		ESNT_PARTICLE_SYSTEM,

		//! Quake3 Model Scene Node ( has tag to link to )
		ESNT_MD3_SCENE_NODE,

		//! Amount of build in Scene Nodes
		ESNT_COUNT,

		//! Unknown scene node
		ESNT_UNKNOWN,

		//! This enum is never used, it only forces the compiler to 
		//! compile these enumeration values to 32 bit.
		ESNT_FORCE_32_BIT = 0x7fffffff
	};


	//! An enumeration for all types of automatic culling for built-in scene nodes 
	enum E_CULLING_TYPE
	{
		EAC_OFF = 0,
		EAC_BOX,
		EAC_FRUSTUM_BOX,
		EAC_FRUSTUM_SPHERE
	};

	//! Names for culling type
	const c8* const AutomaticCullingNames[] =
	{
		"false",
		"box",					// camera box against node box
		"frustum_box",			// camera frustum against node box
		"frustum_sphere",		// camera frustum against node sphere
		0
	};

	//! An enumeration for all types of debug data for built-in scene nodes (flags)
	enum E_DEBUG_SCENE_TYPE 
	{
		//! No Debug Data ( Default )
		EDS_OFF			= 0,
		//! Show Bounding Boxes of SceneNode
		EDS_BBOX		= 1,
		//! Show Vertex Normals
		EDS_NORMALS		= 2,
		//! Shows Skeleton/Tags
		EDS_SKELETON	= 4,
		//! Overlays Mesh Wireframe
		EDS_MESH_WIRE_OVERLAY	= 8,
		//! Temporary use transparency Material Type 
		EDS_HALF_TRANSPARENCY	= 16,
		//! Show Bounding Boxes of all MeshBuffers
		EDS_BBOX_BUFFERS		= 32,
		EDS_FULL		= EDS_BBOX | EDS_NORMALS | EDS_SKELETON | EDS_MESH_WIRE_OVERLAY
	};



} // end namespace scene
} // end namespace irr


#endif

// Copyright (C) 2002-2007 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __I_SCENE_MANAGER_H_INCLUDED__
#define __I_SCENE_MANAGER_H_INCLUDED__

// Copyright (C) 2002-2007 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __I_EVENT_RECEIVER_H_INCLUDED__
#define __I_EVENT_RECEIVER_H_INCLUDED__

// Copyright (C) 2002-2007 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __I_LOGGER_H_INCLUDED__
#define __I_LOGGER_H_INCLUDED__


namespace irr
{

enum ELOG_LEVEL
{
	//! High log level, warnings, errors and important information
	//! texts are printed out.
	ELL_INFORMATION = 0,

	//! Default log level, warnings and errors are printed out
	ELL_WARNING,

	//! Low log level, only errors are printed into the log
	ELL_ERROR,

	//! Nothing is printed out to the log
	ELL_NONE
};


//! Interface for logging messages, warnings and errors
class ILogger : public virtual IUnknown
{
public:

	//! destructor
	virtual ~ILogger() {}

	//! Returns the current set log level.
	virtual ELOG_LEVEL getLogLevel() = 0;

	//! Sets a new log level. With this value, texts which are sent to
	//! the logger are filtered out. For example setting this value to
	//! ELL_WARNING, only warnings and
	//! errors are printed out. Setting it to ELL_INFORMATION, which is
	//! the default setting, warnings,
	//! errors and informational texts are printed out.
	//! \param ll: new log level filter value.
	virtual void setLogLevel(ELOG_LEVEL ll) = 0;

	//! Prints out a text into the log
	//! \param text: Text to print out.
	//! \param ll: Log level of the text. If the text is an error, set
	//! it to ELL_ERROR, if it is warning set it to ELL_WARNING, and if it
	//! is just an informational text, set it to ELL_INFORMATION. Texts are
	//! filtered with these levels. If you want to be a text displayed,
	//! independent on what level filter is set, use ELL_NONE.
	virtual void log(const c8* text, ELOG_LEVEL ll=ELL_INFORMATION) = 0;

	//! Prints out a text into the log
	//! \param text: Text to print out.
	//! \param hint: Additional info. This string is added after a " :" to the
	//! string.
	//! \param ll: Log level of the text. If the text is an error, set
	//! it to ELL_ERROR, if it is warning set it to ELL_WARNING, and if it
	//! is just an informational text, set it to ELL_INFORMATION. Texts are
	//! filtered with these levels. If you want to be a text displayed,
	//! independent on what level filter is set, use ELL_NONE.
	virtual void log(const c8* text, const c8* hint, ELOG_LEVEL ll=ELL_INFORMATION) = 0;

	//! Prints out a text into the log
	//! \param text: Text to print out.
	//! \param hint: Additional info. This string is added after a " :" to the
	//! string.
	//! \param ll: Log level of the text. If the text is an error, set
	//! it to ELL_ERROR, if it is warning set it to ELL_WARNING, and if it
	//! is just an informational text, set it to ELL_INFORMATION. Texts are
	//! filtered with these levels. If you want to be a text displayed,
	//! independent on what level filter is set, use ELL_NONE.
	virtual void log(const wchar_t* text, const wchar_t* hint, ELOG_LEVEL ll=ELL_INFORMATION) = 0;


	//! Prints out a text into the log
	//! \param text: Text to print out.
	//! \param ll: Log level of the text. If the text is an error, set
	//! it to ELL_ERROR, if it is warning set it to ELL_WARNING, and if it
	//! is just an informational text, set it to ELL_INFORMATION. Texts are
	//! filtered with these levels. If you want to be a text displayed,
	//! independent on what level filter is set, use ELL_NONE.
	virtual void log(const wchar_t* text, ELOG_LEVEL ll=ELL_INFORMATION) = 0;
};

} // end namespace

#endif

// Copyright (C) 2002-2007 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __IRR_KEY_CODES_H_INCLUDED__
#define __IRR_KEY_CODES_H_INCLUDED__

namespace irr
{

	enum EKEY_CODE
	{
		KEY_LBUTTON          = 0x01,  // Left mouse button  
		KEY_RBUTTON          = 0x02,  // Right mouse button  
		KEY_CANCEL           = 0x03,  // Control-break processing  
		KEY_MBUTTON          = 0x04,  // Middle mouse button (three-button mouse)  
		KEY_XBUTTON1         = 0x05,  // Windows 2000/XP: X1 mouse button 
		KEY_XBUTTON2         = 0x06,  // Windows 2000/XP: X2 mouse button 
		KEY_BACK             = 0x08,  // BACKSPACE key  
		KEY_TAB              = 0x09,  // TAB key  
		KEY_CLEAR            = 0x0C,  // CLEAR key  
		KEY_RETURN           = 0x0D,  // ENTER key  
		KEY_SHIFT            = 0x10,  // SHIFT key  
		KEY_CONTROL          = 0x11,  // CTRL key  
		KEY_MENU             = 0x12,  // ALT key  
		KEY_PAUSE            = 0x13,  // PAUSE key  
		KEY_CAPITAL          = 0x14,  // CAPS LOCK key  
		KEY_KANA             = 0x15,  // IME Kana mode 
		KEY_HANGUEL          = 0x15,  // IME Hanguel mode (maintained for compatibility use KEY_HANGUL) 
		KEY_HANGUL           = 0x15,  // IME Hangul mode 
		KEY_JUNJA            = 0x17,  // IME Junja mode 
		KEY_FINAL            = 0x18,  // IME final mode 
		KEY_HANJA            = 0x19,  // IME Hanja mode 
		KEY_KANJI            = 0x19,  // IME Kanji mode 
		KEY_ESCAPE           = 0x1B,  // ESC key  
		KEY_CONVERT          = 0x1C,  // IME convert 
		KEY_NONCONVERT       = 0x1D,  // IME nonconvert 
		KEY_ACCEPT           = 0x1E,  // IME accept 
		KEY_MODECHANGE       = 0x1F,  // IME mode change request 
		KEY_SPACE            = 0x20,  // SPACEBAR  
		KEY_PRIOR            = 0x21,  // PAGE UP key  
		KEY_NEXT             = 0x22,  // PAGE DOWN key  
		KEY_END              = 0x23,  // END key  
		KEY_HOME             = 0x24,  // HOME key  
		KEY_LEFT             = 0x25,  // LEFT ARROW key  
		KEY_UP               = 0x26,  // UP ARROW key  
		KEY_RIGHT            = 0x27,  // RIGHT ARROW key  
		KEY_DOWN             = 0x28,  // DOWN ARROW key  
		KEY_SELECT           = 0x29,  // SELECT key  
		KEY_PRINT            = 0x2A,  // PRINT key
		KEY_EXECUT           = 0x2B,  // EXECUTE key  
		KEY_SNAPSHOT         = 0x2C,  // PRINT SCREEN key  
		KEY_INSERT           = 0x2D,  // INS key  
		KEY_DELETE           = 0x2E,  // DEL key  
		KEY_HELP             = 0x2F,  // HELP key  
		KEY_KEY_0            = 0x30,  // 0 key  
		KEY_KEY_1            = 0x31,  // 1 key  
		KEY_KEY_2            = 0x32,  // 2 key  
		KEY_KEY_3            = 0x33,  // 3 key  
		KEY_KEY_4            = 0x34,  // 4 key  
		KEY_KEY_5            = 0x35,  // 5 key  
		KEY_KEY_6            = 0x36,  // 6 key  
		KEY_KEY_7            = 0x37,  // 7 key  
		KEY_KEY_8            = 0x38,  // 8 key  
		KEY_KEY_9            = 0x39,  // 9 key  
		KEY_KEY_A            = 0x41,  // A key  
		KEY_KEY_B            = 0x42,  // B key  
		KEY_KEY_C            = 0x43,  // C key  
		KEY_KEY_D            = 0x44,  // D key  
		KEY_KEY_E            = 0x45,  // E key  
		KEY_KEY_F            = 0x46,  // F key  
		KEY_KEY_G            = 0x47,  // G key  
		KEY_KEY_H            = 0x48,  // H key  
		KEY_KEY_I            = 0x49,  // I key  
		KEY_KEY_J            = 0x4A,  // J key  
		KEY_KEY_K            = 0x4B,  // K key  
		KEY_KEY_L            = 0x4C,  // L key  
		KEY_KEY_M            = 0x4D,  // M key  
		KEY_KEY_N            = 0x4E,  // N key  
		KEY_KEY_O            = 0x4F,  // O key  
		KEY_KEY_P            = 0x50,  // P key  
		KEY_KEY_Q            = 0x51,  // Q key  
		KEY_KEY_R            = 0x52,  // R key  
		KEY_KEY_S            = 0x53,  // S key  
		KEY_KEY_T            = 0x54,  // T key  
		KEY_KEY_U            = 0x55,  // U key  
		KEY_KEY_V            = 0x56,  // V key  
		KEY_KEY_W            = 0x57,  // W key  
		KEY_KEY_X            = 0x58,  // X key  
		KEY_KEY_Y            = 0x59,  // Y key  
		KEY_KEY_Z            = 0x5A,  // Z key  
		KEY_LWIN             = 0x5B,  // Left Windows key (Microsoft Natural keyboard)  
		KEY_RWIN             = 0x5C,  // Right Windows key (Natural keyboard)  
		KEY_APPS             = 0x5D,  //Applications key (Natural keyboard)  
		KEY_SLEEP            = 0x5F,  // Computer Sleep key 
		KEY_NUMPAD0          = 0x60,  // Numeric keypad 0 key  
		KEY_NUMPAD1          = 0x61,  // Numeric keypad 1 key  
		KEY_NUMPAD2          = 0x62,  // Numeric keypad 2 key  
		KEY_NUMPAD3          = 0x63,  // Numeric keypad 3 key  
		KEY_NUMPAD4          = 0x64,  // Numeric keypad 4 key  
		KEY_NUMPAD5          = 0x65,  // Numeric keypad 5 key  
		KEY_NUMPAD6          = 0x66,  // Numeric keypad 6 key  
		KEY_NUMPAD7          = 0x67,  // Numeric keypad 7 key  
		KEY_NUMPAD8          = 0x68,  // Numeric keypad 8 key  
		KEY_NUMPAD9          = 0x69,  // Numeric keypad 9 key  
		KEY_MULTIPLY         = 0x6A,  // Multiply key  
		KEY_ADD              = 0x6B,  // Add key  
		KEY_SEPARATOR        = 0x6C,  // Separator key  
		KEY_SUBTRACT         = 0x6D,  // Subtract key  
		KEY_DECIMAL          = 0x6E,  // Decimal key  
		KEY_DIVIDE           = 0x6F,  // Divide key  
		KEY_F1               = 0x70,  // F1 key  
		KEY_F2               = 0x71,  // F2 key  
		KEY_F3               = 0x72,  // F3 key  
		KEY_F4               = 0x73,  // F4 key  
		KEY_F5               = 0x74,  // F5 key  
		KEY_F6               = 0x75,  // F6 key  
		KEY_F7               = 0x76,  // F7 key  
		KEY_F8               = 0x77,  // F8 key  
		KEY_F9               = 0x78,  // F9 key  
		KEY_F10              = 0x79,  // F10 key  
		KEY_F11              = 0x7A,  // F11 key  
		KEY_F12              = 0x7B,  // F12 key  
		KEY_F13              = 0x7C,  // F13 key  
		KEY_F14              = 0x7D,  // F14 key  
		KEY_F15              = 0x7E,  // F15 key  
		KEY_F16              = 0x7F,  // F16 key  
		KEY_F17              = 0x80,  // F17 key  
		KEY_F18              = 0x81,  // F18 key  
		KEY_F19              = 0x82,  // F19 key  
		KEY_F20              = 0x83,  // F20 key  
		KEY_F21              = 0x84,  // F21 key  
		KEY_F22              = 0x85,  // F22 key  
		KEY_F23              = 0x86,  // F23 key  
		KEY_F24              = 0x87,  // F24 key  
		KEY_NUMLOCK          = 0x90,  // NUM LOCK key  
		KEY_SCROLL           = 0x91,  // SCROLL LOCK key  
		KEY_LSHIFT           = 0xA0,  // Left SHIFT key 
		KEY_RSHIFT           = 0xA1,  // Right SHIFT key 
		KEY_LCONTROL         = 0xA2,  // Left CONTROL key 
		KEY_RCONTROL         = 0xA3,  // Right CONTROL key 
		KEY_LMENU            = 0xA4,  // Left MENU key 
		KEY_RMENU            = 0xA5,  // Right MENU key 
		KEY_PLUS             = 0xBB,  // Plus Key   (+)
		KEY_COMMA            = 0xBC,  // Comma Key  (,)
		KEY_MINUS            = 0xBD,  // Minus Key  (-)
		KEY_PERIOD           = 0xBE,  // Period Key (.)
		KEY_ATTN             = 0xF6,  // Attn key 
		KEY_CRSEL            = 0xF7,  // CrSel key 
		KEY_EXSEL            = 0xF8,  // ExSel key 
		KEY_EREOF            = 0xF9,  // Erase EOF key 
		KEY_PLAY             = 0xFA,  // Play key 
		KEY_ZOOM             = 0xFB,  // Zoom key 
		KEY_PA1              = 0xFD,  // PA1 key 
		KEY_OEM_CLEAR        = 0xFE,   // Clear key 

		KEY_KEY_CODES_COUNT  = 0xFF // this is not a key, but the amount of keycodes there are.
	};

} // end namespace irr

#endif


namespace irr
{
	//! Enumeration for all event types there are.
	enum EEVENT_TYPE
	{
		//! An event of the graphical user interface.
		EET_GUI_EVENT = 0,

		//! A mouse input event.
		EET_MOUSE_INPUT_EVENT,

		//! A key input evant.
		EET_KEY_INPUT_EVENT,

		//! A log event
		EET_LOG_TEXT_EVENT,

		//! A user event with user data. This is not used by Irrlicht and can be used
		//! to send user specific data though the system.
		EET_USER_EVENT
	};

	//! Enumeration for all mouse input events
	enum EMOUSE_INPUT_EVENT
	{
		//! Left mouse button was pressed down.
		EMIE_LMOUSE_PRESSED_DOWN = 0,

		//! Right mouse button was pressed down.
		EMIE_RMOUSE_PRESSED_DOWN,

		//! Middle mouse button was pressed down.
		EMIE_MMOUSE_PRESSED_DOWN,

		//! Left mouse button was left up.
		EMIE_LMOUSE_LEFT_UP,

		//! Right mouse button was left up.
		EMIE_RMOUSE_LEFT_UP,

		//! Middle mouse button was left up.
		EMIE_MMOUSE_LEFT_UP,

		//! The mouse cursor changed its position.
		EMIE_MOUSE_MOVED,

		//! The mouse wheel was moved. Use Wheel value in event data to find out 
		//! in what direction and how fast.
		EMIE_MOUSE_WHEEL,

		//! No real event. Just for convenience to get number of events
		EMIE_COUNT
	};

	namespace gui
	{

		class IGUIElement;

		//! Enumeration for all events which are sendable by the gui system
		enum EGUI_EVENT_TYPE
		{
			//! A gui element has lost its focus.
			EGET_ELEMENT_FOCUS_LOST = 0,

			//! A gui element has got the focus.
			EGET_ELEMENT_FOCUSED,

			//! A gui element was hovered.
			EGET_ELEMENT_HOVERED,

			//! A hovered gui element was left
			EGET_ELEMENT_LEFT,

			//! A button was clicked.
			EGET_BUTTON_CLICKED,

			//! A scrollbar has changed its position.
			EGET_SCROLL_BAR_CHANGED,

			//! A checkbox has changed its check state.
			EGET_CHECKBOX_CHANGED,

			//! A new item in a listbox was seleted.
			EGET_LISTBOX_CHANGED, 

			//! An item in the listbox was selected, which was already selected.
			EGET_LISTBOX_SELECTED_AGAIN, 

			//! A file has been selected in the file dialog
			EGET_FILE_SELECTED,

			//! A file open dialog has been closed without choosing a file
			EGET_FILE_CHOOSE_DIALOG_CANCELLED,

			//! 'Yes' was clicked on a messagebox
			EGET_MESSAGEBOX_YES,

			//! 'No' was clicked on a messagebox
			EGET_MESSAGEBOX_NO,

			//! 'OK' was clicked on a messagebox
			EGET_MESSAGEBOX_OK,

			//! 'Cancel' was clicked on a messagebox
			EGET_MESSAGEBOX_CANCEL,

			//! In an editbox was pressed 'ENTER'
			EGET_EDITBOX_ENTER,

			//! The tab was changed in an tab control
			EGET_TAB_CHANGED,

			//! A menu item was selected in a (context) menu
			EGET_MENU_ITEM_SELECTED,

			//! The selection in a combo box has been changed
			EGET_COMBO_BOX_CHANGED
		};
	} // end namespace gui


//! Struct for holding event data. An event can be a gui, mouse or keyboard event.
struct SEvent
{
	EEVENT_TYPE EventType;

	union
	{
		struct 
		{
			//! IGUIElement who called the event
			gui::IGUIElement* Caller;

			//! Type of GUI Event
			gui::EGUI_EVENT_TYPE EventType;

		} GUIEvent;

		struct
		{
			//! X position of mouse cursor
			s32 X;

			//! Y position of mouse cursor
			s32 Y;

			//! mouse wheel delta, usually 1.0 or -1.0.
			/* Only valid if event was EMIE_MOUSE_WHEEL */
			f32 Wheel; 

			//! type of mouse event
			EMOUSE_INPUT_EVENT Event;
		} MouseInput;

		struct
		{
			//! Character corresponding to the key (0, if not a character)
			wchar_t Char; 

			//! Key which has been pressed or released
			EKEY_CODE Key; 

			//! if not pressed, then the key was left up
			bool PressedDown; 

			//! true if shift was also pressed
			bool Shift; 

			//! true if ctrl was also pressed
			bool Control; 
		} KeyInput;

		struct
		{
			//! pointer to text which has been logged
			const c8* Text;

			//! log level in which the text has been logged
			ELOG_LEVEL Level;
		} LogEvent;

		struct
		{
			//! Some user specified data as int
			s32 UserData1; 

			//! Another user specified data as int
			s32 UserData2; 

			//! Some user specified data as float
			f32 UserData3; 
		} UserEvent;

	};

};

//! Interface of an object wich can receive events.
class IEventReceiver
{
public:

	virtual ~IEventReceiver() {};

	//! called if an event happened. returns true if event was processed
	virtual bool OnEvent(SEvent event) = 0;
};


} // end namespace irr

#endif

// Copyright (C) 2002-2006 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __E_TERRAIN_ELEMENTS_H__
#define __E_TERRAIN_ELEMENTS_H__

namespace irr
{
namespace scene
{
	//! enumeration for patch sizes specifying the size of patches in the TerrainSceneNode
	enum E_TERRAIN_PATCH_SIZE
	{
		//! patch size of 9, at most, use 4 levels of detail with this patch size.
		ETPS_9 = 9,

		//! patch size of 17, at most, use 5 levels of detail with this patch size.
		ETPS_17 = 17,

		//! patch size of 33, at most, use 6 levels of detail with this patch size.
		ETPS_33 = 33,

		//! patch size of 65, at most, use 7 levels of detail with this patch size.
		ETPS_65 = 65,

		//! patch size of 129, at most, use 8 levels of detail with this patch size.
		ETPS_129 = 129
	};

} // end namespace scene
} // end namespace irr

#endif

// Copyright (C) 2002-2007 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __I_SCENE_PARAMETERS_H_INCLUDED__
#define __I_SCENE_PARAMETERS_H_INCLUDED__

/*! \file SceneParameters.h
    \brief Header file containing all scene parameters for modifying mesh loading etc.
    
    This file includes all parameter names which can be set using ISceneManager::getParameters()
	to modify the behaviour of plugins and mesh loaders.
*/

namespace irr
{
namespace scene
{
	//! Name of the parameter for changing the texture path of the built-in csm loader.
	/* Use it like this:
	 \code
	 SceneManager->getParameters()->setAttribute(
	    scene::CSM_TEXTURE_PATH, "path/to/your/textures");
	\endcode
	**/ 
	const c8* const CSM_TEXTURE_PATH = "CSM_TexturePath";

	//! Name of the parameter for changing the texture path of the built-in lmts loader.
	/* Use it like this:
	 \code
	 SceneManager->getParameters()->setAttribute(
	   scene::LMTS_TEXTURE_PATH, "path/to/your/textures");
	\endcode
	**/ 
	const c8* const LMTS_TEXTURE_PATH = "LMTS_TexturePath";

	//! Name of the parameter for changing the texture path of the built-in my3d loader.
	/* Use it like this:
	 \code
	 SceneManager->getParameters()->setAttribute(
	   scene::MY3D_TEXTURE_PATH, "path/to/your/textures");
	\endcode
	**/ 
	const c8* const MY3D_TEXTURE_PATH = "MY3D_TexturePath";

	//! Name of the parameter specifying the COLLADA mesh loading mode
	/**
	Specifies if the COLLADA loader should create instances of the models, lights and
	cameras when loading COLLADA meshes. By default, this is set to false. If this is
	set to true, the ISceneManager::getMesh() method will only return a pointer to a
	dummy mesh and create instances of all meshes and lights and cameras in the collada
	file by itself. Example:
	\code
	 SceneManager->getParameters()->setAttribute(
	   scene::COLLADA_CREATE_SCENE_INSTANCES, true);
	\endcode
	*/
	const c8* const COLLADA_CREATE_SCENE_INSTANCES = "COLLADA_CreateSceneInstances";

	//! Name of the parameter for changing the texture path of the built-in DMF loader.
	/* Use it like this:
	 \code
	 SceneManager->getStringParameters()->setAttribute(
	   scene::DMF_TEXTURE_PATH, "path/to/your/textures");
	\endcode
	**/ 
	const c8* const DMF_TEXTURE_PATH = "DMF_TexturePath";
	
	//! Name of the parameter for preserving DMF textures dir structure with built-in DMF loader.
	/* Use it like this:
	 \code
	 //this way you won't use this setting
	 SceneManager->getParameters()->setAttribute(
	   scene::DMF_USE_MATERIALS_DIRS, false); 
	 \endcode
	 \code
     //this way you'll use this setting
     SceneManager->getParameters()->setAttribute(
	   scene::DMF_USE_MATERIALS_DIRS, true); 
	\endcode
	**/ 
	const c8* const DMF_USE_MATERIALS_DIRS = "DMF_MaterialsDir";

	//! Name of the parameter for setting reference value of alpha in transparent materials.
	/* Use it like this:
	 \code
	 //this way you'll set alpha ref to 0.1
     SceneManager->getParameters()->setAttribute(
	   scene::DMF_ALPHA_CHANNEL_REF, 0.1); 
	\endcode
	**/ 
	const c8* const DMF_ALPHA_CHANNEL_REF = "DMF_AlphaRef";
	
	//! Name of the parameter for choose to flip or not tga files.
	/* Use it like this:
	 \code
	 //this way you'll choose to flip alpha textures
     SceneManager->()->setAttribute(
	   scene::DMF_FLIP_ALPHA_TEXTURES, true); 
	\endcode
	**/ 
	const c8* const DMF_FLIP_ALPHA_TEXTURES = "DMF_FlipAlpha";


	//! Flag set as parameter when the scene manager is used as editor
	/* In this way special animators like deletion animators can be stopped from
	deleting scene nodes for example */
	const c8* const IRR_SCENE_MANAGER_IS_EDITOR = "IRR_Editor";

} // end namespace scene
} // end namespace irr

#endif

// Copyright (C) 2002-2007 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __I_GUI_ENVIRNMENT_H_INCLUDED__
#define __I_GUI_ENVIRNMENT_H_INCLUDED__

// Copyright (C) 2002-2007 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __I_GUI_WINDOW_H_INCLUDED__
#define __I_GUI_WINDOW_H_INCLUDED__

// Copyright (C) 2002-2007 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __I_GUI_BUTTON_H_INCLUDED__
#define __I_GUI_BUTTON_H_INCLUDED__

 // Copyright (C) 2002-2007 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __I_GUI_ELEMENT_H_INCLUDED__
#define __I_GUI_ELEMENT_H_INCLUDED__

// Copyright (C) 2002-2007 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __IRR_LIST_H_INCLUDED__
#define __IRR_LIST_H_INCLUDED__


namespace irr
{
namespace core
{

//! Double linked list template.
template <class T>
class list
{
private:

	//! List element node with pointer to previous and next element in the list.
	struct SKListNode
	{
		SKListNode() : next(0), prev(0) {};

		SKListNode* next;
		SKListNode* prev;
		T element;
	};

public:

	//! List iterator.
	class Iterator
	{
	public:

		Iterator() : current(0) {};

		Iterator& operator ++() { current = current->next; return *this; };
		Iterator& operator --() { current = current->prev; return *this; };
		Iterator operator ++(s32) { Iterator tmp = *this; current = current->next; return tmp; };
		Iterator operator --(s32) { Iterator tmp = *this; current = current->prev; return tmp; };

		Iterator operator+(s32 num) const
		{
			Iterator tmp = *this;

			if (num >= 0)
				while (num-- && tmp.current != 0) ++tmp;
			else
				while (num++ && tmp.current != 0) --tmp;

			return tmp;
		}

		Iterator& operator+=(s32 num)
		{
			if (num >= 0)
				while (num-- && this->current != 0) ++(*this);
			else
				while (num++ && this->current != 0) --(*this);

			return *this;
		}

		Iterator operator-(s32 num) const  { return (*this)+(-num);          }
		Iterator operator-=(s32 num) const { (*this)+=(-num);  return *this; }

		bool operator ==(const Iterator& other) const { return current == other.current; };
		bool operator !=(const Iterator& other) const { return current != other.current; };

		T& operator *() { return current->element; };

	private:

		Iterator(SKListNode* begin) : current(begin) {};

		friend class list<T>;

		SKListNode* current;
	};


	//! constructor
	list()
		: root(0), last(0), size(0) {}


	//! copy constructor
	list(const list<T>& other) : root(0), last(0), size(0)
	{
		*this = other;
	}


	//! destructor
	~list()
	{
		clear();
	}



	//! Assignment operator 
	void operator=(const list<T>& other) 
	{ 
		clear();
 
		SKListNode* node = other.root; 
		while(node) 
		{ 
			push_back(node->element); 
			node = node->next; 
		} 
	} 



	//! Returns amount of elements in list.
	//! \return Returns amount of elements in the list.
	u32 getSize() const
	{
		return size;
	}



	//! Clears the list, deletes all elements in the list. All existing
	//! iterators of this list will be invalid.
	void clear()
	{
		SKListNode* node = root;
		while(node)
		{
			SKListNode* next = node->next;
			delete node;
			node = next;
		}

		root = 0;
		last = 0;
		size = 0;
	}



	//! Returns ture if the list is empty.
	//! \return Returns true if the list is empty and false if not.
	bool empty() const
	{
		return root == 0;
	}



	//! Adds an element at the end of the list.
	//! \param element: Element to add to the list.
	void push_back(const T& element)
	{
		SKListNode* node = new SKListNode;
		node->element = element;

		++size;

		if (root == 0)
			root = node;

		node->prev = last;

		if (last != 0)
			last->next = node;

		last = node;
	}


	//! Adds an element at the begin of the list.
	//! \param element: Element to add to the list.
	void push_front(const T& element)
	{
		SKListNode* node = new SKListNode;
		node->element = element;

		++size;

		if (root == 0)
		{
			last = node;
			root = node;
		}
		else
		{
			node->next = root;
			root->prev = node;
			root = node;
		}
	}


	//! Gets begin node.
	//! \return Returns a list iterator pointing to the begin of the list.
	Iterator begin() const
	{
		return Iterator(root);
	}


	//! Gets end node.
	//! \return Returns a list iterator pointing to null.
	Iterator end() const
	{
		return Iterator(0);
	}


	//! Gets last element.
	//! \return Returns a list iterator pointing to the end of the list.
	Iterator getLast() const
	{
		return Iterator(last);
	}


	//! Inserts an element after an element.
	//! \param it: Iterator pointing to element after which the new element
	//! should be inserted.
	//! \param element: The new element to be insterted into the list.
	void insert_after(Iterator& it, const T& element)
	{
		SKListNode* node = new SKListNode;
		node->element = element;

		node->next = it.current->next;

		if (it.current->next)
			it.current->next->prev = node;

		node->prev = it.current;
		it.current->next = node;
		++size;

		if (it.current == last)
			last = node;
	}


	//! Inserts an element before an element.
	//! \param it: Iterator pointing to element before which the new element
	//! should be inserted.
	//! \param element: The new element to be insterted into the list.
	void insert_before(Iterator& it, const T& element)
	{
		SKListNode* node = new SKListNode;
		node->element = element;

		node->prev = it.current->prev;

		if (it.current->prev)
			it.current->prev->next = node;

		node->next = it.current;
		it.current->prev = node;
		++size;

		if (it.current == root)
			root = node;
	}


	//! Erases an element
	//! \param it: Iterator pointing to the element which should be erased.
	//! \return Returns iterator pointing to next element.
	Iterator erase(Iterator& it)
	{
		Iterator returnIterator(it);
		++returnIterator;

		if (it.current == root)
			root = it.current->next;

		if (it.current == last)
			last = it.current->prev;

		if (it.current->next)
			it.current->next->prev = it.current->prev;

		if (it.current->prev)
			it.current->prev->next = it.current->next;

		delete it.current;
		it.current = 0;
		--size;

		return returnIterator;
	}

private:

	SKListNode* root;
	SKListNode* last;
	u32 size;

};


} // end namespace core
}// end namespace irr

#endif

// Copyright (C) 2002-2007 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __E_GUI_ELEMENT_TYPES_H_INCLUDED__
#define __E_GUI_ELEMENT_TYPES_H_INCLUDED__

namespace irr
{
namespace gui
{

//! List of all basic Irrlicht GUI elements. 
/* An IGUIElement returns this when calling IGUIElement::getType(); */
enum EGUI_ELEMENT_TYPE
{
	//! A button (IGUIButton)
	EGUIET_BUTTON = 0,

	//! A check box (IGUICheckBox)
	EGUIET_CHECK_BOX,

	//! A combo box (IGUIComboBox)
	EGUIET_COMBO_BOX,

	//! A context menu (IGUIContextMenu)
	EGUIET_CONTEXT_MENU,

	//! A menu (IGUIMenu)
	EGUIET_MENU,

	//! An edit box (IGUIEditBox)
	EGUIET_EDIT_BOX,

	//! A file open dialog (IGUIFileOpenDialog)
	EGUIET_FILE_OPEN_DIALOG,

	//! A color select open dialog (IGUIColorSelectDialog)
	EGUIET_COLOR_SELECT_DIALOG,

	//! A in/out fader (IGUIInOutFader)
	EGUIET_IN_OUT_FADER,

	//! An image (IGUIImage)
	EGUIET_IMAGE,

	//! A list box (IGUIListBox)
	EGUIET_LIST_BOX,

	//! A mesh viewer (IGUIMeshViewer)
	EGUIET_MESH_VIEWER,

	//! A message box (IGUIWindow)
	EGUIET_MESSAGE_BOX,

	//! A modal screen
	EGUIET_MODAL_SCREEN,

	//! A scroll bar (IGUIScrollBar)
	EGUIET_SCROLL_BAR,

	//! A static text (IGUIStaticText)
	EGUIET_STATIC_TEXT,

	//! A tab (IGUITab)
	EGUIET_TAB,

	//! A tab control
	EGUIET_TAB_CONTROL,

	//! A tool bar (IGUIToolBar)
	EGUIET_TOOL_BAR,

	//! A window
	EGUIET_WINDOW,

	//! Not an element, amount of elements in there
	EGUIET_COUNT,

	//! Unknown type.
	EGUIET_ELEMENT,

	//! This enum is never used, it only forces the compiler to 
	//! compile these enumeration values to 32 bit.
	EGUIET_FORCE_32_BIT = 0x7fffffff

};

//! Names for built-in element types
const c8* const GUIElementTypeNames[] =
{
	"button",
	"checkBox",
	"comboBox",
	"contextMenu",
	"menu",
	"editBox",
	"fileOpenDialog",
	"colorSelectDialog",
	"inOutFader",
	"image",
	"listBox",
	"meshViewer",
	"messageBox",
	"modalScreen",
	"scrollBar",
	"staticText",
	"tab",
	"tabControl",
	"toolBar",
	"window",
	0
};

} // end namespace gui
} // end namespace irr

#endif


namespace irr
{
namespace gui
{
class IGUIEnvironment;

enum EGUI_ALIGNMENT
{
	//! Aligned to parent's top or left side (default)
	EGUIA_UPPERLEFT=0,
	//! Aligned to parent's bottom or right side
	EGUIA_LOWERRIGHT,
	//! Aligned to the center of parent
	EGUIA_CENTER,
	//! Scaled within its parent
	EGUIA_SCALE
};

//! Names for alignments
const c8* const GUIAlignmentNames[] =
{
	"upperLeft",
	"lowerRight",
	"center",
	"scale",
	0
};

//! Base class of all GUI elements.
class IGUIElement : public virtual io::IAttributeExchangingObject, public IEventReceiver
{
public:

	//! Constructor
	IGUIElement(EGUI_ELEMENT_TYPE type, IGUIEnvironment* environment, IGUIElement* parent,
		s32 id, core::rect<s32> rectangle)
		: Parent(0), RelativeRect(rectangle), AbsoluteRect(rectangle),
		AbsoluteClippingRect(rectangle), DesiredRect(rectangle),
		MaxSize(0,0), MinSize(1,1), IsVisible(true), IsEnabled(true),
		IsSubElement(false), NoClip(false), ID(id), 
		AlignLeft(EGUIA_UPPERLEFT), AlignRight(EGUIA_UPPERLEFT), AlignTop(EGUIA_UPPERLEFT), AlignBottom(EGUIA_UPPERLEFT),
		Environment(environment), Type(type)
	{
		// if we were given a parent to attach to
		if (parent)
			parent->addChild(this);

		// if we succeeded in becoming a child
		if (Parent)
		{
			LastParentRect = Parent->getAbsolutePosition();
			AbsoluteRect += LastParentRect.UpperLeftCorner;
			AbsoluteClippingRect = AbsoluteRect;
			AbsoluteClippingRect.clipAgainst(Parent->AbsoluteClippingRect);
		}
	}


	//! Destructor
	virtual ~IGUIElement()
	{
		// delete all children
		core::list<IGUIElement*>::Iterator it = Children.begin();
		for (; it != Children.end(); ++it)
		{
			(*it)->Parent = 0;
			(*it)->drop();
		}
	};


	//! Returns parent of this element.
	IGUIElement* getParent() const
	{
		return Parent;
	}


	//! Returns the relative rectangle of this element.
	core::rect<s32> getRelativePosition() const
	{
		return RelativeRect;
	}


	//! Sets the relative rectangle of this element.
	void setRelativePosition(const core::rect<s32>& r)
	{
		if (Parent)
		{
			core::rect<s32> r2(Parent->getAbsolutePosition());
		
			core::dimension2df d((f32)r2.getSize().Width, (f32)r2.getSize().Height);

			if (AlignLeft   == EGUIA_SCALE)
				ScaleRect.UpperLeftCorner.X = (f32)r.UpperLeftCorner.X / d.Width;
			if (AlignRight  == EGUIA_SCALE)
				ScaleRect.LowerRightCorner.X = (f32)r.LowerRightCorner.X / d.Width;
			if (AlignTop    == EGUIA_SCALE)
				ScaleRect.UpperLeftCorner.Y = (f32)r.UpperLeftCorner.Y / d.Height;
			if (AlignBottom == EGUIA_SCALE)
				ScaleRect.LowerRightCorner.Y = (f32)r.LowerRightCorner.Y / d.Height;
		}

		DesiredRect = r;
		updateAbsolutePosition();
	}

	//! Sets the relative rectangle of this element.
	void setRelativePosition(const core::rect<f32>& r)
	{
		if (!Parent)
			return;
		
		core::rect<s32> r2(Parent->getAbsolutePosition());
		
		core::dimension2di d(r2.getSize());
		
		DesiredRect = core::rect<s32>( 
						(s32)((f32)d.Width  * r.UpperLeftCorner.X),
						(s32)((f32)d.Height * r.UpperLeftCorner.Y),
						(s32)((f32)d.Width  * r.LowerRightCorner.X),
						(s32)((f32)d.Height * r.LowerRightCorner.Y));

		ScaleRect = r;

		updateAbsolutePosition();
	}


	//! Returns the absolute rectangle of element.
	core::rect<s32> getAbsolutePosition() const
	{
		return AbsoluteRect;
	}

	//! Sets whether the element will ignore its parent's clipping rectangle
	void setNotClipped(bool noClip)
	{
		NoClip = noClip;
	}

	//! Gets whether the element will ignore its parent's clipping rectangle
	bool isNotClipped()
	{
		return NoClip;
	}

	//! Sets the maximum size allowed for this element
	/* If set to 0,0, there is no maximum size */
	void setMaxSize(core::dimension2di size)
	{
		MaxSize = size;
		updateAbsolutePosition();
	}

	//! Sets the minimum size allowed for this element
	void setMinSize(core::dimension2di size)
	{
		MinSize = size;
		if (MinSize.Width < 1)
			MinSize.Width = 1;
		if (MinSize.Height < 1)
			MinSize.Height = 1;
		updateAbsolutePosition();
	}

	void setAlignment(EGUI_ALIGNMENT left, EGUI_ALIGNMENT right, EGUI_ALIGNMENT top, EGUI_ALIGNMENT bottom)
	{
		AlignLeft = left;
		AlignRight = right;
		AlignTop = top;
		AlignBottom = bottom;

		if (Parent)
		{
			core::rect<s32> r(Parent->getAbsolutePosition());
		
			core::dimension2df d((f32)r.getSize().Width, (f32)r.getSize().Height);

			if (AlignLeft   == EGUIA_SCALE)
				ScaleRect.UpperLeftCorner.X = (f32)DesiredRect.UpperLeftCorner.X / d.Width;
			if (AlignRight  == EGUIA_SCALE)
				ScaleRect.LowerRightCorner.X = (f32)DesiredRect.LowerRightCorner.X / d.Width;
			if (AlignTop    == EGUIA_SCALE)
				ScaleRect.UpperLeftCorner.Y = (f32)DesiredRect.UpperLeftCorner.Y / d.Height;
			if (AlignBottom == EGUIA_SCALE)
				ScaleRect.LowerRightCorner.Y = (f32)DesiredRect.LowerRightCorner.Y / d.Height;
		}
	}

	//! Updates the absolute position.
	virtual void updateAbsolutePosition()
	{
		core::rect<s32> parentAbsolute(0,0,0,0);
		core::rect<s32> parentAbsoluteClip;
		s32 diffx, diffy;
		f32 fw=0.f, fh=0.f;

		if (Parent)
		{
			parentAbsolute = Parent->AbsoluteRect;

			if (NoClip)
			{
				IGUIElement* p=this;
				while (p && p->NoClip && p->Parent)
						p = p->Parent;
				if (p->Parent)
					parentAbsoluteClip = p->Parent->AbsoluteClippingRect;
				else
					parentAbsoluteClip = p->AbsoluteClippingRect;
			}
			else
				parentAbsoluteClip = Parent->AbsoluteClippingRect;
		}


		diffx = parentAbsolute.getWidth() - LastParentRect.getWidth();
		diffy = parentAbsolute.getHeight() - LastParentRect.getHeight();
		
		if (AlignLeft == EGUIA_SCALE || AlignRight == EGUIA_SCALE)
			fw = (f32)parentAbsolute.getWidth();

		if (AlignTop == EGUIA_SCALE || AlignBottom == EGUIA_SCALE)
			fh = (f32)parentAbsolute.getHeight();


		switch (AlignLeft)
		{
			case EGUIA_UPPERLEFT:
				break;
			case EGUIA_LOWERRIGHT:
				DesiredRect.UpperLeftCorner.X += diffx;
				break;
			case EGUIA_CENTER:
				DesiredRect.UpperLeftCorner.X += diffx/2;
				break;
			case EGUIA_SCALE:
				DesiredRect.UpperLeftCorner.X = (s32)(ScaleRect.UpperLeftCorner.X * fw);
				break;
		}

		switch (AlignRight)
		{
			case EGUIA_UPPERLEFT:
				break;
			case EGUIA_LOWERRIGHT:
				DesiredRect.LowerRightCorner.X += diffx;
				break;
			case EGUIA_CENTER:
				DesiredRect.LowerRightCorner.X += diffx/2;
				break;
			case EGUIA_SCALE:
				DesiredRect.LowerRightCorner.X = (s32)(ScaleRect.LowerRightCorner.X * fw);
				break;
		}

		switch (AlignTop)
		{
			case EGUIA_UPPERLEFT:
				break;
			case EGUIA_LOWERRIGHT:
				DesiredRect.UpperLeftCorner.Y += diffy;
				break;
			case EGUIA_CENTER:
				DesiredRect.UpperLeftCorner.Y += diffy/2;
				break;
			case EGUIA_SCALE:
				DesiredRect.UpperLeftCorner.Y = (s32)(ScaleRect.UpperLeftCorner.Y * fh);
				break;
		}

		switch (AlignBottom)
		{
			case EGUIA_UPPERLEFT:
				break;
			case EGUIA_LOWERRIGHT:
				DesiredRect.LowerRightCorner.Y += diffy;
				break;
			case EGUIA_CENTER:
				DesiredRect.LowerRightCorner.Y += diffy/2;
				break;
			case EGUIA_SCALE:
				DesiredRect.LowerRightCorner.Y = (s32)(ScaleRect.LowerRightCorner.Y * fh);
				break;
		}

		RelativeRect = DesiredRect;

		s32 w = RelativeRect.getWidth();
		s32 h = RelativeRect.getHeight();

		// make sure the desired rectangle is allowed
		if (w < MinSize.Width)
			RelativeRect.LowerRightCorner.X = RelativeRect.UpperLeftCorner.X + MinSize.Width;
		if (h < MinSize.Height)
			RelativeRect.LowerRightCorner.Y = RelativeRect.UpperLeftCorner.Y + MinSize.Height;
		if (MaxSize.Width && w > MaxSize.Width)
			RelativeRect.LowerRightCorner.X = RelativeRect.UpperLeftCorner.X + MaxSize.Width;
		if (MaxSize.Height && h > MaxSize.Height)
			RelativeRect.LowerRightCorner.Y = RelativeRect.UpperLeftCorner.Y + MaxSize.Height;

		RelativeRect.repair();
		
		AbsoluteRect = RelativeRect + parentAbsolute.UpperLeftCorner;

		if (!Parent)
			parentAbsoluteClip = AbsoluteRect;

		AbsoluteClippingRect = AbsoluteRect;
		AbsoluteClippingRect.clipAgainst(parentAbsoluteClip);

		LastParentRect = parentAbsolute;

		// update all children
		core::list<IGUIElement*>::Iterator it = Children.begin();
		for (; it != Children.end(); ++it)
		{
			(*it)->updateAbsolutePosition();
		}
	}


	//! Returns the child element, which is at the position of the point.
	IGUIElement* getElementFromPoint(const core::position2d<s32>& point)
	{
		IGUIElement* target = 0;

		// we have to search from back to front.

		core::list<IGUIElement*>::Iterator it = Children.getLast();

		if (IsVisible)
			while(it != Children.end())
			{
				target = (*it)->getElementFromPoint(point);
				if (target)
					return target;

				--it;
			}

		if (AbsoluteClippingRect.isPointInside(point) && IsVisible)
			target = this;
		
		return target;
	}


	//! Adds a GUI element as new child of this element.
	virtual void addChild(IGUIElement* child)
	{
		if (child)
		{
			child->grab();
			child->remove();  // remove from old parent
			child->Parent = this;
			Children.push_back(child);						
		}
	}


	//! Removes a child.
	virtual void removeChild(IGUIElement* child)
	{
		core::list<IGUIElement*>::Iterator it = Children.begin();
		for (; it != Children.end(); ++it)
			if ((*it) == child)
			{
				(*it)->Parent = 0;
				(*it)->drop();
				Children.erase(it);
				return;
			}
	}


	//! Removes this element from its parent.
	virtual void remove()
	{
		if (Parent)
			Parent->removeChild(this);
	}


	//! Draws the element and its children.
	virtual void draw()
	{
		if (!IsVisible)
			return;

		core::list<IGUIElement*>::Iterator it = Children.begin();
		for (; it != Children.end(); ++it)
			(*it)->draw();
	}

	//! animate the element and its children.
	virtual void OnPostRender(u32 timeMs)
	{
		if (!IsVisible)
			return;

		core::list<IGUIElement*>::Iterator it = Children.begin();
		for (; it != Children.end(); ++it)
			(*it)->OnPostRender( timeMs );
	}


	//! Moves this element.
	virtual void move(core::position2d<s32> absoluteMovement)
	{
		setRelativePosition(DesiredRect + absoluteMovement);
	}


	//! Returns true if element is visible.
	virtual bool isVisible()
	{
		_IRR_IMPLEMENT_MANAGED_MARSHALLING_BUGFIX;
		return IsVisible;
	}


	//! Sets the visible state of this element.
	virtual void setVisible(bool visible)
	{
		IsVisible = visible;
	}


	//! Returns true if this element was created as part of its parent control
	virtual bool isSubElement()
	{
		_IRR_IMPLEMENT_MANAGED_MARSHALLING_BUGFIX;
		return IsSubElement;
	}

	//! Sets whether this control was created as part of its parent, 
	//! for example when a scrollbar is part of a listbox. 
	//! SubElements are not saved to disk when calling guiEnvironment->saveGUI()
	virtual void setSubElement(bool subElement)
	{
		IsSubElement = subElement;
	}

	//! Returns true if element is enabled.
	virtual bool isEnabled()
	{
		_IRR_IMPLEMENT_MANAGED_MARSHALLING_BUGFIX;
		return IsEnabled;
	}


	//! Sets the enabled state of this element.
	virtual void setEnabled(bool enabled)
	{
		IsEnabled = enabled;
	}


	//! Sets the new caption of this element.
	virtual void setText(const wchar_t* text)
	{
		Text = text;
	}


	//! Returns caption of this element.
	virtual const wchar_t* getText()
	{
		return Text.c_str();
	}

	//! Sets the new caption of this element.
	virtual void setToolTipText(const wchar_t* text)
	{
		ToolTipText = text;
	}


	//! Returns caption of this element.
	virtual core::stringw &getToolTipText()
	{
		return ToolTipText;
	}


	//! Returns id. Can be used to identify the element.
	virtual s32 getID()
	{
		return ID;
	}

	//! Sets the id of this element
	virtual void setID(s32 id)
	{
		ID = id;
	}


	//! Called if an event happened.
	virtual bool OnEvent(SEvent event)
	{
		if (Parent)
			Parent->OnEvent(event);

		return true;
	}


	//! Brings a child to front
	/* \return Returns true if successful, false if not. */
	virtual bool bringToFront(IGUIElement* element)
	{
		core::list<IGUIElement*>::Iterator it = Children.begin();
		for (; it != Children.end(); ++it)
		{
			if (element == (*it))
			{
				Children.erase(it);
				Children.push_back(element);
				return true;
			}
		}

		_IRR_IMPLEMENT_MANAGED_MARSHALLING_BUGFIX;
		return false;
	}

	//! Returns list with children of this element
	virtual const core::list<IGUIElement*>& getChildren() const
	{
		return Children;
	}

	//! Finds the first element with the given id.
	/* \param id: Id to search for.
	 \param searchchildren: Set this to true, if also children of this 
	 element may contain the element with the searched id and they 
	 should be searched too.
	 \return Returns the first element with the given id. If no element
	 with this id was found, 0 is returned. */
	virtual IGUIElement* getElementFromId(s32 id, bool searchchildren=false) const
	{
		IGUIElement* e = 0;

		core::list<IGUIElement*>::Iterator it = Children.begin();
		for (; it != Children.end(); ++it)
		{
			if ((*it)->getID() == id)
				return (*it);

			if (searchchildren)
				e = (*it)->getElementFromId(id, true);

			if (e)
				return e;
		}		

		return e;
	}

	//! Returns the type of the gui element. 
	/* This is needed for the .NET wrapper but will be used
	later for serializing and deserializing.
	If you wrote your own GUIElements, you need to set the type for your element as first parameter
	in the constructor of IGUIElement. For own (=unknown) elements, simply use EGUIET_ELEMENT as type */
	EGUI_ELEMENT_TYPE getType()
	{
		return Type;
	}

	//! Returns the type name of the gui element. 
	/* This is needed serializing elements. For serializing your own elements, override this function 
	and return your own type name which is created by your IGUIElementFactory */
	virtual const c8* getTypeName()
	{
		return GUIElementTypeNames[Type];
	}

	//! Writes attributes of the scene node.
	//! Implement this to expose the attributes of your scene node for
	//! scripting languages, editors, debuggers or xml serialization purposes.
	virtual void serializeAttributes(io::IAttributes* out, io::SAttributeReadWriteOptions* options=0)
	{
		out->addInt("Id", ID );
		out->addString("Caption", Text.c_str());
		out->addRect("Rect", DesiredRect);
		out->addPosition2d("MinSize", core::position2di(MinSize.Width, MinSize.Height));
		out->addPosition2d("MaxSize", core::position2di(MaxSize.Width, MaxSize.Height));
		out->addBool("NoClip", NoClip);
		out->addEnum("LeftAlign", AlignLeft, GUIAlignmentNames);
		out->addEnum("RightAlign", AlignRight, GUIAlignmentNames);
		out->addEnum("TopAlign", AlignTop, GUIAlignmentNames);
		out->addEnum("BottomAlign", AlignBottom, GUIAlignmentNames);
		out->addBool("Visible", IsVisible );
		out->addBool("Enabled", IsEnabled );
	}

	//! Reads attributes of the scene node.
	//! Implement this to set the attributes of your scene node for
	//! scripting languages, editors, debuggers or xml deserialization purposes.
	virtual void deserializeAttributes(io::IAttributes* in, io::SAttributeReadWriteOptions* options=0)
	{
		//! relative rect of element
		ID = in->getAttributeAsInt("Id");
		Text = in->getAttributeAsStringW("Caption").c_str();
		IsVisible = in->getAttributeAsBool("Visible");
		IsEnabled = in->getAttributeAsBool("Enabled");
		core::position2di p = in->getAttributeAsPosition2d("MaxSize");
		MaxSize = core::dimension2di(p.X,p.Y);
		p = in->getAttributeAsPosition2d("MinSize");
		MinSize = core::dimension2di(p.X,p.Y);
		NoClip = in->getAttributeAsBool("NoClip");
		AlignLeft = (EGUI_ALIGNMENT) in->getAttributeAsEnumeration("LeftAlign", GUIAlignmentNames);
		AlignRight = (EGUI_ALIGNMENT)in->getAttributeAsEnumeration("RightAlign", GUIAlignmentNames);
		AlignTop = (EGUI_ALIGNMENT)in->getAttributeAsEnumeration("TopAlign", GUIAlignmentNames);
		AlignBottom = (EGUI_ALIGNMENT)in->getAttributeAsEnumeration("BottomAlign", GUIAlignmentNames);

		setRelativePosition(in->getAttributeAsRect("Rect"));
	}

protected:

	//! List of all children of this element
	core::list<IGUIElement*> Children;

	//! Pointer to the parent
	IGUIElement* Parent;

	//! relative rect of element
	core::rect<s32> RelativeRect;

	//! absolute rect of element
	core::rect<s32> AbsoluteRect;

	//! absolute clipping rect of element
	core::rect<s32> AbsoluteClippingRect;

	//! the rectangle the element would prefer to be, 
	//! if it was not constrained by parent or max/min size
	core::rect<s32> DesiredRect;

	//! for calculating the difference when resizing parent
	core::rect<s32> LastParentRect;

	//! relative scale of the element inside its parent
	core::rect<f32> ScaleRect;

	//! maximum and minimum size of the element
	core::dimension2di MaxSize, MinSize;

	//! is visible?
	bool IsVisible;

	//! is enabled?
	bool IsEnabled;

	//! is a part of a larger whole and should not be serialized?
	bool IsSubElement;

	//! does this element ignore its parent's clipping rectangle?
	bool NoClip;

	//! caption
	core::stringw Text;

	//! tooltip
	core::stringw ToolTipText;

	//! id
	s32 ID;

	//! tells the element how to act when its parent is resized
	EGUI_ALIGNMENT AlignLeft, AlignRight, AlignTop, AlignBottom;

	//! GUI Environment
	IGUIEnvironment* Environment;

	//! type of element
	EGUI_ELEMENT_TYPE Type;
};


} // end namespace gui
} // end namespace irr

#endif


namespace irr
{

namespace video
{
	class ITexture;
} // end namespace video

namespace gui
{
	class IGUIFont;
	class IGUISpriteBank;

	enum EGUI_BUTTON_STATE
	{
		//! The button is not pressed
		EGBS_BUTTON_UP=0,
		//! The button is currently pressed down
		EGBS_BUTTON_DOWN,
		//! The mouse cursor is over the button
		EGBS_BUTTON_MOUSE_OVER,
		//! The mouse cursor is not over the button
		EGBS_BUTTON_MOUSE_OFF,
		//! The button has the focus
		EGBS_BUTTON_FOCUSED,
		//! The button doesn't have the focus
		EGBS_BUTTON_NOT_FOCUSED,
		//! not used, counts the number of enumerated items
		EGBS_COUNT
	};

	//! Names for gui button state icons
	const c8* const GUIButtonStateNames[] =
	{
		"buttonUp",
		"buttonDown",
		"buttonMouseOver",
		"buttonMouseOff",
		"buttonFocused",
		"buttonNotFocused",
		0,
		0,
	};

	//! GUI Button interface.
	class IGUIButton : public IGUIElement
	{
	public:

		//! constructor
		IGUIButton(IGUIEnvironment* environment, IGUIElement* parent, s32 id, core::rect<s32> rectangle)
			: IGUIElement(EGUIET_BUTTON, environment, parent, id, rectangle) {}

		//! destructor
		~IGUIButton() {};

		//! Sets another skin independent font.
		/* If this is set to zero, the button uses the font of the skin.
		 \param font: New font to set. */
		virtual void setOverrideFont(IGUIFont* font=0) = 0;

		//! Sets an image which should be displayed on the button when it is in normal state. 
		/* \param image: Image to be displayed */
		virtual void setImage(video::ITexture* image) = 0;

		//! Sets a background image for the button when it is in normal state. 
		/* \param image: Texture containing the image to be displayed
		 \param pos: Position in the texture, where the image is located */
		virtual void setImage(video::ITexture* image, const core::rect<s32>& pos) = 0;

		//! Sets a background image for the button when it is in pressed state. 
		/* If no images is specified for the pressed state via
		setPressedImage(), this image is also drawn in pressed state.
		\param image: Image to be displayed */
		virtual void setPressedImage(video::ITexture* image) = 0;

		//! Sets an image which should be displayed on the button when it is in pressed state. 
		/* \param image: Texture containing the image to be displayed
		 \param pos: Position in the texture, where the image is located */
		virtual void setPressedImage(video::ITexture* image, const core::rect<s32>& pos) = 0;

		//! Sets the sprite bank used by the button
		virtual void setSpriteBank(IGUISpriteBank* bank) = 0;

		//! Sets the animated sprite for a specific button state
		/* \param index: Number of the sprite within the sprite bank, use -1 for no sprite
		\param state: State of the button to set the sprite for
		\param index: The sprite number from the current sprite bank
		\param color: The color of the sprite
		\param loop: True if the animation should loop, false if not
		*/
		virtual void setSprite(EGUI_BUTTON_STATE state, s32 index, 
				video::SColor color=video::SColor(255,255,255,255), bool loop=false) = 0;

		//! Sets if the button should behave like a push button. 
		/* Which means it can be in two states: Normal or Pressed. With a click on the button,
		the user can change the state of the button. */
		virtual void setIsPushButton(bool isPushButton) = 0;

		//! Sets the pressed state of the button if this is a pushbutton
		virtual void setPressed(bool pressed) = 0;

		//! Returns if the button is currently pressed
		virtual bool isPressed() = 0;

		//! Sets if the alpha channel should be used for drawing background images on the button (default is false)
		virtual void setUseAlphaChannel(bool useAlphaChannel) = 0;

		//! Returns if the alpha channel should be used for drawing background images on the button
		virtual bool getUseAlphaChannel() = 0;

		//! Sets if the button should use the skin to draw its border (default is true)
		virtual void setDrawBorder(bool border) = 0;
	};


} // end namespace gui
} // end namespace irr

#endif


namespace irr
{
namespace gui
{
	//! enumeration for message box layout flags
	enum EMESSAGE_BOX_FLAG
	{
		//! Flag for the ok button
		EMBF_OK = 0x1,

		//! Flag for the cancel button
		EMBF_CANCEL = 0x2,

		//! Flag for the yes button
		EMBF_YES = 0x4,

		//! Flag for the no button
		EMBF_NO = 0x8,

		//! This value is not used. It only forces this enumeration to compile in 32 bit. 
		EMBF_FORCE_32BIT = 0x7fffffff	
	};

	//! Default moveable window GUI element with border, caption and close icons.
	class IGUIWindow : public IGUIElement
	{
	public:

		//! constructor
		IGUIWindow(IGUIEnvironment* environment, IGUIElement* parent, s32 id, core::rect<s32> rectangle)
			: IGUIElement(EGUIET_WINDOW, environment, parent, id, rectangle) {}

		//! destructor
		virtual ~IGUIWindow() {};

		//! Returns pointer to the close button
		virtual IGUIButton* getCloseButton() = 0;

		//! Returns pointer to the minimize button
		virtual IGUIButton* getMinimizeButton() = 0;

		//! Returns pointer to the maximize button
		virtual IGUIButton* getMaximizeButton() = 0;
	};


} // end namespace gui
} // end namespace irr

#endif

// Copyright (C) 2002-2007 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __I_GUI_SKIN_H_INCLUDED__
#define __I_GUI_SKIN_H_INCLUDED__

/* SKIPPED: #include "IGUISkin.h" */

namespace irr
{
namespace gui
{
	class IGUIFont;
	class IGUISpriteBank;
	class IGUIElement;

	//! Enumeration of available default skins.
	/* To set one of the skins, use the following code, for example to set
	the Windows classic skin:
	\code
	gui::IGUISkin newskin = environment->createSkin(gui::EGST_WINDOWS_CLASSIC);
	environment->setSkin(newskin);
	newskin->drop();
	\endcode
	*/
	enum EGUI_SKIN_TYPE
	{
		//! Default windows look and feel
		EGST_WINDOWS_CLASSIC=0,
		//! Like EGST_WINDOWS_CLASSIC, but with metallic shaded windows and buttons
		EGST_WINDOWS_METALLIC,
		//! Burning's skin
		EGST_BURNING_SKIN,

		//! An unknown skin, not serializable at present
		EGST_UNKNOWN
	};

	//! Names for gui element types
	const c8* const GUISkinTypeNames[] =
	{
		"windowsClassic",
		"windowsMetallic",
		"burning",
		"unknown",
		0,
	};


	//! Enumeration for skin colors
	enum EGUI_DEFAULT_COLOR
	{
		//! Dark shadow for three-dimensional display elements.
		EGDC_3D_DARK_SHADOW = 0,
		//! Shadow color for three-dimensional display elements (for edges facing away from the light source).
		EGDC_3D_SHADOW,
		//! Face color for three-dimensional display elements and for dialog box backgrounds.
		EGDC_3D_FACE,
		//! Highlight color for three-dimensional display elements (for edges facing the light source.)
		EGDC_3D_HIGH_LIGHT,
		//! Light color for three-dimensional display elements (for edges facing the light source.)
		EGDC_3D_LIGHT,
		//! Active window border.
		EGDC_ACTIVE_BORDER,
		//! Active window title bar text.
		EGDC_ACTIVE_CAPTION,
		//! Background color of multiple document interface (MDI) applications.
		EGDC_APP_WORKSPACE,
		//! Text on a button
		EGDC_BUTTON_TEXT,
		//! Grayed (disabled) text.
		EGDC_GRAY_TEXT,
		//! Item(s) selected in a control.
		EGDC_HIGH_LIGHT,
		//! Text of item(s) selected in a control.
		EGDC_HIGH_LIGHT_TEXT,
		//! Inactive window border.
		EGDC_INACTIVE_BORDER,
		//! Inactive window caption.
		EGDC_INACTIVE_CAPTION,
		//! Tool tip color
		EGDC_TOOLTIP,
		//! Scrollbar gray area
		EGDC_SCROLLBAR,
		//! Window background
		EGDC_WINDOW,
		//! Window symbols like on close buttons, scroll bars and check boxes
		EGDC_WINDOW_SYMBOL,
		//! Icons in a list or tree
		EGDC_ICON,
		//! Selected icons in a list or tree
		EGDC_ICON_HIGH_LIGHT,
		//! this value is not used, it only specifies the amount of default colors
		//! available.
		EGDC_COUNT
	};

	//! Names for default skin colors
	const c8* const GUISkinColorNames[] =
	{
		"3DDarkShadow",
		"3DShadow",
		"3DFace",
		"3DHighlight",
		"3DLight",
		"ActiveBorder",
		"ActiveCaption",
		"AppWorkspace",
		"ButtonText",
		"GrayText",
		"Highlight",
		"HighlightText",
		"InactiveBorder",
		"InactiveCaption",
		"ToolTip",
		"ScrollBar",
		"Window",
		"WindowSymbol",
		"Icon",
		"IconHighlight",
		0,
	};

	//! Enumeration for default sizes.
	enum EGUI_DEFAULT_SIZE
	{
		//! default with / height of scrollbar
		EGDS_SCROLLBAR_SIZE = 0,
		//! height of menu
		EGDS_MENU_HEIGHT,
		//! width of a window button
		EGDS_WINDOW_BUTTON_WIDTH,
		//! width of a checkbox check
		EGDS_CHECK_BOX_WIDTH,
		//! width of a messagebox
		EGDS_MESSAGE_BOX_WIDTH,
		//! height of a messagebox
		EGDS_MESSAGE_BOX_HEIGHT,
		//! width of a default button
		EGDS_BUTTON_WIDTH,
		//! height of a default button
		EGDS_BUTTON_HEIGHT,
		//! distance for text from background
		EGDS_TEXT_DISTANCE_X,
		//! distance for text from background
		EGDS_TEXT_DISTANCE_Y,
		//! this value is not used, it only specifies the amount of default sizes
		//! available.
		EGDS_COUNT
	};


	//! Names for default skin sizes
	const c8* const GUISkinSizeNames[] =
	{
		"ScrollBarSize",
		"MenuHeight",
		"WindowButtonWidth",
		"CheckBoxWidth",
		"MessageBoxWidth",
		"MessageBoxHeight",
		"ButtonWidth",
		"ButtonHeight",
		"TextDistanceX",
		"TextDistanceY",
		0,
	};


	enum EGUI_DEFAULT_TEXT
	{
		//! Text for the OK button on a message box
		EGDT_MSG_BOX_OK = 0,
		//! Text for the Cancel button on a message box
		EGDT_MSG_BOX_CANCEL,
		//! Text for the Yes button on a message box
		EGDT_MSG_BOX_YES,
		//! Text for the No button on a message box
		EGDT_MSG_BOX_NO,
		//! Tooltip text for window close button
		EGDT_WINDOW_CLOSE,
		//! Tooltip text for window maximize button
		EGDT_WINDOW_MAXIMIZE,
		//! Tooltip text for window minimize button
		EGDT_WINDOW_MINIMIZE,
		//! Tooltip text for window restore button
		EGDT_WINDOW_RESTORE,

		//! this value is not used, it only specifies the number of default texts
		EGDT_COUNT
	};

	//! Names for default skin sizes
	const c8* const GUISkinTextNames[] =
	{
		"MessageBoxOkay",
		"MessageBoxCancel",
		"MessageBoxYes",
		"MessageBoxNo",
		"WindowButtonClose",
		"WindowButtonMaximize",
		"WindowButtonMinimize",
		"WindowButtonRestore",
		0,
	};

	//! Customizable symbols for GUI
	enum EGUI_DEFAULT_ICON
	{
		//! maximize window button
		EGDI_WINDOW_MAXIMIZE = 0,
		//! restore window button
		EGDI_WINDOW_RESTORE,
		//! close window button
		EGDI_WINDOW_CLOSE,
		//! minimize window button
		EGDI_WINDOW_MINIMIZE,
		//! scroll bar up button
		EGDI_CURSOR_UP,
		//! scroll bar down button
		EGDI_CURSOR_DOWN,
		//! scroll bar left button
		EGDI_CURSOR_LEFT,
		//! scroll bar right button
		EGDI_CURSOR_RIGHT,
		//! icon for menu children
		EGDI_MENU_MORE,
		//! tick for checkbox
		EGDI_CHECK_BOX_CHECKED,
		//! down arrow for dropdown menus
		EGDI_DROP_DOWN,
		//! smaller up arrow
		EGDI_SMALL_CURSOR_UP,
		//! smaller down arrow
		EGDI_SMALL_CURSOR_DOWN,
		//! selection dot in a radio button
		EGDI_RADIO_BUTTON_CHECKED,
		//! file icon for file selection
		EGDI_FILE,
		//! folder icon for file selection
		EGDI_DIRECTORY,

		//! value not used, it only specifies the number of icons
		EGDI_COUNT
	};

	const c8* const GUISkinIconNames[] =
	{
		"windowMaximize",
		"windowRestore",
		"windowClose",
		"windowMinimize",
		"cursorUp",
		"cursorDown",
		"cursorLeft",
		"cursorRight",
		"menuMore",
		"checkBoxChecked",
		"dropDown",
		"smallCursorUp",
		"smallCursorDown",
		"radioButtonChecked",
		"file",
		"directory",
		0
	};

	//! A skin modifies the look of the GUI elements.
	class IGUISkin : public virtual io::IAttributeExchangingObject
	{
	public:

		//! destructor
		~IGUISkin() {};

		//! returns default color
		virtual video::SColor getColor(EGUI_DEFAULT_COLOR color) = 0;

		//! sets a default color
		virtual void setColor(EGUI_DEFAULT_COLOR which, video::SColor newColor) = 0;

		//! returns default color
		virtual s32 getSize(EGUI_DEFAULT_SIZE size) = 0;

		//! Returns a default text. 
		/* For example for Message box button captions:
		"OK", "Cancel", "Yes", "No" and so on. */
		virtual const wchar_t* getDefaultText(EGUI_DEFAULT_TEXT text) = 0;

		//! Sets a default text.
		/* For example for Message box button captions:
		"OK", "Cancel", "Yes", "No" and so on. */
		virtual void setDefaultText(EGUI_DEFAULT_TEXT which, const wchar_t* newText) = 0;

		//! sets a default size
		virtual void setSize(EGUI_DEFAULT_SIZE which, s32 size) = 0;

		//! returns the default font
		virtual IGUIFont* getFont() = 0;

		//! sets a default font
		virtual void setFont(IGUIFont* font) = 0;

		//! returns the sprite bank
		virtual IGUISpriteBank* getSpriteBank() = 0;

		//! sets the sprite bank
		virtual void setSpriteBank(IGUISpriteBank* bank) = 0;

		//! Returns a default icon
		/* Returns the sprite index within the sprite bank */
		virtual u32 getIcon(EGUI_DEFAULT_ICON icon) = 0;

		//! Sets a default icon
		/* Sets the sprite index used for drawing icons like arrows, 
		close buttons and ticks in checkboxes 
		\param icon: Enum specifying which icon to change
		\param index: The sprite index used to draw this icon */
		virtual void setIcon(EGUI_DEFAULT_ICON icon, u32 index) = 0;

		//! draws a standard 3d button pane
		/*	Used for drawing for example buttons in normal state. 
		It uses the colors EGDC_3D_DARK_SHADOW, EGDC_3D_HIGH_LIGHT, EGDC_3D_SHADOW and
		EGDC_3D_FACE for this. See EGUI_DEFAULT_COLOR for details. 
		\param element: Pointer to the element which wishes to draw this. This parameter
		is usually not used by IGUISkin, but can be used for example by more complex 
		implementations to find out how to draw the part exactly. 
		\param rect: Defining area where to draw.
		\param clip: Clip area.	*/
		virtual void draw3DButtonPaneStandard(IGUIElement* element,
			const core::rect<s32>& rect,
			const core::rect<s32>* clip=0) = 0;

		//! draws a pressed 3d button pane
		/*	Used for drawing for example buttons in pressed state. 
		It uses the colors EGDC_3D_DARK_SHADOW, EGDC_3D_HIGH_LIGHT, EGDC_3D_SHADOW and
		EGDC_3D_FACE for this. See EGUI_DEFAULT_COLOR for details. 
		\param element: Pointer to the element which wishes to draw this. This parameter
		is usually not used by IGUISkin, but can be used for example by more complex 
		implementations to find out how to draw the part exactly. 
		\param rect: Defining area where to draw.
		\param clip: Clip area.	*/
		virtual void draw3DButtonPanePressed(IGUIElement* element, 
			const core::rect<s32>& rect,
			const core::rect<s32>* clip=0) = 0;

		//! draws a sunken 3d pane
		/* Used for drawing the background of edit, combo or check boxes.
		\param element: Pointer to the element which wishes to draw this. This parameter
		is usually not used by IGUISkin, but can be used for example by more complex 
		implementations to find out how to draw the part exactly. 
		\param bgcolor: Background color.
		\param flat: Specifies if the sunken pane should be flat or displayed as sunken 
		 deep into the ground.
		\param fillBackGround: Specifies if the background should be filled with the background
		color or not be drawn at all.
		\param rect: Defining area where to draw.
		\param clip: Clip area.	*/
		virtual void draw3DSunkenPane(IGUIElement* element,
			video::SColor bgcolor, bool flat, bool fillBackGround,
			const core::rect<s32>& rect,
			const core::rect<s32>* clip=0) = 0;

		//! draws a window background
		/* Used for drawing the background of dialogs and windows.
		\param element: Pointer to the element which wishes to draw this. This parameter
		is usually not used by IGUISkin, but can be used for example by more complex 
		implementations to find out how to draw the part exactly. 
		\param titleBarColor: Title color.
		\param drawTitleBar: True to enable title drawing.
		\param rect: Defining area where to draw.
		\param clip: Clip area.	
		\return Returns rect where it would be good to draw title bar text. */
		virtual core::rect<s32> draw3DWindowBackground(IGUIElement* element,
			bool drawTitleBar, video::SColor titleBarColor,
			const core::rect<s32>& rect,
			const core::rect<s32>* clip=0) = 0;

		//! draws a standard 3d menu pane
		/*	Used for drawing for menus and context menus. 
		It uses the colors EGDC_3D_DARK_SHADOW, EGDC_3D_HIGH_LIGHT, EGDC_3D_SHADOW and
		EGDC_3D_FACE for this. See EGUI_DEFAULT_COLOR for details. 
		\param element: Pointer to the element which wishes to draw this. This parameter
		is usually not used by IGUISkin, but can be used for example by more complex 
		implementations to find out how to draw the part exactly. 
		\param rect: Defining area where to draw.
		\param clip: Clip area.	*/
		virtual void draw3DMenuPane(IGUIElement* element,
			const core::rect<s32>& rect,
			const core::rect<s32>* clip=0) = 0;

		//! draws a standard 3d tool bar
		/*	Used for drawing for toolbars and menus.
		\param element: Pointer to the element which wishes to draw this. This parameter
		is usually not used by IGUISkin, but can be used for example by more complex 
		implementations to find out how to draw the part exactly. 
		\param rect: Defining area where to draw.
		\param clip: Clip area.	*/
		virtual void draw3DToolBar(IGUIElement* element,
			const core::rect<s32>& rect,
			const core::rect<s32>* clip=0) = 0;

		//! draws a tab button
		/*	Used for drawing for tab buttons on top of tabs.
		\param element: Pointer to the element which wishes to draw this. This parameter
		is usually not used by IGUISkin, but can be used for example by more complex 
		implementations to find out how to draw the part exactly. 
		\param active: Specifies if the tab is currently active.
		\param rect: Defining area where to draw.
		\param clip: Clip area.	*/
		virtual void draw3DTabButton(IGUIElement* element, bool active,
			const core::rect<s32>& rect, const core::rect<s32>* clip=0) = 0;

		//! draws a tab control body
		/*	\param element: Pointer to the element which wishes to draw this. This parameter
		is usually not used by IGUISkin, but can be used for example by more complex 
		implementations to find out how to draw the part exactly. 
		\param border: Specifies if the border should be drawn.
		\param background: Specifies if the background should be drawn.
		\param rect: Defining area where to draw.
		\param clip: Clip area.	*/
		virtual void draw3DTabBody(IGUIElement* element, bool border, bool background,
			const core::rect<s32>& rect, const core::rect<s32>* clip=0) = 0;

		//! draws an icon, usually from the skin's sprite bank
		/*	\param parent: Pointer to the element which wishes to draw this icon. 
		This parameter is usually not used by IGUISkin, but can be used for example 
		by more complex implementations to find out how to draw the part exactly. 
		\param icon: Specifies the icon to be drawn.
		\param position: The position to draw the icon
		\param starttime: The time at the start of the animation
		\param currenttime: The present time, used to calculate the frame number
		\param loop: Whether the animation should loop or not
		\param clip: Clip area.	*/
		virtual void drawIcon(IGUIElement* element, EGUI_DEFAULT_ICON icon,
			const core::position2di position, u32 starttime=0, u32 currenttime=0, 
			bool loop=false, const core::rect<s32>* clip=0) = 0;

		//! get the type of this skin
		virtual EGUI_SKIN_TYPE getType() { return EGST_UNKNOWN; };

	};


} // end namespace gui
} // end namespace irr

#endif


namespace irr
{
	namespace io
	{
		class IXMLWriter;
		class IReadFile;
		class IWriteFile;
	} // end namespace io
	namespace video
	{
		class IVideoDriver;
		class ITexture;
	} // end namespace video

namespace gui
{

class IGUIElement;
class IGUIFont;
class IGUISpriteBank;
class IGUIScrollBar;
class IGUIImage;
class IGUIMeshViewer;
class IGUICheckBox;
class IGUIListBox;
class IGUIFileOpenDialog;
class IGUIColorSelectDialog;
class IGUIInOutFader;
class IGUIStaticText;
class IGUIEditBox;
class IGUITabControl;
class IGUITab;
class IGUIContextMenu;
class IGUIComboBox;
class IGUIToolBar;
class IGUIElementFactory;

//! GUI Environment. Used as factory and manager of all other GUI elements.
class IGUIEnvironment : public virtual IUnknown
{
public:

	//! destructor
	virtual ~IGUIEnvironment() {};

	//! Draws all gui elements.
	virtual void drawAll() = 0;

	//! Sets the focus to an element.
	virtual void setFocus(IGUIElement* element) = 0;

	//! Returns the element with the focus
	virtual IGUIElement* getFocus() = 0;

	//! Removes the focus from an element.
	virtual void removeFocus(IGUIElement* element) = 0;

	//! Returns if the element has focus
	virtual bool hasFocus(IGUIElement* element) = 0;

	//! Returns the current video driver.
	virtual video::IVideoDriver* getVideoDriver() = 0;

	//! Returns the file system.
	virtual io::IFileSystem* getFileSystem() = 0;

	//! removes all elements from the environment.
	virtual void clear() = 0;

	//! Posts an input event to the environment. 
	/* Usually you do not have to
	use this method, it is used by the internal engine. */
	virtual bool postEventFromUser(SEvent event) = 0;

	//! This sets a new event receiver for gui events. 
	/* Usually you do not have to
	use this method, it is used by the internal engine. */
	virtual void setUserEventReceiver(IEventReceiver* evr) = 0;

	//! Returns pointer to the current gui skin.
	virtual IGUISkin* getSkin() = 0;

	//! Sets a new GUI Skin
	/* You can used this to change the appearance of the whole GUI Environment. You
	can set one ot the built-in skins or implement your own class derived from 
	IGUISkin and set this useing this method.
	To set for example the built-in Windows classic skin, use the following code:
	\code
	gui::IGUISkin newskin = environment->createSkin(gui::EGST_WINDOWS_CLASSIC);
	environment->setSkin(newskin);
	newskin->drop();
	\endcode
	*/
	virtual void setSkin(IGUISkin* skin) = 0;

	//! Creates a new GUI Skin based on a template.
	/* Use setSkin() to set the created skin.
	\return Returns a pointer to the created skin.
	If you no longer need the image, you should call IGUISkin::drop().
	See IUnknown::drop() for more information. */
	virtual IGUISkin* createSkin(EGUI_SKIN_TYPE type) = 0;

	//! Returns pointer to the font with the specified file name. 
	/* Loads the font if it was not loaded before. Returns 0 if the font could not be loaded.
	\return
	returns a pointer to the font.
	This pointer should not be dropped. See IUnknown::drop() for more information. */
	virtual IGUIFont* getFont(const c8* filename) = 0;

	//! Returns the default built-in font.
	virtual IGUIFont* getBuiltInFont() = 0;

	//! Returns pointer to the sprite bank with the specified file name. 
	/* Loads the bank if it was not loaded before. Returns 0 if it could not be loaded.
	\return
	returns a pointer to the sprite bank.
	This pointer should not be dropped. See IUnknown::drop() for more information. */
	virtual IGUISpriteBank* getSpriteBank(const c8* filename) = 0;

	//! adds an empty sprite bank to the manager
	virtual IGUISpriteBank* addEmptySpriteBank(const c8 *name) = 0;

	//! Returns the root gui element. 
	/* This is the first gui element, parent of all other
	gui elements. You'll never need to use this method, unless you are not creating 
	your own gui elements, trying to add them to the gui elements without a parent.
	The returned pointer should not be dropped. See IUnknown::drop() for more information. */
	virtual IGUIElement* getRootGUIElement() = 0;

	//! Adds an button element. 
	/* \return
	 Returns a pointer to the created button. Returns 0 if an error occured.
	 This pointer should not be dropped. See IUnknown::drop() for more information. */
	virtual IGUIButton* addButton(const core::rect<s32>& rectangle,
		IGUIElement* parent=0, s32 id=-1, const wchar_t* text=0, const wchar_t* tooltiptext = 0) = 0;

	//! Adds an empty window element. 
	/* \param modal: Defines if the dialog is modal. This means, that all other
	gui elements which were created before the message box cannot be used
	until this messagebox is removed.
	\return
	Returns a pointer to the created window. Returns 0 if an error occured.
	This pointer should not be dropped. See IUnknown::drop() for more information. */
	virtual IGUIWindow* addWindow(const core::rect<s32>& rectangle, bool modal = false, 
		const wchar_t* text=0, IGUIElement* parent=0, s32 id=-1) = 0;

	//! Adds a modal screen. This control stops its parent's members from being 
	//! able to recieve input until its last child is removed, it then deletes its self.
	/* \return
	Returns a pointer to the created window. Returns 0 if an error occured.
	This pointer should not be dropped. See IUnknown::drop() for more information. */
	virtual IGUIElement* addModalScreen(IGUIElement* parent) = 0;

	//! Adds a message box.
	/* \param caption: Text to be displayed the title of the message box.
	\param text: Text to be displayed in the body of the message box.
	 \param modal: Defines if the dialog is modal. This means, that all other
	 gui elements which were created before the message box cannot be used
	 until this messagebox is removed.
	 \param flags: Flags specifying the layout of the message box. For example
	 to create a message box with an OK and a CANCEL button on it, set this
	 to (EMBF_OK | EMBF_CANCEL).
	 \param parent: Parent gui element of the message box.
	 \param id: Id with which the gui element can be identified.
	 \return
	 Returns a pointer to the created message box. Returns 0 if an error occured.
	 This pointer should not be dropped. See IUnknown::drop() for more information. */
	virtual IGUIWindow* addMessageBox(const wchar_t* caption, const wchar_t* text=0,
		bool modal = true, s32 flags = EMBF_OK, IGUIElement* parent=0, s32 id=-1) = 0;

	//! Adds a scrollbar. 
	/* \return
	Returns a pointer to the created scrollbar. Returns 0 if an error occured.
	This pointer should not be dropped. See IUnknown::drop() for more information. */
	virtual IGUIScrollBar* addScrollBar(bool horizontal, const core::rect<s32>& rectangle,
		IGUIElement* parent=0, s32 id=-1) = 0;

	//! Adds an image element. 
	/* \param image: Image to be displayed.
	 \param pos: Position of the image. The width and height of the image is taken
	 from the image.
	 \param useAlphaChannel: Sets if the image should use the alpha channel of the texture
	 to draw itself.
	 \return
	 Returns a pointer to the created image element. Returns 0 if an error occured.
	 This pointer should not be dropped. See IUnknown::drop() for more information. */
	virtual IGUIImage* addImage(video::ITexture* image, core::position2d<s32> pos,
		bool useAlphaChannel=true, IGUIElement* parent=0, s32 id=-1, const wchar_t* text=0) = 0;

	//! Adds an image element. 
	/* Use IGUIImage::setImage later to set the image to be displayed. 
	\return
	 Returns a pointer to the created image element. Returns 0 if an error occured.
	 This pointer should not be dropped. See IUnknown::drop() for more information. */
	virtual IGUIImage* addImage(const core::rect<s32>& rectangle,
		IGUIElement* parent=0, s32 id=-1, const wchar_t* text=0) = 0;

	//! Adds a checkbox element.
	/* \return
	 Returns a pointer to the created check box. Returns 0 if an error occured.
	 This pointer should not be dropped. See IUnknown::drop() for more information. */
	virtual IGUICheckBox* addCheckBox(bool checked, const core::rect<s32>& rectangle,
		IGUIElement* parent=0, s32 id=-1, const wchar_t* text=0) = 0;

	//! Adds a list box element.
	/* \return
	 Returns a pointer to the created list box. Returns 0 if an error occured.
	 This pointer should not be dropped. See IUnknown::drop() for more information. */
	virtual IGUIListBox* addListBox(const core::rect<s32>& rectangle, 
		IGUIElement* parent=0, s32 id=-1, bool drawBackground=false) = 0;

	//! Adds an mesh viewer. Not 100% implemented yet.
	/* \return
	 Returns a pointer to the created mesh viewer. Returns 0 if an error occured.
	 This pointer should not be dropped. See IUnknown::drop() for more information. */
	virtual IGUIMeshViewer* addMeshViewer(const core::rect<s32>& rectangle, IGUIElement* parent=0, s32 id=-1, const wchar_t* text=0) = 0;

	//! Adds a file open dialog.
	/* \param modal: Defines if the dialog is modal. This means, that all other
	 gui elements which were created before the message box cannot be used
	 until this messagebox is removed.
	 \return
	 Returns a pointer to the created file open dialog. Returns 0 if an error occured.
	 This pointer should not be dropped. See IUnknown::drop() for more information. */
	virtual IGUIFileOpenDialog* addFileOpenDialog(const wchar_t* title = 0, 
		bool modal=true, IGUIElement* parent=0, s32 id=-1) = 0;

	//! Adds a color select dialog.
	/* \param modal: Defines if the dialog is modal. This means, that all other
	 gui elements which were created before the message box cannot be used
	 until this messagebox is removed.
	 \return
	 Returns a pointer to the created file open dialog. Returns 0 if an error occured.
	 This pointer should not be dropped. See IUnknown::drop() for more information. */
	virtual IGUIColorSelectDialog* addColorSelectDialog(const wchar_t* title = 0, 
		bool modal=true, IGUIElement* parent=0, s32 id=-1) = 0;

	//! Adds a static text. 
	/* The returned pointer must not be dropped.
	 \param text is the text to be displayed. Can be altered after creation with SetText().
	 \param rectangle is the position of the static text.
	 \param border has to be set to true if the static text should have a 3d border.
	 \param wordWrap specifies, if the text should be wrapped into multiple lines.
	 \param parent is the parent item of the element. E.g. a window. Set it to 0 to place the fader directly in the environment.
	 \param id is a s32 to identify the static text element.
	 \param fillBackground specifies if the background will be filled. Default: false.
	 \return
	 Returns a pointer to the created static text. Returns 0 if an error occured.
	 This pointer should not be dropped. See IUnknown::drop() for more information. */
	virtual IGUIStaticText* addStaticText(const wchar_t* text, const core::rect<s32>& rectangle, 
		bool border=false, bool wordWrap=true, IGUIElement* parent=0, s32 id=-1, 
		bool fillBackground = false) = 0;

	//! Adds an edit box.  
	/*  Supports unicode input from every keyboard around the world,
	 scrolling, copying and pasting (exchanging data with the clipboard directly), maximum 
	 character amount, marking and all shortcuts like ctrl+X, ctrl+V, ctrg+C, 
	 shift+Left, shift+Right, Home, End, and so on. 
	 \param text is the text to be displayed. Can be altered after creation with SetText().
	 \param rectangle is the position of the edit box.
	 \param border has to be set to true if the edit box should have a 3d border.
	 \param parent is the parent item of the element. E.g. a window. Set it to 0 to place the edit box directly in the environment.
	 \param id is a s32 to identify the edit box.
	 \return
	 Returns a pointer to the created static text. Returns 0 if an error occured.
	 This pointer should not be dropped. See IUnknown::drop() for more information. */
	virtual IGUIEditBox* addEditBox(const wchar_t* text, const core::rect<s32>& rectangle, 
		bool border=true, IGUIElement* parent=0, s32 id=-1) = 0;

	//! Adds an element for fading in or out.
	/* \param rectangle: Pointer to rectangle specifing the borders of the element.
	 If the pointer is NULL, the whole screen is used.
	 \param parent: Parent item of the element. E.g. a window. Set it to 0 to place the static text directly in the environment.
	 \param id: A s32 to identify the text.
	 \return
	 Returns a pointer to the created in-out-fader. Returns 0 if an error occured.
	 This pointer should not be dropped. See IUnknown::drop() for more information. */
	virtual IGUIInOutFader* addInOutFader(const core::rect<s32>* rectangle=0, IGUIElement* parent=0, s32 id=-1) = 0;

	//! Adds a tab control to the environment.
	/* \param rectangle is the position of the tab control.
	 \param parent is the parent item of the element. E.g. a window. Set it to 0 to place the tab control directly in the environment.
	 \param fillbackground specifies if the background of the tab control should be drawn to.
	 \param border specifiys if a flat 3d border should be drawn.
	 This is usually not necesarry unless you don't place the control directly into the environment without a window as parent.
	 \param id is a s32 to identify the tab control.
	 \return
	 Returns a pointer to the created tab control element. Returns 0 if an error occured.
	 This pointer should not be dropped. See IUnknown::drop() for more information. */
	virtual IGUITabControl* addTabControl(const core::rect<s32>& rectangle,
		IGUIElement* parent=0, bool fillbackground=false,
		bool border=true, s32 id=-1) = 0;

	//! Adds tab to the environment. 
	/*  You can use this element to group other elements. This is not used for creating tabs on tab controls,
	 please use IGUITabControl::addTab() for this instead.
	 \param rectangle is the position of the tab.
	 \param parent is the parent item of the element. E.g. a window. Set it to 0 to place the tab directly in the environment.
	 \param id is a s32 to identify the tab. */
	virtual IGUITab* addTab(const core::rect<s32>& rectangle,
		IGUIElement* parent=0, s32 id=-1) = 0;

	//! Adds a context menu to the environment.
	/* \param rectangle is the position of the menu. Note that the menu is 
	 resizing itself based on what items you add.
	 \param parent is the parent item of the element. E.g. a window. Set it to 0 to place the menu directly in the environment.
	 \param id is a s32 to identify the menu. */
	virtual IGUIContextMenu* addContextMenu(const core::rect<s32>& rectangle,
		IGUIElement* parent=0, s32 id=-1) = 0;

	//! Adds a menu to the environment.
	/*  This is like the menu you can find on top of most windows in modern graphical user interfaces.
	 \param parent is the parent item of the element. E.g. a window. Set it to 0 to place the menu directly in the environment.
	 \param id is a s32 to identify the menu. */
	virtual IGUIContextMenu* addMenu(IGUIElement* parent=0, s32 id=-1) = 0;

	//! Adds a toolbar to the environment.
	/* It is like a menu is always placed on top
	 in its parent, and contains buttons.
	 \param parent is the parent item of the element. E.g. a window. Set it to 0 to place the tool bar directly in the environment.
	 \param id is a s32 to identify the tool bar. */
	virtual IGUIToolBar* addToolBar(IGUIElement* parent=0, s32 id=-1) = 0;

	//! Adds a combo box to the environment.
	/* \param parent is the parent item of the element. E.g. a window. Set it to 0 to place the combo box directly in the environment.
	 \param id is a s32 to identify the combo box. */
	virtual IGUIComboBox* addComboBox(const core::rect<s32>& rectangle,
		IGUIElement* parent=0, s32 id=-1) = 0;

	//! Returns the default element factory which can create all built in elements
	virtual IGUIElementFactory* getDefaultGUIElementFactory() = 0;

	//! Adds an element factory to the gui environment.
	/* Use this to extend the gui environment with new element types which it should be
	able to create automaticly, for example when loading data from xml files. */
	virtual void registerGUIElementFactory(IGUIElementFactory* factoryToAdd) = 0;

	//! Returns amount of registered scene node factories.
	virtual s32 getRegisteredGUIElementFactoryCount() = 0;

	//! Returns a scene node factory by index
	virtual IGUIElementFactory* getGUIElementFactory(s32 index) = 0;

	//! Adds a GUI Element by its name
	virtual IGUIElement* addGUIElement(const c8* elementName, IGUIElement* parent=0) = 0;

	//! Saves the current gui into a file.
	//! \param filename: Name of the file.
	virtual bool saveGUI(const c8* filename)=0;

	//! Saves the current gui into a file.
	virtual bool saveGUI(io::IWriteFile* file)=0;

	//! Loads the gui. Note that the current gui is not cleared before.
	//! \param filename: Name of the file .
	virtual bool loadGUI(const c8* filename)=0;

	//! Loads the gui. Note that the current gui is not cleared before.
	virtual bool loadGUI(io::IReadFile* file)=0;	

	//! Writes attributes of the gui environment
	virtual void serializeAttributes(io::IAttributes* out, io::SAttributeReadWriteOptions* options=0)=0;

	//! Reads attributes of the gui environment
	virtual void deserializeAttributes(io::IAttributes* in, io::SAttributeReadWriteOptions* options=0)=0;

	//! writes an element
	virtual void writeGUIElement(io::IXMLWriter* writer, IGUIElement* node) =0;

	//! reads an element
	virtual void readGUIElement(io::IXMLReader* reader, IGUIElement* parent) =0;

};


} // end namespace gui
} // end namespace irr

#endif


namespace irr
{
	struct SKeyMap;

namespace io
{
	class IFileSystem;
	class IReadFile;
	class IAttributes;
	class IWriteFile;
} // end namespace io

namespace gui
{
	class IGUIFont;
	class IGUIFontBitmap;
} // end namespace gui

namespace video
{
	class IVideoDriver;
} // end namespace video

namespace scene
{
	//! Enumeration for render passes.
	/* A parameter passed to the registerNodeForRendering() method of the ISceneManager,
	specifying when the mode wants to be drawn in relation to the other nodes. */
	enum E_SCENE_NODE_RENDER_PASS
	{
		//! Camera pass. The active view is set up here.
		//! The very first pass.
		ESNRP_CAMERA,

		//! In this pass, lights are transformed into camera space and added to the driver
		ESNRP_LIGHT,

		//! This is used for sky boxes.
		ESNRP_SKY_BOX,

		//! All normal objects can use this for registering themselves.
		//! This value will never be returned by ISceneManager::getSceneNodeRenderPass().
		//! The scene manager will determine by itself if an object is
		//! transparent or solid and register the object as SNRT_TRANSPARENT or
		//! SNRT_SOLD automaticly if you call registerNodeForRendering with this
		//! value (which is default). Note that it will register the node only as ONE type.
		//! If your scene node has both solid and transparent material types register
		//! it twice (one time as SNRT_SOLID, the other time as SNRT_TRANSPARENT) and
		//! in the render() method call getSceneNodeRenderPass() to find out the current
		//! render pass and render only the corresponding parts of the node.
		ESNRP_AUTOMATIC,

		//! Solid scene nodes or special scene nodes without materials.
		ESNRP_SOLID,

		//! Drawn after the transparent nodes, the time for drawing shadow volumes
		ESNRP_SHADOW,

		//! Transparent scene nodes, drawn after shadow nodes. They are sorted from back
		//! to front and drawn in that order.
		ESNRP_TRANSPARENT,

		//! Scene Nodes with special support
		ESNRP_SHADER_0,
		ESNRP_SHADER_1,
		ESNRP_SHADER_2,
		ESNRP_SHADER_3,
		ESNRP_SHADER_4,
		ESNRP_SHADER_5,
		ESNRP_SHADER_6,
		ESNRP_SHADER_7,
		ESNRP_SHADER_8,
		ESNRP_SHADER_9,
		ESNRP_SHADER_10,

		//! Never used, value specifing how much parameters there are.
		ESNRP_COUNT
	};

	class IMesh;
	class IMeshBuffer;
	class IAnimatedMesh;
	class IMeshCache;
	class ISceneNode;
	class ICameraSceneNode;
	class IAnimatedMeshSceneNode;
	class ISceneNodeAnimator;
	class ISceneNodeAnimatorCollisionResponse;
	class ILightSceneNode;
	class IBillboardSceneNode;
	class ITerrainSceneNode;
	class IMeshSceneNode;
	class IMeshLoader;
	class ISceneCollisionManager;
	class IParticleSystemSceneNode;
	class IDummyTransformationSceneNode;
	class ITriangleSelector;
	class IMetaTriangleSelector;
	class IMeshManipulator;
	class ITextSceneNode;
	class ISceneNodeFactory;
	class ISceneNodeAnimatorFactory;
	class ISceneUserDataSerializer;

	namespace quake3
	{
		class SShader;
	} // end namespace quake3

	//!	The Scene Manager manages scene nodes, mesh recources, cameras and all the other stuff.
	/* All Scene nodes can be created only here. There is a always growing list of scene
	nodes for lots of purposes: Indoor rendering scene nodes like the Octree
	(addOctTreeSceneNode()) or the terrain renderer (addTerrainSceneNode()),
	different Camera scene nodes (addCameraSceneNode(), addCameraSceneNodeMaya()),
	scene nodes for Light (addLightSceneNode()), Billboards (addBillboardSceneNode())
	and so on.
	A scene node is a node in the hierachical scene graph. Every scene node may have children,
	which are other scene nodes. Children move relative the their parents position. If the parent of a node is not
	visible, its children won't be visible, too. In this way, it is for example easily possible
	to attach a light to a moving car or to place a walking character on a moving platform
	on a moving ship.
	The SceneManager is also able to load 3d mesh files of different formats. Take a look
	at getMesh() to find out what formats are supported. And if these formats are not enough
	use addExternalMeshLoader() to add new formats to the engine.
	*/
	class ISceneManager : public virtual IUnknown
	{
	public:

		//! destructor
		virtual ~ISceneManager() {};

		//! Returns pointer to an animateable mesh. Loads the file if not loaded already.
		/**
		  If you want to remove a loaded mesh from the cache again, use removeMesh().
		   Currently there are the following mesh formats supported:
		   <TABLE border="1" cellpadding="2" cellspacing="0">
		   <TR>
		     <TD>Format</TD>
		     <TD>Description</TD>
		   </TR>
		   <TR>
		     <TD>3D Studio (.3ds)</TD>
		     <TD>Loader for 3D-Studio files which lots of 3D packages are able to export.
		       Only static meshes are currently supported by this importer. </TD>
		   </TR>
		   <TR>
		     <TD>Bliz Basic B3D (.b3d)</TD>
		     <TD>Loader for blitz basic files, developed by Mark Sibly, also supports animations.</TD>
		   </TR>
		   <TR>
		     <TD>Cartography shop 4 (.csm)</TD>
		     <TD>Cartography Shop is a modeling program for creating architecture and calculating
		       lighting. Irrlicht can directly import .csm files thanks to the IrrCSM library
		       created by Saurav Mohapatra which is now integrated directly in Irrlicht.
		       If you are using this loader, please note that you'll have to set the path
		       of the textures before loading .csm files. You can do this using SceneManager-&gt;getParameters()-&gt;setParameter(scene::CSM_TEXTURE_PATH,
		       &quot;path/to/your/textures&quot;);</TD>
		   </TR>
		   <TR>
		     <TD>COLLADA (.dae, .xml)</TD>
		     <TD>COLLADA is an open Digital Asset Exchange Schema for the interactive 3D industry. There are
		         exporters and importers for this format available for most of the big 3d packages
		         at http://collada.org. Irrlicht can import COLLADA files by using the
		         ISceneManager::getMesh() method. COLLADA files need not contain only one single mesh
		         but multiple meshes and a whole scene setup with lights, cameras and mesh instances,
		         this loader can set up a scene as described by the COLLADA file instead of loading
		         and returning one single mesh. By default, this loader behaves like the other loaders
		         and does not create instances, but it can be switched into this mode by using
		         SceneManager->getParameters()->setParameter(COLLADA_CREATE_SCENE_INSTANCES, true);
		         Created scene nodes will be named as the names of the nodes in the
		         COLLADA file. The returned mesh is just a dummy object in this mode. Meshes included in
		         the scene will be added into the scene manager with the following naming scheme:
		         path/to/file/file.dea#meshname. The loading of such meshes is logged.
		         Currently, this loader is able to create meshes (made of only polygons), lights,
		         and cameras. Materials and animations are currently not supported but this will
		         change with future releases.
		     </TD>
		   </TR>
		   <TR>
		     <TD>Delgine DeleD (.dmf)</TD>
		     <TD>DeleD (delgine.com) is a 3D editor and level-editor combined into one and is specifically
		         designed for 3D game-development. With this loader, it is possible to directly load
		         all geometry is as well as textures and lightmaps from .dmf files. To set texture and
		         material paths, see scene::DMF_USE_MATERIALS_DIRS and scene::DMF_TEXTURE_PATH. It is also
		         possible to flip the alpha texture by setting scene::DMF_FLIP_ALPHA_TEXTURES to true and
		         to set the material transparent reference value by setting scene::DMF_ALPHA_CHANNEL_REF to
		         a float between 0 and 1. The loader is
		         based on Salvatore Russo's .dmf loader, I just changed some parts of it. Thanks to
		         Salvatore for his work and for allowing me to use his code in Irrlicht and put it under Irrlicht's
		         license. For newer and more enchanced versions of the loader, take a look at delgine.com.
		     </TD>
		   </TR>
		   <TR>
		     <TD>DirectX (.x)</TD>
		     <TD>Platform independent importer (so not D3D-only) for .x files. Most 3D
		       packages can export these natively and there are several tools for them
		       available. (e.g. the Maya exporter included in the DX SDK) .x files can
		       include skeletal animations and Irrlicht is able to play and display them.
		       Currently, Irrlicht only supports uncompressed .x files.</TD>
		   </TR>
		   <TR>
		     <TD>Maya (.obj)</TD>
		     <TD>Most 3D software can create .obj files which contain static geometry without
		       material data. The material files .mtl are also supported. This importer
		       for Irrlicht can load them directly. </TD>
		   </TR>
		   <TR>
		     <TD>Milkshape (.ms3d)</TD>
		     <TD>.MS3D files contain models and sometimes skeletal animations from the
		       Milkshape 3D modeling and animation software. This importer for Irrlicht
		       can display and/or animate these files.  </TD>
		   </TR>
		   <TR>
		   <TD>My3D (.my3d)</TD>
		       <TD>.my3D is a flexible 3D file format. The My3DTools contains plug-ins to
		         export .my3D files from several 3D packages. With this built-in importer,
		         Irrlicht can read and display those files directly. This loader was written
		         by Zhuck Dimitry who also created the whole My3DTools package. If you are using this loader, please
		       note that you can set the path of the textures before loading .my3d files.
		       You can do this using SceneManager-&gt;getParameters()-&gt;setParameter(scene::MY3D_TEXTURE_PATH,
		       &quot;path/to/your/textures&quot;); </TD>
		     </TR>
		     <TR>
		       <TD>OCT (.oct)</TD>
		       <TD>The oct file format contains 3D geometry and lightmaps and can be loaded
		         directly by Irrlicht. OCT files<br>
		         can be created by FSRad, Paul Nette's radiosity processor or exported from
		         Blender using OCTTools which can be found in the exporters/OCTTools directory
		         of the SDK. Thanks to Murphy McCauley for creating all this.</TD>
		     </TR>
		 	  <TR>
		       <TD>OGRE Meshes (.mesh)</TD>
		       <TD>Ogre .mesh files contain 3D data for the OGRE 3D engine. Irrlicht can read and
		           display them directly with this importer. To define materials for the mesh,
		 			copy a .material file named like the corresponding .mesh file where the .mesh
		 			file is. (For example ogrehead.material for ogrehead.mesh). Thanks to Christian Stehno
		 			who wrote and contributed this loader.</TD>
		     </TR>
		     <TR>
		       <TD>Pulsar LMTools (.lmts)</TD>
		       <TD>LMTools is a set of tools (Windows &amp; Linux) for creating lightmaps.
		         Irrlicht can directly read .lmts files thanks to<br>
		         the importer created by Jonas Petersen. If you are using this loader, please
		         note that you can set the path of the textures before loading .lmts files.
		         You can do this using SceneManager-&gt;getParameters()-&gt;setParameter(scene::LMTS_TEXTURE_PATH,
		         &quot;path/to/your/textures&quot;); Notes for<br>
		         this version of the loader:<br>
		         - It does not recognice/support user data in the .lmts files.<br>
		         - The TGAs generated by LMTools don't work in Irrlicht for some reason (the
		         textures are upside down). Opening and resaving them in a graphics app will
		         solve the problem.</TD>
		     </TR>
		     <TR>
		       <TD>Quake 3 levels (.bsp)</TD>
		       <TD>Quake 3 is a popular game by IDSoftware, and .pk3 files contain .bsp files
		         and textures/lightmaps describing huge<br>
		         prelighted levels. Irrlicht can read .pk3 and .bsp files directly and thus
		         render Quake 3 levels directly. Written by Nikolaus Gebhardt enhanced by
		         Dean P. Macri with the curved surfaces feature. </TD>
		     </TR>
		     <TR>
		       <TD>Quake 2 models (.md2)</TD>
		       <TD>Quake 2 models are characters with morph target animation. Irrlicht can
		         read, display and animate them directly with this importer. </TD>
		     </TR>
		   </TABLE>
		 *
		   To load and display a mesh quickly, just do this:
		   \code
		   SceneManager->addAnimatedMeshSceneNode(
		 		SceneManager->getMesh("yourmesh.3ds"));
		   \endcode
		   If you would like to implement and add your own file format loader to Irrlicht,
		   see addExternalMeshLoader().
		   \param filename: Filename of the mesh to load.
		   \return Returns NULL if failed and the pointer to the mesh if
		   successful.
		   This pointer should not be dropped. See IUnknown::drop() for more information.
		 **/
		virtual IAnimatedMesh* getMesh(const c8* filename) = 0;

		//! Returns an interface to the mesh cache which is shared beween all existing scene managers.
		/* With this interface, it is possible to manually add new loaded
		meshes (if ISceneManager::getMesh() is not sufficient), to remove them and to iterate
		through already loaded meshes. */
		virtual IMeshCache* getMeshCache() = 0;

		//! Returns the video driver.
		/* \return Returns pointer to the video Driver.
		 This pointer should not be dropped. See IUnknown::drop() for more information. */
		virtual video::IVideoDriver* getVideoDriver() = 0;

		//! Returns the active GUIEnvironment
		/* \return Returns pointer to the GUIEnvironment
		 This pointer should not be dropped. See IUnknown::drop() for more information. */
		virtual gui::IGUIEnvironment* getGUIEnvironment() = 0;

		//! Adds a test scene node for test purposes to the scene.
		/* It is a simple cube of (1,1,1) size.
		\param size: Size of the cube.
		\param parent: Parent of the scene node. Can be NULL if no parent.
		\param id: Id of the node. This id can be used to identify the scene node.
		\param position: Position of the space relative to its parent where the
		 scene node will be placed.
		\param rotation: Initital rotation of the scene node.
		\param scale: Initial scale of the scene node.
		\return Returns pointer to the created test scene node.
	     This pointer should not be dropped. See IUnknown::drop() for more information. */
		virtual ISceneNode* addCubeSceneNode(f32 size=10.0f, ISceneNode* parent=0, s32 id=-1,
			const core::vector3df& position = core::vector3df(0,0,0),
			const core::vector3df& rotation = core::vector3df(0,0,0),
			const core::vector3df& scale = core::vector3df(1.0f, 1.0f, 1.0f)) = 0;

		//! Adds a sphere scene node for test purposes to the scene.
		/* It is a simple sphere.
		\param radius: Radius of the sphere.
		\param polyCount: Polycount of the sphere.
		\param parent: Parent of the scene node. Can be NULL if no parent.
		\param id: Id of the node. This id can be used to identify the scene node.
		\param position: Position of the space relative to its parent where the
		 scene node will be placed.
		\param rotation: Initital rotation of the scene node.
		\param scale: Initial scale of the scene node.
		\return Returns pointer to the created test scene node.
	     This pointer should not be dropped. See IUnknown::drop() for more information. */
		virtual ISceneNode* addSphereSceneNode(f32 radius=5.0f, s32 polyCount=16, ISceneNode* parent=0, s32 id=-1,
			const core::vector3df& position = core::vector3df(0,0,0),
			const core::vector3df& rotation = core::vector3df(0,0,0),
			const core::vector3df& scale = core::vector3df(1.0f, 1.0f, 1.0f)) = 0;

		//! Adds a scene node for rendering an animated mesh model.
		/* \param mesh: Pointer to the loaded animated mesh to be displayed.
		\param parent: Parent of the scene node. Can be NULL if no parent.
		\param id: Id of the node. This id can be used to identify the scene node.
		\param position: Position of the space relative to its parent where the
		scene node will be placed.
		\param rotation: Initital rotation of the scene node.
		\param scale: Initial scale of the scene node.
		\return Returns pointer to the created scene node.
		This pointer should not be dropped. See IUnknown::drop() for more information. */
		virtual IAnimatedMeshSceneNode* addAnimatedMeshSceneNode(IAnimatedMesh* mesh, ISceneNode* parent=0, s32 id=-1,
			const core::vector3df& position = core::vector3df(0,0,0),
			const core::vector3df& rotation = core::vector3df(0,0,0),
			const core::vector3df& scale = core::vector3df(1.0f, 1.0f, 1.0f),
			bool alsoAddIfMeshPointerZero=false) = 0;

		//! Adds a scene node for rendering a static mesh.
		/* \param mesh: Pointer to the loaded static mesh to be displayed.
		\param parent: Parent of the scene node. Can be NULL if no parent.
		\param id: Id of the node. This id can be used to identify the scene node.
		\param position: Position of the space relative to its parent where the
		scene node will be placed.
		\param rotation: Initital rotation of the scene node.
		\param scale: Initial scale of the scene node.
		\return Returns pointer to the created scene node.
		This pointer should not be dropped. See IUnknown::drop() for more information. */
		virtual IMeshSceneNode* addMeshSceneNode(IMesh* mesh, ISceneNode* parent=0, s32 id=-1,
			const core::vector3df& position = core::vector3df(0,0,0),
			const core::vector3df& rotation = core::vector3df(0,0,0),
			const core::vector3df& scale = core::vector3df(1.0f, 1.0f, 1.0f),
			bool alsoAddIfMeshPointerZero=false) = 0;

		//! Adds a scene node for rendering a animated water surface mesh.
		/* Looks really good when the Material type EMT_TRANSPARENT_REFLECTION
		 is used.
		 \param waveHeight: Height of the water waves.
		 \param waveSpeed: Speed of the water waves.
		 \param waveLength: Lenght of a water wave.
		 \param mesh: Pointer to the loaded static mesh to be displayed with water waves on it.
		 \param parent: Parent of the scene node. Can be NULL if no parent.
		 \param id: Id of the node. This id can be used to identify the scene node.
		 \param position: Position of the space relative to its parent where the
		 scene node will be placed.
		 \param rotation: Initital rotation of the scene node.
		 \param scale: Initial scale of the scene node.
		 \return Returns pointer to the created scene node.
		 This pointer should not be dropped. See IUnknown::drop() for more information. */
		virtual ISceneNode* addWaterSurfaceSceneNode(IMesh* mesh,
			f32 waveHeight=2.0f, f32 waveSpeed=300.0f, f32 waveLength=10.0f,
			ISceneNode* parent=0, s32 id=-1,
			const core::vector3df& position = core::vector3df(0,0,0),
			const core::vector3df& rotation = core::vector3df(0,0,0),
			const core::vector3df& scale = core::vector3df(1.0f, 1.0f, 1.0f)) = 0;


		 //! Adds a scene node for rendering using a octtree to the scene graph.
		 /* This a good method for rendering
		 scenes with lots of geometry. The Octree is built on the fly from the mesh.
		 \param mesh: The mesh containing all geometry from which the octtree will be build.
		 If this animated mesh has more than one frames in it, the first frame is taken.
		 \param parent: Parent node of the octtree node.
		 \param id: id of the node. This id can be used to identify the node.
		 \param minimalPolysPerNode: Specifies the minimal polygons contained a octree node.
		 If a node gets less polys the this value, it will not be splitted into
		 smaller nodes.
		 \return Returns the pointer to the octtree if successful, otherwise 0.
		 This pointer should not be dropped. See IUnknown::drop() for more information. */
		virtual ISceneNode* addOctTreeSceneNode(IAnimatedMesh* mesh, ISceneNode* parent=0,
			s32 id=-1, s32 minimalPolysPerNode=256, bool alsoAddIfMeshPointerZero=false) = 0;

		//! Adds a scene node for rendering using a octtree to the scene graph.
		/* This a good method for rendering
		 scenes with lots of geometry. The Octree is built on the fly from the mesh, much
		 faster then a bsp tree.
		 \param mesh: The mesh containing all geometry from which the octtree will be build.
		 \param parent: Parent node of the octtree node.
		 \param id: id of the node. This id can be used to identify the node.
		 \param minimalPolysPerNode: Specifies the minimal polygons contained a octree node.
		 If a node gets less polys the this value, it will not be splitted into
		 smaller nodes.
		 \return Returns the pointer to the octtree if successful, otherwise 0.
		 This pointer should not be dropped. See IUnknown::drop() for more information. */
		virtual ISceneNode* addOctTreeSceneNode(IMesh* mesh, ISceneNode* parent=0,
			s32 id=-1, s32 minimalPolysPerNode=256, bool alsoAddIfMeshPointerZero=false) = 0;

		//! Adds a camera scene node to the scene graph and sets it as active camera.
		/* This camera does not react on user input like for example the one created with
		addCameraSceneNodeFPS(). If you want to move or animate it, use animators or the
		ISceneNode::setPosition(), ICameraSceneNode::setTarget() etc methods.
		 \param position: Position of the space relative to its parent where the camera will be placed.
		 \param lookat: Position where the camera will look at. Also known as target.
		 \param parent: Parent scene node of the camera. Can be null. If the parent moves,
		 the camera will move too.
		 \param id: id of the camera. This id can be used to identify the camera.
		 \return Returns pointer to interface to camera if successful, otherwise 0.
		 This pointer should not be dropped. See IUnknown::drop() for more information. */
		virtual ICameraSceneNode* addCameraSceneNode(ISceneNode* parent = 0,
			const core::vector3df& position = core::vector3df(0,0,0),
			const core::vector3df& lookat = core::vector3df(0,0,100), s32 id=-1) = 0;

		//! Adds a maya style user controlled camera scene node to the scene graph.
		/* The maya camera is able to be controlled with the mouse similar
		 like in the 3D Software Maya by Alias Wavefront.
		 \param parent: Parent scene node of the camera. Can be null.
		 \param rotateSpeed: Rotation speed of the camera.
		 \param zoomSpeed: Zoom speed of the camera.
		 \param tranlationSpeed: TranslationSpeed of the camera.
		 \param id: id of the camera. This id can be used to identify the camera.
		 \return Returns a pointer to the interface of the camera if successful, otherwise 0.
		 This pointer should not be dropped. See IUnknown::drop() for more information. */
		virtual ICameraSceneNode* addCameraSceneNodeMaya(ISceneNode* parent = 0,
			f32 rotateSpeed = -1500.0f, f32 zoomSpeed = 200.0f, f32 translationSpeed = 1500.0f, s32 id=-1) = 0;

		//! Adds a camera scene node which is able to be controlled with the mouse and keys like in most first person shooters (FPS).
		/* Look with the mouse, move with cursor keys. If you do not like the default
		 key layout, you may want to specify your own. For example to make the camera
		 be controlled by the cursor keys AND the keys W,A,S, and D, do something
		 like this:
		 \code
		 SKeyMap keyMap[8];
		 keyMap[0].Action = EKA_MOVE_FORWARD;
		 keyMap[0].KeyCode = KEY_UP;
		 keyMap[1].Action = EKA_MOVE_FORWARD;
		 keyMap[1].KeyCode = KEY_KEY_W;

		 keyMap[2].Action = EKA_MOVE_BACKWARD;
		 keyMap[2].KeyCode = KEY_DOWN;
		 keyMap[3].Action = EKA_MOVE_BACKWARD;
		 keyMap[3].KeyCode = KEY_KEY_S;

		 keyMap[4].Action = EKA_STRAFE_LEFT;
		 keyMap[4].KeyCode = KEY_LEFT;
		 keyMap[5].Action = EKA_STRAFE_LEFT;
		 keyMap[5].KeyCode = KEY_KEY_A;

		 keyMap[6].Action = EKA_STRAFE_RIGHT;
		 keyMap[6].KeyCode = KEY_RIGHT;
		 keyMap[7].Action = EKA_STRAFE_RIGHT;
		 keyMap[7].KeyCode = KEY_KEY_D;

		 camera = sceneManager->addCameraSceneNodeFPS(0, 100, 500, -1, keyMap, 8);
		 \endcode
		 \param parent: Parent scene node of the camera. Can be null.
		 \param rotateSpeed: Speed with wich the camera is rotated. This can be done
		 only with the mouse.
		 \param movespeed: Speed with which the camera is moved. Movement is done with
		 the cursor keys.
		 \param id: id of the camera. This id can be used to identify the camera.
		 \param keyMapArray: Optional pointer to an array of a keymap, specifying what
		 keys should be used to move the camera. If this is null, the default keymap
		 is used. You can define actions more then one time in the array, to bind
		 multiple keys to the same action.
		 \param keyMapSize: Amount of items in the keymap array.
		 \param noVerticalMovement: Setting this to true makes the camera only move within a
		 horizontal plane, and disables vertical movement as known from most ego shooters. Default
		 is 'false', with which it is possible to fly around in space, if no gravity is there.
		 \return Returns a pointer to the interface of the camera if successful, otherwise 0.
		 This pointer should not be dropped. See IUnknown::drop() for more information. */
		virtual ICameraSceneNode* addCameraSceneNodeFPS(ISceneNode* parent = 0,
			f32 rotateSpeed = 100.0f, f32 moveSpeed = 500.0f, s32 id=-1,
			SKeyMap* keyMapArray=0, s32 keyMapSize=0, bool noVerticalMovement=false,
			f32 jumpSpeed = 0.f) = 0;

		//! Adds a dynamic light scene node to the scene graph.
		/* The light will cast dynamic light on all
		 other scene nodes in the scene, which have the material flag video::MTF_LIGHTING
		 turned on. (This is the default setting in most scene nodes).
		 \param parent: Parent scene node of the light. Can be null. If the parent moves,
		 the light will move too.
		 \param position: Position of the space relative to its parent where the light will be placed.
		 \param color: Diffuse color of the light. Ambient or Specular colors can be set manually with
		 the ILightSceneNode::getLightData() method.
		 \param radius: Radius of the light.
		 \param id: id of the node. This id can be used to identify the node.
		 \return Returns pointer to the interface of the light if successful, otherwise NULL.
		 This pointer should not be dropped. See IUnknown::drop() for more information. */
		virtual ILightSceneNode* addLightSceneNode(ISceneNode* parent = 0,
			const core::vector3df& position = core::vector3df(0,0,0),
			video::SColorf color = video::SColorf(1.0f, 1.0f, 1.0f),
			f32 radius=100.0f, s32 id=-1) = 0;

		//! Adds a billboard scene node to the scene graph.
		/* A billboard is like a 3d sprite: A 2d element,
		 which always looks to the camera. It is usually used for things like explosions, fire,
		 lensflares and things like that.
		 \param parent: Parent scene node of the billboard. Can be null. If the parent moves,
		 the billboard will move too.
		 \param position: Position of the space relative to its parent where the billboard will be placed.
		 \param size: Size of the billboard. This size is 2 dimensional because a billboard only has
		 width and height.
		 \param id: An id of the node. This id can be used to identify the node.
		 \param shade_top: vertex color top
		 \param shade_down: vertex color down
		 \return Returns pointer to the billboard if successful, otherwise NULL.
		 This pointer should not be dropped. See IUnknown::drop() for more information. */
		virtual IBillboardSceneNode* addBillboardSceneNode(ISceneNode* parent = 0,
			const core::dimension2d<f32>& size = core::dimension2d<f32>(10.0f, 10.0f),
			const core::vector3df& position = core::vector3df(0,0,0), s32 id=-1,
			video::SColor shade_top = 0xFFFFFFFF, video::SColor shade_down = 0xFFFFFFFF) = 0;

		//! Adds a skybox scene node to the scene graph.
		/* A skybox is a big cube with 6 textures on it and
		 is drawn around the camera position.
		 \param top: Texture for the top plane of the box.
		 \param bottom: Texture for the bottom plane of the box.
		 \param left: Texture for the left plane of the box.
		 \param right: Texture for the right plane of the box.
		 \param front: Texture for the front plane of the box.
		 \param back: Texture for the back plane of the box.
		 \param parent: Parent scene node of the skybox. A skybox usually has no parent,
		 so this should be null. Note: If a parent is set to the skybox, the box will not
		 change how it is drawn.
		 \param id: An id of the node. This id can be used to identify the node.
		 \return Returns a pointer to the sky box if successful, otherwise NULL.
		 This pointer should not be dropped. See IUnknown::drop() for more information. */
		virtual ISceneNode* addSkyBoxSceneNode(video::ITexture* top, video::ITexture* bottom,
			video::ITexture* left, video::ITexture* right, video::ITexture* front,
			video::ITexture* back, ISceneNode* parent = 0, s32 id=-1) = 0;

		//! Adds a skydome scene node to the scene graph.
		/* A skydome is a large (half-) sphere with a panoramic texture
		 on the inside and is drawn around the camera position.
		 \param texture: Texture for the dome.
		 \param horiRes: Number of vertices of a horizontal layer of the sphere.
		 \param vertRes: Number of vertices of a vertical layer of the sphere.
		 \param texturePercentage: How much of the height of the texture is used. Should be between 0 and 1.
		 \param spherePercentage: How much of the sphere is drawn. Value should be between 0 and 2, where 1 is an exact half-sphere and 2 is a full sphere.
		 \param parent: Parent scene node of the dome. A dome usually has no parent,
		 so this should be null. Note: If a parent is set, the dome will not
		 change how it is drawn.
		 \param id: An id of the node. This id can be used to identify the node.
		 \return Returns a pointer to the sky dome if successful, otherwise NULL.
		 This pointer should not be dropped. See IUnknown::drop() for more information. */
		virtual ISceneNode* addSkyDomeSceneNode(video::ITexture* texture,
			u32 horiRes, u32 vertRes, f64 texturePercentage, f64 spherePercentage,
			ISceneNode* parent = 0, s32 id=-1) = 0;

		//! Adds a particle system scene node to the scene graph.
		/* \param withDefaultEmitter: Creates a default working point emitter
		 which emitts some particles. Set this to true to see a particle system
		 in action. If set to false, you'll have to set the emitter you want by
		 calling IParticleSystemSceneNode::setEmitter().
		 \param parent: Parent of the scene node. Can be NULL if no parent.
		 \param id: Id of the node. This id can be used to identify the scene node.
		 \param position: Position of the space relative to its parent where the
		 scene node will be placed.
		 \param rotation: Initital rotation of the scene node.
		 \param scale: Initial scale of the scene node.
		 \return Returns pointer to the created scene node.
		 This pointer should not be dropped. See IUnknown::drop() for more information. */
		virtual IParticleSystemSceneNode* addParticleSystemSceneNode(
			bool withDefaultEmitter=true, ISceneNode* parent=0, s32 id=-1,
			const core::vector3df& position = core::vector3df(0,0,0),
			const core::vector3df& rotation = core::vector3df(0,0,0),
			const core::vector3df& scale = core::vector3df(1.0f, 1.0f, 1.0f)) = 0;

		//! Adds a terrain scene node to the scene graph.
		/* This node
		 implements is a simple terrain renderer which uses
		 a technique known as geo mip mapping
		 for reducing the detail of triangle blocks which are far away.
		 The code for the TerrainSceneNode is based on the terrain renderer by Soconne and
	     the GeoMipMapSceneNode developed by Spintz. They made their code available for Irrlicht
	     and allowed it to be  distributed under this licence. I only modified some parts.
	     A lot of thanks go to them.

		 This scene node is capable of very quickly loading
		 terrains and updating the indices at runtime to enable viewing very large terrains.  It uses a
		 CLOD (Continuous Level of Detail) algorithm which updates the indices for each patch based on
		 a LOD (Level of Detail) which is determined based on a patch's distance from the camera.

		 The patch size of the terrain must always be a size of ( 2^N+1, i.e. 8+1(9), 16+1(17), etc. ).
		 The MaxLOD available is directly dependent on the patch size of the terrain.  LOD 0 contains all
		 of the indices to draw all the triangles at the max detail for a patch.  As each LOD goes up by 1
		 the step taken, in generating indices increases by - 2^LOD, so for LOD 1, the step taken is 2, for
		 LOD 2, the step taken is 4, LOD 3 - 8, etc.  The step can be no larger than the size of the patch,
		 so having a LOD of 8, with a patch size of 17, is asking the algoritm to generate indices every
		 2^8 ( 256 ) vertices, which is not possible with a patch size of 17.  The maximum LOD for a patch
		 size of 17 is 2^4 ( 16 ).  So, with a MaxLOD of 5, you'll have LOD 0 ( full detail ), LOD 1 ( every
		 2 vertices ), LOD 2 ( every 4 vertices ), LOD 3 ( every 8 vertices ) and LOD 4 ( every 16 vertices ).
		 \param heightMapFile: The location of the file on disk, to read vertex data from. This should
		 be a gray scale bitmap.
		 \param position: The absolute position of this node.
		 \param rotation: The absolute rotation of this node. ( NOT YET IMPLEMENTED )
		 \param scale: The scale factor for the terrain.  If you're using a heightmap of size 128x128 and would like
		 your terrain to be 12800x12800 in game units, then use a scale factor of ( core::vector ( 100.0f, 100.0f, 100.0f ).
		 If you use a Y scaling factor of 0.0f, then your terrain will be flat.
		 \param vertexColor: The default color of all the vertices. If no texture is associated
		 with the scene node, then all vertices will be this color. Defaults to white.
		 \param maxLOD: The maximum LOD (level of detail) for the node. Only change if you
		 know what you are doing, this might lead to strange behaviour.
		 \param patchSize: patch size of the terrain. Only change if you
		 know what you are doing, this might lead to strange behaviour.
		 \return Returns pointer to the created scene node. Can be null if the
		 terrain could not be created, for example because the heightmap could not be loaded.
		 The returned pointer should not be dropped. See IUnknown::drop() for more information. */
		virtual ITerrainSceneNode* addTerrainSceneNode(
				const c8* heightMapFileName,
				ISceneNode* parent=0, s32 id=-1,
			const core::vector3df& position = core::vector3df(0.0f,0.0f,0.0f),
			const core::vector3df& rotation = core::vector3df(0.0f,0.0f,0.0f),
			const core::vector3df& scale = core::vector3df(1.0f,1.0f,1.0f),
			video::SColor vertexColor = video::SColor(255,255,255,255),
			s32 maxLOD=5, E_TERRAIN_PATCH_SIZE patchSize=ETPS_17, s32 smoothFactor=0) = 0;

		//! Adds a terrain scene node to the scene graph.
		/* Just like the other addTerrainSceneNode() method, but takes an IReadFile
		 pointer as parameter for the heightmap. For more informations take a look
		 add the other overload. */
		virtual ITerrainSceneNode* addTerrainSceneNode(
			io::IReadFile* heightMapFile,
			ISceneNode* parent=0, s32 id=-1,
			const core::vector3df& position = core::vector3df(0.0f,0.0f,0.0f),
			const core::vector3df& rotation = core::vector3df(0.0f,0.0f,0.0f),
			const core::vector3df& scale = core::vector3df(1.0f,1.0f,1.0f),
			video::SColor vertexColor = video::SColor(255,255,255,255),
			s32 maxLOD=5, E_TERRAIN_PATCH_SIZE patchSize=ETPS_17, s32 smoothFactor=0) = 0;

		//! Adds a quake3 scene node to the scene graph.
		/* A Quake3 Scene renders multiple meshes for a specific HighLanguage Shader (Quake3 Style )
		 \return Returns a pointer to the quake3 scene node if successful, otherwise NULL.
		 This pointer should not be dropped. See IUnknown::drop() for more information. */
		virtual ISceneNode* addQuake3SceneNode(IMeshBuffer* meshBuffer, const quake3::SShader * shader,
												ISceneNode* parent=0, s32 id=-1
												) = 0;


		//! Adds an empty scene node to the scene graph.
		/* Can be used for doing advanced transformations
		 or structuring the scene graph.
		 \return Returns pointer to the created scene node.
		 This pointer should not be dropped. See IUnknown::drop() for more information. */
		virtual ISceneNode* addEmptySceneNode(ISceneNode* parent=0, s32 id=-1) = 0;

		//! Adds a dummy transformation scene node to the scene graph.
		/* This scene node does not render itself, and does not respond to set/getPosition,
		 set/getRotation and set/getScale. Its just a simple scene node that takes a
		 matrix as relative transformation, making it possible to insert any transformation
		 anywhere into the scene graph.
		 \return Returns pointer to the created scene node.
		 This pointer should not be dropped. See IUnknown::drop() for more information. */
		virtual IDummyTransformationSceneNode* addDummyTransformationSceneNode(
			ISceneNode* parent=0, s32 id=-1) = 0;

		//! Adds a text scene node, which is able to display  2d text at a position in three dimensional space
		virtual ITextSceneNode* addTextSceneNode(gui::IGUIFont* font, const wchar_t* text,
			video::SColor color=video::SColor(100,255,255,255),
			ISceneNode* parent = 0,	const core::vector3df& position = core::vector3df(0,0,0),
			s32 id=-1) = 0;

		//! Adds a text scene node, which uses billboards
		virtual ITextSceneNode* addBillboardTextSceneNode( gui::IGUIFont* font, const wchar_t* text,
			ISceneNode* parent = 0,
			const core::dimension2d<f32>& size = core::dimension2d<f32>(10.0f, 10.0f),
			const core::vector3df& position = core::vector3df(0,0,0), s32 id=-1,
			video::SColor shade_top = 0xFFFFFFFF, video::SColor shade_down = 0xFFFFFFFF) = 0;

		//! Adds a Hill Plane mesh to the mesh pool.
		/* The mesh is generated on the fly
		 and looks like a plane with some hills on it. It is uses mostly for quick
		 tests of the engine only. You can specify how many hills there should be
		 on the plane and how high they should be. Also you must specify a name for
		 the mesh, because the mesh is added to the mesh pool, and can be retieved
		 again using ISceneManager::getMesh() with the name as parameter.
		 \param name: The name of this mesh which must be specified in order
		 to be able to retrieve the mesh later with ISceneManager::getMesh().
		 \param tileSize: Size of a tile of the mesh. (10.0f, 10.0f) would be a
		 good value to start, for example.
		 \param tileCount: Specifies how much tiles there will be. If you specifiy
		 for example that a tile has the size (10.0f, 10.0f) and the tileCount is
		 (10,10), than you get a field of 100 tiles wich has the dimension 100.0fx100.0f.
		 \param material: Material of the hill mesh.
		 \param hillHeight: Height of the hills. If you specify a negative value
		 you will get holes instead of hills. If the height is 0, no hills will be
		 created.
		 \param countHills: Amount of hills on the plane. There will be countHills.X
		 hills along the X axis and countHills.Y along the Y axis. So in total there
		 will be countHills.X  countHills.Y hills.
		 \param textureRepeatCount: Defines how often the texture will be repeated in
		 x and y direction.
		\return Returns null if the creation failed. The reason could be that you
		 specified some invalid parameters or that a mesh with that name already
		 exists. If successful, a pointer to the mesh is returned.
		 This pointer should not be dropped. See IUnknown::drop() for more information. */
		virtual IAnimatedMesh* addHillPlaneMesh(const c8* name,
			const core::dimension2d<f32>& tileSize, const core::dimension2d<s32>& tileCount,
			video::SMaterial* material = 0,	f32 hillHeight = 0.0f,
			const core::dimension2d<f32>& countHills = core::dimension2d<f32>(0.0f, 0.0f),
			const core::dimension2d<f32>& textureRepeatCount = core::dimension2d<f32>(1.0f, 1.0f)) = 0;

		 //! Adds a static terrain mesh to the mesh pool.
		 /* The mesh is generated on the fly
		 from a texture file and a height map file. Both files may be huge
		 (8000x8000 pixels would be no problem) because the generator splits the
		 files into smaller textures if necessary.
		 You must specify a name for the mesh, because the mesh is added to the mesh pool,
		 and can be retieved again using ISceneManager::getMesh() with the name as parameter.
		 \param meshname: The name of this mesh which must be specified in order
		 to be able to retrieve the mesh later with ISceneManager::getMesh().
		 \param texture: Texture for the terrain. Please note that this is not a
		 hardware texture as usual (ITexture), but an IImage software texture.
		 You can load this texture with IVideoDriver::createImageFromFile().
		 \param heightmap: A grayscaled heightmap image. Like the texture,
		 it can be created with IVideoDriver::createImageFromFile(). The amount
		 of triangles created depends on the size of this texture, so use a small
		 heightmap to increase rendering speed.
		 \param stretchSize: Parameter defining how big a is pixel on the heightmap.
		 \param maxHeight: Defines how height a white pixel on the heighmap is.
		 \return Returns null if the creation failed. The reason could be that you
		 specified some invalid parameters, that a mesh with that name already
		 exists, or that a texture could not be found. If successful, a pointer to the mesh is returned.
		 This pointer should not be dropped. See IUnknown::drop() for more information. */
		virtual IAnimatedMesh* addTerrainMesh(const c8* meshname,
			video::IImage* texture, video::IImage* heightmap,
			const core::dimension2d<f32>& stretchSize = core::dimension2d<f32>(10.0f,10.0f),
			f32 maxHeight=200.0f,
			const core::dimension2d<s32>& defaultVertexBlockSize = core::dimension2d<s32>(64,64)) = 0;

		//! add a static arrow mesh to the meshpool
		/* it quite usefull for debuggin purposes. ( showing directions eq )
		*/
		virtual IAnimatedMesh* addArrowMesh(const c8* name, u32 tesselationCylinder, u32 tesselationCone, f32 height,
											f32 cylinderHeight, f32 width0,f32 width1,
											video::SColor vtxColor0, video::SColor vtxColor1) = 0;

		//! Returns the root scene node.
		/* This is the scene node wich is parent
		 of all scene nodes. The root scene node is a special scene node which
		 only exists to manage all scene nodes. It will not be rendered and cannot
		 be removed from the scene.
		 \return Returns a pointer to the root scene node. */
		virtual ISceneNode* getRootSceneNode() = 0;

		//! Returns the first scene node with the specified id.
		/* \param id: The id to search for
		 \param start: Scene node to start from. All children of this scene
		 node are searched. If null is specified, the root scene node is
		 taken.
		 \return Returns pointer to the first scene node with this id,
		 and null if no scene node could be found. */
		virtual ISceneNode* getSceneNodeFromId(s32 id, ISceneNode* start=0) = 0;

		//! Returns the first scene node with the specified name.
		/*\param start: Scene node to start from. All children of this scene
		 node are searched. If null is specified, the root scene node is
		 taken.
		 \return Returns pointer to the first scene node with this id,
		 and null if no scene node could be found. */
		virtual ISceneNode* getSceneNodeFromName(const c8* name, ISceneNode* start=0) = 0;

		//! Returns the current active camera.
		/* \return The active camera is returned. Note that this can be NULL, if there
		 was no camera created yet. */
		virtual ICameraSceneNode* getActiveCamera() = 0;

		//! Sets the currently active camera.
		/* The previous active camera will be deactivated.
		 \param camera: The new camera which should be active. */
		virtual void setActiveCamera(ICameraSceneNode* camera) = 0;

		//! Sets the color of stencil buffers shadows drawn by the scene manager.
		virtual void setShadowColor(video::SColor color = video::SColor(150,0,0,0)) = 0;

		//! Returns the current color of shadows.
		virtual video::SColor getShadowColor() const = 0;

		//! Registers a node for rendering it at a specific time.
		/* This method should only be used by SceneNodes when they get a
		 ISceneNode::OnRegisterSceneNode() call.
		 \param node: Node to register for drawing. Usually scene nodes would set 'this'
		 as parameter here because they want to be drawn.
		 \param pass: Specifies when the mode wants to be drawn in relation to the other nodes.
		 For example, if the node is a shadow, it usually wants to be drawn after all other nodes
		 and will use ESNRP_SHADOW for this. See E_SCENE_NODE_RENDER_PASS for details.
		 \return scene will be rendered ( passed culling ) */
		virtual u32 registerNodeForRendering(ISceneNode* node,
			E_SCENE_NODE_RENDER_PASS pass = ESNRP_AUTOMATIC) = 0;

		//! Draws all the scene nodes.
		/* This can only be invoked between
		 IVideoDriver::beginScene() and IVideoDriver::endScene(). Please note that
		 the scene is not only drawn when calling this, but also animated
		 by existing scene node animators, culling of scene nodes is done, etc. */
		virtual void drawAll() = 0;

		//! Creates a rotation animator, which rotates the attached scene node around itself.
		/* \param rotationPerSecond: Specifies the speed of the animation
		 \return Returns the animator. Attach it to a scene node with ISceneNode::addAnimator()
		 and the animator will animate it.
		 If you no longer need the animator, you should call ISceneNodeAnimator::drop().
		 See IUnknown::drop() for more information. */
		virtual ISceneNodeAnimator* createRotationAnimator(const core::vector3df& rotationPerSecond) = 0;

		//! Creates a fly circle animator, which lets the attached scene node fly  around a center.
		/* \param center: Center of the circle.
		 \param radius: Radius of the circle.
		 \param speed: Specifies the speed of the flight.
		 \return Returns the animator. Attach it to a scene node with ISceneNode::addAnimator()
		 and the animator will animate it.
		 If you no longer need the animator, you should call ISceneNodeAnimator::drop().
		 See IUnknown::drop() for more information. */
		virtual ISceneNodeAnimator* createFlyCircleAnimator(const core::vector3df& center,
			f32 radius, f32 speed=0.001f, const core::vector3df& direction= core::vector3df ( 0.f, 1.f, 0.f ) ) = 0;

		//! Creates a fly straight animator, which lets the attached scene node fly or move along a line between two points.
		/* \param startPoint: Start point of the line.
		 \param endPoint: End point of the line.
		 \param timeForWay: Time in milli seconds how long the node should need to
		 move from the start point to the end point.
		 \param loop: If set to false, the node stops when the end point is reached.
		 If loop is true, the node begins again at the start.
		 \return Returns the animator. Attach it to a scene node with ISceneNode::addAnimator()
		 and the animator will animate it.
		 If you no longer need the animator, you should call ISceneNodeAnimator::drop().
		 See IUnknown::drop() for more information. */
		virtual ISceneNodeAnimator* createFlyStraightAnimator(const core::vector3df& startPoint,
			const core::vector3df& endPoint, u32 timeForWay, bool loop=false) = 0;

		//! Creates a texture animator, which switches the textures of the target scene	 node based on a list of textures.
		/* \param textures: List of textures to use.
		 \param timePerFrame: Time in milliseconds, how long any texture in the list
		 should be visible.
		 \param loop: If set to to false, the last texture remains set, and the animation
		 stops. If set to true, the animation restarts with the first texture.
		 \return Returns the animator. Attach it to a scene node with ISceneNode::addAnimator()
		 and the animator will animate it.
		 If you no longer need the animator, you should call ISceneNodeAnimator::drop().
		 See IUnknown::drop() for more information. */
		virtual ISceneNodeAnimator* createTextureAnimator(const core::array<video::ITexture*>& textures,
			s32 timePerFrame, bool loop=true) = 0;

		//! Creates a scene node animator, which deletes the scene node after some time automatically.
		/* \param timeMs: Time in milliseconds, after when the node will be deleted.
		 \return Returns the animator. Attach it to a scene node with ISceneNode::addAnimator()
		 and the animator will animate it.
		 If you no longer need the animator, you should call ISceneNodeAnimator::drop().
		 See IUnknown::drop() for more information. */
		virtual ISceneNodeAnimator* createDeleteAnimator(u32 timeMs) = 0;

		//! Creates a special scene node animator for doing automatic collision detection and response.
		/* See ISceneNodeAnimatorCollisionResponse for details.
		 \param world: Triangle selector holding all triangles of the world with which
		 the scene node may collide. You can create a triangle selector with
		 ISceneManager::createTriangleSelector();
		 \param sceneNode: SceneNode which should be manipulated. After you added this animator
		 to the scene node, the scene node will not be able to move through walls and is
		 affected by gravity.
		 \param ellipsoidRadius: Radius of the ellipsoid with which collision detection and
		 response is done.  If you have got a scene node, and you are unsure about
		 how big the radius should be, you could use the following code to determine
		 it:
		 \code
		 core::aabbox<f32> box = yourSceneNode->getBoundingBox();
		 core::vector3df radius = box.MaxEdge - box.getCenter();
		 \endcode
		 \param gravityPerSecond: Sets the gravity of the environment. A good example value would be
		 core::vector3df(0,-100.0f,0) for letting gravity affect all object to
		 fall down. For bigger gravity, make increase the length of the vector.
		 You can disable gravity by setting it to core::vector3df(0,0,0).
		 \param ellipsoidTranslation: By default, the ellipsoid for collision detection is created around
		 the center of the scene node, which means that the ellipsoid surrounds
		 it completely. If this is not what you want, you may specify a translation
		 for the ellipsoid.
		 \param slidingValue: DOCUMENTATION NEEDED.
		 \return Returns the animator. Attach it to a scene node with ISceneNode::addAnimator()
		 and the animator will cause it to do collision detection and response.
		 If you no longer need the animator, you should call ISceneNodeAnimator::drop().
		 See IUnknown::drop() for more information. */
		virtual ISceneNodeAnimatorCollisionResponse* createCollisionResponseAnimator(
			ITriangleSelector* world, ISceneNode* sceneNode,
			const core::vector3df& ellipsoidRadius = core::vector3df(30,60,30),
			const core::vector3df& gravityPerSecond = core::vector3df(0,-100.0f,0),
			const core::vector3df& ellipsoidTranslation = core::vector3df(0,0,0),
			f32 slidingValue = 0.0005f) = 0;

		//! Creates a follow spline animator.
		/* The animator modifies the position of
		 the attached scene node to make it follow a hermite spline.
		 The code of the is based on a scene node
		 Matthias Gall sent in. Thanks! I adapted the code just a little bit. Matthias
		 wrote:
		 Uses a subset of hermite splines: either cardinal splines (tightness != 0.5) or catmull-rom-splines (tightness == 0.5)
		 but this is just my understanding of this stuff, I'm not a mathematician, so this might be wrong ;) */
		virtual ISceneNodeAnimator* createFollowSplineAnimator(s32 startTime,
			const core::array< core::vector3df >& points,
			f32 speed = 1.0f, f32 tightness = 0.5f) = 0;

		//! Creates a simple ITriangleSelector, based on a mesh.
		/* Triangle selectors
		 can be used for doing collision detection. Don't use this selector
		 for a huge amount of triangles like in Quake3 maps.
		 Instead, use for example ISceneManager::createOctTreeTriangleSelector().
		 Please note that the created triangle selector is not automaticly attached
		 to the scene node. You will have to call ISceneNode::setTriangleSelector()
		 for this. To create and attach a triangle selector is done like this:
		 \code
		 ITriangleSelector s = sceneManager->createTriangleSelector(yourMesh,
				yourSceneNode);
		 yourSceneNode->setTriangleSelector(s);
		 s->drop();
		 \endcode
		 \param mesh: Mesh of which the triangles are taken.
		 \param node: Scene node of which visibility and transformation is used.
		 \return Returns the selector, or null if not successful.
		 If you no longer need the selector, you should call ITriangleSelector::drop().
		 See IUnknown::drop() for more information. */
		virtual ITriangleSelector* createTriangleSelector(IMesh* mesh, ISceneNode* node) = 0;

		//! Creates a simple dynamic ITriangleSelector, based on a axis aligned bounding box.
		/* Triangle selectors
		 can be used for doing collision detection. Every time when triangles are
		 queried, the triangle selector gets the bounding box of the scene node,
		 an creates new triangles. In this way, it works good with animated scene nodes.
		 \param node: Scene node of which the bounding box, visibility and transformation is used.
		 \return Returns the selector, or null if not successful.
		 If you no longer need the selector, you should call ITriangleSelector::drop().
		 See IUnknown::drop() for more information. */
		virtual ITriangleSelector* createTriangleSelectorFromBoundingBox(ISceneNode* node) = 0;

		//! Creates a Triangle Selector, optimized by an octtree.
		/* Triangle selectors
		 can be used for doing collision detection. This triangle selector is
		 optimized for huge amounts of triangle, it organizes them in an octtree.
		 Please note that the created triangle selector is not automaticly attached
		 to the scene node. You will have to call ISceneNode::setTriangleSelector()
		 for this. To create and attach a triangle selector is done like this:
		 \code
		 ITriangleSelector s = sceneManager->createOctTreeTriangleSelector(yourMesh,
				yourSceneNode);
		 yourSceneNode->setTriangleSelector(s);
		 s->drop();
		 \endcode
		 For more informations and examples on this, take a look at the collision
		 tutorial in the SDK.
		 \param mesh: Mesh of which the triangles are taken.
		 \param node: Scene node of which visibility and transformation is used.
		 \param minimalPolysPerNode: Specifies the minimal polygons contained a octree node.
		 If a node gets less polys the this value, it will not be splitted into
		 smaller nodes.
		 \return Returns the selector, or null if not successful.
		 If you no longer need the selector, you should call ITriangleSelector::drop().
		 See IUnknown::drop() for more information. */
		virtual ITriangleSelector* createOctTreeTriangleSelector(IMesh* mesh,
			ISceneNode* node, s32 minimalPolysPerNode=32) = 0;

		//! Creates a meta triangle selector.
		/* A meta triangle selector is nothing more than a
		 collection of one or more triangle selectors providing together
		 the interface of one triangle selector. In this way,
		 collision tests can be done with different triangle soups in one pass.
		 \return Returns the selector, or null if not successful.
		 If you no longer need the selector, you should call ITriangleSelector::drop().
		 See IUnknown::drop() for more information. */
		virtual IMetaTriangleSelector* createMetaTriangleSelector() = 0;

		//! Creates a triangle selector which can select triangles from a terrain scene node.
		/* \param: Pointer to the created terrain scene node
		 \param: Level of detail, 0 for highest detail. */
		virtual ITriangleSelector* createTerrainTriangleSelector(
			ITerrainSceneNode* node, s32 LOD=0) = 0;

		//! Adds an external mesh loader for extending the engine with new file formats.
		/* If you want the engine to be extended with
		 file formats it currently is not able to load (e.g. .cob), just implement
		 the IMeshLoader interface in your loading class and add it with this method.
		 Using this method it is also possible to override built-in mesh loaders with
		 newer or updated versions without the need of recompiling the engine.
		 \param externalLoader: Implementation of a new mesh loader. */
		virtual void addExternalMeshLoader(IMeshLoader* externalLoader) = 0;

		//! Returns a pointer to the scene collision manager.
		virtual ISceneCollisionManager* getSceneCollisionManager() = 0;

		//! Returns a pointer to the mesh manipulator.
		virtual IMeshManipulator* getMeshManipulator() = 0;

		//! Adds a scene node to the deletion queue.
		/* The scene node is immediatly
		 deleted when it's secure. Which means when the scene node does not
		 execute animators and things like that. This method is for example
		 used for deleting scene nodes by their scene node animators. In
		 most other cases, a ISceneNode::remove() call is enough, using this
		 deletion queue is not necessary.
		 See ISceneManager::createDeleteAnimator() for details.
		 \param node: Node to detete. */
		virtual void addToDeletionQueue(ISceneNode* node) = 0;

		//! Posts an input event to the environment.
		/* Usually you do not have to
		 use this method, it is used by the internal engine. */
		virtual bool postEventFromUser(SEvent event) = 0;

		//! Clears the whole scene.
		/* All scene nodes are removed. */
		virtual void clear() = 0;

		//! Returns interface to the parameters set in this scene.
		/* String parameters can be used by plugins and mesh loaders.
		 For example the CMS and LMTS loader want a parameter named 'CSM_TexturePath'
		 and 'LMTS_TexturePath' set to the path were attached textures can be found. See
		 CSM_TEXTURE_PATH, LMTS_TEXTURE_PATH, MY3D_TEXTURE_PATH,
		 COLLADA_CREATE_SCENE_INSTANCES, DMF_TEXTURE_PATH and DMF_USE_MATERIALS_DIRS*/
		virtual io::IAttributes* getParameters() = 0;

		//! Returns current render pass.
		/* All scene nodes are being rendered in a specific order.
		 First lights, cameras, sky boxes, solid geometry, and then transparent
		 stuff. During the rendering process, scene nodes may want to know what the scene
		 manager is rendering currently, because for example they registered for rendering
		 twice, once for transparent geometry and once for solid. When knowing what rendering
		 pass currently is active they can render the correct part of their geometry. */
		virtual E_SCENE_NODE_RENDER_PASS getSceneNodeRenderPass() = 0;

		//! Returns the default scene node factory which can create all built in scene nodes
		virtual ISceneNodeFactory* getDefaultSceneNodeFactory() = 0;

		//! Adds a scene node factory to the scene manager.
		/* Use this to extend the scene manager with new scene node types which it should be
		able to create automaticly, for example when loading data from xml files. */
		virtual void registerSceneNodeFactory(ISceneNodeFactory* factoryToAdd) = 0;

		//! Returns amount of registered scene node factories.
		virtual s32 getRegisteredSceneNodeFactoryCount() = 0;

		//! Returns a scene node factory by index
		virtual ISceneNodeFactory* getSceneNodeFactory(s32 index) = 0;

		//! Returns the default scene node animator factory which can create all built-in scene node animators
		virtual ISceneNodeAnimatorFactory* getDefaultSceneNodeAnimatorFactory() = 0;

		//! Adds a scene node animator factory to the scene manager.
		/* Use this to extend the scene manager with new scene node animator types which it should be
		able to create automaticly, for example when loading data from xml files. */
		virtual void registerSceneNodeAnimatorFactory(ISceneNodeAnimatorFactory* factoryToAdd) = 0;

		//! Returns amount of registered scene node animator factories.
		virtual s32 getRegisteredSceneNodeAnimatorFactoryCount() = 0;

		//! Returns a scene node animator factory by index
		virtual ISceneNodeAnimatorFactory* getSceneNodeAnimatorFactory(s32 index) = 0;

		//! Returns a typename from a scene node type or null if not found
		virtual const c8* getSceneNodeTypeName(ESCENE_NODE_TYPE type) = 0;

		//! Creates a new scene manager.
		/* This can be used to easily draw and/or store two independent scenes at the same time.
		The mesh cache will be shared between all existing scene managers, which means if you load
		a mesh in the original scene manager using for example getMesh(), the mesh will be available
		in all other scene managers too, without loading.
		The original/main scene manager will still be there and accessible via IrrlichtDevice::getSceneManager().
		If you need input event in this new scene manager, for example for FPS cameras, you'll need
		to forward input to this manually: Just implement an IEventReceiver and call
		yourNewSceneManager->postEventFromUser(), and return true so that the original scene manager
		doesn't get the event. Otherwise, all input will go automaticly to the main scene manager.
		If you no longer need the new scene manager, you should call ISceneManager::drop().
		See IUnknown::drop() for more information. */
		virtual ISceneManager* createNewSceneManager() = 0;

		//! Saves the current scene into a file.
		/* Scene nodes with the option isDebugObject set to true are not being saved.
		The scene is usually written to an .irr file, an xml based format. .irr files can
		Be edited with the Irrlicht Engine Editor, irrEdit (http://irredit.irrlicht3d.org).
		To load .irr files again, see ISceneManager::loadScene().
		\param filename: Name of the file.
		\param userDataSerializer: If you want to save some user data for every scene node into the
		file, implement the ISceneUserDataSerializer interface and provide it as parameter here.
		Otherwise, simply specify 0 as this parameter.
		\return Returns true if successful. */
		virtual bool saveScene(const c8* filename, ISceneUserDataSerializer* userDataSerializer=0) = 0;

		//! Saves the current scene into a file.
		/* Scene nodes with the option isDebugObject set to true are not being saved.
		The scene is usually written to an .irr file, an xml based format. .irr files can
		Be edited with the Irrlicht Engine Editor, irrEdit (http://irredit.irrlicht3d.org).
		To load .irr files again, see ISceneManager::loadScene().
		\param file: File where the scene is saved into.
		\param userDataSerializer: If you want to save some user data for every scene node into the
		file, implement the ISceneUserDataSerializer interface and provide it as parameter here.
		Otherwise, simply specify 0 as this parameter.
		\return Returns true if successful. */
		virtual bool saveScene(io::IWriteFile* file, ISceneUserDataSerializer* userDataSerializer=0) = 0;

		//! Loads a scene. Note that the current scene is not cleared before.
		/* The scene is usually load from an .irr file, an xml based format. .irr files can
		Be edited with the Irrlicht Engine Editor, irrEdit (http://irredit.irrlicht3d.org) or
		saved directly by the engine using ISceneManager::saveScene().		
		\param filename: Name of the file.
		\param userDataSerializer: If you want to load user data possibily saved in that file for
		some scene nodes in the file, implement the ISceneUserDataSerializer interface and provide it as parameter here.
		Otherwise, simply specify 0 as this parameter.
		\return Returns true if successful. */
		virtual bool loadScene(const c8* filename, ISceneUserDataSerializer* userDataSerializer=0) = 0;

		//! Loads a scene. Note that the current scene is not cleared before.
		/* The scene is usually load from an .irr file, an xml based format. .irr files can
		Be edited with the Irrlicht Engine Editor, irrEdit (http://irredit.irrlicht3d.org) or
		saved directly by the engine using ISceneManager::saveScene().		
		\param file: File where the scene is going to be saved into.
		\param userDataSerializer: If you want to load user data possibily saved in that file for
		some scene nodes in the file, implement the ISceneUserDataSerializer interface and provide it as parameter here.
		Otherwise, simply specify 0 as this parameter.
		\return Returns true if successful.	*/
		virtual bool loadScene(io::IReadFile* file, ISceneUserDataSerializer* userDataSerializer=0) = 0;	

		//! Sets ambient color of the scene
		virtual void setAmbientLight(const video::SColorf &ambientColor) = 0;

		//! Returns ambient color of the scene
		virtual video::SColorf getAmbientLight() = 0;

	};


} // end namespace scene
} // end namespace irr

#endif

// Copyright (C) 2002-2007 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __I_SCENE_NODE_ANIMATOR_H_INCLUDED__
#define __I_SCENE_NODE_ANIMATOR_H_INCLUDED__

// Copyright (C) 2002-2007 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __E_SCENE_NODE_ANIMATOR_TYPES_H_INCLUDED__
#define __E_SCENE_NODE_ANIMATOR_TYPES_H_INCLUDED__

namespace irr
{
namespace scene  
{
	//! An enumeration for all types of built-in scene node animators
	enum ESCENE_NODE_ANIMATOR_TYPE
	{
		//! Fly circle scene node animator
		ESNAT_FLY_CIRCLE = 0,

		//! Fly straight scene node animator
		ESNAT_FLY_STRAIGHT,

		//! Follow spline scene node animator
		ESNAT_FOLLOW_SPLINE,

		//! Rotation scene node animator
		ESNAT_ROTATION,

		//! Texture scene node animator
		ESNAT_TEXTURE,

		//! Deletion scene node animator
		ESNAT_DELETION,

		//! Collision respose scene node animator
		ESNAT_COLLISION_RESPONSE,

		//! Amount of build in scene node animators
		ESNAT_COUNT,

		//! Unknown scene node animator
		ESNAT_UNKNOWN,

		//! This enum is never used, it only forces the compiler to 
		//! compile these enumeration values to 32 bit.
		ESNAT_FORCE_32_BIT = 0x7fffffff
	};

} // end namespace scene
} // end namespace irr


#endif


namespace irr
{
namespace io
{
	class IAttributes;
} // end namespace io
namespace scene
{
	class ISceneNode;

	//! Animates a scene node. Can animate position, rotation, material, and so on.
	/* A scene node animator is able to animate a scene node in a very simple way. It may
	change its position, rotation, scale and/or material. There are lots of animators
	to choose from. You can create scene node animators with the ISceneManager interface.
	*/
	class ISceneNodeAnimator : public io::IAttributeExchangingObject
	{
	public:

		//! destructor
		virtual ~ISceneNodeAnimator() {}

		/// <summary>
		/// Animates a scene node.
		/// </summary>
		/// \param node: Node to animate.
		/// \param timeMs: Current time in milli seconds.
		virtual void animateNode(ISceneNode* node, u32 timeMs) = 0;

		//! Returns type of the scene node animator
		virtual ESCENE_NODE_ANIMATOR_TYPE getType()
		{
			return ESNAT_UNKNOWN;
		}
	};
} // end namespace scene
} // end namespace irr

#endif

// Copyright (C) 2002-2007 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __I_TRIANGLE_SELECTOR_H_INCLUDED__
#define __I_TRIANGLE_SELECTOR_H_INCLUDED__


namespace irr
{
namespace scene
{

//! Interface to return triangles with specific properties.
/* Every ISceneNode may have a triangle selector, available with 
 ISceneNode::getTriangleScelector() or ISceneManager::createTriangleSelector.
 This is used for doing collision detection: For example if you know, that a collision may happened in the 
 area between (1,1,1) and (10,10,10), you can get all triangles of the
 scene node in this area with the ITriangleSelector easily and check every triangle
 if it collided. */
class ITriangleSelector : public virtual IUnknown
{
public:

	//! destructor
	virtual ~ITriangleSelector() {};

	//! Returns amount of all available triangles in this selector
	virtual s32 getTriangleCount() const = 0;

	//! Gets all triangles.
	//! \param triangles: Array where the resulting triangles will be written to.
	//! \param arraySize: Size of the target array.
	//! \param outTriangleCount: Amount of triangles which have been written into the
	//! array.
	//! \param transform: Pointer to matrix for transforming the triangles before.
	//! they are returned. Useful for example to scale all triangles down into an
	//! ellipsoid space. If this pointer is null, no transformation will be done.
	virtual void getTriangles(core::triangle3df* triangles, s32 arraySize,
		s32& outTriangleCount, const core::matrix4* transform=0) = 0;

	//! Gets all triangles which lie within a specific bounding box.
	//! Please note that unoptimized triangle selectors also may return triangles,
	//! which are not in the specific box at all.
	//! \param triangles: Array where the resulting triangles will be written to.
	//! \param arraySize: Size of the target array.
	//! \param outTriangleCount: Amount of triangles which have been written into the
	//! array.
	//! \param box: Only triangles which are in this axis aligned bounding box
	//! will be written into the array.
	//! \param transform: Pointer to matrix for transforming the triangles before.
	//! they are returned. Useful for example to scale all triangles down into an
	//! ellipsoid space. If this pointer is null, no transformation will be done.
	virtual void getTriangles(core::triangle3df* triangles, s32 arraySize,
		s32& outTriangleCount, const core::aabbox3d<f32>& box, 
		const core::matrix4* transform=0) = 0;

	//! Gets all triangles which have or may have contact with a 3d line.
	//! Please note that unoptimized triangle selectors also may return triangles,
	//! which are not in contact at all with the 3d line.
	//! \param triangles: Array where the resulting triangles will be written to.
	//! \param arraySize: Size of the target array.
	//! \param outTriangleCount: Amount of triangles which have been written into the
	//! array.
	//! \param line: Only triangles which may be in contact with this 3d line will
	//! be written into the array.
	//! \param transform: Pointer to matrix for transforming the triangles before.
	//! they are returned. Useful for example to scale all triangles down into an
	//! ellipsoid space. If this pointer is null, no transformation will be done.
	virtual void getTriangles(core::triangle3df* triangles, s32 arraySize,
		s32& outTriangleCount, const core::line3d<f32>& line, 
		const core::matrix4* transform=0) = 0;
};

} // end namespace scene
} // end namespace irr


#endif


namespace irr
{
namespace scene
{
	//! Scene node interface.
	/* A scene node is a node in the hirachical scene graph. Every scene node may have children,
	which are other scene nodes. Children move relative the their parents position. If the parent of a node is not
	visible, its children won't be visible too. In this way, it is for example easily possible
	to attach a light to a moving car, or to place a walking character on a moving platform
	on a moving ship. */
	class ISceneNode : public io::IAttributeExchangingObject
	{
	public:

		//! Constructor
		ISceneNode(	ISceneNode* parent, ISceneManager* mgr, s32 id=-1,
					const core::vector3df& position = core::vector3df(0,0,0),
					const core::vector3df& rotation = core::vector3df(0,0,0),
					const core::vector3df& scale = core::vector3df(1.0f, 1.0f, 1.0f))
			: RelativeTranslation(position), RelativeRotation(rotation), RelativeScale(scale),
				Parent(parent), ID(id), SceneManager(mgr), TriangleSelector(0),
				AutomaticCullingState(EAC_BOX), IsVisible(true),
				DebugDataVisible(EDS_OFF), IsDebugObject(false)
		{
			if (Parent)
				Parent->addChild(this);

			updateAbsolutePosition();
		}



		//! Destructor
		virtual ~ISceneNode()
		{
			// delete all children
			removeAll();

			// delete all animators
			core::list<ISceneNodeAnimator*>::Iterator ait = Animators.begin();
			for (; ait != Animators.end(); ++ait)
				(*ait)->drop();

			if (TriangleSelector)
				TriangleSelector->drop();
		}


		//! This method is called just before the rendering process of the whole scene.
		/* Nodes may register themselves in the render pipeline during this call,
		 precalculate the geometry which should be renderered, and prevent their
		 children from being able to register them selfes if they are clipped by simply
		 not calling their OnRegisterSceneNode-Method. 
		 If you are implementing your own scene node, you should overwrite this method
		 with an implementtion code looking like this:
		 \code
		 if (IsVisible)
			SceneManager->registerNodeForRendering(this);

		 ISceneNode::OnRegisterSceneNode();
		 \endcode
	    */
		virtual void OnRegisterSceneNode()
		{
			if (IsVisible)
			{
				core::list<ISceneNode*>::Iterator it = Children.begin();
				for (; it != Children.end(); ++it)
					(*it)->OnRegisterSceneNode();
			}
		}


		//! OnAnimate() is called just before rendering the whole scene.
		//! Nodes may calculate or store animations here, and may do other useful things,
		//! dependent on what they are. Also, OnAnimate() should be called for all
		//! child scene nodes here. This method will called once per frame, independent
		//! of if the scene node is visible or not.
		//! \param timeMs: Current time in milli seconds.
		virtual void OnAnimate(u32 timeMs)
		{
			if (IsVisible)
			{
				// animate this node with all animators

				core::list<ISceneNodeAnimator*>::Iterator ait = Animators.begin();
				for (; ait != Animators.end(); ++ait)
					(*ait)->animateNode(this, timeMs);

				// update absolute position
				updateAbsolutePosition();

				// perform the post render process on all children

				core::list<ISceneNode*>::Iterator it = Children.begin();
				for (; it != Children.end(); ++it)
					(*it)->OnAnimate(timeMs);
			}
		}


		//! Renders the node.
		virtual void render() = 0;


		//! Returns the name of the node.
		//! \return Returns name as wide character string.
		virtual const c8* getName() const
		{
			return Name.c_str();
		}


		//! Sets the name of the node.
		//! \param name: New name of the scene node.
		virtual void setName(const c8* name)
		{
			Name = name;
		}


		//! Returns the axis aligned, not transformed bounding box of this node.
		//! This means that if this node is a animated 3d character, moving in a room,
		//! the bounding box will always be around the origin. To get the box in
		//! real world coordinates, just transform it with the matrix you receive with
		//! getAbsoluteTransformation() or simply use getTransformedBoundingBox(),
		//! which does the same.
		virtual const core::aabbox3d<f32>& getBoundingBox() const = 0;


		//! Returns the axis aligned, transformed and animated absolute bounding box
		//! of this node.
		virtual const core::aabbox3d<f32> getTransformedBoundingBox() const
		{
			core::aabbox3d<f32> box = getBoundingBox();
			AbsoluteTransformation.transformBox(box);
			return box;
		}


		//! returns the absolute transformation of the node. Is recalculated every OnAnimate()-call.
		const core::matrix4& getAbsoluteTransformation() const
		{
			return AbsoluteTransformation;
		}


		//! Returns the relative transformation of the scene node.
		//! The relative transformation is stored internally as 3 vectors:
		//! translation, rotation and scale. To get the relative transformation
		//! matrix, it is calculated from these values.
		//! \return Returns the relative transformation matrix.
		virtual core::matrix4 getRelativeTransformation() const
		{
			core::matrix4 mat;
			mat.setRotationDegrees(RelativeRotation);
			mat.setTranslation(RelativeTranslation);

			if (RelativeScale != core::vector3df(1,1,1))
			{
				core::matrix4 smat;
				smat.setScale(RelativeScale);
				mat *= smat;
			}

			return mat;
		}


		//! Returns true if the node is visible. This is only an option, set by the user and has
		//! nothing to do with geometry culling
		virtual bool isVisible() const
		{
			_IRR_IMPLEMENT_MANAGED_MARSHALLING_BUGFIX;
			return IsVisible;
		}


		//! Sets if the node should be visible or not. All children of this node won't be visible too.
		virtual void setVisible(bool isVisible)
		{
			IsVisible = isVisible;
		}


		//! Returns the id of the scene node. This id can be used to identify the node.
		virtual s32 getID() const
		{
			return ID;
		}


		//! sets the id of the scene node. This id can be used to identify the node.
		virtual void setID(s32 id)
		{
			ID = id;
		}


		//! Adds a child to this scene node. If the scene node already
		//! has got a parent, it is removed from there as child.
		virtual void addChild(ISceneNode* child)
		{
			if (child)
			{
				child->grab();
				child->remove(); // remove from old parent
				Children.push_back(child);
				child->Parent = this;
			}
		}


		//! Removes a child from this scene node.
		//! \return Returns true if the child could be removed, and false if not.
		virtual bool removeChild(ISceneNode* child)
		{
			core::list<ISceneNode*>::Iterator it = Children.begin();
			for (; it != Children.end(); ++it)
				if ((*it) == child)
				{
					(*it)->Parent = 0;
					(*it)->drop();
					Children.erase(it);
					return true;
				}

			_IRR_IMPLEMENT_MANAGED_MARSHALLING_BUGFIX;
			return false;
		}


		//! Removes all children of this scene node
		virtual void removeAll()
		{
			core::list<ISceneNode*>::Iterator it = Children.begin();
			for (; it != Children.end(); ++it)
			{
				(*it)->Parent = 0;
				(*it)->drop();
			}

			Children.clear();
		}


		//! Removes this scene node from the scene, deleting it.
		virtual void remove()
		{
			if (Parent)
				Parent->removeChild(this);
		}


		//! Adds an animator which should animate this node.
		virtual void addAnimator(ISceneNodeAnimator* animator)
		{
			if (animator)
			{
				Animators.push_back(animator);
				animator->grab();
			}
		}


		//! Returns a const reference to the list of all scene node animators.
		const core::list<ISceneNodeAnimator*>& getAnimators() const
		{
			return Animators;
		}


		//! Removes an animator from this scene node.
		virtual void removeAnimator(ISceneNodeAnimator* animator)
		{
			core::list<ISceneNodeAnimator*>::Iterator it = Animators.begin();
			for (; it != Animators.end(); ++it)
				if ((*it) == animator)
				{
					(*it)->drop();
					Animators.erase(it);
					return;
				}
		}


		//! Removes all animators from this scene node.
		virtual void removeAnimators()
		{
			core::list<ISceneNodeAnimator*>::Iterator it = Animators.begin();
			for (; it != Animators.end(); ++it)
				(*it)->drop();

			Animators.clear();
		}


		//! Returns the material based on the zero based index i. To get the amount
		//! of materials used by this scene node, use getMaterialCount().
		//! This function is needed for inserting the node into the scene hirachy on a
		//! optimal position for minimizing renderstate changes, but can also be used
		//! to directly modify the material of a scene node.
		//! \param num: Zero based index. The maximal value is getMaterialCount() - 1.
		//! \return Returns the material of that index.
		virtual video::SMaterial& getMaterial(u32 num)
		{
			return *((video::SMaterial*)0);
		}


		//! Returns amount of materials used by this scene node.
		//! \return Returns current count of materials used by this scene node.
		virtual u32 getMaterialCount()
		{
			return 0;
		}


		//! Sets all material flags at once to a new value. Helpful for
		//! example, if you want to be the the whole mesh to be lighted by
		//! \param flag: Which flag of all materials to be set.
		//! \param newvalue: New value of the flag.
		void setMaterialFlag(video::E_MATERIAL_FLAG flag, bool newvalue)
		{
			for (u32 i=0; i<getMaterialCount(); ++i)
				getMaterial(i).setFlag(flag, newvalue);
		}


		//! Sets the texture of the specified layer in all materials of this
		//! scene node to the new texture.
		//! \param textureLayer: Layer of texture to be set. Must be a value greater or
		//! equal than 0 and smaller than MATERIAL_MAX_TEXTURES.
		//! \param texture: Texture to be used.
		void setMaterialTexture(u32 textureLayer, video::ITexture* texture)
		{
			if (textureLayer>= video::MATERIAL_MAX_TEXTURES)
				return;

			for (u32 i=0; i<getMaterialCount(); ++i)
				getMaterial(i).Textures[textureLayer] = texture;
		}


		//! Sets the material type of all materials s32 this scene node
		//! to a new material type.
		//! \param newType: New type of material to be set.
		void setMaterialType(video::E_MATERIAL_TYPE newType)
		{
			for (u32 i=0; i<getMaterialCount(); ++i)
				getMaterial(i).MaterialType = newType;
		}


		//! Gets the scale of the scene node.
		/* \return Returns the scale of the scene node. */
		virtual core::vector3df getScale() const
		{
			return RelativeScale;
		}


		//! Sets the scale of the scene node.
		/* \param scale: New scale of the node */
		virtual void setScale(const core::vector3df& scale)
		{
			RelativeScale = scale;
		}


		//! Gets the rotation of the node.
		/* Note that this is the relative rotation of the node.
		\return Current relative rotation of the scene node. */
		virtual const core::vector3df& getRotation() const
		{
			return RelativeRotation;
		}


		//! Sets the rotation of the node.
		/* This only modifies the relative rotation of the node.
		\param rotation: New rotation of the node in degrees. */
		virtual void setRotation(const core::vector3df& rotation)
		{
			RelativeRotation = rotation;
		}


		//! Gets the position of the node.
		/* Note that the position is relative to the parent.
		\return Returns the current position of the node relative to the parent. */
		virtual const core::vector3df getPosition() const
		{
			return RelativeTranslation;
		}


		//! Sets the position of the node.
		/* Note that the position is relative to the parent.
		\param newpos: New relative postition of the scene node. */
		virtual void setPosition(const core::vector3df& newpos)
		{
			RelativeTranslation = newpos;
		}


		//! Gets the abolute position of the node.
		/* The position is absolute.
		\return Returns the current absolute position of the scene node. */
		virtual core::vector3df getAbsolutePosition() const
		{
			return AbsoluteTransformation.getTranslation();
		}


		//! Enables or disables automatic culling based on the bounding box.
		/* Automatic culling is enabled by default. Note that not
		all SceneNodes support culling (the billboard scene node for example)
		and that some nodes always cull their geometry because it is their
		only reason for existance, for example the OctreeSceneNode.
		\param enabled: If true, automatic culling is enabled.
		If false, it is disabled. */
		void setAutomaticCulling( E_CULLING_TYPE state)
		{
			AutomaticCullingState = state;
		}


		//! Gets the automatic culling state.
		/* \return The node is culled based on its bounding box if this method
		 returns true, otherwise no culling is performed. */
		E_CULLING_TYPE getAutomaticCulling() const
		{
			_IRR_IMPLEMENT_MANAGED_MARSHALLING_BUGFIX;
			return AutomaticCullingState;
		}


		//! Sets if debug data like bounding boxes should be drawn.
		/* Please note that not all scene nodes support this feature. */
		virtual void setDebugDataVisible(E_DEBUG_SCENE_TYPE visible)
		{
			DebugDataVisible = visible;
		}

		//! Returns if debug data like bounding boxes are drawed.
		E_DEBUG_SCENE_TYPE isDebugDataVisible() const
		{
			_IRR_IMPLEMENT_MANAGED_MARSHALLING_BUGFIX;
			return DebugDataVisible;
		}


		//! Sets if this scene node is a debug object.
		/* Debug objects have some special properties, for example they can be easily
		excluded from collision detection or from serialization, etc. */
		void setIsDebugObject(bool debugObject)
		{
			IsDebugObject = debugObject;
		}

		//! Returns if this scene node is a debug object.
		/* Debug objects have some special properties, for example they can be easily
		excluded from collision detection or from serialization, etc. */
		bool isDebugObject()
		{
			_IRR_IMPLEMENT_MANAGED_MARSHALLING_BUGFIX;
			return IsDebugObject;
		}


		//! Returns a const reference to the list of all children.
		const core::list<ISceneNode*>& getChildren() const
		{
			return Children;
		}


		//! Changes the parent of the scene node.
		virtual void setParent(ISceneNode* newParent)
		{
			grab();
			remove();

			Parent = newParent;

			if (Parent)
				Parent->addChild(this);

			drop();
		}


		//! Returns the triangle selector attached to this scene node.
		//! The Selector can be used by the engine for doing collision
		//! detection. You can create a TriangleSelector with
		//! ISceneManager::createTriangleSelector() or
		//! ISceneManager::createOctTreeTriangleSelector and set it with
		//! ISceneNode::setTriangleSelector(). If a scene node got no triangle
		//! selector, but collision tests should be done with it, a triangle
		//! selector is created using the bounding box of the scene node.
		//! \return Returns a pointer to the TriangleSelector or NULL, if there
		//! is none.
		virtual ITriangleSelector* getTriangleSelector() const
		{
			return TriangleSelector;
		}


		//! Sets the triangle selector of the scene node. The Selector can be
		//! used by the engine for doing collision detection. You can create a
		//! TriangleSelector with ISceneManager::createTriangleSelector() or
		//! ISceneManager::createOctTreeTriangleSelector(). Some nodes may
		//! create their own selector by default, so it would be good to
		//! check if there is already a selector in this node by calling
		//! ISceneNode::getTriangleSelector().
		//! \param selector: New triangle selector for this scene node.
		virtual void setTriangleSelector(ITriangleSelector* selector)
		{
			if (TriangleSelector)
				TriangleSelector->drop();

			TriangleSelector = selector;
			if (TriangleSelector)
				TriangleSelector->grab();
		}

		//! updates the absolute position based on the relative and the parents position
		virtual void updateAbsolutePosition()
		{
			if (Parent )
			{
				AbsoluteTransformation =
					Parent->getAbsoluteTransformation() * getRelativeTransformation();
			}
			else
				AbsoluteTransformation = getRelativeTransformation();
		}

		//! Returns the parent of this scene node
		scene::ISceneNode* getParent() const
		{
			return Parent;
		}

		//! Returns type of the scene node
		virtual ESCENE_NODE_TYPE getType() const
		{
			return ESNT_UNKNOWN;
		}

		//! Writes attributes of the scene node.
		//! Implement this to expose the attributes of your scene node for
		//! scripting languages, editors, debuggers or xml serialization purposes.
		virtual void serializeAttributes(io::IAttributes* out, io::SAttributeReadWriteOptions* options=0)
		{
			out->addString	("Name", Name.c_str());
			out->addInt	("Id", ID );
			out->addVector3d("Position", RelativeTranslation );
			out->addVector3d("Rotation", RelativeRotation );
			out->addVector3d("Scale", RelativeScale );
			out->addBool	("Visible", IsVisible );
			out->addEnum	("AutomaticCulling", AutomaticCullingState, AutomaticCullingNames);
			out->addInt		("DebugDataVisible", DebugDataVisible );
			out->addBool	("IsDebugObject", IsDebugObject );
		}

		//! Reads attributes of the scene node.
		//! Implement this to set the attributes of your scene node for
		//! scripting languages, editors, debuggers or xml deserialization purposes.
		virtual void deserializeAttributes(io::IAttributes* in, io::SAttributeReadWriteOptions* options=0)
		{
			Name = in->getAttributeAsString("Name");
			ID = in->getAttributeAsInt("Id");
			RelativeTranslation = in->getAttributeAsVector3d("Position");
			RelativeRotation = in->getAttributeAsVector3d("Rotation");
			RelativeScale = in->getAttributeAsVector3d("Scale");
			IsVisible = in->getAttributeAsBool("Visible");
			AutomaticCullingState = (scene::E_CULLING_TYPE ) in->getAttributeAsEnumeration("AutomaticCulling", scene::AutomaticCullingNames);

			DebugDataVisible = (scene::E_DEBUG_SCENE_TYPE ) in->getAttributeAsInt("DebugDataVisible");
			IsDebugObject = in->getAttributeAsBool("IsDebugObject");

			updateAbsolutePosition();
		}

	protected:

		//! name of the scene node.
		core::stringc Name;

		//! absolute transformation of the node.
		core::matrix4 AbsoluteTransformation;

		//! relative translation of the scene node.
		core::vector3df RelativeTranslation;

		//! relative rotation of the scene node.
		core::vector3df RelativeRotation;

		//! relative scale of the scene node.
		core::vector3df RelativeScale;

		//! Pointer to the parent
		ISceneNode* Parent;

		//! List of all children of this node
		core::list<ISceneNode*> Children;

		//! List of all animator nodes
		core::list<ISceneNodeAnimator*> Animators;

		//! id of the node.
		s32 ID;

		//! pointer to the scene manager
		ISceneManager* SceneManager;

		//! pointer to the triangle selector
		ITriangleSelector* TriangleSelector;

		//! automatic culling
		E_CULLING_TYPE AutomaticCullingState;

		//! is the node visible?
		bool IsVisible;

		//! flag if debug data should be drawn, such as Bounding Boxes.
		E_DEBUG_SCENE_TYPE DebugDataVisible;

		//! is debug object?
		bool IsDebugObject;
	};

} // end namespace scene
} // end namespace irr

#endif


namespace irr
{
namespace scene
{
	//! Interface for using some special functions of B3d meshes
	/* Please note that the B3d Mesh's frame numbers are scaled by 100 */
	class IAnimatedMeshB3d : public IAnimatedMesh
	{
	public:

		//! Returns a pointer to a transformation matrix of a part of the
		//! mesh based on a frame time. This is used for being able to attach
		//! objects to parts of animated meshes. For example a weapon to an animated
		//! hand.
		//! \param jointNumber: Zero based index of joint. The last joint has the number
		//! IAnimatedMeshB3d::getJointCount()-1;
		//! \param frame: Frame of the animation.
		//! \return Returns a pointer to the matrix of the mesh part or
		//! null if an error occured.
		virtual core::matrix4* getMatrixOfJoint(s32 jointNumber, s32 frame) = 0;


		//! Returns a pointer to a local matrix of a Joint, can be used to control the animation
		virtual core::matrix4* getLocalMatrixOfJoint(s32 jointNumber) = 0;

		//! Returns a pointer to a matrix of a part of the mesh unanimated
		virtual core::matrix4* getMatrixOfJointUnanimated(s32 jointNumber) = 0;


		//! Move this Joint's local matrix when animating
		//! \param jointNumber: Zero based index of joint. The last joint has the number
		//! IAnimatedMeshB3d::getJointCount()-1;
		//! \param On: False= Leave joint's local matrix, True= Animate
		//! (not used yet)
		virtual void setJointAnimation(s32 jointNumber, bool On) = 0;


		//! Gets joint count.
		//! \return Returns amount of joints in the skeletal animated mesh.
		virtual s32 getJointCount() const = 0;

		//! Gets the name of a joint.
		//! \param number: Zero based index of joint. The last joint has the number
		//! IAnimatedMeshB3d::getJointCount()-1;
		//! \return Returns name of joint and null if an error happened.
		virtual const c8* getJointName(s32 number) const = 0;

		//! Gets a joint number from its name
		//! \param name: Name of the joint.
		//! \return Returns the number of the joint or -1 if not found.
		virtual s32 getJointNumber(const c8* name) const = 0;

		//!Update Normals when Animating
		//!False= Don't (default)
		//!True= Update normals, slower
		virtual void updateNormalsWhenAnimating(bool on) = 0;


		//!Sets Interpolation Mode
		//!0- Constant
		//!1- Linear (default)
		virtual void setInterpolationMode(s32 mode) = 0;

		//!Want should happen on when animating
		//!0-Nothing
		//!1-Update nodes only
		//!2-Update skin only
		//!3-Update both nodes and skin (default)
		virtual void setAnimateMode(s32 mode) = 0;

		//!Convert all mesh buffers to use tangent vertices
		virtual void convertToTangents() =0;


		virtual void recoverJointsFromMesh(core::array<ISceneNode*> &JointChildSceneNodes)=0;
		virtual void tranferJointsToMesh(core::array<ISceneNode*> &JointChildSceneNodes)=0;
		virtual void createJoints(core::array<ISceneNode*> &JointChildSceneNodes, ISceneNode* AnimatedMeshSceneNode, ISceneManager* SceneManager)=0;

	};

} // end namespace scene
} // end namespace irr

#endif


// Copyright (C) 2002-2007 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __I_ANIMATED_MESH_SCENE_NODE_H_INCLUDED__
#define __I_ANIMATED_MESH_SCENE_NODE_H_INCLUDED__

// Copyright (C) 2002-2007 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __I_SHADOW_VOLUME_SCENE_NODE_H_INCLUDED__
#define __I_SHADOW_VOLUME_SCENE_NODE_H_INCLUDED__


namespace irr
{
namespace scene
{

	//! Scene node for rendering a shadow volume into a stencil buffer.
	class IShadowVolumeSceneNode : public ISceneNode
	{
	public:

		//! constructor
		IShadowVolumeSceneNode(ISceneNode* parent, ISceneManager* mgr, s32 id)
			: ISceneNode(parent, mgr, id) {}

		//! sets the mesh from which the shadow volume should be generated.
		virtual void setMeshToRenderFrom(IMesh* mesh) = 0;
	};

} // end namespace scene
} // end namespace irr

#endif


namespace irr
{
namespace scene
{
	class IAnimatedMeshSceneNode;

	//! Callback interface for catching events of ended animations.
	/* Implement this interface and use
	 IAnimatedMeshSceneNode::setAnimationEndCallback to be able to
	 be notified if an animation playback has ended.
	**/
	class IAnimationEndCallBack : public virtual IUnknown
	{
	public:

		//! Will be called when the animation playback has ended.
		//! See IAnimatedMeshSceneNode::setAnimationEndCallback for
		//! more informations.
		//! \param node: Node of which the animation has ended.
		virtual void OnAnimationEnd(IAnimatedMeshSceneNode* node) = 0;
	};

	//! Scene node capable of displaying an animated mesh and its shadow.
	/* The shadow is optional: If a shadow should be displayed too, just invoke
	the IAnimatedMeshSceneNode::createShadowVolumeSceneNode().*/
	class IAnimatedMeshSceneNode : public ISceneNode
	{
	public:

		//! Constructor
		IAnimatedMeshSceneNode(ISceneNode* parent, ISceneManager* mgr, s32 id,
			const core::vector3df& position = core::vector3df(0,0,0),
			const core::vector3df& rotation = core::vector3df(0,0,0),
			const core::vector3df& scale = core::vector3df(1.0f, 1.0f, 1.0f))
			: ISceneNode(parent, mgr, id, position, rotation, scale) {}

		//! Destructor
		virtual ~IAnimatedMeshSceneNode() {};

		//! Sets the current frame number.
		//! From now on the animation is played from this frame.
		//! \param frame: Number of the frame to let the animation be started from.
		//! The frame number must be a valid frame number of the IMesh used by this
		//! scene node. Set IAnimatedMesh::getMesh() for details.
		virtual void setCurrentFrame(s32 frame) = 0;

		//! Sets the frame numbers between the animation is looped.
		//! The default is 0 - MaximalFrameCount of the mesh.
		//! \param begin: Start frame number of the loop.
		//! \param end: End frame number of the loop.
		//! \return Returns true if successful, false if not.
		virtual bool setFrameLoop(s32 begin, s32 end) = 0;

		//! Sets the speed with witch the animation is played.
		//! \param framesPerSecond: Frames per second played.
		virtual void setAnimationSpeed(f32 framesPerSecond) = 0;

		//! Creates shadow volume scene node as child of this node
		//! and returns a pointer to it.  The shadow can be rendered using the ZPass
		//! or the zfail method. ZPass is a little bit faster because the shadow volume
		//! creation is easier, but with this method there occur ugly looking artifacs
		//! when the camera is inside the shadow volume. These error do not occur
		//! with the ZFail method.
		//! \param id: Id of the shadow scene node. This id can be used to identify
		//! the node later.
		//! \param zfailmethod: If set to true, the shadow will use the zfail method,
		//! if not, zpass is used.
		//! \param infinity: Value used by the shadow volume algorithm to scale the
		//! shadow volume.
		//! \return Returns pointer to the created shadow scene node.
		//! This pointer should not be dropped. See IUnknown::drop() for more information.
		virtual IShadowVolumeSceneNode* addShadowVolumeSceneNode(s32 id=-1,
			bool zfailmethod=true, f32 infinity=10000.0f) = 0;

		//! Returns a pointer to a child node, wich has the same transformation as
		//! the corresponding joint, if the mesh in this scene node is a ms3d mesh.
		//! Otherwise 0 is returned. With this method it is possible to
		//! attach scene nodes to joints more easily. In this way, it is
		//! for example possible to attach a weapon to the left hand of an
		//! animated model. This example shows how:
		//! \code
		//! ISceneNode* hand =
		//!		yourMS3DAnimatedMeshSceneNode->getMS3DJointNode("LeftHand");
		//! hand->addChild(weaponSceneNode);
		//! \endcode
		//! Please note that the SceneNode returned by this method may not exist
		//! before this call and is created by it.
		//! \param jointName: Name of the joint.
		//! \return Returns a pointer to the scene node which represents the joint
		//! with the specified name. Returns 0 if the contained mesh is not an
		//! ms3d mesh or the name of the joint could not be found.
		virtual ISceneNode* getMS3DJointNode(const c8* jointName) = 0;

		//! Returns a pointer to a child node, which has the same transformation as
		//! the corresponding joint, if the mesh in this scene node is a x mesh.
		//! Otherwise 0 is returned. With this method it is possible to
		//! attach scene nodes to joints more easily. In this way, it is
		//! for example possible to attach a weapon to the left hand of an
		//! animated model. This example shows how:
		//! \code
		//! ISceneNode* hand =
		//!		yourMS3DAnimatedMeshSceneNode->getXJointNode("LeftHand");
		//! hand->addChild(weaponSceneNode);
		//! \endcode
		//! Please note that the SceneNode returned by this method may not exist
		//! before this call and is created by it.
		//! \param jointName: Name of the joint.
		//! \return Returns a pointer to the scene node which represents the joint
		//! with the specified name. Returns 0 if the contained mesh is not an
		//! ms3d mesh or the name of the joint could not be found.
		virtual ISceneNode* getXJointNode(const c8* jointName) = 0;

		//! Returns a pointer to a child node, wich has the same transformation as
		//! the corresponding joint, if the mesh in this scene node is a b3d mesh.
		//! Otherwise 0 is returned. With this method it is possible to
		//! attach scene nodes to joints more easily. In this way, it is
		//! for example possible to attach a weapon to the left hand of an
		//! animated model. This example shows how:
		//! \code
		//! ISceneNode* hand =
		//!		yourB3DAnimatedMeshSceneNode->getB3DJointNode("LeftHand");
		//! hand->addChild(weaponSceneNode);
		//! \endcode
		//! Please note that the SceneNode returned by this method may not exist
		//! before this call and is created by it.
		//! \param jointName: Name of the joint.
		//! \return Returns a pointer to the scene node which represents the joint
		//! with the specified name. Returns 0 if the contained mesh is not an
		//! ms3d mesh or the name of the joint could not be found.
		virtual ISceneNode* getB3DJointNode(const c8* jointName) = 0;

		//! Starts a default MD2 animation.
		//! With this method it is easily possible to start a Run, Attack,
		//! Die or whatever animation, if the mesh contained in this scene
		//! node is an md2 mesh. Otherwise, nothing happens.
		//! \param anim: An MD2 animation type, which should be played, for
		//! example EMAT_STAND for the standing animation.
		//! \return Returns true if successful, and false if not, for example
		//! if the mesh in the scene node is not a md2 mesh.
		virtual bool setMD2Animation(EMD2_ANIMATION_TYPE anim) = 0;

		//! Starts a special MD2 animation.
		//! With this method it is easily possible to start a Run, Attack,
		//! Die or whatever animation, if the mesh contained in this scene
		//! node is an md2 mesh. Otherwise, nothing happens. This method uses
		//! a character string to identify the animation. If the animation is a
		//! standard md2 animation, you might want to start this animation
		//! with the EMD2_ANIMATION_TYPE enumeration instead.
		//! \param animationName: Name of the animation which should be played.
		//! \return Returns true if successful, and false if not, for example
		//! if the mesh in the scene node is not an md2 mesh, or no animation
		//! with this name could be found.
		virtual bool setMD2Animation(const c8* animationName) = 0;

		//! Returns the current displayed frame number.
		virtual s32 getFrameNr() = 0;
		//! Returns the current start frame number.
		virtual s32 getStartFrame() = 0;
		//! Returns the current end frame number.
		virtual s32 getEndFrame() = 0;

		//! Sets looping mode which is on by default. If set to false,
		//! animations will not be played looped.
		virtual void setLoopMode(bool playAnimationLooped) = 0;

		//! Sets a callback interface which will be called if an animation
		//! playback has ended. Set this to 0 to disable the callback again.
		//! Please note that this will only be called when in non looped mode,
		//! see IAnimatedMeshSceneNode::setLoopMode().
		virtual void setAnimationEndCallback(IAnimationEndCallBack* callback=0) = 0;

		//! Sets if the scene node should not copy the materials of the mesh but use them in a read only style.
		/* In this way it is possible to change the materials a mesh causing all mesh scene nodes
		referencing this mesh to change too. */
		virtual void setReadOnlyMaterials(bool readonly) = 0;

		//! Returns if the scene node should not copy the materials of the mesh but use them in a read only style
		virtual bool isReadOnlyMaterials() = 0;

		//! Sets a new mesh
		virtual void setMesh(IAnimatedMesh* mesh) = 0;

		//! Returns the current mesh
		virtual IAnimatedMesh* getMesh(void) = 0;

		// returns the absolute transformation for a special MD3 Tag if the mesh is a md3 mesh,
		// or the absolutetransformation if it's a normal scenenode
		virtual const SMD3QuaterionTag& getAbsoluteTransformation( const core::stringc & tagname) = 0;

	};

} // end namespace scene
} // end namespace irr

#endif

// Copyright (C) 2002-2007 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __I_CAMERA_SCENE_NODE_H_INCLUDED__
#define __I_CAMERA_SCENE_NODE_H_INCLUDED__

// Copyright (C) 2002-2007 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __S_VIEW_FRUSTUM_H_INCLUDED__
#define __S_VIEW_FRUSTUM_H_INCLUDED__


namespace irr
{
namespace scene
{

	//! Defines the view frustum. Thats the space viewed by the camera.
	/* The view frustum is enclosed by 6 planes. These six planes share
	four points. A bounding box around these four points is also stored in
	this structure.
	*/
	struct SViewFrustum
	{
		enum VFPLANES
		{
			//! Far plane of the frustum. Thats the plane farest away from the eye.
			VF_FAR_PLANE = 0,
			//! Near plane of the frustum. Thats the plane nearest to the eye.
			VF_NEAR_PLANE,
			//! Left plane of the frustum.
			VF_LEFT_PLANE,
			//! Right plane of the frustum.
			VF_RIGHT_PLANE,
			//! Bottom plane of the frustum.
			VF_BOTTOM_PLANE,
			//! Top plane of the frustum.
			VF_TOP_PLANE,

			//! Amount of planes enclosing the view frustum. Should be 6.
			VF_PLANE_COUNT
		};

		//! Default Constructor
		SViewFrustum() {};

		//! This constructor creates a view frustum based on a projection and/or
		//! view matrix.
		SViewFrustum(const core::matrix4& mat);

		//! This constructor creates a view frustum based on a projection
		//! and/or view matrix.
		void setFrom(const core::matrix4& mat);

		//! the position of the camera
		core::vector3df cameraPosition;

		//! all planes enclosing the view frustum.
		core::plane3d<f32> planes[VF_PLANE_COUNT];


		//! transforms the frustum by the matrix
		//! \param mat: Matrix by which the view frustum is transformed.
		void transform(const core::matrix4 &mat);

		//! returns the point which is on the far left upper corner inside the
		//! the view frustum.
		core::vector3df getFarLeftUp() const;

		//! returns the point which is on the far left bottom corner inside the
		//! the view frustum.
		core::vector3df getFarLeftDown() const;

		//! returns the point which is on the far right top corner inside the
		//! the view frustum.
		core::vector3df getFarRightUp() const;

		//! returns the point which is on the far right bottom corner inside the
		//! the view frustum.
		core::vector3df getFarRightDown() const;

		//! returns a bounding box enclosing the whole view frustum
		const core::aabbox3d<f32> &getBoundingBox() const;

		//! recalculates the bounding box member based on the planes
		inline void recalculateBoundingBox();

		//! bouding box around the view frustum
		core::aabbox3d<f32> boundingBox;

		//! Hold a copy of important transform matrices
		enum E_TRANSFORMATION_STATE_3
		{
			ETS_VIEW_PROJECTION_3 = video::ETS_PROJECTION + 1,
			ETS_VIEW_MODEL_INVERSE_3,
			ETS_CURRENT_3,
			ETS_COUNT_3
		};

		core::matrix4 Matrices[ETS_COUNT_3];
		void setTransformState( video::E_TRANSFORMATION_STATE state);
	};


	//! transforms the frustum by the matrix
	//! \param Matrix by which the view frustum is transformed.
	inline void SViewFrustum::transform(const core::matrix4 &mat)
	{
		for (int i=0; i<VF_PLANE_COUNT; ++i)
			mat.transformPlane(planes[i]);

		mat.transformVect(cameraPosition);
		recalculateBoundingBox();
	}


	//! returns the point which is on the far left upper corner inside the
	//! the view frustum.
	inline core::vector3df SViewFrustum::getFarLeftUp() const
	{
		core::vector3df p;
		planes[scene::SViewFrustum::VF_FAR_PLANE].getIntersectionWithPlanes(
			planes[scene::SViewFrustum::VF_TOP_PLANE],
			planes[scene::SViewFrustum::VF_LEFT_PLANE], p);

		return p;
	}

	//! returns the point which is on the far left bottom corner inside the
	//! the view frustum.
	inline core::vector3df SViewFrustum::getFarLeftDown() const
	{
		core::vector3df p;
		planes[scene::SViewFrustum::VF_FAR_PLANE].getIntersectionWithPlanes(
			planes[scene::SViewFrustum::VF_BOTTOM_PLANE],
			planes[scene::SViewFrustum::VF_LEFT_PLANE], p);

		return p;
	}

	//! returns the point which is on the far right top corner inside the
	//! the view frustum.
	inline core::vector3df SViewFrustum::getFarRightUp() const
	{
		core::vector3df p;
		planes[scene::SViewFrustum::VF_FAR_PLANE].getIntersectionWithPlanes(
			planes[scene::SViewFrustum::VF_TOP_PLANE],
			planes[scene::SViewFrustum::VF_RIGHT_PLANE], p);

		return p;
	}

	//! returns the point which is on the far right bottom corner inside the
	//! the view frustum.
	inline core::vector3df SViewFrustum::getFarRightDown() const
	{
		core::vector3df p;
		planes[scene::SViewFrustum::VF_FAR_PLANE].getIntersectionWithPlanes(
			planes[scene::SViewFrustum::VF_BOTTOM_PLANE],
			planes[scene::SViewFrustum::VF_RIGHT_PLANE], p);

		return p;
	}

	//! returns a bounding box enclosing the whole view frustum
	inline const core::aabbox3d<f32> &SViewFrustum::getBoundingBox() const
	{
		return boundingBox;
	}

	//! recalculates the bounding box member based on the planes
	inline void SViewFrustum::recalculateBoundingBox()
	{
		boundingBox.reset ( cameraPosition );

		boundingBox.addInternalPoint(getFarLeftUp());
		boundingBox.addInternalPoint(getFarRightUp());
		boundingBox.addInternalPoint(getFarLeftDown());
		boundingBox.addInternalPoint(getFarRightDown());
	}

	//! This constructor creates a view frustum based on a projection
	//! and/or view matrix.
	inline SViewFrustum::SViewFrustum(const core::matrix4& mat)
	{
		setFrom ( mat );
	}

/*
	//! This constructor creates a view frustum based on a projection
	//! and/or view matrix.
	inline void SViewFrustum::setFrom(const core::matrix4& mat)
	{
		// left clipping plane
		planes[SViewFrustum::VF_LEFT_PLANE].Normal.X = -(mat(0,3) + mat(0,0));
		planes[SViewFrustum::VF_LEFT_PLANE].Normal.Y = -(mat(1,3) + mat(1,0));
		planes[SViewFrustum::VF_LEFT_PLANE].Normal.Z = -(mat(2,3) + mat(2,0));
		planes[SViewFrustum::VF_LEFT_PLANE].D =		  -(mat(3,3) + mat(3,0));

		// right clipping plane
		planes[SViewFrustum::VF_RIGHT_PLANE].Normal.X = -(mat(0,3) - mat(0,0));
		planes[SViewFrustum::VF_RIGHT_PLANE].Normal.Y = -(mat(1,3) - mat(1,0));
		planes[SViewFrustum::VF_RIGHT_PLANE].Normal.Z = -(mat(2,3) - mat(2,0));
		planes[SViewFrustum::VF_RIGHT_PLANE].D =        -(mat(3,3) - mat(3,0));

		// top clipping plane
		planes[SViewFrustum::VF_TOP_PLANE].Normal.X = -(mat(0,3) - mat(0,1));
		planes[SViewFrustum::VF_TOP_PLANE].Normal.Y = -(mat(1,3) - mat(1,1));
		planes[SViewFrustum::VF_TOP_PLANE].Normal.Z = -(mat(2,3) - mat(2,1));
		planes[SViewFrustum::VF_TOP_PLANE].D =        -(mat(3,3) - mat(3,1));

		// bottom clipping plane
		planes[SViewFrustum::VF_BOTTOM_PLANE].Normal.X = -(mat(0,3) + mat(0,1));
		planes[SViewFrustum::VF_BOTTOM_PLANE].Normal.Y = -(mat(1,3) + mat(1,1));
		planes[SViewFrustum::VF_BOTTOM_PLANE].Normal.Z = -(mat(2,3) + mat(2,1));
		planes[SViewFrustum::VF_BOTTOM_PLANE].D =        -(mat(3,3) + mat(3,1));

		// near clipping plane
		planes[SViewFrustum::VF_NEAR_PLANE].Normal.X = -mat(0,2);
		planes[SViewFrustum::VF_NEAR_PLANE].Normal.Y = -mat(1,2);
		planes[SViewFrustum::VF_NEAR_PLANE].Normal.Z = -mat(2,2);
		planes[SViewFrustum::VF_NEAR_PLANE].D =        -mat(3,2);

		// far clipping plane
		planes[SViewFrustum::VF_FAR_PLANE].Normal.X = -(mat(0,3) - mat(0,2));
		planes[SViewFrustum::VF_FAR_PLANE].Normal.Y = -(mat(1,3) - mat(1,2));
		planes[SViewFrustum::VF_FAR_PLANE].Normal.Z = -(mat(2,3) - mat(2,2));
		planes[SViewFrustum::VF_FAR_PLANE].D =        -(mat(3,3) - mat(3,2));
		// normalize normals

		for (s32 i=0; i<6; ++i)
		{
			const f32 len = core::reciprocal_squareroot ( planes[i].Normal.getLengthSQ() );
			planes[i].Normal = len;
			planes[i].D = len;
		}

		// make bounding box
		recalculateBoundingBox();
	}
*/

	//! This constructor creates a view frustum based on a projection
	//! and/or view matrix.
	inline void SViewFrustum::setFrom(const core::matrix4& mat)
	{
		// left clipping plane
		planes[VF_LEFT_PLANE].Normal.X	= mat[3 ] + mat[0];
		planes[VF_LEFT_PLANE].Normal.Y	= mat[7 ] + mat[4];
		planes[VF_LEFT_PLANE].Normal.Z	= mat[11] + mat[8];
		planes[VF_LEFT_PLANE].D		= mat[15] + mat[12];

		// right clipping plane
		planes[VF_RIGHT_PLANE].Normal.X = mat[3 ] - mat[0];
		planes[VF_RIGHT_PLANE].Normal.Y = mat[7 ] - mat[4];
		planes[VF_RIGHT_PLANE].Normal.Z = mat[11] - mat[8];
		planes[VF_RIGHT_PLANE].D =        mat[15] - mat[12];

		// top clipping plane
		planes[VF_TOP_PLANE].Normal.X = mat[3 ] - mat[1];
		planes[VF_TOP_PLANE].Normal.Y = mat[7 ] - mat[5];
		planes[VF_TOP_PLANE].Normal.Z = mat[11] - mat[9];
		planes[VF_TOP_PLANE].D =        mat[15] - mat[13];

		// bottom clipping plane
		planes[VF_BOTTOM_PLANE].Normal.X = mat[3 ] + mat[1];
		planes[VF_BOTTOM_PLANE].Normal.Y = mat[7 ] + mat[5];
		planes[VF_BOTTOM_PLANE].Normal.Z = mat[11] + mat[9];
		planes[VF_BOTTOM_PLANE].D =        mat[15] + mat[13];

		// far clipping plane
		planes[VF_FAR_PLANE].Normal.X = mat[3 ] - mat[2];
		planes[VF_FAR_PLANE].Normal.Y = mat[7 ] - mat[6];
		planes[VF_FAR_PLANE].Normal.Z = mat[11] - mat[10];
		planes[VF_FAR_PLANE].D =        mat[15] - mat[14];

		// near clipping plane
		planes[VF_NEAR_PLANE].Normal.X = mat[2];
		planes[VF_NEAR_PLANE].Normal.Y = mat[6];
		planes[VF_NEAR_PLANE].Normal.Z = mat[10];
		planes[VF_NEAR_PLANE].D =        mat[14];

		
		// normalize normals
		u32 i;
		for ( i=0; i != 6; ++i)
		{
			const f32 len = - core::reciprocal_squareroot ( planes[i].Normal.getLengthSQ() );
			planes[i].Normal *= len;
			planes[i].D *= len;
		}

		// make bounding box
		recalculateBoundingBox();
	}

	inline void SViewFrustum::setTransformState( video::E_TRANSFORMATION_STATE state)
	{
		switch ( state )
		{
			case video::ETS_VIEW:
				Matrices[ETS_VIEW_PROJECTION_3].setbyproduct_nocheck (	Matrices[ video::ETS_PROJECTION],
																		Matrices[ video::ETS_VIEW]
																	);
				Matrices[ETS_VIEW_MODEL_INVERSE_3] = Matrices[ video::ETS_VIEW];
				Matrices[ETS_VIEW_MODEL_INVERSE_3].makeInverse();
				break;

			case video::ETS_WORLD:
				Matrices[ETS_CURRENT_3].setbyproduct (  Matrices[ ETS_VIEW_PROJECTION_3 ],
														Matrices[ video::ETS_WORLD]	);
				break;
			default:
				break;
		}
	}


} // end namespace scene
} // end namespace irr

#endif


namespace irr
{
namespace scene
{

	//! Scene Node which is a (controlable) camera.
	/* The whole scene will be
	rendered from the cameras point of view. Because the ICameraScenNode
	is a SceneNode, it can be attached to any other scene node, and will
	follow its parents movement, rotation and so on.
	*/
	class ICameraSceneNode : public ISceneNode, public IEventReceiver
	{
	public:

		//! Constructor
		ICameraSceneNode(ISceneNode* parent, ISceneManager* mgr, s32 id, 
			const core::vector3df& position = core::vector3df(0,0,0),
			const core::vector3df& rotation = core::vector3df(0,0,0),
			const core::vector3df& scale = core::vector3df(1.0f,1.0f,1.0f))
			: ISceneNode(parent, mgr, id, position, rotation, scale), IsOrthogonal(false) {}

		//! Destructor
		virtual ~ICameraSceneNode() {};

		//! Sets the projection matrix of the camera. 
		/* The core::matrix4 class has some methods
		to build a projection matrix. e.g: core::matrix4::buildProjectionMatrixPerspectiveFovLH.
		Note that the matrix will only stay as set by this method until one of 
		the following Methods are called: setNearValue, setFarValue, setAspectRatio, setFOV.
		\param projection: The new projection matrix of the camera.  */
		virtual void setProjectionMatrix(const core::matrix4& projection) = 0;

		//! Gets the current projection matrix of the camera.
		/* \return Returns the current projection matrix of the camera. */
		virtual const core::matrix4& getProjectionMatrix() = 0;

		//! Gets the current view matrix of the camera.
		/* \return Returns the current view matrix of the camera. */
		virtual const core::matrix4& getViewMatrix() = 0;

		//! It is possible to send mouse and key events to the camera.
		/* Most cameras
		may ignore this input, but camera scene nodes which are created for 
		example with ISceneManager::addMayaCameraSceneNode or
		ISceneManager::addMeshViewerCameraSceneNode, may want to get this input
		for changing their position, look at target or whatever.  */
		virtual bool OnEvent(SEvent event) = 0;

		//! Sets the look at target of the camera
		/* \param pos: Look at target of the camera. */
		virtual void setTarget(const core::vector3df& pos) = 0;

		//! Gets the current look at target of the camera
		/* \return Returns the current look at target of the camera */
		virtual core::vector3df getTarget() const = 0;

		//! Sets the up vector of the camera.
		/* \param pos: New upvector of the camera. */
		virtual void setUpVector(const core::vector3df& pos) = 0;

		//! Gets the up vector of the camera.
		/* \return Returns the up vector of the camera. */
		virtual core::vector3df getUpVector() const = 0;

		//! Gets the value of the near plane of the camera.
		/* \return Returns the value of the near plane of the camera. */
		virtual f32 getNearValue() = 0;

		//! Gets the value of the far plane of the camera.
		/* \return Returns the value of the far plane of the camera. */
		virtual f32 getFarValue() = 0;

		//! Gets the aspect ratio of the camera.
		/* \return Returns the aspect ratio of the camera. */
		virtual f32 getAspectRatio() = 0;

		//! Gets the field of view of the camera.
		/* \return Returns the field of view of the camera in radiants. */
		virtual f32 getFOV() = 0;

		//! Sets the value of the near clipping plane. (default: 1.0f)
		/* \param zn: New z near value. */
		virtual void setNearValue(f32 zn) = 0;

		//! Sets the value of the far clipping plane (default: 2000.0f)
		/* \param zf: New z far value. */
		virtual void setFarValue(f32 zf) = 0;

		//! Sets the aspect ratio (default: 4.0f / 3.0f)
		/* \param aspect: New aspect ratio. */
		virtual void setAspectRatio(f32 aspect) = 0;

		//! Sets the field of view (Default: PI / 2.5f)
		/* \param fovy: New field of view in radiants. */
		virtual void setFOV(f32 fovy) = 0;

		//! Returns the view frustum. 
		/* Needed sometimes by bspTree or LOD render nodes.
		\return Returns the current view frustum. */
		virtual const SViewFrustum* getViewFrustum() const = 0;

		//! Disables or enables the camera to get key or mouse inputs.
		/* If this is set to true, the camera will respond to key inputs
		 otherwise not. */
		virtual void setInputReceiverEnabled(bool enabled) = 0;

		//! Returns if the input receiver of the camera is currently enabled.
		virtual bool isInputReceiverEnabled() = 0;

		//! Returns if a camera is orthogonal.
		/* This setting does not change anything of the view or projection matrix. However
		it influences how collision detection and picking is done with this camera. */
		virtual bool isOrthogonal() 
		{
			_IRR_IMPLEMENT_MANAGED_MARSHALLING_BUGFIX;
			return IsOrthogonal;
		} 

		//! Sets if this camera should return if it is orthogonal. 
		/* This setting does not change anything of the view or projection matrix. However
		it influences how collision detection and picking is done with this camera. */
		void setIsOrthogonal( bool orthogonal )
		{
			IsOrthogonal = orthogonal;
		}


	private:

		bool IsOrthogonal;
	};

} // end namespace scene
} // end namespace irr

#endif

// Copyright (C) 2002-2007 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __I_DUMMY_TRANSFORMATION_SCENE_NODE_H_INCLUDED__
#define __I_DUMMY_TRANSFORMATION_SCENE_NODE_H_INCLUDED__


namespace irr
{
namespace scene
{

//! Dummy scene node for adding additional transformations to the scene graph.
/* This scene node does not render itself, and does not respond to set/getPosition,
set/getRotation and set/getScale. Its just a simple scene node that takes a 
matrix as relative transformation, making it possible to insert any transformation
anywhere into the scene graph.
This scene node is for example used by the IAnimatedMeshSceneNode for emulating
joint scene nodes when playing skeletal animations.
*/
class IDummyTransformationSceneNode : public ISceneNode
{
public:

	//! constructor
	IDummyTransformationSceneNode(ISceneNode* parent, ISceneManager* mgr, s32 id)
		: ISceneNode(parent, mgr, id) {}

    //! Returns a reference to the current relative transformation matrix.
	//! This is the matrix, this scene node uses instead of scale, translation
	//! and rotation.
	virtual core::matrix4& getRelativeTransformationMatrix() = 0;
};

} // end namespace scene
} // end namespace irr


#endif

// Copyright (C) 2002-2007 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __I_FILE_LIST_H_INCLUDED__
#define __I_FILE_LIST_H_INCLUDED__


namespace irr
{
namespace io
{

//! The Filelist lists all files in a directory.
class IFileList : public virtual IUnknown
{
public:

	//! destructor
	virtual ~IFileList() {};

	//! Returns the amount of files in the filelist.
	//! \return
	//! Returns the amount of files and directories in the file list.
	virtual s32 getFileCount() = 0;

	//! Gets the name of a file in the list, based on an index.
	//! The path is not included in this name. Use getFullFileName for this.
	//! \param index is the zero based index of the file which name should
	//!   be returned. The index has to be smaller than the amount getFileCount() returns.
	//! \return
	//! Returns the file name of the file. Returns 0, if an error occured.
	virtual const c8* getFileName(s32 index) = 0;

	//! Gets the full name of a file in the list, path included, based on an index.
	//! \param index is the zero based index of the file which name should
	//!   be returned. The index has to be smaller than the amount getFileCount() returns.
	//! \return
	//! Returns the file name of the file. Returns 0, if an error occured.
	virtual const c8* getFullFileName(s32 index) = 0;

	//! Returns of the file is a directory
	//! \param
	//! index is the zero based index of the file which name should
	//!   be returned. The index has to be smaller than the amount getFileCount() returns.
	//! \return
	//! Returns true, if the file is a directory, and false, if it is not.
	//!  If an error occurs, the result is undefined.
	virtual bool isDirectory(s32 index) = 0;
};

} // end namespace irr
} // end namespace io


#endif

// Copyright (C) 2002-2007 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __I_GUI_CHECKBOX_H_INCLUDED__
#define __I_GUI_CHECKBOX_H_INCLUDED__


namespace irr
{
namespace gui
{

	//! GUI Check box interface.
	class IGUICheckBox : public IGUIElement
	{
	public:

		//! constructor
		IGUICheckBox(IGUIEnvironment* environment, IGUIElement* parent, s32 id, core::rect<s32> rectangle)
			: IGUIElement(EGUIET_CHECK_BOX, environment, parent, id, rectangle) {}

		//! destructor
		~IGUICheckBox() {};

		//! Set if box is checked.
		virtual void setChecked(bool checked) = 0;

		//! Returns true if box is checked.
		virtual bool isChecked() = 0;
	};

} // end namespace gui
} // end namespace irr

#endif

// Copyright (C) 2002-2007 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __I_GUI_CONTEXT_MENU_H_INCLUDED__
#define __I_GUI_CONTEXT_MENU_H_INCLUDED__


namespace irr
{
namespace gui
{

	//! GUI Context menu interface.
	class IGUIContextMenu : public IGUIElement
	{
	public:

		//! constructor
		IGUIContextMenu(IGUIEnvironment* environment, IGUIElement* parent, s32 id, core::rect<s32> rectangle)
			: IGUIElement(EGUIET_CONTEXT_MENU, environment, parent, id, rectangle) {}

		//! destructor
		~IGUIContextMenu() {};

		//! Returns amount of menu items
		virtual s32 getItemCount() const = 0;

		//! Adds a menu item.
		/* \param text: Text of menu item. Set this to 0 to create
		 an separator instead of a real item, which is the same like
		 calling addSeparator();
		 \param commandId: Command id of menu item, a simple id you may 
		 set to whatever you want.
		 \param enabled: Specifies if the menu item should be enabled.
		 \param hasSubMenu: Set this to true if there should be a submenu
		 at this item. You can acess this submenu via getSubMenu().
		 \return Returns the index of the new item */
		virtual s32 addItem(const wchar_t* text, s32 commandId=-1, bool enabled=true,
			bool hasSubMenu=false,
			bool checked=false
			) = 0;

		//! Adds a separator item to the menu
		virtual void addSeparator() = 0;

		//! Returns text of the menu item.
		/* \param idx: Zero based index of the menu item */
		virtual const wchar_t* getItemText(s32 idx) = 0;

		//! Sets text of the menu item.
		/* \param idx: Zero based index of the menu item
		 \param text: New text of the item. */
		virtual void setItemText(s32 idx, const wchar_t* text) = 0;

		//! Returns if a menu item is enabled
		/* \param idx: Zero based index of the menu item */
		virtual bool isItemEnabled(s32 idx) = 0;

		//! Sets if the menu item should be enabled.
		/* \param idx: Zero based index of the menu item
		 \param enabled: True if it is enabled, otherwise false. */
		virtual void setItemEnabled(s32 idx, bool enabled) = 0;

		//! Sets if the menu item should be checked.
		/* \param idx: Zero based index of the menu item
		 \param enabled: True if it is enabled, otherwise false. */
		virtual void setItemChecked(s32 idx, bool enabled) = 0;


		//! Removes a menu item
		/* \param idx: Zero based index of the menu item */
		virtual void removeItem(s32 idx) = 0;

		//! Removes all menu items
		virtual void removeAllItems() = 0;

		//! Returns the selected item in the menu
		/* \return Index of the selected item, -1 if none selected. */
		virtual s32 getSelectedItem() = 0;

		//! Returns command id of a menu item
		/* \param idx: Zero based index of the menu item */
		virtual s32 getItemCommandId(s32 idx) = 0;

		//! Sets the command id of a menu item
		/* \param idx: Zero based index of the menu item
		 \param id: Command id of menu item, a simple id you may 
		 set to whatever you want. */
		virtual void setItemCommandId(s32 idx, s32 id) = 0;

		//! \return Returns a pointer to the submenu of an item. 
		/* 0 is returned if there is no submenu
		 \param idx: Zero based index of the menu item */
		virtual IGUIContextMenu* getSubMenu(s32 idx) = 0;
	};

} // end namespace gui
} // end namespace irr

#endif

// Copyright (C) 2002-2007 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __I_GUI_COMBO_BOX_H_INCLUDED__
#define __I_GUI_COMBO_BOX_H_INCLUDED__


namespace irr
{
namespace gui
{
	//! Combobox widget
	class IGUIComboBox : public IGUIElement
	{
	public:

		//! constructor
		IGUIComboBox(IGUIEnvironment* environment, IGUIElement* parent, s32 id, core::rect<s32> rectangle)
			: IGUIElement(EGUIET_COMBO_BOX, environment, parent, id, rectangle) {}

		//! destructor
		~IGUIComboBox() {};

		//! Returns amount of items in box
		virtual s32 getItemCount() = 0;

		//! returns string of an item. the idx may be a value from 0 to itemCount-1
		virtual const wchar_t* getItem(s32 idx) = 0;

		//! adds an item and returns the index of it
		virtual s32 addItem(const wchar_t* text) = 0;

		//! deletes all items in the combo box
		virtual void clear() = 0;

		//! returns id of selected item. returns -1 if no item is selected.
		virtual s32 getSelected() = 0;

		//! sets the selected item. Set this to -1 if no item should be selected
		virtual void setSelected(s32 id) = 0;

	};


} // end namespace gui
} // end namespace irr

#endif

// Copyright (C) 2002-2007 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __I_GUI_EDIT_BOX_H_INCLUDED__
#define __I_GUI_EDIT_BOX_H_INCLUDED__


namespace irr
{
namespace gui
{
	class IGUIFont;

	//! Single line edit box for editing simple text.
	class IGUIEditBox : public IGUIElement
	{
	public:

		//! constructor
		IGUIEditBox(IGUIEnvironment* environment, IGUIElement* parent, s32 id, core::rect<s32> rectangle)
			: IGUIElement(EGUIET_EDIT_BOX, environment, parent, id, rectangle) {}

		//! destructor
		~IGUIEditBox() {};

		//! Sets another skin independent font.
		/* If this is set to zero, the button uses the font of the skin.
		 \param font: New font to set. */
		virtual void setOverrideFont(IGUIFont* font=0) = 0;

		//! Sets another color for the text.
		/* If set, the edit box does not use the EGDC_BUTTON_TEXT color defined
         in the skin, but the set color instead. You don't need to call 
		 IGUIEditBox::enableOverrrideColor(true) after this, this is done
		 by this function.
		 If you set a color, and you want the text displayed with the color
		 of the skin again, call IGUIEditBox::enableOverrideColor(false);
		 \param color: New color of the text. */
		virtual void setOverrideColor(video::SColor color) = 0;

		//! Sets if the text should use the overide color or the color in the gui skin.
		/* \param enable: If set to true, the override color, which can be set
		 with IGUIEditBox::setOverrideColor is used, otherwise the
		 EGDC_BUTTON_TEXT color of the skin. */
		virtual void enableOverrideColor(bool enable) = 0;

		//! Sets the maximum amount of characters which may be entered in the box.
		/* \param max: Maximum amount of characters. If 0, the character amount is 
		 infinity. */
		virtual void setMax(s32 max) = 0;

		//! Returns maximum amount of characters, previously set by setMax();
		virtual s32 getMax() = 0;
	};


} // end namespace gui
} // end namespace irr

#endif

// Copyright (C) 2002-2007 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __I_GUI_FILE_OPEN_DIALOG_H_INCLUDED__
#define __I_GUI_FILE_OPEN_DIALOG_H_INCLUDED__


namespace irr
{
namespace gui
{

	//! Standard file chooser dialog.
	class IGUIFileOpenDialog : public IGUIElement
	{
	public:

		//! constructor
		IGUIFileOpenDialog(IGUIEnvironment* environment, IGUIElement* parent, s32 id, core::rect<s32> rectangle)
			: IGUIElement(EGUIET_FILE_OPEN_DIALOG, environment, parent, id, rectangle) {}

		//! destructor
		virtual ~IGUIFileOpenDialog() {};

		//! Returns the filename of the selected file. Returns NULL, if no file was selected.
		virtual const wchar_t* getFilename() = 0;

	};


} // end namespace gui
} // end namespace irr

#endif

// Copyright (C) 2002-2007 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __I_GUI_COLOR_SELECT_DIALOG_H_INCLUDED__
#define __I_GUI_COLOR_SELECT_DIALOG_H_INCLUDED__


namespace irr
{
namespace gui
{

	//! Standard file chooser dialog.
	class IGUIColorSelectDialog : public IGUIElement
	{
	public:

		//! constructor
		IGUIColorSelectDialog(IGUIEnvironment* environment, IGUIElement* parent, s32 id, core::rect<s32> rectangle)
			: IGUIElement(EGUIET_COLOR_SELECT_DIALOG, environment, parent, id, rectangle) {}

		//! destructor
		virtual ~IGUIColorSelectDialog() {};


	};


} // end namespace gui
} // end namespace irr

#endif

// Copyright (C) 2002-2007 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __I_GUI_FONT_H_INCLUDED__
#define __I_GUI_FONT_H_INCLUDED__


namespace irr
{
namespace gui
{

//! An enum for the different types of GUI font.
enum EGUI_FONT_TYPE
{
	//! Bitmap fonts loaded from an XML file or a texture.
	EGFT_BITMAP = 0,

	//! Scalable vector fonts loaded from an XML file. 
	//! These fonts reside in system memory and use no video memory 
	//! until they are displayed. These are slower than bitmap fonts
	//! but can be easily scaled and rotated.
	EGFT_VECTOR,

	//! A font which uses a the native API provided by the operating system.
	//! Currently not used.
	EGFT_OS,

	//! An external font type provided by the user.
	EGFT_CUSTOM
};

//! Font interface.
class IGUIFont : public virtual IUnknown
{
public:

	//! Destructor
	virtual ~IGUIFont() {};

	//! Draws an text and clips it to the specified rectangle if wanted.
	/* \param text: Text to draw
	 \param position: Rectangle specifying position where to draw the text.
	 \param color: Color of the text
	 \param hcenter: Specifiies if the text should be centered horizontally into the rectangle.
	 \param vcenter: Specifiies if the text should be centered vertically into the rectangle.
	 \param clip: Optional pointer to a rectangle against which the text will be clipped.
	 If the pointer is null, no clipping will be done. */
	virtual void draw(const wchar_t* text, const core::rect<s32>& position, 
		video::SColor color, bool hcenter=false, bool vcenter=false,
		const core::rect<s32>* clip=0) = 0;

	//! Calculates the dimension of a text.
	/* \return Returns width and height of the area covered by the text if it would be
	  drawn. */
	virtual core::dimension2d<s32> getDimension(const wchar_t* text) = 0;

	//! Calculates the index of the character in the text which is on a specific position.
	/* \param text: Text string.
	\param pixel_x: X pixel position of which the index of the character will be returned.
	\return Returns zero based index of the character in the text, and -1 if no no character
	is on this position. (=the text is too short). */
	virtual s32 getCharacterFromPos(const wchar_t* text, s32 pixel_x) = 0;

	//! Returns the type of this font
	virtual EGUI_FONT_TYPE getType() { return EGFT_CUSTOM; }

	//! Sets global kerning for the font.
	virtual void setKerningWidth (s32 kerning) = 0;
	virtual void setKerningHeight (s32 kerning) = 0;

	//! Gets kerning values (distance between letters) for the font. If no parameters are provided,
	/* the global kerning distance is returned.
	\param thisLetter: If this parameter is provided, the left side kerning for this letter is added
	to the global kerning value. For example, a space might only be one pixel wide, but it may
	be displayed as several pixels.
	\param previousLetter: If provided, kerning is calculated for both letters and added to the global
	kerning value. For example, in a font which supports kerning pairs a string such as 'Wo' may have 
	the 'o' tucked neatly under the 'W'.
	*/
	virtual s32 getKerningWidth(const wchar_t* thisLetter=0, const wchar_t* previousLetter=0) = 0;

	//! Returns the distance between letters
	virtual s32 getKerningHeight() = 0;

};

} // end namespace gui
} // end namespace irr

#endif

// Copyright (C) 2002-2006 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __I_GUI_FONT_BITMAP_H_INCLUDED__
#define __I_GUI_FONT_BITMAP_H_INCLUDED__


#ifndef __I_GUI_SPRITE_BANK_H_INCLUDED__
#define __I_GUI_SPRITE_BANK_H_INCLUDED__


namespace irr
{

namespace video
{
	class ITexture;
} // end namespace video

namespace gui
{

struct SGUISpriteFrame
{
	u32 textureNumber;
	u32 rectNumber;
};

struct SGUISprite
{
	SGUISprite() : Frames(), frameTime(0) { };
	core::array<SGUISpriteFrame> Frames;
	u32 frameTime;
};


//! Sprite bank interface.
class IGUISpriteBank : public virtual IUnknown
{
public:

	//! Destructor
	virtual ~IGUISpriteBank() {};

	//! Returns the list of rectangles held by the sprite bank
	virtual core::array< core::rect<s32> >& getPositions() = 0;

	//! Returns the array of animated sprites within the sprite bank
	virtual core::array< SGUISprite >& getSprites() = 0;

	//! Returns the number of textures held by the sprite bank
	virtual u32 getTextureCount() = 0;

	//! Gets the texture with the specified index
	virtual video::ITexture* getTexture(u32 index) = 0;

	//! Adds a texture to the sprite bank
	virtual void addTexture(video::ITexture* texture) = 0;

	//! Changes one of the textures in the sprite bank
	virtual void setTexture(u32 index, video::ITexture* texture) = 0;

	//! Draws a sprite in 2d with position and color
	virtual void draw2DSprite(u32 index, const core::position2di& pos, const core::rect<s32>* clip=0,
			const video::SColor& color= video::SColor(255,255,255,255),
				u32 starttime=0, u32 currenttime=0, bool loop=true, bool center=false) = 0;

};

} // end namespace gui
} // end namespace irr

#endif // __I_GUI_SPRITE_BANK_H_INCLUDED__



namespace irr
{
namespace gui
{

//! Font interface.
class IGUIFontBitmap : public IGUIFont
{
public:

	//! Destructor
	virtual ~IGUIFontBitmap() {};

	//! Returns the type of this font
	virtual EGUI_FONT_TYPE getType() { return EGFT_BITMAP; }

	//! returns the parsed Symbol Information
	virtual IGUISpriteBank* getSpriteBank() = 0;

	//! returns the sprite number from a given character
	virtual u32 getSpriteNoFromChar(const wchar_t *c) = 0;

	//! Gets kerning values (distance between letters) for the font. If no parameters are provided,
	/* the global kerning distance is returned.
	\param thisLetter: If this parameter is provided, the left side kerning for this letter is added
	to the global kerning value. For example, a space might only be one pixel wide, but it may
	be displayed as several pixels.
	\param previousLetter: If provided, kerning is calculated for both letters and added to the global
	kerning value. For example, EGFT_BITMAP will add the right kerning value of previousLetter to the
	left side kerning value of thisLetter, then add the global value.
	*/
	virtual s32 getKerningWidth(const wchar_t* thisLetter=0, const wchar_t* previousLetter=0) = 0;

};

} // end namespace gui
} // end namespace irr

#endif

// Copyright (C) 2002-2007 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __I_GUI_IMAGE_H_INCLUDED__
#define __I_GUI_IMAGE_H_INCLUDED__


namespace irr
{
namespace gui
{

	//! GUI element displaying an image.
	class IGUIImage : public IGUIElement
	{
	public:

		//! constructor
		IGUIImage(IGUIEnvironment* environment, IGUIElement* parent, s32 id, core::rect<s32> rectangle)
			: IGUIElement(EGUIET_IMAGE, environment, parent, id, rectangle) {}

		//! destructor
		~IGUIImage() {};

		//! sets an image
		virtual void setImage(video::ITexture* image) = 0;

		//! sets if the image should use its alpha channel to draw itself
		virtual void setUseAlphaChannel(bool use) = 0;
	};


} // end namespace gui
} // end namespace irr

#endif

// Copyright (C) 2002-2007 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __I_GUI_IN_OUT_FADER_H_INCLUDED__
#define __I_GUI_IN_OUT_FADER_H_INCLUDED__


namespace irr
{
namespace gui
{

	//! Element for fading out or in
	/*	Here is a small example on how the class is used. In this example we fade
	in from a total red screen in the beginning. As you can see, the fader is not
	only useful for dramatic in and out fading, but also to show that the player
	is hit in a first person shooter game for example.
	\code
	gui::IGUIInOutFader fader = device->getGUIEnvironment()->addInOutFader();
	fader->setColor(video::SColor(0,255,0,0));
	fader->fadeIn(4000);
	\endcode
	*/
	class IGUIInOutFader : public IGUIElement
	{
	public:

		//! constructor
		IGUIInOutFader(IGUIEnvironment* environment, IGUIElement* parent, s32 id, core::rect<s32> rectangle)
			: IGUIElement(EGUIET_IN_OUT_FADER, environment, parent, id, rectangle) {}

		//! destructor
		~IGUIInOutFader() {};

		//! Gets the color to fade out to or to fade in from.
		virtual video::SColor getColor() const = 0;

		//! Sets the color to fade out to or to fade in from.
		//! \param color: Color to where it is faded out od from it is faded in.
		virtual void setColor(video::SColor color) = 0;
		virtual void setColor(video::SColor source, video::SColor dest) = 0;

		//! Starts the fade in process. In the beginning the whole rect is drawn by
		//! the set color (black by default) and at the end of the overgiven
		//! time the color has faded out.
		//! \param time: Time specifing how long it should need to fade in,
		//! in milliseconds.
		virtual void fadeIn(u32 time) = 0;

		//! Starts the fade out process. In the beginning everything is visible,
		//! and at the end of the time only the set color (black by the fault)
		//! will be drawn.
		//! \param time: Time specifing how long it should need to fade out,
		//! in milliseconds.
		virtual void fadeOut(u32 time) = 0;

		//! Returns if the fade in or out process is done.
		virtual bool isReady() const = 0;
	};


} // end namespace gui
} // end namespace irr

#endif

// Copyright (C) 2002-2007 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __I_GUI_LIST_BOX_BAR_H_INCLUDED__
#define __I_GUI_LIST_BOX_BAR_H_INCLUDED__


namespace irr
{
namespace gui
{
	class IGUIFont;
	class IGUISpriteBank;

	//! Default list box GUI element.
	class IGUIListBox : public IGUIElement
	{
	public:

		//! constructor
		IGUIListBox(IGUIEnvironment* environment, IGUIElement* parent, s32 id, core::rect<s32> rectangle)
			: IGUIElement(EGUIET_LIST_BOX, environment, parent, id, rectangle) {}

		//! destructor
		~IGUIListBox() {};

		//! returns amount of list items
		virtual s32 getItemCount() = 0;

		//! returns string of a list item. the may id be a value from 0 to itemCount-1
		virtual const wchar_t* getListItem(s32 id) = 0;

		//! adds an list item, returns id of item
		virtual s32 addItem(const wchar_t* text) = 0;

		//! adds an list item with an icon
		//! \param text Text of list entry
		//! \param icon Sprite index of the Icon within the current sprite bank. Set it to -1 if you want no icon
		//! \return
		//! returns the id of the new created item
		virtual s32 addItem(const wchar_t* text, s32 icon) = 0;

		//! Removes an item from the list
		virtual void removeItem(s32 index) = 0;

		//! Sets the sprite bank which should be used to draw list icons. This font is set to the sprite bank of
		//! the built-in-font by default. A sprite can be displayed in front of every list item.
		//! An icon is an index within the icon sprite bank. Several default icons are available in the
		//! skin through getIcon
		virtual void setSpriteBank(IGUISpriteBank* bank) = 0;

		//! clears the list, deletes all items in the listbox
		virtual void clear() = 0;

		//! returns id of selected item. returns -1 if no item is selected.
		virtual s32 getSelected() = 0;

		//! sets the selected item. Set this to -1 if no item should be selected
		virtual void setSelected(s32 id) = 0;
	};


} // end namespace gui
} // end namespace irr

#endif

// Copyright (C) 2002-2007 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __I_GUI_MESH_VIEWER_H_INCLUDED__
#define __I_GUI_MESH_VIEWER_H_INCLUDED__


namespace irr
{

namespace video
{
	class SMaterial;
} // end namespace video

namespace scene
{
	class IAnimatedMesh;
} // end namespace scene

namespace gui
{

	//! 3d mesh viewing GUI element.
	class IGUIMeshViewer : public IGUIElement
	{
	public:

		//! constructor
		IGUIMeshViewer(IGUIEnvironment* environment, IGUIElement* parent, s32 id, core::rect<s32> rectangle)
			: IGUIElement(EGUIET_MESH_VIEWER, environment, parent, id, rectangle) {}

		//! destructor
		~IGUIMeshViewer() {};

		//! sets the mesh to be shown
		virtual void setMesh(scene::IAnimatedMesh* mesh) = 0;

		//! sets the material
		virtual void setMaterial(const video::SMaterial& material) = 0;

		//! gets the material
		virtual const video::SMaterial& getMaterial() = 0;

	};


} // end namespace gui
} // end namespace irr

#endif

// Copyright (C) 2002-2007 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __I_GUI_SCROLL_BAR_H_INCLUDED__
#define __I_GUI_SCROLL_BAR_H_INCLUDED__


namespace irr
{
namespace gui
{

	//! Default scroll bar GUI element.
	class IGUIScrollBar : public IGUIElement
	{
	public:

		//! constructor
		IGUIScrollBar(IGUIEnvironment* environment, IGUIElement* parent, s32 id, core::rect<s32> rectangle)
			: IGUIElement(EGUIET_SCROLL_BAR, environment, parent, id, rectangle) {}

		//! destructor
		~IGUIScrollBar() {};

		//! sets the maximum value of the scrollbar. must be > 0
		virtual void setMax(s32 max) = 0;

		//! sets the small step value
		virtual void setSmallStep(s32 step) = 0;

		//! gets the current position of the scrollbar
		virtual s32 getPos() = 0;

		//! sets the current position of the scrollbar
		virtual void setPos(s32 pos) = 0;
	};


} // end namespace gui
} // end namespace irr

#endif

// Copyright (C) 2002-2007 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __I_GUI_STATIC_TEXT_H_INCLUDED__
#define __I_GUI_STATIC_TEXT_H_INCLUDED__


namespace irr
{
namespace gui
{
	class IGUIFont;

	//! Multi or single line text label.
	class IGUIStaticText : public IGUIElement
	{
	public:

		//! constructor
		IGUIStaticText(IGUIEnvironment* environment, IGUIElement* parent, s32 id, core::rect<s32> rectangle)
			: IGUIElement(EGUIET_STATIC_TEXT, environment, parent, id, rectangle) {}

		//! destructor
		~IGUIStaticText() {};

		//! Sets another skin independent font.
		/* If this is set to zero, the button uses the font of the skin.
		\param font: New font to set. */
		virtual void setOverrideFont(IGUIFont* font=0) = 0;

		//! Gets the override font (if any)
		//! \return The override font (may be 0)
		virtual IGUIFont * getOverrideFont(void) = 0;

		//! Sets another color for the text.
		/* If set, the static text does not use the EGDC_BUTTON_TEXT color defined
         in the skin, but the set color instead. You don't need to call 
		 IGUIStaticText::enableOverrrideColor(true) after this, this is done
		 by this function.
		 If you set a color, and you want the text displayed with the color
		 of the skin again, call IGUIStaticText::enableOverrideColor(false);
		 \param color: New color of the text. */
		virtual void setOverrideColor(video::SColor color) = 0;

		//! Gets the override color
		//! \return: The override color
		virtual video::SColor const & getOverrideColor(void) = 0;

		//! Sets if the static text should use the overide color or the color in the gui skin.
		/* \param enable: If set to true, the override color, which can be set
		with IGUIStaticText::setOverrideColor is used, otherwise the
		EGDC_BUTTON_TEXT color of the skin. */
		virtual void enableOverrideColor(bool enable) = 0;

		//! Checks if an override color is enabled
		//! \return true if the override color is enabled, false otherwise
		virtual bool isOverrideColorEnabled(void) = 0;

		//! Enables or disables word wrap for using the static text as multiline text control.
		/* \param enable: If set to true, words going over one line are 
		 breaked to the next line. */
		virtual void setWordWrap(bool enable) = 0;

		//! Checks if word wrap is enabled
		//! \return true if word wrap is enabled, false otherwise
		virtual bool isWordWrapEnabled(void) = 0;

		//! Returns the height of the text in pixels when it is drawn. 
		/* This is useful for adjusting the layout of gui elements based on the height 
		 of the multiline text in this element. 
		 \return Returns height of text in pixels. */
		virtual s32 getTextHeight() = 0;

		//! Returns the width of the current text, in the current font
		/* If the text is broken, this returns the width of the widest line
		 \return The width of the text, or the widest broken line. */
		virtual s32 getTextWidth(void) = 0;

	};


} // end namespace gui
} // end namespace irr

#endif


// Copyright (C) 2002-2007 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __I_GUI_TAB_CONTROL_H_INCLUDED__
#define __I_GUI_TAB_CONTROL_H_INCLUDED__


namespace irr
{
namespace gui
{
	//! A tab, onto which other gui elements could be added.
	class IGUITab : public IGUIElement
	{
	public:

		//! constructor
		IGUITab(IGUIEnvironment* environment, IGUIElement* parent, s32 id, core::rect<s32> rectangle)
			: IGUIElement(EGUIET_TAB, environment, parent, id, rectangle) {}

		//! destructor
		virtual ~IGUITab() {};

		//! Returns number of tab if in tabcontrol.
		/* Can be accessed later IGUITabControl::getTab() by this number. */
		virtual s32 getNumber() = 0;

		//! sets if the tab should draw its background
		virtual void setDrawBackground(bool draw=true) = 0;

		//! sets the color of the background, if it should be drawn.
		virtual void setBackgroundColor(video::SColor c) = 0;
	};

	//! A standard tab control
	class IGUITabControl : public IGUIElement
	{
	public:

		//! constructor
		IGUITabControl(IGUIEnvironment* environment, IGUIElement* parent, s32 id, core::rect<s32> rectangle)
			: IGUIElement(EGUIET_TAB_CONTROL, environment, parent, id, rectangle) {}

		//! destructor
		virtual ~IGUITabControl() {};

		//! Adds a tab
		virtual IGUITab* addTab(const wchar_t* caption, s32 id=-1) = 0;

		//! Returns amount of tabs in the tabcontrol
		virtual s32 getTabcount() = 0;

		//! Returns a tab based on zero based index
		/* \param idx: zero based index of tab. Is a value betwenn 0 and getTabcount()-1;
		\return Returns pointer to the Tab. Returns 0 if no tab
		 is corresponding to this tab. */
		virtual IGUITab* getTab(s32 idx) = 0;

		//! Brings a tab to front.
		/* \param idx: number of the tab.
		 \return Returns true if successful. */
		virtual bool setActiveTab(s32 idx) = 0;

		//! Brings a tab to front.
		/* \param idx: pointer to the tab.
		 \return Returns true if successful. */
		virtual bool setActiveTab(IGUIElement *tab) = 0;

		//! Returns which tab is currently active
		virtual s32 getActiveTab() = 0;
	};


} // end namespace gui
} // end namespace irr

#endif

// Copyright (C) 2002-2007 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __I_GUI_TOOL_BAR_H_INCLUDED__
#define __I_GUI_TOOL_BAR_H_INCLUDED__


namespace irr
{
namespace video
{
	class ITexture;
} // end namespace video
namespace gui
{
	class IGUIButton;

	//! Stays at the top of its parent like the menu bar and contains tool buttons
	class IGUIToolBar : public IGUIElement
	{
	public:

		//! constructor
		IGUIToolBar(IGUIEnvironment* environment, IGUIElement* parent, s32 id, core::rect<s32> rectangle)
			: IGUIElement(EGUIET_TOOL_BAR, environment, parent, id, rectangle) {}

		//! destructor
		~IGUIToolBar() {};

		//! Adds a button to the tool bar
		virtual IGUIButton* addButton(s32 id=-1, const wchar_t* text=0,const wchar_t* tooltiptext=0,
			video::ITexture* img=0, video::ITexture* pressedimg=0,
			bool isPushButton=false, bool useAlphaChannel=false) = 0;
	};


} // end namespace gui
} // end namespace irr

#endif

// Copyright (C) 2002-2007 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __I_LIGHT_SCENE_NODE_H_INCLUDED__
#define __I_LIGHT_SCENE_NODE_H_INCLUDED__


namespace irr
{
namespace scene
{

//! Scene node which is a dynamic light. 
/* You can switch the light on and off by 
making it visible or not, and let it be animated by ordinary scene node animators.
If you set the light type to be directional, you will need to set the direction of the
light source manually in the SLight structure, the position of the scene node will have no
effect on this direction.
*/
class ILightSceneNode : public ISceneNode
{
public:

	//! constructor
	ILightSceneNode(ISceneNode* parent, ISceneManager* mgr, s32 id, 
		const core::vector3df& position = core::vector3df(0,0,0))
		: ISceneNode(parent, mgr, id, position) {}

	//! Sets the light data associated with this ILightSceneNode
	virtual void setLightData(const video::SLight& light) = 0;

	//! Gets the light data associated with this ILightSceneNode
	//! \return Returns the light data.
	virtual video::SLight& getLightData() = 0;

};

} // end namespace scene
} // end namespace irr


#endif

// Copyright (C) 2002-2007 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __I_MESH_CACHE_H_INCLUDED__
#define __I_MESH_CACHE_H_INCLUDED__


namespace irr
{

namespace scene
{
	class IMesh;
	class IAnimatedMesh;
	class IAnimatedMeshSceneNode;
	class IMeshLoader;

	//!	The mesh cache stores already loaded meshes and provides an interface to them.
	/* You can access it using ISceneManager::getMeshCache(). All existing scene managers
	will return a pointer to the same mesh cache, because it is shared between them. With 
	this interface, it is possible to manually add new loaded meshes (if
	ISceneManager::getMesh() is not sufficient), to remove them and to iterate through
	already loaded meshes.  */
	class IMeshCache : public virtual IUnknown
	{
	public:

		//! destructor
		virtual ~IMeshCache() {};

		//! Adds a mesh to the internal list of loaded meshes.
		/* Usually, ISceneManager::getMesh() is called to load a mesh from a file.
		That method searches the list of loaded meshes if a mesh has already been loaded and
		returns a pointer to if	it is in that list and already in memory. Otherwise it loads
		the mesh. With IMeshCache::addMesh(), it is possible to pretend that a mesh already
		has been loaded. This method can be used for example by mesh loaders who need to
		load more than one mesh with one call. They can add additional meshes with this
		method to the scene manager. The COLLADA loader for example uses this method.
		\param filename: Filename of the mesh. When called ISceneManager::getMesh() with this 
		parameter, the method will return the mesh parameter given with this method. 
		\param mesh: Pointer to a mesh which will now be referenced by this name. */ 
		virtual void addMesh(const c8* filename, IAnimatedMesh* mesh) = 0;

		//! Removes a mesh from the cache.
		/* After loading a mesh with getMesh(), the mesh can be removed from the cache
		using this method, freeing a lot of memory.	*/
		virtual void removeMesh(IAnimatedMesh* mesh) = 0;

		//! Returns amount of loaded meshes in the cache.
		/* You can load new meshes into the cache using getMesh() and addMesh(). 
		If you ever need to access the internal mesh cache, you can do this using
		removeMesh(), getMeshNumber(), getMeshByIndex() and getMeshFilename() */
		virtual s32 getMeshCount() = 0;

		//! Returns current index number of the mesh, and -1 if it is not in the cache.
		virtual s32 getMeshIndex(IAnimatedMesh* mesh) = 0;

		//! Returns a mesh based on its index number.
		/* \param index: Index of the mesh, number between 0 and getMeshCount()-1. 
		Note that this number is only valid until a new mesh is loaded or removed *
		\return Returns pointer to the mesh or 0 if there is none with this number. */
		virtual IAnimatedMesh* getMeshByIndex(s32 index) = 0;

		//! Returns name of a mesh based on its index number. 
		/* \param index: Index of the mesh, number between 0 and getMeshCount()-1. 
		Note that this is only valid until a new mesh is loaded */
		virtual const c8* getMeshFilename(s32 index) = 0;

		//! Returns the filename of a loaded mesh, if there is any.
		/* Returns 0 if there is none. */
		virtual const c8* getMeshFilename(IAnimatedMesh* mesh) = 0;

		//! Returns the filename of a loaded mesh, if there is any.
		/* Returns 0 if there is none.*/
		virtual const c8* getMeshFilename(IMesh* mesh) = 0;
	};


} // end namespace scene
} // end namespace irr

#endif

// Copyright (C) 2002-2007 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __I_MESH_SCENE_NODE_H_INCLUDED__
#define __I_MESH_SCENE_NODE_H_INCLUDED__


namespace irr
{
namespace scene
{

class IMesh;


//! A scene node displaying a static mesh
class IMeshSceneNode : public ISceneNode
{
public:

	//! constructor
	IMeshSceneNode(ISceneNode* parent, ISceneManager* mgr, s32 id, 
		const core::vector3df& position, const core::vector3df& rotation,
			const core::vector3df& scale)
		: ISceneNode(parent, mgr, id, position, rotation, scale) {}

	//! Sets a new mesh to display
	virtual void setMesh(IMesh* mesh) = 0;

	//! Returns the current mesh
	virtual IMesh* getMesh(void) = 0;

	//! Sets if the scene node should not copy the materials of the mesh but use them in a read only style.
	/* In this way it is possible to change the materials a mesh causing all mesh scene nodes 
	referencing this mesh to change too. */
	virtual void setReadOnlyMaterials(bool readonly) = 0;

	//! Returns if the scene node should not copy the materials of the mesh but use them in a read only style
	virtual bool isReadOnlyMaterials() = 0;
};

} // end namespace scene
} // end namespace irr


#endif

// Copyright (C) 2002-2007 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __I_MESH_MANIPULATOR_H_INCLUDED__
#define __I_MESH_MANIPULATOR_H_INCLUDED__


namespace irr
{
namespace scene
{

	class IMesh;
	class IAnimatedMesh;
	struct SMesh;

	//! An interface for easily manipulate meshes.
	/* Scale, set alpha value, flip surfaces, and so on. This exists for fixing problems 
	with wrong imported or exported meshes quickly after loading. It is not intended for doing mesh
	modifications and/or animations during runtime.
	*/
	class IMeshManipulator : public virtual IUnknown
	{
	public:

		//! destructor
		virtual ~IMeshManipulator() {};

		//! Flips the direction of surfaces. 
		/* Changes backfacing triangles to frontfacing
		triangles and vice versa.
		\param mesh: Mesh on which the operation is performed. */
		virtual void flipSurfaces(IMesh* mesh) const = 0;

		//! Sets the alpha vertex color value of the whole mesh to a new value.
		/* \param mesh: Mesh on which the operation is performed.
		 \param alpha: New alpha value. Must be a value between 0 and 255. */
		virtual void setVertexColorAlpha(IMesh* mesh, s32 alpha) const = 0;

		//! Sets the colors of all vertices to one color
		virtual void setVertexColors(IMesh* mesh, video::SColor color) const = 0;

		//! Recalculates all normals of the mesh.
		/* \param mesh: Mesh on which the operation is performed. */
		virtual void recalculateNormals(IMesh* mesh, bool smooth = false) const = 0;

		//! Recalculates all normals of the mesh buffer.
		/* \param buffer: Mesh buffer on which the operation is performed. */
		virtual void recalculateNormals(IMeshBuffer* buffer, bool smooth = false) const = 0;

		//! Scales the whole mesh.
		/* \param mesh: Mesh on which the operation is performed.
		 \param scale: Scale factor. */
		virtual void scaleMesh(IMesh* mesh, const core::vector3df& scale) const = 0;

		//! Applies a transformation
		/* \param mesh: Mesh on which the operation is performed.
		 \param m: transformation matrix. */
		virtual void transformMesh(IMesh* mesh, const core::matrix4& m) const = 0;

		//! Clones a static IMesh into a modifyable SMesh.
		/* All meshbuffers in the returned SMesh
		are of type SMeshBuffer or SMeshBufferLightMap.
		\param mesh: Mesh to copy.
		\return Returns the cloned mesh.
		If you no longer need the cloned mesh, you should call SMesh::drop().
		See IUnknown::drop() for more information. */
		virtual SMesh* createMeshCopy(IMesh* mesh) const = 0;


		//! Creates a planar texture mapping on the mesh
		/* \param mesh: Mesh on which the operation is performed.
		\param resolution: resolution of the planar mapping. This is the value
		specifying which is the relation between world space and 
		texture coordinate space. */
		virtual void makePlanarTextureMapping(IMesh* mesh, f32 resolution=0.001f) const = 0;

		//! Creates a copy of the mesh, which will only consist of S3DVertexTangents vertices.
        /* This is useful if you want to draw tangent space normal mapped geometry because
		it calculates the tangent and binormal data which is needed there.
		\param mesh: Input mesh
		\return Mesh consiting only of S3DVertexTangents vertices.
		If you no longer need the cloned mesh, you should call IMesh::drop().
		See IUnknown::drop() for more information. */
		virtual IMesh* createMeshWithTangents(IMesh* mesh) const = 0;

		//! Unweld vertices
		virtual IMesh* createMeshUniquePrimitives(IMesh* mesh) const = 0;

		//! Recalculates the bounding box for a meshbuffer
		virtual void recalculateBoundingBox(scene::IMeshBuffer* buffer) const = 0;

		//! Returns amount of polygons in mesh.
		virtual s32 getPolyCount(scene::IMesh* mesh) const = 0;

		//! Returns amount of polygons in mesh.
		virtual s32 getPolyCount(scene::IAnimatedMesh* mesh) const = 0;

		//! create a new AnimatedMesh and adds the mesh to it
		virtual IAnimatedMesh * createAnimatedMesh(scene::IMesh* mesh,
			scene::E_ANIMATED_MESH_TYPE type = scene::EAMT_UNKNOWN) const = 0;

	};

} // end namespace scene
} // end namespace irr


#endif

// Copyright (C) 2002-2007 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __I_META_TRIANGLE_SELECTOR_H_INCLUDED__
#define __I_META_TRIANGLE_SELECTOR_H_INCLUDED__


namespace irr
{
namespace scene
{

//! Interface for making multiple triangle selectors work as one big selector.
/* This is nothing more than a collection of one or more triangle selectors
providing together the interface of one triangle selector. In this way, 
collision tests can be done with different triangle soups in one pass.
*/
class IMetaTriangleSelector : public ITriangleSelector
{
public:

	//! Adds a triangle selector to the collection of triangle selectors
	//! in this metaTriangleSelector.
	//! \param toAdd: Pointer to an triangle selector to add to the list.
	virtual void addTriangleSelector(ITriangleSelector* toAdd) = 0; 

	//! Removes a specific triangle selector which was added before	from the collection.
	//! \param toRemove: Pointer to an triangle selector which is in the list
	//! but will be removed.
	//! \return Returns true if successful, false if not.
	virtual bool removeTriangleSelector(ITriangleSelector* toRemove) = 0;

	//! Removes all triangle selectors from the collection.
	virtual void removeAllTriangleSelectors() = 0;
};

} // end namespace scene
} // end namespace irr


#endif

// Copyright (C) 2002-2007 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __I_IRRLICHT_DEVICE_H_INCLUDED__
#define __I_IRRLICHT_DEVICE_H_INCLUDED__

// Copyright (C) 2002-2007 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __I_CURSOR_CONTROL_H_INCLUDED__
#define __I_CURSOR_CONTROL_H_INCLUDED__


namespace irr
{
namespace gui
{

	//! Interface to manipulate the mouse cursor.
	class ICursorControl : public virtual IUnknown
	{
	public:

		//! Changes the visible state of the mouse cursor.
		/* \param visible: The new visible state. If true, the cursor will be visible,
		if false, it will be invisible. */
		virtual void setVisible(bool visible) = 0;

		//! Returns if the cursor is currently visible.
		/* \return Returns true if the cursor is visible, false if not. */
		virtual bool isVisible() = 0;

		//! Sets the new position of the cursor.
		/* \param pos: New position of the cursor. The position must be between
		(0.0f, 0.0f) and (1.0f, 1.0f), where (0.0f, 0.0f) is 
		the top left corner and (1.0f, 1.0f) is the bottom right corner of the
		render window. */
		virtual void setPosition(const core::position2d<f32> &pos) = 0;

		//! Sets the new position of the cursor.
		/* \param pos: New position of the cursor. The position must be between
		 (0.0f, 0.0f) and (1.0f, 1.0f), where (0.0f, 0.0f) is 
		 the top left corner and (1.0f, 1.0f) is the bottom right corner of the
		 render window. */
		virtual void setPosition(f32 x, f32 y) = 0;

		//! Sets the new position of the cursor.
		/* \param pos: New position of the cursor. The coordinates are pixel units. */
		virtual void setPosition(const core::position2d<s32> &pos) = 0;

		//! Sets the new position of the cursor.
		/* \param pos: New position of the cursor. The coordinates are pixel units. */
		virtual void setPosition(s32 x, s32 y) = 0;

		//! Returns the current position of the mouse cursor.
		/* \return Returns the current position of the cursor. The returned position
		is the position of the mouse cursor in pixel units. */
		virtual core::position2d<s32> getPosition() = 0;

		//! Returns the current position of the mouse cursor.
		/* \return Returns the current position of the cursor. The returned position
		 is a value between (0.0f, 0.0f) and (1.0f, 1.0f), where (0.0f, 0.0f) is 
		 the top left corner and (1.0f, 1.0f) is the bottom right corner of the
		 render window. */
		virtual core::position2d<f32> getRelativePosition() = 0;
	};


} // end namespace gui
} // end namespace irr

#endif

// Copyright (C) 2002-2007 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __IRR_I_VIDEO_MODE_LIST_H_INCLUDED__
#define __IRR_I_VIDEO_MODE_LIST_H_INCLUDED__


namespace irr
{
namespace video
{

	//! A list of all available video modes.
	/* You can get a list via IrrlichtDevice::getVideoModeList(). If you are confused 
	now, because you think you have to create an Irrlicht Device with a video
	mode before being able to get the video mode list, let me tell you that
	there is no need to start up an Irrlicht Device with EDT_DIRECT3D8, EDT_OPENGL or
	EDT_SOFTWARE: For this (and for lots of other reasons) the null device,
	EDT_NULL exists.*/
	class IVideoModeList : public virtual IUnknown
	{
	public:

		//! destructor
		virtual ~IVideoModeList() {}

		//! Gets amount of video modes in the list.
		//! \return Returns amount of video modes.
		virtual s32 getVideoModeCount() const = 0;

		//! Returns the screen size of a video mode in pixels.
		//! \param modeNumber: zero based index of the video mode.
		//! \return Returns size of screen in pixels of the specified video mode.
		virtual core::dimension2d<s32> getVideoModeResolution(s32 modeNumber) const = 0;

		//! Returns the pixel depth of a video mode in bits.
		//! \param modeNumber: zero based index of the video mode.
		//! \return Returns the size of each pixel of the specified video mode in bits.
		virtual s32 getVideoModeDepth(s32 modeNumber) const = 0;

		//! Returns current desktop screen resolution.
		//! \return Returns size of screen in pixels of the current desktop video mode.
		virtual core::dimension2d<s32> getDesktopResolution() const = 0;

		//! Returns the pixel depth of a video mode in bits.
		//! \return Returns the size of each pixel of the current desktop video mode in bits.
		virtual s32 getDesktopDepth() const = 0;
	};

} // end namespace video
} // end namespace irr


#endif

// Copyright (C) 2002-2007 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __I_TIMER_H_INCLUDED__
#define __I_TIMER_H_INCLUDED__


namespace irr
{

//! Interface for getting and manipulating the virtual time
class ITimer : public virtual IUnknown
{
public:

	//! destructor
	virtual ~ITimer() {}

	//! Returns current real time in milliseconds of the system. 
	/* This value does not start with 0 when the application starts.
	For example in one implementation the value returned could be the 
	amount of milliseconds which have elapsed since the system was started. */
	virtual u32 getRealTime() = 0;

	//! Returns current virtual time in milliseconds. 
	/* This value starts with 0 and can be manipulated using setTime(), stopTimer(),
	startTimer(), etc. This value depends on the set speed of the timer if the timer 
	is stopped, etc. If you need the system time, use getRealTime() */
	virtual u32 getTime() = 0;

	//! sets current virtual time
	virtual void setTime(u32 time) = 0;

	//! Stops the virtual timer. 
	/* The timer is reference counted, which means everything which calls 
	stop() will also have to call start(), otherwise the timer may not start/stop
	corretly again. */
	virtual void stop() = 0;

	//! Starts the virtual timer.
	/* The timer is reference counted, which means everything which calls 
	stop() will also have to call start(), otherwise the timer may not start/stop
	corretly again. */
	virtual void start() = 0;

	//! Sets the speed of the timer
	/* The speed is the factor with which the time is running faster or slower then the
	real system time. */
	virtual void setSpeed(f32 speed = 1.0f) = 0;

	//! Returns current speed of the timer
	/* The speed is the factor with which the time is running faster or slower then the
	real system time. */
	virtual f32 getSpeed() = 0;

	//! Returns if the virtual timer is currently stopped
	virtual bool isStopped() = 0;

	//! Advances the virtual time
	/* Makes the virtual timer update the time value based on the real
	time. This is called automatically when calling IrrlichtDevice::run(),
	but you can call it manually if you don't use this method. */
	virtual void tick() = 0;
};

} // end namespace irr

#endif

// Copyright (C) 2002-2007 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __I_OS_OPERATOR_H_INCLUDED__
#define __I_OS_OPERATOR_H_INCLUDED__


namespace irr
{

//! The Operating system operator provides operation system specific methods and informations.
/* Currently only 3 methods are supported. But it will be extended with more functionality
soon. */
class IOSOperator : public virtual IUnknown
{
public:

	//! destructor
	virtual ~IOSOperator() {}

	//! returns the current operation system version as string.
	virtual const wchar_t* getOperationSystemVersion() = 0;

	//! copies text to the clipboard
	virtual void copyToClipboard(const c8* text) = 0;

	//! gets text from the clipboard
	//! \return Returns 0 if no string is in there.
	virtual c8* getTextFromClipboard() = 0;	

	//! gets the processor speed in megahertz
	//! \param Mhz:
	//! \return Returns true if successful, false if not
	virtual bool getProcessorSpeedMHz(irr::u32* MHz) = 0;

	//! gets the total and available system RAM
	//! \param Total: will contain the total system memory
	//! \param Avail: will contain the available memory
	//! \return Returns true if successful, false if not
	virtual bool getSystemMemory(irr::u32* Total, irr::u32* Avail) = 0;

};

} // end namespace

#endif


namespace irr
{
	//! The Irrlicht device. You can create it with createDevice() or createDeviceEx(). 
	/* This is the most important class of the Irrlicht Engine. You can access everything
	in the engine if you have a pointer to an instance of this class. 
	*/
	class IrrlichtDevice : public virtual IUnknown
	{
	public:

		//! destructor
		virtual ~IrrlichtDevice() {};

        //! Runs the device. 
		/* Also increments the virtual timer by calling ITimer::tick();. You can prevent this
		by calling ITimer::stop(); before and ITimer::start() after calling IrrlichtDevice::run().
		Returns false if device wants to be deleted. Use it in this way:
		\code
while(device->run())
{
  // draw everything here
}
		\endcode 
		If you want the device to do nothing if the window is inactive (recommended),
		use this slightly enhanced code instead:
		\code
while(device->run())
  if (device->isWindowActive())
  {
    // draw everything here
  }
		\endcode 
		Note if you are running Irrlicht inside an external, custom created window:
		Calling	Device->run() will cause Irrlicht to dispatch windows messages internally.
		If you are running Irrlicht in your own, custom window, you 
		you can also simply use your own message loop
		using GetMessage, DispatchMessage and whatever and simply don't use this method.
		But note that Irrlicht will not be able to fetch user input then. See 
		irr::SIrrlichtCreationParameters::WindowId for more informations and example code.
		*/
		virtual bool run() = 0;

		//! Cause the device to temporarily pause execution and let other processes to run
		// This should bring down processor usage without major performance loss for Irrlicht
		virtual void yield() = 0;

		//! Pause execution and let other processes to run for a specified amount of time.
		/* It may not wait the full given time, as sleep may be interrupted
		\param timeMs: Time to sleep for in milisecs. 
		\param pauseTimer: If true, pauses the device timer while sleeping
		*/
		virtual void sleep(u32 timeMs, bool pauseTimer=false) = 0;

		//! Provides access to the video driver for drawing 3d and 2d geometry.
		/* \return Returns a pointer the video driver. */
		virtual video::IVideoDriver* getVideoDriver() = 0;

		//! Provides access to the virtual file system.
		/* \return Returns a pointer to the file system. */
		virtual io::IFileSystem* getFileSystem() = 0;

		//! Provides access to the 2d user interface environment.
		/* \return Returns a pointer to the gui environment. */
		virtual gui::IGUIEnvironment* getGUIEnvironment() = 0;

		//! \return Returns a pointer to the scene manager.
		virtual scene::ISceneManager* getSceneManager() = 0;

		//! Provides access to the cursor control.
		/* \return Returns a pointer to the mouse cursor control interface. */
		virtual gui::ICursorControl* getCursorControl() = 0;

		//! Provides access to the logger. 
		/* \return Returns a pointer to the logger. */
		virtual ILogger* getLogger() = 0;

		//! Gets a list with all video modes available. 
		/* If you are confused 
		now, because you think you have to create an Irrlicht Device with a video
		mode before being able to get the video mode list, let me tell you that
		there is no need to start up an Irrlicht Device with EDT_DIRECT3D8, EDT_OPENGL or
		EDT_SOFTWARE: For this (and for lots of other reasons) the null device,
		EDT_NULL exists.
		\return Returns a pointer to a list with all video modes supported
		by the gfx adapter. */
		virtual video::IVideoModeList* getVideoModeList() = 0;

		//! Returns the operation system opertator object.
		/* It provides methods for
		getting operation system specific informations and doing operation system
		specific operations. Like for example exchanging data with the clipboard
		or reading the operation system version. */
		virtual IOSOperator* getOSOperator() = 0;

		//! Returns pointer to the timer.
		/* \return Returns a pointer to the ITimer object. The system time can be retrieved by it as
		well as the virtual time, which also can be manipulated. */
		virtual ITimer* getTimer() = 0;

		//! Sets the caption of the window.
		/* \param text: New text of the window caption. */
		virtual void setWindowCaption(const wchar_t* text) = 0;

		//! Returns if the window is active.
		/* \return Returns true if window is active. If the window is inactive,
		nothing need to be drawn. So if you don't want to draw anything when
		the window is inactive, create your drawing loop this way:
		\code
while(device->run())
  if (device->isWindowActive())
  {
    // draw everything here
  }
		\endcode */
		virtual bool isWindowActive() = 0;

		//! Notifies the device that it should close itself.
		/* IrrlichtDevice::run() will always return false after closeDevice() was called. */
		virtual void closeDevice() = 0;

		//! Returns the version of the engine.
		/* The returned string
		will look like this: "1.2.3" or this: "1.2". */
		virtual const c8* getVersion() = 0;

		//! Sets a new event receiver to receive events.
		virtual void setEventReceiver(IEventReceiver* receiver) = 0;

		//! Returns poinhter to the current event receiver. Returns 0 if there is none.
		virtual IEventReceiver* getEventReceiver() = 0;

		//! Sends a user created event to the engine.
		/* Is is usually not necessary to use this. However, if you are using an own
		input library for example for doing joystick input, you can use this to post key or mouse input 
		events to the engine. Internally, this method only delegates the events further to the 
		scene manager and the GUI environment. */
		virtual void postEventFromUser(SEvent event) = 0;

		//! Sets if the window should be resizeable in windowed mode.
		/* The default is false. This method only works in windowed mode. */
		virtual void setResizeAble(bool resize=false) = 0;
	};

} // end namespace irr

#endif

// Copyright (C) 2002-2006 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __I_SCENE_USER_DATA_SERIALIZER_H_INCLUDED__
#define __I_SCENE_USER_DATA_SERIALIZER_H_INCLUDED__


namespace irr
{
namespace io
{
	class IAttributes;
} // end namespace io
namespace scene
{
	class ISceneNode;

//! Interface to read and write user data to and from .irr files.
/* This interface is to be imlpemented by the user, to make it possible to read 
and write user data when reading or writing .irr files via ISceneManager.
To be used with ISceneManager::loadScene() and ISceneManager::saveScene() */
class ISceneUserDataSerializer
{
public:

	virtual ~ISceneUserDataSerializer() {}

	//! Called when the scene manager read a scene node while loading a file.
	/* The userData pointer contains a list of attributes with userData which
	were attached to the scene node in the read scene file.*/
	virtual void OnReadUserData(ISceneNode* forSceneNode, io::IAttributes* userData) = 0;

	//! Called when the scene manager is writing a scene node to an xml file for example.
	/* Implement this method and return a list of attributes containing the user data
	you want to be saved together with the scene node. Return 0 if no user data should 
	be added. Please note that the scene manager will call drop() to the returned pointer
	after it no longer needs it, so if you didn't create a new object for the return value
	and returning a longer existing IAttributes object, simply call grab() before returning it. */
	virtual io::IAttributes* createUserData(ISceneNode* forSceneNode) = 0;
};

} // end namespace scene
} // end namespace irr

#endif

// Copyright (C) 2002-2007 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __I_SCENE_COLLISION_MANAGER_H_INCLUDED__
#define __I_SCENE_COLLISION_MANAGER_H_INCLUDED__


namespace irr
{


namespace scene
{
	class ISceneNode;
	class ICameraSceneNode;
	class ITriangleSelector;

	//!	The Scene Collision Manager provides methods for performing collision tests and picking on scene nodes.
	class ISceneCollisionManager : public virtual IUnknown
	{
	public:

		//! destructor
		virtual ~ISceneCollisionManager() {};

		//! Finds the collision point of a line and lots of triangles, if there is one.
		//! \param ray: Line with witch collisions are tested.
		//! \param selector: TriangleSelector containing the triangles. It can
		//! be created for example using ISceneManager::createTriangleSelector() or 
		//! ISceneManager::createTriangleOctTreeSelector().
		//! \param outCollisionPoint: If a collision is detected, this will contain the
		//! position of the nearest collision.
		//! \param outTriangle: If a collision is detected, this will contain the triangle
		//! with which the ray collided.
		//! \return Returns true if a collision was detected and false if not.
		virtual bool getCollisionPoint(const core::line3d<f32>& ray,
			ITriangleSelector* selector, core::vector3df& outCollisionPoint,
			core::triangle3df& outTriangle) = 0;

		//! Collides a moving ellipsoid with a 3d world with gravity and returns
		//! the resulting new position of the ellipsoid. This can be used for moving
		//! a character in a 3d world: The character will slide at walls and is able
		//! to walk up stairs. The method used how to calculate the collision result
		//! position is based on the paper "Improved Collision detection and Response"
		//! by Kasper Fauerby.
		//! \param selector: TriangleSelector containing the triangles of the world.
		//! It can be created for example using ISceneManager::createTriangleSelector() or 
		//! ISceneManager::createTriangleOctTreeSelector().
		//! \param ellipsoidPosition: Position of the ellipsoid.
		//! \param ellipsoidRadius: Radius of the ellipsoid.
		//! \param ellipsoidDirectionAndSpeed: Direction and speed of 
		//! the movement of the ellipsoid.
		//! \param triout: Optional parameter where the last triangle causing a 
		//! collision is stored, if there is a collision.
		//! \param outFalling: Is set to true if the ellipsoid is falling down, caused
		//! by gravity.
		//! \param slidingSpeed: DOCUMENTATION NEEDED.
		//! \param gravityDirectionAndSpeed: Direction and force of gravity.
		//! \return Returns the new position of the ellipsoid.
		virtual core::vector3df getCollisionResultPosition(
			ITriangleSelector* selector,
			const core::vector3df &ellipsoidPosition,
			const core::vector3df& ellipsoidRadius, 
			const core::vector3df& ellipsoidDirectionAndSpeed,
			core::triangle3df& triout,
			bool& outFalling,
			f32 slidingSpeed = 0.0005f,
			const core::vector3df& gravityDirectionAndSpeed 
			= core::vector3df(0.0f, 0.0f, 0.0f)) = 0;

		//! Returns a 3d ray which would go through the 2d screen coodinates.
		//! \param pos: Screen coordinates in pixels.
		//! \param camera: Camera from which the ray starts. If null, the
		//! active camera is used. 
		//! \return Returns a ray starting from the position of the camera
		//! and ending at a length of the far value of the camera at a position
		//! which would be behind the 2d screen coodinates.
		virtual core::line3d<f32> getRayFromScreenCoordinates(
			core::position2d<s32> pos, ICameraSceneNode* camera = 0) = 0;

		//! Calculates 2d screen position from a 3d position.
		//! \param pos: 3D position in world space to be transformed into
		//! 2d.
		//! \param camera: Camera to be used. If null, the currently active
		//! camera is used.
		//! \return Returns the 2d screen coordinates which a object in the 
		//! 3d world would have if it would be rendered to the screen. If the 
		//! 3d position is behind the camera, it is set to (-10000,-10000). In
		//! most cases you can ignore this fact, because if you use this method
		//! for drawing a decorator over a 3d object, it will be clipped by the
		//! screen borders.
		virtual core::position2d<s32> getScreenCoordinatesFrom3DPosition(
			core::vector3df pos, ICameraSceneNode* camera=0) = 0;

		//! Returns the scene node, which is currently visible under the overgiven 
		//! screencoordinates, viewed from the currently active camera. The collision
		//! tests are done using a bounding box for each scene node.
		//! \param pos: Position in pixel screen coordinates, under which the returned
		//! scene node will be.
		//! \param idBitMask: Only scene nodes with an id with bits set like in this mask
		//! will be tested. If the BitMask is 0, this feature is disabled.
		//! \param bNoDebugObjects: Doesn't take debug objects into account when true. These
		//  are scene nodes with IsDebugObject() = true.
		//! \return Returns the visible scene node under screen coordinates with matching
		//! bits in its id. If there is no scene node under this position, 0 is returned.
		virtual ISceneNode* getSceneNodeFromScreenCoordinatesBB(core::position2d<s32> pos,
			s32 idBitMask=0, bool bNoDebugObjects = false) = 0;

		//! Returns the nearest scene node which collides with a 3d ray and 
		//! which id matches a bitmask. The collision tests are done using a bounding
		//! box for each scene node.
		//! \param ray: Line with witch collisions are tested.
		//! \param idBitMask: Only scene nodes with an id with bits set like in this mask
		//! will be tested. If the BitMask is 0, this feature is disabled.
		//! \param bNoDebugObjects: Doesn't take debug objects into account when true. These
		//  are scene nodes with IsDebugObject() = true.
		//! \return Returns the scene node nearest to ray.start, which collides with the
		//! ray and matches the idBitMask, if the mask is not null. If no scene
		//! node is found, 0 is returned.
		virtual ISceneNode* getSceneNodeFromRayBB(core::line3d<f32> ray, 
			s32 idBitMask=0, bool bNoDebugObjects = false) = 0;

		//! Returns the scene node, at which the overgiven camera is looking at and
		//! which id matches the bitmask. A ray is simply casted from the position
		//! of the camera to the view target position, and all scene nodes are tested
		//! against this ray. The collision tests are done using a bounding
		//! box for each scene node.
		//! \param camera: Camera from which the ray is casted.
		//! \param idBitMask: Only scene nodes with an id with bits set like in this mask
		//! will be tested. If the BitMask is 0, this feature is disabled.
		//! \param bNoDebugObjects: Doesn't take debug objects into account when true. These
		//  are scene nodes with IsDebugObject() = true.
		//! \return Returns the scene node nearest to the camera, which collides with the
		//! ray and matches the idBitMask, if the mask is not null. If no scene
		//! node is found, 0 is returned.
		virtual ISceneNode* getSceneNodeFromCameraBB(ICameraSceneNode* camera,
			s32 idBitMask=0, bool bNoDebugObjects = false) = 0;
	};


} // end namespace scene
} // end namespace irr

#endif

// Copyright (C) 2002-2007 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __I_MATERIAL_RENDERER_SERVICES_H_INCLUDED__
#define __I_MATERIAL_RENDERER_SERVICES_H_INCLUDED__


namespace irr
{
namespace video  
{

class IVideoDriver;


//! Interface providing some methods for changing advanced, internal states of a IVideoDriver.
class IMaterialRendererServices
{
public: 

	//! destructor
	virtual ~IMaterialRendererServices() {}

	//! Can be called by an IMaterialRenderer to make its work easier.
	//! Sets all basic renderstates if needed.
	//! Basic render states are diffuse, ambient, specular, and emissive color, specular power,
	//! bilinear and trilinear filtering, wireframe mode,
	//! grouraudshading, lighting, zbuffer, zwriteenable, backfaceculling and fog enabling.
	virtual void setBasicRenderStates(const SMaterial& material, 
		const SMaterial& lastMaterial,
		bool resetAllRenderstates) = 0;

	//! Sets a constant for the vertex shader based on a name. This can be used if you used
	//! a high level shader language like GLSL or HLSL to create a shader. Example: If you
	//! created a shader which has variables named 'mWorldViewProj' (containing the 
	//! WorldViewProjection matrix) and another one named 'fTime' containing one float, 
	//! you can set them in your IShaderConstantSetCallBack derived class like this:
	//! \code
	//! virtual void OnSetConstants(video::IMaterialRendererServices* services, s32 userData)
	//! {
	//! 	video::IVideoDriver* driver = services->getVideoDriver();
	//! 
	//! 	f32 time = (f32)os::Timer::getTime()/100000.0f;
	//! 	services->setVertexShaderConstant("fTime", &time, 1);
	//! 
	//! 	core::matrix4 worldViewProj(driver->getTransform(video::ETS_PROJECTION));
	//! 	worldViewProj *= driver->getTransform(video::ETS_VIEW);
	//! 	worldViewProj *= driver->getTransform(video::ETS_WORLD);
	//! 	services->setVertexShaderConstant("mWorldViewProj", worldViewProj.M, 16);
	//! }
	//! \endcode
	//! \param name: Name of the variable
	//! \param floats: Pointer to array of floats
	//! \param count: Amount of floats in array.
	//! \return: Returns true if successful.
	virtual bool setVertexShaderConstant(const c8* name, const f32* floats, int count) = 0;

	//! Sets a vertex shader constant. Can be used if you created a shader using 
	//! pixel/vertex shader assembler or ARB_fragment_program or ARB_vertex_program.
	//! \param data: Data to be set in the constants
	//! \param startRegister: First register to be set
	//! \param constantAmount: Amount of registers to be set. One register consists of 4 floats.
	virtual void setVertexShaderConstant(const f32* data, s32 startRegister, s32 constantAmount=1) = 0;

	//! Sets a constant for the pixel shader based on a name. This can be used if you used
	//! a high level shader language like GLSL or HLSL to create a shader. See 
	//! setVertexShaderConstant() for an example on how to use this.
	//! \param name: Name of the variable
	//! \param floats: Pointer to array of floats
	//! \param count: Amount of floats in array.
	//! \return: Returns true if successful.
	virtual bool setPixelShaderConstant(const c8* name, const f32* floats, int count) = 0;

	//! Sets a pixel shader constant. Can be used if you created a shader using 
	//! pixel/vertex shader assembler or ARB_fragment_program or ARB_vertex_program.
	//! \param data: Data to be set in the constants
	//! \param startRegister: First register to be set.
	//! \param constantAmount: Amount of registers to be set. One register consists of 4 floats.
	virtual void setPixelShaderConstant(const f32* data, s32 startRegister, s32 constantAmount=1) = 0;

	//! Returns a pointer to the IVideoDriver interface
	virtual IVideoDriver* getVideoDriver() = 0;
};

} // end namespace video
} // end namespace irr

#endif

// Copyright (C) 2002-2007 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __I_SCENE_NODE_FACTORY_H_INCLUDED__
#define __I_SCENE_NODE_FACTORY_H_INCLUDED__


namespace irr
{


namespace scene
{
	class ISceneNode;
	
	//!	Interface making it possible to dynamicly create scene nodes 
	/* To be able to add custom scene nodes to Irrlicht and to make it possible for the 
	scene manager to save and load those external scene nodes, simply implement this
	interface and register it in you scene manager via ISceneManager::registerSceneNodeFactory.
	Note: When implementing your own scene node factory, don't call ISceneNodeManager::grab() to
	increase the reference counter of the scene node manager. This is not necessary because the
	scene node manager will grab() the factory anyway, and otherwise cyclic references will
	be created and the scene manager and all its nodes won't get deallocated.
	*/
	class ISceneNodeFactory : public virtual IUnknown
	{
	public:

		//! adds a scene node to the scene graph based on its type id
		/* \param type: Type of the scene node to add.
		\param parent: Parent scene node of the new node, can be null to add the scene node to the root.
		\return Returns pointer to the new scene node or null if not successful. */
		virtual ISceneNode* addSceneNode(ESCENE_NODE_TYPE type, ISceneNode* parent=0) = 0;

		//! adds a scene node to the scene graph based on its type name
		/* \param typeName: Type name of the scene node to add.
		\param parent: Parent scene node of the new node, can be null to add the scene node to the root.
		\return Returns pointer to the new scene node or null if not successful. */
		virtual ISceneNode* addSceneNode(const c8* typeName, ISceneNode* parent=0) = 0;

		//! returns amount of scene node types this factory is able to create
		virtual s32 getCreatableSceneNodeTypeCount() = 0;

			//! returns type of a createable scene node type
		/* \param idx: Index of scene node type in this factory. Must be a value between 0 and
		getCreatableSceneNodeTypeCount() */
		virtual ESCENE_NODE_TYPE getCreateableSceneNodeType(s32 idx) = 0;

		//! returns type name of a createable scene node type by index
		/* \param idx: Index of scene node type in this factory. Must be a value between 0 and
		getCreatableSceneNodeTypeCount() */
		virtual const c8* getCreateableSceneNodeTypeName(s32 idx) = 0;

		//! returns type name of a createable scene node type 
		/* \param type: Type of scene node. 
		\return: Returns name of scene node type if this factory can create the type, otherwise 0. */
		virtual const c8* getCreateableSceneNodeTypeName(ESCENE_NODE_TYPE type) = 0;
	};


} // end namespace scene
} // end namespace irr

#endif

// Copyright (C) 2002-2007 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __I_SCENE_NODE_ANIMATOR_FACTORY_H_INCLUDED__
#define __I_SCENE_NODE_ANIMATOR_FACTORY_H_INCLUDED__


namespace irr
{
namespace scene
{
	class ISceneNode;
	class ISceneNodeAnimator;
	
	//!	Interface making it possible to dynamicly create scene nodes animators 
	/* To be able to add custom scene node animators to Irrlicht and to make it possible for the 
	scene manager to save and load those external animators, simply implement this
	interface and register it in you scene manager via ISceneManager::registerSceneNodeAnimatorFactory.
	Note: When implementing your own scene node factory, don't call ISceneNodeManager::grab() to
	increase the reference counter of the scene node manager. This is not necessary because the
	scene node manager will grab() the factory anyway, and otherwise cyclic references will
	be created and the scene manager and all its nodes won't get deallocated.
	*/
	class ISceneNodeAnimatorFactory : public virtual IUnknown
	{
	public:

		//! creates a scene node animator based on its type id
		/* \param type: Type of the scene node animator to add.
		\param target: Target scene node of the new animator.
		\return Returns pointer to the new scene node animator or null if not successful. You need to
		drop this pointer after calling this, see IUnknown::drop() for details. */
		virtual ISceneNodeAnimator* createSceneNodeAnimator(ESCENE_NODE_ANIMATOR_TYPE type, ISceneNode* target) = 0;

		//! creates a scene node animator based on its type name
		/* \param typeName: Type of the scene node animator to add.
		\param target: Target scene node of the new animator.
		\return Returns pointer to the new scene node animator or null if not successful. You need to
		drop this pointer after calling this, see IUnknown::drop() for details. */
		virtual ISceneNodeAnimator* createSceneNodeAnimator(const c8* typeName, ISceneNode* target) = 0;

		//! returns amount of scene node animator types this factory is able to create
		virtual s32 getCreatableSceneNodeAnimatorTypeCount() = 0;

		//! returns type of a createable scene node animator type
		/* \param idx: Index of scene node animator type in this factory. Must be a value between 0 and
		getCreatableSceneNodeTypeCount() */
		virtual ESCENE_NODE_ANIMATOR_TYPE getCreateableSceneNodeAnimatorType(s32 idx) = 0;

		//! returns type name of a createable scene node animator type 
		/* \param idx: Index of scene node animator type in this factory. Must be a value between 0 and
		getCreatableSceneNodeAnimatorTypeCount() */
		virtual const c8* getCreateableSceneNodeAnimatorTypeName(s32 idx) = 0;

		//! returns type name of a createable scene node animator type 
		/* \param type: Type of scene node animator. 
		\return: Returns name of scene node animator type if this factory can create the type, otherwise 0. */
		virtual const c8* getCreateableSceneNodeAnimatorTypeName(ESCENE_NODE_ANIMATOR_TYPE type) = 0;
	};


} // end namespace scene
} // end namespace irr

#endif

// Copyright (C) 2002-2007 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __I_SCENE_NODE_ANIMATOR_COLLISION_RESPONSE_H_INCLUDED__
#define __I_SCENE_NODE_ANIMATOR_COLLISION_RESPONSE_H_INCLUDED__


namespace irr
{
namespace scene
{

	//! Special scene node animator for doing automatic collision detection and response.
	/* This scene node animator can be attached to any scene node modifying it in that
	way, that it cannot move through walls of the world, is influenced by gravity and
	acceleration. This animator is useful for example for first person shooter 
	games. Attach it for example to a first person shooter camera, and the camera will
	behave as the player control in a first person shooter game: The camera stops and
	slides at walls, walks up stairs, falls down if there is no floor under it, and so on.
	*/
	class ISceneNodeAnimatorCollisionResponse : public ISceneNodeAnimator
	{
	public:

		//! destructor
		virtual ~ISceneNodeAnimatorCollisionResponse() {}

		//! Returns if the attached scene node is falling, which means that
		//! there is no blocking wall from the scene node in the direction of
		//! the gravity. The implementation of this method is very fast,
		//! no collision detection is done when invoking it. 
		//! \return Returns true if the scene node is falling, false if not.
		virtual bool isFalling() = 0;

		//! Sets the radius of the ellipsoid with which collision detection and
		//! response is done. If you have got a scene node, and you are unsure about
		//! how big the radius should be, you could use the following code to determine
		//! it:
		//! \code
		//! core::aabbox<f32> box = yourSceneNode->getBoundingBox();
		//! core::vector3df radius = box.MaxEdge - box.getCenter();
		//! \endcode
		//! \param radius: New radius of the ellipsoid.
		virtual void setEllipsoidRadius(const core::vector3df& radius) = 0;

		//! Returns the radius of the ellipsoid with wich the collision detection and
		//! response is done.
		//! \return Radius of the ellipsoid.
		virtual core::vector3df getEllipsoidRadius() const = 0;

		//! Sets the gravity of the environment. A good example value would be
		//! core::vector3df(0,-100.0f,0) for letting gravity affect all object to
		//! fall down. For bigger gravity, make increase the length of the vector.
		//! You can disable gravity by setting it to core::vector3df(0,0,0);
		//! \param gravity: New gravity vector.
		virtual void setGravity(const core::vector3df& gravity) = 0;

		//! Returns current vector of gravity.
		//! \return Returns the gravity vector.
		virtual core::vector3df getGravity() const = 0;

		//! By default, the ellipsoid for collision detection is created around
		//! the center of the scene node, which means that the ellipsoid surrounds
		//! it completely. If this is not what you want, you may specify a translation
		//! for the ellipsoid.
		//! \param translation: Translation of the ellipsoid relative 
		//! to the position of the scene node.
		virtual void setEllipsoidTranslation(const core::vector3df &translation) = 0;

		//! Returns the translation of the ellipsoid for collision detection. See
		//! ISceneNodeAnimatorCollisionResponse::setEllipsoidTranslation() for
		//! more details.
		//! \return Returns the tranlation of the ellipsoid relative to the position
		//! of the scene node.
		virtual core::vector3df getEllipsoidTranslation() const = 0;

		//! Sets a triangle selector holding all triangles of the world with which
		//! the scene node may collide.
		//! \param newWorld: New triangle selector containing triangles to let the
		//! scene node collide with.
		virtual void setWorld(ITriangleSelector* newWorld) = 0;

		//! Returns the current triangle selector containing all triangles for
		//! collision detection.
		virtual ITriangleSelector* getWorld() const = 0;
	};
} // end namespace scene
} // end namespace irr

#endif

// Copyright (C) 2002-2007 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __I_SHADER_CONSTANT_SET_CALLBACT_H_INCLUDED__
#define __I_SHADER_CONSTANT_SET_CALLBACT_H_INCLUDED__


namespace irr
{
namespace video  
{
	class IMaterialRendererServices;

//! Interface making it possible to set constants for gpu programs every frame. 
/* Implement this interface in an own class and pass a pointer to it to one of the methods in
 IGPUProgrammingServices when creating a shader. The OnSetConstants method will be called
 every frame now. */
class IShaderConstantSetCallBack : public virtual IUnknown
{
public:

	//! Destructor.
	virtual ~IShaderConstantSetCallBack() {}

	//! Called by the engine when the vertex and/or pixel shader constants for an material renderer should be set.
	/* 
	 Implement the IShaderConstantSetCallBack in an own class and implement your own
	 OnSetConstants method using the given IMaterialRendererServices interface.
	 Pass a pointer to this class to one of the methods in IGPUProgrammingServices 
	 when creating a shader. The OnSetConstants method will now be called every time
	 before geometry is being drawn using your shader material. A sample implementation
	 would look like this:
	 \code
	 virtual void OnSetConstants(video::IMaterialRendererServices services, s32 userData)
	 {
	   video::IVideoDriver driver = services->getVideoDriver();
	
	   // set clip matrix at register 4
	   core::matrix4 worldViewProj(driver->getTransform(video::ETS_PROJECTION));
	   worldViewProj = driver->getTransform(video::ETS_VIEW);
	   worldViewProj = driver->getTransform(video::ETS_WORLD);
	   services->setVertexShaderConstant(&worldViewProj.M[0], 4, 4);
	   // for high level shading languages, this would be another solution:
	   //services->setVertexShaderConstant("mWorldViewProj", worldViewProj.M, 16);
	   
	   // set some light color at register 9
	   video::SColorf col(0.0f,1.0f,1.0f,0.0f);
	   services->setVertexShaderConstant(reinterpret_cast<const f32>(&col), 9, 1);
	   // for high level shading languages, this would be another solution:
	   //services->setVertexShaderConstant("myColor", reinterpret_cast<f32>(&col), 4);
	 }
	 \endcode
	 \param services: Pointer to an interface providing methods to set the constants for the shader.
	 \param userData: Userdata int which can be specified when creating the shader.
	*/
	virtual void OnSetConstants(IMaterialRendererServices* services, s32 userData) = 0;
};


} // end namespace video
} // end namespace irr

#endif


// Copyright (C) 2002-2007 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __I_PARTICLE_SYSTEM_SCENE_NODE_H_INCLUDED__
#define __I_PARTICLE_SYSTEM_SCENE_NODE_H_INCLUDED__

// Copyright (C) 2002-2007 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __I_PARTICLE_EMITTER_H_INCLUDED__
#define __I_PARTICLE_EMITTER_H_INCLUDED__

// Copyright (C) 2002-2007 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __S_PARTICLE_H_INCLUDED__
#define __S_PARTICLE_H_INCLUDED__


namespace irr
{
namespace scene
{
	//! Struct for holding particle data
	struct SParticle
	{
		//! Position of the particle
		core::vector3df pos;

		//! Direction and speed of the particle
		core::vector3df vector;

		//! Start life time of the particle
		u32 startTime;

		//! End life time of the particle
		u32 endTime;

		//! Current color of the particle
		video::SColor color;

		//! Original color of the particle. That's the color
		//! of the particle it had when it was emitted.
		video::SColor startColor;

		//! Original direction and speed of the particle, 
		//! the direction and speed the particle had when
		//! it was emitted.
		core::vector3df startVector;
	};


} // end namespace scene
} // end namespace irr

#endif


namespace irr
{
namespace scene
{

//! Types of built in particle emitters
enum E_PARTICLE_EMITTER_TYPE
{
	EPET_POINT = 0,
	EPET_BOX,
	EPET_COUNT
};

//! Names for built in particle emitters
const c8* const ParticleEmitterTypeNames[] = 
{
	"Point",
	"Box",
	0
};

//! A particle emitter for using with particle systems.
/* A Particle emitter emitts new particles into a particle system.
*/
class IParticleEmitter : public virtual io::IAttributeExchangingObject
{
public:

	//! destructor
	virtual ~IParticleEmitter() {};

	//! Prepares an array with new particles to emitt into the system
	//! and returns how much new particles there are.
	//! \param now: Current time.
	//! \param timeSinceLastCall: Time elapsed since last call, in milliseconds.
	//! \param outArray: Pointer which will point to the array with the new 
	//! particles to add into the system.
	//! \return Returns amount of new particles in the array. Can be 0.
	virtual s32 emitt(u32 now, u32 timeSinceLastCall, SParticle*& outArray) = 0;

	//! Writes attributes of the object.
	//! Implement this to expose the attributes of your scene node animator for 
	//! scripting languages, editors, debuggers or xml serialization purposes.
	virtual void serializeAttributes(io::IAttributes* out, io::SAttributeReadWriteOptions* options=0) {}

	//! Reads attributes of the object.
	//! Implement this to set the attributes of your scene node animator for 
	//! scripting languages, editors, debuggers or xml deserialization purposes.
	//! \param startIndex: start index where to start reading attributes.
	//! \return: returns last index of an attribute read by this affector
	virtual s32 deserializeAttributes(s32 startIndex, io::IAttributes* in, io::SAttributeReadWriteOptions* options=0) { return 0; }

	//! Get emitter type
	virtual E_PARTICLE_EMITTER_TYPE getType() = 0;
};

} // end namespace scene
} // end namespace irr


#endif

// Copyright (C) 2002-2007 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __I_PARTICLE_AFFECTOR_H_INCLUDED__
#define __I_PARTICLE_AFFECTOR_H_INCLUDED__


namespace irr
{
namespace scene
{

//! Types of built in particle affectors
enum E_PARTICLE_AFFECTOR_TYPE
{
	EPAT_NONE = 0,
	EPAT_FADE_OUT,
	EPAT_GRAVITY,
	EPAT_COUNT
};

//! Names for built in particle affectors
const c8* const ParticleAffectorTypeNames[] =
{
	"None",
	"FadeOut",
	"Gravity",
	0
};

//! A particle affector modifies particles.
class IParticleAffector : public virtual io::IAttributeExchangingObject
{
public:

	//! constructor
	IParticleAffector() : Enabled(true) {}

	//! Affects an array of particles.
	//! \param now: Current time. (Same as ITimer::getTime() would return)
	//! \param particlearray: Array of particles.
	//! \param count: Amount of particles in array.
	virtual void affect(u32 now, SParticle* particlearray, u32 count) = 0;

	//! Sets whether or not the affector is currently enabled.
	virtual void setEnabled(bool enabled) {Enabled = enabled;}

	//! Gets whether or not the affector is currently enabled.
	virtual bool getEnabled() const { return Enabled;}

	//! Writes attributes of the object.
	//! Implement this to expose the attributes of your scene node animator for
	//! scripting languages, editors, debuggers or xml serialization purposes.
	virtual void serializeAttributes(io::IAttributes* out, io::SAttributeReadWriteOptions* options=0) {}

	//! Reads attributes of the object.
	//! Implement this to set the attributes of your scene node animator for
	//! scripting languages, editors, debuggers or xml deserialization purposes.
	//! \param startIndex: start index where to start reading attributes.
	//! \return: returns last index of an attribute read by this affector
	virtual s32 deserializeAttributes(s32 startIndex, io::IAttributes* in, io::SAttributeReadWriteOptions* options=0) { return 0; }

	//! Get emitter type
	virtual E_PARTICLE_AFFECTOR_TYPE getType() = 0;

protected:
	bool Enabled;
};

} // end namespace scene
} // end namespace irr


#endif


namespace irr
{
namespace scene
{

//! A particle system scene node for creating snow, fire, exlosions, smoke...
/* A scene node controlling a particle System. The behavior of the particles
can be controlling by setting the right particle emitters and effectors.
You can for example easily a campfire by doing this:

\code
	scene::IParticleSystemSceneNode p = scenemgr->addParticleSystemSceneNode();
	p->setParticleSize(core::dimension2d<f32>(20.0f, 10.0f));
	scene::IParticleEmitter em = p->createBoxEmitter(
		core::aabbox3d<f32>(-5,0,-5,5,1,5), 
		core::vector3df(0.0f,0.03f,0.0f),
		40,80, video::SColor(0,255,255,255),video::SColor(0,255,255,255), 1100,2000);
	p->setEmitter(em);
	em->drop();
	scene::IParticleAffector paf = p->createFadeOutParticleAffector();
	p->addAffector(paf);
	paf->drop();
\endcode

*/
class IParticleSystemSceneNode : public ISceneNode
{
public:

	//! constructor
	IParticleSystemSceneNode(ISceneNode* parent, ISceneManager* mgr, s32 id, 
		const core::vector3df& position = core::vector3df(0,0,0),
		const core::vector3df& rotation = core::vector3df(0,0,0),
		const core::vector3df& scale = core::vector3df(1.0f, 1.0f, 1.0f))
			: ISceneNode(parent, mgr, id, position, rotation, scale) {}

	//! Sets the size of all particles.
	virtual void setParticleSize(
		const core::dimension2d<f32> &size = core::dimension2d<f32>(5.0f, 5.0f)) = 0;

	//! Sets if the particles should be global. If it is, the particles are affected by 
	//! the movement of the particle system scene node too, otherwise they completely 
	//! ignore it. Default is true.
	virtual void setParticlesAreGlobal(bool global) = 0;

	//! Sets the particle emitter, which creates the particles.
	//! A particle emitter can be created using one of the 
	//! methods. For example to create and use a simple PointEmitter,
	//! call IParticleEmitter* p = createPointEmitter(); setEmitter(p); p->drop();
	//! \param emitter: Sets the particle emitter. You can set this to 0
	//! for removing the current emitter and stopping the particle system
	//! emitting new particles.
	virtual void setEmitter(IParticleEmitter* emitter) = 0;

	//! Adds new particle effector to the particle system. A particle
	//! affector modifies the particles. For example, the FadeOut
	//! affector lets all particles fade out after some time. It is created
	//! and used in this way: IParticleAffector* p = createFadeOutParticleAffector();
	//! addAffector(p); p->drop();
	//! Please note that a affector is not necessary for the particle
	//! system to work.
	//! \param affector: New affector.
	virtual void addAffector(IParticleAffector* affector) = 0;

	//! Removes all particle affectors in the particle system.
	virtual void removeAllAffectors() = 0;

	//! Creates a point particle emitter.
	//! \param direction: Direction and speed of particle emission.
	//! \param minParticlesPerSecond: Minimal amount of particles emitted
	//! per second.
	//! \param maxParticlesPerSecond: Maximal amount of particles emitted
	//! per second.
	//! \param minStartColor: Minimal initial start color of a particle. 
	//! The real color of every particle is calculated as random interpolation
	//! between minStartColor and maxStartColor.
	//! \param maxStartColor: Maximal initial start color of a particle. 
	//! The real color of every particle is calculated as random interpolation
	//! between minStartColor and maxStartColor.
	//! \param lifeTimeMin: Minimal lifetime of a particle, in milliseconds.
	//! \param lifeTimeMax: Maximal lifetime of a particle, in milliseconds.
	//! \param maxAngleDegrees: Maximal angle in degrees, the emitting direction
	//! of the particle will differ from the orignial direction.
	//! \return Returns a pointer to the created particle emitter.
	//! To set this emitter as new emitter of this particle system,
	//! just call setEmitter(). Note that you'll have to drop() the
	//! returned pointer, after you don't need it any more, see
	//! IUnknown::drop() for more informations.
	virtual IParticleEmitter* createPointEmitter(
		const core::vector3df& direction = core::vector3df(0.0f,0.03f,0.0f), 
		u32 minParticlesPerSecond = 5,
		u32 maxParticlesPerSecond = 10,
		video::SColor minStartColor = video::SColor(255,0,0,0),
		video::SColor maxStartColor = video::SColor(255,255,255,255),
		u32 lifeTimeMin=2000, u32 lifeTimeMax=4000,
		s32 maxAngleDegrees=0) = 0;

	//! Creates a box particle emitter.
	//! \param box: The box for the emitter.
	//! \param direction: Direction and speed of particle emission.
	//! \param minParticlesPerSecond: Minimal amount of particles emitted
	//! per second.
	//! \param maxParticlesPerSecond: Maximal amount of particles emitted
	//! per second.
	//! \param minStartColor: Minimal initial start color of a particle. 
	//! The real color of every particle is calculated as random interpolation
	//! between minStartColor and maxStartColor.
	//! \param maxStartColor: Maximal initial start color of a particle. 
	//! The real color of every particle is calculated as random interpolation
	//! between minStartColor and maxStartColor.
	//! \param lifeTimeMin: Minimal lifetime of a particle, in milliseconds.
	//! \param lifeTimeMax: Maximal lifetime of a particle, in milliseconds.
	//! \param maxAngleDegrees: Maximal angle in degrees, the emitting direction
	//! of the particle will differ from the orignial direction.
	//! \return Returns a pointer to the created particle emitter.
	//! To set this emitter as new emitter of this particle system,
	//! just call setEmitter(). Note that you'll have to drop() the
	//! returned pointer, after you don't need it any more, see
	//! IUnknown::drop() for more informations.
	virtual IParticleEmitter* createBoxEmitter(
		const core::aabbox3df& box = core::aabbox3df(-10,28,-10,10,30,10),
		const core::vector3df& direction = core::vector3df(0.0f,0.03f,0.0f), 
		u32 minParticlesPerSecond = 5,
		u32 maxParticlesPerSecond = 10,
		video::SColor minStartColor = video::SColor(255,0,0,0),
		video::SColor maxStartColor = video::SColor(255,255,255,255),
		u32 lifeTimeMin=2000, u32 lifeTimeMax=4000,
		s32 maxAngleDegrees=0) = 0;

	//! Creates a fade out particle affector. This affector modifies
	//! the color of every particle and and reaches the final color
	//! when the particle dies.
	//! This affector looks really good, if the EMT_TRANSPARENT_VERTEX_ALPHA
	//! material is used and the targetColor is video::SColor(0,0,0,0):
	//! Particles are fading out into void with this setting.
	//! \param targetColor: Color whereto the color of the particle is changed.
	//! \param timeNeededToFadeOut: How much time in milli seconds 
	//! should the affector need to change the color to the targetColor. 
	//! \return Returns a pointer to the created particle affector.
	//! To add this affector as new affector of this particle system,
	//! just call addAffector(). Note that you'll have to drop() the
	//! returned pointer, after you don't need it any more, see
	//! IUnknown::drop() for more informations.
	virtual IParticleAffector* createFadeOutParticleAffector(
		video::SColor targetColor = video::SColor(0,0,0,0),
		u32 timeNeededToFadeOut = 1000) = 0;

	//! Creates a gravity affector. This affector modifies the direction
	//! of the particle. It assumes that the particle is fired out of the
	//! emitter with huge force, but is loosing this after some time
	//! and is catched by the gravity then. This affector is ideal for
	//! creating things like fountains.
	//! \param gravity: Direction and force of gravity.
	//! \param timeForceLost: Time in milli seconds when the force 
	//! of the emitter is totally lost and the particle does not move any more.
	//! This is the time where gravity fully affects the particle.
	//! \return Returns a pointer to the created particle affector.
	//! To add this affector as new affector of this particle system,
	//! just call addAffector(). Note that you'll have to drop() the
	//! returned pointer, after you don't need it any more, see
	//! IUnknown::drop() for more informations.
	virtual IParticleAffector* createGravityAffector(
		const core::vector3df& gravity = core::vector3df(0.0f,-0.03f,0.0f),
		u32 timeForceLost = 1000) = 0;
};

} // end namespace scene
} // end namespace irr


#endif

// Copyright (C) 2002-2007 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

// The code for the TerrainSceneNode is based on the terrain renderer by Soconne and
// the GeoMipMapSceneNode developed by Spintz.  They made their code available for Irrlicht 
// and allowed it to be  distributed under this licence. I only modified some parts.
// A lot of thanks go to them. 

#ifndef __I_TERRAIN_SCENE_NODE_H__
#define __I_TERRAIN_SCENE_NODE_H__

// Copyright (C) 2002-2007 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __S_MESH_BUFFER_LIGHT_MAP_H_INCLUDED__
#define __S_MESH_BUFFER_LIGHT_MAP_H_INCLUDED__


namespace irr
{
namespace scene
{
	//! Simple implementation of the IMeshBuffer interface with S3DVertex2TCoords vertices.
	struct SMeshBufferLightMap : public IMeshBuffer
	{
		//! constructor
		SMeshBufferLightMap()
		{
			#ifdef _DEBUG
			setDebugName("SMeshBufferLightMap");
			#endif
		}

		//! destructor
		~SMeshBufferLightMap() {}; 

		//! returns the material of this meshbuffer
		virtual const video::SMaterial& getMaterial() const
		{
			return Material;
		}


		//! returns the material of this meshbuffer
		video::SMaterial& getMaterial()
		{
			return Material;
		}

		//! returns pointer to vertices
		virtual const void* getVertices() const
		{
			return Vertices.const_pointer();
		} 

		//! returns pointer to vertices
		virtual void* getVertices()
		{
			return Vertices.pointer();
		} 

		//! returns amount of vertices
		virtual u32 getVertexCount() const
		{
			return Vertices.size();
		}

		//! returns pointer to Indices
		virtual const u16* getIndices() const
		{
			return Indices.const_pointer();
		}

		//! returns pointer to Indices
		virtual u16* getIndices()
		{
			return Indices.pointer();
		}

		//! returns amount of indices
		virtual u32 getIndexCount() const
		{
			return Indices.size();
		}

		//! returns an axis aligned bounding box
		virtual const core::aabbox3d<f32>& getBoundingBox() const
		{
			return BoundingBox;
		}

		//! set user axis aligned bounding box
		virtual void setBoundingBox( const core::aabbox3df& box)
		{
			BoundingBox = box;
		}


		//! recalculates the bounding box. should be called if the mesh changed.
		void recalculateBoundingBox()
		{
			if (Vertices.empty())
				BoundingBox.reset(0,0,0);
			else
			{
				BoundingBox.reset(Vertices[0].Pos);
				for (u32 i=1; i<Vertices.size(); ++i)
					BoundingBox.addInternalPoint(Vertices[i].Pos);
			}
		}

		//! returns which type of vertex data is stored.
		virtual video::E_VERTEX_TYPE getVertexType() const
		{
			return video::EVT_2TCOORDS;
		}

		//! returns the byte size (stride, pitch) of the vertex
		virtual u32 getVertexPitch() const
		{
			return sizeof ( video::S3DVertex2TCoords );
		}


		video::SMaterial Material; //! material for this meshBuffer.
		core::array<video::S3DVertex2TCoords> Vertices; //! Array of vertices
		core::array<u16> Indices; //! Array of the Indices.
		core::aabbox3d<f32> BoundingBox;
	};

} // end namespace scene
} // end namespace irr

#endif


namespace irr
{
namespace scene
{
	//! A scene node for displaying terrain using the geo mip map algorithm.
	/* The code for the TerrainSceneNode is based on the Terrain renderer by Soconne and 
	  the GeoMipMapSceneNode developed by Spintz. They made their code available for Irrlicht 
	  and allowed it to be  distributed under this licence. I only modified some parts.
	  A lot of thanks go to them. 
	 *
	  This scene node is capable of very quickly loading
	  terrains and updating the indices at runtime to enable viewing very large terrains.  It uses a
	  CLOD ( Continuous Level of Detail ) algorithm which updates the indices for each patch based on 
	  a LOD ( Level of Detail ) which is determined based on a patch's distance from the camera.
	 *
	  The Patch Size of the terrain must always be a size of ( 2^N+1, i.e. 8+1(9), 16+1(17), etc. ).
	  The MaxLOD available is directly dependent on the patch size of the terrain.  LOD 0 contains all
	  of the indices to draw all the triangles at the max detail for a patch.  As each LOD goes up by 1
	  the step taken, in generating indices increases by - 2^LOD, so for LOD 1, the step taken is 2, for
	  LOD 2, the step taken is 4, LOD 3 - 8, etc.  The step can be no larger than the size of the patch,
	  so having a LOD of 8, with a patch size of 17, is asking the algoritm to generate indices every 
	  2^8 ( 256 ) vertices, which is not possible with a patch size of 17.  The maximum LOD for a patch
	  size of 17 is 2^4 ( 16 ).  So, with a MaxLOD of 5, you'll have LOD 0 ( full detail ), LOD 1 ( every
	  2 vertices ), LOD 2 ( every 4 vertices ), LOD 3 ( every 8 vertices ) and LOD 4 ( every 16 vertices ).
	 **/
	class ITerrainSceneNode : public ISceneNode
	{
	public:

		//! constructor
		ITerrainSceneNode(ISceneNode* parent, ISceneManager* mgr, s32 id, 
			const core::vector3df& position = core::vector3df(0.0f, 0.0f, 0.0f),
			const core::vector3df& rotation = core::vector3df(0.0f, 0.0f, 0.0f),
			const core::vector3df& scale = core::vector3df(1.0f, 1.0f, 1.0f) ) 
			: ISceneNode (parent, mgr, id, position, rotation, scale) {}

		//! destructor
		virtual ~ITerrainSceneNode() {};

		//! \return: Returns the bounding box of the entire terrain.
		virtual const core::aabbox3d<f32>& getBoundingBox ( ) const = 0;

		//! Returns the bounding box of a patch
		virtual const core::aabbox3d<f32>& getBoundingBox (s32 patchX, s32 patchZ) const = 0;

		//! Returns the number of indices currently in the meshbuffer for this scene node.
		virtual u32 getIndexCount() = 0;

		//! Returns pointer to the mesh
		virtual IMesh* getMesh() = 0;

		//! Gets the meshbuffer data based on a specified level of detail.
		/* \param mb: A reference to an SMeshBuffer object
		 \param LOD: the level of detail you want the indices from. */
		virtual void getMeshBufferForLOD(SMeshBufferLightMap& mb, s32 LOD) = 0;

		//! Gets the indices for a specified patch at a specified Level of Detail.  
		/* \param indices: A reference to an array of u32 indices.
		\param patchX: Patch x coordinate.
		\param patchZ: Patch z coordinate.
		\param LOD: The level of detail to get for that patch.  If -1, then get 
		the CurrentLOD.  If the CurrentLOD is set to -1, meaning it's not shown,
		then it will retrieve the triangles at the highest LOD ( 0 ).
		\return: Number if indices put into the buffer. */
		virtual s32 getIndicesForPatch(core::array<u32>& indices, 
			s32 patchX, s32 patchZ, s32 LOD = 0 ) = 0;

		//! Populates an array with the CurrentLOD of each patch.
		/* \param LODs: A reference to a core::array<s32> to hold the values
		 \return: Returns the number of elements in the array */
		virtual s32 getCurrentLODOfPatches(core::array<s32>& LODs) = 0;

		//! Manually sets the LOD of a patch
		/* \param patchX: Patch x coordinate.
		\param patchZ: Patch z coordinate.
		\param LOD: The level of detail to set the patch to. */
		virtual void setLODOfPatch( s32 patchX, s32 patchZ, s32 LOD ) = 0;

		//! Returns center of terrain.
		virtual core::vector3df getTerrainCenter() = 0;

		//! Returns height of a point of the terrain.
		virtual f32 getHeight( f32 x, f32 y ) = 0;

		//! Sets the movement camera threshold.
		/* It is used to determine when to recalculate
		 indices for the scene node.  The default value is 10.0f. */
		virtual void setCameraMovementDelta(f32 delta) = 0;

		//! Sets the rotation camera threshold.
		/* It is used to determine when to recalculate
		indices for the scene node.  The default value is 1.0f. */
		virtual void setCameraRotationDelta(f32 delta) = 0;

		//! Sets whether or not the node should dynamically update its associated selector when the geomipmap data changes.
		/* \param bVal: Boolean value representing whether or not to update selector dynamically. */
		virtual void setDynamicSelectorUpdate(bool bVal) = 0;

		//! Override the default generation of distance thresholds.
		/* For determining the LOD a patch
		is rendered at. If any LOD is overridden, then the scene node will no longer apply
		scaling factors to these values.  If you override these distances, and then apply
		a scale to the scene node, it is your responsibility to update the new distances to
		work best with your new terrain size. */
		virtual bool overrideLODDistance(s32 LOD, f64 newDistance) = 0;

		//! Scales the base texture, similar to makePlanarTextureMapping.
		/* \param scale: The scaling amount.  Values above 1.0 increase the number of time the 
		texture is drawn on the terrain.  Values below 0 will decrease the number of times the
		texture is drawn on the terrain.  Using negative values will flip the texture, as
		well as still scaling it. 
		\param scale2: If set to 0 (default value), this will set the second texture coordinate set
		to the same values as in the first set. If this is another value than zero, it will scale
		the second texture coordinate set by this value. */
		virtual void scaleTexture(f32 scale = 1.0f, f32 scale2 = 0.0f) = 0;
	};

} // end namespace scene
} // end namespace irr


#endif // __IGEOMIPMAPSCENENODE_H__
// Copyright (C) 2002-2007 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __I_TEXT_SCENE_NODE_H_INCLUDED__
#define __I_TEXT_SCENE_NODE_H_INCLUDED__


namespace irr
{
namespace scene
{

//! A scene node for displaying 2d text at a position in three dimensional space
class ITextSceneNode : public ISceneNode
{
public:

	//! constructor
	ITextSceneNode(ISceneNode* parent, ISceneManager* mgr, s32 id, 
		const core::vector3df& position = core::vector3df(0,0,0))
			: ISceneNode(parent, mgr, id, position) {}

	//! sets the text string
	virtual void setText(const wchar_t* text) = 0;

	//! sets the color of the text
	virtual void setTextColor(video::SColor color) = 0;
};

} // end namespace scene
} // end namespace irr


#endif

// Copyright (C) 2002-2007 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __I_BILLBOARD_SCENE_NODE_H_INCLUDED__
#define __I_BILLBOARD_SCENE_NODE_H_INCLUDED__


namespace irr
{
namespace scene
{

//! A billboard scene node.
/* A billboard is like a 3d sprite: A 2d element,
which always looks to the camera. It is usually used for explosions, fire,
lensflares, particles and things like that.
*/
class IBillboardSceneNode : public ISceneNode
{
public:

	//! constructor
	IBillboardSceneNode(ISceneNode* parent, ISceneManager* mgr, s32 id, 
		const core::vector3df& position = core::vector3df(0,0,0))
		: ISceneNode(parent, mgr, id, position) {}

	//! Sets the size of the billboard.
	virtual void setSize(const core::dimension2d<f32>& size) = 0;

	//! Returns the size of the billboard.
	virtual const core::dimension2d<f32>& getSize() = 0;

	//! Set the color of all vertices of the billboard
	//! \param overallColor: the color to set
	virtual void setColor(const video::SColor & overallColor) = 0;

	//! Set the color of the top and bottom vertices of the billboard
	//! \param topColor: the color to set the top vertices
	//! \param bottomColor: the color to set the bottom vertices
	virtual void setColor(const video::SColor & topColor, const video::SColor & bottomColor) = 0;

	//! Gets the color of the top and bottom vertices of the billboard
	//! \param[out] topColor: stores the color of the top vertices
	//! \param[out] bottomColor: stores the color of the bottom vertices
	virtual void getColor(video::SColor & topColor, video::SColor & bottomColor) = 0;

};

} // end namespace scene
} // end namespace irr


#endif

// Copyright (C) 2002-2007 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __I_WRITE_FILE_H_INCLUDED__
#define __I_WRITE_FILE_H_INCLUDED__


namespace irr
{
namespace io
{

	//! Interface providing write acess to a file.
	class IWriteFile : public virtual IUnknown
	{
	public:

		virtual ~IWriteFile() {};

		//! Reads an amount of bytes from the file.
		//! \param buffer: Pointer to buffer of bytes to write.
		//! \param sizeToWrite: Amount of bytes to wrtie to the file.
		//! \return Returns how much bytes were written.
		virtual s32 write(const void* buffer, s32 sizeToWrite) = 0;

		//! Changes position in file, returns true if successful.
		//! \param finalPos: Destination position in the file.
		//! \param relativeMovement: If set to true, the position in the file is
		//! changed relative to current position. Otherwise the position is changed 
		//! from begin of file.		
		//! \return Returns true if successful, otherwise false.
		virtual bool seek(s32 finalPos, bool relativeMovement = false) = 0;

		//! Returns the current position in the file.
		//! \return Returns the current position in the file in bytes.
		virtual s32 getPos() = 0;

		//! Returns name of file.
		//! \return Returns the file name as zero terminated character string.
		virtual const c8* getFileName() = 0;
	};

	//! Internal function, please do not use.
	IWriteFile* createWriteFile(const c8* fileName, bool append);

} // end namespace io
} // end namespace irr

#endif

// Copyright (C) 2002-2007 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __I_XML_WRITER_H_INCLUDED__
#define __I_XML_WRITER_H_INCLUDED__


namespace irr
{
namespace io
{

	//! Interface providing methods for making it easier to write XML files.
	/* This XML Writer only writes UTF-16 xml files, because these are parsed 
	faster than all other formats by IXMLReader.
	*/
	class IXMLWriter : public virtual IUnknown
	{
	public:

		//! Destructor
		virtual ~IXMLWriter() {};

		//! Writes a xml 1.0 header like &lt;?xml version="1.0"?&gt;. This should
		//! always be called before writing anything other, because also the
		//! text file header for unicode texts is written out with this method.
		virtual void writeXMLHeader() = 0;

		//! Writes an xml element with maximal 5 attributes like "<foo />" or
		//! &lt;foo optAttr="value" /&gt;. The element can be empty or not.
		//! \param name: Name of the element
		//! \param empty: Specifies if the element should be empty. Like "<foo />". If
		//! You set this to false, something like this is written instead: "<foo>".
		//! \param attr1Name: 1st attributes name
		//! \param attr1Value: 1st attributes value
		//! \param attr2Name: 2nd attributes name
		//! \param attr2Value: 2nd attributes value
		//! \param attr3Name: 3rd attributes name
		//! \param attr3Value: 3rd attributes value
		//! \param attr4Name: 4th attributes name
		//! \param attr4Value: 4th attributes value
		//! \param attr5Name: 5th attributes name
		//! \param attr5Value: 5th attributes value
		virtual void writeElement(const wchar_t* name, bool empty=false,
			const wchar_t* attr1Name = 0, const wchar_t* attr1Value = 0,
			const wchar_t* attr2Name = 0, const wchar_t* attr2Value = 0,
			const wchar_t* attr3Name = 0, const wchar_t* attr3Value = 0,
			const wchar_t* attr4Name = 0, const wchar_t* attr4Value = 0,
			const wchar_t* attr5Name = 0, const wchar_t* attr5Value = 0) = 0;

		//! Writes an xml element with any number of attributes
		virtual void writeElement(const wchar_t* name, bool empty,
				core::array<core::stringw> &names, core::array<core::stringw> &values) = 0;

		//! Writes a comment into the xml file
		virtual void writeComment(const wchar_t* comment) = 0;

		//! Writes the closing tag for an element. Like "</foo>"
		virtual void writeClosingTag(const wchar_t* name) = 0;

		//! Writes a text into the file. All occurrences of special characters like
		//! & (&amp;), < (&lt;), > (&gt;), and " (&quot;) are automaticly replaced.
		virtual void writeText(const wchar_t* text) = 0;

		//! Writes a line break
		virtual void writeLineBreak() = 0;
	};

} // end namespace io
} // end namespace irr

#endif

// Copyright (C) 2002-2007 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __S_ANIMATED_MESH_H_INCLUDED__
#define __S_ANIMATED_MESH_H_INCLUDED__


namespace irr
{
namespace scene
{

	//! Simple implementation of the IAnimatedMesh interface.
	struct SAnimatedMesh : public IAnimatedMesh
	{
		//! constructor
		SAnimatedMesh()
		{
			#ifdef _DEBUG
			setDebugName("SAnimatedMesh");
			#endif

			Type = EAMT_UNKNOWN;
		}


		//! destructor
		~SAnimatedMesh()
		{
			// drop meshes
			for (u32 i=0; i<Meshes.size(); ++i)
				Meshes[i]->drop();
		};


		//! Gets the frame count of the animated mesh.
		//! \return Returns the amount of frames. If the amount is 1, it is a static, non animated mesh.
		virtual s32 getFrameCount()
		{
			return Meshes.size();
		}



		//! Returns the IMesh interface for a frame.
		//! \param frame: Frame number as zero based index. The maximum frame number is
		//! getFrameCount() - 1;
		//! \param detailLevel: Level of detail. 0 is the lowest,
		//! 255 the highest level of detail. Most meshes will ignore the detail level.
		//! \param startFrameLoop: start frame
		//! \param endFrameLoop: end frame
		//! \return Returns the animated mesh based on a detail level. 
		virtual IMesh* getMesh(s32 frame, s32 detailLevel, s32 startFrameLoop=-1, s32 endFrameLoop=-1)
		{
			if (Meshes.empty())
				return 0;

			return Meshes[frame];
		}


		//! adds a Mesh
		void addMesh(IMesh* mesh)
		{
			if (mesh)
			{
				mesh->grab();
				Meshes.push_back(mesh);
			}
		}

        
		//! Returns an axis aligned bounding box of the mesh.
		//! \return A bounding box of this mesh is returned.
		virtual const core::aabbox3d<f32>& getBoundingBox() const
		{
			return Box;
		}

		//! set user axis aligned bounding box
		virtual void setBoundingBox( const core::aabbox3df& box)
		{
			Box = box;
		}

		void recalculateBoundingBox()
		{
			Box.reset(0,0,0);

			if (Meshes.empty())
				return;

			Box = Meshes[0]->getBoundingBox();

			for (u32 i=1; i<Meshes.size(); ++i)
				Box.addInternalBox(Meshes[i]->getBoundingBox());				
		}


		//! Returns the type of the animated mesh.
		virtual E_ANIMATED_MESH_TYPE getMeshType() const
		{
			return Type;
		}

		core::aabbox3d<f32> Box;
		core::array<IMesh*> Meshes;
		E_ANIMATED_MESH_TYPE Type;
	};


} // end namespace scene
} // end namespace irr

#endif

// Copyright (C) 2002-2007 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __S_KEY_MAP_H_INCLUDED__
#define __S_KEY_MAP_H_INCLUDED__


namespace irr
{

	//! enumeration for key actions. Used for example in the FPS Camera.
	enum EKEY_ACTION
	{
		EKA_MOVE_FORWARD = 0,
		EKA_MOVE_BACKWARD,
		EKA_STRAFE_LEFT,
		EKA_STRAFE_RIGHT,
		EKA_JUMP_UP,
		EKA_COUNT,

		//! This value is not used. It only forces this enumeration to compile in 32 bit. 
		EKA_FORCE_32BIT = 0x7fffffff	
	};

	//! Struct storing which key belongs to which action.
	struct SKeyMap
	{
		EKEY_ACTION Action;
		EKEY_CODE KeyCode;
	};

} // end namespace irr

#endif

// Copyright (C) 2002-2007 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __S_MESH_H_INCLUDED__
#define __S_MESH_H_INCLUDED__


namespace irr
{
namespace scene
{
	//! Simple implementation of the IMesh interface.
	struct SMesh : public IMesh
	{
		//! constructor
		SMesh()
		{
			#ifdef _DEBUG
			setDebugName("SMesh");
			#endif
		}

		//! destructor
		~SMesh()
		{
			// drop buffers
			for (u32 i=0; i<MeshBuffers.size(); ++i)
			{
				MeshBuffers[i]->drop();
			}
		};

		//! returns amount of mesh buffers.
		virtual u32 getMeshBufferCount() const
		{
			return MeshBuffers.size();
		}

		//! returns pointer to a mesh buffer
		virtual IMeshBuffer* getMeshBuffer(u32 nr) const
		{
			return MeshBuffers[nr];
		}

		//! returns a meshbuffer which fits a material
		// reverse search
		virtual IMeshBuffer* getMeshBuffer( const video::SMaterial & material) const
		{
			for (s32 i = (s32) MeshBuffers.size(); --i >= 0; )
			{
				if ( !(material != MeshBuffers[i]->getMaterial()) )
					return MeshBuffers[i];
			}

			return 0;
		}

		//! returns an axis aligned bounding box
		virtual const core::aabbox3d<f32>& getBoundingBox() const
		{
			return BoundingBox;
		}

		//! set user axis aligned bounding box
		virtual void setBoundingBox( const core::aabbox3df& box)
		{
			BoundingBox = box;
		}

		//! recalculates the bounding box
		void recalculateBoundingBox()
		{
			if (MeshBuffers.size())
			{
				BoundingBox = MeshBuffers[0]->getBoundingBox();
				for (u32 i=1; i<MeshBuffers.size(); ++i)
					BoundingBox.addInternalBox(MeshBuffers[i]->getBoundingBox());
			}
			else
				BoundingBox.reset(0.0f, 0.0f, 0.0f);
		}

		//! adds a MeshBuffer
		void addMeshBuffer(IMeshBuffer* buf)
		{
			if (buf)
			{
				buf->grab();
				MeshBuffers.push_back(buf);
			}
		}

		//! sets a flag of all contained materials to a new value
		virtual void setMaterialFlag(video::E_MATERIAL_FLAG flag, bool newvalue)
		{
			for (u32 i=0; i<MeshBuffers.size(); ++i)
				MeshBuffers[i]->getMaterial().setFlag(flag, newvalue);
		}

		core::array<IMeshBuffer*> MeshBuffers;
		core::aabbox3d<f32> BoundingBox;
	};


} // end namespace scene
} // end namespace irr

#endif

// Copyright (C) 2002-2007 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __S_MESH_BUFFER_H_INCLUDED__
#define __S_MESH_BUFFER_H_INCLUDED__


namespace irr
{
namespace scene
{
	//! Simple implementation of the IMeshBuffer interface with S3DVertex vertices.
	struct SMeshBuffer : public IMeshBuffer
	{
		//! constructor
		SMeshBuffer()
		{
			#ifdef _DEBUG
			setDebugName("SMeshBuffer");
			#endif
		}

		//! destructor
		~SMeshBuffer() {}; 

		//! returns the material of this meshbuffer
		virtual const video::SMaterial& getMaterial() const
		{
			return Material;
		}

		//! returns the material of this meshbuffer
		virtual video::SMaterial& getMaterial()
		{
			return Material;
		}

		//! returns pointer to vertices
		virtual const void* getVertices() const
		{
			return Vertices.const_pointer();
		} 

		//! returns pointer to vertices
		virtual void* getVertices()
		{
			return Vertices.pointer();
		} 

		//! returns amount of vertices
		virtual u32 getVertexCount() const
		{
			return Vertices.size();
		}

		//! returns pointer to Indices
		virtual const u16* getIndices() const
		{
			return Indices.const_pointer();
		}

		//! returns pointer to Indices
		virtual u16* getIndices()
		{
			return Indices.pointer();
		}

		//! returns amount of indices
		virtual u32 getIndexCount() const
		{
			return Indices.size();
		}

		//! returns an axis aligned bounding box
		virtual const core::aabbox3d<f32>& getBoundingBox() const
		{
			return BoundingBox;
		}

		//! set user axis aligned bounding box
		virtual void setBoundingBox( const core::aabbox3df& box)
		{
			BoundingBox = box;
		}


		//! recalculates the bounding box. should be called if the mesh changed.
		void recalculateBoundingBox()
		{
			if (Vertices.empty())
				BoundingBox.reset(0,0,0);
			else
			{
				BoundingBox.reset(Vertices[0].Pos);
				for (u32 i=1; i<Vertices.size(); ++i)
					BoundingBox.addInternalPoint(Vertices[i].Pos);
			}
		}

		//! returns which type of vertex data is stored.
		virtual video::E_VERTEX_TYPE getVertexType() const
		{
			return video::EVT_STANDARD;
		}

		//! returns the byte size (stride, pitch) of the vertex
		virtual u32 getVertexPitch() const
		{
			return sizeof ( video::S3DVertex );
		}


		video::SMaterial Material; //! material for this meshBuffer.
		core::array<video::S3DVertex> Vertices; //! Array of vertices
		core::array<u16> Indices; //! Array of the Indices.
		core::aabbox3d<f32> BoundingBox;
	};

} // end namespace scene
} // end namespace irr

#endif

// Copyright (C) 2002-2007 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __S_MESH_BUFFER_TANGENTS_H_INCLUDED__
#define __S_MESH_BUFFER_TANGENTS_H_INCLUDED__


namespace irr
{
namespace scene
{
	//! Simple implementation of the IMeshBuffer interface with S3DVertexTangents vertices.
	struct SMeshBufferTangents : public IMeshBuffer
	{
		//! constructor
		SMeshBufferTangents()
		{
			#ifdef _DEBUG
			setDebugName("SMeshBufferTangents");
			#endif
		}

		//! destructor
		~SMeshBufferTangents() {}; 

		//! returns the material of this meshbuffer
		virtual const video::SMaterial& getMaterial() const
		{
			return Material;
		}

		//! returns the material of this meshbuffer
		virtual video::SMaterial& getMaterial()
		{
			return Material;
		}

		//! returns pointer to vertices
		virtual const void* getVertices() const
		{
			return Vertices.const_pointer();
		} 

		//! returns pointer to vertices
		virtual void* getVertices()
		{
			return Vertices.pointer();
		} 

		//! returns amount of vertices
		virtual u32 getVertexCount() const
		{
			return Vertices.size();
		}

		//! returns pointer to Indices
		virtual const u16* getIndices() const
		{
			return Indices.const_pointer();
		}

		//! returns pointer to Indices
		virtual u16* getIndices()
		{
			return Indices.pointer();
		}

		//! returns amount of indices
		virtual u32 getIndexCount() const
		{
			return Indices.size();
		}

		//! returns an axis aligned bounding box
		virtual const core::aabbox3d<f32>& getBoundingBox() const
		{
			return BoundingBox;
		}

		//! set user axis aligned bounding box
		virtual void setBoundingBox( const core::aabbox3df& box)
		{
			BoundingBox = box;
		}


		//! recalculates the bounding box. should be called if the mesh changed.
		void recalculateBoundingBox()
		{
			if (Vertices.empty())
				BoundingBox.reset(0,0,0);
			else
			{
				BoundingBox.reset(Vertices[0].Pos);
				for (u32 i=1; i<Vertices.size(); ++i)
					BoundingBox.addInternalPoint(Vertices[i].Pos);
			}
		}

		//! returns which type of vertex data is stored.
		virtual video::E_VERTEX_TYPE getVertexType() const
		{
			return video::EVT_TANGENTS;
		}

		//! returns the byte size (stride, pitch) of the vertex
		virtual u32 getVertexPitch() const
		{
			return sizeof ( video::S3DVertexTangents );
		}


		video::SMaterial Material; //! material for this meshBuffer.
		core::array<video::S3DVertexTangents> Vertices; //! Array of vertices
		core::array<u16> Indices; //! Array of the Indices.
		core::aabbox3d<f32> BoundingBox;
	};

} // end namespace scene
} // end namespace irr

#endif


/*! \mainpage Irrlicht Engine 1.3 API documentation
 *
  <div align="center"><img src="logobig.png" ></div>
 *
  \section intro Introduction
 *
  Welcome to the Irrlicht Engine API documentation.
  Here you'll find any information you'll need to develop applications with
  the Irrlicht Engine. If you are looking for a tutorial on how to start, you'll
  find some on the homepage of the Irrlicht Engine at 
  <A HREF="http://irrlicht.sourceforge.net" >irrlicht.sourceforge.net</A> 
  or inside the SDK in the directory \examples.
 *
  The Irrlicht Engine is intended to be an easy-to-use 3d engine, so
  this documentation is an important part of it. If you have any questions or
  suggestions, just send a email to the author of the engine, Nikolaus Gebhardt
  (niko (at) irrlicht3d.org).
 *
 *
  \section links Links
 *
  <A HREF="namespaces.html">Namespaces</A>: A very good place to start reading
  the documentation.<BR>
  <A HREF="annotated.html">Class list</A>: List of all classes with descriptions.<BR>
  <A HREF="functions.html">Class members</A>: Good place to find forgotten features.<BR>
 *
  \section irrexample Short example
 *
  A simple application, starting up the engine, loading a Quake 2 animated 
  model file and the corresponding texture, animating and displaying it
  in front of a blue background and placing a user controlable 3d camera
  would look like the following code. I think this example shows the usage
  of the engine quite well:
 *
  \code
  #include <irrlicht.h>
  using namespace irr;
 *
  int main()
  {
 	// start up the engine
 	IrrlichtDevice device = createDevice(video::EDT_DIRECT3D8,
 		core::dimension2d<s32>(640,480));
 *
 	video::IVideoDriver driver = device->getVideoDriver();
 	scene::ISceneManager scenemgr = device->getSceneManager();
 *
 	device->setWindowCaption(L"Hello World!");
 *
 	// load and show quake2 .md2 model
 	scene::ISceneNode node = scenemgr->addAnimatedMeshSceneNode(
 		scenemgr->getMesh("quake2model.md2"));
 *
 	// if everything worked, add a texture and disable lighting
 	if (node)
 	{
 		node->setMaterialTexture(0, driver->getTexture("texture.bmp"));
 		node->setMaterialFlag(video::EMF_LIGHTING, false);
 	}
 *
 	// add a first person shooter style user controlled camera
 	scenemgr->addCameraSceneNodeFPS();
  
 	// draw everything
 	while(device->run() && driver)
 	{
 		driver->beginScene(true, true, video::SColor(255,0,0,255));
 		scenemgr->drawAll();
 		driver->endScene();
 	}
 *
 	// delete device
 	device->drop();
 	return 0;
  }
  \endcode
 *
  Irrlicht can load a lot of file formats automaticly, see irr::scene::ISceneManager::getMesh()
  for a detailed list. So if you would like to replace the simple blue screen background by
  a cool Quake 3 Map, optimized by an octtree, just insert this code
  somewhere before the while loop:
 *
  \code
 	// add .pk3 archive to the file system
 	device->getFileSystem()->addZipFileArchive("quake3map.pk3");
 *
 	// load .bsp file and show it using an octtree
 	scenemgr->addOctTreeSceneNode(
 		scenemgr->getMesh("quake3map.bsp"));
  \endcode
 *
  As you can see, the engine uses namespaces. Everything in the engine is
  placed into the namespace 'irr', but there are also 5 sub namespaces.
  You can find a list of all namespaces with descriptions at the 
  <A HREF="namespaces.html"> namespaces page</A>. 
  This is also a good place to start reading the documentation. If you
  don't want to write the namespace names all the time, just use all namespaces like 
  this:
  \code
  using namespace core;
  using namespace scene;
  using namespace video;
  using namespace io;
  using namespace gui;
  \endcode
 *
  There is a lot more the engine can do, but I hope this gave a short
  overview over the basic features of the engine. For more examples, please take
  a look into the examples directory of the SDK.
 */

// Copyright (C) 2002-2007 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __I_IRRLICHT_CREATION_PARAMETERS_H_INCLUDED__
#define __I_IRRLICHT_CREATION_PARAMETERS_H_INCLUDED__

namespace irr
{
	//! Structure for holding advanced Irrlicht Device creation parameters.
	/* This structure is only used in the createDeviceEx() function. */
	struct SIrrlichtCreationParameters
	{
		//! Constructs a SIrrlichtCreationParameters structure with default values.
		SIrrlichtCreationParameters()
		{
			DriverType = video::EDT_BURNINGSVIDEO;
			WindowSize = core::dimension2d<s32>(800, 600);
			Bits = 16;
			Fullscreen = false;
			Stencilbuffer = false;
			Vsync = false;
			AntiAlias = false;
			HighPrecisionFPU = false;
			EventReceiver = 0;
			WindowId = 0;
			SDK_version_do_not_use = IRRLICHT_SDK_VERSION;
		}

		//! Type of the device. 
		/* This can currently be video::EDT_NULL, 
		video::EDT_SOFTWARE, video::EDT_DIRECT3D8, video::EDT_DIRECT3D9 and video::EDT_OPENGL. 
		Default: Software. */
		video::E_DRIVER_TYPE DriverType;

		//! Size of the window or the video mode in fullscreen mode. Default: 800x600
		core::dimension2d<s32> WindowSize;

		//! Bits per pixel in fullscreen mode. Ignored if windowed mode. Default: 16.
		u32 Bits;

		//! Should be set to true if the device should run in fullscreen. 
		/* Otherwise the device runs in windowed mode. Default: false.  */
		bool Fullscreen;

		//! Specifies if the stencil buffer should be enabled. 
		/* Set this to true,
	    if you want the engine be able to draw stencil buffer shadows. Note that not all
		devices are able to use the stencil buffer. If they don't no shadows will be drawn. 
		Default: false. */
		bool Stencilbuffer;

		//! Specifies vertical syncronisation.
		/* If set to true, the driver will wait for the vertical retrace period, otherwise not.
		Default: false */
		bool Vsync;

		//! Specifies if the device should use fullscreen anti aliasing
		/* Makes sharp/pixelated edges softer, but requires more performance. Also, 2D 
		elements might look blurred with this switched on. The resulting rendering quality 
		also depends on the hardware and driver you are using, your program might look
		different on different hardware with this. So if you are writing a 
		game/application with antiAlias switched on, it would be a good idea to make it
		possible to switch this option off again by the user.
		This is only supported in D3D9 and D3D8. In D3D9, both sample types are supported,
		D3DMULTISAMPLE_X_SAMPLES and D3DMULTISAMPLE_NONMASKABLE. Default value: false */
		bool AntiAlias;

		//! Specifies if the device should use high precision FPU setting
		/* This is only relevant for DirectX Devices, which switch to low FPU precision
		by default for performance reasons. However, this may lead to problems with the
		other computations of the application. In this case setting this flag to true
		should help - on the expense of performance loss, though.
		Default value: false */
		bool HighPrecisionFPU;

		//! A user created event receiver.
		IEventReceiver* EventReceiver;

		//! Window Id.
		/* If this is set to a value other than 0, the Irrlicht Engine will be created in 
		an already existing window. For windows, set this to the HWND of the window you want.
		The windowSize and FullScreen options will be ignored when using the WindowId parameter.
		Default this is set to 0. 
		To make Irrlicht run inside the custom window, you still will have to draw Irrlicht
		on your own. You can use this loop, as usual:
		\code
		while (device->run())
		{
			driver->beginScene(true, true, 0);
			smgr->drawAll();
			driver->endScene();
		}
		\endcode
		Instead of this, you can also simply use your own message loop
		using GetMessage, DispatchMessage and whatever. Calling
		IrrlichtDevice::run() will cause Irrlicht to dispatch messages internally too. 
		You need not call Device->run() if you want to do your own message 
		dispatching loop, but Irrlicht will not be able to fetch
		user input then and you have to do it on your own using the window
		messages, DirectInput, or whatever. Also, you'll have to increment the Irrlicht timer.
		An alternative, own message dispatching loop without device->run() would
		look like this:
		\code
		MSG msg;
		while (true)
		{
			if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);

				if (msg.message == WM_QUIT)
					break;
			}

			// increase virtual timer time
			device->getTimer()->tick();

			// draw engine picture
			driver->beginScene(true, true, 0);
			smgr->drawAll();
			driver->endScene();
		}
		\endcode
		However, there is no need to draw the picture this often. Just do it how you like.
		*/
		s32 WindowId;

		//! Don't use or change this parameter. 
		/* Always set it to IRRLICHT_SDK_VERSION, which is done by default.
		This is needed for sdk version checks. */
		const c8* SDK_version_do_not_use;
	};


} // end namespace irr

#endif


//! Everything in the Irrlicht Engine can be found in this namespace.
namespace irr
{
	//! Creates an Irrlicht device. The Irrlicht device is the root object for using the engine.
	/* If you need more parameters to be passed to the creation of the Irrlicht Engine device,
	use the createDeviceEx() function.
	\param deviceType: Type of the device. This can currently be video::EDT_NULL, 
	video::EDT_SOFTWARE, video::EDT_BURNINGSVIDEO, video::EDT_DIRECT3D8, video::EDT_DIRECT3D9 and video::EDT_OPENGL.
	\param windowSize: Size of the window or the video mode in fullscreen mode.
	\param bits: Bits per pixel in fullscreen mode. Ignored if windowed mode.
	\param fullscreen: Should be set to true if the device should run in fullscreen. Otherwise
		the device runs in windowed mode.
	\param stencilbuffer: Specifies if the stencil buffer should be enabled. Set this to true,
	    if you want the engine be able to draw stencil buffer shadows. Note that not all
		devices are able to use the stencil buffer. If they don't no shadows will be drawn.
	\param vsync: Specifies vertical syncronisation: If set to true, the driver will wait 
		for the vertical retrace period, otherwise not.
	\param receiver: A user created event receiver.
	\param sdk_version_do_not_use: Don't use or change this parameter. Always set it to
	IRRLICHT_SDK_VERSION, which is done by default. This is needed for sdk version checks.
	\return Returns pointer to the created IrrlichtDevice or null if the 
	device could not be created.
	*/
	IRRLICHT_API IrrlichtDevice* IRRCALLCONV createDevice(
		video::E_DRIVER_TYPE deviceType = video::EDT_SOFTWARE, 
		const core::dimension2d<s32>& windowSize = core::dimension2d<s32>(640,480),
		u32 bits = 16,
		bool fullscreen = false,
		bool stencilbuffer=false,
		bool vsync=false,
		IEventReceiver* receiver = 0,
		const c8* sdk_version_do_not_use = IRRLICHT_SDK_VERSION);

	//! Creates an Irrlicht device with the option to specify advanced parameters. 
	/* Usually you should used createDevice() for creating an Irrlicht Engine device.
	Use this function only if you wish to specify advanced parameters like a window
	handle in which the device should be created.
	\param parameters: Structure containing advanced parameters for the creation of the device.
	See irr::SIrrlichtCreationParameters for details.
	\return Returns pointer to the created IrrlichtDevice or null if the 
	device could not be created. */
	IRRLICHT_API IrrlichtDevice* IRRCALLCONV createDeviceEx(
		const SIrrlichtCreationParameters& parameters);


	// THE FOLLOWING IS AN EMPTY LIST OF ALL SUB NAMESPACES
	// EXISTING ONLY FOR THE DOCUMENTATION SOFTWARE DOXYGEN.

	//! In this namespace can be found basic classes like vectors, planes, arrays, lists and so on.
	namespace core
	{
	}

	//! The gui namespace contains useful classes for easy creation of a graphical user interface.
	namespace gui
	{
	}

	//! This namespace provides interfaces for input/output: Reading and writing files, accessing zip archives, xml files, ...
	namespace io
	{
	}

	//! All scene management can be found in this namespace: Mesh loading, special scene nodes like octrees and billboards, ...
	namespace scene
	{
	}

	//! The video namespace contains classes for accessing the video driver. All 2d and 3d rendering is done here.
	namespace video
	{
	}
}

using namespace irr;
using namespace irr::core;
using namespace irr::gui;
using namespace irr::io;
using namespace irr::video;
using namespace irr::scene;

/*! \file irrlicht.h
    \brief Main header file of the irrlicht, the only file needed to include.
*/

#endif


//******************************************************
//**  MSGAEngine3DObjectInfo class
//******************************************************
class MSGAEngine3DObjectInfo
	{
	////////////////////////////////////////////////
	//@{
	bool mInitialized;
	//@}
	
	float mPosVelX;
	float mPosVelY;
	float mPosVelZ;
	float mRotVelX;
	float mRotVelY;
	float mRotVelZ;	
	matrix4 mRelativeTransformation;			// Relative Offset Transformation
	ISceneNode *mSceneNode;						// Scene Node Associated with object
	int mNodeID;								// Node id
	float mMinUpdateDistance;					// Minimum Update Distance
	bool (*mOnStop)(MSGAEngine3DObjectInfo &object,void *extra1,void *extra2);
	void *mOnStopExtra1;
	void *mOnStopExtra2;
	
	////////////////////////////////////////////////
	void ClearObject(void);
	
	////////////////////////////////////////////////
	public:
	MSGAEngine3DObjectInfo(void);
	~MSGAEngine3DObjectInfo(void);
	bool Create(ISceneNode *node,int nodeid
			,float offsetrotx=0,float offsetroty=0,float offsetrotz=0);
	bool Destroy(void);
	//@{
	bool IsInitialized(void);
	bool IsValid(void);
	//@}
	bool Update(int deltatime);					// Update information since last time
	int GetNodeID(void);						// Get Node ID
	bool SetMinUpdateDistance(float value=0);

	bool SetPos(float x,float y,float z);
	bool GetPos(float &x,float &y,float &z);
	bool SetPosVel(float x,float y,float z);
	bool GetPosVel(float &x,float &y,float &z);
	bool AddPos(float dx,float dy,float dz);
	bool AddPosVel(float dx,float dy,float dz);
	bool StopTranslation(void);					// Stops the translation

	bool SetRot(float x,float y,float z);
	bool GetRot(float &x,float &y,float &z);
	bool SetRotVel(float x,float y,float z);
	bool GetRotVel(float &x,float &y,float &z);
	bool AddRot(float dx,float dy,float dz);
	bool AddRotVel(float dx,float dy,float dz);
	bool StopRotation(void);					// Stops the rotation
	
	bool GetUp(float &nx,float &ny,float &nz);		// Get Up Vector
	bool GetFront(float &nx,float &ny,float &nz);	// Get Front Vector
	bool GetRight(float &nx,float &ny,float &nz);	// Get Right Vector

	bool SetFrontVel(float vel);				// Set a Front Velocity
	bool AddFrontVel(float vel);				// Add a Front Velocity
	bool GetFrontVel(float &vel);				// Get the front velocity

	// Set On Stop Code
	bool SetOnStop(bool onstop(MSGAEngine3DObjectInfo &ref,void *,void *)
			,void *extra1,void *extra2);
	};

#endif // MSGAEngine3DObjectInfo_h

//v1.2 copyright Comine.com 20070223F13
#ifndef MSGAEngine3DFontInfo_h
#define MSGAEngine3DFontInfo_h

///////////////////////////////////////////////////
//v1.24 copyright Comine.com 20070419R09
#ifndef MString_h
#define MString_h

////////////////////////////////////////////////
//v1.13 copyright Comine.com 20070329R10
#ifndef MStdLib_h
#define MStdLib_h

/////////////////////////////////////////////////
#if (_MSC_VER<=1300 || !defined(WIN32) )
#include <wchar.h>
#endif

// Include time
#include <time.h>

// Define All common functions
#ifndef	NULL
#define NULL			(0)
#endif

//////////////////////////////////////////////////
#ifdef NDEBUG
#define MStdAssert(exp)
#else

////////////////////////////////////////////////////////////////
void MStdAssertInternal(bool exp,const char *expinfo,const char *filename,int lineno);
#define MStdAssert(exp)	MStdAssertInternal(exp,#exp,__FILE__,__LINE__)

#endif // NDEBUG

//////////////////////////////////////////////////
// Abstract File Handles
typedef void *MStdFileHandle;

//////////////////////////////////////////////////
MStdFileHandle MStdFileOpen(const char *filename,const char *mode);		// Open file
bool MStdSetStdInMode(bool binary=false);				// Reset Mode to binary/text
bool MStdSetStdOutMode(bool binary=false);				// Open StdInput
bool MStdFileClose(MStdFileHandle handle);				// Close File Handle
MStdFileHandle MStdGetStdIn(void);						// Get File stdin
MStdFileHandle MStdGetStdOut(void);						// Get File stdout
bool MStdFileWrite(MStdFileHandle handle,const char *stri);		// Write a string
int MStdFileWrite(MStdFileHandle handle,const void *buffer
		,int elementsize,int elementcount);				// Write to file
int MStdFileRead(MStdFileHandle handle,void *buffer,int elementsize
		,int elementcount);								// Read file
bool MStdFileGetString(MStdFileHandle handle,char *buffer,int buffersize);
bool MStdFileFlush(MStdFileHandle handle);				// Flush the file
bool MStdFileSeek(MStdFileHandle handle,int offset,int type);	//type 0-start,1-middle,2-end
long MStdFileTell(MStdFileHandle handle);				// Get Position in file

//////////////////////////////////////////////////
// Console Operations
int MStdPrintf(const char *format,...);					// Console Output
int MStdErrPrintf(const char *format,...);				// Console Error
bool MStdGetString(char *buffer,int size);				// Read Console String
bool MStdOpenConsoleIO(void);							// Reopen console Input
bool MStdSetOutput(const char *filename);				// Set Standard ouput to file
bool MStdSetInput(const char *filename);				// Set Standard Input from file
bool MStdSetError(const char *filename);				// Set Standard Error to file

//////////////////////////////////////////////////
// String Operations
int MStdSPrintf(char *target,int targetsize,const char *format,...);	// String Formated Printf
const char *MStdStr(bool value);						// Build a temp string
const char *MStdStr(int value);							// Build a temp string
const char *MStdStr(float value);						// Build a temp string
const char *MStdStr(double value);						// Build a temp string
bool MStdStrCpy(char *dst,const char *src);				// String Copy
bool MStdStrCpy(char *dst,int dstsize,const char *src);	// String Copy
int MStdStrLen(const char *src);						// String Length
int MStdStrCmp(const char *str1,const char *str2);		// String Compare
int MStdStrICmp(const char *str1,const char *str2);		// String Compare
bool MStdStrCat(char *dst,int dstsize,const char *src);	// String Catenate
bool MStdStrBegins(const char *str,const char *prefix);	// Check if string begins with prefix
bool MStdStrIBegins(const char *str,const char *prefix);	// Check if string begins with prefix
bool MStdIsSubStr(const char *str,const char *substring);	// Check if substring
bool MStdIsISubStr(const char *str,const char *substring);	// Check if insensitive substring
bool MStdStrToLower(char *str);							// Convert string to lower
bool MStdStrToUpper(char *str);							// Convert string to lower

/////////////////////////////////////////////////
// Wide String Operations
int MStdSPrintf(wchar_t *target,int targetsize,const wchar_t *format,...);	// String Formated Printf
const wchar_t *MStdStrWide(bool value);					// Build a temp string
const wchar_t *MStdStrWide(int value);					// Build a temp string
const wchar_t *MStdStrWide(float value);				// Build a temp string
const wchar_t *MStdStrWide(double value);				// Build a temp string
bool MStdStrCpy(wchar_t *dst,const wchar_t *src);		// String Copy
bool MStdStrCpy(wchar_t *dst,int dstsize,const wchar_t *src);	// String Copy
int MStdStrLen(const wchar_t *src);						// String Length
int MStdStrCmp(const wchar_t *str1,const wchar_t *str2);	// String Compare
int MStdStrICmp(const wchar_t *str1,const wchar_t *str2);	// String Compare
bool MStdStrCat(wchar_t *dst,int dstsize,const wchar_t *src);	// String Catenate
bool MStdStrBegins(const wchar_t *str,const wchar_t *prefix);	// Check if string begins with prefix
bool MStdStrIBegins(const wchar_t *str,const wchar_t *prefix);	// Check if string begins with prefix
bool MStdIsSubStr(const wchar_t *str,const wchar_t *substring);	// Check if substring
bool MStdIsISubStr(const wchar_t *str,const wchar_t *substring);	// Check if insensitive substring
bool MStdStrToLower(wchar_t *str);						// Convert string to lower
bool MStdStrToUpper(wchar_t *str);						// Convert string to lower

//////////////////////////////////////////////////
// Extra Functions
bool MStdWindowOutput(const char *title,const char *info);	// Dialog Box if availible
bool MStdSleep(int ms);									// Sleep for some ms
bool MStdExit(int value);								// Exit application

//////////////////////////////////////////////////
// Char Functions
bool MStdIsSpace(char ch);
bool MStdIsDigit(char ch);
bool MStdIsAlpha(char ch);
bool MStdIsAlphaNumeric(char ch);
bool MStdIsUpper(char ch);
bool MStdIsLower(char ch);
char MStdToLower(char ch);
char MStdToUpper(char ch);

////////////////////////////////////////////////////
// Wide Char Functions
bool MStdIsSpace(wchar_t ch);
bool MStdIsDigit(wchar_t ch);
bool MStdIsAlpha(wchar_t ch);
bool MStdIsAlphaNumeric(wchar_t ch);
bool MStdIsUpper(wchar_t ch);
bool MStdIsLower(wchar_t ch);
wchar_t MStdToLower(wchar_t ch);
wchar_t MStdToUpper(wchar_t ch);

//////////////////////////////////////////////////
// Memory Functions
bool MStdMemCpy(void *target,const void *src,int count);		// Copy block of memory
bool MStdMemSet(void *,int value,int size);				// Set Buffer with zero
bool MStdMemZero(void *,int size);						// Set buffer to zero
int MStdMemCmp(const void *src,const void *dst,int size);		// Compare two memory blocks
bool MStdMemMove(void *dst,void *src,int count);		// Move Memory
void *MStdMalloc(int size);								// Allocate block of memory
bool MStdFree(void *memblock);							// Free Block of memory
void *MStdReAlloc(void *memblock,int newsize);			// Realloc memory with new size

//////////////////////////////////////////////////
bool MStdKbHit(void);									// Check if keyboard clicked
int MStdGetCh(bool forcestdio=false);					// Get Entered char

//////////////////////////////////////////////////
bool MStdCTime(char *buf,int bufsize,time_t *tm);		// Convert time into a string

//////////////////////////////////////////////////
// Call this function at exit
bool MStdAtExit(void fun(void));
bool MStdFileRemove(const char *filename);

///////////////////////////////////////////////////
// Conversion Functions
int MStdAToI(const char *str);							// Convert string to integer
int MStdAToI(const wchar_t *str);						// Convert string to integer
double MStdAToF(const char *str);						// Convert string to double
double MStdAToF(const wchar_t *str);					// Convert string to double
int MStdGetMax(int value1,int value2);					// Get Max of two values
float MStdGetMax(float value1,float value2);			// Get Max of two values
double MStdGetMax(double value1,double value2);			// Get Max of two values
int MStdGetMin(int value1,int value2);					// Get Min of two values
float MStdGetMin(float value1,float value2);			// Get Min of two values
double MStdGetMin(double value1,double value2);			// Get Min of two values
int MStdGetAbs(int value);								// Get Absolute Value
float MStdGetAbs(float value);							// Get Absolute Value
double MStdGetAbs(double value);						// Get Absolute Value

//////////////////////////////////////////////////
// Random Number Generation
void MStdSRand(int seed);								// Seed
int MStdRand(int range=32767);							// Random Number

//////////////////////////////////////////////////
// Log File
bool MStdLog(const char *logentry,const char *file,int lineno);

#endif // MStdLib_h


////////////////////////////////////////////////
class MStringWide;  // forward declaration

///////////////////////////////////////////////
class MString
	{
	//@{
	bool mInitialized;
	//@}
	char *mString;	// Points to a copy of a string
	int mLength;	// Holds the string length

	/////////////////////////////////////////////
	void ClearObject(void);

	/////////////////////////////////////////////
	public:
	MString(void);
	MString(const char *str);
	MString(const wchar_t *str);
	MString(const MString &str);			// Copy Constructor
	MString(MStringWide &str);
	~MString(void);
	bool Create(const char *str);
	bool Create(const wchar_t *str);
	bool Create(MString &str);
	bool Create(MStringWide &str);
	bool Create(char ch);
	bool Create(wchar_t ch);
	bool Destroy(void);
	//@{
	bool IsInitialized(void);
	bool IsValid(void);
	//@}

	// Operators
	bool operator=(const char *str);
	bool operator=(const wchar_t *str);
	bool operator=(const MString &src);
	MString operator +(const char *str);		// return a temp object
	MString operator +(MString &ref);			// return a temp object
	MString operator +(MStringWide &ref);		// return a temp object
	char &operator[](int index);
	const char *Get(void);
	const char *GetEnd(int count);				// Get End String
	bool ToUpper(void);
	bool ToLower(void);
	bool Trim(void);							// Trim Spaces
	bool TrimLeft(void);						// Trim Spaces on the Left
	bool TrimRight(void);						// Trim Spaces on the Right
	bool TrimRight(int length);					// Trim Spaces on the Right
	bool Append(const char *str);
	bool Append(const wchar_t *str);
	bool Append(char ch);
	bool Append(wchar_t ch);
	bool Append(int val);
	bool Append(float val);
	bool Append(double val);
	bool Append(bool val);
	int Length(void);
	int Compare(const char *string);
	int Compare(const wchar_t *string);
	int Compare(MString &string);
	int Compare(MStringWide &string);

	/////////////// Class Methods ////////////////////
	// Basic String Copy
	static bool Copy(char *dest,const char *src);
	static bool Copy(char *dest,const wchar_t *src);
	static bool Copy(wchar_t *dest,const char *src);
	static bool Copy(wchar_t *dest,const wchar_t *src);
	static bool Copy(char *dest,const char *src,int maxcopy);
	static bool Copy(char *dest,const wchar_t *src,int maxcopy);
	static bool Copy(wchar_t *dest,const char *src,int maxcopy);
	static bool Copy(wchar_t *dest,const wchar_t *src,int maxcopy);


	// Basic String Length
	static int Length(const char *str);
	static int Length(const wchar_t *str);

	// Basic String Compare
	static int Compare(const char *src,const char *dst);
	static int Compare(const wchar_t *src,const char *dst);
	static int Compare(const char *src,const wchar_t *dst);
	static int Compare(const wchar_t *src,const wchar_t *dst);

	// Basic String CaseInsensitive Compare
	static int ICompare(const char *src,const char *dst);
	static int ICompare(const wchar_t *src,const char *dst);
	static int ICompare(const char *src,const wchar_t *dst);
	static int ICompare(const wchar_t *src,const wchar_t *dst);


	// Basic Char Operations
	static bool IsSpace(char ch);  // for ' ',/r/n/t
	static bool IsSpace(wchar_t ch);
	static char ToUpper(char ch);
	static char ToLower(char ch);
	static wchar_t ToUpper(wchar_t ch);
	static wchar_t ToLower(wchar_t ch);

	// String Conversions
	static bool ToLower(char *str);
	static bool ToLower(wchar_t *str);
	static bool ToUpper(char *str);
	static bool ToUpper(wchar_t *str);
	static bool Trim(char *str);  // Remove All spaces
	static bool Trim(wchar_t *str);  // Remove All spaces
	static bool TrimLeft(char *str);
	static bool TrimRight(char *str);
	static bool TrimLeft(wchar_t *str);
	static bool TrimRight(wchar_t *str);

	// Append Operations
	static bool Append(char *str,const char *src);
	static bool Append(char *str,const wchar_t *src);
	static bool Append(wchar_t *str,const char *src);
	static bool Append(wchar_t *str,const wchar_t *src);

	// Dynamic Memory Allocation
	static char *Alloc(const char *st,const char *file,int lineno);
	static char *Alloc(const char *st,const char *st2,const char *file,int lineno);
	};



////////////////////////////////////////////////
class MStringWide
	{
	//@{
	bool mInitialized;
	//@}
	wchar_t *mString;	// Points to a copy of a string
	int mLength;		// Holds the string length

	/////////////////////////////////////////////
	void ClearObject(void);

	/////////////////////////////////////////////
	public:
	MStringWide(void);
	MStringWide(const char *str);
	MStringWide(const wchar_t *str);
	MStringWide(const MStringWide &str);
	MStringWide(MString &str);
	~MStringWide(void);
	bool Create(const char *str);
	bool Create(const wchar_t *str);
	bool Create(MString &str);
	bool Create(const MStringWide &str);
	bool Create(char ch);
	bool Create(wchar_t ch);
	bool Destroy(void);
	//@{
	bool IsInitialized(void);
	bool IsValid(void);
	//@}
	bool operator=(const char *str);
	bool operator=(const wchar_t *str);
	bool operator=(const MStringWide &src);
	wchar_t &operator[](int index);
	const wchar_t *Get(void);
	const wchar_t *GetEnd(int count);			// Get End String
	bool ToUpper(void);
	bool ToLower(void);
	bool Trim(void);
	bool TrimLeft(void);
	bool TrimRight(void);
	bool TrimRight(int length);
	bool Append(const wchar_t *str);
	bool Append(const char *str);
	bool Append(char ch);
	bool Append(wchar_t ch);
	bool Append(int val);
	bool Append(float val);
	bool Append(double val);
	bool Append(bool val);
	int Length(void);
	int Compare(const char *string);
	int Compare(const wchar_t *string);
	int Compare(MString &string);
	int Compare(MStringWide &string);
	};


#endif // MString_h

//******************************************************
//**  MSGAEngine3DFontInfo class
//******************************************************
class MSGAEngine3DFontInfo
	{
	////////////////////////////////////////////////
	//@{
	bool mInitialized;
	//@}
	int mRows;								// Rows in original sprite
	int mCols;								// Cols in original sprite
	MString mLookup;						// String for lookup
	ITexture **mArray;						// Array of ITextures
	
	////////////////////////////////////////////////
	void ClearObject(void);
	int GetIndex(int row,int col);			// Get Index by using row/col
	
	////////////////////////////////////////////////
	public:
	MSGAEngine3DFontInfo(void);
	~MSGAEngine3DFontInfo(void);
	bool Create(IVideoDriver *driver,const char *filename
				,int rows,int cols,const char *lookup);
	bool Destroy(void);
	//@{
	bool IsInitialized(void);
	bool IsValid(void);
	//@}
	ITexture *GetChar(char ch,bool casesensitive=false);				// Return texture where object
	};

#endif // MSGAEngine3DFontInfo_h

//v1.0 copyright Comine.com 20070204U13
#ifndef MSGAEngine3DTextureInfo_h
#define MSGAEngine3DTextureInfo_h

////////////////////////////////////////////////////

//******************************************************
//**  MSGAEngine3DTextureInfo class
//******************************************************
class MSGAEngine3DTextureInfo
	{
	////////////////////////////////////////////////
	//@{
	bool mInitialized;
	//@}
	ITexture *mTexture;					// Texture Reference
	IVideoDriver *mVideoDriver;			// Video Driver Reference
	
	////////////////////////////////////////////////
	void ClearObject(void);
	
	////////////////////////////////////////////////
	public:
	MSGAEngine3DTextureInfo(void);
	~MSGAEngine3DTextureInfo(void);
	bool Create(ITexture *texture,IVideoDriver *videodriver);
	bool Destroy(void);
	//@{
	bool IsInitialized(void);
	bool IsValid(void);
	//@}
	ITexture *GetTexture(void);
	};

#endif // MSGAEngine3DTextureInfo_h

//v1.1 copyright Comine.com 20070222R02
#ifndef MSGAEngine3DMeshInfo_h
#define MSGAEngine3DMeshInfo_h

////////////////////////////////////////////////////

//******************************************************
//**  MSGAEngine3DMeshInfo class
//******************************************************
class MSGAEngine3DMeshInfo
	{
	////////////////////////////////////////////////
	//@{
	bool mInitialized;
	//@}
	bool mDropMesh;						// If Mesh has to be dropped
	IAnimatedMesh *mMesh;				// Reference to Mesh
	bool mIsSMeshBuffer;				// Is type of SMeshBuffer
	
	////////////////////////////////////////////////
	void ClearObject(void);
	
	////////////////////////////////////////////////
	public:
	MSGAEngine3DMeshInfo(void);
	~MSGAEngine3DMeshInfo(void);
	bool Create(IAnimatedMesh *mesh,bool dropmesh,bool ismeshbuffer);
	bool Destroy(void);
	//@{
	bool IsInitialized(void);
	bool IsValid(void);
	//@}
	IAnimatedMesh *GetMesh(void);
	bool IsSMeshBuffer(void);
	};

#endif // MSGAEngine3DMeshInfo_h

//v1.3 copyright Comine.com 20070314W00
#ifndef MSGAEngine3DNodeInfo_h
#define MSGAEngine3DNodeInfo_h

///////////////////////////////////////////////////

//******************************************************
//**  MSGAEngine3DNodeInfoType class
//******************************************************
enum MSGAEngine3DNodeInfoType
	{
	MSGAE3DNIT_CUBE,
	MSGAE3DNIT_SPHERE,
	MSGAE3DNIT_TEXT,
	MSGAE3DNIT_WATER_SURFACE,
	MSGAE3DNIT_TERRAIN,
	MSGAE3DNIT_SKY_BOX,
	MSGAE3DNIT_SKY_DOME,
	MSGAE3DNIT_SHADOW_VOLUME,
	MSGAE3DNIT_OCT_TREE,
	MSGAE3DNIT_MESH,
	MSGAE3DNIT_LIGHT,
	MSGAE3DNIT_EMPTY,
	MSGAE3DNIT_DUMMY_TRANSFORMATION,
	MSGAE3DNIT_CAMERA,
	MSGAE3DNIT_CAMERA_MAYA,
	MSGAE3DNIT_CAMERA_FPS,
	MSGAE3DNIT_BILLBOARD,
	MSGAE3DNIT_ANIMATED_MESH,
	MSGAE3DNIT_PARTICLE_SYSTEM,
	MSGAE3DNIT_FONT_TEXT,
	MSGAE3DNIT_LOD_NODE
	};


//******************************************************
//**  MSGAEngine3DNodeInfo class
//******************************************************
class MSGAEngine3DNodeInfo
	{
	////////////////////////////////////////////////
	//@{
	bool mInitialized;
	//@}
	class MSGAEngine3D *mRefEngine;	// Reference to Engine
	ISceneManager *mSceneMgr;		// Scene Manager
	ISceneNode *mNode;				// Reference to Scene Node
	bool mRemoveOnDelete;			// Remove Node from Scene Graph On Delete
	MSGAEngine3DNodeInfoType mNodeType;		// Scene Node Type
	bool (*mLODCallBack)(class MSGAEngine3D &engine,float cameradistance2
			,int nodeid,void *extra);
	void *mLODCallBackExtra;
	
	////////////////////////////////////////////////
	void ClearObject(void);
	
	////////////////////////////////////////////////
	public:
	MSGAEngine3DNodeInfo(void);
	~MSGAEngine3DNodeInfo(void);
	bool Create(class MSGAEngine3D &refengine
			,ISceneNode *node,MSGAEngine3DNodeInfoType nodetype);
	bool Destroy(void);
	//@{
	bool IsInitialized(void);
	bool IsValid(void);
	//@}
	ISceneNode *GetNode(void);
	bool SetRemoveOnDelete(bool value);	// Remove Node from scene graph on delete
	MSGAEngine3DNodeInfoType GetNodeType(void);	// Get Scene Node Type
	bool SetLODCallBack(bool lodcallback(class MSGAEngine3D &engine
			,float cameradistance2,int nodeid,void *extra),void *extra);
	bool GetLODCallBack(bool (*&lodcallback)(class MSGAEngine3D &engine
			,float cameradistance2,int nodeid,void *extra),void *&extra);	
	};

#endif // MSGAEngine3DNodeInfo_h

//v1.2 copyright Comine.com 20070209F09
#ifndef MSGAEngine3DTaskInfo_h
#define MSGAEngine3DTaskInfo_h

////////////////////////////////////////////////////
//v2.3 copyright Comine.com 20070303S21
#ifndef MTimeEventHeap_h
#define MTimeEventHeap_h

////////////////////////////////////////////////
//v1.7 copyright Comine.com 20060223R09
#ifndef MBlockMgr_h
#define MBlockMgr_h

//******************************************************
//**  MBlockMgr class
//******************************************************
class MBlockMgr
	{
	////////////////////////////////////////////////
	//@{
	bool mInitialized;
	//@}
	int mCount;					// Maximum number of Blocks
	int mBlockSize;				// Allocate to nearest int boundary
	char *mArray;				// Pointer to array where blocks are stored
	int *mBlockAllocTable;		// points to an allocation table
	int mFirstBlock;			// Holds the first unused block
	int mLastBlock;				// Holds the last used block
	
	////////////////////////////////////////////////
	void ClearObject(void);
	
	////////////////////////////////////////////////
	public:
	MBlockMgr(void);
	~MBlockMgr(void);
	bool Create(int msgsize,int maxcount);
	bool Destroy(void);
	//@{
	bool IsInitialized(void);
	bool IsValid(void);
	//@}
	bool Clear(void);			// Free All Blocks to pool	
	int GetBlockSize(void);		// Returns calculated max block size (int aligned)
	int GetPoolSize(void);		// Get Number of blocks in pool
	int Alloc(void);			// =-1 on failure, Allocate a block from pool 
	void *GetAddress(int id);	// =NULL(if not used). Otherwise,=address of block
	int GetID(void *address);	// Get Block ID from address
	bool Free(int id);			// Release the block
	bool IsUsed(int id);		// =true id is used
	};

#endif // MBlockMgr_h


//******************************************************
//**  MTimeEventHeapInfo class
//******************************************************
struct MTimeEventHeapInfo
	{
	int EventID;					// May be used to identify info
	};


//******************************************************
//**  MTimeEventHeap class
//******************************************************
class MTimeEventHeap
	{
	////////////////////////////////////////////////
	bool mInitialized;
	MBlockMgr mBlockMgr;					// Holds all the messages
	int mMaxLength;							// Maximum Length of Event Queue
	int mLength;							// Holds the length
	struct GEventHeapNode **mArray;			// Holds an array of pointers
	static MTimeEventHeapInfo *GExtraData;	// Dummy Variable for extra data
	
	////////////////////////////////////////////////
	void ClearObject(void);
	
	////////////////////////////////////////////////
	public:
	MTimeEventHeap(void);
	~MTimeEventHeap(void);
	bool Create(int maxcapacity,int extradata=0);
	bool Destroy(void);
	//@{
	bool IsInitialized(void);
	bool IsValid(void);
	//@}
	int Enqueue(unsigned int abstime_ms
			,bool onaction(unsigned int scheduledtime,MTimeEventHeapInfo *extradata)
			,bool onend(MTimeEventHeapInfo *extradata)=NULL
			,MTimeEventHeapInfo *&info=GExtraData);				//=Returns an eventid
	bool Dequeue(void);						// Dequeue the first item	
	bool IsEmpty(void);						//=true if queue is empty
	bool IsFull(void);						//=true if queue is Full
	int GetLength(void);					// Get Current Queue Size
	int GetMaxQueueSize(void);				// Get Maximum Queue Size
	bool Clear(void);						// Clear the queue
	bool ResetTimes(void);					// Reset all times relative to first node
	bool ClearEvent(int eventid);			// Clear Event (Just sets action to NULL)
	bool Process(unsigned int currenttime);	// Process all events
	};

#endif // MTimeEventHeap_h


//******************************************************
//**  MSGAEngine3DTaskInfo class
//******************************************************
class MSGAEngine3DTaskInfo
	{
	////////////////////////////////////////////////
	//@{
	bool mInitialized;
	//@}
	int mEventID;
	MTimeEventHeap *mRefEventHeap;
	void *mData[7];						// Hold 7*4 bytes of data

	////////////////////////////////////////////////
	void ClearObject(void);
	
	////////////////////////////////////////////////
	public:
	MSGAEngine3DTaskInfo(void);
	~MSGAEngine3DTaskInfo(void);
	bool Create(int eventid,MTimeEventHeap *refheap);
	bool Destroy(void);
	//@{
	bool IsInitialized(void);
	bool IsValid(void);
	//@}
	int GetEventID(void);
	bool SetEventID(int eventid);
	bool SetData(int index,int value);
	int GetData(int index);
	bool SetDataPtr(int index,void *value);
	void *GetDataPtr(int index);
	bool SetDataFloat(int index,float value);
	float GetDataFloat(int index);
	};

#endif // MSGAEngine3DTaskInfo_h

//v1.1 copyright Comine.com 20070328W13
#ifndef MSGAEngine3DGUIInfo_h
#define MSGAEngine3DGUIInfo_h

/////////////////////////////////////////////////////////

//******************************************************
//**  MSGAEngine3DGUIInfoType Enumerations
//******************************************************
enum MSGAEngine3DGUIInfoType
	{
	MSGA3DGIT_LABEL,
	MSGA3DGIT_TEXTBOX,
	MSGA3DGIT_BUTTON,
	MSGA3DGIT_LISTBOX
	};

//******************************************************
//**  MSGAEngine3DGUIInfo class
//******************************************************
class MSGAEngine3DGUIInfo
	{
	////////////////////////////////////////////////
	//@{
	bool mInitialized;
	//@}
	IGUIElement *mRef;
	class MSGAEngine3D *mEngine;
	bool (*mOnEvent)(MSGAEngine3D &ref,int iextra,void *pextra);
	int mIExtra;
	void *mPExtra;
	MSGAEngine3DGUIInfoType mControlType;

	
	////////////////////////////////////////////////
	void ClearObject(void);
	
	////////////////////////////////////////////////
	public:
	MSGAEngine3DGUIInfo(void);
	~MSGAEngine3DGUIInfo(void);
	bool Create(IGUIElement *ref
			,MSGAEngine3D *engine
			,MSGAEngine3DGUIInfoType controltype);
	bool Destroy(void);
	//@{
	bool IsInitialized(void);
	bool IsValid(void);
	//@}
	bool SetEventHandler(bool onevent(MSGAEngine3D &engine,int iextra,void *pextra)=NULL
			,int iextra=0
			,void *pextra=NULL);
	bool OnEvent(void);
	MSGAEngine3DGUIInfoType GetType(void);
	IGUIElement *Get(void);
	};

#endif // MSGAEngine3DGUIInfo_h

//v1.1 copyright Comine.com 20070207W10
#ifndef MSGAEngine3DAnimationInfo_h
#define MSGAEngine3DAnimationInfo_h

///////////////////////////////////////////////////

//******************************************************
//**  MSGAEngine3DAnimationInfo class
//******************************************************
class MSGAEngine3DAnimationInfo
	{
	////////////////////////////////////////////////
	//@{
	bool mInitialized;
	//@}
	int mRows;								// Rows in original sprite
	int mCols;								// Cols in original sprite
	ITexture **mArray;						// Array of ITextures
	int mDeltaTime;							// Time Between Frames
	
	////////////////////////////////////////////////
	void ClearObject(void);
	int GetIndex(int row,int col);
	
	////////////////////////////////////////////////
	public:
	MSGAEngine3DAnimationInfo(void);
	~MSGAEngine3DAnimationInfo(void);
	bool Create(IVideoDriver *driver,const char *filename
				,int rows,int cols,int deltatime);
	bool Destroy(void);
	//@{
	bool IsInitialized(void);
	bool IsValid(void);
	//@}
	int GetCount(void);						// Get count of animations
	ITexture *Get(int index);				// Return texture by index
	int GetDeltaTime(void);					// Get Delta Time
	};

#endif // MSGAEngine3DAnimationInfo_h

//v1.2 copyright Comine.com 20070426R14
#ifndef MSGAEngine3DSoundInfo_h
#define MSGAEngine3DSoundInfo_h

///////////////////////////////////////////////////
/* irrKlang.h -- interface of the 'irrKlang' library

  Copyright (C) 2002-2007 Nikolaus Gebhardt

  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.
*/

#ifndef __IRR_KLANG_H_INCLUDED__
#define __IRR_KLANG_H_INCLUDED__

// Copyright (C) 2002-2007 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __IRR_TYPES_H_INCLUDED__
#define __IRR_TYPES_H_INCLUDED__


namespace irr
{

//! 8 bit unsigned variable.
/* This is a typedef for unsigned char, it ensures portability of the engine. */
typedef unsigned char		u8; 

//! 8 bit signed variable.
/* This is a typedef for signed char, it ensures portability of the engine. */
typedef signed char		s8; 

//! 8 bit character variable.
/* This is a typedef for char, it ensures portability of the engine. */
typedef char			c8; 



//! 16 bit unsigned variable.
/* This is a typedef for unsigned short, it ensures portability of the engine. */
typedef unsigned short		u16;

//! 16 bit signed variable.
/* This is a typedef for signed short, it ensures portability of the engine. */
typedef signed short		s16; 



//! 32 bit unsigned variable.
/* This is a typedef for unsigned int, it ensures portability of the engine. */
typedef unsigned int		u32;

//! 32 bit signed variable.
/* This is a typedef for signed int, it ensures portability of the engine. */
typedef signed int		s32; 



// 64 bit signed variable.
// This is a typedef for __int64, it ensures portability of the engine. 
// This type is currently not used by the engine and not supported by compilers
// other than Microsoft Compilers, so it is outcommented.
//typedef __int64				s64; 



//! 32 bit floating point variable.
/* This is a typedef for float, it ensures portability of the engine. */
typedef float				f32; 

//! 64 bit floating point variable.
/* This is a typedef for double, it ensures portability of the engine. */
typedef double				f64; 


} // end namespace


// define the wchar_t type if not already built in.
#ifdef _MSC_VER 
#ifndef _WCHAR_T_DEFINED
//! A 16 bit wide character type.
/**
	Defines the wchar_t-type.
	In VS6, its not possible to tell
	the standard compiler to treat wchar_t as a built-in type, and 
	sometimes we just don't want to include the huge stdlib.h or wchar.h,
	so we'll use this.
*/
typedef unsigned short wchar_t;
#define _WCHAR_T_DEFINED
#endif // wchar is not defined
#endif // microsoft compiler

//! define a break macro for debugging only in Win32 mode.
#if defined(_DEBUG)
#if defined(WIN32) && defined(_MSC_VER)
#define _IRR_DEBUG_BREAK_IF( _CONDITION_ ) if (_CONDITION_) {_asm int 3}
#else 
#include <assert.h>
#define _IRR_DEBUG_BREAK_IF( _CONDITION_ ) assert( !(_CONDITION_) );
#endif
#else 
#define _IRR_DEBUG_BREAK_IF( _CONDITION_ )
#endif

//! Defines a small statement to work around a microsoft compiler bug.
/* The microsft compiler 7.0 - 7.1 has a bug:
When you call unmanaged code that returns a bool type value of false from managed code, 
the return value may appear as true. See 
http://support.microsoft.com/default.aspx?kbid=823071 for details. 
Compiler version defines: VC6.0 : 1200, VC7.0 : 1300, VC7.1 : 1310, VC8.0 : 1400*/
#if defined(WIN32) && defined(_MSC_VER) && (_MSC_VER > 1299) && (_MSC_VER < 1400)
#define _IRR_IMPLEMENT_MANAGED_MARSHALLING_BUGFIX __asm mov eax,100
#else
#define _IRR_IMPLEMENT_MANAGED_MARSHALLING_BUGFIX
#endif // _IRR_MANAGED_MARSHALLING_BUGFIX


#if defined(_DEBUG) && (defined(IRRLICHT_EXPORTS) || defined(IRRKLANG_EXPORTS))	&& defined(_MSC_VER) && !defined(_IRR_DONT_DO_MEMORY_DEBUGGING_HERE)
	
	#define CRTDBG_MAP_ALLOC
	#define _CRTDBG_MAP_ALLOC
	#define DEBUG_CLIENTBLOCK   new( _CLIENT_BLOCK, __FILE__, __LINE__)
	#include <stdlib.h>
	#include <crtdbg.h>
	#define new DEBUG_CLIENTBLOCK
#endif 

// disable truncated debug information warning in visual studio 6 by default
#if defined(_MSC_VER) && (_MSC_VER < 1300 )
#pragma warning( disable: 4786)
#endif // _MSC

#endif // __IRR_TYPES_H_INCLUDED__

// Copyright (C) 2002-2007 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __I_UNKNOWN_H_INCLUDED__
#define __I_UNKNOWN_H_INCLUDED__


namespace irr
{

	//! Base class of most objects of the Irrlicht Engine.
	/* This class provides reference counting through the methods grab() and drop().
	It also is able to store a debug string for every instance of an object.
	Most objects of the Irrlicht
	Engine are derived from IUnknown, and so they are reference counted.

	When you create an object in the Irrlicht engine, calling a method
	which starts with 'create', an object is created, and you get a pointer
	to the new object. If you no longer need the object, you have 
	to call drop(). This will destroy the object, if grab() was not called
	in another part of you program, because this part still needs the object.
	Note, that you only need to call drop() to the object, if you created it,
	and the method had a 'create' in it. 

	A simple example:

	If you want to create a texture, you may want to call an imaginable method
	IDriver::createTexture. You call
	ITexture texture = driver->createTexture(dimension2d<s32>(128, 128));
	If you no longer need the texture, call texture->drop().

	If you want to load a texture, you may want to call imaginable method
	IDriver::loadTexture. You do this like
	ITexture texture = driver->loadTexture("example.jpg");
	You will not have to drop the pointer to the loaded texture, because
	the name of the method does not start with 'create'. The texture
	is stored somewhere by the driver.
	*/
	class IUnknown
	{
	public:

		//! Constructor.
		IUnknown()
			: ReferenceCounter(1), DebugName(0)
		{
		}

		//! Destructor.
		virtual ~IUnknown()
		{
		}

		//! Grabs the object. Increments the reference counter by one.
		//! Someone who calls grab() to an object, should later also call
		//! drop() to it. If an object never gets as much drop() as grab()
		//! calls, it will never be destroyed.
		//! The IUnknown class provides a basic reference counting mechanism
		//! with its methods grab() and drop(). Most objects of the Irrlicht
		//! Engine are derived from IUnknown, and so they are reference counted.
		//!
		//! When you create an object in the Irrlicht engine, calling a method
		//! which starts with 'create', an object is created, and you get a pointer
		//! to the new object. If you no longer need the object, you have 
		//! to call drop(). This will destroy the object, if grab() was not called
		//! in another part of you program, because this part still needs the object.
		//! Note, that you only need to call drop() to the object, if you created it,
		//! and the method had a 'create' in it. 
		//!
		//! A simple example:
		//!
		//! If you want to create a texture, you may want to call an imaginable method
		//! IDriver::createTexture. You call
		//! ITexture* texture = driver->createTexture(dimension2d<s32>(128, 128));
		//! If you no longer need the texture, call texture->drop().
		//! If you want to load a texture, you may want to call imaginable method
		//! IDriver::loadTexture. You do this like
		//! ITexture* texture = driver->loadTexture("example.jpg");
		//! You will not have to drop the pointer to the loaded texture, because
		//! the name of the method does not start with 'create'. The texture
		//! is stored somewhere by the driver.
		void grab() { ++ReferenceCounter; }

		//! Drops the object. Decrements the reference counter by one.
		//! Returns true, if the object was deleted.
		//! The IUnknown class provides a basic reference counting mechanism
		//! with its methods grab() and drop(). Most objects of the Irrlicht
		//! Engine are derived from IUnknown, and so they are reference counted.
		//!
		//! When you create an object in the Irrlicht engine, calling a method
		//! which starts with 'create', an object is created, and you get a pointer
		//! to the new object. If you no longer need the object, you have 
		//! to call drop(). This will destroy the object, if grab() was not called
		//! in another part of you program, because this part still needs the object.
		//! Note, that you only need to call drop() to the object, if you created it,
		//! and the method had a 'create' in it. 
		//!
		//! A simple example:
		//!
		//! If you want to create a texture, you may want to call an imaginable method
		//! IDriver::createTexture. You call
		//! ITexture* texture = driver->createTexture(dimension2d<s32>(128, 128));
		//! If you no longer need the texture, call texture->drop().
		//! If you want to load a texture, you may want to call imaginable method
		//! IDriver::loadTexture. You do this like
		//! ITexture* texture = driver->loadTexture("example.jpg");
		//! You will not have to drop the pointer to the loaded texture, because
		//! the name of the method does not start with 'create'. The texture
		//! is stored somewhere by the driver.
		bool drop()
		{
			_IRR_DEBUG_BREAK_IF(ReferenceCounter <= 0) // someone is doing bad reference counting.

			--ReferenceCounter;
			if (!ReferenceCounter)
			{
				delete this;
				return true;
			}

			return false;
		}

		//! Returns the debug name of the object. The Debugname may only be set and
		//! changed by the object itself. This method should only be used in Debug mode.
		//! \return Returns a string, previously set by setDebugName();
		const c8* getDebugName() const
		{
			return DebugName;
		} 

	protected:

		//! Sets the debug name of the object. The Debugname may only be set and
		//! changed by the object itself. This method should only be used in Debug mode.
		//! \param newName: New debug name to set.
		void setDebugName(const c8* newName)
		{
			DebugName = newName;
		}

	private:

		s32	ReferenceCounter;
		const c8* DebugName;
	};

} // end namespace irr

#endif

// Copyright (C) 2002-2007 Nikolaus Gebhardt
// This file is part of the "irrKlang" library.
// For conditions of distribution and use, see copyright notice in irrKlang.h

#ifndef __I_VIRTUAL_UNKNOWN_H_INCLUDED__
#define __I_VIRTUAL_UNKNOWN_H_INCLUDED__


namespace irr
{

	//! Reference counting base class for objects in the Irrlicht Engine similar to IUnknown.
	/* See IUnknown for the basics of this class.
	The difference to IUnknown is that the class has to implement reference counting
	for itself. 
	*/
	class IVirtualUnknown
	{
	public:

		//! Destructor.
		virtual ~IVirtualUnknown()
		{
		}

		//! Grabs the object. Increments the reference counter by one.
		/* To be implemented by the derived class. If you don't want to
		implement this, use the class IUnknown instead. See IUnknown::grab() for details
		of this method. */
		virtual void grab() = 0;

		//! Drops the object. Decrements the reference counter by one.
		/* To be implemented by the derived class. If you don't want to
		implement this, use the class IUnknown instead. See IUnknown::grab() for details
		of this method. */
		virtual bool drop() = 0;
	};



} // end namespace 

#endif


// Copyright (C) 2002-2007 Nikolaus Gebhardt
// This file is part of the "irrKlang" library.
// For conditions of distribution and use, see copyright notice in irrKlang.h

#ifndef __E_SOUND_OUTPUT_DRIVERS_H_INCLUDED__
#define __E_SOUND_OUTPUT_DRIVERS_H_INCLUDED__

namespace irr
{
namespace audio
{
	//! An enumeration for all types of supported sound drivers
	enum E_SOUND_OUTPUT_DRIVER
	{
		//! Autodetects the best sound driver for the system
		ESOD_AUTO_DETECT = 0,

		//! DirectSound sound output driver, windows only
		ESOD_DIRECT_SOUND,

		//! WinMM sound output driver, windows only
		ESOD_WIN_MM,

		//! ALSA sound output driver, linux only
		ESOD_ALSA,

		//! Null driver, creating no sound output
		ESOD_NULL,

		//! Amount of built-in sound output drivers
		ESOD_COUNT,

		//! This enumeration literal is never used, it only forces the compiler to
		//! compile these enumeration values to 32 bit.
		ESOD_FORCE_32_BIT = 0x7fffffff
	};

} // end namespace audio
} // end namespace irr


#endif

// Copyright (C) 2002-2007 Nikolaus Gebhardt
// This file is part of the "irrKlang" library.
// For conditions of distribution and use, see copyright notice in irrKlang.h

#ifndef __E_SOUND_ENGINE_OPTIONS_H_INCLUDED__
#define __E_SOUND_ENGINE_OPTIONS_H_INCLUDED__

namespace irr
{
namespace audio  
{
	//! An enumeration for all options for starting up the sound engine
	/* When using createIrrKlangDevice, use a combination of this these
	as 'options' parameter to start up the engine. */
	enum E_SOUND_ENGINE_OPTIONS
	{
		/* If specified (default), it will make irrKlang run in a separate thread, updating
		all streams, sounds, 3d positions and whatever automaticly. You also don't need to call ISoundEngine::update()
		if irrKlang is running multithreaded. However, if you want to run irrKlang in the same thread
		as your application (for easier debugging for example), don't set this. But you need to call ISoundEngine::update()
		as often as you can (at least about 2-3 times per second) to make irrKlang update everything correctly then. */
		ESEO_MULTI_THREADED = 0x01,

		/* If the window of the application doesn't have the focus, irrKlang will be silent 
		if this has been set. This will only work when irrKlang is using the
		DirectSound output driver. */
		ESEO_MUTE_IF_NOT_FOCUSED = 0x02,

		//! Automaticly loads external plugins when starting up.
		/* Plugins usually are .dll 
		files named for example ikpMP3.dll (= short for irrKlangPluginMP3) which are executed
		after the startup of the sound engine and modify it for example to make it possible
		to play back mp3 files. Plugins are being loaded from the current working directory 
		as well as from the position where the .exe using the irrKlang library resides. */
		ESEO_LOAD_PLUGINS = 0x04,

		//! Uses 3D sound buffers instead of emulating them when playing 3d sounds (default).
		/* If this flag is not specified, all buffers will by created
		in 2D only and 3D positioning will be emulated in software, making the engine run
		faster if hardware 3d audio is slow on the system.  */
		ESEO_USE_3D_BUFFERS = 0x08,

		//! In addition to printing debug info to stdout, irrKlang will print debug info
		//! to any windows debugger supporting OutputDebugString() (like VisualStudio).
		//! This is pretty useful if your application does not capture any console output.
		ESEO_PRINT_DEBUG_INFO_TO_DEBUGGER = 0x10,

		//! If specified, instead of the default logarithmic one, irrKlang will 
		//! use a linear rolloff model which influences the attenuation 
		//! of the sounds over distance. The volume is interpolated linearly between the MinDistance
		//! and MaxDistance, making it possible to adjust sounds more easily although this is not
		//! physically correct.
		//! Note that this option may not work when used together with the ESEO_USE_3D_BUFFERS
		//! option when using Direct3D for example, irrKlang will then turn off ESEO_USE_3D_BUFFERS
		//! automaticly to be able to use this option and write out a warning.
		ESEO_LINEAR_ROLLOFF = 0x20,

		//! Default parameters when starting up the engine.
		ESEO_DEFAULT_OPTIONS = ESEO_MULTI_THREADED | ESEO_LOAD_PLUGINS | ESEO_USE_3D_BUFFERS | ESEO_PRINT_DEBUG_INFO_TO_DEBUGGER,

		//! This enumeration literal is never used, it only forces the compiler to 
		//! compile these enumeration values to 32 bit.
		ESEO_FORCE_32_BIT = 0x7fffffff
	};

} // end namespace audio
} // end namespace irr


#endif

// Copyright (C) 2002-2007 Nikolaus Gebhardt
// This file is part of the "irrKlang" library.
// For conditions of distribution and use, see copyright notice in irrKlang.h

#ifndef __E_STREAM_MODES_H_INCLUDED__
#define __E_STREAM_MODES_H_INCLUDED__

namespace irr
{
namespace audio  
{
	//! An enumeration for all types of supported stream modes
	enum E_STREAM_MODE
	{
		//! Autodetects the best stream mode for a specified audio data
		ESM_AUTO_DETECT = 0,

		//! Streams the audio data when needed
		ESM_STREAMING,

		//! Loads the whole audio data into the memory
		ESM_NO_STREAMING,

		//! This enumeration literal is never used, it only forces the compiler to 
		//! compile these enumeration values to 32 bit.
		ESM_FORCE_32_BIT = 0x7fffffff
	};

} // end namespace audio
} // end namespace irr


#endif

// Copyright (C) 2002-2007 Nikolaus Gebhardt
// This file is part of the "irrKlang" library.
// For conditions of distribution and use, see copyright notice in irrKlang.h

#ifndef __S_AUDIO_STREAM_FORMAT_H_INCLUDED__
#define __S_AUDIO_STREAM_FORMAT_H_INCLUDED__


namespace irr
{
namespace audio
{

	//! audio sample data format enumeration for supported formats
	enum ESampleFormat
	{
		//! one unsigned byte (0;255)
		ESF_U8, 

		//! 16 bit, signed (-32k;32k)
		ESF_S16 
	};

	//! structure describing an audio stream format with helper functions
	struct SAudioStreamFormat
	{
		//! channels, 1 for mono, 2 for stereo
		s32 ChannelCount; 

		//! amount of frames in the sample data or stream. 
		/* If the stream has an unknown lenght, let this be -1 */
		s32 FrameCount;		

		//! samples per second
		s32 SampleRate;
		
		//! format of the sample data
		ESampleFormat SampleFormat;

		//! returns the size of a sample of the data described by the stream data in bytes
		inline s32 getSampleSize() const
		{
			return (SampleFormat == ESF_U8) ? 1 : 2;
		}

		//! returns the frame size of the stream data in bytes
		inline s32 getFrameSize() const
		{
			return ChannelCount * getSampleSize();
		}

		//! returns the size of the sample data in bytes
		inline s32 getSampleDataSize() const
		{
			return getFrameSize() * FrameCount;
		}

		//! returns amount of bytes per second
		inline s32 getBytesPerSecond() const
		{
			return getFrameSize() * SampleRate;
		}
	};


} // end namespace audio
} // end namespace irr

#endif

// Copyright (C) 2002-2007 Nikolaus Gebhardt
// This file is part of the "irrKlang" library.
// For conditions of distribution and use, see copyright notice in irrKlang.h

#ifndef __I_SOUND_ENGINE_H_INCLUDED__
#define __I_SOUND_ENGINE_H_INCLUDED__

// Copyright (C) 2002-2007 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __IRR_POINT_3D_H_INCLUDED__
#define __IRR_POINT_3D_H_INCLUDED__

#include <math.h>
// Copyright (C) 2002-2007 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __IRR_MATH_H_INCLUDED__
#define __IRR_MATH_H_INCLUDED__


namespace irr
{
namespace core
{
	//! Rounding error constant often used when comparing f32 values.
	const f32 ROUNDING_ERROR	= 0.0001f;

	//! Constant for PI.
	const f32 PI			= 3.14159f;

	//! Constant for 64bit PI.
	const f64 PI64			= 3.1415926535897932384626433832795028841971693993751;

	//! Constant for converting radians to degrees.
	const f64 GRAD_PI		= 180.0 / PI64;

	//! Constant for converting degrees to radians.
	const f64 GRAD_PI2		= PI64 / 180.0;

       //! 32bit Constant for converting from degrees to radians
       const f32 DEGTORAD              = PI / 180.0f;

	//! 32bit constant for converting from radians to degrees
	const f32 RADTODEG              = 180.0f / PI;

	//! 64bit constant for converting from degrees to radians
	const f64 DEGTORAD64    = PI64 / 180.0;

	//! 64bit constant for converting from radians to degrees
	const f64 RADTODEG64    = 180.0 / PI64;

	//! returns minimum of two values. Own implementation to get rid of the STL (VS6 problems)
	template<class T>
	inline const T min_(const T a, const T b)
	{
		return a < b ? a : b;
	}

	//! returns minimum of three values. Own implementation to get rid of the STL (VS6 problems)
	template<class T>
	inline const T min_(const T a, const T b, const T c)
	{
		return a < b ? min_(a, c) : min_(b, c);
	}
	
	//! returns minimum of two values. Own implementation to get rid of the STL (VS6 problems)
	template<class T>
	inline T max_(const T a, const T b)
	{
		return a < b ? b : a;
	}

	//! returns minimum of three values. Own implementation to get rid of the STL (VS6 problems)
	template<class T>
	inline const T max_(const T a, const T b, const T c)
	{
		return a < b ? max_(b, c) : max_(a, c);
	}

	//! Clamps the value between to other values
	template<class T>
	inline const T clamp_(const T v, const T a, const T b)
	{
		return v < a ? a : (v > b ? b : v);
	}

	//! returns abs of two values. Own implementation to get rid of STL (VS6 problems)
	template<class T>
	inline T abs_(const T a)
	{
		return a < 0 ? -a : a;
	}

	//! returns if a float equals the other one, taking floating 
	//! point rounding errors into account
	inline bool equals(f32 a, f32 b, const f32 error = ROUNDING_ERROR)
	{
		return (a + error > b) && (a - error < b);
	}

} // end namespace core
}// end namespace irr

#endif


namespace irr
{
namespace core
{
	
	//! 3d vector template class with lots of operators and methods.
	template <class T>
	class vector3d  
	{
	public:

		vector3d(): X(0), Y(0), Z(0) {};
		vector3d(T nx, T ny, T nz) : X(nx), Y(ny), Z(nz) {};
		vector3d(const vector3d<T>& other)	:X(other.X), Y(other.Y), Z(other.Z) {};

		// operators

		vector3d<T> operator-() const { return vector3d<T>(-X, -Y, -Z);   }

		vector3d<T>& operator=(const vector3d<T>& other)	{ X = other.X; Y = other.Y; Z = other.Z; return *this; }

		vector3d<T> operator+(const vector3d<T>& other) const { return vector3d<T>(X + other.X, Y + other.Y, Z + other.Z);	}
		vector3d<T>& operator+=(const vector3d<T>& other)	{ X+=other.X; Y+=other.Y; Z+=other.Z; return *this; }

		vector3d<T> operator-(const vector3d<T>& other) const { return vector3d<T>(X - other.X, Y - other.Y, Z - other.Z);	}
		vector3d<T>& operator-=(const vector3d<T>& other)	{ X-=other.X; Y-=other.Y; Z-=other.Z; return *this; }

		vector3d<T> operator*(const vector3d<T>& other) const { return vector3d<T>(X * other.X, Y * other.Y, Z * other.Z);	}
		vector3d<T>& operator*=(const vector3d<T>& other)	{ X*=other.X; Y*=other.Y; Z*=other.Z; return *this; }
		vector3d<T> operator*(const T v) const { return vector3d<T>(X * v, Y * v, Z * v);	}
		vector3d<T>& operator*=(const T v) { X*=v; Y*=v; Z*=v; return *this; }

		vector3d<T> operator/(const vector3d<T>& other) const { return vector3d<T>(X / other.X, Y / other.Y, Z / other.Z);	}
		vector3d<T>& operator/=(const vector3d<T>& other)	{ X/=other.X; Y/=other.Y; Z/=other.Z; return *this; }
		vector3d<T> operator/(const T v) const { T i=(T)1.0/v; return vector3d<T>(X * i, Y * i, Z * i);	}
		vector3d<T>& operator/=(const T v) { T i=(T)1.0/v; X*=i; Y*=i; Z*=i; return *this; }

		bool operator<=(const vector3d<T>&other) const { return X<=other.X && Y<=other.Y && Z<=other.Z;};
		bool operator>=(const vector3d<T>&other) const { return X>=other.X && Y>=other.Y && Z>=other.Z;};

		bool operator==(const vector3d<T>& other) const { return other.X==X && other.Y==Y && other.Z==Z; }
		bool operator!=(const vector3d<T>& other) const { return other.X!=X || other.Y!=Y || other.Z!=Z; }

		// functions

		//! returns if this vector equals the other one, taking floating point rounding errors into account
		bool equals(const vector3d<T>& other)
		{
			return core::equals(X, other.X) &&
				   core::equals(Y, other.Y) &&
				   core::equals(Z, other.Z);
		}

		void set(const T nx, const T ny, const T nz) {X=nx; Y=ny; Z=nz; }
		void set(const vector3d<T>& p) { X=p.X; Y=p.Y; Z=p.Z;}

		//! Returns length of the vector.
		f64 getLength() const { return sqrt(X*X + Y*Y + Z*Z); }

		//! Returns squared length of the vector.
		/* This is useful because it is much faster then
		getLength(). */
		f64 getLengthSQ() const { return X*X + Y*Y + Z*Z; }

		//! Returns the dot product with another vector.
		T dotProduct(const vector3d<T>& other) const
		{
			return X*other.X + Y*other.Y + Z*other.Z;
		}

		//! Returns distance from an other point.
		/* Here, the vector is interpreted as point in 3 dimensional space. */
		f64 getDistanceFrom(const vector3d<T>& other) const
		{
			f64 vx = X - other.X; f64 vy = Y - other.Y; f64 vz = Z - other.Z;
			return sqrt(vx*vx + vy*vy + vz*vz);
		}

		//! Returns squared distance from an other point. 
		/* Here, the vector is interpreted as point in 3 dimensional space. */
		f32 getDistanceFromSQ(const vector3d<T>& other) const
		{
			f32 vx = X - other.X; f32 vy = Y - other.Y; f32 vz = Z - other.Z;
			return (vx*vx + vy*vy + vz*vz);
		}

		//! Calculates the cross product with another vector
		vector3d<T> crossProduct(const vector3d<T>& p) const
		{
			return vector3d<T>(Y * p.Z - Z * p.Y, Z * p.X - X * p.Z, X * p.Y - Y * p.X);
		}

		//! Returns if this vector interpreted as a point is on a line between two other points.
		/* It is assumed that the point is on the line. */
		bool isBetweenPoints(const vector3d<T>& begin, const vector3d<T>& end) const
		{
			f32 f = (f32)(end - begin).getLengthSQ();
			return (f32)getDistanceFromSQ(begin) < f && 
				(f32)getDistanceFromSQ(end) < f;
		}

		//! Normalizes the vector.
		vector3d<T>& normalize()
		{
			T l = (T)getLength();
			if (l == 0)
				return *this;

			l = (T)1.0 / l;
			X *= l;
			Y *= l;
			Z *= l;
			return *this;
		}

		//! Sets the lenght of the vector to a new value
		void setLength(T newlength)
		{
			normalize();
			*this *= newlength;
		}

		//! Inverts the vector.
		void invert()
		{
			X *= -1.0f;
			Y *= -1.0f;
			Z *= -1.0f;
		}

		//! Rotates the vector by a specified number of degrees around the Y 
		//! axis and the specified center.
		//! \param degrees: Number of degrees to rotate around the Y axis.
		//! \param center: The center of the rotation.
		void rotateXZBy(f64 degrees, const vector3d<T>& center)
		{
			degrees *=GRAD_PI2;
			T cs = (T)cos(degrees);
			T sn = (T)sin(degrees);
			X -= center.X;
			Z -= center.Z;
			set(X*cs - Z*sn, Y, X*sn + Z*cs);
			X += center.X;
			Z += center.Z;
		}

		//! Rotates the vector by a specified number of degrees around the Z 
		//! axis and the specified center.
		//! \param degrees: Number of degrees to rotate around the Z axis.
		//! \param center: The center of the rotation.
		void rotateXYBy(f64 degrees, const vector3d<T>& center)
		{
			degrees *=GRAD_PI2;
			T cs = (T)cos(degrees);
			T sn = (T)sin(degrees);
			X -= center.X;
			Y -= center.Y;
			set(X*cs - Y*sn, X*sn + Y*cs, Z);
			X += center.X;
			Y += center.Y;
		}

		//! Rotates the vector by a specified number of degrees around the X
		//! axis and the specified center.
		//! \param degrees: Number of degrees to rotate around the X axis.
		//! \param center: The center of the rotation.
		void rotateYZBy(f64 degrees, const vector3d<T>& center)
		{
			degrees *=GRAD_PI2;
			T cs = (T)cos(degrees);
			T sn = (T)sin(degrees);
			Z -= center.Z;
			Y -= center.Y;
			set(X, Y*cs - Z*sn, Y*sn + Z*cs);
			Z += center.Z;
			Y += center.Y;
		}

		//! Returns interpolated vector.
		/* \param other: other vector to interpolate between
		\param d: value between 0.0f and 1.0f. */
		vector3d<T> getInterpolated(const vector3d<T>& other, f32 d) const
		{
			f32 inv = 1.0f - d;
			return vector3d<T>(other.X*inv + X*d,
								other.Y*inv + Y*d,
								other.Z*inv + Z*d);
		}

		//! Gets the Y and Z rotations of a vector.
		/* Thanks to Arras on the Irrlicht forums to add this method.
		 \return A vector representing the rotation in degrees of
		this vector. The Z component of the vector will always be 0. */
		vector3d<T> getHorizontalAngle()
		{
			vector3d<T> angle;

			angle.Y = (T)atan2(X, Z); 
			angle.Y *= (f32)GRAD_PI;
			    
			if (angle.Y < 0.0f) angle.Y += 360.0f; 
			if (angle.Y >= 360.0f) angle.Y -= 360.0f; 
			    
			f32 z1 = (T)sqrt(X*X + Z*Z); 
			    
			angle.X = (T)atan2(z1, Y); 
			angle.X *= (f32)GRAD_PI;
			angle.X -= 90.0f; 
			    
			if (angle.X < 0.0f) angle.X += 360.0f; 
			if (angle.X >= 360) angle.X -= 360.0f; 

			return angle;
		}

		//! Fills an array of 4 values with the vector data (usually floats).
		/* Useful for setting in shader constants for example. The fourth value
		 will always be 0. */
		void getAs4Values(T* array)
		{
			array[0] = X;
			array[1] = Y;
			array[2] = Z;
			array[3] = 0;
		}


		// member variables

		T X, Y, Z;
	};


	//! Typedef for a f32 3d vector.
	typedef vector3d<f32> vector3df;
	//! Typedef for an integer 3d vector.
	typedef vector3d<s32> vector3di;

	template<class S, class T> vector3d<T> operator*(const S scalar, const vector3d<T>& vector) { return vector*scalar; }
} // end namespace core
} // end namespac irr

#endif

// Copyright (C) 2002-2007 Nikolaus Gebhardt
// This file is part of the "irrKlang" library.
// For conditions of distribution and use, see copyright notice in irrKlang.h

#ifndef __I_IRR_SOUND_SOURCE_H_INCLUDED__
#define __I_IRR_SOUND_SOURCE_H_INCLUDED__


namespace irr
{

namespace audio
{
	//! A sound source describes an input file (.ogg, .mp3 or .wav) and its default settings for volume, 3d or 2d etc.
	/* The sound source can have default settings (is it a 3d sound source, is is a stream, does it loop, etc). */
	class ISoundSource : public virtual irr::IUnknown
	{
	public:

		//! returns the name of the sound source (usually, this is the file name)
		virtual const c8* getName() = 0;

		//! returns the detected or set type of the sound with wich the sound will be played.
		/* Note: If the returned type is ESM_AUTO_DETECT, this mode will change after the
		sound has been played the first time. */
		virtual E_STREAM_MODE getStreamMode() = 0;

		//! returns the play length of the sound in milliseconds.
		/* Returns -1 if not known for this sound for example because its decoder
		does not support lenght reporting or it is a file stream of unknown size.
		Note: If the sound never has been played before, the sound engine will have to open
		the file and try to get the play lenght from there, so this call could take a bit depending
		on the type of file. */
		virtual u32 getPlayLength() = 0;

		//! Forces the sound to be reloaded at next replay.
		/* Sounds which are not played as streams are buffered to make it possible to
		replay them without much overhead. If the sound file is altered after the sound
		has been played the first time, the engine won't play the changed file then.
		Calling this method makes the engine reload the file before the file is played
		the next time.*/
		virtual void forceReloadAtNextUse() = 0;

		//! Sets the threshold size where irrKlang decides to force streaming a file independent of the user specified setting.
		/* When specifying ESM_NO_STREAMING for playing back a sound file, irrKlang will
		ignore this setting if the file is bigger than this threshold and stream the file
		anyway. Please note that if an audio format loader is not able to return the 
		size of a sound source and returns -1 as length, this will be ignored as well 
		and streaming has to be forced.
		\param threshold: New threshold. The value is specified in uncompressed bytes and its default value is 
		about one Megabyte. Set to 0 or a negative value to disable stream forcing. */
		virtual void setForcedStreamingThreshold(s32 thresholdBytes) = 0;

		//! Returns the threshold size where irrKlang decides to force streaming a file independent of the user specified setting.
		/* See setForcedStreamingThreshold() for details. */
		virtual s32 getForcedStreamingForceThreshold() = 0;
	};

} // end namespace sound
} // end namespace irr


#endif
// Copyright (C) 2002-2007 Nikolaus Gebhardt
// This file is part of the "irrKlang" library.
// For conditions of distribution and use, see copyright notice in irrKlang.h

#ifndef __I_SOUND_H_INCLUDED__
#define __I_SOUND_H_INCLUDED__


namespace irr
{

namespace audio
{
	class ISoundSource;

	//! Represents a sound which is currently played.
	/* You can stop the sound or change the volume or whatever using this interface.
	Creating sounds is done using ISoundEngine::play2D() or ISoundEngine::play3D(). 
	More informations about the source of a sound can be obtained from the ISoundSource
	interface. */
	class ISound : public virtual irr::IVirtualUnknown
	{
	public:

		//! returns source of the sound (with which you can get the filename or similar)
		virtual ISoundSource* getSoundSource() = 0;

		//! returns if the sound is paused
		virtual void setIsPaused( bool paused = true) = 0;

		//! returns if the sound is paused
		virtual bool getIsPaused() = 0;

		//! Will stop the sound and free its resources.
		/* If you just want to pause the sound, use setIsPaused().
		After calling stop(), isFinished() will usually return true. */
		virtual void stop() = 0;

		//! returns volume of the sound, a value between 0 (mute) and 1 (full volume).
		/* (this volume gets multiplied with the master volume of the sound engine
		and other parameters like distance to listener when played as 3d sound)  */
		virtual f32 getVolume() = 0;

		//! sets the volume of the sound, a value between 0 (mute) and 1 (full volume).
		/* This volume gets multiplied with the master volume of the sound engine
		and other parameters like distance to listener when played as 3d sound.  */
		virtual void setVolume(f32 volume) = 0;

		//! sets the pan of the sound. Takes a value between -1 and 1, 0 is center.
		virtual void setPan(f32 pan) = 0;

		//! returns the pan of the sound. Takes a value between -1 and 1, 0 is center.
		virtual f32 getPan() = 0;

		//! returns if the sound has been started to play looped
		virtual bool isLooped() = 0;

		//! returns if the sound has finished playing.
		/* Don't mix this up with isPaused(). isFinished() returns if the sound has been
		finished playing. If it has, is maybe already have been removed from the playing list of the
		sound engine and calls to any other of the methods of ISound will not have any result.
		If you call stop() to a playing sound will result that this function will return true
		when invoked. */
		virtual bool isFinished() = 0;

		//! Sets the minimal distance if this is a 3D sound.
		/* Specify the distances at which 3D sounds stop getting louder or quieter. This works
		like this: As a listener approaches a 3D sound source, the sound gets louder.
		Past a certain point, it is not reasonable for the volume to continue to increase.
		Either the maximum (zero) has been reached, or the nature of the sound source
		imposes a logical limit. This is the minimum distance for the sound source.
		Similarly, the maximum distance for a sound source is the distance beyond
		which the sound does not get any quieter.
		The default minimum distance is 1, the default max distance is a huge number nearly to infinite. */
		virtual void setMinDistance(f32 min) = 0;

		//! Returns the minimal distance if this is a 3D sound.
		/* See setMaxDistance() for details. */
		virtual f32 getMinDistance() = 0;

		//! Sets the maximal distance if this is a 3D sound.
		/* Specify the distances at which 3D sounds stop getting louder or quieter. This works
		like this: As a listener approaches a 3D sound source, the sound gets louder.
		Past a certain point, it is not reasonable for the volume to continue to increase.
		Either the maximum (zero) has been reached, or the nature of the sound source
		imposes a logical limit. This is the minimum distance for the sound source.
		Similarly, the maximum distance for a sound source is the distance beyond
		which the sound does not get any quieter.
		The default minimum distance is 1, the default max distance is a huge number nearly to infinite. */
		virtual void setMaxDistance(f32 max) = 0;

		//! Returns the maximal distance if this is a 3D sound.
		/* See setMaxDistance() for details. */
		virtual f32 getMaxDistance() = 0;

		//! sets the position of the sound in 3d space
		virtual void setPosition(core::vector3df position) = 0;

		//! returns the position of the sound in 3d space
		virtual core::vector3df getPosition() = 0;

		//! returns the current play position of the sound in milliseconds.
		/* Returns -1 if not implemented or possible for this sound for example
		because it already has been stopped and freed internally or similar. */
		virtual u32 getPlayPosition() = 0;

		//! returns the play length of the sound in milliseconds.
		/* Returns -1 if not known for this sound for example because its decoder
		does not support length reporting or it is a file stream of unknown size.
		Note: You can also use ISoundSource::getPlayLength() to get the length of 
		a sound without actually needing to play it. */
		virtual u32 getPlayLength() = 0;
	};

} // end namespace audio
} // end namespace irr


#endif
// Copyright (C) 2002-2007 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __I_FILE_FACTORY_H_INCLUDED__
#define __I_FILE_FACTORY_H_INCLUDED__


namespace irr
{
namespace io
{
	class IReadFile;

	//! Interface to overwrite opening files
	/* Derive your own class from IFileFactory, overwrite the createAndOpenFile()
		method and return your own implemented IReadFile to overwrite file access of irrKlang.
	 */
	class IFileFactory : public virtual IUnknown
	{
	public:

		virtual ~IFileFactory() {};

		//! Opens a file for read access.
		/* Derive your own class from IFileFactory, overwrite this
		method and return your own implemented IReadFile to overwrite file access of irrKlang.
		\param filename Name of file to open.
		\return Returns a pointer to the created file interface.
		The returned pointer should be dropped when no longer needed.
		See IUnknown::drop() for more information. Returns 0 if file cannot be opened. */
		virtual IReadFile* createAndOpenFile(const c8* filename) = 0;		
	};

} // end namespace irr
} // end namespace io

#endif


namespace irr
{
namespace audio
{
	class IAudioStreamLoader;

	//! Interface to the sound engine, for playing 3d and 2d sound and music
	class ISoundEngine : public virtual irr::IUnknown
	{
	public:

		//! loads a sound source (if not loaded already) from a file and plays it.
		/* \param sourceFileName Filename of sound, like "sounds/test.wav" or "foobar.ogg".
		 \param playLooped plays the sound in loop mode. If set to 'false', the sound is played once, then stopped and deleted from the internal playing list. Calls to
		 ISound have no effect after such a non looped sound has been stopped automaticly.
		 \param startPaused starts the sound paused. This implies that track=true. Use this if you want to modify some of the playing
		 parameters before the sound actually plays. Usually you would set this parameter to true, then use the ISound interface to
		 modify some of the sound parameters and then call ISound::setPaused(false);
		 Note: You need to call ISound::drop() when setting this parameter to true and you don't need the ISound
		 object anymore. See 'return' for details.
		 \param track Makes it possible to track the sound. Causes the method to return an ISound interface. See 'return' for details.
		 \param streamMode Specifies if the file should be streamed or loaded completely into memory for playing.
		 ESM_AUTO_DETECT sets this to autodetection. Note: if the sound has been loaded or played before into the
		 engine, this parameter has no effect.
		 \return Only returns a pointer to an ISound if the parameters 'track' or 'startPaused' have been
		 set to true. Note: if this method returns an ISound as result, you HAVE to call ISound::drop()
		 after you don't need the ISound interface anymore. Otherwise this will cause memory waste or even
		 hardware buffer wastes. This method also may return 0 altough 'track' or 'startPaused' have been
		 set to true, if the sound could not be played.*/
		virtual ISound* play2D(const char* soundFileName, bool playLooped=false,
							   bool startPaused=false, bool track=false, E_STREAM_MODE streamMode=ESM_AUTO_DETECT) = 0;

		//! Plays a sound source as 2D sound with its default settings stored in ISoundSource.
		/* An ISoundSource object will be created internally when playing a sound the first time,
		or can be added with getSoundSource().
		\param source The sound source, specifiying sound file source and default settings for this file.
		Use the other ISoundEngine::play2D() overloads if you want to specify a filename string instead of this.
		\param playLooped plays the sound in loop mode. If set to 'false', the sound is played once, then stopped and deleted from the internal playing list. Calls to
		 ISound have no effect after such a non looped sound has been stopped automaticly.
		\param startPaused starts the sound paused. This implies that track=true. Use this if you want to modify some of the playing
		 parameters before the sound actually plays. Usually you would set this parameter to true, then use the ISound interface to
		 modify some of the sound parameters and then call ISound::setPaused(false);
		 Note: You need to call ISound::drop() when setting this parameter to true and you don't need the ISound
		 object anymore. See 'return' for details.
		 \param track Makes it possible to track the sound. Causes the method to return an ISound interface. See 'return' for details.
		 \return Only returns a pointer to an ISound if the parameters 'track' or 'startPaused' have been
		 set to true. Note: if this method returns an ISound as result, you HAVE to call ISound::drop()
		 after you don't need the ISound interface anymore. Otherwise this will cause memory waste or even
		 hardware buffer wastes. This method also may return 0 altough 'track' or 'startPaused' have been
		 set to true, if the sound could not be played.*/
		virtual ISound* play2D(ISoundSource* source, bool playLooped=false,
								bool startPaused=false, bool track=false) = 0;

		//! loads a sound source (if not loaded already) from a file and plays it as 3D sound.
		/* \param sourceFileName Filename of sound, like "sounds/test.wav" or "foobar.ogg".
		 \param pos Position of the 3D sound.
		 \param playLooped plays the sound in loop mode. If set to 'false', the sound is played once, then stopped and deleted from the internal playing list. Calls to
		 ISound have no effect after such a non looped sound has been stopped automaticly.
		 \param startPaused starts the sound paused. This implies that track=true. Use this if you want to modify some of the playing
		 parameters before the sound actually plays. Usually you would set this parameter to true, then use the ISound interface to
		 modify some of the sound parameters and then call ISound::setPaused(false);
		 Note: You need to call ISound::drop() when setting this parameter to true and you don't need the ISound
		 object anymore. See 'return' for details.
		 \param track Makes it possible to track the sound. Causes the method to return an ISound interface. See 'return' for details.
 		 \param streamMode Specifies if the file should be streamed or loaded completely into memory for playing.
		 ESM_AUTO_DETECT sets this to autodetection. Note: if the sound has been loaded or played before into the
		 engine, this parameter has no effect.
		 \return Only returns a pointer to an ISound if the parameters 'track' or 'startPaused' have been
		 set to true. Note: if this method returns an ISound as result, you HAVE to call ISound::drop()
		 after you don't need the ISound interface anymore. Otherwise this will cause memory waste or even
		 hardware buffer wastes. This method also may return 0 altough 'track' or 'startPaused' have been
		 set to true, if the sound could not be played.*/
		virtual ISound* play3D(const char* soundFileName, core::vector3df pos,
							   bool playLooped=false, bool startPaused=false,
							   bool track=false, E_STREAM_MODE streamMode=ESM_AUTO_DETECT) = 0;

		//! Plays a sound source as 2D sound with its default settings stored in ISoundSource.
		/* An ISoundSource object will be created internally when playing a sound the first time,
		or can be added with getSoundSource().
		\param source The sound source, specifiying sound file source and default settings for this file.
		Use the other ISoundEngine::play2D() overloads if you want to specify a filename string instead of this.
		\param pos Position of the 3D sound.
		\param playLooped plays the sound in loop mode. If set to 'false', the sound is played once, then stopped and deleted from the internal playing list. Calls to
		 ISound have no effect after such a non looped sound has been stopped automaticly.
		\param startPaused starts the sound paused. This implies that track=true. Use this if you want to modify some of the playing
		 parameters before the sound actually plays. Usually you would set this parameter to true, then use the ISound interface to
		 modify some of the sound parameters and then call ISound::setPaused(false);
		 Note: You need to call ISound::drop() when setting this parameter to true and you don't need the ISound
		 object anymore. See 'return' for details.
		 \param track Makes it possible to track the sound. Causes the method to return an ISound interface. See 'return' for details.
		 \return Only returns a pointer to an ISound if the parameters 'track' or 'startPaused' have been
		 set to true. Note: if this method returns an ISound as result, you HAVE to call ISound::drop()
		 after you don't need the ISound interface anymore. Otherwise this will cause memory waste or even
		 hardware buffer wastes. This method also may return 0 altough 'track' or 'startPaused' have been
		 set to true, if the sound could not be played.*/
		virtual ISound* play3D(ISoundSource* source, core::vector3df pos,
							   bool playLooped=false, bool startPaused=false, bool track=false) = 0;

		//! stops all currently playing sounds
		virtual void stopAllSounds() = 0;

        //! pauses or unpauses all currently playing sounds
		virtual void setAllSoundsPaused( bool bPaused = true ) = 0;

		//! Gets a sound source by sound name. Adds the sound source as file into the sound engine if not loaded already.
		/* Please note: For performance reasons most ISoundEngine implementations will
		not try to load the sound when calling this method, but only when play() is called
		with this sound source as parameter. */
		virtual ISoundSource* getSoundSource(const c8* soundName) = 0;

		//! returns a sound source by index.
		/* \param idx: Index of the loaded sound source, must by smaller than getSoundSourceCount() */
		virtual ISoundSource* getSoundSource(s32 index) = 0;

		//! returns amount of loaded sound sources
		virtual s32 getSoundSourceCount() = 0;

		//! Adds sound source into the sound engine as file.
		/* Please note: For performance reasons most ISoundEngine implementations will
		not try to load the sound file when calling this method, but only when play() is called
		with this sound source as parameter.
		\param fileName Name of the sound file (e.g. "sounds/something.mp3"). You can also use this
		name when calling play3D() or play2D().
		\param mode Streaming mode for this sound source
		\return Returns the pointer to the added sound source or 0 if not sucessful because for
		example a sound already existed with that name. If not successful, the reason will be printed
		into the log. */
		virtual ISoundSource* addSoundSource(const c8* fileName, E_STREAM_MODE mode=ESM_AUTO_DETECT) = 0;

		//! Adds sound source into the sound engine as memory source.
		/* \param memory Pointer to the memory to be treated as loaded sound file.
		Note: The memory block pointed to should remain there as long as the sound engine exists.
		This will change with the the next release of the engine.
		\param sizeInBytes Size of the memory chunk, in bytes.
		\param soundName Name of the virtual sound file (e.g. "sounds/something.mp3"). You can also use this
		name when calling play3D() or play2D().
		\return Returns the pointer to the added sound source or 0 if not sucessful because for
		example a sound already existed with that name. If not successful, the reason will be printed
		into the log. */
		virtual ISoundSource* addSoundSource(void* memory, s32 sizeInBytes, const c8* soundName) = 0;

		//! Removes a sound source from the engine, freeing the memory it occupies.
		/* This will also cause all currently playing sounds of this source to be stopped. 
		Also note that if the source has been removed successfully, the value returned 
		by getSoundSourceCount() will have been decreased by one. 
		Removing sound sources is only necessary if you know you won't use a lot of non-streamed
		sounds again. Sound sources of streamed sounds do not cost a lot of memory.*/
		virtual void removeSoundSource(ISoundSource* source) = 0;

		//! Removes a sound source from the engine, freeing the memory it occupies.
		/* This will also cause all currently playing sounds of this source to be stopped. 
		Also note that if the source has been removed successfully, the value returned 
		by getSoundSourceCount() will have been decreased by one. 
		Removing sound sources is only necessary if you know you won't use a lot of non-streamed
		sounds again. Sound sources of streamed sounds do not cost a lot of memory. */
		virtual void removeSoundSource(const c8* name) = 0;

		//! Removes all sound sources from the engine
		/* This will also cause all sounds to be stopped. 
		Removing sound sources is only necessary if you know you won't use a lot of non-streamed
		sounds again. Sound sources of streamed sounds do not cost a lot of memory. */
		virtual void removeAllSoundSources() = 0;

		//! sets sound volume. This value is multiplied with all sounds played
		//! \param volume 0 (silent) to 1.0f (full volume)
		virtual void setSoundVolume(f32 volume) = 0;

		//! returns sound volume
		virtual f32 getSoundVolume() = 0;

		//! Sets the current listener 3d position.
		/* This method is being called by the scene manager automaticly if you are using one, so
		 you might want to ignore this. */
		virtual void setListenerPosition(const core::vector3df& pos,
			const core::vector3df& lookdir,
			const core::vector3df& velPerSecond = core::vector3df(0,0,0),
			const core::vector3df& upVector = core::vector3df(0,1,0)) = 0;

		//! Updates the audio engine. This should be called several times per frame if irrKlang was started in single thread mode.
		/* This updates the 3d positions of the sounds as well as their volumes, effects,
		streams and other stuff. Call this several times per frame (the more the better) if you
		specified irrKlang to run single threaded. Otherwise it is not necessary to use this method.
		This method is being called by the scene manager automaticly if you are using one, so
		you might want to ignore this. */
		virtual void update() = 0;

		//! Returns if a sound with the specified name is currently playing
		virtual bool isCurrentlyPlaying(const char* soundName) = 0;

		//! Returns if a sound with the specified source is currently playing
		virtual bool isCurrentlyPlaying(ISoundSource* source) = 0;

		//! Registers a new audio stream loader in the sound engine
		/* Use this to enhance the audio engine to support other or new file formats.
		To do this, implement your own IAudioStreamLoader interface and register it
		with this method*/
		virtual void registerAudioStreamLoader(IAudioStreamLoader* loader) = 0;

		//! Returns if irrKlang is running in the same thread as the application or is using multithreading.
		/* This basicly returns the flag set by the user when creating the sound engine.*/
		virtual bool isMultiThreaded() const = 0;

		//! Adds a file factory to the sound engine, making it possible to override file access of the sound engine.
		/* Derive your own class from IFileFactory, overwrite the createAndOpenFile()
		method and return your own implemented IReadFile to overwrite file access of irrKlang. */
		virtual void addFileFactory(io::IFileFactory* fileFactory) = 0;
	};


} // end namespace sound
} // end namespace irr


#endif
// Copyright (C) 2002-2007 Nikolaus Gebhardt
// This file is part of the "irrKlang" library.
// For conditions of distribution and use, see copyright notice in irrKlang.h

#ifndef __I_AUDIO_STREAM_H_INCLUDED__
#define __I_AUDIO_STREAM_H_INCLUDED__


namespace irr
{
namespace audio
{


//!	Reads and decodes audio data into an usable audio stream for the ISoundEngine
class IAudioStream : public IUnknown
{
public:

	//! destructor
	virtual ~IAudioStream() {};

	//! returns format of the audio stream
	virtual SAudioStreamFormat getFormat() = 0;

	//! sets the position of the audio stream.
	/* For example to let the stream be read from the beginning of the file again, 
	setPosition(0) would be called. This is usually done be the sound engine to
	loop a stream after if has reached the end. Return true if sucessful and 0 if not. */
	virtual bool setPosition(s32 pos) = 0;

    //! tells the audio stream to read frameCountToRead audio frames into the specified buffer
	/* \param target: Target data buffer to the method will write the read frames into. The
	specified buffer will be at least getFormat().getFrameSize()frameCountToRead bytes big.
	\param frameCountToRead: amount of frames to be read.
	\returns Returns amount of frames really read. Should be frameCountToRead in most cases. */
	virtual s32 readFrames(void* target, s32 frameCountToRead) = 0;
};


} // end namespace audio
} // end namespace irr

#endif

// Copyright (C) 2002-2007 Nikolaus Gebhardt
// This file is part of the "irrKlang" library.
// For conditions of distribution and use, see copyright notice in irrKlang.h

#ifndef __I_AUDIO_STREAM_LOADER_H_INCLUDED__
#define __I_AUDIO_STREAM_LOADER_H_INCLUDED__

// Copyright (C) 2002-2007 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __I_READ_FILE_H_INCLUDED__
#define __I_READ_FILE_H_INCLUDED__


namespace irr
{
namespace io
{

	//! Interface providing read acess to a file.
	class IReadFile : public virtual IUnknown
	{
	public:

		virtual ~IReadFile() {};

		//! Reads an amount of bytes from the file.
		//! \param buffer: Pointer to buffer where to read bytes will be written to.
		//! \param sizeToRead: Amount of bytes to read from the file.
		//! \return Returns how much bytes were read.
		virtual s32 read(void* buffer, u32 sizeToRead) = 0;

		//! Changes position in file, returns true if successful.
		//! \param finalPos: Destination position in the file.
		//! \param relativeMovement: If set to true, the position in the file is
		//! changed relative to current position. Otherwise the position is changed 
		//! from beginning of file.
		//! \return Returns true if successful, otherwise false.
		virtual bool seek(s32 finalPos, bool relativeMovement = false) = 0;

		//! Returns size of file.
		//! \return Returns the size of the file in bytes.
		virtual s32 getSize() = 0;

		//! Returns the current position in the file.
		//! \return Returns the current position in the file in bytes.
		virtual s32 getPos() = 0;

		//! Returns name of file.
		//! \return Returns the file name as zero terminated character string.
		virtual const c8* getFileName() = 0;
	};

	//! Internal function, please do not use.
	IReadFile* createReadFile(const c8* fileName);
	//! Internal function, please do not use.
	IReadFile* createLimitReadFile(const c8* fileName, IReadFile* alreadyOpenedFile, s32 areaSize);
	//! Internal function, please do not use.
	IReadFile* createMemoryReadFile(void* memory, s32 size, const c8* fileName, bool deleteMemoryWhenDropped);

} // end namespace io
} // end namespace irr

#endif


namespace irr
{
namespace audio
{
	class IAudioStream;

//!	Class which is able to create an audio file stream from a file.
class IAudioStreamLoader : public IUnknown
{
public:

	//! destructor
	virtual ~IAudioStreamLoader() {};

	//! Returns true if the file maybe is able to be loaded by this class.
	/* This decision should be based only on the file extension (e.g. ".wav"). The given
	filename string is guaranteed to be lower case. */
	virtual bool isALoadableFileExtension(const c8* fileName) = 0;

	//! Creates an audio file input stream from a file
	/* \return Pointer to the created audio stream. Returns 0 if loading failed.
	If you no longer need the stream, you should call IAudioFileStream::drop().
	See IUnknown::drop() for more information. */
	virtual IAudioStream* createAudioStream(irr::io::IReadFile* file) = 0;
};


} // end namespace audio
} // end namespace irr

#endif


//! irrKlang Version
#define IRR_KLANG_VERSION "0.7"

/*! \mainpage irrKlang 0.7 API documentation
 *
  <div align="center"><img src="logobig.png" ></div>
 *
  \section intro Introduction
 *
  Welcome to the irrKlang API documentation.
  Here you'll find any information you'll need to develop applications with
  irrKlang. If you are looking for a tutorial on how to start, you'll
  find some on the homepage of irrKlang at
  <A HREF="http://www.ambiera.com/irrklang" >http://www.ambiera.com/irrklang</A>
  or inside the SDK in the directory \examples.
 *
  The irrKlang library is intended to be an easy-to-use 3d and 2d sound engine, so
  this documentation is an important part of it. If you have any questions or
  suggestions, just send a email to the author of the engine, Nikolaus Gebhardt
  (niko (at) irrlicht3d.org).
 *
 *
  \section links Links
 *
  <A HREF="namespaces.html">Namespaces</A>: A very good place to start reading
  the documentation.<BR>
  <A HREF="annotated.html">Class list</A>: List of all classes with descriptions.<BR>
  <A HREF="functions.html">Class members</A>: Good place to find forgotten features.<BR>
 *
  \section irrexample Short example
 *
  A simple application, starting up the sound engine and playing a .wav sound effect and
  some streaming .ogg music file.
 *
  \code
  #include <iostream>
  #include <irrKlang.h>
  using namespace irr;
  using namespace audio;
 *
  #pragma comment(lib, "irrKlang.lib") // link with irrKlang.dll
 *
 *
  int main(int argc, const char argv)
  {
  	// start the sound engine with default parameters
  	ISoundEngine engine = createIrrKlangDevice();
 *
  	if (!engine)
  		return 0; // error starting up the engine
 *
  	// play some sound stream, looped
  	engine->play2D("../../media/helltroopers.ogg", true);
 *
  	std::cout << "\nHello World!\n";
 *
  	char i = 0;
 *
  	while(i != 'q')
  	{
  		std::cout << "Press any key to play some sound, press 'q' to quit.\n";
 *
  		// play a single sound
  		engine->play2D("../../media/bell.wav");
 *
  		std::cin >> i; // wait for user to press some key
  	}
 *
  	engine->drop(); // delete engine
  	return 0;
  }
 *
  \endcode
 */

#if defined(IRRKLANG_STATIC)
    #define IRRKLANG_API
#else
    #if (defined(WIN32) || defined(WIN64) || defined(_MSC_VER))
        #ifdef IRRKLANG_EXPORTS
        #define IRRKLANG_API __declspec(dllexport)
        #else
        #define IRRKLANG_API __declspec(dllimport)
        #endif // IRRKLANG_EXPORT
    #else
        #define IRRKLANG_API __attribute__((visibility("default")))
    #endif // defined(WIN32) || defined(WIN64)
#endif // IRRKLANG_STATIC

#if defined(_STDCALL_SUPPORTED)
#define IRRKLANGCALLCONV __stdcall  // Declare the calling convention.
#else
#define IRRKLANGCALLCONV
#endif // STDCALL_SUPPORTED

//! Everything in the Irrlicht Engine can be found in this namespace.
namespace irr
{
namespace audio
{
	//! Creates an irrKlang device. The irrKlang device is the root object for using the sound engine.
	/* \param driver The sound output driver to be used for sound output. Use audio::ESOD_AUTO_DETECT
	to let irrKlang decide which driver will be best.
	\param options A combination of audio::E_SOUND_ENGINE_OPTIONS literals. Default value is ESEO_DEFAULT_OPTIONS.
	\param sdk_version_do_not_use Don't use or change this parameter. Always set it to
	IRRKLANG_SDK_VERSION, which is done by default. This is needed for sdk version checks.
	\return Returns pointer to the created irrKlang device or null if the
	device could not be created. If you don't need the device, use ISoundEngine::drop() to
	delete it. See IUnknown::drop() for details.
	*/
	IRRKLANG_API ISoundEngine* IRRKLANGCALLCONV createIrrKlangDevice(
		E_SOUND_OUTPUT_DRIVER driver = ESOD_AUTO_DETECT,
		int options = audio::ESEO_DEFAULT_OPTIONS,
		const char* sdk_version_do_not_use = IRR_KLANG_VERSION);
}

	// THE FOLLOWING IS AN EMPTY LIST OF ALL SUB NAMESPACES
	// EXISTING ONLY FOR THE DOCUMENTATION SOFTWARE DOXYGEN.

	//! In this namespace can be found basic classes like vectors, planes, arrays, lists and so on.
	namespace core
	{
	}

	//! This namespace provides interfaces for input/output: Reading and writing files, accessing zip archives, xml files, ...
	namespace io
	{
	}

	//! The video namespace contains classes for accessing the video driver. All 2d and 3d rendering is done here.
	namespace video
	{
	}

	//! Most of the irrKlang classes for sound output can be found here.
	namespace audio
	{
	}
}


/*! \file irrKlang.h
    \brief Main header file of the irrKlang sound library, the only file needed to include.
*/

using namespace irr;
using namespace audio;

#pragma comment(lib, "irrklang.lib")


#endif


//******************************************************
//**  MSGAEngine3DSoundInfo class
//******************************************************
class MSGAEngine3DSoundInfo
	{
	////////////////////////////////////////////////
	//@{
	bool mInitialized;
	//@}
	MString mFileName;					// File Name of file
	ISoundEngine *mDevice;				// Reference to sound
	ISound *mSound;
	
	////////////////////////////////////////////////
	void ClearObject(void);
	
	////////////////////////////////////////////////
	public:
	MSGAEngine3DSoundInfo(void);
	~MSGAEngine3DSoundInfo(void);
	bool Create(ISoundEngine *engine,const char *filename);	
	bool Destroy(void);
	//@{
	bool IsInitialized(void);
	bool IsValid(void);
	//@}
	bool Play(bool loop=false);
	bool Play3D(float x,float y,float z,bool loop=false);
	bool Stop(void);					// Stop the sound
	bool Continue(void);				// Continue the sound
	bool IsPaused(void);				// =true, if sound is stoped
	bool IsFinished(void);				// =true if sound is finished playing
	bool SetVolume(float volume);		// volume(0...1.0f)
	bool SetPan(float val);				// val(-1..0(Center).,+1)
	int GetPlayLength(void);			// =0(if unknown)
	int GetPlayPosition(void);			// Get Current Play Position
	};

#endif // MSGAEngine3DSoundInfo_h

//v1.0 copyright Comine.com 20070128U00
#ifndef THeapObjectTable_h
#define THeapObjectTable_h

//////////////////////////////////////////////////
///v1.3 Copyright Comine.com 20070128U01
#ifndef THeapObject_h
#define THeapObject_h

//////////////////////////////////////////////
//v1.25 copyright Comine.com 20070329R10
#ifndef MMemory_h
#define MMemory_h

////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////
class MMemory
	{

	////////////////////////////////////////////////////////////
	public:
	static void *Alloc(int size,const char *file,int linenumber);
	static void *Realloc(void *oldblock,int newsize,const char *file,int linenumber);
	static bool Free(void *memoryblock);
	static bool IsValid(void *memoryblock);			// Checks if memory block is valid
	//@{
	static void Enable(bool flag=true);				// Enable MemoryTracker
	static bool IsMemoryOK(void);					// Check if memory blocks have broken fences
	static void Display(void);						// Displays a list of used memory blocks
	static bool IsMemoryTrackEnabled(void);			// =true if memory track is enabled
	//@}
	static int GetTotalBlocks(void);				// Get Total Memory Blocks
	};


//****************************************************************
//** Overload for C++ Ease
//****************************************************************
template <class Simple>
Simple *MMemoryAlloc(const char *file,int lineno)
	{
	Simple *mem;
	mem=(Simple *)MMemory::Alloc(sizeof(Simple),file,lineno);
	if(mem==0)
		{
		MStdLog("Unable to alloc memory object",file,lineno);
		return 0;
		}

	MStdMemZero(mem,sizeof(Simple) );
	return mem;
	}


////////////////////////////////////////////////
template <class Simple>
bool MMemoryFree(Simple  *&ptr)
	{
	if(ptr==0)
		{
		return true;
		}

	ptr->Destroy();
	MMemory::Free(ptr);
	ptr=0;
	return true;
	}

#endif // MMemory_h


//////////////////////////////////////////////
template <class MClass>
class THeapObject:public MClass
	{
	//////////////////////////////////////////
	int mRefCount;
	
	//////////////////////////////////////////
	THeapObject(void){ }

	//////////////////////////////////////////
	~THeapObject(void) { }

	//////////////////////////////////////////
	public:

	//////////////////////////////////////////
	int AddRef(void)
		{
		mRefCount=mRefCount+1;
		return mRefCount;
		}


	//////////////////////////////////////////
	int DropRef(void)
		{
		MStdAssert(mRefCount>0);
		mRefCount=mRefCount-1;
		if(mRefCount<=0)
			{
			Destroy();
			mRefCount=0;
			MMemory::Free(this);
			return 0;
			}

		return mRefCount;
		}


	/////////////////////////////////////////
	int GetRefCount(void)
		{
		return mRefCount;
		}


	//////////////////////////////////////////
	static THeapObject *Alloc(const char *file,int line)
		{
		THeapObject *object=(THeapObject *)MMemory::Alloc(sizeof(THeapObject),file,line);
		if(object==NULL) { return NULL; }
		MStdMemZero(object,sizeof(THeapObject) );
		object->mRefCount=1;
		return object;
		}
	};


#endif // THeapObject_h

//v1.6 copyright Comine.com 20070303S21
#ifndef MIntLookupTable_h
#define MIntLookupTable_h

//******************************************************
//**  MIntLookupTable Holds Objects identified by an Integer
//******************************************************
class MIntLookupTable
	{
	////////////////////////////////////////////////
	bool mInitialized;
	struct GObjectTableNode **mTable;			// Table
	int mTableLength;							// Table Length
	int mObjectCount;							// Count of Objects
	int mSignature;								// Signature for error checking
	int mCurrentReadIndex;						// Current Read Index
	int mLastUniqueID;							// Attempt to find an unique id
	struct GObjectTableNode *mNextReadNode;		// Next Read Node
	static int GTempType;

	////////////////////////////////////////////////
	void ClearObject(void);
	bool ClearTable(void);						// Clears the table
	bool FreeSlot(int index);					// Free up list at index
	int HashFun(int objectid);					// Hash Function
	GObjectTableNode *Find(int objid);			// Find the Object but do not move
	GObjectTableNode *FindAndMove(int objid);	// Find Object and Move To Front
	
	////////////////////////////////////////////////
	public:
	MIntLookupTable(void);
	~MIntLookupTable(void);
	bool Create(int hashtablesize=101);			// Use prime number for table size
	bool Destroy(void);
	//@{
	bool IsInitialized(void);
	bool IsValid(void);
	//@}
	bool Clear(void);							// Clears the table
	int GetCount(void);							// Get Count of Objects
	bool ObjectAlloc(int objid,void *object,bool ondestroy(void *)=0
			,int objtype=0);					// Allocate object space
	bool ObjectFree(int objid);					// Delete Object
	void *ObjectGet(int id,int &objecttype=GTempType);	// Find Object using id
	bool IsObject(int id);						// Non Mutable check
	bool ObjectCheck(void *object);				// Check if object is member of colleciton
	bool ObjectTypeDelete(int objecttype);		// Delete All Nodes with this type
	int GetUnusedID(void);						// Get an unused ID

	// Reader Code
	bool ReadReset(void);						// Reset Reader
	bool Read(void *&object,int &objid,int &objecttype=GTempType);		// read
	};


#endif // MIntLookupTable_h


//////////////////////////////////////////////////
template <class MClass>
class THeapObjectTable:public MIntLookupTable
	{
	static int GClassType;

	/////////////////////////////////////////////
	static bool GOnDestroy(void *object)
		{
		THeapObject<MClass> *ptr=(THeapObject<MClass> *)object;
		MStdAssert(ptr!=NULL);
		ptr->DropRef();
		return true;
		}


	//////////////////////////////////////////////////////////
	public:
	bool ObjectAlloc(int objid,int objtype)
		{
		// Allocate Reference Counted Heap Object
		THeapObject<MClass> *newobject=THeapObject<MClass>::Alloc(__FILE__,__LINE__);
		MStdAssert(newobject!=NULL);
		if(newobject==NULL)
			{  return false; }

		// Allocate table entry
		if(MIntLookupTable::ObjectAlloc(objid,newobject,GOnDestroy,objtype)==false)
			{
			// Release heap object
			newobject->DropRef();
			return false;
			}

		return true;
		}

	
	//////////////////////////////////////////////////////////
	THeapObject<MClass> *ObjectGet(int objid,int &objtype=GClassType)
		{
		return (THeapObject<MClass> *)MIntLookupTable::ObjectGet(objid,objtype);
		}


	///////////////////////////////////////////////////////////
	bool Read(THeapObject<MClass> *&object,int &objid,int &objecttype=GClassType)
		{
		return MIntLookupTable::Read((void * &)object,objid,objecttype);
		}

	///////////////////////////////////////////////////////////
	bool Read(MClass *&object,int &objid,int &objecttype=GClassType)
		{
		return MIntLookupTable::Read((void * &)object,objid,objecttype);
		}
	};


////////////////////////////////////////////////////////////////
template <class MClass>
int THeapObjectTable<MClass>::GClassType=0;


#endif // THeapObjectTable_h


#ifndef MLIBRARY
#pragma comment(lib,"MSGA3D.lib")
#endif // MLIBRARY

//*****************************************************
//*  Keyboard Define Statements
//*****************************************************
#define MSGA3D_KEY_ESCAPE          0x01
#define MSGA3D_KEY_1               0x02
#define MSGA3D_KEY_2               0x03
#define MSGA3D_KEY_3               0x04
#define MSGA3D_KEY_4               0x05
#define MSGA3D_KEY_5               0x06
#define MSGA3D_KEY_6               0x07
#define MSGA3D_KEY_7               0x08
#define MSGA3D_KEY_8               0x09
#define MSGA3D_KEY_9               0x0A
#define MSGA3D_KEY_0               0x0B
#define MSGA3D_KEY_MINUS           0x0C    /* - on main keyboard */
#define MSGA3D_KEY_EQUALS          0x0D
#define MSGA3D_KEY_BACK            0x0E    /* backspace */
#define MSGA3D_KEY_TAB             0x0F
#define MSGA3D_KEY_Q               0x10
#define MSGA3D_KEY_W               0x11
#define MSGA3D_KEY_E               0x12
#define MSGA3D_KEY_R               0x13
#define MSGA3D_KEY_T               0x14
#define MSGA3D_KEY_Y               0x15
#define MSGA3D_KEY_U               0x16
#define MSGA3D_KEY_I               0x17
#define MSGA3D_KEY_O               0x18
#define MSGA3D_KEY_P               0x19
#define MSGA3D_KEY_LBRACKET        0x1A
#define MSGA3D_KEY_RBRACKET        0x1B
#define MSGA3D_KEY_RETURN          0x1C    /* Enter on main keyboard */
#define MSGA3D_KEY_LCONTROL        0x1D
#define MSGA3D_KEY_A               0x1E
#define MSGA3D_KEY_S               0x1F
#define MSGA3D_KEY_D               0x20
#define MSGA3D_KEY_F               0x21
#define MSGA3D_KEY_G               0x22
#define MSGA3D_KEY_H               0x23
#define MSGA3D_KEY_J               0x24
#define MSGA3D_KEY_K               0x25
#define MSGA3D_KEY_L               0x26
#define MSGA3D_KEY_SEMICOLON       0x27
#define MSGA3D_KEY_APOSTROPHE      0x28
#define MSGA3D_KEY_GRAVE           0x29    /* accent grave */
#define MSGA3D_KEY_LSHIFT          0x2A
#define MSGA3D_KEY_BACKSLASH       0x2B
#define MSGA3D_KEY_Z               0x2C
#define MSGA3D_KEY_X               0x2D
#define MSGA3D_KEY_C               0x2E
#define MSGA3D_KEY_V               0x2F
#define MSGA3D_KEY_B               0x30
#define MSGA3D_KEY_N               0x31
#define MSGA3D_KEY_M               0x32
#define MSGA3D_KEY_COMMA           0x33
#define MSGA3D_KEY_PERIOD          0x34    /* . on main keyboard */
#define MSGA3D_KEY_SLASH           0x35    /* / on main keyboard */
#define MSGA3D_KEY_RSHIFT          0x36
#define MSGA3D_KEY_MULTIPLY        0x37    /*  on numeric keypad */
#define MSGA3D_KEY_LMENU           0x38    /* left Alt */
#define MSGA3D_KEY_SPACE           0x39
#define MSGA3D_KEY_CAPITAL         0x3A
#define MSGA3D_KEY_F1              0x3B
#define MSGA3D_KEY_F2              0x3C
#define MSGA3D_KEY_F3              0x3D
#define MSGA3D_KEY_F4              0x3E
#define MSGA3D_KEY_F5              0x3F
#define MSGA3D_KEY_F6              0x40
#define MSGA3D_KEY_F7              0x41
#define MSGA3D_KEY_F8              0x42
#define MSGA3D_KEY_F9              0x43
#define MSGA3D_KEY_F10             0x44
#define MSGA3D_KEY_NUMLOCK         0x45
#define MSGA3D_KEY_SCROLL          0x46    /* Scroll Lock */
#define MSGA3D_KEY_NUMPAD7         0x47
#define MSGA3D_KEY_NUMPAD8         0x48
#define MSGA3D_KEY_NUMPAD9         0x49
#define MSGA3D_KEY_SUBTRACT        0x4A    /* - on numeric keypad */
#define MSGA3D_KEY_NUMPAD4         0x4B
#define MSGA3D_KEY_NUMPAD5         0x4C
#define MSGA3D_KEY_NUMPAD6         0x4D
#define MSGA3D_KEY_ADD             0x4E    /* + on numeric keypad */
#define MSGA3D_KEY_NUMPAD1         0x4F
#define MSGA3D_KEY_NUMPAD2         0x50
#define MSGA3D_KEY_NUMPAD3         0x51
#define MSGA3D_KEY_NUMPAD0         0x52
#define MSGA3D_KEY_DECIMAL         0x53    /* . on numeric keypad */
#define MSGA3D_KEY_OEM_102         0x56    /* <> or \| on RT 102-key keyboard (Non-U.S.) */
#define MSGA3D_KEY_F11             0x57
#define MSGA3D_KEY_F12             0x58
#define MSGA3D_KEY_F13             0x64    /*                     (NEC PC98) */
#define MSGA3D_KEY_F14             0x65    /*                     (NEC PC98) */
#define MSGA3D_KEY_F15             0x66    /*                     (NEC PC98) */
#define MSGA3D_KEY_KANA            0x70    /* (Japanese keyboard)            */
#define MSGA3D_KEY_ABNT_C1         0x73    /* /? on Brazilian keyboard */
#define MSGA3D_KEY_CONVERT         0x79    /* (Japanese keyboard)            */
#define MSGA3D_KEY_NOCONVERT       0x7B    /* (Japanese keyboard)            */
#define MSGA3D_KEY_YEN             0x7D    /* (Japanese keyboard)            */
#define MSGA3D_KEY_ABNT_C2         0x7E    /* Numpad . on Brazilian keyboard */
#define MSGA3D_KEY_NUMPADEQUALS    0x8D    /* = on numeric keypad (NEC PC98) */
#define MSGA3D_KEY_PREVTRACK       0x90    /* Previous Track (MSGA3D_KEY_CIRCUMFLEX on Japanese keyboard) */
#define MSGA3D_KEY_AT              0x91    /*                     (NEC PC98) */
#define MSGA3D_KEY_COLON           0x92    /*                     (NEC PC98) */
#define MSGA3D_KEY_UNDERLINE       0x93    /*                     (NEC PC98) */
#define MSGA3D_KEY_KANJI           0x94    /* (Japanese keyboard)            */
#define MSGA3D_KEY_STOP            0x95    /*                     (NEC PC98) */
#define MSGA3D_KEY_AX              0x96    /*                     (Japan AX) */
#define MSGA3D_KEY_UNLABELED       0x97    /*                        (J3100) */
#define MSGA3D_KEY_NEXTTRACK       0x99    /* Next Track */
#define MSGA3D_KEY_NUMPADENTER     0x9C    /* Enter on numeric keypad */
#define MSGA3D_KEY_RCONTROL        0x9D
#define MSGA3D_KEY_MUTE            0xA0    /* Mute */
#define MSGA3D_KEY_CALCULATOR      0xA1    /* Calculator */
#define MSGA3D_KEY_PLAYPAUSE       0xA2    /* Play / Pause */
#define MSGA3D_KEY_MEDIASTOP       0xA4    /* Media Stop */
#define MSGA3D_KEY_VOLUMEDOWN      0xAE    /* Volume - */
#define MSGA3D_KEY_VOLUMEUP        0xB0    /* Volume + */
#define MSGA3D_KEY_WEBHOME         0xB2    /* Web home */
#define MSGA3D_KEY_NUMPADCOMMA     0xB3    /* , on numeric keypad (NEC PC98) */
#define MSGA3D_KEY_DIVIDE          0xB5    /* / on numeric keypad */
#define MSGA3D_KEY_SYSRQ           0xB7
#define MSGA3D_KEY_RMENU           0xB8    /* right Alt */
#define MSGA3D_KEY_PAUSE           0xC5    /* Pause */
#define MSGA3D_KEY_HOME            0xC7    /* Home on arrow keypad */
#define MSGA3D_KEY_UP              0xC8    /* UpArrow on arrow keypad */
#define MSGA3D_KEY_PRIOR           0xC9    /* PgUp on arrow keypad */
#define MSGA3D_KEY_LEFT            0xCB    /* LeftArrow on arrow keypad */
#define MSGA3D_KEY_RIGHT           0xCD    /* RightArrow on arrow keypad */
#define MSGA3D_KEY_END             0xCF    /* End on arrow keypad */
#define MSGA3D_KEY_DOWN            0xD0    /* DownArrow on arrow keypad */
#define MSGA3D_KEY_NEXT            0xD1    /* PgDn on arrow keypad */
#define MSGA3D_KEY_INSERT          0xD2    /* Insert on arrow keypad */
#define MSGA3D_KEY_DELETE          0xD3    /* Delete on arrow keypad */
#define MSGA3D_KEY_LWIN            0xDB    /* Left Windows key */
#define MSGA3D_KEY_RWIN            0xDC    /* Right Windows key */
#define MSGA3D_KEY_APPS            0xDD    /* AppMenu key */
#define MSGA3D_KEY_POWER           0xDE    /* System Power */
#define MSGA3D_KEY_SLEEP           0xDF    /* System Sleep */
#define MSGA3D_KEY_WAKE            0xE3    /* System Wake */
#define MSGA3D_KEY_WEBSEARCH       0xE5    /* Web Search */
#define MSGA3D_KEY_WEBFAVORITES    0xE6    /* Web Favorites */
#define MSGA3D_KEY_WEBREFRESH      0xE7    /* Web Refresh */
#define MSGA3D_KEY_WEBSTOP         0xE8    /* Web Stop */
#define MSGA3D_KEY_WEBFORWARD      0xE9    /* Web Forward */
#define MSGA3D_KEY_WEBBACK         0xEA    /* Web Back */
#define MSGA3D_KEY_MYCOMPUTER      0xEB    /* My Computer */
#define MSGA3D_KEY_MAIL            0xEC    /* Mail */
#define MSGA3D_KEY_MEDIASELECT     0xED    /* Media Select */


//******************************************************
//**  MSGAEngine3D class
//******************************************************
class MSGAEngine3D
	{
	////////////////////////////////////////////////
	bool mInitialized;

	// Irrlicht/IrrKlang References 
	IrrlichtDevice *mRefDevice;						// Reference to Irrlicht Device
	IVideoDriver *mRefVideoDriver;					// Reference to Irrlicht Video Driver
	ISceneManager *mRefSceneMgr;					// Reference to Irrlicht Scene Manager
	IFileSystem *mRefFileSystem;					// Reference to Irrlicht File System
	ICursorControl *mRefCursorControl;				// Reference to Irrlicht Cursor Control
	ITimer *mRefTimer;								// Reference to Irrlicht Timer
	ISceneCollisionManager *mRefCollisionMgr;		// Reference to Irrlicht Collision Mgr
	IGUIEnvironment *mRefGUIEnvironment;			// Reference to Irrlicht GUI Environment
	ISoundEngine *mSoundDevice;						// irrKlang Device

	unsigned int mLastFrameTime;
	class MTimeEventHeap *mEventQueue;				// Holds Events
	class MTimeWatch *mClock;						// Master Clock
	class MMouseDevice *mMouse;						// Mouse Wrapper
	class MKeyboardDevice *mKeyboard;				// Keyboard Wrapper
	class MCollisionOracle *mCache;					// Cache for sector node lookup
	class MCollisionOracle *mObjectCache;			// Cache of all Objects
	HWND mhIrrlichtWindow;							// Handle to irrlicht window
	int mLastKey;									// Last Key Pressed
	unsigned int mLastKeyTime;						// Last Key/Mouse time
	SColor mBackColor;								// Default Back Color
	THeapObjectTable<MSGAEngine3DSoundInfo> mSoundTable;	// Holds all the sounds
	THeapObjectTable<MSGAEngine3DTextureInfo> mTextureTable;	// Holds all the textures
	THeapObjectTable<MSGAEngine3DMeshInfo> mMeshTable;	// Holds all the animates meshs
	THeapObjectTable<MSGAEngine3DNodeInfo> mNodeTable;	// Reference to Node Table
	THeapObjectTable<MSGAEngine3DObjectInfo> mObjectTable;	// Object Table
	THeapObjectTable<MSGAEngine3DFontInfo> mFontTable;	// Table of Fonts
	THeapObjectTable<MSGAEngine3DGUIInfo> mGUITable;	// Table of GUI Objects
	THeapObjectTable<MSGAEngine3DTaskInfo> mTaskTable;	// Holds all the Tasks
	THeapObjectTable<MSGAEngine3DAnimationInfo> mAnimationTable;	// Holds All Animations
	bool mGUIEnabled;								// =true if GUI Is Enabled
	bool mSceneGraphEnabled;						// =true if scene graph is enabled
	int mGameLoopExitCode;							// >=0 for (exit)
	bool mGameLoopDisableExc;						// = true if escape key is disabled
	class MSGAEngine3DEventReceiver *mEventReceiver;// Handles all Events
	bool (*mWindowRendererFirst)(MSGAEngine3D &);	// Call back for rendering
	bool (*mWindowRendererSecond)(MSGAEngine3D &);	// Call back for rendering
	bool (*mWindowRendererThird)(MSGAEngine3D &);	// Call back for rendering
	int mWindowWidth;								// Width of window
	int mWindowHeight;								// Height of Window
	class MActionIDList *mGameLoopActionList;		// List of Loop Actions
	class MActionIDList *mKeyboardActionList;		// List of Callbacks for Keyboard

	/////////////////////////////////////////////////
	static BOOL CALLBACK GEnumWindows(HWND hwnd,LPARAM lparam);
	static bool GOnTimedEvent(unsigned int,struct MTimeEventHeapInfo *);
	static bool GOnTimedEventEnd(struct MTimeEventHeapInfo *);
	static bool GOnAnimationEvent(unsigned int,struct MTimeEventHeapInfo *);
	static bool GOnAnimationEventEnd(struct MTimeEventHeapInfo *);
	static bool GOnTaskAnimation(MSGAEngine3D &engine,int,void *);
	static bool GRemoveAnimator(MSGAEngine3D &engine,int nodeid,void *animator);
	static bool GMoveRemoveAnimatorAndExecute(MSGAEngine3D &engine
			,int taskid,void *animator);
	static bool GRotateRemoveAnimatorAndExecute(MSGAEngine3D &engine
			,int taskid,void *animator);

	////////////////////////////////////////////////
	void ClearObject(void);
	bool CaptureScreen(void);
	bool CreateDevice(HWND hwnd);
	bool ObjectUpdate(int deltatime);				// Update all object positions
	bool MoveConsoleWindow(void);					// Move Console Window to top left
	bool RepositionWindow(void);					// Reposition output window for debugging
	bool DisplayIntro(void);						// Display Introduction
	IMesh *MakeMeshRectangle(int width,int height);	// Make a mesh Rectangle
	bool AddNodeToTable(int nodeid,ISceneNode *node,MSGAEngine3DNodeInfoType nodetype);	// Add Node To Node Table
	bool AddTextureToTable(int texid,ITexture *texure);	// Add Texture to Texture Table
	bool AddMeshToTable(int meshid,IAnimatedMesh *mesh,bool dropmesh,bool issmeshbuffer);
	
	////////////////////////////////////////////////
	public:
	MSGAEngine3D(void);
	MSGAEngine3D(int width,int height,int bpp,bool fullscreen=false);
	~MSGAEngine3D(void);
	bool Create(int width=640,int height=480,int bpp=16,bool fullscreen=false);
	bool Create(HWND hwndirrlicht,HWND hwndapplication);
	bool Destroy(void);
	bool IsInitialized(void);
	bool IsValid(void);

	// Irrlicht Accessor Functions
	IrrlichtDevice *GetDevice(void);
	IVideoDriver *GetVideoDriver(void);
	ISceneManager *GetSceneManager(void);
	IFileSystem *GetFileSystem(void);
	IEventReceiver *GetEventReceiver(void);
	ICursorControl *GetCursorControl(void);
	ITimer *GetTimer(void);
	ISceneCollisionManager *GetCollisionManager(void);
	IGUIEnvironment *GetGUIEnviron(void);
	ISoundEngine *GetSoundDevice(void);

	// Mouse+Keyboard Functions
	bool KeyIsPressed(int key,unsigned int lastdelta=0);	// Check if key is pressed
	bool MouseGetDelta(int &dx,int &dy);					// Get Mouse Delta
	bool MouseIsLeftPressed(unsigned int lastdelta=0);		// Check if Mouse Left Key pressed
	bool MouseIsRightPressed(unsigned int lastdelta=0);		// Check if Mouse Right Key pressed
	bool MouseIsMiddlePressed(unsigned int lastdelta=0);	// Check if Mouse Middle Key pressed

	// Keyboard Functions
	bool KeyHandlerLoad(int id,bool OnKey(MSGAEngine3D &engine,int key) );
	bool KeyHandlerUnload(int id);
	bool KeyHandlerUnloadAll(void);

	// Game Loop Functions
	int GameLoop(void);
	bool GameLoopExit(int exitvalue=0);				// Exit Game Loop once
	bool GameLoopDisableEsc(bool newval=true);		// Disable Escape Key
	bool GameEnginePause(bool pause=true);			// Pause the game engine time
	bool GameEngineIsPaused(void);					// =true, if engine clocks are paused
	bool GameLoopActionLoad(int actionid,bool action(MSGAEngine3D &engine) );						// Add Action to loop list
	bool GameLoopActionUnload(int actionid);		// Unload an Action
	bool GameLoopActionUnloadAll(void);				// Unload all loop Actions

	// Task Events
	bool TaskLoad(int taskid,int deltatime,bool repeat
			,bool (*action)(MSGAEngine3D &engine,int iextra,void *pextra)
			,int iextra=0,void *pextra=0);
	bool TaskLoadSimple(int deltatime
			,bool (*action)(MSGAEngine3D &engine,int iextra,void *pextra)
			,int iextra=0,void *pextra=0);
	bool TaskLoadAnimation(int taskid,int animid,int nodeid);
	int TaskGetUnusedID(void);						// Return an unused taskid
	MSGAEngine3DTaskInfo *TaskFind(int taskid);	
	bool TaskUnload(int taskid);
	bool TaskUnloadAll(void);		

	// Sound Functions
	MSGAEngine3DSoundInfo *SoundLoad(int soundid,const char *file);	//Load up sound
	MSGAEngine3DSoundInfo *SoundFind(int soundid);	// Find the Sound
	bool SoundPlay(int soundid,bool loop=false);	// Play the sound
	bool SoundPlay(int soundid,float x,float y,float z,bool loop=false);
	bool SoundSetListner(float x=0,float y=0,float z=0
			,float velx=0,float vely=0,float velz=0
			,float nx=0,float ny=0,float nz=1.0);
	bool SoundStop(int soundid);					// Stop playing the sound
	bool SoundContinue(int soundid);				// Continue playing the sound
	bool SoundVolume(int soundid,float vol);		// volume(0...1(100%) )
	bool SoundPan(int soundid,float pan);			// (+1..0(center)...-1)
	bool SoundUnload(int soundid);					// Unload the sound
	bool SoundUnloadAll(void);						// Unload all the sounds

	// Texture Functions
	ITexture *TextureLoad(int texid,const char *filename);
	bool TextureLoadSpriteSet(int texidstart,int rows,int cols,const char *filename);
	bool TextureColorKey(int texid,int alpha=255,int red=0,int green=0,int blue=0);
	bool TextureRangeColorKey(int texidstart,int count,int alpha=255,int red=0,int green=0,int blue=0);
	bool TextureColorKeyPixel(int texid,int pixelx=1,int pixely=1);
	bool TextureRangeColorKeyPixel(int texstart,int count,int pixelx=1,int pixely=1);
	bool TextureMakeNormalMap(int texid,float amplitude=5.0f);
	ITexture *TextureFind(int texid);
	bool TextureUnload(int texid);
	bool TextureUnloadAll(void);

	// Font Functions
	MSGAEngine3DFontInfo *FontLoad(int fontid,const char *filename
				,int rows,int cols,char *lookup);
	MSGAEngine3DFontInfo *FontFind(int fontid);
	bool FontUnload(int fontid);
	bool FontUnloadAll(void);

	// Animation Functions
	MSGAEngine3DAnimationInfo *AnimationLoad(int animid,const char *filename
			,int rows,int cols,int deltatime=100);
	MSGAEngine3DAnimationInfo *AnimationFind(int animid);
	bool AnimationPlay(int animid,int nodeid);
	bool AnimationColorKey(int animid,int alpha=255,int red=0,int green=0,int blue=0);
	bool AnimationColorKeyPixel(int texid,int pixelx=1,int pixely=1);
	bool AnimationUnload(int animid);
	bool AnimationUnloadAll(void);

	// Mesh Functions
	IAnimatedMesh *MeshLoadEmpty(int meshid);	
	IAnimatedMesh *MeshLoad(int meshid,const char *filename);
	IAnimatedMesh *MeshLoadCylinder(int meshid,float radius,float height
			,int pies=20,int layers=1
			,int alpha=255,int red=255,int green=255,int blue=255);
	IAnimatedMesh *MeshLoadRectangle(int meshid,float width,float height
			,int alpha=255,int red=255,int green=255,int blue=255
			,int texumax=1,int texvmax=1);
	IAnimatedMesh *MeshLoadBox(int meshid,float xwidth,float ywidth,float zwidth
			,int alpha=255,int red=255,int green=255,int blue=255);
	IAnimatedMesh *MeshLoadBoxWithFaces(int meshid,float xwidth,float ywidth,float zwidth
			,int alpha=255,int red=255,int green=255,int blue=255); // Texture split across faces
	IAnimatedMesh *MeshLoadEmptyBox(int meshid,float xwidth,float ywidth,float zwidth);
	IAnimatedMesh *MeshLoadSphere(int meshid,float radius,int slices=10,int layers=10
			,int alpha=255,int red=255,int green=255,int blue=255);
	IAnimatedMesh *MeshLoadTangents(int meshid,int srcmesh);
	IAnimatedMesh *MeshLoadHillPlane(int meshid);
	bool MeshUnload(int meshid);
	bool MeshUnloadAll(void);
	
	int MeshGetCount(int meshid);					// Returns >1 (animated) =1(Normal)
	int MeshGetSubCount(int meshid,int submesh);	// Get Sub Count of Meshs
	IAnimatedMesh *MeshFind(int meshid);
	bool MeshSetAABB(int meshid,float minx,float miny,float minz
			,float maxx,float maxy,float maxz,int submesh=0);
	bool MeshGetAABB(int meshid,float &minx,float &miny,float &minz
			,float &maxx,float &maxy,float &maxz,int submesh=0);	
	bool MeshSetColor(int meshid,int alpha,int red,int green,int blue);
	int MeshGetVertexCount(int meshid);					// Get Vertex Count
	int MeshGetTriangleCount(int meshid);				// Get Trianle Count
	bool MeshAddVertex(int meshid,float x,float y,float z
				,float u=0,float v=0
				,int alpha=255,int red=255,int green=255,int blue=255
				,float n1=1,float n2=0,float n3=0);
	bool MeshAddTriangle(int meshid,int index1,int index2,int index3);

	// ISceneNode
	ISceneNode *NodeLoadEmpty(int nodeid);
	ISceneNode *NodeLoadFontText(int nodeid,int fontid,int size,const char *fmt,...);
	ISceneNode *NodeLoadMesh(int nodeid,int meshid);
	ISceneNode *NodeLoadCube(int nodeid,float size);
	IAnimatedMeshSceneNode *NodeLoadAnimated(int nodeid,int meshid);
	ISceneNode *NodeLoadWater(int nodeid,int meshid,float height=5.0f
			,float speed=300.0f,float length=10.0f);
	ISceneNode *NodeLoadOctTree(int nodeid,int meshid);
	ICameraSceneNode *NodeLoadCameraFPS(int nodeid,float rotatespeed=100.0f
			,float movespeed=500.0f,float farplanedistance=3000.0f,bool vertmove=true);
	ICameraSceneNode *NodeLoadCamera(int nodeid,float farplanedistance=3000.0f);
	IBillboardSceneNode *NodeLoadBillboard(int nodeid,float width=50.0f,float height=50.0f);
	ISceneNode *NodeLoadSkyBox(int nodeid,int textop,int texbottom
			,int texfront,int texback,int texleft,int texright);
	ISceneNode *NodeLoadText(int nodeid,int alpha,int red,int green,int blue
				,const char *format,...);
	ITerrainSceneNode *NodeLoadTerrain(int nodeid,const char *terrain);
	ISceneNode *NodeLoadSkyDome(int nodeid,int textureid,float fov=360);
	ISceneNode *NodeLoadLight(int nodeid,float radius=1000
				,int red=255,int green=255,int blue=255);
	IParticleSystemSceneNode *NodeLoadParticleSystem(int nodeid);
	ISceneNode *NodeLoadLOD(int nodeid
			,bool onprerender(MSGAEngine3D &,int,void *)
			,void *onprerenderextra=NULL
			,bool onpostrender(MSGAEngine3D &,int,void *)=NULL
			,void *onpostrenderextra=NULL);
	int NodeGetUnusedID(void);						// Return an unused nodeid
	bool NodeUnload(int nodeid,bool removefromscene=true);
	bool NodeUnloadAll(void);

	// Node Operations
	bool NodeCameraSetActive(int nodeid);
	bool NodeCameraLookAt(int nodeid,float x,float y,float z);
	int NodeCameraGetViewing(void);				//=nodeid which camera is looking at or -1
	ISceneNode *NodeFind(int nodeid);
	int NodeFind(ISceneNode *node);
	bool NodeGetUp(int nodeid,float &nx,float &ny,float &nz);
	bool NodeGetFront(int nodeid,float &nx,float &ny,float &nz);
	bool NodeGetRight(int nodeid,float &nx,float &ny,float &nz);
	bool NodeSetPosition(int nodeid,float x,float y,float z);
	bool NodeSetRotation(int nodeid,float rx,float ry,float rz);
	bool NodeSetScale(int nodeid,float sx,float sy,float sz);
	bool NodeGetPosition(int nodeid,float &x,float &y,float &z);
	bool NodeGetAbsolutePosition(int nodeid,float &x,float &y,float &z);
	bool NodeGetRotation(int nodeid,float &rx,float &ry,float &rz);
	bool NodeGetScale(int nodeid,float &sx,float &sy,float &sz);	
	bool NodeAddPosition(int nodeid,float x,float y,float z);
	bool NodeAddRotation(int nodeid,float rx,float ry,float rz);
	bool NodeAddScale(int nodeid,float sx,float sy,float sz);
	bool NodeUpdatePosition(int nodeid);				// Update Node+Children
	bool NodeSetParent(int nodeid,int newparent,bool keeprelativeposition=false);
	bool NodeSetParent(int nodeid,bool keeprelativeposition=false);	// Set to root scene node
	int NodeGetParent(int nodeid);
	bool NodeSetTexture(int nodeid,int texid,int layer=0);
	bool NodeSolid(int nodid);
	bool NodeReflectSecondLayer(int nodeid);			// Reflect 2nd layer
	bool NodeTransparentAlphaChannel(int nodeid);		// Set Transparent alpha channel
	bool NodeTransparentVertexAlpha(int nodeid);		// (Texture+Material)*Alpha
	bool NodeBackFaceCulling(int nodeid,bool enable=true);
	bool NodeSetMaterialLighting(int nodeid,bool enable);	// Get Lighting
	bool NodeSetMaterialFog(int nodeid,bool enable);	// enable fog effects	
	bool NodeSetMaterialParallaxMap(int nodeid);
	bool NodeTransparentAddColor(int nodid);			// Add background+texture
	bool NodeWireFrame(int nodeid,bool enable);			// Set Node to Wire Frame
	bool NodeSetMaterialFlag(int nodeid,E_MATERIAL_FLAG type=EMF_WIREFRAME,bool flag=true);
	bool NodeSetMaterialType(int nodeid,E_MATERIAL_TYPE type=EMT_SOLID);
	bool NodeSetVisible(int nodeid,bool visible);
	bool NodeIsVisible(int nodeid);
	bool NodeAABBView(int nodeid,bool visible);		// Enable AABB for node
	bool NodeAABBView(bool visible);				// Enable AABB for every node
	bool NodeAABBHitTest(int nodeid1,int nodeid2);	// Check if two AABBs of nodes hit
	bool NodeAABBHitTest(int nodeid1,float x,float y,float z);		// Check if point collides with aabb
	bool NodeAABBHitTest(int nodeid,float x1,float y1,float z1
				,float x2,float y2,float z2);		// Hit Test with a line segment

	// Animation Functions
	bool NodeAnimationSetSpeed(int nodeid,int fps);
	int NodeAnimationFrameCount(int nodeid);
	int NodeAnimationFrameStart(int nodeid);
	int NodeAnimationFrameEnd(int nodeid);
	bool NodeAnimationLoop(int nodeid,bool loop);
	bool NodeAnimationMD2(int nodeid,int animtype);
	bool NodeAnimationStand(int nodeid);
	bool NodeAnimationRun(int nodeid);
	bool NodeAnimationAttack(int nodeid);
	bool NodeAnimationPainA(int nodeid);
	bool NodeAnimationPainB(int nodeid);
	bool NodeAnimationPainC(int nodeid);
	bool NodeAnimationJump(int nodeid);
	bool NodeAnimationFlip(int nodeid);
	bool NodeAnimationSalute(int nodeid);
	bool NodeAnimationFallBack(int nodeid);
	bool NodeAnimationWave(int nodeid);
	bool NodeAnimationPoint(int nodeid);
	bool NodeAnimationCrouchStand(int nodeid);
	bool NodeAnimationCrouchWalk(int nodeid);
	bool NodeAnimationCrouchAttack(int nodeid);
	bool NodeAnimationCrouchPain(int nodeid);
	bool NodeAnimationCrouchDeath(int nodeid);
	bool NodeAnimationDeathFallBack(int nodeid);
	bool NodeAnimationDeathFallForward(int nodeid);
	bool NodeAnimationDeathFallBackSlow(int nodeid);
	bool NodeAnimationBoom(int nodeid);

	// Animators
	bool AnimatorClear(int nodeid);
	bool AnimatorRotation(int nodeid,float rx,float ry,float rz);
	bool AnimatorRotateTo(int nodeid,int deltatime
			,float rx,float ry,float rz
			,bool oncomplete(MSGAEngine3D &engine,int,void *)=0
			,int iextra=0,void *pextra=0);
	bool AnimatorRotateBy(int nodeid,int deltatime
			,float rx,float ry,float rz
			,bool oncomplete(MSGAEngine3D &engine,int,void *)=0
			,int iextra=0,void *pextra=0);
	bool AnimatorFlyStraight(int nodeid
			,float x1,float y1,float z1,float x2,float y2,float z2
			,int timems,bool loop=false);
	bool AnimatorMoveTo(int nodeid,int timems,float x2,float y2,float z2
			,bool oncomplete(MSGAEngine3D &engine,int,void *)=0
			,int iextra=0,void *pextra=0);
	bool AnimatorMoveRelative(int nodeid,int timems,float dx,float dy,float dz
			,bool oncomplete(MSGAEngine3D &engine,int,void *)=0
			,int iextra=0,void *pextra=0);
	bool AnimatorFlyCircle(int nodeid,float x,float y,float z,float radius,float speed);
	bool AnimatorCollisionResponse(int nodeid,int targetnode,int meshid
			,int polycount=32,float nodesize=50.0f,float gravity=0);
	bool AnimatorCollisionResponseTerrain(int nodeid,int terrainid,float gravity=0);

	// Physics Wrapper Object with Position and Rotation Velocity information
	bool ObjectLoad(int objid,int nodeid,float rotx=0,float roty=0,float rotz=0);
	bool ObjectUnload(int objid,bool unloadnode=false);		// Unload Object
	bool ObjectUnloadAll(bool unloadnodes=false);			// Unload all the objects
	int ObjectGetNode(int objid);					// Get Scene Node from Object
	bool ObjectGetFront(int objid,float &nx,float &ny,float &nz);	// Get Front Unit Vector
	bool ObjectGetUp(int objid,float &nx,float &ny,float &nz);		// Get Up Unit Vector
	bool ObjectGetRight(int objid,float &nx,float &ny,float &nz);	// Get Right Unit Vector
	bool ObjectSetFrontVelocity(int objid,float val);				// Set Front Speed
	bool ObjectSetPosition(int objid,float x,float y,float z);		// Set Object Position
	bool ObjectGetPosition(int objid,float &x,float &y,float &z);	// Get Object Relative Position
	bool ObjectAddPosition(int objid,float x,float y,float z);		// Add to object position
	bool ObjectGetAbsolutePosition(int nodeid,float &x,float &y,float &z);
	bool ObjectSetVelocity(int objid,float x,float y,float z);
	bool ObjectGetVelocity(int objid,float &vx,float &vy,float &vz);
	bool ObjectSetRotation(int objid,float x,float y,float z);
	bool ObjectGetRotation(int objid,float &x,float &y,float &z);
	bool ObjectAddRotation(int objid,float x,float y,float z);
	bool ObjectSetRotationVelocity(int objid,float x,float y,float z);
	bool ObjectGetRotationVelocity(int objid,float &vx,float &vy,float &vz);
	bool ObjectAddPositionVelocity(int objid,float dx,float dy,float dz);
	bool ObjectAddRotationVelocity(int objid,float dx,float dy,float dz);
	bool ObjectGetFrontVelocity(int objid,float &vel);
	bool ObjectSetCollisionError(int objid,float errordistance);
	bool ObjectOnStop(int objid,bool OnStop(MSGAEngine3D &engine));
	bool ObjectPrint(int objid,const char *extra="",bool newline=true);	// Print out info
	int ObjectGetUnusedID(void);									// Get Unused ID

	// Track Locations of objects for sector collision testing
	bool ObjectTableInit(float spacewidth=500.0f);					//  Define Sector width
	int ObjectFindAllInSector(float x,float y,float z,int objects[100]);	// Get objects in Sector
	int ObjectFindAllInSector(int objid,int objects[100]);					// Get objects in Sector
	
	// GUI Functions
	bool GUILoadButton(int guidid,int x,int y,int width,int height
			,const char *label="Button"
			,bool handler(MSGAEngine3D &engine,int iextra,void *pextra)=0
			,int iextra=0,void *pextra=0);
	bool GUILoadLabel(int guidid,int x,int y,int width,int height
			,const char *label="Label");			// Load up a Label
	bool GUILoadTextBox(int guidid,int x,int y,int width,int height
			,const char *label="Text Box");			// Load up a Text Box
	bool GUILoadListBox(int guiid,int x,int y,int width,int height);

	bool GUIButtonSetClickEvent(int guiid,bool handler(MSGAEngine3D &engine,int iextra,void *pextra)=0
			,int iextra=0,void *pextra=0);

	bool GUIListBoxClear(int guiid);
	bool GUIListBoxAdd(int guiid,const char *string,int extra=0);
	int GUIListBoxGetItemCount(int guiid);
	int GUIListBoxGetSelected(int guiid);
	bool GUIListBoxSetSelected(int guiid,int index);
	bool GUIListBoxGetItem(int guiid,int index,char item[200]);
	bool GUIListBoxRemoveItem(int guiid,int index);

	bool GUITextBoxGetText(int guuid,char data[200]);
	bool GUITextBoxSetText(int guuid,const char *item);
	bool GUILabelSetText(int guuid,const char *item);

	bool GUIControlSetEnabled(int guiid,bool enable);		// Enable or diable GUI element
	bool GUIControlSetVisible(int guiid,bool visible);		// Show/Hide GUI Element
	bool GUIEnable(bool enable);					// Enable or diable GUI
	bool GUIIsEnabled(void);						//=true if GUI Is enabled
	bool GUIUnload(int guidid);						// Unload a GUID Object
	bool GUIUnloadAll(void);

	// Spatial Cache Holds Sectors
	bool CacheClear(float sectorwidth=500.0f);		// Clear the Cache
	bool CacheLoadNode(int nodeid);					// Add New Node from Cache
	bool CacheUpdateNode(int nodeid);				// Updates node in Cache
	bool CacheUpdateAllNodes(void);					// Updates all nodes in Cache
	bool CacheUnloadNode(int nodeid);				// Remove Node from cache 
	float CacheWidth(void);							// Get Cache Width
	int CacheFindNodes(float x,float y,float z,int nodes[100]);	// Get Nodes in Sector

	// Engine Extras
	bool UnloadAll(void);
	int TimeGet(void);								// Get Clock time in ms

	// Window Functions
	bool WindowSetCaption(const char *caption,...);		// Set Window Caption
	int WindowFrameTime(void);						// Time Since Last Frame
	bool WindowSetColor(int red=0xff,int green=0xff,int blue=0xff);
	bool WindowLogo(void);							// Display Window Logo
	bool WindowRenderer(int level,bool renderer(MSGAEngine3D &)=0);
	bool WindowWrite(int fontid,int left,int top,int size
				,bool colorkey,char *fmt,...);		// Write to window in renderer
	bool WindowTexture(int texid,int x,int y,int width,int height,bool colorkey=false);
	bool WindowTexture(int texid,bool colorkey=false);
	int WindowFramesPerSecond(void);				// Return Frames Per Second
	int WindowNode(int x,int y);					// Get Node at screen position
	int WindowWidth(void);							// Get Window Width
	int WindowHeight(void);							// Get Window Height
	bool WindowUpdate(void);						// Update window
	
	bool AddZipFile(const char *zipfile);			// Add Zip File
	bool SetDirectory(const char *dir);				// Change Current Directory

	bool SceneGraphEnable(bool visible);			// Enable scenegraph
	bool SceneGraphIsEnabled(void);					//=true if scene graph is enables
	bool SceneGraphSetFog(int red=100,int green=100,int blue=100
				,float start=200,float end=500,float density=0.01f);

	bool CursorSetVisible(bool visible);			// Enable/disable cursor
	bool CursorIsVisible(void);						//=true if cursor is set
	};

#endif // MSGAEngine3D_h

