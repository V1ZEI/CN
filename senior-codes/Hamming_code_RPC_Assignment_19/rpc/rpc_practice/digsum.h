/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _DIGSUM_H_RPCGEN
#define _DIGSUM_H_RPCGEN

#include <rpc/rpc.h>


#ifdef __cplusplus
extern "C" {
#endif


struct in {
	long num1;
	long num2;
};
typedef struct in in;

struct out {
	long res;
};
typedef struct out out;

#define ADD_PROG 0x3123000
#define ADD_VERS 1

#if defined(__STDC__) || defined(__cplusplus)
#define ADDPROC 1
extern  out * addproc_1(in *, CLIENT *);
extern  out * addproc_1_svc(in *, struct svc_req *);
extern int add_prog_1_freeresult (SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define ADDPROC 1
extern  out * addproc_1();
extern  out * addproc_1_svc();
extern int add_prog_1_freeresult ();
#endif /* K&R C */

/* the xdr functions */

#if defined(__STDC__) || defined(__cplusplus)
extern  bool_t xdr_in (XDR *, in*);
extern  bool_t xdr_out (XDR *, out*);

#else /* K&R C */
extern bool_t xdr_in ();
extern bool_t xdr_out ();

#endif /* K&R C */

#ifdef __cplusplus
}
#endif

#endif /* !_DIGSUM_H_RPCGEN */
