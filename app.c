#define nullptr ((void *)0)
#define true  1
#define false  0

typedef int bool;
typedef unsigned int wchar_t;
typedef signed char int8_t;
typedef unsigned char uint8_t;
typedef signed short int16_t;
typedef unsigned short uint16_t;
typedef signed int int32_t;
typedef unsigned int uint32_t;
typedef signed long long int64_t;
typedef unsigned long long uint64_t;

#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wvisibility"
#pragma clang diagnostic ignored "-Wmain-return-type"
#pragma clang diagnostic ignored "-Wincompatible-pointer-types"
#pragma clang diagnostic ignored "-Wincompatible-library-redeclaration"
#elif defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wbuiltin-declaration-mismatch"
#pragma GCC diagnostic ignored "-Wincompatible-pointer-types"
#else
#error "Unsupported compiler"
#endif

#if __has_attribute(__builtin_unreachable)
#define unreachable(...)
    do {
        assert(!"Unreachable code reached");
        __builtin_unreachable();
    } while (0)
#else
#define unreachable(...) abort();
#endif

#define likely(x)      __builtin_expect(!!(x), 1)
#define unlikely(x)    __builtin_expect(!!(x), 0)

#define __CXY_LOOP_CLEANUP(FLAGS, LABEL) \
   if ((FLAGS) == 1) goto LABEL; \
   if ((FLAGS) == 2) { (FLAGS) = 0; break; }

#define __CXY_BLOCK_CLEANUP(FLAGS, LABEL) \
   if ((FLAGS) == 1) goto LABEL; \

#define __CXY_DROP_WITH_FLAGS(FLAGS, ...) if (FLAGS) __VA_ARGS__


/*-----------__builtins.cxy-----------*/
typedef struct SliceI_TsFU_ZVoid_ZException____E SliceI_TsFU_ZVoid_ZException____E;
typedef struct Union416 Union416;
typedef struct Void Void;
struct  Void {
};

typedef struct Exception Exception;
typedef struct Exception_VTable Exception_VTable;
typedef const char*(*builtins_Exception_what_t)(struct Exception *);
struct  Exception_VTable {
  builtins_Exception_what_t what;
};

typedef struct StackTrace StackTrace;
typedef struct CallTrace CallTrace;
struct  CallTrace {
  const char* mod;
  const char* cls;
  const char* fun;
  const char* path;
  uint64_t line;
};

struct  StackTrace {
  struct CallTrace * calls;
  uint64_t size;
  uint64_t capacity;
};

struct  Exception {
  struct Exception_VTable * vtable;
  const char* name;
  struct StackTrace stackTrace;
};

struct Union416{
  uint32_t tag;
  union {
    struct Void _0;
    struct Exception * _1;
  };
};

typedef struct Union416(*Func417_t)();
typedef struct Tuple418 {
  const char* _0;
  Func417_t _1;
} Tuple418;

struct  SliceI_TsFU_ZVoid_ZException____E {
  struct Tuple418 * data;
  uint64_t len;
};

typedef struct SliceI_sE SliceI_sE;
struct  SliceI_sE {
  const char* * data;
  uint64_t len;
};

typedef struct TestFailed TestFailed;
struct  TestFailed {
  struct Exception_VTable * vtable;
  const char* name;
  struct StackTrace stackTrace;
};

typedef struct OptionalI_u64E OptionalI_u64E;
struct  OptionalI_u64E {
  bool ok;
  uint64_t val;
};

typedef struct MemoryOutputStream MemoryOutputStream;
typedef struct OutputStream_VTable OutputStream_VTable;
typedef struct OutputStream OutputStream;
struct  OutputStream {
  struct OutputStream_VTable * vtable;
};

typedef struct OptionalI_u64E(*builtins_OutputStream_append_t)(struct OutputStream *, const void *, uint64_t);
struct  OutputStream_VTable {
  builtins_OutputStream_append_t append;
};

struct  MemoryOutputStream {
  struct OutputStream_VTable * vtable;
  void * _buffer;
  uint64_t _capacity;
  uint64_t _size;
};

typedef struct Repeat Repeat;
struct  Repeat {
  char c;
  uint64_t count;
};

typedef struct StdOutputStream StdOutputStream;
struct  StdOutputStream {
  struct OutputStream_VTable * vtable;
  int32_t fd;
};

typedef struct BufferedOutputStream BufferedOutputStream;
typedef struct BufferedOutputStream_VTable BufferedOutputStream_VTable;
typedef void(*builtins_BufferedOutputStream_flush_t)(struct BufferedOutputStream *, const void *, uint64_t);
struct  BufferedOutputStream_VTable {
  builtins_OutputStream_append_t append;
  builtins_BufferedOutputStream_flush_t flush;
};

struct  BufferedOutputStream {
  struct BufferedOutputStream_VTable * vtable;
  char * _buffer;
  uint64_t _capacity;
  uint64_t _size;
};

typedef struct String String;
struct  String {
  struct OutputStream_VTable * vtable;
  uint64_t _capacity;
  uint64_t _size;
  char * _data;
};

typedef struct __string __string;
struct  __string {
  const char* s;
  uint64_t _size;
};

typedef char Array52[64];
typedef void(*builtins___mem_Func64_t)(void *);
typedef struct __mem __mem;
struct  __mem {
  _Atomic uint32_t refs;
  uint32_t magic;
  builtins___mem_Func64_t dctor;
};

typedef char Array169[32];
typedef char Array170[5];
typedef struct OptionalI_Tci32_E OptionalI_Tci32_E;
typedef struct Tuple235 {
  char _0;
  int32_t _1;
} Tuple235;

struct  OptionalI_Tci32_E {
  bool ok;
  struct Tuple235 val;
};

typedef struct __Closure4 __Closure4;
struct  __Closure4 {
  int32_t i;
  uint64_t _size;
  char * _data;
};

typedef struct EqualsCase EqualsCase;
struct  EqualsCase {
};

typedef struct HashCase HashCase;
struct  HashCase {
};

typedef struct Style Style;
struct  Style {
  int8_t color;
  int8_t _bg;
  bool _bold;
  bool _italics;
  bool _underline;
  bool _blink;
  bool _faded;
};

typedef int8_t Array395[64];
typedef struct OptionalI_Tsi32_E OptionalI_Tsi32_E;
typedef struct Tuple439 {
  const char* _0;
  int32_t _1;
} Tuple439;

struct  OptionalI_Tsi32_E {
  bool ok;
  struct Tuple439 val;
};

typedef struct __Closure15 __Closure15;
struct  __Closure15 {
  int32_t i;
  uint64_t len;
  const char* * data;
};

typedef struct OptionalI_TTsFU_ZVoid_ZException____i32_E OptionalI_TTsFU_ZVoid_ZException____i32_E;
typedef struct Tuple482 {
  struct Tuple418 _0;
  int32_t _1;
} Tuple482;

struct  OptionalI_TTsFU_ZVoid_ZException____i32_E {
  bool ok;
  struct Tuple482 val;
};

typedef struct __Closure19 __Closure19;
struct  __Closure19 {
  int32_t i;
  uint64_t len;
  struct Tuple418 * data;
};

static void builtins___init();
static void builtins_SliceI_TsFU_ZVoid_ZException____E_op__init(struct SliceI_TsFU_ZVoid_ZException____E * this, struct Tuple418 * data, uint64_t len);
static void builtins_SliceI_sE_op__init(struct SliceI_sE * this, const char* * data, uint64_t len);
static const char* builtins_TestFailed_what(struct TestFailed * this);
static struct OptionalI_u64E builtins_MemoryOutputStream_append(struct MemoryOutputStream * this, const char * str, uint64_t size);
static void builtins_Repeat_op__str(const struct Repeat * this, struct OutputStream * os);
static void builtins_Repeat_op__init(struct Repeat * this, char c, uint64_t count);
static struct OptionalI_u64E builtins_StdOutputStream_append(struct StdOutputStream * this, const char * str, uint64_t size);
static struct OptionalI_u64E builtins_BufferedOutputStream_append(struct BufferedOutputStream * this, const void * data, uint64_t size);
static void builtins_String_clear(struct String * this);
static struct OptionalI_u64E builtins_String_append(struct String * this, const char * str, uint64_t size);
static void builtins___string_op__initI_su64E(struct __string * this, const char* s, uint64_t size);
extern uint64_t strlen(const char* s);
extern int64_t sprintf(char * s, const char* fmt, ...);
extern int32_t strcmp(const char* s1, const char* s2);
extern int32_t strncmp(const char* s1, const char* s2, uint64_t len);
extern int32_t strcasecmp(const char* s1, const char* s2);
extern int32_t strncasecmp(const char* s1, const char* s2, uint64_t len);
extern const char* strerror(int32_t errnum);
extern void * memmove(void * dst, const void * src, uint64_t num);
extern void * memset(void * ptr, int32_t value, uint64_t num);
extern void * memcpy(void * dst, const void * src, uint64_t n);
extern int32_t memcmp(const void * lhs, const void * rhs, uint64_t n);
extern void * malloc(uint64_t s);
extern void * realloc(void * ptr, uint64_t s);
extern void free(void * ptr);
extern void abort();
extern void exit(int32_t code);
extern int32_t printf(const char* s, ...);
extern int64_t write(int32_t fd, const void * buf, uint64_t len);
extern int64_t strtoll(const char * str, const char * * endptr, int32_t base);
extern double strtod(const char * str, const char * * endptr);
extern int32_t toupper(int32_t c);
extern int32_t isspace(int32_t c);
extern int32_t isdigit(int32_t c);
extern int32_t isalpha(int32_t c);
extern int64_t sysconf(int32_t name);

static void builtins___cxy_assert_abort(const char* file, uint64_t line, uint64_t column) {
  Array52 buf = {};
  write((int32_t)2, (const void *)"assertion failed: ", (uint64_t)18);
  uint64_t _a25 = strlen(file);
  write((int32_t)2, (const void *)file, _a25);
  int64_t len = sprintf((char *)buf, ":%u:%u\n", line, column);
  write((int32_t)2, (const void *)buf, (uint64_t)len);
  abort();
}

__attribute__((always_inline))
static void __cxy_assert(bool cond, const char* file, uint64_t line, uint64_t column) {
  if (!cond) {
    builtins___cxy_assert_abort(file, line, column);
  }
}

extern int32_t * __errno_location();

static void __cxy_panic(const char* file, uint64_t line, uint64_t column, const char* msg) {
  Array52 buf = {};
  write((int32_t)2, (const void *)"panic: ", (uint64_t)7);
  uint64_t _a26 = strlen(msg);
  write((int32_t)2, (const void *)msg, _a26);
  write((int32_t)2, (const void *)"\n  @", (uint64_t)4);
  uint64_t _a27 = strlen(file);
  write((int32_t)2, (const void *)file, _a27);
  int64_t len = sprintf((char *)buf, ":%u:%u\n", line, column);
  write((int32_t)2, (const void *)buf, (uint64_t)len);
  abort();
}

__attribute__((always_inline))
static const char* builtins_strerr() {
  return strerror((__errno_location()[0]));
}

__attribute__((always_inline))
static uint16_t builtins___bswap16(uint16_t x) {
  return (((x >> 8) & 255) | ((x & 255) << 8));
}

__attribute__((always_inline))
static uint32_t builtins___bswap32(uint32_t x) {
  return (((x & 4278190080u) >> 24) | ((x & 16711680u) >> 8) | ((x & 65280u) << 8) | ((x & 255u) << 24));
}

__attribute__((always_inline))
static uint64_t builtins___bswap64(uint64_t x) {
  return (((x & 18374686479671623680u) >> 56) | ((x & 71776119061217280u) >> 40) | ((x & 280375465082880u) >> 24) | ((x & 1095216660480u) >> 8) | ((x & 4278190080u) << 8) | ((x & 16711680u) << 24) | ((x & 65280u) << 40) | ((x & 255u) << 56));
}

__attribute__((noinline)) __attribute__((optnone))
static void * __smart_ptr_alloc(uint64_t size, builtins___mem_Func64_t dctor) {
  uint64_t _a28 = size + sizeof(struct __mem);
  void * ptr = malloc(_a28);
  if (ptr == nullptr) {
    return (void *)ptr;
  }
  struct __mem * mem = (struct __mem *)ptr;
  mem->magic = 2930683566u;
  mem->refs = 1;
  mem->dctor = dctor;
  return (void *)(((uint8_t *)ptr) + sizeof(struct __mem));
}

__attribute__((noinline)) __attribute__((optnone))
static void * __smart_ptr_get(void * ptr) {
  if (ptr == nullptr) {
    return nullptr;
  }
  struct __mem * mem = (struct __mem *)(((uint8_t *)ptr) + (-sizeof(struct __mem)));
  if (mem->magic != 2930683566u) {
    {
      __cxy_panic("__builtins.cxy", 142u, 9u, "invalid pointer");
    };
  }
  mem->refs++;
  return ptr;
}

__attribute__((noinline)) __attribute__((optnone))
static bool __smart_ptr_drop(void * ptr) {
  if (ptr == nullptr) {
    return false;
  }
  struct __mem * mem = (struct __mem *)(((uint8_t *)ptr) + (-sizeof(struct __mem)));
  if (mem->magic != 2930683566u) {
    {
      __cxy_panic("__builtins.cxy", 155u, 9u, "invalid smart pointer");
    };
  }
  mem->refs--;
  if (mem->refs == 0) {
    if (mem->dctor != nullptr) {
      mem->dctor(ptr);
    }
    mem->magic = 0;
    free((void *)mem);
    return true;
  }
  return false;
}

__attribute__((always_inline))
static void * __calloc(uint64_t size) {
  void * _a29 = malloc(size);
  return memset(_a29, (int32_t)0, size);
}

__attribute__((always_inline))
static uint32_t builtins_hash_fnv1a_uint8(uint32_t h, uint8_t x) {
  return (h ^ x) * 16777619u;
}


static uint32_t builtins_hash_fnv1a_uint16(uint32_t h, uint16_t x) {
  uint8_t _a30 = (uint8_t)(x & 255);
  uint32_t _a31 = builtins_hash_fnv1a_uint8(h, _a30);
  uint8_t _a32 = (uint8_t)(x >> 8);
  return builtins_hash_fnv1a_uint8(_a31, _a32);
}


static uint32_t builtins_hash_fnv1a_uint32(uint32_t h, uint32_t x) {
  uint16_t _a33 = (uint16_t)(x & 65535);
  uint32_t _a34 = builtins_hash_fnv1a_uint16(h, _a33);
  uint16_t _a35 = (uint16_t)(x >> 16);
  return builtins_hash_fnv1a_uint16(_a34, _a35);
}


static uint32_t builtins_hash_fnv1a_uint64(uint32_t h, uint64_t x) {
  uint32_t _a36 = (uint32_t)(x & 4294967295);
  uint32_t _a37 = builtins_hash_fnv1a_uint32(h, _a36);
  uint32_t _a38 = (uint32_t)(x >> 32);
  return builtins_hash_fnv1a_uint32(_a37, _a38);
}


static uint32_t builtins_hash_fnv1a_ptr(uint32_t h, const void * ptr) {
  return builtins_hash_fnv1a_uint64(h, (uint64_t)ptr);
}


static uint32_t builtins_hash_fnv1a_string(uint32_t h, const char* str) {
  int8_t i = 0;
  while (str[i] != '\0') {
    {
      h = builtins_hash_fnv1a_uint8(h, (uint8_t)str[i]);
      i++;
    }
    
  }
  return h;
}


static uint32_t builtins_hash_fnv1a_n_string(uint32_t h, const char* str, uint64_t len) {
  int8_t i = 0;
  while (i < len) {
    {
      h = builtins_hash_fnv1a_uint8(h, (uint8_t)str[i]);
      i++;
    }
    
  }
  return h;
}


static uint32_t builtins_hash_fnv1a_string_n_igc(uint32_t h, const char * str, uint64_t len) {
  int8_t i = 0;
  while (i < len) {
    {
      int32_t c = toupper((int32_t)str[i]);
      h = builtins_hash_fnv1a_uint8(h, (uint8_t)c);
      i++;
    }
    
  }
  return h;
}


static uint32_t builtins_hash_fnv1a_string_igc(uint32_t h, const char* str) {
  int8_t i = 0;
  while (str[i] != '\0') {
    {
      int32_t c = toupper((int32_t)str[i]);
      h = builtins_hash_fnv1a_uint8(h, (uint8_t)c);
      i++;
    }
    
  }
  return h;
}


static uint32_t hash_fnv1a_bytes(uint32_t h, const void * ptr, uint64_t size) {
  const uint8_t * p = (const uint8_t *)ptr;
  {
    int64_t i = 0;
    while (i != size - 1) {
      {
        h = builtins_hash_fnv1a_uint8(h, p[i]);
      }
      i += 1;
    }
  }
  return h;
}

__attribute__((always_inline))
static void builtins_OptionalI_u64E_op__initI_E(struct OptionalI_u64E * this) {
  this->ok = false;
  {
    memset(&this->val, 0, sizeof(uint64_t));
  };
}

__attribute__((always_inline))
static void builtins_OptionalI_u64E_op__initI_u64E(struct OptionalI_u64E * this, uint64_t value) {
  this->val = value;
  this->ok = true;
}


static void builtins_OptionalI_u64E_op__destructor(struct OptionalI_u64E * this) {
  if (this->ok) {
    
  }
}

__attribute__((always_inline))
static struct OptionalI_u64E builtins_OptionalI_u64E_op__copy(struct OptionalI_u64E * this) {
  return (struct OptionalI_u64E){
    .ok = this->ok,
    .val = this->val
  };
}

__attribute__((always_inline))
static bool builtins_OptionalI_u64E_op__truthyI_E(struct OptionalI_u64E * this) {
  return this->ok;
}

__attribute__((always_inline))
static uint64_t builtins_OptionalI_u64E_op__derefI_E(struct OptionalI_u64E * this) {
  return this->val;
}

 __attribute__((optnone))
static uint64_t builtins_OptionalI_u64E_move(struct OptionalI_u64E * this) {
  this->ok = false;
  return this->val;
}

__attribute__((always_inline))
static uint64_t builtins_OptionalI_u64E_op__lor(struct OptionalI_u64E * this, uint64_t def) {
  return this->ok? builtins_OptionalI_u64E_move(this): def;
}

__attribute__((always_inline))
static bool builtins_OptionalI_u64E_op__truthyIc_E(const struct OptionalI_u64E * this) {
  return this->ok;
}

__attribute__((always_inline))
static uint64_t builtins_OptionalI_u64E_op__derefIc_E(const struct OptionalI_u64E * this) {
  return this->val;
}

__attribute__((always_inline))
static struct __string builtins___string_op__initCoverI_su64E(const char* s, uint64_t size) {
  struct __string __obj1 = (struct __string){
    .s = (const char*) {},
    ._size = (uint64_t)0
  };
  builtins___string_op__initI_su64E(&__obj1, s, size);
  return __obj1;
}

__attribute__((always_inline))
static struct OptionalI_u64E builtins_SomeI_u64E(uint64_t value) {
  return (struct OptionalI_u64E){
    .ok = true,
    .val = value
  };
}

__attribute__((always_inline))
static struct OptionalI_u64E builtins_OptionalI_u64E_op__initCover() {
  struct OptionalI_u64E __obj2 = (struct OptionalI_u64E){
    .ok = false
  };
  builtins_OptionalI_u64E_op__initI_E(&__obj2);
  return __obj2;
}

__attribute__((always_inline))
static struct OptionalI_u64E builtins_NoneI_u64E() {
  return builtins_OptionalI_u64E_op__initCover();
}

__attribute__((always_inline))
static void builtins___string_op__initI_E(struct __string * this) {
  
}

__attribute__((always_inline))
static void builtins___string_op__initI_sE(struct __string * this, const char* s) {
  this->s = s;
  if (((void *)s) != nullptr) {
    this->_size = strlen(s);
  }
}


static void builtins___string_op__initI_su64E(struct __string * this, const char* s, uint64_t size) {
  this->s = s;
  this->_size = size;
}


static struct __string builtins___string_trimLeft(const struct __string * this) {
  uint64_t i = 0u;
  while (i < this->_size && (isspace((int32_t)this->s[i]) != 0)) {
    {
      i++;
    }
    
  }
  if (i != 0) {
    const char * p = (const char *)this->s + i;
    uint64_t _a39 = this->_size - i;
    return builtins___string_op__initCoverI_su64E((const char*)p, _a39);
  }
  return builtins___string_op__initCoverI_su64E(this->s, this->_size);
}


static struct __string builtins___string_trimRight(const struct __string * this) {
  uint64_t i = this->_size;
  while (i > 0) {
    {
      uint64_t _idx40 = i - 1;
      if (!(isspace((int32_t)this->s[_idx40]) != 0)) {
        break;
      }
      i--;
    }
    
  }
  return builtins___string_op__initCoverI_su64E(this->s, i);
}

__attribute__((always_inline))
static struct __string builtins___string_trim(const struct __string * this) {
  struct __string _m41 = builtins___string_trimLeft(this);
  return builtins___string_trimRight(&_m41);
}


static int32_t builtins___string_compare(const struct __string * this, struct __string * other) {
  if (this->_size == other->_size) {
    return strncmp(this->s, other->s, this->_size);
  } else if (this->_size < other->_size) {
    return -1;
  } else {
    return 1;
  }
}

__attribute__((always_inline))
static bool builtins___string_op__eq(const struct __string * this, struct __string * other) {
  return builtins___string_compare(this, other) == 0;
}

__attribute__((always_inline))
static bool builtins___string_op__neq(const struct __string * this, struct __string * other) {
  return builtins___string_compare(this, other) != 0;
}

__attribute__((always_inline))
static bool builtins___string_op__lt(const struct __string * this, struct __string * other) {
  return builtins___string_compare(this, other) < 0;
}

__attribute__((always_inline))
static bool builtins___string_op__leq(const struct __string * this, struct __string * other) {
  return builtins___string_compare(this, other) <= 0;
}

__attribute__((always_inline))
static bool builtins___string_op__gt(const struct __string * this, struct __string * other) {
  return builtins___string_compare(this, other) > 0;
}

__attribute__((always_inline))
static bool builtins___string_op__geq(const struct __string * this, struct __string * other) {
  return builtins___string_compare(this, other) >= 0;
}

__attribute__((always_inline))
static char builtins___string_op__idx(const struct __string * this, int64_t idx) {
  return this->s[idx];
}

__attribute__((always_inline))
static uint32_t builtins___string_op__hash(const struct __string * this) {
  return builtins_hash_fnv1a_n_string(16777619u, this->s, this->_size);
}

__attribute__((always_inline))
static struct __string builtins___string_op__copy(const struct __string * this) {
  return builtins___string_op__initCoverI_su64E(this->s, this->_size);
}

__attribute__((always_inline))
static uint64_t builtins___string_size(const struct __string * this) {
  return this->_size;
}

__attribute__((always_inline))
static const char * builtins___string_data(const struct __string * this) {
  return (const char *)this->s;
}

__attribute__((always_inline))
static const char* builtins___string_str(const struct __string * this) {
  return this->s;
}

__attribute__((always_inline))
static bool builtins___string_empty(const struct __string * this) {
  return this->_size == 0;
}

__attribute__((always_inline))
static bool builtins___string_isnt(const struct __string * this) {
  return !builtins___string_empty(this) && this->s[this->_size] == '\0';
}


static struct __string builtins___string_substr(const struct __string * this, uint64_t start, int64_t count) {
  {
    bool _a42 = start <= this->_size;
    __cxy_assert(_a42, "__builtins.cxy", 454u, 9u);
  };
  if (count == -1) {
    count = (int64_t)(this->_size - start);
  } else {
    {
      bool _a43 = count >= 0 && count <= (this->_size - start);
      __cxy_assert(_a43, "__builtins.cxy", 458u, 13u);
    };
  }
  const char * q = (const char *)this->s;
  const char* _a44 = (const char*)q + start;
  return builtins___string_op__initCoverI_su64E(_a44, (uint64_t)count);
}


static void builtins___string_copyto(const struct __string * this, char * buf, uint64_t size) {
  {
    bool _a45 = size > this->_size;
    __cxy_assert(_a45, "__builtins.cxy", 464u, 9u);
  };
  memcpy((void *)buf, (const void *)(void *)this->s, this->_size);
  buf[this->_size] = '\0';
}


static struct OptionalI_u64E builtins___string_indexOf(struct __string * this, char ch) {
  uint64_t i = 0u;
  while (i < this->_size) {
    {
      if (this->s[i] == ch) {
        return builtins_SomeI_u64E(i);
      }
      i++;
    }
    
  }
  return builtins_NoneI_u64E();
}


static struct OptionalI_u64E builtins___string_rIndexOf(struct __string * this, char ch) {
  if (this->_size == 0) {
    return builtins_NoneI_u64E();
  }
  uint64_t i = this->_size - 1;
  while (i > 0) {
    {
      if (this->s[i] == ch) {
        return builtins_SomeI_u64E(i);
      }
      i--;
    }
    
  }
  return builtins_NoneI_u64E();
}


static bool builtins___string_endswith(const struct __string * this, struct __string suffix) {
  if (builtins___string_size(&suffix) > builtins___string_size(this)) {
    return false;
  }
  uint64_t _a46 = builtins___string_size(this) - builtins___string_size(&suffix);
  struct __string _m47 = builtins___string_substr(this, _a46, (int64_t)-1);
  return builtins___string_op__eq(&_m47, &suffix);
}


static bool builtins___string_startswith(const struct __string * this, struct __string suffix) {
  if (builtins___string_size(&suffix) > builtins___string_size(this)) {
    return false;
  }
  int64_t _a48 = (int64_t)builtins___string_size(&suffix);
  struct __string _m49 = builtins___string_substr(this, 0u, _a48);
  return builtins___string_op__eq(&_m49, &suffix);
}


static struct OptionalI_u64E builtins___string_find(const struct __string * this, struct __string part) {
  if (builtins___string_empty(&part)) {
    uint64_t _a50 = this->_size - 1;
    return builtins___string_empty(this)? builtins_NoneI_u64E(): builtins_SomeI_u64E(_a50);
  }
  uint64_t i = this->_size;
  uint64_t j = 0u;
  const char * p = (const char *)this->s;
  while (i >= part._size) {
    {
      i--;
      const void * _a51 = (const void *)p + j;
      if (memcmp(_a51, (const void *)part.s, part._size) == 0) {
        return builtins_SomeI_u64E(j);
      }
      j++;
    }
    
  }
  return builtins_NoneI_u64E();
}


static struct OptionalI_u64E builtins___string_rfind(const struct __string * this, struct __string part) {
  if (this->_size >= part._size) {
    if (builtins___string_empty(&part)) {
      uint64_t _a52 = this->_size - 1;
      return builtins___string_empty(this)? builtins_NoneI_u64E(): builtins_SomeI_u64E(_a52);
    }
    int64_t j = (int64_t)(this->_size - part._size);
    const char * p = (const char *)this->s;
    while (j >= 0) {
      {
        const void * _a53 = (const void *)p + j;
        if (memcmp(_a53, (const void *)part.s, part._size) == 0) {
          return builtins_SomeI_u64E((uint64_t)j);
        }
        j--;
      }
      
    }
  }
  return builtins_NoneI_u64E();
}

struct OutputStream_VTable OutputStream_vTable = (struct OutputStream_VTable){
  .append = (builtins_OutputStream_append_t) {}
};
__attribute__((always_inline))
static void builtins_OutputStream_appendStringI_sE(struct OutputStream * this, const char* s) {
  if (s != nullptr) {
    uint64_t _a54 = strlen(s);
    this->vtable->append(this, (const void *)s, _a54);
  }
}

__attribute__((always_inline))
static void builtins_OutputStream_appendStringI_cRZ__string_E(struct OutputStream * this, const struct __string * s) {
  uint64_t _a55 = builtins___string_size(s);
  this->vtable->append(this, (const void *)s->s, _a55);
}


static void builtins_OutputStream_appendSignedInt(struct OutputStream * this, int64_t num) {
  Array52 buf = {};
  int64_t len = sprintf((char *)buf, "%lld", num);
  this->vtable->append(this, (const void *)buf, (uint64_t)len);
}


static void builtins_OutputStream_appendUnSignedInt(struct OutputStream * this, uint64_t num) {
  Array169 buf = {};
  int64_t len = sprintf((char *)buf, "%llu", num);
  this->vtable->append(this, (const void *)buf, (uint64_t)len);
}


static void builtins_OutputStream_appendFloat(struct OutputStream * this, double num) {
  Array169 data = {};
  int64_t len = sprintf((char *)data, "%g", num);
  this->vtable->append(this, (const void *)data, (uint64_t)len);
}


