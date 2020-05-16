	switch (t->back) {
	default: Uerror("bad return move");
	case  0: goto R999; /* nothing to undo */

		 /* PROC :init: */

	case 3: // STATE 1
		;
		;
		delproc(0, now._nr_pr-1);
		;
		goto R999;

	case 4: // STATE 2
		;
		p_restor(II);
		;
		;
		goto R999;

		 /* PROC testcount */
;
		;
		
	case 6: // STATE 2
		;
		((P0 *)_this)->x = trpt->bup.oval;
		;
		goto R999;

	case 7: // STATE 3
		;
		((P0 *)_this)->x = trpt->bup.oval;
		;
		goto R999;
;
		
	case 8: // STATE 4
		goto R999;
;
		
	case 9: // STATE 12
		goto R999;

	case 10: // STATE 14
		;
		p_restor(II);
		;
		;
		goto R999;
	}

