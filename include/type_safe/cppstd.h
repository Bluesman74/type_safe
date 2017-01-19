#ifndef CPP11_SAFE_INCLUDED
#define CPP11_SAFE_INCLUDED

#pragma message (" Include PN C++11 support")

#include <Boost\config\compiler\visualc.hpp>
#include "boost/type_traits/is_nothrow_move_constructible.hpp"


//#include <Boost\config\suffix.hpp>


#define BOB Bill
//---------------+
// Configuration |
//---------------+

// MSVC's constexpr support is still a WIP, even in VS2015.
// Fall back to a lesser mode to support it.
// TODO: Remove this or retest later once MSVC's constexpr improves.
#if defined(_MSC_VER) && _MSC_VER <= 1900 && ! defined(__clang__)
// MS cl compiler pre VS2017
#  define CONSTDATA const
#  define CONSTCD11
#  define CONSTCD14
#  define NOEXCEPT _NOEXCEPT
#  define CONSTEXPR//FOONATHAN
#elif __cplusplus >= 201402
// C++14
#  define CONSTDATA constexpr const
#  define CONSTCD11 constexpr
#  define CONSTCD14 constexpr
#  define NOEXCEPT noexcept
#  define CONSTEXPR CONSTCD11//FOONATHAN
#else
// C++11
#  define CONSTDATA constexpr const
#  define CONSTCD11 constexpr
#  define CONSTCD14
#  define NOEXCEPT noexcept
#  define CONSTEXPR CONSTCD11//FOONATHAN
#endif

namespace cpp_std = boost;
#else


#endif