static void builtins_OutputStream_appendChar(struct OutputStream * this, wchar_t ch) {
  Array170 data = {};
  uint64_t size = 0;
  if (ch < 128) {
    data[0] = (char)ch;
    size = 1;
  } else if (ch < 2048) {
    data[0] = (char)(192 | (ch >> 6));
    data[1] = (char)(128 | (ch & 63));
    size = 2;
  } else if (ch < 65536) {
    data[0] = (char)(224 | (ch >> 12));
    data[1] = (char)(128 | ((ch >> 6) & 63));
    data[2] = (char)(128 | (ch & 63));
    size = 3;
  } else if (ch < 2097152) {
    data[0] = (char)(240 | (ch >> 16));
    data[1] = (char)(128 | ((ch >> 12) & 63));
    data[2] = (char)(128 | ((ch >> 6) & 63));
    data[3] = (char)(128 | (ch & 63));
    size = 4;
  } else {
    
  }
  this->vtable->append(this, (const void *)data, size);
}

__attribute__((always_inline))
static void builtins_OutputStream_appendBool(struct OutputStream * this, bool val) {
  if (val) {
    this->vtable->append(this, (const void *)"true", 4u);
  } else {
    this->vtable->append(this, (const void *)"false", 5u);
  }
}


static void builtins_OutputStream___defaults_init(struct OutputStream * this) {
  this->vtable = &OutputStream_vTable;
}

__attribute__((always_inline))
static uint64_t builtins_maxI_u64E(uint64_t a, uint64_t b) {
  return a > b? a: b;
}

__attribute__((always_inline))
static void builtins_OptionalI_Tci32_E_op__initI_E(struct OptionalI_Tci32_E * this) {
  this->ok = false;
  {
    memset(&this->val, 0, sizeof(struct Tuple235));
  };
}

__attribute__((always_inline))
static void builtins_OptionalI_Tci32_E_op__initI_Tci32_E(struct OptionalI_Tci32_E * this, struct Tuple235 value) {
  this->val = value;
  this->ok = true;
}


static void builtins_OptionalI_Tci32_E_op__destructor(struct OptionalI_Tci32_E * this) {
  if (this->ok) {
    
  }
}

__attribute__((always_inline))
static struct OptionalI_Tci32_E builtins_OptionalI_Tci32_E_op__copy(struct OptionalI_Tci32_E * this) {
  return (struct OptionalI_Tci32_E){
    .ok = this->ok,
    .val = this->val
  };
}

__attribute__((always_inline))
static bool builtins_OptionalI_Tci32_E_op__truthyI_E(struct OptionalI_Tci32_E * this) {
  return this->ok;
}

__attribute__((always_inline))
static struct Tuple235 builtins_OptionalI_Tci32_E_op__derefI_E(struct OptionalI_Tci32_E * this) {
  return this->val;
}

 __attribute__((optnone))
static struct Tuple235 builtins_OptionalI_Tci32_E_move(struct OptionalI_Tci32_E * this) {
  this->ok = false;
  return this->val;
}

__attribute__((always_inline))
static struct Tuple235 builtins_OptionalI_Tci32_E_op__lor(struct OptionalI_Tci32_E * this, struct Tuple235 def) {
  return this->ok? builtins_OptionalI_Tci32_E_move(this): def;
}

__attribute__((always_inline))
static bool builtins_OptionalI_Tci32_E_op__truthyIc_E(const struct OptionalI_Tci32_E * this) {
  return this->ok;
}

__attribute__((always_inline))
static struct Tuple235 builtins_OptionalI_Tci32_E_op__derefIc_E(const struct OptionalI_Tci32_E * this) {
  return this->val;
}

__attribute__((always_inline))
static struct OptionalI_Tci32_E builtins_SomeI_Tci32_E(struct Tuple235 value) {
  return (struct OptionalI_Tci32_E){
    .ok = true,
    .val = value
  };
}

__attribute__((always_inline))
static struct OptionalI_Tci32_E builtins_OptionalI_Tci32_E_op__initCover() {
  struct OptionalI_Tci32_E __obj3 = (struct OptionalI_Tci32_E){
    .ok = false
  };
  builtins_OptionalI_Tci32_E_op__initI_E(&__obj3);
  return __obj3;
}

__attribute__((always_inline))
static struct OptionalI_Tci32_E builtins_NoneI_Tci32_E() {
  return builtins_OptionalI_Tci32_E_op__initCover();
}


static struct OptionalI_Tci32_E __Closure4_op__call(struct __Closure4 * this) {
  if (this->i < this->_size) {
    struct Tuple235 _a56 = (struct Tuple235){
      ._0 = this->_data[this->i],
      ._1 = this->i++
    };
    return builtins_SomeI_Tci32_E(_a56);
  } else {
    return builtins_NoneI_Tci32_E();
  }
}


static void __Closure4_op__init(struct __Closure4 * this) {
  
}

__attribute__((always_inline))
static struct __string builtins___string_op__initCoverI_sE(const char* s) {
  struct __string __obj6 = (struct __string){
    .s = (const char*) {},
    ._size = (uint64_t)0
  };
  builtins___string_op__initI_sE(&__obj6, s);
  return __obj6;
}

struct OutputStream_VTable String_vTable = (struct OutputStream_VTable){
  .append = (builtins_OutputStream_append_t)builtins_String_append
};

static void builtins_String_grow(struct String * this, uint64_t growSize) {
  uint64_t _a57 = this->_size + growSize;
  uint64_t newSize = builtins_maxI_u64E(_a57, 16u);
  if (this->_data == nullptr) {
    uint64_t _a58 = newSize + 1;
    this->_data = (char *)malloc(_a58);
    this->_capacity = newSize;
  } else if (this->_capacity < newSize) {
    while (this->_capacity < newSize) {
      {
        this->_capacity <<= 1;
      }
      
    }
    uint64_t _a59 = this->_capacity + 1;
    this->_data = (char *)realloc((void *)this->_data, _a59);
  }
}

__attribute__((always_inline))
static void builtins_String_op__initI_E(struct String * this) {
  
}

__attribute__((always_inline))
static void builtins_String_op__initI_sE(struct String * this, const char* str) {
  builtins_OutputStream_appendStringI_sE((struct OutputStream *)this, str);
}

__attribute__((always_inline))
static void builtins_String_op__initI_cPcu64E(struct String * this, const char * str, uint64_t len) {
  builtins_String_append(this, str, len);
}

__attribute__((always_inline))
static void builtins_String_op__initI_Z__string_E(struct String * this, struct __string str) {
  builtins_OutputStream_appendStringI_cRZ__string_E((struct OutputStream *)this, (const struct __string *)&str);
}

__attribute__((always_inline))
static void builtins_String_op__destructor(struct String * this) {
  builtins_String_clear(this);
}


static void builtins_String_op__destructor_fwd(void * ptr) {
  builtins_String_op__destructor(((struct String *)ptr));
}


static char * builtins_String_head(struct String * this) {
  return this->_data;
}


static char * builtins_String_tail(struct String * this) {
  return this->_data + this->_size;
}


static char * builtins_String_reserve(struct String * this, uint64_t size) {
  builtins_String_grow(this, size);
  return builtins_String_tail(this);
}


static void builtins_String_resize(struct String * this, uint64_t newSize) {
  {
    bool _a60 = this->_capacity <= newSize;
    __cxy_assert(_a60, "__builtins.cxy", 804u, 9u);
  };
  this->_size = newSize;
  this->_data[this->_size] = '\0';
}


static void builtins_String_clear(struct String * this) {
  if (this->_data != nullptr) {
    free((void *)this->_data);
    this->_data = nullptr;
    this->_capacity = 0;
    this->_size = 0;
  }
}


static struct OptionalI_u64E builtins_String_append(struct String * this, const char * str, uint64_t size) {
  if (size != 0u) {
    builtins_String_grow(this, size);
    char * p = this->_data + this->_size;
    memmove((void *)p, (const void *)str, size);
    this->_size += size;
    this->_data[this->_size] = '\0';
  }
  return builtins_SomeI_u64E(size);
}


static void builtins_String_trimLeft(struct String * this) {
  uint64_t i = 0u;
  while (i < this->_size && (isspace((int32_t)this->_data[i]) != 0)) {
    {
      i++;
    }
    
  }
  if (i != 0) {
    char * p = this->_data + i;
    uint64_t _a61 = this->_size - i;
    memmove((void *)this->_data, (const void *)p, _a61);
    this->_size = this->_size - i;
  }
}


static void builtins_String_trimRight(struct String * this) {
  while (this->_size > 0) {
    {
      uint64_t _idx62 = this->_size - 1;
      if (!(isspace((int32_t)this->_data[_idx62]) != 0)) {
        break;
      }
      this->_size--;
    }
    
  }
  if (this->_capacity > 0) {
    this->_data[this->_size] = '\0';
  }
}

__attribute__((always_inline))
static void builtins_String_trim(struct String * this) {
  builtins_String_trimLeft(this);
  builtins_String_trimRight(this);
}


static struct OptionalI_u64E builtins_String_indexOf(const struct String * this, char ch) {
  uint64_t i = 0u;
  while (i < this->_size) {
    {
      if (this->_data[i] == ch) {
        return builtins_SomeI_u64E(i);
      }
      i++;
    }
    
  }
  return builtins_NoneI_u64E();
}


static struct OptionalI_u64E builtins_String_rIndexOf(const struct String * this, char ch) {
  if (this->_size == 0) {
    return builtins_NoneI_u64E();
  }
  uint64_t i = this->_size - 1;
  while (i > 0) {
    {
      if (this->_data[i] == ch) {
        return builtins_SomeI_u64E(i);
      }
      i--;
    }
    
  }
  return builtins_NoneI_u64E();
}

__attribute__((always_inline))
static void builtins_String_op__str(const struct String * this, struct OutputStream * sb) {
  sb->vtable->append(sb, (const void *)this->_data, this->_size);
}

__attribute__((always_inline))
static uint32_t builtins_String_op__hash(const struct String * this) {
  if (this->_data != nullptr) {
    return hash_fnv1a_bytes(16777619u, (const void *)this->_data, this->_size);
  } else {
    return 16777619u;
  }
}


static int32_t builtins_String_compareIc_cPcu64E(const struct String * this, const char * other, uint64_t size) {
  if (this->_size != size) {
    return (int32_t)(this->_size - size);
  }
  {
    int64_t i = 0;
    while (i != this->_size) {
      {
        if (this->_data[i] != other[i]) {
          return ((int32_t)this->_data[i]) - ((int32_t)other[i]);
        }
      }
      i += 1;
    }
  }
  return 0;
}

__attribute__((always_inline))
static int32_t builtins_String_compareIc_cRZString_E(const struct String * this, const struct String * other) {
  return builtins_String_compareIc_cPcu64E(this, (const char *)other->_data, other->_size);
}

__attribute__((always_inline))
static int32_t builtins_String_compareIc_csE(const struct String * this, const char* other) {
  uint64_t _a63 = strlen(other);
  return builtins_String_compareIc_cPcu64E(this, (const char *)other, _a63);
}

__attribute__((always_inline))
static bool builtins_String_op__eqIc_cRZString_E(const struct String * this, const struct String * other) {
  return builtins_String_compareIc_cRZString_E(this, other) == 0;
}

__attribute__((always_inline))
static bool builtins_String_op__neqIc_cRZString_E(const struct String * this, const struct String * other) {
  return builtins_String_compareIc_cRZString_E(this, other) != 0;
}

__attribute__((always_inline))
static bool builtins_String_op__ltIc_cRZString_E(const struct String * this, const struct String * other) {
  return builtins_String_compareIc_cRZString_E(this, other) < 0;
}

__attribute__((always_inline))
static bool builtins_String_op__gtIc_cRZString_E(const struct String * this, const struct String * other) {
  return builtins_String_compareIc_cRZString_E(this, other) > 0;
}

__attribute__((always_inline))
static bool builtins_String_op__leqIc_cRZString_E(const struct String * this, const struct String * other) {
  return builtins_String_compareIc_cRZString_E(this, other) <= 0;
}

__attribute__((always_inline))
static bool builtins_String_op__geqIc_cRZString_E(const struct String * this, const struct String * other) {
  return builtins_String_compareIc_cRZString_E(this, other) >= 0;
}

__attribute__((always_inline))
static bool builtins_String_op__eqIc_csE(const struct String * this, const char* other) {
  return builtins_String_compareIc_csE(this, other) == 0;
}

__attribute__((always_inline))
static bool builtins_String_op__neqIc_csE(const struct String * this, const char* other) {
  return builtins_String_compareIc_csE(this, other) != 0;
}

__attribute__((always_inline))
static bool builtins_String_op__ltIc_csE(const struct String * this, const char* other) {
  return builtins_String_compareIc_csE(this, other) < 0;
}

__attribute__((always_inline))
static bool builtins_String_op__gtIc_csE(const struct String * this, const char* other) {
  return builtins_String_compareIc_csE(this, other) > 0;
}

__attribute__((always_inline))
static bool builtins_String_op__leqIc_csE(const struct String * this, const char* other) {
  return builtins_String_compareIc_csE(this, other) <= 0;
}

__attribute__((always_inline))
static bool builtins_String_op__geqIc_csE(const struct String * this, const char* other) {
  return builtins_String_compareIc_csE(this, other) >= 0;
}

__attribute__((always_inline))
static char builtins_String_op__idx(const struct String * this, uint32_t idx) {
  {
    bool _a64 = idx < this->_size;
    __cxy_assert(_a64, "__builtins.cxy", 955u, 9u);
  };
  return this->_data[idx];
}


static struct __Closure4 * builtins_String_op__range(const struct String * this) {
  int32_t i = 0;
  return ({
    struct __Closure4 * __obj5 = (struct __Closure4 *)__smart_ptr_alloc(sizeof(__Closure4), nullptr);
    __obj5->i = i;
    __obj5->_size = this->_size;
    __obj5->_data = this->_data;
    __obj5;
  });
}

__attribute__((always_inline))
static uint64_t builtins_String_size(const struct String * this) {
  return this->_size;
}

__attribute__((always_inline))
static uint64_t builtins_String_capacity(const struct String * this) {
  return this->_capacity;
}

__attribute__((always_inline))
static char * builtins_String_data(const struct String * this) {
  return this->_data;
}

__attribute__((always_inline))
static bool builtins_String_empty(const struct String * this) {
  return this->_size == 0;
}

__attribute__((always_inline))
static const char* builtins_String_str(const struct String * this) {
  return (const char*)this->_data;
}

__attribute__((always_inline))
static struct __string builtins_String___str(const struct String * this) {
  return builtins___string_op__initCoverI_su64E((const char*)this->_data, this->_size);
}

__attribute__((always_inline))
static struct __string builtins_String_substr(const struct String * this, uint64_t start, int64_t count) {
  struct __string _m65 = builtins_String___str(this);
  return builtins___string_substr(&_m65, start, count);
}

__attribute__((always_inline))
static bool builtins_String_endswithIc_ZString_E(const struct String * this, struct String * suffix) {
  struct __string _m66 = builtins_String___str(this);
  struct __string _a67 = builtins_String___str(suffix);
  return builtins___string_endswith(&_m66, _a67);
}

__attribute__((always_inline))
static bool builtins_String_endswithIc_Z__string_E(const struct String * this, struct __string suffix) {
  struct __string _m68 = builtins_String___str(this);
  return builtins___string_endswith(&_m68, suffix);
}

__attribute__((always_inline))
static bool builtins_String_endswithIc_sE(const struct String * this, const char* suffix) {
  struct __string _m69 = builtins_String___str(this);
  struct __string _a70 = builtins___string_op__initCoverI_sE(suffix);
  return builtins___string_endswith(&_m69, _a70);
}

__attribute__((always_inline))
static bool builtins_String_startswithIc_ZString_E(const struct String * this, struct String * suffix) {
  struct __string _m71 = builtins_String___str(this);
  struct __string _a72 = builtins_String___str(suffix);
  return builtins___string_startswith(&_m71, _a72);
}

__attribute__((always_inline))
static bool builtins_String_startswithIc_Z__string_E(const struct String * this, struct __string suffix) {
  struct __string _m73 = builtins_String___str(this);
  return builtins___string_startswith(&_m73, suffix);
}

__attribute__((always_inline))
static bool builtins_String_startswithIc_sE(const struct String * this, const char* suffix) {
  struct __string _m74 = builtins_String___str(this);
  struct __string _a75 = builtins___string_op__initCoverI_sE(suffix);
  return builtins___string_startswith(&_m74, _a75);
}


static void builtins_String___defaults_init(struct String * this) {
  this->_capacity = 0;
  this->_size = 0;
  this->_data = nullptr;
  this->vtable = &String_vTable;
}

struct BufferedOutputStream_VTable BufferedOutputStream_vTable = (struct BufferedOutputStream_VTable){
  .append = (builtins_OutputStream_append_t)builtins_BufferedOutputStream_append,
  .flush = (builtins_BufferedOutputStream_flush_t) {}
};

static void builtins_BufferedOutputStream_op__init(struct BufferedOutputStream * this, uint64_t capacity) {
  this->_capacity = capacity;
  this->_size = 0;
  this->_buffer = (char *)malloc(capacity);
}


static void builtins_BufferedOutputStream_sync(struct BufferedOutputStream * this) {
  if (this->_size > 0) {
    this->vtable->flush(this, (const void *)this->_buffer, this->_size);
    this->_size = 0;
  }
}


static struct OptionalI_u64E builtins_BufferedOutputStream_append(struct BufferedOutputStream * this, const void * data, uint64_t size) {
  uint64_t room = this->_capacity - this->_size;
  if (size > room && this->_size > 0) {
    builtins_BufferedOutputStream_sync(this);
    room = this->_capacity;
  }
  if (size < room) {
    const char * src = (const char *)data;
    memcpy((void *)&this->_buffer[this->_size], (const void *)src, size);
    this->_size += size;
  } else {
    this->vtable->flush(this, data, size);
  }
  return builtins_SomeI_u64E(size);
}

__attribute__((always_inline))
static void builtins_BufferedOutputStream_op__destructor(struct BufferedOutputStream * this) {
  if (this->_buffer != nullptr) {
    builtins_BufferedOutputStream_sync(this);
    free((void *)this->_buffer);
    this->_buffer = nullptr;
  }
}


static void builtins_BufferedOutputStream_op__destructor_fwd(void * ptr) {
  builtins_BufferedOutputStream_op__destructor(((struct BufferedOutputStream *)ptr));
}


static void builtins_BufferedOutputStream___defaults_init(struct BufferedOutputStream * this) {
  this->vtable = &BufferedOutputStream_vTable;
}

struct OutputStream_VTable StdOutputStream_vTable = (struct OutputStream_VTable){
  .append = (builtins_OutputStream_append_t)builtins_StdOutputStream_append
};

static void builtins_StdOutputStream_op__init(struct StdOutputStream * this, int32_t fd) {
  this->fd = fd;
}


static struct OptionalI_u64E builtins_StdOutputStream_append(struct StdOutputStream * this, const char * str, uint64_t size) {
  if (size != 0u) {
    write(this->fd, (const void *)str, size);
  }
  return builtins_SomeI_u64E(size);
}


static void builtins_StdOutputStream___defaults_init(struct StdOutputStream * this) {
  this->vtable = &StdOutputStream_vTable;
}

__attribute__((always_inline))
static struct StdOutputStream * builtins_StdOutputStream_op__initCover(int32_t fd) {
  struct StdOutputStream * __obj7 = (struct StdOutputStream *)__smart_ptr_alloc(sizeof(StdOutputStream), nullptr);
  memset(__obj7, 0, sizeof(StdOutputStream));
  builtins_StdOutputStream___defaults_init(__obj7);
  builtins_StdOutputStream_op__init(__obj7, fd);
  return __obj7;
}

struct OutputStream * builtins_stdout = nullptr;
struct OutputStream * builtins_stderr = nullptr;
int64_t builtins_SysConfPageSize = {};
int64_t builtins_SysConfNumProcs = {};
__attribute__((always_inline))
static bool builtins_EqualsCase_op__callIc_cRZString_cRZString_E(const struct EqualsCase * this, const struct String * lhs, const struct String * rhs) {
  const char* _a76 = builtins_String_str(lhs);
  const char* _a77 = builtins_String_str(rhs);
  uint64_t _a78 = builtins_String_size(lhs);
  return builtins_String_size(lhs) == builtins_String_size(rhs) && strncasecmp(_a76, _a77, _a78) == 0;
}

__attribute__((always_inline))
static bool builtins_EqualsCase_op__callIc_cscsE(const struct EqualsCase * this, const char* lhs, const char* rhs) {
  return strcasecmp(lhs, rhs) == 0;
}

__attribute__((always_inline))
static bool builtins_EqualsCase_op__callIc_cRZ__string_cRZ__string_E(const struct EqualsCase * this, const struct __string * lhs, const struct __string * rhs) {
  const char* _a79 = builtins___string_str(lhs);
  const char* _a80 = builtins___string_str(rhs);
  uint64_t _a81 = builtins___string_size(lhs);
  return builtins___string_size(lhs) == builtins___string_size(rhs) && strncasecmp(_a79, _a80, _a81) == 0;
}

__attribute__((always_inline))
static uint32_t builtins_HashCase_op__callIc_cRZString_E(const struct HashCase * this, const struct String * value) {
  char * _a82 = builtins_String_data(value);
  uint64_t _a83 = builtins_String_size(value);
  return builtins_hash_fnv1a_string_n_igc(16777619u, (const char *)_a82, _a83);
}

__attribute__((always_inline))
static uint32_t builtins_HashCase_op__callIc_cRZ__string_E(const struct HashCase * this, const struct __string * value) {
  const char * _a84 = builtins___string_data(value);
  uint64_t _a85 = builtins___string_size(value);
  return builtins_hash_fnv1a_string_n_igc(16777619u, _a84, _a85);
}

__attribute__((always_inline))
static uint32_t builtins_HashCase_op__callIc_csE(const struct HashCase * this, const char* value) {
  return builtins_hash_fnv1a_string_igc(16777619u, value);
}


static struct OutputStream * builtins_OutputStream_op__lshiftI_sE(struct OutputStream * this, const char* val) {
  builtins_OutputStream_appendStringI_sE(this, val);
  return this;
}


static struct OutputStream * builtins_OutputStream_op__lshiftI_u64E(struct OutputStream * this, const uint64_t val) {
  builtins_OutputStream_appendSignedInt(this, (int64_t)val);
  return this;
}


static void builtins_CallTrace_op__str(const struct CallTrace * this, struct OutputStream * os) {
  if (this->mod != nullptr) {
    struct OutputStream * _m86 = builtins_OutputStream_op__lshiftI_sE(os, this->mod);
    builtins_OutputStream_op__lshiftI_sE(_m86, "::");
  }
  if (this->cls != nullptr) {
    struct OutputStream * _m87 = builtins_OutputStream_op__lshiftI_sE(os, this->cls);
    builtins_OutputStream_op__lshiftI_sE(_m87, "::");
  }
  if (this->fun != nullptr) {
    builtins_OutputStream_op__lshiftI_sE(os, this->fun);
  }
  builtins_OutputStream_op__lshiftI_sE(os, " (");
  if (this->path != nullptr) {
    builtins_OutputStream_op__lshiftI_sE(os, this->path);
  } else {
    builtins_OutputStream_op__lshiftI_sE(os, "<builtin>");
  }
  struct OutputStream * _m88 = builtins_OutputStream_op__lshiftI_sE(os, ":");
  struct OutputStream * _m89 = builtins_OutputStream_op__lshiftI_u64E(_m88, this->line);
  builtins_OutputStream_op__lshiftI_sE(_m89, ")");
}


static struct OutputStream * builtins_OutputStream_op__lshiftI_cE(struct OutputStream * this, const char val) {
  builtins_OutputStream_appendChar(this, (wchar_t)val);
  return this;
}

__attribute__((always_inline))
static struct Repeat builtins_Repeat_op__initCover(char c, uint64_t count) {
  struct Repeat __obj8 = (struct Repeat){};
  builtins_Repeat_op__init(&__obj8, c, count);
  return __obj8;
}


static struct OutputStream * builtins_OutputStream_op__lshiftI_ZRepeat_E(struct OutputStream * this, const struct Repeat * val) {
  builtins_Repeat_op__str(val, this);
  return this;
}


static struct OutputStream * builtins_OutputStream_op__lshiftI_ZCallTrace_E(struct OutputStream * this, const struct CallTrace * val) {
  builtins_CallTrace_op__str(val, this);
  return this;
}


static void builtins_StackTrace_grow(struct StackTrace * this) {
  if (this->size >= this->capacity) {
    if (this->capacity == 0) {
      this->capacity = 8;
    } else {
      this->capacity <<= 1;
    }
    uint64_t _a90 = sizeof(struct CallTrace) * this->capacity;
    this->calls = (struct CallTrace *)realloc((void *)this->calls, _a90);
  }
}


static void builtins_StackTrace_op__init(struct StackTrace * this) {
  builtins_StackTrace_grow(this);
}


static void builtins_StackTrace_push(struct StackTrace * this, const char* mod, const char* cls, const char* fun, const char* path, uint64_t line) {
  builtins_StackTrace_grow(this);
  this->calls[this->size] = (struct CallTrace){
    .mod = mod,
    .cls = cls,
    .fun = fun,
    .path = path,
    .line = line
  };
  this->size++;
}


static void builtins_StackTrace_dump(const struct StackTrace * this, struct OutputStream * os, int64_t s, uint64_t tabs) {
  struct Repeat sp = builtins_Repeat_op__initCover((char)' ', tabs);
  {
    int64_t i = s;
    while (i != this->size) {
      {
        struct OutputStream * _m91 = builtins_OutputStream_op__lshiftI_sE(os, "\n ");
        struct OutputStream * _m92 = builtins_OutputStream_op__lshiftI_ZRepeat_E(_m91, &sp);
        builtins_OutputStream_op__lshiftI_ZCallTrace_E(_m92, &this->calls[i]);
      }
      i += 1;
    }
  }
}


static void builtins_StackTrace_op__str(const struct StackTrace * this, struct OutputStream * os) {
  {
    int64_t i = 0;
    while (i != this->size) {
      {
        struct OutputStream * _m93 = builtins_OutputStream_op__lshiftI_sE(os, "\n ");
        builtins_OutputStream_op__lshiftI_ZCallTrace_E(_m93, &this->calls[i]);
      }
      i += 1;
    }
  }
}


static void builtins_StackTrace_op__destructor(struct StackTrace * this) {
  if (this->calls != nullptr) {
    free((void *)this->calls);
    this->calls = nullptr;
    this->capacity = 0;
    this->size = 0;
  }
}

__attribute__((always_inline))
static struct StackTrace builtins_StackTrace_op__initCover() {
  struct StackTrace __obj9 = (struct StackTrace){
    .calls = (struct CallTrace *) {},
    .size = 0u,
    .capacity = 0u
  };
  builtins_StackTrace_op__init(&__obj9);
  return __obj9;
}


static struct OutputStream * builtins_OutputStream_op__lshiftI_ZStackTrace_E(struct OutputStream * this, const struct StackTrace * val) {
  builtins_StackTrace_op__str(val, this);
  return this;
}

struct Exception_VTable Exception_vTable = (struct Exception_VTable){
  .what = (builtins_Exception_what_t) {}
};

static void builtins_Exception_op__init(struct Exception * this, const char* name) {
  this->name = name;
  this->stackTrace = builtins_StackTrace_op__initCover();
}

__attribute__((always_inline))
static void builtins_Exception_push(struct Exception * this, const char* mod, const char* cls, const char* fun, const char* path, uint64_t line) {
  builtins_StackTrace_push(&this->stackTrace, mod, cls, fun, path, line);
}


static void builtins_Exception_header(const struct Exception * this, struct OutputStream * os) {
  const char* _rv10 = this->vtable->what(this);
  struct OutputStream * _m94 = builtins_OutputStream_op__lshiftI_sE(os, this->name);
  struct OutputStream * _m95 = builtins_OutputStream_op__lshiftI_sE(_m94, "(\"");
  struct OutputStream * _m96 = builtins_OutputStream_op__lshiftI_sE(_m95, _rv10);
  builtins_OutputStream_op__lshiftI_sE(_m96, "\")");
}

__attribute__((always_inline))
static void builtins_Exception_dumpStackTrace(const struct Exception * this, struct OutputStream * os, int64_t s, uint64_t tabs) {
  builtins_StackTrace_dump(&this->stackTrace, os, s, tabs);
}


static void builtins_Exception_op__str(const struct Exception * this, struct OutputStream * os) {
  const char* _rv11 = this->vtable->what(this);
  struct OutputStream * _m97 = builtins_OutputStream_op__lshiftI_sE(os, this->name);
  struct OutputStream * _m98 = builtins_OutputStream_op__lshiftI_sE(_m97, "(\"");
  struct OutputStream * _m99 = builtins_OutputStream_op__lshiftI_sE(_m98, _rv11);
  struct OutputStream * _m100 = builtins_OutputStream_op__lshiftI_sE(_m99, "\") at:");
  struct OutputStream * _m101 = builtins_OutputStream_op__lshiftI_ZStackTrace_E(_m100, &this->stackTrace);
  builtins_OutputStream_op__lshiftI_sE(_m101, "\n");
}

