#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT(hearthstone, 1.1, nitori@ence-dimension.com)
AM_INIT_AUTOMAKE(hearthstone,1.1)
AC_CONFIG_SRCDIR(src/main/core/main.cpp)
AC_CONFIG_HEADERS(config.h)

# Checks for programs.
AC_PROG_CXX
AC_PROG_CC

# Checks for libraries.

# Checks for header files.

# Checks for typedefs, structures, and compiler characteristics.
AC_CHECK_HEADER_STDBOOL

# Checks for library functions.
AC_CHECK_FUNCS([memset])

AC_OUTPUT(Makefile
		  	src/func/core/Makefile
			src/main/core/Makefile
			src/Player/core/Makefile
			src/Randomizer/core/Makefile)
