#pragma once

#include "NDevTypes.h"
#include "NDevDefinitions.h"

namespace NDev
{
	using namespace Types;

    template<typename TypeData>
    struct TIterator
    {
		using FIterator = TIterator<TypeData>;

		using FOnGet = TFunction<TypeData &(FSize, FSize, FSize)>;
		
		using FOnStop = TFunction<FBoolean(FSize)>;

		FOnStop OnStop;
		FOnGet OnGet;
		FBoolean _bHeap;
		FSize _Size, _Offset, _Stride, _Index;
		FByte *_Data;

		TIterator()
		{
			_Index = _Size = _Offset = _Stride = 0;
			_Data = NullPtr;
			_bHeap = True;
			OnGet = NullPtr;
			OnStop = NullPtr;
		}

		TIterator(const FDescriptor Descriptor, FSize Index = 0) : TIterator()
		{
			Reset(Descriptor, Index);
		}

		TIterator(FOnGet _OnGet, FOnStop _OnStop, FSize Index = 0) : TIterator()
		{
			OnGet = _OnGet;
			OnStop = _OnStop;
			Reset(Index);
		}

		TIterator(FOnGet _OnGet, FSize Size, FSize Index = 0) : TIterator()
		{
			OnGet = _OnGet;
			_Size = Size;
			Reset(Index);
		}

		~TIterator()
		{

		}

		FSize Offset()
		{
			return _Offset;
		}

		const FSize Offset() const
		{
			return _Offset;
		}

		FSize Stride()
		{
			return _Stride;
		}

		const FSize Stride() const
		{
			return _Stride;
		}

		FSize Size()
		{
			return _Size;
		}

		const FSize Size() const
		{
			return _Size;
		}

		FSize SizeOf()
		{
			return (sizeof(TypeData) + _Stride) * _Size + _Offset;
		}

		const FSize SizeOf() const
		{
			return (sizeof(TypeData) + _Stride) * _Size + _Offset;
		}

		FByte * Bytes()
		{
			return _Data;
		}

		const FByte * Bytes() const
		{
			return _Data;
		}

		const FDescriptor Descriptor() const
		{
			FDescriptor _Descriptor;

			_Descriptor.Type = None;
			_Descriptor.SizeOf = sizeof(TypeData);
			_Descriptor.Size = _Size;
			_Descriptor._Size = _Size;
			_Descriptor.bHeap = _bHeap;
			_Descriptor.Bytes = _Data;
			_Descriptor.Offset = _Offset;
			_Descriptor.Stride = _Stride;
			return _Descriptor;
		}
		
        TypeData & operator[](FSize Index)
		{
			if (OnGet) { return OnGet(Index, _Offset, _Stride); }
			if (!_Data) { exit(Failure); }
			return *((TypeData*)(_Data + (sizeof(TypeData) + _Stride) * Index + _Offset));
		}

		const TypeData & operator[](FSize Index) const
		{
			if (OnGet) { return OnGet(Index, _Offset, _Stride); }
			if (!_Data) { exit(Failure); }
			return *((TypeData*)(_Data + (sizeof(TypeData) + _Stride) * Index + _Offset));
		}

		FIterator & begin()
		{
			return *this;
		}

		const FIterator & begin() const
		{
			return *this;
		}

		FIterator & end()
		{
			return *this;
		}

		const FIterator & end() const
		{
			return *this;
		}

		TypeData & operator*()
		{
			if (OnGet) { return OnGet(_Index, _Offset, _Stride); }
			if (_Index >= _Size) { exit(Failure); }
			else { return *((TypeData*)(_Data + (sizeof(TypeData) + _Stride) * _Index + _Offset)); }
		}

		const TypeData & operator*() const
		{
			if (OnGet) { return OnGet(_Index, _Offset, _Stride); }
			if (_Index >= _Size) { exit(Failure); }
			return *((TypeData*)(_Data + (sizeof(TypeData) + _Stride) * _Index + _Offset));
		}

		FIterator & operator++()
		{
			++_Index;
			return *this;
		}

		const FIterator & operator++() const
		{
			FIterator Return = *this;
			++Return._Index;
			return Return;
		}

		FBoolean operator!=(const FIterator &Rhs) const
		{	
			if (Rhs._Size != _Size) { exit(Failure); }
			if (OnStop) { return !OnStop(_Index); }
			return  _Index < _Size && Rhs._Index < Rhs._Size;
		}

		FVoid Reset(FSize Index = 0)
		{
			_Index = Index;
		}

		FVoid Reset(const FDescriptor Descriptor, FSize Index = 0)
		{
			_Index = Index;
			_Size = Descriptor.Size;
			_Offset = Descriptor.Offset;
			_Stride = Descriptor.Stride;
			_Data = Descriptor.Bytes;
			_bHeap = Descriptor.bHeap;
		}

        
    };



}