__attribute__((always_inline))
static void builtins_Exception_op__deinit(struct Exception * this) {
  builtins_StackTrace_op__destructor(&this->stackTrace);
}

__attribute__((always_inline))
static void builtins_Exception_op__destructor(struct Exception * this) {
  builtins_Exception_op__deinit(this);
}


static void builtins_Exception___defaults_init(struct Exception * this) {
  this->vtable = &Exception_vTable;
}


static void builtins_Repeat_op__init(struct Repeat * this, char c, uint64_t count) {
  this->c = c;
  this->count = count;
}

__attribute__((always_inline))
static void builtins_Repeat_op__str(const struct Repeat * this, struct OutputStream * os) {
  {
    int64_t i = 0;
    while (i != this->count) {
      {
        builtins_OutputStream_op__lshiftI_cE(os, this->c);
      }
      i += 1;
    }
  }
}

__attribute__((always_inline))
static bool builtins_isnullI_ZException_E(const struct Exception * cls) {
  return ((const void *)cls) == nullptr;
}


static struct OutputStream * builtins_OutputStream_op__lshiftI_ZException_E(struct OutputStream * this, const struct Exception * val) {
  if (builtins_isnullI_ZException_E(val)) {
    builtins_OutputStream_appendStringI_sE(this, "null");
  } else {
    builtins_Exception_op__str(val, this);
  }
  return this;
}

__attribute__((always_inline))
static void panicUnhandledException(struct Exception * ex) {
  struct OutputStream * _m102 = builtins_OutputStream_op__lshiftI_ZException_E(builtins_stderr, (const struct Exception *)ex);
  builtins_OutputStream_op__lshiftI_sE(_m102, "\n");
  __smart_ptr_drop((void *)ex);
  abort();
}

struct OutputStream_VTable MemoryOutputStream_vTable = (struct OutputStream_VTable){
  .append = (builtins_OutputStream_append_t)builtins_MemoryOutputStream_append
};

static void builtins_MemoryOutputStream_op__init(struct MemoryOutputStream * this, void * buffer, uint64_t capacity) {
  this->_buffer = buffer;
  this->_capacity = capacity;
}


static struct OptionalI_u64E builtins_MemoryOutputStream_append(struct MemoryOutputStream * this, const char * str, uint64_t size) {
  if (size != 0u) {
    {
      bool _a103 = size < (this->_capacity - this->_size);
      __cxy_assert(_a103, "__builtins.cxy", 1483u, 13u);
    };
    char * p = ((char *)this->_buffer) + this->_size;
    memmove((void *)p, (const void *)str, size);
    this->_size += size;
    p[size] = '\0';
  }
  return builtins_SomeI_u64E(size);
}


static uint64_t builtins_MemoryOutputStream_size(struct MemoryOutputStream * this) {
  return this->_size;
}

__attribute__((always_inline))
static void builtins_MemoryOutputStream_op__str(const struct MemoryOutputStream * this, struct OutputStream * os) {
  os->vtable->append(os, (const void *)this->_buffer, this->_size);
}


static void builtins_MemoryOutputStream___defaults_init(struct MemoryOutputStream * this) {
  this->_size = 0;
  this->vtable = &MemoryOutputStream_vTable;
}


static struct OutputStream * builtins_OutputStream_op__lshiftI_i8E(struct OutputStream * this, const int8_t val) {
  builtins_OutputStream_appendSignedInt(this, (int64_t)val);
  return this;
}


static struct OutputStream * builtins_OutputStream_op__lshiftI_wE(struct OutputStream * this, const wchar_t val) {
  builtins_OutputStream_appendChar(this, val);
  return this;
}

__attribute__((always_inline))
static bool builtins_isnullI_ZMemoryOutputStream_E(const struct MemoryOutputStream * cls) {
  return ((const void *)cls) == nullptr;
}


static struct OutputStream * builtins_OutputStream_op__lshiftI_ZMemoryOutputStream_E(struct OutputStream * this, const struct MemoryOutputStream * val) {
  if (builtins_isnullI_ZMemoryOutputStream_E(val)) {
    builtins_OutputStream_appendStringI_sE(this, "null");
  } else {
    builtins_MemoryOutputStream_op__str(val, this);
  }
  return this;
}


static void builtins_Style_op__str(const struct Style * this, struct OutputStream * os) {
  Array395 tmp = {};
  struct MemoryOutputStream * mos = ({
    struct MemoryOutputStream * obj = __builtin_alloca(sizeof(MemoryOutputStream));
    builtins_MemoryOutputStream___defaults_init(obj);;
    builtins_MemoryOutputStream_op__init(obj, (void *)tmp, (uint64_t)64);
    obj;
  });
  builtins_OutputStream_op__lshiftI_sE((struct OutputStream *)mos, "\x1B[");
  if (this->color != 0) {
    if (this->_bold) {
      builtins_OutputStream_op__lshiftI_sE((struct OutputStream *)mos, "1;");
    }
    if (this->_faded) {
      builtins_OutputStream_op__lshiftI_sE((struct OutputStream *)mos, "2;");
    }
    if (this->_italics) {
      builtins_OutputStream_op__lshiftI_sE((struct OutputStream *)mos, "3;");
    }
    if (this->_underline) {
      builtins_OutputStream_op__lshiftI_sE((struct OutputStream *)mos, "4;");
    }
    if (this->_blink) {
      builtins_OutputStream_op__lshiftI_sE((struct OutputStream *)mos, "5;");
    }
    if (this->_bg != 0) {
      struct OutputStream * _m104 = builtins_OutputStream_op__lshiftI_i8E((struct OutputStream *)mos, this->_bg);
      builtins_OutputStream_op__lshiftI_sE(_m104, ";");
    }
  }
  struct OutputStream * _m105 = builtins_OutputStream_op__lshiftI_i8E((struct OutputStream *)mos, this->color);
  builtins_OutputStream_op__lshiftI_wE(_m105, 'm');
  builtins_OutputStream_op__lshiftI_ZMemoryOutputStream_E(os, (const struct MemoryOutputStream *)mos);
}


static struct Style builtins_Style_op__callIc_sZStyle_E(const struct Style * this, const char* cfg, struct Style bg) {
  struct Style x = this[0];
  const char * p = (const char *)cfg;
  int32_t i = 0;
  while (p[i] != '\0') {
    {
      bool on = true;
      if (p[i] == '~') {
        i++;
        on = false;
      }
      switch (p[i++]) {
      case 'b': {
        {
          x._bold = on;
        }
        break;
      }
      case 'i': {
        {
          x._italics = on;
        }
        break;
      }
      case 'u': {
        {
          x._underline = on;
        }
        break;
      }
      case 'f': {
        {
          x._faded = on;
        }
        break;
      }
      case 'p': {
        {
          x._blink = on;
        }
        break;
      }
      default: {
        {
          {
            __cxy_assert(false, "__builtins.cxy", 1549u, 28u);
          };
        }
        break;
      }}
      
      {
        bool _a106 = p[i] == '\0' || p[i++] == '|';
        __cxy_assert(_a106, "__builtins.cxy", 1551u, 13u);
      };
    }
    
  }
  if (bg.color >= 0) {
    x._bg = bg.color;
  }
  return x;
}

__attribute__((always_inline))
static struct Style builtins_Style_op__callIc_sE(const struct Style * this, const char* cfg) {
  return builtins_Style_op__callIc_sZStyle_E(this, cfg, (struct Style){
    .color = -1,
    ._bg = 0,
    ._bold = false,
    ._italics = false,
    ._underline = false,
    ._blink = false,
    ._faded = false
  });
}

struct Style builtins_DEF = (struct Style){
  .color = 0,
  ._bg = 0,
  ._bold = false,
  ._italics = false,
  ._underline = false,
  ._blink = false,
  ._faded = false
};
struct Style builtins_RED = (struct Style){
  .color = 31,
  ._bg = 0,
  ._bold = false,
  ._italics = false,
  ._underline = false,
  ._blink = false,
  ._faded = false
};
struct Style builtins_GRN = (struct Style){
  .color = 32,
  ._bg = 0,
  ._bold = false,
  ._italics = false,
  ._underline = false,
  ._blink = false,
  ._faded = false
};
struct Style builtins_YLW = (struct Style){
  .color = 33,
  ._bg = 0,
  ._bold = false,
  ._italics = false,
  ._underline = false,
  ._blink = false,
  ._faded = false
};
struct Style builtins_BLU = (struct Style){
  .color = 34,
  ._bg = 0,
  ._bold = false,
  ._italics = false,
  ._underline = false,
  ._blink = false,
  ._faded = false
};
struct Style builtins_MGN = (struct Style){
  .color = 35,
  ._bg = 0,
  ._bold = false,
  ._italics = false,
  ._underline = false,
  ._blink = false,
  ._faded = false
};
struct Style builtins_cxy = (struct Style){
  .color = 36,
  ._bg = 0,
  ._bold = false,
  ._italics = false,
  ._underline = false,
  ._blink = false,
  ._faded = false
};
struct Style builtins_WHT = (struct Style){
  .color = 37,
  ._bg = 0,
  ._bold = false,
  ._italics = false,
  ._underline = false,
  ._blink = false,
  ._faded = false
};
struct Exception_VTable TestFailed_vTable = (struct Exception_VTable){
  .what = (builtins_Exception_what_t)builtins_TestFailed_what
};

static void builtins_TestFailed_op__init(struct TestFailed * this) {
  builtins_Exception_op__init((struct Exception *)this, "TestFailed");
}


static const char* builtins_TestFailed_what(struct TestFailed * this) {
  return "test failed";
}


static void builtins_TestFailed___defaults_init(struct TestFailed * this) {
  builtins_Exception___defaults_init(this);
  this->vtable = &TestFailed_vTable;
}


static struct OutputStream * builtins_OutputStream_op__lshiftI_ZStyle_E(struct OutputStream * this, const struct Style * val) {
  builtins_Style_op__str(val, this);
  return this;
}


static bool builtins_runTest(struct Tuple418 testCase) {
  struct Union416 _res12 = testCase._1();
  if (_res12.tag == 1u) {
    struct Exception * _ex13 = _res12._1;
    struct OutputStream * _m107 = builtins_OutputStream_op__lshiftI_sE(builtins_stdout, "\r  ");
    struct Repeat _r108 = builtins_Repeat_op__initCover(' ', (uint64_t)100);
    struct Repeat * _a109 = &_r108;
    struct OutputStream * _m110 = builtins_OutputStream_op__lshiftI_ZRepeat_E(_m107, (const struct Repeat *)_a109);
    struct OutputStream * _m111 = builtins_OutputStream_op__lshiftI_sE(_m110, "\r  ");
    struct Style _r112 = builtins_Style_op__callIc_sE(&builtins_RED, "b");
    struct Style * _a113 = &_r112;
    struct OutputStream * _m114 = builtins_OutputStream_op__lshiftI_ZStyle_E(_m111, (const struct Style *)_a113);
    struct OutputStream * _m115 = builtins_OutputStream_op__lshiftI_sE(_m114, "\xE2\x9C\x98 ");
    struct OutputStream * _m116 = builtins_OutputStream_op__lshiftI_ZStyle_E(_m115, &builtins_WHT);
    struct OutputStream * _m117 = builtins_OutputStream_op__lshiftI_sE(_m116, testCase._0);
    struct OutputStream * _m118 = builtins_OutputStream_op__lshiftI_ZStyle_E(_m117, &builtins_DEF);
    builtins_OutputStream_op__lshiftI_sE(_m118, " ");
    builtins_Exception_header(_ex13, builtins_stdout);
    builtins_OutputStream_op__lshiftI_sE(builtins_stdout, " at:");
    builtins_Exception_dumpStackTrace(_ex13, builtins_stdout, (int64_t)1, (uint64_t)4);
    builtins_OutputStream_op__lshiftI_sE(builtins_stdout, "\n");
    return false;
  }
  struct OutputStream * _m119 = builtins_OutputStream_op__lshiftI_sE(builtins_stdout, "\r  ");
  struct Repeat _r120 = builtins_Repeat_op__initCover(' ', (uint64_t)100);
  struct Repeat * _a121 = &_r120;
  struct OutputStream * _m122 = builtins_OutputStream_op__lshiftI_ZRepeat_E(_m119, (const struct Repeat *)_a121);
  struct OutputStream * _m123 = builtins_OutputStream_op__lshiftI_sE(_m122, "\r  ");
  struct Style _r124 = builtins_Style_op__callIc_sE(&builtins_GRN, "b");
  struct Style * _a125 = &_r124;
  struct OutputStream * _m126 = builtins_OutputStream_op__lshiftI_ZStyle_E(_m123, (const struct Style *)_a125);
  struct OutputStream * _m127 = builtins_OutputStream_op__lshiftI_sE(_m126, "\xE2\x9C\x93 ");
  struct OutputStream * _m128 = builtins_OutputStream_op__lshiftI_ZStyle_E(_m127, &builtins_WHT);
  struct OutputStream * _m129 = builtins_OutputStream_op__lshiftI_sE(_m128, testCase._0);
  struct OutputStream * _m130 = builtins_OutputStream_op__lshiftI_ZStyle_E(_m129, &builtins_DEF);
  builtins_OutputStream_op__lshiftI_sE(_m130, "\n");
  return true;
}

__attribute__((always_inline))
static void builtins_OptionalI_Tsi32_E_op__initI_E(struct OptionalI_Tsi32_E * this) {
  this->ok = false;
  {
    memset(&this->val, 0, sizeof(struct Tuple439));
  };
}

__attribute__((always_inline))
static void builtins_OptionalI_Tsi32_E_op__initI_Tsi32_E(struct OptionalI_Tsi32_E * this, struct Tuple439 value) {
  this->val = value;
  this->ok = true;
}


static void builtins_OptionalI_Tsi32_E_op__destructor(struct OptionalI_Tsi32_E * this) {
  if (this->ok) {
    
  }
}

__attribute__((always_inline))
static struct OptionalI_Tsi32_E builtins_OptionalI_Tsi32_E_op__copy(struct OptionalI_Tsi32_E * this) {
  return (struct OptionalI_Tsi32_E){
    .ok = this->ok,
    .val = this->val
  };
}

__attribute__((always_inline))
static bool builtins_OptionalI_Tsi32_E_op__truthyI_E(struct OptionalI_Tsi32_E * this) {
  return this->ok;
}

__attribute__((always_inline))
static struct Tuple439 builtins_OptionalI_Tsi32_E_op__derefI_E(struct OptionalI_Tsi32_E * this) {
  return this->val;
}

 __attribute__((optnone))
static struct Tuple439 builtins_OptionalI_Tsi32_E_move(struct OptionalI_Tsi32_E * this) {
  this->ok = false;
  return this->val;
}

__attribute__((always_inline))
static struct Tuple439 builtins_OptionalI_Tsi32_E_op__lor(struct OptionalI_Tsi32_E * this, struct Tuple439 def) {
  return this->ok? builtins_OptionalI_Tsi32_E_move(this): def;
}

__attribute__((always_inline))
static bool builtins_OptionalI_Tsi32_E_op__truthyIc_E(const struct OptionalI_Tsi32_E * this) {
  return this->ok;
}

__attribute__((always_inline))
static struct Tuple439 builtins_OptionalI_Tsi32_E_op__derefIc_E(const struct OptionalI_Tsi32_E * this) {
  return this->val;
}

__attribute__((always_inline))
static struct OptionalI_Tsi32_E builtins_SomeI_Tsi32_E(struct Tuple439 value) {
  return (struct OptionalI_Tsi32_E){
    .ok = true,
    .val = value
  };
}

__attribute__((always_inline))
static struct OptionalI_Tsi32_E builtins_OptionalI_Tsi32_E_op__initCover() {
  struct OptionalI_Tsi32_E __obj14 = (struct OptionalI_Tsi32_E){
    .ok = false
  };
  builtins_OptionalI_Tsi32_E_op__initI_E(&__obj14);
  return __obj14;
}

__attribute__((always_inline))
static struct OptionalI_Tsi32_E builtins_NoneI_Tsi32_E() {
  return builtins_OptionalI_Tsi32_E_op__initCover();
}


static struct OptionalI_Tsi32_E __Closure15_op__call(struct __Closure15 * this) {
  if (this->i < this->len) {
    struct Tuple439 _a131 = (struct Tuple439){
      ._0 = this->data[this->i],
      ._1 = this->i++
    };
    return builtins_SomeI_Tsi32_E(_a131);
  }
  return builtins_NoneI_Tsi32_E();
}


static void __Closure15_op__init(struct __Closure15 * this) {
  
}

__attribute__((always_inline))
static struct SliceI_sE builtins_SliceI_sE_op__initCover(const char* * data, uint64_t len) {
  struct SliceI_sE __obj17 = (struct SliceI_sE){};
  builtins_SliceI_sE_op__init(&__obj17, data, len);
  return __obj17;
}


static void builtins_SliceI_sE_op__init(struct SliceI_sE * this, const char* * data, uint64_t len) {
  this->data = data;
  this->len = len;
}

__attribute__((always_inline))
static void builtins_SliceI_sE_op__idx_assign(struct SliceI_sE * this, uint64_t index, const char* data) {
  {
    bool _a132 = index < this->len;
    __cxy_assert(_a132, "__builtins.cxy", 1061u, 9u);
  };
  this->data[index] = data;
}

__attribute__((always_inline))
static const char* builtins_SliceI_sE_op__idxI_u64E(struct SliceI_sE * this, uint64_t index) {
  {
    bool _a133 = index < this->len;
    __cxy_assert(_a133, "__builtins.cxy", 1067u, 9u);
  };
  return this->data[index];
}

__attribute__((always_inline))
static const char* builtins_SliceI_sE_op__idxIc_u64E(const struct SliceI_sE * this, uint64_t index) {
  {
    bool _a134 = index < this->len;
    __cxy_assert(_a134, "__builtins.cxy", 1073u, 9u);
  };
  return this->data[index];
}


static struct __Closure15 * builtins_SliceI_sE_op__range(const struct SliceI_sE * this) {
  int32_t i = 0;
  return ({
    struct __Closure15 * __obj16 = (struct __Closure15 *)__smart_ptr_alloc(sizeof(__Closure15), nullptr);
    __obj16->i = i;
    __obj16->len = this->len;
    __obj16->data = this->data;
    __obj16;
  });
}

__attribute__((always_inline))
static uint64_t builtins_SliceI_sE_size(struct SliceI_sE * this) {
  return this->len;
}

__attribute__((always_inline))
static struct SliceI_sE builtins_SliceI_sE_view(struct SliceI_sE * this, uint64_t start, int64_t count) {
  {
    bool _a135 = start <= this->len;
    __cxy_assert(_a135, "__builtins.cxy", 1091u, 9u);
  };
  if (count == -1) {
    count = (int64_t)(this->len - start);
  } else {
    {
      bool _a136 = count >= 0 && count <= (this->len - start);
      __cxy_assert(_a136, "__builtins.cxy", 1095u, 13u);
    };
  }
  const char* * _a137 = this->data + start;
  return builtins_SliceI_sE_op__initCover(_a137, (uint64_t)count);
}


static void builtins_SliceI_sE_op__str(const struct SliceI_sE * this, struct OutputStream * sb) {
  builtins_OutputStream_appendChar(sb, '[');
  {
    int64_t i = 0;
    while (i != this->len) {
      {
        if (i != 0) {
          builtins_OutputStream_appendStringI_sE(sb, ", ");
        }
        builtins_OutputStream_op__lshiftI_sE(sb, this->data[i]);
      }
      i += 1;
    }
  }
  builtins_OutputStream_appendChar(sb, ']');
}

__attribute__((always_inline))
static void builtins_OptionalI_TTsFU_ZVoid_ZException____i32_E_op__initI_E(struct OptionalI_TTsFU_ZVoid_ZException____i32_E * this) {
  this->ok = false;
  {
    memset(&this->val, 0, sizeof(struct Tuple482));
  };
}

__attribute__((always_inline))
static void builtins_OptionalI_TTsFU_ZVoid_ZException____i32_E_op__initI_TTsFU_ZVoid_ZException____i32_E(struct OptionalI_TTsFU_ZVoid_ZException____i32_E * this, struct Tuple482 value) {
  this->val = value;
  this->ok = true;
}


static void builtins_OptionalI_TTsFU_ZVoid_ZException____i32_E_op__destructor(struct OptionalI_TTsFU_ZVoid_ZException____i32_E * this) {
  if (this->ok) {
    
  }
}

__attribute__((always_inline))
static struct OptionalI_TTsFU_ZVoid_ZException____i32_E builtins_OptionalI_TTsFU_ZVoid_ZException____i32_E_op__copy(struct OptionalI_TTsFU_ZVoid_ZException____i32_E * this) {
  return (struct OptionalI_TTsFU_ZVoid_ZException____i32_E){
    .ok = this->ok,
    .val = this->val
  };
}

__attribute__((always_inline))
static bool builtins_OptionalI_TTsFU_ZVoid_ZException____i32_E_op__truthyI_E(struct OptionalI_TTsFU_ZVoid_ZException____i32_E * this) {
  return this->ok;
}

__attribute__((always_inline))
static struct Tuple482 builtins_OptionalI_TTsFU_ZVoid_ZException____i32_E_op__derefI_E(struct OptionalI_TTsFU_ZVoid_ZException____i32_E * this) {
  return this->val;
}

 __attribute__((optnone))
static struct Tuple482 builtins_OptionalI_TTsFU_ZVoid_ZException____i32_E_move(struct OptionalI_TTsFU_ZVoid_ZException____i32_E * this) {
  this->ok = false;
  return this->val;
}

__attribute__((always_inline))
static struct Tuple482 builtins_OptionalI_TTsFU_ZVoid_ZException____i32_E_op__lor(struct OptionalI_TTsFU_ZVoid_ZException____i32_E * this, struct Tuple482 def) {
  return this->ok? builtins_OptionalI_TTsFU_ZVoid_ZException____i32_E_move(this): def;
}

__attribute__((always_inline))
static bool builtins_OptionalI_TTsFU_ZVoid_ZException____i32_E_op__truthyIc_E(const struct OptionalI_TTsFU_ZVoid_ZException____i32_E * this) {
  return this->ok;
}

__attribute__((always_inline))
static struct Tuple482 builtins_OptionalI_TTsFU_ZVoid_ZException____i32_E_op__derefIc_E(const struct OptionalI_TTsFU_ZVoid_ZException____i32_E * this) {
  return this->val;
}

__attribute__((always_inline))
static struct OptionalI_TTsFU_ZVoid_ZException____i32_E builtins_SomeI_TTsFU_ZVoid_ZException____i32_E(struct Tuple482 value) {
  return (struct OptionalI_TTsFU_ZVoid_ZException____i32_E){
    .ok = true,
    .val = value
  };
}

__attribute__((always_inline))
static struct OptionalI_TTsFU_ZVoid_ZException____i32_E builtins_OptionalI_TTsFU_ZVoid_ZException____i32_E_op__initCover() {
  struct OptionalI_TTsFU_ZVoid_ZException____i32_E __obj18 = (struct OptionalI_TTsFU_ZVoid_ZException____i32_E){
    .ok = false
  };
  builtins_OptionalI_TTsFU_ZVoid_ZException____i32_E_op__initI_E(&__obj18);
  return __obj18;
}

__attribute__((always_inline))
static struct OptionalI_TTsFU_ZVoid_ZException____i32_E builtins_NoneI_TTsFU_ZVoid_ZException____i32_E() {
  return builtins_OptionalI_TTsFU_ZVoid_ZException____i32_E_op__initCover();
}


static struct OptionalI_TTsFU_ZVoid_ZException____i32_E __Closure19_op__call(struct __Closure19 * this) {
  if (this->i < this->len) {
    struct Tuple482 _a138 = (struct Tuple482){
      ._0 = this->data[this->i],
      ._1 = this->i++
    };
    return builtins_SomeI_TTsFU_ZVoid_ZException____i32_E(_a138);
  }
  return builtins_NoneI_TTsFU_ZVoid_ZException____i32_E();
}


static void __Closure19_op__init(struct __Closure19 * this) {
  
}

__attribute__((always_inline))
static struct SliceI_TsFU_ZVoid_ZException____E builtins_SliceI_TsFU_ZVoid_ZException____E_op__initCover(struct Tuple418 * data, uint64_t len) {
  struct SliceI_TsFU_ZVoid_ZException____E __obj21 = (struct SliceI_TsFU_ZVoid_ZException____E){};
  builtins_SliceI_TsFU_ZVoid_ZException____E_op__init(&__obj21, data, len);
  return __obj21;
}


static struct OutputStream * builtins_OutputStream_op__lshiftI_FU_ZVoid_ZException___E(struct OutputStream * this, const Func417_t val) {
  builtins_OutputStream_appendStringI_sE(this, "TODO//function");
  return this;
}


static struct OutputStream * builtins_OutputStream_op__lshiftI_TsFU_ZVoid_ZException____E(struct OutputStream * this, const struct Tuple418 * val) {
  builtins_OutputStream_appendChar(this, '(');
  builtins_OutputStream_op__lshiftI_sE(this, val->_0);
  builtins_OutputStream_appendStringI_sE(this, ", ");
  builtins_OutputStream_op__lshiftI_FU_ZVoid_ZException___E(this, val->_1);
  builtins_OutputStream_appendChar(this, ')');
  return this;
}


static void builtins_SliceI_TsFU_ZVoid_ZException____E_op__init(struct SliceI_TsFU_ZVoid_ZException____E * this, struct Tuple418 * data, uint64_t len) {
  this->data = data;
  this->len = len;
}

__attribute__((always_inline))
static void builtins_SliceI_TsFU_ZVoid_ZException____E_op__idx_assign(struct SliceI_TsFU_ZVoid_ZException____E * this, uint64_t index, struct Tuple418 data) {
  {
    bool _a139 = index < this->len;
    __cxy_assert(_a139, "__builtins.cxy", 1061u, 9u);
  };
  this->data[index] = data;
}

__attribute__((always_inline))
static struct Tuple418 builtins_SliceI_TsFU_ZVoid_ZException____E_op__idxI_u64E(struct SliceI_TsFU_ZVoid_ZException____E * this, uint64_t index) {
  {
    bool _a140 = index < this->len;
    __cxy_assert(_a140, "__builtins.cxy", 1067u, 9u);
  };
  return this->data[index];
}

__attribute__((always_inline))
static struct Tuple418 builtins_SliceI_TsFU_ZVoid_ZException____E_op__idxIc_u64E(const struct SliceI_TsFU_ZVoid_ZException____E * this, uint64_t index) {
  {
    bool _a141 = index < this->len;
    __cxy_assert(_a141, "__builtins.cxy", 1073u, 9u);
  };
  return this->data[index];
}


static struct __Closure19 * builtins_SliceI_TsFU_ZVoid_ZException____E_op__range(const struct SliceI_TsFU_ZVoid_ZException____E * this) {
  int32_t i = 0;
  return ({
    struct __Closure19 * __obj20 = (struct __Closure19 *)__smart_ptr_alloc(sizeof(__Closure19), nullptr);
    __obj20->i = i;
    __obj20->len = this->len;
    __obj20->data = this->data;
    __obj20;
  });
}

__attribute__((always_inline))
static uint64_t builtins_SliceI_TsFU_ZVoid_ZException____E_size(struct SliceI_TsFU_ZVoid_ZException____E * this) {
  return this->len;
}

__attribute__((always_inline))
static struct SliceI_TsFU_ZVoid_ZException____E builtins_SliceI_TsFU_ZVoid_ZException____E_view(struct SliceI_TsFU_ZVoid_ZException____E * this, uint64_t start, int64_t count) {
  {
    bool _a142 = start <= this->len;
    __cxy_assert(_a142, "__builtins.cxy", 1091u, 9u);
  };
  if (count == -1) {
    count = (int64_t)(this->len - start);
  } else {
    {
      bool _a143 = count >= 0 && count <= (this->len - start);
      __cxy_assert(_a143, "__builtins.cxy", 1095u, 13u);
    };
  }
  struct Tuple418 * _a144 = this->data + start;
  return builtins_SliceI_TsFU_ZVoid_ZException____E_op__initCover(_a144, (uint64_t)count);
}


static void builtins_SliceI_TsFU_ZVoid_ZException____E_op__str(const struct SliceI_TsFU_ZVoid_ZException____E * this, struct OutputStream * sb) {
  builtins_OutputStream_appendChar(sb, '[');
  {
    int64_t i = 0;
    while (i != this->len) {
      {
        if (i != 0) {
          builtins_OutputStream_appendStringI_sE(sb, ", ");
        }
        builtins_OutputStream_op__lshiftI_TsFU_ZVoid_ZException____E(sb, &this->data[i]);
      }
      i += 1;
    }
  }
  builtins_OutputStream_appendChar(sb, ']');
}


