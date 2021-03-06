#pragma once

#ifdef EXCHCXX_HAS_CONFIG_H
#include <exchcxx/exchcxx_config.hpp>
#endif


#include <exchcxx/xc_kernel.hpp>
#include <exchcxx/impl/builtin/fwd.hpp>
#include <type_traits>

namespace ExchCXX {



class BuiltinKernel {

  Spin polar_;

public:

  explicit BuiltinKernel( Spin p ) : polar_(p) { }
  virtual ~BuiltinKernel() = default;

  virtual bool is_lda()       const noexcept = 0;
  virtual bool is_gga()       const noexcept = 0;
  virtual bool is_mgga()      const noexcept = 0;
  virtual bool is_hyb()       const noexcept = 0;
  virtual double hyb_exx()    const noexcept = 0;

  inline bool is_polarized() const noexcept { 
    return polar_ == Spin::Polarized; 
  };

  inline auto polar() const noexcept { return polar_; }

  // LDA interface
  virtual LDA_EXC_GENERATOR( eval_exc )                 const;
  virtual LDA_EXC_VXC_GENERATOR( eval_exc_vxc )         const;
  virtual LDA_EXC_INC_GENERATOR( eval_exc_inc )         const;
  virtual LDA_EXC_VXC_INC_GENERATOR( eval_exc_vxc_inc ) const;

  // GGA interface
  virtual GGA_EXC_GENERATOR( eval_exc )                 const;
  virtual GGA_EXC_VXC_GENERATOR( eval_exc_vxc )         const;
  virtual GGA_EXC_INC_GENERATOR( eval_exc_inc )         const;
  virtual GGA_EXC_VXC_INC_GENERATOR( eval_exc_vxc_inc ) const;

  // MGGA interface
  virtual MGGA_EXC_GENERATOR( eval_exc )                 const;
  virtual MGGA_EXC_VXC_GENERATOR( eval_exc_vxc )         const;
  virtual MGGA_EXC_INC_GENERATOR( eval_exc_inc )         const;
  virtual MGGA_EXC_VXC_INC_GENERATOR( eval_exc_vxc_inc ) const;

#ifdef EXCHCXX_ENABLE_DEVICE

  // LDA interface
  virtual LDA_EXC_GENERATOR_DEVICE( eval_exc_device )                 const;
  virtual LDA_EXC_VXC_GENERATOR_DEVICE( eval_exc_vxc_device )         const;
  virtual LDA_EXC_INC_GENERATOR_DEVICE( eval_exc_inc_device )         const;
  virtual LDA_EXC_VXC_INC_GENERATOR_DEVICE( eval_exc_vxc_inc_device ) const;

  // GGA interface
  virtual GGA_EXC_GENERATOR_DEVICE( eval_exc_device )                 const;
  virtual GGA_EXC_VXC_GENERATOR_DEVICE( eval_exc_vxc_device )         const;
  virtual GGA_EXC_INC_GENERATOR_DEVICE( eval_exc_inc_device )         const;
  virtual GGA_EXC_VXC_INC_GENERATOR_DEVICE( eval_exc_vxc_inc_device ) const;

