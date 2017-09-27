// BaseFun.h: interface for the CBaseFun class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BASEFUN_H__78C4A60A_7885_4464_B1C5_839D44F54BAE__INCLUDED_)
#define AFX_BASEFUN_H__78C4A60A_7885_4464_B1C5_839D44F54BAE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if defined(__cplusplus)
extern "C" {
#endif

#if 1 && !defined( USE_INLINING )
#  define USE_INLINING
#endif

#if defined( USE_INLINING )
#  if defined( _MSC_VER )
#    define mh_decl __inline
#  elif defined( __GNUC__ ) || defined( __GNU_LIBRARY__ )
#    define mh_decl static inline
#  else
#    define mh_decl static
#  endif
#endif

#if defined( USE_INLINING )
#  define gf_decl __inline
#endif

typedef unsigned char uint_8t;
typedef unsigned short uint_16t;
typedef unsigned int uint_32t;
typedef unsigned long long uint_64t;

#if defined( UNIT_BITS )
# undef UNIT_BITS
#endif


#if !defined( UNIT_BITS )
#    define UNIT_BITS 32
#endif

#    define VOID_RETURN  void
#    define INT_RETURN   int

#define AES_RETURN INT_RETURN

#define UI_TYPE(size)               uint_##size##t
#define UNIT_TYPEDEF(x,size)        typedef UI_TYPE(size) x
#define BUFR_TYPEDEF(x,size,bsize)  typedef UI_TYPE(size) x[bsize / (size >> 3)]
#define UNIT_CAST(x,size)           ((UI_TYPE(size) )(x))  
#define UPTR_CAST(x,size)           ((UI_TYPE(size)*)(x))

#define AES_128     /* if a fast 128 bit key scheduler is needed    */
#define AES_VAR     /* if variable key size scheduler is needed     */
#define AES_MODES   /* if support is needed for modes               */
#define KS_LENGTH       60

#define gf_m(n,x)    gf_mulx ## n ## x
#define gf_mulx1(x)  gf_m(1,x)
#define gf_mulx4(x)  gf_m(4,x)
#define gf_mulx8(x)  gf_m(8,x)

#define GF_BYTE_LEN 16
#define GF_UNIT_LEN (GF_BYTE_LEN / (UNIT_BITS >> 3))

#define BUF_INC          (UNIT_BITS >> 3)
#define BUF_ADRMASK     ((UNIT_BITS >> 3) - 1)


#define AES_BLOCK_SIZE  16  /* the AES block size in bytes          */
#define N_COLS           4  /* the number of columns in the state   */
#define GCM_BLOCK_SIZE  AES_BLOCK_SIZE

#define RC_LENGTH   (5 * (AES_BLOCK_SIZE / 4 - 2))

#define BLOCK_SIZE      GCM_BLOCK_SIZE      /* block length                 */
#define BLK_ADR_MASK    (BLOCK_SIZE - 1)    /* mask for 'in block' address  */
#define CTR_POS         12

#  define GF_MODE_LB    /* the representation used by GCM */
#  define mode   _lb
#  define GF_INDEX(i)  (i)
#  define t_dec(m,n) t_##m##n
#  define t_set(m,n) t_##m##n
#  define t_use(m,n) t_##m##n

#define DO_TABLES
#define FIXED_TABLES
#  define FT4_SET

#  define to_byte(x)  ((x) & 0xff)
// #  define upr(x,n)      (((uint_32t)(x) << (8 * (n))) | ((uint_32t)(x) >> (32 - 8 * (n))))
// #  define ups(x,n)      ((uint_32t) (x) << (8 * (n)))
#  define bval(x,n)     to_byte((x) >> (8 * (n)))
#  define bytes2word(b0, b1, b2, b3)  \
	(((uint_32t)(b3) << 24) | ((uint_32t)(b2) << 16) | ((uint_32t)(b1) << 8) | (b0))

#define vf1(x,r,c)  (x)
#define rf1(r,c)    (r)
#define rf2(r,c)    ((8+r-c)&3)



#if defined(FIXED_TABLES)

#define sb_data(w) {\
	w(0x63), w(0x7c), w(0x77), w(0x7b), w(0xf2), w(0x6b), w(0x6f), w(0xc5),\
	w(0x30), w(0x01), w(0x67), w(0x2b), w(0xfe), w(0xd7), w(0xab), w(0x76),\
	w(0xca), w(0x82), w(0xc9), w(0x7d), w(0xfa), w(0x59), w(0x47), w(0xf0),\
	w(0xad), w(0xd4), w(0xa2), w(0xaf), w(0x9c), w(0xa4), w(0x72), w(0xc0),\
	w(0xb7), w(0xfd), w(0x93), w(0x26), w(0x36), w(0x3f), w(0xf7), w(0xcc),\
	w(0x34), w(0xa5), w(0xe5), w(0xf1), w(0x71), w(0xd8), w(0x31), w(0x15),\
	w(0x04), w(0xc7), w(0x23), w(0xc3), w(0x18), w(0x96), w(0x05), w(0x9a),\
	w(0x07), w(0x12), w(0x80), w(0xe2), w(0xeb), w(0x27), w(0xb2), w(0x75),\
	w(0x09), w(0x83), w(0x2c), w(0x1a), w(0x1b), w(0x6e), w(0x5a), w(0xa0),\
	w(0x52), w(0x3b), w(0xd6), w(0xb3), w(0x29), w(0xe3), w(0x2f), w(0x84),\
	w(0x53), w(0xd1), w(0x00), w(0xed), w(0x20), w(0xfc), w(0xb1), w(0x5b),\
	w(0x6a), w(0xcb), w(0xbe), w(0x39), w(0x4a), w(0x4c), w(0x58), w(0xcf),\
	w(0xd0), w(0xef), w(0xaa), w(0xfb), w(0x43), w(0x4d), w(0x33), w(0x85),\
	w(0x45), w(0xf9), w(0x02), w(0x7f), w(0x50), w(0x3c), w(0x9f), w(0xa8),\
	w(0x51), w(0xa3), w(0x40), w(0x8f), w(0x92), w(0x9d), w(0x38), w(0xf5),\
	w(0xbc), w(0xb6), w(0xda), w(0x21), w(0x10), w(0xff), w(0xf3), w(0xd2),\
	w(0xcd), w(0x0c), w(0x13), w(0xec), w(0x5f), w(0x97), w(0x44), w(0x17),\
	w(0xc4), w(0xa7), w(0x7e), w(0x3d), w(0x64), w(0x5d), w(0x19), w(0x73),\
	w(0x60), w(0x81), w(0x4f), w(0xdc), w(0x22), w(0x2a), w(0x90), w(0x88),\
	w(0x46), w(0xee), w(0xb8), w(0x14), w(0xde), w(0x5e), w(0x0b), w(0xdb),\
	w(0xe0), w(0x32), w(0x3a), w(0x0a), w(0x49), w(0x06), w(0x24), w(0x5c),\
	w(0xc2), w(0xd3), w(0xac), w(0x62), w(0x91), w(0x95), w(0xe4), w(0x79),\
	w(0xe7), w(0xc8), w(0x37), w(0x6d), w(0x8d), w(0xd5), w(0x4e), w(0xa9),\
	w(0x6c), w(0x56), w(0xf4), w(0xea), w(0x65), w(0x7a), w(0xae), w(0x08),\
	w(0xba), w(0x78), w(0x25), w(0x2e), w(0x1c), w(0xa6), w(0xb4), w(0xc6),\
	w(0xe8), w(0xdd), w(0x74), w(0x1f), w(0x4b), w(0xbd), w(0x8b), w(0x8a),\
	w(0x70), w(0x3e), w(0xb5), w(0x66), w(0x48), w(0x03), w(0xf6), w(0x0e),\
	w(0x61), w(0x35), w(0x57), w(0xb9), w(0x86), w(0xc1), w(0x1d), w(0x9e),\
	w(0xe1), w(0xf8), w(0x98), w(0x11), w(0x69), w(0xd9), w(0x8e), w(0x94),\
	w(0x9b), w(0x1e), w(0x87), w(0xe9), w(0xce), w(0x55), w(0x28), w(0xdf),\
	w(0x8c), w(0xa1), w(0x89), w(0x0d), w(0xbf), w(0xe6), w(0x42), w(0x68),\
	w(0x41), w(0x99), w(0x2d), w(0x0f), w(0xb0), w(0x54), w(0xbb), w(0x16) }

