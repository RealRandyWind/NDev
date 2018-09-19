#pragma once

#include "NDevTypes.h"
#include "NDevDefinitions.h"

namespace NDev
{
	using namespace Types;
	
	template<typename TypeData>
	struct TSequence
	{
		FSize _Size, _BufferSize, _ActiveIndex, _LastIndex, _IncrementSize;
		FBoolean _bIterateAll, _bClearDataOnDestroy, _bClearDataOnReplace, _bFixedSize, _bResizeOnAccess, _bSizeOnAccess, _bHeap;
		TypeData *_Data;

		TSequence()
		{
			_IncrementSize = 64;
			_Size = _BufferSize = 0;
			_ActiveIndex = _LastIndex = 0;
			_bIterateAll = False;
			_bClearDataOnDestroy = True;
			_bClearDataOnReplace = _bClearDataOnDestroy;
			_bFixedSize = False;
			_bResizeOnAccess = True;
			_bSizeOnAccess = False;
			_bHeap = True;
			_Data = NullPtr;
		}

		TSequence(FSize ReserveSize, FBoolean bSetSizeToReserveSize = False) : TSequence()
		{
			Reserve(ReserveSize, bSetSizeToReserveSize);
		}

		~TSequence()
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

		FVoid FixedSize(FBoolean bTrue = True)
		{
			_bFixedSize = bTrue;
		}

		FVoid ResizeOnAccess(FBoolean bTrue = True)
		{
			_bResizeOnAccess = bTrue;
		}

		FVoid SizeOnAccess(FBoolean bTrue = True)
		{
			_bSizeOnAccess = bTrue;
		}
		
		FVoid Reset()
		{
			_Size = _ActiveIndex = _LastIndex = 0;
		}

		FVoid Add(TypeData Rhs)
		{
			FBoolean bResize = !_bFixedSize && _Size >= _BufferSize;

			if (bResize) { Reserve(_Size + _IncrementSize); }
			_Data[_Size] = Rhs;
			++_Size;
		}

		FVoid Swap(TypeData Rhs)
		{
			if (_Size < _BufferSize)
			{
				++_Size;
			}

			++_ActiveIndex;
			if (_ActiveIndex >= _BufferSize)
			{
				_ActiveIndex = 0;
			}

			_Data[_ActiveIndex] = Rhs;
		}

		TypeData & Active()
		{
			return _Data[_ActiveIndex];
		}

		const TypeData & Active() const
		{
			return _Data[_ActiveIndex];
		}

		TypeData & Last()
		{
			return _Data[_LastIndex];
		}

		const TypeData & Last() const
		{
			return _Data[_LastIndex];
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
			return sizeof(TypeData) * _Size;
		}

		const FSize SizeOf() const
		{
			return sizeof(TypeData) * _Size;
		}

		FSize BufferSizeOf()
		{
			return sizeof(TypeData) * _BufferSize;
		}

		const FSize BufferSizeOf() const
		{
			return sizeof(TypeData) * _BufferSize;
		}

		FByte * Bytes()
		{
			return (FByte *) &_Data[0];
		}

		const FByte * Bytes() const
		{
			return (FByte *) &_Data[0];
		}

		TypeData * Data()
		{
			return &_Data[0];
		}

		const TypeData * Data() const
		{
			return &_Data[0];
		}

		TypeData *Data(const FDescriptor Descriptor, FBoolean bNoFree = True)
		{
			return Data((TypeData *) Descriptor.Pointer, Descriptor.Size, Descriptor._Size, Descriptor.bHeap, bNoFree);
		}

		TypeData *Data(TypeData *Pointer, FSize SizeData, FSize SizeBuffer = 0, FBoolean bHeap = True, FBoolean bNoFree = True)
		{
			FBoolean bFree = _bHeap && _bClearDataOnReplace && _Data;

			if (bFree) { free(_Data); }
			if (SizeBuffer < SizeData) { SizeBuffer = SizeData; }
			_Size = SizeData;
			_BufferSize = SizeBuffer;
			_Data = Pointer;
			_bHeap = bHeap;
			if(bNoFree) { _bClearDataOnReplace = _bClearDataOnDestroy = !bNoFree; }
			return &_Data[0];
		}

		const FDescriptor Descriptor() const
		{
			FDescriptor _Descriptor;

			_Descriptor.Type = None;
			_Descriptor.SizeOf = sizeof(TypeData);
			_Descriptor.Size = _Size;
			_Descriptor._Size = _BufferSize;
			_Descriptor.bHeap = _bHeap;
			_Descriptor.Pointer = (FPointer)&_Data[0];
			_Descriptor.Offset = 0;
			_Descriptor.Stride = 0;
			return _Descriptor;
		}

		TypeData & operator[](FSize Index)
		{
			FBoolean bResize = !_bFixedSize && _bResizeOnAccess && _BufferSize <= Index;
			FBoolean bSize = _bSizeOnAccess && Index >= _Size;

			if (bResize) { Reserve(Index + _IncrementSize); }
			if (bSize) { _Size = Index + 1; }
			_LastIndex = Index;
			return _Data[Index];
		}

		const TypeData & operator[](FSize Index) const
		{
			if (Index >= _Size) { exit(Failure); }
			return _Data[Index];
		}

		FVoid Reserve(FSize ReserveSize, FBoolean bSetSizeToReserveSize = False)
		{
			FPointer Pointer;
			FBoolean bFaildResize;

			Pointer = realloc(_Data, ReserveSize * sizeof(TypeData));
			bFaildResize = _Data && !Pointer && ReserveSize;
			if (bFaildResize) { exit(Failure); }
			if (_bHeap)
			{
				_bHeap = True;
				_bClearDataOnDestroy = True;
			}
			_Data = (TypeData *) Pointer;
			if (bSetSizeToReserveSize) { _Size = ReserveSize; }
			_BufferSize = ReserveSize;
			if (ReserveSize < _Size) { _Size = ReserveSize; }
		}

		TypeData * begin()
		{
			return &_Data[0];
		}

		const TypeData * begin() const
		{
			return &_Data[0];
		}

		TypeData * end()
		{
			return _bIterateAll ? &_Data[_BufferSize] : &_Data[_Size];
		}

		const TypeData * end() const
		{
			return _bIterateAll ? &_Data[_BufferSize] : &_Data[_Size];
		}


	};



}