  // MGGA interface
  virtual MGGA_EXC_GENERATOR_DEVICE( eval_exc_device )                 const;
  virtual MGGA_EXC_VXC_GENERATOR_DEVICE( eval_exc_vxc_device )         const;
  virtual MGGA_EXC_INC_GENERATOR_DEVICE( eval_exc_inc_device )         const;
  virtual MGGA_EXC_VXC_INC_GENERATOR_DEVICE( eval_exc_vxc_inc_device ) const;

#endif


};



namespace detail {

template <typename KernelType>
LDA_EXC_GENERATOR( host_eval_exc_helper_unpolar );
template <typename KernelType>
LDA_EXC_VXC_GENERATOR( host_eval_exc_vxc_helper_unpolar );

template <typename KernelType>
LDA_EXC_INC_GENERATOR( host_eval_exc_inc_helper_unpolar );
template <typename KernelType>
LDA_EXC_VXC_INC_GENERATOR( host_eval_exc_vxc_inc_helper_unpolar );

template <typename KernelType>
GGA_EXC_GENERATOR( host_eval_exc_helper_unpolar );
template <typename KernelType>
GGA_EXC_VXC_GENERATOR( host_eval_exc_vxc_helper_unpolar );

template <typename KernelType>
GGA_EXC_INC_GENERATOR( host_eval_exc_inc_helper_unpolar );
template <typename KernelType>
GGA_EXC_VXC_INC_GENERATOR( host_eval_exc_vxc_inc_helper_unpolar );

template <typename KernelType>
LDA_EXC_GENERATOR( host_eval_exc_helper_polar );
template <typename KernelType>
LDA_EXC_VXC_GENERATOR( host_eval_exc_vxc_helper_polar );

template <typename KernelType>
LDA_EXC_INC_GENERATOR( host_eval_exc_inc_helper_polar );
template <typename KernelType>
LDA_EXC_VXC_INC_GENERATOR( host_eval_exc_vxc_inc_helper_polar );

template <typename KernelType>
GGA_EXC_GENERATOR( host_eval_exc_helper_polar );
template <typename KernelType>
GGA_EXC_VXC_GENERATOR( host_eval_exc_vxc_helper_polar );

template <typename KernelType>
GGA_EXC_INC_GENERATOR( host_eval_exc_inc_helper_polar );
template <typename KernelType>
GGA_EXC_VXC_INC_GENERATOR( host_eval_exc_vxc_inc_helper_polar );

#ifdef EXCHCXX_ENABLE_DEVICE

template <typename KernelType>
LDA_EXC_GENERATOR_DEVICE( device_eval_exc_helper_unpolar );
template <typename KernelType>
LDA_EXC_VXC_GENERATOR_DEVICE( device_eval_exc_vxc_helper_unpolar );

template <typename KernelType>
LDA_EXC_INC_GENERATOR_DEVICE( device_eval_exc_inc_helper_unpolar );
template <typename KernelType>
LDA_EXC_VXC_INC_GENERATOR_DEVICE( device_eval_exc_vxc_inc_helper_unpolar );

template <typename KernelType>
GGA_EXC_GENERATOR_DEVICE( device_eval_exc_helper_unpolar );
template <typename KernelType>
GGA_EXC_VXC_GENERATOR_DEVICE( device_eval_exc_vxc_helper_unpolar );

template <typename KernelType>
GGA_EXC_INC_GENERATOR_DEVICE( device_eval_exc_inc_helper_unpolar );
template <typename KernelType>
GGA_EXC_VXC_INC_GENERATOR_DEVICE( device_eval_exc_vxc_inc_helper_unpolar );

template <typename KernelType>
LDA_EXC_GENERATOR_DEVICE( device_eval_exc_helper_polar );
template <typename KernelType>
LDA_EXC_VXC_GENERATOR_DEVICE( device_eval_exc_vxc_helper_polar );

template <typename KernelType>
LDA_EXC_INC_GENERATOR_DEVICE( device_eval_exc_inc_helper_polar );
template <typename KernelType>
LDA_EXC_VXC_INC_GENERATOR_DEVICE( device_eval_exc_vxc_inc_helper_polar );

template <typename KernelType>
GGA_EXC_GENERATOR_DEVICE( device_eval_exc_helper_polar );
template <typename KernelType>
GGA_EXC_VXC_GENERATOR_DEVICE( device_eval_exc_vxc_helper_polar );

template <typename KernelType>
GGA_EXC_INC_GENERATOR_DEVICE( device_eval_exc_inc_helper_polar );
template <typename KernelType>
GGA_EXC_VXC_INC_GENERATOR_DEVICE( device_eval_exc_vxc_inc_helper_polar );

#endif





template <typename KernelType>
struct BuiltinKernelImpl<
  KernelType,
  std::enable_if_t<kernel_traits<KernelType>::is_lda>
> : public BuiltinKernel {

private:

  template <typename... Args>
  void eval_exc_(Args&&... args) const {
    if( is_polarized() )
      host_eval_exc_helper_polar<KernelType>(
        std::forward<Args>(args)...
      );
    else
      host_eval_exc_helper_unpolar<KernelType>(
        std::forward<Args>(args)...
      );
  }

  template <typename... Args>
  void eval_exc_vxc_(Args&&... args) const {
    if( is_polarized() )
      host_eval_exc_vxc_helper_polar<KernelType>(
        std::forward<Args>(args)...
      );
    else
      host_eval_exc_vxc_helper_unpolar<KernelType>(
        std::forward<Args>(args)...
      );
  }

  template <typename... Args>
  void eval_exc_inc_(Args&&... args) const {
    if( is_polarized() )
      host_eval_exc_inc_helper_polar<KernelType>(
        std::forward<Args>(args)...
      );
    else
      host_eval_exc_inc_helper_unpolar<KernelType>(
        std::forward<Args>(args)...
      );
  }

  template <typename... Args>
  void eval_exc_vxc_inc_(Args&&... args) const {
    if( is_polarized() )
      host_eval_exc_vxc_inc_helper_polar<KernelType>(
        std::forward<Args>(args)...
      );
    else
      host_eval_exc_vxc_inc_helper_unpolar<KernelType>(
        std::forward<Args>(args)...
      );
  }

#ifdef EXCHCXX_ENABLE_DEVICE

  template <typename... Args>
  void eval_exc_device_(Args&&... args) const {
    if( is_polarized() )
      device_eval_exc_helper_polar<KernelType>(
        std::forward<Args>(args)...
      );
    else
      device_eval_exc_helper_unpolar<KernelType>(
        std::forward<Args>(args)...
      );
  }

  template <typename... Args>
  void eval_exc_vxc_device_(Args&&... args) const {
    if( is_polarized() )
      device_eval_exc_vxc_helper_polar<KernelType>(
        std::forward<Args>(args)...
      );
    else
      device_eval_exc_vxc_helper_unpolar<KernelType>(
        std::forward<Args>(args)...
      );
  }

  template <typename... Args>
  void eval_exc_inc_device_(Args&&... args) const {
    if( is_polarized() )
      device_eval_exc_inc_helper_polar<KernelType>(
        std::forward<Args>(args)...
      );
    else
      device_eval_exc_inc_helper_unpolar<KernelType>(
        std::forward<Args>(args)...
      );
  }

  template <typename... Args>
  void eval_exc_vxc_inc_device_(Args&&... args) const {
    if( is_polarized() )
      device_eval_exc_vxc_inc_helper_polar<KernelType>(
        std::forward<Args>(args)...
      );
    else
      device_eval_exc_vxc_inc_helper_unpolar<KernelType>(
        std::forward<Args>(args)...
      );
  }

#endif

public:

  using traits = kernel_traits<KernelType>;

  BuiltinKernelImpl( Spin p ) : BuiltinKernel(p) { }
  virtual ~BuiltinKernelImpl() noexcept = default;

  inline bool is_hyb()  const noexcept override { return traits::is_hyb;  }
  inline bool is_lda()  const noexcept override { return traits::is_lda;  }
  inline bool is_gga()  const noexcept override { return traits::is_gga;  }
  inline bool is_mgga() const noexcept override { return traits::is_mgga; }

  inline double hyb_exx() const noexcept override {
    return traits::is_hyb ? traits::exx_coeff : 0.;
  }

  inline FORWARD_XC_ARGS( LDA, EXC, eval_exc, eval_exc_, const override );
  inline FORWARD_XC_ARGS( LDA, EXC_VXC, eval_exc_vxc, eval_exc_vxc_, const override );

  inline FORWARD_XC_INC_ARGS( LDA, EXC, eval_exc_inc, eval_exc_inc_, const override );
  inline FORWARD_XC_INC_ARGS( LDA, EXC_VXC, eval_exc_vxc_inc, eval_exc_vxc_inc_, const override );

#ifdef EXCHCXX_ENABLE_DEVICE

  inline FORWARD_XC_ARGS_DEVICE( LDA, EXC, eval_exc_device, eval_exc_device_, const override );
  inline FORWARD_XC_ARGS_DEVICE( LDA, EXC_VXC, eval_exc_vxc_device, eval_exc_vxc_device_, const override );

  inline FORWARD_XC_INC_ARGS_DEVICE( LDA, EXC, eval_exc_inc_device, eval_exc_inc_device_, const override );
  inline FORWARD_XC_INC_ARGS_DEVICE( LDA, EXC_VXC, eval_exc_vxc_inc_device, eval_exc_vxc_inc_device_, const override );

#endif
};



template <typename KernelType>
struct BuiltinKernelImpl<
  KernelType,
  std::enable_if_t<kernel_traits<KernelType>::is_gga>
> : public BuiltinKernel {

private:

  template <typename... Args>
  void eval_exc_(Args&&... args) const {
    if( is_polarized() )
      host_eval_exc_helper_polar<KernelType>(
        std::forward<Args>(args)...
      );
    else
      host_eval_exc_helper_unpolar<KernelType>(
        std::forward<Args>(args)...
      );
  }

  template <typename... Args>
  void eval_exc_vxc_(Args&&... args) const {
    if( is_polarized() )
      host_eval_exc_vxc_helper_polar<KernelType>(
        std::forward<Args>(args)...
      );
    else
      host_eval_exc_vxc_helper_unpolar<KernelType>(
        std::forward<Args>(args)...
      );
  }

  template <typename... Args>
  void eval_exc_inc_(Args&&... args) const {
    if( is_polarized() )
      host_eval_exc_inc_helper_polar<KernelType>(
        std::forward<Args>(args)...
      );
    else
      host_eval_exc_inc_helper_unpolar<KernelType>(
        std::forward<Args>(args)...
      );
  }

  template <typename... Args>
  void eval_exc_vxc_inc_(Args&&... args) const {
    if( is_polarized() )
      host_eval_exc_vxc_inc_helper_polar<KernelType>(
        std::forward<Args>(args)...
      );
    else
      host_eval_exc_vxc_inc_helper_unpolar<KernelType>(
        std::forward<Args>(args)...
      );
  }

#ifdef EXCHCXX_ENABLE_DEVICE

  template <typename... Args>
  void eval_exc_device_(Args&&... args) const {
    if( is_polarized() )
      device_eval_exc_helper_polar<KernelType>(
        std::forward<Args>(args)...
      );
    else
      device_eval_exc_helper_unpolar<KernelType>(
        std::forward<Args>(args)...
      );
  }

  template <typename... Args>
  void eval_exc_vxc_device_(Args&&... args) const {
    if( is_polarized() )
      device_eval_exc_vxc_helper_polar<KernelType>(
        std::forward<Args>(args)...
      );
    else
      device_eval_exc_vxc_helper_unpolar<KernelType>(
        std::forward<Args>(args)...
      );
  }

  template <typename... Args>
  void eval_exc_inc_device_(Args&&... args) const {
    if( is_polarized() )
      device_eval_exc_inc_helper_polar<KernelType>(
        std::forward<Args>(args)...
      );
    else
      device_eval_exc_inc_helper_unpolar<KernelType>(
        std::forward<Args>(args)...
      );
  }

  template <typename... Args>
  void eval_exc_vxc_inc_device_(Args&&... args) const {
    if( is_polarized() )
      device_eval_exc_vxc_inc_helper_polar<KernelType>(
        std::forward<Args>(args)...
      );
    else
      device_eval_exc_vxc_inc_helper_unpolar<KernelType>(
        std::forward<Args>(args)...
      );
  }

#endif

public:

  using traits = kernel_traits<KernelType>;

  BuiltinKernelImpl( Spin p ) : BuiltinKernel(p) { }
  virtual ~BuiltinKernelImpl() noexcept = default;

  inline bool is_hyb()  const noexcept override { return traits::is_hyb;  }
  inline bool is_lda()  const noexcept override { return traits::is_lda;  }
  inline bool is_gga()  const noexcept override { return traits::is_gga;  }
  inline bool is_mgga() const noexcept override { return traits::is_mgga; }

  inline double hyb_exx() const noexcept override {
    return traits::is_hyb ? traits::exx_coeff : 0.;
  }

  inline FORWARD_XC_ARGS( GGA, EXC, eval_exc, eval_exc_, const override );
  inline FORWARD_XC_ARGS( GGA, EXC_VXC, eval_exc_vxc, eval_exc_vxc_, const override );

  inline FORWARD_XC_INC_ARGS( GGA, EXC, eval_exc_inc, eval_exc_inc_, const override );
  inline FORWARD_XC_INC_ARGS( GGA, EXC_VXC, eval_exc_vxc_inc, eval_exc_vxc_inc_, const override );

#ifdef EXCHCXX_ENABLE_DEVICE

  inline FORWARD_XC_ARGS_DEVICE( GGA, EXC, eval_exc_device, eval_exc_device_, const override );
  inline FORWARD_XC_ARGS_DEVICE( GGA, EXC_VXC, eval_exc_vxc_device, eval_exc_vxc_device_, const override );

  inline FORWARD_XC_INC_ARGS_DEVICE( GGA, EXC, eval_exc_inc_device, eval_exc_inc_device_, const override );
  inline FORWARD_XC_INC_ARGS_DEVICE( GGA, EXC_VXC, eval_exc_vxc_inc_device, eval_exc_vxc_inc_device_, const override );

#endif
};

}





}
