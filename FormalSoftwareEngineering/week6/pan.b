	switch (t->back) {
	default: Uerror("bad return move");
	case  0: goto R999; /* nothing to undo */

		 /* CLAIM never_0 */
;
		;
		
	case 4: // STATE 6
		;
		p_restor(II);
		;
		;
		goto R999;

		 /* PROC Q */
;
		;
		;
		;
		
	case 7: // STATE 3
		;
		formalSW = trpt->bup.oval;
		;
		goto R999;
;
		;
		
	case 9: // STATE 5
		;
		formalSW = trpt->bup.oval;
		;
		goto R999;

	case 10: // STATE 6
		;
		now.critical = trpt->bup.oval;
		;
		goto R999;

	case 11: // STATE 10
		;
		p_restor(II);
		;
		;
		goto R999;

		 /* PROC P */
;
		;
		;
		;
		;
		;
		
	case 15: // STATE 4
		;
		now.critical = trpt->bup.oval;
		;
		goto R999;

	case 16: // STATE 8
		;
		p_restor(II);
		;
		;
		goto R999;
	}

