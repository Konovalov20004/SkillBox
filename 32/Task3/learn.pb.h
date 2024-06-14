// Generated by the protocol buffer compiler.  DO NOT EDIT!
// NO CHECKED-IN PROTOBUF GENCODE
// source: learn.proto
// Protobuf C++ Version: 5.27.1

#ifndef GOOGLE_PROTOBUF_INCLUDED_learn_2eproto_2epb_2eh
#define GOOGLE_PROTOBUF_INCLUDED_learn_2eproto_2epb_2eh

#include <limits>
#include <string>
#include <type_traits>
#include <utility>

#include "google/protobuf/runtime_version.h"
#if PROTOBUF_VERSION != 5027001
#error "Protobuf C++ gencode is built with an incompatible version of"
#error "Protobuf C++ headers/runtime. See"
#error "https://protobuf.dev/support/cross-version-runtime-guarantee/#cpp"
#endif
#include "google/protobuf/io/coded_stream.h"
#include "google/protobuf/arena.h"
#include "google/protobuf/arenastring.h"
#include "google/protobuf/generated_message_tctable_decl.h"
#include "google/protobuf/generated_message_util.h"
#include "google/protobuf/metadata_lite.h"
#include "google/protobuf/generated_message_reflection.h"
#include "google/protobuf/message.h"
#include "google/protobuf/repeated_field.h"  // IWYU pragma: export
#include "google/protobuf/extension_set.h"  // IWYU pragma: export
#include "google/protobuf/unknown_field_set.h"
// @@protoc_insertion_point(includes)

// Must be included last.
#include "google/protobuf/port_def.inc"

#define PROTOBUF_INTERNAL_EXPORT_learn_2eproto

namespace google {
namespace protobuf {
namespace internal {
class AnyMetadata;
}  // namespace internal
}  // namespace protobuf
}  // namespace google

// Internal implementation detail -- do not use these members.
struct TableStruct_learn_2eproto {
  static const ::uint32_t offsets[];
};
extern const ::google::protobuf::internal::DescriptorTable
    descriptor_table_learn_2eproto;
class Manufactured;
struct ManufacturedDefaultTypeInternal;
extern ManufacturedDefaultTypeInternal _Manufactured_default_instance_;
namespace google {
namespace protobuf {
}  // namespace protobuf
}  // namespace google


// ===================================================================


// -------------------------------------------------------------------