#define isb_data(w) {\
	w(0x52), w(0x09), w(0x6a), w(0xd5), w(0x30), w(0x36), w(0xa5), w(0x38),\
	w(0xbf), w(0x40), w(0xa3), w(0x9e), w(0x81), w(0xf3), w(0xd7), w(0xfb),\
	w(0x7c), w(0xe3), w(0x39), w(0x82), w(0x9b), w(0x2f), w(0xff), w(0x87),\
	w(0x34), w(0x8e), w(0x43), w(0x44), w(0xc4), w(0xde), w(0xe9), w(0xcb),\
	w(0x54), w(0x7b), w(0x94), w(0x32), w(0xa6), w(0xc2), w(0x23), w(0x3d),\
	w(0xee), w(0x4c), w(0x95), w(0x0b), w(0x42), w(0xfa), w(0xc3), w(0x4e),\
	w(0x08), w(0x2e), w(0xa1), w(0x66), w(0x28), w(0xd9), w(0x24), w(0xb2),\
	w(0x76), w(0x5b), w(0xa2), w(0x49), w(0x6d), w(0x8b), w(0xd1), w(0x25),\
	w(0x72), w(0xf8), w(0xf6), w(0x64), w(0x86), w(0x68), w(0x98), w(0x16),\
	w(0xd4), w(0xa4), w(0x5c), w(0xcc), w(0x5d), w(0x65), w(0xb6), w(0x92),\
	w(0x6c), w(0x70), w(0x48), w(0x50), w(0xfd), w(0xed), w(0xb9), w(0xda),\
	w(0x5e), w(0x15), w(0x46), w(0x57), w(0xa7), w(0x8d), w(0x9d), w(0x84),\
	w(0x90), w(0xd8), w(0xab), w(0x00), w(0x8c), w(0xbc), w(0xd3), w(0x0a),\
	w(0xf7), w(0xe4), w(0x58), w(0x05), w(0xb8), w(0xb3), w(0x45), w(0x06),\
	w(0xd0), w(0x2c), w(0x1e), w(0x8f), w(0xca), w(0x3f), w(0x0f), w(0x02),\
	w(0xc1), w(0xaf), w(0xbd), w(0x03), w(0x01), w(0x13), w(0x8a), w(0x6b),\
	w(0x3a), w(0x91), w(0x11), w(0x41), w(0x4f), w(0x67), w(0xdc), w(0xea),\
	w(0x97), w(0xf2), w(0xcf), w(0xce), w(0xf0), w(0xb4), w(0xe6), w(0x73),\
	w(0x96), w(0xac), w(0x74), w(0x22), w(0xe7), w(0xad), w(0x35), w(0x85),\
	w(0xe2), w(0xf9), w(0x37), w(0xe8), w(0x1c), w(0x75), w(0xdf), w(0x6e),\
	w(0x47), w(0xf1), w(0x1a), w(0x71), w(0x1d), w(0x29), w(0xc5), w(0x89),\
	w(0x6f), w(0xb7), w(0x62), w(0x0e), w(0xaa), w(0x18), w(0xbe), w(0x1b),\
	w(0xfc), w(0x56), w(0x3e), w(0x4b), w(0xc6), w(0xd2), w(0x79), w(0x20),\
	w(0x9a), w(0xdb), w(0xc0), w(0xfe), w(0x78), w(0xcd), w(0x5a), w(0xf4),\
	w(0x1f), w(0xdd), w(0xa8), w(0x33), w(0x88), w(0x07), w(0xc7), w(0x31),\
	w(0xb1), w(0x12), w(0x10), w(0x59), w(0x27), w(0x80), w(0xec), w(0x5f),\
	w(0x60), w(0x51), w(0x7f), w(0xa9), w(0x19), w(0xb5), w(0x4a), w(0x0d),\
	w(0x2d), w(0xe5), w(0x7a), w(0x9f), w(0x93), w(0xc9), w(0x9c), w(0xef),\
	w(0xa0), w(0xe0), w(0x3b), w(0x4d), w(0xae), w(0x2a), w(0xf5), w(0xb0),\
	w(0xc8), w(0xeb), w(0xbb), w(0x3c), w(0x83), w(0x53), w(0x99), w(0x61),\
	w(0x17), w(0x2b), w(0x04), w(0x7e), w(0xba), w(0x77), w(0xd6), w(0x26),\
	w(0xe1), w(0x69), w(0x14), w(0x63), w(0x55), w(0x21), w(0x0c), w(0x7d) }