static int8_t builtins_runTests(struct SliceI_sE args, const char* testFile, struct SliceI_TsFU_ZVoid_ZException____E tests) {
  int8_t failed = 0;
  if (tests.len == 0) {
    struct OutputStream * _m145 = builtins_OutputStream_op__lshiftI_sE(builtins_stdout, "0 tests defined in ");
    struct OutputStream * _m146 = builtins_OutputStream_op__lshiftI_sE(_m145, testFile);
    builtins_OutputStream_op__lshiftI_sE(_m146, "\n");
    return 0;
  }
  struct OutputStream * _m147 = builtins_OutputStream_op__lshiftI_sE(builtins_stdout, "Running ");
  struct OutputStream * _m148 = builtins_OutputStream_op__lshiftI_sE(_m147, testFile);
  builtins_OutputStream_op__lshiftI_sE(_m148, " tests...\n");
  struct __Closure19 * _rg22 = builtins_SliceI_TsFU_ZVoid_ZException____E_op__range(&tests);
  struct OptionalI_TTsFU_ZVoid_ZException____i32_E _it23 = __Closure19_op__call(_rg22);
  while (!!builtins_OptionalI_TTsFU_ZVoid_ZException____i32_E_op__truthyI_E(&_it23)) {
    {
      struct Tuple482 tmpVar24 = builtins_OptionalI_TTsFU_ZVoid_ZException____i32_E_op__derefI_E(&_it23);
      struct Tuple418 testCase = tmpVar24._0;
      struct OutputStream * _m149 = builtins_OutputStream_op__lshiftI_sE(builtins_stdout, "  Running test case ");
      struct OutputStream * _m150 = builtins_OutputStream_op__lshiftI_sE(_m149, testCase._0);
      builtins_OutputStream_op__lshiftI_sE(_m150, "");
      if (!builtins_runTest(testCase)) {
        failed++;
      }
    }
    {
      _it23 = __Closure19_op__call(_rg22);
    }
  }
  if (failed != 0) {
    struct Style _r151 = builtins_Style_op__callIc_sE(&builtins_RED, "b");
    struct Style * _a152 = &_r151;
    struct OutputStream * _m153 = builtins_OutputStream_op__lshiftI_ZStyle_E(builtins_stdout, (const struct Style *)_a152);
    struct OutputStream * _m154 = builtins_OutputStream_op__lshiftI_sE(_m153, "\xE2\x9C\x98 FAILED - ");
    struct OutputStream * _m155 = builtins_OutputStream_op__lshiftI_i8E(_m154, failed);
    struct OutputStream * _m156 = builtins_OutputStream_op__lshiftI_sE(_m155, "/");
    struct OutputStream * _m157 = builtins_OutputStream_op__lshiftI_u64E(_m156, tests.len);
    struct OutputStream * _m158 = builtins_OutputStream_op__lshiftI_sE(_m157, " tests failed!");
    struct OutputStream * _m159 = builtins_OutputStream_op__lshiftI_ZStyle_E(_m158, &builtins_DEF);
    builtins_OutputStream_op__lshiftI_sE(_m159, "\n");
    return -1;
  }
  return 0;
}

__attribute__((constructor))

static void builtins___init() {
  builtins_stdout = builtins_StdOutputStream_op__initCover((int32_t)1);
  builtins_stderr = builtins_StdOutputStream_op__initCover((int32_t)2);
  builtins_SysConfPageSize = sysconf((int32_t)30);
  builtins_SysConfNumProcs = sysconf((int32_t)84);
}

/*-----------/home/dev/.cxy/lib/cxy/std/stdlib/list.cxy-----------*/

/*-----------/home/dev/.cxy/lib/cxy/std/stdlib/native/index.cxy-----------*/

/*-----------/home/dev/.cxy/lib/cxy/std/stdlib/coro.cxy-----------*/
typedef int32_t Status;
enum {
  Status_AE_OK = 0,
  Status_AE_ERR = -1,
  Status_AE_NO_MORE = -1,
  Status_AE_DELETED_EVENT_ID = -1,
};

typedef struct aeEventLoop _aeEventLoop;
typedef struct aeFileEvent _aeFileEvent;
typedef struct __ext_s172 ___ext_s172;
struct  __ext_s172 {
  uint64_t id;
  int64_t when_sec;
  int64_t when_ms;
  struct aeFileEvent * prev;
  struct aeFileEvent * next;
  int32_t fd;
};

typedef void(*Func859)(struct aeEventLoop *, int32_t, void *, int32_t);
struct  aeFileEvent {
  struct __ext_s172 timer;
  int32_t mask;
  Func859 rfileProc;
  Func859 wfileProc;
  void * clientData;
};

typedef struct aeFiredEvent _aeFiredEvent;
struct  aeFiredEvent {
  int32_t fd;
  int32_t mask;
};

typedef struct aeTimeEvent _aeTimeEvent;
typedef Status(*Func861)(struct aeEventLoop *, int64_t, void *);
typedef void(*Func863)(struct aeEventLoop *, void *);
struct  aeTimeEvent {
  uint64_t id;
  int64_t when_sec;
  int64_t when_ms;
  struct aeTimeEvent * prev;
  struct aeTimeEvent * next;
  int32_t fd;
  Func861 timeProc;
  Func863 finalizerProc;
  void * clientData;
};

typedef void(*Func886)(struct aeEventLoop *);
struct  aeEventLoop {
  int32_t maxfd;
  int32_t setsize;
  int64_t timeEventNextId;
  int64_t lastTime;
  struct aeFileEvent * events;
  struct aeFiredEvent * fired;
  struct aeTimeEvent * timeEventHead;
  int32_t stop;
  void * context;
  void * apidata;
  Func886 beforesleep;
  Func886 aftersleep;
};

typedef uint32_t State;
enum {
  State_AE_NONE = 0,
  State_AE_READABLE = 1,
  State_AE_WRITABLE = 2,
  State_AE_TIMEOUT = 4,
  State_AE_BARRIER = 8,
};

typedef struct coro_CoroutineScheduler coro_CoroutineScheduler;
typedef struct coro_Coroutine coro_Coroutine;
typedef struct __jmp_buf_tag ___jmp_buf_tag;
typedef int64_t Array521[8];
typedef struct __ext_s169 ___ext_s169;
typedef uint64_t Array524[16];
struct  __ext_s169 {
  Array524 __val;
};

struct  __jmp_buf_tag {
  Array521 __jmpbuf;
  int32_t __mask_was_saved;
  struct __ext_s169 __saved_mask;
};

typedef struct __jmp_buf_tag Array531[1];
struct  __attribute__((aligned(16))) coro_Coroutine {
  struct coro_Coroutine * link;
  void * scheduler;
  int32_t id;
  int32_t result;
  Array531 ctx;
  bool ready;
  void * promise;
  const char* name;
};

typedef struct list_ListI_ZcoroCoroutine_E list_ListI_ZcoroCoroutine_E;
struct  list_ListI_ZcoroCoroutine_E {
  struct coro_Coroutine * _head;
  struct coro_Coroutine * _tail;
  uint64_t count;
};

typedef struct list_ListI_ZcoroCachedStack_E list_ListI_ZcoroCachedStack_E;
typedef struct coro_CachedStack coro_CachedStack;
struct  coro_CachedStack {
  struct coro_CachedStack * link;
};

struct  list_ListI_ZcoroCachedStack_E {
  struct coro_CachedStack * _head;
  struct coro_CachedStack * _tail;
  uint64_t count;
};

struct  coro_CoroutineScheduler {
  struct coro_Coroutine * running;
  struct list_ListI_ZcoroCoroutine_E ready;
  struct coro_Coroutine main;
  struct list_ListI_ZcoroCachedStack_E stacks;
  int32_t idGenerator;
  int32_t counter;
  struct aeEventLoop * eventLoop;
};

typedef uint32_t Flags;
enum {
  Flags_AE_FILE_EVENTS = 1,
  Flags_AE_TIME_EVENTS = 2,
  Flags_AE_ALL_EVENTS = 3,
  Flags_AE_DONT_WAIT = 4,
  Flags_AE_CALL_AFTER_SLEEP = 8,
};

typedef struct OptionalI_PZcoroCoroutine_E OptionalI_PZcoroCoroutine_E;
struct  OptionalI_PZcoroCoroutine_E {
  bool ok;
  struct coro_Coroutine * val;
};

typedef struct list___Closure174 list___Closure174;
struct  list___Closure174 {
  struct coro_Coroutine * item;
};

typedef struct OptionalI_PZcoroCachedStack_E OptionalI_PZcoroCachedStack_E;
struct  OptionalI_PZcoroCachedStack_E {
  bool ok;
  struct coro_CachedStack * val;
};

typedef struct list___Closure178 list___Closure178;
struct  list___Closure178 {
  struct coro_CachedStack * item;
};

typedef struct coro_Mutex coro_Mutex;
struct  coro_Mutex {
  struct list_ListI_ZcoroCoroutine_E waiting;
  struct coro_Coroutine * holder;
};

static void coro___init_coro();
extern int64_t aeOsTime();
extern Status aeCreateTimeEvent(struct aeEventLoop * eventLoop, int64_t milliseconds, Func861 proc, void * clientData, Func863 finalizerProc);
extern void aeDeleteFileEvent(struct aeEventLoop * eventLoop, int32_t fd, State mask);
extern Status aeCreateFileEvent(struct aeEventLoop * eventLoop, int32_t fd, State mask, Func859 proc, void * clientData, uint64_t timeout);
static void coro_CoroutineScheduler_resume(struct coro_CoroutineScheduler * this, struct coro_Coroutine * cr, int32_t res);
extern int32_t aeProcessEvents(struct aeEventLoop * eventLoop, Flags flags, int64_t timeout);
extern int32_t munmap(void * __addr, uint64_t __len);
extern void * mmap(void * __addr, uint64_t __len, int32_t __prot, int32_t __flags, int32_t __fd, int64_t __offset);
extern struct aeEventLoop * aeCreateEventLoop(void * context, int32_t setsize);

static void coro_Coroutine_op__init(struct coro_Coroutine * this, const char* name, int32_t id) {
  this->name = name;
  this->id = id;
}

__attribute__((always_inline))
static uint64_t coro_stackAlign(uint64_t size, uint64_t align) {
  uint64_t _rt194 = {};
  _rt194 = ((size + (align - 1)) & ~(align - 1)) + align;
  return _rt194;
}

uint64_t coro_stackSize = {};
__attribute__((always_inline))
static void builtins_OptionalI_PZcoroCoroutine_E_op__initI_E(struct OptionalI_PZcoroCoroutine_E * this) {
  this->ok = false;
  {
    memset(&this->val, 0, sizeof(struct coro_Coroutine *));
  };
}

__attribute__((always_inline))
static void builtins_OptionalI_PZcoroCoroutine_E_op__initI_PZcoroCoroutine_E(struct OptionalI_PZcoroCoroutine_E * this, struct coro_Coroutine * value) {
  this->val = value;
  this->ok = true;
}


static void builtins_OptionalI_PZcoroCoroutine_E_op__destructor(struct OptionalI_PZcoroCoroutine_E * this) {
  if (this->ok) {
    
  }
}

__attribute__((always_inline))
static struct OptionalI_PZcoroCoroutine_E builtins_OptionalI_PZcoroCoroutine_E_op__copy(struct OptionalI_PZcoroCoroutine_E * this) {
  struct OptionalI_PZcoroCoroutine_E _rt195 = {};
  _rt195 = (struct OptionalI_PZcoroCoroutine_E){
    .ok = this->ok,
    .val = this->val
  };
  return _rt195;
}

__attribute__((always_inline))
static bool builtins_OptionalI_PZcoroCoroutine_E_op__truthyI_E(struct OptionalI_PZcoroCoroutine_E * this) {
  bool _rt196 = {};
  _rt196 = this->ok;
  return _rt196;
}

__attribute__((always_inline))
static struct coro_Coroutine * builtins_OptionalI_PZcoroCoroutine_E_op__derefI_E(struct OptionalI_PZcoroCoroutine_E * this) {
  struct coro_Coroutine * _rt197 = {};
  _rt197 = this->val;
  return _rt197;
}

 __attribute__((optnone))
static struct coro_Coroutine * builtins_OptionalI_PZcoroCoroutine_E_move(struct OptionalI_PZcoroCoroutine_E * this) {
  struct coro_Coroutine * _rt198 = {};
  this->ok = false;
  _rt198 = this->val;
  return _rt198;
}

__attribute__((always_inline))
static struct coro_Coroutine * builtins_OptionalI_PZcoroCoroutine_E_op__lor(struct OptionalI_PZcoroCoroutine_E * this, struct coro_Coroutine * def) {
  struct coro_Coroutine * _rt199 = {};
  _rt199 = this->ok? builtins_OptionalI_PZcoroCoroutine_E_move(this): def;
  return _rt199;
}

__attribute__((always_inline))
static bool builtins_OptionalI_PZcoroCoroutine_E_op__truthyIc_E(const struct OptionalI_PZcoroCoroutine_E * this) {
  bool _rt200 = {};
  _rt200 = this->ok;
  return _rt200;
}

__attribute__((always_inline))
static struct coro_Coroutine * builtins_OptionalI_PZcoroCoroutine_E_op__derefIc_E(const struct OptionalI_PZcoroCoroutine_E * this) {
  struct coro_Coroutine * _rt201 = {};
  _rt201 = this->val;
  return _rt201;
}

__attribute__((always_inline))
static struct OptionalI_PZcoroCoroutine_E builtins_SomeI_PZcoroCoroutine_E(struct coro_Coroutine * value) {
  struct OptionalI_PZcoroCoroutine_E _rt202 = {};
  _rt202 = (struct OptionalI_PZcoroCoroutine_E){
    .ok = true,
    .val = value
  };
  return _rt202;
}

__attribute__((always_inline))
static struct OptionalI_PZcoroCoroutine_E builtins_OptionalI_PZcoroCoroutine_E_op__initCover() {
  struct OptionalI_PZcoroCoroutine_E _rt203 = {};
  struct OptionalI_PZcoroCoroutine_E __obj173 = (struct OptionalI_PZcoroCoroutine_E){
    .ok = false
  };
  builtins_OptionalI_PZcoroCoroutine_E_op__initI_E(&__obj173);
  _rt203 = __obj173;
  return _rt203;
}

__attribute__((always_inline))
static struct OptionalI_PZcoroCoroutine_E builtins_NoneI_PZcoroCoroutine_E() {
  struct OptionalI_PZcoroCoroutine_E _rt204 = {};
  _rt204 = builtins_OptionalI_PZcoroCoroutine_E_op__initCover();
  return _rt204;
}


static struct OptionalI_PZcoroCoroutine_E coro___Closure174_op__call(struct list___Closure174 * this) {
  struct OptionalI_PZcoroCoroutine_E _rt205 = {};
  if (this->item != nullptr) {
    struct coro_Coroutine * curr = this->item;
    this->item = this->item->link;
    _rt205 = builtins_SomeI_PZcoroCoroutine_E(curr);
    return _rt205;
  } else {
    _rt205 = builtins_NoneI_PZcoroCoroutine_E();
    return _rt205;
  }
}


static void coro___Closure174_op__init(struct list___Closure174 * this) {
  
}


static void list_ListI_ZcoroCoroutine_E_push(struct list_ListI_ZcoroCoroutine_E * this, struct coro_Coroutine * item) {
  {
    bool _a181 = item->link == nullptr;
    __cxy_assert(_a181, "/home/dev/.cxy/lib/cxy/std/stdlib/list.cxy", 9u, 9u);
  };
  if (this->_head == nullptr) {
    this->_head = item;
  } else {
    this->_tail->link = item;
  }
  this->count++;
  this->_tail = item;
}


static struct coro_Coroutine * list_ListI_ZcoroCoroutine_E_pop(struct list_ListI_ZcoroCoroutine_E * this) {
  struct coro_Coroutine * _rt206 = {};
  struct coro_Coroutine * item = this->_head;
  if (this->_head != nullptr) {
    this->count--;
    this->_head = this->_head->link;
    if (this->_head == nullptr) {
      this->_tail = nullptr;
    }
    item->link = nullptr;
  }
  _rt206 = item;
  return _rt206;
}


static struct list___Closure174 * list_ListI_ZcoroCoroutine_E_op__range(struct list_ListI_ZcoroCoroutine_E * this) {
  struct list___Closure174 * _rt207 = {};
  struct coro_Coroutine * item = this->_head;
  _rt207 = ({
    struct list___Closure174 * __obj175 = (struct list___Closure174 *)__smart_ptr_alloc(sizeof(list___Closure174), nullptr);
    __obj175->item = item;
    __obj175;
  });
  return _rt207;
}

__attribute__((always_inline))
static struct coro_Coroutine * list_ListI_ZcoroCoroutine_E_front(struct list_ListI_ZcoroCoroutine_E * this) {
  struct coro_Coroutine * _rt208 = {};
  if (this->_head == nullptr) {
    return nullptr;
  } else {
    _rt208 = this->_head;
    return _rt208;
  }
}

__attribute__((always_inline))
static struct coro_Coroutine * list_ListI_ZcoroCoroutine_E_back(struct list_ListI_ZcoroCoroutine_E * this) {
  struct coro_Coroutine * _rt209 = {};
  if (this->_tail == nullptr) {
    return nullptr;
  } else {
    _rt209 = this->_tail;
    return _rt209;
  }
}

__attribute__((always_inline))
static uint64_t list_ListI_ZcoroCoroutine_E_size(const struct list_ListI_ZcoroCoroutine_E * this) {
  uint64_t _rt210 = {};
  _rt210 = this->count;
  return _rt210;
}

__attribute__((always_inline))
static bool list_ListI_ZcoroCoroutine_E_empty(const struct list_ListI_ZcoroCoroutine_E * this) {
  bool _rt211 = {};
  _rt211 = this->_head == nullptr;
  return _rt211;
}

__attribute__((always_inline))
static struct coro_Coroutine coro_Coroutine_op__initCover(const char* name, int32_t id) {
  struct coro_Coroutine _rt212 = {};
  struct coro_Coroutine __obj176 = (struct coro_Coroutine){
    .link = (struct coro_Coroutine *) {},
    .scheduler = (void *) {},
    .id = (int32_t)-1,
    .result = (int32_t)0,
    .ready = false,
    .promise = (void *) {},
    .name = (const char*) {}
  };
  coro_Coroutine_op__init(&__obj176, name, id);
  _rt212 = __obj176;
  return _rt212;
}

__attribute__((always_inline))
static void builtins_OptionalI_PZcoroCachedStack_E_op__initI_E(struct OptionalI_PZcoroCachedStack_E * this) {
  this->ok = false;
  {
    memset(&this->val, 0, sizeof(struct coro_CachedStack *));
  };
}

__attribute__((always_inline))
static void builtins_OptionalI_PZcoroCachedStack_E_op__initI_PZcoroCachedStack_E(struct OptionalI_PZcoroCachedStack_E * this, struct coro_CachedStack * value) {
  this->val = value;
  this->ok = true;
}


static void builtins_OptionalI_PZcoroCachedStack_E_op__destructor(struct OptionalI_PZcoroCachedStack_E * this) {
  if (this->ok) {
    
  }
}

__attribute__((always_inline))
static struct OptionalI_PZcoroCachedStack_E builtins_OptionalI_PZcoroCachedStack_E_op__copy(struct OptionalI_PZcoroCachedStack_E * this) {
  struct OptionalI_PZcoroCachedStack_E _rt213 = {};
  _rt213 = (struct OptionalI_PZcoroCachedStack_E){
    .ok = this->ok,
    .val = this->val
  };
  return _rt213;
}

__attribute__((always_inline))
static bool builtins_OptionalI_PZcoroCachedStack_E_op__truthyI_E(struct OptionalI_PZcoroCachedStack_E * this) {
  bool _rt214 = {};
  _rt214 = this->ok;
  return _rt214;
}

__attribute__((always_inline))
static struct coro_CachedStack * builtins_OptionalI_PZcoroCachedStack_E_op__derefI_E(struct OptionalI_PZcoroCachedStack_E * this) {
  struct coro_CachedStack * _rt215 = {};
  _rt215 = this->val;
  return _rt215;
}

 __attribute__((optnone))
static struct coro_CachedStack * builtins_OptionalI_PZcoroCachedStack_E_move(struct OptionalI_PZcoroCachedStack_E * this) {
  struct coro_CachedStack * _rt216 = {};
  this->ok = false;
  _rt216 = this->val;
  return _rt216;
}

__attribute__((always_inline))
static struct coro_CachedStack * builtins_OptionalI_PZcoroCachedStack_E_op__lor(struct OptionalI_PZcoroCachedStack_E * this, struct coro_CachedStack * def) {
  struct coro_CachedStack * _rt217 = {};
  _rt217 = this->ok? builtins_OptionalI_PZcoroCachedStack_E_move(this): def;
  return _rt217;
}

__attribute__((always_inline))
static bool builtins_OptionalI_PZcoroCachedStack_E_op__truthyIc_E(const struct OptionalI_PZcoroCachedStack_E * this) {
  bool _rt218 = {};
  _rt218 = this->ok;
  return _rt218;
}

__attribute__((always_inline))
static struct coro_CachedStack * builtins_OptionalI_PZcoroCachedStack_E_op__derefIc_E(const struct OptionalI_PZcoroCachedStack_E * this) {
  struct coro_CachedStack * _rt219 = {};
  _rt219 = this->val;
  return _rt219;
}

__attribute__((always_inline))
static struct OptionalI_PZcoroCachedStack_E builtins_SomeI_PZcoroCachedStack_E(struct coro_CachedStack * value) {
  struct OptionalI_PZcoroCachedStack_E _rt220 = {};
  _rt220 = (struct OptionalI_PZcoroCachedStack_E){
    .ok = true,
    .val = value
  };
  return _rt220;
}

__attribute__((always_inline))
static struct OptionalI_PZcoroCachedStack_E builtins_OptionalI_PZcoroCachedStack_E_op__initCover() {
  struct OptionalI_PZcoroCachedStack_E _rt221 = {};
  struct OptionalI_PZcoroCachedStack_E __obj177 = (struct OptionalI_PZcoroCachedStack_E){
    .ok = false
  };
  builtins_OptionalI_PZcoroCachedStack_E_op__initI_E(&__obj177);
  _rt221 = __obj177;
  return _rt221;
}

__attribute__((always_inline))
static struct OptionalI_PZcoroCachedStack_E builtins_NoneI_PZcoroCachedStack_E() {
  struct OptionalI_PZcoroCachedStack_E _rt222 = {};
  _rt222 = builtins_OptionalI_PZcoroCachedStack_E_op__initCover();
  return _rt222;
}


static struct OptionalI_PZcoroCachedStack_E coro___Closure178_op__call(struct list___Closure178 * this) {
  struct OptionalI_PZcoroCachedStack_E _rt223 = {};
  if (this->item != nullptr) {
    struct coro_CachedStack * curr = this->item;
    this->item = this->item->link;
    _rt223 = builtins_SomeI_PZcoroCachedStack_E(curr);
    return _rt223;
  } else {
    _rt223 = builtins_NoneI_PZcoroCachedStack_E();
    return _rt223;
  }
}


static void coro___Closure178_op__init(struct list___Closure178 * this) {
  
}


static void list_ListI_ZcoroCachedStack_E_push(struct list_ListI_ZcoroCachedStack_E * this, struct coro_CachedStack * item) {
  {
    bool _a182 = item->link == nullptr;
    __cxy_assert(_a182, "/home/dev/.cxy/lib/cxy/std/stdlib/list.cxy", 9u, 9u);
  };
  if (this->_head == nullptr) {
    this->_head = item;
  } else {
    this->_tail->link = item;
  }
  this->count++;
  this->_tail = item;
}


static struct coro_CachedStack * list_ListI_ZcoroCachedStack_E_pop(struct list_ListI_ZcoroCachedStack_E * this) {
  struct coro_CachedStack * _rt224 = {};
  struct coro_CachedStack * item = this->_head;
  if (this->_head != nullptr) {
    this->count--;
    this->_head = this->_head->link;
    if (this->_head == nullptr) {
      this->_tail = nullptr;
    }
    item->link = nullptr;
  }
  _rt224 = item;
  return _rt224;
}


static struct list___Closure178 * list_ListI_ZcoroCachedStack_E_op__range(struct list_ListI_ZcoroCachedStack_E * this) {
  struct list___Closure178 * _rt225 = {};
  struct coro_CachedStack * item = this->_head;
  _rt225 = ({
    struct list___Closure178 * __obj179 = (struct list___Closure178 *)__smart_ptr_alloc(sizeof(list___Closure178), nullptr);
    __obj179->item = item;
    __obj179;
  });
  return _rt225;
}

__attribute__((always_inline))
static struct coro_CachedStack * list_ListI_ZcoroCachedStack_E_front(struct list_ListI_ZcoroCachedStack_E * this) {
  struct coro_CachedStack * _rt226 = {};
  if (this->_head == nullptr) {
    return nullptr;
  } else {
    _rt226 = this->_head;
    return _rt226;
  }
}

__attribute__((always_inline))
static struct coro_CachedStack * list_ListI_ZcoroCachedStack_E_back(struct list_ListI_ZcoroCachedStack_E * this) {
  struct coro_CachedStack * _rt227 = {};
  if (this->_tail == nullptr) {
    return nullptr;
  } else {
    _rt227 = this->_tail;
    return _rt227;
  }
}

__attribute__((always_inline))
static uint64_t list_ListI_ZcoroCachedStack_E_size(const struct list_ListI_ZcoroCachedStack_E * this) {
  uint64_t _rt228 = {};
  _rt228 = this->count;
  return _rt228;
}

__attribute__((always_inline))
static bool list_ListI_ZcoroCachedStack_E_empty(const struct list_ListI_ZcoroCachedStack_E * this) {
  bool _rt229 = {};
  _rt229 = this->_head == nullptr;
  return _rt229;
}


static void coro_CoroutineScheduler_op__init(struct coro_CoroutineScheduler * this) {
  this->running = &this->main;
  this->eventLoop = aeCreateEventLoop((void *)this, (int32_t)1024);
}


static void * coro_CoroutineScheduler_allocStack(struct coro_CoroutineScheduler * this) {
  void * _rt230 = {};
  void * ptr = nullptr;
  struct coro_CachedStack * stack = list_ListI_ZcoroCachedStack_E_pop(&this->stacks);
  if (stack != nullptr) {
    ptr = ((void *)stack);
  } else {
    ptr = mmap((void *) {}, coro_stackSize, (int32_t)3, (int32_t)34, (int32_t)-1, (int64_t)0);
  }
  uint8_t * top = ((uint8_t *)ptr) + coro_stackSize;
  _rt230 = (void *)top;
  return _rt230;
}


static void coro_CoroutineScheduler_freeStack(struct coro_CoroutineScheduler * this, void * ptr) {
  if (this->stacks.count >= 32u) {
    struct coro_CachedStack * stack = list_ListI_ZcoroCachedStack_E_pop(&this->stacks);
    munmap((void *)stack, coro_stackSize);
  } else {
    uint8_t * base = ((uint8_t *)ptr) + (-coro_stackSize);
    list_ListI_ZcoroCachedStack_E_push(&this->stacks, (struct coro_CachedStack *)base);
  }
}

__attribute__((always_inline))
static void coro_CoroutineScheduler_eventLoopWait(struct coro_CoroutineScheduler * this, int64_t timeout) {
  Flags _a183 = Flags_AE_FILE_EVENTS | Flags_AE_TIME_EVENTS;
  aeProcessEvents(this->eventLoop, _a183, timeout);
}


static void coro_CoroutineScheduler_eventLoopCallback(struct aeEventLoop * loop, int32_t fd, void * arg, int32_t mask) {
  struct coro_CoroutineScheduler * scheduler = ((struct coro_CoroutineScheduler *)loop->context);
  struct coro_Coroutine * cr = (struct coro_Coroutine *)arg;
  coro_CoroutineScheduler_resume(scheduler, cr, mask);
}


static Status coro_CoroutineScheduler_eventLoopTimerFired(struct aeEventLoop * loop, int64_t id, void * arg) {
  Status _rt231 = {};
  struct coro_CoroutineScheduler * scheduler = __smart_ptr_get((struct coro_CoroutineScheduler *)loop->context);
  struct coro_Coroutine * cr = (struct coro_Coroutine *)arg;
  coro_CoroutineScheduler_resume(scheduler, cr, (int32_t)id);
  __smart_ptr_drop(scheduler);
  return Status_AE_NO_MORE;
}


