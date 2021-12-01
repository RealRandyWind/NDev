#pragma once

#include "NDevTypes.h"

namespace NDev
{
	using namespace Types;

	template<typename Type>
	struct TConstant
	{
		static Type Pi() { return 3.141592653589793238462643383279502884L; }

		static Type Pi2() { return 6.283185307179586476925286766559005768L; }

		static Type Pi3() { return 9.42477796076937971538793014983850865L; }

		static Type PiSquar() { return 9.869604401089358618834490999876151135L; }

		static Type PiCube() { return 31.006276680299820175476315067101395202L; }

		static Type PiTess() { return 9.8696044010893586188344909998761511353L; }

		static Type ByPi() { return 0.31830988618379067153776752674502872L; }

		static Type PiBy2() { return 1.57079632679489661923132169163975144L; }

		static Type PiBy3() { return 0.954929658551372014613302580235086172L; }

		static Type LnPi() { return 1.1447298858494001741434273513530587116L; }

		static Type SqrtPi() { return 1.77245385090551602729816748334114518279L; }

		static Type CbrtPi() { return 1.46459188756152326302014252726379039173L; }

		static Type TsrtPi() { return 1.3313353638003897127975349179502808533L; }

		static Type Phi() { return 1.61803398874989484820458683436563811772L; }

		static Type Phi2() { return 3.23606797749978969640917366873127623544L; }

		static Type Phi3() { return 4.8541019662496845446137605030969143531609L; }

		static Type PhiSquar() { return 2.61803398874989484820458683436563811772L; }

		static Type PhiCube() { return 4.23606797749978969640917366873127623544L; }

		static Type PhiTess() { return 2.61803398874989484820458683436563811772L; }

		static Type ByPhi() { return 0.61803398874989484820458683436563811772L; }

		static Type PhiBy2() { return 0.80901699437494742410229341718281905886L; }

		static Type PhiBy3() { return 0.539344662916631616068195611455212705906L; }

		static Type LnPhi() { return 0.48121182505960344749775891342436842313518L; }

		static Type SqrtPhi() { return 1.27201964951406896425242246173749149L; }

		static Type CbrtPhi() { return 1.173984996705328509966683971886266741955L; }

		static Type TsrtPhi() { return 1.12783848556168226026483548317704245843L; }

		static Type E() { return 2.718281828459045235360287471352662497757247L; }

		static Type E2() { return 5.436563656918090470720574942705324995514494L; }

		static Type E3() { return 8.154845485377135706080862414057987493271741L; }

		static Type ESquare() { return 7.38905609893065022723042746057500781318L; }

		static Type ECube() { return 20.085536923187667740928529654581717896987L; }

		static Type ETess() { return 2.718281828459045235360287471352662497757247L; }

		static Type ByE() { return 0.36787944117144232159552377016146086744581L; }

		static Type EBy2() { return 1.3591409142295226176801437356763312488786L; }

		static Type EBy3() { return 0.90609394281968174512009582378422083258574L; }

		static Type LnE() { return 1.0L; }

		static Type SqrtE() { return 1.6487212707001281468486507878141635716537761L; }

		static Type CbrtE() { return 1.3956124250860895286281253196025868375979065L; }

		static Type TsrtE() { return 1.2840254166877414840734205680624364583362808L; }

		static Type Sqrt2() { return 1.41421356237309504880168872420969807856967L; }

		static Type BySqrt2() { return 0.70710678118654752440084436210484903928L; }

		static Type Sqrt3() { return 1.7320508075688772935274463415058723669428L; }

		static Type BySqrt3() { return 0.5773502691896257645091487805019574556476L; }

		static Type Cbrt2() { return 1.259921049894873164767210607278228350570251L; }

		static Type ByCbrt2() { return 0.7937005259840997373758528196361541301957L; }

		static Type Cbrt3() { return 1.4422495703074083823216383107801095883918692L; }

		static Type ByCbrt3() { return 0.693361274350634704843352274785961795445935L; }