class Manufactured final : public ::google::protobuf::Message
/* @@protoc_insertion_point(class_definition:Manufactured) */ {
 public:
  inline Manufactured() : Manufactured(nullptr) {}
  ~Manufactured() override;
  template <typename = void>
  explicit PROTOBUF_CONSTEXPR Manufactured(
      ::google::protobuf::internal::ConstantInitialized);

  inline Manufactured(const Manufactured& from) : Manufactured(nullptr, from) {}
  inline Manufactured(Manufactured&& from) noexcept
      : Manufactured(nullptr, std::move(from)) {}
  inline Manufactured& operator=(const Manufactured& from) {
    CopyFrom(from);
    return *this;
  }
  inline Manufactured& operator=(Manufactured&& from) noexcept {
    if (this == &from) return *this;
    if (GetArena() == from.GetArena()
#ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetArena() != nullptr
#endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const
      ABSL_ATTRIBUTE_LIFETIME_BOUND {
    return _internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance);
  }
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields()
      ABSL_ATTRIBUTE_LIFETIME_BOUND {
    return _internal_metadata_.mutable_unknown_fields<::google::protobuf::UnknownFieldSet>();
  }

  static const ::google::protobuf::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::google::protobuf::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::google::protobuf::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const Manufactured& default_instance() {
    return *internal_default_instance();
  }
  static inline const Manufactured* internal_default_instance() {
    return reinterpret_cast<const Manufactured*>(
        &_Manufactured_default_instance_);
  }
  static constexpr int kIndexInFileMessages = 0;
  friend void swap(Manufactured& a, Manufactured& b) { a.Swap(&b); }
  inline void Swap(Manufactured* other) {
    if (other == this) return;
#ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetArena() != nullptr && GetArena() == other->GetArena()) {
#else   // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetArena() == other->GetArena()) {
#endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::google::protobuf::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(Manufactured* other) {
    if (other == this) return;
    ABSL_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  Manufactured* New(::google::protobuf::Arena* arena = nullptr) const final {
    return ::google::protobuf::Message::DefaultConstruct<Manufactured>(arena);
  }
  using ::google::protobuf::Message::CopyFrom;
  void CopyFrom(const Manufactured& from);
  using ::google::protobuf::Message::MergeFrom;
  void MergeFrom(const Manufactured& from) { Manufactured::MergeImpl(*this, from); }

  private:
  static void MergeImpl(
      ::google::protobuf::MessageLite& to_msg,
      const ::google::protobuf::MessageLite& from_msg);

  public:
  bool IsInitialized() const {
    return IsInitializedImpl(*this);
  }

  private:
  static bool IsInitializedImpl(const MessageLite& msg);

  public:
  ABSL_ATTRIBUTE_REINITIALIZES void Clear() final;
  ::size_t ByteSizeLong() const final;
  ::uint8_t* _InternalSerialize(
      ::uint8_t* target,
      ::google::protobuf::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::google::protobuf::Arena* arena);
  void SharedDtor();
  void InternalSwap(Manufactured* other);
 private:
  friend class ::google::protobuf::internal::AnyMetadata;
  static ::absl::string_view FullMessageName() { return "Manufactured"; }

 protected:
  explicit Manufactured(::google::protobuf::Arena* arena);
  Manufactured(::google::protobuf::Arena* arena, const Manufactured& from);
  Manufactured(::google::protobuf::Arena* arena, Manufactured&& from) noexcept
      : Manufactured(arena) {
    *this = ::std::move(from);
  }
  const ::google::protobuf::Message::ClassData* GetClassData() const final;

 public:
  ::google::protobuf::Metadata GetMetadata() const;
  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------
  enum : int {
    kAdressFieldNumber = 2,
    kNameFieldNumber = 3,
    kLineFieldNumber = 4,
    kYearFieldNumber = 1,
    kForeignEconomicsFieldNumber = 5,
  };
  // required string adress = 2;
  bool has_adress() const;
  void clear_adress() ;
  const std::string& adress() const;
  template <typename Arg_ = const std::string&, typename... Args_>
  void set_adress(Arg_&& arg, Args_... args);
  std::string* mutable_adress();
  PROTOBUF_NODISCARD std::string* release_adress();
  void set_allocated_adress(std::string* value);

  private:
  const std::string& _internal_adress() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_adress(
      const std::string& value);
  std::string* _internal_mutable_adress();

  public:
  // required string name = 3;
  bool has_name() const;
  void clear_name() ;
  const std::string& name() const;
  template <typename Arg_ = const std::string&, typename... Args_>
  void set_name(Arg_&& arg, Args_... args);
  std::string* mutable_name();
  PROTOBUF_NODISCARD std::string* release_name();
  void set_allocated_name(std::string* value);

  private:
  const std::string& _internal_name() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_name(
      const std::string& value);
  std::string* _internal_mutable_name();

  public:
  // optional string line = 4;
  bool has_line() const;
  void clear_line() ;
  const std::string& line() const;
  template <typename Arg_ = const std::string&, typename... Args_>
  void set_line(Arg_&& arg, Args_... args);
  std::string* mutable_line();
  PROTOBUF_NODISCARD std::string* release_line();
  void set_allocated_line(std::string* value);

  private:
  const std::string& _internal_line() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_line(
      const std::string& value);
  std::string* _internal_mutable_line();

  public:
  // required int32 year = 1;
  bool has_year() const;
  void clear_year() ;
  ::int32_t year() const;
  void set_year(::int32_t value);

  private:
  ::int32_t _internal_year() const;
  void _internal_set_year(::int32_t value);

  public:
  // optional int32 foreign_economics = 5;
  bool has_foreign_economics() const;
  void clear_foreign_economics() ;
  ::int32_t foreign_economics() const;
  void set_foreign_economics(::int32_t value);

  private:
  ::int32_t _internal_foreign_economics() const;
  void _internal_set_foreign_economics(::int32_t value);

  public:
  // @@protoc_insertion_point(class_scope:Manufactured)
 private:
  class _Internal;
  friend class ::google::protobuf::internal::TcParser;
  static const ::google::protobuf::internal::TcParseTable<
      3, 5, 0,
      35, 2>
      _table_;

  static constexpr const void* _raw_default_instance_ =
      &_Manufactured_default_instance_;

  friend class ::google::protobuf::MessageLite;
  friend class ::google::protobuf::Arena;
  template <typename T>
  friend class ::google::protobuf::Arena::InternalHelper;
  using InternalArenaConstructable_ = void;
  using DestructorSkippable_ = void;
  struct Impl_ {
    inline explicit constexpr Impl_(
        ::google::protobuf::internal::ConstantInitialized) noexcept;
    inline explicit Impl_(::google::protobuf::internal::InternalVisibility visibility,
                          ::google::protobuf::Arena* arena);
    inline explicit Impl_(::google::protobuf::internal::InternalVisibility visibility,
                          ::google::protobuf::Arena* arena, const Impl_& from,
                          const Manufactured& from_msg);
    ::google::protobuf::internal::HasBits<1> _has_bits_;
    mutable ::google::protobuf::internal::CachedSize _cached_size_;
    ::google::protobuf::internal::ArenaStringPtr adress_;
    ::google::protobuf::internal::ArenaStringPtr name_;
    ::google::protobuf::internal::ArenaStringPtr line_;
    ::int32_t year_;
    ::int32_t foreign_economics_;
    PROTOBUF_TSAN_DECLARE_MEMBER
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_learn_2eproto;
};

// ===================================================================




// ===================================================================


#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// -------------------------------------------------------------------

// Manufactured

// required int32 year = 1;
inline bool Manufactured::has_year() const {
  bool value = (_impl_._has_bits_[0] & 0x00000008u) != 0;
  return value;
}
inline void Manufactured::clear_year() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.year_ = 0;
  _impl_._has_bits_[0] &= ~0x00000008u;
}
inline ::int32_t Manufactured::year() const {
  // @@protoc_insertion_point(field_get:Manufactured.year)
  return _internal_year();
}
inline void Manufactured::set_year(::int32_t value) {
  _internal_set_year(value);
  _impl_._has_bits_[0] |= 0x00000008u;
  // @@protoc_insertion_point(field_set:Manufactured.year)
}
inline ::int32_t Manufactured::_internal_year() const {
  ::google::protobuf::internal::TSanRead(&_impl_);
  return _impl_.year_;
}
inline void Manufactured::_internal_set_year(::int32_t value) {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.year_ = value;
}

// required string adress = 2;
inline bool Manufactured::has_adress() const {
  bool value = (_impl_._has_bits_[0] & 0x00000001u) != 0;
  return value;
}
inline void Manufactured::clear_adress() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.adress_.ClearToEmpty();
  _impl_._has_bits_[0] &= ~0x00000001u;
}
inline const std::string& Manufactured::adress() const
    ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_get:Manufactured.adress)
  return _internal_adress();
}
template <typename Arg_, typename... Args_>
inline PROTOBUF_ALWAYS_INLINE void Manufactured::set_adress(Arg_&& arg,
                                                     Args_... args) {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_._has_bits_[0] |= 0x00000001u;
  _impl_.adress_.Set(static_cast<Arg_&&>(arg), args..., GetArena());
  // @@protoc_insertion_point(field_set:Manufactured.adress)
}
inline std::string* Manufactured::mutable_adress() ABSL_ATTRIBUTE_LIFETIME_BOUND {
  std::string* _s = _internal_mutable_adress();
  // @@protoc_insertion_point(field_mutable:Manufactured.adress)
  return _s;
}
inline const std::string& Manufactured::_internal_adress() const {
  ::google::protobuf::internal::TSanRead(&_impl_);
  return _impl_.adress_.Get();
}
inline void Manufactured::_internal_set_adress(const std::string& value) {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_._has_bits_[0] |= 0x00000001u;
  _impl_.adress_.Set(value, GetArena());
}
inline std::string* Manufactured::_internal_mutable_adress() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_._has_bits_[0] |= 0x00000001u;
  return _impl_.adress_.Mutable( GetArena());
}
inline std::string* Manufactured::release_adress() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  // @@protoc_insertion_point(field_release:Manufactured.adress)
  if ((_impl_._has_bits_[0] & 0x00000001u) == 0) {
    return nullptr;
  }
  _impl_._has_bits_[0] &= ~0x00000001u;
  auto* released = _impl_.adress_.Release();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  _impl_.adress_.Set("", GetArena());
  #endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  return released;
}
inline void Manufactured::set_allocated_adress(std::string* value) {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  if (value != nullptr) {
    _impl_._has_bits_[0] |= 0x00000001u;
  } else {
    _impl_._has_bits_[0] &= ~0x00000001u;
  }
  _impl_.adress_.SetAllocated(value, GetArena());
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
        if (_impl_.adress_.IsDefault()) {
          _impl_.adress_.Set("", GetArena());
        }
  #endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:Manufactured.adress)
}