static int32_t coro_CoroutineScheduler_suspend(struct coro_CoroutineScheduler * this) {
  int32_t _rt232 = {};
  if (this->counter >= 103) {
    coro_CoroutineScheduler_eventLoopWait(this, (int64_t)0);
    this->counter = 0;
  }
  if (this->running != nullptr) {
    if (({
      volatile int32_t ret = 0;
      __asm__ __volatile__("\n        lea LJMPRET%=(%%rip), %%rcx\n        xor %0, %0\n        movq %%rbx,   (%1)\n        movq %%rbp,  8(%1)\n        movq %%r12, 16(%1)\n        movq %%r13, 24(%1)\n        movq %%r14, 32(%1)\n        movq %%r15, 40(%1)\n        movq %%rsp, 48(%1)\n        movq %%rcx, 56(%1)\n        LJMPRET%=:\n        "
      :"=&r" (ret)
      :"r" (&this->running->ctx)
      :"memory", "rcx", "rsi", "rdi", "r8", "r9", "r10", "r11", "cc");
      ret;
    }) != 0) {
      _rt232 = this->running->result;
      return _rt232;
    }
  }
  while (true) {
    {
      struct coro_Coroutine * coro = list_ListI_ZcoroCoroutine_E_pop(&this->ready);
      if (coro != nullptr) {
        this->counter++;
        {
          __cxy_assert(coro->ready, "/home/dev/.cxy/lib/cxy/std/stdlib/coro.cxy", 217u, 17u);
        };
        coro->ready = false;
        this->running = coro;
        {
          __asm__ __volatile__("\n        movq    $1, %%rdx\n        movq 56(%0), %%rcx\n        movq 48(%0), %%rsp\n        movq 40(%0), %%r15\n        movq 32(%0), %%r14\n        movq 24(%0), %%r13\n        movq 16(%0), %%r12\n        movq  8(%0), %%rbp\n        movq   (%0), %%rbx\n        .cfi_def_cfa %%rdx, 0\n        .cfi_offset %%rbx, 0\n        .cfi_offset %%rbp, 8\n        .cfi_offset %%r12, 16\n        .cfi_offset %%r13, 24\n        .cfi_offset %%r14, 32\n        .cfi_offset %%r15, 40\n        .cfi_offset %%rsp, 48\n        .cfi_offset %%rip, 56\n        jmp    *%%rcx\n        " :
          :"r" (&coro->ctx)
          :"rdx");
          
        };
      }
      coro_CoroutineScheduler_eventLoopWait(this, (int64_t)-1);
      this->counter = 0;
    }
    
  }
  return 0;
}


static void coro_CoroutineScheduler_resume(struct coro_CoroutineScheduler * this, struct coro_Coroutine * cr, int32_t res) {
  cr->ready = true;
  cr->result = res;
  list_ListI_ZcoroCoroutine_E_push(&this->ready, cr);
}


static void coro_CoroutineScheduler_yld(struct coro_CoroutineScheduler * this) {
  coro_CoroutineScheduler_resume(this, this->running, (int32_t)0);
  coro_CoroutineScheduler_suspend(this);
}


static struct coro_Coroutine * coro_CoroutineScheduler_prologue(struct coro_CoroutineScheduler * this, const char* name, const char* file, uint64_t line) {
  struct coro_Coroutine * _rt233 = {};
  void * stack = coro_CoroutineScheduler_allocStack(this);
  struct coro_Coroutine * cr = ((struct coro_Coroutine *)stack) + (-1);
  cr->link = nullptr;
  cr->scheduler = ((void *)this);
  cr->id = this->idGenerator++;
  cr->ready = false;
  cr->name = name;
  coro_CoroutineScheduler_resume(this, this->running, (int32_t)0);
  this->running = cr;
  _rt233 = cr;
  return _rt233;
}


static void coro_CoroutineScheduler_epilogue(struct coro_CoroutineScheduler * this) {
  struct coro_Coroutine * cr = this->running;
  struct coro_Coroutine * sp = cr + 1;
  this->running = nullptr;
  coro_CoroutineScheduler_freeStack(this, (void *)sp);
  coro_CoroutineScheduler_suspend(this);
}


static int32_t coro_CoroutineScheduler_fdWaitWrite(struct coro_CoroutineScheduler * this, int32_t fd, uint64_t timeout) {
  int32_t _rt234 = {};
  Status status = aeCreateFileEvent(this->eventLoop, fd, State_AE_WRITABLE, (Func859)coro_CoroutineScheduler_eventLoopCallback, (void *)this->running, timeout);
  if (status == Status_AE_OK) {
    int32_t result = coro_CoroutineScheduler_suspend(this);
    aeDeleteFileEvent(this->eventLoop, fd, State_AE_WRITABLE);
    _rt234 = result;
    return _rt234;
  }
  _rt234 = status;
  return _rt234;
}


static int32_t coro_CoroutineScheduler_fdWaitRead(struct coro_CoroutineScheduler * this, int32_t fd, uint64_t timeout) {
  int32_t _rt235 = {};
  Status status = aeCreateFileEvent(this->eventLoop, fd, State_AE_READABLE, (Func859)coro_CoroutineScheduler_eventLoopCallback, (void *)this->running, timeout);
  if (status == Status_AE_OK) {
    int32_t result = coro_CoroutineScheduler_suspend(this);
    aeDeleteFileEvent(this->eventLoop, fd, State_AE_READABLE);
    _rt235 = result;
    return _rt235;
  }
  _rt235 = status;
  return _rt235;
}


static void coro_CoroutineScheduler_sleep(struct coro_CoroutineScheduler * this, int64_t ms) {
  if (ms > 0) {
    Status status = aeCreateTimeEvent(this->eventLoop, ms, (Func861)coro_CoroutineScheduler_eventLoopTimerFired, (void *)this->running, (Func863) {});
    {
      bool _a184 = status != Status_AE_ERR;
      __cxy_assert(_a184, "/home/dev/.cxy/lib/cxy/std/stdlib/coro.cxy", 307u, 13u);
    };
    coro_CoroutineScheduler_suspend(this);
  }
}


static void coro_CoroutineScheduler_op__deinit(struct coro_CoroutineScheduler * this) {
  
}


static void coro_CoroutineScheduler_op__destructor(struct coro_CoroutineScheduler * this) {
  coro_CoroutineScheduler_op__deinit(this);
}


static void coro_CoroutineScheduler_op__destructor_fwd(void * ptr) {
  coro_CoroutineScheduler_op__destructor((struct coro_CoroutineScheduler *)ptr);
}


static void coro_CoroutineScheduler___defaults_init(struct coro_CoroutineScheduler * this) {
  this->running = nullptr;
  this->ready = (struct list_ListI_ZcoroCoroutine_E){
    ._head = (struct coro_Coroutine *) {},
    ._tail = (struct coro_Coroutine *) {},
    .count = (uint64_t)0
  };
  this->main = coro_Coroutine_op__initCover("main", (int32_t)0);
  this->stacks = (struct list_ListI_ZcoroCachedStack_E){
    ._head = (struct coro_CachedStack *) {},
    ._tail = (struct coro_CachedStack *) {},
    .count = (uint64_t)0
  };
  this->idGenerator = 1;
  this->counter = 0;
  this->eventLoop = nullptr;
}

__thread struct coro_CoroutineScheduler * coro___cxy_coro_scheduler = nullptr;
__attribute__((always_inline))
static struct coro_CoroutineScheduler * coro_CoroutineScheduler_op__initCover() {
  struct coro_CoroutineScheduler * _rt236 = {};
  struct coro_CoroutineScheduler * __obj180 = (struct coro_CoroutineScheduler *)__smart_ptr_alloc(sizeof(coro_CoroutineScheduler), coro_CoroutineScheduler_op__destructor_fwd);
  memset(__obj180, 0, sizeof(coro_CoroutineScheduler));
  coro_CoroutineScheduler___defaults_init(__obj180);
  coro_CoroutineScheduler_op__init(__obj180);
  _rt236 = __obj180;
  return _rt236;
}

__attribute__((always_inline))
static struct coro_CoroutineScheduler * coro___get_scheduler() {
  struct coro_CoroutineScheduler * _rt237 = {};
  if (unlikely(coro___cxy_coro_scheduler == nullptr)) {
    coro___cxy_coro_scheduler = coro_CoroutineScheduler_op__initCover();
  }
  _rt237 = coro___cxy_coro_scheduler;
  return _rt237;
}

__attribute__((always_inline))
static int64_t coro___now() {
  int64_t _rt238 = {};
  _rt238 = aeOsTime();
  return _rt238;
}

__attribute__((always_inline))
static int32_t coro___fdWaitRead(int32_t fd, uint64_t timeout) {
  int32_t _rt239 = {};
  struct coro_CoroutineScheduler * _m185 = coro___get_scheduler();
  _rt239 = coro_CoroutineScheduler_fdWaitRead(_m185, fd, timeout);
  return _rt239;
}

__attribute__((always_inline))
static int32_t coro___fdWaitWrite(int32_t fd, uint64_t timeout) {
  int32_t _rt240 = {};
  struct coro_CoroutineScheduler * _m186 = coro___get_scheduler();
  _rt240 = coro_CoroutineScheduler_fdWaitWrite(_m186, fd, timeout);
  return _rt240;
}

__attribute__((always_inline))
static void coro___sleep(int64_t ms) {
  struct coro_CoroutineScheduler * _m187 = coro___get_scheduler();
  coro_CoroutineScheduler_sleep(_m187, ms);
}


static void coro_Mutex_op__init(struct coro_Mutex * this) {
  
}


static void coro_Mutex_lock(struct coro_Mutex * this) {
  if (this->holder == nullptr) {
    struct coro_CoroutineScheduler * _m188 = coro___get_scheduler();
    this->holder = _m188->running;
    return;
  }
  struct coro_CoroutineScheduler * _m189 = coro___get_scheduler();
  list_ListI_ZcoroCoroutine_E_push(&this->waiting, _m189->running);
  struct coro_CoroutineScheduler * _m190 = coro___get_scheduler();
  coro_CoroutineScheduler_suspend(_m190);
}


static bool coro_Mutex_tryLock(struct coro_Mutex * this) {
  bool _rt241 = {};
  if (this->holder == nullptr) {
    struct coro_CoroutineScheduler * _m191 = coro___get_scheduler();
    this->holder = _m191->running;
    return true;
  }
  return false;
}


static void coro_Mutex_unlock(struct coro_Mutex * this) {
  struct coro_Coroutine * next = list_ListI_ZcoroCoroutine_E_pop(&this->waiting);
  if (next == nullptr) {
    return;
  }
  this->holder = next;
  struct coro_CoroutineScheduler * _m192 = coro___get_scheduler();
  coro_CoroutineScheduler_resume(_m192, next, (int32_t)0);
}

__attribute__((constructor))

static void coro___init_coro() {
  uint64_t _a193 = 1024u * 1024u;
  coro_stackSize = coro_stackAlign(_a193, (uint64_t)builtins_SysConfPageSize);
}

/*-----------/home/dev/.cxy/lib/cxy/std/stdlib/os.cxy-----------*/
typedef struct SliceI_Tss_E SliceI_Tss_E;
typedef struct os_Tuple1843 {
  const char* _0;
  const char* _1;
} os_Tuple1843;

struct  SliceI_Tss_E {
  struct os_Tuple1843 * data;
  uint64_t len;
};

typedef struct os_FileOutputStream os_FileOutputStream;
struct  os_FileOutputStream {
  struct OutputStream_VTable * vtable;
  bool closeOnDestruct;
  int32_t fd;
};

typedef struct os_FileInputStream os_FileInputStream;
typedef struct os_InputStream_VTable os_InputStream_VTable;
typedef struct os_InputStream os_InputStream;
struct  os_InputStream {
  struct os_InputStream_VTable * vtable;
};

typedef struct OptionalI_u64E(*os_InputStream_read_t)(struct os_InputStream *, void *, uint64_t);
typedef int64_t os_Seek;
enum {
  os_Seek_Set = 0,
  os_Seek_Current = 1,
  os_Seek_End = 2,
};

typedef struct OptionalI_u64E(*os_InputStream_seek_t)(struct os_InputStream *, uint64_t, os_Seek);
struct  os_InputStream_VTable {
  os_InputStream_read_t read;
  os_InputStream_seek_t seek;
};

struct  os_FileInputStream {
  struct os_InputStream_VTable * vtable;
  bool closeOnDestruct;
  int32_t fd;
};

typedef struct stat _stat;
typedef struct timespec _timespec;
struct  timespec {
  int64_t tv_sec;
  int64_t tv_nsec;
};

typedef int64_t Array1557[3];
struct  stat {
  uint64_t st_dev;
  uint64_t st_ino;
  uint64_t st_nlink;
  uint32_t st_mode;
  uint32_t st_uid;
  uint32_t st_gid;
  int32_t __pad0;
  uint64_t st_rdev;
  int64_t st_size;
  int64_t st_blksize;
  int64_t st_blocks;
  struct timespec st_atim;
  struct timespec st_mtim;
  struct timespec st_ctim;
  Array1557 __glibc_reserved;
};

typedef struct os_OSError os_OSError;
struct  os_OSError {
  struct Exception_VTable * vtable;
  const char* name;
  struct StackTrace stackTrace;
  struct String * msg;
};

typedef struct os_IOError os_IOError;
struct  os_IOError {
  struct Exception_VTable * vtable;
  const char* name;
  struct StackTrace stackTrace;
  struct String * msg;
};

typedef struct os_Union1657 os_Union1657;
struct os_Union1657{
  uint32_t tag;
  union {
    struct __string _0;
    struct Exception * _1;
  };
};

typedef struct os_Union1682 os_Union1682;
struct os_Union1682{
  uint32_t tag;
  union {
    uint64_t _0;
    struct Exception * _1;
  };
};

typedef struct os_FileDescriptor os_FileDescriptor;
struct  os_FileDescriptor {
  int32_t fd;
  bool closeAfter;
};

typedef struct os_Union1697 os_Union1697;
struct os_Union1697{
  uint32_t tag;
  union {
    struct os_FileDescriptor _0;
    struct Exception * _1;
  };
};

typedef struct os_Union1704 os_Union1704;
struct os_Union1704{
  uint32_t tag;
  union {
    const char* _0;
    struct __string _1;
    struct String * _2;
  };
};

typedef struct os_TempFile os_TempFile;
struct  os_TempFile {
  int32_t fd;
  struct String * path;
};

typedef struct os_Union1733 os_Union1733;
struct os_Union1733{
  uint32_t tag;
  union {
    struct os_TempFile _0;
    struct Exception * _1;
  };
};

typedef struct os_Union1761 os_Union1761;
struct os_Union1761{
  uint32_t tag;
  union {
    struct os_FileInputStream * _0;
    struct Exception * _1;
  };
};

typedef struct os_Union1773 os_Union1773;
struct os_Union1773{
  uint32_t tag;
  union {
    struct String * _0;
    struct Exception * _1;
  };
};

typedef char Array1788[4092];
typedef struct os_Union1794 os_Union1794;
struct os_Union1794{
  uint32_t tag;
  union {
    struct os_FileOutputStream * _0;
    struct Exception * _1;
  };
};

typedef struct os_Union1819 os_Union1819;
struct os_Union1819{
  uint32_t tag;
  union {
    int32_t _0;
    struct Exception * _1;
  };
};

typedef struct os_Process os_Process;
struct  os_Process {
  struct os_FileInputStream * _stdout;
  struct os_FileInputStream * _stderr;
  struct os_FileOutputStream * _stdin;
  int32_t _fdin;
  int32_t _fdout;
  int32_t _fderr;
  int32_t _pid;
};

typedef struct os_Union1836 os_Union1836;
struct os_Union1836{
  uint32_t tag;
  union {
    struct os_Process _0;
    struct Exception * _1;
  };
};

typedef struct OptionalI_TTss_i32_E OptionalI_TTss_i32_E;
typedef struct Tuple1858 {
  struct os_Tuple1843 _0;
  int32_t _1;
} Tuple1858;

struct  OptionalI_TTss_i32_E {
  bool ok;
  struct Tuple1858 val;
};

typedef struct __Closure401 __Closure401;
struct  __Closure401 {
  int32_t i;
  uint64_t len;
  struct os_Tuple1843 * data;
};

typedef int32_t Array580[2];
extern void exit(int32_t __status);
extern int32_t execvp(const char * __file, const char * * __argv);
extern int32_t dup2(int32_t __fd, int32_t __fd2);
extern int32_t fork();
extern int32_t pipe(int32_t * __pipedes);
static void builtins_SliceI_Tss_E_op__init(struct SliceI_Tss_E * this, struct os_Tuple1843 * data, uint64_t len);
extern int32_t pidfd_open(int32_t __pid, uint32_t __flags);
extern int32_t waitpid(int32_t __pid, int32_t * __stat_loc, int32_t __options);
extern int64_t write(int32_t __fd, const void * __buf, uint64_t __n);
static struct OptionalI_u64E os_FileOutputStream_append(struct os_FileOutputStream * this, const void * data, uint64_t size);
static void os_FileOutputStream_op__init(struct os_FileOutputStream * this, int32_t fd, bool closeOnDestruct, bool nonBlocking);
static void os_FileOutputStream___defaults_init(struct os_FileOutputStream * this);
static void os_FileOutputStream_op__destructor_fwd(void * ptr);
static struct Union416 os_FileInputStream_readAllI_RZOutputStream_E(struct os_FileInputStream * this, struct OutputStream * os);
extern int64_t lseek(int32_t __fd, int64_t __offset, int32_t __whence);
extern int64_t read(int32_t __fd, void * __buf, uint64_t __nbytes);
static struct OptionalI_u64E os_FileInputStream_seek(struct os_FileInputStream * this, uint64_t off, os_Seek whence);
static struct OptionalI_u64E os_FileInputStream_read(struct os_FileInputStream * this, void * buf, uint64_t size);
static void os_FileInputStream_op__init(struct os_FileInputStream * this, int32_t fd, bool closeOnDestruct, bool nonBlocking);
static void os_FileInputStream___defaults_init(struct os_FileInputStream * this);
static void os_FileInputStream_op__destructor_fwd(void * ptr);
extern int32_t mkstemps(char * __template, int32_t __suffixlen);
extern int32_t unlink(const char * __name);
extern int32_t open(const char * __file, int32_t __oflag, ...);
extern int32_t close(int32_t __fd);
extern int32_t unsetenv(const char * __name);
extern int32_t setenv(const char * __name, const char * __value, int32_t __replace);
extern char * getenv(const char * __name);
extern int32_t fcntl(int32_t __fd, int32_t __cmd, ...);
extern int32_t fs_lstat(const char * path, struct stat * st);
extern int32_t fs_fstat(int32_t fd, struct stat * st);
extern int32_t fs_stat(const char * path, struct stat * st);
static const char* os_OSError_what(struct os_OSError * this);
static const char* os_IOError_what(struct os_IOError * this);
struct Exception_VTable os_IOError_vTable = (struct Exception_VTable){
  .what = (builtins_Exception_what_t)os_IOError_what
};

static void os_IOError_op__init(struct os_IOError * this, struct String * msg) {
  builtins_Exception_op__init((struct Exception *)this, "IOError");
  __smart_ptr_drop(this->msg);
  this->msg = __smart_ptr_get(msg);
  __smart_ptr_drop(msg);
}


static const char* os_IOError_what(struct os_IOError * this) {
  const char* _rt535 = {};
  _rt535 = this->msg == nullptr? "": builtins_String_str(this->msg);
  return _rt535;
}


static void os_IOError_op__destructor(struct os_IOError * this) {
  builtins_Exception_op__destructor((struct Exception *)this);
  __smart_ptr_drop(this->msg);
  *(&this->msg) = nullptr;
}


static void os_IOError_op__destructor_fwd(void * ptr) {
  os_IOError_op__destructor((struct os_IOError *)ptr);
}


static void os_IOError___defaults_init(struct os_IOError * this) {
  builtins_Exception___defaults_init(this);
  this->vtable = &os_IOError_vTable;
}

struct Exception_VTable os_OSError_vTable = (struct Exception_VTable){
  .what = (builtins_Exception_what_t)os_OSError_what
};

static void os_OSError_op__init(struct os_OSError * this, struct String * msg) {
  builtins_Exception_op__init((struct Exception *)this, "OSError");
  __smart_ptr_drop(this->msg);
  this->msg = __smart_ptr_get(msg);
  __smart_ptr_drop(msg);
}


static const char* os_OSError_what(struct os_OSError * this) {
  const char* _rt536 = {};
  _rt536 = this->msg == nullptr? "": builtins_String_str(this->msg);
  return _rt536;
}


static void os_OSError_op__destructor(struct os_OSError * this) {
  builtins_Exception_op__destructor((struct Exception *)this);
  __smart_ptr_drop(this->msg);
  *(&this->msg) = nullptr;
}


static void os_OSError_op__destructor_fwd(void * ptr) {
  os_OSError_op__destructor((struct os_OSError *)ptr);
}


static void os_OSError___defaults_init(struct os_OSError * this) {
  builtins_Exception___defaults_init(this);
  this->vtable = &os_OSError_vTable;
}

__attribute__((always_inline))
static int32_t os_stat(const char* path, struct stat * s) {
  int32_t _rt537 = {};
  _rt537 = fs_stat((const char *)path, s);
  return _rt537;
}

__attribute__((always_inline))
static int32_t os_fstat(int32_t fd, struct stat * s) {
  int32_t _rt538 = {};
  _rt538 = fs_fstat(fd, s);
  return _rt538;
}

__attribute__((always_inline))
static int32_t os_lstat(const char* path, struct stat * s) {
  int32_t _rt539 = {};
  _rt539 = fs_lstat((const char *)path, s);
  return _rt539;
}

__attribute__((always_inline))
static bool os_setNonblocking(int32_t fd, bool blocking) {
  bool _rt540 = {};
  int32_t flags = fcntl(fd, 3, 0);
  if (flags == -1) {
    return false;
  }
  flags = (blocking? (flags & ~(2048u)): (flags | 2048));
  _rt540 = (fcntl(fd, 4, flags) == 0);
  return _rt540;
}


static struct os_Union1657 builtins___union_copyI_U_Z__string_ZException__E(struct os_Union1657 * obj) {
  struct os_Union1657 _rt541 = {};
  switch (obj->tag) {
  case 0u: {
    {
      struct __string * y = &obj->_0;
      _rt541 = (struct os_Union1657){.tag = 0, ._0 = *(y)};
      return _rt541;
    }
  }
  case 1u: {
    {
      struct Exception * y = obj->_1;
      _rt541 = (struct os_Union1657){.tag = 1, ._1 = __smart_ptr_get(y)};
      return _rt541;
    }
  }
  default: { unreachable("unhandled-default-case"); }
  }
  
}


static void builtins___union_dctorI_U_Z__string_ZException__E(struct os_Union1657 * obj) {
  switch (obj->tag) {
  case 0u: {
    {
      struct __string * y = &obj->_0;
    }
    break;
  }
  case 1u: {
    {
      struct Exception * y = obj->_1;
      __smart_ptr_drop(y);
    }
    break;
  }
  default: { unreachable("unhandled-default-case"); }
  }
  
}

__attribute__((always_inline))
static struct String * builtins_String_op__initI_ECover() {
  struct String * _rt542 = {};
  struct String * __obj369 = (struct String *)__smart_ptr_alloc(sizeof(String), builtins_String_op__destructor_fwd);
  memset(__obj369, 0, sizeof(String));
  builtins_String___defaults_init(__obj369);
  builtins_String_op__initI_E(__obj369);
  _rt542 = __obj369;
  return _rt542;
}

__attribute__((always_inline))
static struct os_OSError * os_OSError_op__initCover(struct String * msg) {
  struct os_OSError * _rt543 = {};
  struct os_OSError * __obj370 = (struct os_OSError *)__smart_ptr_alloc(sizeof(os_OSError), os_OSError_op__destructor_fwd);
  memset(__obj370, 0, sizeof(os_OSError));
  os_OSError___defaults_init(__obj370);
  os_OSError_op__init(__obj370, msg);
  _rt543 = __obj370;
  return _rt543;
}

__attribute__((always_inline))
static struct os_Union1657 os_getenv(const char* name, const char* def) {
  struct os_Union1657 _rt544 = {};
  const char* value = (const char*)getenv((const char *)name);
  if (value == nullptr) {
    if (def == nullptr) {
      struct String * sb303 = builtins_String_op__initI_ECover();
      struct OutputStream * _m415 = (struct OutputStream *)sb303;
      struct OutputStream * _m416 = builtins_OutputStream_op__lshiftI_sE(_m415, "environment variable ");
      struct OutputStream * _m417 = builtins_OutputStream_op__lshiftI_sE(_m416, name);
      builtins_OutputStream_op__lshiftI_sE(_m417, " does not exist");
      struct Exception * _ex304 = (struct Exception *)os_OSError_op__initCover(__smart_ptr_get(sb303));
      builtins_Exception_push(_ex304, "os", (const char*) {}, "getenv", "/home/dev/.cxy/lib/cxy/std/stdlib/os.cxy", (uint64_t)69);
      _rt544 = (struct os_Union1657){.tag = 1, ._1 = _ex304};
      __smart_ptr_drop(sb303);
      return _rt544;
    }
    value = def;
  }
  _rt544 = (struct os_Union1657){.tag = 0, ._0 = builtins___string_op__initCoverI_sE(value)};
  return _rt544;
}


static struct Union416 builtins___union_copyI_U_ZVoid_ZException__E(struct Union416 * obj) {
  struct Union416 _rt545 = {};
  switch (obj->tag) {
  case 0u: {
    {
      struct Void * y = &obj->_0;
      _rt545 = (struct Union416){.tag = 0, ._0 = *(y)};
      return _rt545;
    }
  }
  case 1u: {
    {
      struct Exception * y = obj->_1;
      _rt545 = (struct Union416){.tag = 1, ._1 = __smart_ptr_get(y)};
      return _rt545;
    }
  }
  default: { unreachable("unhandled-default-case"); }
  }
  
  _rt545 = (struct Union416){.tag = 0, ._0 = (struct Void){}};
  return _rt545;
}


static void builtins___union_dctorI_U_ZVoid_ZException__E(struct Union416 * obj) {
  switch (obj->tag) {
  case 0u: {
    {
      struct Void * y = &obj->_0;
    }
    break;
  }
  case 1u: {
    {
      struct Exception * y = obj->_1;
      __smart_ptr_drop(y);
    }
    break;
  }
  default: { unreachable("unhandled-default-case"); }
  }
  
}

__attribute__((always_inline))
static struct Union416 os_setenv(const char* name, const char* value, bool overwrite) {
  struct Union416 _rt546 = {};
  if (setenv((const char *)name, (const char *)value, (int32_t)(uint8_t)overwrite) != 0) {
    struct String * sb305 = builtins_String_op__initI_ECover();
    const char* _rv371 = builtins_strerr();
    struct OutputStream * _m418 = (struct OutputStream *)sb305;
    struct OutputStream * _m419 = builtins_OutputStream_op__lshiftI_sE(_m418, "setenv ");
    struct OutputStream * _m420 = builtins_OutputStream_op__lshiftI_sE(_m419, name);
    struct OutputStream * _m421 = builtins_OutputStream_op__lshiftI_sE(_m420, "=");
    struct OutputStream * _m422 = builtins_OutputStream_op__lshiftI_sE(_m421, value);
    struct OutputStream * _m423 = builtins_OutputStream_op__lshiftI_sE(_m422, " failed: ");
    builtins_OutputStream_op__lshiftI_sE(_m423, _rv371);
    struct Exception * _ex306 = (struct Exception *)os_OSError_op__initCover(__smart_ptr_get(sb305));
    builtins_Exception_push(_ex306, "os", (const char*) {}, "setenv", "/home/dev/.cxy/lib/cxy/std/stdlib/os.cxy", (uint64_t)78);
    _rt546 = (struct Union416){.tag = 1, ._1 = _ex306};
    __smart_ptr_drop(sb305);
    return _rt546;
  }
  _rt546 = (struct Union416){.tag = 0, ._0 = (struct Void){}};
  return _rt546;
}

__attribute__((always_inline))
static struct Union416 os_unsetenv(const char* name) {
  struct Union416 _rt547 = {};
  if (unsetenv((const char *)name) != 0) {
    struct String * sb307 = builtins_String_op__initI_ECover();
    const char* _rv372 = builtins_strerr();
    struct OutputStream * _m424 = (struct OutputStream *)sb307;
    struct OutputStream * _m425 = builtins_OutputStream_op__lshiftI_sE(_m424, "unsetenv ");
    struct OutputStream * _m426 = builtins_OutputStream_op__lshiftI_sE(_m425, name);
    struct OutputStream * _m427 = builtins_OutputStream_op__lshiftI_sE(_m426, " failed: ");
    builtins_OutputStream_op__lshiftI_sE(_m427, _rv372);
    struct Exception * _ex308 = (struct Exception *)os_OSError_op__initCover(__smart_ptr_get(sb307));
    builtins_Exception_push(_ex308, "os", (const char*) {}, "unsetenv", "/home/dev/.cxy/lib/cxy/std/stdlib/os.cxy", (uint64_t)84);
    _rt547 = (struct Union416){.tag = 1, ._1 = _ex308};
    __smart_ptr_drop(sb307);
    return _rt547;
  }
  _rt547 = (struct Union416){.tag = 0, ._0 = (struct Void){}};
  return _rt547;
}


