#pragma once

#include "NDevTypes.h"
#include "NDevDefinitions.h"

namespace NDev
{
	using namespace Types;
	
    template<typename ... TypeAttributes>
    struct TRecord
	{
		template<typename ... Types>
		struct _TInfo
		{
			static const FSize Size = sizeof ... (TypeAttributes);
			static const FSize SizeOf = (... + sizeof(Types));
		};

		using _FInfo = _TInfo<TypeAttributes...>;

		FByte _Data[_FInfo::SizeOf];
		

		FSize Size()
		{
			return _FInfo::Size;
		}

		const FSize Size() const
		{
			return _FInfo::Size;
		}

		FSize SizeOf()
		{
			return _FInfo::SizeOf;
		}

		const FSize SizeOf() const
		{
			return _FInfo::SizeOf;
		}

		const FDescriptor Descriptor() const
		{
			FDescriptor _Descriptor;

			_Descriptor.Type = None;
			_Descriptor.SizeOf = _FInfo::SizeOf;
			_Descriptor.Size = 1;
			_Descriptor._Size = 1;
			_Descriptor.N = 0;
			_Descriptor.bHeap = False;
			_Descriptor.Bytes = (FByte*)&_Data[0];
			_Descriptor.Offset = 0;
			_Descriptor.Stride = 0;
			return _Descriptor;
		}

    };
	
}