// required string name = 3;
inline bool Manufactured::has_name() const {
  bool value = (_impl_._has_bits_[0] & 0x00000002u) != 0;
  return value;
}
inline void Manufactured::clear_name() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.name_.ClearToEmpty();
  _impl_._has_bits_[0] &= ~0x00000002u;
}
inline const std::string& Manufactured::name() const
    ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_get:Manufactured.name)
  return _internal_name();
}
template <typename Arg_, typename... Args_>
inline PROTOBUF_ALWAYS_INLINE void Manufactured::set_name(Arg_&& arg,
                                                     Args_... args) {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_._has_bits_[0] |= 0x00000002u;
  _impl_.name_.Set(static_cast<Arg_&&>(arg), args..., GetArena());
  // @@protoc_insertion_point(field_set:Manufactured.name)
}
inline std::string* Manufactured::mutable_name() ABSL_ATTRIBUTE_LIFETIME_BOUND {
  std::string* _s = _internal_mutable_name();
  // @@protoc_insertion_point(field_mutable:Manufactured.name)
  return _s;
}
inline const std::string& Manufactured::_internal_name() const {
  ::google::protobuf::internal::TSanRead(&_impl_);
  return _impl_.name_.Get();
}
inline void Manufactured::_internal_set_name(const std::string& value) {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_._has_bits_[0] |= 0x00000002u;
  _impl_.name_.Set(value, GetArena());
}
inline std::string* Manufactured::_internal_mutable_name() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_._has_bits_[0] |= 0x00000002u;
  return _impl_.name_.Mutable( GetArena());
}
inline std::string* Manufactured::release_name() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  // @@protoc_insertion_point(field_release:Manufactured.name)
  if ((_impl_._has_bits_[0] & 0x00000002u) == 0) {
    return nullptr;
  }
  _impl_._has_bits_[0] &= ~0x00000002u;
  auto* released = _impl_.name_.Release();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  _impl_.name_.Set("", GetArena());
  #endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  return released;
}
inline void Manufactured::set_allocated_name(std::string* value) {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  if (value != nullptr) {
    _impl_._has_bits_[0] |= 0x00000002u;
  } else {
    _impl_._has_bits_[0] &= ~0x00000002u;
  }
  _impl_.name_.SetAllocated(value, GetArena());
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
        if (_impl_.name_.IsDefault()) {
          _impl_.name_.Set("", GetArena());
        }
  #endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:Manufactured.name)
}