static struct os_Union1682 builtins___union_copyI_U_u64ZException__E(struct os_Union1682 * obj) {
  struct os_Union1682 _rt548 = {};
  switch (obj->tag) {
  case 0u: {
    {
      uint64_t y = obj->_0;
      _rt548 = (struct os_Union1682){.tag = 0, ._0 = y};
      return _rt548;
    }
  }
  case 1u: {
    {
      struct Exception * y = obj->_1;
      _rt548 = (struct os_Union1682){.tag = 1, ._1 = __smart_ptr_get(y)};
      return _rt548;
    }
  }
  default: { unreachable("unhandled-default-case"); }
  }
  
}


static void builtins___union_dctorI_U_u64ZException__E(struct os_Union1682 * obj) {
  switch (obj->tag) {
  case 0u: {
    {
      uint64_t y = obj->_0;
    }
    break;
  }
  case 1u: {
    {
      struct Exception * y = obj->_1;
      __smart_ptr_drop(y);
    }
    break;
  }
  default: { unreachable("unhandled-default-case"); }
  }
  
}


static struct OutputStream * builtins_OutputStream_op__lshiftI_i32E(struct OutputStream * this, const int32_t val) {
  struct OutputStream * _rt549 = {};
  builtins_OutputStream_appendSignedInt(this, (int64_t)val);
  _rt549 = this;
  return _rt549;
}

__attribute__((always_inline))
static struct os_IOError * os_IOError_op__initCover(struct String * msg) {
  struct os_IOError * _rt550 = {};
  struct os_IOError * __obj374 = (struct os_IOError *)__smart_ptr_alloc(sizeof(os_IOError), os_IOError_op__destructor_fwd);
  memset(__obj374, 0, sizeof(os_IOError));
  os_IOError___defaults_init(__obj374);
  os_IOError_op__init(__obj374, msg);
  _rt550 = __obj374;
  return _rt550;
}


static void os_FileDescriptor_op__init(struct os_FileDescriptor * this, int32_t fd, bool closeAfter) {
  this->fd = fd;
  this->closeAfter = closeAfter;
}

__attribute__((always_inline))
static void os_FileDescriptor_close(struct os_FileDescriptor * this) {
  if (this->fd != -1) {
    close(this->fd);
  }
}


static void os_FileDescriptor_op__deinit(struct os_FileDescriptor * this) {
  if (this->closeAfter) {
    os_FileDescriptor_close(this);
    this->fd = -1;
    this->closeAfter = false;
  }
}

__attribute__((always_inline))
static struct os_Union1682 os_FileDescriptor_size(struct os_FileDescriptor * this) {
  struct os_Union1682 _rt551 = {};
  struct stat st = (struct stat){};
  if (fs_fstat(this->fd, &st) != 0) {
    struct String * sb309 = builtins_String_op__initI_ECover();
    const char* _rv373 = builtins_strerr();
    struct OutputStream * _m428 = (struct OutputStream *)sb309;
    struct OutputStream * _m429 = builtins_OutputStream_op__lshiftI_sE(_m428, "fstat(");
    struct OutputStream * _m430 = builtins_OutputStream_op__lshiftI_i32E(_m429, this->fd);
    struct OutputStream * _m431 = builtins_OutputStream_op__lshiftI_sE(_m430, ") failed: ");
    builtins_OutputStream_op__lshiftI_sE(_m431, _rv373);
    struct Exception * _ex310 = (struct Exception *)os_IOError_op__initCover(__smart_ptr_get(sb309));
    builtins_Exception_push(_ex310, "os", "FileDescriptor", "size", "/home/dev/.cxy/lib/cxy/std/stdlib/os.cxy", (uint64_t)122);
    _rt551 = (struct os_Union1682){.tag = 1, ._1 = _ex310};
    __smart_ptr_drop(sb309);
    return _rt551;
  }
  _rt551 = (struct os_Union1682){.tag = 0, ._0 = (uint64_t)st.st_size};
  return _rt551;
}

__attribute__((always_inline))
static bool os_FileDescriptor_op__truthy(struct os_FileDescriptor * this) {
  bool _rt552 = {};
  _rt552 = this->fd != -1;
  return _rt552;
}

__attribute__((always_inline))
static struct os_FileDescriptor os_FileDescriptor_op__copy(struct os_FileDescriptor * this) {
  struct os_FileDescriptor _rt553 = {};
  _rt553 = (struct os_FileDescriptor){
    .fd = this->fd,
    .closeAfter = this->closeAfter
  };
  return _rt553;
}


static void os_FileDescriptor_op__destructor(struct os_FileDescriptor * this) {
  os_FileDescriptor_op__deinit(this);
}


static struct os_Union1697 builtins___union_copyI_U_ZosFileDescriptor_ZException__E(struct os_Union1697 * obj) {
  struct os_Union1697 _rt554 = {};
  switch (obj->tag) {
  case 0u: {
    {
      struct os_FileDescriptor * y = &obj->_0;
      _rt554 = (struct os_Union1697){.tag = 0, ._0 = os_FileDescriptor_op__copy(y)};
      return _rt554;
    }
  }
  case 1u: {
    {
      struct Exception * y = obj->_1;
      _rt554 = (struct os_Union1697){.tag = 1, ._1 = __smart_ptr_get(y)};
      return _rt554;
    }
  }
  default: { unreachable("unhandled-default-case"); }
  }
  
}


static void builtins___union_dctorI_U_ZosFileDescriptor_ZException__E(struct os_Union1697 * obj) {
  switch (obj->tag) {
  case 0u: {
    {
      struct os_FileDescriptor * y = &obj->_0;
      os_FileDescriptor_op__destructor(y);
    }
    break;
  }
  case 1u: {
    {
      struct Exception * y = obj->_1;
      __smart_ptr_drop(y);
    }
    break;
  }
  default: { unreachable("unhandled-default-case"); }
  }
  
}


static struct os_Union1704 builtins___union_copyI_U_sZ__string_ZString__E(struct os_Union1704 * obj) {
  struct os_Union1704 _rt555 = {};
  switch (obj->tag) {
  case 0u: {
    {
      const char* y = obj->_0;
      _rt555 = (struct os_Union1704){.tag = 0, ._0 = y};
      return _rt555;
    }
  }
  case 1u: {
    {
      struct __string * y = &obj->_1;
      _rt555 = (struct os_Union1704){.tag = 1, ._1 = *(y)};
      return _rt555;
    }
  }
  case 2u: {
    {
      struct String * y = obj->_2;
      _rt555 = (struct os_Union1704){.tag = 2, ._2 = __smart_ptr_get(y)};
      return _rt555;
    }
  }
  default: { unreachable("unhandled-default-case"); }
  }
  
}


static void builtins___union_dctorI_U_sZ__string_ZString__E(struct os_Union1704 * obj) {
  switch (obj->tag) {
  case 0u: {
    {
      const char* y = obj->_0;
    }
    break;
  }
  case 1u: {
    {
      struct __string * y = &obj->_1;
    }
    break;
  }
  case 2u: {
    {
      struct String * y = obj->_2;
      __smart_ptr_drop(y);
    }
    break;
  }
  default: { unreachable("unhandled-default-case"); }
  }
  
}


static struct OutputStream * builtins_OutputStream_op__lshiftI_Z__string_E(struct OutputStream * this, const struct __string * val) {
  struct OutputStream * _rt556 = {};
  builtins_OutputStream_appendStringI_cRZ__string_E(this, val);
  _rt556 = this;
  return _rt556;
}

__attribute__((always_inline))
static bool builtins_isnullI_ZString_E(const struct String * cls) {
  bool _rt557 = {};
  _rt557 = ((const void *)cls) == nullptr;
  return _rt557;
}


static struct OutputStream * builtins_OutputStream_op__lshiftI_ZString_E(struct OutputStream * this, const struct String * val) {
  struct OutputStream * _rt558 = {};
  if (builtins_isnullI_ZString_E(val)) {
    builtins_OutputStream_appendStringI_sE(this, "null");
  } else {
    uint64_t _a432 = builtins_String_size(val);
    this->vtable->append(this, (const void *)val->_data, _a432);
  }
  _rt558 = this;
  return _rt558;
}


static struct OutputStream * builtins_OutputStream_op__lshiftI_U_sZ__string_ZString__E(struct OutputStream * this, const struct os_Union1704 * val) {
  struct OutputStream * _rt559 = {};
  switch (val->tag) {
  case 0u: {
    {
      const char* y = val->_0;
      builtins_OutputStream_op__lshiftI_sE(this, y);
    }
    break;
  }
  case 1u: {
    {
      const struct __string * y = &val->_1;
      builtins_OutputStream_op__lshiftI_Z__string_E(this, y);
    }
    break;
  }
  case 2u: {
    {
      const struct String * y = val->_2;
      builtins_OutputStream_op__lshiftI_ZString_E(this, y);
    }
    break;
  }
  default: { unreachable("unhandled-default-case"); }
  }
  
  _rt559 = this;
  return _rt559;
}

__attribute__((always_inline))
static struct os_FileDescriptor os_FileDescriptor_op__initCover(int32_t fd, bool closeAfter) {
  struct os_FileDescriptor _rt560 = {};
  struct os_FileDescriptor __obj376 = (struct os_FileDescriptor){
    .fd = -1,
    .closeAfter = false
  };
  os_FileDescriptor_op__init(&__obj376, fd, closeAfter);
  _rt560 = __obj376;
  return _rt560;
}


static struct os_Union1697 os_open(struct os_Union1704 path, bool nonBlocking, int32_t flags, int32_t mode) {
  struct os_Union1697 _rt561 = {};
  const char* spath = nullptr;
  switch (path.tag) {
  case 0u: {
    {
      __cxy_assert(path.tag == 0u, "/home/dev/.cxy/lib/cxy/std/stdlib/os.cxy", 137u, 12u);
      const char* s = path._0;
      spath = s;
    }
    break;
  }
  case 1u: {
    {
      __cxy_assert(path.tag == 1u, "/home/dev/.cxy/lib/cxy/std/stdlib/os.cxy", 137u, 12u);
      struct __string * s = &path._1;
      spath = builtins___string_str(s);
    }
    break;
  }
  case 2u: {
    {
      __cxy_assert(path.tag == 2u, "/home/dev/.cxy/lib/cxy/std/stdlib/os.cxy", 137u, 12u);
      struct String * s = path._2;
      spath = builtins_String_str(s);
    }
    break;
  }
  default: { unreachable("unhandled-default-case"); }
  }
  
  int32_t fd = open((const char *)spath, flags, mode);
  if (fd < 0) {
    struct String * sb311 = builtins_String_op__initI_ECover();
    const char* _rv375 = builtins_strerr();
    struct OutputStream * _m433 = (struct OutputStream *)sb311;
    struct OutputStream * _m434 = builtins_OutputStream_op__lshiftI_sE(_m433, "opening file '");
    struct OutputStream * _m435 = builtins_OutputStream_op__lshiftI_U_sZ__string_ZString__E(_m434, (const struct os_Union1704 *)&path);
    struct OutputStream * _m436 = builtins_OutputStream_op__lshiftI_sE(_m435, "' failed: ");
    builtins_OutputStream_op__lshiftI_sE(_m436, _rv375);
    struct Exception * _ex312 = (struct Exception *)os_IOError_op__initCover(__smart_ptr_get(sb311));
    builtins_Exception_push(_ex312, "os", (const char*) {}, "open", "/home/dev/.cxy/lib/cxy/std/stdlib/os.cxy", (uint64_t)145);
    _rt561 = (struct os_Union1697){.tag = 1, ._1 = _ex312};
    __smart_ptr_drop(sb311);
    builtins___union_dctorI_U_sZ__string_ZString__E(&(path));
    return _rt561;
  }
  if (nonBlocking) {
    os_setNonblocking(fd, false);
  }
  _rt561 = (struct os_Union1697){.tag = 0, ._0 = os_FileDescriptor_op__initCover(fd, true)};
  builtins___union_dctorI_U_sZ__string_ZString__E(&(path));
  return _rt561;
}


static void os_TempFile_op__init(struct os_TempFile * this, int32_t fd, struct String * path) {
  this->fd = fd;
  __smart_ptr_drop(this->path);
  this->path = path;
}


static void os_TempFile_op__deinit(struct os_TempFile * this) {
  if (this->path != nullptr) {
    const char * _a437 = (const char *)builtins_String_str(this->path);
    unlink(_a437);
    __smart_ptr_drop(this->path);
    this->path = nullptr;
    this->fd = -1;
  }
}

__attribute__((always_inline))
static struct String * os_TempFile_name(struct os_TempFile * this) {
  struct String * _rt562 = {};
  _rt562 = this->path;
  return _rt562;
}

__attribute__((always_inline))
static bool os_TempFile_op__truthy(struct os_TempFile * this) {
  bool _rt563 = {};
  _rt563 = this->path != nullptr;
  return _rt563;
}

__attribute__((always_inline))
static struct os_Union1682 os_TempFile_size(struct os_TempFile * this) {
  struct os_Union1682 _rt564 = {};
  struct stat st = (struct stat){};
  if (fs_fstat(this->fd, &st) != 0) {
    struct String * sb313 = builtins_String_op__initI_ECover();
    const char* _rv377 = builtins_strerr();
    struct OutputStream * _m438 = (struct OutputStream *)sb313;
    struct OutputStream * _m439 = builtins_OutputStream_op__lshiftI_sE(_m438, "fstat(");
    struct OutputStream * _m440 = builtins_OutputStream_op__lshiftI_i32E(_m439, this->fd);
    struct OutputStream * _m441 = builtins_OutputStream_op__lshiftI_sE(_m440, ") failed: ");
    builtins_OutputStream_op__lshiftI_sE(_m441, _rv377);
    struct Exception * _ex314 = (struct Exception *)os_IOError_op__initCover(__smart_ptr_get(sb313));
    builtins_Exception_push(_ex314, "os", "TempFile", "size", "/home/dev/.cxy/lib/cxy/std/stdlib/os.cxy", (uint64_t)178);
    _rt564 = (struct os_Union1682){.tag = 1, ._1 = _ex314};
    __smart_ptr_drop(sb313);
    return _rt564;
  }
  _rt564 = (struct os_Union1682){.tag = 0, ._0 = (uint64_t)st.st_size};
  return _rt564;
}

__attribute__((always_inline))
static struct String * os_TempFile_keep(struct os_TempFile * this) {
  struct String * _rt565 = {};
  _rt565 = this->path;
  *(&this->path) = nullptr;
  return _rt565;
}

__attribute__((always_inline))
static struct os_TempFile os_TempFile_op__copy(struct os_TempFile * this) {
  struct os_TempFile _rt566 = {};
  _rt566 = (struct os_TempFile){
    .fd = this->fd,
    .path = (struct String *)__smart_ptr_get(this->path)
  };
  return _rt566;
}


static void os_TempFile_op__destructor(struct os_TempFile * this) {
  os_TempFile_op__deinit(this);
  __smart_ptr_drop(this->path);
  *(&this->path) = nullptr;
}


static struct os_Union1733 builtins___union_copyI_U_ZosTempFile_ZException__E(struct os_Union1733 * obj) {
  struct os_Union1733 _rt567 = {};
  switch (obj->tag) {
  case 0u: {
    {
      struct os_TempFile * y = &obj->_0;
      _rt567 = (struct os_Union1733){.tag = 0, ._0 = os_TempFile_op__copy(y)};
      return _rt567;
    }
  }
  case 1u: {
    {
      struct Exception * y = obj->_1;
      _rt567 = (struct os_Union1733){.tag = 1, ._1 = __smart_ptr_get(y)};
      return _rt567;
    }
  }
  default: { unreachable("unhandled-default-case"); }
  }
  
}


static void builtins___union_dctorI_U_ZosTempFile_ZException__E(struct os_Union1733 * obj) {
  switch (obj->tag) {
  case 0u: {
    {
      struct os_TempFile * y = &obj->_0;
      os_TempFile_op__destructor(y);
    }
    break;
  }
  case 1u: {
    {
      struct Exception * y = obj->_1;
      __smart_ptr_drop(y);
    }
    break;
  }
  default: { unreachable("unhandled-default-case"); }
  }
  
}

__attribute__((always_inline))
static struct __string builtins___string_op__initI_ECover() {
  struct __string _rt568 = {};
  struct __string __obj378 = (struct __string){
    .s = (const char*) {},
    ._size = (uint64_t)0
  };
  builtins___string_op__initI_E(&__obj378);
  _rt568 = __obj378;
  return _rt568;
}

__attribute__((always_inline))
static struct String * builtins_String_op__initI_sECoverI_sE(const char* str) {
  struct String * _rt569 = {};
  struct String * __obj379 = (struct String *)__smart_ptr_alloc(sizeof(String), builtins_String_op__destructor_fwd);
  memset(__obj379, 0, sizeof(String));
  builtins_String___defaults_init(__obj379);
  builtins_String_op__initI_sE(__obj379, str);
  _rt569 = __obj379;
  return _rt569;
}

__attribute__((always_inline))
static struct os_TempFile os_TempFile_op__initCover(int32_t fd, struct String * path) {
  struct os_TempFile _rt570 = {};
  struct os_TempFile __obj381 = (struct os_TempFile){
    .fd = -1,
    .path = (struct String *)nullptr
  };
  os_TempFile_op__init(&__obj381, fd, path);
  _rt570 = __obj381;
  return _rt570;
}


static struct os_Union1733 os_mkstemp(const char* prefix, struct __string suffix, bool nonBlocking) {
  struct os_Union1733 _rt571 = {};
  struct String * path = builtins_String_op__initI_sECoverI_sE(prefix);
  struct OutputStream * _m442 = (struct OutputStream *)path;
  struct OutputStream * _m443 = builtins_OutputStream_op__lshiftI_sE(_m442, "XXXXXX");
  builtins_OutputStream_op__lshiftI_Z__string_E(_m443, (const struct __string *)&suffix);
  int32_t fd = {};
  {
    char * _a444 = (char *)builtins_String_data(path);
    int32_t _a445 = (int32_t)builtins___string_size(&suffix);
    fd = mkstemps(_a444, _a445);
  }
  if (fd < 0) {
    struct String * sb315 = builtins_String_op__initI_ECover();
    const char* _rv380 = builtins_strerr();
    struct OutputStream * _m446 = (struct OutputStream *)sb315;
    struct OutputStream * _m447 = builtins_OutputStream_op__lshiftI_sE(_m446, "creating temp file ");
    struct OutputStream * _m448 = builtins_OutputStream_op__lshiftI_ZString_E(_m447, (const struct String *)path);
    struct OutputStream * _m449 = builtins_OutputStream_op__lshiftI_sE(_m448, " failed: ");
    builtins_OutputStream_op__lshiftI_sE(_m449, _rv380);
    struct Exception * _ex316 = (struct Exception *)os_IOError_op__initCover(__smart_ptr_get(sb315));
    builtins_Exception_push(_ex316, "os", (const char*) {}, "mkstemp", "/home/dev/.cxy/lib/cxy/std/stdlib/os.cxy", (uint64_t)202);
    _rt571 = (struct os_Union1733){.tag = 1, ._1 = _ex316};
    __smart_ptr_drop(sb315);
    __smart_ptr_drop(path);
    return _rt571;
  }
  if (nonBlocking) {
    os_setNonblocking(fd, false);
  }
  _rt571 = (struct os_Union1733){.tag = 0, ._0 = os_TempFile_op__initCover(fd, path)};
  return _rt571;
}

struct os_InputStream_VTable os_InputStream_vTable = (struct os_InputStream_VTable){
  .read = (os_InputStream_read_t) {},
  .seek = (os_InputStream_seek_t) {}
};

static void os_InputStream___defaults_init(struct os_InputStream * this) {
  this->vtable = &os_InputStream_vTable;
}


static struct os_Union1761 builtins___union_copyI_U_ZosFileInputStream_ZException__E(struct os_Union1761 * obj) {
  struct os_Union1761 _rt572 = {};
  switch (obj->tag) {
  case 0u: {
    {
      struct os_FileInputStream * y = obj->_0;
      _rt572 = (struct os_Union1761){.tag = 0, ._0 = __smart_ptr_get(y)};
      return _rt572;
    }
  }
  case 1u: {
    {
      struct Exception * y = obj->_1;
      _rt572 = (struct os_Union1761){.tag = 1, ._1 = __smart_ptr_get(y)};
      return _rt572;
    }
  }
  default: { unreachable("unhandled-default-case"); }
  }
  
}


static void builtins___union_dctorI_U_ZosFileInputStream_ZException__E(struct os_Union1761 * obj) {
  switch (obj->tag) {
  case 0u: {
    {
      struct os_FileInputStream * y = obj->_0;
    }
    break;
  }
  case 1u: {
    {
      struct Exception * y = obj->_1;
      __smart_ptr_drop(y);
    }
    break;
  }
  default: { unreachable("unhandled-default-case"); }
  }
  
}


static struct os_Union1773 builtins___union_copyI_U_ZString_ZException__E(struct os_Union1773 * obj) {
  struct os_Union1773 _rt573 = {};
  switch (obj->tag) {
  case 0u: {
    {
      struct String * y = obj->_0;
      _rt573 = (struct os_Union1773){.tag = 0, ._0 = __smart_ptr_get(y)};
      return _rt573;
    }
  }
  case 1u: {
    {
      struct Exception * y = obj->_1;
      _rt573 = (struct os_Union1773){.tag = 1, ._1 = __smart_ptr_get(y)};
      return _rt573;
    }
  }
  default: { unreachable("unhandled-default-case"); }
  }
  
}


static void builtins___union_dctorI_U_ZString_ZException__E(struct os_Union1773 * obj) {
  switch (obj->tag) {
  case 0u: {
    {
      struct String * y = obj->_0;
      __smart_ptr_drop(y);
    }
    break;
  }
  case 1u: {
    {
      struct Exception * y = obj->_1;
      __smart_ptr_drop(y);
    }
    break;
  }
  default: { unreachable("unhandled-default-case"); }
  }
  
}

__attribute__((always_inline))
static struct os_FileInputStream * os_FileInputStream_op__initCover(int32_t fd, bool closeOnDestruct, bool nonBlocking) {
  struct os_FileInputStream * _rt574 = {};
  struct os_FileInputStream * __obj383 = (struct os_FileInputStream *)__smart_ptr_alloc(sizeof(os_FileInputStream), os_FileInputStream_op__destructor_fwd);
  memset(__obj383, 0, sizeof(os_FileInputStream));
  os_FileInputStream___defaults_init(__obj383);
  os_FileInputStream_op__init(__obj383, fd, closeOnDestruct, nonBlocking);
  _rt574 = __obj383;
  return _rt574;
}


static struct OutputStream * builtins_OutputStream_op__lshiftI_i64E(struct OutputStream * this, const int64_t val) {
  struct OutputStream * _rt575 = {};
  builtins_OutputStream_appendSignedInt(this, val);
  _rt575 = this;
  return _rt575;
}

struct os_InputStream_VTable os_FileInputStream_vTable = (struct os_InputStream_VTable){
  .read = (os_InputStream_read_t)os_FileInputStream_read,
  .seek = (os_InputStream_seek_t)os_FileInputStream_seek
};

static void os_FileInputStream_op__init(struct os_FileInputStream * this, int32_t fd, bool closeOnDestruct, bool nonBlocking) {
  this->fd = fd;
  this->closeOnDestruct = closeOnDestruct;
  if (nonBlocking) {
    os_setNonblocking(fd, false);
  }
}


static void os_FileInputStream_op__deinit(struct os_FileInputStream * this) {
  if (this->closeOnDestruct && this->fd != -1) {
    close(this->fd);
  }
  this->fd = -1;
}


static struct os_Union1761 os_FileInputStream_open(const char* path, bool nonBlocking, int32_t mode) {
  struct os_Union1761 _rt576 = {};
  int32_t fd = open((const char *)path, 0, mode);
  if (fd < 0) {
    struct String * sb321 = builtins_String_op__initI_ECover();
    const char* _rv382 = builtins_strerr();
    struct OutputStream * _m450 = (struct OutputStream *)sb321;
    struct OutputStream * _m451 = builtins_OutputStream_op__lshiftI_sE(_m450, "opening file '");
    struct OutputStream * _m452 = builtins_OutputStream_op__lshiftI_sE(_m451, path);
    struct OutputStream * _m453 = builtins_OutputStream_op__lshiftI_sE(_m452, "' failed: ");
    builtins_OutputStream_op__lshiftI_sE(_m453, _rv382);
    struct Exception * _ex322 = (struct Exception *)os_IOError_op__initCover(__smart_ptr_get(sb321));
    builtins_Exception_push(_ex322, "os", "FileInputStream", "open", "/home/dev/.cxy/lib/cxy/std/stdlib/os.cxy", (uint64_t)279);
    _rt576 = (struct os_Union1761){.tag = 1, ._1 = _ex322};
    __smart_ptr_drop(sb321);
    return _rt576;
  }
  _rt576 = (struct os_Union1761){.tag = 0, ._0 = os_FileInputStream_op__initCover(fd, true, nonBlocking)};
  return _rt576;
}


static struct OptionalI_u64E os_FileInputStream_read(struct os_FileInputStream * this, void * buf, uint64_t size) {
  struct OptionalI_u64E _rt577 = {};
  if (this->fd == -1) {
    _rt577 = builtins_NoneI_u64E();
    return _rt577;
  }
  int64_t bytes = read(this->fd, buf, size);
  if (bytes == -1) {
    _rt577 = builtins_NoneI_u64E();
    return _rt577;
  }
  _rt577 = builtins_SomeI_u64E((uint64_t)bytes);
  return _rt577;
}


static struct OptionalI_u64E os_FileInputStream_seek(struct os_FileInputStream * this, uint64_t off, os_Seek whence) {
  struct OptionalI_u64E _rt578 = {};
  int64_t pos = lseek(this->fd, (int64_t)off, (int32_t)whence);
  if (pos < 0) {
    _rt578 = builtins_NoneI_u64E();
    return _rt578;
  }
  _rt578 = builtins_SomeI_u64E((uint64_t)pos);
  return _rt578;
}


static struct Union416 os_FileInputStream_readAsyncI_RZOutputStream_u64E(struct os_FileInputStream * this, struct OutputStream * os, uint64_t timeout) {
  struct Union416 _rt579 = {};
  Array1788 buf = {};
  while (true) {
    {
      struct OptionalI_u64E tmp = os_FileInputStream_read(this, (void *)buf, (uint64_t)4092);
      if (!builtins_OptionalI_u64E_op__truthyI_E(&tmp)) {
        if ((__errno_location()[0]) == 11) {
          int32_t ret = coro___fdWaitRead(this->fd, timeout);
          if (ret != State_AE_READABLE) {
            struct String * sb323 = builtins_String_op__initI_ECover();
            const char* _rv384 = builtins_strerr();
            struct OutputStream * _m454 = (struct OutputStream *)sb323;
            struct OutputStream * _m455 = builtins_OutputStream_op__lshiftI_sE(_m454, "Waiting for file ");
            struct OutputStream * _m456 = builtins_OutputStream_op__lshiftI_i32E(_m455, this->fd);
            struct OutputStream * _m457 = builtins_OutputStream_op__lshiftI_sE(_m456, " to be readable failed: ");
            builtins_OutputStream_op__lshiftI_sE(_m457, _rv384);
            struct Exception * _ex324 = (struct Exception *)os_IOError_op__initCover(__smart_ptr_get(sb323));
            builtins_Exception_push(_ex324, "os", "FileInputStream", "readAsync", "/home/dev/.cxy/lib/cxy/std/stdlib/os.cxy", (uint64_t)309);
            _rt579 = (struct Union416){.tag = 1, ._1 = _ex324};
            __smart_ptr_drop(sb323);
            builtins_OptionalI_u64E_op__destructor(&(tmp));
            return _rt579;
          }
          builtins_OptionalI_u64E_op__destructor(&(tmp));
          continue;
        }
        struct String * sb325 = builtins_String_op__initI_ECover();
        const char* _rv385 = builtins_strerr();
        struct OutputStream * _m458 = (struct OutputStream *)sb325;
        struct OutputStream * _m459 = builtins_OutputStream_op__lshiftI_sE(_m458, "reading from file ");
        struct OutputStream * _m460 = builtins_OutputStream_op__lshiftI_i32E(_m459, this->fd);
        struct OutputStream * _m461 = builtins_OutputStream_op__lshiftI_sE(_m460, " failed: ");
        builtins_OutputStream_op__lshiftI_sE(_m461, _rv385);
        struct Exception * _ex326 = (struct Exception *)os_IOError_op__initCover(__smart_ptr_get(sb325));
        builtins_Exception_push(_ex326, "os", "FileInputStream", "readAsync", "/home/dev/.cxy/lib/cxy/std/stdlib/os.cxy", (uint64_t)312);
        _rt579 = (struct Union416){.tag = 1, ._1 = _ex326};
        __smart_ptr_drop(sb325);
        builtins_OptionalI_u64E_op__destructor(&(tmp));
        return _rt579;
      }
      if (builtins_OptionalI_u64E_op__derefI_E(&tmp) == 0) {
        _rt579 = (struct Union416){.tag = 0, ._0 = (struct Void){}};
        builtins_OptionalI_u64E_op__destructor(&(tmp));
        return _rt579;
      }
      uint64_t _a462 = builtins_OptionalI_u64E_op__derefI_E(&tmp);
      os->vtable->append(os, (const void *)buf, _a462);
      builtins_OptionalI_u64E_op__destructor(&(tmp));
    }
    
  }
  _rt579 = (struct Union416){.tag = 0, ._0 = (struct Void){}};
  return _rt579;
}