#define mm_data(w) {\
	w(0x00), w(0x01), w(0x02), w(0x03), w(0x04), w(0x05), w(0x06), w(0x07),\
	w(0x08), w(0x09), w(0x0a), w(0x0b), w(0x0c), w(0x0d), w(0x0e), w(0x0f),\
	w(0x10), w(0x11), w(0x12), w(0x13), w(0x14), w(0x15), w(0x16), w(0x17),\
	w(0x18), w(0x19), w(0x1a), w(0x1b), w(0x1c), w(0x1d), w(0x1e), w(0x1f),\
	w(0x20), w(0x21), w(0x22), w(0x23), w(0x24), w(0x25), w(0x26), w(0x27),\
	w(0x28), w(0x29), w(0x2a), w(0x2b), w(0x2c), w(0x2d), w(0x2e), w(0x2f),\
	w(0x30), w(0x31), w(0x32), w(0x33), w(0x34), w(0x35), w(0x36), w(0x37),\
	w(0x38), w(0x39), w(0x3a), w(0x3b), w(0x3c), w(0x3d), w(0x3e), w(0x3f),\
	w(0x40), w(0x41), w(0x42), w(0x43), w(0x44), w(0x45), w(0x46), w(0x47),\
	w(0x48), w(0x49), w(0x4a), w(0x4b), w(0x4c), w(0x4d), w(0x4e), w(0x4f),\
	w(0x50), w(0x51), w(0x52), w(0x53), w(0x54), w(0x55), w(0x56), w(0x57),\
	w(0x58), w(0x59), w(0x5a), w(0x5b), w(0x5c), w(0x5d), w(0x5e), w(0x5f),\
	w(0x60), w(0x61), w(0x62), w(0x63), w(0x64), w(0x65), w(0x66), w(0x67),\
	w(0x68), w(0x69), w(0x6a), w(0x6b), w(0x6c), w(0x6d), w(0x6e), w(0x6f),\
	w(0x70), w(0x71), w(0x72), w(0x73), w(0x74), w(0x75), w(0x76), w(0x77),\
	w(0x78), w(0x79), w(0x7a), w(0x7b), w(0x7c), w(0x7d), w(0x7e), w(0x7f),\
	w(0x80), w(0x81), w(0x82), w(0x83), w(0x84), w(0x85), w(0x86), w(0x87),\
	w(0x88), w(0x89), w(0x8a), w(0x8b), w(0x8c), w(0x8d), w(0x8e), w(0x8f),\
	w(0x90), w(0x91), w(0x92), w(0x93), w(0x94), w(0x95), w(0x96), w(0x97),\
	w(0x98), w(0x99), w(0x9a), w(0x9b), w(0x9c), w(0x9d), w(0x9e), w(0x9f),\
	w(0xa0), w(0xa1), w(0xa2), w(0xa3), w(0xa4), w(0xa5), w(0xa6), w(0xa7),\
	w(0xa8), w(0xa9), w(0xaa), w(0xab), w(0xac), w(0xad), w(0xae), w(0xaf),\
	w(0xb0), w(0xb1), w(0xb2), w(0xb3), w(0xb4), w(0xb5), w(0xb6), w(0xb7),\
	w(0xb8), w(0xb9), w(0xba), w(0xbb), w(0xbc), w(0xbd), w(0xbe), w(0xbf),\
	w(0xc0), w(0xc1), w(0xc2), w(0xc3), w(0xc4), w(0xc5), w(0xc6), w(0xc7),\
	w(0xc8), w(0xc9), w(0xca), w(0xcb), w(0xcc), w(0xcd), w(0xce), w(0xcf),\
	w(0xd0), w(0xd1), w(0xd2), w(0xd3), w(0xd4), w(0xd5), w(0xd6), w(0xd7),\
	w(0xd8), w(0xd9), w(0xda), w(0xdb), w(0xdc), w(0xdd), w(0xde), w(0xdf),\
	w(0xe0), w(0xe1), w(0xe2), w(0xe3), w(0xe4), w(0xe5), w(0xe6), w(0xe7),\
	w(0xe8), w(0xe9), w(0xea), w(0xeb), w(0xec), w(0xed), w(0xee), w(0xef),\
	w(0xf0), w(0xf1), w(0xf2), w(0xf3), w(0xf4), w(0xf5), w(0xf6), w(0xf7),\
	w(0xf8), w(0xf9), w(0xfa), w(0xfb), w(0xfc), w(0xfd), w(0xfe), w(0xff) }