// optional string line = 4;
inline bool Manufactured::has_line() const {
  bool value = (_impl_._has_bits_[0] & 0x00000004u) != 0;
  return value;
}
inline void Manufactured::clear_line() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.line_.ClearToEmpty();
  _impl_._has_bits_[0] &= ~0x00000004u;
}
inline const std::string& Manufactured::line() const
    ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_get:Manufactured.line)
  return _internal_line();
}
template <typename Arg_, typename... Args_>
inline PROTOBUF_ALWAYS_INLINE void Manufactured::set_line(Arg_&& arg,
                                                     Args_... args) {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_._has_bits_[0] |= 0x00000004u;
  _impl_.line_.Set(static_cast<Arg_&&>(arg), args..., GetArena());
  // @@protoc_insertion_point(field_set:Manufactured.line)
}
inline std::string* Manufactured::mutable_line() ABSL_ATTRIBUTE_LIFETIME_BOUND {
  std::string* _s = _internal_mutable_line();
  // @@protoc_insertion_point(field_mutable:Manufactured.line)
  return _s;
}
inline const std::string& Manufactured::_internal_line() const {
  ::google::protobuf::internal::TSanRead(&_impl_);
  return _impl_.line_.Get();
}
inline void Manufactured::_internal_set_line(const std::string& value) {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_._has_bits_[0] |= 0x00000004u;
  _impl_.line_.Set(value, GetArena());
}
inline std::string* Manufactured::_internal_mutable_line() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_._has_bits_[0] |= 0x00000004u;
  return _impl_.line_.Mutable( GetArena());
}
inline std::string* Manufactured::release_line() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  // @@protoc_insertion_point(field_release:Manufactured.line)
  if ((_impl_._has_bits_[0] & 0x00000004u) == 0) {
    return nullptr;
  }
  _impl_._has_bits_[0] &= ~0x00000004u;
  auto* released = _impl_.line_.Release();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  _impl_.line_.Set("", GetArena());
  #endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  return released;
}
inline void Manufactured::set_allocated_line(std::string* value) {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  if (value != nullptr) {
    _impl_._has_bits_[0] |= 0x00000004u;
  } else {
    _impl_._has_bits_[0] &= ~0x00000004u;
  }
  _impl_.line_.SetAllocated(value, GetArena());
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
        if (_impl_.line_.IsDefault()) {
          _impl_.line_.Set("", GetArena());
        }
  #endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:Manufactured.line)
}