__attribute__((always_inline))
static struct os_Union1682 os_FileInputStream_readAsyncI_PZ_u64u64E(struct os_FileInputStream * this, void * buf, uint64_t size, uint64_t timeout) {
  struct os_Union1682 _rt580 = {};
  struct MemoryOutputStream * mos = ({
    struct MemoryOutputStream * obj = __builtin_alloca(sizeof(MemoryOutputStream));
    builtins_MemoryOutputStream___defaults_init(obj);;
    builtins_MemoryOutputStream_op__init(obj, buf, size);
    obj;
  });
  struct os_Union1682 _res386 = os_FileInputStream_readAsyncI_PZ_u64u64E(this, (void *)mos, timeout, (uint64_t)0);
  bool ___res386_dflags = true;
  if (_res386.tag == 1u) {
    struct Exception * ex = _res386._1;
    ___res386_dflags = false;
    builtins_Exception_push(ex, "os", "FileInputStream", "readAsync", "/home/dev/.cxy/lib/cxy/std/stdlib/os.cxy", 324u);
    _rt580 = (struct os_Union1682){.tag = 1, ._1 = ex};
    return _rt580;
  }
  _rt580 = (struct os_Union1682){.tag = 0, ._0 = builtins_MemoryOutputStream_size(mos)};
  __CXY_DROP_WITH_FLAGS(___res386_dflags, builtins___union_dctorI_U_u64ZException__E(&(_res386)));
  ___res386_dflags = false;
  return _rt580;
}

__attribute__((always_inline))
static struct os_Union1773 os_FileInputStream_readAsyncI_u64E(struct os_FileInputStream * this, uint64_t timeout) {
  struct os_Union1773 _rt581 = {};
  struct String * str = builtins_String_op__initI_ECover();
  struct os_Union1682 _res387 = os_FileInputStream_readAsyncI_PZ_u64u64E(this, (void *)str, timeout, (uint64_t)0);
  bool ___res387_dflags = true;
  if (_res387.tag == 1u) {
    struct Exception * ex = _res387._1;
    ___res387_dflags = false;
    builtins_Exception_push(ex, "os", "FileInputStream", "readAsync", "/home/dev/.cxy/lib/cxy/std/stdlib/os.cxy", 331u);
    _rt581 = (struct os_Union1773){.tag = 1, ._1 = ex};
    __smart_ptr_drop(str);
    return _rt581;
  }
  _rt581 = (struct os_Union1773){.tag = 0, ._0 = str};
  __CXY_DROP_WITH_FLAGS(___res387_dflags, builtins___union_dctorI_U_u64ZException__E(&(_res387)));
  ___res387_dflags = false;
  return _rt581;
}

__attribute__((always_inline))
static struct os_Union1773 os_FileInputStream_readAllI_E(struct os_FileInputStream * this) {
  struct os_Union1773 _rt582 = {};
  struct stat st = (struct stat){};
  if (fs_fstat(this->fd, &st) != 0) {
    struct String * sb327 = builtins_String_op__initI_ECover();
    const char* _rv388 = builtins_strerr();
    struct OutputStream * _m463 = (struct OutputStream *)sb327;
    struct OutputStream * _m464 = builtins_OutputStream_op__lshiftI_sE(_m463, "fstat(");
    struct OutputStream * _m465 = builtins_OutputStream_op__lshiftI_i32E(_m464, this->fd);
    struct OutputStream * _m466 = builtins_OutputStream_op__lshiftI_sE(_m465, ") failed: ");
    builtins_OutputStream_op__lshiftI_sE(_m466, _rv388);
    struct Exception * _ex328 = (struct Exception *)os_IOError_op__initCover(__smart_ptr_get(sb327));
    builtins_Exception_push(_ex328, "os", "FileInputStream", "readAll", "/home/dev/.cxy/lib/cxy/std/stdlib/os.cxy", (uint64_t)339);
    _rt582 = (struct os_Union1773){.tag = 1, ._1 = _ex328};
    __smart_ptr_drop(sb327);
    return _rt582;
  }
  if (st.st_size > 1048576) {
    struct String * sb329 = builtins_String_op__initI_ECover();
    struct OutputStream * _m467 = (struct OutputStream *)sb329;
    struct OutputStream * _m468 = builtins_OutputStream_op__lshiftI_sE(_m467, "file size(=");
    struct OutputStream * _m469 = builtins_OutputStream_op__lshiftI_i64E(_m468, st.st_size);
    builtins_OutputStream_op__lshiftI_sE(_m469, ") to large (limit: 1mb) to read with this api");
    struct Exception * _ex330 = (struct Exception *)os_IOError_op__initCover(__smart_ptr_get(sb329));
    builtins_Exception_push(_ex330, "os", "FileInputStream", "readAll", "/home/dev/.cxy/lib/cxy/std/stdlib/os.cxy", (uint64_t)342);
    _rt582 = (struct os_Union1773){.tag = 1, ._1 = _ex330};
    __smart_ptr_drop(sb329);
    return _rt582;
  }
  struct String * s = builtins_String_op__initI_ECover();
  bool __s_dflags = true;
  if (!(((st.st_mode) & 61440) == (32768))) {
    struct Union416 _res389 = os_FileInputStream_readAllI_RZOutputStream_E(this, (struct OutputStream *)s);
    bool ___res389_dflags = true;
    if (_res389.tag == 1u) {
      struct Exception * ex = _res389._1;
      ___res389_dflags = false;
      builtins_Exception_push(ex, "os", "FileInputStream", "readAll", "/home/dev/.cxy/lib/cxy/std/stdlib/os.cxy", 347u);
      _rt582 = (struct os_Union1773){.tag = 1, ._1 = ex};
      __CXY_DROP_WITH_FLAGS(__s_dflags, __smart_ptr_drop(s));
      __s_dflags = false;
      return _rt582;
    }
    _rt582 = (struct os_Union1773){.tag = 0, ._0 = s};
    __s_dflags = false;
    __CXY_DROP_WITH_FLAGS(___res389_dflags, builtins___union_dctorI_U_ZVoid_ZException__E(&(_res389)));
    ___res389_dflags = false;
    return _rt582;
  }
  if (st.st_size == 0) {
    _rt582 = (struct os_Union1773){.tag = 0, ._0 = s};
    __s_dflags = false;
    return _rt582;
  }
  char * buf = builtins_String_reserve(s, (uint64_t)st.st_size);
  uint64_t nRead = 0u;
  while (nRead < st.st_size) {
    {
      char * p = buf + nRead;
      int64_t _a470 = st.st_size - nRead;
      struct OptionalI_u64E tmp = os_FileInputStream_read(this, (void *)p, (uint64_t)_a470);
      if (!builtins_OptionalI_u64E_op__truthyI_E(&tmp)) {
        struct String * sb331 = builtins_String_op__initI_ECover();
        const char* _rv390 = builtins_strerr();
        struct OutputStream * _m471 = (struct OutputStream *)sb331;
        struct OutputStream * _m472 = builtins_OutputStream_op__lshiftI_sE(_m471, "error reading file ");
        struct OutputStream * _m473 = builtins_OutputStream_op__lshiftI_i32E(_m472, this->fd);
        struct OutputStream * _m474 = builtins_OutputStream_op__lshiftI_sE(_m473, ": ");
        builtins_OutputStream_op__lshiftI_sE(_m474, _rv390);
        struct Exception * _ex332 = (struct Exception *)os_IOError_op__initCover(__smart_ptr_get(sb331));
        builtins_Exception_push(_ex332, "os", "FileInputStream", "readAll", "/home/dev/.cxy/lib/cxy/std/stdlib/os.cxy", (uint64_t)360);
        _rt582 = (struct os_Union1773){.tag = 1, ._1 = _ex332};
        __smart_ptr_drop(sb331);
        builtins_OptionalI_u64E_op__destructor(&(tmp));
        __CXY_DROP_WITH_FLAGS(__s_dflags, __smart_ptr_drop(s));
        __s_dflags = false;
        return _rt582;
      }
      nRead += builtins_OptionalI_u64E_op__derefI_E(&tmp);
      builtins_OptionalI_u64E_op__destructor(&(tmp));
    }
    
  }
  builtins_String_resize(s, nRead);
  _rt582 = (struct os_Union1773){.tag = 0, ._0 = s};
  __s_dflags = false;
  return _rt582;
}


static struct Union416 os_FileInputStream_readAllI_RZOutputStream_E(struct os_FileInputStream * this, struct OutputStream * os) {
  struct Union416 _rt583 = {};
  Array1788 buf = {};
  while (true) {
    {
      struct OptionalI_u64E tmp = os_FileInputStream_read(this, (void *)buf, (uint64_t)4092);
      if (builtins_OptionalI_u64E_op__derefI_E(&tmp) < 0) {
        struct String * sb333 = builtins_String_op__initI_ECover();
        const char* _rv391 = builtins_strerr();
        struct OutputStream * _m475 = (struct OutputStream *)sb333;
        struct OutputStream * _m476 = builtins_OutputStream_op__lshiftI_sE(_m475, "reading command output failed: ");
        builtins_OutputStream_op__lshiftI_sE(_m476, _rv391);
        struct Exception * _ex334 = (struct Exception *)os_IOError_op__initCover(__smart_ptr_get(sb333));
        builtins_Exception_push(_ex334, "os", "FileInputStream", "readAll", "/home/dev/.cxy/lib/cxy/std/stdlib/os.cxy", (uint64_t)372);
        _rt583 = (struct Union416){.tag = 1, ._1 = _ex334};
        __smart_ptr_drop(sb333);
        builtins_OptionalI_u64E_op__destructor(&(tmp));
        return _rt583;
      }
      if (builtins_OptionalI_u64E_op__derefI_E(&tmp) == 0) {
        _rt583 = (struct Union416){.tag = 0, ._0 = (struct Void){}};
        builtins_OptionalI_u64E_op__destructor(&(tmp));
        return _rt583;
      }
      uint64_t _a477 = builtins_OptionalI_u64E_op__derefI_E(&tmp);
      os->vtable->append(os, (const void *)buf, _a477);
      builtins_OptionalI_u64E_op__destructor(&(tmp));
    }
    
  }
  _rt583 = (struct Union416){.tag = 0, ._0 = (struct Void){}};
  return _rt583;
}


static void os_FileInputStream_op__destructor(struct os_FileInputStream * this) {
  os_FileInputStream_op__deinit(this);
}


static void os_FileInputStream_op__destructor_fwd(void * ptr) {
  os_FileInputStream_op__destructor((struct os_FileInputStream *)ptr);
}


static void os_FileInputStream___defaults_init(struct os_FileInputStream * this) {
  this->vtable = &os_FileInputStream_vTable;
}


static struct os_Union1794 builtins___union_copyI_U_ZosFileOutputStream_ZException__E(struct os_Union1794 * obj) {
  struct os_Union1794 _rt584 = {};
  switch (obj->tag) {
  case 0u: {
    {
      struct os_FileOutputStream * y = obj->_0;
      _rt584 = (struct os_Union1794){.tag = 0, ._0 = __smart_ptr_get(y)};
      return _rt584;
    }
  }
  case 1u: {
    {
      struct Exception * y = obj->_1;
      _rt584 = (struct os_Union1794){.tag = 1, ._1 = __smart_ptr_get(y)};
      return _rt584;
    }
  }
  default: { unreachable("unhandled-default-case"); }
  }
  
}


static void builtins___union_dctorI_U_ZosFileOutputStream_ZException__E(struct os_Union1794 * obj) {
  switch (obj->tag) {
  case 0u: {
    {
      struct os_FileOutputStream * y = obj->_0;
    }
    break;
  }
  case 1u: {
    {
      struct Exception * y = obj->_1;
      __smart_ptr_drop(y);
    }
    break;
  }
  default: { unreachable("unhandled-default-case"); }
  }
  
}

__attribute__((always_inline))
static struct os_FileOutputStream * os_FileOutputStream_op__initCover(int32_t fd, bool closeOnDestruct, bool nonBlocking) {
  struct os_FileOutputStream * _rt585 = {};
  struct os_FileOutputStream * __obj393 = (struct os_FileOutputStream *)__smart_ptr_alloc(sizeof(os_FileOutputStream), os_FileOutputStream_op__destructor_fwd);
  memset(__obj393, 0, sizeof(os_FileOutputStream));
  os_FileOutputStream___defaults_init(__obj393);
  os_FileOutputStream_op__init(__obj393, fd, closeOnDestruct, nonBlocking);
  _rt585 = __obj393;
  return _rt585;
}

struct OutputStream_VTable os_FileOutputStream_vTable = (struct OutputStream_VTable){
  .append = (builtins_OutputStream_append_t)os_FileOutputStream_append
};

static void os_FileOutputStream_op__init(struct os_FileOutputStream * this, int32_t fd, bool closeOnDestruct, bool nonBlocking) {
  this->fd = fd;
  this->closeOnDestruct = closeOnDestruct;
  if (nonBlocking) {
    os_setNonblocking(fd, false);
  }
}


static void os_FileOutputStream_op__deinit(struct os_FileOutputStream * this) {
  if (this->closeOnDestruct && this->fd != -1) {
    close(this->fd);
  }
  this->fd = -1;
}


static struct os_Union1794 os_FileOutputStream_open(const char* path, bool nonBlocking, int32_t flags, int32_t mode) {
  struct os_Union1794 _rt586 = {};
  int32_t fd = open((const char *)path, flags, mode);
  if (fd < 0) {
    struct String * sb335 = builtins_String_op__initI_ECover();
    const char* _rv392 = builtins_strerr();
    struct OutputStream * _m478 = (struct OutputStream *)sb335;
    struct OutputStream * _m479 = builtins_OutputStream_op__lshiftI_sE(_m478, "opening file '");
    struct OutputStream * _m480 = builtins_OutputStream_op__lshiftI_sE(_m479, path);
    struct OutputStream * _m481 = builtins_OutputStream_op__lshiftI_sE(_m480, "' failed: ");
    builtins_OutputStream_op__lshiftI_sE(_m481, _rv392);
    struct Exception * _ex336 = (struct Exception *)os_IOError_op__initCover(__smart_ptr_get(sb335));
    builtins_Exception_push(_ex336, "os", "FileOutputStream", "open", "/home/dev/.cxy/lib/cxy/std/stdlib/os.cxy", (uint64_t)407);
    _rt586 = (struct os_Union1794){.tag = 1, ._1 = _ex336};
    __smart_ptr_drop(sb335);
    return _rt586;
  }
  _rt586 = (struct os_Union1794){.tag = 0, ._0 = os_FileOutputStream_op__initCover(fd, true, nonBlocking)};
  return _rt586;
}


static struct OptionalI_u64E os_FileOutputStream_append(struct os_FileOutputStream * this, const void * data, uint64_t size) {
  struct OptionalI_u64E _rt587 = {};
  if (this->fd == -1) {
    _rt587 = builtins_NoneI_u64E();
    return _rt587;
  }
  int64_t bytes = write(this->fd, data, size);
  if (bytes == -1) {
    _rt587 = builtins_NoneI_u64E();
    return _rt587;
  }
  _rt587 = builtins_SomeI_u64E((uint64_t)bytes);
  return _rt587;
}

__attribute__((always_inline))
static struct OptionalI_u64E os_FileOutputStream_write(struct os_FileOutputStream * this, const void * buf, uint64_t size) {
  struct OptionalI_u64E _rt588 = {};
  _rt588 = os_FileOutputStream_append(this, buf, size);
  return _rt588;
}


static struct os_Union1682 os_FileOutputStream_writeAsync(struct os_FileOutputStream * this, const void * buf, uint64_t size, uint64_t timeout) {
  struct os_Union1682 _rt589 = {};
  uint64_t numWritten = 0u;
  while (numWritten < size) {
    {
      char * p = ((char *)buf) + numWritten;
      uint64_t _a482 = size - numWritten;
      struct OptionalI_u64E tmp = os_FileOutputStream_append(this, (const void *)p, _a482);
      if (!builtins_OptionalI_u64E_op__truthyI_E(&tmp)) {
        if ((__errno_location()[0]) == 11) {
          int32_t ret = coro___fdWaitRead(this->fd, timeout);
          if (ret != State_AE_WRITABLE) {
            struct String * sb337 = builtins_String_op__initI_ECover();
            const char* _rv394 = builtins_strerr();
            struct OutputStream * _m483 = (struct OutputStream *)sb337;
            struct OutputStream * _m484 = builtins_OutputStream_op__lshiftI_sE(_m483, "Waiting for file ");
            struct OutputStream * _m485 = builtins_OutputStream_op__lshiftI_i32E(_m484, this->fd);
            struct OutputStream * _m486 = builtins_OutputStream_op__lshiftI_sE(_m485, " to be writable failed: ");
            builtins_OutputStream_op__lshiftI_sE(_m486, _rv394);
            struct Exception * _ex338 = (struct Exception *)os_IOError_op__initCover(__smart_ptr_get(sb337));
            builtins_Exception_push(_ex338, "os", "FileOutputStream", "writeAsync", "/home/dev/.cxy/lib/cxy/std/stdlib/os.cxy", (uint64_t)435);
            _rt589 = (struct os_Union1682){.tag = 1, ._1 = _ex338};
            __smart_ptr_drop(sb337);
            builtins_OptionalI_u64E_op__destructor(&(tmp));
            return _rt589;
          }
          builtins_OptionalI_u64E_op__destructor(&(tmp));
          continue;
        }
        struct String * sb339 = builtins_String_op__initI_ECover();
        const char* _rv395 = builtins_strerr();
        struct OutputStream * _m487 = (struct OutputStream *)sb339;
        struct OutputStream * _m488 = builtins_OutputStream_op__lshiftI_sE(_m487, "writing to file ");
        struct OutputStream * _m489 = builtins_OutputStream_op__lshiftI_i32E(_m488, this->fd);
        struct OutputStream * _m490 = builtins_OutputStream_op__lshiftI_sE(_m489, " failed: ");
        builtins_OutputStream_op__lshiftI_sE(_m490, _rv395);
        struct Exception * _ex340 = (struct Exception *)os_IOError_op__initCover(__smart_ptr_get(sb339));
        builtins_Exception_push(_ex340, "os", "FileOutputStream", "writeAsync", "/home/dev/.cxy/lib/cxy/std/stdlib/os.cxy", (uint64_t)438);
        _rt589 = (struct os_Union1682){.tag = 1, ._1 = _ex340};
        __smart_ptr_drop(sb339);
        builtins_OptionalI_u64E_op__destructor(&(tmp));
        return _rt589;
      }
      numWritten += builtins_OptionalI_u64E_op__derefI_E(&tmp);
      builtins_OptionalI_u64E_op__destructor(&(tmp));
    }
    
  }
  _rt589 = (struct os_Union1682){.tag = 0, ._0 = numWritten};
  return _rt589;
}


static struct OptionalI_u64E os_FileOutputStream_seek(struct os_FileOutputStream * this, uint64_t off, os_Seek whence) {
  struct OptionalI_u64E _rt590 = {};
  int64_t pos = lseek(this->fd, (int64_t)off, (int32_t)whence);
  if (pos < 0) {
    _rt590 = builtins_NoneI_u64E();
    return _rt590;
  }
  _rt590 = builtins_SomeI_u64E((uint64_t)pos);
  return _rt590;
}


static void os_FileOutputStream_op__destructor(struct os_FileOutputStream * this) {
  os_FileOutputStream_op__deinit(this);
}


static void os_FileOutputStream_op__destructor_fwd(void * ptr) {
  os_FileOutputStream_op__destructor((struct os_FileOutputStream *)ptr);
}


static void os_FileOutputStream___defaults_init(struct os_FileOutputStream * this) {
  this->vtable = &os_FileOutputStream_vTable;
}


static struct os_Union1819 builtins___union_copyI_U_i32ZException__E(struct os_Union1819 * obj) {
  struct os_Union1819 _rt591 = {};
  switch (obj->tag) {
  case 0u: {
    {
      int32_t y = obj->_0;
      _rt591 = (struct os_Union1819){.tag = 0, ._0 = y};
      return _rt591;
    }
  }
  case 1u: {
    {
      struct Exception * y = obj->_1;
      _rt591 = (struct os_Union1819){.tag = 1, ._1 = __smart_ptr_get(y)};
      return _rt591;
    }
  }
  default: { unreachable("unhandled-default-case"); }
  }
  
}


static void builtins___union_dctorI_U_i32ZException__E(struct os_Union1819 * obj) {
  switch (obj->tag) {
  case 0u: {
    {
      int32_t y = obj->_0;
    }
    break;
  }
  case 1u: {
    {
      struct Exception * y = obj->_1;
      __smart_ptr_drop(y);
    }
    break;
  }
  default: { unreachable("unhandled-default-case"); }
  }
  
}


static void os_Process_op__init(struct os_Process * this, int32_t pid, int32_t input, int32_t out, int32_t err) {
  this->_pid = pid;
  this->_fdin = input;
  this->_fdout = out;
  this->_fderr = err;
}

__attribute__((always_inline))
static struct os_FileInputStream * os_Process_stdout(struct os_Process * this) {
  struct os_FileInputStream * _rt592 = {};
  if (this->_stdout == nullptr) {
    __smart_ptr_drop(this->_stdout);
    this->_stdout = os_FileInputStream_op__initCover(this->_fdout, true, true);
    this->_fdout = -1;
  }
  _rt592 = this->_stdout;
  return _rt592;
}

__attribute__((always_inline))
static struct os_FileInputStream * os_Process_stderr(struct os_Process * this) {
  struct os_FileInputStream * _rt593 = {};
  if (this->_stderr == nullptr) {
    __smart_ptr_drop(this->_stderr);
    this->_stderr = os_FileInputStream_op__initCover(this->_fderr, true, true);
    this->_fderr = -1;
  }
  _rt593 = this->_stderr;
  return _rt593;
}

__attribute__((always_inline))
static int32_t os_Process_stdin(struct os_Process * this) {
  int32_t _rt594 = {};
  if (this->_stdin == nullptr) {
    __smart_ptr_drop(this->_stdin);
    this->_stdin = os_FileOutputStream_op__initCover(this->_fdin, true, true);
    this->_fdin = -1;
  }
  _rt594 = this->_fdin;
  return _rt594;
}


static void os_Process_op__deinit(struct os_Process * this) {
  if (this->_fdin > 0) {
    close(this->_fdin);
    this->_fdin = -1;
  }
  if (this->_fdout > 0) {
    close(this->_fdout);
    this->_fdout = -1;
  }
  if (this->_fderr > 0) {
    close(this->_fderr);
    this->_fderr = -1;
  }
}


static bool os_Process_isExited(const struct os_Process * this) {
  bool _rt595 = {};
  int32_t status = 0;
  int32_t ret = waitpid(this->_pid, &status, 1);
  if (ret < 0) {
    return true;
  }
  _rt595 = ret == this->_pid && ((((&status))[0] & 177) == 0);
  return _rt595;
}


static struct os_Union1819 os_Process_wait(struct os_Process * this) {
  struct os_Union1819 _rt596 = {};
  int32_t status = 0;
  int32_t ret = waitpid(this->_pid, &status, (int32_t)0);
  if (ret < 0) {
    struct String * sb341 = builtins_String_op__initI_ECover();
    const char* _rv396 = builtins_strerr();
    struct OutputStream * _m491 = (struct OutputStream *)sb341;
    struct OutputStream * _m492 = builtins_OutputStream_op__lshiftI_sE(_m491, "wait for pid ");
    struct OutputStream * _m493 = builtins_OutputStream_op__lshiftI_i32E(_m492, this->_pid);
    struct OutputStream * _m494 = builtins_OutputStream_op__lshiftI_sE(_m493, " failed: ");
    builtins_OutputStream_op__lshiftI_sE(_m494, _rv396);
    struct Exception * _ex342 = (struct Exception *)os_IOError_op__initCover(__smart_ptr_get(sb341));
    builtins_Exception_push(_ex342, "os", "Process", "wait", "/home/dev/.cxy/lib/cxy/std/stdlib/os.cxy", (uint64_t)524);
    _rt596 = (struct os_Union1819){.tag = 1, ._1 = _ex342};
    __smart_ptr_drop(sb341);
    return _rt596;
  }
  if (((((&status))[0] & 177) == 0)) {
    _rt596 = (struct os_Union1819){.tag = 0, ._0 = ((((&status))[0] >> 8) & 255)};
    return _rt596;
  }
  _rt596 = (struct os_Union1819){.tag = 0, ._0 = -1};
  return _rt596;
}


static struct os_Union1819 os_Process_waitAsync(struct os_Process * this) {
  struct os_Union1819 _rt597 = {};
  {
    int32_t pidFd = pidfd_open(this->_pid, (uint32_t)2048);
    if (pidFd < 1) {
      if ((__errno_location()[0]) == 22) {
        _rt597 = (struct os_Union1819){.tag = 0, ._0 = -(22)};
        return _rt597;
      }
      struct String * sb343 = builtins_String_op__initI_ECover();
      const char* _rv397 = builtins_strerr();
      struct OutputStream * _m495 = (struct OutputStream *)sb343;
      struct OutputStream * _m496 = builtins_OutputStream_op__lshiftI_sE(_m495, "wait for pid ");
      struct OutputStream * _m497 = builtins_OutputStream_op__lshiftI_i32E(_m496, this->_pid);
      struct OutputStream * _m498 = builtins_OutputStream_op__lshiftI_sE(_m497, " failed: ");
      builtins_OutputStream_op__lshiftI_sE(_m498, _rv397);
      struct Exception * _ex344 = (struct Exception *)os_IOError_op__initCover(__smart_ptr_get(sb343));
      builtins_Exception_push(_ex344, "os", "Process", "waitAsync", "/home/dev/.cxy/lib/cxy/std/stdlib/os.cxy", (uint64_t)542);
      _rt597 = (struct os_Union1819){.tag = 1, ._1 = _ex344};
      __smart_ptr_drop(sb343);
      return _rt597;
    }
    int32_t status = 0;
    int32_t ret = waitpid(this->_pid, &status, 1);
    if (ret < 0) {
      struct String * sb345 = builtins_String_op__initI_ECover();
      const char* _rv398 = builtins_strerr();
      struct OutputStream * _m499 = (struct OutputStream *)sb345;
      struct OutputStream * _m500 = builtins_OutputStream_op__lshiftI_sE(_m499, "wait for pid ");
      struct OutputStream * _m501 = builtins_OutputStream_op__lshiftI_i32E(_m500, this->_pid);
      struct OutputStream * _m502 = builtins_OutputStream_op__lshiftI_sE(_m501, " failed: ");
      builtins_OutputStream_op__lshiftI_sE(_m502, _rv398);
      struct Exception * _ex346 = (struct Exception *)os_IOError_op__initCover(__smart_ptr_get(sb345));
      builtins_Exception_push(_ex346, "os", "Process", "waitAsync", "/home/dev/.cxy/lib/cxy/std/stdlib/os.cxy", (uint64_t)549);
      close(pidFd);
      _rt597 = (struct os_Union1819){.tag = 1, ._1 = _ex346};
      __smart_ptr_drop(sb345);
      return _rt597;
    }
    if (ret == 0) {
      coro___fdWaitRead(pidFd, (uint64_t)0);
      ret = waitpid(this->_pid, &status, 1);
      if (ret < 0) {
        struct String * sb347 = builtins_String_op__initI_ECover();
        const char* _rv399 = builtins_strerr();
        struct OutputStream * _m503 = (struct OutputStream *)sb347;
        struct OutputStream * _m504 = builtins_OutputStream_op__lshiftI_sE(_m503, "wait for pid ");
        struct OutputStream * _m505 = builtins_OutputStream_op__lshiftI_i32E(_m504, this->_pid);
        struct OutputStream * _m506 = builtins_OutputStream_op__lshiftI_sE(_m505, " failed: ");
        builtins_OutputStream_op__lshiftI_sE(_m506, _rv399);
        struct Exception * _ex348 = (struct Exception *)os_IOError_op__initCover(__smart_ptr_get(sb347));
        builtins_Exception_push(_ex348, "os", "Process", "waitAsync", "/home/dev/.cxy/lib/cxy/std/stdlib/os.cxy", (uint64_t)554);
        close(pidFd);
        _rt597 = (struct os_Union1819){.tag = 1, ._1 = _ex348};
        __smart_ptr_drop(sb347);
        return _rt597;
      }
    }
    if (((((&status))[0] & 177) == 0)) {
      close(pidFd);
      _rt597 = (struct os_Union1819){.tag = 0, ._0 = ((((&status))[0] >> 8) & 255)};
      return _rt597;
    }
    close(pidFd);
    _rt597 = (struct os_Union1819){.tag = 0, ._0 = -1};
    return _rt597;
  }
}