#define rc_data(w) {\
	w(0x01), w(0x02), w(0x04), w(0x08), w(0x10),w(0x20), w(0x40), w(0x80),\
	w(0x1b), w(0x36) }

#define h0(x)   (x)

#define w0(p)   bytes2word(p, 0, 0, 0)
#define w1(p)   bytes2word(0, p, 0, 0)
#define w2(p)   bytes2word(0, 0, p, 0)
#define w3(p)   bytes2word(0, 0, 0, p)

#define u0(p)   bytes2word(f2(p), p, p, f3(p))
#define u1(p)   bytes2word(f3(p), f2(p), p, p)
#define u2(p)   bytes2word(p, f3(p), f2(p), p)
#define u3(p)   bytes2word(p, p, f3(p), f2(p))

#define v0(p)   bytes2word(fe(p), f9(p), fd(p), fb(p))
#define v1(p)   bytes2word(fb(p), fe(p), f9(p), fd(p))
#define v2(p)   bytes2word(fd(p), fb(p), fe(p), f9(p))
#define v3(p)   bytes2word(f9(p), fd(p), fb(p), fe(p))

#endif

#define WPOLY   0x011b
#define BPOLY     0x1b

#define f2(x)   ((x<<1) ^ (((x>>7) & 1) * WPOLY))
#define f4(x)   ((x<<2) ^ (((x>>6) & 1) * WPOLY) ^ (((x>>6) & 2) * WPOLY))
#define f8(x)   ((x<<3) ^ (((x>>5) & 1) * WPOLY) ^ (((x>>5) & 2) * WPOLY) \
	^ (((x>>5) & 4) * WPOLY))

