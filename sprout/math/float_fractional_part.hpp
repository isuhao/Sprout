#ifndef SPROUT_MATH_FLOAT_FRACTIONAL_PART_HPP
#define SPROUT_MATH_FLOAT_FRACTIONAL_PART_HPP

#include <type_traits>
#include <sprout/config.hpp>
#include <sprout/math/detail/config.hpp>
#include <sprout/math/float_integer_part.hpp>
#include <sprout/type_traits/enabler_if.hpp>

namespace sprout {
	namespace math {
		namespace detail {
			template<
				typename FloatType,
				typename sprout::enabler_if<std::is_floating_point<FloatType>::value>::type = sprout::enabler
			>
			inline SPROUT_CONSTEXPR FloatType
			float_fractional_part(FloatType x) {
				return x - sprout::math::float_integer_part(x);
			}

			template<
				typename IntType,
				typename sprout::enabler_if<std::is_integral<IntType>::value>::type = sprout::enabler
			>
			inline SPROUT_CONSTEXPR double
			float_fractional_part(IntType x) {
				return sprout::math::detail::float_fractional_part(static_cast<double>(x));
			}
		}	// namespace detail

		using sprout::math::detail::float_fractional_part;
	}	// namespace math

	using sprout::math::float_fractional_part;
}	// namespace sprout

#endif	// #ifndef SPROUT_MATH_FLOAT_FRACTIONAL_PART_HPP
