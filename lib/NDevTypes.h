#pragma once

#include <stdlib.h>
#include <inttypes.h>
#include <chrono>
#include <iostream>
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

		using FString = FCharacter *;

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

		using FFile = std::fstream;
		
		using FOut = std::ostream;

		using FIn = std::istream;

		static const size_t BlockSize = 64;
		static const size_t ByteSize = 8;
		static const decltype("") NullStr = "";
		static const decltype('\0') NullChr = '\0';
		static const decltype(nullptr) NullPtr = nullptr;
		static const decltype(nullptr) Null = nullptr;
		static const decltype(0) None = 0;
		static const decltype(0) Unknown = 0;
		static const decltype(EXIT_SUCCESS) Success = EXIT_SUCCESS;
		static const decltype(EXIT_FAILURE) Failure = EXIT_FAILURE;
		static const decltype(false) False = false;
		static const decltype(true) True = true;

		static decltype(std::cin) &InStream = std::cin;
		static decltype(std::cout) &OutStream = std::cout;
		static decltype(std::clog) &LogStream = std::clog;
		static decltype(std::cerr) &ErrorStream = std::cerr;

	}



}