#define f3(x)   (f2(x) ^ x)
#define f9(x)   (f8(x) ^ x)
#define fb(x)   (f8(x) ^ f2(x) ^ x)
#define fd(x)   (f8(x) ^ f4(x) ^ x)
#define fe(x)   (f8(x) ^ f4(x) ^ f2(x))

//#  define brot(x,n)   (((uint_32t)(x) <<  n) | ((uint_32t)(x) >> (32 - n)))
//#  define aes_sw32(x) ((brot((x),8) & 0x00ff00ff) | (brot((x),24) & 0xff00ff00))

#  define inv_mcol(x)       four_tables(x,t_use(i,m),vf1,rf1,0)
#define ff(x)   inv_mcol(x)

#define d_4(t,n,b,e,f,g,h)  const  t n[4][256] = { b(e), b(f), b(g), b(h) }

const uint_32t t_dec(r,c)[RC_LENGTH] = rc_data(w0);

d_4(uint_32t, t_dec(f,n), sb_data, u0, u1, u2, u3);  //������
d_4(uint_32t, t_dec(f,l), sb_data, w0, w1, w2, w3);

d_4(uint_32t, t_dec(i,n), isb_data, v0, v1, v2, v3);  //������
d_4(uint_32t, t_dec(i,l), isb_data, w0, w1, w2, w3);
d_4(uint_32t, t_dec(i,m), mm_data, v0, v1, v2, v3);
/* the character array 'inf' in the following structures is used    */
/* to hold AES context information. This AES code uses cx->inf.b[0] */
/* to hold the number of rounds multiplied by 16. The other three   */
/* elements can be used by code that implements additional modes    */

