#pragma once
#ifndef __ALLOC_H__
#define __ALLOC_H__

#include <__config>
#include <memory>
#include <cstdlib>

using namespace std;

template <class T>
class Alloc {
public:
	typedef size_t            size_type;
	typedef ptrdiff_t         difference_type;
	typedef T*              pointer;
	typedef const T*        const_pointer;
	typedef T&              reference;
	typedef const T&        const_reference;
	typedef T               value_type;

	typedef true_type propagate_on_container_move_assignment;
	typedef true_type is_always_equal;

	template <class _Up> struct rebind {typedef Alloc<_Up> other;};

	Alloc() {
	}

	template <class _Up>

			Alloc(const Alloc<_Up>&)  {}

			pointer address(reference __x) const
			{return _VSTD::addressof(__x);}
			const_pointer address(const_reference __x) const
			{return _VSTD::addressof(__x);}
			pointer allocate(size_type __n)
			{
		_allocator_used = 1;
		if (__n > max_size())
			__throw_length_error("Alloc<T>::allocate(size_t n)"
								 " 'n' exceeds maximum supported size");
		return static_cast<pointer>(_VSTD::__libcpp_allocate(__n * sizeof(T), _LIBCPP_ALIGNOF(T)));
			}
			void deallocate(pointer __p, size_type __n)
			{
		_allocator_used = 1;
		_VSTD::__libcpp_deallocate((void*)__p, __n * sizeof(T), _LIBCPP_ALIGNOF(T));}
		size_type max_size() const
		{return size_type(~0) / sizeof(T);}
#if !defined(_LIBCPP_HAS_NO_RVALUE_REFERENCES) && !defined(_LIBCPP_HAS_NO_VARIADICS)
template <class _Up, class... _Args>
_LIBCPP_INLINE_VISIBILITY
void
construct(_Up* __p, _Args&&... __args)
{
		_allocator_used = 1;
		::new((void*)__p) _Up(_VSTD::forward<_Args>(__args)...);
}
#else

void
construct(pointer __p)
{
		_allocator_used = 1;
		::new((void*)__p) T();
}
# if defined(_LIBCPP_HAS_NO_RVALUE_REFERENCES)

template <class _A0>
void
construct(pointer __p, _A0& __a0)
{
		_allocator_used = 1;
		::new((void*)__p) T(__a0);
}
template <class _A0>
void
construct(pointer __p, const _A0& __a0)
{
		_allocator_used = 1;
		::new((void*)__p) T(__a0);
}
# endif
template <class _A0, class _A1>

void
construct(pointer __p, _A0& __a0, _A1& __a1)
{
		_allocator_used = 1;
		::new((void*)__p) T(__a0, __a1);
}
template <class _A0, class _A1>

void
construct(pointer __p, const _A0& __a0, _A1& __a1)
{
		_allocator_used = 1;
		::new((void*)__p) T(__a0, __a1);
}
template <class _A0, class _A1>

		void
		construct(pointer __p, _A0& __a0, const _A1& __a1)
		{
		_allocator_used = 1;
		::new((void*)__p) T(__a0, __a1);
		}
		template <class _A0, class _A1>

				void
				construct(pointer __p, const _A0& __a0, const _A1& __a1)
				{
		_allocator_used = 1;
		::new((void*)__p) T(__a0, __a1);
				}
#endif
void destroy(pointer __p) {__p->~T();}
};

template <class T>
class Alloc<const T>
{
public:
	typedef size_t            size_type;
	typedef ptrdiff_t         difference_type;
	typedef const T*        pointer;
	typedef const T*        const_pointer;
	typedef const T&        reference;
	typedef const T&        const_reference;
	typedef const T         value_type;

	typedef true_type propagate_on_container_move_assignment;
	typedef true_type is_always_equal;

	template <class _Up> struct rebind {typedef Alloc<_Up> other;};

	Alloc() {
	}

	template <class _Up>
			Alloc(const Alloc<_Up>&) {}

			const_pointer address(const_reference __x) const
			{return _VSTD::addressof(__x);}
			pointer allocate(size_type __n)
			{
		_allocator_used = 1;
		if (__n > max_size())
			__throw_length_error("Alloc<const T>::allocate(size_t n)"
								 " 'n' exceeds maximum supported size");
		return static_cast<pointer>(_VSTD::__libcpp_allocate(__n * sizeof(T), _LIBCPP_ALIGNOF(T)));
			}
			void deallocate(pointer __p, size_type __n)
			{
		_allocator_used = 1;
		_VSTD::__libcpp_deallocate((void*) const_cast<T *>(__p), __n * sizeof(T), _LIBCPP_ALIGNOF(T));}
		size_type max_size() const
		{return size_type(~0) / sizeof(T);}
#if !defined(_LIBCPP_HAS_NO_RVALUE_REFERENCES) && !defined(_LIBCPP_HAS_NO_VARIADICS)
template <class _Up, class... _Args>
_LIBCPP_INLINE_VISIBILITY
void
construct(_Up* __p, _Args&&... __args)
{
		_allocator_used = 1;
		::new((void*)__p) _Up(_VSTD::forward<_Args>(__args)...);
}
#else

void
construct(pointer __p)
{
		_allocator_used = 1;
		::new((void*) const_cast<T *>(__p)) T();
}
# if defined(_LIBCPP_HAS_NO_RVALUE_REFERENCES)

template <class _A0>

void
construct(pointer __p, _A0& __a0)
{
		_allocator_used = 1;
		::new((void*) const_cast<T *>(__p)) T(__a0);
}
template <class _A0>
void
construct(pointer __p, const _A0& __a0)
{
		_allocator_used = 1;
		::new((void*) const_cast<T *>(__p)) T(__a0);
}
# endif
template <class _A0, class _A1>
void
construct(pointer __p, _A0& __a0, _A1& __a1)
{
		_allocator_used = 1;
		::new((void*) const_cast<T *>(__p)) T(__a0, __a1);
}
template <class _A0, class _A1>
void
construct(pointer __p, const _A0& __a0, _A1& __a1)
{
		_allocator_used = 1;
		::new((void*) const_cast<T *>(__p)) T(__a0, __a1);
}
template <class _A0, class _A1>
		void
		construct(pointer __p, _A0& __a0, const _A1& __a1)
		{
		_allocator_used = 1;
		::new((void*) const_cast<T *>(__p)) T(__a0, __a1);
		}
		template <class _A0, class _A1>
				void
				construct(pointer __p, const _A0& __a0, const _A1& __a1)
				{
		_allocator_used = 1;
		::new((void*) const_cast<T *>(__p)) T(__a0, __a1);
				}
#endif
void destroy(pointer __p) {__p->~T();}
};

#endif