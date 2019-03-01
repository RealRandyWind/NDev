#pragma once

#include "NDevTypes.h"
#include "NDevDefinitions.h"

namespace NDev
{
	using namespace Types;
	
	template<typename TypeValue>
	struct TSequence
	{
		using FValue = typename TypeValue;

		FSize _Size, _BufferSize, _RecentIndex, _IncrementSize;
		FBoolean _bIterateAll, _bClearDataOnDestroy, _bClearDataOnReplace, _bFixedSize, _bResizeOnAccess, _bSizeOnAccess, _bHeap;
		TypeValue *_Data;

		TSequence()
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

		TSequence(FSize ReserveSize, FBoolean bSetSizeToReserveSize = False, FBoolean bFill = False) : TSequence()
		{
			Reserve(ReserveSize, bSetSizeToReserveSize, bFill);
		}

		~TSequence()
		{
			FBoolean bFree = _bHeap && _bClearDataOnDestroy && _Data;

			if (bFree) { Remove(_Data); }
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

		TypeValue & Recent()
		{
			return _Data[_RecentIndex];
		}

		const TypeValue & Recent() const
		{
			return _Data[_RecentIndex];
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
			return Data((TypeValue *) Descriptor.Pointer, Descriptor.Size, Descriptor._Size, Descriptor.bHeap, bNoFree);
		}

		TypeValue *Data(TypeValue *Pointer, FSize SizeData, FSize SizeBuffer = 0, FBoolean bHeap = True, FBoolean bNoFree = True)
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
			_Descriptor.SizeOf = sizeof(TypeValue);
			_Descriptor.Size = _Size;
			_Descriptor._Size = _BufferSize;
			_Descriptor.bHeap = _bHeap;
			_Descriptor.Bytes = (FByte *) _Data;
			_Descriptor.Offset = 0;
			_Descriptor.Stride = 0;
			return _Descriptor;
		}

		TypeValue & operator[](FSize Index)
		{
			FBoolean bResize = !_bFixedSize && _bResizeOnAccess && _BufferSize <= Index;
			FBoolean bSize = _bSizeOnAccess && Index >= _Size;

			if (bResize) { Reserve(Index + _IncrementSize); }
			if (bSize) { _Size = Index + 1; }
			_RecentIndex = Index;
			return _Data[Index];
		}

		const TypeValue & operator[](FSize Index) const
		{
			if (Index >= _Size) { exit(Failure); }
			return _Data[Index];
		}

		FVoid Reserve(FSize ReserveSize, FBoolean bSetSizeToReserveSize = False, FBoolean bFill = False)
		{
			_Data = ResizeNull(_Data, ReserveSize);
			if (!_bHeap)
			{
				_bHeap = True;
				_bClearDataOnDestroy = True;
			}
			if (bSetSizeToReserveSize) { _Size = ReserveSize; }
			_BufferSize = ReserveSize;
			if (ReserveSize < _Size) { _Size = ReserveSize; }
			if (bFill) { Fill(); }
		}

		FVoid Fill(const TypeValue Value = TypeValue(), FBoolean bFillAll = True)
		{
			FSize Index, End;

			End = bFillAll ? _BufferSize : _Size;
			for (Index = 0; Index < End; ++Index) { _Data[Index] = Value; }
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
			if (!_Data) { return NullPtr;  }
			return _Data + (_bIterateAll ? _BufferSize : _Size);
		}

		const TypeValue * end() const
		{
			if (!_Data) { return NullPtr; }
			return _Data + (_bIterateAll ? _BufferSize : _Size);
		}

		static TSequence<TypeValue> Like()
		{
			TSequence<TypeValue> Result;
			return Result;
		}

		static TypeValue Item()
		{
			return TypeValue();
		}
	};



}