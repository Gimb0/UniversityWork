/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _BOX_H_RPCGEN
#define _BOX_H_RPCGEN

#define RPCGEN_VERSION	199506

#include <rpc/rpc.h>


struct dimensions {
	float length;
	float width;
	float height;
};
typedef struct dimensions dimensions;
#ifdef __cplusplus
extern "C" bool_t xdr_dimensions(XDR *, dimensions*);
#elif __STDC__
extern  bool_t xdr_dimensions(XDR *, dimensions*);
#else /* Old Style C */
bool_t xdr_dimensions();
#endif /* Old Style C */


struct box_results {
	float surface;
	float volume;
};
typedef struct box_results box_results;
#ifdef __cplusplus
extern "C" bool_t xdr_box_results(XDR *, box_results*);
#elif __STDC__
extern  bool_t xdr_box_results(XDR *, box_results*);
#else /* Old Style C */
bool_t xdr_box_results();
#endif /* Old Style C */


#define RPC_BOX ((rpc_uint)0x40049453)
#define BOXVERSION1 ((rpc_uint)1)

#ifdef __cplusplus
#define BOX_CALC ((rpc_uint)1)
extern "C" box_results * box_calc_1(dimensions *, CLIENT *);
extern "C" box_results * box_calc_1_svc(dimensions *, struct svc_req *);

#elif __STDC__
#define BOX_CALC ((rpc_uint)1)
extern  box_results * box_calc_1(dimensions *, CLIENT *);
extern  box_results * box_calc_1_svc(dimensions *, struct svc_req *);

#else /* Old Style C */
#define BOX_CALC ((rpc_uint)1)
extern  box_results * box_calc_1();
extern  box_results * box_calc_1_svc();
#endif /* Old Style C */

#endif /* !_BOX_H_RPCGEN */