typedef union
{   uint_32t l;
    uint_8t b[4];
} aes_inf;
typedef struct
{  
   uint_32t ks[KS_LENGTH];
   aes_inf inf;
} aes_encrypt_ctx;

typedef struct
{   
	uint_32t ks[KS_LENGTH];
    aes_inf inf;
} aes_decrypt_ctx;

/* This routine must be called before first use if non-static       */
/* tables are being used                                            */

//AES_RETURN aes_init(void);


#define DATA_256(q) {\
    q(0x00), q(0x01), q(0x02), q(0x03), q(0x04), q(0x05), q(0x06), q(0x07),\
    q(0x08), q(0x09), q(0x0a), q(0x0b), q(0x0c), q(0x0d), q(0x0e), q(0x0f),\
    q(0x10), q(0x11), q(0x12), q(0x13), q(0x14), q(0x15), q(0x16), q(0x17),\
    q(0x18), q(0x19), q(0x1a), q(0x1b), q(0x1c), q(0x1d), q(0x1e), q(0x1f),\
    q(0x20), q(0x21), q(0x22), q(0x23), q(0x24), q(0x25), q(0x26), q(0x27),\
    q(0x28), q(0x29), q(0x2a), q(0x2b), q(0x2c), q(0x2d), q(0x2e), q(0x2f),\
    q(0x30), q(0x31), q(0x32), q(0x33), q(0x34), q(0x35), q(0x36), q(0x37),\
    q(0x38), q(0x39), q(0x3a), q(0x3b), q(0x3c), q(0x3d), q(0x3e), q(0x3f),\
    q(0x40), q(0x41), q(0x42), q(0x43), q(0x44), q(0x45), q(0x46), q(0x47),\
    q(0x48), q(0x49), q(0x4a), q(0x4b), q(0x4c), q(0x4d), q(0x4e), q(0x4f),\
    q(0x50), q(0x51), q(0x52), q(0x53), q(0x54), q(0x55), q(0x56), q(0x57),\
    q(0x58), q(0x59), q(0x5a), q(0x5b), q(0x5c), q(0x5d), q(0x5e), q(0x5f),\
    q(0x60), q(0x61), q(0x62), q(0x63), q(0x64), q(0x65), q(0x66), q(0x67),\
    q(0x68), q(0x69), q(0x6a), q(0x6b), q(0x6c), q(0x6d), q(0x6e), q(0x6f),\
    q(0x70), q(0x71), q(0x72), q(0x73), q(0x74), q(0x75), q(0x76), q(0x77),\
    q(0x78), q(0x79), q(0x7a), q(0x7b), q(0x7c), q(0x7d), q(0x7e), q(0x7f),\
    q(0x80), q(0x81), q(0x82), q(0x83), q(0x84), q(0x85), q(0x86), q(0x87),\
    q(0x88), q(0x89), q(0x8a), q(0x8b), q(0x8c), q(0x8d), q(0x8e), q(0x8f),\
    q(0x90), q(0x91), q(0x92), q(0x93), q(0x94), q(0x95), q(0x96), q(0x97),\
    q(0x98), q(0x99), q(0x9a), q(0x9b), q(0x9c), q(0x9d), q(0x9e), q(0x9f),\
    q(0xa0), q(0xa1), q(0xa2), q(0xa3), q(0xa4), q(0xa5), q(0xa6), q(0xa7),\
    q(0xa8), q(0xa9), q(0xaa), q(0xab), q(0xac), q(0xad), q(0xae), q(0xaf),\
    q(0xb0), q(0xb1), q(0xb2), q(0xb3), q(0xb4), q(0xb5), q(0xb6), q(0xb7),\
    q(0xb8), q(0xb9), q(0xba), q(0xbb), q(0xbc), q(0xbd), q(0xbe), q(0xbf),\
    q(0xc0), q(0xc1), q(0xc2), q(0xc3), q(0xc4), q(0xc5), q(0xc6), q(0xc7),\
    q(0xc8), q(0xc9), q(0xca), q(0xcb), q(0xcc), q(0xcd), q(0xce), q(0xcf),\
    q(0xd0), q(0xd1), q(0xd2), q(0xd3), q(0xd4), q(0xd5), q(0xd6), q(0xd7),\
    q(0xd8), q(0xd9), q(0xda), q(0xdb), q(0xdc), q(0xdd), q(0xde), q(0xdf),\
    q(0xe0), q(0xe1), q(0xe2), q(0xe3), q(0xe4), q(0xe5), q(0xe6), q(0xe7),\
    q(0xe8), q(0xe9), q(0xea), q(0xeb), q(0xec), q(0xed), q(0xee), q(0xef),\
    q(0xf0), q(0xf1), q(0xf2), q(0xf3), q(0xf4), q(0xf5), q(0xf6), q(0xf7),\
    q(0xf8), q(0xf9), q(0xfa), q(0xfb), q(0xfc), q(0xfd), q(0xfe), q(0xff) }

