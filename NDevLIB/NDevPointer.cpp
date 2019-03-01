#include "stdafx.h"
#include "NDevPointer.h"

using namespace NDev;
using namespace NDev::Types;

TList<_FPointer::FEntry> _FPointer::_List = TList<_FPointer::FEntry>();
_FPointer::FEntry *_FPointer::_Next = NullPtr;

_FPointer::_FPointer()
{
	_Entry = _Next ? _Next : &_List.New();
	auto Entry = *_Entry;
	_Next = Entry._Next;
	Entry.Pointer = this;
}

_FPointer::~_FPointer()
{
	auto Entry = *_Entry;
	Entry._Next = _Next;
	_Next = _Entry;
}

