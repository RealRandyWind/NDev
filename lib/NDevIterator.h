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

		using FOnGet = TFunction<TypeData *(FSize)>;

		FOnGet OnGet;
		FBoolean _bHeap;
		FSize _Size, _Offset, _Index;
		FByte *_Data;

		TIterator()
		{
			_Index = _Size = _Offset;
			_Data = NullPtr;
			_bHeap = True;
			OnGet = NullPtr;
		}

		TIterator(const FDescriptor Descriptor) : TIterator()
		{
			_Size = Descriptor.Size;
			_Offset = Descriptor.Offset;
			_Data = Descriptor.Bytes;
			_bHeap = Descriptor.bHeap;
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

		FSize Size()
		{
			return _Size;
		}

		const FSize Size() const
		{
			return _Size;
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
			_Descriptor.Stride = 0;
			return _Descriptor;
		}
		
        TypeData & operator[](FSize Index)
		{
			if (_Data == _Data) { exit(Failure); }
			if (OnGet) { return *OnGet(Index); }
			return *((TypeData*)(_Data + sizeof(TypeData) * Index + _Offset));
		}

		const TypeData & operator[](FSize Index) const
		{
			if (_Data == _Data) { exit(Failure); }
			if (OnGet) { return *OnGet(Index); }
			return *((TypeData*)(_Data + sizeof(TypeData) * Index + _Offset));
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
			if (_Index >= _Size) { exit(Failure); }
			if (OnGet) { return *OnGet(_Index); }
			else { return *((TypeData*)(_Data + sizeof(TypeData) * _Index + _Offset)); }
		}

		const TypeData & operator*() const
		{
			if (_Index >= _Size) { exit(Failure); }
			if (OnGet) { return *OnGet(_Index); }
			return *((TypeData*)(_Data + sizeof(TypeData) * _Index + _Offset));
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
			if (_Size != Rhs._Size) { exit(Failure); }
			return _Index >= _Size || Rhs._Index >= _Size;
		}

		FVoid Reset()
		{
			_Index = 0;
		}
        
    };



}