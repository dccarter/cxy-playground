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

typedef struct __Closure3 __Closure3;
struct  __Closure3 {
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

typedef struct CallTrace CallTrace;
struct  CallTrace {
  const char* mod;
  const char* cls;
  const char* fun;
  const char* path;
  uint64_t line;
};

typedef struct StackTrace StackTrace;
struct  StackTrace {
  struct CallTrace * calls;
  uint64_t size;
  uint64_t capacity;
};

typedef struct Exception_VTable Exception_VTable;
typedef struct Exception Exception;
struct  Exception {
  struct Exception_VTable * vtable;
  const char* name;
  struct StackTrace stackTrace;
};

typedef const char*(*builtins_Exception_what_t)(struct Exception *);
struct  Exception_VTable {
  builtins_Exception_what_t what;
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
static void builtins___init();
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
  uint64_t _a11 = strlen(file);
  write((int32_t)2, (const void *)file, _a11);
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
  uint64_t _a12 = strlen(msg);
  write((int32_t)2, (const void *)msg, _a12);
  write((int32_t)2, (const void *)"\n  @", (uint64_t)4);
  uint64_t _a13 = strlen(file);
  write((int32_t)2, (const void *)file, _a13);
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
  uint64_t _a14 = size + sizeof(struct __mem);
  void * ptr = malloc(_a14);
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
  void * _a15 = malloc(size);
  return memset(_a15, (int32_t)0, size);
}

__attribute__((always_inline))
static uint32_t builtins_hash_fnv1a_uint8(uint32_t h, uint8_t x) {
  return (h ^ x) * 16777619u;
}


static uint32_t builtins_hash_fnv1a_uint16(uint32_t h, uint16_t x) {
  uint8_t _a16 = (uint8_t)(x & 255);
  uint32_t _a17 = builtins_hash_fnv1a_uint8(h, _a16);
  uint8_t _a18 = (uint8_t)(x >> 8);
  return builtins_hash_fnv1a_uint8(_a17, _a18);
}


static uint32_t builtins_hash_fnv1a_uint32(uint32_t h, uint32_t x) {
  uint16_t _a19 = (uint16_t)(x & 65535);
  uint32_t _a20 = builtins_hash_fnv1a_uint16(h, _a19);
  uint16_t _a21 = (uint16_t)(x >> 16);
  return builtins_hash_fnv1a_uint16(_a20, _a21);
}


static uint32_t builtins_hash_fnv1a_uint64(uint32_t h, uint64_t x) {
  uint32_t _a22 = (uint32_t)(x & 4294967295);
  uint32_t _a23 = builtins_hash_fnv1a_uint32(h, _a22);
  uint32_t _a24 = (uint32_t)(x >> 32);
  return builtins_hash_fnv1a_uint32(_a23, _a24);
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
  struct __string __obj0 = (struct __string){
    .s = (const char*) {},
    ._size = (uint64_t)0
  };
  builtins___string_op__initI_su64E(&__obj0, s, size);
  return __obj0;
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
  struct OptionalI_u64E __obj1 = (struct OptionalI_u64E){
    .ok = false
  };
  builtins_OptionalI_u64E_op__initI_E(&__obj1);
  return __obj1;
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
    uint64_t _a25 = this->_size - i;
    return builtins___string_op__initCoverI_su64E((const char*)p, _a25);
  }
  return builtins___string_op__initCoverI_su64E(this->s, this->_size);
}


static struct __string builtins___string_trimRight(const struct __string * this) {
  uint64_t i = this->_size;
  while (i > 0) {
    {
      uint64_t _idx26 = i - 1;
      if (!(isspace((int32_t)this->s[_idx26]) != 0)) {
        break;
      }
      i--;
    }
    
  }
  return builtins___string_op__initCoverI_su64E(this->s, i);
}

__attribute__((always_inline))
static struct __string builtins___string_trim(const struct __string * this) {
  struct __string _m27 = builtins___string_trimLeft(this);
  return builtins___string_trimRight(&_m27);
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
    bool _a28 = start <= this->_size;
    __cxy_assert(_a28, "__builtins.cxy", 454u, 9u);
  };
  if (count == -1) {
    count = (int64_t)(this->_size - start);
  } else {
    {
      bool _a29 = count >= 0 && count <= (this->_size - start);
      __cxy_assert(_a29, "__builtins.cxy", 458u, 13u);
    };
  }
  const char * q = (const char *)this->s;
  const char* _a30 = (const char*)q + start;
  return builtins___string_op__initCoverI_su64E(_a30, (uint64_t)count);
}


