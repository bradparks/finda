package finda;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class Fun_eb5b71ee extends haxe.lang.Function
{
	public    Fun_eb5b71ee()
	{
		super(2, 1);
	}
	
	
	public static  finda.Fun_eb5b71ee __hx_current;
	
	@Override public   double __hx_invoke2_f(double __fn_float1, double __fn_float2, java.lang.Object __fn_dyn1, java.lang.Object __fn_dyn2)
	{
		java.lang.Object f2 = ( (( __fn_dyn2 == haxe.lang.Runtime.undefined )) ? (((java.lang.Object) (__fn_float2) )) : (((java.lang.Object) (__fn_dyn2) )) );
		java.lang.Object f1 = ( (( __fn_dyn1 == haxe.lang.Runtime.undefined )) ? (((java.lang.Object) (__fn_float1) )) : (((java.lang.Object) (__fn_dyn1) )) );
		if (( haxe.lang.Runtime.toBool(haxe.lang.Runtime.getField(f1, "isDir", true)) && haxe.lang.Runtime.toBool(( ! (haxe.lang.Runtime.toBool(haxe.lang.Runtime.getField(f2, "isDir", true))) )) )) 
		{
			return ((double) (-1) );
		}
		
		if (( haxe.lang.Runtime.toBool(( ! (haxe.lang.Runtime.toBool(haxe.lang.Runtime.getField(f1, "isDir", true))) )) && haxe.lang.Runtime.toBool(haxe.lang.Runtime.getField(f2, "isDir", true)) )) 
		{
			return ((double) (1) );
		}
		
		if (( haxe.lang.Runtime.compare(((int) (haxe.lang.Runtime.getField_f(f1, "firstLetter", true)) ), ((int) (haxe.lang.Runtime.getField_f(f2, "firstLetter", true)) )) > 0 )) 
		{
			return ((double) (1) );
		}
		
		if (( haxe.lang.Runtime.compare(((int) (haxe.lang.Runtime.getField_f(f1, "firstLetter", true)) ), ((int) (haxe.lang.Runtime.getField_f(f2, "firstLetter", true)) )) < 0 )) 
		{
			return ((double) (-1) );
		}
		
		return ((double) (0) );
	}
	
	
}


