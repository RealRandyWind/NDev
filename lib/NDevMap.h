#pragma once

#include "NDevTypes.h"
#include "NDevDefinitions.h"

namespace NDev
{
	using namespace Types;
	
	template<typename TypeKeys, typename TypeData>
	struct TMap
	{

		FSize _Size, _BufferSize, _RecentIndex, _IncrementSize;
		FBoolean _bIterateAll, _bClearDataOnDestroy, _bClearDataOnReplace, _bFixedSize, _bResizeOnAccess, _bSizeOnAccess, _bHeap;
		TypeKeys *_Keys;
		TypeData *_Data;

		TMap()
		{
			_IncrementSize = 64;
			_Size = _BufferSize = 0;
			_RecentIndex = 0;
			_bIterateAll = False;
			_bClearDataOnDestroy = True;
			_bClearDataOnReplace = _bClearDataOnDestroy;
			_bFixedSize = False;
			_bResizeOnAccess = True;
			_bSizeOnAccess = False;
			_bHeap = True;
			_Data = NullPtr;
		}

		TMap(FSize ReserveSize, FBoolean bSetSizeToReserveSize = False) : TMap()
		{
			Reserve(ReserveSize, bSetSizeToReserveSize);
		}

		~TMap()
		{
			FBoolean bFree = _bHeap && _bClearDataOnDestroy && _Data;

			if (bFree) { _Remove(_Data); }
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
		
		virtual FVoid Reset()
		{
			_Size = _RecentIndex = 0;
		}

		TypeData & Recent()
		{
			return _Data[_RecentIndex];
		}

		const TypeData & Recent() const
		{
			return _Data[_RecentIndex];
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
			return (FByte *) _Data;
		}

		const FByte * Bytes() const
		{
			return (FByte *) _Data;
		}

		TypeData * Data()
		{
			return _Data;
		}

		const TypeData * Data() const
		{
			return _Data;
		}

		TypeData *Data(const FDescriptor Descriptor, FBoolean bNoFree = True)
		{
			return Data((TypeData *) Descriptor.Pointer, Descriptor.Size, Descriptor._Size, Descriptor.bHeap, bNoFree);
		}

		TypeData *Data(TypeData *Pointer, FSize SizeData, FSize SizeBuffer = 0, FBoolean bHeap = True, FBoolean bNoFree = True)
		{
			FBoolean bFree = _bHeap && _bClearDataOnReplace && _Data;

			if (bFree) { _Remove(_Data); }
			if (SizeBuffer < SizeData) { SizeBuffer = SizeData; }
			_Size = SizeData;
			_BufferSize = SizeBuffer;
			_Data = Pointer;
			_bHeap = bHeap;
			if(bNoFree) { _bClearDataOnReplace = _bClearDataOnDestroy = !bNoFree; }
			return _Data;
		}

		const FDescriptor Descriptor() const
		{
			FDescriptor _Descriptor;

			_Descriptor.Type = None;
			_Descriptor.SizeOf = sizeof(TypeData);
			_Descriptor.Size = _Size;
			_Descriptor._Size = _BufferSize;
			_Descriptor.bHeap = _bHeap;
			_Descriptor.Bytes = (FByte *) _Data;
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
			_RecentIndex = Index;
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
			return _Data;
		}

		const TypeData * begin() const
		{
			return _Data;
		}

		TypeData * end()
		{
			if (!_Data) { return NullPtr;  }
			return _Data + (_bIterateAll ? _BufferSize : _Size);
		}

		const TypeData * end() const
		{
			if (!_Data) { return NullPtr; }
			return _Data + (_bIterateAll ? _BufferSize : _Size);
		}


	};



}