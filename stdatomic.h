/*--
 * C11 `<stdatomic.h>` shim for MSVC.
 *
 * Copyright (c) 2022, Angelo Haller <angelo@szanni.org>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef MSVC_STDATOMIC_H
#define MSVC_STDATOMIC_H

/* MSVC guarantees proper type alignment to use with the Interlocked* API,
 * other compilers may not.
 * Alternative would be to change the definition of _Atomic to include
 * alignment or only support predefined atomic_* types. */
#if !defined(_MSC_VER)
#error "Compiler not supported, use MSVC"
#else

#include <windows.h>
#include <winnt.h>
#include <assert.h>

#ifndef _Atomic
#define _Atomic volatile
#endif

typedef enum memory_order {
	memory_order_relaxed,
	memory_order_consume,
	memory_order_acquire,
	memory_order_release,
	memory_order_acq_rel,
	memory_order_seq_cst
} memory_order;

#define atomic_init(obj, value) atomic_store(obj, value)

#define _atomic_store(object, desired) do {				\
	switch(sizeof(*(object))) {					\
		case 8: InterlockedExchange64(object, desired); break;	\
		case 4: InterlockedExchange(object, desired); break;	\
		case 2: InterlockedExchange16(object, desired); break;	\
		case 1: InterlockedExchange8(object, desired); break;	\
		default: assert(0); break;				\
	}								\
} while (0)

#define atomic_store(object, desired) atomic_store_explicit(object, desired, memory_order_seq_cst)
#define atomic_store_explicit(object, desired, order) _atomic_store(object, desired)

#define _atomic_load(object)						\
	  (sizeof(*object) == 8) ? InterlockedExchangeAdd64(object, 0)	\
	: (sizeof(*object) == 4) ? InterlockedExchangeAdd(object, 0)	\
	: (sizeof(*object) == 2) ? InterlockedExchangeAdd16(object, 0)	\
	: (sizeof(*object) == 1) ? InterlockedExchangeAdd8(object, 0)	\
	: 0

#define atomic_load(object) atomic_load_explicit(object, memory_order_seq_cst)
#define atomic_load_explicit(object, order) _atomic_load(object)

#endif /* _MSC_VER */
#endif /* MSVC_STDATOMIC_H */