/*  Within the 16 bytes of the field element the top and bottom field bits
    are within bytes as follows (bit numbers in bytes 0 from ls up) for
    each of the four field representations supported (see gf128mul.txt):

    GF_BIT   127 126 125 124 123 122 121 120     .....  7 6 5 4 3 2 1 0
                                                  0x87  1 0 0 0 0 1 1 1
    BL x[ 0]   7   6   5   4   3   2   1   0     x[15]  7 6 5 4 3 2 1 0
    LL x[15]   7   6   5   4   3   2   1   0     x[ 0]  7 6 5 4 3 2 1 0

    GF_BIT   120 121 122 123 124 125 126 127     .....  0 1 2 3 4 5 6 7
                                                  0xc1  1 1 1 0 0 0 0 1
    BB x[ 0]   7   6   5   4   3   2   1   0     x[15]  7 6 5 4 3 2 1 0
    LB x[15]   7   6   5   4   3   2   1   0     x[ 0]  7 6 5 4 3 2 1 0

    When the field element is multiplied by x^n, the high bits overflow
    and are used to form an overflow byte. For the BL and LL modes this
    byte has the lowest overflow bit in bit 0 whereas for the BB and LB
    modes this bit is in biit 7.  So we have for this byte:

    bit (bit n = 2^n)    7   6   5   4   3   2   1   0
    BL and LL          x^7 x^6 x^5 x^4 x^3 x^2 x^1 x^0  
    BB and LB          x^0 x^1 x^2 x^3 x^4 x^5 x^6 x^7  
    
    This byte then has to be multiplied by the low bits of the field
    polynomial, which produces a value of 16 bits to be xored into the 
    left shifted field value. For the BL and LL modes bit 0 gives the
    word value 0x0087, bit 1 gives 0x010e (0x87 left shifted 1), 0x021c
    (0x87 left shifted 2), ... For the BB and LB modes, bit 7 gives the
    value 0x00e1, bit 6 gives 0x8070, bit 5 gives 0x4038, ... Each bit
    in the overflow byte is expanded in this way and is xored into the
    overall result, so eaach of the 256 byte values will produce a
    corresponding word value that is computed by the gf_uint16_xor(i)
    macros below.

    These word values have to be xored into the low 16 bits of the 
    field value. If the byte endianess of the mode matches that of
    the architecture xoring the word value will be correct. But if
    the mode has the opposite endianess, the word value has to be
    xored in byte reversed order. This is done by the ord() macro.
*/
/* field and numeric bit significance are in reverse */
#  define ord(hi, lo)   0x##hi##lo

