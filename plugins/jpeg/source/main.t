value__ntId__ntName__ntTemplate
viewBoundsstepChildrenviewJustifybppconvertJPEGtheJPEGFile	__ntDatatype	__ntFlags ?  ?
 P R O T   @			
 R E C T  lefttoprightbottom < < ????? ????8  			
 A R A Y  				__ntDeclare			viewFlags
viewFormat	viewDrawScriptbitMap			 ?  (
 C L A S   @			
 R E C T  				   P ????? ????$  			
 N U M B     			
 N U M B   ? ??  			 ?  ?
 N U M B    			z f u n c ( )  b e g i n  	 i f   b i t m a p   t h e n  	 	 : D r a w S h a p e ( b i t m a p ,   n i l ) ;    e n d  
 S C P T    			 n i l  
 E V A L    clView c a n v a s  	 									icon			 ?  0
 C L A S   @			
 R E C T  				 H x  ????L  			
 N U M B     			
 N U M B   ? ??  			 ?  ?
 N U M B    		
 P I C T  
clPictureView c a n v a s p  	 				buttonClickScripttext					 ?  ?
 P R O T   @			
 S C P T  B f u n c ( )  : c o n v e r t J P E G ( t h e J P E G f i l e )    			
 E V A L   " D r a w ! "    			
 R E C T  				   ????? ? ?????  			 ? 
 N U M B    protoTextButton D r a w B u t t o n  					H	I					 ?  ?	K @			
 S C P T  ? f u n c ( )  b e g i n  	 / /   e r a s e   t h e   i m a g e .  	 / / c a n v a s : H i d e ( ) ;   c a n v a s : S h o w ( ) ;  	 s e t V a l u e ( c a n v a s p ,   ' i c o n ,   n i l ) ;  e n d    			
 E V A L   " C l e a r "    			
 R E C T  				 ?   ????? ?  ? ?????  			 ? 
 N U M B    	W C l e a r B u t t o n  									I				 ?  ?
 P R O T   @			
 R E C T  				 ?  ? ????? ?  ? ?????  			 ?  ?
 N U M B    			 ? 
 N U M B    			 " 1 2 8 "  
 E V A L    			 ? ??
 N U M B    protoInputLine t h r e s h o l d  	 					title					 ?  ?
 P R O T   @			
 E V A L   " J P E G   V i e w e r "    			
 R E C T   K  			 X
 N U M B    
protoTitle t i t l e  	 				labelCommands	I	labelActionScript	textSetup			 ?  ?
 P R O T   @			
 E V A L  h [  { i t e m :   " H e l l o S m a l l . j p g " ,   v a l u e :   k H e l l o S m a l l J P G }  ]   ?			
 E V A L   " L a b e l "    			
 R E C T  d  			d f u n c ( c m d )  t h e J P E G F i l e   : =   l a b e l C o m m a n d s [ c m d ] . v a l u e  
 S C P T    			? f u n c ( )  L F e t c h ( l a b e l C o m m a n d s ,   t h e J P E G f i l e ,   0 ,   ' | = | ,   ' v a l u e ) . i t e m  
 S C P T    protoLabelPicker p i c t u r e P i c k e r  					?	I		?	?				 ?  ?	? @			
 E V A L    [ " 1 " ,   " 2 " ,   " 4 " ]    			
 E V A L   " b p p "    			
 R E C T  				 ?????  ????? @  			v f u n c ( c m d )  b p p   : =   F l o o r ( S t r i n g T o N u m b e r ( l a b e l C o m m a n d s [ c m d ] ) )  
 S C P T    			p f u n c ( )   / /   r e t u r n   f i r s t   o n e   a s   d e f a u l t  S P r i n t O b j e c t ( b p p )  
 S C P T    			 ?  ?
 N U M B    	? b p p P i c k e r   ?   			 ?  ?
 N U M B    			 
 N U M B    			
 S C P T  ?  ? f u n c (   i m g   )  b e g i n  	 l o c a l   p i c   : =   n i l ;  	  	 l o c a l   d a t a   : =   i m g ;  	 l o c a l   I N T   l e n   : =     L e n g t h (   i m g   ) ;   	 / / d a t a   : =   G e t D e f a u l t S t o r e ( ) : N e w V B O ( ' b i t s , l e n   ) ;  	 / / b i n a r y m u n g e r ( d a t a , 0 , l e n , i m g , 0 , l e n ) ;  	  	 / / s e t c l a s s ( d a t a , ' b i n a r y ) ;  	 l o c a l   t h r e s h   : =   c e i l i n g ( S t r i n g T o N u m b e r ( t h r e s h o l d . t e x t ) ) ;  	  	 / /   w h a t   v e r s i o n ?  	 p r i n t (   c a l l   J P E G . V e r s i o n   w i t h   (   )   ) ;  	 	  	 / /   P r o c e s s   a   J P E G .    	 / /  	 / /   P a r a m e t e r s :  	 / / 	 d a t a   -   t h e   b i n a r y   i m a g e   s t r e a m  	 / /     b p p   -   b i t s   p e r   p i x e l   o f   r e s u l t   i m a g e   ( 1 ,   2 ,   o r   4 )  	 / /     t h r e s h   -   ( u s e d   f o r   b p p = 1 ) .   0 - 2 5 5  	 / / 	 t r u e / f a l s e   -   e n a b l e s / d i s a b l e s   F l o y d - S t e i n b e r g   d i t h e r i n g   	 p i c s   : =   c a l l   J P E G . D e c o m p r e s s   w i t h   (   d a t a ,   b p p ,   t h r e s h ,   t r u e   ) ;    	 / /   C o n v e r t   t o   1 - b p p   i c o n   . . .  	 l o c a l   b f r a m e   : =   {   b o u n d s :   S h a p e B o u n d s ( p i c s ) ,  	 	 	 b i t s :   S e t C l a s s (   p i c s . d a t a ,   ' b i t s )    	 	 	 } ;  	 B i n a r y M u n g e r (   b f r a m e . b i t s , 1 6 , 8 ,   n i l , 0 , n i l ) ;  	  	   	  / * 	 / /   S T E V E ,   t h i s   w a s   c o d e   f o r   s h o w i n g   g r a y   a n i m a t e d   G I F s   s t u f f .   	 l o c a l   p i c   : =   p i c ; 	   	 l o c a l   b n d s   : =   S h a p e B o u n d s ( p i c ) ;  	 l o c a l   b i t s   : =   p i c . d a t a ;  	 B i n a r y M u n g e r ( b i t s , 1 6 , 8 ,   n i l , 0 , n i l ) ;  	 / / B i n a r y M u n g e r ( b i t s , 8 , 4 ,   n i l , 0 , n i l ) ;  	 l o c a l   b f r a m e   : =  	 	 i f   b p p = 1  	 	 t h e n   { b o u n d s :   b n d s ,  	 	 	 b i t s :   S e t C l a s s ( b i t s ,   ' b i t s ) }  	 	 e l s e   { b o u n d s :   b n d s ,                              c o l o r d a t a :   [ { c b i t s :   S e t C l a s s ( b i t s ,   ' c b i t s ) ,   b i t d e p t h :   b p p } , ] ,  	 	 	 	 } ;  	 	 / / 	 P r i n t ( b f r a m e ) ;   	 	 / /   y o u   c a n   u s e   N e w t o n   2 . 0   b i t m a p   c o m m a n d s   o n   t h i s   b i t m a p :  	 	 / / M u n g e B i t m a p (   p i c ,   ' r o t a t e R i g h t ,   n i l   ) ;  	  	 	  	 	 / /   y o u   c a n   s c a l e   t h e   b i t m a p   u s i n g   a   S c a l e S h a p e .    	 	  	 	 / /   ( h e r e   w e   s c a l e   t h e   N e w t   l o g o   t o   ~ 5 0 %   i t s   o r i g i n a l   s i z e )  	 	 / / t o R e c t   : =   S e t B o u n d s ( 5 ,   5 ,   1 2 0 ,   1 6 0 ) ;  	 	 / / S c a l e S h a p e (   p i c ,   n i l ,   t o R e c t   ) ;  	 * /  	   	 t r y  	 	 S e t V a l u e ( c a n v a s p ,   ' i c o n ,   b f r a m e ) ;  	 	 / / c a n v a s : D r a w S h a p e (   b f r a m e ,   n i l   ) ;   / /   p i c  	 o n e x c e p t i o n   | e v t . e x |   d o   N I L ;  	  e n d    			 k H e l l o S m a l l J P G  
 E V A L    protoFloatNGo
 b a s e  