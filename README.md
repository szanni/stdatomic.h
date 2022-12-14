stdatomic.h
===========

C11 `<stdatomic.h>` shim for MSVC.

Status
------

### Keyword

- [x] _Atomic

### Types

- [x] memory_order
    - [x] memory_order_relaxed
    - [x] memory_order_consume
    - [x] memory_order_acquire
    - [x] memory_order_release
    - [x] memory_order_acq_rel
    - [x] memory_order_seq_cst
- [ ] atomic_flag

### Macros

- [ ] ATOMIC_BOOL_LOCK_FREE
- [ ] ATOMIC_CHAR_LOCK_FREE
- [ ] ATOMIC_CHAR16_T_LOCK_FREE
- [ ] ATOMIC_CHAR32_T_LOCK_FREE
- [ ] ATOMIC_WCHAR_T_LOCK_FREE
- [ ] ATOMIC_SHORT_LOCK_FREE
- [ ] ATOMIC_INT_LOCK_FREE
- [ ] ATOMIC_LONG_LOCK_FREE
- [ ] ATOMIC_LLONG_LOCK_FREE
- [ ] ATOMIC_POINTER_LOCK_FREE

- [ ] ATOMIC_FLAG_INIT
- [ ] ATOMIC_VAR_INIT
- [ ] kill_dependency

### Functions

- [x] atomic_init
- [ ] atomic_thread_fence
- [ ] atomic_signal_fence
- [ ] atomic_is_lock_free
- [x] atomic_store
- [x] atomic_store_explicit
- [x] atomic_load
- [x] atomic_load_explicit
- [ ] atomic_exchange
- [ ] atomic_exchange_explicit
- [ ] atomic_compare_exchange_strong
- [ ] atomic_compare_exchange_strong_explicit
- [ ] atomic_compare_exchange_weak
- [ ] atomic_compare_exchange_weak_explicit
- [ ] atomic_fetch_add
- [ ] atomic_fetch_add_explicit
- [ ] atomic_fetch_sub
- [ ] atomic_fetch_sub_explicit
- [ ] atomic_fetch_or
- [ ] atomic_fetch_or_explicit
- [ ] atomic_fetch_xor
- [ ] atomic_fetch_xor_explicit
- [ ] atomic_fetch_and
- [ ] atomic_fetch_and_explicit
- [ ] atomic_flag_test_and_set
- [ ] atomic_flag_test_and_set_explicit
- [ ] atomic_flag_clear
- [ ] atomic_flag_clear_explicit

### Atomic Types

- [ ] atomic_bool
- [ ] atomic_char
- [ ] atomic_schar
- [ ] atomic_uchar
- [ ] atomic_short
- [ ] atomic_ushort
- [ ] atomic_int
- [ ] atomic_uint
- [ ] atomic_long
- [ ] atomic_ulong
- [ ] atomic_llong
- [ ] atomic_ullong
- [ ] atomic_char16_t
- [ ] atomic_char32_t
- [ ] atomic_wchar_t
- [ ] atomic_int_least8_t
- [ ] atomic_uint_least8_t
- [ ] atomic_int_least16_t
- [ ] atomic_uint_least16_t
- [ ] atomic_int_least32_t
- [ ] atomic_uint_least32_t
- [ ] atomic_int_least64_t
- [ ] atomic_uint_least64_t
- [ ] atomic_int_fast8_t
- [ ] atomic_uint_fast8_t
- [ ] atomic_int_fast16_t
- [ ] atomic_uint_fast16_t
- [ ] atomic_int_fast32_t
- [ ] atomic_uint_fast32_t
- [ ] atomic_int_fast64_t
- [ ] atomic_uint_fast64_t
- [ ] atomic_intptr_t
- [ ] atomic_uintptr_t
- [ ] atomic_size_t
- [ ] atomic_ptrdiff_t
- [ ] atomic_intmax_t
- [ ] atomic_uintmax_t

Limitations
-----------

Currently all operations are performed as `memory_order_seq_cst`.

License
-------

BSD 2-clause license, see LICENSE for more details.

