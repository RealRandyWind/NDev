#pragma once

#include <stdlib.h>
#include <inttypes.h>
#include <chrono>
#include <functional>

namespace NDev
{
	namespace Types
	{
		template<typename TypeSignature>
		using TFunction = std::function<TypeSignature>;

		using FVoid = void;

		using FNone = void;

		using FBoolean = bool;

		using FCharacter = char;

		using FString = char *;

		using FPointer = void *;

		using FSize = size_t;

		using FReal = double;

		using FRaw = uint8_t;

		using FBlock = uint64_t;

		using FByte = char;

		using FInteger = int;

		using FEnum = size_t;

		using FClock = std::chrono::high_resolution_clock;

		using FTime = FClock::time_point;

		using FDuration = FClock::duration;

		using FReturn = decltype(EXIT_SUCCESS);

		const size_t ByteSize = 8;
		const decltype("") NullStr = "";
		const decltype('\0') NullChr = '\0';
		const decltype(nullptr) NullPtr = nullptr;
		const decltype(nullptr) Null = nullptr;
		const decltype(0) None = 0;
		const decltype(0) Unknown = 0;
		const decltype(EXIT_SUCCESS) Success = EXIT_SUCCESS;
		const decltype(EXIT_FAILURE) Failure = EXIT_FAILURE;
		const decltype(false) False = false;
		const decltype(true) True = true;


		
	}



}