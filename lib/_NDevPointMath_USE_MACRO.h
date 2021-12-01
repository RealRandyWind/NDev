#define USE_POINT_OPERATORS(__TYPE__, __FIELD__)\
	\
	template<FSize SizeLhs, typename TypeLhs>\
	operator TPoint<SizeLhs, TypeLhs>(){ TPoint<SizeLhs, TypeLhs> Lhs; return (Lhs = __FIELD__); }\
	\
	template<typename TypeRhs>\
	__TYPE__ & operator=(const TypeRhs& Rhs) { return (__FIELD__ = Rhs); }\
	\
	template<typename TypeRhs>\
	__TYPE__& operator=(const TypeRhs& Rhs) { return (__FIELD__ = Rhs); }\
	\
	template<FSize SizeRhs, typename TypRhs>\
	__TYPE__ & operator=(const TPoint<SizeRhs, TypRhs> &Rhs) { return (__FIELD__ = Rhs); }\
	\
	static __TYPE__ Like() { __TYPE__ Result; return Result; }\
	