// optional int32 foreign_economics = 5;
inline bool Manufactured::has_foreign_economics() const {
  bool value = (_impl_._has_bits_[0] & 0x00000010u) != 0;
  return value;
}
inline void Manufactured::clear_foreign_economics() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.foreign_economics_ = 0;
  _impl_._has_bits_[0] &= ~0x00000010u;
}
inline ::int32_t Manufactured::foreign_economics() const {
  // @@protoc_insertion_point(field_get:Manufactured.foreign_economics)
  return _internal_foreign_economics();
}
inline void Manufactured::set_foreign_economics(::int32_t value) {
  _internal_set_foreign_economics(value);
  _impl_._has_bits_[0] |= 0x00000010u;
  // @@protoc_insertion_point(field_set:Manufactured.foreign_economics)
}
inline ::int32_t Manufactured::_internal_foreign_economics() const {
  ::google::protobuf::internal::TSanRead(&_impl_);
  return _impl_.foreign_economics_;
}
inline void Manufactured::_internal_set_foreign_economics(::int32_t value) {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.foreign_economics_ = value;
}

#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)


// @@protoc_insertion_point(global_scope)

#include "google/protobuf/port_undef.inc"

#endif  // GOOGLE_PROTOBUF_INCLUDED_learn_2eproto_2epb_2eh