__attribute__((always_inline))
static struct os_Process os_Process_op__copy(struct os_Process * this) {
  struct os_Process _rt598 = {};
  _rt598 = (struct os_Process){
    ._stdout = (struct os_FileInputStream *)__smart_ptr_get(this->_stdout),
    ._stderr = (struct os_FileInputStream *)__smart_ptr_get(this->_stderr),
    ._stdin = (struct os_FileOutputStream *)__smart_ptr_get(this->_stdin),
    ._fdin = this->_fdin,
    ._fdout = this->_fdout,
    ._fderr = this->_fderr,
    ._pid = this->_pid
  };
  return _rt598;
}


static void os_Process_op__destructor(struct os_Process * this) {
  os_Process_op__deinit(this);
  __smart_ptr_drop(this->_stdout);
  *(&this->_stdout) = nullptr;
  __smart_ptr_drop(this->_stderr);
  *(&this->_stderr) = nullptr;
  __smart_ptr_drop(this->_stdin);
  *(&this->_stdin) = nullptr;
}


static struct os_Union1836 builtins___union_copyI_U_ZosProcess_ZException__E(struct os_Union1836 * obj) {
  struct os_Union1836 _rt599 = {};
  switch (obj->tag) {
  case 0u: {
    {
      struct os_Process * y = &obj->_0;
      _rt599 = (struct os_Union1836){.tag = 0, ._0 = os_Process_op__copy(y)};
      return _rt599;
    }
  }
  case 1u: {
    {
      struct Exception * y = obj->_1;
      _rt599 = (struct os_Union1836){.tag = 1, ._1 = __smart_ptr_get(y)};
      return _rt599;
    }
  }
  default: { unreachable("unhandled-default-case"); }
  }
  
}


static void builtins___union_dctorI_U_ZosProcess_ZException__E(struct os_Union1836 * obj) {
  switch (obj->tag) {
  case 0u: {
    {
      struct os_Process * y = &obj->_0;
      os_Process_op__destructor(y);
    }
    break;
  }
  case 1u: {
    {
      struct Exception * y = obj->_1;
      __smart_ptr_drop(y);
    }
    break;
  }
  default: { unreachable("unhandled-default-case"); }
  }
  
}

__attribute__((always_inline))
static void builtins_OptionalI_TTss_i32_E_op__initI_E(struct OptionalI_TTss_i32_E * this) {
  this->ok = false;
  {
    memset(&this->val, 0, sizeof(struct Tuple1858));
  };
}

__attribute__((always_inline))
static void builtins_OptionalI_TTss_i32_E_op__initI_TTss_i32_E(struct OptionalI_TTss_i32_E * this, struct Tuple1858 value) {
  this->val = value;
  this->ok = true;
}


static void builtins_OptionalI_TTss_i32_E_op__destructor(struct OptionalI_TTss_i32_E * this) {
  if (this->ok) {
    
  }
}

__attribute__((always_inline))
static struct OptionalI_TTss_i32_E builtins_OptionalI_TTss_i32_E_op__copy(struct OptionalI_TTss_i32_E * this) {
  struct OptionalI_TTss_i32_E _rt600 = {};
  _rt600 = (struct OptionalI_TTss_i32_E){
    .ok = this->ok,
    .val = this->val
  };
  return _rt600;
}

__attribute__((always_inline))
static bool builtins_OptionalI_TTss_i32_E_op__truthyI_E(struct OptionalI_TTss_i32_E * this) {
  bool _rt601 = {};
  _rt601 = this->ok;
  return _rt601;
}

__attribute__((always_inline))
static struct Tuple1858 builtins_OptionalI_TTss_i32_E_op__derefI_E(struct OptionalI_TTss_i32_E * this) {
  struct Tuple1858 _rt602 = {};
  _rt602 = this->val;
  return _rt602;
}

 __attribute__((optnone))
static struct Tuple1858 builtins_OptionalI_TTss_i32_E_move(struct OptionalI_TTss_i32_E * this) {
  struct Tuple1858 _rt603 = {};
  this->ok = false;
  _rt603 = this->val;
  return _rt603;
}

__attribute__((always_inline))
static struct Tuple1858 builtins_OptionalI_TTss_i32_E_op__lor(struct OptionalI_TTss_i32_E * this, struct Tuple1858 def) {
  struct Tuple1858 _rt604 = {};
  _rt604 = this->ok? builtins_OptionalI_TTss_i32_E_move(this): def;
  return _rt604;
}

__attribute__((always_inline))
static bool builtins_OptionalI_TTss_i32_E_op__truthyIc_E(const struct OptionalI_TTss_i32_E * this) {
  bool _rt605 = {};
  _rt605 = this->ok;
  return _rt605;
}

__attribute__((always_inline))
static struct Tuple1858 builtins_OptionalI_TTss_i32_E_op__derefIc_E(const struct OptionalI_TTss_i32_E * this) {
  struct Tuple1858 _rt606 = {};
  _rt606 = this->val;
  return _rt606;
}

__attribute__((always_inline))
static struct OptionalI_TTss_i32_E builtins_SomeI_TTss_i32_E(struct Tuple1858 value) {
  struct OptionalI_TTss_i32_E _rt607 = {};
  _rt607 = (struct OptionalI_TTss_i32_E){
    .ok = true,
    .val = value
  };
  return _rt607;
}

__attribute__((always_inline))
static struct OptionalI_TTss_i32_E builtins_OptionalI_TTss_i32_E_op__initCover() {
  struct OptionalI_TTss_i32_E _rt608 = {};
  struct OptionalI_TTss_i32_E __obj400 = (struct OptionalI_TTss_i32_E){
    .ok = false
  };
  builtins_OptionalI_TTss_i32_E_op__initI_E(&__obj400);
  _rt608 = __obj400;
  return _rt608;
}

__attribute__((always_inline))
static struct OptionalI_TTss_i32_E builtins_NoneI_TTss_i32_E() {
  struct OptionalI_TTss_i32_E _rt609 = {};
  _rt609 = builtins_OptionalI_TTss_i32_E_op__initCover();
  return _rt609;
}


static struct OptionalI_TTss_i32_E os___Closure401_op__call(struct __Closure401 * this) {
  struct OptionalI_TTss_i32_E _rt610 = {};
  if (this->i < this->len) {
    struct Tuple1858 _a507 = (struct Tuple1858){
      ._0 = this->data[this->i],
      ._1 = this->i++
    };
    _rt610 = builtins_SomeI_TTss_i32_E(_a507);
    return _rt610;
  }
  _rt610 = builtins_NoneI_TTss_i32_E();
  return _rt610;
}


static void os___Closure401_op__init(struct __Closure401 * this) {
  
}

__attribute__((always_inline))
static struct SliceI_Tss_E builtins_SliceI_Tss_E_op__initCover(struct os_Tuple1843 * data, uint64_t len) {
  struct SliceI_Tss_E _rt611 = {};
  struct SliceI_Tss_E __obj403 = (struct SliceI_Tss_E){};
  builtins_SliceI_Tss_E_op__init(&__obj403, data, len);
  _rt611 = __obj403;
  return _rt611;
}


static struct OutputStream * builtins_OutputStream_op__lshiftI_Tss_E(struct OutputStream * this, const struct os_Tuple1843 * val) {
  struct OutputStream * _rt612 = {};
  builtins_OutputStream_appendChar(this, '(');
  builtins_OutputStream_op__lshiftI_sE(this, val->_0);
  builtins_OutputStream_appendStringI_sE(this, ", ");
  builtins_OutputStream_op__lshiftI_sE(this, val->_1);
  builtins_OutputStream_appendChar(this, ')');
  _rt612 = this;
  return _rt612;
}


static void builtins_SliceI_Tss_E_op__init(struct SliceI_Tss_E * this, struct os_Tuple1843 * data, uint64_t len) {
  this->data = data;
  this->len = len;
}

__attribute__((always_inline))
static void builtins_SliceI_Tss_E_op__idx_assign(struct SliceI_Tss_E * this, uint64_t index, struct os_Tuple1843 data) {
  {
    bool _a508 = index < this->len;
    __cxy_assert(_a508, "__builtins.cxy", 1061u, 9u);
  };
  this->data[index] = data;
}

__attribute__((always_inline))
static struct os_Tuple1843 builtins_SliceI_Tss_E_op__idxI_u64E(struct SliceI_Tss_E * this, uint64_t index) {
  struct os_Tuple1843 _rt613 = {};
  {
    bool _a509 = index < this->len;
    __cxy_assert(_a509, "__builtins.cxy", 1067u, 9u);
  };
  _rt613 = this->data[index];
  return _rt613;
}

__attribute__((always_inline))
static struct os_Tuple1843 builtins_SliceI_Tss_E_op__idxIc_u64E(const struct SliceI_Tss_E * this, uint64_t index) {
  struct os_Tuple1843 _rt614 = {};
  {
    bool _a510 = index < this->len;
    __cxy_assert(_a510, "__builtins.cxy", 1073u, 9u);
  };
  _rt614 = this->data[index];
  return _rt614;
}


static struct __Closure401 * builtins_SliceI_Tss_E_op__range(const struct SliceI_Tss_E * this) {
  struct __Closure401 * _rt615 = {};
  int32_t i = 0;
  _rt615 = ({
    struct __Closure401 * __obj402 = (struct __Closure401 *)__smart_ptr_alloc(sizeof(__Closure401), nullptr);
    __obj402->i = i;
    __obj402->len = this->len;
    __obj402->data = this->data;
    __obj402;
  });
  return _rt615;
}

__attribute__((always_inline))
static uint64_t builtins_SliceI_Tss_E_size(struct SliceI_Tss_E * this) {
  uint64_t _rt616 = {};
  _rt616 = this->len;
  return _rt616;
}

__attribute__((always_inline))
static struct SliceI_Tss_E builtins_SliceI_Tss_E_view(struct SliceI_Tss_E * this, uint64_t start, int64_t count) {
  struct SliceI_Tss_E _rt617 = {};
  {
    bool _a511 = start <= this->len;
    __cxy_assert(_a511, "__builtins.cxy", 1091u, 9u);
  };
  if (count == -1) {
    count = (int64_t)(this->len - start);
  } else {
    {
      bool _a512 = count >= 0 && count <= (this->len - start);
      __cxy_assert(_a512, "__builtins.cxy", 1095u, 13u);
    };
  }
  struct os_Tuple1843 * _a513 = this->data + start;
  _rt617 = builtins_SliceI_Tss_E_op__initCover(_a513, (uint64_t)count);
  return _rt617;
}


static void builtins_SliceI_Tss_E_op__str(const struct SliceI_Tss_E * this, struct OutputStream * sb) {
  builtins_OutputStream_appendChar(sb, '[');
  {
    int64_t i = 0;
    while (i != this->len) {
      {
        if (i != 0) {
          builtins_OutputStream_appendStringI_sE(sb, ", ");
        }
        builtins_OutputStream_op__lshiftI_Tss_E(sb, &this->data[i]);
      }
      i += 1;
    }
  }
  builtins_OutputStream_appendChar(sb, ']');
}

__attribute__((always_inline))
static struct os_Process os_Process_op__initCover(int32_t pid, int32_t input, int32_t out, int32_t err) {
  struct os_Process _rt618 = {};
  struct os_Process __obj412 = (struct os_Process){
    ._stdout = (struct os_FileInputStream *)nullptr,
    ._stderr = (struct os_FileInputStream *)nullptr,
    ._stdin = (struct os_FileOutputStream *)nullptr,
    ._pid = (int32_t)0
  };
  os_Process_op__init(&__obj412, pid, input, out, err);
  _rt618 = __obj412;
  return _rt618;
}


static struct os_Union1836 os_execvpe(const char* cmd, struct SliceI_sE argv, struct SliceI_Tss_E env) {
  struct os_Union1836 _rt619 = {};
  Array580 input = {};
  Array580 out = {};
  Array580 err = {};
  uint64_t sz = builtins_SliceI_sE_size(&argv);
  uint64_t _a514 = sz - 1;
  if (sz < 2 || builtins_SliceI_sE_op__idxI_u64E(&argv, _a514) != nullptr) {
    struct String * _a515 = builtins_String_op__initI_sECoverI_sE("arguments `argv` must be null terminated and argv[0] must be the command");
    struct Exception * _ex349 = (struct Exception *)os_IOError_op__initCover(_a515);
    builtins_Exception_push(_ex349, "os", (const char*) {}, "execvpe", "/home/dev/.cxy/lib/cxy/std/stdlib/os.cxy", (uint64_t)572);
    _rt619 = (struct os_Union1836){.tag = 1, ._1 = _ex349};
    return _rt619;
  }
  struct __string _m516 = builtins___string_op__initCoverI_sE(cmd);
  const char* _a517 = builtins_SliceI_sE_op__idxIc_u64E(&argv, (uint64_t)0);
  struct __string _r518 = builtins___string_op__initCoverI_sE(_a517);
  struct __string * _a519 = &_r518;
  if (builtins___string_op__neq(&_m516, (struct __string *)_a519)) {
    struct String * _a520 = builtins_String_op__initI_sECoverI_sE("first entry of `argv` must be the same as the command name");
    struct Exception * _ex350 = (struct Exception *)os_IOError_op__initCover(_a520);
    builtins_Exception_push(_ex350, "os", (const char*) {}, "execvpe", "/home/dev/.cxy/lib/cxy/std/stdlib/os.cxy", (uint64_t)574);
    _rt619 = (struct os_Union1836){.tag = 1, ._1 = _ex350};
    return _rt619;
  }
  if (pipe((int32_t *)input) != 0) {
    struct String * sb351 = builtins_String_op__initI_ECover();
    const char* _rv404 = builtins_strerr();
    struct OutputStream * _m521 = (struct OutputStream *)sb351;
    struct OutputStream * _m522 = builtins_OutputStream_op__lshiftI_sE(_m521, "opening process input stream failed: ");
    builtins_OutputStream_op__lshiftI_sE(_m522, _rv404);
    struct Exception * _ex352 = (struct Exception *)os_IOError_op__initCover(__smart_ptr_get(sb351));
    builtins_Exception_push(_ex352, "os", (const char*) {}, "execvpe", "/home/dev/.cxy/lib/cxy/std/stdlib/os.cxy", (uint64_t)577);
    _rt619 = (struct os_Union1836){.tag = 1, ._1 = _ex352};
    __smart_ptr_drop(sb351);
    return _rt619;
  }
  if (pipe((int32_t *)out) != 0) {
    struct String * sb353 = builtins_String_op__initI_ECover();
    const char* _rv405 = builtins_strerr();
    struct OutputStream * _m523 = (struct OutputStream *)sb353;
    struct OutputStream * _m524 = builtins_OutputStream_op__lshiftI_sE(_m523, "opening process output stream failed: ");
    builtins_OutputStream_op__lshiftI_sE(_m524, _rv405);
    struct Exception * _ex354 = (struct Exception *)os_IOError_op__initCover(__smart_ptr_get(sb353));
    builtins_Exception_push(_ex354, "os", (const char*) {}, "execvpe", "/home/dev/.cxy/lib/cxy/std/stdlib/os.cxy", (uint64_t)579);
    _rt619 = (struct os_Union1836){.tag = 1, ._1 = _ex354};
    __smart_ptr_drop(sb353);
    return _rt619;
  }
  if (pipe((int32_t *)err) != 0) {
    struct String * sb355 = builtins_String_op__initI_ECover();
    const char* _rv406 = builtins_strerr();
    struct OutputStream * _m525 = (struct OutputStream *)sb355;
    struct OutputStream * _m526 = builtins_OutputStream_op__lshiftI_sE(_m525, "opening process error stream failed: ");
    builtins_OutputStream_op__lshiftI_sE(_m526, _rv406);
    struct Exception * _ex356 = (struct Exception *)os_IOError_op__initCover(__smart_ptr_get(sb355));
    builtins_Exception_push(_ex356, "os", (const char*) {}, "execvpe", "/home/dev/.cxy/lib/cxy/std/stdlib/os.cxy", (uint64_t)581);
    _rt619 = (struct os_Union1836){.tag = 1, ._1 = _ex356};
    __smart_ptr_drop(sb355);
    return _rt619;
  }
  int32_t pid = fork();
  if (pid == -1) {
    struct String * sb357 = builtins_String_op__initI_ECover();
    const char* _rv407 = builtins_strerr();
    struct OutputStream * _m527 = (struct OutputStream *)sb357;
    struct OutputStream * _m528 = builtins_OutputStream_op__lshiftI_sE(_m527, "creating a process failed: ");
    builtins_OutputStream_op__lshiftI_sE(_m528, _rv407);
    struct Exception * _ex358 = (struct Exception *)os_IOError_op__initCover(__smart_ptr_get(sb357));
    builtins_Exception_push(_ex358, "os", (const char*) {}, "execvpe", "/home/dev/.cxy/lib/cxy/std/stdlib/os.cxy", (uint64_t)585);
    _rt619 = (struct os_Union1836){.tag = 1, ._1 = _ex358};
    __smart_ptr_drop(sb357);
    return _rt619;
  }
  if (pid == 0) {
    dup2(input[1], 0);
    dup2(out[1], 1);
    dup2(err[1], 2);
    close(input[0]);
    close(out[0]);
    close(err[0]);
    struct __Closure401 * _rg408 = builtins_SliceI_Tss_E_op__range(&env);
    struct OptionalI_TTss_i32_E _it409 = os___Closure401_op__call(_rg408);
    while (!!builtins_OptionalI_TTss_i32_E_op__truthyI_E(&_it409)) {
      {
        struct Tuple1858 tmpVar410 = builtins_OptionalI_TTss_i32_E_op__derefI_E(&_it409);
        struct os_Tuple1843 x = tmpVar410._0;
        setenv((const char *)x._0, (const char *)x._1, (int32_t)1);
      }
      {
        builtins_OptionalI_TTss_i32_E_op__destructor(&(_it409));
        _it409 = os___Closure401_op__call(_rg408);
      }
    }
    int32_t ret = execvp((const char *)cmd, (const char * *)argv.data);
    struct String * sb359 = builtins_String_op__initI_ECover();
    const char* _rv411 = builtins_strerr();
    struct OutputStream * _m529 = (struct OutputStream *)sb359;
    struct OutputStream * _m530 = builtins_OutputStream_op__lshiftI_sE(_m529, "starting ");
    struct OutputStream * _m531 = builtins_OutputStream_op__lshiftI_sE(_m530, cmd);
    struct OutputStream * _m532 = builtins_OutputStream_op__lshiftI_sE(_m531, " failed: ");
    builtins_OutputStream_op__lshiftI_sE(_m532, _rv411);
    struct Exception * _ex360 = (struct Exception *)os_IOError_op__initCover(__smart_ptr_get(sb359));
    builtins_Exception_push(_ex360, "os", (const char*) {}, "execvpe", "/home/dev/.cxy/lib/cxy/std/stdlib/os.cxy", (uint64_t)598);
    _rt619 = (struct os_Union1836){.tag = 1, ._1 = _ex360};
    __smart_ptr_drop(_rg408);
    builtins_OptionalI_TTss_i32_E_op__destructor(&(_it409));
    __smart_ptr_drop(sb359);
    return _rt619;
    exit(ret);
  } else if (pid > 0) {
    close(input[1]);
    close(out[1]);
    close(err[1]);
    _rt619 = (struct os_Union1836){.tag = 0, ._0 = os_Process_op__initCover(pid, input[0], out[0], err[0])};
    return _rt619;
  }
  struct String * sb361 = builtins_String_op__initI_ECover();
  const char* _rv413 = builtins_strerr();
  struct OutputStream * _m533 = (struct OutputStream *)sb361;
  struct OutputStream * _m534 = builtins_OutputStream_op__lshiftI_sE(_m533, "forking process failed: ");
  builtins_OutputStream_op__lshiftI_sE(_m534, _rv413);
  struct Exception * _ex362 = (struct Exception *)os_IOError_op__initCover(__smart_ptr_get(sb361));
  builtins_Exception_push(_ex362, "os", (const char*) {}, "execvpe", "/home/dev/.cxy/lib/cxy/std/stdlib/os.cxy", (uint64_t)607);
  _rt619 = (struct os_Union1836){.tag = 1, ._1 = _ex362};
  __smart_ptr_drop(sb361);
  return _rt619;
}

__attribute__((always_inline))
static struct os_Union1836 os_execvp(const char* cmd, struct SliceI_sE argv) {
  struct os_Union1836 _rt620 = {};
  struct SliceI_Tss_E env = builtins_SliceI_Tss_E_op__initCover((struct os_Tuple1843 *) {}, (uint64_t)0);
  struct os_Union1836 _res414 = os_execvpe(cmd, argv, env);
  bool ___res414_dflags = true;
  if (_res414.tag == 1u) {
    struct Exception * ex = _res414._1;
    ___res414_dflags = false;
    builtins_Exception_push(ex, "os", (const char*) {}, "execvp", "/home/dev/.cxy/lib/cxy/std/stdlib/os.cxy", 613u);
    _rt620 = (struct os_Union1836){.tag = 1, ._1 = ex};
    return _rt620;
  }
  _rt620 = (struct os_Union1836){.tag = 0, ._0 = _res414._0};
  ___res414_dflags = false;
  return _rt620;
}


/*-----------/workspace/snippets/tests.cxy-----------*/
typedef struct example_User example_User;
struct  example_User {
  int32_t id;
  const char* name;
};

typedef struct Union416(*example_test30I_E_t)();
typedef struct example_Tuple1912 {
  const char* _0;
  example_test30I_E_t _1;
} example_Tuple1912;

typedef struct example_Tuple1912 Array1915[3];

static bool example_check(int32_t a) {
  bool _rt629 = {};
  _rt629 = a != 0;
  return _rt629;
}

__attribute__((always_inline))
static struct TestFailed * builtins_TestFailed_op__initCover() {
  struct TestFailed * _rt630 = {};
  struct TestFailed * __obj628 = (struct TestFailed *)__smart_ptr_alloc(sizeof(TestFailed), nullptr);
  memset(__obj628, 0, sizeof(TestFailed));
  builtins_TestFailed___defaults_init(__obj628);
  builtins_TestFailed_op__init(__obj628);
  _rt630 = __obj628;
  return _rt630;
}


static struct Union416 example_test30I_E() {
  struct Union416 _rt631 = {};
  {
    if (!(!example_check((int32_t)0))) {
      struct Exception * _ex0 = (struct Exception *)builtins_TestFailed_op__initCover();
      builtins_Exception_push(_ex0, (const char*) {}, (const char*) {}, (const char*) {}, "__builtins.cxy", (uint64_t)1584);
      struct Exception * _ex623 = _ex0;
      builtins_Exception_push(_ex623, "example", (const char*) {}, (const char*) {}, "/workspace/snippets/tests.cxy", (uint64_t)31);
      _rt631 = (struct Union416){.tag = 1, ._1 = _ex623};
      return _rt631;
    }
  };
  {
    if (!(example_check((int32_t)1))) {
      struct Exception * _ex0 = (struct Exception *)builtins_TestFailed_op__initCover();
      builtins_Exception_push(_ex0, (const char*) {}, (const char*) {}, (const char*) {}, "__builtins.cxy", (uint64_t)1584);
      struct Exception * _ex624 = _ex0;
      builtins_Exception_push(_ex624, "example", (const char*) {}, (const char*) {}, "/workspace/snippets/tests.cxy", (uint64_t)32);
      _rt631 = (struct Union416){.tag = 1, ._1 = _ex624};
      return _rt631;
    }
  };
  int16_t a = 199;
  {
    if (!(a - 20 == 179)) {
      struct Exception * _ex0 = (struct Exception *)builtins_TestFailed_op__initCover();
      builtins_Exception_push(_ex0, (const char*) {}, (const char*) {}, (const char*) {}, "__builtins.cxy", (uint64_t)1584);
      struct Exception * _ex625 = _ex0;
      builtins_Exception_push(_ex625, "example", (const char*) {}, (const char*) {}, "/workspace/snippets/tests.cxy", (uint64_t)34);
      _rt631 = (struct Union416){.tag = 1, ._1 = _ex625};
      return _rt631;
    }
  };
  _rt631 = (struct Union416){.tag = 0, ._0 = (struct Void){}};
  return _rt631;
}


static struct Union416 example_test37I_E() {
  struct Union416 _rt632 = {};
  {
    if (!(example_check((int32_t)0))) {
      struct Exception * _ex0 = (struct Exception *)builtins_TestFailed_op__initCover();
      builtins_Exception_push(_ex0, (const char*) {}, (const char*) {}, (const char*) {}, "__builtins.cxy", (uint64_t)1584);
      struct Exception * _ex626 = _ex0;
      builtins_Exception_push(_ex626, "example", (const char*) {}, (const char*) {}, "/workspace/snippets/tests.cxy", (uint64_t)38);
      _rt632 = (struct Union416){.tag = 1, ._1 = _ex626};
      return _rt632;
    }
  };
  _rt632 = (struct Union416){.tag = 0, ._0 = (struct Void){}};
  return _rt632;
}


static struct Union416 example_test41I_E() {
  struct Union416 _rt633 = {};
  struct example_User user = (struct example_User){
    .id = 102,
    .name = "Thunya"
  };
  {
    if (!(user.id == 102)) {
      struct Exception * _ex0 = (struct Exception *)builtins_TestFailed_op__initCover();
      builtins_Exception_push(_ex0, (const char*) {}, (const char*) {}, (const char*) {}, "__builtins.cxy", (uint64_t)1584);
      struct Exception * _ex627 = _ex0;
      builtins_Exception_push(_ex627, "example", (const char*) {}, (const char*) {}, "/workspace/snippets/tests.cxy", (uint64_t)43);
      _rt633 = (struct Union416){.tag = 1, ._1 = _ex627};
      return _rt633;
    }
  };
  _rt633 = (struct Union416){.tag = 0, ._0 = (struct Void){}};
  return _rt633;
}

Array1915 example_allTestCases = (Array1915){(struct example_Tuple1912){
  ._0 = "Test will pass",
  ._1 = example_test30I_E
}, (struct example_Tuple1912){
  ._0 = "Test will fail",
  ._1 = example_test37I_E
}, (struct example_Tuple1912){
  ._0 = "Tests specific code",
  ._1 = example_test41I_E
}};typedef struct { __typeof(example_allTestCases[0]) *data; uint64_t len; } __TestCases;
int main(int argc, char *argv[]) {
  return builtins_runTests((SliceI_sE){.data = argv, .len = argc}, "/workspace/snippets/tests.cxy", (SliceI_TsFU_ZVoid_ZException____E){.data = example_allTestCases, .len = sizeof(example_allTestCases)/sizeof(example_allTestCases[0])});
  
}
#ifdef __MAIN_RETURN_TYPE__
#ifdef __MAIN_RETURNS___
__MAIN_RETURN_TYPE__ main(int argc, char *argv[]) {
#else
int main(int argc, char *argv[]) {
#endif
#ifdef __MAIN_PARAM_TYPE__
    __MAIN_PARAM_TYPE__ args = { .data = argv, .len = argc };
#define __MAIN_ARGS__ args
#else
#define __MAIN_ARGS__
#endif

#ifdef __MAIN_RAISED_TYPE__
    __MAIN_RAISED_TYPE__ ex = _main(__MAIN_ARGS__);
    if (ex.tag == 1) {
         panicUnhandledException(ex._1);
         unreachable();
    }
#ifdef __MAIN_RETURNS__
    __MAIN_RETURN_TYPE__ ret = ex._0;
    __MAIN_RAISED_TYPE_DCTOR__(&ex);
    return ret;
#else
     __MAIN_RAISED_TYPE_DCTOR__(&ex);
     return 0;
#endif
#else
#ifdef __MAIN_RETURNS__
      return _main(__MAIN_ARGS__);
#else
      _main(__MAIN_ARGS__);
      return 0;
#endif
#endif
}

#endif
#if defined(__GNUC__)
#pragma GCC diagnostic pop
#elif defined(__clang__)
#pragma clang diagnostic pop
#else
#error "Unsupported compiler"
#endif

/* clang -D_XOPEN_SOURCE=1 -D_DEFAULT_SOURCE -I/usr/lib/llvm-18/lib/clang/18/include -I/usr/local/include -I/usr/include/x86_64-linux-gnu -I/usr/include /home/dev/.cxy/lib/cxy/std/stdlib/native/evloop/ae.c /home/dev/.cxy/lib/cxy/std/stdlib/native/memtrace.c /home/dev/.cxy/lib/cxy/std/stdlib/native/dns/dns.c /home/dev/.cxy/lib/cxy/std/stdlib/native/nos.c /home/dev/.cxy/lib/cxy/std/stdlib/native/http/parser.c ./app.c -o ./app */
