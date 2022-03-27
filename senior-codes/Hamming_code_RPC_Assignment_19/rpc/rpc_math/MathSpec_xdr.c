/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "MathSpec.h"

bool_t
xdr_operations (XDR *xdrs, operations *objp)
{
	register int32_t *buf;

	int i;

	if (xdrs->x_op == XDR_ENCODE) {
		buf = XDR_INLINE (xdrs, (5 +  20 )* BYTES_PER_XDR_UNIT);
		if (buf == NULL) {
			 if (!xdr_int (xdrs, &objp->op1))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->op2))
				 return FALSE;
			 if (!xdr_vector (xdrs, (char *)objp->arr, 20,
				sizeof (int), (xdrproc_t) xdr_int))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->len))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->result))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->operation))
				 return FALSE;
		} else {
			IXDR_PUT_LONG(buf, objp->op1);
			IXDR_PUT_LONG(buf, objp->op2);
			{
				register int *genp;

				for (i = 0, genp = objp->arr;
					i < 20; ++i) {
					IXDR_PUT_LONG(buf, *genp++);
				}
			}
			IXDR_PUT_LONG(buf, objp->len);
			IXDR_PUT_LONG(buf, objp->result);
			IXDR_PUT_LONG(buf, objp->operation);
		}
		return TRUE;
	} else if (xdrs->x_op == XDR_DECODE) {
		buf = XDR_INLINE (xdrs, (5 +  20 )* BYTES_PER_XDR_UNIT);
		if (buf == NULL) {
			 if (!xdr_int (xdrs, &objp->op1))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->op2))
				 return FALSE;
			 if (!xdr_vector (xdrs, (char *)objp->arr, 20,
				sizeof (int), (xdrproc_t) xdr_int))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->len))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->result))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->operation))
				 return FALSE;
		} else {
			objp->op1 = IXDR_GET_LONG(buf);
			objp->op2 = IXDR_GET_LONG(buf);
			{
				register int *genp;

				for (i = 0, genp = objp->arr;
					i < 20; ++i) {
					*genp++ = IXDR_GET_LONG(buf);
				}
			}
			objp->len = IXDR_GET_LONG(buf);
			objp->result = IXDR_GET_LONG(buf);
			objp->operation = IXDR_GET_LONG(buf);
		}
	 return TRUE;
	}

	 if (!xdr_int (xdrs, &objp->op1))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->op2))
		 return FALSE;
	 if (!xdr_vector (xdrs, (char *)objp->arr, 20,
		sizeof (int), (xdrproc_t) xdr_int))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->len))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->result))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->operation))
		 return FALSE;
	return TRUE;
}