		static Type Tsrt2() { return 1.18920711500272106671749997056047591529297209L; }

		static Type ByTsrt2() { return 0.840896415253714543031125476233214895040034262L; }

		static Type Tsrt3() { return 1.31607401295249246081921890179699905516006859020L; }

		static Type ByTsrt3() { return 0.759835685651592547331187750654545335396773448L; }


	};


	namespace Constants
	{
		const FReal Pi = TConstant<FReal>::Pi();

		const FReal Pi2 = TConstant<FReal>::Pi2();

		const FReal Pi3 = TConstant<FReal>::Pi3();

		const FReal PiSquar = TConstant<FReal>::PiSquar();

		const FReal PiCube = TConstant<FReal>::PiCube();

		const FReal PiTess = TConstant<FReal>::PiTess();

		const FReal ByPi = TConstant<FReal>::ByPi();

		const FReal PiBy2 = TConstant<FReal>::PiBy2();

		const FReal PiBy3 = TConstant<FReal>::PiBy3();

		const FReal LnPi = TConstant<FReal>::LnPi();

		const FReal SqrtPi = TConstant<FReal>::SqrtPi();

		const FReal CbrtPi = TConstant<FReal>::CbrtPi();

		const FReal TsrtPi = TConstant<FReal>::TsrtPi();

		const FReal Phi = TConstant<FReal>::Phi();

		const FReal Phi2 = TConstant<FReal>::Phi2();

		const FReal Phi3 = TConstant<FReal>::Phi3();

		const FReal PhiSquar = TConstant<FReal>::PhiSquar();

		const FReal PhiCube = TConstant<FReal>::PhiCube();

		const FReal PhiTess = TConstant<FReal>::PhiTess();

		const FReal ByPhi = TConstant<FReal>::ByPhi();

		const FReal PhiBy2 = TConstant<FReal>::PhiBy2();

		const FReal PhiBy3 = TConstant<FReal>::PhiBy3();

		const FReal LnPhi = TConstant<FReal>::LnPhi();

		const FReal SqrtPhi = TConstant<FReal>::SqrtPhi();

		const FReal CbrtPhi = TConstant<FReal>::CbrtPhi();

		const FReal TsrtPhi = TConstant<FReal>::TsrtPhi();

		const FReal E = TConstant<FReal>::E();

		const FReal E2 = TConstant<FReal>::E2();

		const FReal E3 = TConstant<FReal>::E3();

		const FReal ESquare = TConstant<FReal>::ESquare();

		const FReal ECube = TConstant<FReal>::ECube();

		const FReal ETess = TConstant<FReal>::ETess();

		const FReal ByE = TConstant<FReal>::ByE();

		const FReal EBy2 = TConstant<FReal>::EBy2();

		const FReal EBy3 = TConstant<FReal>::EBy3();

		const FReal LnE = TConstant<FReal>::LnE();

		const FReal SqrtE = TConstant<FReal>::SqrtE();

		const FReal CbrtE = TConstant<FReal>::CbrtE();

		const FReal TsrtE = TConstant<FReal>::TsrtE();

		const FReal Sqrt2 = TConstant<FReal>::Sqrt2();

		const FReal BySqrt2 = TConstant<FReal>::BySqrt2();

		const FReal Sqrt3 = TConstant<FReal>::Sqrt3();

		const FReal BySqrt3 = TConstant<FReal>::BySqrt3();

		const FReal Cbrt2 = TConstant<FReal>::Cbrt2();

		const FReal ByCbrt2 = TConstant<FReal>::ByCbrt2();

		const FReal Cbrt3 = TConstant<FReal>::Cbrt3();

		const FReal ByCbrt3 = TConstant<FReal>::ByCbrt3();

		const FReal Tsrt2 = TConstant<FReal>::Tsrt2();

		const FReal ByTsrt2 = TConstant<FReal>::ByTsrt2();

		const FReal Tsrt3 = TConstant<FReal>::Tsrt3();

		const FReal ByTsrt3 = TConstant<FReal>::ByTsrt3();



	}



}