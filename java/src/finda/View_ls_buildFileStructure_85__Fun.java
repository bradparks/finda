package finda;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class View_ls_buildFileStructure_85__Fun extends haxe.lang.Function
{
	public    View_ls_buildFileStructure_85__Fun()
	{
		super(2, 1);
	}
	
	
	public static  finda.View_ls_buildFileStructure_85__Fun __hx_current;
	
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


