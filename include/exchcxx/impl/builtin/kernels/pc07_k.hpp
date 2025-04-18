#pragma once
#include <cmath>

#include <exchcxx/impl/builtin/fwd.hpp>
#include <exchcxx/impl/builtin/constants.hpp>
#include <exchcxx/impl/builtin/kernel_type.hpp>
#include <exchcxx/impl/builtin/util.hpp>

#include <exchcxx/impl/builtin/kernels/screening_interface.hpp>



namespace ExchCXX {

template <>
struct kernel_traits< BuiltinPC07_K > :
  public mgga_screening_interface< BuiltinPC07_K > {

  static constexpr bool is_lda  = false;
  static constexpr bool is_gga  = false;
  static constexpr bool is_mgga = true;
  static constexpr bool needs_laplacian = true;
  static constexpr bool is_kedf = true;
  static constexpr bool is_epc  = false;

  static constexpr double dens_tol  = 1e-15;
  static constexpr double zeta_tol  = 1e-15;
  static constexpr double sigma_tol  = 1.0000000000000027e-20;
  static constexpr double tau_tol = is_kedf ? 0.0 : 1e-20;

  static constexpr bool is_hyb  = false;
  static constexpr double exx_coeff = 0.0;

  static constexpr double a = 0.5389;
  static constexpr double b = 3.0;

  BUILTIN_KERNEL_EVAL_RETURN
    eval_exc_unpolar_impl( double rho, double sigma, double lapl, double tau, double& eps ) {

    (void)(tau);
    (void)(eps);
    constexpr double t4 = constants::m_cbrt_3;
    constexpr double t6 = constants::m_cbrt_pi;
    constexpr double t25 = constants::m_cbrt_6;
    constexpr double t26 = constants::m_pi_sq;
    constexpr double t27 = constants::m_cbrt_pi_sq;
    constexpr double t31 = constants::m_cbrt_2;
    constexpr double t5 = t4 * t4;
    constexpr double t28 = t27 * t27;
    constexpr double t29 = 0.1e1 / t28;
    constexpr double t30 = t25 * t29;
    constexpr double t32 = t31 * t31;
    constexpr double t47 = t25 * t25;
    constexpr double t49 = 0.1e1 / t27 / t26;
    constexpr double t50 = t47 * t49;
    constexpr double t87 = a / 0.4e2;
    constexpr double t89 = 0.39e2 / 0.4e2 * a;
    constexpr double t91 = a * b;


    const double t3 = rho / 0.2e1 <= dens_tol;
    const double t8 = t5 * t6 * M_PI;
    const double t9 = 0.1e1 <= zeta_tol;
    const double t10 = zeta_tol - 0.1e1;
    const double t12 = piecewise_functor_5( t9, t10, t9, -t10, 0.0 );
    const double t13 = 0.1e1 + t12;
    const double t15 = safe_math::cbrt( zeta_tol );
    const double t16 = t15 * t15;
    const double t18 = safe_math::cbrt( t13 );
    const double t19 = t18 * t18;
    const double t21 = piecewise_functor_3( t13 <= zeta_tol, t16 * zeta_tol, t19 * t13 );
    const double t22 = safe_math::cbrt( rho );
    const double t23 = t22 * t22;
    const double t24 = t21 * t23;
    const double t33 = sigma * t32;
    const double t34 = rho * rho;
    const double t36 = 0.1e1 / t23 / t34;
    const double t38 = t30 * t33 * t36;
    const double t39 = 0.5e1 / 0.72e2 * t38;
    const double t41 = lapl * t32;
    const double t43 = 0.1e1 / t23 / rho;
    const double t51 = lapl * lapl;
    const double t52 = t51 * t31;
    const double t53 = t34 * rho;
    const double t55 = 0.1e1 / t22 / t53;
    const double t58 = t50 * t52 * t55 / 0.2916e4;
    const double t59 = t50 * sigma;
    const double t60 = t34 * t34;
    const double t62 = 0.1e1 / t22 / t60;
    const double t63 = t31 * t62;
    const double t64 = t63 * lapl;
    const double t66 = t59 * t64 / 0.2592e4;
    const double t67 = sigma * sigma;
    const double t68 = t67 * t31;
    const double t69 = t60 * rho;
    const double t71 = 0.1e1 / t22 / t69;
    const double t74 = t50 * t68 * t71 / 0.8748e4;
    const double t75 = 0.1e1 + 0.5e1 / 0.648e3 * t38 + 0.5e1 / 0.54e2 * t30 * t41 * t43 + t58 - t66 + t74;
    const double t76 = t58 - t66 + t74;
    const double t77 = t76 * t76;
    const double t78 = 0.1e1 + t39;
    const double t79 = t78 * t78;
    const double t80 = 0.1e1 / t79;
    const double t82 = t77 * t80 + 0.1e1;
    const double t83 = safe_math::sqrt( t82 );
    const double t84 = 0.1e1 / t83;
    const double t86 = t75 * t84 - t39;
    const double t88 = t86 <= t87;
    const double t90 = t89 <= t86;
    const double t92 = t86 < t87;
    const double t93 = piecewise_functor_3( t92, t87, t86 );
    const double t94 = t93 < t89;
    const double t95 = piecewise_functor_3( t94, t93, t89 );
    const double t96 = 0.1e1 / t95;
    const double t98 = safe_math::exp( -t91 * t96 );
    const double t99 = a - t95;
    const double t102 = safe_math::exp( -a / t99 );
    const double t103 = 0.1e1 + t102;
    const double t104 = safe_math::pow( t103, b );
    const double t105 = t98 * t104;
    const double t107 = safe_math::exp( -a * t96 );
    const double t108 = t107 + t102;
    const double t109 = safe_math::pow( t108, b );
    const double t110 = 0.1e1 / t109;
    const double t111 = t105 * t110;
    const double t112 = piecewise_functor_5( t88, 0.0, t90, 1.0, t111 );
    const double t114 = t86 * t112 + t39;
    const double t118 = piecewise_functor_3( t3, 0.0, 0.3e1 / 0.2e2 * t8 * t24 * t114 );


    eps = 0.2e1 * t118;

  }

  BUILTIN_KERNEL_EVAL_RETURN
    eval_exc_vxc_unpolar_impl( double rho, double sigma, double lapl, double tau, double& eps, double& vrho, double& vsigma, double& vlapl, double& vtau ) {

    (void)(tau);
    (void)(eps);
    constexpr double t4 = constants::m_cbrt_3;
    constexpr double t6 = constants::m_cbrt_pi;
    constexpr double t25 = constants::m_cbrt_6;
    constexpr double t26 = constants::m_pi_sq;
    constexpr double t27 = constants::m_cbrt_pi_sq;
    constexpr double t31 = constants::m_cbrt_2;
    constexpr double t5 = t4 * t4;
    constexpr double t28 = t27 * t27;
    constexpr double t29 = 0.1e1 / t28;
    constexpr double t30 = t25 * t29;
    constexpr double t32 = t31 * t31;
    constexpr double t47 = t25 * t25;
    constexpr double t49 = 0.1e1 / t27 / t26;
    constexpr double t50 = t47 * t49;
    constexpr double t87 = a / 0.4e2;
    constexpr double t89 = 0.39e2 / 0.4e2 * a;
    constexpr double t91 = a * b;
    constexpr double t224 = t29 * t32;


    const double t3 = rho / 0.2e1 <= dens_tol;
    const double t8 = t5 * t6 * M_PI;
    const double t9 = 0.1e1 <= zeta_tol;
    const double t10 = zeta_tol - 0.1e1;
    const double t12 = piecewise_functor_5( t9, t10, t9, -t10, 0.0 );
    const double t13 = 0.1e1 + t12;
    const double t15 = safe_math::cbrt( zeta_tol );
    const double t16 = t15 * t15;
    const double t18 = safe_math::cbrt( t13 );
    const double t19 = t18 * t18;
    const double t21 = piecewise_functor_3( t13 <= zeta_tol, t16 * zeta_tol, t19 * t13 );
    const double t22 = safe_math::cbrt( rho );
    const double t23 = t22 * t22;
    const double t24 = t21 * t23;
    const double t33 = sigma * t32;
    const double t34 = rho * rho;
    const double t36 = 0.1e1 / t23 / t34;
    const double t38 = t30 * t33 * t36;
    const double t39 = 0.5e1 / 0.72e2 * t38;
    const double t41 = lapl * t32;
    const double t43 = 0.1e1 / t23 / rho;
    const double t51 = lapl * lapl;
    const double t52 = t51 * t31;
    const double t53 = t34 * rho;
    const double t55 = 0.1e1 / t22 / t53;
    const double t58 = t50 * t52 * t55 / 0.2916e4;
    const double t59 = t50 * sigma;
    const double t60 = t34 * t34;
    const double t62 = 0.1e1 / t22 / t60;
    const double t63 = t31 * t62;
    const double t64 = t63 * lapl;
    const double t66 = t59 * t64 / 0.2592e4;
    const double t67 = sigma * sigma;
    const double t68 = t67 * t31;
    const double t69 = t60 * rho;
    const double t71 = 0.1e1 / t22 / t69;
    const double t74 = t50 * t68 * t71 / 0.8748e4;
    const double t75 = 0.1e1 + 0.5e1 / 0.648e3 * t38 + 0.5e1 / 0.54e2 * t30 * t41 * t43 + t58 - t66 + t74;
    const double t76 = t58 - t66 + t74;
    const double t77 = t76 * t76;
    const double t78 = 0.1e1 + t39;
    const double t79 = t78 * t78;
    const double t80 = 0.1e1 / t79;
    const double t82 = t77 * t80 + 0.1e1;
    const double t83 = safe_math::sqrt( t82 );
    const double t84 = 0.1e1 / t83;
    const double t86 = t75 * t84 - t39;
    const double t88 = t86 <= t87;
    const double t90 = t89 <= t86;
    const double t92 = t86 < t87;
    const double t93 = piecewise_functor_3( t92, t87, t86 );
    const double t94 = t93 < t89;
    const double t95 = piecewise_functor_3( t94, t93, t89 );
    const double t96 = 0.1e1 / t95;
    const double t98 = safe_math::exp( -t91 * t96 );
    const double t99 = a - t95;
    const double t102 = safe_math::exp( -a / t99 );
    const double t103 = 0.1e1 + t102;
    const double t104 = safe_math::pow( t103, b );
    const double t105 = t98 * t104;
    const double t107 = safe_math::exp( -a * t96 );
    const double t108 = t107 + t102;
    const double t109 = safe_math::pow( t108, b );
    const double t110 = 0.1e1 / t109;
    const double t111 = t105 * t110;
    const double t112 = piecewise_functor_5( t88, 0.0, t90, 1.0, t111 );
    const double t114 = t86 * t112 + t39;
    const double t118 = piecewise_functor_3( t3, 0.0, 0.3e1 / 0.2e2 * t8 * t24 * t114 );
    const double t120 = t21 / t22;
    const double t125 = 0.1e1 / t23 / t53;
    const double t126 = t33 * t125;
    const double t127 = t30 * t126;
    const double t128 = 0.5e1 / 0.27e2 * t127;
    const double t135 = 0.5e1 / 0.4374e4 * t50 * t52 * t62;
    const double t136 = t31 * t71;
    const double t137 = t136 * lapl;
    const double t139 = 0.13e2 / 0.7776e4 * t59 * t137;
    const double t140 = t60 * t34;
    const double t142 = 0.1e1 / t22 / t140;
    const double t145 = 0.4e1 / 0.6561e4 * t50 * t68 * t142;
    const double t146 = -0.5e1 / 0.243e3 * t127 - 0.25e2 / 0.162e3 * t30 * t41 * t36 - t135 + t139 - t145;
    const double t149 = 0.1e1 / t83 / t82;
    const double t150 = t75 * t149;
    const double t151 = t76 * t80;
    const double t152 = -t135 + t139 - t145;
    const double t155 = t79 * t78;
    const double t156 = 0.1e1 / t155;
    const double t158 = t77 * t156 * t25;
    const double t159 = t29 * sigma;
    const double t160 = t32 * t125;
    const double t161 = t159 * t160;
    const double t164 = 0.2e1 * t151 * t152 + 0.1e2 / 0.27e2 * t158 * t161;
    const double t167 = t146 * t84 - t150 * t164 / 0.2e1 + t128;
    const double t169 = t95 * t95;
    const double t170 = 0.1e1 / t169;
    const double t171 = t91 * t170;
    const double t172 = piecewise_functor_3( t92, 0.0, t167 );
    const double t173 = piecewise_functor_3( t94, t172, 0.0 );
    const double t174 = t173 * t98;
    const double t175 = t104 * t110;
    const double t176 = t174 * t175;
    const double t178 = t105 * t91;
    const double t179 = t99 * t99;
    const double t180 = 0.1e1 / t179;
    const double t181 = t180 * t173;
    const double t182 = 0.1e1 / t103;
    const double t184 = t102 * t182 * t110;
    const double t187 = a * t170;
    const double t188 = t173 * t107;
    const double t190 = a * t180;
    const double t191 = t173 * t102;
    const double t193 = t187 * t188 - t190 * t191;
    const double t195 = 0.1e1 / t108;
    const double t199 = piecewise_functor_5( t88, 0.0, t90, 0.0, -t111 * b * t193 * t195 - t178 * t181 * t184 + t171 * t176 );
    const double t201 = t167 * t112 + t86 * t199 - t128;
    const double t206 = piecewise_functor_3( t3, 0.0, t8 * t120 * t114 / 0.1e2 + 0.3e1 / 0.2e2 * t8 * t24 * t201 );
    const double t209 = t32 * t36;
    const double t210 = t30 * t209;
    const double t211 = 0.5e1 / 0.72e2 * t210;
    const double t213 = t50 * t64;
    const double t214 = t213 / 0.2592e4;
    const double t215 = sigma * t31;
    const double t217 = t50 * t215 * t71;
    const double t218 = t217 / 0.4374e4;
    const double t219 = 0.5e1 / 0.648e3 * t210 - t214 + t218;
    const double t221 = -t214 + t218;
    const double t225 = t224 * t36;
    const double t228 = 0.2e1 * t151 * t221 - 0.5e1 / 0.36e2 * t158 * t225;
    const double t231 = t219 * t84 - t150 * t228 / 0.2e1 - t211;
    const double t233 = piecewise_functor_3( t92, 0.0, t231 );
    const double t234 = piecewise_functor_3( t94, t233, 0.0 );
    const double t235 = t234 * t98;
    const double t236 = t235 * t175;
    const double t238 = t180 * t234;
    const double t241 = t234 * t107;
    const double t243 = t234 * t102;
    const double t245 = t187 * t241 - t190 * t243;
    const double t246 = b * t245;
    const double t250 = piecewise_functor_5( t88, 0.0, t90, 0.0, -t111 * t246 * t195 - t178 * t238 * t184 + t171 * t236 );
    const double t252 = t231 * t112 + t86 * t250 + t211;
    const double t256 = piecewise_functor_3( t3, 0.0, 0.3e1 / 0.2e2 * t8 * t24 * t252 );
    const double t264 = t50 * lapl * t31 * t55 / 0.1458e4;
    const double t267 = t50 * t215 * t62 / 0.2592e4;
    const double t268 = 0.5e1 / 0.54e2 * t30 * t32 * t43 + t264 - t267;
    const double t270 = t264 - t267;
    const double t271 = t151 * t270;
    const double t273 = -t150 * t271 + t268 * t84;
    const double t275 = piecewise_functor_3( t92, 0.0, t273 );
    const double t276 = piecewise_functor_3( t94, t275, 0.0 );
    const double t277 = t276 * t98;
    const double t278 = t277 * t175;
    const double t280 = t180 * t276;
    const double t283 = t276 * t107;
    const double t285 = t276 * t102;
    const double t287 = t187 * t283 - t190 * t285;
    const double t288 = b * t287;
    const double t292 = piecewise_functor_5( t88, 0.0, t90, 0.0, -t111 * t195 * t288 - t178 * t184 * t280 + t171 * t278 );
    const double t294 = t112 * t273 + t292 * t86;
    const double t298 = piecewise_functor_3( t3, 0.0, 0.3e1 / 0.2e2 * t8 * t24 * t294 );


    eps = 0.2e1 * t118;
    vrho = 0.2e1 * rho * t206 + 0.2e1 * t118;
    vsigma = 0.2e1 * rho * t256;
    vlapl = 0.2e1 * rho * t298;
    vtau = 0.e0;

  }

  BUILTIN_KERNEL_EVAL_RETURN
    eval_exc_polar_impl( double rho_a, double rho_b, double sigma_aa, double sigma_ab, double sigma_bb, double lapl_a, double lapl_b, double tau_a, double tau_b, double& eps ) {

    (void)(sigma_ab);
    (void)(tau_a);
    (void)(tau_b);
    (void)(eps);
    constexpr double t3 = constants::m_cbrt_3;
    constexpr double t5 = constants::m_cbrt_pi;
    constexpr double t33 = constants::m_cbrt_6;
    constexpr double t34 = constants::m_pi_sq;
    constexpr double t35 = constants::m_cbrt_pi_sq;
    constexpr double t4 = t3 * t3;
    constexpr double t36 = t35 * t35;
    constexpr double t37 = 0.1e1 / t36;
    constexpr double t38 = t33 * t37;
    constexpr double t53 = t33 * t33;
    constexpr double t55 = 0.1e1 / t35 / t34;
    constexpr double t56 = t53 * t55;
    constexpr double t90 = a / 0.4e2;
    constexpr double t92 = 0.39e2 / 0.4e2 * a;
    constexpr double t94 = a * b;


    const double t2 = rho_a <= dens_tol;
    const double t7 = t4 * t5 * M_PI;
    const double t8 = rho_a + rho_b;
    const double t9 = 0.1e1 / t8;
    const double t12 = 0.2e1 * rho_a * t9 <= zeta_tol;
    const double t13 = zeta_tol - 0.1e1;
    const double t16 = 0.2e1 * rho_b * t9 <= zeta_tol;
    const double t17 = -t13;
    const double t18 = rho_a - rho_b;
    const double t20 = piecewise_functor_5( t12, t13, t16, t17, t18 * t9 );
    const double t21 = 0.1e1 + t20;
    const double t22 = t21 <= zeta_tol;
    const double t23 = safe_math::cbrt( zeta_tol );
    const double t24 = t23 * t23;
    const double t25 = t24 * zeta_tol;
    const double t26 = safe_math::cbrt( t21 );
    const double t27 = t26 * t26;
    const double t29 = piecewise_functor_3( t22, t25, t27 * t21 );
    const double t30 = safe_math::cbrt( t8 );
    const double t31 = t30 * t30;
    const double t32 = t29 * t31;
    const double t39 = rho_a * rho_a;
    const double t40 = safe_math::cbrt( rho_a );
    const double t41 = t40 * t40;
    const double t43 = 0.1e1 / t41 / t39;
    const double t45 = t38 * sigma_aa * t43;
    const double t46 = 0.5e1 / 0.72e2 * t45;
    const double t49 = 0.1e1 / t41 / rho_a;
    const double t57 = lapl_a * lapl_a;
    const double t58 = t39 * rho_a;
    const double t60 = 0.1e1 / t40 / t58;
    const double t63 = t56 * t57 * t60 / 0.5832e4;
    const double t64 = t39 * t39;
    const double t66 = 0.1e1 / t40 / t64;
    const double t67 = sigma_aa * t66;
    const double t70 = t56 * t67 * lapl_a / 0.5184e4;
    const double t71 = sigma_aa * sigma_aa;
    const double t72 = t64 * rho_a;
    const double t74 = 0.1e1 / t40 / t72;
    const double t77 = t56 * t71 * t74 / 0.17496e5;
    const double t78 = 0.1e1 + 0.5e1 / 0.648e3 * t45 + 0.5e1 / 0.54e2 * t38 * lapl_a * t49 + t63 - t70 + t77;
    const double t79 = t63 - t70 + t77;
    const double t80 = t79 * t79;
    const double t81 = 0.1e1 + t46;
    const double t82 = t81 * t81;
    const double t83 = 0.1e1 / t82;
    const double t85 = t80 * t83 + 0.1e1;
    const double t86 = safe_math::sqrt( t85 );
    const double t87 = 0.1e1 / t86;
    const double t89 = t78 * t87 - t46;
    const double t91 = t89 <= t90;
    const double t93 = t92 <= t89;
    const double t95 = t89 < t90;
    const double t96 = piecewise_functor_3( t95, t90, t89 );
    const double t97 = t96 < t92;
    const double t98 = piecewise_functor_3( t97, t96, t92 );
    const double t99 = 0.1e1 / t98;
    const double t101 = safe_math::exp( -t94 * t99 );
    const double t102 = a - t98;
    const double t105 = safe_math::exp( -a / t102 );
    const double t106 = 0.1e1 + t105;
    const double t107 = safe_math::pow( t106, b );
    const double t108 = t101 * t107;
    const double t110 = safe_math::exp( -a * t99 );
    const double t111 = t110 + t105;
    const double t112 = safe_math::pow( t111, b );
    const double t113 = 0.1e1 / t112;
    const double t114 = t108 * t113;
    const double t115 = piecewise_functor_5( t91, 0.0, t93, 1.0, t114 );
    const double t117 = t89 * t115 + t46;
    const double t121 = piecewise_functor_3( t2, 0.0, 0.3e1 / 0.2e2 * t7 * t32 * t117 );
    const double t122 = rho_b <= dens_tol;
    const double t123 = -t18;
    const double t125 = piecewise_functor_5( t16, t13, t12, t17, t123 * t9 );
    const double t126 = 0.1e1 + t125;
    const double t127 = t126 <= zeta_tol;
    const double t128 = safe_math::cbrt( t126 );
    const double t129 = t128 * t128;
    const double t131 = piecewise_functor_3( t127, t25, t129 * t126 );
    const double t132 = t131 * t31;
    const double t133 = rho_b * rho_b;
    const double t134 = safe_math::cbrt( rho_b );
    const double t135 = t134 * t134;
    const double t137 = 0.1e1 / t135 / t133;
    const double t139 = t38 * sigma_bb * t137;
    const double t140 = 0.5e1 / 0.72e2 * t139;
    const double t143 = 0.1e1 / t135 / rho_b;
    const double t147 = lapl_b * lapl_b;
    const double t148 = t133 * rho_b;
    const double t150 = 0.1e1 / t134 / t148;
    const double t153 = t56 * t147 * t150 / 0.5832e4;
    const double t154 = t133 * t133;
    const double t156 = 0.1e1 / t134 / t154;
    const double t157 = sigma_bb * t156;
    const double t160 = t56 * t157 * lapl_b / 0.5184e4;
    const double t161 = sigma_bb * sigma_bb;
    const double t162 = t154 * rho_b;
    const double t164 = 0.1e1 / t134 / t162;
    const double t167 = t56 * t161 * t164 / 0.17496e5;
    const double t168 = 0.1e1 + 0.5e1 / 0.648e3 * t139 + 0.5e1 / 0.54e2 * t38 * lapl_b * t143 + t153 - t160 + t167;
    const double t169 = t153 - t160 + t167;
    const double t170 = t169 * t169;
    const double t171 = 0.1e1 + t140;
    const double t172 = t171 * t171;
    const double t173 = 0.1e1 / t172;
    const double t175 = t170 * t173 + 0.1e1;
    const double t176 = safe_math::sqrt( t175 );
    const double t177 = 0.1e1 / t176;
    const double t179 = t168 * t177 - t140;
    const double t180 = t179 <= t90;
    const double t181 = t92 <= t179;
    const double t182 = t179 < t90;
    const double t183 = piecewise_functor_3( t182, t90, t179 );
    const double t184 = t183 < t92;
    const double t185 = piecewise_functor_3( t184, t183, t92 );
    const double t186 = 0.1e1 / t185;
    const double t188 = safe_math::exp( -t94 * t186 );
    const double t189 = a - t185;
    const double t192 = safe_math::exp( -a / t189 );
    const double t193 = 0.1e1 + t192;
    const double t194 = safe_math::pow( t193, b );
    const double t195 = t188 * t194;
    const double t197 = safe_math::exp( -a * t186 );
    const double t198 = t197 + t192;
    const double t199 = safe_math::pow( t198, b );
    const double t200 = 0.1e1 / t199;
    const double t201 = t195 * t200;
    const double t202 = piecewise_functor_5( t180, 0.0, t181, 1.0, t201 );
    const double t204 = t179 * t202 + t140;
    const double t208 = piecewise_functor_3( t122, 0.0, 0.3e1 / 0.2e2 * t7 * t132 * t204 );


    eps = t121 + t208;

  }

  BUILTIN_KERNEL_EVAL_RETURN
    eval_exc_vxc_polar_impl( double rho_a, double rho_b, double sigma_aa, double sigma_ab, double sigma_bb, double lapl_a, double lapl_b, double tau_a, double tau_b, double& eps, double& vrho_a, double& vrho_b, double& vsigma_aa, double& vsigma_ab, double& vsigma_bb, double& vlapl_a, double& vlapl_b, double& vtau_a, double& vtau_b ) {

    (void)(sigma_ab);
    (void)(tau_a);
    (void)(tau_b);
    (void)(eps);
    constexpr double t3 = constants::m_cbrt_3;
    constexpr double t5 = constants::m_cbrt_pi;
    constexpr double t33 = constants::m_cbrt_6;
    constexpr double t34 = constants::m_pi_sq;
    constexpr double t35 = constants::m_cbrt_pi_sq;
    constexpr double t4 = t3 * t3;
    constexpr double t36 = t35 * t35;
    constexpr double t37 = 0.1e1 / t36;
    constexpr double t38 = t33 * t37;
    constexpr double t53 = t33 * t33;
    constexpr double t55 = 0.1e1 / t35 / t34;
    constexpr double t56 = t53 * t55;
    constexpr double t90 = a / 0.4e2;
    constexpr double t92 = 0.39e2 / 0.4e2 * a;
    constexpr double t94 = a * b;


    const double t2 = rho_a <= dens_tol;
    const double t7 = t4 * t5 * M_PI;
    const double t8 = rho_a + rho_b;
    const double t9 = 0.1e1 / t8;
    const double t12 = 0.2e1 * rho_a * t9 <= zeta_tol;
    const double t13 = zeta_tol - 0.1e1;
    const double t16 = 0.2e1 * rho_b * t9 <= zeta_tol;
    const double t17 = -t13;
    const double t18 = rho_a - rho_b;
    const double t20 = piecewise_functor_5( t12, t13, t16, t17, t18 * t9 );
    const double t21 = 0.1e1 + t20;
    const double t22 = t21 <= zeta_tol;
    const double t23 = safe_math::cbrt( zeta_tol );
    const double t24 = t23 * t23;
    const double t25 = t24 * zeta_tol;
    const double t26 = safe_math::cbrt( t21 );
    const double t27 = t26 * t26;
    const double t29 = piecewise_functor_3( t22, t25, t27 * t21 );
    const double t30 = safe_math::cbrt( t8 );
    const double t31 = t30 * t30;
    const double t32 = t29 * t31;
    const double t39 = rho_a * rho_a;
    const double t40 = safe_math::cbrt( rho_a );
    const double t41 = t40 * t40;
    const double t43 = 0.1e1 / t41 / t39;
    const double t45 = t38 * sigma_aa * t43;
    const double t46 = 0.5e1 / 0.72e2 * t45;
    const double t49 = 0.1e1 / t41 / rho_a;
    const double t57 = lapl_a * lapl_a;
    const double t58 = t39 * rho_a;
    const double t60 = 0.1e1 / t40 / t58;
    const double t63 = t56 * t57 * t60 / 0.5832e4;
    const double t64 = t39 * t39;
    const double t66 = 0.1e1 / t40 / t64;
    const double t67 = sigma_aa * t66;
    const double t70 = t56 * t67 * lapl_a / 0.5184e4;
    const double t71 = sigma_aa * sigma_aa;
    const double t72 = t64 * rho_a;
    const double t74 = 0.1e1 / t40 / t72;
    const double t77 = t56 * t71 * t74 / 0.17496e5;
    const double t78 = 0.1e1 + 0.5e1 / 0.648e3 * t45 + 0.5e1 / 0.54e2 * t38 * lapl_a * t49 + t63 - t70 + t77;
    const double t79 = t63 - t70 + t77;
    const double t80 = t79 * t79;
    const double t81 = 0.1e1 + t46;
    const double t82 = t81 * t81;
    const double t83 = 0.1e1 / t82;
    const double t85 = t80 * t83 + 0.1e1;
    const double t86 = safe_math::sqrt( t85 );
    const double t87 = 0.1e1 / t86;
    const double t89 = t78 * t87 - t46;
    const double t91 = t89 <= t90;
    const double t93 = t92 <= t89;
    const double t95 = t89 < t90;
    const double t96 = piecewise_functor_3( t95, t90, t89 );
    const double t97 = t96 < t92;
    const double t98 = piecewise_functor_3( t97, t96, t92 );
    const double t99 = 0.1e1 / t98;
    const double t101 = safe_math::exp( -t94 * t99 );
    const double t102 = a - t98;
    const double t105 = safe_math::exp( -a / t102 );
    const double t106 = 0.1e1 + t105;
    const double t107 = safe_math::pow( t106, b );
    const double t108 = t101 * t107;
    const double t110 = safe_math::exp( -a * t99 );
    const double t111 = t110 + t105;
    const double t112 = safe_math::pow( t111, b );
    const double t113 = 0.1e1 / t112;
    const double t114 = t108 * t113;
    const double t115 = piecewise_functor_5( t91, 0.0, t93, 1.0, t114 );
    const double t117 = t89 * t115 + t46;
    const double t121 = piecewise_functor_3( t2, 0.0, 0.3e1 / 0.2e2 * t7 * t32 * t117 );
    const double t122 = rho_b <= dens_tol;
    const double t123 = -t18;
    const double t125 = piecewise_functor_5( t16, t13, t12, t17, t123 * t9 );
    const double t126 = 0.1e1 + t125;
    const double t127 = t126 <= zeta_tol;
    const double t128 = safe_math::cbrt( t126 );
    const double t129 = t128 * t128;
    const double t131 = piecewise_functor_3( t127, t25, t129 * t126 );
    const double t132 = t131 * t31;
    const double t133 = rho_b * rho_b;
    const double t134 = safe_math::cbrt( rho_b );
    const double t135 = t134 * t134;
    const double t137 = 0.1e1 / t135 / t133;
    const double t139 = t38 * sigma_bb * t137;
    const double t140 = 0.5e1 / 0.72e2 * t139;
    const double t143 = 0.1e1 / t135 / rho_b;
    const double t147 = lapl_b * lapl_b;
    const double t148 = t133 * rho_b;
    const double t150 = 0.1e1 / t134 / t148;
    const double t153 = t56 * t147 * t150 / 0.5832e4;
    const double t154 = t133 * t133;
    const double t156 = 0.1e1 / t134 / t154;
    const double t157 = sigma_bb * t156;
    const double t160 = t56 * t157 * lapl_b / 0.5184e4;
    const double t161 = sigma_bb * sigma_bb;
    const double t162 = t154 * rho_b;
    const double t164 = 0.1e1 / t134 / t162;
    const double t167 = t56 * t161 * t164 / 0.17496e5;
    const double t168 = 0.1e1 + 0.5e1 / 0.648e3 * t139 + 0.5e1 / 0.54e2 * t38 * lapl_b * t143 + t153 - t160 + t167;
    const double t169 = t153 - t160 + t167;
    const double t170 = t169 * t169;
    const double t171 = 0.1e1 + t140;
    const double t172 = t171 * t171;
    const double t173 = 0.1e1 / t172;
    const double t175 = t170 * t173 + 0.1e1;
    const double t176 = safe_math::sqrt( t175 );
    const double t177 = 0.1e1 / t176;
    const double t179 = t168 * t177 - t140;
    const double t180 = t179 <= t90;
    const double t181 = t92 <= t179;
    const double t182 = t179 < t90;
    const double t183 = piecewise_functor_3( t182, t90, t179 );
    const double t184 = t183 < t92;
    const double t185 = piecewise_functor_3( t184, t183, t92 );
    const double t186 = 0.1e1 / t185;
    const double t188 = safe_math::exp( -t94 * t186 );
    const double t189 = a - t185;
    const double t192 = safe_math::exp( -a / t189 );
    const double t193 = 0.1e1 + t192;
    const double t194 = safe_math::pow( t193, b );
    const double t195 = t188 * t194;
    const double t197 = safe_math::exp( -a * t186 );
    const double t198 = t197 + t192;
    const double t199 = safe_math::pow( t198, b );
    const double t200 = 0.1e1 / t199;
    const double t201 = t195 * t200;
    const double t202 = piecewise_functor_5( t180, 0.0, t181, 1.0, t201 );
    const double t204 = t179 * t202 + t140;
    const double t208 = piecewise_functor_3( t122, 0.0, 0.3e1 / 0.2e2 * t7 * t132 * t204 );
    const double t209 = t8 * t8;
    const double t210 = 0.1e1 / t209;
    const double t211 = t18 * t210;
    const double t213 = piecewise_functor_5( t12, 0.0, t16, 0.0, t9 - t211 );
    const double t216 = piecewise_functor_3( t22, 0.0, 0.5e1 / 0.3e1 * t27 * t213 );
    const double t217 = t216 * t31;
    const double t221 = 0.1e1 / t30;
    const double t222 = t29 * t221;
    const double t225 = t7 * t222 * t117 / 0.1e2;
    const double t227 = 0.1e1 / t41 / t58;
    const double t228 = sigma_aa * t227;
    const double t229 = t38 * t228;
    const double t230 = 0.5e1 / 0.27e2 * t229;
    const double t237 = 0.5e1 / 0.8748e4 * t56 * t57 * t66;
    const double t238 = sigma_aa * t74;
    const double t241 = 0.13e2 / 0.15552e5 * t56 * t238 * lapl_a;
    const double t242 = t64 * t39;
    const double t244 = 0.1e1 / t40 / t242;
    const double t247 = 0.2e1 / 0.6561e4 * t56 * t71 * t244;
    const double t248 = -0.5e1 / 0.243e3 * t229 - 0.25e2 / 0.162e3 * t38 * lapl_a * t43 - t237 + t241 - t247;
    const double t251 = 0.1e1 / t86 / t85;
    const double t252 = t78 * t251;
    const double t253 = t79 * t83;
    const double t254 = -t237 + t241 - t247;
    const double t257 = t82 * t81;
    const double t258 = 0.1e1 / t257;
    const double t259 = t80 * t258;
    const double t260 = t259 * t33;
    const double t261 = t37 * sigma_aa;
    const double t262 = t261 * t227;
    const double t265 = 0.2e1 * t253 * t254 + 0.1e2 / 0.27e2 * t260 * t262;
    const double t268 = t248 * t87 - t252 * t265 / 0.2e1 + t230;
    const double t270 = t98 * t98;
    const double t271 = 0.1e1 / t270;
    const double t272 = t94 * t271;
    const double t273 = piecewise_functor_3( t95, 0.0, t268 );
    const double t274 = piecewise_functor_3( t97, t273, 0.0 );
    const double t275 = t274 * t101;
    const double t276 = t107 * t113;
    const double t277 = t275 * t276;
    const double t279 = t108 * t94;
    const double t280 = t102 * t102;
    const double t281 = 0.1e1 / t280;
    const double t282 = t281 * t274;
    const double t283 = 0.1e1 / t106;
    const double t285 = t105 * t283 * t113;
    const double t288 = a * t271;
    const double t289 = t274 * t110;
    const double t291 = a * t281;
    const double t292 = t274 * t105;
    const double t294 = t288 * t289 - t291 * t292;
    const double t296 = 0.1e1 / t111;
    const double t300 = piecewise_functor_5( t91, 0.0, t93, 0.0, -t114 * b * t294 * t296 - t279 * t282 * t285 + t272 * t277 );
    const double t302 = t268 * t115 + t89 * t300 - t230;
    const double t307 = piecewise_functor_3( t2, 0.0, 0.3e1 / 0.2e2 * t7 * t217 * t117 + t225 + 0.3e1 / 0.2e2 * t7 * t32 * t302 );
    const double t308 = t123 * t210;
    const double t310 = piecewise_functor_5( t16, 0.0, t12, 0.0, -t9 - t308 );
    const double t313 = piecewise_functor_3( t127, 0.0, 0.5e1 / 0.3e1 * t129 * t310 );
    const double t314 = t313 * t31;
    const double t318 = t131 * t221;
    const double t321 = t7 * t318 * t204 / 0.1e2;
    const double t323 = piecewise_functor_3( t122, 0.0, 0.3e1 / 0.2e2 * t7 * t314 * t204 + t321 );
    const double t327 = piecewise_functor_5( t12, 0.0, t16, 0.0, -t9 - t211 );
    const double t330 = piecewise_functor_3( t22, 0.0, 0.5e1 / 0.3e1 * t27 * t327 );
    const double t331 = t330 * t31;
    const double t336 = piecewise_functor_3( t2, 0.0, 0.3e1 / 0.2e2 * t7 * t331 * t117 + t225 );
    const double t338 = piecewise_functor_5( t16, 0.0, t12, 0.0, t9 - t308 );
    const double t341 = piecewise_functor_3( t127, 0.0, 0.5e1 / 0.3e1 * t129 * t338 );
    const double t342 = t341 * t31;
    const double t347 = 0.1e1 / t135 / t148;
    const double t349 = t38 * sigma_bb * t347;
    const double t350 = 0.5e1 / 0.27e2 * t349;
    const double t357 = 0.5e1 / 0.8748e4 * t56 * t147 * t156;
    const double t358 = sigma_bb * t164;
    const double t361 = 0.13e2 / 0.15552e5 * t56 * t358 * lapl_b;
    const double t362 = t154 * t133;
    const double t364 = 0.1e1 / t134 / t362;
    const double t367 = 0.2e1 / 0.6561e4 * t56 * t161 * t364;
    const double t368 = -0.5e1 / 0.243e3 * t349 - 0.25e2 / 0.162e3 * t38 * lapl_b * t137 - t357 + t361 - t367;
    const double t371 = 0.1e1 / t176 / t175;
    const double t372 = t168 * t371;
    const double t373 = t169 * t173;
    const double t374 = -t357 + t361 - t367;
    const double t377 = t172 * t171;
    const double t378 = 0.1e1 / t377;
    const double t379 = t170 * t378;
    const double t380 = t379 * t33;
    const double t381 = t37 * sigma_bb;
    const double t382 = t381 * t347;
    const double t385 = 0.2e1 * t373 * t374 + 0.1e2 / 0.27e2 * t380 * t382;
    const double t388 = t368 * t177 - t372 * t385 / 0.2e1 + t350;
    const double t390 = t185 * t185;
    const double t391 = 0.1e1 / t390;
    const double t392 = t94 * t391;
    const double t393 = piecewise_functor_3( t182, 0.0, t388 );
    const double t394 = piecewise_functor_3( t184, t393, 0.0 );
    const double t395 = t394 * t188;
    const double t396 = t194 * t200;
    const double t397 = t395 * t396;
    const double t399 = t195 * t94;
    const double t400 = t189 * t189;
    const double t401 = 0.1e1 / t400;
    const double t402 = t401 * t394;
    const double t403 = 0.1e1 / t193;
    const double t405 = t192 * t403 * t200;
    const double t408 = a * t391;
    const double t409 = t394 * t197;
    const double t411 = a * t401;
    const double t412 = t394 * t192;
    const double t414 = t408 * t409 - t411 * t412;
    const double t416 = 0.1e1 / t198;
    const double t420 = piecewise_functor_5( t180, 0.0, t181, 0.0, -t201 * b * t414 * t416 - t399 * t402 * t405 + t392 * t397 );
    const double t422 = t179 * t420 + t388 * t202 - t350;
    const double t427 = piecewise_functor_3( t122, 0.0, 0.3e1 / 0.2e2 * t7 * t342 * t204 + t321 + 0.3e1 / 0.2e2 * t7 * t132 * t422 );
    const double t430 = t38 * t43;
    const double t431 = 0.5e1 / 0.72e2 * t430;
    const double t434 = t56 * t66 * lapl_a;
    const double t435 = t434 / 0.5184e4;
    const double t436 = t56 * t238;
    const double t437 = t436 / 0.8748e4;
    const double t438 = 0.5e1 / 0.648e3 * t430 - t435 + t437;
    const double t440 = -t435 + t437;
    const double t445 = 0.2e1 * t253 * t440 - 0.5e1 / 0.36e2 * t259 * t430;
    const double t448 = t438 * t87 - t252 * t445 / 0.2e1 - t431;
    const double t450 = piecewise_functor_3( t95, 0.0, t448 );
    const double t451 = piecewise_functor_3( t97, t450, 0.0 );
    const double t452 = t451 * t101;
    const double t453 = t452 * t276;
    const double t455 = t281 * t451;
    const double t458 = t451 * t110;
    const double t460 = t451 * t105;
    const double t462 = t288 * t458 - t291 * t460;
    const double t463 = b * t462;
    const double t467 = piecewise_functor_5( t91, 0.0, t93, 0.0, -t114 * t463 * t296 - t279 * t455 * t285 + t272 * t453 );
    const double t469 = t448 * t115 + t89 * t467 + t431;
    const double t473 = piecewise_functor_3( t2, 0.0, 0.3e1 / 0.2e2 * t7 * t32 * t469 );
    const double t474 = t38 * t137;
    const double t475 = 0.5e1 / 0.72e2 * t474;
    const double t478 = t56 * t156 * lapl_b;
    const double t479 = t478 / 0.5184e4;
    const double t480 = t56 * t358;
    const double t481 = t480 / 0.8748e4;
    const double t482 = 0.5e1 / 0.648e3 * t474 - t479 + t481;
    const double t484 = -t479 + t481;
    const double t489 = 0.2e1 * t373 * t484 - 0.5e1 / 0.36e2 * t379 * t474;
    const double t492 = t482 * t177 - t372 * t489 / 0.2e1 - t475;
    const double t494 = piecewise_functor_3( t182, 0.0, t492 );
    const double t495 = piecewise_functor_3( t184, t494, 0.0 );
    const double t496 = t495 * t188;
    const double t497 = t496 * t396;
    const double t499 = t401 * t495;
    const double t502 = t495 * t197;
    const double t504 = t495 * t192;
    const double t506 = t408 * t502 - t411 * t504;
    const double t507 = b * t506;
    const double t511 = piecewise_functor_5( t180, 0.0, t181, 0.0, -t201 * t507 * t416 - t399 * t499 * t405 + t392 * t497 );
    const double t513 = t179 * t511 + t492 * t202 + t475;
    const double t517 = piecewise_functor_3( t122, 0.0, 0.3e1 / 0.2e2 * t7 * t132 * t513 );
    const double t522 = t56 * lapl_a * t60 / 0.2916e4;
    const double t524 = t56 * t67 / 0.5184e4;
    const double t525 = 0.5e1 / 0.54e2 * t38 * t49 + t522 - t524;
    const double t527 = t522 - t524;
    const double t528 = t253 * t527;
    const double t530 = -t252 * t528 + t525 * t87;
    const double t532 = piecewise_functor_3( t95, 0.0, t530 );
    const double t533 = piecewise_functor_3( t97, t532, 0.0 );
    const double t534 = t533 * t101;
    const double t535 = t534 * t276;
    const double t537 = t281 * t533;
    const double t540 = t533 * t110;
    const double t542 = t533 * t105;
    const double t544 = t288 * t540 - t291 * t542;
    const double t545 = b * t544;
    const double t549 = piecewise_functor_5( t91, 0.0, t93, 0.0, -t114 * t545 * t296 - t279 * t537 * t285 + t272 * t535 );
    const double t551 = t530 * t115 + t89 * t549;
    const double t555 = piecewise_functor_3( t2, 0.0, 0.3e1 / 0.2e2 * t7 * t32 * t551 );
    const double t560 = t56 * lapl_b * t150 / 0.2916e4;
    const double t562 = t56 * t157 / 0.5184e4;
    const double t563 = 0.5e1 / 0.54e2 * t38 * t143 + t560 - t562;
    const double t565 = t560 - t562;
    const double t566 = t373 * t565;
    const double t568 = t563 * t177 - t372 * t566;
    const double t570 = piecewise_functor_3( t182, 0.0, t568 );
    const double t571 = piecewise_functor_3( t184, t570, 0.0 );
    const double t572 = t571 * t188;
    const double t573 = t572 * t396;
    const double t575 = t401 * t571;
    const double t578 = t571 * t197;
    const double t580 = t571 * t192;
    const double t582 = t408 * t578 - t411 * t580;
    const double t583 = b * t582;
    const double t587 = piecewise_functor_5( t180, 0.0, t181, 0.0, -t201 * t583 * t416 - t399 * t575 * t405 + t392 * t573 );
    const double t589 = t179 * t587 + t568 * t202;
    const double t593 = piecewise_functor_3( t122, 0.0, 0.3e1 / 0.2e2 * t7 * t132 * t589 );


    eps = t121 + t208;
    vrho_a = t121 + t208 + t8 * ( t307 + t323 );
    vrho_b = t121 + t208 + t8 * ( t336 + t427 );
    vsigma_aa = t8 * t473;
    vsigma_ab = 0.e0;
    vsigma_bb = t8 * t517;
    vlapl_a = t8 * t555;
    vlapl_b = t8 * t593;
    vtau_a = 0.e0;
    vtau_b = 0.e0;

  }


};

struct BuiltinPC07_K : detail::BuiltinKernelImpl< BuiltinPC07_K > {

  BuiltinPC07_K( Spin p ) :
    detail::BuiltinKernelImpl< BuiltinPC07_K >(p) { }
  
  virtual ~BuiltinPC07_K() = default;

};



} // namespace ExchCXX