#define gf_uint16_xor(i) ( \
	(i & 0x80 ? ord(00,e1) : 0) ^ (i & 0x40 ? ord(80,70) : 0) ^ \
	(i & 0x20 ? ord(40,38) : 0) ^ (i & 0x10 ? ord(20,1c) : 0) ^ \
	(i & 0x08 ? ord(10,0e) : 0) ^ (i & 0x04 ? ord(08,07) : 0) ^ \
	(i & 0x02 ? ord(84,03) : 0) ^ (i & 0x01 ? ord(c2,01) : 0) )

const uint_16t gf_tab[256] = DATA_256(gf_uint16_xor);

//BUFR_TYPEDEF(gf_t, UNIT_BITS, GF_BYTE_LEN);


#define MASK(x) ((x) * (UNIT_CAST(-1,UNIT_BITS) / 0xff))
#define f1_lb(n,r,x)   r[n] = (x[n] >> 1) & ~MASK(0x80) | ((x[n] << 15) \
 	| (n ? x[n-1] >> 17 : 0)) & MASK(0x80)
// #define f4_lb(n,r,x)   r[n] = (x[n] >> 4) & ~MASK(0xf0) | ((x[n] << 12) \
// 	| (n ? x[n-1] >> 20 : 0)) & MASK(0xf0)
#define f8_lb(n,r,x)   r[n] = (x[n] << 8) | (n ? x[n-1] >> 24 : 0)

#define rep2_u2(f,r,x)    f( 0,r,x); f( 1,r,x) 
#define rep2_u4(f,r,x)    f( 0,r,x); f( 1,r,x); f( 2,r,x); f( 3,r,x) 

#define rep2_d2(f,r,x)    f( 1,r,x); f( 0,r,x) 
#define rep2_d4(f,r,x)    f( 3,r,x); f( 2,r,x); f( 1,r,x); f( 0,r,x) 

#define rep3_u2(f,r,x,y,c)  f( 0,r,x,y,c); f( 1,r,x,y,c) 
#define rep3_u4(f,r,x,y,c)  f( 0,r,x,y,c); f( 1,r,x,y,c); f( 2,r,x,y,c); f( 3,r,x,y,c) 
#define rep3_u16(f,r,x,y,c) f( 0,r,x,y,c); f( 1,r,x,y,c); f( 2,r,x,y,c); f( 3,r,x,y,c); \
	f( 4,r,x,y,c); f( 5,r,x,y,c); f( 6,r,x,y,c); f( 7,r,x,y,c); \
	f( 8,r,x,y,c); f( 9,r,x,y,c); f(10,r,x,y,c); f(11,r,x,y,c); \
	f(12,r,x,y,c); f(13,r,x,y,c); f(14,r,x,y,c); f(15,r,x,y,c)
#define four_tables(x,tab,vf,rf,c) \
	(  tab[0][bval(vf(x,0,c),rf(0,c))] \
	^ tab[1][bval(vf(x,1,c),rf(1,c))] \
	^ tab[2][bval(vf(x,2,c),rf(2,c))] \
	^ tab[3][bval(vf(x,3,c),rf(3,c))])

#define UI8_PTR(x)     UPTR_CAST(x,  8)
#define UI32_PTR(x)     UPTR_CAST(x, 32)
#define UNIT_PTR(x)     UPTR_CAST(x, UNIT_BITS)

#define  UI8_VAL(x)     UNIT_CAST(x,  8)
#define UI32_VAL(x)     UNIT_CAST(x, 32)
#define UNIT_VAL(x)     UNIT_CAST(x, UNIT_BITS)

#define f_copy(n,p,q)     p[n] = q[n]
#define f_xor(n,r,p,q,c)  r[n] = c(p[n] ^ q[n])

#  define word_in(x,c)    (*((uint_32t*)(x)+(c)))
#  define word_out(x,c,v) (*((uint_32t*)(x)+(c)) = (v))

enum x_bit 
{ 
	X_0 = 0x80, X_1 = 0x40, X_2 = 0x20, X_3 = 0x10, 
	X_4 = 0x08, X_5 = 0x04, X_6 = 0x02, X_7 = 0x01
};

#if defined(__cplusplus)
}
#endif

#endif // !defined(AFX_BASEFUN_H__78C4A60A_7885_4464_B1C5_849D44F54BAE__INCLUDED_)
