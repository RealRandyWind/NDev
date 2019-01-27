#include "stdafx.h"
#include "NDevResource.h"

using namespace NDev;



FSize FResource::_NextId = 0;
FSize FResource::_Count = 0;
TList<_FResource> FResource::_List = TList<_FResource>();

FResource::FResource()
{
	auto &Slot = _List[_NextId];
	_Id = _NextId;
	_NextId = Slot.Id;
	Slot.Id = _Id;
	Slot.Pointer = this;
	if (_Id >= _List.Size())
	{ 
		_List.Add(Slot);
		_NextId = _List.Size();
	}
	++_Count;
}

FResource::~FResource()
{
	--_Count;
	auto &Slot = _List[_Id];
	Slot.Pointer = NullPtr;
	Slot.Id = _NextId;
	_NextId = _Id;
}

FSize FResource::Id()
{
	return _Id;
}

const FSize FResource::Id() const
{
	return _Id;
}

FResource &FResource::Reference(FSize ResourceId)
{
	if (ResourceId >= _List.Size()) { exit(Failure); }
	auto Resource = _List[ResourceId].Pointer;
	if (!Resource) { exit(Failure); }
	return *Resource;
}

FResource *FResource::Pointer(FSize ResourceId)
{
	if (ResourceId >= _List.Size()) { return NullPtr; }
	return _List[ResourceId].Pointer;
}

FSize FResource::ResourceCount()
{
	return _Count;
}

FSize FResource::ResourceBufferSize()
{
	return _List.BufferSize();
}