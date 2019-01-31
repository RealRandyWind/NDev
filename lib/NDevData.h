#pragma once

#include "NDevTypes.h"
#include "NDevDefinitions.h"
#include "NDevResource.h"

namespace NDev
{
	using namespace Types;

	template<typename TypeValue>
	struct TData : public FResource
	{
		using FValue = typename TypeValue;

		FSize _Size, _BufferSize;
		FBoolean _bIterateAll, _bClearDataOnDestroy, _bClearDataOnReplace, _bHeap;
		TypeValue *_Data;

		TData()
		{
			_Size = _BufferSize = 0;
			_bIterateAll = False;
			_bClearDataOnDestroy = True;
			_bClearDataOnReplace = _bClearDataOnDestroy;
			_bHeap = True;
			_Data = NullPtr;
		}

		TData(FSize ReserveSize, FBoolean bSetSizeToReserveSize = False) : TData()
		{
			Reserve(ReserveSize, bSetSizeToReserveSize);
		}

		~TData()
		{
			FBoolean bFree = _bHeap && _bClearDataOnDestroy && _Data;
			if (bFree) { free(_Data); }
			_Data = NullPtr;
		}

		FBoolean Empty()
		{
			return !_Size || !_Data;
		}

		const FBoolean Empty() const
		{
			return !_Size || !_Data;
		}

		FBoolean Full()
		{
			return (_Size >= _BufferSize) && _Data;
		}

		const FBoolean Full() const
		{
			return (_Size >= _BufferSize) && _Data;
		}

		FVoid IterateAll(FBoolean bTrue = True)
		{
			_bIterateAll = bTrue;
		}

		FVoid ClearDataOnDestroy(FBoolean bTrue = True)
		{
			_bClearDataOnDestroy = bTrue;
		}

		FVoid ClearDataOnReplace(FBoolean bTrue = True)
		{
			_bClearDataOnReplace = bTrue;
		}

		FSize Stride()
		{
			return 0;
		}

		const FSize Stride() const
		{
			return 0;
		}

		FSize Offset()
		{
			return 0;
		}

		const FSize Offset() const
		{
			return 0;
		}

		FSize Size()
		{
			return _Size;
		}

		const FSize Size() const
		{
			return _Size;
		}

		FSize BufferSize()
		{
			return _BufferSize;
		}

		const FSize BufferSize() const
		{
			return _BufferSize;
		}

		FSize SizeOf()
		{
			return sizeof(TypeValue) * _Size;
		}

		const FSize SizeOf() const
		{
			return sizeof(TypeValue) * _Size;
		}

		FSize BufferSizeOf()
		{
			return sizeof(TypeValue) * _BufferSize;
		}

		const FSize BufferSizeOf() const
		{
			return sizeof(TypeValue) * _BufferSize;
		}

		FByte * Bytes()
		{
			return (FByte *) _Data;
		}

		const FByte * Bytes() const
		{
			return (FByte *) _Data;
		}

		TypeValue * Data()
		{
			return _Data;
		}

		const TypeValue * Data() const
		{
			return _Data;
		}

		TypeValue *Data(const FDescriptor Descriptor, FBoolean bNoFree = True)
		{
			return Data((TypeValue *)Descriptor.Pointer, Descriptor.Size, Descriptor._Size, Descriptor.bHeap, bNoFree);
		}

		TypeValue *Data(TypeValue *Pointer, FSize SizeData, FSize SizeBuffer = 0, FBoolean bHeap = True, FBoolean bNoFree = True)
		{
			FBoolean bFree = _bHeap && _bClearDataOnReplace && _Data;

			if (bFree) { free(_Data); }
			if (SizeBuffer < SizeData) { SizeBuffer = SizeData; }
			_Size = SizeData;
			_BufferSize = SizeBuffer;
			_Data = Pointer;
			_bHeap = bHeap;
			if (bNoFree) { _bClearDataOnReplace = _bClearDataOnDestroy = !bNoFree; }
			return _Data;
		}

		const FDescriptor Descriptor() const
		{
			FDescriptor _Descriptor;

			_Descriptor.Type = None;
			_Descriptor.SizeOf = sizeof(TypeValue);
			_Descriptor.Size = _Size;
			_Descriptor._Size = _BufferSize;
			_Descriptor.N = 0;
			_Descriptor.bHeap = _bHeap;
			_Descriptor.Bytes = (FByte *) _Data;
			_Descriptor.Offset = 0;
			_Descriptor.Stride = 0;
			return _Descriptor;
		}

		TypeValue & operator[](FSize Index)
		{
			return _Data[Index];
		}

		const TypeValue & operator[](FSize Index) const
		{
			return _Data[Index];
		}

		FVoid Reserve(FSize ReserveSize, FBoolean bSetSizeToReserveSize = False)
		{
			FPointer Pointer;
			FBoolean bFaildResize;

			Pointer = realloc(_Data, ReserveSize * sizeof(TypeValue));
			bFaildResize = _Data && !Pointer && ReserveSize;
			if (bFaildResize) { exit(Failure); }
			if (_bHeap)
			{
				_bHeap = True;
				_bClearDataOnDestroy = True;
			}
			_Data = (TypeValue *) Pointer;
			if (bSetSizeToReserveSize) { _Size = ReserveSize; }
			_BufferSize = ReserveSize;
			if (ReserveSize < _Size) { _Size = ReserveSize; }
		}

		TypeValue * begin()
		{
			return _Data;
		}

		const TypeValue * begin() const
		{
			return _Data;
		}

		TypeValue * end()
		{
			if (!_Data) { return NullPtr; }
			return _Data + (_bIterateAll ? _BufferSize : _Size);
		}

		const TypeValue * end() const
		{
			if (!_Data) { return NullPtr; }
			return _Data + (_bIterateAll ? _BufferSize : _Size);
		}

		static TData<TypeValue> Like()
		{
			TData<TypeValue> Result;
			return Result;
		}
	};



}