static void builtins___string_copyto(const struct __string * this, char * buf, uint64_t size) {
  {
    bool _a31 = size > this->_size;
    __cxy_assert(_a31, "__builtins.cxy", 464u, 9u);
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
  uint64_t _a32 = builtins___string_size(this) - builtins___string_size(&suffix);
  struct __string _m33 = builtins___string_substr(this, _a32, (int64_t)-1);
  return builtins___string_op__eq(&_m33, &suffix);
}


static bool builtins___string_startswith(const struct __string * this, struct __string suffix) {
  if (builtins___string_size(&suffix) > builtins___string_size(this)) {
    return false;
  }
  int64_t _a34 = (int64_t)builtins___string_size(&suffix);
  struct __string _m35 = builtins___string_substr(this, 0u, _a34);
  return builtins___string_op__eq(&_m35, &suffix);
}


static struct OptionalI_u64E builtins___string_find(const struct __string * this, struct __string part) {
  if (builtins___string_empty(&part)) {
    uint64_t _a36 = this->_size - 1;
    return builtins___string_empty(this)? builtins_NoneI_u64E(): builtins_SomeI_u64E(_a36);
  }
  uint64_t i = this->_size;
  uint64_t j = 0u;
  const char * p = (const char *)this->s;
  while (i >= part._size) {
    {
      i--;
      const void * _a37 = (const void *)p + j;
      if (memcmp(_a37, (const void *)part.s, part._size) == 0) {
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
      uint64_t _a38 = this->_size - 1;
      return builtins___string_empty(this)? builtins_NoneI_u64E(): builtins_SomeI_u64E(_a38);
    }
    int64_t j = (int64_t)(this->_size - part._size);
    const char * p = (const char *)this->s;
    while (j >= 0) {
      {
        const void * _a39 = (const void *)p + j;
        if (memcmp(_a39, (const void *)part.s, part._size) == 0) {
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
    uint64_t _a40 = strlen(s);
    this->vtable->append(this, (const void *)s, _a40);
  }
}

__attribute__((always_inline))
static void builtins_OutputStream_appendStringI_cRZ__string_E(struct OutputStream * this, const struct __string * s) {
  uint64_t _a41 = builtins___string_size(s);
  this->vtable->append(this, (const void *)s->s, _a41);
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
  struct OptionalI_Tci32_E __obj2 = (struct OptionalI_Tci32_E){
    .ok = false
  };
  builtins_OptionalI_Tci32_E_op__initI_E(&__obj2);
  return __obj2;
}

__attribute__((always_inline))
static struct OptionalI_Tci32_E builtins_NoneI_Tci32_E() {
  return builtins_OptionalI_Tci32_E_op__initCover();
}


static struct OptionalI_Tci32_E __Closure3_op__call(struct __Closure3 * this) {
  if (this->i < this->_size) {
    struct Tuple235 _a42 = (struct Tuple235){
      ._0 = this->_data[this->i],
      ._1 = this->i++
    };
    return builtins_SomeI_Tci32_E(_a42);
  } else {
    return builtins_NoneI_Tci32_E();
  }
}


static void __Closure3_op__init(struct __Closure3 * this) {
  
}

__attribute__((always_inline))
static struct __string builtins___string_op__initCoverI_sE(const char* s) {
  struct __string __obj5 = (struct __string){
    .s = (const char*) {},
    ._size = (uint64_t)0
  };
  builtins___string_op__initI_sE(&__obj5, s);
  return __obj5;
}

struct OutputStream_VTable String_vTable = (struct OutputStream_VTable){
  .append = (builtins_OutputStream_append_t)builtins_String_append
};

static void builtins_String_grow(struct String * this, uint64_t growSize) {
  uint64_t _a43 = this->_size + growSize;
  uint64_t newSize = builtins_maxI_u64E(_a43, 16u);
  if (this->_data == nullptr) {
    uint64_t _a44 = newSize + 1;
    this->_data = (char *)malloc(_a44);
    this->_capacity = newSize;
  } else if (this->_capacity < newSize) {
    while (this->_capacity < newSize) {
      {
        this->_capacity <<= 1;
      }
      
    }
    uint64_t _a45 = this->_capacity + 1;
    this->_data = (char *)realloc((void *)this->_data, _a45);
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
    bool _a46 = this->_capacity <= newSize;
    __cxy_assert(_a46, "__builtins.cxy", 804u, 9u);
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
    uint64_t _a47 = this->_size - i;
    memmove((void *)this->_data, (const void *)p, _a47);
    this->_size = this->_size - i;
  }
}


static void builtins_String_trimRight(struct String * this) {
  while (this->_size > 0) {
    {
      uint64_t _idx48 = this->_size - 1;
      if (!(isspace((int32_t)this->_data[_idx48]) != 0)) {
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
  uint64_t _a49 = strlen(other);
  return builtins_String_compareIc_cPcu64E(this, (const char *)other, _a49);
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
    bool _a50 = idx < this->_size;
    __cxy_assert(_a50, "__builtins.cxy", 955u, 9u);
  };
  return this->_data[idx];
}


static struct __Closure3 * builtins_String_op__range(const struct String * this) {
  int32_t i = 0;
  return ({
    struct __Closure3 * __obj4 = (struct __Closure3 *)__smart_ptr_alloc(sizeof(__Closure3), nullptr);
    __obj4->i = i;
    __obj4->_size = this->_size;
    __obj4->_data = this->_data;
    __obj4;
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
  struct __string _m51 = builtins_String___str(this);
  return builtins___string_substr(&_m51, start, count);
}

__attribute__((always_inline))
static bool builtins_String_endswithIc_ZString_E(const struct String * this, struct String * suffix) {
  struct __string _m52 = builtins_String___str(this);
  struct __string _a53 = builtins_String___str(suffix);
  return builtins___string_endswith(&_m52, _a53);
}

__attribute__((always_inline))
static bool builtins_String_endswithIc_Z__string_E(const struct String * this, struct __string suffix) {
  struct __string _m54 = builtins_String___str(this);
  return builtins___string_endswith(&_m54, suffix);
}

__attribute__((always_inline))
static bool builtins_String_endswithIc_sE(const struct String * this, const char* suffix) {
  struct __string _m55 = builtins_String___str(this);
  struct __string _a56 = builtins___string_op__initCoverI_sE(suffix);
  return builtins___string_endswith(&_m55, _a56);
}

__attribute__((always_inline))
static bool builtins_String_startswithIc_ZString_E(const struct String * this, struct String * suffix) {
  struct __string _m57 = builtins_String___str(this);
  struct __string _a58 = builtins_String___str(suffix);
  return builtins___string_startswith(&_m57, _a58);
}

__attribute__((always_inline))
static bool builtins_String_startswithIc_Z__string_E(const struct String * this, struct __string suffix) {
  struct __string _m59 = builtins_String___str(this);
  return builtins___string_startswith(&_m59, suffix);
}

__attribute__((always_inline))
static bool builtins_String_startswithIc_sE(const struct String * this, const char* suffix) {
  struct __string _m60 = builtins_String___str(this);
  struct __string _a61 = builtins___string_op__initCoverI_sE(suffix);
  return builtins___string_startswith(&_m60, _a61);
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
  struct StdOutputStream * __obj6 = (struct StdOutputStream *)__smart_ptr_alloc(sizeof(StdOutputStream), nullptr);
  memset(__obj6, 0, sizeof(StdOutputStream));
  builtins_StdOutputStream___defaults_init(__obj6);
  builtins_StdOutputStream_op__init(__obj6, fd);
  return __obj6;
}

struct OutputStream * builtins_stdout = nullptr;
struct OutputStream * builtins_stderr = nullptr;
int64_t builtins_SysConfPageSize = {};
int64_t builtins_SysConfNumProcs = {};
__attribute__((always_inline))
static bool builtins_EqualsCase_op__callIc_cRZString_cRZString_E(const struct EqualsCase * this, const struct String * lhs, const struct String * rhs) {
  const char* _a62 = builtins_String_str(lhs);
  const char* _a63 = builtins_String_str(rhs);
  uint64_t _a64 = builtins_String_size(lhs);
  return builtins_String_size(lhs) == builtins_String_size(rhs) && strncasecmp(_a62, _a63, _a64) == 0;
}

__attribute__((always_inline))
static bool builtins_EqualsCase_op__callIc_cscsE(const struct EqualsCase * this, const char* lhs, const char* rhs) {
  return strcasecmp(lhs, rhs) == 0;
}

__attribute__((always_inline))
static bool builtins_EqualsCase_op__callIc_cRZ__string_cRZ__string_E(const struct EqualsCase * this, const struct __string * lhs, const struct __string * rhs) {
  const char* _a65 = builtins___string_str(lhs);
  const char* _a66 = builtins___string_str(rhs);
  uint64_t _a67 = builtins___string_size(lhs);
  return builtins___string_size(lhs) == builtins___string_size(rhs) && strncasecmp(_a65, _a66, _a67) == 0;
}

__attribute__((always_inline))
static uint32_t builtins_HashCase_op__callIc_cRZString_E(const struct HashCase * this, const struct String * value) {
  char * _a68 = builtins_String_data(value);
  uint64_t _a69 = builtins_String_size(value);
  return builtins_hash_fnv1a_string_n_igc(16777619u, (const char *)_a68, _a69);
}

__attribute__((always_inline))
static uint32_t builtins_HashCase_op__callIc_cRZ__string_E(const struct HashCase * this, const struct __string * value) {
  const char * _a70 = builtins___string_data(value);
  uint64_t _a71 = builtins___string_size(value);
  return builtins_hash_fnv1a_string_n_igc(16777619u, _a70, _a71);
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
    struct OutputStream * _m72 = builtins_OutputStream_op__lshiftI_sE(os, this->mod);
    builtins_OutputStream_op__lshiftI_sE(_m72, "::");
  }
  if (this->cls != nullptr) {
    struct OutputStream * _m73 = builtins_OutputStream_op__lshiftI_sE(os, this->cls);
    builtins_OutputStream_op__lshiftI_sE(_m73, "::");
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
  struct OutputStream * _m74 = builtins_OutputStream_op__lshiftI_sE(os, ":");
  struct OutputStream * _m75 = builtins_OutputStream_op__lshiftI_u64E(_m74, this->line);
  builtins_OutputStream_op__lshiftI_sE(_m75, ")");
}


static struct OutputStream * builtins_OutputStream_op__lshiftI_cE(struct OutputStream * this, const char val) {
  builtins_OutputStream_appendChar(this, (wchar_t)val);
  return this;
}

__attribute__((always_inline))
static struct Repeat builtins_Repeat_op__initCover(char c, uint64_t count) {
  struct Repeat __obj7 = (struct Repeat){};
  builtins_Repeat_op__init(&__obj7, c, count);
  return __obj7;
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
    uint64_t _a76 = sizeof(struct CallTrace) * this->capacity;
    this->calls = (struct CallTrace *)realloc((void *)this->calls, _a76);
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
        struct OutputStream * _m77 = builtins_OutputStream_op__lshiftI_sE(os, "\n ");
        struct OutputStream * _m78 = builtins_OutputStream_op__lshiftI_ZRepeat_E(_m77, &sp);
        builtins_OutputStream_op__lshiftI_ZCallTrace_E(_m78, &this->calls[i]);
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
        struct OutputStream * _m79 = builtins_OutputStream_op__lshiftI_sE(os, "\n ");
        builtins_OutputStream_op__lshiftI_ZCallTrace_E(_m79, &this->calls[i]);
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
  struct StackTrace __obj8 = (struct StackTrace){
    .calls = (struct CallTrace *) {},
    .size = 0u,
    .capacity = 0u
  };
  builtins_StackTrace_op__init(&__obj8);
  return __obj8;
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
  const char* _rv9 = this->vtable->what(this);
  struct OutputStream * _m80 = builtins_OutputStream_op__lshiftI_sE(os, this->name);
  struct OutputStream * _m81 = builtins_OutputStream_op__lshiftI_sE(_m80, "(\"");
  struct OutputStream * _m82 = builtins_OutputStream_op__lshiftI_sE(_m81, _rv9);
  builtins_OutputStream_op__lshiftI_sE(_m82, "\")");
}

__attribute__((always_inline))
static void builtins_Exception_dumpStackTrace(const struct Exception * this, struct OutputStream * os, int64_t s, uint64_t tabs) {
  builtins_StackTrace_dump(&this->stackTrace, os, s, tabs);
}


static void builtins_Exception_op__str(const struct Exception * this, struct OutputStream * os) {
  const char* _rv10 = this->vtable->what(this);
  struct OutputStream * _m83 = builtins_OutputStream_op__lshiftI_sE(os, this->name);
  struct OutputStream * _m84 = builtins_OutputStream_op__lshiftI_sE(_m83, "(\"");
  struct OutputStream * _m85 = builtins_OutputStream_op__lshiftI_sE(_m84, _rv10);
  struct OutputStream * _m86 = builtins_OutputStream_op__lshiftI_sE(_m85, "\") at:");
  struct OutputStream * _m87 = builtins_OutputStream_op__lshiftI_ZStackTrace_E(_m86, &this->stackTrace);
  builtins_OutputStream_op__lshiftI_sE(_m87, "\n");
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
  struct OutputStream * _m88 = builtins_OutputStream_op__lshiftI_ZException_E(builtins_stderr, (const struct Exception *)ex);
  builtins_OutputStream_op__lshiftI_sE(_m88, "\n");
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
      bool _a89 = size < (this->_capacity - this->_size);
      __cxy_assert(_a89, "__builtins.cxy", 1477u, 13u);
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
      struct OutputStream * _m90 = builtins_OutputStream_op__lshiftI_i8E((struct OutputStream *)mos, this->_bg);
      builtins_OutputStream_op__lshiftI_sE(_m90, ";");
    }
  }
  struct OutputStream * _m91 = builtins_OutputStream_op__lshiftI_i8E((struct OutputStream *)mos, this->color);
  builtins_OutputStream_op__lshiftI_wE(_m91, 'm');
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
            __cxy_assert(false, "__builtins.cxy", 1543u, 28u);
          };
        }
        break;
      }}
      
      {
        bool _a92 = p[i] == '\0' || p[i++] == '|';
        __cxy_assert(_a92, "__builtins.cxy", 1545u, 13u);
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
__attribute__((constructor))

static void builtins___init() {
  builtins_stdout = builtins_StdOutputStream_op__initCover((int32_t)1);
  builtins_stderr = builtins_StdOutputStream_op__initCover((int32_t)2);
  builtins_SysConfPageSize = sysconf((int32_t)29);
  builtins_SysConfNumProcs = sysconf((int32_t)58);
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
typedef struct __ext_s102 ___ext_s102;
struct  __ext_s102 {
  uint64_t id;
  int64_t when_sec;
  int64_t when_ms;
  struct aeFileEvent * prev;
  struct aeFileEvent * next;
  int32_t fd;
};

typedef void(*Func750)(struct aeEventLoop *, int32_t, void *, int32_t);
struct  aeFileEvent {
  struct __ext_s102 timer;
  int32_t mask;
  Func750 rfileProc;
  Func750 wfileProc;
  void * clientData;
};

typedef struct aeFiredEvent _aeFiredEvent;
struct  aeFiredEvent {
  int32_t fd;
  int32_t mask;
};

typedef struct aeTimeEvent _aeTimeEvent;
typedef Status(*Func752)(struct aeEventLoop *, int64_t, void *);
typedef void(*Func754)(struct aeEventLoop *, void *);
struct  aeTimeEvent {
  uint64_t id;
  int64_t when_sec;
  int64_t when_ms;
  struct aeTimeEvent * prev;
  struct aeTimeEvent * next;
  int32_t fd;
  Func752 timeProc;
  Func754 finalizerProc;
  void * clientData;
};

typedef void(*Func777)(struct aeEventLoop *);
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
  Func777 beforesleep;
  Func777 aftersleep;
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
typedef int64_t Array412[8];
typedef struct __ext_s99 ___ext_s99;
typedef uint64_t Array415[16];
struct  __ext_s99 {
  Array415 __val;
};

struct  __jmp_buf_tag {
  Array412 __jmpbuf;
  int32_t __mask_was_saved;
  struct __ext_s99 __saved_mask;
};

typedef struct __jmp_buf_tag Array422[1];
struct  __attribute__((aligned(16))) coro_Coroutine {
  struct coro_Coroutine * link;
  void * scheduler;
  int32_t id;
  int32_t result;
  Array422 ctx;
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

typedef struct list___Closure104 list___Closure104;
struct  list___Closure104 {
  struct coro_Coroutine * item;
};

typedef struct OptionalI_PZcoroCachedStack_E OptionalI_PZcoroCachedStack_E;
struct  OptionalI_PZcoroCachedStack_E {
  bool ok;
  struct coro_CachedStack * val;
};

typedef struct list___Closure108 list___Closure108;
struct  list___Closure108 {
  struct coro_CachedStack * item;
};

typedef struct coro_Mutex coro_Mutex;
struct  coro_Mutex {
  struct list_ListI_ZcoroCoroutine_E waiting;
  struct coro_Coroutine * holder;
};

static void coro___init_coro();
extern int64_t aeOsTime();
extern Status aeCreateTimeEvent(struct aeEventLoop * eventLoop, int64_t milliseconds, Func752 proc, void * clientData, Func754 finalizerProc);
extern void aeDeleteFileEvent(struct aeEventLoop * eventLoop, int32_t fd, State mask);
extern Status aeCreateFileEvent(struct aeEventLoop * eventLoop, int32_t fd, State mask, Func750 proc, void * clientData, uint64_t timeout);
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
  uint64_t _rt124 = {};
  _rt124 = ((size + (align - 1)) & ~(align - 1)) + align;
  return _rt124;
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
  struct OptionalI_PZcoroCoroutine_E _rt125 = {};
  _rt125 = (struct OptionalI_PZcoroCoroutine_E){
    .ok = this->ok,
    .val = this->val
  };
  return _rt125;
}

__attribute__((always_inline))
static bool builtins_OptionalI_PZcoroCoroutine_E_op__truthyI_E(struct OptionalI_PZcoroCoroutine_E * this) {
  bool _rt126 = {};
  _rt126 = this->ok;
  return _rt126;
}

__attribute__((always_inline))
static struct coro_Coroutine * builtins_OptionalI_PZcoroCoroutine_E_op__derefI_E(struct OptionalI_PZcoroCoroutine_E * this) {
  struct coro_Coroutine * _rt127 = {};
  _rt127 = this->val;
  return _rt127;
}

 __attribute__((optnone))
static struct coro_Coroutine * builtins_OptionalI_PZcoroCoroutine_E_move(struct OptionalI_PZcoroCoroutine_E * this) {
  struct coro_Coroutine * _rt128 = {};
  this->ok = false;
  _rt128 = this->val;
  return _rt128;
}

__attribute__((always_inline))
static struct coro_Coroutine * builtins_OptionalI_PZcoroCoroutine_E_op__lor(struct OptionalI_PZcoroCoroutine_E * this, struct coro_Coroutine * def) {
  struct coro_Coroutine * _rt129 = {};
  _rt129 = this->ok? builtins_OptionalI_PZcoroCoroutine_E_move(this): def;
  return _rt129;
}

__attribute__((always_inline))
static bool builtins_OptionalI_PZcoroCoroutine_E_op__truthyIc_E(const struct OptionalI_PZcoroCoroutine_E * this) {
  bool _rt130 = {};
  _rt130 = this->ok;
  return _rt130;
}

__attribute__((always_inline))
static struct coro_Coroutine * builtins_OptionalI_PZcoroCoroutine_E_op__derefIc_E(const struct OptionalI_PZcoroCoroutine_E * this) {
  struct coro_Coroutine * _rt131 = {};
  _rt131 = this->val;
  return _rt131;
}

__attribute__((always_inline))
static struct OptionalI_PZcoroCoroutine_E builtins_SomeI_PZcoroCoroutine_E(struct coro_Coroutine * value) {
  struct OptionalI_PZcoroCoroutine_E _rt132 = {};
  _rt132 = (struct OptionalI_PZcoroCoroutine_E){
    .ok = true,
    .val = value
  };
  return _rt132;
}

__attribute__((always_inline))
static struct OptionalI_PZcoroCoroutine_E builtins_OptionalI_PZcoroCoroutine_E_op__initCover() {
  struct OptionalI_PZcoroCoroutine_E _rt133 = {};
  struct OptionalI_PZcoroCoroutine_E __obj103 = (struct OptionalI_PZcoroCoroutine_E){
    .ok = false
  };
  builtins_OptionalI_PZcoroCoroutine_E_op__initI_E(&__obj103);
  _rt133 = __obj103;
  return _rt133;
}

__attribute__((always_inline))
static struct OptionalI_PZcoroCoroutine_E builtins_NoneI_PZcoroCoroutine_E() {
  struct OptionalI_PZcoroCoroutine_E _rt134 = {};
  _rt134 = builtins_OptionalI_PZcoroCoroutine_E_op__initCover();
  return _rt134;
}


static struct OptionalI_PZcoroCoroutine_E coro___Closure104_op__call(struct list___Closure104 * this) {
  struct OptionalI_PZcoroCoroutine_E _rt135 = {};
  if (this->item != nullptr) {
    struct coro_Coroutine * curr = this->item;
    this->item = this->item->link;
    _rt135 = builtins_SomeI_PZcoroCoroutine_E(curr);
    return _rt135;
  } else {
    _rt135 = builtins_NoneI_PZcoroCoroutine_E();
    return _rt135;
  }
}


static void coro___Closure104_op__init(struct list___Closure104 * this) {
  
}


static void list_ListI_ZcoroCoroutine_E_push(struct list_ListI_ZcoroCoroutine_E * this, struct coro_Coroutine * item) {
  {
    bool _a111 = item->link == nullptr;
    __cxy_assert(_a111, "/home/dev/.cxy/lib/cxy/std/stdlib/list.cxy", 9u, 9u);
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
  struct coro_Coroutine * _rt136 = {};
  struct coro_Coroutine * item = this->_head;
  if (this->_head != nullptr) {
    this->count--;
    this->_head = this->_head->link;
    if (this->_head == nullptr) {
      this->_tail = nullptr;
    }
    item->link = nullptr;
  }
  _rt136 = item;
  return _rt136;
}


static struct list___Closure104 * list_ListI_ZcoroCoroutine_E_op__range(struct list_ListI_ZcoroCoroutine_E * this) {
  struct list___Closure104 * _rt137 = {};
  struct coro_Coroutine * item = this->_head;
  _rt137 = ({
    struct list___Closure104 * __obj105 = (struct list___Closure104 *)__smart_ptr_alloc(sizeof(list___Closure104), nullptr);
    __obj105->item = item;
    __obj105;
  });
  return _rt137;
}

__attribute__((always_inline))
static struct coro_Coroutine * list_ListI_ZcoroCoroutine_E_front(struct list_ListI_ZcoroCoroutine_E * this) {
  struct coro_Coroutine * _rt138 = {};
  if (this->_head == nullptr) {
    return nullptr;
  } else {
    _rt138 = this->_head;
    return _rt138;
  }
}

__attribute__((always_inline))
static struct coro_Coroutine * list_ListI_ZcoroCoroutine_E_back(struct list_ListI_ZcoroCoroutine_E * this) {
  struct coro_Coroutine * _rt139 = {};
  if (this->_tail == nullptr) {
    return nullptr;
  } else {
    _rt139 = this->_tail;
    return _rt139;
  }
}

__attribute__((always_inline))
static uint64_t list_ListI_ZcoroCoroutine_E_size(const struct list_ListI_ZcoroCoroutine_E * this) {
  uint64_t _rt140 = {};
  _rt140 = this->count;
  return _rt140;
}

__attribute__((always_inline))
static bool list_ListI_ZcoroCoroutine_E_empty(const struct list_ListI_ZcoroCoroutine_E * this) {
  bool _rt141 = {};
  _rt141 = this->_head == nullptr;
  return _rt141;
}

__attribute__((always_inline))
static struct coro_Coroutine coro_Coroutine_op__initCover(const char* name, int32_t id) {
  struct coro_Coroutine _rt142 = {};
  struct coro_Coroutine __obj106 = (struct coro_Coroutine){
    .link = (struct coro_Coroutine *) {},
    .scheduler = (void *) {},
    .id = (int32_t)-1,
    .result = (int32_t)0,
    .ready = false,
    .promise = (void *) {},
    .name = (const char*) {}
  };
  coro_Coroutine_op__init(&__obj106, name, id);
  _rt142 = __obj106;
  return _rt142;
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
  struct OptionalI_PZcoroCachedStack_E _rt143 = {};
  _rt143 = (struct OptionalI_PZcoroCachedStack_E){
    .ok = this->ok,
    .val = this->val
  };
  return _rt143;
}

__attribute__((always_inline))
static bool builtins_OptionalI_PZcoroCachedStack_E_op__truthyI_E(struct OptionalI_PZcoroCachedStack_E * this) {
  bool _rt144 = {};
  _rt144 = this->ok;
  return _rt144;
}

__attribute__((always_inline))
static struct coro_CachedStack * builtins_OptionalI_PZcoroCachedStack_E_op__derefI_E(struct OptionalI_PZcoroCachedStack_E * this) {
  struct coro_CachedStack * _rt145 = {};
  _rt145 = this->val;
  return _rt145;
}

 __attribute__((optnone))
static struct coro_CachedStack * builtins_OptionalI_PZcoroCachedStack_E_move(struct OptionalI_PZcoroCachedStack_E * this) {
  struct coro_CachedStack * _rt146 = {};
  this->ok = false;
  _rt146 = this->val;
  return _rt146;
}

__attribute__((always_inline))
static struct coro_CachedStack * builtins_OptionalI_PZcoroCachedStack_E_op__lor(struct OptionalI_PZcoroCachedStack_E * this, struct coro_CachedStack * def) {
  struct coro_CachedStack * _rt147 = {};
  _rt147 = this->ok? builtins_OptionalI_PZcoroCachedStack_E_move(this): def;
  return _rt147;
}

__attribute__((always_inline))
static bool builtins_OptionalI_PZcoroCachedStack_E_op__truthyIc_E(const struct OptionalI_PZcoroCachedStack_E * this) {
  bool _rt148 = {};
  _rt148 = this->ok;
  return _rt148;
}

__attribute__((always_inline))
static struct coro_CachedStack * builtins_OptionalI_PZcoroCachedStack_E_op__derefIc_E(const struct OptionalI_PZcoroCachedStack_E * this) {
  struct coro_CachedStack * _rt149 = {};
  _rt149 = this->val;
  return _rt149;
}

__attribute__((always_inline))
static struct OptionalI_PZcoroCachedStack_E builtins_SomeI_PZcoroCachedStack_E(struct coro_CachedStack * value) {
  struct OptionalI_PZcoroCachedStack_E _rt150 = {};
  _rt150 = (struct OptionalI_PZcoroCachedStack_E){
    .ok = true,
    .val = value
  };
  return _rt150;
}

__attribute__((always_inline))
static struct OptionalI_PZcoroCachedStack_E builtins_OptionalI_PZcoroCachedStack_E_op__initCover() {
  struct OptionalI_PZcoroCachedStack_E _rt151 = {};
  struct OptionalI_PZcoroCachedStack_E __obj107 = (struct OptionalI_PZcoroCachedStack_E){
    .ok = false
  };
  builtins_OptionalI_PZcoroCachedStack_E_op__initI_E(&__obj107);
  _rt151 = __obj107;
  return _rt151;
}

__attribute__((always_inline))
static struct OptionalI_PZcoroCachedStack_E builtins_NoneI_PZcoroCachedStack_E() {
  struct OptionalI_PZcoroCachedStack_E _rt152 = {};
  _rt152 = builtins_OptionalI_PZcoroCachedStack_E_op__initCover();
  return _rt152;
}


static struct OptionalI_PZcoroCachedStack_E coro___Closure108_op__call(struct list___Closure108 * this) {
  struct OptionalI_PZcoroCachedStack_E _rt153 = {};
  if (this->item != nullptr) {
    struct coro_CachedStack * curr = this->item;
    this->item = this->item->link;
    _rt153 = builtins_SomeI_PZcoroCachedStack_E(curr);
    return _rt153;
  } else {
    _rt153 = builtins_NoneI_PZcoroCachedStack_E();
    return _rt153;
  }
}


static void coro___Closure108_op__init(struct list___Closure108 * this) {
  
}


static void list_ListI_ZcoroCachedStack_E_push(struct list_ListI_ZcoroCachedStack_E * this, struct coro_CachedStack * item) {
  {
    bool _a112 = item->link == nullptr;
    __cxy_assert(_a112, "/home/dev/.cxy/lib/cxy/std/stdlib/list.cxy", 9u, 9u);
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
  struct coro_CachedStack * _rt154 = {};
  struct coro_CachedStack * item = this->_head;
  if (this->_head != nullptr) {
    this->count--;
    this->_head = this->_head->link;
    if (this->_head == nullptr) {
      this->_tail = nullptr;
    }
    item->link = nullptr;
  }
  _rt154 = item;
  return _rt154;
}


static struct list___Closure108 * list_ListI_ZcoroCachedStack_E_op__range(struct list_ListI_ZcoroCachedStack_E * this) {
  struct list___Closure108 * _rt155 = {};
  struct coro_CachedStack * item = this->_head;
  _rt155 = ({
    struct list___Closure108 * __obj109 = (struct list___Closure108 *)__smart_ptr_alloc(sizeof(list___Closure108), nullptr);
    __obj109->item = item;
    __obj109;
  });
  return _rt155;
}

__attribute__((always_inline))
static struct coro_CachedStack * list_ListI_ZcoroCachedStack_E_front(struct list_ListI_ZcoroCachedStack_E * this) {
  struct coro_CachedStack * _rt156 = {};
  if (this->_head == nullptr) {
    return nullptr;
  } else {
    _rt156 = this->_head;
    return _rt156;
  }
}

__attribute__((always_inline))
static struct coro_CachedStack * list_ListI_ZcoroCachedStack_E_back(struct list_ListI_ZcoroCachedStack_E * this) {
  struct coro_CachedStack * _rt157 = {};
  if (this->_tail == nullptr) {
    return nullptr;
  } else {
    _rt157 = this->_tail;
    return _rt157;
  }
}

__attribute__((always_inline))
static uint64_t list_ListI_ZcoroCachedStack_E_size(const struct list_ListI_ZcoroCachedStack_E * this) {
  uint64_t _rt158 = {};
  _rt158 = this->count;
  return _rt158;
}

__attribute__((always_inline))
static bool list_ListI_ZcoroCachedStack_E_empty(const struct list_ListI_ZcoroCachedStack_E * this) {
  bool _rt159 = {};
  _rt159 = this->_head == nullptr;
  return _rt159;
}


static void coro_CoroutineScheduler_op__init(struct coro_CoroutineScheduler * this) {
  this->running = &this->main;
  this->eventLoop = aeCreateEventLoop((void *)this, (int32_t)1024);
}


static void * coro_CoroutineScheduler_allocStack(struct coro_CoroutineScheduler * this) {
  void * _rt160 = {};
  void * ptr = nullptr;
  struct coro_CachedStack * stack = list_ListI_ZcoroCachedStack_E_pop(&this->stacks);
  if (stack != nullptr) {
    ptr = ((void *)stack);
  } else {
    ptr = mmap((void *) {}, coro_stackSize, (int32_t)3, (int32_t)34, (int32_t)-1, (int64_t)0);
  }
  uint8_t * top = ((uint8_t *)ptr) + coro_stackSize;
  _rt160 = (void *)top;
  return _rt160;
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
  Flags _a113 = Flags_AE_FILE_EVENTS | Flags_AE_TIME_EVENTS;
  aeProcessEvents(this->eventLoop, _a113, timeout);
}


static void coro_CoroutineScheduler_eventLoopCallback(struct aeEventLoop * loop, int32_t fd, void * arg, int32_t mask) {
  struct coro_CoroutineScheduler * scheduler = ((struct coro_CoroutineScheduler *)loop->context);
  struct coro_Coroutine * cr = (struct coro_Coroutine *)arg;
  coro_CoroutineScheduler_resume(scheduler, cr, mask);
}


static Status coro_CoroutineScheduler_eventLoopTimerFired(struct aeEventLoop * loop, int64_t id, void * arg) {
  Status _rt161 = {};
  struct coro_CoroutineScheduler * scheduler = __smart_ptr_get((struct coro_CoroutineScheduler *)loop->context);
  struct coro_Coroutine * cr = (struct coro_Coroutine *)arg;
  coro_CoroutineScheduler_resume(scheduler, cr, (int32_t)id);
  __smart_ptr_drop(scheduler);
  return Status_AE_NO_MORE;
}


static int32_t coro_CoroutineScheduler_suspend(struct coro_CoroutineScheduler * this) {
  int32_t _rt162 = {};
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
      _rt162 = this->running->result;
      return _rt162;
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
  struct coro_Coroutine * _rt163 = {};
  void * stack = coro_CoroutineScheduler_allocStack(this);
  struct coro_Coroutine * cr = ((struct coro_Coroutine *)stack) + (-1);
  cr->link = nullptr;
  cr->scheduler = ((void *)this);
  cr->id = this->idGenerator++;
  cr->ready = false;
  cr->name = name;
  coro_CoroutineScheduler_resume(this, this->running, (int32_t)0);
  this->running = cr;
  _rt163 = cr;
  return _rt163;
}


static void coro_CoroutineScheduler_epilogue(struct coro_CoroutineScheduler * this) {
  struct coro_Coroutine * cr = this->running;
  struct coro_Coroutine * sp = cr + 1;
  this->running = nullptr;
  coro_CoroutineScheduler_freeStack(this, (void *)sp);
  coro_CoroutineScheduler_suspend(this);
}


static int32_t coro_CoroutineScheduler_fdWaitWrite(struct coro_CoroutineScheduler * this, int32_t fd, uint64_t timeout) {
  int32_t _rt164 = {};
  Status status = aeCreateFileEvent(this->eventLoop, fd, State_AE_WRITABLE, (Func750)coro_CoroutineScheduler_eventLoopCallback, (void *)this->running, timeout);
  if (status == Status_AE_OK) {
    int32_t result = coro_CoroutineScheduler_suspend(this);
    aeDeleteFileEvent(this->eventLoop, fd, State_AE_WRITABLE);
    _rt164 = result;
    return _rt164;
  }
  _rt164 = status;
  return _rt164;
}


static int32_t coro_CoroutineScheduler_fdWaitRead(struct coro_CoroutineScheduler * this, int32_t fd, uint64_t timeout) {
  int32_t _rt165 = {};
  Status status = aeCreateFileEvent(this->eventLoop, fd, State_AE_READABLE, (Func750)coro_CoroutineScheduler_eventLoopCallback, (void *)this->running, timeout);
  if (status == Status_AE_OK) {
    int32_t result = coro_CoroutineScheduler_suspend(this);
    aeDeleteFileEvent(this->eventLoop, fd, State_AE_READABLE);
    _rt165 = result;
    return _rt165;
  }
  _rt165 = status;
  return _rt165;
}


static void coro_CoroutineScheduler_sleep(struct coro_CoroutineScheduler * this, int64_t ms) {
  if (ms > 0) {
    Status status = aeCreateTimeEvent(this->eventLoop, ms, (Func752)coro_CoroutineScheduler_eventLoopTimerFired, (void *)this->running, (Func754) {});
    {
      bool _a114 = status != Status_AE_ERR;
      __cxy_assert(_a114, "/home/dev/.cxy/lib/cxy/std/stdlib/coro.cxy", 307u, 13u);
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
  struct coro_CoroutineScheduler * _rt166 = {};
  struct coro_CoroutineScheduler * __obj110 = (struct coro_CoroutineScheduler *)__smart_ptr_alloc(sizeof(coro_CoroutineScheduler), coro_CoroutineScheduler_op__destructor_fwd);
  memset(__obj110, 0, sizeof(coro_CoroutineScheduler));
  coro_CoroutineScheduler___defaults_init(__obj110);
  coro_CoroutineScheduler_op__init(__obj110);
  _rt166 = __obj110;
  return _rt166;
}

__attribute__((always_inline))
static struct coro_CoroutineScheduler * coro___get_scheduler() {
  struct coro_CoroutineScheduler * _rt167 = {};
  if (unlikely(coro___cxy_coro_scheduler == nullptr)) {
    coro___cxy_coro_scheduler = coro_CoroutineScheduler_op__initCover();
  }
  _rt167 = coro___cxy_coro_scheduler;
  return _rt167;
}

__attribute__((always_inline))
static int64_t coro___now() {
  int64_t _rt168 = {};
  _rt168 = aeOsTime();
  return _rt168;
}

__attribute__((always_inline))
static int32_t coro___fdWaitRead(int32_t fd, uint64_t timeout) {
  int32_t _rt169 = {};
  struct coro_CoroutineScheduler * _m115 = coro___get_scheduler();
  _rt169 = coro_CoroutineScheduler_fdWaitRead(_m115, fd, timeout);
  return _rt169;
}

__attribute__((always_inline))
static int32_t coro___fdWaitWrite(int32_t fd, uint64_t timeout) {
  int32_t _rt170 = {};
  struct coro_CoroutineScheduler * _m116 = coro___get_scheduler();
  _rt170 = coro_CoroutineScheduler_fdWaitWrite(_m116, fd, timeout);
  return _rt170;
}

__attribute__((always_inline))
static void coro___sleep(int64_t ms) {
  struct coro_CoroutineScheduler * _m117 = coro___get_scheduler();
  coro_CoroutineScheduler_sleep(_m117, ms);
}


static void coro_Mutex_op__init(struct coro_Mutex * this) {
  
}


static void coro_Mutex_lock(struct coro_Mutex * this) {
  if (this->holder == nullptr) {
    struct coro_CoroutineScheduler * _m118 = coro___get_scheduler();
    this->holder = _m118->running;
    return;
  }
  struct coro_CoroutineScheduler * _m119 = coro___get_scheduler();
  list_ListI_ZcoroCoroutine_E_push(&this->waiting, _m119->running);
  struct coro_CoroutineScheduler * _m120 = coro___get_scheduler();
  coro_CoroutineScheduler_suspend(_m120);
}


static bool coro_Mutex_tryLock(struct coro_Mutex * this) {
  bool _rt171 = {};
  if (this->holder == nullptr) {
    struct coro_CoroutineScheduler * _m121 = coro___get_scheduler();
    this->holder = _m121->running;
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
  struct coro_CoroutineScheduler * _m122 = coro___get_scheduler();
  coro_CoroutineScheduler_resume(_m122, next, (int32_t)0);
}

__attribute__((constructor))

static void coro___init_coro() {
  uint64_t _a123 = 256u * 1024u;
  coro_stackSize = coro_stackAlign(_a123, (uint64_t)builtins_SysConfPageSize);
}

/*-----------/home/dev/.cxy/lib/cxy/std/stdlib/os.cxy-----------*/
typedef struct SliceI_Tss_E SliceI_Tss_E;
typedef struct os_Tuple1736 {
  const char* _0;
  const char* _1;
} os_Tuple1736;

struct  SliceI_Tss_E {
  struct os_Tuple1736 * data;
  uint64_t len;
};

typedef struct SliceI_sE SliceI_sE;
struct  SliceI_sE {
  const char* * data;
  uint64_t len;
};

typedef struct os_FileOutputStream os_FileOutputStream;
struct  os_FileOutputStream {
  struct OutputStream_VTable * vtable;
  bool closeOnDestruct;
  int32_t fd;
};

typedef struct os_Union1557 os_Union1557;
typedef struct Void Void;
struct  Void {
};

struct os_Union1557{
  uint32_t tag;
  union {
    struct Void _0;
    struct Exception * _1;
  };
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

typedef int64_t Array1448[3];
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
  Array1448 __glibc_reserved;
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

typedef struct os_Union1546 os_Union1546;
struct os_Union1546{
  uint32_t tag;
  union {
    struct __string _0;
    struct Exception * _1;
  };
};

typedef struct os_Union1572 os_Union1572;
struct os_Union1572{
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

typedef struct os_Union1587 os_Union1587;
struct os_Union1587{
  uint32_t tag;
  union {
    struct os_FileDescriptor _0;
    struct Exception * _1;
  };
};

typedef struct os_Union1611 os_Union1611;
struct os_Union1611{
  uint32_t tag;
  union {
    struct os_FileInputStream * _0;
    struct Exception * _1;
  };
};

typedef struct os_Union1623 os_Union1623;
struct os_Union1623{
  uint32_t tag;
  union {
    struct String * _0;
    struct Exception * _1;
  };
};

typedef char Array1638[4092];
typedef struct os_Union1644 os_Union1644;
struct os_Union1644{
  uint32_t tag;
  union {
    struct os_FileOutputStream * _0;
    struct Exception * _1;
  };
};

typedef struct os_Union1669 os_Union1669;
struct os_Union1669{
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

typedef struct os_Union1686 os_Union1686;
struct os_Union1686{
  uint32_t tag;
  union {
    struct os_Process _0;
    struct Exception * _1;
  };
};

typedef struct OptionalI_Tsi32_E OptionalI_Tsi32_E;
typedef struct Tuple1707 {
  const char* _0;
  int32_t _1;
} Tuple1707;

struct  OptionalI_Tsi32_E {
  bool ok;
  struct Tuple1707 val;
};

typedef struct __Closure318 __Closure318;
struct  __Closure318 {
  int32_t i;
  uint64_t len;
  const char* * data;
};

typedef struct OptionalI_TTss_i32_E OptionalI_TTss_i32_E;
typedef struct Tuple1751 {
  struct os_Tuple1736 _0;
  int32_t _1;
} Tuple1751;

struct  OptionalI_TTss_i32_E {
  bool ok;
  struct Tuple1751 val;
};

typedef struct __Closure322 __Closure322;
struct  __Closure322 {
  int32_t i;
  uint64_t len;
  struct os_Tuple1736 * data;
};

typedef int32_t Array471[2];
extern void exit(int32_t __status);
extern int32_t execvp(const char * __file, const char * * __argv);
extern int32_t dup2(int32_t __fd, int32_t __fd2);
extern int32_t fork();
extern int32_t pipe(int32_t * __pipedes);
static void builtins_SliceI_Tss_E_op__init(struct SliceI_Tss_E * this, struct os_Tuple1736 * data, uint64_t len);
static void builtins_SliceI_sE_op__init(struct SliceI_sE * this, const char* * data, uint64_t len);
extern int32_t pidfd_open(int32_t __pid, uint32_t __flags);
extern int32_t waitpid(int32_t __pid, int32_t * __stat_loc, int32_t __options);
extern int64_t write(int32_t __fd, const void * __buf, uint64_t __n);
static struct OptionalI_u64E os_FileOutputStream_append(struct os_FileOutputStream * this, const void * data, uint64_t size);
static void os_FileOutputStream_op__init(struct os_FileOutputStream * this, int32_t fd, bool closeOnDestruct, bool nonBlocking);
static void os_FileOutputStream___defaults_init(struct os_FileOutputStream * this);
static void os_FileOutputStream_op__destructor_fwd(void * ptr);
static struct os_Union1557 os_FileInputStream_readAllI_RZOutputStream_E(struct os_FileInputStream * this, struct OutputStream * os);
extern int64_t lseek(int32_t __fd, int64_t __offset, int32_t __whence);
extern int64_t read(int32_t __fd, void * __buf, uint64_t __nbytes);
static struct OptionalI_u64E os_FileInputStream_seek(struct os_FileInputStream * this, uint64_t off, os_Seek whence);
static struct OptionalI_u64E os_FileInputStream_read(struct os_FileInputStream * this, void * buf, uint64_t size);
static void os_FileInputStream_op__init(struct os_FileInputStream * this, int32_t fd, bool closeOnDestruct, bool nonBlocking);
static void os_FileInputStream___defaults_init(struct os_FileInputStream * this);
static void os_FileInputStream_op__destructor_fwd(void * ptr);
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
  const char* _rt451 = {};
  _rt451 = this->msg == nullptr? "": builtins_String_str(this->msg);
  return _rt451;
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
  const char* _rt452 = {};
  _rt452 = this->msg == nullptr? "": builtins_String_str(this->msg);
  return _rt452;
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
  int32_t _rt453 = {};
  _rt453 = fs_stat((const char *)path, s);
  return _rt453;
}

__attribute__((always_inline))
static int32_t os_fstat(int32_t fd, struct stat * s) {
  int32_t _rt454 = {};
  _rt454 = fs_fstat(fd, s);
  return _rt454;
}

__attribute__((always_inline))
static int32_t os_lstat(const char* path, struct stat * s) {
  int32_t _rt455 = {};
  _rt455 = fs_lstat((const char *)path, s);
  return _rt455;
}

__attribute__((always_inline))
static bool os_setNonblocking(int32_t fd, bool blocking) {
  bool _rt456 = {};
  int32_t flags = fcntl(fd, 3, 0);
  if (flags == -1) {
    return false;
  }
  flags = (blocking? (flags & ~(2048u)): (flags | 2048));
  _rt456 = (fcntl(fd, 4, flags) == 0);
  return _rt456;
}


static struct os_Union1546 builtins___union_copyI_U_Z__string_ZException__E(struct os_Union1546 * obj) {
  struct os_Union1546 _rt457 = {};
  switch (obj->tag) {
  case 0u: {
    {
      struct __string * y = &obj->_0;
      _rt457 = (struct os_Union1546){.tag = 0, ._0 = *(y)};
      return _rt457;
    }
  }
  case 1u: {
    {
      struct Exception * y = obj->_1;
      _rt457 = (struct os_Union1546){.tag = 1, ._1 = __smart_ptr_get(y)};
      return _rt457;
    }
  }
  default: { unreachable("unhandled-default-case"); }
  }
  
}


static void builtins___union_dctorI_U_Z__string_ZException__E(struct os_Union1546 * obj) {
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
  struct String * _rt458 = {};
  struct String * __obj291 = (struct String *)__smart_ptr_alloc(sizeof(String), builtins_String_op__destructor_fwd);
  memset(__obj291, 0, sizeof(String));
  builtins_String___defaults_init(__obj291);
  builtins_String_op__initI_E(__obj291);
  _rt458 = __obj291;
  return _rt458;
}

__attribute__((always_inline))
static struct os_OSError * os_OSError_op__initCover(struct String * msg) {
  struct os_OSError * _rt459 = {};
  struct os_OSError * __obj292 = (struct os_OSError *)__smart_ptr_alloc(sizeof(os_OSError), os_OSError_op__destructor_fwd);
  memset(__obj292, 0, sizeof(os_OSError));
  os_OSError___defaults_init(__obj292);
  os_OSError_op__init(__obj292, msg);
  _rt459 = __obj292;
  return _rt459;
}

__attribute__((always_inline))
static struct os_Union1546 os_getenv(const char* name, const char* def) {
  struct os_Union1546 _rt460 = {};
  const char* value = (const char*)getenv((const char *)name);
  if (value == nullptr) {
    if (def == nullptr) {
      struct String * sb233 = builtins_String_op__initI_ECover();
      struct OutputStream * _m337 = (struct OutputStream *)sb233;
      struct OutputStream * _m338 = builtins_OutputStream_op__lshiftI_sE(_m337, "environment variable ");
      struct OutputStream * _m339 = builtins_OutputStream_op__lshiftI_sE(_m338, name);
      builtins_OutputStream_op__lshiftI_sE(_m339, " does not exist");
      struct Exception * _ex234 = (struct Exception *)os_OSError_op__initCover(__smart_ptr_get(sb233));
      builtins_Exception_push(_ex234, "os", (const char*) {}, "getenv", "/home/dev/.cxy/lib/cxy/std/stdlib/os.cxy", (uint64_t)59);
      _rt460 = (struct os_Union1546){.tag = 1, ._1 = _ex234};
      __smart_ptr_drop(sb233);
      return _rt460;
    }
    value = def;
  }
  _rt460 = (struct os_Union1546){.tag = 0, ._0 = builtins___string_op__initCoverI_sE(value)};
  return _rt460;
}


static struct os_Union1557 builtins___union_copyI_U_ZVoid_ZException__E(struct os_Union1557 * obj) {
  struct os_Union1557 _rt461 = {};
  switch (obj->tag) {
  case 0u: {
    {
      struct Void * y = &obj->_0;
      _rt461 = (struct os_Union1557){.tag = 0, ._0 = *(y)};
      return _rt461;
    }
  }
  case 1u: {
    {
      struct Exception * y = obj->_1;
      _rt461 = (struct os_Union1557){.tag = 1, ._1 = __smart_ptr_get(y)};
      return _rt461;
    }
  }
  default: { unreachable("unhandled-default-case"); }
  }
  
  _rt461 = (struct os_Union1557){.tag = 0, ._0 = (struct Void){}};
  return _rt461;
}


static void builtins___union_dctorI_U_ZVoid_ZException__E(struct os_Union1557 * obj) {
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
static struct os_Union1557 os_setenv(const char* name, const char* value, bool overwrite) {
  struct os_Union1557 _rt462 = {};
  if (setenv((const char *)name, (const char *)value, (int32_t)(uint8_t)overwrite) != 0) {
    struct String * sb235 = builtins_String_op__initI_ECover();
    const char* _rv293 = builtins_strerr();
    struct OutputStream * _m340 = (struct OutputStream *)sb235;
    struct OutputStream * _m341 = builtins_OutputStream_op__lshiftI_sE(_m340, "setenv ");
    struct OutputStream * _m342 = builtins_OutputStream_op__lshiftI_sE(_m341, name);
    struct OutputStream * _m343 = builtins_OutputStream_op__lshiftI_sE(_m342, "=");
    struct OutputStream * _m344 = builtins_OutputStream_op__lshiftI_sE(_m343, value);
    struct OutputStream * _m345 = builtins_OutputStream_op__lshiftI_sE(_m344, " failed: ");
    builtins_OutputStream_op__lshiftI_sE(_m345, _rv293);
    struct Exception * _ex236 = (struct Exception *)os_OSError_op__initCover(__smart_ptr_get(sb235));
    builtins_Exception_push(_ex236, "os", (const char*) {}, "setenv", "/home/dev/.cxy/lib/cxy/std/stdlib/os.cxy", (uint64_t)68);
    _rt462 = (struct os_Union1557){.tag = 1, ._1 = _ex236};
    __smart_ptr_drop(sb235);
    return _rt462;
  }
  _rt462 = (struct os_Union1557){.tag = 0, ._0 = (struct Void){}};
  return _rt462;
}

__attribute__((always_inline))
static struct os_Union1557 os_unsetenv(const char* name) {
  struct os_Union1557 _rt463 = {};
  if (unsetenv((const char *)name) != 0) {
    struct String * sb237 = builtins_String_op__initI_ECover();
    const char* _rv294 = builtins_strerr();
    struct OutputStream * _m346 = (struct OutputStream *)sb237;
    struct OutputStream * _m347 = builtins_OutputStream_op__lshiftI_sE(_m346, "unsetenv ");
    struct OutputStream * _m348 = builtins_OutputStream_op__lshiftI_sE(_m347, name);
    struct OutputStream * _m349 = builtins_OutputStream_op__lshiftI_sE(_m348, " failed: ");
    builtins_OutputStream_op__lshiftI_sE(_m349, _rv294);
    struct Exception * _ex238 = (struct Exception *)os_OSError_op__initCover(__smart_ptr_get(sb237));
    builtins_Exception_push(_ex238, "os", (const char*) {}, "unsetenv", "/home/dev/.cxy/lib/cxy/std/stdlib/os.cxy", (uint64_t)74);
    _rt463 = (struct os_Union1557){.tag = 1, ._1 = _ex238};
    __smart_ptr_drop(sb237);
    return _rt463;
  }
  _rt463 = (struct os_Union1557){.tag = 0, ._0 = (struct Void){}};
  return _rt463;
}


static struct os_Union1572 builtins___union_copyI_U_u64ZException__E(struct os_Union1572 * obj) {
  struct os_Union1572 _rt464 = {};
  switch (obj->tag) {
  case 0u: {
    {
      uint64_t y = obj->_0;
      _rt464 = (struct os_Union1572){.tag = 0, ._0 = y};
      return _rt464;
    }
  }
  case 1u: {
    {
      struct Exception * y = obj->_1;
      _rt464 = (struct os_Union1572){.tag = 1, ._1 = __smart_ptr_get(y)};
      return _rt464;
    }
  }
  default: { unreachable("unhandled-default-case"); }
  }
  
}


static void builtins___union_dctorI_U_u64ZException__E(struct os_Union1572 * obj) {
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
  struct OutputStream * _rt465 = {};
  builtins_OutputStream_appendSignedInt(this, (int64_t)val);
  _rt465 = this;
  return _rt465;
}

__attribute__((always_inline))
static struct os_IOError * os_IOError_op__initCover(struct String * msg) {
  struct os_IOError * _rt466 = {};
  struct os_IOError * __obj296 = (struct os_IOError *)__smart_ptr_alloc(sizeof(os_IOError), os_IOError_op__destructor_fwd);
  memset(__obj296, 0, sizeof(os_IOError));
  os_IOError___defaults_init(__obj296);
  os_IOError_op__init(__obj296, msg);
  _rt466 = __obj296;
  return _rt466;
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
static struct os_Union1572 os_FileDescriptor_size(struct os_FileDescriptor * this) {
  struct os_Union1572 _rt467 = {};
  struct stat st = (struct stat){};
  if (fs_fstat(this->fd, &st) != 0) {
    struct String * sb239 = builtins_String_op__initI_ECover();
    const char* _rv295 = builtins_strerr();
    struct OutputStream * _m350 = (struct OutputStream *)sb239;
    struct OutputStream * _m351 = builtins_OutputStream_op__lshiftI_sE(_m350, "fstat(");
    struct OutputStream * _m352 = builtins_OutputStream_op__lshiftI_i32E(_m351, this->fd);
    struct OutputStream * _m353 = builtins_OutputStream_op__lshiftI_sE(_m352, ") failed: ");
    builtins_OutputStream_op__lshiftI_sE(_m353, _rv295);
    struct Exception * _ex240 = (struct Exception *)os_IOError_op__initCover(__smart_ptr_get(sb239));
    builtins_Exception_push(_ex240, "os", "FileDescriptor", "size", "/home/dev/.cxy/lib/cxy/std/stdlib/os.cxy", (uint64_t)112);
    _rt467 = (struct os_Union1572){.tag = 1, ._1 = _ex240};
    __smart_ptr_drop(sb239);
    return _rt467;
  }
  _rt467 = (struct os_Union1572){.tag = 0, ._0 = (uint64_t)st.st_size};
  return _rt467;
}

__attribute__((always_inline))
static bool os_FileDescriptor_op__truthy(struct os_FileDescriptor * this) {
  bool _rt468 = {};
  _rt468 = this->fd != -1;
  return _rt468;
}

__attribute__((always_inline))
static struct os_FileDescriptor os_FileDescriptor_op__copy(struct os_FileDescriptor * this) {
  struct os_FileDescriptor _rt469 = {};
  _rt469 = (struct os_FileDescriptor){
    .fd = this->fd,
    .closeAfter = this->closeAfter
  };
  return _rt469;
}


static void os_FileDescriptor_op__destructor(struct os_FileDescriptor * this) {
  os_FileDescriptor_op__deinit(this);
}


static struct os_Union1587 builtins___union_copyI_U_ZosFileDescriptor_ZException__E(struct os_Union1587 * obj) {
  struct os_Union1587 _rt470 = {};
  switch (obj->tag) {
  case 0u: {
    {
      struct os_FileDescriptor * y = &obj->_0;
      _rt470 = (struct os_Union1587){.tag = 0, ._0 = os_FileDescriptor_op__copy(y)};
      return _rt470;
    }
  }
  case 1u: {
    {
      struct Exception * y = obj->_1;
      _rt470 = (struct os_Union1587){.tag = 1, ._1 = __smart_ptr_get(y)};
      return _rt470;
    }
  }
  default: { unreachable("unhandled-default-case"); }
  }
  
}


static void builtins___union_dctorI_U_ZosFileDescriptor_ZException__E(struct os_Union1587 * obj) {
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

__attribute__((always_inline))
static struct os_FileDescriptor os_FileDescriptor_op__initCover(int32_t fd, bool closeAfter) {
  struct os_FileDescriptor _rt471 = {};
  struct os_FileDescriptor __obj298 = (struct os_FileDescriptor){
    .fd = -1,
    .closeAfter = false
  };
  os_FileDescriptor_op__init(&__obj298, fd, closeAfter);
  _rt471 = __obj298;
  return _rt471;
}


static struct os_Union1587 os_open(const char* path, bool nonBlocking, int32_t flags, int32_t mode) {
  struct os_Union1587 _rt472 = {};
  int32_t fd = open((const char *)path, flags, mode);
  if (fd < 0) {
    struct String * sb241 = builtins_String_op__initI_ECover();
    const char* _rv297 = builtins_strerr();
    struct OutputStream * _m354 = (struct OutputStream *)sb241;
    struct OutputStream * _m355 = builtins_OutputStream_op__lshiftI_sE(_m354, "opening file '");
    struct OutputStream * _m356 = builtins_OutputStream_op__lshiftI_sE(_m355, path);
    struct OutputStream * _m357 = builtins_OutputStream_op__lshiftI_sE(_m356, "' failed: ");
    builtins_OutputStream_op__lshiftI_sE(_m357, _rv297);
    struct Exception * _ex242 = (struct Exception *)os_IOError_op__initCover(__smart_ptr_get(sb241));
    builtins_Exception_push(_ex242, "os", (const char*) {}, "open", "/home/dev/.cxy/lib/cxy/std/stdlib/os.cxy", (uint64_t)128);
    _rt472 = (struct os_Union1587){.tag = 1, ._1 = _ex242};
    __smart_ptr_drop(sb241);
    return _rt472;
  }
  if (nonBlocking) {
    os_setNonblocking(fd, false);
  }
  _rt472 = (struct os_Union1587){.tag = 0, ._0 = os_FileDescriptor_op__initCover(fd, true)};
  return _rt472;
}

struct os_InputStream_VTable os_InputStream_vTable = (struct os_InputStream_VTable){
  .read = (os_InputStream_read_t) {},
  .seek = (os_InputStream_seek_t) {}
};

static void os_InputStream___defaults_init(struct os_InputStream * this) {
  this->vtable = &os_InputStream_vTable;
}


static struct os_Union1611 builtins___union_copyI_U_ZosFileInputStream_ZException__E(struct os_Union1611 * obj) {
  struct os_Union1611 _rt473 = {};
  switch (obj->tag) {
  case 0u: {
    {
      struct os_FileInputStream * y = obj->_0;
      _rt473 = (struct os_Union1611){.tag = 0, ._0 = __smart_ptr_get(y)};
      return _rt473;
    }
  }
  case 1u: {
    {
      struct Exception * y = obj->_1;
      _rt473 = (struct os_Union1611){.tag = 1, ._1 = __smart_ptr_get(y)};
      return _rt473;
    }
  }
  default: { unreachable("unhandled-default-case"); }
  }
  
}


static void builtins___union_dctorI_U_ZosFileInputStream_ZException__E(struct os_Union1611 * obj) {
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


static struct os_Union1623 builtins___union_copyI_U_ZString_ZException__E(struct os_Union1623 * obj) {
  struct os_Union1623 _rt474 = {};
  switch (obj->tag) {
  case 0u: {
    {
      struct String * y = obj->_0;
      _rt474 = (struct os_Union1623){.tag = 0, ._0 = __smart_ptr_get(y)};
      return _rt474;
    }
  }
  case 1u: {
    {
      struct Exception * y = obj->_1;
      _rt474 = (struct os_Union1623){.tag = 1, ._1 = __smart_ptr_get(y)};
      return _rt474;
    }
  }
  default: { unreachable("unhandled-default-case"); }
  }
  
}


static void builtins___union_dctorI_U_ZString_ZException__E(struct os_Union1623 * obj) {
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
  struct os_FileInputStream * _rt475 = {};
  struct os_FileInputStream * __obj300 = (struct os_FileInputStream *)__smart_ptr_alloc(sizeof(os_FileInputStream), os_FileInputStream_op__destructor_fwd);
  memset(__obj300, 0, sizeof(os_FileInputStream));
  os_FileInputStream___defaults_init(__obj300);
  os_FileInputStream_op__init(__obj300, fd, closeOnDestruct, nonBlocking);
  _rt475 = __obj300;
  return _rt475;
}


static struct OutputStream * builtins_OutputStream_op__lshiftI_i64E(struct OutputStream * this, const int64_t val) {
  struct OutputStream * _rt476 = {};
  builtins_OutputStream_appendSignedInt(this, val);
  _rt476 = this;
  return _rt476;
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


static struct os_Union1611 os_FileInputStream_open(const char* path, bool nonBlocking, int32_t mode) {
  struct os_Union1611 _rt477 = {};
  int32_t fd = open((const char *)path, 0, mode);
  if (fd < 0) {
    struct String * sb243 = builtins_String_op__initI_ECover();
    const char* _rv299 = builtins_strerr();
    struct OutputStream * _m358 = (struct OutputStream *)sb243;
    struct OutputStream * _m359 = builtins_OutputStream_op__lshiftI_sE(_m358, "opening file '");
    struct OutputStream * _m360 = builtins_OutputStream_op__lshiftI_sE(_m359, path);
    struct OutputStream * _m361 = builtins_OutputStream_op__lshiftI_sE(_m360, "' failed: ");
    builtins_OutputStream_op__lshiftI_sE(_m361, _rv299);
    struct Exception * _ex244 = (struct Exception *)os_IOError_op__initCover(__smart_ptr_get(sb243));
    builtins_Exception_push(_ex244, "os", "FileInputStream", "open", "/home/dev/.cxy/lib/cxy/std/stdlib/os.cxy", (uint64_t)162);
    _rt477 = (struct os_Union1611){.tag = 1, ._1 = _ex244};
    __smart_ptr_drop(sb243);
    return _rt477;
  }
  _rt477 = (struct os_Union1611){.tag = 0, ._0 = os_FileInputStream_op__initCover(fd, true, nonBlocking)};
  return _rt477;
}


static struct OptionalI_u64E os_FileInputStream_read(struct os_FileInputStream * this, void * buf, uint64_t size) {
  struct OptionalI_u64E _rt478 = {};
  if (this->fd == -1) {
    _rt478 = builtins_NoneI_u64E();
    return _rt478;
  }
  int64_t bytes = read(this->fd, buf, size);
  if (bytes == -1) {
    _rt478 = builtins_NoneI_u64E();
    return _rt478;
  }
  _rt478 = builtins_SomeI_u64E((uint64_t)bytes);
  return _rt478;
}


static struct OptionalI_u64E os_FileInputStream_seek(struct os_FileInputStream * this, uint64_t off, os_Seek whence) {
  struct OptionalI_u64E _rt479 = {};
  int64_t pos = lseek(this->fd, (int64_t)off, (int32_t)whence);
  if (pos < 0) {
    _rt479 = builtins_NoneI_u64E();
    return _rt479;
  }
  _rt479 = builtins_SomeI_u64E((uint64_t)pos);
  return _rt479;
}


static struct os_Union1557 os_FileInputStream_readAsyncI_RZOutputStream_u64E(struct os_FileInputStream * this, struct OutputStream * os, uint64_t timeout) {
  struct os_Union1557 _rt480 = {};
  Array1638 buf = {};
  while (true) {
    {
      struct OptionalI_u64E tmp = os_FileInputStream_read(this, (void *)buf, (uint64_t)4092);
      if (!builtins_OptionalI_u64E_op__truthyI_E(&tmp)) {
        if ((__errno_location()[0]) == 11) {
          int32_t ret = coro___fdWaitRead(this->fd, timeout);
          if (ret != State_AE_READABLE) {
            struct String * sb245 = builtins_String_op__initI_ECover();
            const char* _rv301 = builtins_strerr();
            struct OutputStream * _m362 = (struct OutputStream *)sb245;
            struct OutputStream * _m363 = builtins_OutputStream_op__lshiftI_sE(_m362, "Waiting for file ");
            struct OutputStream * _m364 = builtins_OutputStream_op__lshiftI_i32E(_m363, this->fd);
            struct OutputStream * _m365 = builtins_OutputStream_op__lshiftI_sE(_m364, " to be readable failed: ");
            builtins_OutputStream_op__lshiftI_sE(_m365, _rv301);
            struct Exception * _ex246 = (struct Exception *)os_IOError_op__initCover(__smart_ptr_get(sb245));
            builtins_Exception_push(_ex246, "os", "FileInputStream", "readAsync", "/home/dev/.cxy/lib/cxy/std/stdlib/os.cxy", (uint64_t)192);
            _rt480 = (struct os_Union1557){.tag = 1, ._1 = _ex246};
            __smart_ptr_drop(sb245);
            builtins_OptionalI_u64E_op__destructor(&(tmp));
            return _rt480;
          }
          builtins_OptionalI_u64E_op__destructor(&(tmp));
          continue;
        }
        struct String * sb247 = builtins_String_op__initI_ECover();
        const char* _rv302 = builtins_strerr();
        struct OutputStream * _m366 = (struct OutputStream *)sb247;
        struct OutputStream * _m367 = builtins_OutputStream_op__lshiftI_sE(_m366, "reading from file ");
        struct OutputStream * _m368 = builtins_OutputStream_op__lshiftI_i32E(_m367, this->fd);
        struct OutputStream * _m369 = builtins_OutputStream_op__lshiftI_sE(_m368, " failed: ");
        builtins_OutputStream_op__lshiftI_sE(_m369, _rv302);
        struct Exception * _ex248 = (struct Exception *)os_IOError_op__initCover(__smart_ptr_get(sb247));
        builtins_Exception_push(_ex248, "os", "FileInputStream", "readAsync", "/home/dev/.cxy/lib/cxy/std/stdlib/os.cxy", (uint64_t)195);
        _rt480 = (struct os_Union1557){.tag = 1, ._1 = _ex248};
        __smart_ptr_drop(sb247);
        builtins_OptionalI_u64E_op__destructor(&(tmp));
        return _rt480;
      }
      if (builtins_OptionalI_u64E_op__derefI_E(&tmp) == 0) {
        _rt480 = (struct os_Union1557){.tag = 0, ._0 = (struct Void){}};
        builtins_OptionalI_u64E_op__destructor(&(tmp));
        return _rt480;
      }
      uint64_t _a370 = builtins_OptionalI_u64E_op__derefI_E(&tmp);
      os->vtable->append(os, (const void *)buf, _a370);
      builtins_OptionalI_u64E_op__destructor(&(tmp));
    }
    
  }
  _rt480 = (struct os_Union1557){.tag = 0, ._0 = (struct Void){}};
  return _rt480;
}

__attribute__((always_inline))
static struct os_Union1572 os_FileInputStream_readAsyncI_PZ_u64u64E(struct os_FileInputStream * this, void * buf, uint64_t size, uint64_t timeout) {
  struct os_Union1572 _rt481 = {};
  struct MemoryOutputStream * mos = ({
    struct MemoryOutputStream * obj = __builtin_alloca(sizeof(MemoryOutputStream));
    builtins_MemoryOutputStream___defaults_init(obj);;
    builtins_MemoryOutputStream_op__init(obj, buf, size);
    obj;
  });
  struct os_Union1572 _res303 = os_FileInputStream_readAsyncI_PZ_u64u64E(this, (void *)mos, timeout, (uint64_t)0);
  bool ___res303_dflags = true;
  if (_res303.tag == 1u) {
    struct Exception * ex = _res303._1;
    ___res303_dflags = false;
    builtins_Exception_push(ex, "os", "FileInputStream", "readAsync", "/home/dev/.cxy/lib/cxy/std/stdlib/os.cxy", 207u);
    _rt481 = (struct os_Union1572){.tag = 1, ._1 = ex};
    return _rt481;
  }
  _rt481 = (struct os_Union1572){.tag = 0, ._0 = builtins_MemoryOutputStream_size(mos)};
  __CXY_DROP_WITH_FLAGS(___res303_dflags, builtins___union_dctorI_U_u64ZException__E(&(_res303)));
  ___res303_dflags = false;
  return _rt481;
}

__attribute__((always_inline))
static struct os_Union1623 os_FileInputStream_readAsyncI_u64E(struct os_FileInputStream * this, uint64_t timeout) {
  struct os_Union1623 _rt482 = {};
  struct String * str = builtins_String_op__initI_ECover();
  struct os_Union1572 _res304 = os_FileInputStream_readAsyncI_PZ_u64u64E(this, (void *)str, timeout, (uint64_t)0);
  bool ___res304_dflags = true;
  if (_res304.tag == 1u) {
    struct Exception * ex = _res304._1;
    ___res304_dflags = false;
    builtins_Exception_push(ex, "os", "FileInputStream", "readAsync", "/home/dev/.cxy/lib/cxy/std/stdlib/os.cxy", 214u);
    _rt482 = (struct os_Union1623){.tag = 1, ._1 = ex};
    __smart_ptr_drop(str);
    return _rt482;
  }
  _rt482 = (struct os_Union1623){.tag = 0, ._0 = str};
  __CXY_DROP_WITH_FLAGS(___res304_dflags, builtins___union_dctorI_U_u64ZException__E(&(_res304)));
  ___res304_dflags = false;
  return _rt482;
}

__attribute__((always_inline))
static struct os_Union1623 os_FileInputStream_readAllI_E(struct os_FileInputStream * this) {
  struct os_Union1623 _rt483 = {};
  struct stat st = (struct stat){};
  if (fs_fstat(this->fd, &st) != 0) {
    struct String * sb249 = builtins_String_op__initI_ECover();
    const char* _rv305 = builtins_strerr();
    struct OutputStream * _m371 = (struct OutputStream *)sb249;
    struct OutputStream * _m372 = builtins_OutputStream_op__lshiftI_sE(_m371, "fstat(");
    struct OutputStream * _m373 = builtins_OutputStream_op__lshiftI_i32E(_m372, this->fd);
    struct OutputStream * _m374 = builtins_OutputStream_op__lshiftI_sE(_m373, ") failed: ");
    builtins_OutputStream_op__lshiftI_sE(_m374, _rv305);
    struct Exception * _ex250 = (struct Exception *)os_IOError_op__initCover(__smart_ptr_get(sb249));
    builtins_Exception_push(_ex250, "os", "FileInputStream", "readAll", "/home/dev/.cxy/lib/cxy/std/stdlib/os.cxy", (uint64_t)222);
    _rt483 = (struct os_Union1623){.tag = 1, ._1 = _ex250};
    __smart_ptr_drop(sb249);
    return _rt483;
  }
  if (st.st_size > 1048576) {
    struct String * sb251 = builtins_String_op__initI_ECover();
    struct OutputStream * _m375 = (struct OutputStream *)sb251;
    struct OutputStream * _m376 = builtins_OutputStream_op__lshiftI_sE(_m375, "file size(=");
    struct OutputStream * _m377 = builtins_OutputStream_op__lshiftI_i64E(_m376, st.st_size);
    builtins_OutputStream_op__lshiftI_sE(_m377, ") to large (limit: 1mb) to read with this api");
    struct Exception * _ex252 = (struct Exception *)os_IOError_op__initCover(__smart_ptr_get(sb251));
    builtins_Exception_push(_ex252, "os", "FileInputStream", "readAll", "/home/dev/.cxy/lib/cxy/std/stdlib/os.cxy", (uint64_t)225);
    _rt483 = (struct os_Union1623){.tag = 1, ._1 = _ex252};
    __smart_ptr_drop(sb251);
    return _rt483;
  }
  struct String * s = builtins_String_op__initI_ECover();
  bool __s_dflags = true;
  if (!(((st.st_mode) & 61440) == (32768))) {
    struct os_Union1557 _res306 = os_FileInputStream_readAllI_RZOutputStream_E(this, (struct OutputStream *)s);
    bool ___res306_dflags = true;
    if (_res306.tag == 1u) {
      struct Exception * ex = _res306._1;
      ___res306_dflags = false;
      builtins_Exception_push(ex, "os", "FileInputStream", "readAll", "/home/dev/.cxy/lib/cxy/std/stdlib/os.cxy", 230u);
      _rt483 = (struct os_Union1623){.tag = 1, ._1 = ex};
      __CXY_DROP_WITH_FLAGS(__s_dflags, __smart_ptr_drop(s));
      __s_dflags = false;
      return _rt483;
    }
    _rt483 = (struct os_Union1623){.tag = 0, ._0 = s};
    __s_dflags = false;
    __CXY_DROP_WITH_FLAGS(___res306_dflags, builtins___union_dctorI_U_ZVoid_ZException__E(&(_res306)));
    ___res306_dflags = false;
    return _rt483;
  }
  if (st.st_size == 0) {
    _rt483 = (struct os_Union1623){.tag = 0, ._0 = s};
    __s_dflags = false;
    return _rt483;
  }
  char * buf = builtins_String_reserve(s, (uint64_t)st.st_size);
  uint64_t nRead = 0u;
  while (nRead < st.st_size) {
    {
      char * p = buf + nRead;
      int64_t _a378 = st.st_size - nRead;
      struct OptionalI_u64E tmp = os_FileInputStream_read(this, (void *)p, (uint64_t)_a378);
      if (!builtins_OptionalI_u64E_op__truthyI_E(&tmp)) {
        struct String * sb253 = builtins_String_op__initI_ECover();
        const char* _rv307 = builtins_strerr();
        struct OutputStream * _m379 = (struct OutputStream *)sb253;
        struct OutputStream * _m380 = builtins_OutputStream_op__lshiftI_sE(_m379, "error reading file ");
        struct OutputStream * _m381 = builtins_OutputStream_op__lshiftI_i32E(_m380, this->fd);
        struct OutputStream * _m382 = builtins_OutputStream_op__lshiftI_sE(_m381, ": ");
        builtins_OutputStream_op__lshiftI_sE(_m382, _rv307);
        struct Exception * _ex254 = (struct Exception *)os_IOError_op__initCover(__smart_ptr_get(sb253));
        builtins_Exception_push(_ex254, "os", "FileInputStream", "readAll", "/home/dev/.cxy/lib/cxy/std/stdlib/os.cxy", (uint64_t)243);
        _rt483 = (struct os_Union1623){.tag = 1, ._1 = _ex254};
        __smart_ptr_drop(sb253);
        builtins_OptionalI_u64E_op__destructor(&(tmp));
        __CXY_DROP_WITH_FLAGS(__s_dflags, __smart_ptr_drop(s));
        __s_dflags = false;
        return _rt483;
      }
      nRead += builtins_OptionalI_u64E_op__derefI_E(&tmp);
      builtins_OptionalI_u64E_op__destructor(&(tmp));
    }
    
  }
  builtins_String_resize(s, nRead);
  _rt483 = (struct os_Union1623){.tag = 0, ._0 = s};
  __s_dflags = false;
  return _rt483;
}


static struct os_Union1557 os_FileInputStream_readAllI_RZOutputStream_E(struct os_FileInputStream * this, struct OutputStream * os) {
  struct os_Union1557 _rt484 = {};
  Array1638 buf = {};
  while (true) {
    {
      struct OptionalI_u64E tmp = os_FileInputStream_read(this, (void *)buf, (uint64_t)4092);
      if (builtins_OptionalI_u64E_op__derefI_E(&tmp) < 0) {
        struct String * sb255 = builtins_String_op__initI_ECover();
        const char* _rv308 = builtins_strerr();
        struct OutputStream * _m383 = (struct OutputStream *)sb255;
        struct OutputStream * _m384 = builtins_OutputStream_op__lshiftI_sE(_m383, "reading command output failed: ");
        builtins_OutputStream_op__lshiftI_sE(_m384, _rv308);
        struct Exception * _ex256 = (struct Exception *)os_IOError_op__initCover(__smart_ptr_get(sb255));
        builtins_Exception_push(_ex256, "os", "FileInputStream", "readAll", "/home/dev/.cxy/lib/cxy/std/stdlib/os.cxy", (uint64_t)255);
        _rt484 = (struct os_Union1557){.tag = 1, ._1 = _ex256};
        __smart_ptr_drop(sb255);
        builtins_OptionalI_u64E_op__destructor(&(tmp));
        return _rt484;
      }
      if (builtins_OptionalI_u64E_op__derefI_E(&tmp) == 0) {
        _rt484 = (struct os_Union1557){.tag = 0, ._0 = (struct Void){}};
        builtins_OptionalI_u64E_op__destructor(&(tmp));
        return _rt484;
      }
      uint64_t _a385 = builtins_OptionalI_u64E_op__derefI_E(&tmp);
      os->vtable->append(os, (const void *)buf, _a385);
      builtins_OptionalI_u64E_op__destructor(&(tmp));
    }
    
  }
  _rt484 = (struct os_Union1557){.tag = 0, ._0 = (struct Void){}};
  return _rt484;
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


static struct os_Union1644 builtins___union_copyI_U_ZosFileOutputStream_ZException__E(struct os_Union1644 * obj) {
  struct os_Union1644 _rt485 = {};
  switch (obj->tag) {
  case 0u: {
    {
      struct os_FileOutputStream * y = obj->_0;
      _rt485 = (struct os_Union1644){.tag = 0, ._0 = __smart_ptr_get(y)};
      return _rt485;
    }
  }
  case 1u: {
    {
      struct Exception * y = obj->_1;
      _rt485 = (struct os_Union1644){.tag = 1, ._1 = __smart_ptr_get(y)};
      return _rt485;
    }
  }
  default: { unreachable("unhandled-default-case"); }
  }
  
}


static void builtins___union_dctorI_U_ZosFileOutputStream_ZException__E(struct os_Union1644 * obj) {
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
  struct os_FileOutputStream * _rt486 = {};
  struct os_FileOutputStream * __obj310 = (struct os_FileOutputStream *)__smart_ptr_alloc(sizeof(os_FileOutputStream), os_FileOutputStream_op__destructor_fwd);
  memset(__obj310, 0, sizeof(os_FileOutputStream));
  os_FileOutputStream___defaults_init(__obj310);
  os_FileOutputStream_op__init(__obj310, fd, closeOnDestruct, nonBlocking);
  _rt486 = __obj310;
  return _rt486;
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


static struct os_Union1644 os_FileOutputStream_open(const char* path, bool nonBlocking, int32_t flags, int32_t mode) {
  struct os_Union1644 _rt487 = {};
  int32_t fd = open((const char *)path, flags, mode);
  if (fd < 0) {
    struct String * sb257 = builtins_String_op__initI_ECover();
    const char* _rv309 = builtins_strerr();
    struct OutputStream * _m386 = (struct OutputStream *)sb257;
    struct OutputStream * _m387 = builtins_OutputStream_op__lshiftI_sE(_m386, "opening file '");
    struct OutputStream * _m388 = builtins_OutputStream_op__lshiftI_sE(_m387, path);
    struct OutputStream * _m389 = builtins_OutputStream_op__lshiftI_sE(_m388, "' failed: ");
    builtins_OutputStream_op__lshiftI_sE(_m389, _rv309);
    struct Exception * _ex258 = (struct Exception *)os_IOError_op__initCover(__smart_ptr_get(sb257));
    builtins_Exception_push(_ex258, "os", "FileOutputStream", "open", "/home/dev/.cxy/lib/cxy/std/stdlib/os.cxy", (uint64_t)290);
    _rt487 = (struct os_Union1644){.tag = 1, ._1 = _ex258};
    __smart_ptr_drop(sb257);
    return _rt487;
  }
  _rt487 = (struct os_Union1644){.tag = 0, ._0 = os_FileOutputStream_op__initCover(fd, true, nonBlocking)};
  return _rt487;
}


static struct OptionalI_u64E os_FileOutputStream_append(struct os_FileOutputStream * this, const void * data, uint64_t size) {
  struct OptionalI_u64E _rt488 = {};
  if (this->fd == -1) {
    _rt488 = builtins_NoneI_u64E();
    return _rt488;
  }
  int64_t bytes = write(this->fd, data, size);
  if (bytes == -1) {
    _rt488 = builtins_NoneI_u64E();
    return _rt488;
  }
  _rt488 = builtins_SomeI_u64E((uint64_t)bytes);
  return _rt488;
}

__attribute__((always_inline))
static struct OptionalI_u64E os_FileOutputStream_write(struct os_FileOutputStream * this, void * buf, uint64_t size) {
  struct OptionalI_u64E _rt489 = {};
  _rt489 = os_FileOutputStream_append(this, (const void *)buf, size);
  return _rt489;
}


static struct os_Union1572 os_FileOutputStream_writeAsync(struct os_FileOutputStream * this, void * buf, uint64_t size, uint64_t timeout) {
  struct os_Union1572 _rt490 = {};
  uint64_t numWritten = 0u;
  while (numWritten < size) {
    {
      char * _r390 = (((char *)buf) + numWritten);
      char * * p = &_r390;
      uint64_t _a391 = size - numWritten;
      struct OptionalI_u64E tmp = os_FileOutputStream_append(this, (const void *)p, _a391);
      if (!builtins_OptionalI_u64E_op__truthyI_E(&tmp)) {
        if ((__errno_location()[0]) == 11) {
          int32_t ret = coro___fdWaitRead(this->fd, timeout);
          if (ret != State_AE_WRITABLE) {
            struct String * sb259 = builtins_String_op__initI_ECover();
            const char* _rv311 = builtins_strerr();
            struct OutputStream * _m392 = (struct OutputStream *)sb259;
            struct OutputStream * _m393 = builtins_OutputStream_op__lshiftI_sE(_m392, "Waiting for file ");
            struct OutputStream * _m394 = builtins_OutputStream_op__lshiftI_i32E(_m393, this->fd);
            struct OutputStream * _m395 = builtins_OutputStream_op__lshiftI_sE(_m394, " to be writable failed: ");
            builtins_OutputStream_op__lshiftI_sE(_m395, _rv311);
            struct Exception * _ex260 = (struct Exception *)os_IOError_op__initCover(__smart_ptr_get(sb259));
            builtins_Exception_push(_ex260, "os", "FileOutputStream", "writeAsync", "/home/dev/.cxy/lib/cxy/std/stdlib/os.cxy", (uint64_t)318);
            _rt490 = (struct os_Union1572){.tag = 1, ._1 = _ex260};
            __smart_ptr_drop(sb259);
            builtins_OptionalI_u64E_op__destructor(&(tmp));
            return _rt490;
          }
          builtins_OptionalI_u64E_op__destructor(&(tmp));
          continue;
        }
        struct String * sb261 = builtins_String_op__initI_ECover();
        const char* _rv312 = builtins_strerr();
        struct OutputStream * _m396 = (struct OutputStream *)sb261;
        struct OutputStream * _m397 = builtins_OutputStream_op__lshiftI_sE(_m396, "writing to file ");
        struct OutputStream * _m398 = builtins_OutputStream_op__lshiftI_i32E(_m397, this->fd);
        struct OutputStream * _m399 = builtins_OutputStream_op__lshiftI_sE(_m398, " failed: ");
        builtins_OutputStream_op__lshiftI_sE(_m399, _rv312);
        struct Exception * _ex262 = (struct Exception *)os_IOError_op__initCover(__smart_ptr_get(sb261));
        builtins_Exception_push(_ex262, "os", "FileOutputStream", "writeAsync", "/home/dev/.cxy/lib/cxy/std/stdlib/os.cxy", (uint64_t)321);
        _rt490 = (struct os_Union1572){.tag = 1, ._1 = _ex262};
        __smart_ptr_drop(sb261);
        builtins_OptionalI_u64E_op__destructor(&(tmp));
        return _rt490;
      }
      numWritten += builtins_OptionalI_u64E_op__derefI_E(&tmp);
      builtins_OptionalI_u64E_op__destructor(&(tmp));
    }
    
  }
  _rt490 = (struct os_Union1572){.tag = 0, ._0 = numWritten};
  return _rt490;
}


static struct OptionalI_u64E os_FileOutputStream_seek(struct os_FileOutputStream * this, uint64_t off, os_Seek whence) {
  struct OptionalI_u64E _rt491 = {};
  int64_t pos = lseek(this->fd, (int64_t)off, (int32_t)whence);
  if (pos < 0) {
    _rt491 = builtins_NoneI_u64E();
    return _rt491;
  }
  _rt491 = builtins_SomeI_u64E((uint64_t)pos);
  return _rt491;
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


static struct os_Union1669 builtins___union_copyI_U_i32ZException__E(struct os_Union1669 * obj) {
  struct os_Union1669 _rt492 = {};
  switch (obj->tag) {
  case 0u: {
    {
      int32_t y = obj->_0;
      _rt492 = (struct os_Union1669){.tag = 0, ._0 = y};
      return _rt492;
    }
  }
  case 1u: {
    {
      struct Exception * y = obj->_1;
      _rt492 = (struct os_Union1669){.tag = 1, ._1 = __smart_ptr_get(y)};
      return _rt492;
    }
  }
  default: { unreachable("unhandled-default-case"); }
  }
  
}


static void builtins___union_dctorI_U_i32ZException__E(struct os_Union1669 * obj) {
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
  struct os_FileInputStream * _rt493 = {};
  if (this->_stdout == nullptr) {
    __smart_ptr_drop(this->_stdout);
    this->_stdout = os_FileInputStream_op__initCover(this->_fdout, true, true);
    this->_fdout = -1;
  }
  _rt493 = this->_stdout;
  return _rt493;
}

__attribute__((always_inline))
static struct os_FileInputStream * os_Process_stderr(struct os_Process * this) {
  struct os_FileInputStream * _rt494 = {};
  if (this->_stderr == nullptr) {
    __smart_ptr_drop(this->_stderr);
    this->_stderr = os_FileInputStream_op__initCover(this->_fderr, true, true);
    this->_fderr = -1;
  }
  _rt494 = this->_stderr;
  return _rt494;
}

__attribute__((always_inline))
static int32_t os_Process_stdin(struct os_Process * this) {
  int32_t _rt495 = {};
  if (this->_stdin == nullptr) {
    __smart_ptr_drop(this->_stdin);
    this->_stdin = os_FileOutputStream_op__initCover(this->_fdin, true, true);
    this->_fdin = -1;
  }
  _rt495 = this->_fdin;
  return _rt495;
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
  bool _rt496 = {};
  int32_t status = 0;
  int32_t ret = waitpid(this->_pid, &status, 1);
  if (ret < 0) {
    return true;
  }
  _rt496 = ret == this->_pid && ((((&status))[0] & 177) == 0);
  return _rt496;
}


static struct os_Union1669 os_Process_wait(struct os_Process * this) {
  struct os_Union1669 _rt497 = {};
  int32_t status = 0;
  int32_t ret = waitpid(this->_pid, &status, (int32_t)0);
  if (ret < 0) {
    struct String * sb263 = builtins_String_op__initI_ECover();
    const char* _rv313 = builtins_strerr();
    struct OutputStream * _m400 = (struct OutputStream *)sb263;
    struct OutputStream * _m401 = builtins_OutputStream_op__lshiftI_sE(_m400, "wait for pid ");
    struct OutputStream * _m402 = builtins_OutputStream_op__lshiftI_i32E(_m401, this->_pid);
    struct OutputStream * _m403 = builtins_OutputStream_op__lshiftI_sE(_m402, " failed: ");
    builtins_OutputStream_op__lshiftI_sE(_m403, _rv313);
    struct Exception * _ex264 = (struct Exception *)os_IOError_op__initCover(__smart_ptr_get(sb263));
    builtins_Exception_push(_ex264, "os", "Process", "wait", "/home/dev/.cxy/lib/cxy/std/stdlib/os.cxy", (uint64_t)407);
    _rt497 = (struct os_Union1669){.tag = 1, ._1 = _ex264};
    __smart_ptr_drop(sb263);
    return _rt497;
  }
  if (((((&status))[0] & 177) == 0)) {
    _rt497 = (struct os_Union1669){.tag = 0, ._0 = ((((&status))[0] >> 8) & 255)};
    return _rt497;
  }
  _rt497 = (struct os_Union1669){.tag = 0, ._0 = -1};
  return _rt497;
}


static struct os_Union1669 os_Process_waitAsync(struct os_Process * this) {
  struct os_Union1669 _rt498 = {};
  {
    int32_t pidFd = pidfd_open(this->_pid, (uint32_t)2048);
    if (pidFd < 1) {
      if ((__errno_location()[0]) == 22) {
        _rt498 = (struct os_Union1669){.tag = 0, ._0 = -(22)};
        return _rt498;
      }
      struct String * sb265 = builtins_String_op__initI_ECover();
      const char* _rv314 = builtins_strerr();
      struct OutputStream * _m404 = (struct OutputStream *)sb265;
      struct OutputStream * _m405 = builtins_OutputStream_op__lshiftI_sE(_m404, "wait for pid ");
      struct OutputStream * _m406 = builtins_OutputStream_op__lshiftI_i32E(_m405, this->_pid);
      struct OutputStream * _m407 = builtins_OutputStream_op__lshiftI_sE(_m406, " failed: ");
      builtins_OutputStream_op__lshiftI_sE(_m407, _rv314);
      struct Exception * _ex266 = (struct Exception *)os_IOError_op__initCover(__smart_ptr_get(sb265));
      builtins_Exception_push(_ex266, "os", "Process", "waitAsync", "/home/dev/.cxy/lib/cxy/std/stdlib/os.cxy", (uint64_t)425);
      _rt498 = (struct os_Union1669){.tag = 1, ._1 = _ex266};
      __smart_ptr_drop(sb265);
      return _rt498;
    }
    int32_t status = 0;
    int32_t ret = waitpid(this->_pid, &status, 1);
    if (ret < 0) {
      struct String * sb267 = builtins_String_op__initI_ECover();
      const char* _rv315 = builtins_strerr();
      struct OutputStream * _m408 = (struct OutputStream *)sb267;
      struct OutputStream * _m409 = builtins_OutputStream_op__lshiftI_sE(_m408, "wait for pid ");
      struct OutputStream * _m410 = builtins_OutputStream_op__lshiftI_i32E(_m409, this->_pid);
      struct OutputStream * _m411 = builtins_OutputStream_op__lshiftI_sE(_m410, " failed: ");
      builtins_OutputStream_op__lshiftI_sE(_m411, _rv315);
      struct Exception * _ex268 = (struct Exception *)os_IOError_op__initCover(__smart_ptr_get(sb267));
      builtins_Exception_push(_ex268, "os", "Process", "waitAsync", "/home/dev/.cxy/lib/cxy/std/stdlib/os.cxy", (uint64_t)432);
      close(pidFd);
      _rt498 = (struct os_Union1669){.tag = 1, ._1 = _ex268};
      __smart_ptr_drop(sb267);
      return _rt498;
    }
    if (ret == 0) {
      coro___fdWaitRead(pidFd, (uint64_t)0);
      ret = waitpid(this->_pid, &status, 1);
      if (ret < 0) {
        struct String * sb269 = builtins_String_op__initI_ECover();
        const char* _rv316 = builtins_strerr();
        struct OutputStream * _m412 = (struct OutputStream *)sb269;
        struct OutputStream * _m413 = builtins_OutputStream_op__lshiftI_sE(_m412, "wait for pid ");
        struct OutputStream * _m414 = builtins_OutputStream_op__lshiftI_i32E(_m413, this->_pid);
        struct OutputStream * _m415 = builtins_OutputStream_op__lshiftI_sE(_m414, " failed: ");
        builtins_OutputStream_op__lshiftI_sE(_m415, _rv316);
        struct Exception * _ex270 = (struct Exception *)os_IOError_op__initCover(__smart_ptr_get(sb269));
        builtins_Exception_push(_ex270, "os", "Process", "waitAsync", "/home/dev/.cxy/lib/cxy/std/stdlib/os.cxy", (uint64_t)437);
        close(pidFd);
        _rt498 = (struct os_Union1669){.tag = 1, ._1 = _ex270};
        __smart_ptr_drop(sb269);
        return _rt498;
      }
    }
    if (((((&status))[0] & 177) == 0)) {
      close(pidFd);
      _rt498 = (struct os_Union1669){.tag = 0, ._0 = ((((&status))[0] >> 8) & 255)};
      return _rt498;
    }
    close(pidFd);
    _rt498 = (struct os_Union1669){.tag = 0, ._0 = -1};
    return _rt498;
  }
}

__attribute__((always_inline))
static struct os_Process os_Process_op__copy(struct os_Process * this) {
  struct os_Process _rt499 = {};
  _rt499 = (struct os_Process){
    ._stdout = (struct os_FileInputStream *)__smart_ptr_get(this->_stdout),
    ._stderr = (struct os_FileInputStream *)__smart_ptr_get(this->_stderr),
    ._stdin = (struct os_FileOutputStream *)__smart_ptr_get(this->_stdin),
    ._fdin = this->_fdin,
    ._fdout = this->_fdout,
    ._fderr = this->_fderr,
    ._pid = this->_pid
  };
  return _rt499;
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


static struct os_Union1686 builtins___union_copyI_U_ZosProcess_ZException__E(struct os_Union1686 * obj) {
  struct os_Union1686 _rt500 = {};
  switch (obj->tag) {
  case 0u: {
    {
      struct os_Process * y = &obj->_0;
      _rt500 = (struct os_Union1686){.tag = 0, ._0 = os_Process_op__copy(y)};
      return _rt500;
    }
  }
  case 1u: {
    {
      struct Exception * y = obj->_1;
      _rt500 = (struct os_Union1686){.tag = 1, ._1 = __smart_ptr_get(y)};
      return _rt500;
    }
  }
  default: { unreachable("unhandled-default-case"); }
  }
  
}


static void builtins___union_dctorI_U_ZosProcess_ZException__E(struct os_Union1686 * obj) {
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
static void builtins_OptionalI_Tsi32_E_op__initI_E(struct OptionalI_Tsi32_E * this) {
  this->ok = false;
  {
    memset(&this->val, 0, sizeof(struct Tuple1707));
  };
}

__attribute__((always_inline))
static void builtins_OptionalI_Tsi32_E_op__initI_Tsi32_E(struct OptionalI_Tsi32_E * this, struct Tuple1707 value) {
  this->val = value;
  this->ok = true;
}


static void builtins_OptionalI_Tsi32_E_op__destructor(struct OptionalI_Tsi32_E * this) {
  if (this->ok) {
    
  }
}

__attribute__((always_inline))
static struct OptionalI_Tsi32_E builtins_OptionalI_Tsi32_E_op__copy(struct OptionalI_Tsi32_E * this) {
  struct OptionalI_Tsi32_E _rt501 = {};
  _rt501 = (struct OptionalI_Tsi32_E){
    .ok = this->ok,
    .val = this->val
  };
  return _rt501;
}

__attribute__((always_inline))
static bool builtins_OptionalI_Tsi32_E_op__truthyI_E(struct OptionalI_Tsi32_E * this) {
  bool _rt502 = {};
  _rt502 = this->ok;
  return _rt502;
}

__attribute__((always_inline))
static struct Tuple1707 builtins_OptionalI_Tsi32_E_op__derefI_E(struct OptionalI_Tsi32_E * this) {
  struct Tuple1707 _rt503 = {};
  _rt503 = this->val;
  return _rt503;
}

 __attribute__((optnone))
static struct Tuple1707 builtins_OptionalI_Tsi32_E_move(struct OptionalI_Tsi32_E * this) {
  struct Tuple1707 _rt504 = {};
  this->ok = false;
  _rt504 = this->val;
  return _rt504;
}

__attribute__((always_inline))
static struct Tuple1707 builtins_OptionalI_Tsi32_E_op__lor(struct OptionalI_Tsi32_E * this, struct Tuple1707 def) {
  struct Tuple1707 _rt505 = {};
  _rt505 = this->ok? builtins_OptionalI_Tsi32_E_move(this): def;
  return _rt505;
}

__attribute__((always_inline))
static bool builtins_OptionalI_Tsi32_E_op__truthyIc_E(const struct OptionalI_Tsi32_E * this) {
  bool _rt506 = {};
  _rt506 = this->ok;
  return _rt506;
}

__attribute__((always_inline))
static struct Tuple1707 builtins_OptionalI_Tsi32_E_op__derefIc_E(const struct OptionalI_Tsi32_E * this) {
  struct Tuple1707 _rt507 = {};
  _rt507 = this->val;
  return _rt507;
}

__attribute__((always_inline))
static struct OptionalI_Tsi32_E builtins_SomeI_Tsi32_E(struct Tuple1707 value) {
  struct OptionalI_Tsi32_E _rt508 = {};
  _rt508 = (struct OptionalI_Tsi32_E){
    .ok = true,
    .val = value
  };
  return _rt508;
}

__attribute__((always_inline))
static struct OptionalI_Tsi32_E builtins_OptionalI_Tsi32_E_op__initCover() {
  struct OptionalI_Tsi32_E _rt509 = {};
  struct OptionalI_Tsi32_E __obj317 = (struct OptionalI_Tsi32_E){
    .ok = false
  };
  builtins_OptionalI_Tsi32_E_op__initI_E(&__obj317);
  _rt509 = __obj317;
  return _rt509;
}

__attribute__((always_inline))
static struct OptionalI_Tsi32_E builtins_NoneI_Tsi32_E() {
  struct OptionalI_Tsi32_E _rt510 = {};
  _rt510 = builtins_OptionalI_Tsi32_E_op__initCover();
  return _rt510;
}


static struct OptionalI_Tsi32_E os___Closure318_op__call(struct __Closure318 * this) {
  struct OptionalI_Tsi32_E _rt511 = {};
  if (this->i < this->len) {
    struct Tuple1707 _a416 = (struct Tuple1707){
      ._0 = this->data[this->i],
      ._1 = this->i++
    };
    _rt511 = builtins_SomeI_Tsi32_E(_a416);
    return _rt511;
  }
  _rt511 = builtins_NoneI_Tsi32_E();
  return _rt511;
}


static void os___Closure318_op__init(struct __Closure318 * this) {
  
}

__attribute__((always_inline))
static struct SliceI_sE builtins_SliceI_sE_op__initCover(const char* * data, uint64_t len) {
  struct SliceI_sE _rt512 = {};
  struct SliceI_sE __obj320 = (struct SliceI_sE){};
  builtins_SliceI_sE_op__init(&__obj320, data, len);
  _rt512 = __obj320;
  return _rt512;
}


static void builtins_SliceI_sE_op__init(struct SliceI_sE * this, const char* * data, uint64_t len) {
  this->data = data;
  this->len = len;
}

__attribute__((always_inline))
static void builtins_SliceI_sE_op__idx_assign(struct SliceI_sE * this, uint64_t index, const char* data) {
  {
    bool _a417 = index < this->len;
    __cxy_assert(_a417, "__builtins.cxy", 1061u, 9u);
  };
  this->data[index] = data;
}

__attribute__((always_inline))
static const char* builtins_SliceI_sE_op__idxI_u64E(struct SliceI_sE * this, uint64_t index) {
  const char* _rt513 = {};
  {
    bool _a418 = index < this->len;
    __cxy_assert(_a418, "__builtins.cxy", 1067u, 9u);
  };
  _rt513 = this->data[index];
  return _rt513;
}

__attribute__((always_inline))
static const char* builtins_SliceI_sE_op__idxIc_u64E(const struct SliceI_sE * this, uint64_t index) {
  const char* _rt514 = {};
  {
    bool _a419 = index < this->len;
    __cxy_assert(_a419, "__builtins.cxy", 1073u, 9u);
  };
  _rt514 = this->data[index];
  return _rt514;
}


static struct __Closure318 * builtins_SliceI_sE_op__range(const struct SliceI_sE * this) {
  struct __Closure318 * _rt515 = {};
  int32_t i = 0;
  _rt515 = ({
    struct __Closure318 * __obj319 = (struct __Closure318 *)__smart_ptr_alloc(sizeof(__Closure318), nullptr);
    __obj319->i = i;
    __obj319->len = this->len;
    __obj319->data = this->data;
    __obj319;
  });
  return _rt515;
}

__attribute__((always_inline))
static uint64_t builtins_SliceI_sE_size(struct SliceI_sE * this) {
  uint64_t _rt516 = {};
  _rt516 = this->len;
  return _rt516;
}

__attribute__((always_inline))
static struct SliceI_sE builtins_SliceI_sE_view(struct SliceI_sE * this, uint64_t start, int64_t count) {
  struct SliceI_sE _rt517 = {};
  {
    bool _a420 = start <= this->len;
    __cxy_assert(_a420, "__builtins.cxy", 1091u, 9u);
  };
  if (count == -1) {
    count = (int64_t)(this->len - start);
  } else {
    {
      bool _a421 = count >= 0 && count <= (this->len - start);
      __cxy_assert(_a421, "__builtins.cxy", 1095u, 13u);
    };
  }
  const char* * _a422 = this->data + start;
  _rt517 = builtins_SliceI_sE_op__initCover(_a422, (uint64_t)count);
  return _rt517;
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
static void builtins_OptionalI_TTss_i32_E_op__initI_E(struct OptionalI_TTss_i32_E * this) {
  this->ok = false;
  {
    memset(&this->val, 0, sizeof(struct Tuple1751));
  };
}

__attribute__((always_inline))
static void builtins_OptionalI_TTss_i32_E_op__initI_TTss_i32_E(struct OptionalI_TTss_i32_E * this, struct Tuple1751 value) {
  this->val = value;
  this->ok = true;
}


static void builtins_OptionalI_TTss_i32_E_op__destructor(struct OptionalI_TTss_i32_E * this) {
  if (this->ok) {
    
  }
}

__attribute__((always_inline))
static struct OptionalI_TTss_i32_E builtins_OptionalI_TTss_i32_E_op__copy(struct OptionalI_TTss_i32_E * this) {
  struct OptionalI_TTss_i32_E _rt518 = {};
  _rt518 = (struct OptionalI_TTss_i32_E){
    .ok = this->ok,
    .val = this->val
  };
  return _rt518;
}

__attribute__((always_inline))
static bool builtins_OptionalI_TTss_i32_E_op__truthyI_E(struct OptionalI_TTss_i32_E * this) {
  bool _rt519 = {};
  _rt519 = this->ok;
  return _rt519;
}

__attribute__((always_inline))
static struct Tuple1751 builtins_OptionalI_TTss_i32_E_op__derefI_E(struct OptionalI_TTss_i32_E * this) {
  struct Tuple1751 _rt520 = {};
  _rt520 = this->val;
  return _rt520;
}

 __attribute__((optnone))
static struct Tuple1751 builtins_OptionalI_TTss_i32_E_move(struct OptionalI_TTss_i32_E * this) {
  struct Tuple1751 _rt521 = {};
  this->ok = false;
  _rt521 = this->val;
  return _rt521;
}

__attribute__((always_inline))
static struct Tuple1751 builtins_OptionalI_TTss_i32_E_op__lor(struct OptionalI_TTss_i32_E * this, struct Tuple1751 def) {
  struct Tuple1751 _rt522 = {};
  _rt522 = this->ok? builtins_OptionalI_TTss_i32_E_move(this): def;
  return _rt522;
}

__attribute__((always_inline))
static bool builtins_OptionalI_TTss_i32_E_op__truthyIc_E(const struct OptionalI_TTss_i32_E * this) {
  bool _rt523 = {};
  _rt523 = this->ok;
  return _rt523;
}

__attribute__((always_inline))
static struct Tuple1751 builtins_OptionalI_TTss_i32_E_op__derefIc_E(const struct OptionalI_TTss_i32_E * this) {
  struct Tuple1751 _rt524 = {};
  _rt524 = this->val;
  return _rt524;
}

__attribute__((always_inline))
static struct OptionalI_TTss_i32_E builtins_SomeI_TTss_i32_E(struct Tuple1751 value) {
  struct OptionalI_TTss_i32_E _rt525 = {};
  _rt525 = (struct OptionalI_TTss_i32_E){
    .ok = true,
    .val = value
  };
  return _rt525;
}

__attribute__((always_inline))
static struct OptionalI_TTss_i32_E builtins_OptionalI_TTss_i32_E_op__initCover() {
  struct OptionalI_TTss_i32_E _rt526 = {};
  struct OptionalI_TTss_i32_E __obj321 = (struct OptionalI_TTss_i32_E){
    .ok = false
  };
  builtins_OptionalI_TTss_i32_E_op__initI_E(&__obj321);
  _rt526 = __obj321;
  return _rt526;
}

__attribute__((always_inline))
static struct OptionalI_TTss_i32_E builtins_NoneI_TTss_i32_E() {
  struct OptionalI_TTss_i32_E _rt527 = {};
  _rt527 = builtins_OptionalI_TTss_i32_E_op__initCover();
  return _rt527;
}


static struct OptionalI_TTss_i32_E os___Closure322_op__call(struct __Closure322 * this) {
  struct OptionalI_TTss_i32_E _rt528 = {};
  if (this->i < this->len) {
    struct Tuple1751 _a423 = (struct Tuple1751){
      ._0 = this->data[this->i],
      ._1 = this->i++
    };
    _rt528 = builtins_SomeI_TTss_i32_E(_a423);
    return _rt528;
  }
  _rt528 = builtins_NoneI_TTss_i32_E();
  return _rt528;
}


static void os___Closure322_op__init(struct __Closure322 * this) {
  
}

__attribute__((always_inline))
static struct SliceI_Tss_E builtins_SliceI_Tss_E_op__initCover(struct os_Tuple1736 * data, uint64_t len) {
  struct SliceI_Tss_E _rt529 = {};
  struct SliceI_Tss_E __obj324 = (struct SliceI_Tss_E){};
  builtins_SliceI_Tss_E_op__init(&__obj324, data, len);
  _rt529 = __obj324;
  return _rt529;
}


static struct OutputStream * builtins_OutputStream_op__lshiftI_Tss_E(struct OutputStream * this, const struct os_Tuple1736 * val) {
  struct OutputStream * _rt530 = {};
  builtins_OutputStream_appendChar(this, '(');
  builtins_OutputStream_op__lshiftI_sE(this, val->_0);
  builtins_OutputStream_appendStringI_sE(this, ", ");
  builtins_OutputStream_op__lshiftI_sE(this, val->_1);
  builtins_OutputStream_appendChar(this, ')');
  _rt530 = this;
  return _rt530;
}


static void builtins_SliceI_Tss_E_op__init(struct SliceI_Tss_E * this, struct os_Tuple1736 * data, uint64_t len) {
  this->data = data;
  this->len = len;
}

__attribute__((always_inline))
static void builtins_SliceI_Tss_E_op__idx_assign(struct SliceI_Tss_E * this, uint64_t index, struct os_Tuple1736 data) {
  {
    bool _a424 = index < this->len;
    __cxy_assert(_a424, "__builtins.cxy", 1061u, 9u);
  };
  this->data[index] = data;
}

__attribute__((always_inline))
static struct os_Tuple1736 builtins_SliceI_Tss_E_op__idxI_u64E(struct SliceI_Tss_E * this, uint64_t index) {
  struct os_Tuple1736 _rt531 = {};
  {
    bool _a425 = index < this->len;
    __cxy_assert(_a425, "__builtins.cxy", 1067u, 9u);
  };
  _rt531 = this->data[index];
  return _rt531;
}

__attribute__((always_inline))
static struct os_Tuple1736 builtins_SliceI_Tss_E_op__idxIc_u64E(const struct SliceI_Tss_E * this, uint64_t index) {
  struct os_Tuple1736 _rt532 = {};
  {
    bool _a426 = index < this->len;
    __cxy_assert(_a426, "__builtins.cxy", 1073u, 9u);
  };
  _rt532 = this->data[index];
  return _rt532;
}


static struct __Closure322 * builtins_SliceI_Tss_E_op__range(const struct SliceI_Tss_E * this) {
  struct __Closure322 * _rt533 = {};
  int32_t i = 0;
  _rt533 = ({
    struct __Closure322 * __obj323 = (struct __Closure322 *)__smart_ptr_alloc(sizeof(__Closure322), nullptr);
    __obj323->i = i;
    __obj323->len = this->len;
    __obj323->data = this->data;
    __obj323;
  });
  return _rt533;
}

__attribute__((always_inline))
static uint64_t builtins_SliceI_Tss_E_size(struct SliceI_Tss_E * this) {
  uint64_t _rt534 = {};
  _rt534 = this->len;
  return _rt534;
}

__attribute__((always_inline))
static struct SliceI_Tss_E builtins_SliceI_Tss_E_view(struct SliceI_Tss_E * this, uint64_t start, int64_t count) {
  struct SliceI_Tss_E _rt535 = {};
  {
    bool _a427 = start <= this->len;
    __cxy_assert(_a427, "__builtins.cxy", 1091u, 9u);
  };
  if (count == -1) {
    count = (int64_t)(this->len - start);
  } else {
    {
      bool _a428 = count >= 0 && count <= (this->len - start);
      __cxy_assert(_a428, "__builtins.cxy", 1095u, 13u);
    };
  }
  struct os_Tuple1736 * _a429 = this->data + start;
  _rt535 = builtins_SliceI_Tss_E_op__initCover(_a429, (uint64_t)count);
  return _rt535;
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
static struct String * builtins_String_op__initI_sECoverI_sE(const char* str) {
  struct String * _rt536 = {};
  struct String * __obj325 = (struct String *)__smart_ptr_alloc(sizeof(String), builtins_String_op__destructor_fwd);
  memset(__obj325, 0, sizeof(String));
  builtins_String___defaults_init(__obj325);
  builtins_String_op__initI_sE(__obj325, str);
  _rt536 = __obj325;
  return _rt536;
}

__attribute__((always_inline))
static struct os_Process os_Process_op__initCover(int32_t pid, int32_t input, int32_t out, int32_t err) {
  struct os_Process _rt537 = {};
  struct os_Process __obj334 = (struct os_Process){
    ._stdout = (struct os_FileInputStream *)nullptr,
    ._stderr = (struct os_FileInputStream *)nullptr,
    ._stdin = (struct os_FileOutputStream *)nullptr,
    ._pid = (int32_t)0
  };
  os_Process_op__init(&__obj334, pid, input, out, err);
  _rt537 = __obj334;
  return _rt537;
}


static struct os_Union1686 os_execvpe(const char* cmd, struct SliceI_sE argv, struct SliceI_Tss_E env) {
  struct os_Union1686 _rt538 = {};
  Array471 input = {};
  Array471 out = {};
  Array471 err = {};
  uint64_t sz = builtins_SliceI_sE_size(&argv);
  uint64_t _a430 = sz - 1;
  if (sz < 2 || builtins_SliceI_sE_op__idxI_u64E(&argv, _a430) != nullptr) {
    struct String * _a431 = builtins_String_op__initI_sECoverI_sE("arguments `argv` must be null terminated and argv[0] must be the command");
    struct Exception * _ex271 = (struct Exception *)os_IOError_op__initCover(_a431);
    builtins_Exception_push(_ex271, "os", (const char*) {}, "execvpe", "/home/dev/.cxy/lib/cxy/std/stdlib/os.cxy", (uint64_t)455);
    _rt538 = (struct os_Union1686){.tag = 1, ._1 = _ex271};
    return _rt538;
  }
  struct __string _m432 = builtins___string_op__initCoverI_sE(cmd);
  const char* _a433 = builtins_SliceI_sE_op__idxIc_u64E(&argv, (uint64_t)0);
  struct __string _r434 = builtins___string_op__initCoverI_sE(_a433);
  struct __string * _a435 = &_r434;
  if (builtins___string_op__neq(&_m432, (struct __string *)_a435)) {
    struct String * _a436 = builtins_String_op__initI_sECoverI_sE("first entry of `argv` must be the same as the command name");
    struct Exception * _ex272 = (struct Exception *)os_IOError_op__initCover(_a436);
    builtins_Exception_push(_ex272, "os", (const char*) {}, "execvpe", "/home/dev/.cxy/lib/cxy/std/stdlib/os.cxy", (uint64_t)457);
    _rt538 = (struct os_Union1686){.tag = 1, ._1 = _ex272};
    return _rt538;
  }
  if (pipe((int32_t *)input) != 0) {
    struct String * sb273 = builtins_String_op__initI_ECover();
    const char* _rv326 = builtins_strerr();
    struct OutputStream * _m437 = (struct OutputStream *)sb273;
    struct OutputStream * _m438 = builtins_OutputStream_op__lshiftI_sE(_m437, "opening process input stream failed: ");
    builtins_OutputStream_op__lshiftI_sE(_m438, _rv326);
    struct Exception * _ex274 = (struct Exception *)os_IOError_op__initCover(__smart_ptr_get(sb273));
    builtins_Exception_push(_ex274, "os", (const char*) {}, "execvpe", "/home/dev/.cxy/lib/cxy/std/stdlib/os.cxy", (uint64_t)460);
    _rt538 = (struct os_Union1686){.tag = 1, ._1 = _ex274};
    __smart_ptr_drop(sb273);
    return _rt538;
  }
  if (pipe((int32_t *)out) != 0) {
    struct String * sb275 = builtins_String_op__initI_ECover();
    const char* _rv327 = builtins_strerr();
    struct OutputStream * _m439 = (struct OutputStream *)sb275;
    struct OutputStream * _m440 = builtins_OutputStream_op__lshiftI_sE(_m439, "opening process output stream failed: ");
    builtins_OutputStream_op__lshiftI_sE(_m440, _rv327);
    struct Exception * _ex276 = (struct Exception *)os_IOError_op__initCover(__smart_ptr_get(sb275));
    builtins_Exception_push(_ex276, "os", (const char*) {}, "execvpe", "/home/dev/.cxy/lib/cxy/std/stdlib/os.cxy", (uint64_t)462);
    _rt538 = (struct os_Union1686){.tag = 1, ._1 = _ex276};
    __smart_ptr_drop(sb275);
    return _rt538;
  }
  if (pipe((int32_t *)err) != 0) {
    struct String * sb277 = builtins_String_op__initI_ECover();
    const char* _rv328 = builtins_strerr();
    struct OutputStream * _m441 = (struct OutputStream *)sb277;
    struct OutputStream * _m442 = builtins_OutputStream_op__lshiftI_sE(_m441, "opening process error stream failed: ");
    builtins_OutputStream_op__lshiftI_sE(_m442, _rv328);
    struct Exception * _ex278 = (struct Exception *)os_IOError_op__initCover(__smart_ptr_get(sb277));
    builtins_Exception_push(_ex278, "os", (const char*) {}, "execvpe", "/home/dev/.cxy/lib/cxy/std/stdlib/os.cxy", (uint64_t)464);
    _rt538 = (struct os_Union1686){.tag = 1, ._1 = _ex278};
    __smart_ptr_drop(sb277);
    return _rt538;
  }
  int32_t pid = fork();
  if (pid == -1) {
    struct String * sb279 = builtins_String_op__initI_ECover();
    const char* _rv329 = builtins_strerr();
    struct OutputStream * _m443 = (struct OutputStream *)sb279;
    struct OutputStream * _m444 = builtins_OutputStream_op__lshiftI_sE(_m443, "creating a process failed: ");
    builtins_OutputStream_op__lshiftI_sE(_m444, _rv329);
    struct Exception * _ex280 = (struct Exception *)os_IOError_op__initCover(__smart_ptr_get(sb279));
    builtins_Exception_push(_ex280, "os", (const char*) {}, "execvpe", "/home/dev/.cxy/lib/cxy/std/stdlib/os.cxy", (uint64_t)468);
    _rt538 = (struct os_Union1686){.tag = 1, ._1 = _ex280};
    __smart_ptr_drop(sb279);
    return _rt538;
  }
  if (pid == 0) {
    dup2(input[1], 0);
    dup2(out[1], 1);
    dup2(err[1], 2);
    close(input[0]);
    close(out[0]);
    close(err[0]);
    struct __Closure322 * _rg330 = builtins_SliceI_Tss_E_op__range(&env);
    struct OptionalI_TTss_i32_E _it331 = os___Closure322_op__call(_rg330);
    while (!!builtins_OptionalI_TTss_i32_E_op__truthyI_E(&_it331)) {
      {
        struct Tuple1751 tmpVar332 = builtins_OptionalI_TTss_i32_E_op__derefI_E(&_it331);
        struct os_Tuple1736 x = tmpVar332._0;
        setenv((const char *)x._0, (const char *)x._1, (int32_t)1);
      }
      {
        builtins_OptionalI_TTss_i32_E_op__destructor(&(_it331));
        _it331 = os___Closure322_op__call(_rg330);
      }
    }
    int32_t ret = execvp((const char *)cmd, (const char * *)argv.data);
    struct String * sb281 = builtins_String_op__initI_ECover();
    const char* _rv333 = builtins_strerr();
    struct OutputStream * _m445 = (struct OutputStream *)sb281;
    struct OutputStream * _m446 = builtins_OutputStream_op__lshiftI_sE(_m445, "starting ");
    struct OutputStream * _m447 = builtins_OutputStream_op__lshiftI_sE(_m446, cmd);
    struct OutputStream * _m448 = builtins_OutputStream_op__lshiftI_sE(_m447, " failed: ");
    builtins_OutputStream_op__lshiftI_sE(_m448, _rv333);
    struct Exception * _ex282 = (struct Exception *)os_IOError_op__initCover(__smart_ptr_get(sb281));
    builtins_Exception_push(_ex282, "os", (const char*) {}, "execvpe", "/home/dev/.cxy/lib/cxy/std/stdlib/os.cxy", (uint64_t)481);
    _rt538 = (struct os_Union1686){.tag = 1, ._1 = _ex282};
    __smart_ptr_drop(_rg330);
    builtins_OptionalI_TTss_i32_E_op__destructor(&(_it331));
    __smart_ptr_drop(sb281);
    return _rt538;
    exit(ret);
  } else if (pid > 0) {
    close(input[1]);
    close(out[1]);
    close(err[1]);
    _rt538 = (struct os_Union1686){.tag = 0, ._0 = os_Process_op__initCover(pid, input[0], out[0], err[0])};
    return _rt538;
  }
  struct String * sb283 = builtins_String_op__initI_ECover();
  const char* _rv335 = builtins_strerr();
  struct OutputStream * _m449 = (struct OutputStream *)sb283;
  struct OutputStream * _m450 = builtins_OutputStream_op__lshiftI_sE(_m449, "forking process failed: ");
  builtins_OutputStream_op__lshiftI_sE(_m450, _rv335);
  struct Exception * _ex284 = (struct Exception *)os_IOError_op__initCover(__smart_ptr_get(sb283));
  builtins_Exception_push(_ex284, "os", (const char*) {}, "execvpe", "/home/dev/.cxy/lib/cxy/std/stdlib/os.cxy", (uint64_t)490);
  _rt538 = (struct os_Union1686){.tag = 1, ._1 = _ex284};
  __smart_ptr_drop(sb283);
  return _rt538;
}

__attribute__((always_inline))
static struct os_Union1686 os_execvp(const char* cmd, struct SliceI_sE argv) {
  struct os_Union1686 _rt539 = {};
  struct SliceI_Tss_E env = builtins_SliceI_Tss_E_op__initCover((struct os_Tuple1736 *) {}, (uint64_t)0);
  struct os_Union1686 _res336 = os_execvpe(cmd, argv, env);
  bool ___res336_dflags = true;
  if (_res336.tag == 1u) {
    struct Exception * ex = _res336._1;
    ___res336_dflags = false;
    builtins_Exception_push(ex, "os", (const char*) {}, "execvp", "/home/dev/.cxy/lib/cxy/std/stdlib/os.cxy", 496u);
    _rt539 = (struct os_Union1686){.tag = 1, ._1 = ex};
    return _rt539;
  }
  _rt539 = (struct os_Union1686){.tag = 0, ._0 = _res336._0};
  ___res336_dflags = false;
  return _rt539;
}


/*-----------/home/dev/.cxy/lib/cxy/std/stdlib/base64.cxy-----------*/
typedef struct base64_Base64Error base64_Base64Error;
struct  base64_Base64Error {
  struct Exception_VTable * vtable;
  const char* name;
  struct StackTrace stackTrace;
  const char* msg;
};

typedef uint8_t Array1794[256];
static const char* base64_Base64Error_what(struct base64_Base64Error * this);
const char* base64_b64table = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
Array1794 base64_ASCII_LOOKUP = (Array1794){64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 62u, 64u, 64u, 64u, 63u, 52u, 53u, 54u, 55u, 56u, 57u, 58u, 59u, 60u, 61u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 0u, 1u, 2u, 3u, 4u, 5u, 6u, 7u, 8u, 9u, 10u, 11u, 12u, 13u, 14u, 15u, 16u, 17u, 18u, 19u, 20u, 21u, 22u, 23u, 24u, 25u, 64u, 64u, 64u, 64u, 64u, 64u, 26u, 27u, 28u, 29u, 30u, 31u, 32u, 33u, 34u, 35u, 36u, 37u, 38u, 39u, 40u, 41u, 42u, 43u, 44u, 45u, 46u, 47u, 48u, 49u, 50u, 51u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u, 64u};

static void base64_encodeBuffer(struct OutputStream * os, const void * data, uint64_t size) {
  const uint8_t * p = (const uint8_t *)data;
  uint64_t i = 0u;
  while (size >= 3) {
    {
      int16_t _idx546 = ((p[i] & 252) >> 2);
      os->vtable->append(os, (const void *)&base64_b64table[_idx546], (uint64_t)1);
      uint8_t h = (p[i++] & 3) << 4;
      int16_t _idx547 = h | ((p[i] & 240) >> 4);
      os->vtable->append(os, (const void *)&base64_b64table[_idx547], (uint64_t)1);
      h = (p[i++] & 15) << 2;
      int16_t _idx548 = h | ((p[i] & 192) >> 6);
      os->vtable->append(os, (const void *)&base64_b64table[_idx548], (uint64_t)1);
      uint8_t _idx549 = (p[i++] & 63);
      os->vtable->append(os, (const void *)&base64_b64table[_idx549], (uint64_t)1);
      size -= 3;
    }
    
  }
  if (size == 1) {
    int16_t _idx550 = ((p[i] & 252) >> 2);
    os->vtable->append(os, (const void *)&base64_b64table[_idx550], (uint64_t)1);
    uint8_t h = (p[i++] & 3) << 4;
    os->vtable->append(os, (const void *)&base64_b64table[h], (uint64_t)1);
    builtins_OutputStream_op__lshiftI_sE(os, "==");
  } else if (size == 2) {
    int16_t _idx551 = ((p[i] & 252) >> 2);
    os->vtable->append(os, (const void *)&base64_b64table[_idx551], (uint64_t)1);
    uint8_t h = (p[i++] & 3) << 4;
    int16_t _idx552 = h | ((p[i] & 240) >> 4);
    os->vtable->append(os, (const void *)&base64_b64table[_idx552], (uint64_t)1);
    h = (p[i] & 15) << 2;
    os->vtable->append(os, (const void *)&base64_b64table[h], (uint64_t)1);
    builtins_OutputStream_op__lshiftI_sE(os, "=");
  }
}

struct Exception_VTable base64_Base64Error_vTable = (struct Exception_VTable){
  .what = (builtins_Exception_what_t)base64_Base64Error_what
};

static void base64_Base64Error_op__init(struct base64_Base64Error * this, const char* msg) {
  builtins_Exception_op__init((struct Exception *)this, "Base64Error");
  this->msg = msg;
}


static const char* base64_Base64Error_what(struct base64_Base64Error * this) {
  const char* _rt559 = {};
  _rt559 = this->msg;
  return _rt559;
}


static void base64_Base64Error_op__destructor(struct base64_Base64Error * this) {
  builtins_Exception_op__destructor((struct Exception *)this);
}


static void base64_Base64Error_op__destructor_fwd(void * ptr) {
  base64_Base64Error_op__destructor((struct base64_Base64Error *)ptr);
}


static void base64_Base64Error___defaults_init(struct base64_Base64Error * this) {
  builtins_Exception___defaults_init(this);
  this->vtable = &base64_Base64Error_vTable;
}

__attribute__((always_inline))
static struct base64_Base64Error * base64_Base64Error_op__initCover(const char* msg) {
  struct base64_Base64Error * _rt560 = {};
  struct base64_Base64Error * __obj545 = (struct base64_Base64Error *)__smart_ptr_alloc(sizeof(base64_Base64Error), base64_Base64Error_op__destructor_fwd);
  memset(__obj545, 0, sizeof(base64_Base64Error));
  base64_Base64Error___defaults_init(__obj545);
  base64_Base64Error_op__init(__obj545, msg);
  _rt560 = __obj545;
  return _rt560;
}


static struct os_Union1557 base64_decodeBuffer(struct OutputStream * os, const void * data, uint64_t size) {
  struct os_Union1557 _rt561 = {};
  uint64_t sz = size;
  uint64_t i = 0u;
  const uint8_t * p = (const uint8_t *)data;
  while (sz > 4) {
    {
      const uint8_t * it = p + i;
      if (base64_ASCII_LOOKUP[it[0]] == 64 || base64_ASCII_LOOKUP[it[1]] == 64 || base64_ASCII_LOOKUP[it[2]] == 64 || base64_ASCII_LOOKUP[it[3]] == 64) {
        struct Exception * _ex543 = (struct Exception *)base64_Base64Error_op__initCover("base64::decode - invalid base64 encoded string passed");
        builtins_Exception_push(_ex543, "base64", (const char*) {}, "decodeBuffer", "/home/dev/.cxy/lib/cxy/std/stdlib/base64.cxy", (uint64_t)97);
        _rt561 = (struct os_Union1557){.tag = 1, ._1 = _ex543};
        return _rt561;
      }
      char _a553 = (char)((base64_ASCII_LOOKUP[it[0]] << 2 | base64_ASCII_LOOKUP[it[1]] >> 4));
      builtins_OutputStream_op__lshiftI_cE(os, _a553);
      char _a554 = (char)((base64_ASCII_LOOKUP[it[1]] << 4 | base64_ASCII_LOOKUP[it[2]] >> 2));
      builtins_OutputStream_op__lshiftI_cE(os, _a554);
      char _a555 = (char)((base64_ASCII_LOOKUP[it[2]] << 6 | base64_ASCII_LOOKUP[it[3]]));
      builtins_OutputStream_op__lshiftI_cE(os, _a555);
      sz -= 4;
      i += 4;
    }
    
  }
  const uint8_t * it = p + i;
  i = 0;
  while (i < 4 && (p[i] != 61u) && base64_ASCII_LOOKUP[it[i]] != 64) {
    {
      i++;
    }
    
  }
  if ((sz - i) != 0 && (it[i] != 61u)) {
    struct Exception * _ex544 = (struct Exception *)base64_Base64Error_op__initCover("base64::decode - invalid base64 encoded string passed");
    builtins_Exception_push(_ex544, "base64", (const char*) {}, "decodeBuffer", "/home/dev/.cxy/lib/cxy/std/stdlib/base64.cxy", (uint64_t)114);
    _rt561 = (struct os_Union1557){.tag = 1, ._1 = _ex544};
    return _rt561;
  }
  sz -= 4 - i;
  if (sz > 1) {
    char _a556 = (char)(base64_ASCII_LOOKUP[it[0]] << 2 | base64_ASCII_LOOKUP[it[1]] >> 4);
    builtins_OutputStream_op__lshiftI_cE(os, _a556);
  }
  if (sz > 2) {
    char _a557 = (char)(base64_ASCII_LOOKUP[it[1]] << 4 | base64_ASCII_LOOKUP[it[2]] >> 2);
    builtins_OutputStream_op__lshiftI_cE(os, _a557);
  }
  if (sz > 3) {
    char _a558 = (char)(base64_ASCII_LOOKUP[it[2]] << 6 | base64_ASCII_LOOKUP[it[3]]);
    builtins_OutputStream_op__lshiftI_cE(os, _a558);
  }
  _rt561 = (struct os_Union1557){.tag = 0, ._0 = (struct Void){}};
  return _rt561;
}


/*-----------/home/dev/.cxy/lib/cxy/std/stdlib/json.cxy-----------*/
typedef struct json_JSONParser json_JSONParser;
struct  json_JSONParser {
  struct __string data;
  uint32_t off;
  uint32_t line;
  uint32_t col;
};

typedef struct json_JSONParserError json_JSONParserError;
struct  json_JSONParserError {
  struct Exception_VTable * vtable;
  const char* name;
  struct StackTrace stackTrace;
  struct String * msg;
};

typedef struct json_Union1827 json_Union1827;
struct json_Union1827{
  uint32_t tag;
  union {
    bool _0;
    struct Exception * _1;
  };
};

typedef struct json_Tuple1851 {
  uint32_t _0;
  uint32_t _1;
} json_Tuple1851;

static bool json_JSONParser_done(struct json_JSONParser * this);
static const char* json_JSONParserError_what(struct json_JSONParserError * this);
struct Exception_VTable json_JSONParserError_vTable = (struct Exception_VTable){
  .what = (builtins_Exception_what_t)json_JSONParserError_what
};

static void json_JSONParserError_op__init(struct json_JSONParserError * this, struct String * msg) {
  builtins_Exception_op__init((struct Exception *)this, "JSONParserError");
  __smart_ptr_drop(this->msg);
  this->msg = __smart_ptr_get(msg);
  __smart_ptr_drop(msg);
}


static const char* json_JSONParserError_what(struct json_JSONParserError * this) {
  const char* _rt608 = {};
  _rt608 = (this->msg != nullptr)? builtins_String_str(this->msg): "";
  return _rt608;
}


static void json_JSONParserError_op__destructor(struct json_JSONParserError * this) {
  builtins_Exception_op__destructor((struct Exception *)this);
  __smart_ptr_drop(this->msg);
  *(&this->msg) = nullptr;
}


static void json_JSONParserError_op__destructor_fwd(void * ptr) {
  json_JSONParserError_op__destructor((struct json_JSONParserError *)ptr);
}


static void json_JSONParserError___defaults_init(struct json_JSONParserError * this) {
  builtins_Exception___defaults_init(this);
  this->vtable = &json_JSONParserError_vTable;
}


static struct json_Union1827 builtins___union_copyI_U_bZException__E(struct json_Union1827 * obj) {
  struct json_Union1827 _rt609 = {};
  switch (obj->tag) {
  case 0u: {
    {
      bool y = obj->_0;
      _rt609 = (struct json_Union1827){.tag = 0, ._0 = y};
      return _rt609;
    }
  }
  case 1u: {
    {
      struct Exception * y = obj->_1;
      _rt609 = (struct json_Union1827){.tag = 1, ._1 = __smart_ptr_get(y)};
      return _rt609;
    }
  }
  default: { unreachable("unhandled-default-case"); }
  }
  
}


static void builtins___union_dctorI_U_bZException__E(struct json_Union1827 * obj) {
  switch (obj->tag) {
  case 0u: {
    {
      bool y = obj->_0;
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


static struct OutputStream * builtins_OutputStream_op__lshiftI_u32E(struct OutputStream * this, const uint32_t val) {
  struct OutputStream * _rt610 = {};
  builtins_OutputStream_appendSignedInt(this, (int64_t)val);
  _rt610 = this;
  return _rt610;
}

__attribute__((always_inline))
static struct json_JSONParserError * json_JSONParserError_op__initCover(struct String * msg) {
  struct json_JSONParserError * _rt611 = {};
  struct json_JSONParserError * __obj576 = (struct json_JSONParserError *)__smart_ptr_alloc(sizeof(json_JSONParserError), json_JSONParserError_op__destructor_fwd);
  memset(__obj576, 0, sizeof(json_JSONParserError));
  json_JSONParserError___defaults_init(__obj576);
  json_JSONParserError_op__init(__obj576, msg);
  _rt611 = __obj576;
  return _rt611;
}


static struct OutputStream * builtins_OutputStream_op__lshiftI_Z__string_E(struct OutputStream * this, const struct __string * val) {
  struct OutputStream * _rt612 = {};
  builtins_OutputStream_appendStringI_cRZ__string_E(this, val);
  _rt612 = this;
  return _rt612;
}


static void json_JSONParser_op__init(struct json_JSONParser * this, struct __string data) {
  this->data = data;
}


static void json_JSONParser_advance(struct json_JSONParser * this) {
  this->off++;
  this->col++;
  if (builtins___string_op__idx(&this->data, (int64_t)this->off) == '\n') {
    this->line++;
    this->col = 1;
  }
}


static void json_JSONParser_skipWhitespace(struct json_JSONParser * this) {
  const char* p = builtins___string_str(&this->data);
  while (!json_JSONParser_done(this) && (isspace((int32_t)p[this->off]) != 0)) {
    {
      json_JSONParser_advance(this);
    }
    
  }
}

__attribute__((always_inline))
static bool json_JSONParser_consumeChar(struct json_JSONParser * this, char c) {
  bool _rt613 = {};
  json_JSONParser_skipWhitespace(this);
  if (builtins___string_op__idx(&this->data, (int64_t)this->off) == c) {
    json_JSONParser_advance(this);
    return true;
  }
  return false;
}

__attribute__((always_inline))
static bool json_JSONParser_done(struct json_JSONParser * this) {
  bool _rt614 = {};
  _rt614 = this->off >= builtins___string_size(&this->data);
  return _rt614;
}


static struct os_Union1546 json_JSONParser_expectString(struct json_JSONParser * this) {
  struct os_Union1546 _rt615 = {};
  json_JSONParser_skipWhitespace(this);
  if (builtins___string_op__idx(&this->data, (int64_t)this->off) != '\"') {
    struct String * sb562 = builtins_String_op__initI_ECover();
    struct OutputStream * _m578 = (struct OutputStream *)sb562;
    struct OutputStream * _m579 = builtins_OutputStream_op__lshiftI_u32E(_m578, this->line);
    struct OutputStream * _m580 = builtins_OutputStream_op__lshiftI_sE(_m579, ":");
    struct OutputStream * _m581 = builtins_OutputStream_op__lshiftI_u32E(_m580, this->col);
    builtins_OutputStream_op__lshiftI_sE(_m581, " - expecting a string start token '\"'");
    struct Exception * _ex563 = (struct Exception *)json_JSONParserError_op__initCover(__smart_ptr_get(sb562));
    builtins_Exception_push(_ex563, "json", "JSONParser", "expectString", "/home/dev/.cxy/lib/cxy/std/stdlib/json.cxy", (uint64_t)125);
    _rt615 = (struct os_Union1546){.tag = 1, ._1 = _ex563};
    __smart_ptr_drop(sb562);
    return _rt615;
  }
  json_JSONParser_advance(this);
  uint32_t start = this->off;
  const char* p = builtins___string_str(&this->data);
  while (!json_JSONParser_done(this) && p[this->off] != '\0') {
    {
      uint32_t _idx582 = this->off + 1;
      if (p[this->off] == '\\' && p[_idx582] == '\"') {
        json_JSONParser_advance(this);
        json_JSONParser_advance(this);
        continue;
      }
      if (p[this->off] == '\"') {
        break;
      }
      json_JSONParser_advance(this);
    }
    
  }
  if (p[this->off] != '\"') {
    struct String * sb564 = builtins_String_op__initI_ECover();
    struct OutputStream * _m583 = (struct OutputStream *)sb564;
    struct OutputStream * _m584 = builtins_OutputStream_op__lshiftI_u32E(_m583, this->line);
    struct OutputStream * _m585 = builtins_OutputStream_op__lshiftI_sE(_m584, ":");
    struct OutputStream * _m586 = builtins_OutputStream_op__lshiftI_u32E(_m585, this->col);
    builtins_OutputStream_op__lshiftI_sE(_m586, " - expecting a '\"' to terminate the string");
    struct Exception * _ex565 = (struct Exception *)json_JSONParserError_op__initCover(__smart_ptr_get(sb564));
    builtins_Exception_push(_ex565, "json", "JSONParser", "expectString", "/home/dev/.cxy/lib/cxy/std/stdlib/json.cxy", (uint64_t)141);
    _rt615 = (struct os_Union1546){.tag = 1, ._1 = _ex565};
    __smart_ptr_drop(sb564);
    return _rt615;
  }
  uint32_t _a587 = this->off - start;
  struct __string str = builtins___string_substr(&this->data, (uint64_t)start, (int64_t)_a587);
  json_JSONParser_advance(this);
  _rt615 = (struct os_Union1546){.tag = 0, ._0 = str};
  return _rt615;
}

__attribute__((always_inline))
static struct os_Union1546 json_JSONParser_expectKey(struct json_JSONParser * this) {
  struct os_Union1546 _rt616 = {};
  struct os_Union1546 _res577 = json_JSONParser_expectString(this);
  bool ___res577_dflags = true;
  if (_res577.tag == 1u) {
    struct Exception * ex = _res577._1;
    ___res577_dflags = false;
    builtins_Exception_push(ex, "json", "JSONParser", "expectKey", "/home/dev/.cxy/lib/cxy/std/stdlib/json.cxy", 148u);
    _rt616 = (struct os_Union1546){.tag = 1, ._1 = ex};
    return _rt616;
  }
  _rt616 = (struct os_Union1546){.tag = 0, ._0 = _res577._0};
  ___res577_dflags = false;
  return _rt616;
}


static struct json_Union1827 json_JSONParser_expectBool(struct json_JSONParser * this) {
  struct json_Union1827 _rt617 = {};
  json_JSONParser_skipWhitespace(this);
  uint32_t l = this->line;
  uint32_t c = this->col;
  uint32_t start = this->off;
  const char* p = builtins___string_str(&this->data);
  while (!json_JSONParser_done(this) && (isalpha((int32_t)p[this->off]) != 0)) {
    {
      json_JSONParser_advance(this);
    }
    
  }
  uint32_t _a588 = this->off - start;
  struct __string str = builtins___string_substr(&this->data, (uint64_t)start, (int64_t)_a588);
  struct __string _r589 = builtins___string_op__initCoverI_sE("true");
  struct __string * _a590 = &_r589;
  if (builtins___string_op__eq(&str, (struct __string *)_a590)) {
    _rt617 = (struct json_Union1827){.tag = 0, ._0 = true};
    return _rt617;
  }
  struct __string _r591 = builtins___string_op__initCoverI_sE("false");
  struct __string * _a592 = &_r591;
  if (builtins___string_op__eq(&str, (struct __string *)_a592)) {
    _rt617 = (struct json_Union1827){.tag = 0, ._0 = false};
    return _rt617;
  }
  struct String * sb566 = builtins_String_op__initI_ECover();
  struct OutputStream * _m593 = (struct OutputStream *)sb566;
  struct OutputStream * _m594 = builtins_OutputStream_op__lshiftI_u32E(_m593, l);
  struct OutputStream * _m595 = builtins_OutputStream_op__lshiftI_sE(_m594, ":");
  struct OutputStream * _m596 = builtins_OutputStream_op__lshiftI_u32E(_m595, c);
  struct OutputStream * _m597 = builtins_OutputStream_op__lshiftI_sE(_m596, " - expecting a boolean value (true|false) got '");
  struct OutputStream * _m598 = builtins_OutputStream_op__lshiftI_Z__string_E(_m597, (const struct __string *)&str);
  builtins_OutputStream_op__lshiftI_sE(_m598, "'");
  struct Exception * _ex567 = (struct Exception *)json_JSONParserError_op__initCover(__smart_ptr_get(sb566));
  builtins_Exception_push(_ex567, "json", "JSONParser", "expectBool", "/home/dev/.cxy/lib/cxy/std/stdlib/json.cxy", (uint64_t)165);
  _rt617 = (struct json_Union1827){.tag = 1, ._1 = _ex567};
  __smart_ptr_drop(sb566);
  return _rt617;
}


static char json_JSONParser_peekChar(struct json_JSONParser * this) {
  char _rt618 = {};
  json_JSONParser_skipWhitespace(this);
  if (json_JSONParser_done(this)) {
    return '\0';
  }
  _rt618 = builtins___string_op__idx(&this->data, (int64_t)this->off);
  return _rt618;
}


static struct os_Union1557 json_JSONParser_expectChar(struct json_JSONParser * this, char c) {
  struct os_Union1557 _rt619 = {};
  json_JSONParser_skipWhitespace(this);
  if (json_JSONParser_done(this) || builtins___string_op__idx(&this->data, (int64_t)this->off) != c) {
    struct String * sb572 = builtins_String_op__initI_ECover();
    struct OutputStream * _m599 = (struct OutputStream *)sb572;
    struct OutputStream * _m600 = builtins_OutputStream_op__lshiftI_u32E(_m599, this->line);
    struct OutputStream * _m601 = builtins_OutputStream_op__lshiftI_sE(_m600, ":");
    struct OutputStream * _m602 = builtins_OutputStream_op__lshiftI_u32E(_m601, this->col);
    struct OutputStream * _m603 = builtins_OutputStream_op__lshiftI_sE(_m602, " - expected character '");
    struct OutputStream * _m604 = builtins_OutputStream_op__lshiftI_cE(_m603, c);
    builtins_OutputStream_op__lshiftI_sE(_m604, "' not found");
    struct Exception * _ex573 = (struct Exception *)json_JSONParserError_op__initCover(__smart_ptr_get(sb572));
    builtins_Exception_push(_ex573, "json", "JSONParser", "expectChar", "/home/dev/.cxy/lib/cxy/std/stdlib/json.cxy", (uint64_t)220);
    _rt619 = (struct os_Union1557){.tag = 1, ._1 = _ex573};
    __smart_ptr_drop(sb572);
    return _rt619;
  }
  json_JSONParser_advance(this);
  _rt619 = (struct os_Union1557){.tag = 0, ._0 = (struct Void){}};
  return _rt619;
}


static bool json_JSONParser_matchNull(struct json_JSONParser * this) {
  bool _rt620 = {};
  json_JSONParser_skipWhitespace(this);
  uint32_t end = this->off + 4;
  struct __string _m605 = builtins___string_substr(&this->data, (uint64_t)this->off, (int64_t)4);
  struct __string _r606 = builtins___string_op__initCoverI_sE("null");
  struct __string * _a607 = &_r606;
  if (end > builtins___string_size(&this->data) || builtins___string_op__neq(&_m605, (struct __string *)_a607)) {
    return false;
  }
  this->off = end;
  return true;
}

__attribute__((always_inline))
static struct json_Tuple1851 json_JSONParser_tag(struct json_JSONParser * this) {
  struct json_Tuple1851 _rt621 = {};
  _rt621 = (struct json_Tuple1851){
    ._0 = this->line,
    ._1 = this->col
  };
  return _rt621;
}


static void json_JSONParser___defaults_init(struct json_JSONParser * this) {
  this->off = 0u;
  this->line = 1u;
  this->col = 1u;
}


/*-----------/home/dev/.cxy/lib/cxy/std/stdlib/time.cxy-----------*/
typedef struct tm _tm;
struct  tm {
  int32_t tm_sec;
  int32_t tm_min;
  int32_t tm_hour;
  int32_t tm_mday;
  int32_t tm_mon;
  int32_t tm_year;
  int32_t tm_wday;
  int32_t tm_yday;
  int32_t tm_isdst;
  int64_t tm_gmtoff;
  const char * tm_zone;
};

typedef struct time_Time time_Time;
struct  time_Time {
  int64_t _t;
  struct tm _tm;
};

typedef char Array1872[512];
extern uint64_t strftime(char * __s, uint64_t __maxsize, const char * __format, const struct tm * __tp);
extern int64_t timegm(struct tm * __tp);
extern char * strptime(const char * __s, const char * __fmt, struct tm * __tp);
extern int64_t time(int64_t * __timer);
extern struct tm * gmtime_r(const int64_t * __timer, struct tm * __tp);

static void time_Time_op__initI_i64E(struct time_Time * this, int64_t t) {
  this->_t = t;
  gmtime_r((const int64_t *)&this->_t, &this->_tm);
}


static void time_Time_op__initI_E(struct time_Time * this) {
  this->_t = time((int64_t *) {});
  gmtime_r((const int64_t *)&this->_t, &this->_tm);
}


static void time_Time_op__initI_ssE(struct time_Time * this, const char* str, const char* fmt) {
  strptime((const char *)str, (const char *)fmt, &this->_tm);
  this->_t = timegm(&this->_tm);
}


static void time_Time_format(const struct time_Time * this, const char* fmt, struct OutputStream * os) {
  if (fmt[0] != '\0') {
    Array1872 buf = {};
    uint64_t sz = strftime((char *)buf, (uint64_t)512, (const char *)fmt, &this->_tm);
    os->vtable->append(os, (const void *)buf, sz);
  }
}

__attribute__((always_inline))
static void time_Time_op__str(const struct time_Time * this, struct OutputStream * os) {
  time_Time_format(this, "%a, %d %b %Y %T GMT", os);
}

__attribute__((always_inline))
static int64_t time_Time_timestamp(const struct time_Time * this) {
  int64_t _rt622 = {};
  _rt622 = this->_t;
  return _rt622;
}

/*-----------/home/dev/.cxy/lib/cxy/std/stdlib/log.cxy-----------*/
typedef struct logger_FixedWidth logger_FixedWidth;
struct  logger_FixedWidth {
  struct __string s;
  uint64_t count;
};

typedef int64_t logger_Level;
enum {
  logger_Level_TRACE = 0,
  logger_Level_DEBUG = 1,
  logger_Level_INFO = 2,
  logger_Level_WARNING = 3,
  logger_Level_ERROR = 4,
};

typedef struct logger_Logger logger_Logger;
struct  logger_Logger {
  struct OutputStream * os;
  logger_Level _level;
};

static void logger___init_logger();
__attribute__((always_inline))
static uint64_t builtins_minI_u64E(uint64_t a, uint64_t b) {
  uint64_t _rt641 = {};
  _rt641 = a < b? a: b;
  return _rt641;
}


static void logger_FixedWidth_op__init(struct logger_FixedWidth * this, struct __string s, uint64_t count) {
  this->s = s;
  this->count = count;
}

__attribute__((always_inline))
static void logger_FixedWidth_op__str(const struct logger_FixedWidth * this, struct OutputStream * os) {
  uint64_t _a626 = builtins___string_size(&this->s);
  int64_t _a627 = (int64_t)builtins_minI_u64E(this->count, _a626);
  struct __string _r628 = builtins___string_substr(&this->s, 0u, _a627);
  struct __string * _a629 = &_r628;
  builtins_OutputStream_op__lshiftI_Z__string_E(os, (const struct __string *)_a629);
  if (builtins___string_size(&this->s) < this->count) {
    uint64_t _a630 = this->count - builtins___string_size(&this->s);
    struct Repeat _r631 = builtins_Repeat_op__initCover((char)' ', _a630);
    struct Repeat * _a632 = &_r631;
    builtins_OutputStream_op__lshiftI_ZRepeat_E(os, (const struct Repeat *)_a632);
  }
}

__attribute__((always_inline))
static struct time_Time time_Time_op__initI_ECoverI_E() {
  struct time_Time _rt642 = {};
  struct time_Time __obj623 = (struct time_Time){};
  time_Time_op__initI_E(&__obj623);
  _rt642 = __obj623;
  return _rt642;
}


static struct OutputStream * builtins_OutputStream_op__lshiftI_ZloggerLevel_E(struct OutputStream * this, const logger_Level val) {
  struct OutputStream * _rt643 = {};
  switch (val) {
  case logger_Level_TRACE: {
    {
      builtins_OutputStream_appendStringI_sE(this, "TRC");
    }
    break;
  }
  case logger_Level_DEBUG: {
    {
      builtins_OutputStream_appendStringI_sE(this, "DBG");
    }
    break;
  }
  case logger_Level_INFO: {
    {
      builtins_OutputStream_appendStringI_sE(this, "INF");
    }
    break;
  }
  case logger_Level_WARNING: {
    {
      builtins_OutputStream_appendStringI_sE(this, "WRN");
    }
    break;
  }
  case logger_Level_ERROR: {
    {
      builtins_OutputStream_appendStringI_sE(this, "ERR");
    }
    break;
  }
  default: { unreachable("unhandled-default-case"); }
  }
  
  _rt643 = this;
  return _rt643;
}

__attribute__((always_inline))
static struct logger_FixedWidth logger_FixedWidth_op__initCover(struct __string s, uint64_t count) {
  struct logger_FixedWidth _rt644 = {};
  struct logger_FixedWidth __obj624 = (struct logger_FixedWidth){};
  logger_FixedWidth_op__init(&__obj624, s, count);
  _rt644 = __obj624;
  return _rt644;
}


static struct OutputStream * builtins_OutputStream_op__lshiftI_ZloggerFixedWidth_E(struct OutputStream * this, const struct logger_FixedWidth * val) {
  struct OutputStream * _rt645 = {};
  logger_FixedWidth_op__str(val, this);
  _rt645 = this;
  return _rt645;
}


static void logger_Logger_op__init(struct logger_Logger * this) {
  __smart_ptr_drop(this->os);
  this->os = builtins_stdout;
}


static void logger_Logger_setOutputStream(struct logger_Logger * this, struct OutputStream * os) {
  __smart_ptr_drop(this->os);
  this->os = os;
}


static void logger_Logger_levelI_ZloggerLevel_E(struct logger_Logger * this, logger_Level lvl) {
  this->_level = lvl;
}


static logger_Level logger_Logger_levelIc_E(const struct logger_Logger * this) {
  logger_Level _rt646 = {};
  _rt646 = this->_level;
  return _rt646;
}


static struct OutputStream * logger_Logger_log(struct logger_Logger * this, logger_Level lvl, const char* tag) {
  struct OutputStream * _rt647 = {};
  struct time_Time _m633 = time_Time_op__initI_ECoverI_E();
  time_Time_format(&_m633, "%Y-%m-%d %H:%M:%S", this->os);
  struct OutputStream * _m634 = builtins_OutputStream_op__lshiftI_sE(this->os, " ");
  struct OutputStream * _m635 = builtins_OutputStream_op__lshiftI_ZloggerLevel_E(_m634, lvl);
  struct OutputStream * _m636 = builtins_OutputStream_op__lshiftI_sE(_m635, " ");
  struct __string _a637 = builtins___string_op__initCoverI_sE(tag);
  struct logger_FixedWidth _r638 = logger_FixedWidth_op__initCover(_a637, (uint64_t)10);
  struct logger_FixedWidth * _a639 = &_r638;
  struct OutputStream * _m640 = builtins_OutputStream_op__lshiftI_ZloggerFixedWidth_E(_m636, (const struct logger_FixedWidth *)_a639);
  builtins_OutputStream_op__lshiftI_sE(_m640, " ");
  _rt647 = this->os;
  return _rt647;
}


static void logger_Logger_op__destructor(struct logger_Logger * this) {
  __smart_ptr_drop(this->os);
  *(&this->os) = nullptr;
}


static void logger_Logger_op__destructor_fwd(void * ptr) {
  logger_Logger_op__destructor((struct logger_Logger *)ptr);
}


static void logger_Logger___defaults_init(struct logger_Logger * this) {
  this->_level = logger_Level_TRACE;
}

__attribute__((always_inline))
static struct logger_Logger * logger_Logger_op__initCover() {
  struct logger_Logger * _rt648 = {};
  struct logger_Logger * __obj625 = (struct logger_Logger *)__smart_ptr_alloc(sizeof(logger_Logger), logger_Logger_op__destructor_fwd);
  memset(__obj625, 0, sizeof(logger_Logger));
  logger_Logger___defaults_init(__obj625);
  logger_Logger_op__init(__obj625);
  _rt648 = __obj625;
  return _rt648;
}

struct logger_Logger * logger___L = nullptr;
__attribute__((constructor))

static void logger___init_logger() {
  __smart_ptr_drop(logger___L);
  logger___L = logger_Logger_op__initCover();
}

/*-----------/home/dev/.cxy/lib/cxy/std/stdlib/path.cxy-----------*/
typedef struct path_Union1972 path_Union1972;
typedef struct path_Path path_Path;
struct  path_Path {
  struct String * path;
};

struct path_Union1972{
  uint32_t tag;
  union {
    const char* _0;
    struct __string _1;
    struct String * _2;
    struct path_Path _3;
  };
};

typedef struct __dirstream ___dirstream;
struct  __dirstream {
};

typedef struct dirent _dirent;
typedef char Array1469[256];
struct  dirent {
  uint64_t d_ino;
  int64_t d_off;
  uint16_t d_reclen;
  uint8_t d_type;
  Array1469 d_name;
};

typedef struct passwd _passwd;
struct  passwd {
  char * pw_name;
  char * pw_passwd;
  uint32_t pw_uid;
  uint32_t pw_gid;
  char * pw_gecos;
  char * pw_dir;
  char * pw_shell;
};

typedef char Array1983[1024];
typedef bool(*Func1999_t)(void *, const char *);
typedef struct path_Tuple2000 {
  void * _0;
  Func1999_t _1;
} path_Tuple2000;

typedef struct path___Closure666 path___Closure666;
struct  path___Closure666 {
};

typedef struct path___Closure668 path___Closure668;
struct  path___Closure668 {
};

typedef struct path___Closure670 path___Closure670;
struct  path___Closure670 {
};

typedef struct path___Closure672 path___Closure672;
struct  path___Closure672 {
};

typedef int32_t(*Func2038_t)(void *, const char *);
typedef struct path_Tuple2039 {
  void * _0;
  Func2038_t _1;
} path_Tuple2039;

typedef struct path___Closure674 path___Closure674;
struct  path___Closure674 {
  uint16_t mode;
};

typedef struct __dirstream *(*Func2055_t)(void *, const char *);
typedef struct path_Tuple2056 {
  void * _0;
  Func2055_t _1;
} path_Tuple2056;

typedef struct path___Closure679 path___Closure679;
struct  path___Closure679 {
};

typedef bool(*Func2050_t)(void *, struct path_Union1972);
typedef struct path_Tuple2051 {
  void * _0;
  Func2050_t _1;
} path_Tuple2051;

typedef struct path___Closure683 path___Closure683;
struct  path___Closure683 {
};

typedef struct path___Closure688 path___Closure688;
struct  path___Closure688 {
};

typedef struct path___Closure691 path___Closure691;
struct  path___Closure691 {
};

typedef struct path___Closure694 path___Closure694;
struct  path___Closure694 {
};

extern int32_t unlink(const char * __name);
extern int32_t rmdir(const char * __path);
static struct os_Union1557 path_remove(struct path_Union1972 path, bool recursive);
extern int32_t closedir(struct __dirstream * __dirp);
extern struct dirent * nos_readdir(struct __dirstream * dir);
extern struct __dirstream * opendir(const char * __name);
extern int32_t mkdir(const char * __path, uint32_t __mode);
extern uint32_t getuid();
extern struct passwd * getpwuid(uint32_t __uid);
extern char * getcwd(char * __buf, uint64_t __size);
extern int32_t access(const char * __name, int32_t __type);
static void path_Path_op__initI_ZString_E(struct path_Path * this, struct String * s);
__attribute__((always_inline))
static struct String * builtins_String_op__initI_Z__string_ECoverI_Z__string_E(struct __string str) {
  struct String * _rt765 = {};
  struct String * __obj661 = (struct String *)__smart_ptr_alloc(sizeof(String), builtins_String_op__destructor_fwd);
  memset(__obj661, 0, sizeof(String));
  builtins_String___defaults_init(__obj661);
  builtins_String_op__initI_Z__string_E(__obj661, str);
  _rt765 = __obj661;
  return _rt765;
}

__attribute__((always_inline))
static struct path_Path path_Path_op__initCoverI_ZString_E(struct String * s) {
  struct path_Path _rt766 = {};
  struct path_Path __obj662 = (struct path_Path){
    .path = (struct String *)nullptr
  };
  path_Path_op__initI_ZString_E(&__obj662, s);
  _rt766 = __obj662;
  return _rt766;
}

__attribute__((always_inline))
static bool builtins_isnullI_ZString_E(const struct String * cls) {
  bool _rt767 = {};
  _rt767 = ((const void *)cls) == nullptr;
  return _rt767;
}


static struct OutputStream * builtins_OutputStream_op__lshiftI_ZString_E(struct OutputStream * this, const struct String * val) {
  struct OutputStream * _rt768 = {};
  if (builtins_isnullI_ZString_E(val)) {
    builtins_OutputStream_appendStringI_sE(this, "null");
  } else {
    uint64_t _a697 = builtins_String_size(val);
    this->vtable->append(this, (const void *)val->_data, _a697);
  }
  _rt768 = this;
  return _rt768;
}

__attribute__((always_inline))
static void path_Path_op__initI_E(struct path_Path * this) {
  
}

__attribute__((always_inline))
static void path_Path_op__initI_sE(struct path_Path * this, const char* s) {
  __smart_ptr_drop(this->path);
  this->path = builtins_String_op__initI_sECoverI_sE(s);
}

__attribute__((always_inline))
static void path_Path_op__initI_ZString_E(struct path_Path * this, struct String * s) {
  __smart_ptr_drop(this->path);
  this->path = s;
}

__attribute__((always_inline))
static void path_Path_op__initI_Z__string_E(struct path_Path * this, struct __string s) {
  __smart_ptr_drop(this->path);
  this->path = builtins_String_op__initI_Z__string_ECoverI_Z__string_E(s);
}


static struct path_Path path_Path_op__divIc_Z__string_E(const struct path_Path * this, struct __string suffix) {
  struct path_Path _rt769 = {};
  const char* _a698 = builtins_String_str(this->path);
  struct String * res = builtins_String_op__initI_sECoverI_sE(_a698);
  if (builtins_String_endswithIc_sE(res, "/")) {
    struct OutputStream * _m699 = (struct OutputStream *)res;
    builtins_OutputStream_op__lshiftI_Z__string_E(_m699, (const struct __string *)&suffix);
  } else {
    struct OutputStream * _m700 = (struct OutputStream *)res;
    struct OutputStream * _m701 = builtins_OutputStream_op__lshiftI_sE(_m700, "/");
    builtins_OutputStream_op__lshiftI_Z__string_E(_m701, (const struct __string *)&suffix);
  }
  _rt769 = path_Path_op__initCoverI_ZString_E(res);
  return _rt769;
}

__attribute__((always_inline))
static struct path_Path path_Path_op__divIc_sE(const struct path_Path * this, const char* suffix) {
  struct path_Path _rt770 = {};
  struct __string _a702 = builtins___string_op__initCoverI_sE(suffix);
  _rt770 = path_Path_op__divIc_Z__string_E(this, _a702);
  return _rt770;
}

__attribute__((always_inline))
static struct path_Path path_Path_op__divIc_ZString_E(const struct path_Path * this, struct String * suffix) {
  struct path_Path _rt771 = {};
  struct __string _a703 = builtins_String___str(suffix);
  _rt771 = path_Path_op__divIc_Z__string_E(this, _a703);
  __smart_ptr_drop(suffix);
  return _rt771;
}

__attribute__((always_inline))
static bool path_Path_op__truthy(const struct path_Path * this) {
  bool _rt772 = {};
  _rt772 = !builtins_String_empty(this->path);
  return _rt772;
}

__attribute__((always_inline))
static bool path_Path_op__eqIc_cRZpathPath_E(const struct path_Path * this, const struct path_Path * other) {
  bool _rt773 = {};
  _rt773 = builtins_String_op__eqIc_cRZString_E(this->path, (const struct String *)other->path);
  return _rt773;
}

__attribute__((always_inline))
static bool path_Path_op__neqIc_cRZpathPath_E(const struct path_Path * this, const struct path_Path * other) {
  bool _rt774 = {};
  _rt774 = !(builtins_String_op__eqIc_cRZString_E(this->path, (const struct String *)other->path));
  return _rt774;
}

__attribute__((always_inline))
static uint32_t path_Path_op__hash(const struct path_Path * this) {
  uint32_t _rt775 = {};
  _rt775 = builtins_String_op__hash(this->path);
  return _rt775;
}

__attribute__((always_inline))
static void path_Path_op__str(const struct path_Path * this, struct OutputStream * os) {
  builtins_OutputStream_op__lshiftI_ZString_E(os, this->path);
}

__attribute__((always_inline))
static const char* path_Path_str(const struct path_Path * this) {
  const char* _rt776 = {};
  _rt776 = builtins_String_str(this->path);
  return _rt776;
}

__attribute__((always_inline))
static struct __string path_Path___str(const struct path_Path * this) {
  struct __string _rt777 = {};
  _rt777 = builtins_String___str(this->path);
  return _rt777;
}

__attribute__((always_inline))
static bool path_Path_exists(const struct path_Path * this) {
  bool _rt778 = {};
  const char * _a704 = (const char *)builtins_String_str(this->path);
  _rt778 = access(_a704, 0) == 0;
  return _rt778;
}

__attribute__((always_inline))
static bool path_Path_empty(const struct path_Path * this) {
  bool _rt779 = {};
  _rt779 = builtins_String_empty(this->path);
  return _rt779;
}

__attribute__((always_inline))
static bool path_Path_op__eqIc_cRZString_E(const struct path_Path * this, const struct String * other) {
  bool _rt780 = {};
  _rt780 = builtins_String_op__eqIc_cRZString_E(this->path, (const struct String *)other);
  return _rt780;
}

__attribute__((always_inline))
static bool path_Path_op__eqIc_Z__string_E(const struct path_Path * this, struct __string other) {
  bool _rt781 = {};
  struct __string _m705 = builtins_String___str(this->path);
  _rt781 = builtins___string_op__eq(&_m705, (struct __string *)&other);
  return _rt781;
}

__attribute__((always_inline))
static bool path_Path_op__eqIc_sE(const struct path_Path * this, const char* other) {
  bool _rt782 = {};
  struct __string _m706 = builtins_String___str(this->path);
  struct __string _r707 = builtins___string_op__initCoverI_sE(other);
  struct __string * _a708 = &_r707;
  _rt782 = builtins___string_op__eq(&_m706, (struct __string *)_a708);
  return _rt782;
}

__attribute__((always_inline))
static bool path_Path_op__neqIc_cRZString_E(const struct path_Path * this, const struct String * other) {
  bool _rt783 = {};
  _rt783 = builtins_String_op__neqIc_cRZString_E(this->path, (const struct String *)other);
  return _rt783;
}

__attribute__((always_inline))
static bool path_Path_op__neqIc_Z__string_E(const struct path_Path * this, struct __string other) {
  bool _rt784 = {};
  struct __string _m709 = builtins_String___str(this->path);
  _rt784 = builtins___string_op__neq(&_m709, (struct __string *)&other);
  return _rt784;
}

__attribute__((always_inline))
static bool path_Path_op__neqIc_sE(const struct path_Path * this, const char* other) {
  bool _rt785 = {};
  struct __string _m710 = builtins_String___str(this->path);
  struct __string _r711 = builtins___string_op__initCoverI_sE(other);
  struct __string * _a712 = &_r711;
  _rt785 = builtins___string_op__neq(&_m710, (struct __string *)_a712);
  return _rt785;
}

__attribute__((always_inline))
static struct path_Path path_Path_op__copy(struct path_Path * this) {
  struct path_Path _rt786 = {};
  _rt786 = (struct path_Path){
    .path = (struct String *)__smart_ptr_get(this->path)
  };
  return _rt786;
}


static void path_Path_op__destructor(struct path_Path * this) {
  __smart_ptr_drop(this->path);
  *(&this->path) = nullptr;
}


static struct path_Union1972 builtins___union_copyI_U1972_E(struct path_Union1972 * obj) {
  struct path_Union1972 _rt787 = {};
  switch (obj->tag) {
  case 0u: {
    {
      const char* y = obj->_0;
      _rt787 = (struct path_Union1972){.tag = 0, ._0 = y};
      return _rt787;
    }
  }
  case 1u: {
    {
      struct __string * y = &obj->_1;
      _rt787 = (struct path_Union1972){.tag = 1, ._1 = *(y)};
      return _rt787;
    }
  }
  case 2u: {
    {
      struct String * y = obj->_2;
      _rt787 = (struct path_Union1972){.tag = 2, ._2 = __smart_ptr_get(y)};
      return _rt787;
    }
  }
  case 3u: {
    {
      struct path_Path * y = &obj->_3;
      _rt787 = (struct path_Union1972){.tag = 3, ._3 = path_Path_op__copy(y)};
      return _rt787;
    }
  }
  default: { unreachable("unhandled-default-case"); }
  }
  
}


static void builtins___union_dctorI_U1972_E(struct path_Union1972 * obj) {
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
  case 3u: {
    {
      struct path_Path * y = &obj->_3;
      path_Path_op__destructor(y);
    }
    break;
  }
  default: { unreachable("unhandled-default-case"); }
  }
  
}

__attribute__((always_inline))
static struct path_Path path_Path_op__initCoverI_sE(const char* s) {
  struct path_Path _rt788 = {};
  struct path_Path __obj663 = (struct path_Path){
    .path = (struct String *)nullptr
  };
  path_Path_op__initI_sE(&__obj663, s);
  _rt788 = __obj663;
  return _rt788;
}

__attribute__((always_inline))
static struct path_Path path_Path_op__initCover() {
  struct path_Path _rt789 = {};
  struct path_Path __obj664 = (struct path_Path){
    .path = (struct String *)nullptr
  };
  path_Path_op__initI_E(&__obj664);
  _rt789 = __obj664;
  return _rt789;
}


static struct path_Path path_cwd() {
  struct path_Path _rt790 = {};
  Array1983 buffer = {};
  char * str = getcwd((char *)buffer, sizeof(Array1983));
  if (str != nullptr) {
    _rt790 = path_Path_op__initCoverI_sE((const char*)str);
    return _rt790;
  }
  _rt790 = path_Path_op__initCover();
  return _rt790;
}


static struct path_Path path_homedir() {
  struct path_Path _rt791 = {};
  char * dir = getenv((const char *)"HOME");
  if (dir == nullptr) {
    uint32_t _a713 = getuid();
    struct passwd * _m714 = getpwuid(_a713);
    dir = _m714->pw_dir;
  }
  _rt791 = path_Path_op__initCoverI_sE((const char*)dir);
  return _rt791;
}


static struct __string path_castI_Z__string_E(struct path_Union1972 * path) {
  struct __string _rt792 = {};
  switch (path->tag) {
  case 0u: {
    {
      const char* s = path->_0;
      _rt792 = builtins___string_op__initCoverI_sE(s);
      return _rt792;
    }
  }
  case 1u: {
    {
      struct __string * s = &path->_1;
      _rt792 = builtins___string_op__copy(s);
      return _rt792;
    }
  }
  case 2u: {
    {
      struct String * s = path->_2;
      _rt792 = builtins_String___str(s);
      return _rt792;
    }
  }
  case 3u: {
    {
      struct path_Path * p = &path->_3;
      _rt792 = path_Path___str(p);
      return _rt792;
    }
  }
  default: { unreachable("unhandled-default-case"); }
  }
  
}

__attribute__((always_inline))
static struct path_Path path_Path_op__initCoverI_Z__string_E(struct __string s) {
  struct path_Path _rt793 = {};
  struct path_Path __obj665 = (struct path_Path){
    .path = (struct String *)nullptr
  };
  path_Path_op__initI_Z__string_E(&__obj665, s);
  _rt793 = __obj665;
  return _rt793;
}


static struct path_Path path_castI_ZpathPath_E(struct path_Union1972 * path) {
  struct path_Path _rt794 = {};
  switch (path->tag) {
  case 0u: {
    {
      const char* s = path->_0;
      _rt794 = path_Path_op__initCoverI_sE(s);
      return _rt794;
    }
  }
  case 1u: {
    {
      struct __string * s = &path->_1;
      struct __string _a715 = builtins___string_op__copy(s);
      _rt794 = path_Path_op__initCoverI_Z__string_E(_a715);
      return _rt794;
    }
  }
  case 2u: {
    {
      struct String * s = path->_2;
      struct String * _a716 = __smart_ptr_get(s);
      _rt794 = path_Path_op__initCoverI_ZString_E(_a716);
      return _rt794;
    }
  }
  case 3u: {
    {
      struct path_Path * p = &path->_3;
      _rt794 = path_Path_op__copy(p);
      return _rt794;
    }
  }
  default: { unreachable("unhandled-default-case"); }
  }
  
}


static struct path_Path path_expand(struct path_Union1972 path) {
  struct path_Path _rt795 = {};
  struct __string spath = path_castI_Z__string_E(&path);
  struct path_Path ppath = path_castI_ZpathPath_E(&path);
  bool __ppath_dflags = true;
  struct __string _a717 = builtins___string_op__initCoverI_sE("~");
  if (!builtins___string_startswith(&spath, _a717)) {
    _rt795 = ppath;
    __ppath_dflags = false;
    builtins___union_dctorI_U1972_E(&(path));
    return _rt795;
  }
  struct path_Path home = path_homedir();
  bool __home_dflags = true;
  if (!path_Path_op__truthy(&home)) {
    _rt795 = ppath;
    __ppath_dflags = false;
    builtins___union_dctorI_U1972_E(&(path));
    __CXY_DROP_WITH_FLAGS(__home_dflags, path_Path_op__destructor(&(home)));
    __home_dflags = false;
    return _rt795;
  }
  int8_t i = 0;
  while (builtins___string_op__idx(&spath, (int64_t)i) == '~' || builtins___string_op__idx(&spath, (int64_t)i) == '/') {
    {
      i++;
    }
    
  }
  spath = builtins___string_substr(&spath, (uint64_t)i, (int64_t)-1);
  if (builtins___string_empty(&spath)) {
    _rt795 = home;
    builtins___union_dctorI_U1972_E(&(path));
    __CXY_DROP_WITH_FLAGS(__ppath_dflags, path_Path_op__destructor(&(ppath)));
    __ppath_dflags = false;
    return _rt795;
  }
  _rt795 = path_Path_op__divIc_Z__string_E(&home, spath);
  builtins___union_dctorI_U1972_E(&(path));
  __CXY_DROP_WITH_FLAGS(__ppath_dflags, path_Path_op__destructor(&(ppath)));
  __ppath_dflags = false;
  __CXY_DROP_WITH_FLAGS(__home_dflags, path_Path_op__destructor(&(home)));
  __home_dflags = false;
  return _rt795;
}

__attribute__((always_inline))
static struct path_Path path_current() {
  struct path_Path _rt796 = {};
  _rt796 = path_Path_op__initCoverI_sE("/home/dev/.cxy/lib/cxy/std/stdlib/path.cxy");
  return _rt796;
}

__attribute__((always_inline))
static bool path_withNullTerminationI_bE(const struct __string * s, struct path_Tuple2000 fn) {
  bool _rt797 = {};
  if (builtins___string_isnt(s)) {
    Array1983 p = {};
    builtins___string_copyto(s, (char *)p, sizeof(Array1983));
    _rt797 = fn._1(fn._0, (const char *)p);
    return _rt797;
  } else {
    const char * _a718 = builtins___string_data(s);
    _rt797 = fn._1(fn._0, _a718);
    return _rt797;
  }
}


static bool path___Closure666_op__call(struct path___Closure666 * this, const char * p) {
  bool _rt798 = {};
  _rt798 = access(p, 0) == 0;
  return _rt798;
}


static void path___Closure666_op__init(struct path___Closure666 * this) {
  
}


static bool path___Closure666__fwd(void * ptr, const char * p) {
  bool _rt799 = {};
  struct path___Closure666 * self_ = __smart_ptr_get((struct path___Closure666 *)ptr);
  _rt799 = path___Closure666_op__call(self_, p);
  __smart_ptr_drop(self_);
  return _rt799;
}


static bool path_exists(struct path_Union1972 path) {
  bool _rt800 = {};
  struct __string spath = path_castI_Z__string_E(&path);
  if (builtins___string_empty(&spath)) {
    builtins___union_dctorI_U1972_E(&(path));
    return false;
  }
  struct path_Tuple2000 _a719 = (struct path_Tuple2000){
    ._0 = (void *)({
      struct path___Closure666 * __obj667 = (struct path___Closure666 *)__smart_ptr_alloc(sizeof(path___Closure666), nullptr);
      __obj667;
    }),
    ._1 = path___Closure666__fwd
  };
  _rt800 = path_withNullTerminationI_bE((const struct __string *)&spath, _a719);
  builtins___union_dctorI_U1972_E(&(path));
  return _rt800;
}


static bool path___Closure668_op__call(struct path___Closure668 * this, const char * p) {
  bool _rt801 = {};
  struct stat s = (struct stat){};
  if (os_stat((const char*)p, &s) != 0) {
    return false;
  }
  if ((s.st_mode & 61440) == 32768) {
    return true;
  }
  if ((s.st_mode & 61440) == 40960) {
    if (os_lstat((const char*)p, &s) != 0) {
      return false;
    }
    _rt801 = (s.st_mode & 61440) == 32768;
    return _rt801;
  }
  return false;
}


static void path___Closure668_op__init(struct path___Closure668 * this) {
  
}


static bool path___Closure668__fwd(void * ptr, const char * p) {
  bool _rt802 = {};
  struct path___Closure668 * self_ = __smart_ptr_get((struct path___Closure668 *)ptr);
  _rt802 = path___Closure668_op__call(self_, p);
  __smart_ptr_drop(self_);
  return _rt802;
}


static bool path_isfile(struct path_Union1972 path) {
  bool _rt803 = {};
  struct __string spath = path_castI_Z__string_E(&path);
  if (builtins___string_empty(&spath)) {
    builtins___union_dctorI_U1972_E(&(path));
    return false;
  }
  struct path_Tuple2000 _a720 = (struct path_Tuple2000){
    ._0 = (void *)({
      struct path___Closure668 * __obj669 = (struct path___Closure668 *)__smart_ptr_alloc(sizeof(path___Closure668), nullptr);
      __obj669;
    }),
    ._1 = path___Closure668__fwd
  };
  _rt803 = path_withNullTerminationI_bE((const struct __string *)&spath, _a720);
  builtins___union_dctorI_U1972_E(&(path));
  return _rt803;
}


static bool path___Closure670_op__call(struct path___Closure670 * this, const char * p) {
  bool _rt804 = {};
  struct stat s = (struct stat){};
  if (os_stat((const char*)p, &s) != 0) {
    return false;
  }
  if ((s.st_mode & 61440) == 16384) {
    return true;
  }
  if ((s.st_mode & 61440) == 40960) {
    if (os_lstat((const char*)p, &s) != 0) {
      return false;
    }
    _rt804 = (s.st_mode & 61440) == 16384;
    return _rt804;
  }
  return false;
}


static void path___Closure670_op__init(struct path___Closure670 * this) {
  
}


static bool path___Closure670__fwd(void * ptr, const char * p) {
  bool _rt805 = {};
  struct path___Closure670 * self_ = __smart_ptr_get((struct path___Closure670 *)ptr);
  _rt805 = path___Closure670_op__call(self_, p);
  __smart_ptr_drop(self_);
  return _rt805;
}


static bool path_isdir(struct path_Union1972 path) {
  bool _rt806 = {};
  struct __string spath = path_castI_Z__string_E(&path);
  if (builtins___string_empty(&spath)) {
    builtins___union_dctorI_U1972_E(&(path));
    return false;
  }
  struct path_Tuple2000 _a721 = (struct path_Tuple2000){
    ._0 = (void *)({
      struct path___Closure670 * __obj671 = (struct path___Closure670 *)__smart_ptr_alloc(sizeof(path___Closure670), nullptr);
      __obj671;
    }),
    ._1 = path___Closure670__fwd
  };
  _rt806 = path_withNullTerminationI_bE((const struct __string *)&spath, _a721);
  builtins___union_dctorI_U1972_E(&(path));
  return _rt806;
}


static bool path___Closure672_op__call(struct path___Closure672 * this, const char * p) {
  bool _rt807 = {};
  struct stat s = (struct stat){};
  if (os_stat((const char*)p, &s) != 0) {
    return false;
  }
  _rt807 = (s.st_mode & 61440) == 40960;
  return _rt807;
}


static void path___Closure672_op__init(struct path___Closure672 * this) {
  
}


static bool path___Closure672__fwd(void * ptr, const char * p) {
  bool _rt808 = {};
  struct path___Closure672 * self_ = __smart_ptr_get((struct path___Closure672 *)ptr);
  _rt808 = path___Closure672_op__call(self_, p);
  __smart_ptr_drop(self_);
  return _rt808;
}


static bool path_islink(struct path_Union1972 path) {
  bool _rt809 = {};
  struct __string spath = path_castI_Z__string_E(&path);
  if (builtins___string_empty(&spath)) {
    builtins___union_dctorI_U1972_E(&(path));
    return false;
  }
  struct path_Tuple2000 _a722 = (struct path_Tuple2000){
    ._0 = (void *)({
      struct path___Closure672 * __obj673 = (struct path___Closure672 *)__smart_ptr_alloc(sizeof(path___Closure672), nullptr);
      __obj673;
    }),
    ._1 = path___Closure672__fwd
  };
  _rt809 = path_withNullTerminationI_bE((const struct __string *)&spath, _a722);
  builtins___union_dctorI_U1972_E(&(path));
  return _rt809;
}


static struct path_Union1972 path_dirname(struct path_Union1972 path) {
  struct path_Union1972 _rt810 = {};
  struct __string spath = path_castI_Z__string_E(&path);
  struct __string _a723 = builtins___string_op__initCoverI_sE("/");
  struct OptionalI_u64E sep = builtins___string_rfind(&spath, _a723);
  if (builtins_OptionalI_u64E_op__truthyI_E(&sep)) {
    int64_t _a724 = (int64_t)builtins_OptionalI_u64E_op__derefI_E(&sep);
    spath = builtins___string_substr(&spath, (uint64_t)0, _a724);
    _rt810 = (struct path_Union1972){.tag = 3, ._3 = path_Path_op__initCoverI_Z__string_E(spath)};
    builtins___union_dctorI_U1972_E(&(path));
    builtins_OptionalI_u64E_op__destructor(&(sep));
    return _rt810;
  }
  _rt810 = path;
  builtins_OptionalI_u64E_op__destructor(&(sep));
  return _rt810;
}


static struct path_Union1972 path_basename(struct path_Union1972 path) {
  struct path_Union1972 _rt811 = {};
  struct __string spath = path_castI_Z__string_E(&path);
  struct __string _a725 = builtins___string_op__initCoverI_sE("/");
  struct OptionalI_u64E sep = builtins___string_rfind(&spath, _a725);
  if (builtins_OptionalI_u64E_op__truthyI_E(&sep)) {
    uint64_t _a726 = builtins_OptionalI_u64E_op__derefI_E(&sep) + 1;
    spath = builtins___string_substr(&spath, _a726, (int64_t)-1);
    _rt811 = (struct path_Union1972){.tag = 3, ._3 = path_Path_op__initCoverI_Z__string_E(spath)};
    builtins___union_dctorI_U1972_E(&(path));
    builtins_OptionalI_u64E_op__destructor(&(sep));
    return _rt811;
  }
  _rt811 = path;
  builtins_OptionalI_u64E_op__destructor(&(sep));
  return _rt811;
}

__attribute__((always_inline))
static int32_t path_withNullTerminationI_i32E(const struct __string * s, struct path_Tuple2039 fn) {
  int32_t _rt812 = {};
  if (builtins___string_isnt(s)) {
    Array1983 p = {};
    builtins___string_copyto(s, (char *)p, sizeof(Array1983));
    _rt812 = fn._1(fn._0, (const char *)p);
    return _rt812;
  } else {
    const char * _a727 = builtins___string_data(s);
    _rt812 = fn._1(fn._0, _a727);
    return _rt812;
  }
}


static int32_t path___Closure674_op__call(struct path___Closure674 * this, const char * p) {
  int32_t _rt813 = {};
  _rt813 = mkdir(p, (uint32_t)this->mode);
  return _rt813;
}


static void path___Closure674_op__init(struct path___Closure674 * this) {
  
}


static int32_t path___Closure674__fwd(void * ptr, const char * p) {
  int32_t _rt814 = {};
  struct path___Closure674 * self_ = __smart_ptr_get((struct path___Closure674 *)ptr);
  _rt814 = path___Closure674_op__call(self_, p);
  __smart_ptr_drop(self_);
  return _rt814;
}


static struct os_Union1557 path_mkdir(struct path_Union1972 path, uint16_t mode) {
  struct os_Union1557 _rt815 = {};
  struct __string spath = path_castI_Z__string_E(&path);
  struct path_Tuple2039 _a728 = (struct path_Tuple2039){
    ._0 = (void *)({
      struct path___Closure674 * __obj675 = (struct path___Closure674 *)__smart_ptr_alloc(sizeof(path___Closure674), nullptr);
      __obj675->mode = mode;
      __obj675;
    }),
    ._1 = path___Closure674__fwd
  };
  int32_t status = path_withNullTerminationI_i32E((const struct __string *)&spath, _a728);
  if (status != 0) {
    struct String * sb649 = builtins_String_op__initI_ECover();
    const char* _rv676 = builtins_strerr();
    struct OutputStream * _m729 = (struct OutputStream *)sb649;
    struct OutputStream * _m730 = builtins_OutputStream_op__lshiftI_sE(_m729, "creating directory ");
    struct OutputStream * _m731 = builtins_OutputStream_op__lshiftI_Z__string_E(_m730, (const struct __string *)&spath);
    struct OutputStream * _m732 = builtins_OutputStream_op__lshiftI_sE(_m731, " failed: ");
    builtins_OutputStream_op__lshiftI_sE(_m732, _rv676);
    struct Exception * _ex650 = (struct Exception *)os_IOError_op__initCover(__smart_ptr_get(sb649));
    builtins_Exception_push(_ex650, "path", (const char*) {}, "mkdir", "/home/dev/.cxy/lib/cxy/std/stdlib/path.cxy", (uint64_t)283);
    _rt815 = (struct os_Union1557){.tag = 1, ._1 = _ex650};
    __smart_ptr_drop(sb649);
    builtins___union_dctorI_U1972_E(&(path));
    return _rt815;
  }
  _rt815 = (struct os_Union1557){.tag = 0, ._0 = (struct Void){}};
  builtins___union_dctorI_U1972_E(&(path));
  return _rt815;
}


static struct os_Union1557 path_mkdirs(struct path_Union1972 path, uint16_t mode) {
  struct os_Union1557 _rt816 = {};
  if (!path_exists(builtins___union_copyI_U1972_E(&(path)))) {
    struct path_Union1972 base = path_dirname(builtins___union_copyI_U1972_E(&(path)));
    struct __string sbase = path_castI_Z__string_E(&base);
    struct __string spath = path_castI_Z__string_E(&path);
    if (!builtins___string_empty(&sbase) && builtins___string_op__neq(&spath, (struct __string *)&sbase)) {
      struct os_Union1557 _res677 = path_mkdirs(builtins___union_copyI_U1972_E(&(base)), mode);
      bool ___res677_dflags = true;
      if (_res677.tag == 1u) {
        struct Exception * ex = _res677._1;
        ___res677_dflags = false;
        builtins_Exception_push(ex, "path", (const char*) {}, "mkdirs", "/home/dev/.cxy/lib/cxy/std/stdlib/path.cxy", 292u);
        _rt816 = (struct os_Union1557){.tag = 1, ._1 = ex};
        builtins___union_dctorI_U1972_E(&(base));
        builtins___union_dctorI_U1972_E(&(path));
        return _rt816;
      }
      __CXY_DROP_WITH_FLAGS(___res677_dflags, builtins___union_dctorI_U_ZVoid_ZException__E(&(_res677)));
      ___res677_dflags = false;
    }
    struct os_Union1557 _res678 = path_mkdir(builtins___union_copyI_U1972_E(&(path)), mode);
    bool ___res678_dflags = true;
    if (_res678.tag == 1u) {
      struct Exception * ex = _res678._1;
      ___res678_dflags = false;
      builtins_Exception_push(ex, "path", (const char*) {}, "mkdirs", "/home/dev/.cxy/lib/cxy/std/stdlib/path.cxy", 293u);
      _rt816 = (struct os_Union1557){.tag = 1, ._1 = ex};
      builtins___union_dctorI_U1972_E(&(base));
      builtins___union_dctorI_U1972_E(&(path));
      return _rt816;
    }
    __CXY_DROP_WITH_FLAGS(___res678_dflags, builtins___union_dctorI_U_ZVoid_ZException__E(&(_res678)));
    ___res678_dflags = false;
    builtins___union_dctorI_U1972_E(&(base));
  }
  _rt816 = (struct os_Union1557){.tag = 0, ._0 = (struct Void){}};
  builtins___union_dctorI_U1972_E(&(path));
  return _rt816;
}

__attribute__((always_inline))
static struct __dirstream * path_withNullTerminationI_PZ__dirstream_E(const struct __string * s, struct path_Tuple2056 fn) {
  struct __dirstream * _rt817 = {};
  if (builtins___string_isnt(s)) {
    Array1983 p = {};
    builtins___string_copyto(s, (char *)p, sizeof(Array1983));
    _rt817 = fn._1(fn._0, (const char *)p);
    return _rt817;
  } else {
    const char * _a733 = builtins___string_data(s);
    _rt817 = fn._1(fn._0, _a733);
    return _rt817;
  }
}


static struct __dirstream * path___Closure679_op__call(struct path___Closure679 * this, const char * p) {
  struct __dirstream * _rt818 = {};
  _rt818 = opendir(p);
  return _rt818;
}


static void path___Closure679_op__init(struct path___Closure679 * this) {
  
}


static struct __dirstream * path___Closure679__fwd(void * ptr, const char * p) {
  struct __dirstream * _rt819 = {};
  struct path___Closure679 * self_ = __smart_ptr_get((struct path___Closure679 *)ptr);
  _rt819 = path___Closure679_op__call(self_, p);
  __smart_ptr_drop(self_);
  return _rt819;
}


static struct OutputStream * builtins_OutputStream_op__lshiftI_ZpathPath_E(struct OutputStream * this, const struct path_Path * val) {
  struct OutputStream * _rt820 = {};
  path_Path_op__str(val, this);
  _rt820 = this;
  return _rt820;
}


static struct OutputStream * builtins_OutputStream_op__lshiftI_U1972_E(struct OutputStream * this, const struct path_Union1972 * val) {
  struct OutputStream * _rt821 = {};
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
  case 3u: {
    {
      const struct path_Path * y = &val->_3;
      builtins_OutputStream_op__lshiftI_ZpathPath_E(this, y);
    }
    break;
  }
  default: { unreachable("unhandled-default-case"); }
  }
  
  _rt821 = this;
  return _rt821;
}


static struct os_Union1557 path_ls(struct path_Union1972 path, struct path_Tuple2051 cb, bool recursive) {
  struct os_Union1557 _rt822 = {};
  struct __string spath = path_castI_Z__string_E(&path);
  struct path_Tuple2056 _a734 = (struct path_Tuple2056){
    ._0 = (void *)({
      struct path___Closure679 * __obj680 = (struct path___Closure679 *)__smart_ptr_alloc(sizeof(path___Closure679), nullptr);
      __obj680;
    }),
    ._1 = path___Closure679__fwd
  };
  struct __dirstream * d = path_withNullTerminationI_PZ__dirstream_E((const struct __string *)&spath, _a734);
  if (d == nullptr) {
    struct String * sb651 = builtins_String_op__initI_ECover();
    const char* _rv681 = builtins_strerr();
    struct OutputStream * _m735 = (struct OutputStream *)sb651;
    struct OutputStream * _m736 = builtins_OutputStream_op__lshiftI_sE(_m735, "opendir('");
    struct OutputStream * _m737 = builtins_OutputStream_op__lshiftI_U1972_E(_m736, (const struct path_Union1972 *)&path);
    struct OutputStream * _m738 = builtins_OutputStream_op__lshiftI_sE(_m737, "') failed: ");
    builtins_OutputStream_op__lshiftI_sE(_m738, _rv681);
    struct Exception * _ex652 = (struct Exception *)os_IOError_op__initCover(__smart_ptr_get(sb651));
    builtins_Exception_push(_ex652, "path", (const char*) {}, "ls", "/home/dev/.cxy/lib/cxy/std/stdlib/path.cxy", (uint64_t)305);
    _rt822 = (struct os_Union1557){.tag = 1, ._1 = _ex652};
    __smart_ptr_drop(sb651);
    builtins___union_dctorI_U1972_E(&(path));
    return _rt822;
  }
  struct path_Path base = path_castI_ZpathPath_E(&path);
  while (true) {
    {
      struct dirent * tmp = nos_readdir(d);
      if (tmp == nullptr) {
        break;
      }
      struct __string name = builtins___string_op__initCoverI_sE((const char*)tmp->d_name);
      struct __string _r739 = builtins___string_op__initCoverI_sE(".");
      struct __string * _a740 = &_r739;
      struct __string _r741 = builtins___string_op__initCoverI_sE("..");
      struct __string * _a742 = &_r741;
      if (builtins___string_op__eq(&name, (struct __string *)_a740) || builtins___string_op__eq(&name, (struct __string *)_a742)) {
        continue;
      }
      struct path_Path ipath = path_Path_op__divIc_Z__string_E(&base, name);
      bool isDir = tmp->d_type == 4u;
      if (recursive && isDir) {
        struct path_Union1972 _a743 = (struct path_Union1972){.tag = 3, ._3 = path_Path_op__copy(&(ipath))};
        struct os_Union1557 _res682 = path_ls(_a743, cb, recursive);
        bool ___res682_dflags = true;
        if (_res682.tag == 1u) {
          struct Exception * ex = _res682._1;
          ___res682_dflags = false;
          builtins_Exception_push(ex, "path", (const char*) {}, "ls", "/home/dev/.cxy/lib/cxy/std/stdlib/path.cxy", 323u);
          closedir(d);
          _rt822 = (struct os_Union1557){.tag = 1, ._1 = ex};
          __CXY_DROP_WITH_FLAGS(___res682_dflags, builtins___union_dctorI_U_ZVoid_ZException__E(&(_res682)));
          ___res682_dflags = false;
          path_Path_op__destructor(&(ipath));
          builtins___union_dctorI_U1972_E(&(path));
          path_Path_op__destructor(&(base));
          return _rt822;
        }
        __CXY_DROP_WITH_FLAGS(___res682_dflags, builtins___union_dctorI_U_ZVoid_ZException__E(&(_res682)));
        ___res682_dflags = false;
      }
      struct path_Union1972 _a744 = (struct path_Union1972){.tag = 3, ._3 = path_Path_op__copy(&(ipath))};
      if (!cb._1(cb._0, _a744)) {
        path_Path_op__destructor(&(ipath));
        break;
      }
      path_Path_op__destructor(&(ipath));
    }
    
  }
  closedir(d);
  _rt822 = (struct os_Union1557){.tag = 0, ._0 = (struct Void){}};
  builtins___union_dctorI_U1972_E(&(path));
  path_Path_op__destructor(&(base));
  return _rt822;
}


static struct __dirstream * path___Closure683_op__call(struct path___Closure683 * this, const char * p) {
  struct __dirstream * _rt823 = {};
  _rt823 = opendir(p);
  return _rt823;
}


static void path___Closure683_op__init(struct path___Closure683 * this) {
  
}


static struct __dirstream * path___Closure683__fwd(void * ptr, const char * p) {
  struct __dirstream * _rt824 = {};
  struct path___Closure683 * self_ = __smart_ptr_get((struct path___Closure683 *)ptr);
  _rt824 = path___Closure683_op__call(self_, p);
  __smart_ptr_drop(self_);
  return _rt824;
}


static struct json_Union1827 path_isDirEmpty(struct path_Union1972 path) {
  struct json_Union1827 _rt825 = {};
  struct __string spath = path_castI_Z__string_E(&path);
  struct path_Tuple2056 _a745 = (struct path_Tuple2056){
    ._0 = (void *)({
      struct path___Closure683 * __obj684 = (struct path___Closure683 *)__smart_ptr_alloc(sizeof(path___Closure683), nullptr);
      __obj684;
    }),
    ._1 = path___Closure683__fwd
  };
  struct __dirstream * d = path_withNullTerminationI_PZ__dirstream_E((const struct __string *)&spath, _a745);
  if (d == nullptr) {
    struct String * sb653 = builtins_String_op__initI_ECover();
    const char* _rv685 = builtins_strerr();
    struct OutputStream * _m746 = (struct OutputStream *)sb653;
    struct OutputStream * _m747 = builtins_OutputStream_op__lshiftI_sE(_m746, "opendir('");
    struct OutputStream * _m748 = builtins_OutputStream_op__lshiftI_Z__string_E(_m747, (const struct __string *)&spath);
    struct OutputStream * _m749 = builtins_OutputStream_op__lshiftI_sE(_m748, "') failed: ");
    builtins_OutputStream_op__lshiftI_sE(_m749, _rv685);
    struct Exception * _ex654 = (struct Exception *)os_IOError_op__initCover(__smart_ptr_get(sb653));
    builtins_Exception_push(_ex654, "path", (const char*) {}, "isDirEmpty", "/home/dev/.cxy/lib/cxy/std/stdlib/path.cxy", (uint64_t)337);
    _rt825 = (struct json_Union1827){.tag = 1, ._1 = _ex654};
    __smart_ptr_drop(sb653);
    builtins___union_dctorI_U1972_E(&(path));
    return _rt825;
  }
  int8_t n = 0;
  while (n <= 2) {
    {
      struct dirent * tmp = nos_readdir(d);
      if (tmp == nullptr) {
        break;
      }
      n++;
    }
    
  }
  closedir(d);
  _rt825 = (struct json_Union1827){.tag = 0, ._0 = n <= 2};
  builtins___union_dctorI_U1972_E(&(path));
  return _rt825;
}


static bool path___Closure688_op__call(struct path___Closure688 * this, struct path_Union1972 path) {
  bool _rt826 = {};
  struct os_Union1557 _res687 = path_remove(builtins___union_copyI_U1972_E(&(path)), true);
  builtins___union_dctorI_U1972_E(&(path));
  builtins___union_dctorI_U_ZVoid_ZException__E(&(_res687));
  return true;
}


static void path___Closure688_op__init(struct path___Closure688 * this) {
  
}


static bool path___Closure688__fwd(void * ptr, struct path_Union1972 path) {
  bool _rt827 = {};
  struct path___Closure688 * self_ = __smart_ptr_get((struct path___Closure688 *)ptr);
  _rt827 = path___Closure688_op__call(self_, path);
  __smart_ptr_drop(self_);
  return _rt827;
}


static int32_t path___Closure691_op__call(struct path___Closure691 * this, const char * p) {
  int32_t _rt828 = {};
  _rt828 = rmdir(p);
  return _rt828;
}


static void path___Closure691_op__init(struct path___Closure691 * this) {
  
}


static int32_t path___Closure691__fwd(void * ptr, const char * p) {
  int32_t _rt829 = {};
  struct path___Closure691 * self_ = __smart_ptr_get((struct path___Closure691 *)ptr);
  _rt829 = path___Closure691_op__call(self_, p);
  __smart_ptr_drop(self_);
  return _rt829;
}


static int32_t path___Closure694_op__call(struct path___Closure694 * this, const char * p) {
  int32_t _rt830 = {};
  _rt830 = unlink(p);
  return _rt830;
}


static void path___Closure694_op__init(struct path___Closure694 * this) {
  
}


static int32_t path___Closure694__fwd(void * ptr, const char * p) {
  int32_t _rt831 = {};
  struct path___Closure694 * self_ = __smart_ptr_get((struct path___Closure694 *)ptr);
  _rt831 = path___Closure694_op__call(self_, p);
  __smart_ptr_drop(self_);
  return _rt831;
}


static struct os_Union1557 path_remove(struct path_Union1972 path, bool recursive) {
  struct os_Union1557 _rt832 = {};
  struct __string spath = path_castI_Z__string_E(&path);
  struct path_Union1972 _a750 = (struct path_Union1972){.tag = 1, ._1 = spath};
  if (path_isdir(_a750)) {
    struct path_Union1972 _a751 = (struct path_Union1972){.tag = 1, ._1 = spath};
    struct json_Union1827 _res686 = path_isDirEmpty(_a751);
    bool ___res686_dflags = true;
    if (_res686.tag == 1u) {
      struct Exception * ex = _res686._1;
      ___res686_dflags = false;
      builtins_Exception_push(ex, "path", (const char*) {}, "remove", "/home/dev/.cxy/lib/cxy/std/stdlib/path.cxy", 354u);
      _rt832 = (struct os_Union1557){.tag = 1, ._1 = ex};
      builtins___union_dctorI_U1972_E(&(path));
      return _rt832;
    }
    if (!_res686._0) {
      if (!recursive) {
        struct String * sb655 = builtins_String_op__initI_ECover();
        struct OutputStream * _m752 = (struct OutputStream *)sb655;
        struct OutputStream * _m753 = builtins_OutputStream_op__lshiftI_sE(_m752, "attempt to delete a non empty directory ");
        builtins_OutputStream_op__lshiftI_Z__string_E(_m753, (const struct __string *)&spath);
        struct Exception * _ex656 = (struct Exception *)os_IOError_op__initCover(__smart_ptr_get(sb655));
        builtins_Exception_push(_ex656, "path", (const char*) {}, "remove", "/home/dev/.cxy/lib/cxy/std/stdlib/path.cxy", (uint64_t)356);
        _rt832 = (struct os_Union1557){.tag = 1, ._1 = _ex656};
        __smart_ptr_drop(sb655);
        builtins___union_dctorI_U1972_E(&(path));
        return _rt832;
      }
      struct path_Tuple2051 _a754 = (struct path_Tuple2051){
        ._0 = (void *)({
          struct path___Closure688 * __obj689 = (struct path___Closure688 *)__smart_ptr_alloc(sizeof(path___Closure688), nullptr);
          __obj689;
        }),
        ._1 = path___Closure688__fwd
      };
      struct os_Union1557 _res690 = path_ls(builtins___union_copyI_U1972_E(&(path)), _a754, false);
      bool ___res690_dflags = true;
      if (_res690.tag == 1u) {
        struct Exception * ex = _res690._1;
        ___res690_dflags = false;
        builtins_Exception_push(ex, "path", (const char*) {}, "remove", "/home/dev/.cxy/lib/cxy/std/stdlib/path.cxy", 359u);
        _rt832 = (struct os_Union1557){.tag = 1, ._1 = ex};
        builtins___union_dctorI_U1972_E(&(path));
        return _rt832;
      }
      __CXY_DROP_WITH_FLAGS(___res690_dflags, builtins___union_dctorI_U_ZVoid_ZException__E(&(_res690)));
      ___res690_dflags = false;
    }
    ___res686_dflags = false;
    struct path_Tuple2039 _a755 = (struct path_Tuple2039){
      ._0 = (void *)({
        struct path___Closure691 * __obj692 = (struct path___Closure691 *)__smart_ptr_alloc(sizeof(path___Closure691), nullptr);
        __obj692;
      }),
      ._1 = path___Closure691__fwd
    };
    int32_t status = path_withNullTerminationI_i32E((const struct __string *)&spath, _a755);
    if (status != 0) {
      struct String * sb657 = builtins_String_op__initI_ECover();
      const char* _rv693 = builtins_strerr();
      struct OutputStream * _m756 = (struct OutputStream *)sb657;
      struct OutputStream * _m757 = builtins_OutputStream_op__lshiftI_sE(_m756, "deleting directory '");
      struct OutputStream * _m758 = builtins_OutputStream_op__lshiftI_Z__string_E(_m757, (const struct __string *)&spath);
      struct OutputStream * _m759 = builtins_OutputStream_op__lshiftI_sE(_m758, "' failed: ");
      builtins_OutputStream_op__lshiftI_sE(_m759, _rv693);
      struct Exception * _ex658 = (struct Exception *)os_IOError_op__initCover(__smart_ptr_get(sb657));
      builtins_Exception_push(_ex658, "path", (const char*) {}, "remove", "/home/dev/.cxy/lib/cxy/std/stdlib/path.cxy", (uint64_t)366);
      _rt832 = (struct os_Union1557){.tag = 1, ._1 = _ex658};
      __smart_ptr_drop(sb657);
      builtins___union_dctorI_U1972_E(&(path));
      return _rt832;
    }
  } else if (path_exists(builtins___union_copyI_U1972_E(&(path)))) {
    struct path_Tuple2039 _a760 = (struct path_Tuple2039){
      ._0 = (void *)({
        struct path___Closure694 * __obj695 = (struct path___Closure694 *)__smart_ptr_alloc(sizeof(path___Closure694), nullptr);
        __obj695;
      }),
      ._1 = path___Closure694__fwd
    };
    int32_t status = path_withNullTerminationI_i32E((const struct __string *)&spath, _a760);
    if (status != 0) {
      struct String * sb659 = builtins_String_op__initI_ECover();
      const char* _rv696 = builtins_strerr();
      struct OutputStream * _m761 = (struct OutputStream *)sb659;
      struct OutputStream * _m762 = builtins_OutputStream_op__lshiftI_sE(_m761, "deleting file '");
      struct OutputStream * _m763 = builtins_OutputStream_op__lshiftI_Z__string_E(_m762, (const struct __string *)&spath);
      struct OutputStream * _m764 = builtins_OutputStream_op__lshiftI_sE(_m763, "' failed: ");
      builtins_OutputStream_op__lshiftI_sE(_m764, _rv696);
      struct Exception * _ex660 = (struct Exception *)os_IOError_op__initCover(__smart_ptr_get(sb659));
      builtins_Exception_push(_ex660, "path", (const char*) {}, "remove", "/home/dev/.cxy/lib/cxy/std/stdlib/path.cxy", (uint64_t)371);
      _rt832 = (struct os_Union1557){.tag = 1, ._1 = _ex660};
      __smart_ptr_drop(sb659);
      builtins___union_dctorI_U1972_E(&(path));
      return _rt832;
    }
  }
  _rt832 = (struct os_Union1557){.tag = 0, ._0 = (struct Void){}};
  builtins___union_dctorI_U1972_E(&(path));
  return _rt832;
}

/*-----------/workspace/server/isolate.cxy-----------*/
typedef struct isolate_IsolateError isolate_IsolateError;
struct  isolate_IsolateError {
  struct Exception_VTable * vtable;
  const char* name;
  struct StackTrace stackTrace;
  const char* msg;
};

typedef struct isolate_Mount isolate_Mount;
struct  isolate_Mount {
  const char* src;
  const char* dst;
  const char* flags;
};

typedef struct isolate__AgumentAssignI_i32E isolate__AgumentAssignI_i32E;
struct  isolate__AgumentAssignI_i32E {
  int32_t x;
  const char* arg;
};

typedef const char* Array2161[4];
typedef struct isolate_Sandbox isolate_Sandbox;
struct  isolate_Sandbox {
  struct path_Path path;
  int64_t id;
  const char* LOG_TAG;
};

typedef struct isolate_SandboxConfig isolate_SandboxConfig;
struct  isolate_SandboxConfig {
  const char* cxyRoot;
  const char* srcRoot;
  int32_t processes;
  int32_t wallTime;
};

typedef struct isolate_Union2164 isolate_Union2164;
struct isolate_Union2164{
  uint32_t tag;
  union {
    struct isolate_Sandbox _0;
    struct Exception * _1;
  };
};

static const char* isolate_IsolateError_what(struct isolate_IsolateError * this);
struct Exception_VTable isolate_IsolateError_vTable = (struct Exception_VTable){
  .what = (builtins_Exception_what_t)isolate_IsolateError_what
};

static void isolate_IsolateError_op__init(struct isolate_IsolateError * this, const char* msg) {
  builtins_Exception_op__init((struct Exception *)this, "IsolateError");
  this->msg = msg;
}


static const char* isolate_IsolateError_what(struct isolate_IsolateError * this) {
  const char* _rt916 = {};
  _rt916 = this->msg;
  return _rt916;
}


static void isolate_IsolateError_op__destructor(struct isolate_IsolateError * this) {
  builtins_Exception_op__destructor((struct Exception *)this);
}


static void isolate_IsolateError_op__destructor_fwd(void * ptr) {
  isolate_IsolateError_op__destructor((struct isolate_IsolateError *)ptr);
}


static void isolate_IsolateError___defaults_init(struct isolate_IsolateError * this) {
  builtins_Exception___defaults_init(this);
  this->vtable = &isolate_IsolateError_vTable;
}


static void isolate_Mount_op__str(const struct isolate_Mount * this, struct OutputStream * os) {
  struct OutputStream * _m850 = builtins_OutputStream_op__lshiftI_sE(os, this->dst);
  struct OutputStream * _m851 = builtins_OutputStream_op__lshiftI_sE(_m850, "=");
  builtins_OutputStream_op__lshiftI_sE(_m851, this->src);
  if (this->flags != nullptr) {
    struct OutputStream * _m852 = builtins_OutputStream_op__lshiftI_sE(os, ":");
    builtins_OutputStream_op__lshiftI_sE(_m852, this->flags);
  }
}

__attribute__((always_inline))
static struct isolate_IsolateError * isolate_IsolateError_op__initCover(const char* msg) {
  struct isolate_IsolateError * _rt917 = {};
  struct isolate_IsolateError * __obj835 = (struct isolate_IsolateError *)__smart_ptr_alloc(sizeof(isolate_IsolateError), isolate_IsolateError_op__destructor_fwd);
  memset(__obj835, 0, sizeof(isolate_IsolateError));
  isolate_IsolateError___defaults_init(__obj835);
  isolate_IsolateError_op__init(__obj835, msg);
  _rt917 = __obj835;
  return _rt917;
}


static void isolate__AgumentAssignI_i32E_op__str(const struct isolate__AgumentAssignI_i32E * this, struct OutputStream * os) {
  struct OutputStream * _m853 = builtins_OutputStream_op__lshiftI_sE(os, this->arg);
  struct OutputStream * _m854 = builtins_OutputStream_op__lshiftI_sE(_m853, "=");
  builtins_OutputStream_op__lshiftI_i32E(_m854, this->x);
}

__attribute__((always_inline))
static struct isolate__AgumentAssignI_i32E isolate_argumentAssignI_i32E(const char* arg, int32_t x) {
  struct isolate__AgumentAssignI_i32E _rt918 = {};
  _rt918 = (struct isolate__AgumentAssignI_i32E){
    .x = x,
    .arg = arg
  };
  return _rt918;
}


static struct OutputStream * builtins_OutputStream_op__lshiftI_ZisolateMount_E(struct OutputStream * this, const struct isolate_Mount * val) {
  struct OutputStream * _rt919 = {};
  isolate_Mount_op__str(val, this);
  _rt919 = this;
  return _rt919;
}


static struct OutputStream * builtins_OutputStream_op__lshiftI_Zisolate_AgumentAssignI_i32E_E(struct OutputStream * this, const struct isolate__AgumentAssignI_i32E * val) {
  struct OutputStream * _rt920 = {};
  isolate__AgumentAssignI_i32E_op__str(val, this);
  _rt920 = this;
  return _rt920;
}


static struct os_Union1686 os_execlpeI_ssE(const char* cmd, struct SliceI_Tss_E env, const char* args, const char* args1) {
  struct os_Union1686 _rt921 = {};
  Array2161 argv = {};
  argv[0] = cmd;
  argv[1] = args;
  argv[2] = args1;
  argv[3] = nullptr;
  struct SliceI_sE _a855 = builtins_SliceI_sE_op__initCover((const char* *)argv, 4u);
  struct os_Union1686 _res836 = os_execvpe(cmd, _a855, env);
  bool ___res836_dflags = true;
  if (_res836.tag == 1u) {
    struct Exception * ex = _res836._1;
    ___res836_dflags = false;
    builtins_Exception_push(ex, "isolate", "Sandbox", "execlpeI_ssE", "/workspace/server/isolate.cxy", 523u);
    _rt921 = (struct os_Union1686){.tag = 1, ._1 = ex};
    return _rt921;
  }
  _rt921 = (struct os_Union1686){.tag = 0, ._0 = _res836._0};
  ___res836_dflags = false;
  return _rt921;
}


static struct os_Union1686 os_shellI_si64sZisolateMount_ssssssssssZisolate_AgumentAssignI_i32E_Zisolate_AgumentAssignI_i32E_sssE(const char* cmd, const char* args, int64_t args1, const char* args2, struct isolate_Mount args3, const char* args4, const char* args5, const char* args6, const char* args7, const char* args8, const char* args9, const char* args10, const char* args11, const char* args12, const char* args13, struct isolate__AgumentAssignI_i32E args14, struct isolate__AgumentAssignI_i32E args15, const char* args16, const char* args17, const char* args18) {
  struct os_Union1686 _rt922 = {};
  struct SliceI_Tss_E env = builtins_SliceI_Tss_E_op__initCover((struct os_Tuple1736 *) {}, (uint64_t)0);
  struct String * s = builtins_String_op__initI_sECoverI_sE(cmd);
  struct OutputStream * _m856 = (struct OutputStream *)s;
  struct OutputStream * _m857 = builtins_OutputStream_op__lshiftI_sE(_m856, " ");
  builtins_OutputStream_op__lshiftI_sE(_m857, args);
  struct OutputStream * _m858 = (struct OutputStream *)s;
  struct OutputStream * _m859 = builtins_OutputStream_op__lshiftI_sE(_m858, " ");
  builtins_OutputStream_op__lshiftI_i64E(_m859, args1);
  struct OutputStream * _m860 = (struct OutputStream *)s;
  struct OutputStream * _m861 = builtins_OutputStream_op__lshiftI_sE(_m860, " ");
  builtins_OutputStream_op__lshiftI_sE(_m861, args2);
  struct OutputStream * _m862 = (struct OutputStream *)s;
  struct OutputStream * _m863 = builtins_OutputStream_op__lshiftI_sE(_m862, " ");
  builtins_OutputStream_op__lshiftI_ZisolateMount_E(_m863, &args3);
  struct OutputStream * _m864 = (struct OutputStream *)s;
  struct OutputStream * _m865 = builtins_OutputStream_op__lshiftI_sE(_m864, " ");
  builtins_OutputStream_op__lshiftI_sE(_m865, args4);
  struct OutputStream * _m866 = (struct OutputStream *)s;
  struct OutputStream * _m867 = builtins_OutputStream_op__lshiftI_sE(_m866, " ");
  builtins_OutputStream_op__lshiftI_sE(_m867, args5);
  struct OutputStream * _m868 = (struct OutputStream *)s;
  struct OutputStream * _m869 = builtins_OutputStream_op__lshiftI_sE(_m868, " ");
  builtins_OutputStream_op__lshiftI_sE(_m869, args6);
  struct OutputStream * _m870 = (struct OutputStream *)s;
  struct OutputStream * _m871 = builtins_OutputStream_op__lshiftI_sE(_m870, " ");
  builtins_OutputStream_op__lshiftI_sE(_m871, args7);
  struct OutputStream * _m872 = (struct OutputStream *)s;
  struct OutputStream * _m873 = builtins_OutputStream_op__lshiftI_sE(_m872, " ");
  builtins_OutputStream_op__lshiftI_sE(_m873, args8);
  struct OutputStream * _m874 = (struct OutputStream *)s;
  struct OutputStream * _m875 = builtins_OutputStream_op__lshiftI_sE(_m874, " ");
  builtins_OutputStream_op__lshiftI_sE(_m875, args9);
  struct OutputStream * _m876 = (struct OutputStream *)s;
  struct OutputStream * _m877 = builtins_OutputStream_op__lshiftI_sE(_m876, " ");
  builtins_OutputStream_op__lshiftI_sE(_m877, args10);
  struct OutputStream * _m878 = (struct OutputStream *)s;
  struct OutputStream * _m879 = builtins_OutputStream_op__lshiftI_sE(_m878, " ");
  builtins_OutputStream_op__lshiftI_sE(_m879, args11);
  struct OutputStream * _m880 = (struct OutputStream *)s;
  struct OutputStream * _m881 = builtins_OutputStream_op__lshiftI_sE(_m880, " ");
  builtins_OutputStream_op__lshiftI_sE(_m881, args12);
  struct OutputStream * _m882 = (struct OutputStream *)s;
  struct OutputStream * _m883 = builtins_OutputStream_op__lshiftI_sE(_m882, " ");
  builtins_OutputStream_op__lshiftI_sE(_m883, args13);
  struct OutputStream * _m884 = (struct OutputStream *)s;
  struct OutputStream * _m885 = builtins_OutputStream_op__lshiftI_sE(_m884, " ");
  builtins_OutputStream_op__lshiftI_Zisolate_AgumentAssignI_i32E_E(_m885, &args14);
  struct OutputStream * _m886 = (struct OutputStream *)s;
  struct OutputStream * _m887 = builtins_OutputStream_op__lshiftI_sE(_m886, " ");
  builtins_OutputStream_op__lshiftI_Zisolate_AgumentAssignI_i32E_E(_m887, &args15);
  struct OutputStream * _m888 = (struct OutputStream *)s;
  struct OutputStream * _m889 = builtins_OutputStream_op__lshiftI_sE(_m888, " ");
  builtins_OutputStream_op__lshiftI_sE(_m889, args16);
  struct OutputStream * _m890 = (struct OutputStream *)s;
  struct OutputStream * _m891 = builtins_OutputStream_op__lshiftI_sE(_m890, " ");
  builtins_OutputStream_op__lshiftI_sE(_m891, args17);
  struct OutputStream * _m892 = (struct OutputStream *)s;
  struct OutputStream * _m893 = builtins_OutputStream_op__lshiftI_sE(_m892, " ");
  builtins_OutputStream_op__lshiftI_sE(_m893, args18);
  struct os_Union1686 _res837 = os_execlpeI_ssE("sh", env, "-c", builtins_String_str(s));
  bool ___res837_dflags = true;
  if (_res837.tag == 1u) {
    struct Exception * ex = _res837._1;
    ___res837_dflags = false;
    builtins_Exception_push(ex, "isolate", "Sandbox", "shellI_si64sZisolateMount_ssssssssssZisolate_AgumentAssignI_i32E_Zisolate_AgumentAssignI_i32E_sssE", "/workspace/server/isolate.cxy", 605u);
    _rt922 = (struct os_Union1686){.tag = 1, ._1 = ex};
    __smart_ptr_drop(s);
    return _rt922;
  }
  _rt922 = (struct os_Union1686){.tag = 0, ._0 = _res837._0};
  ___res837_dflags = false;
  __smart_ptr_drop(s);
  return _rt922;
}


static struct os_Union1686 os_shellI_si64sE(const char* cmd, const char* args, int64_t args1, const char* args2) {
  struct os_Union1686 _rt923 = {};
  struct SliceI_Tss_E env = builtins_SliceI_Tss_E_op__initCover((struct os_Tuple1736 *) {}, (uint64_t)0);
  struct String * s = builtins_String_op__initI_sECoverI_sE(cmd);
  struct OutputStream * _m894 = (struct OutputStream *)s;
  struct OutputStream * _m895 = builtins_OutputStream_op__lshiftI_sE(_m894, " ");
  builtins_OutputStream_op__lshiftI_sE(_m895, args);
  struct OutputStream * _m896 = (struct OutputStream *)s;
  struct OutputStream * _m897 = builtins_OutputStream_op__lshiftI_sE(_m896, " ");
  builtins_OutputStream_op__lshiftI_i64E(_m897, args1);
  struct OutputStream * _m898 = (struct OutputStream *)s;
  struct OutputStream * _m899 = builtins_OutputStream_op__lshiftI_sE(_m898, " ");
  builtins_OutputStream_op__lshiftI_sE(_m899, args2);
  struct os_Union1686 _res839 = os_execlpeI_ssE("sh", env, "-c", builtins_String_str(s));
  bool ___res839_dflags = true;
  if (_res839.tag == 1u) {
    struct Exception * ex = _res839._1;
    ___res839_dflags = false;
    builtins_Exception_push(ex, "isolate", "Sandbox", "shellI_si64sE", "/workspace/server/isolate.cxy", 605u);
    _rt923 = (struct os_Union1686){.tag = 1, ._1 = ex};
    __smart_ptr_drop(s);
    return _rt923;
  }
  _rt923 = (struct os_Union1686){.tag = 0, ._0 = _res839._0};
  ___res839_dflags = false;
  __smart_ptr_drop(s);
  return _rt923;
}


static void isolate_Sandbox_op__init(struct isolate_Sandbox * this, struct path_Path path, int64_t id) {
  path_Path_op__destructor(&(this->path));
  this->path = path_Path_op__copy(&(path));
  this->id = id;
  path_Path_op__destructor(&(path));
}


static struct os_Union1686 isolate_Sandbox_execute(struct isolate_Sandbox * this, struct isolate_SandboxConfig * config, const char* cmd) {
  struct os_Union1686 _rt924 = {};
  if (this->id == -1) {
    struct Exception * _ex833 = (struct Exception *)isolate_IsolateError_op__initCover("Sandbox not initialized");
    builtins_Exception_push(_ex833, "isolate", "Sandbox", "execute", "/workspace/server/isolate.cxy", (uint64_t)56);
    _rt924 = (struct os_Union1686){.tag = 1, ._1 = _ex833};
    return _rt924;
  }
  struct os_Union1686 _res838 = os_shellI_si64sZisolateMount_ssssssssssZisolate_AgumentAssignI_i32E_Zisolate_AgumentAssignI_i32E_sssE("isolate", "--box-id", this->id, "--dir", (struct isolate_Mount){
    .src = config->cxyRoot,
    .dst = "/cxy",
    .flags = (const char*) {}
  }, "--chdir", "/box", "--env", "HOME=box", "--env", "CXY_ROOT=/cxy", "--env", "CXY_STDLIB_DIR=/cxy/lib/cxy/std", "--env", "PATH=/usr/local/bin:/usr/bin:/cxy/bin", isolate_argumentAssignI_i32E("--wall-time", config->wallTime), isolate_argumentAssignI_i32E("--processes", config->processes), "--run", "--", cmd);
  bool ___res838_dflags = true;
  if (_res838.tag == 1u) {
    struct Exception * ex = _res838._1;
    ___res838_dflags = false;
    builtins_Exception_push(ex, "isolate", "Sandbox", "execute", "/workspace/server/isolate.cxy", 58u);
    _rt924 = (struct os_Union1686){.tag = 1, ._1 = ex};
    return _rt924;
  }
  _rt924 = (struct os_Union1686){.tag = 0, ._0 = _res838._0};
  ___res838_dflags = false;
  return _rt924;
}


static struct os_Union1557 isolate_Sandbox_cleanup(struct isolate_Sandbox * this) {
  struct os_Union1557 _rt925 = {};
  if (this->id != -1) {
    struct os_Union1686 _res840 = os_shellI_si64sE("isolate", "--box-id", this->id, "--cleanup");
    bool ___res840_dflags = true;
    if (_res840.tag == 1u) {
      struct Exception * ex = _res840._1;
      ___res840_dflags = false;
      builtins_Exception_push(ex, "isolate", "Sandbox", "cleanup", "/workspace/server/isolate.cxy", 76u);
      this->id = -1;
      _rt925 = (struct os_Union1557){.tag = 1, ._1 = ex};
      return _rt925;
    }
    struct os_Process proc = _res840._0;
    ___res840_dflags = false;
    struct os_Union1669 _res841 = os_Process_waitAsync(&proc);
    bool ___res841_dflags = true;
    if (_res841.tag == 1u) {
      struct Exception * ex = _res841._1;
      ___res841_dflags = false;
      builtins_Exception_push(ex, "isolate", "Sandbox", "cleanup", "/workspace/server/isolate.cxy", 77u);
      this->id = -1;
      _rt925 = (struct os_Union1557){.tag = 1, ._1 = ex};
      os_Process_op__destructor(&(proc));
      return _rt925;
    }
    int32_t status = _res841._0;
    ___res841_dflags = false;
    if (status != 0) {
      if (logger_Level_DEBUG >= logger_Logger_levelIc_E(logger___L)) {
        struct os_FileInputStream * _m900 = os_Process_stderr(&proc);
        struct os_Union1623 _res842 = os_FileInputStream_readAllI_E(_m900);
        bool ___res842_dflags = true;
        if (_res842.tag == 1u) {
          struct Exception * ex = _res842._1;
          ___res842_dflags = false;
          builtins_Exception_push(ex, "isolate", "Sandbox", "cleanup", "/workspace/server/isolate.cxy", 80u);
          this->id = -1;
          _rt925 = (struct os_Union1557){.tag = 1, ._1 = ex};
          os_Process_op__destructor(&(proc));
          return _rt925;
        }
        struct OutputStream * _m901 = logger_Logger_log(logger___L, logger_Level_DEBUG, this->LOG_TAG);
        struct OutputStream * _m902 = builtins_OutputStream_op__lshiftI_sE(_m901, "Cleaning up sandbox ");
        struct OutputStream * _m903 = builtins_OutputStream_op__lshiftI_i64E(_m902, this->id);
        struct OutputStream * _m904 = builtins_OutputStream_op__lshiftI_sE(_m903, " failed: ");
        struct String * _r905 = _res842._0;
        ___res842_dflags = false;
        struct String * _a906 = _r905;
        struct OutputStream * _m907 = builtins_OutputStream_op__lshiftI_ZString_E(_m904, (const struct String *)_a906);
        builtins_OutputStream_op__lshiftI_wE(_m907, '\n');
      };
    }
    this->id = -1;
    os_Process_op__destructor(&(proc));
  }
  _rt925 = (struct os_Union1557){.tag = 0, ._0 = (struct Void){}};
  return _rt925;
}

__attribute__((always_inline))
static void isolate_Sandbox_op__deinit(struct isolate_Sandbox * this) {
  struct os_Union1557 _res843 = isolate_Sandbox_cleanup(this);
  bool ___res843_dflags = true;
  if (_res843.tag == 1u) {
    struct Exception * _ex844 = _res843._1;
    ___res843_dflags = false;
    if (logger_Level_DEBUG >= logger_Logger_levelIc_E(logger___L)) {
      struct OutputStream * _m908 = logger_Logger_log(logger___L, logger_Level_DEBUG, this->LOG_TAG);
      struct OutputStream * _m909 = builtins_OutputStream_op__lshiftI_sE(_m908, "failed to cleanup sandbox: ");
      struct OutputStream * _m910 = builtins_OutputStream_op__lshiftI_ZException_E(_m909, (const struct Exception *)_ex844);
      builtins_OutputStream_op__lshiftI_wE(_m910, '\n');
    };
    __smart_ptr_drop(_ex844);
  }
  __CXY_DROP_WITH_FLAGS(___res843_dflags, builtins___union_dctorI_U_ZVoid_ZException__E(&(_res843)));
  ___res843_dflags = false;
}

__attribute__((always_inline))
static struct isolate_Sandbox isolate_Sandbox_op__copy(struct isolate_Sandbox * this) {
  struct isolate_Sandbox _rt926 = {};
  _rt926 = (struct isolate_Sandbox){
    .path = path_Path_op__copy(&(this->path)),
    .id = this->id,
    .LOG_TAG = this->LOG_TAG
  };
  return _rt926;
}


static void isolate_Sandbox_op__destructor(struct isolate_Sandbox * this) {
  isolate_Sandbox_op__deinit(this);
  path_Path_op__destructor(&(this->path));
  memset(&this->path, 0, sizeof(struct path_Path));
}


static struct isolate_Union2164 builtins___union_copyI_U_ZisolateSandbox_ZException__E(struct isolate_Union2164 * obj) {
  struct isolate_Union2164 _rt927 = {};
  switch (obj->tag) {
  case 0u: {
    {
      struct isolate_Sandbox * y = &obj->_0;
      _rt927 = (struct isolate_Union2164){.tag = 0, ._0 = isolate_Sandbox_op__copy(y)};
      return _rt927;
    }
  }
  case 1u: {
    {
      struct Exception * y = obj->_1;
      _rt927 = (struct isolate_Union2164){.tag = 1, ._1 = __smart_ptr_get(y)};
      return _rt927;
    }
  }
  default: { unreachable("unhandled-default-case"); }
  }
  
}


static void builtins___union_dctorI_U_ZisolateSandbox_ZException__E(struct isolate_Union2164 * obj) {
  switch (obj->tag) {
  case 0u: {
    {
      struct isolate_Sandbox * y = &obj->_0;
      isolate_Sandbox_op__destructor(y);
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
static struct isolate_Sandbox isolate_Sandbox_op__initCover(struct path_Path path, int64_t id) {
  struct isolate_Sandbox _rt928 = {};
  struct isolate_Sandbox __obj848 = (struct isolate_Sandbox){
    .id = (int64_t)-1,
    .LOG_TAG = "Sandbox"
  };
  isolate_Sandbox_op__init(&__obj848, path, id);
  _rt928 = __obj848;
  return _rt928;
}


static struct isolate_Union2164 isolate_createSandbox() {
  struct isolate_Union2164 _rt929 = {};
  {
    int64_t id = 0;
    while (id != 1000) {
      {
        struct os_Union1686 _res845 = os_shellI_si64sE("isolate", "--box-id", id, "--init");
        bool ___res845_dflags = true;
        if (_res845.tag == 1u) {
          struct Exception * ex = _res845._1;
          ___res845_dflags = false;
          builtins_Exception_push(ex, "isolate", (const char*) {}, "createSandbox", "/workspace/server/isolate.cxy", 95u);
          _rt929 = (struct isolate_Union2164){.tag = 1, ._1 = ex};
          __CXY_DROP_WITH_FLAGS(___res845_dflags, builtins___union_dctorI_U_ZosProcess_ZException__E(&(_res845)));
          ___res845_dflags = false;
          return _rt929;
        }
        struct os_Process proc = _res845._0;
        ___res845_dflags = false;
        struct os_Union1669 _res846 = os_Process_waitAsync(&proc);
        bool ___res846_dflags = true;
        if (_res846.tag == 1u) {
          struct Exception * ex = _res846._1;
          ___res846_dflags = false;
          builtins_Exception_push(ex, "isolate", (const char*) {}, "createSandbox", "/workspace/server/isolate.cxy", 96u);
          _rt929 = (struct isolate_Union2164){.tag = 1, ._1 = ex};
          __CXY_DROP_WITH_FLAGS(___res845_dflags, builtins___union_dctorI_U_ZosProcess_ZException__E(&(_res845)));
          ___res845_dflags = false;
          os_Process_op__destructor(&(proc));
          __CXY_DROP_WITH_FLAGS(___res846_dflags, builtins___union_dctorI_U_i32ZException__E(&(_res846)));
          ___res846_dflags = false;
          return _rt929;
        }
        int32_t status = _res846._0;
        ___res846_dflags = false;
        if (status == 0) {
          struct os_FileInputStream * _m911 = os_Process_stdout(&proc);
          struct os_Union1623 _res847 = os_FileInputStream_readAllI_E(_m911);
          bool ___res847_dflags = true;
          if (_res847.tag == 1u) {
            struct Exception * ex = _res847._1;
            ___res847_dflags = false;
            builtins_Exception_push(ex, "isolate", (const char*) {}, "createSandbox", "/workspace/server/isolate.cxy", 98u);
            _rt929 = (struct isolate_Union2164){.tag = 1, ._1 = ex};
            __CXY_DROP_WITH_FLAGS(___res847_dflags, builtins___union_dctorI_U_ZString_ZException__E(&(_res847)));
            ___res847_dflags = false;
            __CXY_DROP_WITH_FLAGS(___res845_dflags, builtins___union_dctorI_U_ZosProcess_ZException__E(&(_res845)));
            ___res845_dflags = false;
            os_Process_op__destructor(&(proc));
            __CXY_DROP_WITH_FLAGS(___res846_dflags, builtins___union_dctorI_U_i32ZException__E(&(_res846)));
            ___res846_dflags = false;
            return _rt929;
          }
          struct String * output = _res847._0;
          ___res847_dflags = false;
          builtins_String_trim(output);
          struct path_Path _m912 = path_Path_op__initCoverI_ZString_E(__smart_ptr_get(output));
          struct path_Path path = path_Path_op__divIc_sE(&_m912, "box");
          _rt929 = (struct isolate_Union2164){.tag = 0, ._0 = isolate_Sandbox_op__initCover(path, id)};
          __smart_ptr_drop(output);
          __CXY_DROP_WITH_FLAGS(___res845_dflags, builtins___union_dctorI_U_ZosProcess_ZException__E(&(_res845)));
          ___res845_dflags = false;
          os_Process_op__destructor(&(proc));
          __CXY_DROP_WITH_FLAGS(___res846_dflags, builtins___union_dctorI_U_i32ZException__E(&(_res846)));
          ___res846_dflags = false;
          return _rt929;
        } else {
          struct os_FileInputStream * _m913 = os_Process_stderr(&proc);
          struct os_Union1623 _res849 = os_FileInputStream_readAllI_E(_m913);
          bool ___res849_dflags = true;
          if (_res849.tag == 1u) {
            struct Exception * ex = _res849._1;
            ___res849_dflags = false;
            builtins_Exception_push(ex, "isolate", (const char*) {}, "createSandbox", "/workspace/server/isolate.cxy", 104u);
            _rt929 = (struct isolate_Union2164){.tag = 1, ._1 = ex};
            __CXY_DROP_WITH_FLAGS(___res849_dflags, builtins___union_dctorI_U_ZString_ZException__E(&(_res849)));
            ___res849_dflags = false;
            __CXY_DROP_WITH_FLAGS(___res845_dflags, builtins___union_dctorI_U_ZosProcess_ZException__E(&(_res845)));
            ___res845_dflags = false;
            os_Process_op__destructor(&(proc));
            __CXY_DROP_WITH_FLAGS(___res846_dflags, builtins___union_dctorI_U_i32ZException__E(&(_res846)));
            ___res846_dflags = false;
            return _rt929;
          }
          struct String * err = _res849._0;
          ___res849_dflags = false;
          struct OutputStream * _m914 = builtins_OutputStream_op__lshiftI_sE(builtins_stdout, "error: ");
          struct OutputStream * _m915 = builtins_OutputStream_op__lshiftI_ZString_E(_m914, (const struct String *)err);
          builtins_OutputStream_op__lshiftI_sE(_m915, "\n");
          __smart_ptr_drop(err);
        }
        os_Process_op__destructor(&(proc));
      }
      id += 1;
    }
  }
  struct Exception * _ex834 = (struct Exception *)isolate_IsolateError_op__initCover("Sandbox limit reached");
  builtins_Exception_push(_ex834, "isolate", (const char*) {}, "createSandbox", "/workspace/server/isolate.cxy", (uint64_t)108);
  _rt929 = (struct isolate_Union2164){.tag = 1, ._1 = _ex834};
  return _rt929;
}

/*-----------/workspace/server/builder.cxy-----------*/
typedef struct builder_BuildRequest builder_BuildRequest;
struct  builder_BuildRequest {
  struct String * args;
  struct String * code;
};

typedef struct builder_BuildResponse builder_BuildResponse;
struct  builder_BuildResponse {
  struct String * stdout;
  struct String * stderr;
  int32_t status;
};

typedef struct builder_RunResponse builder_RunResponse;
struct  builder_RunResponse {
  struct builder_BuildResponse build;
  struct String * stdout;
  struct String * stderr;
  int32_t status;
};

typedef struct builder_Union2191 builder_Union2191;
struct builder_Union2191{
  uint32_t tag;
  union {
    struct builder_BuildResponse _0;
    struct Exception * _1;
  };
};

typedef struct builder_Union2201 builder_Union2201;
struct builder_Union2201{
  uint32_t tag;
  union {
    struct builder_RunResponse _0;
    struct Exception * _1;
  };
};

__attribute__((always_inline))
static struct builder_BuildRequest builder_BuildRequest_op__copy(struct builder_BuildRequest * this) {
  struct builder_BuildRequest _rt965 = {};
  _rt965 = (struct builder_BuildRequest){
    .args = (struct String *)__smart_ptr_get(this->args),
    .code = (struct String *)__smart_ptr_get(this->code)
  };
  return _rt965;
}


static void builder_BuildRequest_op__destructor(struct builder_BuildRequest * this) {
  __smart_ptr_drop(this->args);
  *(&this->args) = nullptr;
  __smart_ptr_drop(this->code);
  *(&this->code) = nullptr;
}

__attribute__((always_inline))
static struct builder_BuildResponse builder_BuildResponse_op__copy(struct builder_BuildResponse * this) {
  struct builder_BuildResponse _rt966 = {};
  _rt966 = (struct builder_BuildResponse){
    .stdout = (struct String *)__smart_ptr_get(this->stdout),
    .stderr = (struct String *)__smart_ptr_get(this->stderr),
    .status = this->status
  };
  return _rt966;
}


static void builder_BuildResponse_op__destructor(struct builder_BuildResponse * this) {
  __smart_ptr_drop(this->stdout);
  *(&this->stdout) = nullptr;
  __smart_ptr_drop(this->stderr);
  *(&this->stderr) = nullptr;
}

__attribute__((always_inline))
static struct builder_RunResponse builder_RunResponse_op__copy(struct builder_RunResponse * this) {
  struct builder_RunResponse _rt967 = {};
  _rt967 = (struct builder_RunResponse){
    .build = builder_BuildResponse_op__copy(&(this->build)),
    .stdout = (struct String *)__smart_ptr_get(this->stdout),
    .stderr = (struct String *)__smart_ptr_get(this->stderr),
    .status = this->status
  };
  return _rt967;
}


static void builder_RunResponse_op__destructor(struct builder_RunResponse * this) {
  builder_BuildResponse_op__destructor(&(this->build));
  memset(&this->build, 0, sizeof(struct builder_BuildResponse));
  __smart_ptr_drop(this->stdout);
  *(&this->stdout) = nullptr;
  __smart_ptr_drop(this->stderr);
  *(&this->stderr) = nullptr;
}

const char* builder_LOG_TAG = "Builder";

static struct os_Union1557 builder_writeFile(struct path_Path * dir, struct String * code) {
  struct os_Union1557 _rt968 = {};
  struct path_Path path = path_Path_op__divIc_sE(dir, "app.cxy");
  const char* _a951 = path_Path_str(&path);
  struct os_Union1644 _res931 = os_FileOutputStream_open(_a951, true, (int32_t)1089, (int32_t)438);
  bool ___res931_dflags = true;
  if (_res931.tag == 1u) {
    struct Exception * ex = _res931._1;
    ___res931_dflags = false;
    builtins_Exception_push(ex, "builder", (const char*) {}, "writeFile", "/workspace/server/builder.cxy", 39u);
    _rt968 = (struct os_Union1557){.tag = 1, ._1 = ex};
    path_Path_op__destructor(&(path));
    return _rt968;
  }
  struct os_FileOutputStream * os = _res931._0;
  ___res931_dflags = false;
  struct OutputStream * _m952 = (struct OutputStream *)os;
  builtins_OutputStream_op__lshiftI_ZString_E(_m952, (const struct String *)code);
  _rt968 = (struct os_Union1557){.tag = 0, ._0 = (struct Void){}};
  path_Path_op__destructor(&(path));
  __smart_ptr_drop(os);
  return _rt968;
}


static struct builder_Union2191 builtins___union_copyI_U_ZbuilderBuildResponse_ZException__E(struct builder_Union2191 * obj) {
  struct builder_Union2191 _rt969 = {};
  switch (obj->tag) {
  case 0u: {
    {
      struct builder_BuildResponse * y = &obj->_0;
      _rt969 = (struct builder_Union2191){.tag = 0, ._0 = builder_BuildResponse_op__copy(y)};
      return _rt969;
    }
  }
  case 1u: {
    {
      struct Exception * y = obj->_1;
      _rt969 = (struct builder_Union2191){.tag = 1, ._1 = __smart_ptr_get(y)};
      return _rt969;
    }
  }
  default: { unreachable("unhandled-default-case"); }
  }
  
}


static void builtins___union_dctorI_U_ZbuilderBuildResponse_ZException__E(struct builder_Union2191 * obj) {
  switch (obj->tag) {
  case 0u: {
    {
      struct builder_BuildResponse * y = &obj->_0;
      builder_BuildResponse_op__destructor(y);
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


static struct builder_Union2191 builder_buildCode(struct isolate_SandboxConfig * config, struct isolate_Sandbox * sandbox, struct builder_BuildRequest * request) {
  struct builder_Union2191 _rt970 = {};
  struct os_Union1557 _res932 = builder_writeFile(&sandbox->path, request->code);
  bool ___res932_dflags = true;
  if (_res932.tag == 1u) {
    struct Exception * ex = _res932._1;
    ___res932_dflags = false;
    builtins_Exception_push(ex, "builder", (const char*) {}, "buildCode", "/workspace/server/builder.cxy", 45u);
    _rt970 = (struct builder_Union2191){.tag = 1, ._1 = ex};
    return _rt970;
  }
  struct String * cmd = builtins_String_op__initI_sECoverI_sE("/cxy/bin/cxy build /box/app.cxy");
  if (builtins_String_size(request->args) > 0) {
    struct OutputStream * _m953 = (struct OutputStream *)cmd;
    struct OutputStream * _m954 = builtins_OutputStream_op__lshiftI_sE(_m953, " ");
    builtins_OutputStream_op__lshiftI_ZString_E(_m954, (const struct String *)request->args);
  }
  if (logger_Level_DEBUG >= logger_Logger_levelIc_E(logger___L)) {
    struct OutputStream * _m955 = logger_Logger_log(logger___L, logger_Level_DEBUG, builder_LOG_TAG);
    struct OutputStream * _m956 = builtins_OutputStream_op__lshiftI_sE(_m955, "executing command: ");
    struct OutputStream * _m957 = builtins_OutputStream_op__lshiftI_ZString_E(_m956, (const struct String *)cmd);
    builtins_OutputStream_op__lshiftI_wE(_m957, '\n');
  };
  const char* _a958 = builtins_String_str(cmd);
  struct os_Union1686 _res933 = isolate_Sandbox_execute(sandbox, config, _a958);
  bool ___res933_dflags = true;
  if (_res933.tag == 1u) {
    struct Exception * ex = _res933._1;
    ___res933_dflags = false;
    builtins_Exception_push(ex, "builder", (const char*) {}, "buildCode", "/workspace/server/builder.cxy", 51u);
    _rt970 = (struct builder_Union2191){.tag = 1, ._1 = ex};
    __CXY_DROP_WITH_FLAGS(___res932_dflags, builtins___union_dctorI_U_ZVoid_ZException__E(&(_res932)));
    ___res932_dflags = false;
    __smart_ptr_drop(cmd);
    return _rt970;
  }
  struct os_Process proc = _res933._0;
  ___res933_dflags = false;
  struct os_Union1669 _res934 = os_Process_waitAsync(&proc);
  bool ___res934_dflags = true;
  if (_res934.tag == 1u) {
    struct Exception * ex = _res934._1;
    ___res934_dflags = false;
    builtins_Exception_push(ex, "builder", (const char*) {}, "buildCode", "/workspace/server/builder.cxy", 52u);
    _rt970 = (struct builder_Union2191){.tag = 1, ._1 = ex};
    __CXY_DROP_WITH_FLAGS(___res932_dflags, builtins___union_dctorI_U_ZVoid_ZException__E(&(_res932)));
    ___res932_dflags = false;
    __smart_ptr_drop(cmd);
    os_Process_op__destructor(&(proc));
    return _rt970;
  }
  int32_t status = _res934._0;
  ___res934_dflags = false;
  struct os_FileInputStream * _m959 = os_Process_stdout(&proc);
  struct os_Union1623 _res935 = os_FileInputStream_readAllI_E(_m959);
  bool ___res935_dflags = true;
  if (_res935.tag == 1u) {
    struct Exception * ex = _res935._1;
    ___res935_dflags = false;
    builtins_Exception_push(ex, "builder", (const char*) {}, "buildCode", "/workspace/server/builder.cxy", 54u);
    _rt970 = (struct builder_Union2191){.tag = 1, ._1 = ex};
    __CXY_DROP_WITH_FLAGS(___res932_dflags, builtins___union_dctorI_U_ZVoid_ZException__E(&(_res932)));
    ___res932_dflags = false;
    __smart_ptr_drop(cmd);
    os_Process_op__destructor(&(proc));
    return _rt970;
  }
  struct builder_BuildResponse response = (struct builder_BuildResponse){
    .stdout = _res935._0,
    .status = status,
    .stderr = (struct String *)nullptr
  };
  ___res935_dflags = false;
  if (status != 0) {
    struct os_FileInputStream * _m960 = os_Process_stderr(&proc);
    struct os_Union1623 _res936 = os_FileInputStream_readAllI_E(_m960);
    bool ___res936_dflags = true;
    if (_res936.tag == 1u) {
      struct Exception * ex = _res936._1;
      ___res936_dflags = false;
      builtins_Exception_push(ex, "builder", (const char*) {}, "buildCode", "/workspace/server/builder.cxy", 58u);
      _rt970 = (struct builder_Union2191){.tag = 1, ._1 = ex};
      __CXY_DROP_WITH_FLAGS(___res932_dflags, builtins___union_dctorI_U_ZVoid_ZException__E(&(_res932)));
      ___res932_dflags = false;
      __smart_ptr_drop(cmd);
      os_Process_op__destructor(&(proc));
      builder_BuildResponse_op__destructor(&(response));
      return _rt970;
    }
    __smart_ptr_drop(response.stderr);
    response.stderr = _res936._0;
    ___res936_dflags = false;
  }
  _rt970 = (struct builder_Union2191){.tag = 0, ._0 = response};
  __CXY_DROP_WITH_FLAGS(___res932_dflags, builtins___union_dctorI_U_ZVoid_ZException__E(&(_res932)));
  ___res932_dflags = false;
  __smart_ptr_drop(cmd);
  os_Process_op__destructor(&(proc));
  return _rt970;
}


static struct builder_Union2191 builder_build(struct isolate_SandboxConfig * config, struct builder_BuildRequest * request) {
  struct builder_Union2191 _rt971 = {};
  struct isolate_Union2164 _res937 = isolate_createSandbox();
  bool ___res937_dflags = true;
  if (_res937.tag == 1u) {
    struct Exception * ex = _res937._1;
    ___res937_dflags = false;
    builtins_Exception_push(ex, "builder", (const char*) {}, "build", "/workspace/server/builder.cxy", 64u);
    _rt971 = (struct builder_Union2191){.tag = 1, ._1 = ex};
    return _rt971;
  }
  struct isolate_Sandbox sandbox = _res937._0;
  ___res937_dflags = false;
  struct builder_Union2191 _res938 = builder_buildCode(config, &sandbox, request);
  bool ___res938_dflags = true;
  if (_res938.tag == 1u) {
    struct Exception * ex = _res938._1;
    ___res938_dflags = false;
    builtins_Exception_push(ex, "builder", (const char*) {}, "build", "/workspace/server/builder.cxy", 65u);
    _rt971 = (struct builder_Union2191){.tag = 1, ._1 = ex};
    isolate_Sandbox_op__destructor(&(sandbox));
    return _rt971;
  }
  _rt971 = (struct builder_Union2191){.tag = 0, ._0 = _res938._0};
  ___res938_dflags = false;
  isolate_Sandbox_op__destructor(&(sandbox));
  return _rt971;
}


static struct builder_Union2201 builtins___union_copyI_U_ZbuilderRunResponse_ZException__E(struct builder_Union2201 * obj) {
  struct builder_Union2201 _rt972 = {};
  switch (obj->tag) {
  case 0u: {
    {
      struct builder_RunResponse * y = &obj->_0;
      _rt972 = (struct builder_Union2201){.tag = 0, ._0 = builder_RunResponse_op__copy(y)};
      return _rt972;
    }
  }
  case 1u: {
    {
      struct Exception * y = obj->_1;
      _rt972 = (struct builder_Union2201){.tag = 1, ._1 = __smart_ptr_get(y)};
      return _rt972;
    }
  }
  default: { unreachable("unhandled-default-case"); }
  }
  
}


static void builtins___union_dctorI_U_ZbuilderRunResponse_ZException__E(struct builder_Union2201 * obj) {
  switch (obj->tag) {
  case 0u: {
    {
      struct builder_RunResponse * y = &obj->_0;
      builder_RunResponse_op__destructor(y);
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


static struct builder_Union2201 builder_run(struct isolate_SandboxConfig * config, struct builder_BuildRequest * request) {
  struct builder_Union2201 _rt973 = {};
  struct isolate_Union2164 _res939 = isolate_createSandbox();
  bool ___res939_dflags = true;
  if (_res939.tag == 1u) {
    struct Exception * ex = _res939._1;
    ___res939_dflags = false;
    builtins_Exception_push(ex, "builder", (const char*) {}, "run", "/workspace/server/builder.cxy", 69u);
    _rt973 = (struct builder_Union2201){.tag = 1, ._1 = ex};
    return _rt973;
  }
  struct isolate_Sandbox sandbox = _res939._0;
  ___res939_dflags = false;
  struct builder_Union2191 _res940 = builder_buildCode(config, &sandbox, request);
  bool ___res940_dflags = true;
  if (_res940.tag == 1u) {
    struct Exception * ex = _res940._1;
    ___res940_dflags = false;
    builtins_Exception_push(ex, "builder", (const char*) {}, "run", "/workspace/server/builder.cxy", 70u);
    _rt973 = (struct builder_Union2201){.tag = 1, ._1 = ex};
    isolate_Sandbox_op__destructor(&(sandbox));
    return _rt973;
  }
  struct builder_BuildResponse build = _res940._0;
  ___res940_dflags = false;
  if (build.status != 0) {
    _rt973 = (struct builder_Union2201){.tag = 0, ._0 = (struct builder_RunResponse){
      .build = builder_BuildResponse_op__copy(&(build)),
      .status = build.status,
      .stdout = (struct String *)nullptr,
      .stderr = (struct String *)nullptr
    }};
    isolate_Sandbox_op__destructor(&(sandbox));
    builder_BuildResponse_op__destructor(&(build));
    return _rt973;
  }
  struct os_Union1686 _res941 = isolate_Sandbox_execute(&sandbox, config, "/box/app");
  bool ___res941_dflags = true;
  if (_res941.tag == 1u) {
    struct Exception * ex = _res941._1;
    ___res941_dflags = false;
    builtins_Exception_push(ex, "builder", (const char*) {}, "run", "/workspace/server/builder.cxy", 78u);
    _rt973 = (struct builder_Union2201){.tag = 1, ._1 = ex};
    isolate_Sandbox_op__destructor(&(sandbox));
    builder_BuildResponse_op__destructor(&(build));
    return _rt973;
  }
  struct os_Process proc = _res941._0;
  ___res941_dflags = false;
  struct os_Union1669 _res942 = os_Process_waitAsync(&proc);
  bool ___res942_dflags = true;
  if (_res942.tag == 1u) {
    struct Exception * ex = _res942._1;
    ___res942_dflags = false;
    builtins_Exception_push(ex, "builder", (const char*) {}, "run", "/workspace/server/builder.cxy", 79u);
    _rt973 = (struct builder_Union2201){.tag = 1, ._1 = ex};
    isolate_Sandbox_op__destructor(&(sandbox));
    builder_BuildResponse_op__destructor(&(build));
    os_Process_op__destructor(&(proc));
    return _rt973;
  }
  int32_t status = _res942._0;
  ___res942_dflags = false;
  struct os_FileInputStream * _m961 = os_Process_stdout(&proc);
  struct os_Union1623 _res943 = os_FileInputStream_readAllI_E(_m961);
  bool ___res943_dflags = true;
  if (_res943.tag == 1u) {
    struct Exception * ex = _res943._1;
    ___res943_dflags = false;
    builtins_Exception_push(ex, "builder", (const char*) {}, "run", "/workspace/server/builder.cxy", 82u);
    _rt973 = (struct builder_Union2201){.tag = 1, ._1 = ex};
    isolate_Sandbox_op__destructor(&(sandbox));
    builder_BuildResponse_op__destructor(&(build));
    os_Process_op__destructor(&(proc));
    return _rt973;
  }
  struct builder_RunResponse response = (struct builder_RunResponse){
    .build = builder_BuildResponse_op__copy(&(build)),
    .stdout = _res943._0,
    .status = status,
    .stderr = (struct String *)nullptr
  };
  ___res943_dflags = false;
  if (status != 0) {
    struct os_FileInputStream * _m962 = os_Process_stderr(&proc);
    struct os_Union1623 _res944 = os_FileInputStream_readAllI_E(_m962);
    bool ___res944_dflags = true;
    if (_res944.tag == 1u) {
      struct Exception * ex = _res944._1;
      ___res944_dflags = false;
      builtins_Exception_push(ex, "builder", (const char*) {}, "run", "/workspace/server/builder.cxy", 86u);
      _rt973 = (struct builder_Union2201){.tag = 1, ._1 = ex};
      isolate_Sandbox_op__destructor(&(sandbox));
      builder_BuildResponse_op__destructor(&(build));
      os_Process_op__destructor(&(proc));
      builder_RunResponse_op__destructor(&(response));
      return _rt973;
    }
    __smart_ptr_drop(response.stderr);
    response.stderr = _res944._0;
    ___res944_dflags = false;
  }
  _rt973 = (struct builder_Union2201){.tag = 0, ._0 = response};
  isolate_Sandbox_op__destructor(&(sandbox));
  builder_BuildResponse_op__destructor(&(build));
  os_Process_op__destructor(&(proc));
  return _rt973;
}


static struct builder_Union2201 builder_source(struct isolate_SandboxConfig * config, struct builder_BuildRequest * request) {
  struct builder_Union2201 _rt974 = {};
  struct isolate_Union2164 _res945 = isolate_createSandbox();
  bool ___res945_dflags = true;
  if (_res945.tag == 1u) {
    struct Exception * ex = _res945._1;
    ___res945_dflags = false;
    builtins_Exception_push(ex, "builder", (const char*) {}, "source", "/workspace/server/builder.cxy", 92u);
    _rt974 = (struct builder_Union2201){.tag = 1, ._1 = ex};
    return _rt974;
  }
  struct isolate_Sandbox sandbox = _res945._0;
  ___res945_dflags = false;
  struct builder_Union2191 _res946 = builder_buildCode(config, &sandbox, request);
  bool ___res946_dflags = true;
  if (_res946.tag == 1u) {
    struct Exception * ex = _res946._1;
    ___res946_dflags = false;
    builtins_Exception_push(ex, "builder", (const char*) {}, "source", "/workspace/server/builder.cxy", 93u);
    _rt974 = (struct builder_Union2201){.tag = 1, ._1 = ex};
    isolate_Sandbox_op__destructor(&(sandbox));
    return _rt974;
  }
  struct builder_BuildResponse build = _res946._0;
  ___res946_dflags = false;
  if (build.status != 0) {
    _rt974 = (struct builder_Union2201){.tag = 0, ._0 = (struct builder_RunResponse){
      .build = builder_BuildResponse_op__copy(&(build)),
      .status = build.status,
      .stdout = (struct String *)nullptr,
      .stderr = (struct String *)nullptr
    }};
    isolate_Sandbox_op__destructor(&(sandbox));
    builder_BuildResponse_op__destructor(&(build));
    return _rt974;
  }
  struct os_Union1686 _res947 = isolate_Sandbox_execute(&sandbox, config, "/usr/bin/cat /box/app.c");
  bool ___res947_dflags = true;
  if (_res947.tag == 1u) {
    struct Exception * ex = _res947._1;
    ___res947_dflags = false;
    builtins_Exception_push(ex, "builder", (const char*) {}, "source", "/workspace/server/builder.cxy", 101u);
    _rt974 = (struct builder_Union2201){.tag = 1, ._1 = ex};
    isolate_Sandbox_op__destructor(&(sandbox));
    builder_BuildResponse_op__destructor(&(build));
    return _rt974;
  }
  struct os_Process proc = _res947._0;
  ___res947_dflags = false;
  struct os_Union1669 _res948 = os_Process_waitAsync(&proc);
  bool ___res948_dflags = true;
  if (_res948.tag == 1u) {
    struct Exception * ex = _res948._1;
    ___res948_dflags = false;
    builtins_Exception_push(ex, "builder", (const char*) {}, "source", "/workspace/server/builder.cxy", 102u);
    _rt974 = (struct builder_Union2201){.tag = 1, ._1 = ex};
    isolate_Sandbox_op__destructor(&(sandbox));
    builder_BuildResponse_op__destructor(&(build));
    os_Process_op__destructor(&(proc));
    return _rt974;
  }
  int32_t status = _res948._0;
  ___res948_dflags = false;
  struct os_FileInputStream * _m963 = os_Process_stdout(&proc);
  struct os_Union1623 _res949 = os_FileInputStream_readAllI_E(_m963);
  bool ___res949_dflags = true;
  if (_res949.tag == 1u) {
    struct Exception * ex = _res949._1;
    ___res949_dflags = false;
    builtins_Exception_push(ex, "builder", (const char*) {}, "source", "/workspace/server/builder.cxy", 105u);
    _rt974 = (struct builder_Union2201){.tag = 1, ._1 = ex};
    isolate_Sandbox_op__destructor(&(sandbox));
    builder_BuildResponse_op__destructor(&(build));
    os_Process_op__destructor(&(proc));
    return _rt974;
  }
  struct builder_RunResponse response = (struct builder_RunResponse){
    .build = builder_BuildResponse_op__copy(&(build)),
    .stdout = _res949._0,
    .status = status,
    .stderr = (struct String *)nullptr
  };
  ___res949_dflags = false;
  if (status != 0) {
    struct os_FileInputStream * _m964 = os_Process_stderr(&proc);
    struct os_Union1623 _res950 = os_FileInputStream_readAllI_E(_m964);
    bool ___res950_dflags = true;
    if (_res950.tag == 1u) {
      struct Exception * ex = _res950._1;
      ___res950_dflags = false;
      builtins_Exception_push(ex, "builder", (const char*) {}, "source", "/workspace/server/builder.cxy", 109u);
      _rt974 = (struct builder_Union2201){.tag = 1, ._1 = ex};
      isolate_Sandbox_op__destructor(&(sandbox));
      builder_BuildResponse_op__destructor(&(build));
      os_Process_op__destructor(&(proc));
      builder_RunResponse_op__destructor(&(response));
      return _rt974;
    }
    __smart_ptr_drop(response.stderr);
    response.stderr = _res950._0;
    ___res950_dflags = false;
  }
  _rt974 = (struct builder_Union2201){.tag = 0, ._0 = response};
  isolate_Sandbox_op__destructor(&(sandbox));
  builder_BuildResponse_op__destructor(&(build));
  os_Process_op__destructor(&(proc));
  return _rt974;
}

/*-----------/home/dev/.cxy/lib/cxy/std/stdlib/vector.cxy-----------*/

/*-----------/home/dev/.cxy/lib/cxy/std/stdlib/hash.cxy-----------*/
typedef uint64_t Array2213[24];
Array2213 hash_HMAP_RIMES = (Array2213){0u, 1u, 5u, 11u, 23u, 53u, 101u, 197u, 389u, 683u, 1259u, 2417u, 4733u, 9371u, 18617u, 37097u, 74093u, 148073u, 296099u, 592019u, 1100009u, 2200013u, 4400021u, 8800019u};

/*-----------/home/dev/.cxy/lib/cxy/std/stdlib/trie.cxy-----------*/

/*-----------/home/dev/.cxy/lib/cxy/std/stdlib/net.cxy-----------*/
typedef struct dns_addrinfo _dns_addrinfo;
struct  dns_addrinfo {
};

typedef struct addrinfo _addrinfo;
typedef struct sockaddr _sockaddr;
typedef char Array2227[14];
struct  sockaddr {
  uint16_t sa_family;
  Array2227 sa_data;
};

struct  addrinfo {
  int32_t ai_flags;
  int32_t ai_family;
  int32_t ai_socktype;
  int32_t ai_protocol;
  uint32_t ai_addrlen;
  struct sockaddr * ai_addr;
  char * ai_canonname;
  struct addrinfo * ai_next;
};

typedef struct dns_resolver _dns_resolver;
struct  dns_resolver {
};

typedef uint32_t dns_type;
enum {
  dns_type_DNS_T_A = 1,
  dns_type_DNS_T_NS = 2,
  dns_type_DNS_T_CNAME = 5,
  dns_type_DNS_T_SOA = 6,
  dns_type_DNS_T_PTR = 12,
  dns_type_DNS_T_MX = 15,
  dns_type_DNS_T_TXT = 16,
  dns_type_DNS_T_AAAA = 28,
  dns_type_DNS_T_SRV = 33,
  dns_type_DNS_T_OPT = 41,
  dns_type_DNS_T_SSHFP = 44,
  dns_type_DNS_T_SPF = 99,
  dns_type_DNS_T_ALL = 255,
};

typedef struct dns_resolv_conf _dns_resolv_conf;
typedef struct sockaddr_storage _sockaddr_storage;
typedef char Array2230[118];
struct  sockaddr_storage {
  uint16_t ss_family;
  Array2230 __ss_padding;
  uint64_t __ss_align;
};

typedef struct sockaddr_storage Array2925[3];
typedef Array1469 Array2926[4];
typedef char Array2927[36];
typedef struct __ext_s997 ___ext_s997;
struct  __ext_s997 {
  bool edns0;
  uint32_t ndots;
  uint32_t timeout;
  uint32_t attempts;
  bool rotate;
  bool recurse;
  bool smart;
  uint32_t tcp;
};

typedef struct __ext_s998 ___ext_s998;
struct  __ext_s998 {
  uint64_t refcount;
};

struct  dns_resolv_conf {
  Array2925 nameserver;
  Array2926 search;
  Array2927 lookup;
  struct __ext_s997 options;
  struct sockaddr_storage iface;
  struct __ext_s998 _;
};

typedef struct dns_hosts _dns_hosts;
struct  dns_hosts {
};

typedef struct dns_hints _dns_hints;
struct  dns_hints {
};

typedef struct dns_cache _dns_cache;
typedef uint64_t(*Func2976)(struct dns_cache *);
typedef struct dns_packet _dns_packet;
typedef uint16_t Array2728[16];
typedef struct dns_s_memo _dns_s_memo;
struct  dns_s_memo {
  uint16_t base;
  uint16_t end;
};

typedef struct __ext_s988 ___ext_s988;
struct  __ext_s988 {
  struct dns_packet * cqe_next;
  struct dns_packet * cqe_prev;
};

typedef union __ext_s991 __ext_s991;
typedef struct dns_header _dns_header;
struct  dns_header {
  uint32_t qid:16;
  uint32_t rd:1;
  uint32_t tc:1;
  uint32_t aa:1;
  uint32_t opcode:4;
  uint32_t qr:1;
  uint32_t rcode:4;
  uint32_t unused:3;
  uint32_t ra:1;
  uint32_t qdcount:16;
  uint32_t ancount:16;
  uint32_t nscount:16;
  uint32_t arcount:16;
};

typedef uint8_t Array2736[1];
union __ext_s991 {
  struct dns_header header;
  Array2736 data;
};

struct  dns_packet {
  Array2728 dict;
  struct dns_s_memo qd;
  struct dns_s_memo an;
  struct dns_s_memo ns;
  struct dns_s_memo ar;
  struct __ext_s988 cqe;
  uint64_t size;
  uint64_t end;
  int32_t __ext_f989:16;
  union __ext_s991 __ext_f990;
};

typedef struct dns_packet *(*Func2977)(struct dns_packet *, struct dns_cache *, int32_t *);
typedef int32_t(*Func2978)(struct dns_packet *, struct dns_cache *);
typedef int32_t(*Func2979)(struct dns_cache *);
typedef struct dns_packet *(*Func2980)(struct dns_cache *, int32_t *);
typedef int16_t(*Func2981)(struct dns_cache *);
typedef void(*Func2982)(struct dns_cache *);
typedef union __ext_s1000 __ext_s1000;
union __ext_s1000 {
  int64_t i;
  void * p;
};

typedef union __ext_s1000 Array2985[3];
typedef struct __ext_s1001 ___ext_s1001;
struct  __ext_s1001 {
  uint64_t refcount;
};

struct  dns_cache {
  void * state;
  Func2976 acquire;
  Func2976 release;
  Func2977 query;
  Func2978 submit;
  Func2979 check;
  Func2980 fetch;
  Func2979 pollfd;
  Func2981 events;
  Func2982 clear;
  Array2985 arg;
  struct __ext_s1001 _;
};

typedef struct dns_options _dns_options;
typedef struct __ext_s1002 ___ext_s1002;
typedef int32_t(*Func2994)(int32_t *, void *);
struct  __ext_s1002 {
  void * arg;
  Func2994 cb;
};

struct  dns_options {
  struct __ext_s1002 closefd;
  int32_t events;
};

typedef struct ifaddrs _ifaddrs;
typedef union __ext_s980 __ext_s980;
union __ext_s980 {
  struct sockaddr * ifu_broadaddr;
  struct sockaddr * ifu_dstaddr;
};

struct  ifaddrs {
  struct ifaddrs * ifa_next;
  char * ifa_name;
  uint32_t ifa_flags;
  struct sockaddr * ifa_addr;
  struct sockaddr * ifa_netmask;
  union __ext_s980 ifa_ifu;
  void * ifa_data;
};

typedef struct net_Address net_Address;
typedef int8_t Array3097[32];
struct  net_Address {
  Array3097 addr;
};

typedef struct in6_addr _in6_addr;
typedef union __ext_s981 __ext_s981;
typedef uint8_t Array2340[16];
typedef uint16_t Array2341[8];
typedef uint32_t Array1358[4];
union __ext_s981 {
  Array2340 __u6_addr8;
  Array2341 __u6_addr16;
  Array1358 __u6_addr32;
};

struct  in6_addr {
  union __ext_s981 __in6_u;
};

typedef int64_t net_IPVersion;
enum {
  net_IPVersion_Any = 0,
  net_IPVersion_V4 = 1,
  net_IPVersion_V6 = 2,
};

typedef struct sockaddr_in _sockaddr_in;
typedef struct in_addr _in_addr;
struct  in_addr {
  uint32_t s_addr;
};

typedef uint8_t Array2346[8];
struct  sockaddr_in {
  uint16_t sin_family;
  uint16_t sin_port;
  struct in_addr sin_addr;
  Array2346 sin_zero;
};

typedef struct sockaddr_in6 _sockaddr_in6;
struct  sockaddr_in6 {
  uint16_t sin6_family;
  uint16_t sin6_port;
  uint32_t sin6_flowinfo;
  struct in6_addr sin6_addr;
  uint32_t sin6_scope_id;
};

typedef char Array3121[46];
typedef char Array1119[8];
extern void dns_ai_close(struct dns_addrinfo * );
extern int32_t dns_ai_pollfd(struct dns_addrinfo * );
extern int32_t dns_ai_nextent(struct addrinfo * * , struct dns_addrinfo * );
extern void dns_res_close(struct dns_resolver * );
extern struct dns_addrinfo * dns_ai_open(const char * , const char * , dns_type , const struct addrinfo * , struct dns_resolver * , int32_t * );
extern struct dns_resolver * dns_res_open(struct dns_resolv_conf * , struct dns_hosts * hosts, struct dns_hints * , struct dns_cache * , const struct dns_options * , int32_t * );
extern struct dns_hints * dns_hints_local(struct dns_resolv_conf * , int32_t * );
extern struct dns_hosts * dns_hosts_local(int32_t * );
extern struct dns_resolv_conf * dns_resconf_local(int32_t * );
extern void freeifaddrs(struct ifaddrs * __ifa);
extern int32_t getifaddrs(struct ifaddrs * * __ifap);
extern const char * inet_ntop(int32_t __af, const void * __cp, char * __buf, uint32_t __len);
extern int32_t inet_pton(int32_t __af, const char * __cp, void * __buf);
static bool net_Address_parseIpv6(struct net_Address * this, const char* ip, uint16_t port);
static bool net_Address_parseIpv4(struct net_Address * this, const char* ip, uint16_t port);
extern const struct in6_addr in6addr_any;

static uint16_t net_htons(uint16_t x) {
  uint16_t _rt1022 = {};
  {
    _rt1022 = builtins___bswap16(x);
    return _rt1022;
  }
}

__attribute__((always_inline))
static uint32_t net_htonl(uint32_t x) {
  uint32_t _rt1023 = {};
  {
    _rt1023 = builtins___bswap32(x);
    return _rt1023;
  }
}

__attribute__((always_inline))
static uint64_t net_htonll(uint64_t x) {
  uint64_t _rt1024 = {};
  {
    _rt1024 = builtins___bswap64(x);
    return _rt1024;
  }
}

__attribute__((always_inline))
static uint16_t net_ntohs(uint16_t x) {
  uint16_t _rt1025 = {};
  {
    _rt1025 = builtins___bswap16(x);
    return _rt1025;
  }
}

__attribute__((always_inline))
static uint32_t net_ntohl(uint32_t x) {
  uint32_t _rt1026 = {};
  {
    _rt1026 = builtins___bswap32(x);
    return _rt1026;
  }
}

__attribute__((always_inline))
static uint64_t net_ntohll(uint64_t x) {
  uint64_t _rt1027 = {};
  {
    _rt1027 = builtins___bswap64(x);
    return _rt1027;
  }
}

struct dns_resolv_conf * net_cxy_DNS_conf = nullptr;
struct dns_hosts * net_cxy_DNS_hosts = nullptr;
struct dns_hints * net_cxy_DNS_hints = nullptr;

static void net_Address_op__initI_E(struct net_Address * this) {
  ((struct sockaddr *)this->addr)->sa_family = 0u;
}


static void net_Address_op__initI_u16ZnetIPVersion_E(struct net_Address * this, uint16_t port, net_IPVersion mode) {
  if (mode == net_IPVersion_Any || mode == net_IPVersion_V4) {
    struct sockaddr_in * ipv4 = (struct sockaddr_in *)this->addr;
    ipv4->sin_family = 2u;
    ipv4->sin_addr.s_addr = net_htonl(0u);
    ipv4->sin_port = net_htons(port);
  } else {
    struct sockaddr_in6 * ipv6 = (struct sockaddr_in6 *)this->addr;
    ipv6->sin6_family = 10u;
    memcpy((void *)&ipv6->sin6_addr, (const void *)&in6addr_any, sizeof(const struct in6_addr));
    ipv6->sin6_port = net_htons(port);
  }
}


static void net_Address_op__initI_su16ZnetIPVersion_E(struct net_Address * this, const char* ip, uint16_t port, net_IPVersion mode) {
  switch (mode) {
  case net_IPVersion_Any: {
    {
      if (!net_Address_parseIpv4(this, ip, port)) {
        net_Address_parseIpv6(this, ip, port);
      }
    }
    break;
  }
  case net_IPVersion_V4: {
    {
      net_Address_parseIpv4(this, ip, port);
    }
    break;
  }
  case net_IPVersion_V6: {
    {
      net_Address_parseIpv6(this, ip, port);
    }
    break;
  }
  default: { unreachable("unhandled-default-case"); }
  }
  
}


static bool net_Address_parseIpv4(struct net_Address * this, const char* ip, uint16_t port) {
  bool _rt1028 = {};
  struct sockaddr_in * ipv4 = (struct sockaddr_in *)this->addr;
  int32_t rc = inet_pton(2, (const char *)ip, (void *)&ipv4->sin_addr);
  if (rc == 1) {
    ipv4->sin_family = 2u;
    ipv4->sin_port = net_htons(port);
    return true;
  } else {
    ipv4->sin_family = 0u;
    return false;
  }
}


static bool net_Address_parseIpv6(struct net_Address * this, const char* ip, uint16_t port) {
  bool _rt1029 = {};
  struct sockaddr_in6 * ipv6 = (struct sockaddr_in6 *)this->addr;
  int32_t rc = inet_pton(10, (const char *)ip, (void *)&ipv6->sin6_addr);
  if (rc == 1) {
    ipv6->sin6_family = 10u;
    ipv6->sin6_port = net_htons(port);
    return true;
  } else {
    ipv6->sin6_family = 0u;
    return false;
  }
}

__attribute__((always_inline))
static uint16_t net_Address_family(const struct net_Address * this) {
  uint16_t _rt1030 = {};
  _rt1030 = ((struct sockaddr *)this->addr)->sa_family;
  return _rt1030;
}

__attribute__((always_inline))
static uint64_t net_Address_len(const struct net_Address * this) {
  uint64_t _rt1031 = {};
  _rt1031 = net_Address_family(this) == 2? sizeof(struct sockaddr_in): sizeof(struct sockaddr_in6);
  return _rt1031;
}

__attribute__((always_inline))
static uint16_t net_Address_port(const struct net_Address * this) {
  uint16_t _rt1032 = {};
  if (net_Address_family(this) == 2) {
    _rt1032 = net_ntohs(((struct sockaddr_in *)this->addr)->sin_port);
    return _rt1032;
  } else {
    _rt1032 = net_ntohs(((struct sockaddr_in6 *)this->addr)->sin6_port);
    return _rt1032;
  }
}


static struct sockaddr * net_Address_nativeAddrI_E(struct net_Address * this) {
  struct sockaddr * _rt1033 = {};
  _rt1033 = (struct sockaddr *)this->addr;
  return _rt1033;
}


static const struct sockaddr * net_Address_nativeAddrIc_E(const struct net_Address * this) {
  const struct sockaddr * _rt1034 = {};
  _rt1034 = (const struct sockaddr *)this->addr;
  return _rt1034;
}

__attribute__((always_inline))
static int8_t net_Address_op__hash(const struct net_Address * this) {
  int8_t _rt1035 = {};
  return 0;
}

__attribute__((always_inline))
static bool net_Address_op__truthy(const struct net_Address * this) {
  bool _rt1036 = {};
  _rt1036 = net_Address_family(this) != 0;
  return _rt1036;
}


static void net_Address_op__str(const struct net_Address * this, struct OutputStream * os) {
  Array3121 buffer = {};
  bool rc = false;
  if (net_Address_family(this) == 2) {
    struct sockaddr_in * ipv4 = (struct sockaddr_in *)this->addr;
    rc = inet_ntop(2, (const void *)&ipv4->sin_addr, (char *)buffer, (uint32_t)16) != nullptr;
  } else {
    struct sockaddr_in6 * ipv6 = (struct sockaddr_in6 *)this->addr;
    rc = inet_ntop(10, (const void *)&ipv6->sin6_addr, (char *)buffer, (uint32_t)46) != nullptr;
  }
  if (rc) {
    builtins_OutputStream_appendStringI_sE(os, (const char*)buffer);
    builtins_OutputStream_appendChar(os, ':');
    uint16_t _a1011 = net_Address_port(this);
    builtins_OutputStream_appendUnSignedInt(os, (uint64_t)_a1011);
  } else {
    builtins_OutputStream_appendStringI_sE(os, "0.0.0.0:0000");
  }
}

__attribute__((always_inline))
static struct net_Address net_Address_op__initCoverI_u16ZnetIPVersion_E(uint16_t port, net_IPVersion mode) {
  struct net_Address _rt1037 = {};
  struct net_Address __obj1009 = (struct net_Address){};
  net_Address_op__initI_u16ZnetIPVersion_E(&__obj1009, port, mode);
  _rt1037 = __obj1009;
  return _rt1037;
}

__attribute__((always_inline))
static struct net_Address net_Address_op__initCoverI_su16ZnetIPVersion_E(const char* ip, uint16_t port, net_IPVersion mode) {
  struct net_Address _rt1038 = {};
  struct net_Address __obj1010 = (struct net_Address){};
  net_Address_op__initI_su16ZnetIPVersion_E(&__obj1010, ip, port, mode);
  _rt1038 = __obj1010;
  return _rt1038;
}


static struct net_Address net_getLocalAddress(const char* name, uint16_t port, net_IPVersion mode) {
  struct net_Address _rt1039 = {};
  if (name[0] == '\0') {
    _rt1039 = net_Address_op__initCoverI_u16ZnetIPVersion_E(port, mode);
    return _rt1039;
  }
  struct net_Address addr = net_Address_op__initCoverI_su16ZnetIPVersion_E(name, port, mode);
  if (net_Address_op__truthy(&addr)) {
    _rt1039 = addr;
    return _rt1039;
  }
  struct ifaddrs * ifaces = nullptr;
  int32_t rc = getifaddrs(&ifaces);
  {
    bool _a1012 = rc == 0;
    __cxy_assert(_a1012, "/home/dev/.cxy/lib/cxy/std/stdlib/net.cxy", 252u, 5u);
  };
  {
    bool _a1013 = ifaces != nullptr;
    __cxy_assert(_a1013, "/home/dev/.cxy/lib/cxy/std/stdlib/net.cxy", 253u, 5u);
  };
  struct ifaddrs * ipv4 = nullptr;
  struct ifaddrs * ipv6 = nullptr;
  struct ifaddrs * it = ifaces;
  while (it != nullptr) {
    {
      if (it->ifa_addr == nullptr) {
        it = it->ifa_next;
        continue;
      }
      if (strcmp((const char*)it->ifa_name, name) != 0) {
        it = it->ifa_next;
        continue;
      }
      struct sockaddr * addr = ((struct sockaddr *)it->ifa_addr);
      if (addr->sa_family == 2) {
        {
          bool _a1014 = ipv4 == nullptr;
          __cxy_assert(_a1014, "/home/dev/.cxy/lib/cxy/std/stdlib/net.cxy", 272u, 13u);
        };
        ipv4 = it;
      } else if (addr->sa_family == 10) {
        {
          bool _a1015 = ipv6 == nullptr;
          __cxy_assert(_a1015, "/home/dev/.cxy/lib/cxy/std/stdlib/net.cxy", 276u, 13u);
        };
        ipv6 = it;
      }
      if (ipv4 != nullptr && ipv6 != nullptr) {
        break;
      }
      it = it->ifa_next;
    }
    
  }
  switch (mode) {
  case net_IPVersion_V4: {
    {
      
    }
    break;
  }
  case net_IPVersion_V6: {
    {
      
    }
    break;
  }
  default: {
    
    break;
  }}
  
  if (ipv4 != nullptr) {
    struct sockaddr_in * inaddr = (struct sockaddr_in *)addr.addr;
    memcpy((void *)inaddr, (const void *)ipv4->ifa_addr, sizeof(struct sockaddr_in));
    inaddr->sin_port = net_htons(port);
  } else if (ipv6 != nullptr) {
    struct sockaddr_in6 * inaddr = (struct sockaddr_in6 *)addr.addr;
    memcpy((void *)inaddr, (const void *)ipv6->ifa_addr, sizeof(struct sockaddr_in6));
    inaddr->sin6_port = net_htons(port);
    printf("size is %lu\n", sizeof(struct sockaddr_in6));
  }
  freeifaddrs(ifaces);
  _rt1039 = addr;
  return _rt1039;
}


static struct net_Address net_getRemoteAddress(const char* name, uint16_t port, net_IPVersion mode) {
  struct net_Address _rt1040 = {};
  int32_t rc = 0;
  struct net_Address addr = net_Address_op__initCoverI_su16ZnetIPVersion_E(name, port, mode);
  if (net_Address_op__truthy(&addr)) {
    _rt1040 = addr;
    return _rt1040;
  }
  if (net_cxy_DNS_conf == nullptr) {
    net_cxy_DNS_conf = dns_resconf_local(&rc);
    {
      bool _a1016 = net_cxy_DNS_conf != nullptr;
      __cxy_assert(_a1016, "/home/dev/.cxy/lib/cxy/std/stdlib/net.cxy", 319u, 9u);
    };
    net_cxy_DNS_hosts = dns_hosts_local(&rc);
    {
      bool _a1017 = net_cxy_DNS_hosts != nullptr;
      __cxy_assert(_a1017, "/home/dev/.cxy/lib/cxy/std/stdlib/net.cxy", 321u, 9u);
    };
    net_cxy_DNS_hints = dn